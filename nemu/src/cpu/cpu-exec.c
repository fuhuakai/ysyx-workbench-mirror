/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "../monitor/sdb/watchpoint.h"

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

#define IRINGBUF_SIZE 16

typedef struct {
    vaddr_t pc;          // 指令PC
    uint32_t inst;       // 指令二进制
    char logbuf[128];    // 完整日志行
} IRingBufItem;

static IRingBufItem iringbuf[IRINGBUF_SIZE];  // 环形缓冲区
static int iringbuf_head = 0;                 // 当前写入位置
static int iringbuf_count = 0;                // 当前指令数
static vaddr_t fault_pc = 0;                  // 出错指令PC

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

// 更新环形缓冲区
  if (iringbuf_count < IRINGBUF_SIZE) {
      iringbuf_count++;  // 缓冲区未满时增加计数
  }
  
  // 写入当前指令信息
  IRingBufItem *item = &iringbuf[iringbuf_head];
  item->pc = _this->pc;
  item->inst = _this->isa.inst;
  strncpy(item->logbuf, _this->logbuf, sizeof(item->logbuf));
  item->logbuf[sizeof(item->logbuf)-1] = '\0';
  
  // 移动头指针(环形)
  iringbuf_head = (iringbuf_head + 1) % IRINGBUF_SIZE;

  // 新增监视点检查
    if (checkWP()) {
        printf("Watchpoint triggered, execution paused.\n");
        nemu_state.state = NEMU_STOP; // 暂停程序执行
    }
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  //rtfsc注：调用反汇编函数，将二进制指令转换为可读的汇编指令
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
  
   // 检测到错误时记录PC
    if (nemu_state.state == NEMU_ABORT) {
        fault_pc = s.pc;  // 保存出错指令PC
    } 

    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

// 打印环形缓冲区函数，标记出错指令
static void print_iringbuf() {
  if (iringbuf_count == 0) return;
  
  // 计算起始位置(最旧的指令)
  int start = (iringbuf_head - iringbuf_count + IRINGBUF_SIZE) % IRINGBUF_SIZE;
  int count = iringbuf_count;
  
  printf("\nInstruction trace before fault (max %d):\n", IRINGBUF_SIZE);
  for (int i = 0; i < count; i++) {
      int idx = (start + i) % IRINGBUF_SIZE;
      IRingBufItem *item = &iringbuf[idx];
      
      // 标记错误指令
      if (item->pc == fault_pc) {
          printf("  -->  %s\n", item->logbuf);
      } else {
          printf("      " FMT_WORD ": %s\n", item->pc, item->logbuf);
      }
  }
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  // 出错时打印环形缓冲区
  if (nemu_state.state == NEMU_ABORT && fault_pc != 0) {
      print_iringbuf();
  }

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}


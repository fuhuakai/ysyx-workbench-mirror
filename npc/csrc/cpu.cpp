#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "../include/macro.h"
#include "Vrv32.h"
#include "Vrv32___024root.h"

/********extern functions or variables********/
extern void single_cycle(void); 
extern NPCState npc_state;
extern Vrv32 *top;
extern uint64_t get_time();

#ifdef CONFIG_ITRACE
extern void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
#endif

#ifdef CONFIG_FTRACE 
extern void ftrace_ret(uint32_t pc);
extern void ftrace_call(uint32_t pc, uint32_t npc);
#define OPCODE(inst)  ((inst) & 0x7f)
#endif

#ifdef CONFIG_IRINGBUF 
extern void append_iringbuf(char *s);
extern void display_iringbuf(void);
#endif

#ifdef CONFIG_DIFFTEST 
extern void difftest_step(vaddr_t pc, vaddr_t npc);
#endif
/*********************************************/


#define MAX_INST_TO_PRINT 20
static uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
IFDEF(CONFIG_ITRACE, char logbuf[128]);


static struct {
  word_t pc;
  word_t npc;
  word_t inst;
  word_t ninst;
} PCSet = {0, 0, 0, 0};


static void statistic() {
    Log("host time spent = %lu us", g_timer);
    Log("total guest instructions = %lu" , g_nr_guest_inst);
    if (g_timer > 0) Log("simulation frequency = %lu inst/s", g_nr_guest_inst * 1000000 / g_timer);
    else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
    Log("total guest instructions = %lu", g_nr_guest_inst);
}

static void execute_once() 
{
    // 先推进一个完整指令节拍（IFU延迟后整体约6拍/指令）
    single_cycle(); single_cycle(); single_cycle(); single_cycle(); single_cycle(); single_cycle();
        // 读取 IFU 数据包寄存器，高32位为PC，低32位为inst
    uint64_t ifu_pack0 = (uint64_t)top->rootp->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg;
    PCSet.pc   = (uint32_t)(ifu_pack0 >> 32);
    PCSet.inst = (uint32_t)(ifu_pack0 & 0xffffffffu);
    // 分阶段顺序推进：IFU 引入1拍返回延迟后，整体6拍/指令
    single_cycle(); single_cycle(); single_cycle(); single_cycle(); single_cycle(); single_cycle();
    uint64_t ifu_pack1 = (uint64_t)top->rootp->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg;
    PCSet.npc   = top->rootp->rv32__DOT__bru_inst__DOT__npc_reg;
    PCSet.ninst = (uint32_t)(ifu_pack1 & 0xffffffffu);

#ifdef CONFIG_ITRACE
    // 将指令拆分为字节
    uint8_t inst_bytes[4];
    for (int i = 0; i < 4; i++) {
        inst_bytes[i] = (PCSet.inst >> (i * 8)) & 0xFF;
    }
    
    // 格式化输出
    snprintf(logbuf, sizeof(logbuf), "0x%08x: %02x %02x %02x %02x  ", PCSet.pc, 
             inst_bytes[3], inst_bytes[2], inst_bytes[1], inst_bytes[0]);
    
    // 调用反汇编函数
    int len = strlen(logbuf);
    disassemble(logbuf + len, sizeof(logbuf) - len, PCSet.pc, inst_bytes, 4);
#endif

#ifdef CONFIG_FTRACE
  if(PCSet.inst == 0x00008067)  //ret
    ftrace_ret(PCSet.pc);
  else if((OPCODE(PCSet.inst)==0b1100111) || (OPCODE(PCSet.inst)== 0b1101111))  //jalr or jal
    ftrace_call(PCSet.pc, PCSet.npc);
#endif

#ifdef CONFIG_IRINGBUF 
    append_iringbuf(logbuf);
#endif
}

static void trace_and_difftest() 
{
    // itrace
    #ifdef CONFIG_ITRACE
        log_write("%s\n", logbuf);
    #endif
    if(g_print_step) 
        IFDEF(CONFIG_ITRACE, puts(logbuf)); 

    // difftest
    IFDEF(CONFIG_DIFFTEST, difftest_step(PCSet.pc, PCSet.npc));

}

static void execute(uint64_t n) 
{
    for (;n > 0; n --) 
    {    
        execute_once();
        g_nr_guest_inst ++;
        trace_and_difftest();
        if (npc_state.state != NPC_RUNNING) 
            break;
    }
}


void cpu_exec(uint64_t n) 
{
    g_print_step = (n < MAX_INST_TO_PRINT);
    switch (npc_state.state) 
    {
        case NPC_END: case NPC_ABORT:
            printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
            return;
        default: npc_state.state = NPC_RUNNING;
    }   
    uint64_t timer_start = get_time();

    execute(n);

    // 出错时打印环形缓冲区
    #ifdef CONFIG_IRINGBUF
    if (npc_state.state == NPC_ABORT) {
        display_iringbuf();
     }
    #endif

    uint64_t timer_end = get_time();
    g_timer += timer_end - timer_start;

    switch (npc_state.state) 
    {
        case NPC_RUNNING: npc_state.state = NPC_STOP; break;

        case NPC_END: case NPC_ABORT:
            Log("NPC: %s at pc = 0x%08x",
                (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
                (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                    ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
                npc_state.halt_pc);
        case NPC_QUIT: statistic();
    }
}
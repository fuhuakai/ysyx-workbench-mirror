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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#ifdef CONFIG_MTRACE
static bool mtrace_always = true;
static char mtrace_cond_str[256] = "true";
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);

    // 新增：初始化 mtrace 条件
  #ifdef CONFIG_MTRACE
  if (strcmp(CONFIG_MTRACE_COND, "true") != 0) {
    mtrace_always = false;
    strncpy(mtrace_cond_str, CONFIG_MTRACE_COND, sizeof(mtrace_cond_str)-1);
    mtrace_cond_str[sizeof(mtrace_cond_str)-1] = '\0';
  }
  #endif
}

// 新增：简单的条件检查（不依赖 expr_compile）
static inline bool mtrace_cond_met() {
  #ifdef CONFIG_MTRACE
  if (mtrace_always) return true;
  
  // 简单的条件检查逻辑（只支持 "pc == 0x8xxxxxxx" ）
  if (strstr(mtrace_cond_str, "pc == ") != NULL){
    unsigned long target_pc;
    if (sscanf(mtrace_cond_str, "pc == %lx", &target_pc) == 1) {
      return cpu.pc == target_pc;
    }
  }
  
  // 默认条件不满足
  return false;
  #else
  return false;
  #endif
}

// 新增：mtrace 输出函数
static inline void mtrace_log(char type, paddr_t addr, int len, word_t data) {
  #ifdef CONFIG_MTRACE
  if (mtrace_cond_met()) {
    printf("%c " FMT_PADDR " %d 0x%08x " FMT_WORD "\n", 
           type, addr, len, data, cpu.pc);
  }
  #endif
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) {
    word_t ret = pmem_read(addr, len);
    mtrace_log('R', addr, len, ret);
    return ret;
  }
  IFDEF(CONFIG_DEVICE, {
    word_t ret = mmio_read(addr, len);
    mtrace_log('R', addr, len, ret);
    return ret;
  });
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    mtrace_log('W', addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, {
    mmio_write(addr, len, data);
    mtrace_log('W', addr, len, data);
    return;
  });
  out_of_bound(addr);
}

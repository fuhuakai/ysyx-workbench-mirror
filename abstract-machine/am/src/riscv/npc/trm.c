#include <am.h>
#include <klib-macros.h>
#include "../riscv.h"

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
#define SERIAL_PORT 0xa00003f8

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);

#define MAINARGS_MAX_LEN 64 
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

//在halt中加入npc-trap，在npc上运行的AM程序结束时执行ebreak结束仿真
void halt(int code) {
  npc_trap(code);

  // should not reach here
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}

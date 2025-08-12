#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <stdint.h>

#ifdef CONFIG_FTRACE

void init_ftrace(const char *elf_file);
const char *ftrace_func_name(uint32_t addr);
void ftrace_call(uint32_t pc, uint32_t target);
void ftrace_ret(uint32_t pc);

#else

static inline void init_ftrace(const char *elf_file) { (void)elf_file; }
static inline void ftrace_call(uint32_t pc, uint32_t target) {
    (void)pc; (void)target;
}
static inline void ftrace_ret(uint32_t pc) { 
    (void)pc;
}

#endif // CONFIG_FTRACE

#endif // __FTRACE_H__
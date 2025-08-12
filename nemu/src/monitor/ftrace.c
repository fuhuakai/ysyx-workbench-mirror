#include "../../../include/ftrace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef CONFIG_FTRACE

typedef struct {
    uint32_t addr;
    uint32_t size;
    const char *name;
} FuncSymbol;

static FuncSymbol *func_symtab = NULL;
static int sym_count = 0;
static char *strtab = NULL;

// 调用栈管理
#define CALL_STACK_DEPTH 64
static uint32_t call_stack[CALL_STACK_DEPTH];
static int call_stack_top = -1;

const char *ftrace_func_name(uint32_t addr) {
    for (int i = 0; i < sym_count; i++) {
        if (addr >= func_symtab[i].addr && 
            addr < func_symtab[i].addr + func_symtab[i].size) {
            return func_symtab[i].name;
        }
    }
    return "???";
}

void ftrace_call(uint32_t pc, uint32_t target) {
    if (call_stack_top < CALL_STACK_DEPTH - 1) {
        call_stack[++call_stack_top] = pc + 4; // 保存返回地址
    }
    printf("[FTRACE] Call: 0x%08x -> %s\n", target, ftrace_func_name(target));
}

void ftrace_ret(uint32_t pc) {
    if (call_stack_top >= 0) {
        uint32_t ret_addr = call_stack[call_stack_top--];
        const char *func_name = ftrace_func_name(pc);
        printf("[FTRACE] Ret:  %s -> 0x%08x\n", func_name, ret_addr);
    }
}

// 简易ELF解析器
void init_ftrace(const char *elf_file) {
    FILE *fp = fopen(elf_file, "rb");
    if (!fp) return;
    
    // 1. 读取ELF头
    uint8_t e_ident[16];
    fread(e_ident, 1, 16, fp);
    if (memcmp(e_ident, "\x7F""ELF", 4) != 0) {
        fclose(fp);
        return;
    }
    
    // 跳过ELF头剩余部分
    fseek(fp, 32, SEEK_SET); // 定位到e_shoff位置
    
    // 2. 读取节头表偏移和数量
    uint32_t e_shoff;
    uint16_t e_shnum, e_shentsize;
    fread(&e_shoff, 4, 1, fp);
    fseek(fp, 46, SEEK_SET); // e_shentsize位置
    fread(&e_shentsize, 2, 1, fp);
    fseek(fp, 48, SEEK_SET); // e_shnum位置
    fread(&e_shnum, 2, 1, fp);
    
    // 3. 查找符号表和字符串表
    uint32_t symtab_off = 0, symtab_size = 0;
    uint32_t strtab_off = 0, strtab_size = 0;
    
    for (int i = 0; i < e_shnum; i++) {
        fseek(fp, e_shoff + i * e_shentsize, SEEK_SET);
        
        uint32_t sh_type;
        fread(&sh_type, 4, 1, fp);
        fseek(fp, 12, SEEK_CUR); // 跳过sh_flags, sh_addr, sh_offset
        uint32_t sh_offset, sh_size, sh_link;
        fread(&sh_offset, 4, 1, fp);
        fread(&sh_size, 4, 1, fp);
        fread(&sh_link, 4, 1, fp);
        
        if (sh_type == 2) { // SHT_SYMTAB
            symtab_off = sh_offset;
            symtab_size = sh_size;
            // 获取关联的字符串表
            fseek(fp, e_shoff + sh_link * e_shentsize + 16, SEEK_SET);
            fread(&strtab_off, 4, 1, fp);
            fread(&strtab_size, 4, 1, fp);
        }
    }
    
    // 4. 读取字符串表
    if (strtab_off && strtab_size) {
        strtab = malloc(strtab_size);
        fseek(fp, strtab_off, SEEK_SET);
        fread(strtab, 1, strtab_size, fp);
    }
    
    // 5. 读取并处理符号表
    if (symtab_off && symtab_size) {
        int num_syms = symtab_size / 16; // 每个符号表项16字节
        uint8_t *symtab = malloc(symtab_size);
        fseek(fp, symtab_off, SEEK_SET);
        fread(symtab, 1, symtab_size, fp);
        
        // 统计函数符号数量
        sym_count = 0;
        for (int i = 0; i < num_syms; i++) {
            uint8_t *sym = symtab + i * 16;
            uint8_t st_info = sym[12]; // 符号类型信息
            if ((st_info & 0x0F) == 2) sym_count++; // STT_FUNC
        }
        
        // 提取函数符号
        func_symtab = malloc(sym_count * sizeof(FuncSymbol));
        int idx = 0;
        for (int i = 0; i < num_syms; i++) {
            uint8_t *sym = symtab + i * 16;
            uint8_t st_info = sym[12];
            if ((st_info & 0x0F) == 2) { // STT_FUNC
                uint32_t st_name, st_value, st_size;
                memcpy(&st_name, sym, 4);
                memcpy(&st_value, sym + 4, 4);
                memcpy(&st_size, sym + 8, 4);
                
                func_symtab[idx].addr = st_value;
                func_symtab[idx].size = st_size;
                func_symtab[idx].name = strtab + st_name;
                idx++;
            }
        }
        free(symtab);
    }
    
    fclose(fp);
    printf("Ftrace: loaded %d functions from %s\n", sym_count, elf_file);
}
#endif // CONFIG_FTRACE
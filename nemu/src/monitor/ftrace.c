#include <common.h>
#include <generated/autoconf.h>//必须包含配置宏，否则会因为识别不到CONFIG-FTRACE而直接跳过函数实现！！
#include <ftrace.h>
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

#define CALL_STACK_DEPTH 64
static uint32_t call_stack[CALL_STACK_DEPTH];
static int call_stack_top = -1;

//地址——>函数名
const char *ftrace_func_name(uint32_t addr) {
    for (int i = 0; i < sym_count; i++) {
        if (addr >= func_symtab[i].addr && 
            addr < func_symtab[i].addr + func_symtab[i].size) {
            return func_symtab[i].name;
        }
    }
    return "???";
}

static int call_depth = 0;

void ftrace_call(uint32_t pc, uint32_t target) {
    if (call_stack_top < CALL_STACK_DEPTH - 1) {
        call_stack[++call_stack_top] = pc + 4;
    }
    const char *target_name = ftrace_func_name(target);
    
    printf("0x%08x: ", pc);
    for (int i = 0; i < call_depth; i++) {
        printf("  "); // 每层缩进两个空格
    }
    printf("call [%s@0x%08x]\n", target_name, target);
    call_depth++;
}

void ftrace_ret(uint32_t pc) {
    if (call_stack_top >= 0) {
        call_depth--;
        const char *func_name = ftrace_func_name(pc);
        
        printf("0x%08x: ", pc);
        for (int i = 0; i < call_depth; i++) {
            printf("  "); 
        }
        printf("ret  [%s]\n", func_name);
    }
}


void init_ftrace(const char *elf_file) {
    FILE *fp = fopen(elf_file, "rb");
    if (!fp) {
        printf("Ftrace: cannot open ELF file %s\n", elf_file);
        return;
    }

    // 1. 读取ELF头
    uint8_t e_ident[16];
    if (fread(e_ident, 1, 16, fp) != 16) {
        fclose(fp);
        return;
    }

    // 检查ELF魔数
    if (memcmp(e_ident, "\x7F""ELF", 4) != 0) {
        printf("Ftrace: invalid ELF magic\n");
        fclose(fp);
        return;
    }

    // 检查ELF类别 (32/64位)
    int is_32bit = (e_ident[4] == 1); // 1=32-bit, 2=64-bit

    // 2. 读取ELF头剩余部分
    uint32_t e_shoff;
    uint16_t e_shentsize, e_shnum, e_shstrndx;
    
    fseek(fp, 32, SEEK_SET); // 定位到e_shoff,SEEK_SET是从文件开头开始计算偏移
    if (fread(&e_shoff, 4, 1, fp) != 1) goto cleanup;
    
    fseek(fp, 46, SEEK_SET); // e_shentsize
    if (fread(&e_shentsize, 2, 1, fp) != 1) goto cleanup;
    
    fseek(fp, 48, SEEK_SET); // e_shnum
    if (fread(&e_shnum, 2, 1, fp) != 1) goto cleanup;
    
    fseek(fp, 50, SEEK_SET); // e_shstrndx
    if (fread(&e_shstrndx, 2, 1, fp) != 1) goto cleanup;

    // 3. 查找符号表和字符串表
    uint32_t symtab_off = 0, symtab_size = 0;
    uint32_t strtab_off = 0, strtab_size = 0;
    
    for (int i = 0; i < e_shnum; i++) {
        fseek(fp, e_shoff + i * e_shentsize, SEEK_SET);
        
        // 读取节头基本信息
        uint32_t sh_type, sh_offset, sh_size, sh_link;
        
        // 跳过 sh_name (4字节)
        fseek(fp, 4, SEEK_CUR);
        
        if (fread(&sh_type, 4, 1, fp) != 1) continue;
        
        // 跳过 sh_flags (4字节) 和 sh_addr (4字节)
        fseek(fp, 8, SEEK_CUR);
        
        if (fread(&sh_offset, 4, 1, fp) != 1) continue;
        if (fread(&sh_size, 4, 1, fp) != 1) continue;
        if (fread(&sh_link, 4, 1, fp) != 1) continue;
        
        if (sh_type == 2 || sh_type == 11) { // SHT_SYMTAB 或 SHT_DYNSYM
            symtab_off = sh_offset;
            symtab_size = sh_size;
            
            // 获取关联的字符串表
            if (sh_link < e_shnum) {
                fseek(fp, e_shoff + sh_link * e_shentsize + 16, SEEK_SET);
                if (fread(&strtab_off, 4, 1, fp) != 1) continue;
                if (fread(&strtab_size, 4, 1, fp) != 1) continue;
            }
            break; // 找到符号表后退出循环
        }
    }

    // 4. 读取字符串表(函数名)
    if (strtab_off && strtab_size) {
        strtab = malloc(strtab_size);
        fseek(fp, strtab_off, SEEK_SET);
        if (fread(strtab, 1, strtab_size, fp) != strtab_size) {
            free(strtab);
            strtab = NULL;
        }
    }

    // 5. 处理符号表
    if (symtab_off && symtab_size) {
        // 计算符号数量 (32位ELF每个符号16字节)
        int num_syms = symtab_size / (is_32bit ? 16 : 24);
        uint8_t *symtab_data = malloc(symtab_size);
        fseek(fp, symtab_off, SEEK_SET);
        if (fread(symtab_data, 1, symtab_size, fp) != symtab_size) {
            free(symtab_data);
            goto cleanup;
        }

        // 第一遍：计算函数符号数量
        sym_count = 0;
        for (int i = 0; i < num_syms; i++) {
            uint8_t *sym = symtab_data + i * (is_32bit ? 16 : 24);
            uint8_t st_info = sym[12]; // 符号类型信息
            
            if ((st_info & 0x0F) == 2) { // STT_FUNC
                sym_count++;
            }
        }

        // 分配内存并存储函数符号
        func_symtab = malloc(sym_count * sizeof(FuncSymbol));
        int idx = 0;
        for (int i = 0; i < num_syms; i++) {
            uint8_t *sym = symtab_data + i * (is_32bit ? 16 : 24);
            uint32_t st_name, st_value, st_size;
            uint8_t st_info;
            
            memcpy(&st_name, sym, 4);
            memcpy(&st_value, sym + 4, 4);
            memcpy(&st_size, sym + 8, 4);
            st_info = sym[12];

            if ((st_info & 0x0F) == 2) { // STT_FUNC
                func_symtab[idx].addr = st_value;
                func_symtab[idx].size = st_size;
                func_symtab[idx].name = (strtab && st_name < strtab_size) ? 
                                        (strtab + st_name) : "???";
                idx++;
            }
        }
        
        free(symtab_data);
    }

cleanup:
    fclose(fp);
    printf("Ftrace: loaded %d functions from %s\n", sym_count, elf_file);
}
#endif // CONFIG_FTRACE
#include <dlfcn.h>
#include <../include/common.h>
#include <../tools/capstone/repo/include/capstone/capstone.h>
#include <assert.h>

static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);

static csh handle;

void init_disasm() {
  void *dl_handle;
  dl_handle = dlopen("tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  if (!dl_handle) {
    printf("Failed to load capstone library: %s\n", dlerror());
    assert(0);
  }

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = 
      (cs_err (*)(cs_arch, cs_mode, csh*))dlsym(dl_handle, "cs_open");
  if (!cs_open_dl) {
    printf("Failed to find cs_open: %s\n", dlerror());
    assert(0);
  }

  cs_disasm_dl = (size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**))
      dlsym(dl_handle, "cs_disasm");
  if (!cs_disasm_dl) {
    printf("Failed to find cs_disasm: %s\n", dlerror());
    assert(0);
  }

  cs_free_dl = (void (*)(cs_insn*, size_t))dlsym(dl_handle, "cs_free");
  if (!cs_free_dl) {
    printf("Failed to find cs_free: %s\n", dlerror());
    assert(0);
  }

  cs_arch arch = CS_ARCH_RISCV;
  cs_mode mode = CS_MODE_RISCV32;
  cs_err ret = cs_open_dl(arch, mode, &handle);
  if (ret != CS_ERR_OK) {
    printf("Failed to initialize Capstone: %d\n", ret);
    assert(0);
  }
}

// void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
//   cs_insn *insn;
//   size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
//   if (count == 0) {
//     snprintf(str, size, "unknown");
//     return;
//   }
  
//   int ret = snprintf(str, size, "%s", insn->mnemonic);
//   if (insn->op_str[0] != '\0') {
//     snprintf(str + ret, size - ret, "\t%s", insn->op_str);
//   }
//   cs_free_dl(insn, count);
// }

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
  cs_insn *insn;
  size_t count = cs_disasm_dl(handle, code, nbyte, pc, 1, &insn); // 只解码一条指令
  
  // 确保缓冲区至少有一个空字符
  if (size <= 0) {
    return;
  }
  str[0] = '\0';
  
  if (count == 0) {
    snprintf(str, size, "unknown");
    return;
  }
  
  // 计算需要的总空间
  int needed = snprintf(NULL, 0, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0') {
    needed += snprintf(NULL, 0, "\t%s", insn->op_str);
  }
  
  // 检查是否有足够空间
  if (needed >= size) {
    // 空间不足，只复制部分内容
    int ret = snprintf(str, size, "%s", insn->mnemonic);
    if (ret < size - 1 && insn->op_str[0] != '\0') {
      snprintf(str + ret, size - ret, "\t%s", insn->op_str);
    }
  } else {
    // 空间足够
    int ret = snprintf(str, size, "%s", insn->mnemonic);
    if (insn->op_str[0] != '\0') {
      snprintf(str + ret, size - ret, "\t%s", insn->op_str);
    }
  }
  
  cs_free_dl(insn, count);
}
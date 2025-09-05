// #include <dlfcn.h>
// #include <capstone/capstone.h>
// #include <common.h>

// static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
//     size_t code_size, uint64_t address, size_t count, cs_insn **insn);
// static void (*cs_free_dl)(cs_insn *insn, size_t count);

// static csh handle;

// void init_disasm() {
//   void *dl_handle;
//   dl_handle = dlopen("tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);

//   cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
//   cs_open_dl = dlsym(dl_handle, "cs_open");

//   cs_disasm_dl = dlsym(dl_handle, "cs_disasm");

//   cs_free_dl = dlsym(dl_handle, "cs_free");

// }

// void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
// 	cs_insn *insn;
// 	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
//   int ret = snprintf(str, size, "%s", insn->mnemonic);
//   if (insn->op_str[0] != '\0') {
//     snprintf(str + ret, size - ret, "\t%s", insn->op_str);
//   }
//   cs_free_dl(insn, count);
// }

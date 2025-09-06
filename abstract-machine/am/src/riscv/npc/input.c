// #include <am.h>
// #include "../riscv.h"

// #define KBD_ADDR 0xa0000060
// #define KEYDOWN_MASK 0x8000

// void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
//   uint32_t key_code = inl(KBD_ADDR);
//   kbd->keydown = (key_code & KEYDOWN_MASK ? true :false);//按位与结果非零证明有按键按下
//   kbd->keycode = key_code & ~KEYDOWN_MASK;
// }

#include <am.h>

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  kbd->keydown = 0;
  kbd->keycode = AM_KEY_NONE;
}

#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: ev.event = EVENT_YIELD; c->mepc += 4; break;
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *c = kstack.end - sizeof(Context);
  
  //入口为f()
  c->mepc = (uint32_t)entry;
  c->mcause = 0xb;
  c->mstatus = 0x1800;
  
  //a0为传参寄存器
  c->gpr[10] = (uint32_t)arg;
  return c;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, 0xb; ecall");
#else
  asm volatile("li a7, 0xb; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}

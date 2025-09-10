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

#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

//打开difftest config后，src/cpu/difftest/dut.c会调用此函数
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
    int reg_num = ARRLEN(cpu.gpr);
    bool match = true;
    
    for (int i = 0; i < reg_num; i++) {
        if (ref_r->gpr[i] != cpu.gpr[i]) {
            printf("difftest fault: gpr[%d] (ref: 0x%08x != dut: 0x%08x) at PC=0x%08x\n", i, ref_r->gpr[i], cpu.gpr[i], pc);
            match = false;
        }
    }
    
    if (ref_r->pc != cpu.pc) {
        printf("difftest fault: PC (ref: 0x%08x != dut: 0x%08x) at PC=0x%08x\n", ref_r->pc, cpu.pc, pc);
        match = false;
    }
    //添加csr寄存器检查及结果打印
    if (ref_r->csrs.mstatus != cpu.csrs.mstatus) {
        printf("difftest fault: mstatus (ref: 0x%08x != dut: 0x%08x) at PC=0x%08x\n", ref_r->csrs.mstatus, cpu.csrs.mstatus, pc);
        match = false;
    }
    if (ref_r->csrs.mcause != cpu.csrs.mcause) {
        printf("difftest fault: mcause (ref: 0x%08x != dut: 0x%08x) at PC=0x%08x\n", ref_r->csrs.mcause, cpu.csrs.mcause, pc);
        match = false;
    }
    if (ref_r->csrs.mepc != cpu.csrs.mepc) {
        printf("difftest fault: mepc (ref: 0x%08x != dut: 0x%08x) at PC=0x%08x\n", ref_r->csrs.mepc, cpu.csrs.mepc, pc);
        match = false;
    }
    if (ref_r->csrs.mtvec != cpu.csrs.mtvec) {
        printf("difftest fault: mtvec (ref: 0x%08x != dut: 0x%08x) at PC=0x%08x\n", ref_r->csrs.mtvec, cpu.csrs.mtvec, pc);
        match = false;
    }

    return match;
}

void isa_difftest_attach() {
}

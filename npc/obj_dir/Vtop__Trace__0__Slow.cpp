// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->declBus(c+67,"inst", false,-1, 31,0);
    tracep->declBit(c+68,"trap", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->declBus(c+67,"inst", false,-1, 31,0);
    tracep->declBit(c+68,"trap", false,-1);
    tracep->declBus(c+69,"next_pc", false,-1, 31,0);
    tracep->declBit(c+70,"rf_wen", false,-1);
    tracep->declBus(c+71,"rf_raddr1", false,-1, 4,0);
    tracep->declBus(c+72,"rf_rdata1", false,-1, 31,0);
    tracep->declBus(c+73,"rf_waddr", false,-1, 4,0);
    tracep->declBus(c+74,"rf_wdata", false,-1, 31,0);
    tracep->declBus(c+75,"imm", false,-1, 31,0);
    tracep->declBit(c+76,"is_ebreak", false,-1);
    tracep->pushNamePrefix("exu ");
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+72,"rdata1", false,-1, 31,0);
    tracep->declBus(c+75,"imm", false,-1, 31,0);
    tracep->declBit(c+76,"is_ebreak", false,-1);
    tracep->declBus(c+74,"wdata", false,-1, 31,0);
    tracep->declBit(c+68,"trap", false,-1);
    tracep->pushNamePrefix("trap_reg ");
    tracep->declBus(c+110,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+76,"din", false,-1, 0,0);
    tracep->declBus(c+68,"dout", false,-1, 0,0);
    tracep->declBit(c+112,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+67,"inst", false,-1, 31,0);
    tracep->declBus(c+71,"rs1", false,-1, 4,0);
    tracep->declBus(c+73,"rd", false,-1, 4,0);
    tracep->declBus(c+75,"imm", false,-1, 31,0);
    tracep->declBit(c+70,"wen", false,-1);
    tracep->declBit(c+76,"is_ebreak", false,-1);
    tracep->declBus(c+77,"opcode", false,-1, 6,0);
    tracep->declBus(c+78,"funct3", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+69,"din", false,-1, 31,0);
    tracep->declBus(c+66,"dout", false,-1, 31,0);
    tracep->declBit(c+112,"wen", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regs ");
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+71,"raddr1", false,-1, 4,0);
    tracep->declBus(c+72,"rdata1", false,-1, 31,0);
    tracep->declBus(c+73,"waddr", false,-1, 4,0);
    tracep->declBus(c+74,"wdata", false,-1, 31,0);
    tracep->declBit(c+70,"wen", false,-1);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"reg_val", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("reg_gen[10] ");
    tracep->declBit(c+79,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+33,"dout", false,-1, 31,0);
    tracep->declBit(c+79,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[11] ");
    tracep->declBit(c+80,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+34,"dout", false,-1, 31,0);
    tracep->declBit(c+80,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[12] ");
    tracep->declBit(c+81,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+35,"dout", false,-1, 31,0);
    tracep->declBit(c+81,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[13] ");
    tracep->declBit(c+82,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+36,"dout", false,-1, 31,0);
    tracep->declBit(c+82,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[14] ");
    tracep->declBit(c+83,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+37,"dout", false,-1, 31,0);
    tracep->declBit(c+83,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[15] ");
    tracep->declBit(c+84,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+38,"dout", false,-1, 31,0);
    tracep->declBit(c+84,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[16] ");
    tracep->declBit(c+85,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+39,"dout", false,-1, 31,0);
    tracep->declBit(c+85,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[17] ");
    tracep->declBit(c+86,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+40,"dout", false,-1, 31,0);
    tracep->declBit(c+86,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[18] ");
    tracep->declBit(c+87,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+41,"dout", false,-1, 31,0);
    tracep->declBit(c+87,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[19] ");
    tracep->declBit(c+88,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+42,"dout", false,-1, 31,0);
    tracep->declBit(c+88,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[1] ");
    tracep->declBit(c+89,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+43,"dout", false,-1, 31,0);
    tracep->declBit(c+89,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[20] ");
    tracep->declBit(c+90,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+44,"dout", false,-1, 31,0);
    tracep->declBit(c+90,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[21] ");
    tracep->declBit(c+91,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+45,"dout", false,-1, 31,0);
    tracep->declBit(c+91,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[22] ");
    tracep->declBit(c+92,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+46,"dout", false,-1, 31,0);
    tracep->declBit(c+92,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[23] ");
    tracep->declBit(c+93,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+47,"dout", false,-1, 31,0);
    tracep->declBit(c+93,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[24] ");
    tracep->declBit(c+94,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+48,"dout", false,-1, 31,0);
    tracep->declBit(c+94,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[25] ");
    tracep->declBit(c+95,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+49,"dout", false,-1, 31,0);
    tracep->declBit(c+95,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[26] ");
    tracep->declBit(c+96,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+50,"dout", false,-1, 31,0);
    tracep->declBit(c+96,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[27] ");
    tracep->declBit(c+97,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+51,"dout", false,-1, 31,0);
    tracep->declBit(c+97,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[28] ");
    tracep->declBit(c+98,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+52,"dout", false,-1, 31,0);
    tracep->declBit(c+98,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[29] ");
    tracep->declBit(c+99,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+53,"dout", false,-1, 31,0);
    tracep->declBit(c+99,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[2] ");
    tracep->declBit(c+100,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+54,"dout", false,-1, 31,0);
    tracep->declBit(c+100,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[30] ");
    tracep->declBit(c+101,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+55,"dout", false,-1, 31,0);
    tracep->declBit(c+101,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[31] ");
    tracep->declBit(c+102,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+56,"dout", false,-1, 31,0);
    tracep->declBit(c+102,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[3] ");
    tracep->declBit(c+103,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+57,"dout", false,-1, 31,0);
    tracep->declBit(c+103,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[4] ");
    tracep->declBit(c+104,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+58,"dout", false,-1, 31,0);
    tracep->declBit(c+104,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[5] ");
    tracep->declBit(c+105,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+59,"dout", false,-1, 31,0);
    tracep->declBit(c+105,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[6] ");
    tracep->declBit(c+106,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+60,"dout", false,-1, 31,0);
    tracep->declBit(c+106,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[7] ");
    tracep->declBit(c+107,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+61,"dout", false,-1, 31,0);
    tracep->declBit(c+107,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[8] ");
    tracep->declBit(c+108,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+62,"dout", false,-1, 31,0);
    tracep->declBit(c+108,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_gen[9] ");
    tracep->declBit(c+109,"wen_i", false,-1);
    tracep->pushNamePrefix("reg_inst ");
    tracep->declBus(c+113,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+74,"din", false,-1, 31,0);
    tracep->declBus(c+63,"dout", false,-1, 31,0);
    tracep->declBit(c+109,"wen", false,-1);
    tracep->popNamePrefix(4);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__regs__DOT__reg_val[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__regs__DOT__reg_val[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__regs__DOT__reg_val[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__regs__DOT__reg_val[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__regs__DOT__reg_val[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__regs__DOT__reg_val[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__regs__DOT__reg_val[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__regs__DOT__reg_val[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__regs__DOT__reg_val[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__regs__DOT__reg_val[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__regs__DOT__reg_val[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__regs__DOT__reg_val[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__regs__DOT__reg_val[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__regs__DOT__reg_val[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__regs__DOT__reg_val[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__regs__DOT__reg_val[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__regs__DOT__reg_val[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__regs__DOT__reg_val[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__regs__DOT__reg_val[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__regs__DOT__reg_val[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__regs__DOT__reg_val[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__regs__DOT__reg_val[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__regs__DOT__reg_val[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__regs__DOT__reg_val[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__regs__DOT__reg_val[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__regs__DOT__reg_val[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__regs__DOT__reg_val[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__regs__DOT__reg_val[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__regs__DOT__reg_val[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__regs__DOT__reg_val[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__regs__DOT__reg_val[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regs__DOT__reg_val[31]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout),32);
    bufp->fullBit(oldp+64,(vlSelf->clk));
    bufp->fullBit(oldp+65,(vlSelf->rst));
    bufp->fullIData(oldp+66,(vlSelf->pc),32);
    bufp->fullIData(oldp+67,(vlSelf->inst),32);
    bufp->fullBit(oldp+68,(vlSelf->trap));
    bufp->fullIData(oldp+69,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullBit(oldp+70,(vlSelf->top__DOT__rf_wen));
    bufp->fullCData(oldp+71,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullIData(oldp+72,(((0U == (0x1fU & (vlSelf->inst 
                                               >> 0xfU)))
                               ? 0U : vlSelf->top__DOT__regs__DOT__reg_val
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))])),32);
    bufp->fullCData(oldp+73,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__rf_wdata),32);
    bufp->fullIData(oldp+75,((((- (IData)((vlSelf->inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->inst 
                                           >> 0x14U))),32);
    bufp->fullBit(oldp+76,((IData)((0x100073U == (0x10707fU 
                                                  & vlSelf->inst)))));
    bufp->fullCData(oldp+77,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+78,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullBit(oldp+79,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x500U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+80,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x580U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+81,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x600U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+82,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x680U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+83,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x700U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x780U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+85,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x800U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+86,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x880U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+87,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x900U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+88,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x980U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+89,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+90,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xa00U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+91,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xa80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+92,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xb00U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+93,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xb80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+94,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xc00U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+95,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xc80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+96,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xd00U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+97,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xd80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+98,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xe00U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+99,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xe80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+100,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x100U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+101,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0xf00U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+102,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0xf80U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+103,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x180U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+104,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x200U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+105,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x280U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+106,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x300U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+107,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x380U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+108,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x400U == (0xf80U & vlSelf->inst)))));
    bufp->fullBit(oldp+109,(((IData)(vlSelf->top__DOT__rf_wen) 
                             & (0x480U == (0xf80U & vlSelf->inst)))));
    bufp->fullIData(oldp+110,(1U),32);
    bufp->fullIData(oldp+111,(0U),32);
    bufp->fullBit(oldp+112,(1U));
    bufp->fullIData(oldp+113,(0x20U),32);
    bufp->fullIData(oldp+114,(0x80000000U),32);
}

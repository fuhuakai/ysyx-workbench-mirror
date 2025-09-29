// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrv32__Syms.h"


VL_ATTR_COLD void Vrv32___024root__trace_init_sub__TOP__0(Vrv32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->pushNamePrefix("rv32 ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBus(c+19,"clk_cnt", false,-1, 2,0);
    tracep->declBit(c+20,"w_ifu_valid", false,-1);
    tracep->declBus(c+21,"w_ifu_pc", false,-1, 31,0);
    tracep->declBus(c+22,"w_ifu_inst", false,-1, 31,0);
    tracep->declBit(c+23,"w_idu_ready", false,-1);
    tracep->declBit(c+24,"w_idu_valid", false,-1);
    tracep->declBus(c+25,"w_idu_rs_id1", false,-1, 4,0);
    tracep->declBus(c+26,"w_idu_rs_id2", false,-1, 4,0);
    tracep->declBus(c+27,"w_idu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+28,"w_idu_csr_ren", false,-1);
    tracep->declBit(c+29,"w_idu_is_mret", false,-1);
    tracep->declBit(c+30,"w_idu_is_ecall", false,-1);
    tracep->declBus(c+31,"w_idu_csr_type", false,-1, 1,0);
    tracep->declBus(c+32,"w_idu_alu_type", false,-1, 3,0);
    tracep->declBus(c+33,"w_idu_num_sel", false,-1, 1,0);
    tracep->declBus(c+34,"w_idu_imm", false,-1, 31,0);
    tracep->declBit(c+35,"w_idu_is_load", false,-1);
    tracep->declBit(c+36,"w_idu_is_store", false,-1);
    tracep->declBus(c+37,"w_idu_func3", false,-1, 2,0);
    tracep->declBus(c+38,"w_idu_pc", false,-1, 31,0);
    tracep->declBit(c+39,"w_idu_is_jal", false,-1);
    tracep->declBit(c+40,"w_idu_is_jalr", false,-1);
    tracep->declBit(c+41,"w_idu_is_brch", false,-1);
    tracep->declBus(c+42,"w_idu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"w_idu_gpr_wen", false,-1);
    tracep->declBit(c+44,"w_exu_ready", false,-1);
    tracep->declBit(c+45,"w_exu_valid", false,-1);
    tracep->declBus(c+46,"w_exu_exu_res", false,-1, 31,0);
    tracep->declBit(c+47,"w_exu_is_load", false,-1);
    tracep->declBit(c+48,"w_exu_is_store", false,-1);
    tracep->declBus(c+49,"w_exu_func3", false,-1, 2,0);
    tracep->declBus(c+50,"w_exu_rs1", false,-1, 31,0);
    tracep->declBus(c+51,"w_exu_rs2", false,-1, 31,0);
    tracep->declBus(c+52,"w_exu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+53,"w_exu_is_mret", false,-1);
    tracep->declBit(c+54,"w_exu_is_ecall", false,-1);
    tracep->declBus(c+55,"w_exu_imm", false,-1, 31,0);
    tracep->declBus(c+56,"w_exu_pc", false,-1, 31,0);
    tracep->declBit(c+57,"w_exu_is_jal", false,-1);
    tracep->declBit(c+58,"w_exu_is_jalr", false,-1);
    tracep->declBit(c+59,"w_exu_brch", false,-1);
    tracep->declBus(c+60,"w_exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"w_exu_gpr_wen", false,-1);
    tracep->declBus(c+62,"w_exu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"w_exu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+64,"w_exu_csr_wen", false,-1);
    tracep->declBit(c+65,"w_lsu_ready", false,-1);
    tracep->declBit(c+66,"w_lsu_valid", false,-1);
    tracep->declBus(c+67,"w_lsu_imm", false,-1, 31,0);
    tracep->declBus(c+68,"w_lsu_pc", false,-1, 31,0);
    tracep->declBus(c+69,"w_lsu_rs1", false,-1, 31,0);
    tracep->declBit(c+70,"w_lsu_is_jal", false,-1);
    tracep->declBit(c+71,"w_lsu_is_jalr", false,-1);
    tracep->declBit(c+72,"w_lsu_brch", false,-1);
    tracep->declBus(c+73,"w_lsu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+74,"w_lsu_is_ejump", false,-1);
    tracep->declBus(c+75,"w_lsu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"w_lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+77,"w_lsu_gpr_wen", false,-1);
    tracep->declBit(c+78,"w_lsu_csr_wen", false,-1);
    tracep->declBit(c+79,"w_lsu_is_mret", false,-1);
    tracep->declBit(c+80,"w_lsu_is_ecall", false,-1);
    tracep->declBus(c+81,"w_lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"w_lsu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+83,"w_wbu_ready", false,-1);
    tracep->declBit(c+84,"w_wbu_cycle_end", false,-1);
    tracep->declBit(c+85,"w_wbu_npc_wen", false,-1);
    tracep->declBus(c+75,"w_wbu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"w_wbu_rd_id", false,-1, 4,0);
    tracep->declBit(c+86,"w_wbu_gpr_wen", false,-1);
    tracep->declBus(c+69,"w_wbu_mcause_in", false,-1, 31,0);
    tracep->declBus(c+68,"w_wbu_mepc_in", false,-1, 31,0);
    tracep->declBit(c+78,"w_wbu_csr_wen", false,-1);
    tracep->declBus(c+81,"w_wbu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"w_wbu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+87,"w_bru_npc", false,-1, 31,0);
    tracep->declBus(c+88,"w_rf_rs1", false,-1, 31,0);
    tracep->declBus(c+89,"w_rf_rs2", false,-1, 31,0);
    tracep->declBus(c+90,"w_cc_csr_src", false,-1, 31,0);
    tracep->declBus(c+91,"w_cc_csr_npc", false,-1, 31,0);
    tracep->pushNamePrefix("bru_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBus(c+68,"i_bru_pc", false,-1, 31,0);
    tracep->declBus(c+67,"i_bru_imm", false,-1, 31,0);
    tracep->declBit(c+70,"i_bru_is_jal", false,-1);
    tracep->declBit(c+71,"i_bru_is_jalr", false,-1);
    tracep->declBit(c+72,"i_bru_brch", false,-1);
    tracep->declBit(c+74,"i_bru_ejump", false,-1);
    tracep->declBus(c+73,"i_bru_csr_npc", false,-1, 31,0);
    tracep->declBus(c+69,"i_bru_rs1", false,-1, 31,0);
    tracep->declBit(c+85,"i_bru_npc_wen", false,-1);
    tracep->declBus(c+87,"o_bru_npc", false,-1, 31,0);
    tracep->declBus(c+92,"pc_jorb", false,-1, 31,0);
    tracep->declBus(c+93,"npc_t1", false,-1, 31,0);
    tracep->declBus(c+94,"npc_t2", false,-1, 31,0);
    tracep->declBus(c+288,"jalr_mask", false,-1, 31,0);
    tracep->declBus(c+87,"npc_reg", false,-1, 31,0);
    tracep->pushNamePrefix("mux1 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+290,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+92,"out", false,-1, 31,0);
    tracep->declBus(c+71,"key", false,-1, 0,0);
    tracep->declArray(c+95,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+290,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+92,"out", false,-1, 31,0);
    tracep->declBus(c+71,"key", false,-1, 0,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+95,"lut", false,-1, 65,0);
    tracep->declBus(c+294,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+98+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+102+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+104,"lut_out", false,-1, 31,0);
    tracep->declBit(c+105,"hit", false,-1);
    tracep->declBus(c+295,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux2 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+290,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+93,"out", false,-1, 31,0);
    tracep->declBus(c+106,"key", false,-1, 0,0);
    tracep->declArray(c+107,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+290,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+93,"out", false,-1, 31,0);
    tracep->declBus(c+106,"key", false,-1, 0,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+107,"lut", false,-1, 65,0);
    tracep->declBus(c+294,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+110+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+114+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+116,"lut_out", false,-1, 31,0);
    tracep->declBit(c+117,"hit", false,-1);
    tracep->declBus(c+295,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux3 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+290,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+94,"out", false,-1, 31,0);
    tracep->declBus(c+74,"key", false,-1, 0,0);
    tracep->declArray(c+118,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+289,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+290,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+94,"out", false,-1, 31,0);
    tracep->declBus(c+74,"key", false,-1, 0,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+118,"lut", false,-1, 65,0);
    tracep->declBus(c+294,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+121+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+125+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+127,"lut_out", false,-1, 31,0);
    tracep->declBit(c+128,"hit", false,-1);
    tracep->declBus(c+295,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("csr_ctrl_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+28,"i_ccu_csr_ren", false,-1);
    tracep->declBus(c+27,"i_ccu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+29,"i_ccu_is_mret", false,-1);
    tracep->declBit(c+30,"i_ccu_is_ecall", false,-1);
    tracep->declBit(c+78,"i_ccu_csr_wen", false,-1);
    tracep->declBus(c+81,"i_ccu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"i_ccu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+69,"i_ccu_macuse_in", false,-1, 31,0);
    tracep->declBus(c+68,"i_ccu_mepc_in", false,-1, 31,0);
    tracep->declBus(c+90,"o_exu_csr_src", false,-1, 31,0);
    tracep->declBus(c+91,"o_exu_csr_npc", false,-1, 31,0);
    tracep->declBus(c+129,"mstatus", false,-1, 31,0);
    tracep->declBus(c+130,"mtvec", false,-1, 31,0);
    tracep->declBus(c+131,"mepc", false,-1, 31,0);
    tracep->declBus(c+132,"mcause", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+24,"i_pre_valid", false,-1);
    tracep->declBit(c+44,"o_pre_ready", false,-1);
    tracep->declBit(c+45,"o_post_valid", false,-1);
    tracep->declBit(c+65,"i_post_ready", false,-1);
    tracep->declBus(c+38,"i_exu_pc", false,-1, 31,0);
    tracep->declBus(c+32,"i_exu_alu_type", false,-1, 3,0);
    tracep->declBus(c+33,"i_exu_num_sel", false,-1, 1,0);
    tracep->declBus(c+34,"i_exu_imm", false,-1, 31,0);
    tracep->declBit(c+39,"i_exu_is_jal", false,-1);
    tracep->declBit(c+40,"i_exu_is_jalr", false,-1);
    tracep->declBit(c+41,"i_exu_is_brch", false,-1);
    tracep->declBit(c+35,"i_exu_is_load", false,-1);
    tracep->declBit(c+36,"i_exu_is_store", false,-1);
    tracep->declBus(c+37,"i_exu_func3", false,-1, 2,0);
    tracep->declBus(c+42,"i_exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"i_exu_gpr_wen", false,-1);
    tracep->declBus(c+31,"i_exu_csr_type", false,-1, 1,0);
    tracep->declBus(c+27,"i_exu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+28,"i_exu_csr_ren", false,-1);
    tracep->declBit(c+29,"i_exu_is_mret", false,-1);
    tracep->declBit(c+30,"i_exu_is_ecall", false,-1);
    tracep->declBus(c+88,"i_exu_rs1", false,-1, 31,0);
    tracep->declBus(c+89,"i_exu_rs2", false,-1, 31,0);
    tracep->declBus(c+90,"i_exu_csr_src", false,-1, 31,0);
    tracep->declBus(c+91,"i_exu_csr_npc", false,-1, 31,0);
    tracep->declBus(c+46,"o_exu_exu_res", false,-1, 31,0);
    tracep->declBit(c+47,"o_exu_is_load", false,-1);
    tracep->declBit(c+48,"o_exu_is_store", false,-1);
    tracep->declBus(c+49,"o_exu_func3", false,-1, 2,0);
    tracep->declBus(c+50,"o_exu_rs1", false,-1, 31,0);
    tracep->declBus(c+51,"o_exu_rs2", false,-1, 31,0);
    tracep->declBus(c+52,"o_exu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+53,"o_exu_is_mret", false,-1);
    tracep->declBit(c+54,"o_exu_is_ecall", false,-1);
    tracep->declBus(c+55,"o_exu_imm", false,-1, 31,0);
    tracep->declBus(c+56,"o_exu_pc", false,-1, 31,0);
    tracep->declBit(c+57,"o_exu_is_jal", false,-1);
    tracep->declBit(c+58,"o_exu_is_jalr", false,-1);
    tracep->declBit(c+59,"o_exu_brch", false,-1);
    tracep->declBus(c+60,"o_exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"o_exu_gpr_wen", false,-1);
    tracep->declBus(c+62,"o_exu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"o_exu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+64,"o_exu_csr_wen", false,-1);
    tracep->declBus(c+133,"exu_alu_result", false,-1, 31,0);
    tracep->declBit(c+35,"exu_is_load", false,-1);
    tracep->declBit(c+36,"exu_is_store", false,-1);
    tracep->declBus(c+37,"exu_func3", false,-1, 2,0);
    tracep->declBus(c+88,"exu_rs1", false,-1, 31,0);
    tracep->declBus(c+89,"exu_rs2", false,-1, 31,0);
    tracep->declBus(c+91,"exu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+29,"exu_is_mret", false,-1);
    tracep->declBit(c+30,"exu_is_ecall", false,-1);
    tracep->declBus(c+34,"exu_imm", false,-1, 31,0);
    tracep->declBus(c+38,"exu_pc", false,-1, 31,0);
    tracep->declBit(c+39,"exu_is_jal", false,-1);
    tracep->declBit(c+40,"exu_is_jalr", false,-1);
    tracep->declBit(c+134,"exu_brch", false,-1);
    tracep->declBus(c+42,"exu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"exu_gpr_wen", false,-1);
    tracep->declBus(c+27,"exu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+135,"exu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+28,"exu_csr_wen", false,-1);
    tracep->declBus(c+136,"exu_alu_res", false,-1, 31,0);
    tracep->declBus(c+137,"num1", false,-1, 31,0);
    tracep->declBus(c+138,"num2", false,-1, 31,0);
    tracep->declBus(c+139,"num2_neg", false,-1, 31,0);
    tracep->declBit(c+140,"exu_reg_wen", false,-1);
    tracep->declArray(c+141,"exu_valid_data_reg", false,-1, 252,0);
    tracep->declBit(c+45,"post_valid_reg", false,-1);
    tracep->pushNamePrefix("mux1 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+289,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+137,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declArray(c+149,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+289,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+137,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+149,"lut", false,-1, 135,0);
    tracep->declBus(c+297,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+154+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+162+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+166,"lut_out", false,-1, 31,0);
    tracep->declBit(c+167,"hit", false,-1);
    tracep->declBus(c+298,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux2 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+289,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declArray(c+168,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+289,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+138,"out", false,-1, 31,0);
    tracep->declBus(c+33,"key", false,-1, 1,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+168,"lut", false,-1, 135,0);
    tracep->declBus(c+297,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+173+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+11+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+181+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+185,"lut_out", false,-1, 31,0);
    tracep->declBit(c+186,"hit", false,-1);
    tracep->declBus(c+298,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mux3 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+289,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+135,"out", false,-1, 31,0);
    tracep->declBus(c+31,"key", false,-1, 1,0);
    tracep->declArray(c+187,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+296,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+289,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+291,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+292,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+135,"out", false,-1, 31,0);
    tracep->declBus(c+31,"key", false,-1, 1,0);
    tracep->declBus(c+293,"default_out", false,-1, 31,0);
    tracep->declArray(c+187,"lut", false,-1, 135,0);
    tracep->declBus(c+297,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+192+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+15+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+200+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+204,"lut_out", false,-1, 31,0);
    tracep->declBit(c+205,"hit", false,-1);
    tracep->declBus(c+298,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("idu_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+20,"i_pre_valid", false,-1);
    tracep->declBit(c+23,"o_pre_ready", false,-1);
    tracep->declBit(c+24,"o_post_valid", false,-1);
    tracep->declBit(c+44,"i_post_ready", false,-1);
    tracep->declBus(c+21,"i_idu_pc", false,-1, 31,0);
    tracep->declBus(c+22,"i_idu_inst", false,-1, 31,0);
    tracep->declBus(c+25,"o_idu_rs_id1", false,-1, 4,0);
    tracep->declBus(c+26,"o_idu_rs_id2", false,-1, 4,0);
    tracep->declBus(c+27,"o_idu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+28,"o_idu_csr_ren", false,-1);
    tracep->declBit(c+29,"o_idu_is_mret", false,-1);
    tracep->declBit(c+30,"o_idu_is_ecall", false,-1);
    tracep->declBus(c+31,"o_idu_csr_type", false,-1, 1,0);
    tracep->declBus(c+32,"o_idu_alu_type", false,-1, 3,0);
    tracep->declBus(c+33,"o_idu_num_sel", false,-1, 1,0);
    tracep->declBus(c+34,"o_idu_imm", false,-1, 31,0);
    tracep->declBit(c+35,"o_idu_is_load", false,-1);
    tracep->declBit(c+36,"o_idu_is_store", false,-1);
    tracep->declBus(c+37,"o_idu_func3", false,-1, 2,0);
    tracep->declBus(c+38,"o_idu_pc", false,-1, 31,0);
    tracep->declBit(c+39,"o_idu_is_jal", false,-1);
    tracep->declBit(c+40,"o_idu_is_jalr", false,-1);
    tracep->declBit(c+41,"o_idu_is_brch", false,-1);
    tracep->declBus(c+42,"o_idu_rd_id", false,-1, 4,0);
    tracep->declBit(c+43,"o_idu_gpr_wen", false,-1);
    tracep->declBus(c+206,"idu_rs_id1", false,-1, 4,0);
    tracep->declBus(c+207,"idu_rs_id2", false,-1, 4,0);
    tracep->declBus(c+208,"idu_csr_rid", false,-1, 11,0);
    tracep->declBit(c+209,"idu_csr_ren", false,-1);
    tracep->declBit(c+210,"idu_is_mret", false,-1);
    tracep->declBit(c+211,"idu_is_ecall", false,-1);
    tracep->declBus(c+212,"idu_csr_type", false,-1, 1,0);
    tracep->declBus(c+213,"idu_alu_type", false,-1, 3,0);
    tracep->declBus(c+214,"idu_num_sel", false,-1, 1,0);
    tracep->declBus(c+215,"idu_imm", false,-1, 31,0);
    tracep->declBit(c+216,"idu_is_load", false,-1);
    tracep->declBit(c+217,"idu_is_store", false,-1);
    tracep->declBus(c+218,"idu_func3", false,-1, 2,0);
    tracep->declBus(c+21,"idu_pc", false,-1, 31,0);
    tracep->declBit(c+219,"idu_is_jal", false,-1);
    tracep->declBit(c+220,"idu_is_jalr", false,-1);
    tracep->declBit(c+221,"idu_is_brch", false,-1);
    tracep->declBus(c+222,"idu_rd_id", false,-1, 4,0);
    tracep->declBit(c+223,"idu_gpr_wen", false,-1);
    tracep->declBus(c+224,"opcode", false,-1, 6,0);
    tracep->declBus(c+222,"rd_id", false,-1, 4,0);
    tracep->declBus(c+218,"func3", false,-1, 2,0);
    tracep->declBus(c+225,"rs_id1", false,-1, 4,0);
    tracep->declBus(c+207,"rs_id2", false,-1, 4,0);
    tracep->declBus(c+226,"func7", false,-1, 6,0);
    tracep->declBit(c+227,"idu_reg_wen", false,-1);
    tracep->declArray(c+228,"idu_valid_data_reg", false,-1, 110,0);
    tracep->declBit(c+24,"post_valid_reg", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+84,"i_cycle_end", false,-1);
    tracep->declBit(c+20,"o_post_valid", false,-1);
    tracep->declBit(c+23,"i_post_ready", false,-1);
    tracep->declBus(c+87,"i_ifu_npc", false,-1, 31,0);
    tracep->declBus(c+21,"o_ifu_pc", false,-1, 31,0);
    tracep->declBus(c+22,"o_ifu_inst", false,-1, 31,0);
    tracep->declBit(c+232,"s_if_valid", false,-1);
    tracep->declBus(c+233,"s_if_rdata", false,-1, 31,0);
    tracep->declBit(c+234,"s_if_req", false,-1);
    tracep->declBus(c+235,"s_if_addr_reg", false,-1, 31,0);
    tracep->declQuad(c+236,"ifu_valid_data_reg", false,-1, 63,0);
    tracep->declBit(c+20,"ifu_valid_hold", false,-1);
    tracep->pushNamePrefix("u_sram_ifu ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+234,"i_req", false,-1);
    tracep->declBus(c+235,"i_addr", false,-1, 31,0);
    tracep->declBit(c+232,"o_valid", false,-1);
    tracep->declBus(c+233,"o_rdata", false,-1, 31,0);
    tracep->declBus(c+238,"rdata_reg", false,-1, 31,0);
    tracep->declBit(c+239,"pend", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("lsu_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+45,"i_pre_valid", false,-1);
    tracep->declBit(c+65,"o_pre_ready", false,-1);
    tracep->declBit(c+66,"o_post_valid", false,-1);
    tracep->declBit(c+83,"i_post_ready", false,-1);
    tracep->declBus(c+56,"i_lsu_pc", false,-1, 31,0);
    tracep->declBit(c+47,"i_lsu_is_load", false,-1);
    tracep->declBit(c+48,"i_lsu_is_store", false,-1);
    tracep->declBus(c+49,"i_lsu_func3", false,-1, 2,0);
    tracep->declBus(c+55,"i_lsu_imm", false,-1, 31,0);
    tracep->declBit(c+57,"i_lsu_is_jal", false,-1);
    tracep->declBit(c+58,"i_lsu_is_jalr", false,-1);
    tracep->declBit(c+59,"i_lsu_brch", false,-1);
    tracep->declBus(c+60,"i_lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"i_lsu_gpr_wen", false,-1);
    tracep->declBus(c+50,"i_lsu_rs1", false,-1, 31,0);
    tracep->declBus(c+51,"i_lsu_rs2", false,-1, 31,0);
    tracep->declBus(c+52,"i_lsu_csr_npc", false,-1, 31,0);
    tracep->declBus(c+62,"i_lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"i_lsu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+64,"i_lsu_csr_wen", false,-1);
    tracep->declBit(c+53,"i_lsu_is_mret", false,-1);
    tracep->declBit(c+54,"i_lsu_is_ecall", false,-1);
    tracep->declBus(c+46,"i_lsu_exu_res", false,-1, 31,0);
    tracep->declBus(c+67,"o_lsu_imm", false,-1, 31,0);
    tracep->declBus(c+68,"o_lsu_pc", false,-1, 31,0);
    tracep->declBus(c+69,"o_lsu_rs1", false,-1, 31,0);
    tracep->declBit(c+70,"o_lsu_is_jal", false,-1);
    tracep->declBit(c+71,"o_lsu_is_jalr", false,-1);
    tracep->declBit(c+72,"o_lsu_brch", false,-1);
    tracep->declBus(c+73,"o_lsu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+74,"o_lsu_is_ejump", false,-1);
    tracep->declBus(c+75,"o_lsu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"o_lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+77,"o_lsu_gpr_wen", false,-1);
    tracep->declBit(c+78,"o_lsu_csr_wen", false,-1);
    tracep->declBit(c+79,"o_lsu_is_mret", false,-1);
    tracep->declBit(c+80,"o_lsu_is_ecall", false,-1);
    tracep->declBus(c+81,"o_lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"o_lsu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+55,"lsu_imm", false,-1, 31,0);
    tracep->declBus(c+56,"lsu_pc", false,-1, 31,0);
    tracep->declBus(c+50,"lsu_rs1", false,-1, 31,0);
    tracep->declBit(c+57,"lsu_is_jal", false,-1);
    tracep->declBit(c+58,"lsu_is_jalr", false,-1);
    tracep->declBit(c+59,"lsu_brch", false,-1);
    tracep->declBus(c+52,"lsu_csr_npc", false,-1, 31,0);
    tracep->declBit(c+240,"lsu_is_ejump", false,-1);
    tracep->declBus(c+299,"lsu_rd", false,-1, 31,0);
    tracep->declBus(c+60,"lsu_rd_id", false,-1, 4,0);
    tracep->declBit(c+61,"lsu_gpr_wen", false,-1);
    tracep->declBit(c+64,"lsu_csr_wen", false,-1);
    tracep->declBit(c+53,"lsu_is_mret", false,-1);
    tracep->declBit(c+54,"lsu_is_ecall", false,-1);
    tracep->declBus(c+62,"lsu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+63,"lsu_csr_rd", false,-1, 31,0);
    tracep->declBus(c+46,"dmem_raddr", false,-1, 31,0);
    tracep->declBus(c+300,"dmem_rdata_t", false,-1, 31,0);
    tracep->declBus(c+241,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+46,"dmem_waddr", false,-1, 31,0);
    tracep->declBus(c+51,"dmem_wdata", false,-1, 31,0);
    tracep->declBus(c+242,"wmask", false,-1, 7,0);
    tracep->declBit(c+243,"lsu_reg_wen", false,-1);
    tracep->declArray(c+244,"lsu_valid_data_reg", false,-1, 216,0);
    tracep->declBit(c+66,"post_valid_reg", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+251,"raw_read_data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("register_file_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+86,"i_rf_gpr_wen", false,-1);
    tracep->declBus(c+76,"i_rf_rd_id", false,-1, 4,0);
    tracep->declBus(c+75,"i_rf_rd", false,-1, 31,0);
    tracep->declBus(c+25,"i_rf_rs_id1", false,-1, 4,0);
    tracep->declBus(c+26,"i_rf_rs_id2", false,-1, 4,0);
    tracep->declBus(c+88,"o_rf_rs1", false,-1, 31,0);
    tracep->declBus(c+89,"o_rf_rs2", false,-1, 31,0);
    tracep->declBus(c+252,"i", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+253+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("wbu_inst ");
    tracep->declBit(c+286,"clk", false,-1);
    tracep->declBit(c+287,"rst", false,-1);
    tracep->declBit(c+66,"i_pre_valid", false,-1);
    tracep->declBit(c+83,"o_pre_ready", false,-1);
    tracep->declBit(c+84,"o_cycle_end", false,-1);
    tracep->declBus(c+68,"i_wbu_pc", false,-1, 31,0);
    tracep->declBus(c+76,"i_wbu_rd_id", false,-1, 4,0);
    tracep->declBit(c+77,"i_wbu_gpr_wen", false,-1);
    tracep->declBus(c+69,"i_wbu_rs1", false,-1, 31,0);
    tracep->declBit(c+79,"i_wbu_is_mret", false,-1);
    tracep->declBit(c+80,"i_wbu_is_ecall", false,-1);
    tracep->declBus(c+81,"i_wbu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"i_wbu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+78,"i_wbu_csr_wen", false,-1);
    tracep->declBus(c+75,"i_wbu_rd", false,-1, 31,0);
    tracep->declBit(c+85,"o_wbu_npc_wen", false,-1);
    tracep->declBus(c+75,"o_wbu_rd", false,-1, 31,0);
    tracep->declBus(c+76,"o_wbu_rd_id", false,-1, 4,0);
    tracep->declBit(c+86,"o_wbu_gpr_wen", false,-1);
    tracep->declBus(c+69,"o_wbu_mcause_in", false,-1, 31,0);
    tracep->declBus(c+68,"o_wbu_mepc_in", false,-1, 31,0);
    tracep->declBit(c+78,"o_wbu_csr_wen", false,-1);
    tracep->declBus(c+81,"o_wbu_csr_wid", false,-1, 11,0);
    tracep->declBus(c+82,"o_wbu_csr_rd", false,-1, 31,0);
    tracep->declBit(c+285,"pre_valid_reg", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vrv32___024root__trace_init_top(Vrv32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_init_top\n"); );
    // Body
    Vrv32___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vrv32___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vrv32___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vrv32___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vrv32___024root__trace_register(Vrv32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vrv32___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vrv32___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vrv32___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vrv32___024root__trace_full_sub_0(Vrv32___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vrv32___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_full_top_0\n"); );
    // Init
    Vrv32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrv32___024root*>(voidSelf);
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vrv32___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vrv32___024root__trace_full_sub_0(Vrv32___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_hbe37180e__0;
    VlWide<3>/*95:0*/ __Vtemp_h094f6287__0;
    VlWide<3>/*95:0*/ __Vtemp_h2547afd7__0;
    VlWide<5>/*159:0*/ __Vtemp_hce12de26__0;
    VlWide<5>/*159:0*/ __Vtemp_hd74c99fb__0;
    VlWide<5>/*159:0*/ __Vtemp_h00174f39__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+3,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+4,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+5,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+6,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+7,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+8,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+9,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+10,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+11,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+12,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+13,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+14,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+15,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+16,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+17,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+18,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+19,(vlSelf->rv32__DOT__clk_cnt),3);
    bufp->fullBit(oldp+20,(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_hold));
    bufp->fullIData(oldp+21,((IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                      >> 0x20U))),32);
    bufp->fullIData(oldp+22,((IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)),32);
    bufp->fullBit(oldp+23,((1U & (~ (IData)(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg)))));
    bufp->fullBit(oldp+24,(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg));
    bufp->fullCData(oldp+25,((0x1fU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                       >> 0xaU))),5);
    bufp->fullCData(oldp+26,((0x1fU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                       >> 5U))),5);
    bufp->fullSData(oldp+27,((0xfffU & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                         << 7U) | (
                                                   vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                   >> 0x19U)))),12);
    bufp->fullBit(oldp+28,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  >> 0x18U))));
    bufp->fullBit(oldp+29,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  >> 0x17U))));
    bufp->fullBit(oldp+30,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  >> 0x16U))));
    bufp->fullCData(oldp+31,((3U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                    >> 0x14U))),2);
    bufp->fullCData(oldp+32,((0xfU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                      >> 0x10U))),4);
    bufp->fullCData(oldp+33,((3U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                    >> 0xeU))),2);
    bufp->fullIData(oldp+34,(((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                               << 0x12U) | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                            >> 0xeU))),32);
    bufp->fullBit(oldp+35,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                  >> 0xdU))));
    bufp->fullBit(oldp+36,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                  >> 0xcU))));
    bufp->fullCData(oldp+37,((7U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                    >> 9U))),3);
    bufp->fullIData(oldp+38,(((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                               << 0x17U) | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                            >> 9U))),32);
    bufp->fullBit(oldp+39,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                  >> 8U))));
    bufp->fullBit(oldp+40,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                  >> 7U))));
    bufp->fullBit(oldp+41,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                  >> 6U))));
    bufp->fullCData(oldp+42,((0x1fU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                       >> 1U))),5);
    bufp->fullBit(oldp+43,((1U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U])));
    bufp->fullBit(oldp+44,((1U & (~ (IData)(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg)))));
    bufp->fullBit(oldp+45,(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg));
    bufp->fullIData(oldp+46,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                               << 3U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                         >> 0x1dU))),32);
    bufp->fullBit(oldp+47,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                  >> 0x1cU))));
    bufp->fullBit(oldp+48,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                  >> 0x1bU))));
    bufp->fullCData(oldp+49,((7U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                    >> 0x18U))),3);
    bufp->fullIData(oldp+50,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                               << 8U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                         >> 0x18U))),32);
    bufp->fullIData(oldp+51,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                               << 8U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                         >> 0x18U))),32);
    bufp->fullIData(oldp+52,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                               << 8U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                         >> 0x18U))),32);
    bufp->fullBit(oldp+53,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                  >> 0x17U))));
    bufp->fullBit(oldp+54,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                  >> 0x16U))));
    bufp->fullIData(oldp+55,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                               << 0xaU) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                           >> 0x16U))),32);
    bufp->fullIData(oldp+56,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                               << 0xaU) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                           >> 0x16U))),32);
    bufp->fullBit(oldp+57,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0x15U))));
    bufp->fullBit(oldp+58,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0x14U))));
    bufp->fullBit(oldp+59,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0x13U))));
    bufp->fullCData(oldp+60,((0x1fU & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                       >> 0xeU))),5);
    bufp->fullBit(oldp+61,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  >> 0xdU))));
    bufp->fullSData(oldp+62,((0xfffU & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                        >> 1U))),12);
    bufp->fullIData(oldp+63,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                               << 0x1fU) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
                                            >> 1U))),32);
    bufp->fullBit(oldp+64,((1U & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[0U])));
    bufp->fullBit(oldp+65,((1U & (~ (IData)(vlSelf->rv32__DOT__lsu_inst__DOT__post_valid_reg)))));
    bufp->fullBit(oldp+66,(vlSelf->rv32__DOT__lsu_inst__DOT__post_valid_reg));
    bufp->fullIData(oldp+67,(((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[6U] 
                               << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                         >> 0x19U))),32);
    bufp->fullIData(oldp+68,(((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                               << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                         >> 0x19U))),32);
    bufp->fullIData(oldp+69,(((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                               << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                         >> 0x19U))),32);
    bufp->fullBit(oldp+70,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                  >> 0x18U))));
    bufp->fullBit(oldp+71,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                  >> 0x17U))));
    bufp->fullBit(oldp+72,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                  >> 0x16U))));
    bufp->fullIData(oldp+73,(((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                               << 0xaU) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                           >> 0x16U))),32);
    bufp->fullBit(oldp+74,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                  >> 0x15U))));
    bufp->fullIData(oldp+75,(((0x10000000U & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                               ? vlSelf->rv32__DOT__lsu_inst__DOT__dmem_rdata
                               : ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                   << 3U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                             >> 0x1dU)))),32);
    bufp->fullCData(oldp+76,((0x1fU & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                       >> 0x10U))),5);
    bufp->fullBit(oldp+77,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xfU))));
    bufp->fullBit(oldp+78,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xeU))));
    bufp->fullBit(oldp+79,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xdU))));
    bufp->fullBit(oldp+80,((1U & (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                                  >> 0xcU))));
    bufp->fullSData(oldp+81,((0xfffU & vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U])),12);
    bufp->fullIData(oldp+82,(vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[0U]),32);
    bufp->fullBit(oldp+83,((1U & (~ (IData)(vlSelf->rv32__DOT__w_wbu_cycle_end)))));
    bufp->fullBit(oldp+84,(vlSelf->rv32__DOT__w_wbu_cycle_end));
    bufp->fullBit(oldp+85,(vlSelf->rv32__DOT__w_wbu_npc_wen));
    bufp->fullBit(oldp+86,(((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[1U] 
                             >> 0xfU) & (IData)(vlSelf->rv32__DOT__w_wbu_npc_wen))));
    bufp->fullIData(oldp+87,(vlSelf->rv32__DOT__bru_inst__DOT__npc_reg),32);
    bufp->fullIData(oldp+88,(vlSelf->rv32__DOT__w_rf_rs1),32);
    bufp->fullIData(oldp+89,(vlSelf->rv32__DOT__w_rf_rs2),32);
    bufp->fullIData(oldp+90,(vlSelf->rv32__DOT__w_cc_csr_src),32);
    bufp->fullIData(oldp+91,(((0x800000U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                               ? vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mepc
                               : ((0x400000U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                   ? vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mtvec
                                   : 0xdead005aU))),32);
    bufp->fullIData(oldp+92,(vlSelf->rv32__DOT__bru_inst__DOT__pc_jorb),32);
    bufp->fullIData(oldp+93,(vlSelf->rv32__DOT__bru_inst__DOT__npc_t1),32);
    bufp->fullIData(oldp+94,(vlSelf->rv32__DOT__bru_inst__DOT__npc_t2),32);
    __Vtemp_hbe37180e__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(
                                                          (0xfffffffeU 
                                                           & (((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[6U] 
                                                                << 7U) 
                                                               | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                                  >> 0x19U)) 
                                                              + 
                                                              ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                                << 7U) 
                                                               | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                                  >> 0x19U))))))));
    __Vtemp_hbe37180e__0[1U] = (((((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[6U] 
                                    << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                              >> 0x19U)) 
                                  + ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                      << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                >> 0x19U))) 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(
                                                                      (0xfffffffeU 
                                                                       & (((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[6U] 
                                                                            << 7U) 
                                                                           | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                                              >> 0x19U)) 
                                                                          + 
                                                                          ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                                            << 7U) 
                                                                           | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                                              >> 0x19U))))))) 
                                                   >> 0x20U)));
    __Vtemp_hbe37180e__0[2U] = ((((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[6U] 
                                   << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                             >> 0x19U)) 
                                 + ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                     << 7U) | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                               >> 0x19U))) 
                                >> 0x1fU);
    bufp->fullWData(oldp+95,(__Vtemp_hbe37180e__0),66);
    bufp->fullQData(oldp+98,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+100,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+102,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+103,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+104,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+105,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+106,(vlSelf->rv32__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2));
    __Vtemp_h094f6287__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->rv32__DOT__bru_inst__DOT__pc_jorb))));
    __Vtemp_h094f6287__0[1U] = ((((IData)(4U) + ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                  << 7U) 
                                                 | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                    >> 0x19U))) 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->rv32__DOT__bru_inst__DOT__pc_jorb))) 
                                                   >> 0x20U)));
    __Vtemp_h094f6287__0[2U] = (((IData)(4U) + ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[5U] 
                                                 << 7U) 
                                                | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[4U] 
                                                   >> 0x19U))) 
                                >> 0x1fU);
    bufp->fullWData(oldp+107,(__Vtemp_h094f6287__0),66);
    bufp->fullQData(oldp+110,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+112,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+114,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+115,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+116,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+117,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit));
    __Vtemp_h2547afd7__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(
                                                          ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                            << 0xaU) 
                                                           | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                              >> 0x16U))))));
    __Vtemp_h2547afd7__0[1U] = ((vlSelf->rv32__DOT__bru_inst__DOT__npc_t1 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(
                                                                      ((vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[3U] 
                                                                        << 0xaU) 
                                                                       | (vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg[2U] 
                                                                          >> 0x16U))))) 
                                                   >> 0x20U)));
    __Vtemp_h2547afd7__0[2U] = (vlSelf->rv32__DOT__bru_inst__DOT__npc_t1 
                                >> 0x1fU);
    bufp->fullWData(oldp+118,(__Vtemp_h2547afd7__0),66);
    bufp->fullQData(oldp+121,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+123,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+125,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+126,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+127,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+128,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+129,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mstatus),32);
    bufp->fullIData(oldp+130,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mtvec),32);
    bufp->fullIData(oldp+131,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mepc),32);
    bufp->fullIData(oldp+132,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mcause),32);
    bufp->fullIData(oldp+133,(((0x1000000U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                ? vlSelf->rv32__DOT__w_cc_csr_src
                                : vlSelf->rv32__DOT__exu_inst__DOT__exu_alu_res)),32);
    bufp->fullBit(oldp+134,((1U & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                    >> 6U) & vlSelf->rv32__DOT__exu_inst__DOT__exu_alu_res))));
    bufp->fullIData(oldp+135,(vlSelf->rv32__DOT__exu_inst__DOT__exu_csr_rd),32);
    bufp->fullIData(oldp+136,(vlSelf->rv32__DOT__exu_inst__DOT__exu_alu_res),32);
    bufp->fullIData(oldp+137,(vlSelf->rv32__DOT__exu_inst__DOT__num1),32);
    bufp->fullIData(oldp+138,(vlSelf->rv32__DOT__exu_inst__DOT__num2),32);
    bufp->fullIData(oldp+139,(((IData)(1U) + (~ vlSelf->rv32__DOT__exu_inst__DOT__num2))),32);
    bufp->fullBit(oldp+140,(((~ (IData)(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg)) 
                             & (IData)(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg))));
    bufp->fullWData(oldp+141,(vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg),253);
    __Vtemp_hce12de26__0[0U] = (IData)((0x300000000ULL 
                                        | (QData)((IData)(
                                                          ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                            << 0x17U) 
                                                           | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                              >> 9U))))));
    __Vtemp_hce12de26__0[1U] = ((0xfffffffcU & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                 << 0x19U) 
                                                | (0x1fffffcU 
                                                   & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                      >> 7U)))) 
                                | (IData)(((0x300000000ULL 
                                            | (QData)((IData)(
                                                              ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                << 0x17U) 
                                                               | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                  >> 9U))))) 
                                           >> 0x20U)));
    __Vtemp_hce12de26__0[2U] = (8U | ((vlSelf->rv32__DOT__w_rf_rs1 
                                       << 4U) | (3U 
                                                 & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                    >> 7U))));
    __Vtemp_hce12de26__0[3U] = (0x10U | ((vlSelf->rv32__DOT__w_rf_rs1 
                                          << 6U) | 
                                         (vlSelf->rv32__DOT__w_rf_rs1 
                                          >> 0x1cU)));
    __Vtemp_hce12de26__0[4U] = (vlSelf->rv32__DOT__w_rf_rs1 
                                >> 0x1aU);
    bufp->fullWData(oldp+149,(__Vtemp_hce12de26__0),136);
    bufp->fullQData(oldp+154,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+156,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+158,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+160,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+162,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+163,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+164,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+165,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+166,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+167,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit));
    __Vtemp_hd74c99fb__0[0U] = 4U;
    __Vtemp_hd74c99fb__0[1U] = (3U | (0xfffffffcU & 
                                      ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                        << 0x14U) | 
                                       (0xffffcU & 
                                        (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                         >> 0xcU)))));
    __Vtemp_hd74c99fb__0[2U] = (8U | ((0xfffffff0U 
                                       & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                           << 0x16U) 
                                          | (0x3ffff0U 
                                             & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                >> 0xaU)))) 
                                      | (3U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                               >> 0xcU))));
    __Vtemp_hd74c99fb__0[3U] = (0x10U | ((vlSelf->rv32__DOT__w_rf_rs2 
                                          << 6U) | 
                                         (0xfU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                  >> 0xaU))));
    __Vtemp_hd74c99fb__0[4U] = (vlSelf->rv32__DOT__w_rf_rs2 
                                >> 0x1aU);
    bufp->fullWData(oldp+168,(__Vtemp_hd74c99fb__0),136);
    bufp->fullQData(oldp+173,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+175,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+177,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+179,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+181,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+182,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+183,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+184,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+185,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+186,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit));
    __Vtemp_h00174f39__0[0U] = (IData)((0x300000000ULL 
                                        | (QData)((IData)(
                                                          ((~ vlSelf->rv32__DOT__w_cc_csr_src) 
                                                           & vlSelf->rv32__DOT__w_rf_rs1)))));
    __Vtemp_h00174f39__0[1U] = (((vlSelf->rv32__DOT__w_cc_csr_src 
                                  | vlSelf->rv32__DOT__w_rf_rs1) 
                                 << 2U) | (IData)((
                                                   (0x300000000ULL 
                                                    | (QData)((IData)(
                                                                      ((~ vlSelf->rv32__DOT__w_cc_csr_src) 
                                                                       & vlSelf->rv32__DOT__w_rf_rs1)))) 
                                                   >> 0x20U)));
    __Vtemp_h00174f39__0[2U] = (8U | ((vlSelf->rv32__DOT__w_rf_rs1 
                                       << 4U) | ((vlSelf->rv32__DOT__w_cc_csr_src 
                                                  | vlSelf->rv32__DOT__w_rf_rs1) 
                                                 >> 0x1eU)));
    __Vtemp_h00174f39__0[3U] = (0x10U | (vlSelf->rv32__DOT__w_rf_rs1 
                                         >> 0x1cU));
    __Vtemp_h00174f39__0[4U] = 0U;
    bufp->fullWData(oldp+187,(__Vtemp_h00174f39__0),136);
    bufp->fullQData(oldp+192,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+194,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+196,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+198,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+200,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+201,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+202,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+203,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+204,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+205,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+206,(((IData)(vlSelf->rv32__DOT__idu_inst__DOT__idu_is_ecall)
                                ? 0xfU : ((0x37U == 
                                           (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))
                                           ? 0U : (0x1fU 
                                                   & (IData)(
                                                             (vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                              >> 0xfU)))))),5);
    bufp->fullCData(oldp+207,((0x1fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0x14U)))),5);
    bufp->fullSData(oldp+208,((0xfffU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                 >> 0x14U)))),12);
    bufp->fullBit(oldp+209,(vlSelf->rv32__DOT__idu_inst__DOT__idu_csr_ren));
    bufp->fullBit(oldp+210,(vlSelf->rv32__DOT__idu_inst__DOT__idu_is_mret));
    bufp->fullBit(oldp+211,(vlSelf->rv32__DOT__idu_inst__DOT__idu_is_ecall));
    bufp->fullCData(oldp+212,(vlSelf->rv32__DOT__idu_inst__DOT__idu_csr_type),2);
    bufp->fullCData(oldp+213,(vlSelf->rv32__DOT__idu_inst__DOT__idu_alu_type),4);
    bufp->fullCData(oldp+214,(vlSelf->rv32__DOT__idu_inst__DOT__idu_num_sel),2);
    bufp->fullIData(oldp+215,(vlSelf->rv32__DOT__idu_inst__DOT__idu_imm),32);
    bufp->fullBit(oldp+216,((3U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullBit(oldp+217,((0x23U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullCData(oldp+218,((7U & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                             >> 0xcU)))),3);
    bufp->fullBit(oldp+219,((0x6fU == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullBit(oldp+220,((0x67U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullBit(oldp+221,((0x63U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
    bufp->fullCData(oldp+222,((0x1fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 7U)))),5);
    bufp->fullBit(oldp+223,(vlSelf->rv32__DOT__idu_inst__DOT__idu_gpr_wen));
    bufp->fullCData(oldp+224,((0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg))),7);
    bufp->fullCData(oldp+225,((0x1fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0xfU)))),5);
    bufp->fullCData(oldp+226,((0x7fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0x19U)))),7);
    bufp->fullBit(oldp+227,(((~ (IData)(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg)) 
                             & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_hold))));
    bufp->fullWData(oldp+228,(vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg),111);
    bufp->fullBit(oldp+232,(vlSelf->rv32__DOT__ifu_inst__DOT__s_if_valid));
    bufp->fullIData(oldp+233,(vlSelf->rv32__DOT__ifu_inst__DOT__s_if_rdata),32);
    bufp->fullBit(oldp+234,(vlSelf->rv32__DOT__ifu_inst__DOT__s_if_req));
    bufp->fullIData(oldp+235,(vlSelf->rv32__DOT__ifu_inst__DOT__s_if_addr_reg),32);
    bufp->fullQData(oldp+236,(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg),64);
    bufp->fullIData(oldp+238,(vlSelf->rv32__DOT__ifu_inst__DOT__u_sram_ifu__DOT__rdata_reg),32);
    bufp->fullBit(oldp+239,(vlSelf->rv32__DOT__ifu_inst__DOT__u_sram_ifu__DOT__pend));
    bufp->fullBit(oldp+240,((IData)((0U != (0xc00000U 
                                            & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U])))));
    bufp->fullIData(oldp+241,(vlSelf->rv32__DOT__lsu_inst__DOT__dmem_rdata),32);
    bufp->fullCData(oldp+242,(vlSelf->rv32__DOT__lsu_inst__DOT__wmask),8);
    bufp->fullBit(oldp+243,(((~ (IData)(vlSelf->rv32__DOT__lsu_inst__DOT__post_valid_reg)) 
                             & (IData)(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg))));
    bufp->fullWData(oldp+244,(vlSelf->rv32__DOT__lsu_inst__DOT__lsu_valid_data_reg),217);
    bufp->fullIData(oldp+251,(vlSelf->rv32__DOT__lsu_inst__DOT__unnamedblk1__DOT__raw_read_data),32);
    bufp->fullIData(oldp+252,(vlSelf->rv32__DOT__register_file_inst__DOT__i),32);
    bufp->fullIData(oldp+253,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[0]),32);
    bufp->fullIData(oldp+254,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[1]),32);
    bufp->fullIData(oldp+255,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[2]),32);
    bufp->fullIData(oldp+256,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[3]),32);
    bufp->fullIData(oldp+257,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[4]),32);
    bufp->fullIData(oldp+258,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[5]),32);
    bufp->fullIData(oldp+259,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[6]),32);
    bufp->fullIData(oldp+260,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[7]),32);
    bufp->fullIData(oldp+261,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[8]),32);
    bufp->fullIData(oldp+262,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[9]),32);
    bufp->fullIData(oldp+263,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[10]),32);
    bufp->fullIData(oldp+264,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[11]),32);
    bufp->fullIData(oldp+265,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[12]),32);
    bufp->fullIData(oldp+266,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[13]),32);
    bufp->fullIData(oldp+267,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[14]),32);
    bufp->fullIData(oldp+268,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[15]),32);
    bufp->fullIData(oldp+269,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[16]),32);
    bufp->fullIData(oldp+270,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[17]),32);
    bufp->fullIData(oldp+271,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[18]),32);
    bufp->fullIData(oldp+272,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[19]),32);
    bufp->fullIData(oldp+273,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[20]),32);
    bufp->fullIData(oldp+274,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[21]),32);
    bufp->fullIData(oldp+275,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[22]),32);
    bufp->fullIData(oldp+276,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[23]),32);
    bufp->fullIData(oldp+277,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[24]),32);
    bufp->fullIData(oldp+278,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[25]),32);
    bufp->fullIData(oldp+279,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[26]),32);
    bufp->fullIData(oldp+280,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[27]),32);
    bufp->fullIData(oldp+281,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[28]),32);
    bufp->fullIData(oldp+282,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[29]),32);
    bufp->fullIData(oldp+283,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[30]),32);
    bufp->fullIData(oldp+284,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[31]),32);
    bufp->fullBit(oldp+285,(vlSelf->rv32__DOT__wbu_inst__DOT__pre_valid_reg));
    bufp->fullBit(oldp+286,(vlSelf->clk));
    bufp->fullBit(oldp+287,(vlSelf->rst));
    bufp->fullIData(oldp+288,(0xfffffffeU),32);
    bufp->fullIData(oldp+289,(2U),32);
    bufp->fullIData(oldp+290,(1U),32);
    bufp->fullIData(oldp+291,(0x20U),32);
    bufp->fullIData(oldp+292,(0U),32);
    bufp->fullIData(oldp+293,(0U),32);
    bufp->fullIData(oldp+294,(0x21U),32);
    bufp->fullIData(oldp+295,(2U),32);
    bufp->fullIData(oldp+296,(4U),32);
    bufp->fullIData(oldp+297,(0x22U),32);
    bufp->fullIData(oldp+298,(4U),32);
    bufp->fullIData(oldp+299,(vlSelf->rv32__DOT__lsu_inst__DOT__lsu_rd),32);
    bufp->fullIData(oldp+300,(vlSelf->rv32__DOT__lsu_inst__DOT__dmem_rdata_t),32);
}

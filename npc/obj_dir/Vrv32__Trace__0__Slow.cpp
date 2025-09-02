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
    tracep->declBit(c+149,"clk", false,-1);
    tracep->declBit(c+150,"rst", false,-1);
    tracep->pushNamePrefix("rv32 ");
    tracep->declBit(c+149,"clk", false,-1);
    tracep->declBit(c+150,"rst", false,-1);
    tracep->declBus(c+13,"rs1", false,-1, 4,0);
    tracep->declBus(c+14,"rs2", false,-1, 4,0);
    tracep->declBus(c+15,"rd", false,-1, 4,0);
    tracep->declBus(c+16,"funct3", false,-1, 2,0);
    tracep->declBus(c+17,"funct7", false,-1, 6,0);
    tracep->declBus(c+18,"inst", false,-1, 31,0);
    tracep->declBus(c+19,"pc", false,-1, 31,0);
    tracep->declBus(c+20,"Inst_type", false,-1, 2,0);
    tracep->declBit(c+21,"reg_wen", false,-1);
    tracep->declBit(c+22,"mem_wen", false,-1);
    tracep->declBit(c+23,"mem_ren", false,-1);
    tracep->declBus(c+24,"wmask", false,-1, 7,0);
    tracep->declBus(c+25,"rmask", false,-1, 2,0);
    tracep->declBit(c+26,"pc_sel_1", false,-1);
    tracep->declBit(c+27,"pc_sel_2", false,-1);
    tracep->declBit(c+28,"alu_sel_2", false,-1);
    tracep->declBit(c+29,"alu_sel_1", false,-1);
    tracep->declBus(c+30,"wb_sel", false,-1, 1,0);
    tracep->declBus(c+31,"aluc", false,-1, 4,0);
    tracep->declBus(c+32,"PCadd4", false,-1, 31,0);
    tracep->declBus(c+33,"result", false,-1, 31,0);
    tracep->declBus(c+34,"reg_in", false,-1, 31,0);
    tracep->declBus(c+35,"src1", false,-1, 31,0);
    tracep->declBus(c+36,"src2", false,-1, 31,0);
    tracep->declBus(c+37,"imm32", false,-1, 31,0);
    tracep->declBus(c+38,"num1", false,-1, 31,0);
    tracep->declBus(c+39,"num2", false,-1, 31,0);
    tracep->declBus(c+40,"mem_rdata", false,-1, 31,0);
    tracep->pushNamePrefix("PC_inst ");
    tracep->declBit(c+149,"clk", false,-1);
    tracep->declBit(c+150,"rst", false,-1);
    tracep->declBit(c+26,"pc_sel_1", false,-1);
    tracep->declBit(c+27,"pc_sel_2", false,-1);
    tracep->declBus(c+33,"result", false,-1, 31,0);
    tracep->declBus(c+37,"imm32", false,-1, 31,0);
    tracep->declBus(c+32,"PCadd4", false,-1, 31,0);
    tracep->declBus(c+19,"pc", false,-1, 31,0);
    tracep->declBus(c+41,"npc", false,-1, 31,0);
    tracep->declBus(c+42,"npc_temp", false,-1, 31,0);
    tracep->declBus(c+43,"PCaddIMM32", false,-1, 31,0);
    tracep->pushNamePrefix("i1 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+41,"out", false,-1, 31,0);
    tracep->declBus(c+44,"key", false,-1, 0,0);
    tracep->declArray(c+45,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+154,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+41,"out", false,-1, 31,0);
    tracep->declBus(c+44,"key", false,-1, 0,0);
    tracep->declBus(c+155,"default_out", false,-1, 31,0);
    tracep->declArray(c+45,"lut", false,-1, 65,0);
    tracep->declBus(c+156,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+48+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+52+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+54,"lut_out", false,-1, 31,0);
    tracep->declBit(c+55,"hit", false,-1);
    tracep->declBus(c+157,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i2 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+42,"out", false,-1, 31,0);
    tracep->declBus(c+27,"key", false,-1, 0,0);
    tracep->declArray(c+56,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+154,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+42,"out", false,-1, 31,0);
    tracep->declBus(c+27,"key", false,-1, 0,0);
    tracep->declBus(c+155,"default_out", false,-1, 31,0);
    tracep->declArray(c+56,"lut", false,-1, 65,0);
    tracep->declBus(c+156,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+59+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+63+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+65,"lut_out", false,-1, 31,0);
    tracep->declBit(c+66,"hit", false,-1);
    tracep->declBus(c+157,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("alu_inst ");
    tracep->declBus(c+31,"aluc", false,-1, 4,0);
    tracep->declBus(c+38,"num1", false,-1, 31,0);
    tracep->declBus(c+39,"num2", false,-1, 31,0);
    tracep->declBus(c+33,"result", false,-1, 31,0);
    tracep->declBus(c+158,"temp", false,-1, 31,0);
    tracep->declBus(c+67,"num2_cplm", false,-1, 31,0);
    tracep->declBus(c+68,"num2_temp", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("control_unit_inst ");
    tracep->declBus(c+18,"inst", false,-1, 31,0);
    tracep->declBus(c+15,"rd_11_7", false,-1, 4,0);
    tracep->declBus(c+13,"rs1_19_15", false,-1, 4,0);
    tracep->declBus(c+14,"rs2_24_20", false,-1, 4,0);
    tracep->declBus(c+16,"fun3_14_12", false,-1, 2,0);
    tracep->declBus(c+17,"fun7_31_25", false,-1, 6,0);
    tracep->declBus(c+20,"Inst_type", false,-1, 2,0);
    tracep->declBus(c+31,"aluc", false,-1, 4,0);
    tracep->declBit(c+21,"reg_wen", false,-1);
    tracep->declBit(c+22,"mem_wen", false,-1);
    tracep->declBit(c+23,"mem_ren", false,-1);
    tracep->declBus(c+24,"wmask", false,-1, 7,0);
    tracep->declBus(c+25,"rmask", false,-1, 2,0);
    tracep->declBit(c+26,"pc_sel_1", false,-1);
    tracep->declBit(c+27,"pc_sel_2", false,-1);
    tracep->declBit(c+28,"alu_sel_2", false,-1);
    tracep->declBit(c+29,"alu_sel_1", false,-1);
    tracep->declBus(c+30,"wb_sel", false,-1, 1,0);
    tracep->declBus(c+69,"opcode_6_0", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+39,"out", false,-1, 31,0);
    tracep->declBus(c+28,"key", false,-1, 0,0);
    tracep->declArray(c+70,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+154,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+39,"out", false,-1, 31,0);
    tracep->declBus(c+28,"key", false,-1, 0,0);
    tracep->declBus(c+155,"default_out", false,-1, 31,0);
    tracep->declArray(c+70,"lut", false,-1, 65,0);
    tracep->declBus(c+156,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+73+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+5+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+77+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+79,"lut_out", false,-1, 31,0);
    tracep->declBit(c+80,"hit", false,-1);
    tracep->declBus(c+157,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i4 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+38,"out", false,-1, 31,0);
    tracep->declBus(c+29,"key", false,-1, 0,0);
    tracep->declArray(c+81,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+151,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+152,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+154,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+38,"out", false,-1, 31,0);
    tracep->declBus(c+29,"key", false,-1, 0,0);
    tracep->declBus(c+155,"default_out", false,-1, 31,0);
    tracep->declArray(c+81,"lut", false,-1, 65,0);
    tracep->declBus(c+156,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+84+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+88+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+90,"lut_out", false,-1, 31,0);
    tracep->declBit(c+91,"hit", false,-1);
    tracep->declBus(c+157,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("i5 ");
    tracep->declBus(c+159,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+151,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+34,"out", false,-1, 31,0);
    tracep->declBus(c+30,"key", false,-1, 1,0);
    tracep->declArray(c+92,"lut", false,-1, 135,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+159,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+151,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+153,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+154,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+34,"out", false,-1, 31,0);
    tracep->declBus(c+30,"key", false,-1, 1,0);
    tracep->declBus(c+155,"default_out", false,-1, 31,0);
    tracep->declArray(c+92,"lut", false,-1, 135,0);
    tracep->declBus(c+160,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+97+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+9+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+105+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+109,"lut_out", false,-1, 31,0);
    tracep->declBit(c+110,"hit", false,-1);
    tracep->declBus(c+161,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("imm_extend_inst ");
    tracep->declBus(c+13,"rs1", false,-1, 4,0);
    tracep->declBus(c+14,"rs2", false,-1, 4,0);
    tracep->declBus(c+15,"rd", false,-1, 4,0);
    tracep->declBus(c+16,"funct3", false,-1, 2,0);
    tracep->declBus(c+17,"funct7", false,-1, 6,0);
    tracep->declBus(c+20,"Inst_type", false,-1, 2,0);
    tracep->declBus(c+37,"imm32", false,-1, 31,0);
    tracep->declBus(c+111,"imm_12", false,-1, 11,0);
    tracep->declBus(c+112,"imm_20", false,-1, 19,0);
    tracep->declBus(c+113,"imm_12_to_32", false,-1, 31,0);
    tracep->declBus(c+114,"imm_20_to_32", false,-1, 31,0);
    tracep->pushNamePrefix("Extend_12_inst ");
    tracep->declBus(c+111,"imm_12", false,-1, 11,0);
    tracep->declBus(c+113,"imm_12_to_32", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Extend_20_inst ");
    tracep->declBus(c+112,"imm_20", false,-1, 19,0);
    tracep->declBus(c+114,"imm_20_to_32", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RISB_type_inst ");
    tracep->declBus(c+14,"rs2", false,-1, 4,0);
    tracep->declBus(c+15,"rd", false,-1, 4,0);
    tracep->declBus(c+17,"funct7", false,-1, 6,0);
    tracep->declBus(c+20,"Inst_type", false,-1, 2,0);
    tracep->declBus(c+111,"imm_12", false,-1, 11,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("UJ_type_inst ");
    tracep->declBus(c+13,"rs1", false,-1, 4,0);
    tracep->declBus(c+14,"rs2", false,-1, 4,0);
    tracep->declBus(c+16,"funct3", false,-1, 2,0);
    tracep->declBus(c+17,"funct7", false,-1, 6,0);
    tracep->declBus(c+20,"Inst_type", false,-1, 2,0);
    tracep->declBus(c+112,"imm_20", false,-1, 19,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("mem_inst ");
    tracep->declBit(c+149,"clk", false,-1);
    tracep->declBit(c+22,"mem_wen", false,-1);
    tracep->declBus(c+24,"wmask", false,-1, 7,0);
    tracep->declBus(c+33,"waddr", false,-1, 31,0);
    tracep->declBus(c+36,"wdata", false,-1, 31,0);
    tracep->declBit(c+23,"mem_ren", false,-1);
    tracep->declBus(c+25,"rmask", false,-1, 2,0);
    tracep->declBus(c+33,"raddr", false,-1, 31,0);
    tracep->declBus(c+19,"inst_addr", false,-1, 31,0);
    tracep->declBus(c+40,"rdata", false,-1, 31,0);
    tracep->declBus(c+18,"inst_data", false,-1, 31,0);
    tracep->declBus(c+115,"rdata_temp", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register_file_inst ");
    tracep->declBit(c+149,"clk", false,-1);
    tracep->declBit(c+150,"rst", false,-1);
    tracep->declBit(c+21,"reg_wen", false,-1);
    tracep->declBus(c+13,"rs1", false,-1, 4,0);
    tracep->declBus(c+14,"rs2", false,-1, 4,0);
    tracep->declBus(c+15,"rd", false,-1, 4,0);
    tracep->declBus(c+34,"reg_in", false,-1, 31,0);
    tracep->declBus(c+35,"src1", false,-1, 31,0);
    tracep->declBus(c+36,"src2", false,-1, 31,0);
    tracep->declBus(c+116,"i", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+117+i*1,"regs", true,(i+0), 31,0);
    }
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
    VlWide<3>/*95:0*/ __Vtemp_h9def89ec__0;
    VlWide<3>/*95:0*/ __Vtemp_hdeaaeb44__0;
    VlWide<3>/*95:0*/ __Vtemp_h3751e24b__0;
    VlWide<3>/*95:0*/ __Vtemp_h0807cf62__0;
    VlWide<5>/*159:0*/ __Vtemp_ha9a73541__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+3,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+4,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+5,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+6,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+7,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+8,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list[1]));
    bufp->fullCData(oldp+9,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+10,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+11,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[2]),2);
    bufp->fullCData(oldp+12,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[3]),2);
    bufp->fullCData(oldp+13,((0x1fU & (vlSelf->rv32__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+14,((0x1fU & (vlSelf->rv32__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+15,((0x1fU & (vlSelf->rv32__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+16,((7U & (vlSelf->rv32__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+17,((vlSelf->rv32__DOT__inst 
                              >> 0x19U)),7);
    bufp->fullIData(oldp+18,(vlSelf->rv32__DOT__inst),32);
    bufp->fullIData(oldp+19,(vlSelf->rv32__DOT__pc),32);
    bufp->fullCData(oldp+20,(vlSelf->rv32__DOT__Inst_type),3);
    bufp->fullBit(oldp+21,(vlSelf->rv32__DOT__reg_wen));
    bufp->fullBit(oldp+22,(vlSelf->rv32__DOT__mem_wen));
    bufp->fullBit(oldp+23,(vlSelf->rv32__DOT__mem_ren));
    bufp->fullCData(oldp+24,(vlSelf->rv32__DOT__wmask),8);
    bufp->fullCData(oldp+25,(vlSelf->rv32__DOT__rmask),3);
    bufp->fullBit(oldp+26,(vlSelf->rv32__DOT__pc_sel_1));
    bufp->fullBit(oldp+27,(vlSelf->rv32__DOT__pc_sel_2));
    bufp->fullBit(oldp+28,(vlSelf->rv32__DOT__alu_sel_2));
    bufp->fullBit(oldp+29,(vlSelf->rv32__DOT__alu_sel_1));
    bufp->fullCData(oldp+30,(vlSelf->rv32__DOT__wb_sel),2);
    bufp->fullCData(oldp+31,(vlSelf->rv32__DOT__aluc),5);
    bufp->fullIData(oldp+32,(((IData)(4U) + vlSelf->rv32__DOT__pc)),32);
    bufp->fullIData(oldp+33,(vlSelf->rv32__DOT__result),32);
    bufp->fullIData(oldp+34,(vlSelf->rv32__DOT__reg_in),32);
    bufp->fullIData(oldp+35,(vlSelf->rv32__DOT__src1),32);
    bufp->fullIData(oldp+36,(vlSelf->rv32__DOT__src2),32);
    bufp->fullIData(oldp+37,(vlSelf->rv32__DOT__imm32),32);
    bufp->fullIData(oldp+38,(vlSelf->rv32__DOT__num1),32);
    bufp->fullIData(oldp+39,(vlSelf->rv32__DOT__num2),32);
    bufp->fullIData(oldp+40,(vlSelf->rv32__DOT__mem_rdata),32);
    bufp->fullIData(oldp+41,(vlSelf->rv32__DOT__PC_inst__DOT__npc),32);
    bufp->fullIData(oldp+42,(vlSelf->rv32__DOT__PC_inst__DOT__npc_temp),32);
    bufp->fullIData(oldp+43,((vlSelf->rv32__DOT__imm32 
                              + vlSelf->rv32__DOT__pc)),32);
    bufp->fullBit(oldp+44,(vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2));
    __Vtemp_h9def89ec__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(
                                                          (vlSelf->rv32__DOT__imm32 
                                                           + vlSelf->rv32__DOT__pc)))));
    __Vtemp_h9def89ec__0[1U] = ((vlSelf->rv32__DOT__PC_inst__DOT__npc_temp 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(
                                                                      (vlSelf->rv32__DOT__imm32 
                                                                       + vlSelf->rv32__DOT__pc)))) 
                                                   >> 0x20U)));
    __Vtemp_h9def89ec__0[2U] = (vlSelf->rv32__DOT__PC_inst__DOT__npc_temp 
                                >> 0x1fU);
    bufp->fullWData(oldp+45,(__Vtemp_h9def89ec__0),66);
    bufp->fullQData(oldp+48,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+50,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+52,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+53,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+54,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+55,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit));
    __Vtemp_hdeaaeb44__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->rv32__DOT__result))));
    __Vtemp_hdeaaeb44__0[1U] = ((((IData)(4U) + vlSelf->rv32__DOT__pc) 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->rv32__DOT__result))) 
                                                   >> 0x20U)));
    __Vtemp_hdeaaeb44__0[2U] = (((IData)(4U) + vlSelf->rv32__DOT__pc) 
                                >> 0x1fU);
    bufp->fullWData(oldp+56,(__Vtemp_hdeaaeb44__0),66);
    bufp->fullQData(oldp+59,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+61,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+63,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+64,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+65,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+66,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+67,(((IData)(1U) + (~ vlSelf->rv32__DOT__num2))),32);
    bufp->fullIData(oldp+68,((0x1fU & vlSelf->rv32__DOT__num2)),32);
    bufp->fullCData(oldp+69,((0x7fU & vlSelf->rv32__DOT__inst)),7);
    __Vtemp_h3751e24b__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->rv32__DOT__imm32))));
    __Vtemp_h3751e24b__0[1U] = ((vlSelf->rv32__DOT__src2 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->rv32__DOT__imm32))) 
                                                   >> 0x20U)));
    __Vtemp_h3751e24b__0[2U] = (vlSelf->rv32__DOT__src2 
                                >> 0x1fU);
    bufp->fullWData(oldp+70,(__Vtemp_h3751e24b__0),66);
    bufp->fullQData(oldp+73,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+75,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+77,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+78,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+79,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+80,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__hit));
    __Vtemp_h0807cf62__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->rv32__DOT__src1))));
    __Vtemp_h0807cf62__0[1U] = ((vlSelf->rv32__DOT__pc 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->rv32__DOT__src1))) 
                                                   >> 0x20U)));
    __Vtemp_h0807cf62__0[2U] = (vlSelf->rv32__DOT__pc 
                                >> 0x1fU);
    bufp->fullWData(oldp+81,(__Vtemp_h0807cf62__0),66);
    bufp->fullQData(oldp+84,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+86,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+88,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+89,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+90,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+91,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__hit));
    __Vtemp_ha9a73541__0[0U] = 0xdeadbeefU;
    __Vtemp_ha9a73541__0[1U] = (3U | (vlSelf->rv32__DOT__result 
                                      << 2U));
    __Vtemp_ha9a73541__0[2U] = (8U | ((vlSelf->rv32__DOT__mem_rdata 
                                       << 4U) | (vlSelf->rv32__DOT__result 
                                                 >> 0x1eU)));
    __Vtemp_ha9a73541__0[3U] = (0x10U | ((((IData)(4U) 
                                           + vlSelf->rv32__DOT__pc) 
                                          << 6U) | 
                                         (vlSelf->rv32__DOT__mem_rdata 
                                          >> 0x1cU)));
    __Vtemp_ha9a73541__0[4U] = (((IData)(4U) + vlSelf->rv32__DOT__pc) 
                                >> 0x1aU);
    bufp->fullWData(oldp+92,(__Vtemp_ha9a73541__0),136);
    bufp->fullQData(oldp+97,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+99,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+101,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullQData(oldp+103,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[3]),34);
    bufp->fullIData(oldp+105,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+106,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+107,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+108,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+109,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+110,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit));
    bufp->fullSData(oldp+111,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12),12);
    bufp->fullIData(oldp+112,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20),20);
    bufp->fullIData(oldp+113,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12_to_32),32);
    bufp->fullIData(oldp+114,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20_to_32),32);
    bufp->fullIData(oldp+115,(vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp),32);
    bufp->fullIData(oldp+116,(vlSelf->rv32__DOT__register_file_inst__DOT__i),32);
    bufp->fullIData(oldp+117,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[0]),32);
    bufp->fullIData(oldp+118,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[1]),32);
    bufp->fullIData(oldp+119,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[2]),32);
    bufp->fullIData(oldp+120,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[3]),32);
    bufp->fullIData(oldp+121,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[4]),32);
    bufp->fullIData(oldp+122,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[5]),32);
    bufp->fullIData(oldp+123,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[6]),32);
    bufp->fullIData(oldp+124,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[7]),32);
    bufp->fullIData(oldp+125,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[8]),32);
    bufp->fullIData(oldp+126,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[9]),32);
    bufp->fullIData(oldp+127,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[10]),32);
    bufp->fullIData(oldp+128,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[11]),32);
    bufp->fullIData(oldp+129,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[12]),32);
    bufp->fullIData(oldp+130,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[13]),32);
    bufp->fullIData(oldp+131,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[14]),32);
    bufp->fullIData(oldp+132,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[15]),32);
    bufp->fullIData(oldp+133,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[16]),32);
    bufp->fullIData(oldp+134,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[17]),32);
    bufp->fullIData(oldp+135,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[18]),32);
    bufp->fullIData(oldp+136,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[19]),32);
    bufp->fullIData(oldp+137,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[20]),32);
    bufp->fullIData(oldp+138,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[21]),32);
    bufp->fullIData(oldp+139,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[22]),32);
    bufp->fullIData(oldp+140,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[23]),32);
    bufp->fullIData(oldp+141,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[24]),32);
    bufp->fullIData(oldp+142,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[25]),32);
    bufp->fullIData(oldp+143,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[26]),32);
    bufp->fullIData(oldp+144,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[27]),32);
    bufp->fullIData(oldp+145,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[28]),32);
    bufp->fullIData(oldp+146,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[29]),32);
    bufp->fullIData(oldp+147,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[30]),32);
    bufp->fullIData(oldp+148,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[31]),32);
    bufp->fullBit(oldp+149,(vlSelf->clk));
    bufp->fullBit(oldp+150,(vlSelf->rst));
    bufp->fullIData(oldp+151,(2U),32);
    bufp->fullIData(oldp+152,(1U),32);
    bufp->fullIData(oldp+153,(0x20U),32);
    bufp->fullIData(oldp+154,(0U),32);
    bufp->fullIData(oldp+155,(0U),32);
    bufp->fullIData(oldp+156,(0x21U),32);
    bufp->fullIData(oldp+157,(2U),32);
    bufp->fullIData(oldp+158,(0xfffffffeU),32);
    bufp->fullIData(oldp+159,(4U),32);
    bufp->fullIData(oldp+160,(0x22U),32);
    bufp->fullIData(oldp+161,(4U),32);
}

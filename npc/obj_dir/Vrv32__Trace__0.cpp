// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrv32__Syms.h"


void Vrv32___024root__trace_chg_sub_0(Vrv32___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vrv32___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_chg_top_0\n"); );
    // Init
    Vrv32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrv32___024root*>(voidSelf);
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vrv32___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vrv32___024root__trace_chg_sub_0(Vrv32___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_h9def89ec__0;
    VlWide<3>/*95:0*/ __Vtemp_hdeaaeb44__0;
    VlWide<3>/*95:0*/ __Vtemp_h3751e24b__0;
    VlWide<3>/*95:0*/ __Vtemp_h0807cf62__0;
    VlWide<5>/*159:0*/ __Vtemp_hcf9f527e__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+2,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+3,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+4,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+5,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+6,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+7,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+8,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+9,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+10,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+11,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list[3]),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+12,((0x1fU & (vlSelf->rv32__DOT__inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+13,((0x1fU & (vlSelf->rv32__DOT__inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+14,((0x1fU & (vlSelf->rv32__DOT__inst 
                                          >> 7U))),5);
        bufp->chgCData(oldp+15,((7U & (vlSelf->rv32__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+16,((vlSelf->rv32__DOT__inst 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+17,(vlSelf->rv32__DOT__inst),32);
        bufp->chgIData(oldp+18,(vlSelf->rv32__DOT__pc),32);
        bufp->chgCData(oldp+19,(vlSelf->rv32__DOT__IType),3);
        bufp->chgBit(oldp+20,(vlSelf->rv32__DOT__reg_wen));
        bufp->chgBit(oldp+21,(vlSelf->rv32__DOT__mem_wen));
        bufp->chgBit(oldp+22,(vlSelf->rv32__DOT__mem_ren));
        bufp->chgCData(oldp+23,(vlSelf->rv32__DOT__wmask),8);
        bufp->chgCData(oldp+24,(vlSelf->rv32__DOT__rmask),3);
        bufp->chgBit(oldp+25,(vlSelf->rv32__DOT__m1));
        bufp->chgBit(oldp+26,(vlSelf->rv32__DOT__m2));
        bufp->chgBit(oldp+27,(vlSelf->rv32__DOT__m3));
        bufp->chgBit(oldp+28,(vlSelf->rv32__DOT__m4));
        bufp->chgCData(oldp+29,(vlSelf->rv32__DOT__m5),2);
        bufp->chgCData(oldp+30,(vlSelf->rv32__DOT__aluc),5);
        bufp->chgIData(oldp+31,(((IData)(4U) + vlSelf->rv32__DOT__pc)),32);
        bufp->chgIData(oldp+32,(vlSelf->rv32__DOT__result),32);
        bufp->chgIData(oldp+33,(vlSelf->rv32__DOT__reg_in),32);
        bufp->chgIData(oldp+34,(vlSelf->rv32__DOT__src1),32);
        bufp->chgIData(oldp+35,(vlSelf->rv32__DOT__src2),32);
        bufp->chgIData(oldp+36,(vlSelf->rv32__DOT__imm32),32);
        bufp->chgIData(oldp+37,(vlSelf->rv32__DOT__num1),32);
        bufp->chgIData(oldp+38,(vlSelf->rv32__DOT__num2),32);
        bufp->chgIData(oldp+39,(vlSelf->rv32__DOT__mem_rdata),32);
        bufp->chgIData(oldp+40,(vlSelf->rv32__DOT__PC_inst__DOT__npc),32);
        bufp->chgIData(oldp+41,(vlSelf->rv32__DOT__PC_inst__DOT__npc_temp),32);
        bufp->chgIData(oldp+42,((vlSelf->rv32__DOT__imm32 
                                 + vlSelf->rv32__DOT__pc)),32);
        bufp->chgBit(oldp+43,(vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2));
        __Vtemp_h9def89ec__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(
                                                              (vlSelf->rv32__DOT__imm32 
                                                               + vlSelf->rv32__DOT__pc)))));
        __Vtemp_h9def89ec__0[1U] = ((vlSelf->rv32__DOT__PC_inst__DOT__npc_temp 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(
                                                                          (vlSelf->rv32__DOT__imm32 
                                                                           + vlSelf->rv32__DOT__pc)))) 
                                                       >> 0x20U)));
        __Vtemp_h9def89ec__0[2U] = (vlSelf->rv32__DOT__PC_inst__DOT__npc_temp 
                                    >> 0x1fU);
        bufp->chgWData(oldp+44,(__Vtemp_h9def89ec__0),66);
        bufp->chgQData(oldp+47,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+49,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+51,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+52,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+53,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+54,(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit));
        __Vtemp_hdeaaeb44__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->rv32__DOT__result))));
        __Vtemp_hdeaaeb44__0[1U] = ((((IData)(4U) + vlSelf->rv32__DOT__pc) 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->rv32__DOT__result))) 
                                                       >> 0x20U)));
        __Vtemp_hdeaaeb44__0[2U] = (((IData)(4U) + vlSelf->rv32__DOT__pc) 
                                    >> 0x1fU);
        bufp->chgWData(oldp+55,(__Vtemp_hdeaaeb44__0),66);
        bufp->chgQData(oldp+58,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+60,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+62,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+63,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+64,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+65,(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+66,(((IData)(1U) + (~ vlSelf->rv32__DOT__num2))),32);
        bufp->chgIData(oldp+67,((0x1fU & vlSelf->rv32__DOT__num2)),32);
        bufp->chgCData(oldp+68,((0x7fU & vlSelf->rv32__DOT__inst)),7);
        __Vtemp_h3751e24b__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->rv32__DOT__imm32))));
        __Vtemp_h3751e24b__0[1U] = ((vlSelf->rv32__DOT__src2 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->rv32__DOT__imm32))) 
                                                       >> 0x20U)));
        __Vtemp_h3751e24b__0[2U] = (vlSelf->rv32__DOT__src2 
                                    >> 0x1fU);
        bufp->chgWData(oldp+69,(__Vtemp_h3751e24b__0),66);
        bufp->chgQData(oldp+72,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+74,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+76,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+77,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+78,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+79,(vlSelf->rv32__DOT__i3__DOT__i0__DOT__hit));
        __Vtemp_h0807cf62__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->rv32__DOT__src1))));
        __Vtemp_h0807cf62__0[1U] = ((vlSelf->rv32__DOT__pc 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->rv32__DOT__src1))) 
                                                       >> 0x20U)));
        __Vtemp_h0807cf62__0[2U] = (vlSelf->rv32__DOT__pc 
                                    >> 0x1fU);
        bufp->chgWData(oldp+80,(__Vtemp_h0807cf62__0),66);
        bufp->chgQData(oldp+83,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+85,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+87,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+88,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+89,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+90,(vlSelf->rv32__DOT__i4__DOT__i0__DOT__hit));
        __Vtemp_hcf9f527e__0[0U] = 0xdeadbeafU;
        __Vtemp_hcf9f527e__0[1U] = (3U | (vlSelf->rv32__DOT__result 
                                          << 2U));
        __Vtemp_hcf9f527e__0[2U] = (8U | ((vlSelf->rv32__DOT__mem_rdata 
                                           << 4U) | 
                                          (vlSelf->rv32__DOT__result 
                                           >> 0x1eU)));
        __Vtemp_hcf9f527e__0[3U] = (0x10U | ((((IData)(4U) 
                                               + vlSelf->rv32__DOT__pc) 
                                              << 6U) 
                                             | (vlSelf->rv32__DOT__mem_rdata 
                                                >> 0x1cU)));
        __Vtemp_hcf9f527e__0[4U] = (((IData)(4U) + vlSelf->rv32__DOT__pc) 
                                    >> 0x1aU);
        bufp->chgWData(oldp+91,(__Vtemp_hcf9f527e__0),136);
        bufp->chgQData(oldp+96,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+98,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+100,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+102,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+104,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+105,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+106,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+107,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+108,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+109,(vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit));
        bufp->chgSData(oldp+110,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12),12);
        bufp->chgIData(oldp+111,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20),20);
        bufp->chgIData(oldp+112,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12_to_32),32);
        bufp->chgIData(oldp+113,(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20_to_32),32);
        bufp->chgIData(oldp+114,(vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp),32);
        bufp->chgIData(oldp+115,(vlSelf->rv32__DOT__register_file_inst__DOT__i),32);
        bufp->chgIData(oldp+116,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[0]),32);
        bufp->chgIData(oldp+117,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[1]),32);
        bufp->chgIData(oldp+118,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[2]),32);
        bufp->chgIData(oldp+119,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[3]),32);
        bufp->chgIData(oldp+120,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[4]),32);
        bufp->chgIData(oldp+121,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[5]),32);
        bufp->chgIData(oldp+122,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[6]),32);
        bufp->chgIData(oldp+123,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[7]),32);
        bufp->chgIData(oldp+124,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[8]),32);
        bufp->chgIData(oldp+125,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[9]),32);
        bufp->chgIData(oldp+126,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[10]),32);
        bufp->chgIData(oldp+127,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[11]),32);
        bufp->chgIData(oldp+128,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[12]),32);
        bufp->chgIData(oldp+129,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[13]),32);
        bufp->chgIData(oldp+130,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[14]),32);
        bufp->chgIData(oldp+131,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[15]),32);
        bufp->chgIData(oldp+132,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[16]),32);
        bufp->chgIData(oldp+133,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[17]),32);
        bufp->chgIData(oldp+134,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[18]),32);
        bufp->chgIData(oldp+135,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[19]),32);
        bufp->chgIData(oldp+136,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[20]),32);
        bufp->chgIData(oldp+137,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[21]),32);
        bufp->chgIData(oldp+138,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[22]),32);
        bufp->chgIData(oldp+139,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[23]),32);
        bufp->chgIData(oldp+140,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[24]),32);
        bufp->chgIData(oldp+141,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[25]),32);
        bufp->chgIData(oldp+142,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[26]),32);
        bufp->chgIData(oldp+143,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[27]),32);
        bufp->chgIData(oldp+144,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[28]),32);
        bufp->chgIData(oldp+145,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[29]),32);
        bufp->chgIData(oldp+146,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[30]),32);
        bufp->chgIData(oldp+147,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[31]),32);
    }
    bufp->chgBit(oldp+148,(vlSelf->clk));
    bufp->chgBit(oldp+149,(vlSelf->rst));
}

void Vrv32___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root__trace_cleanup\n"); );
    // Init
    Vrv32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrv32___024root*>(voidSelf);
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}

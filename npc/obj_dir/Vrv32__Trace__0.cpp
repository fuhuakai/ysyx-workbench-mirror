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
    VlWide<3>/*95:0*/ __Vtemp_hf583cdce__0;
    VlWide<3>/*95:0*/ __Vtemp_h9dd1dc51__0;
    VlWide<3>/*95:0*/ __Vtemp_hfdf5c643__0;
    VlWide<5>/*159:0*/ __Vtemp_hce12de26__0;
    VlWide<5>/*159:0*/ __Vtemp_hd74c99fb__0;
    VlWide<5>/*159:0*/ __Vtemp_h00174f39__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+2,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+3,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+4,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+5,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__key_list[1]));
        bufp->chgCData(oldp+6,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+7,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+8,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+9,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__key_list[3]),2);
        bufp->chgCData(oldp+10,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+11,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+12,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+13,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__key_list[3]),2);
        bufp->chgCData(oldp+14,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+15,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+16,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+17,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__key_list[3]),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+18,(vlSelf->rv32__DOT__clk_cnt),3);
        bufp->chgBit(oldp+19,((1U & (~ (IData)(vlSelf->rv32__DOT__w_wbu_cycle_end)))));
        bufp->chgIData(oldp+20,((IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                         >> 0x20U))),32);
        bufp->chgIData(oldp+21,((IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)),32);
        bufp->chgBit(oldp+22,((1U & (~ (IData)(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg)))));
        bufp->chgBit(oldp+23,(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg));
        bufp->chgCData(oldp+24,((0x1fU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          >> 0xaU))),5);
        bufp->chgCData(oldp+25,((0x1fU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                          >> 5U))),5);
        bufp->chgSData(oldp+26,((0xfffU & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                              >> 0x19U)))),12);
        bufp->chgBit(oldp+27,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                     >> 0x18U))));
        bufp->chgBit(oldp+28,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                     >> 0x17U))));
        bufp->chgBit(oldp+29,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                     >> 0x16U))));
        bufp->chgCData(oldp+30,((3U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                       >> 0x14U))),2);
        bufp->chgCData(oldp+31,((0xfU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                         >> 0x10U))),4);
        bufp->chgCData(oldp+32,((3U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                       >> 0xeU))),2);
        bufp->chgIData(oldp+33,(((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                  << 0x12U) | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                               >> 0xeU))),32);
        bufp->chgBit(oldp+34,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                     >> 0xdU))));
        bufp->chgBit(oldp+35,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                     >> 0xcU))));
        bufp->chgCData(oldp+36,((7U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                       >> 9U))),3);
        bufp->chgIData(oldp+37,(((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                  << 0x17U) | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                               >> 9U))),32);
        bufp->chgBit(oldp+38,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                     >> 8U))));
        bufp->chgBit(oldp+39,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                     >> 7U))));
        bufp->chgBit(oldp+40,((1U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                     >> 6U))));
        bufp->chgCData(oldp+41,((0x1fU & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                          >> 1U))),5);
        bufp->chgBit(oldp+42,((1U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U])));
        bufp->chgBit(oldp+43,((1U & (~ (IData)(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg)))));
        bufp->chgBit(oldp+44,(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg));
        bufp->chgIData(oldp+45,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                  << 3U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                            >> 0x1dU))),32);
        bufp->chgBit(oldp+46,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                     >> 0x1cU))));
        bufp->chgBit(oldp+47,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                     >> 0x1bU))));
        bufp->chgCData(oldp+48,((7U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                       >> 0x18U))),3);
        bufp->chgIData(oldp+49,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                  << 8U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                            >> 0x18U))),32);
        bufp->chgIData(oldp+50,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                  << 8U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                            >> 0x18U))),32);
        bufp->chgIData(oldp+51,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                  << 8U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                            >> 0x18U))),32);
        bufp->chgBit(oldp+52,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                     >> 0x17U))));
        bufp->chgBit(oldp+53,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                     >> 0x16U))));
        bufp->chgIData(oldp+54,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                  << 0xaU) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                              >> 0x16U))),32);
        bufp->chgIData(oldp+55,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                  << 0xaU) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                              >> 0x16U))),32);
        bufp->chgBit(oldp+56,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0x15U))));
        bufp->chgBit(oldp+57,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0x14U))));
        bufp->chgBit(oldp+58,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0x13U))));
        bufp->chgCData(oldp+59,((0x1fU & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                          >> 0xeU))),5);
        bufp->chgBit(oldp+60,((1U & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                     >> 0xdU))));
        bufp->chgSData(oldp+61,((0xfffU & (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                           >> 1U))),12);
        bufp->chgIData(oldp+62,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                  << 0x1fU) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[0U] 
                                               >> 1U))),32);
        bufp->chgBit(oldp+63,((1U & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[0U])));
        bufp->chgBit(oldp+64,((1U & (~ (IData)(vlSelf->rv32__DOT__lsu_inst__DOT__post_valid_reg)))));
        bufp->chgBit(oldp+65,(vlSelf->rv32__DOT__lsu_inst__DOT__post_valid_reg));
        bufp->chgBit(oldp+66,(vlSelf->rv32__DOT__w_lsu_is_ejump));
        bufp->chgIData(oldp+67,(((0x10000000U & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U])
                                  ? vlSelf->rv32__DOT__lsu_inst__DOT__lsu_mem_rdata_reg
                                  : ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[7U] 
                                      << 3U) | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                >> 0x1dU)))),32);
        bufp->chgBit(oldp+68,(vlSelf->rv32__DOT__w_wbu_cycle_end));
        bufp->chgBit(oldp+69,(vlSelf->rv32__DOT__w_wbu_npc_wen));
        bufp->chgBit(oldp+70,(((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                >> 0xdU) & (IData)(vlSelf->rv32__DOT__w_wbu_npc_wen))));
        bufp->chgIData(oldp+71,(vlSelf->rv32__DOT__bru_inst__DOT__npc_reg),32);
        bufp->chgIData(oldp+72,(vlSelf->rv32__DOT__w_rf_rs1),32);
        bufp->chgIData(oldp+73,(vlSelf->rv32__DOT__w_rf_rs2),32);
        bufp->chgIData(oldp+74,(vlSelf->rv32__DOT__w_cc_csr_src),32);
        bufp->chgIData(oldp+75,(((0x800000U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                  ? vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mepc
                                  : ((0x400000U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                      ? vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mtvec
                                      : 0xdead005aU))),32);
        bufp->chgIData(oldp+76,(vlSelf->rv32__DOT__bru_inst__DOT__pc_jorb),32);
        bufp->chgIData(oldp+77,(vlSelf->rv32__DOT__bru_inst__DOT__npc_t1),32);
        bufp->chgIData(oldp+78,(vlSelf->rv32__DOT__bru_inst__DOT__npc_t2),32);
        __Vtemp_hf583cdce__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(
                                                              (0xfffffffeU 
                                                               & (((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                    << 0xaU) 
                                                                   | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                                                      >> 0x16U)) 
                                                                  + 
                                                                  ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                                    << 8U) 
                                                                   | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                                                      >> 0x18U))))))));
        __Vtemp_hf583cdce__0[1U] = (((((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                        << 0xaU) | 
                                       (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                        >> 0x16U)) 
                                      + ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                          << 0xaU) 
                                         | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                            >> 0x16U))) 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(
                                                                          (0xfffffffeU 
                                                                           & (((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                                << 0xaU) 
                                                                               | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                                                                >> 0x16U)) 
                                                                              + 
                                                                              ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U] 
                                                                                << 8U) 
                                                                               | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[5U] 
                                                                                >> 0x18U))))))) 
                                                       >> 0x20U)));
        __Vtemp_hf583cdce__0[2U] = ((((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                       << 0xaU) | (
                                                   vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                                   >> 0x16U)) 
                                     + ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                         << 0xaU) | 
                                        (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                         >> 0x16U))) 
                                    >> 0x1fU);
        bufp->chgWData(oldp+79,(__Vtemp_hf583cdce__0),66);
        bufp->chgQData(oldp+82,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+84,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+86,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+87,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+88,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+89,(vlSelf->rv32__DOT__bru_inst__DOT__mux1__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+90,(vlSelf->rv32__DOT__bru_inst__DOT____Vcellinp__mux2____pinNumber2));
        __Vtemp_h9dd1dc51__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->rv32__DOT__bru_inst__DOT__pc_jorb))));
        __Vtemp_h9dd1dc51__0[1U] = ((((IData)(4U) + 
                                      ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                        << 0xaU) | 
                                       (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                        >> 0x16U))) 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->rv32__DOT__bru_inst__DOT__pc_jorb))) 
                                                       >> 0x20U)));
        __Vtemp_h9dd1dc51__0[2U] = (((IData)(4U) + 
                                     ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[2U] 
                                       << 0xaU) | (
                                                   vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[1U] 
                                                   >> 0x16U))) 
                                    >> 0x1fU);
        bufp->chgWData(oldp+91,(__Vtemp_h9dd1dc51__0),66);
        bufp->chgQData(oldp+94,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+96,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+98,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+99,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+100,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+101,(vlSelf->rv32__DOT__bru_inst__DOT__mux2__DOT__i0__DOT__hit));
        __Vtemp_hfdf5c643__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(
                                                              ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                                                << 8U) 
                                                               | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                  >> 0x18U))))));
        __Vtemp_hfdf5c643__0[1U] = ((vlSelf->rv32__DOT__bru_inst__DOT__npc_t1 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(
                                                                          ((vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[4U] 
                                                                            << 8U) 
                                                                           | (vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[3U] 
                                                                              >> 0x18U))))) 
                                                       >> 0x20U)));
        __Vtemp_hfdf5c643__0[2U] = (vlSelf->rv32__DOT__bru_inst__DOT__npc_t1 
                                    >> 0x1fU);
        bufp->chgWData(oldp+102,(__Vtemp_hfdf5c643__0),66);
        bufp->chgQData(oldp+105,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+107,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+109,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+110,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+111,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+112,(vlSelf->rv32__DOT__bru_inst__DOT__mux3__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+113,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mstatus),32);
        bufp->chgIData(oldp+114,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mtvec),32);
        bufp->chgIData(oldp+115,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mepc),32);
        bufp->chgIData(oldp+116,(vlSelf->rv32__DOT__csr_ctrl_inst__DOT__mcause),32);
        bufp->chgIData(oldp+117,(((0x1000000U & vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U])
                                   ? vlSelf->rv32__DOT__w_cc_csr_src
                                   : vlSelf->rv32__DOT__exu_inst__DOT__exu_alu_res)),32);
        bufp->chgBit(oldp+118,((1U & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                       >> 6U) & vlSelf->rv32__DOT__exu_inst__DOT__exu_alu_res))));
        bufp->chgIData(oldp+119,(vlSelf->rv32__DOT__exu_inst__DOT__exu_csr_rd),32);
        bufp->chgIData(oldp+120,(vlSelf->rv32__DOT__exu_inst__DOT__exu_alu_res),32);
        bufp->chgIData(oldp+121,(vlSelf->rv32__DOT__exu_inst__DOT__num1),32);
        bufp->chgIData(oldp+122,(vlSelf->rv32__DOT__exu_inst__DOT__num2),32);
        bufp->chgIData(oldp+123,(((IData)(1U) + (~ vlSelf->rv32__DOT__exu_inst__DOT__num2))),32);
        bufp->chgBit(oldp+124,(((~ (IData)(vlSelf->rv32__DOT__exu_inst__DOT__post_valid_reg)) 
                                & (IData)(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg))));
        bufp->chgWData(oldp+125,(vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg),253);
        __Vtemp_hce12de26__0[0U] = (IData)((0x300000000ULL 
                                            | (QData)((IData)(
                                                              ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                << 0x17U) 
                                                               | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                  >> 9U))))));
        __Vtemp_hce12de26__0[1U] = ((0xfffffffcU & 
                                     ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                       << 0x19U) | 
                                      (0x1fffffcU & 
                                       (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                        >> 7U)))) | (IData)(
                                                            ((0x300000000ULL 
                                                              | (QData)((IData)(
                                                                                ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                                                << 0x17U) 
                                                                                | (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[0U] 
                                                                                >> 9U))))) 
                                                             >> 0x20U)));
        __Vtemp_hce12de26__0[2U] = (8U | ((vlSelf->rv32__DOT__w_rf_rs1 
                                           << 4U) | 
                                          (3U & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                 >> 7U))));
        __Vtemp_hce12de26__0[3U] = (0x10U | ((vlSelf->rv32__DOT__w_rf_rs1 
                                              << 6U) 
                                             | (vlSelf->rv32__DOT__w_rf_rs1 
                                                >> 0x1cU)));
        __Vtemp_hce12de26__0[4U] = (vlSelf->rv32__DOT__w_rf_rs1 
                                    >> 0x1aU);
        bufp->chgWData(oldp+133,(__Vtemp_hce12de26__0),136);
        bufp->chgQData(oldp+138,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+140,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+142,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+144,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+146,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+147,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+148,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+149,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+150,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+151,(vlSelf->rv32__DOT__exu_inst__DOT__mux1__DOT__i0__DOT__hit));
        __Vtemp_hd74c99fb__0[0U] = 4U;
        __Vtemp_hd74c99fb__0[1U] = (3U | (0xfffffffcU 
                                          & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                              << 0x14U) 
                                             | (0xffffcU 
                                                & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                   >> 0xcU)))));
        __Vtemp_hd74c99fb__0[2U] = (8U | ((0xfffffff0U 
                                           & ((vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                               << 0x16U) 
                                              | (0x3ffff0U 
                                                 & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[1U] 
                                                    >> 0xaU)))) 
                                          | (3U & (
                                                   vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                   >> 0xcU))));
        __Vtemp_hd74c99fb__0[3U] = (0x10U | ((vlSelf->rv32__DOT__w_rf_rs2 
                                              << 6U) 
                                             | (0xfU 
                                                & (vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg[2U] 
                                                   >> 0xaU))));
        __Vtemp_hd74c99fb__0[4U] = (vlSelf->rv32__DOT__w_rf_rs2 
                                    >> 0x1aU);
        bufp->chgWData(oldp+152,(__Vtemp_hd74c99fb__0),136);
        bufp->chgQData(oldp+157,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+159,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+161,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+163,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+165,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+166,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+167,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+168,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+169,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+170,(vlSelf->rv32__DOT__exu_inst__DOT__mux2__DOT__i0__DOT__hit));
        __Vtemp_h00174f39__0[0U] = (IData)((0x300000000ULL 
                                            | (QData)((IData)(
                                                              ((~ vlSelf->rv32__DOT__w_cc_csr_src) 
                                                               & vlSelf->rv32__DOT__w_rf_rs1)))));
        __Vtemp_h00174f39__0[1U] = (((vlSelf->rv32__DOT__w_cc_csr_src 
                                      | vlSelf->rv32__DOT__w_rf_rs1) 
                                     << 2U) | (IData)(
                                                      ((0x300000000ULL 
                                                        | (QData)((IData)(
                                                                          ((~ vlSelf->rv32__DOT__w_cc_csr_src) 
                                                                           & vlSelf->rv32__DOT__w_rf_rs1)))) 
                                                       >> 0x20U)));
        __Vtemp_h00174f39__0[2U] = (8U | ((vlSelf->rv32__DOT__w_rf_rs1 
                                           << 4U) | 
                                          ((vlSelf->rv32__DOT__w_cc_csr_src 
                                            | vlSelf->rv32__DOT__w_rf_rs1) 
                                           >> 0x1eU)));
        __Vtemp_h00174f39__0[3U] = (0x10U | (vlSelf->rv32__DOT__w_rf_rs1 
                                             >> 0x1cU));
        __Vtemp_h00174f39__0[4U] = 0U;
        bufp->chgWData(oldp+171,(__Vtemp_h00174f39__0),136);
        bufp->chgQData(oldp+176,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+178,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+180,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgQData(oldp+182,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__pair_list[3]),34);
        bufp->chgIData(oldp+184,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+185,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+186,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+187,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+188,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+189,(vlSelf->rv32__DOT__exu_inst__DOT__mux3__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+190,(((IData)(vlSelf->rv32__DOT__idu_inst__DOT__idu_is_ecall)
                                   ? 0xfU : ((0x37U 
                                              == (0x7fU 
                                                  & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))
                                              ? 0U : 
                                             (0x1fU 
                                              & (IData)(
                                                        (vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                         >> 0xfU)))))),5);
        bufp->chgCData(oldp+191,((0x1fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 0x14U)))),5);
        bufp->chgSData(oldp+192,((0xfffU & (IData)(
                                                   (vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                    >> 0x14U)))),12);
        bufp->chgBit(oldp+193,(vlSelf->rv32__DOT__idu_inst__DOT__idu_csr_ren));
        bufp->chgBit(oldp+194,(vlSelf->rv32__DOT__idu_inst__DOT__idu_is_mret));
        bufp->chgBit(oldp+195,(vlSelf->rv32__DOT__idu_inst__DOT__idu_is_ecall));
        bufp->chgCData(oldp+196,(vlSelf->rv32__DOT__idu_inst__DOT__idu_csr_type),2);
        bufp->chgCData(oldp+197,(vlSelf->rv32__DOT__idu_inst__DOT__idu_alu_type),4);
        bufp->chgCData(oldp+198,(vlSelf->rv32__DOT__idu_inst__DOT__idu_num_sel),2);
        bufp->chgIData(oldp+199,(vlSelf->rv32__DOT__idu_inst__DOT__idu_imm),32);
        bufp->chgBit(oldp+200,((3U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgBit(oldp+201,((0x23U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgCData(oldp+202,((7U & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                >> 0xcU)))),3);
        bufp->chgBit(oldp+203,((0x6fU == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgBit(oldp+204,((0x67U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgBit(oldp+205,((0x63U == (0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg)))));
        bufp->chgCData(oldp+206,((0x1fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 7U)))),5);
        bufp->chgBit(oldp+207,(vlSelf->rv32__DOT__idu_inst__DOT__idu_gpr_wen));
        bufp->chgCData(oldp+208,((0x7fU & (IData)(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg))),7);
        bufp->chgCData(oldp+209,((0x1fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 0xfU)))),5);
        bufp->chgCData(oldp+210,((0x7fU & (IData)((vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg 
                                                   >> 0x19U)))),7);
        bufp->chgBit(oldp+211,((1U & ((~ (IData)(vlSelf->rv32__DOT__idu_inst__DOT__post_valid_reg)) 
                                      & (~ (IData)(vlSelf->rv32__DOT__w_wbu_cycle_end))))));
        bufp->chgWData(oldp+212,(vlSelf->rv32__DOT__idu_inst__DOT__idu_valid_data_reg),111);
        bufp->chgIData(oldp+216,(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_inst),32);
        bufp->chgQData(oldp+217,(vlSelf->rv32__DOT__ifu_inst__DOT__ifu_valid_data_reg),64);
        bufp->chgIData(oldp+219,(vlSelf->rv32__DOT__lsu_inst__DOT__lsu_mem_rdata_reg),32);
        bufp->chgCData(oldp+220,(((IData)((0x8000000U 
                                           == (0xf000000U 
                                               & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U])))
                                   ? 1U : ((IData)(
                                                   (0x9000000U 
                                                    == 
                                                    (0xf000000U 
                                                     & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U])))
                                            ? 3U : 
                                           ((IData)(
                                                    (0xa000000U 
                                                     == 
                                                     (0xf000000U 
                                                      & vlSelf->rv32__DOT__exu_inst__DOT__exu_valid_data_reg[6U])))
                                             ? 0xfU
                                             : 0U)))),8);
        bufp->chgIData(oldp+221,(vlSelf->rv32__DOT__lsu_inst__DOT__unnamedblk1__DOT__raw_read_data),32);
        bufp->chgIData(oldp+222,(vlSelf->rv32__DOT__register_file_inst__DOT__i),32);
        bufp->chgIData(oldp+223,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[0]),32);
        bufp->chgIData(oldp+224,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[1]),32);
        bufp->chgIData(oldp+225,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[2]),32);
        bufp->chgIData(oldp+226,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[3]),32);
        bufp->chgIData(oldp+227,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[4]),32);
        bufp->chgIData(oldp+228,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[5]),32);
        bufp->chgIData(oldp+229,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[6]),32);
        bufp->chgIData(oldp+230,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[7]),32);
        bufp->chgIData(oldp+231,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[8]),32);
        bufp->chgIData(oldp+232,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[9]),32);
        bufp->chgIData(oldp+233,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[10]),32);
        bufp->chgIData(oldp+234,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[11]),32);
        bufp->chgIData(oldp+235,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[12]),32);
        bufp->chgIData(oldp+236,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[13]),32);
        bufp->chgIData(oldp+237,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[14]),32);
        bufp->chgIData(oldp+238,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[15]),32);
        bufp->chgIData(oldp+239,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[16]),32);
        bufp->chgIData(oldp+240,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[17]),32);
        bufp->chgIData(oldp+241,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[18]),32);
        bufp->chgIData(oldp+242,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[19]),32);
        bufp->chgIData(oldp+243,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[20]),32);
        bufp->chgIData(oldp+244,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[21]),32);
        bufp->chgIData(oldp+245,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[22]),32);
        bufp->chgIData(oldp+246,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[23]),32);
        bufp->chgIData(oldp+247,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[24]),32);
        bufp->chgIData(oldp+248,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[25]),32);
        bufp->chgIData(oldp+249,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[26]),32);
        bufp->chgIData(oldp+250,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[27]),32);
        bufp->chgIData(oldp+251,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[28]),32);
        bufp->chgIData(oldp+252,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[29]),32);
        bufp->chgIData(oldp+253,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[30]),32);
        bufp->chgIData(oldp+254,(vlSelf->rv32__DOT__register_file_inst__DOT__regs[31]),32);
        bufp->chgBit(oldp+255,(vlSelf->rv32__DOT__wbu_inst__DOT__pre_valid_reg));
    }
    bufp->chgBit(oldp+256,(vlSelf->clk));
    bufp->chgBit(oldp+257,(vlSelf->rst));
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

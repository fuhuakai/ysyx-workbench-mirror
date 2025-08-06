// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__regs__DOT__reg_val[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->top__DOT__regs__DOT__reg_val[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__regs__DOT__reg_val[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->top__DOT__regs__DOT__reg_val[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__regs__DOT__reg_val[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__regs__DOT__reg_val[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__regs__DOT__reg_val[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__regs__DOT__reg_val[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__regs__DOT__reg_val[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__regs__DOT__reg_val[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__regs__DOT__reg_val[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__regs__DOT__reg_val[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__regs__DOT__reg_val[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__regs__DOT__reg_val[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__regs__DOT__reg_val[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__regs__DOT__reg_val[15]),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__regs__DOT__reg_val[16]),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__regs__DOT__reg_val[17]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__regs__DOT__reg_val[18]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__regs__DOT__reg_val[19]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__regs__DOT__reg_val[20]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__regs__DOT__reg_val[21]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__regs__DOT__reg_val[22]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__regs__DOT__reg_val[23]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__regs__DOT__reg_val[24]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__regs__DOT__reg_val[25]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__regs__DOT__reg_val[26]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__regs__DOT__reg_val[27]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__regs__DOT__reg_val[28]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__regs__DOT__reg_val[29]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__regs__DOT__reg_val[30]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__regs__DOT__reg_val[31]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout),32);
    }
    bufp->chgBit(oldp+63,(vlSelf->clk));
    bufp->chgBit(oldp+64,(vlSelf->rst));
    bufp->chgIData(oldp+65,(vlSelf->pc),32);
    bufp->chgIData(oldp+66,(vlSelf->inst),32);
    bufp->chgBit(oldp+67,(vlSelf->trap));
    bufp->chgIData(oldp+68,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgBit(oldp+69,(vlSelf->top__DOT__rf_wen));
    bufp->chgCData(oldp+70,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgIData(oldp+71,(((0U == (0x1fU & (vlSelf->inst 
                                              >> 0xfU)))
                              ? 0U : vlSelf->top__DOT__regs__DOT__reg_val
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))])),32);
    bufp->chgCData(oldp+72,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgIData(oldp+73,(vlSelf->top__DOT__rf_wdata),32);
    bufp->chgIData(oldp+74,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->inst 
                                          >> 0x14U))),32);
    bufp->chgBit(oldp+75,((IData)((0x100073U == (0x10707fU 
                                                 & vlSelf->inst)))));
    bufp->chgCData(oldp+76,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+77,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgBit(oldp+78,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x500U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+79,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x580U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+80,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x600U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+81,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x680U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+82,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x700U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+83,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x780U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+84,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x800U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+85,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x880U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+86,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x900U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+87,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x980U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+88,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+89,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xa00U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+90,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xa80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+91,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xb00U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+92,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xb80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+93,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xc00U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+94,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xc80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+95,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xd00U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+96,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xd80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+97,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xe00U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+98,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0xe80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+99,(((IData)(vlSelf->top__DOT__rf_wen) 
                           & (0x100U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+100,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xf00U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+101,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0xf80U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+102,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x180U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+103,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x200U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+104,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x280U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+105,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x300U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+106,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x380U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+107,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x400U == (0xf80U & vlSelf->inst)))));
    bufp->chgBit(oldp+108,(((IData)(vlSelf->top__DOT__rf_wen) 
                            & (0x480U == (0xf80U & vlSelf->inst)))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}

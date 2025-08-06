// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__trap = vlSelf->trap;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top__DOT__regs__DOT__reg_val[0U] = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    VL_WRITEF("[IDU] inst=0x%8x, opcode=0x%02x, rs1=x%0#, rd=x%0#, imm=0x%8x\n",
              32,vlSelf->inst,7,(0x7fU & vlSelf->inst),
              5,(0x1fU & (vlSelf->inst >> 0xfU)),5,
              (0x1fU & (vlSelf->inst >> 7U)),32,(((- (IData)(
                                                             (vlSelf->inst 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (vlSelf->inst 
                                                    >> 0x14U)));
    vlSelf->top__DOT__next_pc = ((IData)(4U) + vlSelf->pc);
    vlSelf->top__DOT__rf_wen = (IData)((0x13U == (0x707fU 
                                                  & vlSelf->inst)));
    vlSelf->top__DOT__regs__DOT__reg_val[1U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[2U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[3U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[4U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[5U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[6U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[7U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[8U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[9U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xaU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xbU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xcU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xdU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xeU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xfU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x10U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x11U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x12U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x13U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x14U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x15U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x16U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x17U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x18U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x19U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1aU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1bU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1cU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1dU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1eU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1fU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__rf_wdata = ((((- (IData)((vlSelf->inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelf->inst 
                                                >> 0x14U)) 
                                  + ((0U == (0x1fU 
                                             & (vlSelf->inst 
                                                >> 0xfU)))
                                      ? 0U : vlSelf->top__DOT__regs__DOT__reg_val
                                     [(0x1fU & (vlSelf->inst 
                                                >> 0xfU))]));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge trap)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge trap)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->trap = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rf_wdata = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regs__DOT__reg_val[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__trap = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

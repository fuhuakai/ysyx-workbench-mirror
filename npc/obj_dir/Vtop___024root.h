// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(trap,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ top__DOT__rf_wen;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__trap;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    VL_IN(inst,31,0);
    IData/*31:0*/ top__DOT__next_pc;
    IData/*31:0*/ top__DOT__rf_wdata;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout;
    IData/*31:0*/ top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__regs__DOT__reg_val;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

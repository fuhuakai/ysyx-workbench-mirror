// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
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
    vlSelf->top__DOT__rf_wen = (IData)((0x13U == (0x707fU 
                                                  & vlSelf->inst)));
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__exu__DOT__ebreak_TOP();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY(vlSelf->trap)) {
        VL_WRITEF("[EXU] EBREAK detected, stopping simulation\n");
        Vtop___024root____Vdpiimwrap_top__DOT__exu__DOT__ebreak_TOP();
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x1 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x100U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x2 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x180U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x3 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x200U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x4 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x280U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x5 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x300U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x6 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x380U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x7 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x400U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x8 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x480U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x9 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x500U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x10 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x580U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x11 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x600U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x12 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x680U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x13 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x700U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x14 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x780U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x15 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x800U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x16 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x880U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x17 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x900U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x18 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0x980U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x19 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xa00U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x20 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xa80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x21 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xb00U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x22 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xb80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x23 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xc00U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x24 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xc80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x25 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xd00U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x26 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xd80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x27 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xe00U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x28 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xe80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x29 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xf00U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x30 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->top__DOT__rf_wen) 
                     & (0xf80U == (0xf80U & vlSelf->inst))))) {
        VL_WRITEF("[REG] x31 <= 0x%8x\n",32,vlSelf->top__DOT__rf_wdata);
    }
    if (vlSelf->rst) {
        vlSelf->pc = 0x80000000U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout = 0U;
        vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout = 0U;
    } else {
        vlSelf->pc = vlSelf->top__DOT__next_pc;
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xf80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xf00U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xe80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xe00U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xd80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xd00U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xc80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xc00U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xb80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xb00U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xa80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0xa00U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x980U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x900U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x880U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x800U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x780U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x700U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x680U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x600U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x580U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x500U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x480U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x400U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x380U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x300U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x280U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x200U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x180U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x100U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
        if (((IData)(vlSelf->top__DOT__rf_wen) & (0x80U 
                                                  == 
                                                  (0xf80U 
                                                   & vlSelf->inst)))) {
            vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout 
                = vlSelf->top__DOT__rf_wdata;
        }
    }
    vlSelf->trap = ((~ (IData)(vlSelf->rst)) & (IData)(
                                                       (0x100073U 
                                                        == 
                                                        (0x10707fU 
                                                         & vlSelf->inst))));
    vlSelf->top__DOT__next_pc = ((IData)(4U) + vlSelf->pc);
    vlSelf->top__DOT__regs__DOT__reg_val[0x1fU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__31__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1eU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__30__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1dU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__29__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1cU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__28__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1bU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__27__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x1aU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__26__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x19U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__25__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x18U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__24__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x17U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__23__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x16U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__22__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x15U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__21__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x14U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__20__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x13U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__19__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x12U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__18__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x11U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__17__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0x10U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__16__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xfU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__15__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xeU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__14__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xdU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__13__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xcU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__12__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xbU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__11__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[0xaU] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__10__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[9U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__9__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[8U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__8__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[7U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__7__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[6U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__6__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[5U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__5__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[4U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__4__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[3U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__3__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[2U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__2__KET____DOT__reg_inst__dout;
    vlSelf->top__DOT__regs__DOT__reg_val[1U] = vlSelf->top__DOT__regs__DOT____Vcellout__reg_gen__BRA__1__KET____DOT__reg_inst__dout;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG

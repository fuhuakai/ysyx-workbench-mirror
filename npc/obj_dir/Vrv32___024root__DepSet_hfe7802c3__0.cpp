// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vrv32___024root.h"

void Vrv32___024root___eval_act(Vrv32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root___eval_act\n"); );
}

void Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(IData/*31:0*/ station, IData/*31:0*/ inst, CData/*7:0*/ unit);
void Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vrv32___024root____Vdpiimwrap_rv32__DOT__control_unit_inst__DOT__etrace_TOP(IData/*31:0*/ inst);
void Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_INLINE_OPT void Vrv32___024root___nba_sequent__TOP__0(Vrv32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v0;
    __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__rv32__DOT__register_file_inst__DOT__regs__v32;
    __Vdlyvdim0__rv32__DOT__register_file_inst__DOT__regs__v32 = 0;
    IData/*31:0*/ __Vdlyvval__rv32__DOT__register_file_inst__DOT__regs__v32;
    __Vdlyvval__rv32__DOT__register_file_inst__DOT__regs__v32 = 0;
    CData/*0:0*/ __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v32;
    __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v32 = 0;
    // Body
    __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v0 = 0U;
    __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v32 = 0U;
    if (vlSelf->rst) {
        vlSelf->rv32__DOT__register_file_inst__DOT__i = 0x20U;
        __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v0 = 1U;
    } else {
        __Vdlyvval__rv32__DOT__register_file_inst__DOT__regs__v32 
            = (((IData)(vlSelf->rv32__DOT__reg_wen) 
                & (0U != (0x1fU & (vlSelf->rv32__DOT__inst 
                                   >> 7U)))) ? vlSelf->rv32__DOT__reg_in
                : vlSelf->rv32__DOT__register_file_inst__DOT__regs
               [(0x1fU & (vlSelf->rv32__DOT__inst >> 7U))]);
        __Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v32 = 1U;
        __Vdlyvdim0__rv32__DOT__register_file_inst__DOT__regs__v32 
            = (0x1fU & (vlSelf->rv32__DOT__inst >> 7U));
    }
    if (vlSelf->rst) {
        vlSelf->rv32__DOT__csr_regs_inst__DOT__mstatus = 0U;
        vlSelf->rv32__DOT__csr_regs_inst__DOT__mtvec = 0U;
        vlSelf->rv32__DOT__csr_regs_inst__DOT__mepc = 0U;
        vlSelf->rv32__DOT__csr_regs_inst__DOT__mcause = 0U;
    } else if (vlSelf->rv32__DOT__is_ecall) {
        vlSelf->rv32__DOT__csr_regs_inst__DOT__mepc 
            = vlSelf->rv32__DOT__pc;
        vlSelf->rv32__DOT__csr_regs_inst__DOT__mcause = 0xbU;
    } else if (vlSelf->rv32__DOT__csr_wen) {
        if ((0x300U == (vlSelf->rv32__DOT__inst >> 0x14U))) {
            vlSelf->rv32__DOT__csr_regs_inst__DOT__mstatus 
                = vlSelf->rv32__DOT__csr_regs_inst__DOT__csr_wdata;
        } else if ((0x305U == (vlSelf->rv32__DOT__inst 
                               >> 0x14U))) {
            vlSelf->rv32__DOT__csr_regs_inst__DOT__mtvec 
                = vlSelf->rv32__DOT__csr_regs_inst__DOT__csr_wdata;
        } else if ((0x341U == (vlSelf->rv32__DOT__inst 
                               >> 0x14U))) {
            vlSelf->rv32__DOT__csr_regs_inst__DOT__mepc 
                = vlSelf->rv32__DOT__csr_regs_inst__DOT__csr_wdata;
        } else if ((0x342U == (vlSelf->rv32__DOT__inst 
                               >> 0x14U))) {
            vlSelf->rv32__DOT__csr_regs_inst__DOT__mcause 
                = vlSelf->rv32__DOT__csr_regs_inst__DOT__csr_wdata;
        } else {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeadbeefU, 0x10U);
        }
    }
    vlSelf->rv32__DOT__pc = ((IData)(vlSelf->rst) ? 0x80000000U
                              : vlSelf->rv32__DOT__PC_inst__DOT__npc);
    if (__Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v0) {
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[1U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[2U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[3U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[4U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[5U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[6U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[7U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[8U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[9U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0xaU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0xbU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0xcU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0xdU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0xeU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0xfU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x10U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x11U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x12U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x13U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x14U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x15U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x16U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x17U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x18U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x19U] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x1aU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x1bU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x1cU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x1dU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x1eU] = 0U;
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[0x1fU] = 0U;
    }
    if (__Vdlyvset__rv32__DOT__register_file_inst__DOT__regs__v32) {
        vlSelf->rv32__DOT__register_file_inst__DOT__regs[__Vdlyvdim0__rv32__DOT__register_file_inst__DOT__regs__v32] 
            = __Vdlyvval__rv32__DOT__register_file_inst__DOT__regs__v32;
    }
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->rv32__DOT__pc));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(((IData)(4U) + vlSelf->rv32__DOT__pc)));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[3U] 
        = (QData)((IData)(((IData)(4U) + vlSelf->rv32__DOT__pc)));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[3U] 
        = ((IData)(4U) + vlSelf->rv32__DOT__pc);
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[3U] 
        = ((IData)(4U) + vlSelf->rv32__DOT__pc);
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[1U] 
        = vlSelf->rv32__DOT__pc;
    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__pmem_read_TOP(vlSelf->rv32__DOT__pc, vlSelf->__Vfunc_rv32__DOT__mem_inst__DOT__pmem_read__0__Vfuncout);
    vlSelf->rv32__DOT__inst = vlSelf->__Vfunc_rv32__DOT__mem_inst__DOT__pmem_read__0__Vfuncout;
    if ((0x200000U & vlSelf->rv32__DOT__inst)) {
        vlSelf->rv32__DOT__csr_npc = vlSelf->rv32__DOT__csr_regs_inst__DOT__mepc;
        vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1U] 
            = vlSelf->rv32__DOT__csr_regs_inst__DOT__mepc;
    } else {
        vlSelf->rv32__DOT__csr_npc = vlSelf->rv32__DOT__csr_regs_inst__DOT__mtvec;
        vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[1U] 
            = vlSelf->rv32__DOT__csr_regs_inst__DOT__mtvec;
    }
    if ((0U == (0x1fU & (vlSelf->rv32__DOT__inst >> 0x14U)))) {
        vlSelf->rv32__DOT__src2 = 0U;
        vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[1U] = 0U;
    } else {
        vlSelf->rv32__DOT__src2 = vlSelf->rv32__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->rv32__DOT__inst >> 0x14U))];
        vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[1U] 
            = vlSelf->rv32__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->rv32__DOT__inst >> 0x14U))];
    }
    if ((0U == (0x1fU & (vlSelf->rv32__DOT__inst >> 0xfU)))) {
        vlSelf->rv32__DOT__src1 = 0U;
        vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[0U] = 0U;
    } else {
        vlSelf->rv32__DOT__src1 = vlSelf->rv32__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->rv32__DOT__inst >> 0xfU))];
        vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list[0U] 
            = vlSelf->rv32__DOT__register_file_inst__DOT__regs
            [(0x1fU & (vlSelf->rv32__DOT__inst >> 0xfU))];
    }
    vlSelf->rv32__DOT__csr_data = ((0x300U == (vlSelf->rv32__DOT__inst 
                                               >> 0x14U))
                                    ? vlSelf->rv32__DOT__csr_regs_inst__DOT__mstatus
                                    : ((0x305U == (vlSelf->rv32__DOT__inst 
                                                   >> 0x14U))
                                        ? vlSelf->rv32__DOT__csr_regs_inst__DOT__mtvec
                                        : ((0x341U 
                                            == (vlSelf->rv32__DOT__inst 
                                                >> 0x14U))
                                            ? vlSelf->rv32__DOT__csr_regs_inst__DOT__mepc
                                            : ((0x342U 
                                                == 
                                                (vlSelf->rv32__DOT__inst 
                                                 >> 0x14U))
                                                ? vlSelf->rv32__DOT__csr_regs_inst__DOT__mcause
                                                : 0U))));
    vlSelf->rv32__DOT__csr_wen = 0U;
    if ((0x40U & vlSelf->rv32__DOT__inst)) {
        if ((0x20U & vlSelf->rv32__DOT__inst)) {
            if ((0x10U & vlSelf->rv32__DOT__inst)) {
                if ((8U & vlSelf->rv32__DOT__inst)) {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                } else if ((4U & vlSelf->rv32__DOT__inst)) {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                } else if ((2U & vlSelf->rv32__DOT__inst)) {
                    if ((1U & vlSelf->rv32__DOT__inst)) {
                        vlSelf->rv32__DOT__Inst_type = 2U;
                        vlSelf->rv32__DOT__aluc = 0U;
                        vlSelf->rv32__DOT__mem_wen = 0U;
                        vlSelf->rv32__DOT__mem_ren = 0U;
                        vlSelf->rv32__DOT__wmask = 0xfU;
                        vlSelf->rv32__DOT__rmask = 0U;
                        vlSelf->rv32__DOT__pc_sel_1 = 0U;
                        vlSelf->rv32__DOT__alu_sel_2 = 1U;
                        vlSelf->rv32__DOT__alu_sel_1 = 0U;
                        vlSelf->rv32__DOT__wb_sel = 3U;
                        if (((1U == (7U & (vlSelf->rv32__DOT__inst 
                                           >> 0xcU))) 
                             | (2U == (7U & (vlSelf->rv32__DOT__inst 
                                             >> 0xcU))))) {
                            vlSelf->rv32__DOT__is_ecall = 0U;
                            vlSelf->rv32__DOT__csr_wen = 1U;
                            vlSelf->rv32__DOT__reg_wen = 1U;
                            vlSelf->rv32__DOT__pc_sel_2 = 0U;
                        } else if ((0x302U == (vlSelf->rv32__DOT__inst 
                                               >> 0x14U))) {
                            vlSelf->rv32__DOT__is_ecall = 0U;
                            vlSelf->rv32__DOT__csr_wen = 0U;
                            vlSelf->rv32__DOT__reg_wen = 0U;
                            vlSelf->rv32__DOT__pc_sel_2 = 2U;
                        } else if ((0U == (vlSelf->rv32__DOT__inst 
                                           >> 0x14U))) {
                            Vrv32___024root____Vdpiimwrap_rv32__DOT__control_unit_inst__DOT__etrace_TOP(0xdeadbeefU);
                            vlSelf->rv32__DOT__is_ecall = 1U;
                            vlSelf->rv32__DOT__csr_wen = 1U;
                            vlSelf->rv32__DOT__reg_wen = 1U;
                            vlSelf->rv32__DOT__pc_sel_2 = 2U;
                        } else if ((1U == (vlSelf->rv32__DOT__inst 
                                           >> 0x14U))) {
                            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(1U, vlSelf->rv32__DOT__inst, 0xaU);
                        } else {
                            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xbU);
                        }
                    } else {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                    }
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else if ((8U & vlSelf->rv32__DOT__inst)) {
                if ((4U & vlSelf->rv32__DOT__inst)) {
                    if ((2U & vlSelf->rv32__DOT__inst)) {
                        if ((1U & vlSelf->rv32__DOT__inst)) {
                            vlSelf->rv32__DOT__Inst_type = 6U;
                            vlSelf->rv32__DOT__aluc = 0U;
                            vlSelf->rv32__DOT__reg_wen = 1U;
                            vlSelf->rv32__DOT__mem_wen = 0U;
                            vlSelf->rv32__DOT__mem_ren = 0U;
                            vlSelf->rv32__DOT__wmask = 0xfU;
                            vlSelf->rv32__DOT__rmask = 0U;
                            vlSelf->rv32__DOT__pc_sel_1 = 0U;
                            vlSelf->rv32__DOT__pc_sel_2 = 1U;
                            vlSelf->rv32__DOT__alu_sel_2 = 1U;
                            vlSelf->rv32__DOT__alu_sel_1 = 0U;
                            vlSelf->rv32__DOT__wb_sel = 0U;
                        } else {
                            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                        }
                    } else {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                    }
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else if ((4U & vlSelf->rv32__DOT__inst)) {
                if ((2U & vlSelf->rv32__DOT__inst)) {
                    if ((1U & vlSelf->rv32__DOT__inst)) {
                        vlSelf->rv32__DOT__Inst_type = 2U;
                        vlSelf->rv32__DOT__aluc = 0xfU;
                        vlSelf->rv32__DOT__reg_wen = 1U;
                        vlSelf->rv32__DOT__mem_wen = 0U;
                        vlSelf->rv32__DOT__mem_ren = 0U;
                        vlSelf->rv32__DOT__wmask = 0xfU;
                        vlSelf->rv32__DOT__rmask = 0U;
                        vlSelf->rv32__DOT__pc_sel_1 = 0U;
                        vlSelf->rv32__DOT__pc_sel_2 = 1U;
                        vlSelf->rv32__DOT__alu_sel_2 = 1U;
                        vlSelf->rv32__DOT__alu_sel_1 = 1U;
                        vlSelf->rv32__DOT__wb_sel = 0U;
                    } else {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                    }
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else if ((2U & vlSelf->rv32__DOT__inst)) {
                if ((1U & vlSelf->rv32__DOT__inst)) {
                    vlSelf->rv32__DOT__Inst_type = 5U;
                    vlSelf->rv32__DOT__reg_wen = 0U;
                    vlSelf->rv32__DOT__mem_wen = 0U;
                    vlSelf->rv32__DOT__mem_ren = 0U;
                    vlSelf->rv32__DOT__wmask = 0xfU;
                    vlSelf->rv32__DOT__rmask = 0U;
                    vlSelf->rv32__DOT__pc_sel_1 = 1U;
                    vlSelf->rv32__DOT__pc_sel_2 = 0U;
                    vlSelf->rv32__DOT__alu_sel_2 = 0U;
                    vlSelf->rv32__DOT__alu_sel_1 = 1U;
                    vlSelf->rv32__DOT__wb_sel = 2U;
                    if ((0x4000U & vlSelf->rv32__DOT__inst)) {
                        vlSelf->rv32__DOT__aluc = (
                                                   (0x2000U 
                                                    & vlSelf->rv32__DOT__inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->rv32__DOT__inst)
                                                     ? 0xdU
                                                     : 0xcU)
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->rv32__DOT__inst)
                                                     ? 0xbU
                                                     : 0xaU));
                    } else if ((0x2000U & vlSelf->rv32__DOT__inst)) {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 9U);
                    } else {
                        vlSelf->rv32__DOT__aluc = (
                                                   (0x1000U 
                                                    & vlSelf->rv32__DOT__inst)
                                                    ? 9U
                                                    : 8U);
                    }
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else {
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
            }
        } else {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        }
    } else if ((0x20U & vlSelf->rv32__DOT__inst)) {
        if ((0x10U & vlSelf->rv32__DOT__inst)) {
            if ((8U & vlSelf->rv32__DOT__inst)) {
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
            } else if ((4U & vlSelf->rv32__DOT__inst)) {
                if ((2U & vlSelf->rv32__DOT__inst)) {
                    if ((1U & vlSelf->rv32__DOT__inst)) {
                        vlSelf->rv32__DOT__Inst_type = 4U;
                        vlSelf->rv32__DOT__aluc = 0xeU;
                        vlSelf->rv32__DOT__reg_wen = 1U;
                        vlSelf->rv32__DOT__mem_wen = 0U;
                        vlSelf->rv32__DOT__mem_ren = 0U;
                        vlSelf->rv32__DOT__wmask = 0xfU;
                        vlSelf->rv32__DOT__rmask = 0U;
                        vlSelf->rv32__DOT__pc_sel_1 = 0U;
                        vlSelf->rv32__DOT__pc_sel_2 = 0U;
                        vlSelf->rv32__DOT__alu_sel_2 = 1U;
                        vlSelf->rv32__DOT__alu_sel_1 = 1U;
                        vlSelf->rv32__DOT__wb_sel = 2U;
                    } else {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                    }
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else if ((2U & vlSelf->rv32__DOT__inst)) {
                if ((1U & vlSelf->rv32__DOT__inst)) {
                    vlSelf->rv32__DOT__Inst_type = 1U;
                    vlSelf->rv32__DOT__reg_wen = 1U;
                    vlSelf->rv32__DOT__mem_wen = 0U;
                    vlSelf->rv32__DOT__mem_ren = 0U;
                    vlSelf->rv32__DOT__wmask = 0xfU;
                    vlSelf->rv32__DOT__rmask = 0U;
                    vlSelf->rv32__DOT__pc_sel_1 = 0U;
                    vlSelf->rv32__DOT__pc_sel_2 = 0U;
                    vlSelf->rv32__DOT__alu_sel_2 = 0U;
                    vlSelf->rv32__DOT__alu_sel_1 = 1U;
                    vlSelf->rv32__DOT__wb_sel = 2U;
                    if ((0U == (vlSelf->rv32__DOT__inst 
                                >> 0x19U))) {
                        vlSelf->rv32__DOT__aluc = (
                                                   (0x4000U 
                                                    & vlSelf->rv32__DOT__inst)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->rv32__DOT__inst)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->rv32__DOT__inst)
                                                      ? 7U
                                                      : 6U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->rv32__DOT__inst)
                                                      ? 4U
                                                      : 3U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->rv32__DOT__inst)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->rv32__DOT__inst)
                                                      ? 0xcU
                                                      : 0xaU)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->rv32__DOT__inst)
                                                      ? 2U
                                                      : 0U)));
                    } else if ((0x20U == (vlSelf->rv32__DOT__inst 
                                          >> 0x19U))) {
                        if ((0U == (7U & (vlSelf->rv32__DOT__inst 
                                          >> 0xcU)))) {
                            vlSelf->rv32__DOT__aluc = 1U;
                        } else if ((5U == (7U & (vlSelf->rv32__DOT__inst 
                                                 >> 0xcU)))) {
                            vlSelf->rv32__DOT__aluc = 5U;
                        } else {
                            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 3U);
                        }
                    } else {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 4U);
                    }
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else {
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
            }
        } else if ((8U & vlSelf->rv32__DOT__inst)) {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        } else if ((4U & vlSelf->rv32__DOT__inst)) {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        } else if ((2U & vlSelf->rv32__DOT__inst)) {
            if ((1U & vlSelf->rv32__DOT__inst)) {
                vlSelf->rv32__DOT__Inst_type = 3U;
                vlSelf->rv32__DOT__aluc = 0U;
                vlSelf->rv32__DOT__reg_wen = 0U;
                vlSelf->rv32__DOT__mem_wen = 1U;
                vlSelf->rv32__DOT__mem_ren = 0U;
                vlSelf->rv32__DOT__rmask = 0U;
                vlSelf->rv32__DOT__pc_sel_1 = 0U;
                vlSelf->rv32__DOT__pc_sel_2 = 0U;
                vlSelf->rv32__DOT__alu_sel_2 = 1U;
                vlSelf->rv32__DOT__alu_sel_1 = 1U;
                vlSelf->rv32__DOT__wb_sel = 1U;
                if ((0U == (7U & (vlSelf->rv32__DOT__inst 
                                  >> 0xcU)))) {
                    vlSelf->rv32__DOT__wmask = 1U;
                } else if ((1U == (7U & (vlSelf->rv32__DOT__inst 
                                         >> 0xcU)))) {
                    vlSelf->rv32__DOT__wmask = 3U;
                } else if ((2U == (7U & (vlSelf->rv32__DOT__inst 
                                         >> 0xcU)))) {
                    vlSelf->rv32__DOT__wmask = 0xfU;
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 8U);
                }
            } else {
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
            }
        } else {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        }
    } else if ((0x10U & vlSelf->rv32__DOT__inst)) {
        if ((8U & vlSelf->rv32__DOT__inst)) {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        } else if ((4U & vlSelf->rv32__DOT__inst)) {
            if ((2U & vlSelf->rv32__DOT__inst)) {
                if ((1U & vlSelf->rv32__DOT__inst)) {
                    vlSelf->rv32__DOT__Inst_type = 4U;
                    vlSelf->rv32__DOT__aluc = 0U;
                    vlSelf->rv32__DOT__reg_wen = 1U;
                    vlSelf->rv32__DOT__mem_wen = 0U;
                    vlSelf->rv32__DOT__mem_ren = 0U;
                    vlSelf->rv32__DOT__wmask = 0xfU;
                    vlSelf->rv32__DOT__rmask = 0U;
                    vlSelf->rv32__DOT__pc_sel_1 = 0U;
                    vlSelf->rv32__DOT__pc_sel_2 = 0U;
                    vlSelf->rv32__DOT__alu_sel_2 = 1U;
                    vlSelf->rv32__DOT__alu_sel_1 = 0U;
                    vlSelf->rv32__DOT__wb_sel = 2U;
                } else {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
                }
            } else {
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
            }
        } else if ((2U & vlSelf->rv32__DOT__inst)) {
            if ((1U & vlSelf->rv32__DOT__inst)) {
                vlSelf->rv32__DOT__Inst_type = 2U;
                vlSelf->rv32__DOT__reg_wen = 1U;
                vlSelf->rv32__DOT__mem_wen = 0U;
                vlSelf->rv32__DOT__mem_ren = 0U;
                vlSelf->rv32__DOT__wmask = 0xfU;
                vlSelf->rv32__DOT__rmask = 0U;
                vlSelf->rv32__DOT__pc_sel_1 = 0U;
                vlSelf->rv32__DOT__pc_sel_2 = 0U;
                vlSelf->rv32__DOT__alu_sel_2 = 1U;
                vlSelf->rv32__DOT__alu_sel_1 = 1U;
                vlSelf->rv32__DOT__wb_sel = 2U;
                if ((0x4000U & vlSelf->rv32__DOT__inst)) {
                    if ((0x2000U & vlSelf->rv32__DOT__inst)) {
                        vlSelf->rv32__DOT__aluc = (
                                                   (0x1000U 
                                                    & vlSelf->rv32__DOT__inst)
                                                    ? 7U
                                                    : 6U);
                    } else if ((0x1000U & vlSelf->rv32__DOT__inst)) {
                        if ((0U == (vlSelf->rv32__DOT__inst 
                                    >> 0x19U))) {
                            vlSelf->rv32__DOT__aluc = 4U;
                        } else if ((0x20U == (vlSelf->rv32__DOT__inst 
                                              >> 0x19U))) {
                            vlSelf->rv32__DOT__aluc = 5U;
                        } else {
                            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 5U);
                        }
                    } else {
                        vlSelf->rv32__DOT__aluc = 3U;
                    }
                } else if ((0x2000U & vlSelf->rv32__DOT__inst)) {
                    if ((0x1000U & vlSelf->rv32__DOT__inst)) {
                        vlSelf->rv32__DOT__aluc = 0xcU;
                    } else {
                        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 6U);
                    }
                } else {
                    vlSelf->rv32__DOT__aluc = ((0x1000U 
                                                & vlSelf->rv32__DOT__inst)
                                                ? 2U
                                                : 0U);
                }
            } else {
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
            }
        } else {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        }
    } else if ((8U & vlSelf->rv32__DOT__inst)) {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
    } else if ((4U & vlSelf->rv32__DOT__inst)) {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
    } else if ((2U & vlSelf->rv32__DOT__inst)) {
        if ((1U & vlSelf->rv32__DOT__inst)) {
            vlSelf->rv32__DOT__Inst_type = 2U;
            vlSelf->rv32__DOT__aluc = 0U;
            vlSelf->rv32__DOT__reg_wen = 1U;
            vlSelf->rv32__DOT__mem_wen = 0U;
            vlSelf->rv32__DOT__mem_ren = 1U;
            vlSelf->rv32__DOT__wmask = 0xfU;
            vlSelf->rv32__DOT__pc_sel_1 = 0U;
            vlSelf->rv32__DOT__pc_sel_2 = 0U;
            vlSelf->rv32__DOT__alu_sel_2 = 1U;
            vlSelf->rv32__DOT__alu_sel_1 = 1U;
            vlSelf->rv32__DOT__wb_sel = 1U;
            if ((0x4000U & vlSelf->rv32__DOT__inst)) {
                if ((0x2000U & vlSelf->rv32__DOT__inst)) {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 7U);
                } else {
                    vlSelf->rv32__DOT__rmask = ((0x1000U 
                                                 & vlSelf->rv32__DOT__inst)
                                                 ? 2U
                                                 : 1U);
                }
            } else if ((0x2000U & vlSelf->rv32__DOT__inst)) {
                if ((0x1000U & vlSelf->rv32__DOT__inst)) {
                    Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 7U);
                } else {
                    vlSelf->rv32__DOT__rmask = 0U;
                }
            } else {
                vlSelf->rv32__DOT__rmask = ((0x1000U 
                                             & vlSelf->rv32__DOT__inst)
                                             ? 4U : 3U);
            }
        } else {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
        }
    } else {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, vlSelf->rv32__DOT__inst, 0xcU);
    }
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->rv32__DOT__csr_npc)));
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->rv32__DOT__src2));
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->rv32__DOT__src1)));
    vlSelf->rv32__DOT__csr_regs_inst__DOT__csr_wdata 
        = ((0x2000U & vlSelf->rv32__DOT__inst) ? (vlSelf->rv32__DOT__csr_data 
                                                  | vlSelf->rv32__DOT__src1)
            : vlSelf->rv32__DOT__src1);
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[0U] 
        = (0x300000000ULL | (QData)((IData)(vlSelf->rv32__DOT__csr_data)));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[0U] 
        = vlSelf->rv32__DOT__csr_data;
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__wb_sel) 
                                                == 
                                                vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                                                [0U]);
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit) 
                                                | ((IData)(vlSelf->rv32__DOT__wb_sel) 
                                                   == 
                                                   vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                                                   [1U]));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit) 
                                                | ((IData)(vlSelf->rv32__DOT__wb_sel) 
                                                   == 
                                                   vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                                                   [2U]));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__i5__DOT__i0__DOT__hit) 
                                                | ((IData)(vlSelf->rv32__DOT__wb_sel) 
                                                   == 
                                                   vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                                                   [3U]));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->rv32__DOT__pc_sel_2) == 
           vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->rv32__DOT__pc_sel_2) 
              == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->rv32__DOT__pc_sel_2) 
              == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->rv32__DOT__pc_sel_2) 
              == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__alu_sel_2) 
                                                == 
                                                vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list
                                                [0U]);
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__i3__DOT__i0__DOT__hit) 
                                                | ((IData)(vlSelf->rv32__DOT__alu_sel_2) 
                                                   == 
                                                   vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list
                                                   [1U]));
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__alu_sel_1) 
                                                == 
                                                vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list
                                                [0U]);
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__hit = ((IData)(vlSelf->rv32__DOT__i4__DOT__i0__DOT__hit) 
                                                | ((IData)(vlSelf->rv32__DOT__alu_sel_1) 
                                                   == 
                                                   vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list
                                                   [1U]));
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__lut_out = 
        ((- (IData)(((IData)(vlSelf->rv32__DOT__alu_sel_1) 
                     == vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list
                     [0U]))) & vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list
         [0U]);
    vlSelf->rv32__DOT__i4__DOT__i0__DOT__lut_out = 
        (vlSelf->rv32__DOT__i4__DOT__i0__DOT__lut_out 
         | ((- (IData)(((IData)(vlSelf->rv32__DOT__alu_sel_1) 
                        == vlSelf->rv32__DOT__i4__DOT__i0__DOT__key_list
                        [1U]))) & vlSelf->rv32__DOT__i4__DOT__i0__DOT__data_list
            [1U]));
    vlSelf->rv32__DOT__num1 = vlSelf->rv32__DOT__i4__DOT__i0__DOT__lut_out;
    if ((4U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        if ((2U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
            if ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
                vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12 = 0U;
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xdU);
            } else {
                vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12 = 0U;
            }
        } else {
            vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12 
                = ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))
                    ? ((0x800U & (vlSelf->rv32__DOT__inst 
                                  >> 0x14U)) | ((0x400U 
                                                 & (vlSelf->rv32__DOT__inst 
                                                    << 3U)) 
                                                | ((0x3f0U 
                                                    & (vlSelf->rv32__DOT__inst 
                                                       >> 0x15U)) 
                                                   | (0xfU 
                                                      & (vlSelf->rv32__DOT__inst 
                                                         >> 8U)))))
                    : 0U);
        }
    } else if ((2U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12 
            = (0xfffU & ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))
                          ? ((0xfe0U & (vlSelf->rv32__DOT__inst 
                                        >> 0x14U)) 
                             | (0x1fU & (vlSelf->rv32__DOT__inst 
                                         >> 7U))) : 
                         (vlSelf->rv32__DOT__inst >> 0x14U)));
    } else if ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12 = 0U;
    } else {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xdU);
        vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12 = 0U;
    }
    if ((4U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        if ((2U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
            if ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
                vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 = 0U;
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xeU);
            } else {
                vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 
                    = ((0x80000U & (vlSelf->rv32__DOT__inst 
                                    >> 0xcU)) | ((0x7c000U 
                                                  & (vlSelf->rv32__DOT__inst 
                                                     >> 1U)) 
                                                 | ((0x3800U 
                                                     & (vlSelf->rv32__DOT__inst 
                                                        >> 1U)) 
                                                    | ((0x400U 
                                                        & (vlSelf->rv32__DOT__inst 
                                                           >> 0xaU)) 
                                                       | (0x3ffU 
                                                          & (vlSelf->rv32__DOT__inst 
                                                             >> 0x15U))))));
            }
        } else {
            vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 
                = ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))
                    ? 0U : (vlSelf->rv32__DOT__inst 
                            >> 0xcU));
        }
    } else if ((2U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 = 0U;
    } else if ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 = 0U;
    } else {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xeU);
        vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 = 0U;
    }
    vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12_to_32 
        = (((- (IData)((1U & ((IData)(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12) 
                              >> 0xbU)))) << 0xcU) 
           | (IData)(vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12));
    vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20_to_32 
        = (((- (IData)((1U & (vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20 
                              >> 0x13U)))) << 0x14U) 
           | vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20);
    if ((4U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        if ((2U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
            if ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
                vlSelf->rv32__DOT__imm32 = 0xdeafbeafU;
                Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xfU);
            } else {
                vlSelf->rv32__DOT__imm32 = (vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20_to_32 
                                            << 1U);
            }
        } else {
            vlSelf->rv32__DOT__imm32 = ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))
                                         ? (vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12_to_32 
                                            << 1U) : 
                                        (vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_20_to_32 
                                         << 0xcU));
        }
    } else if ((2U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        vlSelf->rv32__DOT__imm32 = vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12_to_32;
    } else if ((1U & (IData)(vlSelf->rv32__DOT__Inst_type))) {
        vlSelf->rv32__DOT__imm32 = vlSelf->rv32__DOT__imm_extend_inst__DOT__imm_12_to_32;
    } else {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0xfU);
        vlSelf->rv32__DOT__imm32 = 0xdeafbeafU;
    }
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->rv32__DOT__imm32)));
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)((vlSelf->rv32__DOT__imm32 
                                             + vlSelf->rv32__DOT__pc))));
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[0U] 
        = (vlSelf->rv32__DOT__imm32 + vlSelf->rv32__DOT__pc);
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list[0U] 
        = vlSelf->rv32__DOT__imm32;
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__lut_out = 
        ((- (IData)(((IData)(vlSelf->rv32__DOT__alu_sel_2) 
                     == vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list
                     [0U]))) & vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list
         [0U]);
    vlSelf->rv32__DOT__i3__DOT__i0__DOT__lut_out = 
        (vlSelf->rv32__DOT__i3__DOT__i0__DOT__lut_out 
         | ((- (IData)(((IData)(vlSelf->rv32__DOT__alu_sel_2) 
                        == vlSelf->rv32__DOT__i3__DOT__i0__DOT__key_list
                        [1U]))) & vlSelf->rv32__DOT__i3__DOT__i0__DOT__data_list
            [1U]));
    vlSelf->rv32__DOT__num2 = vlSelf->rv32__DOT__i3__DOT__i0__DOT__lut_out;
    if ((0x10U & (IData)(vlSelf->rv32__DOT__aluc))) {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 0U);
        vlSelf->rv32__DOT__result = 0U;
    } else {
        vlSelf->rv32__DOT__result = ((8U & (IData)(vlSelf->rv32__DOT__aluc))
                                      ? ((4U & (IData)(vlSelf->rv32__DOT__aluc))
                                          ? ((2U & (IData)(vlSelf->rv32__DOT__aluc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 (0xfffffffeU 
                                                  & (vlSelf->rv32__DOT__num1 
                                                     + vlSelf->rv32__DOT__num2))
                                                  : vlSelf->rv32__DOT__num2)
                                              : ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 (vlSelf->rv32__DOT__num1 
                                                  >= vlSelf->rv32__DOT__num2)
                                                  : 
                                                 (vlSelf->rv32__DOT__num1 
                                                  < vlSelf->rv32__DOT__num2)))
                                          : ((2U & (IData)(vlSelf->rv32__DOT__aluc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 VL_GTES_III(32, vlSelf->rv32__DOT__num1, vlSelf->rv32__DOT__num2)
                                                  : 
                                                 VL_LTS_III(32, vlSelf->rv32__DOT__num1, vlSelf->rv32__DOT__num2))
                                              : ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 (vlSelf->rv32__DOT__num1 
                                                  != vlSelf->rv32__DOT__num2)
                                                  : 
                                                 (vlSelf->rv32__DOT__num1 
                                                  == vlSelf->rv32__DOT__num2))))
                                      : ((4U & (IData)(vlSelf->rv32__DOT__aluc))
                                          ? ((2U & (IData)(vlSelf->rv32__DOT__aluc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 (vlSelf->rv32__DOT__num1 
                                                  & vlSelf->rv32__DOT__num2)
                                                  : 
                                                 (vlSelf->rv32__DOT__num1 
                                                  | vlSelf->rv32__DOT__num2))
                                              : ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & vlSelf->rv32__DOT__num2))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->rv32__DOT__num1, 
                                                                 (0x1fU 
                                                                  & vlSelf->rv32__DOT__num2))
                                                   : 
                                                  (- 
                                                   (vlSelf->rv32__DOT__num1 
                                                    >> 0x1fU)))
                                                  : 
                                                 ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & vlSelf->rv32__DOT__num2))
                                                   ? 
                                                  (vlSelf->rv32__DOT__num1 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelf->rv32__DOT__num2))
                                                   : 0U)))
                                          : ((2U & (IData)(vlSelf->rv32__DOT__aluc))
                                              ? ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 (vlSelf->rv32__DOT__num1 
                                                  ^ vlSelf->rv32__DOT__num2)
                                                  : 
                                                 ((0x1fU 
                                                   >= vlSelf->rv32__DOT__num2)
                                                   ? 
                                                  (vlSelf->rv32__DOT__num1 
                                                   << vlSelf->rv32__DOT__num2)
                                                   : 0U))
                                              : ((1U 
                                                  & (IData)(vlSelf->rv32__DOT__aluc))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  (vlSelf->rv32__DOT__num1 
                                                   + 
                                                   (~ vlSelf->rv32__DOT__num2)))
                                                  : 
                                                 (vlSelf->rv32__DOT__num1 
                                                  + vlSelf->rv32__DOT__num2)))));
    }
    if (vlSelf->rv32__DOT__mem_wen) {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__pmem_write_TOP(vlSelf->rv32__DOT__result, vlSelf->rv32__DOT__src2, (IData)(vlSelf->rv32__DOT__wmask));
    }
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->rv32__DOT__result)));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[1U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->rv32__DOT__result)));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[1U] 
        = vlSelf->rv32__DOT__result;
    vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2 
        = ((IData)(vlSelf->rv32__DOT__pc_sel_1) & vlSelf->rv32__DOT__result);
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list[2U] 
        = vlSelf->rv32__DOT__result;
    if (vlSelf->rv32__DOT__mem_ren) {
        Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__pmem_read_TOP(vlSelf->rv32__DOT__result, vlSelf->__Vfunc_rv32__DOT__mem_inst__DOT__pmem_read__2__Vfuncout);
        vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp 
            = vlSelf->__Vfunc_rv32__DOT__mem_inst__DOT__pmem_read__2__Vfuncout;
    } else {
        vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp = 0xeaeU;
    }
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
           == vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
              == vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->rv32__DOT__pc_sel_2) 
                       == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
        = (vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->rv32__DOT__pc_sel_2) 
                          == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
        = (vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->rv32__DOT__pc_sel_2) 
                          == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
        = (vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->rv32__DOT__pc_sel_2) 
                          == vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->rv32__DOT__PC_inst__DOT__npc_temp = vlSelf->rv32__DOT__PC_inst__DOT__i2__DOT__i0__DOT__lut_out;
    if ((4U & (IData)(vlSelf->rv32__DOT__rmask))) {
        if ((2U & (IData)(vlSelf->rv32__DOT__rmask))) {
            vlSelf->rv32__DOT__mem_rdata = 0xdeadbeafU;
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 1U);
        } else if ((1U & (IData)(vlSelf->rv32__DOT__rmask))) {
            Vrv32___024root____Vdpiimwrap_rv32__DOT__mem_inst__DOT__ebreak_TOP(2U, 0xdeafbeafU, 1U);
            vlSelf->rv32__DOT__mem_rdata = 0xdeadbeafU;
        } else {
            vlSelf->rv32__DOT__mem_rdata = (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp 
                                                            >> 0xfU)))) 
                                             << 0x10U) 
                                            | (0xffffU 
                                               & vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp));
        }
    } else {
        vlSelf->rv32__DOT__mem_rdata = ((2U & (IData)(vlSelf->rv32__DOT__rmask))
                                         ? ((1U & (IData)(vlSelf->rv32__DOT__rmask))
                                             ? (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | (0xffU 
                                                   & vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp))
                                             : (0xffffU 
                                                & vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp))
                                         : ((1U & (IData)(vlSelf->rv32__DOT__rmask))
                                             ? (0xffU 
                                                & vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp)
                                             : vlSelf->rv32__DOT__mem_inst__DOT__rdata_temp));
    }
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->rv32__DOT__PC_inst__DOT__npc_temp));
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list[1U] 
        = vlSelf->rv32__DOT__PC_inst__DOT__npc_temp;
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__pair_list[2U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->rv32__DOT__mem_rdata)));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list[2U] 
        = vlSelf->rv32__DOT__mem_rdata;
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
                       == vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->rv32__DOT__PC_inst__DOT____Vcellinp__i1____pinNumber2) 
                          == vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->rv32__DOT__PC_inst__DOT__npc = vlSelf->rv32__DOT__PC_inst__DOT__i1__DOT__i0__DOT__lut_out;
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out = 
        ((- (IData)(((IData)(vlSelf->rv32__DOT__wb_sel) 
                     == vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                     [0U]))) & vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list
         [0U]);
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out = 
        (vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out 
         | ((- (IData)(((IData)(vlSelf->rv32__DOT__wb_sel) 
                        == vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                        [1U]))) & vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list
            [1U]));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out = 
        (vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out 
         | ((- (IData)(((IData)(vlSelf->rv32__DOT__wb_sel) 
                        == vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                        [2U]))) & vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list
            [2U]));
    vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out = 
        (vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out 
         | ((- (IData)(((IData)(vlSelf->rv32__DOT__wb_sel) 
                        == vlSelf->rv32__DOT__i5__DOT__i0__DOT__key_list
                        [3U]))) & vlSelf->rv32__DOT__i5__DOT__i0__DOT__data_list
            [3U]));
    vlSelf->rv32__DOT__reg_in = vlSelf->rv32__DOT__i5__DOT__i0__DOT__lut_out;
}

void Vrv32___024root___eval_nba(Vrv32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vrv32___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vrv32___024root___eval_triggers__act(Vrv32___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32___024root___dump_triggers__act(Vrv32___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32___024root___dump_triggers__nba(Vrv32___024root* vlSelf);
#endif  // VL_DEBUG

void Vrv32___024root___eval(Vrv32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vrv32___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vrv32___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/fuhuakai/ysyx-workbench/npc/vsrc/rv32.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vrv32___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vrv32___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/fuhuakai/ysyx-workbench/npc/vsrc/rv32.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vrv32___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vrv32___024root___eval_debug_assertions(Vrv32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vrv32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG

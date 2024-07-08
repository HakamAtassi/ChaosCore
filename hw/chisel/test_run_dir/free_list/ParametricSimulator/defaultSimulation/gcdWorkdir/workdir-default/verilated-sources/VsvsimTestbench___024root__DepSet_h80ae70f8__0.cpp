// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root___ico_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_ico(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_ico\n"); );
    // Body
    if ((2ULL & vlSelf->__VicoTriggered.word(0U))) {
        VsvsimTestbench___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VsvsimTestbench___024root___ico_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6;
    svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6 = 0;
    // Body
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (1U & (~ (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_0))))));
    vlSelf->svsimTestbench__DOT__dut__DOT___GEN_4 = 
        (3U & ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_2) 
               + (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_3)));
    vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1 
        = (3U & ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_0) 
                 + (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_1)));
    vlSelf->svsimTestbench__DOT__dut__DOT__flush = 
        ((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_is_misprediction) 
         & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid));
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (3U & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                             - (IData)(1U))))));
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (3U & (((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                              + (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_2)) 
                                             - (IData)(1U))))));
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (7U & (((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                              + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT___GEN_4)) 
                                             - (IData)(1U))))));
    svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6 
        = ((~ (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__flush)) 
           & (0U != (0x1fU & (((IData)(1U) + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)) 
                              >> 2U))));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_0 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_0) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_1 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_1) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_2 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_2) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_3 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_3) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
}

void VsvsimTestbench___024root___eval_triggers__ico(VsvsimTestbench___024root* vlSelf);

bool VsvsimTestbench___024root___eval_phase__ico(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VsvsimTestbench___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VsvsimTestbench___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VsvsimTestbench___024root___eval_act(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_act\n"); );
}

void VsvsimTestbench___024root___nba_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___nba_sequent__TOP__1(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___nba_comb__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_nba(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer;
    __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer = 0;
    CData/*6:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__back_pointer;
    __Vdly__svsimTestbench__DOT__dut__DOT__back_pointer = 0;
    // Body
    __Vdly__svsimTestbench__DOT__dut__DOT__back_pointer 
        = vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer;
    __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer 
        = vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer;
    if (vlSelf->svsimTestbench__DOT__reset) {
        __Vdly__svsimTestbench__DOT__dut__DOT__back_pointer = 0x3fU;
        __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer = 0U;
    } else {
        if ((((IData)(vlSelf->svsimTestbench__DOT__io_commit_valid) 
              & (0x41U > (0x7fU & ((IData)(5U) + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0))))) 
             & (~ (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__flush)))) {
            __Vdly__svsimTestbench__DOT__dut__DOT__back_pointer 
                = (0x7fU & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer) 
                            + (7U & ((3U & (((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_0) 
                                             & ((0U 
                                                 != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_0)) 
                                                & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid))) 
                                            + ((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_1) 
                                               & ((0U 
                                                   != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_1)) 
                                                  & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid))))) 
                                     + (3U & (((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_2) 
                                               & ((0U 
                                                   != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_2)) 
                                                  & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid))) 
                                              + ((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_3) 
                                                 & ((0U 
                                                     != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_3)) 
                                                    & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))))))));
        }
        if (((~ (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__flush)) 
             & (0U != (0x1fU & (((IData)(1U) + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)) 
                                >> 2U))))) {
            __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer 
                = (0x7fU & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer) 
                            + (7U & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                     + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT___GEN_4)))));
        } else if (vlSelf->svsimTestbench__DOT__dut__DOT__flush) {
            __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer 
                = (0x7fU & (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_free_list_front_pointer));
        }
    }
    vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer 
        = __Vdly__svsimTestbench__DOT__dut__DOT__back_pointer;
    vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer 
        = __Vdly__svsimTestbench__DOT__dut__DOT__front_pointer;
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0 
        = (0x7fU & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer) 
                    - (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)));
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_sequent__TOP__1(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->svsimTestbench__DOT__dut__DOT___GEN_4 = 
        (3U & ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_2) 
               + (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_3)));
    vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1 
        = (3U & ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_0) 
                 + (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_1)));
    vlSelf->svsimTestbench__DOT__dut__DOT__flush = 
        ((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_is_misprediction) 
         & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid));
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_comb__TOP__0(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6;
    svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6 = 0;
    // Body
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (1U & (~ (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_0))))));
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (3U & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                             - (IData)(1U))))));
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (3U & (((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                              + (IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_2)) 
                                             - (IData)(1U))))));
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4 
        = (0x1ffU & ((IData)(7U) * ((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)) 
                                    + (7U & (((IData)(vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1) 
                                              + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT___GEN_4)) 
                                             - (IData)(1U))))));
    svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6 
        = ((~ (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__flush)) 
           & (0U != (0x1fU & (((IData)(1U) + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)) 
                              >> 2U))));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_0 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_0) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_1 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_1) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_2 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_2) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
    vlSelf->svsimTestbench__DOT__io_renamed_valid_3 
        = ((IData)(vlSelf->svsimTestbench__DOT__io_rename_valid_3) 
           & (IData)(svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_6));
}

void VsvsimTestbench___024root___eval_triggers__act(VsvsimTestbench___024root* vlSelf);

bool VsvsimTestbench___024root___eval_phase__act(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VsvsimTestbench___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VsvsimTestbench___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VsvsimTestbench___024root___eval_phase__nba(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VsvsimTestbench___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__nba(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VsvsimTestbench___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../generated-sources/testbench.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VsvsimTestbench___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VsvsimTestbench___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../generated-sources/testbench.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VsvsimTestbench___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../generated-sources/testbench.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VsvsimTestbench___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VsvsimTestbench___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VsvsimTestbench___024root___eval_debug_assertions(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

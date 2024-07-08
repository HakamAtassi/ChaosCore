// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench___024root.h"

VL_ATTR_COLD void VsvsimTestbench___024root___eval_static(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_static\n"); );
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial__TOP(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_initial\n"); );
    // Body
    VsvsimTestbench___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 
        = vlSelf->svsimTestbench__DOT__clock;
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_final(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__stl(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VsvsimTestbench___024root___eval_phase__stl(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_settle(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VsvsimTestbench___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../generated-sources/testbench.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VsvsimTestbench___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__stl(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___stl_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_stl(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VsvsimTestbench___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void VsvsimTestbench___024root___stl_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___stl_sequent__TOP__0\n"); );
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
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0 
        = (0x7fU & ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer) 
                    - (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer)));
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

VL_ATTR_COLD void VsvsimTestbench___024root___eval_triggers__stl(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD bool VsvsimTestbench___024root___eval_phase__stl(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VsvsimTestbench___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VsvsimTestbench___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ vlSelf->__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 1 is active: Internal 'ico' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: Internal 'act' trigger - DPI export trigger\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge svsimTestbench.clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__nba(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: Internal 'nba' trigger - DPI export trigger\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge svsimTestbench.clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___ctor_var_reset(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->svsimTestbench__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_0 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_1 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_2 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_3 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_0 = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_1 = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_2 = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RD_3 = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__io_commit_bits_free_list_front_pointer = VL_RAND_RESET_I(8);
    vlSelf->svsimTestbench__DOT__io_commit_bits_RAT_index = VL_RAND_RESET_I(4);
    vlSelf->svsimTestbench__DOT__io_commit_bits_NEXT = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__io_commit_bits_TOS = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__io_commit_bits_GHR = VL_RAND_RESET_I(16);
    vlSelf->svsimTestbench__DOT__io_commit_bits_expected_PC = VL_RAND_RESET_I(32);
    vlSelf->svsimTestbench__DOT__io_commit_bits_is_misprediction = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_fetch_packet_index = VL_RAND_RESET_I(2);
    vlSelf->svsimTestbench__DOT__io_commit_bits_br_type = VL_RAND_RESET_I(3);
    vlSelf->svsimTestbench__DOT__io_commit_bits_ROB_index = VL_RAND_RESET_I(6);
    vlSelf->svsimTestbench__DOT__io_commit_bits_T_NT = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_commit_bits_fetch_PC = VL_RAND_RESET_I(32);
    vlSelf->svsimTestbench__DOT__io_commit_valid = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_renamed_valid_0 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_renamed_valid_1 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_renamed_valid_2 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_renamed_valid_3 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_rename_valid_0 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_rename_valid_1 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_rename_valid_2 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__io_rename_valid_3 = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__dut__DOT__flush = VL_RAND_RESET_I(1);
    vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__dut__DOT___front_pointer_T_1 = VL_RAND_RESET_I(2);
    vlSelf->svsimTestbench__DOT__dut__DOT___GEN_4 = VL_RAND_RESET_I(3);
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0 = VL_RAND_RESET_I(7);
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1 = VL_RAND_RESET_I(9);
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2 = VL_RAND_RESET_I(9);
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3 = VL_RAND_RESET_I(9);
    vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4 = VL_RAND_RESET_I(9);
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

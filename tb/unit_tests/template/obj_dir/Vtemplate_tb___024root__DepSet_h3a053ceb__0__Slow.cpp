// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtemplate_tb.h for the primary calling header

#include "Vtemplate_tb__pch.h"
#include "Vtemplate_tb___024root.h"

VL_ATTR_COLD void Vtemplate_tb___024root___eval_static(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtemplate_tb___024root___eval_initial__TOP(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_initial__TOP\n"); );
    // Body
    VL_WRITEF_NX("Running free_list_tb\n",0);
}

VL_ATTR_COLD void Vtemplate_tb___024root___eval_final(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtemplate_tb___024root___eval_settle(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtemplate_tb___024root___dump_triggers__act(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge free_list_tb.clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtemplate_tb___024root___dump_triggers__nba(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge free_list_tb.clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtemplate_tb___024root___ctor_var_reset(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->free_list_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v0 = 0;
    vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__free_list_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDL2.h for the primary calling header

#include "VSDL2__pch.h"
#include "VSDL2___024root.h"

VL_ATTR_COLD void VSDL2___024root___eval_static(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_static\n"); );
}

VL_ATTR_COLD void VSDL2___024root___eval_initial__TOP(VSDL2___024root* vlSelf);

VL_ATTR_COLD void VSDL2___024root___eval_initial(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_initial\n"); );
    // Body
    VSDL2___024root___eval_initial__TOP(vlSelf);
}

void VSDL2___024root____Vdpiimwrap_SDL2MMIOBlackBox__DOT__create_frame_TOP();

VL_ATTR_COLD void VSDL2___024root___eval_initial__TOP(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_initial__TOP\n"); );
    // Body
    VL_WRITEF_NX("Running SDL2\n",0);
    VSDL2___024root____Vdpiimwrap_SDL2MMIOBlackBox__DOT__create_frame_TOP();
    vlSelf->input_ready = 1U;
}

VL_ATTR_COLD void VSDL2___024root___eval_final(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_final\n"); );
}

VL_ATTR_COLD void VSDL2___024root___eval_settle(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSDL2___024root___dump_triggers__act(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VSDL2___024root___dump_triggers__nba(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSDL2___024root___ctor_var_reset(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->input_ready = VL_RAND_RESET_I(1);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->address = VL_RAND_RESET_I(16);
    vlSelf->data = VL_RAND_RESET_I(24);
    vlSelf->operation = VL_RAND_RESET_I(1);
    vlSelf->dump = VL_RAND_RESET_I(1);
}

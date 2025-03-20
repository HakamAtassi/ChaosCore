// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDL2.h for the primary calling header

#include "VSDL2__pch.h"
#include "VSDL2___024root.h"

void VSDL2___024root___eval_act(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_act\n"); );
}

void VSDL2___024root___eval_nba(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_nba\n"); );
}

void VSDL2___024root___eval_triggers__act(VSDL2___024root* vlSelf);

bool VSDL2___024root___eval_phase__act(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VSDL2___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VSDL2___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VSDL2___024root___eval_phase__nba(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VSDL2___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSDL2___024root___dump_triggers__nba(VSDL2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VSDL2___024root___dump_triggers__act(VSDL2___024root* vlSelf);
#endif  // VL_DEBUG

void VSDL2___024root___eval(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VSDL2___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/SDL2.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VSDL2___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/SDL2.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VSDL2___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VSDL2___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VSDL2___024root___eval_debug_assertions(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
    if (VL_UNLIKELY((vlSelf->data & 0xff000000U))) {
        Verilated::overWidthError("data");}
    if (VL_UNLIKELY((vlSelf->operation & 0xfeU))) {
        Verilated::overWidthError("operation");}
    if (VL_UNLIKELY((vlSelf->dump & 0xfeU))) {
        Verilated::overWidthError("dump");}
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtemplate_tb.h for the primary calling header

#include "Vtemplate_tb__pch.h"
#include "Vtemplate_tb___024root.h"

VL_ATTR_COLD void Vtemplate_tb___024root___eval_initial__TOP(Vtemplate_tb___024root* vlSelf);
VlCoroutine Vtemplate_tb___024root___eval_initial__TOP__Vtiming__0(Vtemplate_tb___024root* vlSelf);
VlCoroutine Vtemplate_tb___024root___eval_initial__TOP__Vtiming__1(Vtemplate_tb___024root* vlSelf);

void Vtemplate_tb___024root___eval_initial(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_initial\n"); );
    // Body
    Vtemplate_tb___024root___eval_initial__TOP(vlSelf);
    Vtemplate_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtemplate_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__free_list_tb__DOT__clock__0 
        = vlSelf->free_list_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vtemplate_tb___024root___eval_initial__TOP__Vtiming__0(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ free_list_tb__DOT____Vrepeat0;
    free_list_tb__DOT____Vrepeat0 = 0;
    // Body
    free_list_tb__DOT____Vrepeat0 = 0x30d40U;
    while (VL_LTS_III(32, 0U, free_list_tb__DOT____Vrepeat0)) {
        co_await vlSelf->__VtrigSched_hb543aebf__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge free_list_tb.clock)", 
                                                           "template_tb.sv", 
                                                           19);
        free_list_tb__DOT____Vrepeat0 = (free_list_tb__DOT____Vrepeat0 
                                         - (IData)(1U));
    }
    VL_FINISH_MT("template_tb.sv", 19, "");
    VL_WRITEF_NX("tb exhaused\n",0);
}

VL_INLINE_OPT VlCoroutine Vtemplate_tb___024root___eval_initial__TOP__Vtiming__1(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v0 = 1U;
        co_await vlSelf->__VdlySched.delay(0xaULL, 
                                           nullptr, 
                                           "template_tb.sv", 
                                           15);
        vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v1 = 1U;
        co_await vlSelf->__VdlySched.delay(0xaULL, 
                                           nullptr, 
                                           "template_tb.sv", 
                                           15);
    }
}

void Vtemplate_tb___024root___eval_act(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_act\n"); );
}

void Vtemplate_tb___024root___nba_sequent__TOP__0(Vtemplate_tb___024root* vlSelf);

void Vtemplate_tb___024root___eval_nba(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtemplate_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtemplate_tb___024root___nba_sequent__TOP__0(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v0) {
        vlSelf->free_list_tb__DOT__clock = 0U;
        vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v0 = 0U;
    }
    if (vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v1) {
        vlSelf->free_list_tb__DOT__clock = 1U;
        vlSelf->__Vdlyvset__free_list_tb__DOT__clock__v1 = 0U;
    }
}

void Vtemplate_tb___024root___timing_resume(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hb543aebf__0.resume("@(posedge free_list_tb.clock)");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtemplate_tb___024root___timing_commit(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hb543aebf__0.commit("@(posedge free_list_tb.clock)");
    }
}

void Vtemplate_tb___024root___eval_triggers__act(Vtemplate_tb___024root* vlSelf);

bool Vtemplate_tb___024root___eval_phase__act(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtemplate_tb___024root___eval_triggers__act(vlSelf);
    Vtemplate_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtemplate_tb___024root___timing_resume(vlSelf);
        Vtemplate_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtemplate_tb___024root___eval_phase__nba(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtemplate_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtemplate_tb___024root___dump_triggers__nba(Vtemplate_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtemplate_tb___024root___dump_triggers__act(Vtemplate_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtemplate_tb___024root___eval(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtemplate_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("template_tb.sv", 10, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtemplate_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("template_tb.sv", 10, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtemplate_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtemplate_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtemplate_tb___024root___eval_debug_assertions(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

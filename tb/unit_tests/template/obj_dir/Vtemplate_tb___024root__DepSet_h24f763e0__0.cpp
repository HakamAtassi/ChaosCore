// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtemplate_tb.h for the primary calling header

#include "Vtemplate_tb__pch.h"
#include "Vtemplate_tb__Syms.h"
#include "Vtemplate_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtemplate_tb___024root___dump_triggers__act(Vtemplate_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtemplate_tb___024root___eval_triggers__act(Vtemplate_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtemplate_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtemplate_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->free_list_tb__DOT__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__free_list_tb__DOT__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP__free_list_tb__DOT__clock__0 
        = vlSelf->free_list_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtemplate_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

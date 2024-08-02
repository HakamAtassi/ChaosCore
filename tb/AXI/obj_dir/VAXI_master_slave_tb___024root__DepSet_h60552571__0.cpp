// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAXI_master_slave_tb.h for the primary calling header

#include "VAXI_master_slave_tb__pch.h"
#include "VAXI_master_slave_tb__Syms.h"
#include "VAXI_master_slave_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__act(VAXI_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG

void VAXI_master_slave_tb___024root___eval_triggers__act(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->AXI_master_slave_tb__DOT__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__AXI_master_slave_tb__DOT__clock__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__AXI_master_slave_tb__DOT__clock__0 
        = vlSelf->AXI_master_slave_tb__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VAXI_master_slave_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

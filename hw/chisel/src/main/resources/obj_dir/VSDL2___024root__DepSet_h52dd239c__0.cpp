// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDL2.h for the primary calling header

#include "VSDL2__pch.h"
#include "VSDL2__Syms.h"
#include "VSDL2___024root.h"

extern "C" void create_frame();

VL_INLINE_OPT void VSDL2___024root____Vdpiimwrap_SDL2MMIOBlackBox__DOT__create_frame_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root____Vdpiimwrap_SDL2MMIOBlackBox__DOT__create_frame_TOP\n"); );
    // Body
    create_frame();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSDL2___024root___dump_triggers__act(VSDL2___024root* vlSelf);
#endif  // VL_DEBUG

void VSDL2___024root___eval_triggers__act(VSDL2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VSDL2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSDL2___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSDL2___024root___dump_triggers__act(vlSelf);
    }
#endif
}

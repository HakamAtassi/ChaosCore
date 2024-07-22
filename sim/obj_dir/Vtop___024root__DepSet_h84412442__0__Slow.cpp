// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    VlUnpacked<CData/*7:0*/, 32769> top__DOT__memory;
    for (int __Vi0 = 0; __Vi0 < 32769; ++__Vi0) {
        top__DOT__memory[__Vi0] = 0;
    }
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e62696eU;
    __Vtemp_1[1U] = 0x61646469U;
    __Vtemp_1[2U] = 0x6965732fU;
    __Vtemp_1[3U] = 0x696e6172U;
    __Vtemp_1[4U] = 0x62U;
    VL_READMEM_N(false, 8, 32769, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(top__DOT__memory), 0, ~0ULL);
    VL_WRITEF_NX("Running ChaosCore\n",0);
    vlSymsp->_vm_contextp__->dumpfile(std::string{"dump.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg = 0U;
    vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__hasBeenResetReg = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

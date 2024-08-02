// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAXI_master_slave_tb.h for the primary calling header

#include "VAXI_master_slave_tb__pch.h"
#include "VAXI_master_slave_tb__Syms.h"
#include "VAXI_master_slave_tb___024root.h"

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_initial__TOP(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlUnpacked<IData/*31:0*/, 16384> AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem;
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__Vi0] = 0;
    }
    IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i;
    AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i = 0;
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6c617665U;
    __Vtemp_1[2U] = 0x65725f73U;
    __Vtemp_1[3U] = 0x6d617374U;
    __Vtemp_1[4U] = 0x4158495fU;
    __Vtemp_1[5U] = 0x74625fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    VL_PRINTF_MT("-Info: axi_master_slave_tb.sv:43: $dumpvar ignored, as Verilated without --trace\n");
    AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i = 0U;
    while (VL_GTS_III(32, 0x4000U, AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i)) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j 
            = AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i;
        while (VL_LTS_III(32, vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j, 
                          ((IData)(0x80U) + AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i))) {
            AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[(0x3fffU 
                                                                   & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j)] = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j 
                = ((IData)(1U) + vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j);
        }
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i 
            = ((IData)(0x80U) + AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__stl(VAXI_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_triggers__stl(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VAXI_master_slave_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_icache_ReadWriteSmem.h"

VL_ATTR_COLD void Vtop_v2_icache_ReadWriteSmem___ctor_var_reset(Vtop_v2_icache_ReadWriteSmem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_v2_icache_ReadWriteSmem___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->io_wr_en = VL_RAND_RESET_I(1);
    vlSelf->io_addr = VL_RAND_RESET_I(6);
    VL_RAND_RESET_W(278, vlSelf->io_data_in);
    VL_RAND_RESET_W(278, vlSelf->io_data_out);
    VL_RAND_RESET_W(278, vlSelf->__PVT___mem_ext_R0_data);
    VL_RAND_RESET_W(278, vlSelf->__Vcellinp__mem_ext__W0_data);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        VL_RAND_RESET_W(278, vlSelf->__PVT__mem_ext__DOT__Memory[__Vi0]);
    }
    vlSelf->__PVT__mem_ext__DOT___R0_en_d0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mem_ext__DOT___R0_addr_d0 = VL_RAND_RESET_I(6);
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_Queue4_FU_output.h"

VL_ATTR_COLD void Vtop_v2_Queue4_FU_output___ctor_var_reset(Vtop_v2_Queue4_FU_output* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vtop_v2_Queue4_FU_output___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_enq_ready = VL_RAND_RESET_I(1);
    vlSelf->io_enq_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(192, vlSelf->io_enq_bits);
    vlSelf->io_deq_ready = VL_RAND_RESET_I(1);
    vlSelf->io_deq_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(192, vlSelf->io_deq_bits);
    vlSelf->__PVT__io_count = VL_RAND_RESET_I(3);
    vlSelf->io_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__enq_ptr_value = VL_RAND_RESET_I(2);
    vlSelf->__PVT__deq_ptr_value = VL_RAND_RESET_I(2);
    vlSelf->__PVT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__do_enq = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(192, vlSelf->__Vcellinp__ram_ext__W0_data);
    vlSelf->__PVT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(192, vlSelf->__PVT__ram_ext__DOT__Memory[__Vi0]);
    }
}

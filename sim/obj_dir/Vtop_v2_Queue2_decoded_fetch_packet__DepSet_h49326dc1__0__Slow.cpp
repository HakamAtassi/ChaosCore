// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_Queue2_decoded_fetch_packet.h"

VL_ATTR_COLD void Vtop_v2_Queue2_decoded_fetch_packet___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__0(Vtop_v2_Queue2_decoded_fetch_packet* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vtop_v2_Queue2_decoded_fetch_packet___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__0\n"); );
    // Body
    vlSelf->io_deq_bits[0U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][0U];
    vlSelf->io_deq_bits[1U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][1U];
    vlSelf->io_deq_bits[2U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][2U];
    vlSelf->io_deq_bits[3U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][3U];
    vlSelf->io_deq_bits[4U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][4U];
    vlSelf->io_deq_bits[5U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][5U];
    vlSelf->io_deq_bits[6U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][6U];
    vlSelf->io_deq_bits[7U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][7U];
    vlSelf->io_deq_bits[8U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][8U];
    vlSelf->io_deq_bits[9U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][9U];
    vlSelf->io_deq_bits[0xaU] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][0xaU];
    vlSelf->io_deq_bits[0xbU] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][0xbU];
    vlSelf->io_deq_bits[0xcU] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][0xcU];
    vlSelf->io_deq_bits[0xdU] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__wrap_1][0xdU];
    vlSelf->__PVT__ptr_match = ((IData)(vlSelf->__PVT__wrap) 
                                == (IData)(vlSelf->__PVT__wrap_1));
    vlSelf->__PVT__empty = ((~ (IData)(vlSelf->__PVT__maybe_full)) 
                            & (IData)(vlSelf->__PVT__ptr_match));
}

VL_ATTR_COLD void Vtop_v2_Queue2_decoded_fetch_packet___ctor_var_reset(Vtop_v2_Queue2_decoded_fetch_packet* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vtop_v2_Queue2_decoded_fetch_packet___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_enq_ready = VL_RAND_RESET_I(1);
    vlSelf->io_enq_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(434, vlSelf->io_enq_bits);
    vlSelf->io_deq_ready = VL_RAND_RESET_I(1);
    vlSelf->io_deq_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(434, vlSelf->io_deq_bits);
    vlSelf->__PVT__io_count = VL_RAND_RESET_I(2);
    vlSelf->io_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wrap = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wrap_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ptr_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__do_enq = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(434, vlSelf->__Vcellinp__ram_ext__W0_data);
    vlSelf->__PVT__unnamedblk1__DOT__do_deq = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_RAND_RESET_W(434, vlSelf->__PVT__ram_ext__DOT__Memory[__Vi0]);
    }
}

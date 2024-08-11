// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_Queue2_decoded_fetch_packet.h"
#include "Vtop_v2__Syms.h"

VL_ATTR_COLD void Vtop_v2_Queue2_decoded_fetch_packet___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__0(Vtop_v2_Queue2_decoded_fetch_packet* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vtop_v2_Queue2_decoded_fetch_packet___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<5>/*159:0*/ __Vtemp_26;
    VlWide<7>/*223:0*/ __Vtemp_32;
    VlWide<7>/*223:0*/ __Vtemp_38;
    VlWide<7>/*223:0*/ __Vtemp_45;
    VlWide<8>/*255:0*/ __Vtemp_52;
    VlWide<9>/*287:0*/ __Vtemp_58;
    VlWide<10>/*319:0*/ __Vtemp_66;
    VlWide<10>/*319:0*/ __Vtemp_73;
    VlWide<12>/*383:0*/ __Vtemp_84;
    VlWide<13>/*415:0*/ __Vtemp_96;
    // Body
    vlSelf->__PVT__ptr_match = ((IData)(vlSelf->__PVT__wrap) 
                                == (IData)(vlSelf->__PVT__wrap_1));
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
    vlSelf->__PVT__empty = ((~ (IData)(vlSelf->__PVT__maybe_full)) 
                            & (IData)(vlSelf->__PVT__ptr_match));
    vlSelf->__PVT__do_enq = ((~ ((IData)(vlSelf->__PVT__ptr_match) 
                                 & (IData)(vlSelf->__PVT__maybe_full))) 
                             & ((IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq) 
                                & ((~ (IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                   & ((IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty) 
                                      | (IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq)))));
    __Vtemp_1[0U] = (IData)((((QData)((IData)(((IData)(vlSelf->__PVT__do_enq) 
                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                  >> 5U)))) 
                              << 0x3eU) | (((QData)((IData)(
                                                            ((IData)(vlSelf->__PVT__do_enq)
                                                              ? 
                                                             (0x7fU 
                                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                 >> 6U))
                                                              : 0U))) 
                                            << 0x37U) 
                                           | (((QData)((IData)(
                                                               ((IData)(vlSelf->__PVT__do_enq) 
                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                   >> 0xdU)))) 
                                               << 0x36U) 
                                              | (((QData)((IData)(
                                                                  ((IData)(vlSelf->__PVT__do_enq)
                                                                    ? 
                                                                   (0x7fU 
                                                                    & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                       >> 0xeU))
                                                                    : 0U))) 
                                                  << 0x2fU) 
                                                 | (((QData)((IData)(
                                                                     ((IData)(vlSelf->__PVT__do_enq) 
                                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                         >> 0x15U)))) 
                                                     << 0x2eU) 
                                                    | (((QData)((IData)(
                                                                        ((IData)(vlSelf->__PVT__do_enq)
                                                                          ? 
                                                                         (0x7fU 
                                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                             >> 0x16U))
                                                                          : 0U))) 
                                                        << 0x27U) 
                                                       | (((QData)((IData)(
                                                                           ((IData)(vlSelf->__PVT__do_enq)
                                                                             ? 
                                                                            (0x1fU 
                                                                             & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                                << 3U) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                                >> 0x1dU)))
                                                                             : 0U))) 
                                                           << 0x22U) 
                                                          | (((QData)((IData)(
                                                                              ((IData)(vlSelf->__PVT__do_enq) 
                                                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                                >> 2U)))) 
                                                              << 0x21U) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq) 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                                >> 3U)))) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xdU] 
                                                                                << 0xeU) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                                                >> 0x12U))
                                                                                 : 0U)))))))))))));
    __Vtemp_1[1U] = ((((IData)(vlSelf->__PVT__do_enq)
                        ? (0x1fffffU & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                         << 0x10U) 
                                        | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                           >> 0x10U)))
                        : 0U) << 0x1fU) | (IData)((
                                                   (((QData)((IData)(
                                                                     ((IData)(vlSelf->__PVT__do_enq) 
                                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                         >> 5U)))) 
                                                     << 0x3eU) 
                                                    | (((QData)((IData)(
                                                                        ((IData)(vlSelf->__PVT__do_enq)
                                                                          ? 
                                                                         (0x7fU 
                                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                             >> 6U))
                                                                          : 0U))) 
                                                        << 0x37U) 
                                                       | (((QData)((IData)(
                                                                           ((IData)(vlSelf->__PVT__do_enq) 
                                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                               >> 0xdU)))) 
                                                           << 0x36U) 
                                                          | (((QData)((IData)(
                                                                              ((IData)(vlSelf->__PVT__do_enq)
                                                                                ? 
                                                                               (0x7fU 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                                >> 0xeU))
                                                                                : 0U))) 
                                                              << 0x2fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq) 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                                >> 0x15U)))) 
                                                                 << 0x2eU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                (0x7fU 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                                >> 0x16U))
                                                                                 : 0U))) 
                                                                    << 0x27U) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                (0x1fU 
                                                                                & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                                << 3U) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                                >> 0x1dU)))
                                                                                 : 0U))) 
                                                                       << 0x22U) 
                                                                      | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq) 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                                >> 2U)))) 
                                                                          << 0x21U) 
                                                                         | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq) 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                                >> 3U)))) 
                                                                             << 0x20U) 
                                                                            | (QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xdU] 
                                                                                << 0xeU) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                                                >> 0x12U))
                                                                                 : 0U)))))))))))) 
                                                   >> 0x20U)));
    __Vtemp_10[3U] = ((0x1fff0000U & (((IData)(vlSelf->__PVT__do_enq) 
                                       << 0x10U) & 
                                      (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                       >> 3U))) | (
                                                   (((IData)(vlSelf->__PVT__do_enq)
                                                      ? 
                                                     (3U 
                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                         >> 0x14U))
                                                      : 0U) 
                                                    << 0xeU) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (3U 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                            >> 0x16U))
                                                         : 0U) 
                                                       << 0xcU) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (0x1fU 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                               >> 0x18U))
                                                            : 0U) 
                                                          << 7U) 
                                                         | ((((IData)(vlSelf->__PVT__do_enq)
                                                               ? 
                                                              (0xfU 
                                                               & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                                   << 3U) 
                                                                  | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                                     >> 0x1dU)))
                                                               : 0U) 
                                                             << 3U) 
                                                            | (((IData)(vlSelf->__PVT__do_enq)
                                                                 ? 
                                                                (0xfU 
                                                                 & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                                    >> 1U))
                                                                 : 0U) 
                                                               >> 1U))))));
    __Vtemp_17[3U] = ((((IData)(vlSelf->__PVT__do_enq)
                         ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                  >> 0xaU)) : 0U) << 0x18U) 
                      | ((((IData)(vlSelf->__PVT__do_enq)
                            ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                     >> 0xcU)) : 0U) 
                          << 0x16U) | ((0xffe00000U 
                                        & (((IData)(vlSelf->__PVT__do_enq) 
                                            << 0x15U) 
                                           & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                              << 7U))) 
                                       | ((0xfff00000U 
                                           & (((IData)(vlSelf->__PVT__do_enq) 
                                               << 0x14U) 
                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                 << 5U))) 
                                          | ((0xfff80000U 
                                              & (((IData)(vlSelf->__PVT__do_enq) 
                                                  << 0x13U) 
                                                 & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                    << 3U))) 
                                             | ((0xfffc0000U 
                                                 & (((IData)(vlSelf->__PVT__do_enq) 
                                                     << 0x12U) 
                                                    & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                       << 1U))) 
                                                | ((0x7ffe0000U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 0x11U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                          >> 1U))) 
                                                   | __Vtemp_10[3U])))))));
    __Vtemp_26[4U] = ((0x1000000U & (((IData)(vlSelf->__PVT__do_enq) 
                                      << 0x18U) & (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[5U] 
                                                   >> 7U))) 
                      | ((((IData)(vlSelf->__PVT__do_enq)
                            ? (0x7fU & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U])
                            : 0U) << 0x11U) | ((0xffff0000U 
                                                & (((IData)(vlSelf->__PVT__do_enq) 
                                                    << 0x10U) 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                      << 9U))) 
                                               | ((((IData)(vlSelf->__PVT__do_enq)
                                                     ? 
                                                    (0x7fU 
                                                     & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                        >> 8U))
                                                     : 0U) 
                                                   << 9U) 
                                                  | ((0x1ffff00U 
                                                      & (((IData)(vlSelf->__PVT__do_enq) 
                                                          << 8U) 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                            >> 7U))) 
                                                     | ((((IData)(vlSelf->__PVT__do_enq)
                                                           ? 
                                                          (0x7fU 
                                                           & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                              >> 0x10U))
                                                           : 0U) 
                                                         << 1U) 
                                                        | (((IData)(vlSelf->__PVT__do_enq)
                                                             ? 
                                                            (0x1fU 
                                                             & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                                >> 0x17U))
                                                             : 0U) 
                                                           >> 4U)))))));
    __Vtemp_32[5U] = ((((IData)(vlSelf->__PVT__do_enq)
                         ? (0xfU & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                    >> 0x17U)) : 0U) 
                       << 0x1dU) | ((((IData)(vlSelf->__PVT__do_enq)
                                       ? (0xfU & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                  >> 0x1bU))
                                       : 0U) << 0x19U) 
                                    | ((((IData)(vlSelf->__PVT__do_enq)
                                          ? (0x3fU 
                                             & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[5U] 
                                                 << 1U) 
                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                   >> 0x1fU)))
                                          : 0U) << 0x13U) 
                                       | ((((IData)(vlSelf->__PVT__do_enq)
                                             ? (3U 
                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[5U] 
                                                   >> 5U))
                                             : 0U) 
                                           << 0x11U) 
                                          | ((((IData)(vlSelf->__PVT__do_enq)
                                                ? (7U 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[5U] 
                                                      >> 7U))
                                                : 0U) 
                                              << 0xeU) 
                                             | (((IData)(vlSelf->__PVT__do_enq)
                                                  ? 
                                                 (0x1fffffU 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[5U] 
                                                     >> 0xaU))
                                                  : 0U) 
                                                >> 7U))))));
    __Vtemp_38[6U] = ((0xfffff000U & (((IData)(vlSelf->__PVT__do_enq) 
                                       << 0xcU) & (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                   << 1U))) 
                      | ((0x7ffff800U & (((IData)(vlSelf->__PVT__do_enq) 
                                          << 0xbU) 
                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                            >> 1U))) 
                         | ((0x1ffffc00U & (((IData)(vlSelf->__PVT__do_enq) 
                                             << 0xaU) 
                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                               >> 3U))) 
                            | ((((IData)(vlSelf->__PVT__do_enq)
                                  ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                           >> 0xeU))
                                  : 0U) << 8U) | ((
                                                   ((IData)(vlSelf->__PVT__do_enq)
                                                     ? 
                                                    (3U 
                                                     & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                        >> 0x10U))
                                                     : 0U) 
                                                   << 6U) 
                                                  | ((((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       (0x1fU 
                                                        & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                           >> 0x12U))
                                                        : 0U) 
                                                      << 1U) 
                                                     | (((IData)(vlSelf->__PVT__do_enq)
                                                          ? 
                                                         (0xfU 
                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                             >> 0x17U))
                                                          : 0U) 
                                                        >> 3U)))))));
    __Vtemp_45[6U] = ((0x7fe00000U & (((IData)(vlSelf->__PVT__do_enq) 
                                       << 0x15U) & 
                                      (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                       >> 1U))) | (
                                                   (0x1ff00000U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 0x14U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                          >> 3U))) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (3U 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                            >> 4U))
                                                         : 0U) 
                                                       << 0x12U) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (3U 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                               >> 6U))
                                                            : 0U) 
                                                          << 0x10U) 
                                                         | ((0xffff8000U 
                                                             & (((IData)(vlSelf->__PVT__do_enq) 
                                                                 << 0xfU) 
                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                   << 7U))) 
                                                            | ((0xffffc000U 
                                                                & (((IData)(vlSelf->__PVT__do_enq) 
                                                                    << 0xeU) 
                                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                      << 5U))) 
                                                               | ((0xffffe000U 
                                                                   & (((IData)(vlSelf->__PVT__do_enq) 
                                                                       << 0xdU) 
                                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[4U] 
                                                                         << 3U))) 
                                                                  | __Vtemp_38[6U])))))));
    __Vtemp_52[7U] = ((0x1fc0000U & (((IData)(vlSelf->__PVT__do_enq) 
                                      << 0x12U) & (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[8U] 
                                                   >> 7U))) 
                      | ((((IData)(vlSelf->__PVT__do_enq)
                            ? (0x7fU & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                         << 6U) | (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[8U] 
                                                   >> 0x1aU)))
                            : 0U) << 0xbU) | ((0xfffffc00U 
                                               & (((IData)(vlSelf->__PVT__do_enq) 
                                                   << 0xaU) 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                     << 9U))) 
                                              | ((((IData)(vlSelf->__PVT__do_enq)
                                                    ? 
                                                   (0x7fU 
                                                    & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                       >> 2U))
                                                    : 0U) 
                                                  << 3U) 
                                                 | ((0x1fffffcU 
                                                     & (((IData)(vlSelf->__PVT__do_enq) 
                                                         << 2U) 
                                                        & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                           >> 7U))) 
                                                    | (((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (0x7fU 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                            >> 0xaU))
                                                         : 0U) 
                                                       >> 5U))))));
    __Vtemp_58[8U] = ((((IData)(vlSelf->__PVT__do_enq)
                         ? (0xfU & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                    >> 0x11U)) : 0U) 
                       << 0x17U) | ((((IData)(vlSelf->__PVT__do_enq)
                                       ? (0xfU & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                  >> 0x15U))
                                       : 0U) << 0x13U) 
                                    | ((((IData)(vlSelf->__PVT__do_enq)
                                          ? (0x3fU 
                                             & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                >> 0x19U))
                                          : 0U) << 0xdU) 
                                       | ((((IData)(vlSelf->__PVT__do_enq)
                                             ? (3U 
                                                & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[8U] 
                                                    << 1U) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                      >> 0x1fU)))
                                             : 0U) 
                                           << 0xbU) 
                                          | ((((IData)(vlSelf->__PVT__do_enq)
                                                ? (7U 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[8U] 
                                                      >> 1U))
                                                : 0U) 
                                              << 8U) 
                                             | (((IData)(vlSelf->__PVT__do_enq)
                                                  ? 
                                                 (0x1fffffU 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[8U] 
                                                     >> 4U))
                                                  : 0U) 
                                                >> 0xdU))))));
    __Vtemp_66[9U] = ((0xffffff00U & (((IData)(vlSelf->__PVT__do_enq) 
                                       << 8U) & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                 << 5U))) 
                      | ((0xffffff80U & (((IData)(vlSelf->__PVT__do_enq) 
                                          << 7U) & 
                                         (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                          << 3U))) 
                         | ((0xffffffc0U & (((IData)(vlSelf->__PVT__do_enq) 
                                             << 6U) 
                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                               << 1U))) 
                            | ((0x7fffffe0U & (((IData)(vlSelf->__PVT__do_enq) 
                                                << 5U) 
                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                  >> 1U))) 
                               | ((0x1ffffff0U & (((IData)(vlSelf->__PVT__do_enq) 
                                                   << 4U) 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                     >> 3U))) 
                                  | ((((IData)(vlSelf->__PVT__do_enq)
                                        ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                 >> 8U))
                                        : 0U) << 2U) 
                                     | ((IData)(vlSelf->__PVT__do_enq)
                                         ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                  >> 0xaU))
                                         : 0U)))))));
    __Vtemp_73[9U] = ((((IData)(vlSelf->__PVT__do_enq)
                         ? (0x7fU & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                     >> 4U)) : 0U) 
                       << 0x15U) | ((((IData)(vlSelf->__PVT__do_enq)
                                       ? (0x1fU & (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                   >> 0xbU))
                                       : 0U) << 0x10U) 
                                    | ((0x7fff8000U 
                                        & (((IData)(vlSelf->__PVT__do_enq) 
                                            << 0xfU) 
                                           & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                              >> 1U))) 
                                       | ((0x1fffc000U 
                                           & (((IData)(vlSelf->__PVT__do_enq) 
                                               << 0xeU) 
                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                 >> 3U))) 
                                          | ((((IData)(vlSelf->__PVT__do_enq)
                                                ? (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                   >> 0x1eU)
                                                : 0U) 
                                              << 0xcU) 
                                             | ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (3U 
                                                   & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U])
                                                   : 0U) 
                                                 << 0xaU) 
                                                | ((0xfffffe00U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 9U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                          << 7U))) 
                                                   | __Vtemp_66[9U])))))));
    __Vtemp_84[0xbU] = ((((IData)(vlSelf->__PVT__do_enq)
                           ? (0xfU & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                      >> 0xbU)) : 0U) 
                         << 0x11U) | ((((IData)(vlSelf->__PVT__do_enq)
                                         ? (0xfU & 
                                            (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                             >> 0xfU))
                                         : 0U) << 0xdU) 
                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                            ? (0x3fU 
                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                  >> 0x13U))
                                            : 0U) << 7U) 
                                         | ((((IData)(vlSelf->__PVT__do_enq)
                                               ? (3U 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                     >> 0x19U))
                                               : 0U) 
                                             << 5U) 
                                            | ((((IData)(vlSelf->__PVT__do_enq)
                                                  ? 
                                                 (7U 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                     >> 0x1bU))
                                                  : 0U) 
                                                << 2U) 
                                               | (((IData)(vlSelf->__PVT__do_enq)
                                                    ? 
                                                   (0x1fffffU 
                                                    & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                        << 2U) 
                                                       | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                          >> 0x1eU)))
                                                    : 0U) 
                                                  >> 0x13U))))));
    __Vtemp_96[0xcU] = ((0xffffff00U & (((IData)(vlSelf->__PVT__do_enq) 
                                         << 8U) & (
                                                   vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                   << 2U))) 
                        | ((((IData)(vlSelf->__PVT__do_enq)
                              ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                       >> 0x18U)) : 0U) 
                            << 6U) | ((((IData)(vlSelf->__PVT__do_enq)
                                         ? (3U & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                  >> 0x1aU))
                                         : 0U) << 4U) 
                                      | ((0x78U & (
                                                   ((IData)(vlSelf->__PVT__do_enq) 
                                                    << 3U) 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                      >> 0x19U))) 
                                         | ((0x1cU 
                                             & (((IData)(vlSelf->__PVT__do_enq) 
                                                 << 2U) 
                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                   >> 0x1bU))) 
                                            | ((6U 
                                                & (((IData)(vlSelf->__PVT__do_enq) 
                                                    << 1U) 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                      >> 0x1dU))) 
                                               | ((IData)(vlSelf->__PVT__do_enq) 
                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                     >> 0x1fU))))))));
    vlSelf->__Vcellinp__ram_ext__W0_data[0U] = __Vtemp_1[0U];
    vlSelf->__Vcellinp__ram_ext__W0_data[1U] = __Vtemp_1[1U];
    vlSelf->__Vcellinp__ram_ext__W0_data[2U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0xfU 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                      >> 1U))
                                                   : 0U) 
                                                 << 0x1fU) 
                                                | ((((IData)(vlSelf->__PVT__do_enq)
                                                      ? 
                                                     (0x3fU 
                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                         >> 5U))
                                                      : 0U) 
                                                    << 0x19U) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (3U 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                            >> 0xbU))
                                                         : 0U) 
                                                       << 0x17U) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (7U 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                               >> 0xdU))
                                                            : 0U) 
                                                          << 0x14U) 
                                                         | (((IData)(vlSelf->__PVT__do_enq)
                                                              ? 
                                                             (0x1fffffU 
                                                              & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[3U] 
                                                                  << 0x10U) 
                                                                 | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[2U] 
                                                                    >> 0x10U)))
                                                              : 0U) 
                                                            >> 1U)))));
    vlSelf->__Vcellinp__ram_ext__W0_data[3U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0x1fU 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                      >> 0x17U))
                                                   : 0U) 
                                                 << 0x1cU) 
                                                | ((0x78000000U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 0x1bU) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                          >> 1U))) 
                                                   | ((0x1c000000U 
                                                       & (((IData)(vlSelf->__PVT__do_enq) 
                                                           << 0x1aU) 
                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[6U] 
                                                             >> 3U))) 
                                                      | __Vtemp_17[3U])));
    vlSelf->__Vcellinp__ram_ext__W0_data[4U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0x1fffffU 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[5U] 
                                                      >> 0xaU))
                                                   : 0U) 
                                                 << 0x19U) 
                                                | __Vtemp_26[4U]);
    vlSelf->__Vcellinp__ram_ext__W0_data[5U] = __Vtemp_32[5U];
    vlSelf->__Vcellinp__ram_ext__W0_data[6U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0x7fU 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                      >> 0xaU))
                                                   : 0U) 
                                                 << 0x1bU) 
                                                | ((((IData)(vlSelf->__PVT__do_enq)
                                                      ? 
                                                     (0x1fU 
                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[9U] 
                                                         >> 0x11U))
                                                      : 0U) 
                                                    << 0x16U) 
                                                   | __Vtemp_45[6U]));
    vlSelf->__Vcellinp__ram_ext__W0_data[7U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0x1fffffU 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[8U] 
                                                      >> 4U))
                                                   : 0U) 
                                                 << 0x13U) 
                                                | __Vtemp_52[7U]);
    vlSelf->__Vcellinp__ram_ext__W0_data[8U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0x1fU 
                                                   & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[7U] 
                                                      >> 0xcU))
                                                   : 0U) 
                                                 << 0x1bU) 
                                                | __Vtemp_58[8U]);
    vlSelf->__Vcellinp__ram_ext__W0_data[9U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  (0x7fU 
                                                   & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                       << 4U) 
                                                      | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                         >> 0x1cU)))
                                                   : 0U) 
                                                 << 0x1dU) 
                                                | ((0xf0000000U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 0x1cU) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                          << 0x19U))) 
                                                   | __Vtemp_73[9U]));
    vlSelf->__Vcellinp__ram_ext__W0_data[0xaU] = ((
                                                   ((IData)(vlSelf->__PVT__do_enq)
                                                     ? 
                                                    (0x1fffffU 
                                                     & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                         << 2U) 
                                                        | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                           >> 0x1eU)))
                                                     : 0U) 
                                                   << 0xdU) 
                                                  | ((0x1fff000U 
                                                      & (((IData)(vlSelf->__PVT__do_enq) 
                                                          << 0xcU) 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                            >> 7U))) 
                                                     | ((((IData)(vlSelf->__PVT__do_enq)
                                                           ? 
                                                          (0x7fU 
                                                           & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                              >> 0x14U))
                                                           : 0U) 
                                                         << 5U) 
                                                        | ((0x1f0U 
                                                            & (((IData)(vlSelf->__PVT__do_enq) 
                                                                << 4U) 
                                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                                  >> 0x17U))) 
                                                           | (((IData)(vlSelf->__PVT__do_enq)
                                                                ? 
                                                               (0x7fU 
                                                                & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xcU] 
                                                                    << 4U) 
                                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xbU] 
                                                                      >> 0x1cU)))
                                                                : 0U) 
                                                              >> 3U)))));
    vlSelf->__Vcellinp__ram_ext__W0_data[0xbU] = ((
                                                   ((IData)(vlSelf->__PVT__do_enq) 
                                                    & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU]) 
                                                   << 0x1fU) 
                                                  | ((0xc0000000U 
                                                      & (((IData)(vlSelf->__PVT__do_enq) 
                                                          << 0x1eU) 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                            << 0x1dU))) 
                                                     | ((((IData)(vlSelf->__PVT__do_enq)
                                                           ? 
                                                          (3U 
                                                           & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                              >> 2U))
                                                           : 0U) 
                                                         << 0x1cU) 
                                                        | ((((IData)(vlSelf->__PVT__do_enq)
                                                              ? 
                                                             (3U 
                                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                                 >> 4U))
                                                              : 0U) 
                                                            << 0x1aU) 
                                                           | ((((IData)(vlSelf->__PVT__do_enq)
                                                                 ? 
                                                                (0x1fU 
                                                                 & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0xaU] 
                                                                    >> 6U))
                                                                 : 0U) 
                                                               << 0x15U) 
                                                              | __Vtemp_84[0xbU])))));
    vlSelf->__Vcellinp__ram_ext__W0_data[0xcU] = ((
                                                   ((IData)(vlSelf->__PVT__do_enq)
                                                     ? 
                                                    (0x7fU 
                                                     & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0U] 
                                                        >> 0xfU))
                                                     : 0U) 
                                                   << 0x1cU) 
                                                  | ((((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       (0xffffU 
                                                        & ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                            << 0xaU) 
                                                           | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0U] 
                                                              >> 0x16U)))
                                                        : 0U) 
                                                      << 0xcU) 
                                                     | ((0xfffff800U 
                                                         & (((IData)(vlSelf->__PVT__do_enq) 
                                                             << 0xbU) 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                               << 2U))) 
                                                        | ((0xfffffc00U 
                                                            & (((IData)(vlSelf->__PVT__do_enq) 
                                                                << 0xaU) 
                                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                                  << 2U))) 
                                                           | ((0xfffffe00U 
                                                               & (((IData)(vlSelf->__PVT__do_enq) 
                                                                   << 9U) 
                                                                  & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[1U] 
                                                                     << 2U))) 
                                                              | __Vtemp_96[0xcU])))));
    vlSelf->__Vcellinp__ram_ext__W0_data[0xdU] = ((
                                                   ((IData)(vlSelf->__PVT__do_enq)
                                                     ? 
                                                    (0xffU 
                                                     & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0U])
                                                     : 0U) 
                                                   << 0xaU) 
                                                  | ((((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       (0x7fU 
                                                        & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0U] 
                                                           >> 8U))
                                                        : 0U) 
                                                      << 3U) 
                                                     | (((IData)(vlSelf->__PVT__do_enq)
                                                          ? 
                                                         (0x7fU 
                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597[0U] 
                                                             >> 0xfU))
                                                          : 0U) 
                                                        >> 4U)));
}

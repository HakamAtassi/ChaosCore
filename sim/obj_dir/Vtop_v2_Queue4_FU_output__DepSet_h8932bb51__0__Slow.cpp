// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_Queue4_FU_output.h"
#include "Vtop_v2__Syms.h"

VL_ATTR_COLD void Vtop_v2_Queue4_FU_output___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__0(Vtop_v2_Queue4_FU_output* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vtop_v2_Queue4_FU_output___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__0\n"); );
    // Body
    vlSelf->io_deq_bits[0U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][0U];
    vlSelf->io_deq_bits[1U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][1U];
    vlSelf->io_deq_bits[2U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][2U];
    vlSelf->io_deq_bits[3U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][3U];
    vlSelf->io_deq_bits[4U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][4U];
    vlSelf->io_deq_bits[5U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][5U];
    vlSelf->__PVT__ptr_match = ((IData)(vlSelf->__PVT__deq_ptr_value) 
                                == (IData)(vlSelf->__PVT__enq_ptr_value));
    vlSelf->__PVT__full = ((IData)(vlSelf->__PVT__ptr_match) 
                           & (IData)(vlSelf->__PVT__maybe_full));
    vlSelf->__PVT__empty = ((~ (IData)(vlSelf->__PVT__maybe_full)) 
                            & (IData)(vlSelf->__PVT__ptr_match));
    vlSelf->__PVT__do_enq = ((~ (IData)(vlSelf->__PVT__full)) 
                             & (IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_load_Q_io_enq_valid_T_14));
    vlSelf->__Vcellinp__ram_ext__W0_data[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelf->__PVT__do_enq) 
                                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[4U] 
                                                                             >> 0x18U)))) 
                                                         << 0x27U) 
                                                        | (((QData)((IData)(
                                                                            ((IData)(vlSelf->__PVT__do_enq)
                                                                              ? 
                                                                             ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[5U] 
                                                                               << 7U) 
                                                                              | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[4U] 
                                                                                >> 0x19U))
                                                                              : 0U))) 
                                                            << 7U) 
                                                           | (QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__do_enq)
                                                                               ? 
                                                                              (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[5U] 
                                                                               >> 0x19U)
                                                                               : 0U))))));
    vlSelf->__Vcellinp__ram_ext__W0_data[1U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[4U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[3U] 
                                                      >> 0x18U))
                                                   : 0U) 
                                                 << 8U) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__do_enq) 
                                                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[4U] 
                                                                                >> 0x18U)))) 
                                                             << 0x27U) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[5U] 
                                                                                << 7U) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[4U] 
                                                                                >> 0x19U))
                                                                                 : 0U))) 
                                                                << 7U) 
                                                               | (QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[5U] 
                                                                                >> 0x19U)
                                                                                 : 0U))))) 
                                                           >> 0x20U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[2U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[3U] 
                                                    << 9U) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[2U] 
                                                      >> 0x17U))
                                                   : 0U) 
                                                 << 9U) 
                                                | ((0x1ff00U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 8U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[3U] 
                                                          >> 0xfU))) 
                                                   | (((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[4U] 
                                                         << 8U) 
                                                        | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[3U] 
                                                           >> 0x18U))
                                                        : 0U) 
                                                      >> 0x18U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[3U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[2U] 
                                                    << 0xaU) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                      >> 0x16U))
                                                   : 0U) 
                                                 << 0xaU) 
                                                | ((0x7fe00U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 9U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[2U] 
                                                          >> 0xdU))) 
                                                   | (((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[3U] 
                                                         << 9U) 
                                                        | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[2U] 
                                                           >> 0x17U))
                                                        : 0U) 
                                                      >> 0x17U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[4U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                    << 0xfU) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U] 
                                                      >> 0x11U))
                                                   : 0U) 
                                                 << 0xfU) 
                                                | ((0x1fffc000U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 0xeU) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                          >> 3U))) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (3U 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                            >> 0x12U))
                                                         : 0U) 
                                                       << 0xcU) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (3U 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                               >> 0x14U))
                                                            : 0U) 
                                                          << 0xaU) 
                                                         | (((IData)(vlSelf->__PVT__do_enq)
                                                              ? 
                                                             ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[2U] 
                                                               << 0xaU) 
                                                              | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                                 >> 0x16U))
                                                              : 0U) 
                                                            >> 0x16U)))));
    vlSelf->__Vcellinp__ram_ext__W0_data[5U] = ((((IData)(vlSelf->__PVT__do_enq) 
                                                  & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U]) 
                                                 << 0x1fU) 
                                                | ((((IData)(vlSelf->__PVT__do_enq)
                                                      ? 
                                                     (3U 
                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U] 
                                                         >> 1U))
                                                      : 0U) 
                                                    << 0x1dU) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (0xfU 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U] 
                                                            >> 3U))
                                                         : 0U) 
                                                       << 0x19U) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (0x3fU 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U] 
                                                               >> 7U))
                                                            : 0U) 
                                                          << 0x13U) 
                                                         | ((((IData)(vlSelf->__PVT__do_enq)
                                                               ? 
                                                              (0xfU 
                                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U] 
                                                                  >> 0xdU))
                                                               : 0U) 
                                                             << 0xfU) 
                                                            | (((IData)(vlSelf->__PVT__do_enq)
                                                                 ? 
                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[1U] 
                                                                  << 0xfU) 
                                                                 | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218[0U] 
                                                                    >> 0x11U))
                                                                 : 0U) 
                                                               >> 0x11U))))));
}

VL_ATTR_COLD void Vtop_v2_Queue4_FU_output___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__0(Vtop_v2_Queue4_FU_output* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vtop_v2_Queue4_FU_output___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__0\n"); );
    // Body
    vlSelf->__PVT__ptr_match = ((IData)(vlSelf->__PVT__deq_ptr_value) 
                                == (IData)(vlSelf->__PVT__enq_ptr_value));
    vlSelf->io_deq_bits[0U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][0U];
    vlSelf->io_deq_bits[1U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][1U];
    vlSelf->io_deq_bits[2U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][2U];
    vlSelf->io_deq_bits[3U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][3U];
    vlSelf->io_deq_bits[4U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][4U];
    vlSelf->io_deq_bits[5U] = vlSelf->__PVT__ram_ext__DOT__Memory
        [vlSelf->__PVT__deq_ptr_value][5U];
    vlSelf->__PVT__full = ((IData)(vlSelf->__PVT__ptr_match) 
                           & (IData)(vlSelf->__PVT__maybe_full));
    vlSelf->__PVT__empty = ((~ (IData)(vlSelf->__PVT__maybe_full)) 
                            & (IData)(vlSelf->__PVT__ptr_match));
    vlSelf->__PVT__do_enq = ((~ (IData)(vlSelf->__PVT__full)) 
                             & (IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_store_Q_io_enq_valid_T_14));
    vlSelf->__Vcellinp__ram_ext__W0_data[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelf->__PVT__do_enq) 
                                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[4U] 
                                                                             >> 0x18U)))) 
                                                         << 0x27U) 
                                                        | (((QData)((IData)(
                                                                            ((IData)(vlSelf->__PVT__do_enq)
                                                                              ? 
                                                                             ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[5U] 
                                                                               << 7U) 
                                                                              | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[4U] 
                                                                                >> 0x19U))
                                                                              : 0U))) 
                                                            << 7U) 
                                                           | (QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__do_enq)
                                                                               ? 
                                                                              (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[5U] 
                                                                               >> 0x19U)
                                                                               : 0U))))));
    vlSelf->__Vcellinp__ram_ext__W0_data[1U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[4U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[3U] 
                                                      >> 0x18U))
                                                   : 0U) 
                                                 << 8U) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__do_enq) 
                                                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[4U] 
                                                                                >> 0x18U)))) 
                                                             << 0x27U) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[5U] 
                                                                                << 7U) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[4U] 
                                                                                >> 0x19U))
                                                                                 : 0U))) 
                                                                << 7U) 
                                                               | (QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[5U] 
                                                                                >> 0x19U)
                                                                                 : 0U))))) 
                                                           >> 0x20U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[2U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[3U] 
                                                    << 9U) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[2U] 
                                                      >> 0x17U))
                                                   : 0U) 
                                                 << 9U) 
                                                | ((0x1ff00U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 8U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[3U] 
                                                          >> 0xfU))) 
                                                   | (((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[4U] 
                                                         << 8U) 
                                                        | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[3U] 
                                                           >> 0x18U))
                                                        : 0U) 
                                                      >> 0x18U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[3U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[2U] 
                                                    << 0xaU) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                      >> 0x16U))
                                                   : 0U) 
                                                 << 0xaU) 
                                                | ((0x7fe00U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 9U) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[2U] 
                                                          >> 0xdU))) 
                                                   | (((IData)(vlSelf->__PVT__do_enq)
                                                        ? 
                                                       ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[3U] 
                                                         << 9U) 
                                                        | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[2U] 
                                                           >> 0x17U))
                                                        : 0U) 
                                                      >> 0x17U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[4U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                    << 0xfU) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U] 
                                                      >> 0x11U))
                                                   : 0U) 
                                                 << 0xfU) 
                                                | ((0x1fffc000U 
                                                    & (((IData)(vlSelf->__PVT__do_enq) 
                                                        << 0xeU) 
                                                       & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                          >> 3U))) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (3U 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                            >> 0x12U))
                                                         : 0U) 
                                                       << 0xcU) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (3U 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                               >> 0x14U))
                                                            : 0U) 
                                                          << 0xaU) 
                                                         | (((IData)(vlSelf->__PVT__do_enq)
                                                              ? 
                                                             ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[2U] 
                                                               << 0xaU) 
                                                              | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                                 >> 0x16U))
                                                              : 0U) 
                                                            >> 0x16U)))));
    vlSelf->__Vcellinp__ram_ext__W0_data[5U] = ((((IData)(vlSelf->__PVT__do_enq) 
                                                  & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U]) 
                                                 << 0x1fU) 
                                                | ((((IData)(vlSelf->__PVT__do_enq)
                                                      ? 
                                                     (3U 
                                                      & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U] 
                                                         >> 1U))
                                                      : 0U) 
                                                    << 0x1dU) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (0xfU 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U] 
                                                            >> 3U))
                                                         : 0U) 
                                                       << 0x19U) 
                                                      | ((((IData)(vlSelf->__PVT__do_enq)
                                                            ? 
                                                           (0x3fU 
                                                            & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U] 
                                                               >> 7U))
                                                            : 0U) 
                                                          << 0x13U) 
                                                         | ((((IData)(vlSelf->__PVT__do_enq)
                                                               ? 
                                                              (0xfU 
                                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U] 
                                                                  >> 0xdU))
                                                               : 0U) 
                                                             << 0xfU) 
                                                            | (((IData)(vlSelf->__PVT__do_enq)
                                                                 ? 
                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[1U] 
                                                                  << 0xfU) 
                                                                 | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219[0U] 
                                                                    >> 0x11U))
                                                                 : 0U) 
                                                               >> 0x11U))))));
}

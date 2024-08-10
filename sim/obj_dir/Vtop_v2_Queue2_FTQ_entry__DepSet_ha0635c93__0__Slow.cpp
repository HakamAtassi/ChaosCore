// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_Queue2_FTQ_entry.h"
#include "Vtop_v2__Syms.h"

VL_ATTR_COLD void Vtop_v2_Queue2_FTQ_entry___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q__0(Vtop_v2_Queue2_FTQ_entry* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vtop_v2_Queue2_FTQ_entry___stl_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q__0\n"); );
    // Body
    vlSelf->__PVT__ptr_match = ((IData)(vlSelf->__PVT__wrap) 
                                == (IData)(vlSelf->__PVT__wrap_1));
    vlSelf->__PVT__empty = ((~ (IData)(vlSelf->__PVT__maybe_full)) 
                            & (IData)(vlSelf->__PVT__ptr_match));
    vlSelf->__PVT__do_enq = ((~ ((IData)(vlSelf->__PVT__ptr_match) 
                                 & (IData)(vlSelf->__PVT__maybe_full))) 
                             & ((IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq) 
                                & ((~ (IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                   & (IData)(vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq))));
    vlSelf->__Vcellinp__ram_ext__W0_data[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelf->__PVT__do_enq) 
                                                                          & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[2U] 
                                                                             >> 0xcU)))) 
                                                         << 0x21U) 
                                                        | (((QData)((IData)(
                                                                            ((IData)(vlSelf->__PVT__do_enq)
                                                                              ? 
                                                                             ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[3U] 
                                                                               << 0x13U) 
                                                                              | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[2U] 
                                                                                >> 0xdU))
                                                                              : 0U))) 
                                                            << 1U) 
                                                           | (QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__do_enq) 
                                                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[3U] 
                                                                                >> 0xdU)))))));
    vlSelf->__Vcellinp__ram_ext__W0_data[1U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[2U] 
                                                    << 0x14U) 
                                                   | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[1U] 
                                                      >> 0xcU))
                                                   : 0U) 
                                                 << 2U) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__do_enq) 
                                                                              & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[2U] 
                                                                                >> 0xcU)))) 
                                                             << 0x21U) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq)
                                                                                 ? 
                                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[3U] 
                                                                                << 0x13U) 
                                                                                | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[2U] 
                                                                                >> 0xdU))
                                                                                 : 0U))) 
                                                                << 1U) 
                                                               | (QData)((IData)(
                                                                                ((IData)(vlSelf->__PVT__do_enq) 
                                                                                & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[3U] 
                                                                                >> 0xdU)))))) 
                                                           >> 0x20U)));
    vlSelf->__Vcellinp__ram_ext__W0_data[2U] = ((((IData)(vlSelf->__PVT__do_enq)
                                                   ? 
                                                  vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[0U]
                                                   : 0U) 
                                                 << 0xeU) 
                                                | ((((IData)(vlSelf->__PVT__do_enq)
                                                      ? 
                                                     (3U 
                                                      & vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[1U])
                                                      : 0U) 
                                                    << 0xcU) 
                                                   | ((((IData)(vlSelf->__PVT__do_enq)
                                                         ? 
                                                        (7U 
                                                         & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[1U] 
                                                            >> 2U))
                                                         : 0U) 
                                                       << 9U) 
                                                      | ((0xffffff00U 
                                                          & (((IData)(vlSelf->__PVT__do_enq) 
                                                              << 8U) 
                                                             & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[1U] 
                                                                << 3U))) 
                                                         | ((((IData)(vlSelf->__PVT__do_enq)
                                                               ? 
                                                              (0x3fU 
                                                               & (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[1U] 
                                                                  >> 6U))
                                                               : 0U) 
                                                             << 2U) 
                                                            | (((IData)(vlSelf->__PVT__do_enq)
                                                                 ? 
                                                                ((vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[2U] 
                                                                  << 0x14U) 
                                                                 | (vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[1U] 
                                                                    >> 0xcU))
                                                                 : 0U) 
                                                               >> 0x1eU))))));
    vlSelf->__Vcellinp__ram_ext__W0_data[3U] = (((IData)(vlSelf->__PVT__do_enq)
                                                  ? 
                                                 vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data[0U]
                                                  : 0U) 
                                                >> 0x12U);
}

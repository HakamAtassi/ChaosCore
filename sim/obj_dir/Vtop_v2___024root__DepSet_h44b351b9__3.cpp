// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2___024root.h"

VL_INLINE_OPT void Vtop_v2___024root___nba_sequent__TOP__5(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___nba_sequent__TOP__5\n"); );
    // Body
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT___data_cache_io_backend_memory_response_bits 
        = (((QData)((IData)(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_26)
                              ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__ram
                              : 0U))) << 4U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__hit_MOB_index_REG)));
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
        = ((- (IData)((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE)))) 
           | ((0xfU & ((- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___byte_offset_match_T_125))) 
                       & (- (IData)((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_access_width)))))) 
              | ((3U & ((- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___byte_offset_match_T_125))) 
                        & (- (IData)((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_access_width)))))) 
                 | (1U & ((- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___byte_offset_match_T_125))) 
                          & (- (IData)((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_access_width)))))))));
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_0__io_addr 
        = ((0U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                         >> 5U))) ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_set)
            : 0U);
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_1__io_addr 
        = ((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                         >> 5U))) ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_set)
            : 0U);
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_2__io_addr 
        = ((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                         >> 5U))) ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_set)
            : 0U);
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_3__io_addr 
        = ((3U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                         >> 5U))) ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_set)
            : 0U);
}

VL_INLINE_OPT void Vtop_v2___024root___nba_comb__TOP__1(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___nba_comb__TOP__1\n"); );
    // Init
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_0;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_0 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_1;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_1 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_2;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_2 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_3;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_3 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_4;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_4 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_5;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_5 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_6;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_6 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_7;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_7 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_8;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_8 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_9;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_9 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_10;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_10 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_11;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_11 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_12;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_12 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_13;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_13 = 0;
    CData/*0:0*/ top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_14;
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_14 = 0;
    // Body
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN 
        = (1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16)) 
                 & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_0 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 1U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 1U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_1 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 2U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 2U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_2 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 3U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 3U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_3 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 4U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 4U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_4 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 5U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 5U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_5 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 6U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 6U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_6 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 7U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 7U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_7 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 8U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 8U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_8 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 9U)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                           >> 9U)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_9 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 0xaU)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                             >> 0xaU)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_10 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 0xbU)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                             >> 0xbU)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_11 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 0xcU)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                             >> 0xcU)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_12 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 0xdU)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                             >> 0xdU)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_13 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 0xeU)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                             >> 0xeU)))));
    top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_14 
        = (1U & ((~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                     >> 0xfU)) & (~ (IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
                                             >> 0xfU)))));
    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index 
        = (((QData)((IData)(((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN) 
                               & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3)) 
                              & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5))
                              ? 1U : ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_0) 
                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                           >> 1U)) 
                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                          >> 1U)) ? 2U
                                       : ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_1) 
                                            & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                               >> 2U)) 
                                           & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                              >> 2U))
                                           ? 4U : (
                                                   (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_2) 
                                                     & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                        >> 3U)) 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                       >> 3U))
                                                    ? 8U
                                                    : 
                                                   ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_3) 
                                                      & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                         >> 4U)) 
                                                     & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                        >> 4U))
                                                     ? 0x10U
                                                     : 
                                                    ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_4) 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                          >> 5U)) 
                                                      & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                         >> 5U))
                                                      ? 0x20U
                                                      : 
                                                     ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_5) 
                                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                           >> 6U)) 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                          >> 6U))
                                                       ? 0x40U
                                                       : 
                                                      ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_6) 
                                                         & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                            >> 7U)) 
                                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                           >> 7U))
                                                        ? 0x80U
                                                        : 
                                                       ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_7) 
                                                          & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                             >> 8U)) 
                                                         & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                            >> 8U))
                                                         ? 0x100U
                                                         : 
                                                        ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_8) 
                                                           & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                              >> 9U)) 
                                                          & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                             >> 9U))
                                                          ? 0x200U
                                                          : 
                                                         ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_9) 
                                                            & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                               >> 0xaU)) 
                                                           & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                              >> 0xaU))
                                                           ? 0x400U
                                                           : 
                                                          ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_10) 
                                                             & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                >> 0xbU)) 
                                                            & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                               >> 0xbU))
                                                            ? 0x800U
                                                            : 
                                                           ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_11) 
                                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                 >> 0xcU)) 
                                                             & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                                >> 0xcU))
                                                             ? 0x1000U
                                                             : 
                                                            ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_12) 
                                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                  >> 0xdU)) 
                                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                                 >> 0xdU))
                                                              ? 0x2000U
                                                              : 
                                                             ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_13) 
                                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                   >> 0xeU)) 
                                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5) 
                                                                  >> 0xeU))
                                                               ? 0x4000U
                                                               : 
                                                              (0xffff8000U 
                                                               & ((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_14) 
                                                                    << 0xfU) 
                                                                   & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3)) 
                                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_5)))))))))))))))))))) 
            << 0x30U) | (((QData)((IData)((((((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN) 
                                              & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3))
                                              ? 1U : 
                                             (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_0) 
                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                  >> 1U))
                                               ? 2U
                                               : (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_1) 
                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                      >> 2U))
                                                   ? 4U
                                                   : 
                                                  (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_2) 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                       >> 3U))
                                                    ? 8U
                                                    : 
                                                   (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_3) 
                                                     & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                        >> 4U))
                                                     ? 0x10U
                                                     : 
                                                    (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_4) 
                                                      & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                         >> 5U))
                                                      ? 0x20U
                                                      : 
                                                     (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_5) 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                          >> 6U))
                                                       ? 0x40U
                                                       : 
                                                      (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_6) 
                                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                           >> 7U))
                                                        ? 0x80U
                                                        : 
                                                       (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_7) 
                                                         & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                            >> 8U))
                                                         ? 0x100U
                                                         : 
                                                        (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_8) 
                                                          & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                             >> 9U))
                                                          ? 0x200U
                                                          : 
                                                         (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_9) 
                                                           & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                              >> 0xaU))
                                                           ? 0x400U
                                                           : 
                                                          (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_10) 
                                                            & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                               >> 0xbU))
                                                            ? 0x800U
                                                            : 
                                                           (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_11) 
                                                             & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                >> 0xcU))
                                                             ? 0x1000U
                                                             : 
                                                            (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_12) 
                                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                 >> 0xdU))
                                                              ? 0x2000U
                                                              : 
                                                             (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_13) 
                                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3) 
                                                                  >> 0xeU))
                                                               ? 0x4000U
                                                               : 
                                                              (0xffff8000U 
                                                               & (((IData)(top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___GEN_14) 
                                                                   << 0xfU) 
                                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_3)))))))))))))))))) 
                                            << 0x10U) 
                                           | ((1U & 
                                               ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16)) 
                                                & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1)))
                                               ? 1U
                                               : ((1U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                        >> 1U)) 
                                                      & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                         >> 1U)))
                                                   ? 2U
                                                   : 
                                                  ((1U 
                                                    & ((~ 
                                                        ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                         >> 2U)) 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                          >> 2U)))
                                                    ? 4U
                                                    : 
                                                   ((1U 
                                                     & ((~ 
                                                         ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                          >> 3U)) 
                                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                           >> 3U)))
                                                     ? 8U
                                                     : 
                                                    ((1U 
                                                      & ((~ 
                                                          ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                           >> 4U)) 
                                                         & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                            >> 4U)))
                                                      ? 0x10U
                                                      : 
                                                     ((1U 
                                                       & ((~ 
                                                           ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                            >> 5U)) 
                                                          & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                             >> 5U)))
                                                       ? 0x20U
                                                       : 
                                                      ((1U 
                                                        & ((~ 
                                                            ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                             >> 6U)) 
                                                           & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                              >> 6U)))
                                                        ? 0x40U
                                                        : 
                                                       ((1U 
                                                         & ((~ 
                                                             ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                              >> 7U)) 
                                                            & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                               >> 7U)))
                                                         ? 0x80U
                                                         : 
                                                        ((1U 
                                                          & ((~ 
                                                              ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                               >> 8U)) 
                                                             & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                >> 8U)))
                                                          ? 0x100U
                                                          : 
                                                         ((1U 
                                                           & ((~ 
                                                               ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                >> 9U)) 
                                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                 >> 9U)))
                                                           ? 0x200U
                                                           : 
                                                          ((1U 
                                                            & ((~ 
                                                                ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                 >> 0xaU)) 
                                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                  >> 0xaU)))
                                                            ? 0x400U
                                                            : 
                                                           ((1U 
                                                             & ((~ 
                                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                  >> 0xbU)) 
                                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                   >> 0xbU)))
                                                             ? 0x800U
                                                             : 
                                                            ((1U 
                                                              & ((~ 
                                                                  ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                   >> 0xcU)) 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                    >> 0xcU)))
                                                              ? 0x1000U
                                                              : 
                                                             ((1U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                    >> 0xdU)) 
                                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                     >> 0xdU)))
                                                               ? 0x2000U
                                                               : 
                                                              ((1U 
                                                                & ((~ 
                                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                     >> 0xeU)) 
                                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                      >> 0xeU)))
                                                                ? 0x4000U
                                                                : 
                                                               ((IData)(
                                                                        ((~ 
                                                                          ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                           >> 0xfU)) 
                                                                         & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT___allocate_index_T_1) 
                                                                            >> 0xfU))) 
                                                                << 0xfU))))))))))))))))))) 
                          << 0x10U) | (QData)((IData)(
                                                      ((1U 
                                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                           ? 
                                                          ((0x10U 
                                                            & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                            ? 
                                                           ((0x20U 
                                                             & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                             ? 
                                                            ((0x40U 
                                                              & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                              ? 
                                                             ((0x80U 
                                                               & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                               ? 
                                                              ((0x100U 
                                                                & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                ? 
                                                               ((0x200U 
                                                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                 ? 
                                                                ((0x400U 
                                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                  ? 
                                                                 ((0x800U 
                                                                   & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                   ? 
                                                                  ((0x1000U 
                                                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                    ? 
                                                                   ((0x2000U 
                                                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                     ? 
                                                                    ((0x4000U 
                                                                      & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16))
                                                                      ? 
                                                                     (0x8000U 
                                                                      & ((~ 
                                                                          ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT____VdfgRegularize_hd3b6760e_0_16) 
                                                                           >> 0xfU)) 
                                                                         << 0xfU))
                                                                      : 0x4000U)
                                                                     : 0x2000U)
                                                                    : 0x1000U)
                                                                   : 0x800U)
                                                                  : 0x400U)
                                                                 : 0x200U)
                                                                : 0x100U)
                                                               : 0x80U)
                                                              : 0x40U)
                                                             : 0x20U)
                                                            : 0x10U)
                                                           : 8U)
                                                          : 4U)
                                                         : 2U)
                                                        : 1U)))));
}

void Vtop_v2___024root___timing_resume(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___timing_resume\n"); );
    // Body
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he840ac8e__0.resume("@(posedge top_v2.clock)");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtop_v2___024root___timing_commit(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___timing_commit\n"); );
    // Body
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he840ac8e__0.commit("@(posedge top_v2.clock)");
    }
}

void Vtop_v2___024root___eval_triggers__act(Vtop_v2___024root* vlSelf);
void Vtop_v2___024root___eval_act(Vtop_v2___024root* vlSelf);

bool Vtop_v2___024root___eval_phase__act(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<8> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop_v2___024root___eval_triggers__act(vlSelf);
    Vtop_v2___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop_v2___024root___timing_resume(vlSelf);
        Vtop_v2___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop_v2___024root___eval_nba(Vtop_v2___024root* vlSelf);

bool Vtop_v2___024root___eval_phase__nba(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop_v2___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_v2___024root___dump_triggers__nba(Vtop_v2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_v2___024root___dump_triggers__act(Vtop_v2___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_v2___024root___eval(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop_v2___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top_v2.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop_v2___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top_v2.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop_v2___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop_v2___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop_v2___024root___eval_debug_assertions(Vtop_v2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

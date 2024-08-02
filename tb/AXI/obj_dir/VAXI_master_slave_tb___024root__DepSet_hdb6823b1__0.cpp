// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAXI_master_slave_tb.h for the primary calling header

#include "VAXI_master_slave_tb__pch.h"
#include "VAXI_master_slave_tb___024root.h"

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_initial__TOP(VAXI_master_slave_tb___024root* vlSelf);
VlCoroutine VAXI_master_slave_tb___024root___eval_initial__TOP__0(VAXI_master_slave_tb___024root* vlSelf);
VlCoroutine VAXI_master_slave_tb___024root___eval_initial__TOP__1(VAXI_master_slave_tb___024root* vlSelf);
VlCoroutine VAXI_master_slave_tb___024root___eval_initial__TOP__2(VAXI_master_slave_tb___024root* vlSelf);

void VAXI_master_slave_tb___024root___eval_initial(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_initial\n"); );
    // Body
    VAXI_master_slave_tb___024root___eval_initial__TOP(vlSelf);
    VAXI_master_slave_tb___024root___eval_initial__TOP__0(vlSelf);
    VAXI_master_slave_tb___024root___eval_initial__TOP__1(vlSelf);
    VAXI_master_slave_tb___024root___eval_initial__TOP__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__AXI_master_slave_tb__DOT__clock__0 
        = vlSelf->AXI_master_slave_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine VAXI_master_slave_tb___024root___eval_initial__TOP__0(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_initial__TOP__0\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__clock = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "axi_master_slave_tb.sv", 
                                           23);
        vlSelf->AXI_master_slave_tb__DOT__clock = (1U 
                                                   & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__clock)));
    }
}

VL_INLINE_OPT VlCoroutine VAXI_master_slave_tb___024root___eval_initial__TOP__1(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_initial__TOP__1\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "axi_master_slave_tb.sv", 
                                       29);
    vlSelf->AXI_master_slave_tb__DOT__reset = 0U;
}

VL_INLINE_OPT VlCoroutine VAXI_master_slave_tb___024root___eval_initial__TOP__2(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_initial__TOP__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xf4240ULL, 
                                       nullptr, "axi_master_slave_tb.sv", 
                                       36);
    VL_FINISH_MT("axi_master_slave_tb.sv", 37, "");
}

void VAXI_master_slave_tb___024root___eval_act(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_act\n"); );
}

VL_INLINE_OPT void VAXI_master_slave_tb___024root___nba_sequent__TOP__0(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    VlUnpacked<IData/*31:0*/, 16384> AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem;
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__Vi0] = 0;
    }
    IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i;
    AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i = 0;
    VlWide<8>/*255:0*/ __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER;
    VL_ZERO_W(256, __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER);
    SData/*13:0*/ __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    SData/*13:0*/ __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    SData/*13:0*/ __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    SData/*13:0*/ __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    // Body
    if (VL_UNLIKELY((1U & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg) 
                           & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__reset)))))) {
        VL_FWRITEF(0x80000002U,"AXI write accepted");
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg)) 
                           & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__reset)))))) {
        VL_FWRITEF(0x80000002U,"AXI write not accepted");
    }
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0U;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0U;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0U;
    __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0U;
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U];
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U];
    AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i = 4U;
    if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en) 
         & (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
        __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 
            = (0xffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata);
        __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 1U;
        __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0U;
        __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 
            = (0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                          >> 2U));
    }
    if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en) 
         & ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
            >> 1U))) {
        __Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 
            = (0xffU & (vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
                        >> 8U));
        __Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 1U;
        __Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 8U;
        __Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 
            = (0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                          >> 2U));
    }
    if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg) {
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U] = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U] = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U] = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U] = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U] = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U] = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U] = 0U;
    } else if (((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg))) {
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U] = 0U;
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next;
    if (__Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0) {
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0))) 
                & AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0) 
                                   << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0))));
    }
    if (__Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1) {
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1))) 
                & AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1) 
                                   << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1))));
    }
    if (__Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2) {
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2))) 
                & AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2) 
                                   << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2))));
    }
    if (__Vdlyvset__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3) {
        AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3))) 
                & AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__Vdlyvdim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3) 
                                   << (IData)(__Vdlyvlsb__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3))));
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U] 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next;
    if (vlSelf->AXI_master_slave_tb__DOT__reset) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE = 0U;
    } else {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS 
            = ((IData)(1U) + vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS);
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE 
            = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid)
                ? ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg)
                    ? 2U : ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
                            & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid)))
                : ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_W_valid)
                    ? ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_W_valid) 
                       << 2U) : ((1U & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_B_ready) 
                                        | (~ ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_R_ready) 
                                              & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg)))))
                                  ? 0U : 3U)));
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_W_valid 
        = (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_B_ready 
        = (4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid 
        = (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_R_ready 
        = (3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
        = ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))
            ? vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U]
            : 0U);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg) 
           & (3U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg) 
           & (4U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)));
    if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
            if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
                 & (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = 1U;
                if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))) {
                    if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                               | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = 1U;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
            if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                       | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = 1U;
            }
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next;
    if (vlSelf->AXI_master_slave_tb__DOT__reset) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg = 0U;
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg;
    if ((1U & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg)))) {
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
             & (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next = 0U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg;
    if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg) {
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg) {
            if ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                       | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg))))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next = 1U;
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next 
                    = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg;
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next 
                    = (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg));
                if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 1U;
                }
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next 
                    = (0xffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg) 
                                - (IData)(1U)));
                if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next 
                        = (0xffffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg) 
                                      + ((IData)(1U) 
                                         << (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg))));
                }
            }
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next 
                = ((1U & (~ ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                             | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg))))) 
                   || (0U < (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg)));
        }
    } else {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
             & (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 1U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 0U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg;
    if ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
                = (0xffffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS);
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
        }
    } else if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
             & (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
                = (0xffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg) 
                            - (IData)(1U)));
            if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 0U;
                if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                           | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
                }
            }
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next 
                = ((0U < (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))
                    ? 1U : ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                                   | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))
                             ? 0U : 2U));
            if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
                    = (0xffffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                                  + ((IData)(1U) << (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg))));
            }
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 1U;
        }
    } else if ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                   | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 2U;
        }
    }
}

void VAXI_master_slave_tb___024root___eval_nba(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VAXI_master_slave_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VAXI_master_slave_tb___024root___timing_resume(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void VAXI_master_slave_tb___024root___eval_triggers__act(VAXI_master_slave_tb___024root* vlSelf);

bool VAXI_master_slave_tb___024root___eval_phase__act(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VAXI_master_slave_tb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VAXI_master_slave_tb___024root___timing_resume(vlSelf);
        VAXI_master_slave_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VAXI_master_slave_tb___024root___eval_phase__nba(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VAXI_master_slave_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__nba(VAXI_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__act(VAXI_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG

void VAXI_master_slave_tb___024root___eval(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VAXI_master_slave_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("axi_master_slave_tb.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VAXI_master_slave_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("axi_master_slave_tb.sv", 8, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VAXI_master_slave_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VAXI_master_slave_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VAXI_master_slave_tb___024root___eval_debug_assertions(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

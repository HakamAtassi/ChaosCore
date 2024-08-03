// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_master_slave_tb.h for the primary calling header

#include "Vaxi_master_slave_tb__pch.h"
#include "Vaxi_master_slave_tb___024root.h"

VL_ATTR_COLD void Vaxi_master_slave_tb___024root___eval_initial__TOP(Vaxi_master_slave_tb___024root* vlSelf);
VlCoroutine Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__0(Vaxi_master_slave_tb___024root* vlSelf);
VlCoroutine Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__1(Vaxi_master_slave_tb___024root* vlSelf);
VlCoroutine Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__2(Vaxi_master_slave_tb___024root* vlSelf);

void Vaxi_master_slave_tb___024root___eval_initial(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_initial\n"); );
    // Body
    Vaxi_master_slave_tb___024root___eval_initial__TOP(vlSelf);
    Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__AXI_master_slave_tb__DOT__clock__0 
        = vlSelf->AXI_master_slave_tb__DOT__clock;
}

VL_INLINE_OPT VlCoroutine Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__0(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__clock = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "axi_master_slave_tb.sv", 
                                           18);
        vlSelf->AXI_master_slave_tb__DOT__clock = (1U 
                                                   & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__clock)));
    }
}

VL_INLINE_OPT VlCoroutine Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__1(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "axi_master_slave_tb.sv", 
                                       24);
    vlSelf->AXI_master_slave_tb__DOT__reset = 0U;
}

VL_INLINE_OPT VlCoroutine Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__2(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Init
    IData/*31:0*/ AXI_master_slave_tb__DOT____Vrepeat0;
    AXI_master_slave_tb__DOT____Vrepeat0 = 0;
    // Body
    AXI_master_slave_tb__DOT____Vrepeat0 = 0x2710U;
    while (VL_LTS_III(32, 0U, AXI_master_slave_tb__DOT____Vrepeat0)) {
        co_await vlSelf->__VtrigSched_he1ee2fab__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge AXI_master_slave_tb.clock)", 
                                                           "axi_master_slave_tb.sv", 
                                                           31);
        AXI_master_slave_tb__DOT____Vrepeat0 = (AXI_master_slave_tb__DOT____Vrepeat0 
                                                - (IData)(1U));
    }
    VL_FINISH_MT("axi_master_slave_tb.sv", 32, "");
}

void Vaxi_master_slave_tb___024root___eval_act(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_act\n"); );
}

void Vaxi_master_slave_tb___024root___nba_sequent__TOP__0(Vaxi_master_slave_tb___024root* vlSelf);

void Vaxi_master_slave_tb___024root___eval_nba(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vaxi_master_slave_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

extern const VlWide<8>/*255:0*/ Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0;

VL_INLINE_OPT void Vaxi_master_slave_tb___024root___nba_sequent__TOP__0(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16;
    AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16 = 0;
    CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_17;
    AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_17 = 0;
    CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_18;
    AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_18 = 0;
    VlWide<8>/*255:0*/ __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER;
    VL_ZERO_W(256, __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER);
    CData/*1:0*/ __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE;
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE = 0;
    IData/*31:0*/ __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter;
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter = 0;
    CData/*7:0*/ __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    SData/*13:0*/ __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    SData/*13:0*/ __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    SData/*13:0*/ __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    SData/*13:0*/ __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0;
    VlWide<8>/*255:0*/ __Vtemp_1;
    // Body
    if (VL_UNLIKELY((1U & (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) 
                            | (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid)) 
                           & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__reset)))))) {
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) {
            __Vtemp_1[0U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[0U];
            __Vtemp_1[1U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[1U];
            __Vtemp_1[2U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[2U];
            __Vtemp_1[3U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[3U];
            __Vtemp_1[4U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[4U];
            __Vtemp_1[5U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[5U];
            __Vtemp_1[6U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[6U];
            __Vtemp_1[7U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[7U];
        } else {
            __Vtemp_1[0U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[0U];
            __Vtemp_1[1U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[1U];
            __Vtemp_1[2U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[2U];
            __Vtemp_1[3U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[3U];
            __Vtemp_1[4U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[4U];
            __Vtemp_1[5U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[5U];
            __Vtemp_1[6U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[6U];
            __Vtemp_1[7U] = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[7U];
        }
        VL_FWRITEF_NX(0x80000002U,"Read Resp: %x\n",0,
                      256,__Vtemp_1.data());
    }
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 0U;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 0U;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 0U;
    __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 0U;
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter;
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
    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i = 4U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full 
        = ((~ (IData)(vlSelf->AXI_master_slave_tb__DOT__reset)) 
           & ((((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__do_enq) 
                == ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) 
                    & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___final_response_buffer_io_deq_valid))) 
               | (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT___do_enq_T)) 
              & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full)));
    if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en) 
         & (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
        __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 
            = (0xffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata);
        __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 
            = (0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                          >> 2U));
        __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0 = 1U;
        __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 
            = (0xffU & (vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
                        >> 8U));
        __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 
            = (0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                          >> 2U));
        __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1 = 1U;
        __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 
            = (0xffU & (vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
                        >> 0x10U));
        __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 
            = (0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                          >> 2U));
        __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2 = 1U;
        __VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 
            = (vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
               >> 0x18U);
        __VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 
            = (0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                          >> 2U));
        __VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3 = 1U;
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next;
    if ((1U & (~ (((2U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                   | (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_9)) 
                  | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_7)))))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[0U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[0U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[1U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[1U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[2U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[2U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[3U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[3U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[4U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[4U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[5U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[5U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[6U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[6U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[7U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[7U];
    }
    if ((1U & ((~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_pipe_reg)) 
               | (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_pipe_reg 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_pipe_reg 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_pipe_reg 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_pipe_reg 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg;
    }
    AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AW_valid));
    AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_17 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_5));
    AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_18 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_5) 
           & (IData)(AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_17));
    if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_11) 
         & (IData)(AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16))) {
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[0U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[1U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[1U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[2U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[2U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[3U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[3U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[4U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[4U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[5U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[5U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[6U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[6U];
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[7U] 
            = Vaxi_master_slave_tb__ConstPool__CONST_h07725354_0[7U];
    } else if (AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_18) {
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
    if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__do_enq) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[0U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[0U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[1U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[1U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[2U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[2U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[3U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[3U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[4U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[4U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[5U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[5U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[6U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[6U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram[7U] 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[7U];
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
    if (vlSelf->AXI_master_slave_tb__DOT__reset) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_pipe_reg = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE = 0U;
        __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE = 0U;
    } else {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_19 
            = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
               & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid));
        if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))) {
            if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_5) {
                if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_8) 
                     & (IData)(AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_17))) {
                    __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE = 3U;
                }
            } else if (((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))
                         ? ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                            & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))
                         : (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_6) 
                             & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg)) 
                            & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_7)))) {
                __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE = 0U;
            }
        } else {
            __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE 
                = ((IData)(AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16)
                    ? 1U : ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_19) 
                            << 1U));
        }
        if (AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_18) {
            __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter 
                = (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter 
                   - (IData)(1U));
        } else if (((~ (IData)((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) 
                    & (IData)(AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16))) {
            __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter 
                = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_11)
                    ? 7U : 0U);
        }
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_11) {
            if (AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT___GEN_16) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE = 1U;
            }
        } else if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_13) 
                    & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_19))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE = 2U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE 
        = __Vdly__AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next;
    if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_rd_en) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
            [(0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg) 
                         >> 2U))];
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next;
    if (vlSelf->AXI_master_slave_tb__DOT__reset) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg = 0U;
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_11 
        = (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_13 
        = (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15 
        = ((1U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)) 
           | (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_5 
        = (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_6 
        = (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U];
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_8 
            = (0U == vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter);
    } else {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata = 0U;
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_8 = 0U;
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid 
        = ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)) 
           & ((~ (IData)((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) 
              & (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AW_valid 
        = ((~ (IData)((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) 
           & (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)));
    if (__VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0] 
            = ((0xffffff00U & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0]) 
               | (IData)(__VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v0));
    }
    if (__VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v1) 
                  << 8U));
    }
    if (__VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v2) 
                  << 0x10U));
    }
    if (__VdlySet__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem[__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3] 
            = ((0xffffffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem
                [__VdlyDim0__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3]) 
               | ((IData)(__VdlyVal__AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem__v3) 
                  << 0x18U));
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[0U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[1U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[0U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[2U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[1U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[3U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[2U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[4U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[3U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[5U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[4U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[6U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[5U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10[7U] 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer[6U];
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_rd_en = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg) 
           & (2U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_7 
        = ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg;
    if ((1U & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg)))) {
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
             & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next 
                = ((2U > ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                           ? 0U : 5U)) ? ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                                           ? 0U : 5U)
                    : 2U);
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next 
                = ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                    ? 0U : (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)));
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg) 
           & (~ (IData)((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg;
    if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
            if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
                 & (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = 1U;
                if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))) {
                    if ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                               | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = 1U;
                        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next 
                            = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
            if ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                       | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = 1U;
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next 
                    = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg;
            }
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg;
    if ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg) 
             & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AW_valid))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next 
                = (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE));
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next 
                = ((2U > ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                           ? 5U : 0U)) ? ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                           ? 5U : 0U)
                    : 2U);
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
                = ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                    ? 7U : 0U);
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next = 0U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
        }
    } else if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
             & (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 0U;
                if ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                           | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
                }
            }
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
                = (0xffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg) 
                            - (IData)(1U)));
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next 
                = ((0U < (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))
                    ? 1U : ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
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
        if ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                   | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 2U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_9 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_7) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg;
    if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg) {
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg) {
            if ((1U & ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                       | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg))))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_rd_en = 1U;
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
                = ((1U & (~ ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                             | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg))))) 
                   || (0U < (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg)));
        }
    } else {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
             & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next 
                = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                    ? 0U : 7U);
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 1U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 0U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid 
        = ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_9));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___final_response_buffer_io_deq_valid 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) 
           | (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT___do_enq_T 
        = ((~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full)) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__do_enq 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) 
           & (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT___do_enq_T));
}

void Vaxi_master_slave_tb___024root___timing_resume(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he1ee2fab__0.resume("@(posedge AXI_master_slave_tb.clock)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vaxi_master_slave_tb___024root___timing_commit(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he1ee2fab__0.commit("@(posedge AXI_master_slave_tb.clock)");
    }
}

void Vaxi_master_slave_tb___024root___eval_triggers__act(Vaxi_master_slave_tb___024root* vlSelf);

bool Vaxi_master_slave_tb___024root___eval_phase__act(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaxi_master_slave_tb___024root___eval_triggers__act(vlSelf);
    Vaxi_master_slave_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vaxi_master_slave_tb___024root___timing_resume(vlSelf);
        Vaxi_master_slave_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaxi_master_slave_tb___024root___eval_phase__nba(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaxi_master_slave_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_slave_tb___024root___dump_triggers__nba(Vaxi_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_slave_tb___024root___dump_triggers__act(Vaxi_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vaxi_master_slave_tb___024root___eval(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vaxi_master_slave_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("axi_master_slave_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vaxi_master_slave_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("axi_master_slave_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vaxi_master_slave_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vaxi_master_slave_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaxi_master_slave_tb___024root___eval_debug_assertions(Vaxi_master_slave_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

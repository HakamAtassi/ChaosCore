// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaxi_master_slave_tb__Syms.h"


void Vaxi_master_slave_tb___024root__trace_chg_0_sub_0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaxi_master_slave_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_chg_0\n"); );
    // Init
    Vaxi_master_slave_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_master_slave_tb___024root*>(voidSelf);
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaxi_master_slave_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vaxi_master_slave_tb___024root__trace_chg_0_sub_0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<8>/*255:0*/ __Vtemp_1;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg));
        bufp->chgBit(oldp+1,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AW_valid));
        bufp->chgQData(oldp+2,((QData)((IData)(((((0U 
                                                   == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                                   ? 7U
                                                   : 0U) 
                                                 << 0xdU) 
                                                | ((((0U 
                                                      == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                                      ? 5U
                                                      : 0U) 
                                                    << 0xaU) 
                                                   | ((0U 
                                                       == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)) 
                                                      << 8U)))))),61);
        bufp->chgBit(oldp+4,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg));
        bufp->chgBit(oldp+5,((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))));
        bufp->chgQData(oldp+6,((((QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata)) 
                                 << 5U) | (QData)((IData)(
                                                          ((0x1eU 
                                                            & ((- (IData)(
                                                                          (1U 
                                                                           == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) 
                                                               << 1U)) 
                                                           | ((1U 
                                                               == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                                                              & (0U 
                                                                 == vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter))))))),37);
        bufp->chgBit(oldp+8,((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+9,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg));
        bufp->chgSData(oldp+10,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg) 
                                 << 2U)),10);
        bufp->chgBit(oldp+11,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg));
        bufp->chgBit(oldp+12,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid));
        bufp->chgQData(oldp+13,((QData)((IData)(((((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                                                    ? 0U
                                                    : 7U) 
                                                  << 0xdU) 
                                                 | ((((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                                                       ? 0U
                                                       : 5U) 
                                                     << 0xaU) 
                                                    | (((0U 
                                                         == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                                         ? 0U
                                                         : 
                                                        (1U 
                                                         == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))) 
                                                       << 8U)))))),61);
        bufp->chgBit(oldp+15,((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+16,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg));
        bufp->chgQData(oldp+17,((((QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg)) 
                                  << 0x23U) | (((QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg)) 
                                                << 3U) 
                                               | (QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg))))),43);
        bufp->chgWData(oldp+19,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER),256);
        bufp->chgCData(oldp+27,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE),2);
        bufp->chgIData(oldp+28,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter),32);
        bufp->chgWData(oldp+29,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer),256);
        bufp->chgCData(oldp+37,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE),2);
        bufp->chgBit(oldp+38,((1U & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full)))));
        bufp->chgBit(oldp+39,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid));
        bufp->chgWData(oldp+40,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10),256);
        bufp->chgBit(oldp+48,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) 
                               | (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid))));
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
        bufp->chgWData(oldp+49,(__Vtemp_1),256);
        bufp->chgBit(oldp+57,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full));
        bufp->chgWData(oldp+58,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram),256);
        bufp->chgBit(oldp+66,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__do_enq));
        bufp->chgCData(oldp+67,(((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                  ? 7U : 0U)),8);
        bufp->chgCData(oldp+68,(((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                  ? 5U : 0U)),3);
        bufp->chgCData(oldp+69,((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))),2);
        bufp->chgIData(oldp+70,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata),32);
        bufp->chgCData(oldp+71,((0xfU & (- (IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))))),4);
        bufp->chgBit(oldp+72,(((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                               & (0U == vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter))));
        bufp->chgCData(oldp+73,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg),8);
        bufp->chgCData(oldp+74,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                                  ? 0U : 7U)),8);
        bufp->chgCData(oldp+75,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                                  ? 0U : 5U)),3);
        bufp->chgCData(oldp+76,(((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                                  ? 0U : (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)))),2);
        bufp->chgCData(oldp+77,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg),8);
        bufp->chgIData(oldp+78,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg),32);
        bufp->chgBit(oldp+79,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg));
        bufp->chgBit(oldp+80,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg));
        bufp->chgBit(oldp+81,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next));
        bufp->chgCData(oldp+82,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg),2);
        bufp->chgCData(oldp+83,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next),2);
        bufp->chgBit(oldp+84,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en));
        bufp->chgBit(oldp+85,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_rd_en));
        bufp->chgCData(oldp+86,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg),8);
        bufp->chgCData(oldp+87,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next),8);
        bufp->chgSData(oldp+88,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg),16);
        bufp->chgSData(oldp+89,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next),16);
        bufp->chgCData(oldp+90,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg),8);
        bufp->chgCData(oldp+91,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next),8);
        bufp->chgCData(oldp+92,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg),3);
        bufp->chgCData(oldp+93,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next),3);
        bufp->chgCData(oldp+94,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg),2);
        bufp->chgCData(oldp+95,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next),2);
        bufp->chgCData(oldp+96,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg),8);
        bufp->chgCData(oldp+97,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_next),8);
        bufp->chgSData(oldp+98,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg),16);
        bufp->chgSData(oldp+99,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next),16);
        bufp->chgCData(oldp+100,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg),8);
        bufp->chgCData(oldp+101,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next),8);
        bufp->chgCData(oldp+102,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg),3);
        bufp->chgCData(oldp+103,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next),3);
        bufp->chgCData(oldp+104,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg),2);
        bufp->chgCData(oldp+105,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next),2);
        bufp->chgBit(oldp+106,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next));
        bufp->chgBit(oldp+107,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next));
        bufp->chgCData(oldp+108,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next),8);
        bufp->chgBit(oldp+109,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next));
        bufp->chgBit(oldp+110,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next));
        bufp->chgCData(oldp+111,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next),8);
        bufp->chgBit(oldp+112,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next));
        bufp->chgBit(oldp+113,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next));
        bufp->chgCData(oldp+114,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_pipe_reg),8);
        bufp->chgIData(oldp+115,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_pipe_reg),32);
        bufp->chgBit(oldp+116,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_pipe_reg));
        bufp->chgBit(oldp+117,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_pipe_reg));
        bufp->chgSData(oldp+118,((0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg) 
                                             >> 2U))),14);
        bufp->chgSData(oldp+119,((0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                                             >> 2U))),14);
    }
    bufp->chgBit(oldp+120,(vlSelf->AXI_master_slave_tb__DOT__clock));
    bufp->chgBit(oldp+121,(vlSelf->AXI_master_slave_tb__DOT__reset));
    bufp->chgIData(oldp+122,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i),32);
    bufp->chgIData(oldp+123,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j),32);
}

void Vaxi_master_slave_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_cleanup\n"); );
    // Init
    Vaxi_master_slave_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_master_slave_tb___024root*>(voidSelf);
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}

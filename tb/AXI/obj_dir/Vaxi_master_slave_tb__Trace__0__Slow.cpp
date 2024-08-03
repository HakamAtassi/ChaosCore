// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaxi_master_slave_tb__Syms.h"


VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_init_sub__TOP__0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("AXI_master_slave_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+121,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+121,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("AXI_master", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+121,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"AXI_AW_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"AXI_AW_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+3,0,"AXI_AW_bits",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 60,0);
    tracep->declBit(c+5,0,"AXI_W_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"AXI_W_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+7,0,"AXI_W_bits",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 36,0);
    tracep->declBit(c+9,0,"AXI_B_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"AXI_B_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"AXI_B_bits",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+12,0,"AXI_AR_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"AXI_AR_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+14,0,"AXI_AR_bits",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 60,0);
    tracep->declBit(c+16,0,"AXI_R_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"AXI_R_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+18,0,"AXI_R_bits",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 42,0);
    tracep->declArray(c+20,0,"AXI_AW_DATA_BUFFER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+28,0,"AXI_REQUEST_STATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+29,0,"write_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+30,0,"AXI_read_buffer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+38,0,"AXI_MASTER_STATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("final_response_buffer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+121,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"io_enq_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"io_enq_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+41,0,"io_enq_bits",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+49,0,"io_deq_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+50,0,"io_deq_bits",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+58,0,"io_count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+59,0,"ram",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+58,0,"full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"do_enq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("axi_ram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+125,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"STRB_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"ID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"PIPELINE_OUTPUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+121,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"s_axi_awid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+131,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+68,0,"s_axi_awlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+69,0,"s_axi_awsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+70,0,"s_axi_awburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+132,0,"s_axi_awlock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"s_axi_awcache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+134,0,"s_axi_awprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+2,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+73,0,"s_axi_wlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"s_axi_bid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+135,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+10,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"s_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"s_axi_arid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+131,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+75,0,"s_axi_arlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"s_axi_arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+77,0,"s_axi_arburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+132,0,"s_axi_arlock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"s_axi_arcache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+134,0,"s_axi_arprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+13,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"s_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_rid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+79,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+80,0,"s_axi_rlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"s_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"VALID_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"WORD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"WORD_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"READ_STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+138,0,"READ_STATE_BURST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+81,0,"read_state_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+82,0,"read_state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+135,0,"WRITE_STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+139,0,"WRITE_STATE_BURST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+140,0,"WRITE_STATE_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+83,0,"write_state_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+84,0,"write_state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+85,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"read_id_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+88,0,"read_id_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+89,0,"read_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+90,0,"read_addr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+91,0,"read_count_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+92,0,"read_count_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+93,0,"read_size_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+94,0,"read_size_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+95,0,"read_burst_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+96,0,"read_burst_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+97,0,"write_id_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+98,0,"write_id_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+99,0,"write_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+100,0,"write_addr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+101,0,"write_count_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"write_count_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+103,0,"write_size_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+104,0,"write_size_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+105,0,"write_burst_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+106,0,"write_burst_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1,0,"s_axi_awready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"s_axi_awready_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"s_axi_wready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"s_axi_wready_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"s_axi_bid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+109,0,"s_axi_bid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+10,0,"s_axi_bvalid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"s_axi_bvalid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"s_axi_arready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"s_axi_arready_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_rid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+112,0,"s_axi_rid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+79,0,"s_axi_rdata_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"s_axi_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+80,0,"s_axi_rlast_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"s_axi_rlast_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"s_axi_rvalid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"s_axi_rvalid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"s_axi_rid_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+116,0,"s_axi_rdata_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+117,0,"s_axi_rlast_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"s_axi_rvalid_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+142,0,"s_axi_awaddr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+142,0,"s_axi_araddr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+119,0,"read_addr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+120,0,"write_addr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+123,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+124,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_init_top(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_init_top\n"); );
    // Body
    Vaxi_master_slave_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaxi_master_slave_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaxi_master_slave_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_register(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vaxi_master_slave_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vaxi_master_slave_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vaxi_master_slave_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vaxi_master_slave_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_const_0_sub_0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_const_0\n"); );
    // Init
    Vaxi_master_slave_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_master_slave_tb___024root*>(voidSelf);
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaxi_master_slave_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_const_0_sub_0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+125,(0x20U),32);
    bufp->fullIData(oldp+126,(0x10U),32);
    bufp->fullIData(oldp+127,(4U),32);
    bufp->fullIData(oldp+128,(8U),32);
    bufp->fullIData(oldp+129,(0U),32);
    bufp->fullCData(oldp+130,(0U),8);
    bufp->fullSData(oldp+131,(0U),16);
    bufp->fullBit(oldp+132,(0U));
    bufp->fullCData(oldp+133,(0U),4);
    bufp->fullCData(oldp+134,(0U),3);
    bufp->fullCData(oldp+135,(0U),2);
    bufp->fullIData(oldp+136,(0xeU),32);
    bufp->fullBit(oldp+137,(0U));
    bufp->fullBit(oldp+138,(1U));
    bufp->fullCData(oldp+139,(1U),2);
    bufp->fullCData(oldp+140,(2U),2);
    bufp->fullIData(oldp+141,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_next),32);
    bufp->fullSData(oldp+142,(0U),14);
}

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_full_0_sub_0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_full_0\n"); );
    // Init
    Vaxi_master_slave_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaxi_master_slave_tb___024root*>(voidSelf);
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaxi_master_slave_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaxi_master_slave_tb___024root__trace_full_0_sub_0(Vaxi_master_slave_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vaxi_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_slave_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<8>/*255:0*/ __Vtemp_1;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg));
    bufp->fullBit(oldp+2,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AW_valid));
    bufp->fullQData(oldp+3,((QData)((IData)(((((0U 
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
    bufp->fullBit(oldp+5,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg));
    bufp->fullBit(oldp+6,((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))));
    bufp->fullQData(oldp+7,((((QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata)) 
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
    bufp->fullBit(oldp+9,((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))));
    bufp->fullBit(oldp+10,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg));
    bufp->fullSData(oldp+11,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg) 
                              << 2U)),10);
    bufp->fullBit(oldp+12,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg));
    bufp->fullBit(oldp+13,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid));
    bufp->fullQData(oldp+14,((QData)((IData)(((((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
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
    bufp->fullBit(oldp+16,((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))));
    bufp->fullBit(oldp+17,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg));
    bufp->fullQData(oldp+18,((((QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg)) 
                               << 0x23U) | (((QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg)) 
                                             << 3U) 
                                            | (QData)((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg))))),43);
    bufp->fullWData(oldp+20,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER),256);
    bufp->fullCData(oldp+28,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE),2);
    bufp->fullIData(oldp+29,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter),32);
    bufp->fullWData(oldp+30,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer),256);
    bufp->fullCData(oldp+38,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE),2);
    bufp->fullBit(oldp+39,((1U & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full)))));
    bufp->fullBit(oldp+40,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid));
    bufp->fullWData(oldp+41,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10),256);
    bufp->fullBit(oldp+49,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full) 
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
    bufp->fullWData(oldp+50,(__Vtemp_1),256);
    bufp->fullBit(oldp+58,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full));
    bufp->fullWData(oldp+59,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram),256);
    bufp->fullBit(oldp+67,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__do_enq));
    bufp->fullCData(oldp+68,(((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                               ? 7U : 0U)),8);
    bufp->fullCData(oldp+69,(((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                               ? 5U : 0U)),3);
    bufp->fullCData(oldp+70,((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))),2);
    bufp->fullIData(oldp+71,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata),32);
    bufp->fullCData(oldp+72,((0xfU & (- (IData)((1U 
                                                 == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))))),4);
    bufp->fullBit(oldp+73,(((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                            & (0U == vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter))));
    bufp->fullCData(oldp+74,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg),8);
    bufp->fullCData(oldp+75,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                               ? 0U : 7U)),8);
    bufp->fullCData(oldp+76,(((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15)
                               ? 0U : 5U)),3);
    bufp->fullCData(oldp+77,(((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE))
                               ? 0U : (1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE)))),2);
    bufp->fullCData(oldp+78,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg),8);
    bufp->fullIData(oldp+79,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg),32);
    bufp->fullBit(oldp+80,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg));
    bufp->fullBit(oldp+81,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg));
    bufp->fullBit(oldp+82,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next));
    bufp->fullCData(oldp+83,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg),2);
    bufp->fullCData(oldp+84,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next),2);
    bufp->fullBit(oldp+85,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en));
    bufp->fullBit(oldp+86,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_rd_en));
    bufp->fullCData(oldp+87,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg),8);
    bufp->fullCData(oldp+88,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next),8);
    bufp->fullSData(oldp+89,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg),16);
    bufp->fullSData(oldp+90,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next),16);
    bufp->fullCData(oldp+91,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg),8);
    bufp->fullCData(oldp+92,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next),8);
    bufp->fullCData(oldp+93,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg),3);
    bufp->fullCData(oldp+94,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next),3);
    bufp->fullCData(oldp+95,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg),2);
    bufp->fullCData(oldp+96,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next),2);
    bufp->fullCData(oldp+97,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg),8);
    bufp->fullCData(oldp+98,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_next),8);
    bufp->fullSData(oldp+99,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg),16);
    bufp->fullSData(oldp+100,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next),16);
    bufp->fullCData(oldp+101,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg),8);
    bufp->fullCData(oldp+102,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next),8);
    bufp->fullCData(oldp+103,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg),3);
    bufp->fullCData(oldp+104,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next),3);
    bufp->fullCData(oldp+105,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg),2);
    bufp->fullCData(oldp+106,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next),2);
    bufp->fullBit(oldp+107,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next));
    bufp->fullBit(oldp+108,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next));
    bufp->fullCData(oldp+109,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next),8);
    bufp->fullBit(oldp+110,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next));
    bufp->fullBit(oldp+111,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next));
    bufp->fullCData(oldp+112,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next),8);
    bufp->fullBit(oldp+113,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next));
    bufp->fullBit(oldp+114,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next));
    bufp->fullCData(oldp+115,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_pipe_reg),8);
    bufp->fullIData(oldp+116,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_pipe_reg),32);
    bufp->fullBit(oldp+117,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_pipe_reg));
    bufp->fullBit(oldp+118,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_pipe_reg));
    bufp->fullSData(oldp+119,((0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg) 
                                          >> 2U))),14);
    bufp->fullSData(oldp+120,((0x3fffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                                          >> 2U))),14);
    bufp->fullBit(oldp+121,(vlSelf->AXI_master_slave_tb__DOT__clock));
    bufp->fullBit(oldp+122,(vlSelf->AXI_master_slave_tb__DOT__reset));
    bufp->fullIData(oldp+123,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i),32);
    bufp->fullIData(oldp+124,(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j),32);
}

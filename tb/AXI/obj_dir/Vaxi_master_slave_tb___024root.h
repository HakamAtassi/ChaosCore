// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaxi_master_slave_tb.h for the primary calling header

#ifndef VERILATED_VAXI_MASTER_SLAVE_TB___024ROOT_H_
#define VERILATED_VAXI_MASTER_SLAVE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaxi_master_slave_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaxi_master_slave_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ AXI_master_slave_tb__DOT__clock;
        CData/*0:0*/ AXI_master_slave_tb__DOT__reset;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AW_valid;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___final_response_buffer_io_deq_valid;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_5;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_6;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_7;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_8;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_9;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_STATE;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_11;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_13;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_15;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT____Vcellinp__final_response_buffer__io_enq_valid;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_19;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__full;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT___do_enq_T;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__do_enq;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_rd_en;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next;
        CData/*2:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg;
        CData/*2:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_reg;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_id_next;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next;
        CData/*2:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg;
        CData/*2:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg;
        CData/*1:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_reg;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bid_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next;
        CData/*7:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_pipe_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_pipe_reg;
        CData/*0:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_pipe_reg;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__AXI_master_slave_tb__DOT__clock__0;
        CData/*0:0*/ __VactContinue;
    };
    struct {
        SData/*15:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg;
        SData/*15:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next;
        SData/*15:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg;
        SData/*15:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata;
        VlWide<8>/*255:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__write_counter;
        VlWide<8>/*255:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_read_buffer;
        VlWide<8>/*255:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT___GEN_10;
        VlWide<8>/*255:0*/ AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__final_response_buffer__DOT__ram;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_reg;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_next;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rdata_pipe_reg;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__i;
        IData/*31:0*/ AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 16384> AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_he1ee2fab__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaxi_master_slave_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaxi_master_slave_tb___024root(Vaxi_master_slave_tb__Syms* symsp, const char* v__name);
    ~Vaxi_master_slave_tb___024root();
    VL_UNCOPYABLE(Vaxi_master_slave_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

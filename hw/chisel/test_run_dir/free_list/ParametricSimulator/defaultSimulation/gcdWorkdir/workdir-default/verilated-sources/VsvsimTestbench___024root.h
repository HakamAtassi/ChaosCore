// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VsvsimTestbench.h for the primary calling header

#ifndef VERILATED_VSVSIMTESTBENCH___024ROOT_H_
#define VERILATED_VSVSIMTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"


class VsvsimTestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ svsimTestbench__DOT__clock;
    CData/*0:0*/ svsimTestbench__DOT__reset;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_bits_RD_valid_0;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_bits_RD_valid_1;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_bits_RD_valid_2;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_bits_RD_valid_3;
    CData/*6:0*/ svsimTestbench__DOT__io_commit_bits_RD_0;
    CData/*6:0*/ svsimTestbench__DOT__io_commit_bits_RD_1;
    CData/*6:0*/ svsimTestbench__DOT__io_commit_bits_RD_2;
    CData/*6:0*/ svsimTestbench__DOT__io_commit_bits_RD_3;
    CData/*7:0*/ svsimTestbench__DOT__io_commit_bits_free_list_front_pointer;
    CData/*3:0*/ svsimTestbench__DOT__io_commit_bits_RAT_index;
    CData/*6:0*/ svsimTestbench__DOT__io_commit_bits_NEXT;
    CData/*6:0*/ svsimTestbench__DOT__io_commit_bits_TOS;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_bits_is_misprediction;
    CData/*1:0*/ svsimTestbench__DOT__io_commit_bits_fetch_packet_index;
    CData/*2:0*/ svsimTestbench__DOT__io_commit_bits_br_type;
    CData/*5:0*/ svsimTestbench__DOT__io_commit_bits_ROB_index;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_bits_T_NT;
    CData/*0:0*/ svsimTestbench__DOT__io_commit_valid;
    CData/*0:0*/ svsimTestbench__DOT__io_renamed_valid_0;
    CData/*0:0*/ svsimTestbench__DOT__io_renamed_valid_1;
    CData/*0:0*/ svsimTestbench__DOT__io_renamed_valid_2;
    CData/*0:0*/ svsimTestbench__DOT__io_renamed_valid_3;
    CData/*0:0*/ svsimTestbench__DOT__io_rename_valid_0;
    CData/*0:0*/ svsimTestbench__DOT__io_rename_valid_1;
    CData/*0:0*/ svsimTestbench__DOT__io_rename_valid_2;
    CData/*0:0*/ svsimTestbench__DOT__io_rename_valid_3;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__flush;
    CData/*6:0*/ svsimTestbench__DOT__dut__DOT__front_pointer;
    CData/*6:0*/ svsimTestbench__DOT__dut__DOT__back_pointer;
    CData/*1:0*/ svsimTestbench__DOT__dut__DOT___front_pointer_T_1;
    CData/*2:0*/ svsimTestbench__DOT__dut__DOT___GEN_4;
    CData/*6:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0;
    CData/*0:0*/ __Vdpi_export_trigger;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ svsimTestbench__DOT__io_commit_bits_GHR;
    SData/*8:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1;
    SData/*8:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2;
    SData/*8:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3;
    SData/*8:0*/ svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4;
    IData/*31:0*/ svsimTestbench__DOT__io_commit_bits_expected_PC;
    IData/*31:0*/ svsimTestbench__DOT__io_commit_bits_fetch_PC;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VsvsimTestbench__Syms* const vlSymsp;

    // CONSTRUCTORS
    VsvsimTestbench___024root(VsvsimTestbench__Syms* symsp, const char* v__name);
    ~VsvsimTestbench___024root();
    VL_UNCOPYABLE(VsvsimTestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

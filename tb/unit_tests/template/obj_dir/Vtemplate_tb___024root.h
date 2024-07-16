// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtemplate_tb.h for the primary calling header

#ifndef VERILATED_VTEMPLATE_TB___024ROOT_H_
#define VERILATED_VTEMPLATE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtemplate_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtemplate_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ free_list_tb__DOT__clock;
    CData/*0:0*/ __Vdlyvset__free_list_tb__DOT__clock__v0;
    CData/*0:0*/ __Vdlyvset__free_list_tb__DOT__clock__v1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__free_list_tb__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb543aebf__0;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtemplate_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtemplate_tb___024root(Vtemplate_tb__Syms* symsp, const char* v__name);
    ~Vtemplate_tb___024root();
    VL_UNCOPYABLE(Vtemplate_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_v2.h for the primary calling header

#ifndef VERILATED_VTOP_V2_QUEUE4_FU_OUTPUT_H_
#define VERILATED_VTOP_V2_QUEUE4_FU_OUTPUT_H_  // guard

#include "verilated.h"


class Vtop_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_v2_Queue4_FU_output final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_enq_ready,0,0);
    VL_IN8(io_enq_valid,0,0);
    VL_IN8(io_deq_ready,0,0);
    VL_OUT8(io_deq_valid,0,0);
    VL_OUT8(__PVT__io_count,2,0);
    VL_IN8(io_flush,0,0);
    CData/*1:0*/ __PVT__enq_ptr_value;
    CData/*1:0*/ __PVT__deq_ptr_value;
    CData/*0:0*/ __PVT__maybe_full;
    CData/*0:0*/ __PVT__ptr_match;
    CData/*0:0*/ __PVT__empty;
    CData/*0:0*/ __PVT__full;
    CData/*0:0*/ __PVT__do_enq;
    CData/*0:0*/ __PVT__unnamedblk1__DOT__do_deq;
    VlWide<6>/*191:0*/ __Vcellinp__ram_ext__W0_data;
    VL_INW(io_enq_bits,191,0,6);
    VL_OUTW(io_deq_bits,191,0,6);
    VlUnpacked<VlWide<6>/*191:0*/, 4> __PVT__ram_ext__DOT__Memory;

    // INTERNAL VARIABLES
    Vtop_v2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_v2_Queue4_FU_output(Vtop_v2__Syms* symsp, const char* v__name);
    ~Vtop_v2_Queue4_FU_output();
    VL_UNCOPYABLE(Vtop_v2_Queue4_FU_output);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

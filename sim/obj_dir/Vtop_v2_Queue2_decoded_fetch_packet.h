// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_v2.h for the primary calling header

#ifndef VERILATED_VTOP_V2_QUEUE2_DECODED_FETCH_PACKET_H_
#define VERILATED_VTOP_V2_QUEUE2_DECODED_FETCH_PACKET_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_v2_Queue2_decoded_fetch_packet final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(__PVT__io_enq_ready,0,0);
    VL_IN8(io_enq_valid,0,0);
    VL_IN8(io_deq_ready,0,0);
    VL_OUT8(io_deq_valid,0,0);
    VL_OUT8(__PVT__io_count,1,0);
    VL_IN8(io_flush,0,0);
    CData/*0:0*/ __PVT__wrap;
    CData/*0:0*/ __PVT__wrap_1;
    CData/*0:0*/ __PVT__maybe_full;
    CData/*0:0*/ __PVT__ptr_match;
    CData/*0:0*/ __PVT__empty;
    CData/*0:0*/ __PVT__do_enq;
    CData/*0:0*/ __PVT__unnamedblk1__DOT__do_deq;
    VlWide<14>/*433:0*/ __Vcellinp__ram_ext__W0_data;
    VL_INW(io_enq_bits,433,0,14);
    VL_OUTW(io_deq_bits,433,0,14);
    VlUnpacked<VlWide<14>/*433:0*/, 2> __PVT__ram_ext__DOT__Memory;

    // INTERNAL VARIABLES
    Vtop_v2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_v2_Queue2_decoded_fetch_packet(Vtop_v2__Syms* symsp, const char* v__name);
    ~Vtop_v2_Queue2_decoded_fetch_packet();
    VL_UNCOPYABLE(Vtop_v2_Queue2_decoded_fetch_packet);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

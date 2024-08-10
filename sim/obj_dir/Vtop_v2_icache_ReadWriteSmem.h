// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_v2.h for the primary calling header

#ifndef VERILATED_VTOP_V2_ICACHE_READWRITESMEM_H_
#define VERILATED_VTOP_V2_ICACHE_READWRITESMEM_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_v2_icache_ReadWriteSmem final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(io_wr_en,0,0);
    VL_IN8(io_addr,5,0);
    CData/*0:0*/ __PVT__mem_ext__DOT___R0_en_d0;
    CData/*5:0*/ __PVT__mem_ext__DOT___R0_addr_d0;
    VlWide<9>/*277:0*/ __PVT___mem_ext_R0_data;
    VL_INW(io_data_in,277,0,9);
    VL_OUTW(io_data_out,277,0,9);
    VlUnpacked<VlWide<9>/*277:0*/, 64> __PVT__mem_ext__DOT__Memory;

    // INTERNAL VARIABLES
    Vtop_v2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_v2_icache_ReadWriteSmem(Vtop_v2__Syms* symsp, const char* v__name);
    ~Vtop_v2_icache_ReadWriteSmem();
    VL_UNCOPYABLE(Vtop_v2_icache_ReadWriteSmem);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

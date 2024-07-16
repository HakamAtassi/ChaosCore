// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtemplate_tb.h for the primary calling header

#ifndef VERILATED_VTEMPLATE_TB___024UNIT_H_
#define VERILATED_VTEMPLATE_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtemplate_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtemplate_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtemplate_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtemplate_tb___024unit(Vtemplate_tb__Syms* symsp, const char* v__name);
    ~Vtemplate_tb___024unit();
    VL_UNCOPYABLE(Vtemplate_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

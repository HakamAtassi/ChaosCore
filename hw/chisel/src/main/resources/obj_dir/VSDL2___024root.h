// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSDL2.h for the primary calling header

#ifndef VERILATED_VSDL2___024ROOT_H_
#define VERILATED_VSDL2___024ROOT_H_  // guard

#include "verilated.h"


class VSDL2__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSDL2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(input_ready,0,0);
    VL_IN8(input_valid,0,0);
    VL_IN8(operation,0,0);
    VL_IN8(dump,0,0);
    CData/*0:0*/ __VactContinue;
    VL_IN16(address,15,0);
    VL_IN(data,23,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSDL2__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSDL2___024root(VSDL2__Syms* symsp, const char* v__name);
    ~VSDL2___024root();
    VL_UNCOPYABLE(VSDL2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

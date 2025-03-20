// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSDL2.h for the primary calling header

#include "VSDL2__pch.h"
#include "VSDL2__Syms.h"
#include "VSDL2___024root.h"

void VSDL2___024root___ctor_var_reset(VSDL2___024root* vlSelf);

VSDL2___024root::VSDL2___024root(VSDL2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VSDL2___024root___ctor_var_reset(this);
}

void VSDL2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VSDL2___024root::~VSDL2___024root() {
}

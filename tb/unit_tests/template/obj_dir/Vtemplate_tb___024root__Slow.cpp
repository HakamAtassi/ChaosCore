// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtemplate_tb.h for the primary calling header

#include "Vtemplate_tb__pch.h"
#include "Vtemplate_tb__Syms.h"
#include "Vtemplate_tb___024root.h"

void Vtemplate_tb___024root___ctor_var_reset(Vtemplate_tb___024root* vlSelf);

Vtemplate_tb___024root::Vtemplate_tb___024root(Vtemplate_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtemplate_tb___024root___ctor_var_reset(this);
}

void Vtemplate_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtemplate_tb___024root::~Vtemplate_tb___024root() {
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtemplate_tb.h for the primary calling header

#include "Vtemplate_tb__pch.h"
#include "Vtemplate_tb__Syms.h"
#include "Vtemplate_tb___024unit.h"

void Vtemplate_tb___024unit___ctor_var_reset(Vtemplate_tb___024unit* vlSelf);

Vtemplate_tb___024unit::Vtemplate_tb___024unit(Vtemplate_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtemplate_tb___024unit___ctor_var_reset(this);
}

void Vtemplate_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtemplate_tb___024unit::~Vtemplate_tb___024unit() {
}

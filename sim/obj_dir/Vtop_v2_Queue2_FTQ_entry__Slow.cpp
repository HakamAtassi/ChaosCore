// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2_Queue2_FTQ_entry.h"
#include "Vtop_v2__Syms.h"

void Vtop_v2_Queue2_FTQ_entry___ctor_var_reset(Vtop_v2_Queue2_FTQ_entry* vlSelf);

Vtop_v2_Queue2_FTQ_entry::Vtop_v2_Queue2_FTQ_entry(Vtop_v2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_v2_Queue2_FTQ_entry___ctor_var_reset(this);
}

void Vtop_v2_Queue2_FTQ_entry::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_v2_Queue2_FTQ_entry::~Vtop_v2_Queue2_FTQ_entry() {
}

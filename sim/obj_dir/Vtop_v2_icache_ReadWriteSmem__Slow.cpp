// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2__Syms.h"
#include "Vtop_v2_icache_ReadWriteSmem.h"

void Vtop_v2_icache_ReadWriteSmem___ctor_var_reset(Vtop_v2_icache_ReadWriteSmem* vlSelf);

Vtop_v2_icache_ReadWriteSmem::Vtop_v2_icache_ReadWriteSmem(Vtop_v2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_v2_icache_ReadWriteSmem___ctor_var_reset(this);
}

void Vtop_v2_icache_ReadWriteSmem::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_v2_icache_ReadWriteSmem::~Vtop_v2_icache_ReadWriteSmem() {
}

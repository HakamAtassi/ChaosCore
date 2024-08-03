// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_master_slave_tb.h for the primary calling header

#include "Vaxi_master_slave_tb__pch.h"
#include "Vaxi_master_slave_tb__Syms.h"
#include "Vaxi_master_slave_tb___024root.h"

void Vaxi_master_slave_tb___024root___ctor_var_reset(Vaxi_master_slave_tb___024root* vlSelf);

Vaxi_master_slave_tb___024root::Vaxi_master_slave_tb___024root(Vaxi_master_slave_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vaxi_master_slave_tb___024root___ctor_var_reset(this);
}

void Vaxi_master_slave_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vaxi_master_slave_tb___024root::~Vaxi_master_slave_tb___024root() {
}

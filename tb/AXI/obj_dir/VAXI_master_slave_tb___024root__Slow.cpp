// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAXI_master_slave_tb.h for the primary calling header

#include "VAXI_master_slave_tb__pch.h"
#include "VAXI_master_slave_tb__Syms.h"
#include "VAXI_master_slave_tb___024root.h"

void VAXI_master_slave_tb___024root___ctor_var_reset(VAXI_master_slave_tb___024root* vlSelf);

VAXI_master_slave_tb___024root::VAXI_master_slave_tb___024root(VAXI_master_slave_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VAXI_master_slave_tb___024root___ctor_var_reset(this);
}

void VAXI_master_slave_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VAXI_master_slave_tb___024root::~VAXI_master_slave_tb___024root() {
}

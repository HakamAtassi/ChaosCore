// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VAXI_master_slave_tb__pch.h"
#include "VAXI_master_slave_tb.h"
#include "VAXI_master_slave_tb___024root.h"

// FUNCTIONS
VAXI_master_slave_tb__Syms::~VAXI_master_slave_tb__Syms()
{
}

VAXI_master_slave_tb__Syms::VAXI_master_slave_tb__Syms(VerilatedContext* contextp, const char* namep, VAXI_master_slave_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}

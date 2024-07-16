// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtemplate_tb__pch.h"
#include "Vtemplate_tb.h"
#include "Vtemplate_tb___024root.h"
#include "Vtemplate_tb___024unit.h"

// FUNCTIONS
Vtemplate_tb__Syms::~Vtemplate_tb__Syms()
{
}

Vtemplate_tb__Syms::Vtemplate_tb__Syms(VerilatedContext* contextp, const char* namep, Vtemplate_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(15);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-10);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}

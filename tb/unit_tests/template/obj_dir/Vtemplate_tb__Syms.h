// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTEMPLATE_TB__SYMS_H_
#define VERILATED_VTEMPLATE_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtemplate_tb.h"

// INCLUDE MODULE CLASSES
#include "Vtemplate_tb___024root.h"
#include "Vtemplate_tb___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtemplate_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtemplate_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtemplate_tb___024root         TOP;

    // CONSTRUCTORS
    Vtemplate_tb__Syms(VerilatedContext* contextp, const char* namep, Vtemplate_tb* modelp);
    ~Vtemplate_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard

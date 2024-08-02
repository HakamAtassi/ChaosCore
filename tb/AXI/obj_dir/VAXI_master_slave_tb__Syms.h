// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VAXI_MASTER_SLAVE_TB__SYMS_H_
#define VERILATED_VAXI_MASTER_SLAVE_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VAXI_master_slave_tb.h"

// INCLUDE MODULE CLASSES
#include "VAXI_master_slave_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VAXI_master_slave_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VAXI_master_slave_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VAXI_master_slave_tb___024root TOP;

    // CONSTRUCTORS
    VAXI_master_slave_tb__Syms(VerilatedContext* contextp, const char* namep, VAXI_master_slave_tb* modelp);
    ~VAXI_master_slave_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSVSIMTESTBENCH__SYMS_H_
#define VERILATED_VSVSIMTESTBENCH__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "VsvsimTestbench.h"

// INCLUDE MODULE CLASSES
#include "VsvsimTestbench___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VsvsimTestbench__Vcb_getBitWidth_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_active_checkpoint_value_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_checkpoints_empty_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_checkpoints_full_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_create_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_restore_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_restore_checkpoint_value_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBits_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_clock);
using VsvsimTestbench__Vcb_getBits_io_RAT_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_0);
using VsvsimTestbench__Vcb_getBits_io_RAT_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_1);
using VsvsimTestbench__Vcb_getBits_io_RAT_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_2);
using VsvsimTestbench__Vcb_getBits_io_RAT_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_3);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS1_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_0);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS1_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_1);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS1_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_2);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS1_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_3);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS2_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_0);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS2_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_1);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS2_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_2);
using VsvsimTestbench__Vcb_getBits_io_RAT_RS2_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_3);
using VsvsimTestbench__Vcb_getBits_io_active_checkpoint_value_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_active_checkpoint_value);
using VsvsimTestbench__Vcb_getBits_io_checkpoints_empty_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_checkpoints_empty);
using VsvsimTestbench__Vcb_getBits_io_checkpoints_full_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_checkpoints_full);
using VsvsimTestbench__Vcb_getBits_io_create_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_create_checkpoint);
using VsvsimTestbench__Vcb_getBits_io_free_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_checkpoint);
using VsvsimTestbench__Vcb_getBits_io_free_list_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_0);
using VsvsimTestbench__Vcb_getBits_io_free_list_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_1);
using VsvsimTestbench__Vcb_getBits_io_free_list_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_2);
using VsvsimTestbench__Vcb_getBits_io_free_list_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_3);
using VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_0);
using VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_1);
using VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_2);
using VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_3);
using VsvsimTestbench__Vcb_getBits_io_instruction_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_0);
using VsvsimTestbench__Vcb_getBits_io_instruction_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_1);
using VsvsimTestbench__Vcb_getBits_io_instruction_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_2);
using VsvsimTestbench__Vcb_getBits_io_instruction_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_3);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS1_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_0);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS1_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_1);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS1_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_2);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS1_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_3);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS2_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_0);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS2_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_1);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS2_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_2);
using VsvsimTestbench__Vcb_getBits_io_instruction_RS2_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_3);
using VsvsimTestbench__Vcb_getBits_io_restore_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_restore_checkpoint);
using VsvsimTestbench__Vcb_getBits_io_restore_checkpoint_value_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_restore_checkpoint_value);
using VsvsimTestbench__Vcb_getBits_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_reset);
using VsvsimTestbench__Vcb_setBits_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_clock);
using VsvsimTestbench__Vcb_setBits_io_create_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_create_checkpoint);
using VsvsimTestbench__Vcb_setBits_io_free_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_checkpoint);
using VsvsimTestbench__Vcb_setBits_io_free_list_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_0);
using VsvsimTestbench__Vcb_setBits_io_free_list_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_1);
using VsvsimTestbench__Vcb_setBits_io_free_list_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_2);
using VsvsimTestbench__Vcb_setBits_io_free_list_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_3);
using VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_0);
using VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_1);
using VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_2);
using VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_3);
using VsvsimTestbench__Vcb_setBits_io_instruction_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_0);
using VsvsimTestbench__Vcb_setBits_io_instruction_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_1);
using VsvsimTestbench__Vcb_setBits_io_instruction_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_2);
using VsvsimTestbench__Vcb_setBits_io_instruction_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_3);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS1_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_0);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS1_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_1);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS1_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_2);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS1_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_3);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS2_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_0);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS2_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_1);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS2_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_2);
using VsvsimTestbench__Vcb_setBits_io_instruction_RS2_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_3);
using VsvsimTestbench__Vcb_setBits_io_restore_checkpoint_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_restore_checkpoint);
using VsvsimTestbench__Vcb_setBits_io_restore_checkpoint_value_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_restore_checkpoint_value);
using VsvsimTestbench__Vcb_setBits_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_reset);
using VsvsimTestbench__Vcb_simulation_disableTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp);
using VsvsimTestbench__Vcb_simulation_enableTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp);
using VsvsimTestbench__Vcb_simulation_initializeTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, std::string traceFilePath);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VsvsimTestbench__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VsvsimTestbench* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VsvsimTestbench___024root      TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_svsimTestbench;

    // CONSTRUCTORS
    VsvsimTestbench__Syms(VerilatedContext* contextp, const char* namep, VsvsimTestbench* modelp);
    ~VsvsimTestbench__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard

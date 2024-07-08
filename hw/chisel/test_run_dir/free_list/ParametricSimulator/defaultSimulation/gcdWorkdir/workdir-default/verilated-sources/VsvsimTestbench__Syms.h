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
using VsvsimTestbench__Vcb_getBitWidth_io_can_allocate_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_can_reallocate_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_GHR_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_NEXT_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RAT_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_ROB_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_TOS_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_T_NT_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_br_type_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_expected_PC_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_fetch_PC_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_fetch_packet_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_free_list_front_pointer_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_is_misprediction_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_commit_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_free_list_front_pointer_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidth_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBits_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_clock);
using VsvsimTestbench__Vcb_getBits_io_can_allocate_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_can_allocate);
using VsvsimTestbench__Vcb_getBits_io_can_reallocate_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_can_reallocate);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_GHR_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*15:0*/ &value_io_commit_bits_GHR);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_NEXT_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_NEXT);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RAT_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_commit_bits_RAT_index);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_0);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_1);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_2);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_3);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_0);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_1);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_2);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_3);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_ROB_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*5:0*/ &value_io_commit_bits_ROB_index);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_TOS_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_TOS);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_T_NT_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_T_NT);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_br_type_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_commit_bits_br_type);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_expected_PC_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value_io_commit_bits_expected_PC);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_fetch_PC_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value_io_commit_bits_fetch_PC);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_fetch_packet_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*1:0*/ &value_io_commit_bits_fetch_packet_index);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_free_list_front_pointer_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*7:0*/ &value_io_commit_bits_free_list_front_pointer);
using VsvsimTestbench__Vcb_getBits_io_commit_bits_is_misprediction_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_is_misprediction);
using VsvsimTestbench__Vcb_getBits_io_commit_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_valid);
using VsvsimTestbench__Vcb_getBits_io_free_list_front_pointer_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_front_pointer);
using VsvsimTestbench__Vcb_getBits_io_rename_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_0);
using VsvsimTestbench__Vcb_getBits_io_rename_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_1);
using VsvsimTestbench__Vcb_getBits_io_rename_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_2);
using VsvsimTestbench__Vcb_getBits_io_rename_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_3);
using VsvsimTestbench__Vcb_getBits_io_renamed_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_0);
using VsvsimTestbench__Vcb_getBits_io_renamed_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_1);
using VsvsimTestbench__Vcb_getBits_io_renamed_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_2);
using VsvsimTestbench__Vcb_getBits_io_renamed_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_3);
using VsvsimTestbench__Vcb_getBits_io_renamed_values_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_0);
using VsvsimTestbench__Vcb_getBits_io_renamed_values_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_1);
using VsvsimTestbench__Vcb_getBits_io_renamed_values_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_2);
using VsvsimTestbench__Vcb_getBits_io_renamed_values_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_3);
using VsvsimTestbench__Vcb_getBits_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_reset);
using VsvsimTestbench__Vcb_setBits_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_clock);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_GHR_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, SData/*15:0*/ value_io_commit_bits_GHR);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_NEXT_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_NEXT);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RAT_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_commit_bits_RAT_index);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_0);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_1);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_2);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_3);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_0);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_1);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_2);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_3);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_ROB_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*5:0*/ value_io_commit_bits_ROB_index);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_TOS_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_TOS);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_T_NT_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_T_NT);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_br_type_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_commit_bits_br_type);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_expected_PC_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ value_io_commit_bits_expected_PC);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_fetch_PC_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ value_io_commit_bits_fetch_PC);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_fetch_packet_index_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*1:0*/ value_io_commit_bits_fetch_packet_index);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_free_list_front_pointer_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*7:0*/ value_io_commit_bits_free_list_front_pointer);
using VsvsimTestbench__Vcb_setBits_io_commit_bits_is_misprediction_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_is_misprediction);
using VsvsimTestbench__Vcb_setBits_io_commit_valid_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_valid);
using VsvsimTestbench__Vcb_setBits_io_rename_valid_0_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_0);
using VsvsimTestbench__Vcb_setBits_io_rename_valid_1_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_1);
using VsvsimTestbench__Vcb_setBits_io_rename_valid_2_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_2);
using VsvsimTestbench__Vcb_setBits_io_rename_valid_3_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_3);
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

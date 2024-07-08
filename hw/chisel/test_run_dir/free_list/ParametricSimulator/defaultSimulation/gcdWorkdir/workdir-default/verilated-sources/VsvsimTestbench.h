// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSVSIMTESTBENCH_H_
#define VERILATED_VSVSIMTESTBENCH_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class VsvsimTestbench__Syms;
class VsvsimTestbench___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VsvsimTestbench__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VsvsimTestbench___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VsvsimTestbench(VerilatedContext* contextp, const char* name = "TOP");
    explicit VsvsimTestbench(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VsvsimTestbench();
  private:
    VL_UNCOPYABLE(VsvsimTestbench);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    /// DPI Export functions
    static void getBitWidth_clock(int* value);
    static void getBitWidth_io_can_allocate(int* value);
    static void getBitWidth_io_can_reallocate(int* value);
    static void getBitWidth_io_commit_bits_GHR(int* value);
    static void getBitWidth_io_commit_bits_NEXT(int* value);
    static void getBitWidth_io_commit_bits_RAT_index(int* value);
    static void getBitWidth_io_commit_bits_RD_0(int* value);
    static void getBitWidth_io_commit_bits_RD_1(int* value);
    static void getBitWidth_io_commit_bits_RD_2(int* value);
    static void getBitWidth_io_commit_bits_RD_3(int* value);
    static void getBitWidth_io_commit_bits_RD_valid_0(int* value);
    static void getBitWidth_io_commit_bits_RD_valid_1(int* value);
    static void getBitWidth_io_commit_bits_RD_valid_2(int* value);
    static void getBitWidth_io_commit_bits_RD_valid_3(int* value);
    static void getBitWidth_io_commit_bits_ROB_index(int* value);
    static void getBitWidth_io_commit_bits_TOS(int* value);
    static void getBitWidth_io_commit_bits_T_NT(int* value);
    static void getBitWidth_io_commit_bits_br_type(int* value);
    static void getBitWidth_io_commit_bits_expected_PC(int* value);
    static void getBitWidth_io_commit_bits_fetch_PC(int* value);
    static void getBitWidth_io_commit_bits_fetch_packet_index(int* value);
    static void getBitWidth_io_commit_bits_free_list_front_pointer(int* value);
    static void getBitWidth_io_commit_bits_is_misprediction(int* value);
    static void getBitWidth_io_commit_valid(int* value);
    static void getBitWidth_io_free_list_front_pointer(int* value);
    static void getBitWidth_io_rename_valid_0(int* value);
    static void getBitWidth_io_rename_valid_1(int* value);
    static void getBitWidth_io_rename_valid_2(int* value);
    static void getBitWidth_io_rename_valid_3(int* value);
    static void getBitWidth_io_renamed_valid_0(int* value);
    static void getBitWidth_io_renamed_valid_1(int* value);
    static void getBitWidth_io_renamed_valid_2(int* value);
    static void getBitWidth_io_renamed_valid_3(int* value);
    static void getBitWidth_io_renamed_values_0(int* value);
    static void getBitWidth_io_renamed_values_1(int* value);
    static void getBitWidth_io_renamed_values_2(int* value);
    static void getBitWidth_io_renamed_values_3(int* value);
    static void getBitWidth_reset(int* value);
    static void getBits_clock(svBitVecVal* value_clock);
    static void getBits_io_can_allocate(svBitVecVal* value_io_can_allocate);
    static void getBits_io_can_reallocate(svBitVecVal* value_io_can_reallocate);
    static void getBits_io_commit_bits_GHR(svBitVecVal* value_io_commit_bits_GHR);
    static void getBits_io_commit_bits_NEXT(svBitVecVal* value_io_commit_bits_NEXT);
    static void getBits_io_commit_bits_RAT_index(svBitVecVal* value_io_commit_bits_RAT_index);
    static void getBits_io_commit_bits_RD_0(svBitVecVal* value_io_commit_bits_RD_0);
    static void getBits_io_commit_bits_RD_1(svBitVecVal* value_io_commit_bits_RD_1);
    static void getBits_io_commit_bits_RD_2(svBitVecVal* value_io_commit_bits_RD_2);
    static void getBits_io_commit_bits_RD_3(svBitVecVal* value_io_commit_bits_RD_3);
    static void getBits_io_commit_bits_RD_valid_0(svBitVecVal* value_io_commit_bits_RD_valid_0);
    static void getBits_io_commit_bits_RD_valid_1(svBitVecVal* value_io_commit_bits_RD_valid_1);
    static void getBits_io_commit_bits_RD_valid_2(svBitVecVal* value_io_commit_bits_RD_valid_2);
    static void getBits_io_commit_bits_RD_valid_3(svBitVecVal* value_io_commit_bits_RD_valid_3);
    static void getBits_io_commit_bits_ROB_index(svBitVecVal* value_io_commit_bits_ROB_index);
    static void getBits_io_commit_bits_TOS(svBitVecVal* value_io_commit_bits_TOS);
    static void getBits_io_commit_bits_T_NT(svBitVecVal* value_io_commit_bits_T_NT);
    static void getBits_io_commit_bits_br_type(svBitVecVal* value_io_commit_bits_br_type);
    static void getBits_io_commit_bits_expected_PC(svBitVecVal* value_io_commit_bits_expected_PC);
    static void getBits_io_commit_bits_fetch_PC(svBitVecVal* value_io_commit_bits_fetch_PC);
    static void getBits_io_commit_bits_fetch_packet_index(svBitVecVal* value_io_commit_bits_fetch_packet_index);
    static void getBits_io_commit_bits_free_list_front_pointer(svBitVecVal* value_io_commit_bits_free_list_front_pointer);
    static void getBits_io_commit_bits_is_misprediction(svBitVecVal* value_io_commit_bits_is_misprediction);
    static void getBits_io_commit_valid(svBitVecVal* value_io_commit_valid);
    static void getBits_io_free_list_front_pointer(svBitVecVal* value_io_free_list_front_pointer);
    static void getBits_io_rename_valid_0(svBitVecVal* value_io_rename_valid_0);
    static void getBits_io_rename_valid_1(svBitVecVal* value_io_rename_valid_1);
    static void getBits_io_rename_valid_2(svBitVecVal* value_io_rename_valid_2);
    static void getBits_io_rename_valid_3(svBitVecVal* value_io_rename_valid_3);
    static void getBits_io_renamed_valid_0(svBitVecVal* value_io_renamed_valid_0);
    static void getBits_io_renamed_valid_1(svBitVecVal* value_io_renamed_valid_1);
    static void getBits_io_renamed_valid_2(svBitVecVal* value_io_renamed_valid_2);
    static void getBits_io_renamed_valid_3(svBitVecVal* value_io_renamed_valid_3);
    static void getBits_io_renamed_values_0(svBitVecVal* value_io_renamed_values_0);
    static void getBits_io_renamed_values_1(svBitVecVal* value_io_renamed_values_1);
    static void getBits_io_renamed_values_2(svBitVecVal* value_io_renamed_values_2);
    static void getBits_io_renamed_values_3(svBitVecVal* value_io_renamed_values_3);
    static void getBits_reset(svBitVecVal* value_reset);
    static void setBits_clock(const svBitVecVal* value_clock);
    static void setBits_io_commit_bits_GHR(const svBitVecVal* value_io_commit_bits_GHR);
    static void setBits_io_commit_bits_NEXT(const svBitVecVal* value_io_commit_bits_NEXT);
    static void setBits_io_commit_bits_RAT_index(const svBitVecVal* value_io_commit_bits_RAT_index);
    static void setBits_io_commit_bits_RD_0(const svBitVecVal* value_io_commit_bits_RD_0);
    static void setBits_io_commit_bits_RD_1(const svBitVecVal* value_io_commit_bits_RD_1);
    static void setBits_io_commit_bits_RD_2(const svBitVecVal* value_io_commit_bits_RD_2);
    static void setBits_io_commit_bits_RD_3(const svBitVecVal* value_io_commit_bits_RD_3);
    static void setBits_io_commit_bits_RD_valid_0(const svBitVecVal* value_io_commit_bits_RD_valid_0);
    static void setBits_io_commit_bits_RD_valid_1(const svBitVecVal* value_io_commit_bits_RD_valid_1);
    static void setBits_io_commit_bits_RD_valid_2(const svBitVecVal* value_io_commit_bits_RD_valid_2);
    static void setBits_io_commit_bits_RD_valid_3(const svBitVecVal* value_io_commit_bits_RD_valid_3);
    static void setBits_io_commit_bits_ROB_index(const svBitVecVal* value_io_commit_bits_ROB_index);
    static void setBits_io_commit_bits_TOS(const svBitVecVal* value_io_commit_bits_TOS);
    static void setBits_io_commit_bits_T_NT(const svBitVecVal* value_io_commit_bits_T_NT);
    static void setBits_io_commit_bits_br_type(const svBitVecVal* value_io_commit_bits_br_type);
    static void setBits_io_commit_bits_expected_PC(const svBitVecVal* value_io_commit_bits_expected_PC);
    static void setBits_io_commit_bits_fetch_PC(const svBitVecVal* value_io_commit_bits_fetch_PC);
    static void setBits_io_commit_bits_fetch_packet_index(const svBitVecVal* value_io_commit_bits_fetch_packet_index);
    static void setBits_io_commit_bits_free_list_front_pointer(const svBitVecVal* value_io_commit_bits_free_list_front_pointer);
    static void setBits_io_commit_bits_is_misprediction(const svBitVecVal* value_io_commit_bits_is_misprediction);
    static void setBits_io_commit_valid(const svBitVecVal* value_io_commit_valid);
    static void setBits_io_rename_valid_0(const svBitVecVal* value_io_rename_valid_0);
    static void setBits_io_rename_valid_1(const svBitVecVal* value_io_rename_valid_1);
    static void setBits_io_rename_valid_2(const svBitVecVal* value_io_rename_valid_2);
    static void setBits_io_rename_valid_3(const svBitVecVal* value_io_rename_valid_3);
    static void setBits_reset(const svBitVecVal* value_reset);
    static void simulation_disableTrace();
    static void simulation_enableTrace();
    static void simulation_initializeTrace(const char* traceFilePath);

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard

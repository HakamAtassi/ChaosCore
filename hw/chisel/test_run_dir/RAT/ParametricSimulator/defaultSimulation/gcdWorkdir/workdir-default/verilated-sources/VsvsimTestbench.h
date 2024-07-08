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
    static void getBitWidth_io_RAT_RD_0(int* value);
    static void getBitWidth_io_RAT_RD_1(int* value);
    static void getBitWidth_io_RAT_RD_2(int* value);
    static void getBitWidth_io_RAT_RD_3(int* value);
    static void getBitWidth_io_RAT_RS1_0(int* value);
    static void getBitWidth_io_RAT_RS1_1(int* value);
    static void getBitWidth_io_RAT_RS1_2(int* value);
    static void getBitWidth_io_RAT_RS1_3(int* value);
    static void getBitWidth_io_RAT_RS2_0(int* value);
    static void getBitWidth_io_RAT_RS2_1(int* value);
    static void getBitWidth_io_RAT_RS2_2(int* value);
    static void getBitWidth_io_RAT_RS2_3(int* value);
    static void getBitWidth_io_active_checkpoint_value(int* value);
    static void getBitWidth_io_checkpoints_empty(int* value);
    static void getBitWidth_io_checkpoints_full(int* value);
    static void getBitWidth_io_create_checkpoint(int* value);
    static void getBitWidth_io_free_checkpoint(int* value);
    static void getBitWidth_io_free_list_RD_0(int* value);
    static void getBitWidth_io_free_list_RD_1(int* value);
    static void getBitWidth_io_free_list_RD_2(int* value);
    static void getBitWidth_io_free_list_RD_3(int* value);
    static void getBitWidth_io_free_list_wr_en_0(int* value);
    static void getBitWidth_io_free_list_wr_en_1(int* value);
    static void getBitWidth_io_free_list_wr_en_2(int* value);
    static void getBitWidth_io_free_list_wr_en_3(int* value);
    static void getBitWidth_io_instruction_RD_0(int* value);
    static void getBitWidth_io_instruction_RD_1(int* value);
    static void getBitWidth_io_instruction_RD_2(int* value);
    static void getBitWidth_io_instruction_RD_3(int* value);
    static void getBitWidth_io_instruction_RS1_0(int* value);
    static void getBitWidth_io_instruction_RS1_1(int* value);
    static void getBitWidth_io_instruction_RS1_2(int* value);
    static void getBitWidth_io_instruction_RS1_3(int* value);
    static void getBitWidth_io_instruction_RS2_0(int* value);
    static void getBitWidth_io_instruction_RS2_1(int* value);
    static void getBitWidth_io_instruction_RS2_2(int* value);
    static void getBitWidth_io_instruction_RS2_3(int* value);
    static void getBitWidth_io_restore_checkpoint(int* value);
    static void getBitWidth_io_restore_checkpoint_value(int* value);
    static void getBitWidth_reset(int* value);
    static void getBits_clock(svBitVecVal* value_clock);
    static void getBits_io_RAT_RD_0(svBitVecVal* value_io_RAT_RD_0);
    static void getBits_io_RAT_RD_1(svBitVecVal* value_io_RAT_RD_1);
    static void getBits_io_RAT_RD_2(svBitVecVal* value_io_RAT_RD_2);
    static void getBits_io_RAT_RD_3(svBitVecVal* value_io_RAT_RD_3);
    static void getBits_io_RAT_RS1_0(svBitVecVal* value_io_RAT_RS1_0);
    static void getBits_io_RAT_RS1_1(svBitVecVal* value_io_RAT_RS1_1);
    static void getBits_io_RAT_RS1_2(svBitVecVal* value_io_RAT_RS1_2);
    static void getBits_io_RAT_RS1_3(svBitVecVal* value_io_RAT_RS1_3);
    static void getBits_io_RAT_RS2_0(svBitVecVal* value_io_RAT_RS2_0);
    static void getBits_io_RAT_RS2_1(svBitVecVal* value_io_RAT_RS2_1);
    static void getBits_io_RAT_RS2_2(svBitVecVal* value_io_RAT_RS2_2);
    static void getBits_io_RAT_RS2_3(svBitVecVal* value_io_RAT_RS2_3);
    static void getBits_io_active_checkpoint_value(svBitVecVal* value_io_active_checkpoint_value);
    static void getBits_io_checkpoints_empty(svBitVecVal* value_io_checkpoints_empty);
    static void getBits_io_checkpoints_full(svBitVecVal* value_io_checkpoints_full);
    static void getBits_io_create_checkpoint(svBitVecVal* value_io_create_checkpoint);
    static void getBits_io_free_checkpoint(svBitVecVal* value_io_free_checkpoint);
    static void getBits_io_free_list_RD_0(svBitVecVal* value_io_free_list_RD_0);
    static void getBits_io_free_list_RD_1(svBitVecVal* value_io_free_list_RD_1);
    static void getBits_io_free_list_RD_2(svBitVecVal* value_io_free_list_RD_2);
    static void getBits_io_free_list_RD_3(svBitVecVal* value_io_free_list_RD_3);
    static void getBits_io_free_list_wr_en_0(svBitVecVal* value_io_free_list_wr_en_0);
    static void getBits_io_free_list_wr_en_1(svBitVecVal* value_io_free_list_wr_en_1);
    static void getBits_io_free_list_wr_en_2(svBitVecVal* value_io_free_list_wr_en_2);
    static void getBits_io_free_list_wr_en_3(svBitVecVal* value_io_free_list_wr_en_3);
    static void getBits_io_instruction_RD_0(svBitVecVal* value_io_instruction_RD_0);
    static void getBits_io_instruction_RD_1(svBitVecVal* value_io_instruction_RD_1);
    static void getBits_io_instruction_RD_2(svBitVecVal* value_io_instruction_RD_2);
    static void getBits_io_instruction_RD_3(svBitVecVal* value_io_instruction_RD_3);
    static void getBits_io_instruction_RS1_0(svBitVecVal* value_io_instruction_RS1_0);
    static void getBits_io_instruction_RS1_1(svBitVecVal* value_io_instruction_RS1_1);
    static void getBits_io_instruction_RS1_2(svBitVecVal* value_io_instruction_RS1_2);
    static void getBits_io_instruction_RS1_3(svBitVecVal* value_io_instruction_RS1_3);
    static void getBits_io_instruction_RS2_0(svBitVecVal* value_io_instruction_RS2_0);
    static void getBits_io_instruction_RS2_1(svBitVecVal* value_io_instruction_RS2_1);
    static void getBits_io_instruction_RS2_2(svBitVecVal* value_io_instruction_RS2_2);
    static void getBits_io_instruction_RS2_3(svBitVecVal* value_io_instruction_RS2_3);
    static void getBits_io_restore_checkpoint(svBitVecVal* value_io_restore_checkpoint);
    static void getBits_io_restore_checkpoint_value(svBitVecVal* value_io_restore_checkpoint_value);
    static void getBits_reset(svBitVecVal* value_reset);
    static void setBits_clock(const svBitVecVal* value_clock);
    static void setBits_io_create_checkpoint(const svBitVecVal* value_io_create_checkpoint);
    static void setBits_io_free_checkpoint(const svBitVecVal* value_io_free_checkpoint);
    static void setBits_io_free_list_RD_0(const svBitVecVal* value_io_free_list_RD_0);
    static void setBits_io_free_list_RD_1(const svBitVecVal* value_io_free_list_RD_1);
    static void setBits_io_free_list_RD_2(const svBitVecVal* value_io_free_list_RD_2);
    static void setBits_io_free_list_RD_3(const svBitVecVal* value_io_free_list_RD_3);
    static void setBits_io_free_list_wr_en_0(const svBitVecVal* value_io_free_list_wr_en_0);
    static void setBits_io_free_list_wr_en_1(const svBitVecVal* value_io_free_list_wr_en_1);
    static void setBits_io_free_list_wr_en_2(const svBitVecVal* value_io_free_list_wr_en_2);
    static void setBits_io_free_list_wr_en_3(const svBitVecVal* value_io_free_list_wr_en_3);
    static void setBits_io_instruction_RD_0(const svBitVecVal* value_io_instruction_RD_0);
    static void setBits_io_instruction_RD_1(const svBitVecVal* value_io_instruction_RD_1);
    static void setBits_io_instruction_RD_2(const svBitVecVal* value_io_instruction_RD_2);
    static void setBits_io_instruction_RD_3(const svBitVecVal* value_io_instruction_RD_3);
    static void setBits_io_instruction_RS1_0(const svBitVecVal* value_io_instruction_RS1_0);
    static void setBits_io_instruction_RS1_1(const svBitVecVal* value_io_instruction_RS1_1);
    static void setBits_io_instruction_RS1_2(const svBitVecVal* value_io_instruction_RS1_2);
    static void setBits_io_instruction_RS1_3(const svBitVecVal* value_io_instruction_RS1_3);
    static void setBits_io_instruction_RS2_0(const svBitVecVal* value_io_instruction_RS2_0);
    static void setBits_io_instruction_RS2_1(const svBitVecVal* value_io_instruction_RS2_1);
    static void setBits_io_instruction_RS2_2(const svBitVecVal* value_io_instruction_RS2_2);
    static void setBits_io_instruction_RS2_3(const svBitVecVal* value_io_instruction_RS2_3);
    static void setBits_io_restore_checkpoint(const svBitVecVal* value_io_restore_checkpoint);
    static void setBits_io_restore_checkpoint_value(const svBitVecVal* value_io_restore_checkpoint_value);
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

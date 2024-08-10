// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_V2_H_
#define VERILATED_VTOP_V2_H_  // guard

#include "verilated.h"

class Vtop_v2__Syms;
class Vtop_v2___024root;
class VerilatedVcdC;
class Vtop_v2_Queue2_FTQ_entry;
class Vtop_v2_Queue2_decoded_fetch_packet;
class Vtop_v2_Queue4_FU_output;
class Vtop_v2_icache_ReadWriteSmem;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtop_v2 VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop_v2__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtop_v2_Queue2_FTQ_entry* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q;
    Vtop_v2_Queue2_decoded_fetch_packet* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q;
    Vtop_v2_Queue2_FTQ_entry* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q;
    Vtop_v2_Queue2_FTQ_entry* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q;
    Vtop_v2_Queue2_decoded_fetch_packet* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q;
    Vtop_v2_Queue4_FU_output* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q;
    Vtop_v2_Queue4_FU_output* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q;
    Vtop_v2_icache_ReadWriteSmem* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0;
    Vtop_v2_icache_ReadWriteSmem* const __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop_v2___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop_v2(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop_v2(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop_v2();
  private:
    VL_UNCOPYABLE(Vtop_v2);  ///< Copying not allowed

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

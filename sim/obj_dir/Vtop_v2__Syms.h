// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_V2__SYMS_H_
#define VERILATED_VTOP_V2__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop_v2.h"

// INCLUDE MODULE CLASSES
#include "Vtop_v2___024root.h"
#include "Vtop_v2_icache_ReadWriteSmem.h"
#include "Vtop_v2_Queue2_decoded_fetch_packet.h"
#include "Vtop_v2_Queue4_FU_output.h"
#include "Vtop_v2_Queue2_FTQ_entry.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop_v2__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_v2* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop_v2___024root              TOP;
    Vtop_v2_Queue4_FU_output       TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q;
    Vtop_v2_Queue4_FU_output       TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q;
    Vtop_v2_Queue2_decoded_fetch_packet TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q;
    Vtop_v2_Queue2_FTQ_entry       TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q;
    Vtop_v2_Queue2_FTQ_entry       TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q;
    Vtop_v2_Queue2_FTQ_entry       TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q;
    Vtop_v2_Queue2_decoded_fetch_packet TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q;
    Vtop_v2_icache_ReadWriteSmem   TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0;
    Vtop_v2_icache_ReadWriteSmem   TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1;

    // SCOPE NAMES
    VerilatedScope __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_0;
    VerilatedScope __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_1;
    VerilatedScope __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_2;
    VerilatedScope __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_3;
    VerilatedScope __Vscope_top_v2__SOC__axi_interconnect__NOC__axi_interconnect_inst;

    // CONSTRUCTORS
    Vtop_v2__Syms(VerilatedContext* contextp, const char* namep, Vtop_v2* modelp);
    ~Vtop_v2__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard

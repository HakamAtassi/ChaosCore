// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop_v2__pch.h"
#include "Vtop_v2.h"
#include "Vtop_v2___024root.h"
#include "Vtop_v2_icache_ReadWriteSmem.h"
#include "Vtop_v2_Queue2_decoded_fetch_packet.h"
#include "Vtop_v2_Queue4_FU_output.h"
#include "Vtop_v2_Queue2_FTQ_entry.h"

// FUNCTIONS
Vtop_v2__Syms::~Vtop_v2__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vtop_v2__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtop_v2__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtop_v2__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vtop_v2__Syms::Vtop_v2__Syms(VerilatedContext* contextp, const char* namep, Vtop_v2* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.backend.MOB.FU_output_load_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.backend.MOB.FU_output_store_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.decoders.decoded_fetch_packet_out_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.decoders.predictions_out_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.instruction_fetch.predecoder.predictions_out_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.rename.predictions_out_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.rename.renamed_decoded_fetch_packet_Q")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.instruction_cache.data_memory_0")}
    , TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1{this, Verilated::catName(namep, "top_v2.SOC.ChaosCore_tile.instruction_cache.data_memory_1")}
{
        // Check resources
        Verilated::stackCheck(22290);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0 = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0;
    TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1 = &TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__Vconfigure(true);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__Vconfigure(false);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__Vconfigure(true);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__Vconfigure(true);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__Vconfigure(false);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__Vconfigure(false);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__Vconfigure(false);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0.__Vconfigure(true);
    TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1.__Vconfigure(false);
    // Setup scopes
    __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_0.configure(this, name(), "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.decoders.decoders_0", "decoders_0", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_1.configure(this, name(), "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.decoders.decoders_1", "decoders_1", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_2.configure(this, name(), "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.decoders.decoders_2", "decoders_2", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top_v2__SOC__ChaosCore_tile__ChaosCore__frontend__decoders__decoders_3.configure(this, name(), "top_v2.SOC.ChaosCore_tile.ChaosCore.frontend.decoders.decoders_3", "decoders_3", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top_v2__SOC__axi_interconnect__NOC__axi_interconnect_inst.configure(this, name(), "top_v2.SOC.axi_interconnect.NOC.axi_interconnect_inst", "axi_interconnect_inst", -9, VerilatedScope::SCOPE_OTHER);
}

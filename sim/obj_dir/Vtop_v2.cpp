// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_v2__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtop_v2::Vtop_v2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_v2__Syms(contextp(), _vcname__, this)}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0}
    , __PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1{vlSymsp->TOP.__PVT__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtop_v2::Vtop_v2(const char* _vcname__)
    : Vtop_v2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_v2::~Vtop_v2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_v2___024root___eval_debug_assertions(Vtop_v2___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_v2___024root___eval_static(Vtop_v2___024root* vlSelf);
void Vtop_v2___024root___eval_initial(Vtop_v2___024root* vlSelf);
void Vtop_v2___024root___eval_settle(Vtop_v2___024root* vlSelf);
void Vtop_v2___024root___eval(Vtop_v2___024root* vlSelf);

void Vtop_v2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_v2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_v2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_v2___024root___eval_static(&(vlSymsp->TOP));
        Vtop_v2___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_v2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_v2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtop_v2::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtop_v2::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtop_v2::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtop_v2::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtop_v2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_v2___024root___eval_final(Vtop_v2___024root* vlSelf);

VL_ATTR_COLD void Vtop_v2::final() {
    Vtop_v2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_v2::hierName() const { return vlSymsp->name(); }
const char* Vtop_v2::modelName() const { return "Vtop_v2"; }
unsigned Vtop_v2::threads() const { return 1; }
void Vtop_v2::prepareClone() const { contextp()->prepareClone(); }
void Vtop_v2::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtop_v2::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtop_v2___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtop_v2___024root__trace_init_top(Vtop_v2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_v2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_v2___024root*>(voidSelf);
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop_v2___024root__trace_decl_types(tracep);
    Vtop_v2___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop_v2___024root__trace_register(Vtop_v2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop_v2::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop_v2::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtop_v2___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}

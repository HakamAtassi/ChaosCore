// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VsvsimTestbench__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VsvsimTestbench::VsvsimTestbench(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VsvsimTestbench__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VsvsimTestbench::VsvsimTestbench(const char* _vcname__)
    : VsvsimTestbench(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VsvsimTestbench::~VsvsimTestbench() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VsvsimTestbench___024root___eval_debug_assertions(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
void VsvsimTestbench___024root___eval_static(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___eval_initial(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___eval_settle(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___eval(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VsvsimTestbench::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VsvsimTestbench___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VsvsimTestbench___024root___eval_static(&(vlSymsp->TOP));
        VsvsimTestbench___024root___eval_initial(&(vlSymsp->TOP));
        VsvsimTestbench___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VsvsimTestbench___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VsvsimTestbench::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step VsvsimTestbench::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool VsvsimTestbench::eventsPending() { return false; }

uint64_t VsvsimTestbench::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VsvsimTestbench::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VsvsimTestbench___024root___eval_final(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench::final() {
    VsvsimTestbench___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VsvsimTestbench::hierName() const { return vlSymsp->name(); }
const char* VsvsimTestbench::modelName() const { return "VsvsimTestbench"; }
unsigned VsvsimTestbench::threads() const { return 1; }
void VsvsimTestbench::prepareClone() const { contextp()->prepareClone(); }
void VsvsimTestbench::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VsvsimTestbench::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VsvsimTestbench___024root__trace_decl_types(VerilatedVcd* tracep);

void VsvsimTestbench___024root__trace_init_top(VsvsimTestbench___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VsvsimTestbench___024root__trace_decl_types(tracep);
    VsvsimTestbench___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VsvsimTestbench___024root__trace_register(VsvsimTestbench___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VsvsimTestbench::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VsvsimTestbench::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VsvsimTestbench___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAXI_master_slave_tb__pch.h"

//============================================================
// Constructors

VAXI_master_slave_tb::VAXI_master_slave_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VAXI_master_slave_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VAXI_master_slave_tb::VAXI_master_slave_tb(const char* _vcname__)
    : VAXI_master_slave_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VAXI_master_slave_tb::~VAXI_master_slave_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VAXI_master_slave_tb___024root___eval_debug_assertions(VAXI_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG
void VAXI_master_slave_tb___024root___eval_static(VAXI_master_slave_tb___024root* vlSelf);
void VAXI_master_slave_tb___024root___eval_initial(VAXI_master_slave_tb___024root* vlSelf);
void VAXI_master_slave_tb___024root___eval_settle(VAXI_master_slave_tb___024root* vlSelf);
void VAXI_master_slave_tb___024root___eval(VAXI_master_slave_tb___024root* vlSelf);

void VAXI_master_slave_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAXI_master_slave_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAXI_master_slave_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VAXI_master_slave_tb___024root___eval_static(&(vlSymsp->TOP));
        VAXI_master_slave_tb___024root___eval_initial(&(vlSymsp->TOP));
        VAXI_master_slave_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VAXI_master_slave_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VAXI_master_slave_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t VAXI_master_slave_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* VAXI_master_slave_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VAXI_master_slave_tb___024root___eval_final(VAXI_master_slave_tb___024root* vlSelf);

VL_ATTR_COLD void VAXI_master_slave_tb::final() {
    VAXI_master_slave_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VAXI_master_slave_tb::hierName() const { return vlSymsp->name(); }
const char* VAXI_master_slave_tb::modelName() const { return "VAXI_master_slave_tb"; }
unsigned VAXI_master_slave_tb::threads() const { return 1; }
void VAXI_master_slave_tb::prepareClone() const { contextp()->prepareClone(); }
void VAXI_master_slave_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void VAXI_master_slave_tb::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'VAXI_master_slave_tb::trace()' called on model that was Verilated without --trace option");
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtemplate_tb__pch.h"

//============================================================
// Constructors

Vtemplate_tb::Vtemplate_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtemplate_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtemplate_tb::Vtemplate_tb(const char* _vcname__)
    : Vtemplate_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtemplate_tb::~Vtemplate_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtemplate_tb___024root___eval_debug_assertions(Vtemplate_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vtemplate_tb___024root___eval_static(Vtemplate_tb___024root* vlSelf);
void Vtemplate_tb___024root___eval_initial(Vtemplate_tb___024root* vlSelf);
void Vtemplate_tb___024root___eval_settle(Vtemplate_tb___024root* vlSelf);
void Vtemplate_tb___024root___eval(Vtemplate_tb___024root* vlSelf);

void Vtemplate_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtemplate_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtemplate_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtemplate_tb___024root___eval_static(&(vlSymsp->TOP));
        Vtemplate_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vtemplate_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtemplate_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtemplate_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtemplate_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtemplate_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtemplate_tb___024root___eval_final(Vtemplate_tb___024root* vlSelf);

VL_ATTR_COLD void Vtemplate_tb::final() {
    Vtemplate_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtemplate_tb::hierName() const { return vlSymsp->name(); }
const char* Vtemplate_tb::modelName() const { return "Vtemplate_tb"; }
unsigned Vtemplate_tb::threads() const { return 1; }
void Vtemplate_tb::prepareClone() const { contextp()->prepareClone(); }
void Vtemplate_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}

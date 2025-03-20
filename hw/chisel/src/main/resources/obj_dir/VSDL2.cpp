// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSDL2__pch.h"

//============================================================
// Constructors

VSDL2::VSDL2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSDL2__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , input_ready{vlSymsp->TOP.input_ready}
    , input_valid{vlSymsp->TOP.input_valid}
    , operation{vlSymsp->TOP.operation}
    , dump{vlSymsp->TOP.dump}
    , address{vlSymsp->TOP.address}
    , data{vlSymsp->TOP.data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VSDL2::VSDL2(const char* _vcname__)
    : VSDL2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSDL2::~VSDL2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSDL2___024root___eval_debug_assertions(VSDL2___024root* vlSelf);
#endif  // VL_DEBUG
void VSDL2___024root___eval_static(VSDL2___024root* vlSelf);
void VSDL2___024root___eval_initial(VSDL2___024root* vlSelf);
void VSDL2___024root___eval_settle(VSDL2___024root* vlSelf);
void VSDL2___024root___eval(VSDL2___024root* vlSelf);

void VSDL2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSDL2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSDL2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSDL2___024root___eval_static(&(vlSymsp->TOP));
        VSDL2___024root___eval_initial(&(vlSymsp->TOP));
        VSDL2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSDL2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSDL2::eventsPending() { return false; }

uint64_t VSDL2::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSDL2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSDL2___024root___eval_final(VSDL2___024root* vlSelf);

VL_ATTR_COLD void VSDL2::final() {
    VSDL2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSDL2::hierName() const { return vlSymsp->name(); }
const char* VSDL2::modelName() const { return "VSDL2"; }
unsigned VSDL2::threads() const { return 1; }
void VSDL2::prepareClone() const { contextp()->prepareClone(); }
void VSDL2::atClone() const {
    contextp()->threadPoolpOnClone();
}

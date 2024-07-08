// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VsvsimTestbench.h"
#include "VsvsimTestbench__Syms.h"
#include "verilated_dpi.h"


void VsvsimTestbench::getBitWidth_clock(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_clock\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_clock");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_clock_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_clock_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_clock(const svBitVecVal* value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_clock\n"); );
    // Init
    CData/*0:0*/ value_clock__Vcvt;
    value_clock__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_clock");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_clock_t __Vcb = (VsvsimTestbench__Vcb_setBits_clock_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_clock__Vcvt = (1U & VL_SET_I_SVBV(value_clock));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_clock__Vcvt);
}

void VsvsimTestbench::getBits_clock(svBitVecVal* value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_clock\n"); );
    // Init
    CData/*0:0*/ value_clock__Vcvt;
    value_clock__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_clock");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_clock_t __Vcb = (VsvsimTestbench__Vcb_getBits_clock_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_clock__Vcvt);
    for (size_t value_clock__Vidx = 0; value_clock__Vidx < 1; ++value_clock__Vidx) VL_SET_SVBV_I(1, value_clock + 1 * value_clock__Vidx, value_clock__Vcvt);
}

void VsvsimTestbench::getBitWidth_reset(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_reset\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_reset");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_reset_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_reset_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_reset(const svBitVecVal* value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_reset\n"); );
    // Init
    CData/*0:0*/ value_reset__Vcvt;
    value_reset__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_reset");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_reset_t __Vcb = (VsvsimTestbench__Vcb_setBits_reset_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_reset__Vcvt = (1U & VL_SET_I_SVBV(value_reset));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_reset__Vcvt);
}

void VsvsimTestbench::getBits_reset(svBitVecVal* value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_reset\n"); );
    // Init
    CData/*0:0*/ value_reset__Vcvt;
    value_reset__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_reset");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_reset_t __Vcb = (VsvsimTestbench__Vcb_getBits_reset_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_reset__Vcvt);
    for (size_t value_reset__Vidx = 0; value_reset__Vidx < 1; ++value_reset__Vidx) VL_SET_SVBV_I(1, value_reset + 1 * value_reset__Vidx, value_reset__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS2_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS2_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS2_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS2_0(svBitVecVal* value_io_RAT_RS2_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS2_0\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS2_0__Vcvt;
    value_io_RAT_RS2_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS2_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS2_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS2_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS2_0__Vcvt);
    for (size_t value_io_RAT_RS2_0__Vidx = 0; value_io_RAT_RS2_0__Vidx < 1; ++value_io_RAT_RS2_0__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS2_0 + 1 * value_io_RAT_RS2_0__Vidx, value_io_RAT_RS2_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS2_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS2_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS2_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS2_1(svBitVecVal* value_io_RAT_RS2_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS2_1\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS2_1__Vcvt;
    value_io_RAT_RS2_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS2_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS2_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS2_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS2_1__Vcvt);
    for (size_t value_io_RAT_RS2_1__Vidx = 0; value_io_RAT_RS2_1__Vidx < 1; ++value_io_RAT_RS2_1__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS2_1 + 1 * value_io_RAT_RS2_1__Vidx, value_io_RAT_RS2_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS2_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS2_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS2_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS2_2(svBitVecVal* value_io_RAT_RS2_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS2_2\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS2_2__Vcvt;
    value_io_RAT_RS2_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS2_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS2_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS2_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS2_2__Vcvt);
    for (size_t value_io_RAT_RS2_2__Vidx = 0; value_io_RAT_RS2_2__Vidx < 1; ++value_io_RAT_RS2_2__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS2_2 + 1 * value_io_RAT_RS2_2__Vidx, value_io_RAT_RS2_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS2_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS2_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS2_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS2_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS2_3(svBitVecVal* value_io_RAT_RS2_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS2_3\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS2_3__Vcvt;
    value_io_RAT_RS2_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS2_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS2_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS2_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS2_3__Vcvt);
    for (size_t value_io_RAT_RS2_3__Vidx = 0; value_io_RAT_RS2_3__Vidx < 1; ++value_io_RAT_RS2_3__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS2_3 + 1 * value_io_RAT_RS2_3__Vidx, value_io_RAT_RS2_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS1_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS1_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS1_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS1_0(svBitVecVal* value_io_RAT_RS1_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS1_0\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS1_0__Vcvt;
    value_io_RAT_RS1_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS1_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS1_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS1_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS1_0__Vcvt);
    for (size_t value_io_RAT_RS1_0__Vidx = 0; value_io_RAT_RS1_0__Vidx < 1; ++value_io_RAT_RS1_0__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS1_0 + 1 * value_io_RAT_RS1_0__Vidx, value_io_RAT_RS1_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS1_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS1_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS1_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS1_1(svBitVecVal* value_io_RAT_RS1_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS1_1\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS1_1__Vcvt;
    value_io_RAT_RS1_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS1_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS1_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS1_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS1_1__Vcvt);
    for (size_t value_io_RAT_RS1_1__Vidx = 0; value_io_RAT_RS1_1__Vidx < 1; ++value_io_RAT_RS1_1__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS1_1 + 1 * value_io_RAT_RS1_1__Vidx, value_io_RAT_RS1_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS1_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS1_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS1_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS1_2(svBitVecVal* value_io_RAT_RS1_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS1_2\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS1_2__Vcvt;
    value_io_RAT_RS1_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS1_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS1_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS1_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS1_2__Vcvt);
    for (size_t value_io_RAT_RS1_2__Vidx = 0; value_io_RAT_RS1_2__Vidx < 1; ++value_io_RAT_RS1_2__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS1_2 + 1 * value_io_RAT_RS1_2__Vidx, value_io_RAT_RS1_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RS1_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RS1_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RS1_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RS1_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RS1_3(svBitVecVal* value_io_RAT_RS1_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RS1_3\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RS1_3__Vcvt;
    value_io_RAT_RS1_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RS1_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RS1_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RS1_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RS1_3__Vcvt);
    for (size_t value_io_RAT_RS1_3__Vidx = 0; value_io_RAT_RS1_3__Vidx < 1; ++value_io_RAT_RS1_3__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RS1_3 + 1 * value_io_RAT_RS1_3__Vidx, value_io_RAT_RS1_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RD_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RD_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RD_0(svBitVecVal* value_io_RAT_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RD_0\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RD_0__Vcvt;
    value_io_RAT_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RD_0__Vcvt);
    for (size_t value_io_RAT_RD_0__Vidx = 0; value_io_RAT_RD_0__Vidx < 1; ++value_io_RAT_RD_0__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RD_0 + 1 * value_io_RAT_RD_0__Vidx, value_io_RAT_RD_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RD_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RD_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RD_1(svBitVecVal* value_io_RAT_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RD_1\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RD_1__Vcvt;
    value_io_RAT_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RD_1__Vcvt);
    for (size_t value_io_RAT_RD_1__Vidx = 0; value_io_RAT_RD_1__Vidx < 1; ++value_io_RAT_RD_1__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RD_1 + 1 * value_io_RAT_RD_1__Vidx, value_io_RAT_RD_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RD_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RD_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RD_2(svBitVecVal* value_io_RAT_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RD_2\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RD_2__Vcvt;
    value_io_RAT_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RD_2__Vcvt);
    for (size_t value_io_RAT_RD_2__Vidx = 0; value_io_RAT_RD_2__Vidx < 1; ++value_io_RAT_RD_2__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RD_2 + 1 * value_io_RAT_RD_2__Vidx, value_io_RAT_RD_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_RAT_RD_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_RAT_RD_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_RAT_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_RAT_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_RAT_RD_3(svBitVecVal* value_io_RAT_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_RAT_RD_3\n"); );
    // Init
    CData/*6:0*/ value_io_RAT_RD_3__Vcvt;
    value_io_RAT_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_RAT_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_RAT_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_RAT_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_RAT_RD_3__Vcvt);
    for (size_t value_io_RAT_RD_3__Vidx = 0; value_io_RAT_RD_3__Vidx < 1; ++value_io_RAT_RD_3__Vidx) VL_SET_SVBV_I(7, value_io_RAT_RD_3 + 1 * value_io_RAT_RD_3__Vidx, value_io_RAT_RD_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_checkpoints_empty(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_checkpoints_empty\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_checkpoints_empty");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_checkpoints_empty_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_checkpoints_empty_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_checkpoints_empty(svBitVecVal* value_io_checkpoints_empty) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_checkpoints_empty\n"); );
    // Init
    CData/*0:0*/ value_io_checkpoints_empty__Vcvt;
    value_io_checkpoints_empty__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_checkpoints_empty");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_checkpoints_empty_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_checkpoints_empty_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_checkpoints_empty__Vcvt);
    for (size_t value_io_checkpoints_empty__Vidx = 0; value_io_checkpoints_empty__Vidx < 1; ++value_io_checkpoints_empty__Vidx) VL_SET_SVBV_I(1, value_io_checkpoints_empty + 1 * value_io_checkpoints_empty__Vidx, value_io_checkpoints_empty__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_checkpoints_full(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_checkpoints_full\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_checkpoints_full");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_checkpoints_full_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_checkpoints_full_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_checkpoints_full(svBitVecVal* value_io_checkpoints_full) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_checkpoints_full\n"); );
    // Init
    CData/*0:0*/ value_io_checkpoints_full__Vcvt;
    value_io_checkpoints_full__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_checkpoints_full");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_checkpoints_full_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_checkpoints_full_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_checkpoints_full__Vcvt);
    for (size_t value_io_checkpoints_full__Vidx = 0; value_io_checkpoints_full__Vidx < 1; ++value_io_checkpoints_full__Vidx) VL_SET_SVBV_I(1, value_io_checkpoints_full + 1 * value_io_checkpoints_full__Vidx, value_io_checkpoints_full__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_active_checkpoint_value(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_active_checkpoint_value\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_active_checkpoint_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_active_checkpoint_value_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_active_checkpoint_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_active_checkpoint_value(svBitVecVal* value_io_active_checkpoint_value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_active_checkpoint_value\n"); );
    // Init
    CData/*3:0*/ value_io_active_checkpoint_value__Vcvt;
    value_io_active_checkpoint_value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_active_checkpoint_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_active_checkpoint_value_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_active_checkpoint_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_active_checkpoint_value__Vcvt);
    for (size_t value_io_active_checkpoint_value__Vidx = 0; value_io_active_checkpoint_value__Vidx < 1; ++value_io_active_checkpoint_value__Vidx) VL_SET_SVBV_I(4, value_io_active_checkpoint_value + 1 * value_io_active_checkpoint_value__Vidx, value_io_active_checkpoint_value__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_restore_checkpoint_value(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_restore_checkpoint_value\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_restore_checkpoint_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_restore_checkpoint_value_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_restore_checkpoint_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_restore_checkpoint_value(const svBitVecVal* value_io_restore_checkpoint_value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_restore_checkpoint_value\n"); );
    // Init
    CData/*3:0*/ value_io_restore_checkpoint_value__Vcvt;
    value_io_restore_checkpoint_value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_restore_checkpoint_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_restore_checkpoint_value_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_restore_checkpoint_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_restore_checkpoint_value__Vcvt = (0xfU 
                                               & VL_SET_I_SVBV(value_io_restore_checkpoint_value));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_restore_checkpoint_value__Vcvt);
}

void VsvsimTestbench::getBits_io_restore_checkpoint_value(svBitVecVal* value_io_restore_checkpoint_value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_restore_checkpoint_value\n"); );
    // Init
    CData/*3:0*/ value_io_restore_checkpoint_value__Vcvt;
    value_io_restore_checkpoint_value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_restore_checkpoint_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_restore_checkpoint_value_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_restore_checkpoint_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_restore_checkpoint_value__Vcvt);
    for (size_t value_io_restore_checkpoint_value__Vidx = 0; value_io_restore_checkpoint_value__Vidx < 1; ++value_io_restore_checkpoint_value__Vidx) VL_SET_SVBV_I(4, value_io_restore_checkpoint_value + 1 * value_io_restore_checkpoint_value__Vidx, value_io_restore_checkpoint_value__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_checkpoint(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_checkpoint\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_checkpoint(const svBitVecVal* value_io_free_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_checkpoint\n"); );
    // Init
    CData/*0:0*/ value_io_free_checkpoint__Vcvt;
    value_io_free_checkpoint__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_checkpoint__Vcvt = (1U & VL_SET_I_SVBV(value_io_free_checkpoint));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_checkpoint__Vcvt);
}

void VsvsimTestbench::getBits_io_free_checkpoint(svBitVecVal* value_io_free_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_checkpoint\n"); );
    // Init
    CData/*0:0*/ value_io_free_checkpoint__Vcvt;
    value_io_free_checkpoint__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_checkpoint__Vcvt);
    for (size_t value_io_free_checkpoint__Vidx = 0; value_io_free_checkpoint__Vidx < 1; ++value_io_free_checkpoint__Vidx) VL_SET_SVBV_I(1, value_io_free_checkpoint + 1 * value_io_free_checkpoint__Vidx, value_io_free_checkpoint__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_restore_checkpoint(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_restore_checkpoint\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_restore_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_restore_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_restore_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_restore_checkpoint(const svBitVecVal* value_io_restore_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_restore_checkpoint\n"); );
    // Init
    CData/*0:0*/ value_io_restore_checkpoint__Vcvt;
    value_io_restore_checkpoint__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_restore_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_restore_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_restore_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_restore_checkpoint__Vcvt = (1U & VL_SET_I_SVBV(value_io_restore_checkpoint));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_restore_checkpoint__Vcvt);
}

void VsvsimTestbench::getBits_io_restore_checkpoint(svBitVecVal* value_io_restore_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_restore_checkpoint\n"); );
    // Init
    CData/*0:0*/ value_io_restore_checkpoint__Vcvt;
    value_io_restore_checkpoint__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_restore_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_restore_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_restore_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_restore_checkpoint__Vcvt);
    for (size_t value_io_restore_checkpoint__Vidx = 0; value_io_restore_checkpoint__Vidx < 1; ++value_io_restore_checkpoint__Vidx) VL_SET_SVBV_I(1, value_io_restore_checkpoint + 1 * value_io_restore_checkpoint__Vidx, value_io_restore_checkpoint__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_create_checkpoint(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_create_checkpoint\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_create_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_create_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_create_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_create_checkpoint(const svBitVecVal* value_io_create_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_create_checkpoint\n"); );
    // Init
    CData/*0:0*/ value_io_create_checkpoint__Vcvt;
    value_io_create_checkpoint__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_create_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_create_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_create_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_create_checkpoint__Vcvt = (1U & VL_SET_I_SVBV(value_io_create_checkpoint));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_create_checkpoint__Vcvt);
}

void VsvsimTestbench::getBits_io_create_checkpoint(svBitVecVal* value_io_create_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_create_checkpoint\n"); );
    // Init
    CData/*0:0*/ value_io_create_checkpoint__Vcvt;
    value_io_create_checkpoint__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_create_checkpoint");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_create_checkpoint_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_create_checkpoint_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_create_checkpoint__Vcvt);
    for (size_t value_io_create_checkpoint__Vidx = 0; value_io_create_checkpoint__Vidx < 1; ++value_io_create_checkpoint__Vidx) VL_SET_SVBV_I(1, value_io_create_checkpoint + 1 * value_io_create_checkpoint__Vidx, value_io_create_checkpoint__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_RD_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_RD_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_RD_0(const svBitVecVal* value_io_free_list_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_RD_0\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_0__Vcvt;
    value_io_free_list_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_RD_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_RD_0__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_free_list_RD_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_0__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_RD_0(svBitVecVal* value_io_free_list_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_RD_0\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_0__Vcvt;
    value_io_free_list_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_0__Vcvt);
    for (size_t value_io_free_list_RD_0__Vidx = 0; value_io_free_list_RD_0__Vidx < 1; ++value_io_free_list_RD_0__Vidx) VL_SET_SVBV_I(7, value_io_free_list_RD_0 + 1 * value_io_free_list_RD_0__Vidx, value_io_free_list_RD_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_RD_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_RD_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_RD_1(const svBitVecVal* value_io_free_list_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_RD_1\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_1__Vcvt;
    value_io_free_list_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_RD_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_RD_1__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_free_list_RD_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_1__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_RD_1(svBitVecVal* value_io_free_list_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_RD_1\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_1__Vcvt;
    value_io_free_list_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_1__Vcvt);
    for (size_t value_io_free_list_RD_1__Vidx = 0; value_io_free_list_RD_1__Vidx < 1; ++value_io_free_list_RD_1__Vidx) VL_SET_SVBV_I(7, value_io_free_list_RD_1 + 1 * value_io_free_list_RD_1__Vidx, value_io_free_list_RD_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_RD_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_RD_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_RD_2(const svBitVecVal* value_io_free_list_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_RD_2\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_2__Vcvt;
    value_io_free_list_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_RD_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_RD_2__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_free_list_RD_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_2__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_RD_2(svBitVecVal* value_io_free_list_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_RD_2\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_2__Vcvt;
    value_io_free_list_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_2__Vcvt);
    for (size_t value_io_free_list_RD_2__Vidx = 0; value_io_free_list_RD_2__Vidx < 1; ++value_io_free_list_RD_2__Vidx) VL_SET_SVBV_I(7, value_io_free_list_RD_2 + 1 * value_io_free_list_RD_2__Vidx, value_io_free_list_RD_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_RD_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_RD_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_RD_3(const svBitVecVal* value_io_free_list_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_RD_3\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_3__Vcvt;
    value_io_free_list_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_RD_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_RD_3__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_free_list_RD_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_3__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_RD_3(svBitVecVal* value_io_free_list_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_RD_3\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_RD_3__Vcvt;
    value_io_free_list_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_RD_3__Vcvt);
    for (size_t value_io_free_list_RD_3__Vidx = 0; value_io_free_list_RD_3__Vidx < 1; ++value_io_free_list_RD_3__Vidx) VL_SET_SVBV_I(7, value_io_free_list_RD_3 + 1 * value_io_free_list_RD_3__Vidx, value_io_free_list_RD_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_wr_en_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_wr_en_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_wr_en_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_wr_en_0(const svBitVecVal* value_io_free_list_wr_en_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_wr_en_0\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_0__Vcvt;
    value_io_free_list_wr_en_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_wr_en_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_wr_en_0__Vcvt = (1U & VL_SET_I_SVBV(value_io_free_list_wr_en_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_0__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_wr_en_0(svBitVecVal* value_io_free_list_wr_en_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_wr_en_0\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_0__Vcvt;
    value_io_free_list_wr_en_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_wr_en_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_0__Vcvt);
    for (size_t value_io_free_list_wr_en_0__Vidx = 0; value_io_free_list_wr_en_0__Vidx < 1; ++value_io_free_list_wr_en_0__Vidx) VL_SET_SVBV_I(1, value_io_free_list_wr_en_0 + 1 * value_io_free_list_wr_en_0__Vidx, value_io_free_list_wr_en_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_wr_en_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_wr_en_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_wr_en_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_wr_en_1(const svBitVecVal* value_io_free_list_wr_en_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_wr_en_1\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_1__Vcvt;
    value_io_free_list_wr_en_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_wr_en_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_wr_en_1__Vcvt = (1U & VL_SET_I_SVBV(value_io_free_list_wr_en_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_1__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_wr_en_1(svBitVecVal* value_io_free_list_wr_en_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_wr_en_1\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_1__Vcvt;
    value_io_free_list_wr_en_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_wr_en_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_1__Vcvt);
    for (size_t value_io_free_list_wr_en_1__Vidx = 0; value_io_free_list_wr_en_1__Vidx < 1; ++value_io_free_list_wr_en_1__Vidx) VL_SET_SVBV_I(1, value_io_free_list_wr_en_1 + 1 * value_io_free_list_wr_en_1__Vidx, value_io_free_list_wr_en_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_wr_en_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_wr_en_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_wr_en_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_wr_en_2(const svBitVecVal* value_io_free_list_wr_en_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_wr_en_2\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_2__Vcvt;
    value_io_free_list_wr_en_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_wr_en_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_wr_en_2__Vcvt = (1U & VL_SET_I_SVBV(value_io_free_list_wr_en_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_2__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_wr_en_2(svBitVecVal* value_io_free_list_wr_en_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_wr_en_2\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_2__Vcvt;
    value_io_free_list_wr_en_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_wr_en_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_2__Vcvt);
    for (size_t value_io_free_list_wr_en_2__Vidx = 0; value_io_free_list_wr_en_2__Vidx < 1; ++value_io_free_list_wr_en_2__Vidx) VL_SET_SVBV_I(1, value_io_free_list_wr_en_2 + 1 * value_io_free_list_wr_en_2__Vidx, value_io_free_list_wr_en_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_wr_en_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_wr_en_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_wr_en_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_wr_en_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_free_list_wr_en_3(const svBitVecVal* value_io_free_list_wr_en_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_free_list_wr_en_3\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_3__Vcvt;
    value_io_free_list_wr_en_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_free_list_wr_en_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_free_list_wr_en_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_free_list_wr_en_3__Vcvt = (1U & VL_SET_I_SVBV(value_io_free_list_wr_en_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_3__Vcvt);
}

void VsvsimTestbench::getBits_io_free_list_wr_en_3(svBitVecVal* value_io_free_list_wr_en_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_wr_en_3\n"); );
    // Init
    CData/*0:0*/ value_io_free_list_wr_en_3__Vcvt;
    value_io_free_list_wr_en_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_wr_en_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_wr_en_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_wr_en_3__Vcvt);
    for (size_t value_io_free_list_wr_en_3__Vidx = 0; value_io_free_list_wr_en_3__Vidx < 1; ++value_io_free_list_wr_en_3__Vidx) VL_SET_SVBV_I(1, value_io_free_list_wr_en_3 + 1 * value_io_free_list_wr_en_3__Vidx, value_io_free_list_wr_en_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RD_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RD_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RD_0(const svBitVecVal* value_io_instruction_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RD_0\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_0__Vcvt;
    value_io_instruction_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RD_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RD_0__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RD_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_0__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RD_0(svBitVecVal* value_io_instruction_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RD_0\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_0__Vcvt;
    value_io_instruction_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_0__Vcvt);
    for (size_t value_io_instruction_RD_0__Vidx = 0; value_io_instruction_RD_0__Vidx < 1; ++value_io_instruction_RD_0__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RD_0 + 1 * value_io_instruction_RD_0__Vidx, value_io_instruction_RD_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RD_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RD_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RD_1(const svBitVecVal* value_io_instruction_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RD_1\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_1__Vcvt;
    value_io_instruction_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RD_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RD_1__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RD_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_1__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RD_1(svBitVecVal* value_io_instruction_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RD_1\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_1__Vcvt;
    value_io_instruction_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_1__Vcvt);
    for (size_t value_io_instruction_RD_1__Vidx = 0; value_io_instruction_RD_1__Vidx < 1; ++value_io_instruction_RD_1__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RD_1 + 1 * value_io_instruction_RD_1__Vidx, value_io_instruction_RD_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RD_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RD_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RD_2(const svBitVecVal* value_io_instruction_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RD_2\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_2__Vcvt;
    value_io_instruction_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RD_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RD_2__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RD_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_2__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RD_2(svBitVecVal* value_io_instruction_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RD_2\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_2__Vcvt;
    value_io_instruction_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_2__Vcvt);
    for (size_t value_io_instruction_RD_2__Vidx = 0; value_io_instruction_RD_2__Vidx < 1; ++value_io_instruction_RD_2__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RD_2 + 1 * value_io_instruction_RD_2__Vidx, value_io_instruction_RD_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RD_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RD_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RD_3(const svBitVecVal* value_io_instruction_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RD_3\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_3__Vcvt;
    value_io_instruction_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RD_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RD_3__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RD_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_3__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RD_3(svBitVecVal* value_io_instruction_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RD_3\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RD_3__Vcvt;
    value_io_instruction_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RD_3__Vcvt);
    for (size_t value_io_instruction_RD_3__Vidx = 0; value_io_instruction_RD_3__Vidx < 1; ++value_io_instruction_RD_3__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RD_3 + 1 * value_io_instruction_RD_3__Vidx, value_io_instruction_RD_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS2_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS2_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS2_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS2_0(const svBitVecVal* value_io_instruction_RS2_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS2_0\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_0__Vcvt;
    value_io_instruction_RS2_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS2_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS2_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS2_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS2_0__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS2_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_0__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS2_0(svBitVecVal* value_io_instruction_RS2_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS2_0\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_0__Vcvt;
    value_io_instruction_RS2_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS2_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS2_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS2_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_0__Vcvt);
    for (size_t value_io_instruction_RS2_0__Vidx = 0; value_io_instruction_RS2_0__Vidx < 1; ++value_io_instruction_RS2_0__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS2_0 + 1 * value_io_instruction_RS2_0__Vidx, value_io_instruction_RS2_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS2_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS2_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS2_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS2_1(const svBitVecVal* value_io_instruction_RS2_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS2_1\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_1__Vcvt;
    value_io_instruction_RS2_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS2_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS2_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS2_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS2_1__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS2_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_1__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS2_1(svBitVecVal* value_io_instruction_RS2_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS2_1\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_1__Vcvt;
    value_io_instruction_RS2_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS2_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS2_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS2_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_1__Vcvt);
    for (size_t value_io_instruction_RS2_1__Vidx = 0; value_io_instruction_RS2_1__Vidx < 1; ++value_io_instruction_RS2_1__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS2_1 + 1 * value_io_instruction_RS2_1__Vidx, value_io_instruction_RS2_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS2_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS2_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS2_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS2_2(const svBitVecVal* value_io_instruction_RS2_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS2_2\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_2__Vcvt;
    value_io_instruction_RS2_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS2_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS2_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS2_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS2_2__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS2_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_2__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS2_2(svBitVecVal* value_io_instruction_RS2_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS2_2\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_2__Vcvt;
    value_io_instruction_RS2_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS2_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS2_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS2_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_2__Vcvt);
    for (size_t value_io_instruction_RS2_2__Vidx = 0; value_io_instruction_RS2_2__Vidx < 1; ++value_io_instruction_RS2_2__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS2_2 + 1 * value_io_instruction_RS2_2__Vidx, value_io_instruction_RS2_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS2_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS2_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS2_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS2_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS2_3(const svBitVecVal* value_io_instruction_RS2_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS2_3\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_3__Vcvt;
    value_io_instruction_RS2_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS2_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS2_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS2_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS2_3__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS2_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_3__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS2_3(svBitVecVal* value_io_instruction_RS2_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS2_3\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS2_3__Vcvt;
    value_io_instruction_RS2_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS2_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS2_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS2_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS2_3__Vcvt);
    for (size_t value_io_instruction_RS2_3__Vidx = 0; value_io_instruction_RS2_3__Vidx < 1; ++value_io_instruction_RS2_3__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS2_3 + 1 * value_io_instruction_RS2_3__Vidx, value_io_instruction_RS2_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS1_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS1_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS1_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS1_0(const svBitVecVal* value_io_instruction_RS1_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS1_0\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_0__Vcvt;
    value_io_instruction_RS1_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS1_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS1_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS1_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS1_0__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS1_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_0__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS1_0(svBitVecVal* value_io_instruction_RS1_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS1_0\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_0__Vcvt;
    value_io_instruction_RS1_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS1_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS1_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS1_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_0__Vcvt);
    for (size_t value_io_instruction_RS1_0__Vidx = 0; value_io_instruction_RS1_0__Vidx < 1; ++value_io_instruction_RS1_0__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS1_0 + 1 * value_io_instruction_RS1_0__Vidx, value_io_instruction_RS1_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS1_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS1_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS1_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS1_1(const svBitVecVal* value_io_instruction_RS1_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS1_1\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_1__Vcvt;
    value_io_instruction_RS1_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS1_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS1_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS1_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS1_1__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS1_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_1__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS1_1(svBitVecVal* value_io_instruction_RS1_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS1_1\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_1__Vcvt;
    value_io_instruction_RS1_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS1_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS1_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS1_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_1__Vcvt);
    for (size_t value_io_instruction_RS1_1__Vidx = 0; value_io_instruction_RS1_1__Vidx < 1; ++value_io_instruction_RS1_1__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS1_1 + 1 * value_io_instruction_RS1_1__Vidx, value_io_instruction_RS1_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS1_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS1_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS1_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS1_2(const svBitVecVal* value_io_instruction_RS1_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS1_2\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_2__Vcvt;
    value_io_instruction_RS1_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS1_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS1_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS1_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS1_2__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS1_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_2__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS1_2(svBitVecVal* value_io_instruction_RS1_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS1_2\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_2__Vcvt;
    value_io_instruction_RS1_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS1_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS1_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS1_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_2__Vcvt);
    for (size_t value_io_instruction_RS1_2__Vidx = 0; value_io_instruction_RS1_2__Vidx < 1; ++value_io_instruction_RS1_2__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS1_2 + 1 * value_io_instruction_RS1_2__Vidx, value_io_instruction_RS1_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_instruction_RS1_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_instruction_RS1_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_instruction_RS1_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_instruction_RS1_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_instruction_RS1_3(const svBitVecVal* value_io_instruction_RS1_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_instruction_RS1_3\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_3__Vcvt;
    value_io_instruction_RS1_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_instruction_RS1_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_instruction_RS1_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_instruction_RS1_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_instruction_RS1_3__Vcvt = (0x1fU & VL_SET_I_SVBV(value_io_instruction_RS1_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_3__Vcvt);
}

void VsvsimTestbench::getBits_io_instruction_RS1_3(svBitVecVal* value_io_instruction_RS1_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_instruction_RS1_3\n"); );
    // Init
    CData/*4:0*/ value_io_instruction_RS1_3__Vcvt;
    value_io_instruction_RS1_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_instruction_RS1_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_instruction_RS1_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_instruction_RS1_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_instruction_RS1_3__Vcvt);
    for (size_t value_io_instruction_RS1_3__Vidx = 0; value_io_instruction_RS1_3__Vidx < 1; ++value_io_instruction_RS1_3__Vidx) VL_SET_SVBV_I(5, value_io_instruction_RS1_3 + 1 * value_io_instruction_RS1_3__Vidx, value_io_instruction_RS1_3__Vcvt);
}

void VsvsimTestbench::simulation_initializeTrace(const char* traceFilePath) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::simulation_initializeTrace\n"); );
    // Init
    static thread_local std::string traceFilePath__Vcvt;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("simulation_initializeTrace");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_simulation_initializeTrace_t __Vcb = (VsvsimTestbench__Vcb_simulation_initializeTrace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    traceFilePath__Vcvt = traceFilePath;
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), traceFilePath__Vcvt);
}

void VsvsimTestbench::simulation_enableTrace() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::simulation_enableTrace\n"); );
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("simulation_enableTrace");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_simulation_enableTrace_t __Vcb = (VsvsimTestbench__Vcb_simulation_enableTrace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()));
}

void VsvsimTestbench::simulation_disableTrace() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::simulation_disableTrace\n"); );
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("simulation_disableTrace");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_simulation_disableTrace_t __Vcb = (VsvsimTestbench__Vcb_simulation_disableTrace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()));
}

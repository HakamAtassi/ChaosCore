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

void VsvsimTestbench::getBitWidth_io_can_allocate(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_can_allocate\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_can_allocate");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_can_allocate_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_can_allocate_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_can_allocate(svBitVecVal* value_io_can_allocate) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_can_allocate\n"); );
    // Init
    CData/*0:0*/ value_io_can_allocate__Vcvt;
    value_io_can_allocate__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_can_allocate");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_can_allocate_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_can_allocate_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_can_allocate__Vcvt);
    for (size_t value_io_can_allocate__Vidx = 0; value_io_can_allocate__Vidx < 1; ++value_io_can_allocate__Vidx) VL_SET_SVBV_I(1, value_io_can_allocate + 1 * value_io_can_allocate__Vidx, value_io_can_allocate__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_can_reallocate(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_can_reallocate\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_can_reallocate");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_can_reallocate_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_can_reallocate_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_can_reallocate(svBitVecVal* value_io_can_reallocate) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_can_reallocate\n"); );
    // Init
    CData/*0:0*/ value_io_can_reallocate__Vcvt;
    value_io_can_reallocate__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_can_reallocate");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_can_reallocate_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_can_reallocate_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_can_reallocate__Vcvt);
    for (size_t value_io_can_reallocate__Vidx = 0; value_io_can_reallocate__Vidx < 1; ++value_io_can_reallocate__Vidx) VL_SET_SVBV_I(1, value_io_can_reallocate + 1 * value_io_can_reallocate__Vidx, value_io_can_reallocate__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_free_list_front_pointer(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_free_list_front_pointer\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_free_list_front_pointer");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_free_list_front_pointer_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_free_list_front_pointer_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_free_list_front_pointer(svBitVecVal* value_io_free_list_front_pointer) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_free_list_front_pointer\n"); );
    // Init
    CData/*6:0*/ value_io_free_list_front_pointer__Vcvt;
    value_io_free_list_front_pointer__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_free_list_front_pointer");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_free_list_front_pointer_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_free_list_front_pointer_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_free_list_front_pointer__Vcvt);
    for (size_t value_io_free_list_front_pointer__Vidx = 0; value_io_free_list_front_pointer__Vidx < 1; ++value_io_free_list_front_pointer__Vidx) VL_SET_SVBV_I(7, value_io_free_list_front_pointer + 1 * value_io_free_list_front_pointer__Vidx, value_io_free_list_front_pointer__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_valid_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_valid_0(const svBitVecVal* value_io_commit_bits_RD_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_valid_0\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_0__Vcvt;
    value_io_commit_bits_RD_valid_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_valid_0__Vcvt = (1U & VL_SET_I_SVBV(value_io_commit_bits_RD_valid_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_0__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_valid_0(svBitVecVal* value_io_commit_bits_RD_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_valid_0\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_0__Vcvt;
    value_io_commit_bits_RD_valid_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_0__Vcvt);
    for (size_t value_io_commit_bits_RD_valid_0__Vidx = 0; value_io_commit_bits_RD_valid_0__Vidx < 1; ++value_io_commit_bits_RD_valid_0__Vidx) VL_SET_SVBV_I(1, value_io_commit_bits_RD_valid_0 + 1 * value_io_commit_bits_RD_valid_0__Vidx, value_io_commit_bits_RD_valid_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_valid_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_valid_1(const svBitVecVal* value_io_commit_bits_RD_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_valid_1\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_1__Vcvt;
    value_io_commit_bits_RD_valid_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_valid_1__Vcvt = (1U & VL_SET_I_SVBV(value_io_commit_bits_RD_valid_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_1__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_valid_1(svBitVecVal* value_io_commit_bits_RD_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_valid_1\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_1__Vcvt;
    value_io_commit_bits_RD_valid_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_1__Vcvt);
    for (size_t value_io_commit_bits_RD_valid_1__Vidx = 0; value_io_commit_bits_RD_valid_1__Vidx < 1; ++value_io_commit_bits_RD_valid_1__Vidx) VL_SET_SVBV_I(1, value_io_commit_bits_RD_valid_1 + 1 * value_io_commit_bits_RD_valid_1__Vidx, value_io_commit_bits_RD_valid_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_valid_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_valid_2(const svBitVecVal* value_io_commit_bits_RD_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_valid_2\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_2__Vcvt;
    value_io_commit_bits_RD_valid_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_valid_2__Vcvt = (1U & VL_SET_I_SVBV(value_io_commit_bits_RD_valid_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_2__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_valid_2(svBitVecVal* value_io_commit_bits_RD_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_valid_2\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_2__Vcvt;
    value_io_commit_bits_RD_valid_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_2__Vcvt);
    for (size_t value_io_commit_bits_RD_valid_2__Vidx = 0; value_io_commit_bits_RD_valid_2__Vidx < 1; ++value_io_commit_bits_RD_valid_2__Vidx) VL_SET_SVBV_I(1, value_io_commit_bits_RD_valid_2 + 1 * value_io_commit_bits_RD_valid_2__Vidx, value_io_commit_bits_RD_valid_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_valid_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_valid_3(const svBitVecVal* value_io_commit_bits_RD_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_valid_3\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_3__Vcvt;
    value_io_commit_bits_RD_valid_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_valid_3__Vcvt = (1U & VL_SET_I_SVBV(value_io_commit_bits_RD_valid_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_3__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_valid_3(svBitVecVal* value_io_commit_bits_RD_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_valid_3\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_RD_valid_3__Vcvt;
    value_io_commit_bits_RD_valid_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_valid_3__Vcvt);
    for (size_t value_io_commit_bits_RD_valid_3__Vidx = 0; value_io_commit_bits_RD_valid_3__Vidx < 1; ++value_io_commit_bits_RD_valid_3__Vidx) VL_SET_SVBV_I(1, value_io_commit_bits_RD_valid_3 + 1 * value_io_commit_bits_RD_valid_3__Vidx, value_io_commit_bits_RD_valid_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_0(const svBitVecVal* value_io_commit_bits_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_0\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_0__Vcvt;
    value_io_commit_bits_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_0__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_commit_bits_RD_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_0__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_0(svBitVecVal* value_io_commit_bits_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_0\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_0__Vcvt;
    value_io_commit_bits_RD_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_0__Vcvt);
    for (size_t value_io_commit_bits_RD_0__Vidx = 0; value_io_commit_bits_RD_0__Vidx < 1; ++value_io_commit_bits_RD_0__Vidx) VL_SET_SVBV_I(7, value_io_commit_bits_RD_0 + 1 * value_io_commit_bits_RD_0__Vidx, value_io_commit_bits_RD_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_1(const svBitVecVal* value_io_commit_bits_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_1\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_1__Vcvt;
    value_io_commit_bits_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_1__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_commit_bits_RD_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_1__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_1(svBitVecVal* value_io_commit_bits_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_1\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_1__Vcvt;
    value_io_commit_bits_RD_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_1__Vcvt);
    for (size_t value_io_commit_bits_RD_1__Vidx = 0; value_io_commit_bits_RD_1__Vidx < 1; ++value_io_commit_bits_RD_1__Vidx) VL_SET_SVBV_I(7, value_io_commit_bits_RD_1 + 1 * value_io_commit_bits_RD_1__Vidx, value_io_commit_bits_RD_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_2(const svBitVecVal* value_io_commit_bits_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_2\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_2__Vcvt;
    value_io_commit_bits_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_2__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_commit_bits_RD_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_2__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_2(svBitVecVal* value_io_commit_bits_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_2\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_2__Vcvt;
    value_io_commit_bits_RD_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_2__Vcvt);
    for (size_t value_io_commit_bits_RD_2__Vidx = 0; value_io_commit_bits_RD_2__Vidx < 1; ++value_io_commit_bits_RD_2__Vidx) VL_SET_SVBV_I(7, value_io_commit_bits_RD_2 + 1 * value_io_commit_bits_RD_2__Vidx, value_io_commit_bits_RD_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RD_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RD_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RD_3(const svBitVecVal* value_io_commit_bits_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RD_3\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_3__Vcvt;
    value_io_commit_bits_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RD_3__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_commit_bits_RD_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_3__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RD_3(svBitVecVal* value_io_commit_bits_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RD_3\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_RD_3__Vcvt;
    value_io_commit_bits_RD_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RD_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RD_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RD_3__Vcvt);
    for (size_t value_io_commit_bits_RD_3__Vidx = 0; value_io_commit_bits_RD_3__Vidx < 1; ++value_io_commit_bits_RD_3__Vidx) VL_SET_SVBV_I(7, value_io_commit_bits_RD_3 + 1 * value_io_commit_bits_RD_3__Vidx, value_io_commit_bits_RD_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_free_list_front_pointer(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_free_list_front_pointer\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_free_list_front_pointer");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_free_list_front_pointer_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_free_list_front_pointer_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_free_list_front_pointer(const svBitVecVal* value_io_commit_bits_free_list_front_pointer) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_free_list_front_pointer\n"); );
    // Init
    CData/*7:0*/ value_io_commit_bits_free_list_front_pointer__Vcvt;
    value_io_commit_bits_free_list_front_pointer__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_free_list_front_pointer");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_free_list_front_pointer_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_free_list_front_pointer_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_free_list_front_pointer__Vcvt 
        = (0xffU & VL_SET_I_SVBV(value_io_commit_bits_free_list_front_pointer));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_free_list_front_pointer__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_free_list_front_pointer(svBitVecVal* value_io_commit_bits_free_list_front_pointer) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_free_list_front_pointer\n"); );
    // Init
    CData/*7:0*/ value_io_commit_bits_free_list_front_pointer__Vcvt;
    value_io_commit_bits_free_list_front_pointer__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_free_list_front_pointer");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_free_list_front_pointer_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_free_list_front_pointer_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_free_list_front_pointer__Vcvt);
    for (size_t value_io_commit_bits_free_list_front_pointer__Vidx = 0; value_io_commit_bits_free_list_front_pointer__Vidx < 1; ++value_io_commit_bits_free_list_front_pointer__Vidx) VL_SET_SVBV_I(8, value_io_commit_bits_free_list_front_pointer + 1 * value_io_commit_bits_free_list_front_pointer__Vidx, value_io_commit_bits_free_list_front_pointer__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_RAT_index(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_RAT_index\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_RAT_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RAT_index_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_RAT_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_RAT_index(const svBitVecVal* value_io_commit_bits_RAT_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_RAT_index\n"); );
    // Init
    CData/*3:0*/ value_io_commit_bits_RAT_index__Vcvt;
    value_io_commit_bits_RAT_index__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_RAT_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_RAT_index_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_RAT_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_RAT_index__Vcvt = (0xfU & 
                                            VL_SET_I_SVBV(value_io_commit_bits_RAT_index));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RAT_index__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_RAT_index(svBitVecVal* value_io_commit_bits_RAT_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_RAT_index\n"); );
    // Init
    CData/*3:0*/ value_io_commit_bits_RAT_index__Vcvt;
    value_io_commit_bits_RAT_index__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_RAT_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_RAT_index_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_RAT_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_RAT_index__Vcvt);
    for (size_t value_io_commit_bits_RAT_index__Vidx = 0; value_io_commit_bits_RAT_index__Vidx < 1; ++value_io_commit_bits_RAT_index__Vidx) VL_SET_SVBV_I(4, value_io_commit_bits_RAT_index + 1 * value_io_commit_bits_RAT_index__Vidx, value_io_commit_bits_RAT_index__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_NEXT(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_NEXT\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_NEXT");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_NEXT_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_NEXT_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_NEXT(const svBitVecVal* value_io_commit_bits_NEXT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_NEXT\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_NEXT__Vcvt;
    value_io_commit_bits_NEXT__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_NEXT");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_NEXT_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_NEXT_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_NEXT__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_commit_bits_NEXT));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_NEXT__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_NEXT(svBitVecVal* value_io_commit_bits_NEXT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_NEXT\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_NEXT__Vcvt;
    value_io_commit_bits_NEXT__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_NEXT");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_NEXT_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_NEXT_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_NEXT__Vcvt);
    for (size_t value_io_commit_bits_NEXT__Vidx = 0; value_io_commit_bits_NEXT__Vidx < 1; ++value_io_commit_bits_NEXT__Vidx) VL_SET_SVBV_I(7, value_io_commit_bits_NEXT + 1 * value_io_commit_bits_NEXT__Vidx, value_io_commit_bits_NEXT__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_TOS(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_TOS\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_TOS");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_TOS_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_TOS_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_TOS(const svBitVecVal* value_io_commit_bits_TOS) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_TOS\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_TOS__Vcvt;
    value_io_commit_bits_TOS__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_TOS");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_TOS_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_TOS_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_TOS__Vcvt = (0x7fU & VL_SET_I_SVBV(value_io_commit_bits_TOS));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_TOS__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_TOS(svBitVecVal* value_io_commit_bits_TOS) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_TOS\n"); );
    // Init
    CData/*6:0*/ value_io_commit_bits_TOS__Vcvt;
    value_io_commit_bits_TOS__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_TOS");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_TOS_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_TOS_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_TOS__Vcvt);
    for (size_t value_io_commit_bits_TOS__Vidx = 0; value_io_commit_bits_TOS__Vidx < 1; ++value_io_commit_bits_TOS__Vidx) VL_SET_SVBV_I(7, value_io_commit_bits_TOS + 1 * value_io_commit_bits_TOS__Vidx, value_io_commit_bits_TOS__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_GHR(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_GHR\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_GHR");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_GHR_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_GHR_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_GHR(const svBitVecVal* value_io_commit_bits_GHR) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_GHR\n"); );
    // Init
    SData/*15:0*/ value_io_commit_bits_GHR__Vcvt;
    value_io_commit_bits_GHR__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_GHR");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_GHR_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_GHR_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_GHR__Vcvt = (0xffffU & VL_SET_I_SVBV(value_io_commit_bits_GHR));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_GHR__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_GHR(svBitVecVal* value_io_commit_bits_GHR) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_GHR\n"); );
    // Init
    SData/*15:0*/ value_io_commit_bits_GHR__Vcvt;
    value_io_commit_bits_GHR__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_GHR");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_GHR_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_GHR_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_GHR__Vcvt);
    for (size_t value_io_commit_bits_GHR__Vidx = 0; value_io_commit_bits_GHR__Vidx < 1; ++value_io_commit_bits_GHR__Vidx) VL_SET_SVBV_I(16, value_io_commit_bits_GHR + 1 * value_io_commit_bits_GHR__Vidx, value_io_commit_bits_GHR__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_expected_PC(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_expected_PC\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_expected_PC");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_expected_PC_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_expected_PC_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_expected_PC(const svBitVecVal* value_io_commit_bits_expected_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_expected_PC\n"); );
    // Init
    IData/*31:0*/ value_io_commit_bits_expected_PC__Vcvt;
    value_io_commit_bits_expected_PC__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_expected_PC");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_expected_PC_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_expected_PC_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_expected_PC__Vcvt = VL_SET_I_SVBV(value_io_commit_bits_expected_PC);
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_expected_PC__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_expected_PC(svBitVecVal* value_io_commit_bits_expected_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_expected_PC\n"); );
    // Init
    IData/*31:0*/ value_io_commit_bits_expected_PC__Vcvt;
    value_io_commit_bits_expected_PC__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_expected_PC");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_expected_PC_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_expected_PC_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_expected_PC__Vcvt);
    for (size_t value_io_commit_bits_expected_PC__Vidx = 0; value_io_commit_bits_expected_PC__Vidx < 1; ++value_io_commit_bits_expected_PC__Vidx) VL_SET_SVBV_I(32, value_io_commit_bits_expected_PC + 1 * value_io_commit_bits_expected_PC__Vidx, value_io_commit_bits_expected_PC__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_is_misprediction(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_is_misprediction\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_is_misprediction");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_is_misprediction_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_is_misprediction_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_is_misprediction(const svBitVecVal* value_io_commit_bits_is_misprediction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_is_misprediction\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_is_misprediction__Vcvt;
    value_io_commit_bits_is_misprediction__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_is_misprediction");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_is_misprediction_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_is_misprediction_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_is_misprediction__Vcvt = (1U 
                                                   & VL_SET_I_SVBV(value_io_commit_bits_is_misprediction));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_is_misprediction__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_is_misprediction(svBitVecVal* value_io_commit_bits_is_misprediction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_is_misprediction\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_is_misprediction__Vcvt;
    value_io_commit_bits_is_misprediction__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_is_misprediction");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_is_misprediction_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_is_misprediction_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_is_misprediction__Vcvt);
    for (size_t value_io_commit_bits_is_misprediction__Vidx = 0; value_io_commit_bits_is_misprediction__Vidx < 1; ++value_io_commit_bits_is_misprediction__Vidx) VL_SET_SVBV_I(1, value_io_commit_bits_is_misprediction + 1 * value_io_commit_bits_is_misprediction__Vidx, value_io_commit_bits_is_misprediction__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_fetch_packet_index(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_fetch_packet_index\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_fetch_packet_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_fetch_packet_index_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_fetch_packet_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_fetch_packet_index(const svBitVecVal* value_io_commit_bits_fetch_packet_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_fetch_packet_index\n"); );
    // Init
    CData/*1:0*/ value_io_commit_bits_fetch_packet_index__Vcvt;
    value_io_commit_bits_fetch_packet_index__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_fetch_packet_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_fetch_packet_index_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_fetch_packet_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_fetch_packet_index__Vcvt = 
        (3U & VL_SET_I_SVBV(value_io_commit_bits_fetch_packet_index));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_fetch_packet_index__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_fetch_packet_index(svBitVecVal* value_io_commit_bits_fetch_packet_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_fetch_packet_index\n"); );
    // Init
    CData/*1:0*/ value_io_commit_bits_fetch_packet_index__Vcvt;
    value_io_commit_bits_fetch_packet_index__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_fetch_packet_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_fetch_packet_index_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_fetch_packet_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_fetch_packet_index__Vcvt);
    for (size_t value_io_commit_bits_fetch_packet_index__Vidx = 0; value_io_commit_bits_fetch_packet_index__Vidx < 1; ++value_io_commit_bits_fetch_packet_index__Vidx) VL_SET_SVBV_I(2, value_io_commit_bits_fetch_packet_index + 1 * value_io_commit_bits_fetch_packet_index__Vidx, value_io_commit_bits_fetch_packet_index__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_br_type(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_br_type\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_br_type");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_br_type_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_br_type_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_br_type(const svBitVecVal* value_io_commit_bits_br_type) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_br_type\n"); );
    // Init
    CData/*2:0*/ value_io_commit_bits_br_type__Vcvt;
    value_io_commit_bits_br_type__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_br_type");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_br_type_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_br_type_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_br_type__Vcvt = (7U & VL_SET_I_SVBV(value_io_commit_bits_br_type));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_br_type__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_br_type(svBitVecVal* value_io_commit_bits_br_type) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_br_type\n"); );
    // Init
    CData/*2:0*/ value_io_commit_bits_br_type__Vcvt;
    value_io_commit_bits_br_type__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_br_type");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_br_type_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_br_type_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_br_type__Vcvt);
    for (size_t value_io_commit_bits_br_type__Vidx = 0; value_io_commit_bits_br_type__Vidx < 1; ++value_io_commit_bits_br_type__Vidx) VL_SET_SVBV_I(3, value_io_commit_bits_br_type + 1 * value_io_commit_bits_br_type__Vidx, value_io_commit_bits_br_type__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_ROB_index(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_ROB_index\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_ROB_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_ROB_index_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_ROB_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_ROB_index(const svBitVecVal* value_io_commit_bits_ROB_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_ROB_index\n"); );
    // Init
    CData/*5:0*/ value_io_commit_bits_ROB_index__Vcvt;
    value_io_commit_bits_ROB_index__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_ROB_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_ROB_index_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_ROB_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_ROB_index__Vcvt = (0x3fU & 
                                            VL_SET_I_SVBV(value_io_commit_bits_ROB_index));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_ROB_index__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_ROB_index(svBitVecVal* value_io_commit_bits_ROB_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_ROB_index\n"); );
    // Init
    CData/*5:0*/ value_io_commit_bits_ROB_index__Vcvt;
    value_io_commit_bits_ROB_index__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_ROB_index");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_ROB_index_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_ROB_index_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_ROB_index__Vcvt);
    for (size_t value_io_commit_bits_ROB_index__Vidx = 0; value_io_commit_bits_ROB_index__Vidx < 1; ++value_io_commit_bits_ROB_index__Vidx) VL_SET_SVBV_I(6, value_io_commit_bits_ROB_index + 1 * value_io_commit_bits_ROB_index__Vidx, value_io_commit_bits_ROB_index__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_T_NT(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_T_NT\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_T_NT");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_T_NT_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_T_NT_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_T_NT(const svBitVecVal* value_io_commit_bits_T_NT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_T_NT\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_T_NT__Vcvt;
    value_io_commit_bits_T_NT__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_T_NT");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_T_NT_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_T_NT_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_T_NT__Vcvt = (1U & VL_SET_I_SVBV(value_io_commit_bits_T_NT));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_T_NT__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_T_NT(svBitVecVal* value_io_commit_bits_T_NT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_T_NT\n"); );
    // Init
    CData/*0:0*/ value_io_commit_bits_T_NT__Vcvt;
    value_io_commit_bits_T_NT__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_T_NT");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_T_NT_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_T_NT_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_T_NT__Vcvt);
    for (size_t value_io_commit_bits_T_NT__Vidx = 0; value_io_commit_bits_T_NT__Vidx < 1; ++value_io_commit_bits_T_NT__Vidx) VL_SET_SVBV_I(1, value_io_commit_bits_T_NT + 1 * value_io_commit_bits_T_NT__Vidx, value_io_commit_bits_T_NT__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_bits_fetch_PC(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_bits_fetch_PC\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_bits_fetch_PC");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_fetch_PC_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_bits_fetch_PC_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_bits_fetch_PC(const svBitVecVal* value_io_commit_bits_fetch_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_bits_fetch_PC\n"); );
    // Init
    IData/*31:0*/ value_io_commit_bits_fetch_PC__Vcvt;
    value_io_commit_bits_fetch_PC__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_bits_fetch_PC");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_bits_fetch_PC_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_bits_fetch_PC_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_bits_fetch_PC__Vcvt = VL_SET_I_SVBV(value_io_commit_bits_fetch_PC);
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_fetch_PC__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_bits_fetch_PC(svBitVecVal* value_io_commit_bits_fetch_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_bits_fetch_PC\n"); );
    // Init
    IData/*31:0*/ value_io_commit_bits_fetch_PC__Vcvt;
    value_io_commit_bits_fetch_PC__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_bits_fetch_PC");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_bits_fetch_PC_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_bits_fetch_PC_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_bits_fetch_PC__Vcvt);
    for (size_t value_io_commit_bits_fetch_PC__Vidx = 0; value_io_commit_bits_fetch_PC__Vidx < 1; ++value_io_commit_bits_fetch_PC__Vidx) VL_SET_SVBV_I(32, value_io_commit_bits_fetch_PC + 1 * value_io_commit_bits_fetch_PC__Vidx, value_io_commit_bits_fetch_PC__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_commit_valid(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_commit_valid\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_commit_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_commit_valid_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_commit_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_commit_valid(const svBitVecVal* value_io_commit_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_commit_valid\n"); );
    // Init
    CData/*0:0*/ value_io_commit_valid__Vcvt;
    value_io_commit_valid__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_commit_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_commit_valid_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_commit_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_commit_valid__Vcvt = (1U & VL_SET_I_SVBV(value_io_commit_valid));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_valid__Vcvt);
}

void VsvsimTestbench::getBits_io_commit_valid(svBitVecVal* value_io_commit_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_commit_valid\n"); );
    // Init
    CData/*0:0*/ value_io_commit_valid__Vcvt;
    value_io_commit_valid__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_commit_valid");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_commit_valid_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_commit_valid_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_commit_valid__Vcvt);
    for (size_t value_io_commit_valid__Vidx = 0; value_io_commit_valid__Vidx < 1; ++value_io_commit_valid__Vidx) VL_SET_SVBV_I(1, value_io_commit_valid + 1 * value_io_commit_valid__Vidx, value_io_commit_valid__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_valid_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_valid_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_valid_0(svBitVecVal* value_io_renamed_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_valid_0\n"); );
    // Init
    CData/*0:0*/ value_io_renamed_valid_0__Vcvt;
    value_io_renamed_valid_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_valid_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_valid_0__Vcvt);
    for (size_t value_io_renamed_valid_0__Vidx = 0; value_io_renamed_valid_0__Vidx < 1; ++value_io_renamed_valid_0__Vidx) VL_SET_SVBV_I(1, value_io_renamed_valid_0 + 1 * value_io_renamed_valid_0__Vidx, value_io_renamed_valid_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_valid_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_valid_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_valid_1(svBitVecVal* value_io_renamed_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_valid_1\n"); );
    // Init
    CData/*0:0*/ value_io_renamed_valid_1__Vcvt;
    value_io_renamed_valid_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_valid_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_valid_1__Vcvt);
    for (size_t value_io_renamed_valid_1__Vidx = 0; value_io_renamed_valid_1__Vidx < 1; ++value_io_renamed_valid_1__Vidx) VL_SET_SVBV_I(1, value_io_renamed_valid_1 + 1 * value_io_renamed_valid_1__Vidx, value_io_renamed_valid_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_valid_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_valid_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_valid_2(svBitVecVal* value_io_renamed_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_valid_2\n"); );
    // Init
    CData/*0:0*/ value_io_renamed_valid_2__Vcvt;
    value_io_renamed_valid_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_valid_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_valid_2__Vcvt);
    for (size_t value_io_renamed_valid_2__Vidx = 0; value_io_renamed_valid_2__Vidx < 1; ++value_io_renamed_valid_2__Vidx) VL_SET_SVBV_I(1, value_io_renamed_valid_2 + 1 * value_io_renamed_valid_2__Vidx, value_io_renamed_valid_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_valid_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_valid_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_valid_3(svBitVecVal* value_io_renamed_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_valid_3\n"); );
    // Init
    CData/*0:0*/ value_io_renamed_valid_3__Vcvt;
    value_io_renamed_valid_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_valid_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_valid_3__Vcvt);
    for (size_t value_io_renamed_valid_3__Vidx = 0; value_io_renamed_valid_3__Vidx < 1; ++value_io_renamed_valid_3__Vidx) VL_SET_SVBV_I(1, value_io_renamed_valid_3 + 1 * value_io_renamed_valid_3__Vidx, value_io_renamed_valid_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_values_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_values_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_values_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_values_0(svBitVecVal* value_io_renamed_values_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_values_0\n"); );
    // Init
    CData/*6:0*/ value_io_renamed_values_0__Vcvt;
    value_io_renamed_values_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_values_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_values_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_values_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_values_0__Vcvt);
    for (size_t value_io_renamed_values_0__Vidx = 0; value_io_renamed_values_0__Vidx < 1; ++value_io_renamed_values_0__Vidx) VL_SET_SVBV_I(7, value_io_renamed_values_0 + 1 * value_io_renamed_values_0__Vidx, value_io_renamed_values_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_values_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_values_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_values_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_values_1(svBitVecVal* value_io_renamed_values_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_values_1\n"); );
    // Init
    CData/*6:0*/ value_io_renamed_values_1__Vcvt;
    value_io_renamed_values_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_values_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_values_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_values_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_values_1__Vcvt);
    for (size_t value_io_renamed_values_1__Vidx = 0; value_io_renamed_values_1__Vidx < 1; ++value_io_renamed_values_1__Vidx) VL_SET_SVBV_I(7, value_io_renamed_values_1 + 1 * value_io_renamed_values_1__Vidx, value_io_renamed_values_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_values_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_values_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_values_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_values_2(svBitVecVal* value_io_renamed_values_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_values_2\n"); );
    // Init
    CData/*6:0*/ value_io_renamed_values_2__Vcvt;
    value_io_renamed_values_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_values_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_values_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_values_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_values_2__Vcvt);
    for (size_t value_io_renamed_values_2__Vidx = 0; value_io_renamed_values_2__Vidx < 1; ++value_io_renamed_values_2__Vidx) VL_SET_SVBV_I(7, value_io_renamed_values_2 + 1 * value_io_renamed_values_2__Vidx, value_io_renamed_values_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_renamed_values_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_renamed_values_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_renamed_values_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_renamed_values_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::getBits_io_renamed_values_3(svBitVecVal* value_io_renamed_values_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_renamed_values_3\n"); );
    // Init
    CData/*6:0*/ value_io_renamed_values_3__Vcvt;
    value_io_renamed_values_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_renamed_values_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_renamed_values_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_renamed_values_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_renamed_values_3__Vcvt);
    for (size_t value_io_renamed_values_3__Vidx = 0; value_io_renamed_values_3__Vidx < 1; ++value_io_renamed_values_3__Vidx) VL_SET_SVBV_I(7, value_io_renamed_values_3 + 1 * value_io_renamed_values_3__Vidx, value_io_renamed_values_3__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_rename_valid_0(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_rename_valid_0\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_rename_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_0_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_rename_valid_0(const svBitVecVal* value_io_rename_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_rename_valid_0\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_0__Vcvt;
    value_io_rename_valid_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_rename_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_rename_valid_0_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_rename_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_rename_valid_0__Vcvt = (1U & VL_SET_I_SVBV(value_io_rename_valid_0));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_0__Vcvt);
}

void VsvsimTestbench::getBits_io_rename_valid_0(svBitVecVal* value_io_rename_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_rename_valid_0\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_0__Vcvt;
    value_io_rename_valid_0__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_rename_valid_0");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_rename_valid_0_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_rename_valid_0_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_0__Vcvt);
    for (size_t value_io_rename_valid_0__Vidx = 0; value_io_rename_valid_0__Vidx < 1; ++value_io_rename_valid_0__Vidx) VL_SET_SVBV_I(1, value_io_rename_valid_0 + 1 * value_io_rename_valid_0__Vidx, value_io_rename_valid_0__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_rename_valid_1(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_rename_valid_1\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_rename_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_1_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_rename_valid_1(const svBitVecVal* value_io_rename_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_rename_valid_1\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_1__Vcvt;
    value_io_rename_valid_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_rename_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_rename_valid_1_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_rename_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_rename_valid_1__Vcvt = (1U & VL_SET_I_SVBV(value_io_rename_valid_1));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_1__Vcvt);
}

void VsvsimTestbench::getBits_io_rename_valid_1(svBitVecVal* value_io_rename_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_rename_valid_1\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_1__Vcvt;
    value_io_rename_valid_1__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_rename_valid_1");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_rename_valid_1_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_rename_valid_1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_1__Vcvt);
    for (size_t value_io_rename_valid_1__Vidx = 0; value_io_rename_valid_1__Vidx < 1; ++value_io_rename_valid_1__Vidx) VL_SET_SVBV_I(1, value_io_rename_valid_1 + 1 * value_io_rename_valid_1__Vidx, value_io_rename_valid_1__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_rename_valid_2(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_rename_valid_2\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_rename_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_2_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_rename_valid_2(const svBitVecVal* value_io_rename_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_rename_valid_2\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_2__Vcvt;
    value_io_rename_valid_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_rename_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_rename_valid_2_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_rename_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_rename_valid_2__Vcvt = (1U & VL_SET_I_SVBV(value_io_rename_valid_2));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_2__Vcvt);
}

void VsvsimTestbench::getBits_io_rename_valid_2(svBitVecVal* value_io_rename_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_rename_valid_2\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_2__Vcvt;
    value_io_rename_valid_2__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_rename_valid_2");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_rename_valid_2_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_rename_valid_2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_2__Vcvt);
    for (size_t value_io_rename_valid_2__Vidx = 0; value_io_rename_valid_2__Vidx < 1; ++value_io_rename_valid_2__Vidx) VL_SET_SVBV_I(1, value_io_rename_valid_2 + 1 * value_io_rename_valid_2__Vidx, value_io_rename_valid_2__Vcvt);
}

void VsvsimTestbench::getBitWidth_io_rename_valid_3(int* value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBitWidth_io_rename_valid_3\n"); );
    // Init
    IData/*31:0*/ value__Vcvt;
    value__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBitWidth_io_rename_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_3_t __Vcb = (VsvsimTestbench__Vcb_getBitWidth_io_rename_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value__Vcvt);
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) *value = value__Vcvt;
}

void VsvsimTestbench::setBits_io_rename_valid_3(const svBitVecVal* value_io_rename_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::setBits_io_rename_valid_3\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_3__Vcvt;
    value_io_rename_valid_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("setBits_io_rename_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_setBits_io_rename_valid_3_t __Vcb = (VsvsimTestbench__Vcb_setBits_io_rename_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    value_io_rename_valid_3__Vcvt = (1U & VL_SET_I_SVBV(value_io_rename_valid_3));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_3__Vcvt);
}

void VsvsimTestbench::getBits_io_rename_valid_3(svBitVecVal* value_io_rename_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root::getBits_io_rename_valid_3\n"); );
    // Init
    CData/*0:0*/ value_io_rename_valid_3__Vcvt;
    value_io_rename_valid_3__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("getBits_io_rename_valid_3");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VsvsimTestbench__Vcb_getBits_io_rename_valid_3_t __Vcb = (VsvsimTestbench__Vcb_getBits_io_rename_valid_3_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VsvsimTestbench__Syms*)(__Vscopep->symsp()), value_io_rename_valid_3__Vcvt);
    for (size_t value_io_rename_valid_3__Vidx = 0; value_io_rename_valid_3__Vidx < 1; ++value_io_rename_valid_3__Vidx) VL_SET_SVBV_I(1, value_io_rename_valid_3 + 1 * value_io_rename_valid_3__Vidx, value_io_rename_valid_3__Vcvt);
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

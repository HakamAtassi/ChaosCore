// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench__Syms.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_clock_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_clock_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__clock = value_clock;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_clock_TOP\n"); );
    // Init
    // Body
    value_clock = vlSymsp->TOP.svsimTestbench__DOT__clock;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_reset_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_reset_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__reset = value_reset;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_reset_TOP\n"); );
    // Init
    // Body
    value_reset = vlSymsp->TOP.svsimTestbench__DOT__reset;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_can_allocate_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_can_allocate_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_can_allocate_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_can_allocate) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_can_allocate_TOP\n"); );
    // Init
    // Body
    value_io_can_allocate = (0U != (0x1fU & (((IData)(1U) 
                                              + (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)) 
                                             >> 2U)));
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_can_reallocate_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_can_reallocate_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_can_reallocate_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_can_reallocate) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_can_reallocate_TOP\n"); );
    // Init
    // Body
    value_io_can_reallocate = (0x41U > (0x7fU & ((IData)(5U) 
                                                 + (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0))));
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_front_pointer_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_front_pointer_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_front_pointer_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_front_pointer) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_front_pointer_TOP\n"); );
    // Init
    // Body
    value_io_free_list_front_pointer = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__front_pointer;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_0_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_0 
        = value_io_commit_bits_RD_valid_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_0_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_valid_0 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_1_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_1 
        = value_io_commit_bits_RD_valid_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_1_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_valid_1 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_2_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_2 
        = value_io_commit_bits_RD_valid_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_2_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_valid_2 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_valid_3_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_RD_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_valid_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_3 
        = value_io_commit_bits_RD_valid_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_RD_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_valid_3_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_valid_3 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_valid_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_0_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_0 
        = value_io_commit_bits_RD_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_0_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_0 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_1_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_1 
        = value_io_commit_bits_RD_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_1_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_1 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_2_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_2 
        = value_io_commit_bits_RD_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_2_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_2 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RD_3_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RD_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_3 
        = value_io_commit_bits_RD_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RD_3_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RD_3 = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RD_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_free_list_front_pointer_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_free_list_front_pointer_TOP\n"); );
    // Init
    // Body
    value = 8U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_free_list_front_pointer_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*7:0*/ value_io_commit_bits_free_list_front_pointer) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_free_list_front_pointer_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_free_list_front_pointer 
        = value_io_commit_bits_free_list_front_pointer;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_free_list_front_pointer_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*7:0*/ &value_io_commit_bits_free_list_front_pointer) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_free_list_front_pointer_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_free_list_front_pointer = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_free_list_front_pointer;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RAT_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_RAT_index_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RAT_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_commit_bits_RAT_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_RAT_index_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RAT_index 
        = value_io_commit_bits_RAT_index;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RAT_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_commit_bits_RAT_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_RAT_index_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_RAT_index = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_RAT_index;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_NEXT_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_NEXT_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_NEXT_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_NEXT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_NEXT_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_NEXT 
        = value_io_commit_bits_NEXT;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_NEXT_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_NEXT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_NEXT_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_NEXT = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_NEXT;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_TOS_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_TOS_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_TOS_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_commit_bits_TOS) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_TOS_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_TOS 
        = value_io_commit_bits_TOS;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_TOS_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_commit_bits_TOS) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_TOS_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_TOS = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_TOS;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_GHR_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_GHR_TOP\n"); );
    // Init
    // Body
    value = 0x10U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_GHR_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*15:0*/ value_io_commit_bits_GHR) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_GHR_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_GHR 
        = value_io_commit_bits_GHR;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_GHR_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*15:0*/ &value_io_commit_bits_GHR) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_GHR_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_GHR = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_GHR;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_expected_PC_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_expected_PC_TOP\n"); );
    // Init
    // Body
    value = 0x20U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_expected_PC_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ value_io_commit_bits_expected_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_expected_PC_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_expected_PC 
        = value_io_commit_bits_expected_PC;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_expected_PC_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value_io_commit_bits_expected_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_expected_PC_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_expected_PC = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_expected_PC;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_is_misprediction_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_is_misprediction_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_is_misprediction_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_is_misprediction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_is_misprediction_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_is_misprediction 
        = value_io_commit_bits_is_misprediction;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_is_misprediction_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_is_misprediction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_is_misprediction_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_is_misprediction = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_is_misprediction;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_fetch_packet_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_fetch_packet_index_TOP\n"); );
    // Init
    // Body
    value = 2U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_fetch_packet_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*1:0*/ value_io_commit_bits_fetch_packet_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_fetch_packet_index_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_fetch_packet_index 
        = value_io_commit_bits_fetch_packet_index;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_fetch_packet_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*1:0*/ &value_io_commit_bits_fetch_packet_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_fetch_packet_index_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_fetch_packet_index = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_fetch_packet_index;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_br_type_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_br_type_TOP\n"); );
    // Init
    // Body
    value = 3U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_br_type_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ value_io_commit_bits_br_type) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_br_type_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_br_type 
        = value_io_commit_bits_br_type;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_br_type_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*2:0*/ &value_io_commit_bits_br_type) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_br_type_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_br_type = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_br_type;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_ROB_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_ROB_index_TOP\n"); );
    // Init
    // Body
    value = 6U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_ROB_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*5:0*/ value_io_commit_bits_ROB_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_ROB_index_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_ROB_index 
        = value_io_commit_bits_ROB_index;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_ROB_index_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*5:0*/ &value_io_commit_bits_ROB_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_ROB_index_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_ROB_index = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_ROB_index;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_T_NT_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_T_NT_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_T_NT_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_bits_T_NT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_T_NT_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_T_NT 
        = value_io_commit_bits_T_NT;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_T_NT_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_bits_T_NT) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_T_NT_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_T_NT = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_T_NT;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_fetch_PC_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_bits_fetch_PC_TOP\n"); );
    // Init
    // Body
    value = 0x20U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_fetch_PC_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ value_io_commit_bits_fetch_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_bits_fetch_PC_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_fetch_PC 
        = value_io_commit_bits_fetch_PC;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_fetch_PC_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value_io_commit_bits_fetch_PC) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_bits_fetch_PC_TOP\n"); );
    // Init
    // Body
    value_io_commit_bits_fetch_PC = vlSymsp->TOP.svsimTestbench__DOT__io_commit_bits_fetch_PC;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_commit_valid_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_commit_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_commit_valid_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_commit_valid 
        = value_io_commit_valid;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_valid_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_commit_valid) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_commit_valid_TOP\n"); );
    // Init
    // Body
    value_io_commit_valid = vlSymsp->TOP.svsimTestbench__DOT__io_commit_valid;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_0_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_0_TOP\n"); );
    // Init
    // Body
    value_io_renamed_valid_0 = vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_1_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_1_TOP\n"); );
    // Init
    // Body
    value_io_renamed_valid_1 = vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_2_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_2_TOP\n"); );
    // Init
    // Body
    value_io_renamed_valid_2 = vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_valid_3_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_renamed_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_valid_3_TOP\n"); );
    // Init
    // Body
    value_io_renamed_valid_3 = vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_0_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

extern const VlWide<14>/*447:0*/ VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0;

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_0_TOP\n"); );
    // Init
    // Body
    value_io_renamed_values_0 = ((IData)(vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_0)
                                  ? ((0x1bfU >= (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)))
                                                    ? 0U
                                                    : 
                                                   (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                    (((IData)(6U) 
                                                      + (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1))))) 
                                                  | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                     ((IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1) 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)))))
                                      : 0U) : 0U);
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_1_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_1_TOP\n"); );
    // Init
    // Body
    value_io_renamed_values_1 = ((IData)(vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_1)
                                  ? ((0x1bfU >= (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)))
                                                    ? 0U
                                                    : 
                                                   (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                    (((IData)(6U) 
                                                      + (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2))))) 
                                                  | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                     ((IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2) 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)))))
                                      : 0U) : 0U);
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_2_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_2_TOP\n"); );
    // Init
    // Body
    value_io_renamed_values_2 = ((IData)(vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_2)
                                  ? ((0x1bfU >= (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)))
                                                    ? 0U
                                                    : 
                                                   (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                    (((IData)(6U) 
                                                      + (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3))))) 
                                                  | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                     ((IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3) 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)))))
                                      : 0U) : 0U);
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_renamed_values_3_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_renamed_values_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_renamed_values_3_TOP\n"); );
    // Init
    // Body
    value_io_renamed_values_3 = ((IData)(vlSymsp->TOP.svsimTestbench__DOT__io_renamed_valid_3)
                                  ? ((0x1bfU >= (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)))
                                                    ? 0U
                                                    : 
                                                   (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                    (((IData)(6U) 
                                                      + (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4))))) 
                                                  | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                     ((IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4) 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x1fU 
                                                      & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)))))
                                      : 0U) : 0U);
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_0_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_0 
        = value_io_rename_valid_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_0_TOP\n"); );
    // Init
    // Body
    value_io_rename_valid_0 = vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_1_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_1 
        = value_io_rename_valid_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_1_TOP\n"); );
    // Init
    // Body
    value_io_rename_valid_1 = vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_2_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_2 
        = value_io_rename_valid_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_2_TOP\n"); );
    // Init
    // Body
    value_io_rename_valid_2 = vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_rename_valid_3_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_rename_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_rename_valid_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_3 
        = value_io_rename_valid_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_rename_valid_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_rename_valid_3_TOP\n"); );
    // Init
    // Body
    value_io_rename_valid_3 = vlSymsp->TOP.svsimTestbench__DOT__io_rename_valid_3;
}

extern "C" int simulation_body();

VL_INLINE_OPT void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    simulation_body();
}

extern "C" void run_simulation(int timesteps);

VL_INLINE_OPT void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__run_simulation_TOP(IData/*31:0*/ timesteps) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__run_simulation_TOP\n"); );
    // Body
    int timesteps__Vcvt;
    for (size_t timesteps__Vidx = 0; timesteps__Vidx < 1; ++timesteps__Vidx) timesteps__Vcvt = timesteps;
    run_simulation(timesteps__Vcvt);
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, std::string traceFilePath) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP\n"); );
    // Init
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NN(
                                                         VL_CONCATN_NNN(traceFilePath, 
                                                                        std::string{".vcd"})));
    vlSymsp->_traceDumpOpen();
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP\n"); );
    // Init
    // Body
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP\n"); );
    // Init
    // Body
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval_triggers__ico(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
    vlSelf->__VicoTriggered.set(1U, (IData)(vlSelf->__Vdpi_export_trigger));
    vlSelf->__Vdpi_export_trigger = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval_triggers__act(VsvsimTestbench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (IData)(vlSelf->__Vdpi_export_trigger));
    vlSelf->__Vdpi_export_trigger = 0U;
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->svsimTestbench__DOT__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 
        = vlSelf->svsimTestbench__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__act(vlSelf);
    }
#endif
}

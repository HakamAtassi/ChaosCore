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

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_0_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_0_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS2_0 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS2_0_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_1_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_1_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS2_1 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS2_1_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_2_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_2_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS2_2 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS2_2_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS2_3_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS2_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS2_3_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS2_3 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS2_3_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_0_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_0_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS1_0 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS1_0_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_1_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_1_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS1_1 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS1_1_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_2_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_2_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS1_2 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS1_2_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RS1_3_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RS1_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RS1_3_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RS1_3 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RS1_3_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_0_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_0_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RD_0 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RD_0_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_1_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_1_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RD_1 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RD_1_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_2_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_2_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RD_2 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RD_2_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_RAT_RD_3_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_RAT_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_RAT_RD_3_TOP\n"); );
    // Init
    // Body
    value_io_RAT_RD_3 = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_RAT_RD_3_REG;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_checkpoints_empty_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_checkpoints_empty_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_checkpoints_empty_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_checkpoints_empty) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_checkpoints_empty_TOP\n"); );
    // Init
    // Body
    value_io_checkpoints_empty = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_checkpoints_empty_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_checkpoints_full_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_checkpoints_full_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_checkpoints_full_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_checkpoints_full) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_checkpoints_full_TOP\n"); );
    // Init
    // Body
    value_io_checkpoints_full = vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__io_checkpoints_full_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_active_checkpoint_value_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_active_checkpoint_value_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_active_checkpoint_value_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_active_checkpoint_value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_active_checkpoint_value_TOP\n"); );
    // Init
    // Body
    value_io_active_checkpoint_value = (0xfU & (IData)(vlSymsp->TOP.svsimTestbench__DOT__dut__DOT__RAT_front_pointer));
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_restore_checkpoint_value_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_restore_checkpoint_value_TOP\n"); );
    // Init
    // Body
    value = 4U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_restore_checkpoint_value_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ value_io_restore_checkpoint_value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_restore_checkpoint_value_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_restore_checkpoint_value 
        = value_io_restore_checkpoint_value;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_restore_checkpoint_value_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*3:0*/ &value_io_restore_checkpoint_value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_restore_checkpoint_value_TOP\n"); );
    // Init
    // Body
    value_io_restore_checkpoint_value = vlSymsp->TOP.svsimTestbench__DOT__io_restore_checkpoint_value;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_checkpoint_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_checkpoint_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_checkpoint 
        = value_io_free_checkpoint;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_checkpoint_TOP\n"); );
    // Init
    // Body
    value_io_free_checkpoint = vlSymsp->TOP.svsimTestbench__DOT__io_free_checkpoint;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_restore_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_restore_checkpoint_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_restore_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_restore_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_restore_checkpoint_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_restore_checkpoint 
        = value_io_restore_checkpoint;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_restore_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_restore_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_restore_checkpoint_TOP\n"); );
    // Init
    // Body
    value_io_restore_checkpoint = vlSymsp->TOP.svsimTestbench__DOT__io_restore_checkpoint;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_create_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_create_checkpoint_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_create_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_create_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_create_checkpoint_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_create_checkpoint 
        = value_io_create_checkpoint;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_create_checkpoint_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_create_checkpoint) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_create_checkpoint_TOP\n"); );
    // Init
    // Body
    value_io_create_checkpoint = vlSymsp->TOP.svsimTestbench__DOT__io_create_checkpoint;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_0_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_0 
        = value_io_free_list_RD_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_0_TOP\n"); );
    // Init
    // Body
    value_io_free_list_RD_0 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_1_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_1 
        = value_io_free_list_RD_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_1_TOP\n"); );
    // Init
    // Body
    value_io_free_list_RD_1 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_2_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_2 
        = value_io_free_list_RD_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_2_TOP\n"); );
    // Init
    // Body
    value_io_free_list_RD_2 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_RD_3_TOP\n"); );
    // Init
    // Body
    value = 7U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ value_io_free_list_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_RD_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_3 
        = value_io_free_list_RD_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*6:0*/ &value_io_free_list_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_RD_3_TOP\n"); );
    // Init
    // Body
    value_io_free_list_RD_3 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_RD_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_0_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_0 
        = value_io_free_list_wr_en_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_0_TOP\n"); );
    // Init
    // Body
    value_io_free_list_wr_en_0 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_1_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_1 
        = value_io_free_list_wr_en_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_1_TOP\n"); );
    // Init
    // Body
    value_io_free_list_wr_en_1 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_2_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_2 
        = value_io_free_list_wr_en_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_2_TOP\n"); );
    // Init
    // Body
    value_io_free_list_wr_en_2 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_free_list_wr_en_3_TOP\n"); );
    // Init
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_io_free_list_wr_en_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_free_list_wr_en_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_3 
        = value_io_free_list_wr_en_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_io_free_list_wr_en_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_free_list_wr_en_3_TOP\n"); );
    // Init
    // Body
    value_io_free_list_wr_en_3 = vlSymsp->TOP.svsimTestbench__DOT__io_free_list_wr_en_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_0_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_0 
        = value_io_instruction_RD_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_0_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RD_0 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_1_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_1 
        = value_io_instruction_RD_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_1_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RD_1 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_2_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_2 
        = value_io_instruction_RD_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_2_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RD_2 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RD_3_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RD_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_3 
        = value_io_instruction_RD_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RD_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RD_3_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RD_3 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RD_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_0_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_0 
        = value_io_instruction_RS2_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_0_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS2_0 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_1_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_1 
        = value_io_instruction_RS2_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_1_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS2_1 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_2_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_2 
        = value_io_instruction_RS2_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_2_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS2_2 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS2_3_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS2_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS2_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_3 
        = value_io_instruction_RS2_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS2_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS2_3_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS2_3 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS2_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_0_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_0_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_0 
        = value_io_instruction_RS1_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_0_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_0_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS1_0 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_0;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_1_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_1_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_1 
        = value_io_instruction_RS1_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_1_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_1_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS1_1 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_1;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_2_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_2_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_2 
        = value_io_instruction_RS1_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_2_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_2_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS1_2 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_2;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidth_io_instruction_RS1_3_TOP\n"); );
    // Init
    // Body
    value = 5U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ value_io_instruction_RS1_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBits_io_instruction_RS1_3_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_3 
        = value_io_instruction_RS1_3;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_3_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*4:0*/ &value_io_instruction_RS1_3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBits_io_instruction_RS1_3_TOP\n"); );
    // Init
    // Body
    value_io_instruction_RS1_3 = vlSymsp->TOP.svsimTestbench__DOT__io_instruction_RS1_3;
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

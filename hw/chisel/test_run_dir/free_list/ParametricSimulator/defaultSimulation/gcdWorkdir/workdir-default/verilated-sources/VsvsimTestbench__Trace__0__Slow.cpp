// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VsvsimTestbench__Syms.h"


VL_ATTR_COLD void VsvsimTestbench___024root__trace_init_sub__TOP__0(VsvsimTestbench___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("svsimTestbench", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+16,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+17,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+9,0,"io_can_allocate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+10,0,"io_can_reallocate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+11,0,"io_free_list_front_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+18,0,"io_commit_bits_RD_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+19,0,"io_commit_bits_RD_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+20,0,"io_commit_bits_RD_valid_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+21,0,"io_commit_bits_RD_valid_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+22,0,"io_commit_bits_RD_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+23,0,"io_commit_bits_RD_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+24,0,"io_commit_bits_RD_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+25,0,"io_commit_bits_RD_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+26,0,"io_commit_bits_free_list_front_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+27,0,"io_commit_bits_RAT_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+28,0,"io_commit_bits_NEXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+29,0,"io_commit_bits_TOS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+30,0,"io_commit_bits_GHR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+31,0,"io_commit_bits_expected_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"io_commit_bits_is_misprediction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+33,0,"io_commit_bits_fetch_packet_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+34,0,"io_commit_bits_br_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+35,0,"io_commit_bits_ROB_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+36,0,"io_commit_bits_T_NT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+37,0,"io_commit_bits_fetch_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"io_commit_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1,0,"io_renamed_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+2,0,"io_renamed_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+3,0,"io_renamed_valid_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+4,0,"io_renamed_valid_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+5,0,"io_renamed_values_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+6,0,"io_renamed_values_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+7,0,"io_renamed_values_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+8,0,"io_renamed_values_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+39,0,"io_rename_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+40,0,"io_rename_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+41,0,"io_rename_valid_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+42,0,"io_rename_valid_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+16,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"io_rename_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"io_rename_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"io_rename_valid_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"io_rename_valid_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"io_renamed_values_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+6,0,"io_renamed_values_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+7,0,"io_renamed_values_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+8,0,"io_renamed_values_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1,0,"io_renamed_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_renamed_valid_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"io_renamed_valid_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_renamed_valid_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"io_commit_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"io_commit_bits_fetch_PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+36,0,"io_commit_bits_T_NT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"io_commit_bits_ROB_index",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+34,0,"io_commit_bits_br_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+33,0,"io_commit_bits_fetch_packet_index",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+32,0,"io_commit_bits_is_misprediction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"io_commit_bits_expected_PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"io_commit_bits_GHR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+29,0,"io_commit_bits_TOS",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+28,0,"io_commit_bits_NEXT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+27,0,"io_commit_bits_RAT_index",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+26,0,"io_commit_bits_free_list_front_pointer",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+22,0,"io_commit_bits_RD_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+23,0,"io_commit_bits_RD_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+24,0,"io_commit_bits_RD_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+25,0,"io_commit_bits_RD_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+18,0,"io_commit_bits_RD_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"io_commit_bits_RD_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"io_commit_bits_RD_valid_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_commit_bits_RD_valid_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"io_free_list_front_pointer",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+10,0,"io_can_reallocate",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"io_can_allocate",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"front_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+12,0,"back_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+13,0,"front_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+14,0,"back_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"valid_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"valid_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"allocate_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"allocate_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"allocate_valid_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"allocate_valid_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"available_elemets",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+10,0,"io_can_reallocate_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VsvsimTestbench___024root__trace_init_top(VsvsimTestbench___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_init_top\n"); );
    // Body
    VsvsimTestbench___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VsvsimTestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VsvsimTestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VsvsimTestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VsvsimTestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VsvsimTestbench___024root__trace_register(VsvsimTestbench___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&VsvsimTestbench___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VsvsimTestbench___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VsvsimTestbench___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VsvsimTestbench___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VsvsimTestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_const_0\n"); );
    // Init
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VsvsimTestbench___024root__trace_full_0_sub_0(VsvsimTestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VsvsimTestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_full_0\n"); );
    // Init
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VsvsimTestbench___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<14>/*447:0*/ VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0;

VL_ATTR_COLD void VsvsimTestbench___024root__trace_full_0_sub_0(VsvsimTestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->svsimTestbench__DOT__io_renamed_valid_0));
    bufp->fullBit(oldp+2,(vlSelf->svsimTestbench__DOT__io_renamed_valid_1));
    bufp->fullBit(oldp+3,(vlSelf->svsimTestbench__DOT__io_renamed_valid_2));
    bufp->fullBit(oldp+4,(vlSelf->svsimTestbench__DOT__io_renamed_valid_3));
    bufp->fullCData(oldp+5,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_0)
                              ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1))
                                  ? (0x7fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)))
                                                ? 0U
                                                : (
                                                   VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                   (((IData)(6U) 
                                                     + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1))))) 
                                              | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                 ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1) 
                                                  >> 5U)] 
                                                 >> 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)))))
                                  : 0U) : 0U)),7);
    bufp->fullCData(oldp+6,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_1)
                              ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2))
                                  ? (0x7fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)))
                                                ? 0U
                                                : (
                                                   VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                   (((IData)(6U) 
                                                     + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2))))) 
                                              | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                 ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2) 
                                                  >> 5U)] 
                                                 >> 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)))))
                                  : 0U) : 0U)),7);
    bufp->fullCData(oldp+7,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_2)
                              ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3))
                                  ? (0x7fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)))
                                                ? 0U
                                                : (
                                                   VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                   (((IData)(6U) 
                                                     + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3))))) 
                                              | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                 ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3) 
                                                  >> 5U)] 
                                                 >> 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)))))
                                  : 0U) : 0U)),7);
    bufp->fullCData(oldp+8,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_3)
                              ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4))
                                  ? (0x7fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)))
                                                ? 0U
                                                : (
                                                   VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                   (((IData)(6U) 
                                                     + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4))))) 
                                              | (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
                                                 ((IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4) 
                                                  >> 5U)] 
                                                 >> 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)))))
                                  : 0U) : 0U)),7);
    bufp->fullBit(oldp+9,((0U != (0x1fU & (((IData)(1U) 
                                            + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)) 
                                           >> 2U)))));
    bufp->fullBit(oldp+10,((0x41U > (0x7fU & ((IData)(5U) 
                                              + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0))))));
    bufp->fullCData(oldp+11,(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer),7);
    bufp->fullCData(oldp+12,(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer),7);
    bufp->fullCData(oldp+13,((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer))),6);
    bufp->fullCData(oldp+14,((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer))),6);
    bufp->fullCData(oldp+15,((0x7fU & ((IData)(1U) 
                                       + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)))),7);
    bufp->fullBit(oldp+16,(vlSelf->svsimTestbench__DOT__clock));
    bufp->fullBit(oldp+17,(vlSelf->svsimTestbench__DOT__reset));
    bufp->fullBit(oldp+18,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_0));
    bufp->fullBit(oldp+19,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_1));
    bufp->fullBit(oldp+20,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_2));
    bufp->fullBit(oldp+21,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_3));
    bufp->fullCData(oldp+22,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_0),7);
    bufp->fullCData(oldp+23,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_1),7);
    bufp->fullCData(oldp+24,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_2),7);
    bufp->fullCData(oldp+25,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_3),7);
    bufp->fullCData(oldp+26,(vlSelf->svsimTestbench__DOT__io_commit_bits_free_list_front_pointer),8);
    bufp->fullCData(oldp+27,(vlSelf->svsimTestbench__DOT__io_commit_bits_RAT_index),4);
    bufp->fullCData(oldp+28,(vlSelf->svsimTestbench__DOT__io_commit_bits_NEXT),7);
    bufp->fullCData(oldp+29,(vlSelf->svsimTestbench__DOT__io_commit_bits_TOS),7);
    bufp->fullSData(oldp+30,(vlSelf->svsimTestbench__DOT__io_commit_bits_GHR),16);
    bufp->fullIData(oldp+31,(vlSelf->svsimTestbench__DOT__io_commit_bits_expected_PC),32);
    bufp->fullBit(oldp+32,(vlSelf->svsimTestbench__DOT__io_commit_bits_is_misprediction));
    bufp->fullCData(oldp+33,(vlSelf->svsimTestbench__DOT__io_commit_bits_fetch_packet_index),2);
    bufp->fullCData(oldp+34,(vlSelf->svsimTestbench__DOT__io_commit_bits_br_type),3);
    bufp->fullCData(oldp+35,(vlSelf->svsimTestbench__DOT__io_commit_bits_ROB_index),6);
    bufp->fullBit(oldp+36,(vlSelf->svsimTestbench__DOT__io_commit_bits_T_NT));
    bufp->fullIData(oldp+37,(vlSelf->svsimTestbench__DOT__io_commit_bits_fetch_PC),32);
    bufp->fullBit(oldp+38,(vlSelf->svsimTestbench__DOT__io_commit_valid));
    bufp->fullBit(oldp+39,(vlSelf->svsimTestbench__DOT__io_rename_valid_0));
    bufp->fullBit(oldp+40,(vlSelf->svsimTestbench__DOT__io_rename_valid_1));
    bufp->fullBit(oldp+41,(vlSelf->svsimTestbench__DOT__io_rename_valid_2));
    bufp->fullBit(oldp+42,(vlSelf->svsimTestbench__DOT__io_rename_valid_3));
    bufp->fullBit(oldp+43,(vlSelf->svsimTestbench__DOT__dut__DOT__flush));
    bufp->fullBit(oldp+44,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_0) 
                            & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_0)) 
                               & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
    bufp->fullBit(oldp+45,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_1) 
                            & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_1)) 
                               & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
    bufp->fullBit(oldp+46,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_2) 
                            & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_2)) 
                               & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
    bufp->fullBit(oldp+47,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_3) 
                            & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_3)) 
                               & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
}

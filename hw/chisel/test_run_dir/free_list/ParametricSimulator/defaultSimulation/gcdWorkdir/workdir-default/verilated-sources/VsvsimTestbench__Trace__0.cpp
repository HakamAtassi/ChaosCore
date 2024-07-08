// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VsvsimTestbench__Syms.h"


void VsvsimTestbench___024root__trace_chg_0_sub_0(VsvsimTestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VsvsimTestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_chg_0\n"); );
    // Init
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VsvsimTestbench___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<14>/*447:0*/ VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0;

void VsvsimTestbench___024root__trace_chg_0_sub_0(VsvsimTestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+0,(vlSelf->svsimTestbench__DOT__io_renamed_valid_0));
        bufp->chgBit(oldp+1,(vlSelf->svsimTestbench__DOT__io_renamed_valid_1));
        bufp->chgBit(oldp+2,(vlSelf->svsimTestbench__DOT__io_renamed_valid_2));
        bufp->chgBit(oldp+3,(vlSelf->svsimTestbench__DOT__io_renamed_valid_3));
        bufp->chgCData(oldp+4,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_0)
                                 ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1))
                                     ? (0x7fU & (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_1)))
                                                   ? 0U
                                                   : 
                                                  (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
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
        bufp->chgCData(oldp+5,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_1)
                                 ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2))
                                     ? (0x7fU & (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_2)))
                                                   ? 0U
                                                   : 
                                                  (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
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
        bufp->chgCData(oldp+6,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_2)
                                 ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3))
                                     ? (0x7fU & (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_3)))
                                                   ? 0U
                                                   : 
                                                  (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
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
        bufp->chgCData(oldp+7,(((IData)(vlSelf->svsimTestbench__DOT__io_renamed_valid_3)
                                 ? ((0x1bfU >= (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4))
                                     ? (0x7fU & (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_4)))
                                                   ? 0U
                                                   : 
                                                  (VsvsimTestbench__ConstPool__CONST_h1bcf5d7c_0[
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
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+8,((0U != (0x1fU & (((IData)(1U) 
                                               + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)) 
                                              >> 2U)))));
        bufp->chgBit(oldp+9,((0x41U > (0x7fU & ((IData)(5U) 
                                                + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0))))));
        bufp->chgCData(oldp+10,(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer),7);
        bufp->chgCData(oldp+11,(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer),7);
        bufp->chgCData(oldp+12,((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__front_pointer))),6);
        bufp->chgCData(oldp+13,((0x3fU & (IData)(vlSelf->svsimTestbench__DOT__dut__DOT__back_pointer))),6);
        bufp->chgCData(oldp+14,((0x7fU & ((IData)(1U) 
                                          + (IData)(vlSelf->svsimTestbench__DOT__dut__DOT____VdfgRegularize_h9fa3630a_0_0)))),7);
    }
    bufp->chgBit(oldp+15,(vlSelf->svsimTestbench__DOT__clock));
    bufp->chgBit(oldp+16,(vlSelf->svsimTestbench__DOT__reset));
    bufp->chgBit(oldp+17,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_0));
    bufp->chgBit(oldp+18,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_1));
    bufp->chgBit(oldp+19,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_2));
    bufp->chgBit(oldp+20,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_3));
    bufp->chgCData(oldp+21,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_0),7);
    bufp->chgCData(oldp+22,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_1),7);
    bufp->chgCData(oldp+23,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_2),7);
    bufp->chgCData(oldp+24,(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_3),7);
    bufp->chgCData(oldp+25,(vlSelf->svsimTestbench__DOT__io_commit_bits_free_list_front_pointer),8);
    bufp->chgCData(oldp+26,(vlSelf->svsimTestbench__DOT__io_commit_bits_RAT_index),4);
    bufp->chgCData(oldp+27,(vlSelf->svsimTestbench__DOT__io_commit_bits_NEXT),7);
    bufp->chgCData(oldp+28,(vlSelf->svsimTestbench__DOT__io_commit_bits_TOS),7);
    bufp->chgSData(oldp+29,(vlSelf->svsimTestbench__DOT__io_commit_bits_GHR),16);
    bufp->chgIData(oldp+30,(vlSelf->svsimTestbench__DOT__io_commit_bits_expected_PC),32);
    bufp->chgBit(oldp+31,(vlSelf->svsimTestbench__DOT__io_commit_bits_is_misprediction));
    bufp->chgCData(oldp+32,(vlSelf->svsimTestbench__DOT__io_commit_bits_fetch_packet_index),2);
    bufp->chgCData(oldp+33,(vlSelf->svsimTestbench__DOT__io_commit_bits_br_type),3);
    bufp->chgCData(oldp+34,(vlSelf->svsimTestbench__DOT__io_commit_bits_ROB_index),6);
    bufp->chgBit(oldp+35,(vlSelf->svsimTestbench__DOT__io_commit_bits_T_NT));
    bufp->chgIData(oldp+36,(vlSelf->svsimTestbench__DOT__io_commit_bits_fetch_PC),32);
    bufp->chgBit(oldp+37,(vlSelf->svsimTestbench__DOT__io_commit_valid));
    bufp->chgBit(oldp+38,(vlSelf->svsimTestbench__DOT__io_rename_valid_0));
    bufp->chgBit(oldp+39,(vlSelf->svsimTestbench__DOT__io_rename_valid_1));
    bufp->chgBit(oldp+40,(vlSelf->svsimTestbench__DOT__io_rename_valid_2));
    bufp->chgBit(oldp+41,(vlSelf->svsimTestbench__DOT__io_rename_valid_3));
    bufp->chgBit(oldp+42,(vlSelf->svsimTestbench__DOT__dut__DOT__flush));
    bufp->chgBit(oldp+43,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_0) 
                           & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_0)) 
                              & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
    bufp->chgBit(oldp+44,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_1) 
                           & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_1)) 
                              & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
    bufp->chgBit(oldp+45,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_2) 
                           & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_2)) 
                              & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
    bufp->chgBit(oldp+46,(((IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_valid_3) 
                           & ((0U != (IData)(vlSelf->svsimTestbench__DOT__io_commit_bits_RD_3)) 
                              & (IData)(vlSelf->svsimTestbench__DOT__io_commit_valid)))));
}

void VsvsimTestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_cleanup\n"); );
    // Init
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}

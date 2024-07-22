// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9513bbd8_0;
extern const VlWide<14>/*447:0*/ Vtop__ConstPool__CONST_hdcbf1b3c_0;

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<16>/*511:0*/ __Vtemp_14;
    VlWide<16>/*511:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<4>/*127:0*/ __Vtemp_41;
    VlWide<4>/*127:0*/ __Vtemp_48;
    VlWide<4>/*127:0*/ __Vtemp_55;
    VlWide<4>/*127:0*/ __Vtemp_62;
    VlWide<4>/*127:0*/ __Vtemp_69;
    VlWide<11>/*351:0*/ __Vtemp_82;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_97;
    VlWide<6>/*191:0*/ __Vtemp_100;
    VlWide<6>/*191:0*/ __Vtemp_103;
    VlWide<4>/*127:0*/ __Vtemp_105;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<8>/*255:0*/ __Vtemp_109;
    VlWide<4>/*127:0*/ __Vtemp_114;
    VlWide<14>/*447:0*/ __Vtemp_115;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__io_commit_valid));
        bufp->chgIData(oldp+1,(vlSelf->top__DOT__io_commit_bits_fetch_PC),32);
        bufp->chgBit(oldp+2,(vlSelf->top__DOT__io_commit_bits_T_NT));
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__dut__DOT__ROB__DOT__io_ROB_output_ROB_index_REG),6);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__io_commit_bits_br_type),3);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__io_commit_bits_fetch_packet_index),2);
        bufp->chgBit(oldp+6,(vlSelf->top__DOT__io_commit_bits_is_misprediction));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__io_commit_bits_exception));
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__io_commit_bits_expected_PC),32);
        bufp->chgSData(oldp+9,(vlSelf->top__DOT__io_commit_bits_GHR),16);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__io_commit_bits_TOS),7);
        bufp->chgCData(oldp+11,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                                  ? (0x7fU & ((vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][2U] 
                                               << 4U) 
                                              | (vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][1U] 
                                                 >> 0x1cU)))
                                  : 0U)),7);
        bufp->chgCData(oldp+12,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                                  ? (0xfU & vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                     [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][1U])
                                  : 0U)),4);
        bufp->chgCData(oldp+13,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                                  ? (0xffU & (vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][1U] 
                                              >> 4U))
                                  : 0U)),8);
        bufp->chgCData(oldp+14,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (0x1fU & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0] 
                                              >> 0xcU))
                                  : 0U)),5);
        bufp->chgCData(oldp+15,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (0x1fU & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0] 
                                              >> 0xcU))
                                  : 0U)),5);
        bufp->chgCData(oldp+16,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (0x1fU & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0] 
                                              >> 0xcU))
                                  : 0U)),5);
        bufp->chgCData(oldp+17,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (0x1fU & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0] 
                                              >> 0xcU))
                                  : 0U)),5);
        bufp->chgCData(oldp+18,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_21)
                                  : 0U)),7);
        bufp->chgCData(oldp+19,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_20)
                                  : 0U)),7);
        bufp->chgCData(oldp+20,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_19)
                                  : 0U)),7);
        bufp->chgCData(oldp+21,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                  ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_18)
                                  : 0U)),7);
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__io_commit_bits_RD_valid_0));
        bufp->chgBit(oldp+23,(vlSelf->top__DOT__io_commit_bits_RD_valid_1));
        bufp->chgBit(oldp+24,(vlSelf->top__DOT__io_commit_bits_RD_valid_2));
        bufp->chgBit(oldp+25,(vlSelf->top__DOT__io_commit_bits_RD_valid_3));
        bufp->chgBit(oldp+26,(vlSelf->top__DOT__io_flush));
        bufp->chgBit(oldp+27,(vlSelf->top__DOT__io_revert_valid));
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__expected_next_PC),32);
        bufp->chgBit(oldp+29,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match) 
                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+30,((1U & ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty)) 
                                     | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__PC_Q__io_enq_valid)))));
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__io_frontend_memory_request_bits_addr),32);
        bufp->chgIData(oldp+32,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty)
                                  ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0)
                                           ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U]
                                           : 0U))),32);
        bufp->chgBit(oldp+33,(((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty))) 
                               && ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0) 
                                   & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][2U]))));
        bufp->chgBit(oldp+34,(((0U != (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_1)) 
                               | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_valid) 
                                  & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_committed) 
                                     & (2U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type)))))));
        __Vtemp_14[0U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_address;
        __Vtemp_14[1U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_address;
        __Vtemp_14[2U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_address;
        __Vtemp_14[3U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_address;
        __Vtemp_14[4U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_address;
        __Vtemp_14[5U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_address;
        __Vtemp_14[6U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_address;
        __Vtemp_14[7U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_address;
        __Vtemp_14[8U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_address;
        __Vtemp_14[9U] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_address;
        __Vtemp_14[0xaU] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_address;
        __Vtemp_14[0xbU] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_address;
        __Vtemp_14[0xcU] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_address;
        __Vtemp_14[0xdU] = vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_address;
        __Vtemp_14[0xeU] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_address)) 
                                     << 0x20U) | (QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_address))));
        __Vtemp_14[0xfU] = (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_address)) 
                                      << 0x20U) | (QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_address))) 
                                    >> 0x20U));
        bufp->chgIData(oldp+35,(((0U != (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_1))
                                  ? (((0U == (0x1fU 
                                              & VL_SHIFTL_III(9,9,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index), 5U)))
                                       ? 0U : (__Vtemp_14[
                                               (((IData)(0x1fU) 
                                                 + 
                                                 (0x1ffU 
                                                  & VL_SHIFTL_III(9,9,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index), 5U))) 
                                                >> 5U)] 
                                               << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,9,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index), 5U))))) 
                                     | (__Vtemp_14[
                                        (0xfU & (VL_SHIFTL_III(9,9,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index), 5U) 
                                                 >> 5U))] 
                                        >> (0x1fU & 
                                            VL_SHIFTL_III(9,9,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index), 5U))))
                                  : (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_valid) 
                                      & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_committed) 
                                         & (2U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type))))
                                      ? vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_address
                                      : 0U))),32);
        bufp->chgCData(oldp+36,((3U & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_1))
                                        ? ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_memory_type) 
                                             << 0x1eU) 
                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_memory_type) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_memory_type) 
                                                   << 0x1aU) 
                                                  | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_memory_type) 
                                                      << 0x18U) 
                                                     | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_memory_type) 
                                                         << 0x16U) 
                                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_memory_type) 
                                                            << 0x14U) 
                                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_memory_type) 
                                                               << 0x12U) 
                                                              | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_memory_type) 
                                                                  << 0x10U) 
                                                                 | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_memory_type) 
                                                                     << 0xeU) 
                                                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_memory_type) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_memory_type) 
                                                                           << 0xaU) 
                                                                          | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_memory_type) 
                                                                              << 8U) 
                                                                             | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_memory_type) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_memory_type) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_memory_type) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type)))))))))))))))) 
                                           >> (0x1fU 
                                               & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index), 1U)))
                                        : (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_valid) 
                                            & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_committed) 
                                               & (2U 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type))))
                                            ? (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type)
                                            : 0U)))),2);
        bufp->chgCData(oldp+37,(((1U & ((~ (IData)(
                                                   (0U 
                                                    != (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_1)))) 
                                        | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_0)))
                                  ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_1)
                                           ? 1U : ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_2)
                                                    ? 2U
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_3)
                                                     ? 3U
                                                     : 
                                                    ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_4)
                                                      ? 4U
                                                      : 
                                                     ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_5)
                                                       ? 5U
                                                       : 
                                                      ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_6)
                                                        ? 6U
                                                        : 
                                                       ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_7)
                                                         ? 7U
                                                         : 
                                                        ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_8)
                                                          ? 8U
                                                          : 
                                                         ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_9)
                                                           ? 9U
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_10)
                                                            ? 0xaU
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_11)
                                                             ? 0xbU
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_12)
                                                              ? 0xcU
                                                              : 
                                                             ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_13)
                                                               ? 0xdU
                                                               : 
                                                              (0xeU 
                                                               | (1U 
                                                                  & (~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_14))))))))))))))))))),4);
        bufp->chgBit(oldp+38,(((7U & ((IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_1) 
                                      + (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_1))) 
                               >= (7U & ((3U & (((0U 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS_type)) 
                                                 & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_0)) 
                                                + (
                                                   (0U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS_type)) 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_1)))) 
                                         + (3U & ((
                                                   (0U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS_type)) 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_2)) 
                                                  + 
                                                  ((0U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS_type)) 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_3)))))))));
        bufp->chgBit(oldp+39,(((7U & ((IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_7) 
                                      + (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_7))) 
                               >= (7U & ((3U & (((1U 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS_type)) 
                                                 & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_0)) 
                                                + (
                                                   (1U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS_type)) 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_1)))) 
                                         + (3U & ((
                                                   (1U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS_type)) 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_2)) 
                                                  + 
                                                  ((1U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS_type)) 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_3)))))))));
        bufp->chgBit(oldp+40,(vlSelf->top__DOT__dut__DOT___FTQ_io_FTQ_valid));
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__dut__DOT___FTQ_io_FTQ_fetch_PC),32);
        __Vtemp_28[0U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_predicted_PC;
        __Vtemp_28[1U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_predicted_PC;
        __Vtemp_28[2U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_predicted_PC;
        __Vtemp_28[3U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_predicted_PC;
        __Vtemp_28[4U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_predicted_PC;
        __Vtemp_28[5U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_predicted_PC;
        __Vtemp_28[6U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_predicted_PC;
        __Vtemp_28[7U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_predicted_PC;
        __Vtemp_28[8U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_predicted_PC;
        __Vtemp_28[9U] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_predicted_PC;
        __Vtemp_28[0xaU] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_predicted_PC;
        __Vtemp_28[0xbU] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_predicted_PC;
        __Vtemp_28[0xcU] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_predicted_PC;
        __Vtemp_28[0xdU] = vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_predicted_PC;
        __Vtemp_28[0xeU] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_predicted_PC)) 
                                     << 0x20U) | (QData)((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_predicted_PC))));
        __Vtemp_28[0xfU] = (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_predicted_PC)) 
                                      << 0x20U) | (QData)((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_predicted_PC))) 
                                    >> 0x20U));
        bufp->chgIData(oldp+42,((((0U == (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                                (0xfU 
                                                                 & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer)), 5U)))
                                   ? 0U : (__Vtemp_28[
                                           (((IData)(0x1fU) 
                                             + (0x1ffU 
                                                & VL_SHIFTL_III(9,9,32, 
                                                                (0xfU 
                                                                 & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer)), 5U))) 
                                            >> 5U)] 
                                           << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0xfU 
                                                                   & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer)), 5U))))) 
                                 | (__Vtemp_28[(0xfU 
                                                & (VL_SHIFTL_III(9,9,32, 
                                                                 (0xfU 
                                                                  & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer)), 5U) 
                                                   >> 5U))] 
                                    >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                              (0xfU 
                                                               & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer)), 5U))))),32);
        bufp->chgBit(oldp+43,((1U & ((((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_T_NT) 
                                       << 0xfU) | (
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_T_NT) 
                                                    << 0xeU) 
                                                   | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_T_NT) 
                                                       << 0xdU) 
                                                      | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_T_NT) 
                                                          << 0xcU) 
                                                         | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_T_NT) 
                                                             << 0xbU) 
                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_T_NT) 
                                                                << 0xaU) 
                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_T_NT) 
                                                                   << 9U) 
                                                                  | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_T_NT) 
                                                                      << 8U) 
                                                                     | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_T_NT) 
                                                                         << 7U) 
                                                                        | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_T_NT) 
                                                                            << 6U) 
                                                                           | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_T_NT) 
                                                                               << 5U) 
                                                                              | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_T_NT) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_T_NT) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_T_NT) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_T_NT) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_T_NT)))))))))))))))) 
                                     >> (0xfU & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer))))));
        bufp->chgCData(oldp+44,(vlSelf->top__DOT__dut__DOT___FTQ_io_FTQ_br_type),3);
        bufp->chgCData(oldp+45,((3U & (vlSelf->top__DOT__dut__DOT__FTQ__DOT___GEN 
                                       >> (0x1fU & 
                                           VL_SHIFTL_III(5,5,32, 
                                                         (0xfU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer)), 1U))))),2);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__dut__DOT___FTQ_io_FTQ_resolved_PC),32);
        bufp->chgBit(oldp+47,((1U & (IData)((vlSelf->top__DOT__dut__DOT__ROB__DOT___GEN 
                                             >> (0x3fU 
                                                 & (IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__front_pointer)))))));
        bufp->chgBit(oldp+48,(vlSelf->top__DOT__dut__DOT___ROB_io_ROB_output_ROB_entries_0_valid));
        bufp->chgBit(oldp+49,(vlSelf->top__DOT__dut__DOT___ROB_io_ROB_output_ROB_entries_1_valid));
        bufp->chgBit(oldp+50,(vlSelf->top__DOT__dut__DOT___ROB_io_ROB_output_ROB_entries_2_valid));
        bufp->chgBit(oldp+51,(vlSelf->top__DOT__dut__DOT___ROB_io_ROB_output_ROB_entries_3_valid));
        bufp->chgBit(oldp+52,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                               & vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                               [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0])));
        bufp->chgBit(oldp+53,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                               & vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                               [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0])));
        bufp->chgBit(oldp+54,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                               & vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                               [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0])));
        bufp->chgBit(oldp+55,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                               & vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                               [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0])));
        bufp->chgBit(oldp+56,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                               & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0] 
                                  >> 1U))));
        bufp->chgBit(oldp+57,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                               & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0] 
                                  >> 1U))));
        bufp->chgBit(oldp+58,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                               & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0] 
                                  >> 1U))));
        bufp->chgBit(oldp+59,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                               & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0] 
                                  >> 1U))));
        bufp->chgBit(oldp+60,(vlSelf->top__DOT__dut__DOT__BRU__DOT__branch_commit));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_valid));
        bufp->chgBit(oldp+62,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1) 
                               & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG))));
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_target_address),32);
        bufp->chgBit(oldp+64,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1) 
                               & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG))));
        bufp->chgCData(oldp+65,(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_FTQ_index),4);
        bufp->chgCData(oldp+66,(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_fetch_packet_index),2);
        bufp->chgBit(oldp+67,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__full)))));
        bufp->chgBit(oldp+68,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__empty)))));
        bufp->chgBit(oldp+69,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_valid));
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_fetch_PC),32);
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_predicted_PC),32);
        bufp->chgBit(oldp+72,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_T_NT));
        bufp->chgCData(oldp+73,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_br_type),3);
        bufp->chgCData(oldp+74,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_dominant_index),2);
        bufp->chgIData(oldp+75,(vlSelf->top__DOT__dut__DOT___frontend_io_predictions_bits_resolved_PC),32);
        bufp->chgCData(oldp+76,((0xfU & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__back_pointer))),4);
        bufp->chgCData(oldp+77,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer),5);
        bufp->chgCData(oldp+78,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__back_pointer),5);
        bufp->chgCData(oldp+79,((0xfU & (IData)(vlSelf->top__DOT__dut__DOT__FTQ__DOT__front_pointer))),4);
        bufp->chgBit(oldp+80,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_valid));
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_fetch_PC),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_predicted_PC),32);
        bufp->chgBit(oldp+83,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_T_NT));
        bufp->chgCData(oldp+84,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_br_type),3);
        bufp->chgCData(oldp+85,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_dominant_index),2);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_0_resolved_PC),32);
        bufp->chgBit(oldp+87,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_valid));
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_fetch_PC),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_predicted_PC),32);
        bufp->chgBit(oldp+90,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_T_NT));
        bufp->chgCData(oldp+91,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_br_type),3);
        bufp->chgCData(oldp+92,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_dominant_index),2);
        bufp->chgIData(oldp+93,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_1_resolved_PC),32);
        bufp->chgBit(oldp+94,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_valid));
        bufp->chgIData(oldp+95,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_fetch_PC),32);
        bufp->chgIData(oldp+96,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_predicted_PC),32);
        bufp->chgBit(oldp+97,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_T_NT));
        bufp->chgCData(oldp+98,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_br_type),3);
        bufp->chgCData(oldp+99,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_dominant_index),2);
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_2_resolved_PC),32);
        bufp->chgBit(oldp+101,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_valid));
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_fetch_PC),32);
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_predicted_PC),32);
        bufp->chgBit(oldp+104,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_T_NT));
        bufp->chgCData(oldp+105,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_br_type),3);
        bufp->chgCData(oldp+106,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_dominant_index),2);
        bufp->chgIData(oldp+107,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_3_resolved_PC),32);
        bufp->chgBit(oldp+108,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_valid));
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_fetch_PC),32);
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_predicted_PC),32);
        bufp->chgBit(oldp+111,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_T_NT));
        bufp->chgCData(oldp+112,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_br_type),3);
        bufp->chgCData(oldp+113,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_dominant_index),2);
        bufp->chgIData(oldp+114,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_4_resolved_PC),32);
        bufp->chgBit(oldp+115,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_valid));
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_fetch_PC),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_predicted_PC),32);
        bufp->chgBit(oldp+118,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_T_NT));
        bufp->chgCData(oldp+119,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_br_type),3);
        bufp->chgCData(oldp+120,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_dominant_index),2);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_5_resolved_PC),32);
        bufp->chgBit(oldp+122,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_valid));
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_fetch_PC),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_predicted_PC),32);
        bufp->chgBit(oldp+125,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_T_NT));
        bufp->chgCData(oldp+126,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_br_type),3);
        bufp->chgCData(oldp+127,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_dominant_index),2);
        bufp->chgIData(oldp+128,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_6_resolved_PC),32);
        bufp->chgBit(oldp+129,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_valid));
        bufp->chgIData(oldp+130,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_fetch_PC),32);
        bufp->chgIData(oldp+131,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_predicted_PC),32);
        bufp->chgBit(oldp+132,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_T_NT));
        bufp->chgCData(oldp+133,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_br_type),3);
        bufp->chgCData(oldp+134,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_dominant_index),2);
        bufp->chgIData(oldp+135,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_7_resolved_PC),32);
        bufp->chgBit(oldp+136,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_valid));
        bufp->chgIData(oldp+137,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_fetch_PC),32);
        bufp->chgIData(oldp+138,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_predicted_PC),32);
        bufp->chgBit(oldp+139,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_T_NT));
        bufp->chgCData(oldp+140,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_br_type),3);
        bufp->chgCData(oldp+141,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_dominant_index),2);
        bufp->chgIData(oldp+142,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_8_resolved_PC),32);
        bufp->chgBit(oldp+143,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_valid));
        bufp->chgIData(oldp+144,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_fetch_PC),32);
        bufp->chgIData(oldp+145,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_predicted_PC),32);
        bufp->chgBit(oldp+146,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_T_NT));
        bufp->chgCData(oldp+147,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_br_type),3);
        bufp->chgCData(oldp+148,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_dominant_index),2);
        bufp->chgIData(oldp+149,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_9_resolved_PC),32);
        bufp->chgBit(oldp+150,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_valid));
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_fetch_PC),32);
        bufp->chgIData(oldp+152,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_predicted_PC),32);
        bufp->chgBit(oldp+153,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_T_NT));
        bufp->chgCData(oldp+154,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_br_type),3);
        bufp->chgCData(oldp+155,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_dominant_index),2);
        bufp->chgIData(oldp+156,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_10_resolved_PC),32);
        bufp->chgBit(oldp+157,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_valid));
        bufp->chgIData(oldp+158,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_fetch_PC),32);
        bufp->chgIData(oldp+159,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_predicted_PC),32);
        bufp->chgBit(oldp+160,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_T_NT));
        bufp->chgCData(oldp+161,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_br_type),3);
        bufp->chgCData(oldp+162,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_dominant_index),2);
        bufp->chgIData(oldp+163,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_11_resolved_PC),32);
        bufp->chgBit(oldp+164,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_valid));
        bufp->chgIData(oldp+165,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_fetch_PC),32);
        bufp->chgIData(oldp+166,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_predicted_PC),32);
        bufp->chgBit(oldp+167,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_T_NT));
        bufp->chgCData(oldp+168,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_br_type),3);
        bufp->chgCData(oldp+169,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_dominant_index),2);
        bufp->chgIData(oldp+170,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_12_resolved_PC),32);
        bufp->chgBit(oldp+171,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_valid));
        bufp->chgIData(oldp+172,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_fetch_PC),32);
        bufp->chgIData(oldp+173,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_predicted_PC),32);
        bufp->chgBit(oldp+174,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_T_NT));
        bufp->chgCData(oldp+175,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_br_type),3);
        bufp->chgCData(oldp+176,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_dominant_index),2);
        bufp->chgIData(oldp+177,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_13_resolved_PC),32);
        bufp->chgBit(oldp+178,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_valid));
        bufp->chgIData(oldp+179,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_fetch_PC),32);
        bufp->chgIData(oldp+180,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_predicted_PC),32);
        bufp->chgBit(oldp+181,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_T_NT));
        bufp->chgCData(oldp+182,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_br_type),3);
        bufp->chgCData(oldp+183,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_dominant_index),2);
        bufp->chgIData(oldp+184,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_14_resolved_PC),32);
        bufp->chgBit(oldp+185,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_valid));
        bufp->chgIData(oldp+186,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_fetch_PC),32);
        bufp->chgIData(oldp+187,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_predicted_PC),32);
        bufp->chgBit(oldp+188,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_T_NT));
        bufp->chgCData(oldp+189,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_br_type),3);
        bufp->chgCData(oldp+190,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_dominant_index),2);
        bufp->chgIData(oldp+191,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__FTQ_15_resolved_PC),32);
        bufp->chgBit(oldp+192,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__dq));
        bufp->chgBit(oldp+193,(vlSelf->top__DOT__dut__DOT__FTQ__DOT__full));
        bufp->chgBit(oldp+194,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__full)))));
        bufp->chgBit(oldp+195,(vlSelf->top__DOT__dut__DOT____Vcellinp__ROB__io_ROB_packet_valid));
        bufp->chgIData(oldp+196,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_fetch_PC),32);
        bufp->chgBit(oldp+197,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready));
        bufp->chgBit(oldp+198,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready));
        bufp->chgCData(oldp+199,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RDold),5);
        bufp->chgCData(oldp+200,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RD),7);
        bufp->chgBit(oldp+201,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RD_valid));
        bufp->chgCData(oldp+202,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RS1),7);
        bufp->chgBit(oldp+203,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid));
        bufp->chgCData(oldp+204,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RS2),7);
        bufp->chgBit(oldp+205,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid));
        bufp->chgIData(oldp+206,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IMM),21);
        bufp->chgCData(oldp+207,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3),3);
        bufp->chgCData(oldp+208,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_packet_index),2);
        bufp->chgCData(oldp+209,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][2U] 
                                           >> 0x19U))),6);
        bufp->chgCData(oldp+210,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index),4);
        bufp->chgCData(oldp+211,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][3U] 
                                          >> 3U))),4);
        bufp->chgCData(oldp+212,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_instructionType),5);
        bufp->chgCData(oldp+213,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_portID),2);
        bufp->chgCData(oldp+214,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS_type),2);
        bufp->chgBit(oldp+215,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU));
        bufp->chgBit(oldp+216,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit));
        bufp->chgBit(oldp+217,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs));
        bufp->chgBit(oldp+218,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT));
        bufp->chgBit(oldp+219,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY));
        bufp->chgBit(oldp+220,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM));
        bufp->chgCData(oldp+221,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_memory_type),2);
        bufp->chgCData(oldp+222,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_access_width),2);
        bufp->chgBit(oldp+223,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready));
        bufp->chgBit(oldp+224,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready));
        bufp->chgCData(oldp+225,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RDold),5);
        bufp->chgCData(oldp+226,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RD),7);
        bufp->chgBit(oldp+227,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RD_valid));
        bufp->chgCData(oldp+228,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RS1),7);
        bufp->chgBit(oldp+229,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid));
        bufp->chgCData(oldp+230,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RS2),7);
        bufp->chgBit(oldp+231,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid));
        bufp->chgIData(oldp+232,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IMM),21);
        bufp->chgCData(oldp+233,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3),3);
        bufp->chgCData(oldp+234,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_packet_index),2);
        bufp->chgCData(oldp+235,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][5U] 
                                           >> 0x13U))),6);
        bufp->chgCData(oldp+236,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index),4);
        bufp->chgCData(oldp+237,((0xfU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][6U] 
                                           << 3U) | 
                                          (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][5U] 
                                           >> 0x1dU)))),4);
        bufp->chgCData(oldp+238,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_instructionType),5);
        bufp->chgCData(oldp+239,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_portID),2);
        bufp->chgCData(oldp+240,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS_type),2);
        bufp->chgBit(oldp+241,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU));
        bufp->chgBit(oldp+242,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit));
        bufp->chgBit(oldp+243,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs));
        bufp->chgBit(oldp+244,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT));
        bufp->chgBit(oldp+245,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY));
        bufp->chgBit(oldp+246,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM));
        bufp->chgCData(oldp+247,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_memory_type),2);
        bufp->chgCData(oldp+248,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_access_width),2);
        bufp->chgBit(oldp+249,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready));
        bufp->chgBit(oldp+250,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready));
        bufp->chgCData(oldp+251,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RDold),5);
        bufp->chgCData(oldp+252,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RD),7);
        bufp->chgBit(oldp+253,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RD_valid));
        bufp->chgCData(oldp+254,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RS1),7);
        bufp->chgBit(oldp+255,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid));
        bufp->chgCData(oldp+256,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RS2),7);
        bufp->chgBit(oldp+257,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid));
        bufp->chgIData(oldp+258,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IMM),21);
        bufp->chgCData(oldp+259,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3),3);
        bufp->chgCData(oldp+260,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_packet_index),2);
        bufp->chgCData(oldp+261,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][8U] 
                                           >> 0xdU))),6);
        bufp->chgCData(oldp+262,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index),4);
        bufp->chgCData(oldp+263,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][8U] 
                                          >> 0x17U))),4);
        bufp->chgCData(oldp+264,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_instructionType),5);
        bufp->chgCData(oldp+265,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_portID),2);
        bufp->chgCData(oldp+266,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS_type),2);
        bufp->chgBit(oldp+267,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU));
        bufp->chgBit(oldp+268,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit));
        bufp->chgBit(oldp+269,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs));
        bufp->chgBit(oldp+270,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT));
        bufp->chgBit(oldp+271,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY));
        bufp->chgBit(oldp+272,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM));
        bufp->chgCData(oldp+273,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_memory_type),2);
        bufp->chgCData(oldp+274,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_access_width),2);
        bufp->chgBit(oldp+275,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready));
        bufp->chgBit(oldp+276,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready));
        bufp->chgCData(oldp+277,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RDold),5);
        bufp->chgCData(oldp+278,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD),7);
        bufp->chgBit(oldp+279,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD_valid));
        bufp->chgCData(oldp+280,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RS1),7);
        bufp->chgBit(oldp+281,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid));
        bufp->chgCData(oldp+282,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RS2),7);
        bufp->chgBit(oldp+283,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid));
        bufp->chgIData(oldp+284,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IMM),21);
        bufp->chgCData(oldp+285,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3),3);
        bufp->chgCData(oldp+286,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_packet_index),2);
        bufp->chgCData(oldp+287,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xbU] 
                                           >> 7U))),6);
        bufp->chgCData(oldp+288,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index),4);
        bufp->chgCData(oldp+289,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xbU] 
                                          >> 0x11U))),4);
        bufp->chgCData(oldp+290,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_instructionType),5);
        bufp->chgCData(oldp+291,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_portID),2);
        bufp->chgCData(oldp+292,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS_type),2);
        bufp->chgBit(oldp+293,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU));
        bufp->chgBit(oldp+294,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit));
        bufp->chgBit(oldp+295,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs));
        bufp->chgBit(oldp+296,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT));
        bufp->chgBit(oldp+297,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY));
        bufp->chgBit(oldp+298,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM));
        bufp->chgCData(oldp+299,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_memory_type),2);
        bufp->chgCData(oldp+300,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_access_width),2);
        bufp->chgBit(oldp+301,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_0));
        bufp->chgBit(oldp+302,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_1));
        bufp->chgBit(oldp+303,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_2));
        bufp->chgBit(oldp+304,(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_3));
        bufp->chgSData(oldp+305,((0xffffU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xcU] 
                                             >> 0xcU))),16);
        bufp->chgCData(oldp+306,((0x7fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                            << 4U) 
                                           | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xcU] 
                                              >> 0x1cU)))),7);
        bufp->chgCData(oldp+307,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                           >> 3U))),7);
        bufp->chgCData(oldp+308,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                          >> 0xaU))),4);
        bufp->chgCData(oldp+309,((0xffU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                           >> 0xeU))),8);
        bufp->chgCData(oldp+310,(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD),7);
        bufp->chgIData(oldp+311,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1)
                                   ? vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG
                                   : vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgBit(oldp+312,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1)
                                 ? (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_valid_REG)
                                 : (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG))));
        bufp->chgIData(oldp+313,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1)
                                   ? vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG
                                   : vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG)),32);
        bufp->chgCData(oldp+314,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1)
                                   ? (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG)
                                   : (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG))),4);
        bufp->chgCData(oldp+315,(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_ROB_index),6);
        bufp->chgBit(oldp+316,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+317,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgIData(oldp+318,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgBit(oldp+319,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgIData(oldp+320,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+321,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+322,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgCData(oldp+323,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+324,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgBit(oldp+325,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+326,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgIData(oldp+327,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgBit(oldp+328,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgIData(oldp+329,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+330,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+331,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgCData(oldp+332,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+333,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgBit(oldp+334,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+335,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgIData(oldp+336,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_address_REG),32);
        bufp->chgCData(oldp+337,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_memory_type_REG),2);
        bufp->chgCData(oldp+338,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_access_width_REG),2);
        bufp->chgBit(oldp+339,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_is_unsigned_REG));
        bufp->chgIData(oldp+340,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_wr_data_REG),32);
        bufp->chgCData(oldp+341,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgBit(oldp+342,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                                & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0] 
                                   >> 1U))));
        bufp->chgCData(oldp+343,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0] 
                                            >> 2U))
                                   : 0U)),2);
        bufp->chgBit(oldp+344,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                                & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0] 
                                   >> 1U))));
        bufp->chgCData(oldp+345,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0] 
                                            >> 2U))
                                   : 0U)),2);
        bufp->chgBit(oldp+346,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                                & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0] 
                                   >> 1U))));
        bufp->chgCData(oldp+347,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0] 
                                            >> 2U))
                                   : 0U)),2);
        bufp->chgBit(oldp+348,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                                & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0] 
                                   >> 1U))));
        bufp->chgCData(oldp+349,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0] 
                                            >> 2U))
                                   : 0U)),2);
        bufp->chgCData(oldp+350,(vlSelf->top__DOT__dut__DOT__ROB__DOT__back_index),6);
        bufp->chgCData(oldp+351,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_RS_io_RF_inputs_0_bits_ROB_index),6);
        bufp->chgIData(oldp+352,(vlSelf->top__DOT__dut__DOT___ROB_io_PC_file_exec_data),32);
        bufp->chgBit(oldp+353,(vlSelf->top__DOT__dut__DOT__ROB__DOT__full));
        bufp->chgCData(oldp+354,(vlSelf->top__DOT__dut__DOT__ROB__DOT__front_pointer),7);
        bufp->chgCData(oldp+355,(vlSelf->top__DOT__dut__DOT__ROB__DOT__back_pointer),7);
        bufp->chgBit(oldp+356,(vlSelf->top__DOT__dut__DOT__ROB__DOT__allocate));
        bufp->chgBit(oldp+357,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_0));
        bufp->chgBit(oldp+358,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_1));
        bufp->chgBit(oldp+359,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_2));
        bufp->chgBit(oldp+360,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_3));
        bufp->chgBit(oldp+361,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_4));
        bufp->chgBit(oldp+362,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_5));
        bufp->chgBit(oldp+363,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_6));
        bufp->chgBit(oldp+364,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_7));
        bufp->chgBit(oldp+365,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_8));
        bufp->chgBit(oldp+366,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_9));
        bufp->chgBit(oldp+367,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_10));
        bufp->chgBit(oldp+368,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_11));
        bufp->chgBit(oldp+369,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_12));
        bufp->chgBit(oldp+370,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_13));
        bufp->chgBit(oldp+371,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_14));
        bufp->chgBit(oldp+372,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_15));
        bufp->chgBit(oldp+373,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_16));
        bufp->chgBit(oldp+374,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_17));
        bufp->chgBit(oldp+375,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_18));
        bufp->chgBit(oldp+376,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_19));
        bufp->chgBit(oldp+377,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_20));
        bufp->chgBit(oldp+378,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_21));
        bufp->chgBit(oldp+379,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_22));
        bufp->chgBit(oldp+380,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_23));
        bufp->chgBit(oldp+381,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_24));
        bufp->chgBit(oldp+382,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_25));
        bufp->chgBit(oldp+383,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_26));
        bufp->chgBit(oldp+384,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_27));
        bufp->chgBit(oldp+385,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_28));
        bufp->chgBit(oldp+386,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_29));
        bufp->chgBit(oldp+387,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_30));
        bufp->chgBit(oldp+388,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_31));
        bufp->chgBit(oldp+389,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_32));
        bufp->chgBit(oldp+390,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_33));
        bufp->chgBit(oldp+391,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_34));
        bufp->chgBit(oldp+392,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_35));
        bufp->chgBit(oldp+393,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_36));
        bufp->chgBit(oldp+394,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_37));
        bufp->chgBit(oldp+395,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_38));
        bufp->chgBit(oldp+396,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_39));
        bufp->chgBit(oldp+397,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_40));
        bufp->chgBit(oldp+398,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_41));
        bufp->chgBit(oldp+399,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_42));
        bufp->chgBit(oldp+400,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_43));
        bufp->chgBit(oldp+401,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_44));
        bufp->chgBit(oldp+402,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_45));
        bufp->chgBit(oldp+403,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_46));
        bufp->chgBit(oldp+404,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_47));
        bufp->chgBit(oldp+405,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_48));
        bufp->chgBit(oldp+406,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_49));
        bufp->chgBit(oldp+407,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_50));
        bufp->chgBit(oldp+408,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_51));
        bufp->chgBit(oldp+409,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_52));
        bufp->chgBit(oldp+410,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_53));
        bufp->chgBit(oldp+411,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_54));
        bufp->chgBit(oldp+412,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_55));
        bufp->chgBit(oldp+413,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_56));
        bufp->chgBit(oldp+414,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_57));
        bufp->chgBit(oldp+415,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_58));
        bufp->chgBit(oldp+416,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_59));
        bufp->chgBit(oldp+417,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_60));
        bufp->chgBit(oldp+418,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_61));
        bufp->chgBit(oldp+419,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_62));
        bufp->chgBit(oldp+420,(vlSelf->top__DOT__dut__DOT__ROB__DOT__row_valid_mem_63));
        bufp->chgCData(oldp+421,(vlSelf->top__DOT__dut__DOT__ROB__DOT__front_index),6);
        bufp->chgBit(oldp+422,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_valid) 
                                & (0U == (IData)(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_fetch_packet_index)))));
        bufp->chgBit(oldp+423,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (0U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgBit(oldp+424,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (0U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgCData(oldp+425,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+426,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__io_FU_output_valid_REG),2);
        bufp->chgCData(oldp+427,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG),2);
        bufp->chgCData(oldp+428,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG),2);
        bufp->chgCData(oldp+429,(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_valid),2);
        bufp->chgBit(oldp+430,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_valid) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_fetch_packet_index)))));
        bufp->chgBit(oldp+431,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgBit(oldp+432,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgCData(oldp+433,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgBit(oldp+434,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_valid) 
                                & (2U == (IData)(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_fetch_packet_index)))));
        bufp->chgBit(oldp+435,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (2U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgBit(oldp+436,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (2U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgCData(oldp+437,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgBit(oldp+438,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_valid) 
                                & (3U == (IData)(vlSelf->top__DOT__dut__DOT___backend_io_FU_outputs_0_bits_fetch_packet_index)))));
        bufp->chgBit(oldp+439,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (3U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgBit(oldp+440,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                & (3U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG)))));
        bufp->chgCData(oldp+441,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgIData(oldp+442,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+443,((((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RDold) 
                                   << 0xcU) | ((0xff0U 
                                                & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][1U] 
                                                   >> 3U)) 
                                               | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_memory_type) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_0)))))),17);
        bufp->chgIData(oldp+444,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+445,((((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RDold) 
                                   << 0xcU) | ((0xff0U 
                                                & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][4U] 
                                                   << 3U)) 
                                               | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_memory_type) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_1)))))),17);
        bufp->chgIData(oldp+446,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+447,((((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RDold) 
                                   << 0xcU) | ((0xff0U 
                                                & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][7U] 
                                                    << 9U) 
                                                   | (0x1f0U 
                                                      & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][6U] 
                                                         >> 0x17U)))) 
                                               | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_memory_type) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_2)))))),17);
        bufp->chgIData(oldp+448,(((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+449,((((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RDold) 
                                   << 0xcU) | ((0xff0U 
                                                & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][9U] 
                                                   >> 0x11U)) 
                                               | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_memory_type) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_valid_bits_3)))))),17);
        if (vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_en_d0) {
            __Vtemp_30[0U] = vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][0U];
            __Vtemp_30[1U] = vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][1U];
            __Vtemp_30[2U] = vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][2U];
        } else {
            __Vtemp_30[0U] = 0U;
            __Vtemp_30[1U] = 0U;
            __Vtemp_30[2U] = 0U;
        }
        bufp->chgWData(oldp+450,(__Vtemp_30),74);
        if (vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0) {
            __Vtemp_32[0U] = vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U];
            __Vtemp_32[1U] = vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][1U];
            __Vtemp_32[2U] = vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][2U];
        } else {
            __Vtemp_32[0U] = 0U;
            __Vtemp_32[1U] = 0U;
            __Vtemp_32[2U] = 0U;
        }
        bufp->chgWData(oldp+453,(__Vtemp_32),74);
        __Vtemp_34[0U] = (IData)((((QData)((IData)(
                                                   (0xffffU 
                                                    & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xcU] 
                                                       >> 0xcU)))) 
                                   << 0x2cU) | (((QData)((IData)(
                                                                 (0xfffU 
                                                                  & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                                                     >> 0xaU)))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_fetch_PC)))));
        __Vtemp_34[1U] = ((0xf0000000U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                          << 0x19U)) 
                          | (IData)(((((QData)((IData)(
                                                       (0xffffU 
                                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xcU] 
                                                           >> 0xcU)))) 
                                       << 0x2cU) | 
                                      (((QData)((IData)(
                                                        (0xfffU 
                                                         & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                                            >> 0xaU)))) 
                                        << 0x20U) | (QData)((IData)(vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_fetch_PC)))) 
                                     >> 0x20U)));
        __Vtemp_34[2U] = ((0x3f8U & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                      << 7U) | (0x78U 
                                                & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xcU] 
                                                   >> 0x19U)))) 
                          | (7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][0xdU] 
                                   >> 7U)));
        bufp->chgWData(oldp+456,(__Vtemp_34),74);
        bufp->chgBit(oldp+459,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__empty)))));
        bufp->chgBit(oldp+460,((0U != (7U & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__availalbe_RS_entries) 
                                             >> 2U)))));
        bufp->chgBit(oldp+461,((0U != (7U & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                             >> 2U)))));
        bufp->chgBit(oldp+462,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_ready_bits_RS1_ready));
        bufp->chgBit(oldp+463,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_ready_bits_RS2_ready));
        bufp->chgCData(oldp+464,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RDold),5);
        bufp->chgCData(oldp+465,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RD),7);
        bufp->chgBit(oldp+466,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RD_valid));
        bufp->chgCData(oldp+467,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RS1),7);
        bufp->chgBit(oldp+468,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RS1_valid));
        bufp->chgCData(oldp+469,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RS2),7);
        bufp->chgBit(oldp+470,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RS2_valid));
        bufp->chgIData(oldp+471,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_IMM),21);
        bufp->chgCData(oldp+472,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_FUNCT3),3);
        bufp->chgCData(oldp+473,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_packet_index),2);
        bufp->chgCData(oldp+474,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_ROB_index),6);
        bufp->chgCData(oldp+475,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_MOB_index),4);
        bufp->chgCData(oldp+476,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_FTQ_index),4);
        bufp->chgCData(oldp+477,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_instructionType),5);
        bufp->chgCData(oldp+478,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_portID),2);
        bufp->chgCData(oldp+479,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_RS_type),2);
        bufp->chgBit(oldp+480,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_needs_ALU));
        bufp->chgBit(oldp+481,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_needs_branch_unit));
        bufp->chgBit(oldp+482,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_needs_CSRs));
        bufp->chgBit(oldp+483,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_SUBTRACT));
        bufp->chgBit(oldp+484,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_MULTIPLY));
        bufp->chgBit(oldp+485,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_IS_IMM));
        bufp->chgCData(oldp+486,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_memory_type),2);
        bufp->chgCData(oldp+487,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG_access_width),2);
        bufp->chgBit(oldp+488,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_ready_bits_RS1_ready));
        bufp->chgBit(oldp+489,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_ready_bits_RS2_ready));
        bufp->chgCData(oldp+490,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RDold),5);
        bufp->chgCData(oldp+491,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RD),7);
        bufp->chgBit(oldp+492,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RD_valid));
        bufp->chgCData(oldp+493,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RS1),7);
        bufp->chgBit(oldp+494,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RS1_valid));
        bufp->chgCData(oldp+495,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RS2),7);
        bufp->chgBit(oldp+496,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RS2_valid));
        bufp->chgIData(oldp+497,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_IMM),21);
        bufp->chgCData(oldp+498,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_FUNCT3),3);
        bufp->chgCData(oldp+499,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_packet_index),2);
        bufp->chgCData(oldp+500,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_ROB_index),6);
        bufp->chgCData(oldp+501,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_MOB_index),4);
        bufp->chgCData(oldp+502,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_FTQ_index),4);
        bufp->chgCData(oldp+503,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_instructionType),5);
        bufp->chgCData(oldp+504,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_portID),2);
        bufp->chgCData(oldp+505,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_RS_type),2);
        bufp->chgBit(oldp+506,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_needs_ALU));
        bufp->chgBit(oldp+507,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_needs_branch_unit));
        bufp->chgBit(oldp+508,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_needs_CSRs));
        bufp->chgBit(oldp+509,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_SUBTRACT));
        bufp->chgBit(oldp+510,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_MULTIPLY));
        bufp->chgBit(oldp+511,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_IS_IMM));
        bufp->chgCData(oldp+512,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_memory_type),2);
        bufp->chgCData(oldp+513,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG_access_width),2);
        bufp->chgBit(oldp+514,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_ready_bits_RS1_ready));
        bufp->chgBit(oldp+515,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_ready_bits_RS2_ready));
        bufp->chgCData(oldp+516,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RDold),5);
        bufp->chgCData(oldp+517,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RD),7);
        bufp->chgBit(oldp+518,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RD_valid));
        bufp->chgCData(oldp+519,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RS1),7);
        bufp->chgBit(oldp+520,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RS1_valid));
        bufp->chgCData(oldp+521,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RS2),7);
        bufp->chgBit(oldp+522,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RS2_valid));
        bufp->chgIData(oldp+523,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_IMM),21);
        bufp->chgCData(oldp+524,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_FUNCT3),3);
        bufp->chgCData(oldp+525,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_packet_index),2);
        bufp->chgCData(oldp+526,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_ROB_index),6);
        bufp->chgCData(oldp+527,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_MOB_index),4);
        bufp->chgCData(oldp+528,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_FTQ_index),4);
        bufp->chgCData(oldp+529,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_instructionType),5);
        bufp->chgCData(oldp+530,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_portID),2);
        bufp->chgCData(oldp+531,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_RS_type),2);
        bufp->chgBit(oldp+532,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_needs_ALU));
        bufp->chgBit(oldp+533,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_needs_branch_unit));
        bufp->chgBit(oldp+534,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_needs_CSRs));
        bufp->chgBit(oldp+535,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_SUBTRACT));
        bufp->chgBit(oldp+536,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_MULTIPLY));
        bufp->chgBit(oldp+537,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_IS_IMM));
        bufp->chgCData(oldp+538,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_memory_type),2);
        bufp->chgCData(oldp+539,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG_access_width),2);
        bufp->chgCData(oldp+540,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG_RD),7);
        bufp->chgIData(oldp+541,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG_IMM),21);
        bufp->chgCData(oldp+542,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG_FUNCT3),3);
        bufp->chgCData(oldp+543,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG_MOB_index),4);
        bufp->chgCData(oldp+544,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG_memory_type),2);
        bufp->chgCData(oldp+545,(vlSelf->top__DOT__dut__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG_access_width),2);
        bufp->chgBit(oldp+546,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0_io_FU_input_valid_REG));
        bufp->chgBit(oldp+547,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1_io_FU_input_valid_REG));
        bufp->chgBit(oldp+548,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2_io_FU_input_valid_REG));
        bufp->chgBit(oldp+549,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3_io_FU_input_valid_REG));
        bufp->chgIData(oldp+550,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_0),32);
        bufp->chgIData(oldp+551,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_1),32);
        bufp->chgBit(oldp+552,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1));
        bufp->chgBit(oldp+553,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__monitor_output_REG));
        bufp->chgBit(oldp+554,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+555,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgIData(oldp+556,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgBit(oldp+557,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgIData(oldp+558,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+559,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+560,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgCData(oldp+561,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+562,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgIData(oldp+563,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+564,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+565,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgBit(oldp+566,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+567,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgIData(oldp+568,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG),32);
        bufp->chgBit(oldp+569,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgIData(oldp+570,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgBit(oldp+571,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG));
        bufp->chgIData(oldp+572,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG),32);
        bufp->chgBit(oldp+573,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG));
        bufp->chgCData(oldp+574,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+575,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgCData(oldp+576,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+577,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgBit(oldp+578,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__BRANCH));
        bufp->chgBit(oldp+579,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__EQ));
        bufp->chgBit(oldp+580,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__NE));
        bufp->chgBit(oldp+581,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__LT));
        bufp->chgBit(oldp+582,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__GE));
        bufp->chgBit(oldp+583,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__LTU));
        bufp->chgBit(oldp+584,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__GEU));
        bufp->chgBit(oldp+585,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__JAL));
        bufp->chgBit(oldp+586,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__JALR));
        bufp->chgIData(oldp+587,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_2),32);
        bufp->chgIData(oldp+588,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_3),32);
        bufp->chgBit(oldp+589,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__monitor_output_REG));
        bufp->chgIData(oldp+590,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+591,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+592,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgIData(oldp+593,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_4),32);
        bufp->chgIData(oldp+594,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_5),32);
        bufp->chgBit(oldp+595,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__monitor_output_REG));
        bufp->chgIData(oldp+596,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+597,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+598,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgIData(oldp+599,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R1_en_d0)
                                   ? vlSelf->top__DOT__dut__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R1_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+600,(vlSelf->top__DOT__dut__DOT__backend__DOT___INT_PRF_io_rdata_7),32);
        bufp->chgBit(oldp+601,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__unnamedblk1__DOT__is_load));
        bufp->chgBit(oldp+602,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__unnamedblk1__DOT__is_store));
        bufp->chgCData(oldp+603,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_9))
                                   : 0U)),6);
        bufp->chgCData(oldp+604,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_10))
                                   : 0U)),6);
        bufp->chgCData(oldp+605,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_11))
                                   : 0U)),6);
        bufp->chgCData(oldp+606,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_12))
                                   : 0U)),6);
        bufp->chgCData(oldp+607,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_13))
                                   : 0U)),6);
        bufp->chgCData(oldp+608,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_14))
                                   : 0U)),6);
        __Vtemp_41[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1))))))))))));
        __Vtemp_41[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1))))))))))) 
                                                >> 0x20U)));
        __Vtemp_41[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1) 
                                                 >> 1U)))));
        __Vtemp_41[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1) 
                                                >> 5U)));
        bufp->chgCData(oldp+609,(((0x6fU >= (0x7fU 
                                             & ((IData)(7U) 
                                                * (0xfU 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                   ? (0x3fU & (((0U 
                                                 == 
                                                 (0x1fU 
                                                  & ((IData)(7U) 
                                                     * 
                                                     (0xfU 
                                                      & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                                 ? 0U
                                                 : 
                                                (__Vtemp_41[
                                                 (((IData)(6U) 
                                                   + 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))))) 
                                               | (__Vtemp_41[
                                                  (3U 
                                                   & (((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))) 
                                                      >> 5U))] 
                                                  >> 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                   : 0U)),6);
        __Vtemp_48[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2))))))))))));
        __Vtemp_48[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2))))))))))) 
                                                >> 0x20U)));
        __Vtemp_48[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2) 
                                                 >> 1U)))));
        __Vtemp_48[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2) 
                                                >> 5U)));
        bufp->chgCData(oldp+610,(((0x6fU >= (0x7fU 
                                             & ((IData)(7U) 
                                                * (0xfU 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                   ? (0x3fU & (((0U 
                                                 == 
                                                 (0x1fU 
                                                  & ((IData)(7U) 
                                                     * 
                                                     (0xfU 
                                                      & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                                 ? 0U
                                                 : 
                                                (__Vtemp_48[
                                                 (((IData)(6U) 
                                                   + 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))))) 
                                               | (__Vtemp_48[
                                                  (3U 
                                                   & (((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))) 
                                                      >> 5U))] 
                                                  >> 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                   : 0U)),6);
        bufp->chgCData(oldp+611,((0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD))),6);
        bufp->chgCData(oldp+612,((0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG))),6);
        bufp->chgCData(oldp+613,((0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG))),6);
        bufp->chgCData(oldp+614,((0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___MOB_io_MOB_output_bits_RD))),6);
        bufp->chgBit(oldp+615,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid));
        bufp->chgBit(oldp+616,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1));
        bufp->chgBit(oldp+617,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2));
        bufp->chgBit(oldp+618,((1U & (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][1U] 
                                           >> 7U) : 
                                       (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][1U] 
                                        >> 7U)) & (
                                                   (~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)) 
                                                   | (~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__empty)))))));
        bufp->chgIData(oldp+619,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)
                                   ? ((vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][1U] 
                                       << 0x19U) | 
                                      (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][0U] 
                                       >> 7U)) : ((
                                                   vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][1U] 
                                                   << 0x19U) 
                                                  | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][0U] 
                                                     >> 7U)))),32);
        bufp->chgIData(oldp+620,(((0U == (0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___MOB_io_MOB_output_bits_RD)))
                                   ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][1U] 
                                                << 0x19U) 
                                               | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][0U] 
                                                  >> 7U))
                                            : ((vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][1U] 
                                                << 0x19U) 
                                               | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][0U] 
                                                  >> 7U))))),32);
        bufp->chgIData(oldp+621,(((0U == (0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG)))
                                   ? 0U : vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgIData(oldp+622,(((0U == (0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG)))
                                   ? 0U : vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgIData(oldp+623,(((0U == (0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD)))
                                   ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__REG_1)
                                            ? vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG
                                            : vlSelf->top__DOT__dut__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result))),32);
        bufp->chgBit(oldp+624,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_0_valid));
        bufp->chgBit(oldp+625,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_1_valid));
        bufp->chgBit(oldp+626,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_2_valid));
        bufp->chgBit(oldp+627,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_3_valid));
        bufp->chgBit(oldp+628,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_60) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+629,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_61) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+630,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_62) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgCData(oldp+631,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? ((0x4fU >= (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                       ? (0x1fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_63[
                                                     (((IData)(4U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_63[
                                                      (3U 
                                                       & (((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))))
                                       : 0U) : 0U)),5);
        bufp->chgCData(oldp+632,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? ((0x6fU >= (0x7fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                       ? (0x7fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_64[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_64[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))))
                                       : 0U) : 0U)),7);
        bufp->chgBit(oldp+633,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_65) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgCData(oldp+634,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_9)
                                   : 0U)),7);
        bufp->chgBit(oldp+635,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_67) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgCData(oldp+636,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_10)
                                   : 0U)),7);
        bufp->chgBit(oldp+637,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_69) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgIData(oldp+638,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? ((0x14fU >= (0x1ffU 
                                                  & ((IData)(0x15U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                       ? (0x1fffffU 
                                          & (((0U == 
                                               (0x1fU 
                                                & ((IData)(0x15U) 
                                                   * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                               ? 0U
                                               : (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_70[
                                                  (((IData)(0x14U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x15U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x15U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))))) 
                                             | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_70[
                                                (0xfU 
                                                 & (((IData)(0x15U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(0x15U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))))
                                       : 0U) : 0U)),21);
        bufp->chgCData(oldp+639,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? ((0x2fU >= (0x3fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                       ? (7U & (IData)(
                                                       (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_71 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))))
                                       : 0U) : 0U)),3);
        bufp->chgCData(oldp+640,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_72 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+641,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0xfU & (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_74 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 2U)))))
                                   : 0U)),4);
        bufp->chgCData(oldp+642,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0xfU & (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_75 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 2U)))))
                                   : 0U)),4);
        bufp->chgCData(oldp+643,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? ((0x4fU >= (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                       ? (0x1fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_76[
                                                     (((IData)(4U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_76[
                                                      (3U 
                                                       & (((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index))))))
                                       : 0U) : 0U)),5);
        bufp->chgCData(oldp+644,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_77 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+645,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_78 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgBit(oldp+646,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_79) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+647,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_80) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+648,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_81) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+649,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_82) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+650,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_83) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgBit(oldp+651,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_84) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgCData(oldp+652,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_85 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+653,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_86 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgBit(oldp+654,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_60) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+655,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_61) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+656,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_62) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgCData(oldp+657,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? ((0x4fU >= (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                       ? (0x1fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_63[
                                                     (((IData)(4U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_63[
                                                      (3U 
                                                       & (((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))))
                                       : 0U) : 0U)),5);
        bufp->chgCData(oldp+658,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? ((0x6fU >= (0x7fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                       ? (0x7fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_64[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_64[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))))
                                       : 0U) : 0U)),7);
        bufp->chgBit(oldp+659,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_65) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgCData(oldp+660,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_11)
                                   : 0U)),7);
        bufp->chgBit(oldp+661,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_67) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgCData(oldp+662,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_12)
                                   : 0U)),7);
        bufp->chgBit(oldp+663,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_69) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgIData(oldp+664,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? ((0x14fU >= (0x1ffU 
                                                  & ((IData)(0x15U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                       ? (0x1fffffU 
                                          & (((0U == 
                                               (0x1fU 
                                                & ((IData)(0x15U) 
                                                   * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                               ? 0U
                                               : (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_70[
                                                  (((IData)(0x14U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x15U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x15U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))))) 
                                             | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_70[
                                                (0xfU 
                                                 & (((IData)(0x15U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(0x15U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))))
                                       : 0U) : 0U)),21);
        bufp->chgCData(oldp+665,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? ((0x2fU >= (0x3fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                       ? (7U & (IData)(
                                                       (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_71 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))))
                                       : 0U) : 0U)),3);
        bufp->chgCData(oldp+666,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_72 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+667,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? ((0x5fU >= (0x7fU 
                                                 & ((IData)(6U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                       ? (0x3fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(6U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_73[
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(6U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(6U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_73[
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(6U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))))
                                       : 0U) : 0U)),6);
        bufp->chgCData(oldp+668,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0xfU & (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_74 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 2U)))))
                                   : 0U)),4);
        bufp->chgCData(oldp+669,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0xfU & (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_75 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 2U)))))
                                   : 0U)),4);
        bufp->chgCData(oldp+670,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? ((0x4fU >= (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                       ? (0x1fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_76[
                                                     (((IData)(4U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_76[
                                                      (3U 
                                                       & (((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index))))))
                                       : 0U) : 0U)),5);
        bufp->chgCData(oldp+671,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_77 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+672,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_78 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgBit(oldp+673,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_79) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+674,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_80) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+675,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_81) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+676,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_82) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+677,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_83) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgBit(oldp+678,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_84) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgCData(oldp+679,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_85 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+680,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_86 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgBit(oldp+681,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_60) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+682,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_61) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+683,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_62) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgCData(oldp+684,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? ((0x4fU >= (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                       ? (0x1fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_63[
                                                     (((IData)(4U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_63[
                                                      (3U 
                                                       & (((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))))
                                       : 0U) : 0U)),5);
        bufp->chgCData(oldp+685,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? ((0x6fU >= (0x7fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                       ? (0x7fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_64[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_64[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))))
                                       : 0U) : 0U)),7);
        bufp->chgBit(oldp+686,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_65) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgCData(oldp+687,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_13)
                                   : 0U)),7);
        bufp->chgBit(oldp+688,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_67) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgCData(oldp+689,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_14)
                                   : 0U)),7);
        bufp->chgBit(oldp+690,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_69) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgIData(oldp+691,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? ((0x14fU >= (0x1ffU 
                                                  & ((IData)(0x15U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                       ? (0x1fffffU 
                                          & (((0U == 
                                               (0x1fU 
                                                & ((IData)(0x15U) 
                                                   * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                               ? 0U
                                               : (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_70[
                                                  (((IData)(0x14U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x15U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x15U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))))) 
                                             | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_70[
                                                (0xfU 
                                                 & (((IData)(0x15U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(0x15U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))))
                                       : 0U) : 0U)),21);
        bufp->chgCData(oldp+692,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? ((0x2fU >= (0x3fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                       ? (7U & (IData)(
                                                       (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_71 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(3U) 
                                                            * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))))
                                       : 0U) : 0U)),3);
        bufp->chgCData(oldp+693,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_72 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+694,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? ((0x5fU >= (0x7fU 
                                                 & ((IData)(6U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                       ? (0x3fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(6U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_73[
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(6U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(6U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_73[
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(6U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))))
                                       : 0U) : 0U)),6);
        bufp->chgCData(oldp+695,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0xfU & (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_74 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 2U)))))
                                   : 0U)),4);
        bufp->chgCData(oldp+696,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0xfU & (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_75 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 2U)))))
                                   : 0U)),4);
        bufp->chgCData(oldp+697,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? ((0x4fU >= (0x7fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                       ? (0x1fU & (
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_76[
                                                     (((IData)(4U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_76[
                                                      (3U 
                                                       & (((IData)(5U) 
                                                           * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(5U) 
                                                          * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index))))))
                                       : 0U) : 0U)),5);
        bufp->chgCData(oldp+698,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_77 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+699,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_78 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgBit(oldp+700,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_79) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+701,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_80) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+702,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_81) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+703,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_82) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+704,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_83) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgBit(oldp+705,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_84) 
                                   >> (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgCData(oldp+706,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_85 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgCData(oldp+707,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (3U & (vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT___GEN_86 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index), 1U))))
                                   : 0U)),2);
        bufp->chgBit(oldp+708,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+709,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+710,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+711,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RD),7);
        bufp->chgBit(oldp+712,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+713,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+714,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+715,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+716,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+717,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+718,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+719,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+720,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+721,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+722,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+723,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+724,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_portID),2);
        bufp->chgCData(oldp+725,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+726,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+727,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+728,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+729,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+730,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+731,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+732,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+733,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+734,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_0_valid));
        bufp->chgBit(oldp+735,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+736,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+737,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+738,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RD),7);
        bufp->chgBit(oldp+739,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+740,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+741,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+742,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+743,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+744,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+745,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+746,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+747,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+748,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+749,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+750,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+751,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_portID),2);
        bufp->chgCData(oldp+752,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+753,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+754,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+755,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+756,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+757,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+758,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+759,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+760,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+761,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_1_valid));
        bufp->chgBit(oldp+762,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+763,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+764,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+765,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RD),7);
        bufp->chgBit(oldp+766,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+767,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+768,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+769,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+770,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+771,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+772,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+773,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+774,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+775,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+776,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+777,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+778,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_portID),2);
        bufp->chgCData(oldp+779,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+780,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+781,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+782,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+783,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+784,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+785,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+786,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+787,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+788,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_2_valid));
        bufp->chgBit(oldp+789,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+790,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+791,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+792,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RD),7);
        bufp->chgBit(oldp+793,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+794,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+795,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+796,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+797,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+798,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+799,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+800,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+801,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+802,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+803,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+804,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+805,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_portID),2);
        bufp->chgCData(oldp+806,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+807,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+808,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+809,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+810,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+811,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+812,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+813,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+814,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+815,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_3_valid));
        bufp->chgBit(oldp+816,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+817,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+818,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+819,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RD),7);
        bufp->chgBit(oldp+820,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+821,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+822,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+823,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+824,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+825,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+826,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+827,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+828,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+829,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+830,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+831,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+832,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_portID),2);
        bufp->chgCData(oldp+833,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+834,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+835,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+836,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+837,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+838,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+839,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+840,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+841,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+842,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_4_valid));
        bufp->chgBit(oldp+843,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+844,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+845,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+846,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RD),7);
        bufp->chgBit(oldp+847,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+848,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+849,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+850,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+851,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+852,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+853,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+854,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+855,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+856,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+857,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+858,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+859,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_portID),2);
        bufp->chgCData(oldp+860,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+861,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+862,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+863,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+864,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+865,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+866,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+867,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+868,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+869,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_5_valid));
        bufp->chgBit(oldp+870,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+871,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+872,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+873,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RD),7);
        bufp->chgBit(oldp+874,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+875,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+876,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+877,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+878,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+879,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+880,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+881,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+882,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+883,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+884,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+885,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+886,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_portID),2);
        bufp->chgCData(oldp+887,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+888,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+889,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+890,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+891,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+892,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+893,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+894,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+895,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+896,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_6_valid));
        bufp->chgBit(oldp+897,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+898,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+899,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+900,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RD),7);
        bufp->chgBit(oldp+901,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+902,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+903,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+904,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+905,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+906,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+907,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+908,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+909,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+910,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+911,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+912,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+913,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_portID),2);
        bufp->chgCData(oldp+914,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+915,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+916,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+917,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+918,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+919,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+920,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+921,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+922,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+923,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_7_valid));
        bufp->chgBit(oldp+924,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+925,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+926,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+927,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RD),7);
        bufp->chgBit(oldp+928,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+929,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+930,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+931,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+932,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+933,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+934,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+935,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+936,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+937,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+938,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+939,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+940,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_portID),2);
        bufp->chgCData(oldp+941,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+942,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+943,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+944,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+945,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+946,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+947,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+948,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+949,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+950,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_8_valid));
        bufp->chgBit(oldp+951,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+952,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+953,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+954,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RD),7);
        bufp->chgBit(oldp+955,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+956,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+957,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+958,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+959,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+960,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+961,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+962,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+963,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+964,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+965,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+966,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+967,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_portID),2);
        bufp->chgCData(oldp+968,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+969,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+970,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+971,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+972,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+973,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+974,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+975,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+976,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+977,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_9_valid));
        bufp->chgBit(oldp+978,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+979,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+980,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+981,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RD),7);
        bufp->chgBit(oldp+982,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+983,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+984,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+985,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+986,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+987,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+988,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+989,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+990,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+991,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+992,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+993,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+994,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_portID),2);
        bufp->chgCData(oldp+995,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+996,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+997,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+998,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+999,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1000,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1001,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1002,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1003,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+1004,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_10_valid));
        bufp->chgBit(oldp+1005,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1006,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1007,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1008,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1009,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1010,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1011,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1012,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1013,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1014,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1015,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1016,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1017,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1018,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1019,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1020,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1021,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1022,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1023,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1024,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1025,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1026,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1027,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1028,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1029,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1030,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+1031,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_11_valid));
        bufp->chgBit(oldp+1032,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1033,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1034,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1035,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1036,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1037,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1038,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1039,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1040,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1041,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1042,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1043,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1044,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1045,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1046,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1047,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1048,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1049,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1050,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1051,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1052,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1053,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1054,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1055,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1056,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1057,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+1058,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_12_valid));
        bufp->chgBit(oldp+1059,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1060,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1061,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1062,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1063,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1064,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1065,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1066,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1067,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1068,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1069,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1070,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1071,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1072,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1073,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1074,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1075,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1076,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1077,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1078,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1079,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1080,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1081,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1082,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1083,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1084,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+1085,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_13_valid));
        bufp->chgBit(oldp+1086,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1087,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1088,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1089,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1090,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1091,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1092,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1093,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1094,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1095,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1096,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1097,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1098,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1099,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1100,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1101,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1102,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1103,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1104,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1105,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1106,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1107,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1108,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1109,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1110,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1111,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+1112,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_14_valid));
        bufp->chgBit(oldp+1113,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1114,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1115,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1116,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1117,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1118,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1119,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1120,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1121,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1122,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1123,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1124,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1125,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1126,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1127,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1128,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1129,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1130,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1131,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1132,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1133,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1134,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1135,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1136,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1137,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1138,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_decoded_instruction_access_width),2);
        bufp->chgBit(oldp+1139,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__reservation_station_15_valid));
        bufp->chgSData(oldp+1140,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__allocate_index_0),16);
        bufp->chgSData(oldp+1141,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__allocate_index_1),16);
        bufp->chgSData(oldp+1142,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__allocate_index_2),16);
        bufp->chgSData(oldp+1143,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__allocate_index_3),16);
        bufp->chgBit(oldp+1144,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_0));
        bufp->chgBit(oldp+1145,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_0));
        bufp->chgBit(oldp+1146,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_1));
        bufp->chgBit(oldp+1147,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_1));
        bufp->chgBit(oldp+1148,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_2));
        bufp->chgBit(oldp+1149,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_2));
        bufp->chgBit(oldp+1150,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_3));
        bufp->chgBit(oldp+1151,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_3));
        bufp->chgBit(oldp+1152,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_4));
        bufp->chgBit(oldp+1153,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_4));
        bufp->chgBit(oldp+1154,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_5));
        bufp->chgBit(oldp+1155,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_5));
        bufp->chgBit(oldp+1156,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_6));
        bufp->chgBit(oldp+1157,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_6));
        bufp->chgBit(oldp+1158,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_7));
        bufp->chgBit(oldp+1159,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_7));
        bufp->chgBit(oldp+1160,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_8));
        bufp->chgBit(oldp+1161,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_8));
        bufp->chgBit(oldp+1162,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_9));
        bufp->chgBit(oldp+1163,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_9));
        bufp->chgBit(oldp+1164,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_10));
        bufp->chgBit(oldp+1165,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_10));
        bufp->chgBit(oldp+1166,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_11));
        bufp->chgBit(oldp+1167,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_11));
        bufp->chgBit(oldp+1168,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_12));
        bufp->chgBit(oldp+1169,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_12));
        bufp->chgBit(oldp+1170,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_13));
        bufp->chgBit(oldp+1171,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_13));
        bufp->chgBit(oldp+1172,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_14));
        bufp->chgBit(oldp+1173,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_14));
        bufp->chgBit(oldp+1174,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS1_match_15));
        bufp->chgBit(oldp+1175,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__RS2_match_15));
        bufp->chgBit(oldp+1176,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_0));
        bufp->chgBit(oldp+1177,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_1));
        bufp->chgBit(oldp+1178,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_2));
        bufp->chgBit(oldp+1179,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_3));
        bufp->chgBit(oldp+1180,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_4));
        bufp->chgBit(oldp+1181,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_5));
        bufp->chgBit(oldp+1182,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_6));
        bufp->chgBit(oldp+1183,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_7));
        bufp->chgBit(oldp+1184,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_8));
        bufp->chgBit(oldp+1185,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_9));
        bufp->chgBit(oldp+1186,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_10));
        bufp->chgBit(oldp+1187,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_11));
        bufp->chgBit(oldp+1188,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_12));
        bufp->chgBit(oldp+1189,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_13));
        bufp->chgBit(oldp+1190,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_14));
        bufp->chgBit(oldp+1191,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions_15));
        bufp->chgCData(oldp+1192,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_RS_index),4);
        bufp->chgBit(oldp+1193,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port0_valid));
        bufp->chgCData(oldp+1194,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_RS_index),4);
        bufp->chgBit(oldp+1195,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port1_valid));
        bufp->chgCData(oldp+1196,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_RS_index),4);
        bufp->chgBit(oldp+1197,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__port2_valid));
        bufp->chgCData(oldp+1198,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries),5);
        bufp->chgCData(oldp+1199,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary),4);
        bufp->chgCData(oldp+1200,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_1),4);
        bufp->chgCData(oldp+1201,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_2),4);
        bufp->chgCData(oldp+1202,(vlSelf->top__DOT__dut__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_3),4);
        bufp->chgBit(oldp+1203,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__MEM_RS__io_backend_packet_0_valid));
        bufp->chgBit(oldp+1204,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__MEM_RS__io_backend_packet_1_valid));
        bufp->chgBit(oldp+1205,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__MEM_RS__io_backend_packet_2_valid));
        bufp->chgBit(oldp+1206,(vlSelf->top__DOT__dut__DOT__backend__DOT____Vcellinp__MEM_RS__io_backend_packet_3_valid));
        bufp->chgBit(oldp+1207,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__good_to_go));
        __Vtemp_55[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RD)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RD)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RD)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RD)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RD)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RD) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RD) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RD) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RD))))))))))));
        __Vtemp_55[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RD) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RD)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RD)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RD)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RD)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RD)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RD) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RD) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RD) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RD))))))))))) 
                                                >> 0x20U)));
        __Vtemp_55[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RD) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RD) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RD) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RD) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RD) 
                                                 >> 1U)))));
        __Vtemp_55[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RD) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RD) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RD) 
                                                >> 5U)));
        bufp->chgCData(oldp+1208,(((0x6fU >= (0x7fU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0xfU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                                  ? 0U
                                                  : 
                                                 (__Vtemp_55[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0x7fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))))) 
                                                | (__Vtemp_55[
                                                   (3U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                    : 0U)),7);
        __Vtemp_62[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1))))))))))));
        __Vtemp_62[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1))))))))))) 
                                                >> 0x20U)));
        __Vtemp_62[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1) 
                                                 >> 1U)))));
        __Vtemp_62[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1) 
                                                >> 5U)));
        bufp->chgCData(oldp+1209,(((0x6fU >= (0x7fU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0xfU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                                  ? 0U
                                                  : 
                                                 (__Vtemp_62[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0x7fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))))) 
                                                | (__Vtemp_62[
                                                   (3U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                    : 0U)),7);
        __Vtemp_69[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2))))))))))));
        __Vtemp_69[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2))))))))))) 
                                                >> 0x20U)));
        __Vtemp_69[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2) 
                                                 >> 1U)))));
        __Vtemp_69[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2) 
                                                >> 5U)));
        bufp->chgCData(oldp+1210,(((0x6fU >= (0x7fU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0xfU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0xfU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                                  ? 0U
                                                  : 
                                                 (__Vtemp_69[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0x7fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))))) 
                                                | (__Vtemp_69[
                                                   (3U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                    : 0U)),7);
        __Vtemp_82[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_IMM)) 
                                   << 0x2aU) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_IMM)) 
                                                 << 0x15U) 
                                                | (QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_IMM)))));
        __Vtemp_82[1U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_IMM 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_IMM)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_IMM)) 
                                                     << 0x15U) 
                                                    | (QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_IMM)))) 
                                                >> 0x20U)));
        __Vtemp_82[2U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_IMM 
                           << 0x14U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_IMM 
                                        >> 1U));
        __Vtemp_82[3U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_IMM 
                           << 0x1eU) | ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_IMM 
                                         << 9U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_IMM 
                                                   >> 0xcU)));
        __Vtemp_82[4U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_IMM 
                           << 0x13U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_IMM 
                                        >> 2U));
        __Vtemp_82[5U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_IMM 
                           << 0x1dU) | ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_IMM 
                                         << 8U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_IMM 
                                                   >> 0xdU)));
        __Vtemp_82[6U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_IMM 
                           << 0x12U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_IMM 
                                        >> 3U));
        __Vtemp_82[7U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_IMM 
                           << 0x1cU) | ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_IMM 
                                         << 7U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_IMM 
                                                   >> 0xeU)));
        __Vtemp_82[8U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_IMM 
                           << 0x11U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_IMM 
                                        >> 4U));
        __Vtemp_82[9U] = ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_IMM 
                           << 0x1bU) | ((vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_IMM 
                                         << 6U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_IMM 
                                                   >> 0xfU)));
        __Vtemp_82[0xaU] = (vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_IMM 
                            >> 5U);
        bufp->chgIData(oldp+1211,(((0x14fU >= (0x1ffU 
                                               & ((IData)(0x15U) 
                                                  * 
                                                  (0xfU 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                    ? (0x1fffffU & 
                                       (((0U == (0x1fU 
                                                 & ((IData)(0x15U) 
                                                    * 
                                                    (0xfU 
                                                     & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                          ? 0U : (__Vtemp_82[
                                                  (((IData)(0x14U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x15U) 
                                                        * 
                                                        (0xfU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x15U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))))))) 
                                        | (__Vtemp_82[
                                           (0xfU & 
                                            (((IData)(0x15U) 
                                              * (0xfU 
                                                 & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))) 
                                             >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(0x15U) 
                                                  * 
                                                  (0xfU 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                    : 0U)),21);
        bufp->chgCData(oldp+1212,(((0x2fU >= (0x3fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (0xfU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))
                                    ? (7U & (IData)(
                                                    ((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_FUNCT3)) 
                                                       << 0x2dU) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_FUNCT3)) 
                                                          << 0x2aU) 
                                                         | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_FUNCT3)) 
                                                             << 0x27U) 
                                                            | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_FUNCT3)) 
                                                                << 0x24U) 
                                                               | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_FUNCT3)) 
                                                                   << 0x21U) 
                                                                  | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_FUNCT3)) 
                                                                      << 0x1eU) 
                                                                     | (QData)((IData)(
                                                                                (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_FUNCT3) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_FUNCT3) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_FUNCT3) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_FUNCT3) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_FUNCT3) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_FUNCT3) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_FUNCT3) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_FUNCT3) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_FUNCT3) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_FUNCT3)))))))))))))))))) 
                                                     >> 
                                                     (0x3fU 
                                                      & ((IData)(3U) 
                                                         * 
                                                         (0xfU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)))))))
                                    : 0U)),3);
        bufp->chgCData(oldp+1213,((0xfU & (IData)((
                                                   (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_MOB_index)) 
                                                     << 0x3cU) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_MOB_index)) 
                                                        << 0x38U) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_MOB_index)) 
                                                           << 0x34U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_MOB_index)) 
                                                              << 0x30U) 
                                                             | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_MOB_index)) 
                                                                 << 0x2cU) 
                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_MOB_index)) 
                                                                    << 0x28U) 
                                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_MOB_index)) 
                                                                       << 0x24U) 
                                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_MOB_index)) 
                                                                          << 0x20U) 
                                                                         | (QData)((IData)(
                                                                                (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_MOB_index) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_MOB_index) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_MOB_index) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_MOB_index) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_MOB_index) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_MOB_index) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_MOB_index) 
                                                                                << 4U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_MOB_index)))))))))))))))))) 
                                                   >> 
                                                   (0x3fU 
                                                    & VL_SHIFTL_III(6,6,32, 
                                                                    (0xfU 
                                                                     & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)), 2U)))))),4);
        bufp->chgCData(oldp+1214,((3U & ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_memory_type) 
                                           << 0x1eU) 
                                          | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_memory_type) 
                                              << 0x1cU) 
                                             | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_memory_type) 
                                                 << 0x1aU) 
                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_memory_type) 
                                                    << 0x18U) 
                                                   | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_memory_type) 
                                                       << 0x16U) 
                                                      | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_memory_type) 
                                                          << 0x14U) 
                                                         | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_memory_type) 
                                                             << 0x12U) 
                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_memory_type) 
                                                                << 0x10U) 
                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_memory_type) 
                                                                   << 0xeU) 
                                                                  | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_memory_type) 
                                                                      << 0xcU) 
                                                                     | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_memory_type) 
                                                                         << 0xaU) 
                                                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_memory_type) 
                                                                            << 8U) 
                                                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_memory_type) 
                                                                               << 6U) 
                                                                              | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_memory_type) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_memory_type) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_memory_type)))))))))))))))) 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(5,5,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)), 1U))))),2);
        bufp->chgCData(oldp+1215,((3U & ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_access_width) 
                                           << 0x1eU) 
                                          | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_access_width) 
                                              << 0x1cU) 
                                             | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_access_width) 
                                                 << 0x1aU) 
                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_access_width) 
                                                    << 0x18U) 
                                                   | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_access_width) 
                                                       << 0x16U) 
                                                      | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_access_width) 
                                                          << 0x14U) 
                                                         | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_access_width) 
                                                             << 0x12U) 
                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_access_width) 
                                                                << 0x10U) 
                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_access_width) 
                                                                   << 0xeU) 
                                                                  | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_access_width) 
                                                                      << 0xcU) 
                                                                     | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_access_width) 
                                                                         << 0xaU) 
                                                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_access_width) 
                                                                            << 8U) 
                                                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_access_width) 
                                                                               << 6U) 
                                                                              | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_access_width) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_access_width) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_access_width)))))))))))))))) 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(5,5,32, 
                                                             (0xfU 
                                                              & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer)), 1U))))),2);
        bufp->chgBit(oldp+1216,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1217,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1218,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1219,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1220,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1221,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1222,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1223,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1224,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1225,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1226,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1227,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1228,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1229,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1230,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1231,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1232,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1233,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1234,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1235,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1236,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1237,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1238,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1239,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1240,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1241,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1242,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_fetch_PC),32);
        bufp->chgBit(oldp+1243,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_committed));
        bufp->chgBit(oldp+1244,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_valid));
        bufp->chgBit(oldp+1245,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1246,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1247,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1248,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1249,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1250,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1251,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1252,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1253,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1254,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1255,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1256,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1257,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1258,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1259,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1260,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1261,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1262,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1263,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1264,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1265,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1266,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1267,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1268,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1269,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1270,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1271,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_fetch_PC),32);
        bufp->chgBit(oldp+1272,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_committed));
        bufp->chgBit(oldp+1273,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_valid));
        bufp->chgBit(oldp+1274,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1275,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1276,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1277,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1278,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1279,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1280,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1281,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1282,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1283,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1284,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1285,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1286,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1287,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1288,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1289,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1290,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1291,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1292,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1293,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1294,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1295,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1296,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1297,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1298,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1299,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1300,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_fetch_PC),32);
        bufp->chgBit(oldp+1301,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_committed));
        bufp->chgBit(oldp+1302,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_valid));
        bufp->chgBit(oldp+1303,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1304,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1305,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1306,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1307,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1308,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1309,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1310,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1311,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1312,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1313,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1314,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1315,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1316,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1317,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1318,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1319,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1320,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1321,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1322,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1323,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1324,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1325,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1326,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1327,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1328,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1329,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_fetch_PC),32);
        bufp->chgBit(oldp+1330,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_committed));
        bufp->chgBit(oldp+1331,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_valid));
        bufp->chgBit(oldp+1332,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1333,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1334,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1335,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1336,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1337,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1338,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1339,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1340,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1341,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1342,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1343,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1344,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1345,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1346,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1347,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1348,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1349,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1350,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1351,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1352,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1353,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1354,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1355,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1356,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1357,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1358,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_fetch_PC),32);
        bufp->chgBit(oldp+1359,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_committed));
        bufp->chgBit(oldp+1360,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_valid));
        bufp->chgBit(oldp+1361,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1362,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1363,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1364,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1365,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1366,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1367,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1368,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1369,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1370,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1371,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1372,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1373,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1374,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1375,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1376,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1377,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1378,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1379,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1380,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1381,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1382,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1383,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1384,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1385,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1386,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1387,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_fetch_PC),32);
        bufp->chgBit(oldp+1388,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_committed));
        bufp->chgBit(oldp+1389,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_valid));
        bufp->chgBit(oldp+1390,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1391,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1392,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1393,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1394,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1395,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1396,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1397,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1398,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1399,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1400,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1401,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1402,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1403,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1404,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1405,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1406,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1407,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1408,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1409,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1410,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1411,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1412,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1413,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1414,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1415,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1416,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_fetch_PC),32);
        bufp->chgBit(oldp+1417,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_committed));
        bufp->chgBit(oldp+1418,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_valid));
        bufp->chgBit(oldp+1419,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1420,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1421,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1422,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1423,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1424,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1425,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1426,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1427,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1428,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1429,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1430,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1431,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1432,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1433,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1434,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1435,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1436,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1437,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1438,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1439,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1440,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1441,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1442,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1443,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1444,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1445,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_fetch_PC),32);
        bufp->chgBit(oldp+1446,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_committed));
        bufp->chgBit(oldp+1447,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_valid));
        bufp->chgBit(oldp+1448,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1449,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1450,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1451,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1452,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1453,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1454,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1455,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1456,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1457,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1458,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1459,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1460,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1461,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1462,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1463,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1464,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1465,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1466,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1467,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1468,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1469,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1470,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1471,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1472,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1473,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1474,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_fetch_PC),32);
        bufp->chgBit(oldp+1475,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_committed));
        bufp->chgBit(oldp+1476,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_valid));
        bufp->chgBit(oldp+1477,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1478,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1479,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1480,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1481,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1482,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1483,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1484,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1485,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1486,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1487,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1488,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1489,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1490,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1491,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1492,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1493,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1494,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1495,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1496,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1497,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1498,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1499,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1500,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1501,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1502,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1503,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_fetch_PC),32);
        bufp->chgBit(oldp+1504,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_committed));
        bufp->chgBit(oldp+1505,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_valid));
        bufp->chgBit(oldp+1506,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1507,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1508,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1509,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1510,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1511,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1512,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1513,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1514,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1515,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1516,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1517,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1518,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1519,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1520,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1521,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1522,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1523,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1524,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1525,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1526,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1527,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1528,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1529,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1530,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1531,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1532,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_fetch_PC),32);
        bufp->chgBit(oldp+1533,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_committed));
        bufp->chgBit(oldp+1534,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_valid));
        bufp->chgBit(oldp+1535,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1536,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1537,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1538,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1539,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1540,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1541,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1542,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1543,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1544,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1545,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1546,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1547,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1548,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1549,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1550,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1551,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1552,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1553,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1554,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1555,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1556,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1557,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1558,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1559,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1560,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1561,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_fetch_PC),32);
        bufp->chgBit(oldp+1562,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_committed));
        bufp->chgBit(oldp+1563,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_valid));
        bufp->chgBit(oldp+1564,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1565,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1566,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1567,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1568,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1569,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1570,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1571,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1572,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1573,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1574,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1575,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1576,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1577,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1578,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1579,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1580,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1581,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1582,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1583,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1584,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1585,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1586,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1587,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1588,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1589,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1590,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_fetch_PC),32);
        bufp->chgBit(oldp+1591,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_committed));
        bufp->chgBit(oldp+1592,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_valid));
        bufp->chgBit(oldp+1593,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1594,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1595,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1596,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1597,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1598,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1599,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1600,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1601,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1602,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1603,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1604,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1605,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1606,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1607,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1608,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1609,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1610,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1611,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1612,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1613,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1614,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1615,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1616,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1617,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1618,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1619,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_fetch_PC),32);
        bufp->chgBit(oldp+1620,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_committed));
        bufp->chgBit(oldp+1621,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_valid));
        bufp->chgBit(oldp+1622,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1623,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1624,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1625,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1626,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1627,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1628,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1629,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1630,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1631,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1632,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1633,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1634,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1635,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1636,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1637,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1638,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1639,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1640,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1641,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1642,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1643,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1644,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1645,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1646,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1647,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1648,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_fetch_PC),32);
        bufp->chgBit(oldp+1649,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_committed));
        bufp->chgBit(oldp+1650,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_valid));
        bufp->chgBit(oldp+1651,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_ready_bits_RS1_ready));
        bufp->chgBit(oldp+1652,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_ready_bits_RS2_ready));
        bufp->chgCData(oldp+1653,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RDold),5);
        bufp->chgCData(oldp+1654,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RD),7);
        bufp->chgBit(oldp+1655,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RD_valid));
        bufp->chgCData(oldp+1656,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1),7);
        bufp->chgBit(oldp+1657,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1_valid));
        bufp->chgCData(oldp+1658,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2),7);
        bufp->chgBit(oldp+1659,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2_valid));
        bufp->chgIData(oldp+1660,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_IMM),21);
        bufp->chgCData(oldp+1661,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_FUNCT3),3);
        bufp->chgCData(oldp+1662,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_packet_index),2);
        bufp->chgCData(oldp+1663,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_ROB_index),6);
        bufp->chgCData(oldp+1664,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_MOB_index),4);
        bufp->chgCData(oldp+1665,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_FTQ_index),4);
        bufp->chgCData(oldp+1666,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_instructionType),5);
        bufp->chgCData(oldp+1667,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_portID),2);
        bufp->chgCData(oldp+1668,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS_type),2);
        bufp->chgBit(oldp+1669,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_needs_ALU));
        bufp->chgBit(oldp+1670,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_needs_branch_unit));
        bufp->chgBit(oldp+1671,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_needs_CSRs));
        bufp->chgBit(oldp+1672,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_SUBTRACT));
        bufp->chgBit(oldp+1673,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_MULTIPLY));
        bufp->chgBit(oldp+1674,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_IS_IMM));
        bufp->chgCData(oldp+1675,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_memory_type),2);
        bufp->chgCData(oldp+1676,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_access_width),2);
        bufp->chgIData(oldp+1677,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_fetch_PC),32);
        bufp->chgBit(oldp+1678,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_committed));
        bufp->chgBit(oldp+1679,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_valid));
        bufp->chgCData(oldp+1680,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer),5);
        bufp->chgCData(oldp+1681,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__back_pointer),5);
        bufp->chgCData(oldp+1682,((0xfU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__front_pointer))),4);
        bufp->chgCData(oldp+1683,((0xfU & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__back_pointer))),4);
        bufp->chgBit(oldp+1684,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1685,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_0_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1686,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1687,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_1_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1688,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1689,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_2_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1690,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1691,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_3_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1692,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1693,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_4_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1694,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1695,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_5_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1696,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1697,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_6_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1698,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1699,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_7_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1700,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1701,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_8_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1702,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1703,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_9_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1704,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1705,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_10_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1706,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1707,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_11_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1708,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1709,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_12_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1710,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1711,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_13_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1712,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1713,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_14_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1714,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS1)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgBit(oldp+1715,(((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT___FU0_io_FU_output_bits_RD) 
                                   == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2)) 
                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid)) 
                                 | ((((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                      == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2)) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_1)) 
                                    | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                                        == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__reservation_station_15_decoded_instruction_RS2)) 
                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RD_valid_2))))));
        bufp->chgCData(oldp+1716,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__availalbe_RS_entries),5);
        bufp->chgBit(oldp+1717,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__unnamedblk1__DOT__written_vec_0));
        bufp->chgBit(oldp+1718,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__unnamedblk1__DOT__written_vec_1));
        bufp->chgBit(oldp+1719,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__unnamedblk1__DOT__written_vec_2));
        bufp->chgBit(oldp+1720,(vlSelf->top__DOT__dut__DOT__backend__DOT__MEM_RS__DOT__unnamedblk1__DOT__written_vec_3));
        bufp->chgBit(oldp+1721,((1U & ((~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)) 
                                       | (~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__empty))))));
        bufp->chgCData(oldp+1722,(vlSelf->top__DOT__dut__DOT__backend__DOT___MOB_io_MOB_output_bits_RD),7);
        bufp->chgBit(oldp+1723,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][1U] 
                                           >> 7U) : 
                                       (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][1U] 
                                        >> 7U)))));
        bufp->chgCData(oldp+1724,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__back_pointer),5);
        bufp->chgBit(oldp+1725,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_valid));
        bufp->chgCData(oldp+1726,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type),2);
        bufp->chgCData(oldp+1727,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_ROB_index),6);
        bufp->chgIData(oldp+1728,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_address),32);
        bufp->chgCData(oldp+1729,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_RD),7);
        bufp->chgBit(oldp+1730,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_data_valid));
        bufp->chgBit(oldp+1731,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_pending));
        bufp->chgBit(oldp+1732,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_committed));
        bufp->chgBit(oldp+1733,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_valid));
        bufp->chgCData(oldp+1734,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_memory_type),2);
        bufp->chgCData(oldp+1735,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_ROB_index),6);
        bufp->chgIData(oldp+1736,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_address),32);
        bufp->chgCData(oldp+1737,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_RD),7);
        bufp->chgBit(oldp+1738,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_data_valid));
        bufp->chgBit(oldp+1739,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_pending));
        bufp->chgBit(oldp+1740,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_committed));
        bufp->chgBit(oldp+1741,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_valid));
        bufp->chgCData(oldp+1742,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_memory_type),2);
        bufp->chgCData(oldp+1743,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_ROB_index),6);
        bufp->chgIData(oldp+1744,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_address),32);
        bufp->chgCData(oldp+1745,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_RD),7);
        bufp->chgBit(oldp+1746,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_data_valid));
        bufp->chgBit(oldp+1747,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_pending));
        bufp->chgBit(oldp+1748,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_committed));
        bufp->chgBit(oldp+1749,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_valid));
        bufp->chgCData(oldp+1750,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_memory_type),2);
        bufp->chgCData(oldp+1751,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_ROB_index),6);
        bufp->chgIData(oldp+1752,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_address),32);
        bufp->chgCData(oldp+1753,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_RD),7);
        bufp->chgBit(oldp+1754,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_data_valid));
        bufp->chgBit(oldp+1755,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_pending));
        bufp->chgBit(oldp+1756,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_committed));
        bufp->chgBit(oldp+1757,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_valid));
        bufp->chgCData(oldp+1758,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_memory_type),2);
        bufp->chgCData(oldp+1759,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_ROB_index),6);
        bufp->chgIData(oldp+1760,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_address),32);
        bufp->chgCData(oldp+1761,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_RD),7);
        bufp->chgBit(oldp+1762,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_data_valid));
        bufp->chgBit(oldp+1763,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_pending));
        bufp->chgBit(oldp+1764,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_committed));
        bufp->chgBit(oldp+1765,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_valid));
        bufp->chgCData(oldp+1766,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_memory_type),2);
        bufp->chgCData(oldp+1767,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_ROB_index),6);
        bufp->chgIData(oldp+1768,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_address),32);
        bufp->chgCData(oldp+1769,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_RD),7);
        bufp->chgBit(oldp+1770,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_data_valid));
        bufp->chgBit(oldp+1771,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_pending));
        bufp->chgBit(oldp+1772,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_committed));
        bufp->chgBit(oldp+1773,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_valid));
        bufp->chgCData(oldp+1774,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_memory_type),2);
        bufp->chgCData(oldp+1775,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_ROB_index),6);
        bufp->chgIData(oldp+1776,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_address),32);
        bufp->chgCData(oldp+1777,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_RD),7);
        bufp->chgBit(oldp+1778,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_data_valid));
        bufp->chgBit(oldp+1779,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_pending));
        bufp->chgBit(oldp+1780,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_committed));
        bufp->chgBit(oldp+1781,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_valid));
        bufp->chgCData(oldp+1782,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_memory_type),2);
        bufp->chgCData(oldp+1783,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_ROB_index),6);
        bufp->chgIData(oldp+1784,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_address),32);
        bufp->chgCData(oldp+1785,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_RD),7);
        bufp->chgBit(oldp+1786,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_data_valid));
        bufp->chgBit(oldp+1787,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_pending));
        bufp->chgBit(oldp+1788,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_committed));
        bufp->chgBit(oldp+1789,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_valid));
        bufp->chgCData(oldp+1790,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_memory_type),2);
        bufp->chgCData(oldp+1791,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_ROB_index),6);
        bufp->chgIData(oldp+1792,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_address),32);
        bufp->chgCData(oldp+1793,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_RD),7);
        bufp->chgBit(oldp+1794,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_data_valid));
        bufp->chgBit(oldp+1795,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_pending));
        bufp->chgBit(oldp+1796,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_committed));
        bufp->chgBit(oldp+1797,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_valid));
        bufp->chgCData(oldp+1798,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_memory_type),2);
        bufp->chgCData(oldp+1799,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_ROB_index),6);
        bufp->chgIData(oldp+1800,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_address),32);
        bufp->chgCData(oldp+1801,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_RD),7);
        bufp->chgBit(oldp+1802,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_data_valid));
        bufp->chgBit(oldp+1803,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_pending));
        bufp->chgBit(oldp+1804,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_committed));
        bufp->chgBit(oldp+1805,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_valid));
        bufp->chgCData(oldp+1806,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_memory_type),2);
        bufp->chgCData(oldp+1807,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_ROB_index),6);
        bufp->chgIData(oldp+1808,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_address),32);
        bufp->chgCData(oldp+1809,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_RD),7);
        bufp->chgBit(oldp+1810,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_data_valid));
        bufp->chgBit(oldp+1811,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_pending));
        bufp->chgBit(oldp+1812,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_committed));
        bufp->chgBit(oldp+1813,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_valid));
        bufp->chgCData(oldp+1814,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_memory_type),2);
        bufp->chgCData(oldp+1815,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_ROB_index),6);
        bufp->chgIData(oldp+1816,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_address),32);
        bufp->chgCData(oldp+1817,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_RD),7);
        bufp->chgBit(oldp+1818,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_data_valid));
        bufp->chgBit(oldp+1819,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_pending));
        bufp->chgBit(oldp+1820,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_committed));
        bufp->chgBit(oldp+1821,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_valid));
        bufp->chgCData(oldp+1822,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_memory_type),2);
        bufp->chgCData(oldp+1823,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_ROB_index),6);
        bufp->chgIData(oldp+1824,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_address),32);
        bufp->chgCData(oldp+1825,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_RD),7);
        bufp->chgBit(oldp+1826,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_data_valid));
        bufp->chgBit(oldp+1827,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_pending));
        bufp->chgBit(oldp+1828,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_committed));
        bufp->chgBit(oldp+1829,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_valid));
        bufp->chgCData(oldp+1830,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_memory_type),2);
        bufp->chgCData(oldp+1831,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_ROB_index),6);
        bufp->chgIData(oldp+1832,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_address),32);
        bufp->chgCData(oldp+1833,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_RD),7);
        bufp->chgBit(oldp+1834,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_data_valid));
        bufp->chgBit(oldp+1835,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_pending));
        bufp->chgBit(oldp+1836,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_committed));
        bufp->chgBit(oldp+1837,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_valid));
        bufp->chgCData(oldp+1838,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_memory_type),2);
        bufp->chgCData(oldp+1839,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_ROB_index),6);
        bufp->chgIData(oldp+1840,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_address),32);
        bufp->chgCData(oldp+1841,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_RD),7);
        bufp->chgBit(oldp+1842,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_data_valid));
        bufp->chgBit(oldp+1843,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_pending));
        bufp->chgBit(oldp+1844,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_committed));
        bufp->chgBit(oldp+1845,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_valid));
        bufp->chgCData(oldp+1846,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_memory_type),2);
        bufp->chgCData(oldp+1847,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_ROB_index),6);
        bufp->chgIData(oldp+1848,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_address),32);
        bufp->chgCData(oldp+1849,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_RD),7);
        bufp->chgBit(oldp+1850,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_pending));
        bufp->chgBit(oldp+1851,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_committed));
        bufp->chgBit(oldp+1852,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type))));
        bufp->chgBit(oldp+1853,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_memory_type))));
        bufp->chgBit(oldp+1854,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_memory_type))));
        bufp->chgBit(oldp+1855,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_memory_type))));
        bufp->chgBit(oldp+1856,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_memory_type))));
        bufp->chgBit(oldp+1857,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_memory_type))));
        bufp->chgBit(oldp+1858,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_memory_type))));
        bufp->chgBit(oldp+1859,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_memory_type))));
        bufp->chgBit(oldp+1860,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_memory_type))));
        bufp->chgBit(oldp+1861,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_memory_type))));
        bufp->chgBit(oldp+1862,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_memory_type))));
        bufp->chgBit(oldp+1863,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_memory_type))));
        bufp->chgBit(oldp+1864,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_memory_type))));
        bufp->chgBit(oldp+1865,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_memory_type))));
        bufp->chgBit(oldp+1866,((1U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_memory_type))));
        bufp->chgBit(oldp+1867,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_0));
        bufp->chgBit(oldp+1868,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_1));
        bufp->chgBit(oldp+1869,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_2));
        bufp->chgBit(oldp+1870,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_3));
        bufp->chgBit(oldp+1871,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_4));
        bufp->chgBit(oldp+1872,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_5));
        bufp->chgBit(oldp+1873,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_6));
        bufp->chgBit(oldp+1874,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_7));
        bufp->chgBit(oldp+1875,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_8));
        bufp->chgBit(oldp+1876,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_9));
        bufp->chgBit(oldp+1877,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_10));
        bufp->chgBit(oldp+1878,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_11));
        bufp->chgBit(oldp+1879,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_12));
        bufp->chgBit(oldp+1880,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_13));
        bufp->chgBit(oldp+1881,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_load_vec_14));
        bufp->chgBit(oldp+1882,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_valid) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_committed) 
                                    & (2U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_memory_type))))));
        bufp->chgCData(oldp+1883,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__load_index),4);
        bufp->chgBit(oldp+1884,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_0));
        bufp->chgBit(oldp+1885,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_1));
        bufp->chgBit(oldp+1886,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_2));
        bufp->chgBit(oldp+1887,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_3));
        bufp->chgBit(oldp+1888,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_4));
        bufp->chgBit(oldp+1889,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_5));
        bufp->chgBit(oldp+1890,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_6));
        bufp->chgBit(oldp+1891,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_7));
        bufp->chgBit(oldp+1892,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_8));
        bufp->chgBit(oldp+1893,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_9));
        bufp->chgBit(oldp+1894,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_10));
        bufp->chgBit(oldp+1895,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_11));
        bufp->chgBit(oldp+1896,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_12));
        bufp->chgBit(oldp+1897,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_13));
        bufp->chgBit(oldp+1898,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_stores_14));
        bufp->chgBit(oldp+1899,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_6) 
                                 & (2U == (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_memory_type)))));
        bufp->chgCData(oldp+1900,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index),4);
        bufp->chgCData(oldp+1901,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__availalbe_MOB_entries),5);
        bufp->chgBit(oldp+1902,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty)))));
        bufp->chgCData(oldp+1903,((0x7fU & vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][0U])),7);
        bufp->chgIData(oldp+1904,(((vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][1U] 
                                    << 0x19U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][0U] 
                                                 >> 7U))),32);
        bufp->chgBit(oldp+1905,((1U & (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value][1U] 
                                       >> 7U))));
        bufp->chgBit(oldp+1906,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__empty));
        bufp->chgBit(oldp+1907,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__empty)))));
        bufp->chgCData(oldp+1908,((0x7fU & vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][0U])),7);
        bufp->chgIData(oldp+1909,(((vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][1U] 
                                    << 0x19U) | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][0U] 
                                                 >> 7U))),32);
        bufp->chgBit(oldp+1910,((1U & (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value][1U] 
                                       >> 7U))));
        bufp->chgBit(oldp+1911,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____Vcellinp__FU_output_load_Q__io_enq_valid));
        __Vtemp_89[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_RD)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_RD)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_RD)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_RD)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_RD)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_RD) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_RD) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_RD) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_RD))))))))))));
        __Vtemp_89[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_RD) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_RD)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_RD)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_RD)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_RD)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_RD)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_RD) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_RD) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_RD) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_RD))))))))))) 
                                                >> 0x20U)));
        __Vtemp_89[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_RD) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_RD) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_RD) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_RD) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_RD) 
                                                 >> 1U)))));
        __Vtemp_89[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_RD) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_RD) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_RD) 
                                                >> 5U)));
        bufp->chgCData(oldp+1912,(((0x6fU >= (0x7fU 
                                              & ((IData)(7U) 
                                                 * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                                                  ? 0U
                                                  : 
                                                 (__Vtemp_89[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0x7fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))))) 
                                                | (__Vtemp_89[
                                                   (3U 
                                                    & (((IData)(7U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+1913,(((0x5fU >= (0x7fU 
                                              & ((IData)(6U) 
                                                 * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                                    ? (0x3fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(6U) 
                                                      * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                                  (((IData)(5U) 
                                                    + 
                                                    (0x7fU 
                                                     & ((IData)(6U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(6U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))))) 
                                                | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                                   (3U 
                                                    & (((IData)(6U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(6U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))))
                                    : 0U)),6);
        bufp->chgBit(oldp+1914,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____Vcellinp__FU_output_load_Q__io_flush));
        bufp->chgBit(oldp+1915,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__maybe_full))))));
        bufp->chgCData(oldp+1916,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__enq_ptr_value),2);
        bufp->chgCData(oldp+1917,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value),2);
        bufp->chgBit(oldp+1918,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1919,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1920,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__do_enq));
        bufp->chgWData(oldp+1921,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__deq_ptr_value]),192);
        __Vtemp_97[0U] = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_RD)) 
                                   << 0x38U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_RD)) 
                                                 << 0x31U) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_RD)) 
                                                    << 0x2aU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_RD)) 
                                                       << 0x23U) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_RD)) 
                                                          << 0x1cU) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_RD) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_RD) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_RD) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_RD))))))))))));
        __Vtemp_97[1U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_RD) 
                           << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_8_RD)) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_7_RD)) 
                                                     << 0x31U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_6_RD)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_5_RD)) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_4_RD)) 
                                                              << 0x1cU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_3_RD) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_2_RD) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_1_RD) 
                                                                                << 7U) 
                                                                                | (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_0_RD))))))))))) 
                                                >> 0x20U)));
        __Vtemp_97[2U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_RD) 
                           << 0x1bU) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_12_RD) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_11_RD) 
                                            << 0xdU) 
                                           | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_10_RD) 
                                               << 6U) 
                                              | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_9_RD) 
                                                 >> 1U)))));
        __Vtemp_97[3U] = (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_15_RD) 
                           << 9U) | (((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_14_RD) 
                                      << 2U) | ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__MOB_13_RD) 
                                                >> 5U)));
        __Vtemp_100[0U] = ((0x6fU >= (0x7fU & ((IData)(7U) 
                                               * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                            ? (0x7fU & (((0U == (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                                          ? 0U : (__Vtemp_97[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0x7fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))))) 
                                        | (__Vtemp_97[
                                           (3U & (((IData)(7U) 
                                                   * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)) 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(7U) 
                                                  * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))))
                            : 0U);
        __Vtemp_100[1U] = 0x80U;
        __Vtemp_100[2U] = 0U;
        __Vtemp_100[3U] = 0U;
        __Vtemp_100[4U] = 0U;
        __Vtemp_100[5U] = (((0x5fU >= (0x7fU & ((IData)(6U) 
                                                * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                             ? (0x3fU & (((0U == (0x1fU 
                                                  & ((IData)(6U) 
                                                     * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))
                                           ? 0U : (
                                                   vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x7fU 
                                                      & ((IData)(6U) 
                                                         * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(6U) 
                                                        * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)))))) 
                                         | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                            (3U & (
                                                   ((IData)(6U) 
                                                    * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index)) 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & ((IData)(6U) 
                                                   * (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__possible_FU_load_index))))))
                             : 0U) << 0x13U);
        bufp->chgWData(oldp+1927,(__Vtemp_100),192);
        bufp->chgWData(oldp+1933,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory[0]),192);
        bufp->chgWData(oldp+1939,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory[1]),192);
        bufp->chgWData(oldp+1945,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory[2]),192);
        bufp->chgWData(oldp+1951,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__ram_ext__DOT__Memory[3]),192);
        bufp->chgBit(oldp+1957,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_load_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgCData(oldp+1958,(((0x5fU >= (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3))
                                    ? (0x3fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3)))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                                  (((IData)(5U) 
                                                    + (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3))))) 
                                                | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3) 
                                                    >> 5U)] 
                                                   >> 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3)))))
                                    : 0U)),6);
        bufp->chgBit(oldp+1959,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__maybe_full))))));
        bufp->chgCData(oldp+1960,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__enq_ptr_value),2);
        bufp->chgCData(oldp+1961,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value),2);
        bufp->chgBit(oldp+1962,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1963,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1964,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__empty));
        bufp->chgBit(oldp+1965,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__do_enq));
        bufp->chgWData(oldp+1966,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__deq_ptr_value]),192);
        __Vtemp_103[0U] = 0U;
        __Vtemp_103[1U] = 0U;
        __Vtemp_103[2U] = 0U;
        __Vtemp_103[3U] = 0U;
        __Vtemp_103[4U] = 0U;
        __Vtemp_103[5U] = (((0x5fU >= (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3))
                             ? (0x3fU & (((0U == (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3)))
                                           ? 0U : (
                                                   vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                                   (((IData)(5U) 
                                                     + (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3))))) 
                                         | (vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT___GEN_2[
                                            ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3) 
                                             >> 5U)] 
                                            >> (0x1fU 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT____VdfgRegularize_hfcbcbef8_1_3)))))
                             : 0U) << 0x13U);
        bufp->chgWData(oldp+1972,(__Vtemp_103),192);
        bufp->chgWData(oldp+1978,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory[0]),192);
        bufp->chgWData(oldp+1984,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory[1]),192);
        bufp->chgWData(oldp+1990,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory[2]),192);
        bufp->chgWData(oldp+1996,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__ram_ext__DOT__Memory[3]),192);
        bufp->chgBit(oldp+2002,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__FU_output_store_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2003,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__written_vec_0));
        bufp->chgBit(oldp+2004,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__written_vec_1));
        bufp->chgBit(oldp+2005,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__written_vec_2));
        bufp->chgBit(oldp+2006,(vlSelf->top__DOT__dut__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__written_vec_3));
        bufp->chgBit(oldp+2007,(vlSelf->top__DOT__dut__DOT____Vcellinp__frontend__io_renamed_decoded_fetch_packet_ready));
        bufp->chgBit(oldp+2008,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__full)))));
        bufp->chgBit(oldp+2009,(vlSelf->top__DOT__dut__DOT__frontend__DOT____Vcellinp__FTQ_queue__io_enq_valid));
        bufp->chgBit(oldp+2010,((1U & vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][0U])));
        bufp->chgIData(oldp+2011,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                    << 0x1fU) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][0U] 
                                                 >> 1U))),32);
        bufp->chgBit(oldp+2012,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                       >> 1U))));
        bufp->chgIData(oldp+2013,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                    << 0x1eU) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                                 >> 2U))),32);
        bufp->chgBit(oldp+2014,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                       >> 2U))));
        bufp->chgCData(oldp+2015,((7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                         >> 3U))),3);
        bufp->chgCData(oldp+2016,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                         >> 6U))),2);
        bufp->chgIData(oldp+2017,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][3U] 
                                    << 0x18U) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                                 >> 8U))),32);
        bufp->chgBit(oldp+2018,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__io_predictions_in_ready_REG));
        bufp->chgBit(oldp+2019,(vlSelf->top__DOT__dut__DOT__frontend__DOT___FTQ_queue_io_deq_valid));
        bufp->chgBit(oldp+2020,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                        ? vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][0U]
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][0U])))));
        bufp->chgIData(oldp+2021,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                    ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                        << 0x1fU) | 
                                       (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][0U] 
                                        >> 1U)) : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                    ? 
                                                   ((vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                     << 0x1fU) 
                                                    | (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                       >> 1U))
                                                    : 0U))),32);
        bufp->chgBit(oldp+2022,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                           >> 1U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                           >> 1U))))));
        bufp->chgIData(oldp+2023,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                    ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                        << 0x1eU) | 
                                       (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                        >> 2U)) : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                    ? 
                                                   ((vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                     << 0x1eU) 
                                                    | (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                       >> 2U))
                                                    : 0U))),32);
        bufp->chgBit(oldp+2024,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                           >> 2U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                           >> 2U))))));
        bufp->chgCData(oldp+2025,((7U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                              << 0x1dU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                                >> 3U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                  << 0x1dU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    >> 3U))
                                              : 0U)))),3);
        bufp->chgCData(oldp+2026,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                              << 0x1aU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                                >> 6U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                  << 0x1aU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    >> 6U))
                                              : 0U)))),2);
        bufp->chgIData(oldp+2027,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty)
                                    ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][3U] 
                                        << 0x18U) | 
                                       (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                        >> 8U)) : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                    ? 
                                                   ((vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                     << 0x18U) 
                                                    | (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                       >> 8U))
                                                    : 0U))),32);
        bufp->chgBit(oldp+2028,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__do_deq));
        bufp->chgCData(oldp+2029,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+2030,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+2031,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__maybe_full));
        bufp->chgBit(oldp+2032,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ptr_match));
        bufp->chgBit(oldp+2033,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__empty));
        bufp->chgBit(oldp+2034,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__full));
        bufp->chgBit(oldp+2035,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__do_enq));
        bufp->chgCData(oldp+2036,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value)))),4);
        if (vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_105[0U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_105[1U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_105[2U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_105[3U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT___R0_addr_d0][3U];
        } else {
            __Vtemp_105[0U] = 0U;
            __Vtemp_105[1U] = 0U;
            __Vtemp_105[2U] = 0U;
            __Vtemp_105[3U] = 0U;
        }
        bufp->chgWData(oldp+2037,(__Vtemp_105),104);
        bufp->chgWData(oldp+2041,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1]),104);
        bufp->chgWData(oldp+2045,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[0]),104);
        bufp->chgWData(oldp+2049,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[1]),104);
        bufp->chgWData(oldp+2053,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[2]),104);
        bufp->chgWData(oldp+2057,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[3]),104);
        bufp->chgWData(oldp+2061,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[4]),104);
        bufp->chgWData(oldp+2065,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[5]),104);
        bufp->chgWData(oldp+2069,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[6]),104);
        bufp->chgWData(oldp+2073,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[7]),104);
        bufp->chgWData(oldp+2077,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[8]),104);
        bufp->chgWData(oldp+2081,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[9]),104);
        bufp->chgWData(oldp+2085,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[10]),104);
        bufp->chgWData(oldp+2089,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[11]),104);
        bufp->chgWData(oldp+2093,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[12]),104);
        bufp->chgWData(oldp+2097,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[13]),104);
        bufp->chgWData(oldp+2101,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[14]),104);
        bufp->chgWData(oldp+2105,(vlSelf->top__DOT__dut__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[15]),104);
        bufp->chgBit(oldp+2109,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__io_fetch_packet_ready_REG));
        bufp->chgBit(oldp+2110,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__empty)))));
        bufp->chgIData(oldp+2111,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][0U]),32);
        bufp->chgBit(oldp+2112,((1U & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U])));
        bufp->chgBit(oldp+2113,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 1U))));
        bufp->chgBit(oldp+2114,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 2U))));
        bufp->chgBit(oldp+2115,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 3U))));
        bufp->chgIData(oldp+2116,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                    << 0x1cU) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                 >> 4U))),32);
        bufp->chgCData(oldp+2117,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                           >> 4U))),4);
        bufp->chgIData(oldp+2118,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                    << 0x12U) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                 >> 0xeU))),32);
        bufp->chgCData(oldp+2119,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0xeU))),4);
        bufp->chgIData(oldp+2120,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                    << 8U) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                              >> 0x18U))),32);
        bufp->chgCData(oldp+2121,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                           >> 0x18U))),4);
        bufp->chgIData(oldp+2122,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                    << 0x1eU) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                 >> 2U))),32);
        bufp->chgCData(oldp+2123,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 2U))),4);
        bufp->chgSData(oldp+2124,((0xffffU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                              >> 0xcU))),16);
        bufp->chgCData(oldp+2125,((0x7fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                             << 4U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                               >> 0x1cU)))),7);
        bufp->chgCData(oldp+2126,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                            >> 3U))),7);
        bufp->chgBit(oldp+2127,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__io_predictions_in_ready_REG));
        bufp->chgBit(oldp+2128,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__empty)))));
        bufp->chgBit(oldp+2129,((1U & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][0U])));
        bufp->chgIData(oldp+2130,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                    << 0x1fU) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][0U] 
                                                 >> 1U))),32);
        bufp->chgBit(oldp+2131,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                       >> 1U))));
        bufp->chgIData(oldp+2132,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                    << 0x1eU) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                                 >> 2U))),32);
        bufp->chgBit(oldp+2133,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                       >> 2U))));
        bufp->chgCData(oldp+2134,((7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                         >> 3U))),3);
        bufp->chgCData(oldp+2135,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                         >> 6U))),2);
        bufp->chgIData(oldp+2136,(((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][3U] 
                                    << 0x18U) | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1][2U] 
                                                 >> 8U))),32);
        bufp->chgBit(oldp+2137,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__full)))));
        bufp->chgBit(oldp+2138,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__empty)))));
        bufp->chgIData(oldp+2139,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0U]),32);
        bufp->chgBit(oldp+2140,((1U & vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U])));
        bufp->chgBit(oldp+2141,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 1U))));
        bufp->chgCData(oldp+2142,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                            >> 2U))),5);
        bufp->chgCData(oldp+2143,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                            >> 7U))),7);
        bufp->chgBit(oldp+2144,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 0xeU))));
        bufp->chgCData(oldp+2145,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                            >> 0xfU))),7);
        bufp->chgBit(oldp+2146,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 0x16U))));
        bufp->chgCData(oldp+2147,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                            >> 0x17U))),7);
        bufp->chgBit(oldp+2148,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                       >> 0x1eU))));
        bufp->chgIData(oldp+2149,((0x1fffffU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                 << 1U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                   >> 0x1fU)))),21);
        bufp->chgCData(oldp+2150,((7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                         >> 0x14U))),3);
        bufp->chgCData(oldp+2151,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                         >> 0x17U))),2);
        bufp->chgCData(oldp+2152,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                            >> 0x19U))),6);
        bufp->chgCData(oldp+2153,((0xfU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                            << 1U) 
                                           | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                              >> 0x1fU)))),4);
        bufp->chgCData(oldp+2154,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 3U))),4);
        bufp->chgCData(oldp+2155,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                            >> 7U))),5);
        bufp->chgCData(oldp+2156,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                         >> 0xcU))),2);
        bufp->chgCData(oldp+2157,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                         >> 0xeU))),2);
        bufp->chgBit(oldp+2158,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+2159,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x11U))));
        bufp->chgBit(oldp+2160,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x12U))));
        bufp->chgBit(oldp+2161,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x13U))));
        bufp->chgBit(oldp+2162,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x14U))));
        bufp->chgBit(oldp+2163,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x15U))));
        bufp->chgCData(oldp+2164,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                         >> 0x16U))),2);
        bufp->chgCData(oldp+2165,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                         >> 0x18U))),2);
        bufp->chgBit(oldp+2166,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x1aU))));
        bufp->chgBit(oldp+2167,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                       >> 0x1bU))));
        bufp->chgCData(oldp+2168,((0x1fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                             << 4U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                               >> 0x1cU)))),5);
        bufp->chgCData(oldp+2169,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                            >> 1U))),7);
        bufp->chgBit(oldp+2170,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                       >> 8U))));
        bufp->chgCData(oldp+2171,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                            >> 9U))),7);
        bufp->chgBit(oldp+2172,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                       >> 0x10U))));
        bufp->chgCData(oldp+2173,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                            >> 0x11U))),7);
        bufp->chgBit(oldp+2174,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                       >> 0x18U))));
        bufp->chgIData(oldp+2175,((0x1fffffU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                 << 7U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                                   >> 0x19U)))),21);
        bufp->chgCData(oldp+2176,((7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                         >> 0xeU))),3);
        bufp->chgCData(oldp+2177,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                         >> 0x11U))),2);
        bufp->chgCData(oldp+2178,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                            >> 0x13U))),6);
        bufp->chgCData(oldp+2179,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                           >> 0x19U))),4);
        bufp->chgCData(oldp+2180,((0xfU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                            << 3U) 
                                           | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                              >> 0x1dU)))),4);
        bufp->chgCData(oldp+2181,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                            >> 1U))),5);
        bufp->chgCData(oldp+2182,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                         >> 6U))),2);
        bufp->chgCData(oldp+2183,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                         >> 8U))),2);
        bufp->chgBit(oldp+2184,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0xaU))));
        bufp->chgBit(oldp+2185,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0xbU))));
        bufp->chgBit(oldp+2186,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0xcU))));
        bufp->chgBit(oldp+2187,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2188,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0xeU))));
        bufp->chgBit(oldp+2189,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0xfU))));
        bufp->chgCData(oldp+2190,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                         >> 0x10U))),2);
        bufp->chgCData(oldp+2191,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                         >> 0x12U))),2);
        bufp->chgBit(oldp+2192,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0x14U))));
        bufp->chgBit(oldp+2193,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                       >> 0x15U))));
        bufp->chgCData(oldp+2194,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                            >> 0x16U))),5);
        bufp->chgCData(oldp+2195,((0x7fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                             << 5U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                               >> 0x1bU)))),7);
        bufp->chgBit(oldp+2196,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                       >> 2U))));
        bufp->chgCData(oldp+2197,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                            >> 3U))),7);
        bufp->chgBit(oldp+2198,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2199,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                            >> 0xbU))),7);
        bufp->chgBit(oldp+2200,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                       >> 0x12U))));
        bufp->chgIData(oldp+2201,((0x1fffffU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                 << 0xdU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                                   >> 0x13U)))),21);
        bufp->chgCData(oldp+2202,((7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                         >> 8U))),3);
        bufp->chgCData(oldp+2203,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                         >> 0xbU))),2);
        bufp->chgCData(oldp+2204,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                            >> 0xdU))),6);
        bufp->chgCData(oldp+2205,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                           >> 0x13U))),4);
        bufp->chgCData(oldp+2206,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                           >> 0x17U))),4);
        bufp->chgCData(oldp+2207,((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                   >> 0x1bU)),5);
        bufp->chgCData(oldp+2208,((3U & vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U])),2);
        bufp->chgCData(oldp+2209,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                         >> 2U))),2);
        bufp->chgBit(oldp+2210,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 4U))));
        bufp->chgBit(oldp+2211,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 5U))));
        bufp->chgBit(oldp+2212,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 6U))));
        bufp->chgBit(oldp+2213,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 7U))));
        bufp->chgBit(oldp+2214,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 8U))));
        bufp->chgBit(oldp+2215,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 9U))));
        bufp->chgCData(oldp+2216,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                         >> 0xaU))),2);
        bufp->chgCData(oldp+2217,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                         >> 0xcU))),2);
        bufp->chgBit(oldp+2218,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 0xeU))));
        bufp->chgBit(oldp+2219,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 0xfU))));
        bufp->chgCData(oldp+2220,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                            >> 0x10U))),5);
        bufp->chgCData(oldp+2221,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                            >> 0x15U))),7);
        bufp->chgBit(oldp+2222,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                       >> 0x1cU))));
        bufp->chgCData(oldp+2223,((0x7fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xaU] 
                                             << 3U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                               >> 0x1dU)))),7);
        bufp->chgBit(oldp+2224,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xaU] 
                                       >> 4U))));
        bufp->chgCData(oldp+2225,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xaU] 
                                            >> 5U))),7);
        bufp->chgBit(oldp+2226,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xaU] 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2227,((0x1fffffU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                 << 0x13U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xaU] 
                                                   >> 0xdU)))),21);
        bufp->chgCData(oldp+2228,((7U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                         >> 2U))),3);
        bufp->chgCData(oldp+2229,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                         >> 5U))),2);
        bufp->chgCData(oldp+2230,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                            >> 7U))),6);
        bufp->chgCData(oldp+2231,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                           >> 0xdU))),4);
        bufp->chgCData(oldp+2232,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                           >> 0x11U))),4);
        bufp->chgCData(oldp+2233,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                            >> 0x15U))),5);
        bufp->chgCData(oldp+2234,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                         >> 0x1aU))),2);
        bufp->chgCData(oldp+2235,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                         >> 0x1cU))),2);
        bufp->chgBit(oldp+2236,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                       >> 0x1eU))));
        bufp->chgBit(oldp+2237,((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                 >> 0x1fU)));
        bufp->chgBit(oldp+2238,((1U & vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU])));
        bufp->chgBit(oldp+2239,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 1U))));
        bufp->chgBit(oldp+2240,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 2U))));
        bufp->chgBit(oldp+2241,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 3U))));
        bufp->chgCData(oldp+2242,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                         >> 4U))),2);
        bufp->chgCData(oldp+2243,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                         >> 6U))),2);
        bufp->chgBit(oldp+2244,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 8U))));
        bufp->chgBit(oldp+2245,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 9U))));
        bufp->chgBit(oldp+2246,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 0xaU))));
        bufp->chgBit(oldp+2247,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                       >> 0xbU))));
        bufp->chgSData(oldp+2248,((0xffffU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                              >> 0xcU))),16);
        bufp->chgCData(oldp+2249,((0x7fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                             << 4U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                               >> 0x1cU)))),7);
        bufp->chgCData(oldp+2250,((0x7fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                            >> 3U))),7);
        bufp->chgCData(oldp+2251,((0xfU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                           >> 0xaU))),4);
        bufp->chgCData(oldp+2252,((0xffU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                            >> 0xeU))),8);
        bufp->chgBit(oldp+2253,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__empty)))));
        bufp->chgBit(oldp+2254,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q_io_deq_ready));
        bufp->chgBit(oldp+2255,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__monitor_output_REG));
        bufp->chgBit(oldp+2256,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__predictions_out_Q__io_enq_valid));
        bufp->chgCData(oldp+2257,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_RDold),5);
        bufp->chgCData(oldp+2258,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_RDold),7);
        bufp->chgBit(oldp+2259,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((0x1bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                        | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                           | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                              | (0x1cU 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType))))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_0__io_instruction_valid))));
        bufp->chgCData(oldp+2260,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                            >> 0x13U))),7);
        bufp->chgBit(oldp+2261,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                        | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_0__io_instruction_valid))));
        bufp->chgCData(oldp+2262,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                            >> 0x18U))),7);
        bufp->chgBit(oldp+2263,((((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                     | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_0__io_instruction_valid))));
        bufp->chgIData(oldp+2264,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_IMM),21);
        bufp->chgCData(oldp+2265,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3),3);
        bufp->chgCData(oldp+2266,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                         >> 4U))),2);
        bufp->chgCData(oldp+2267,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType),5);
        bufp->chgCData(oldp+2268,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__needs_ALU)
                                          ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__next_ALU_port_0)
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_needs_branch_unit)
                                              ? 0U : 
                                             (((0xcU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                               & (((4U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3)) 
                                                      | ((6U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3)) 
                                                         | (7U 
                                                            == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3))))) 
                                                  & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                     >> 0x1dU)))
                                               ? 1U
                                               : (- (IData)(
                                                            ((8U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                                             | (0U 
                                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)))))))))),2);
        bufp->chgCData(oldp+2269,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                    | ((0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                       | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_5) 
                                          | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_6))))
                                    ? 0U : (((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                             | (8U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)))
                                             ? 1U : 2U))),2);
        bufp->chgBit(oldp+2270,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__needs_ALU));
        bufp->chgBit(oldp+2271,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_needs_branch_unit));
        bufp->chgBit(oldp+2272,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                 & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2273,(((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                 & (1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2274,(((4U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                 | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                    | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                       | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                          | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                             | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_needs_branch_unit))))))));
        bufp->chgCData(oldp+2275,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType))
                                    ? 1U : ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType)) 
                                            << 1U))),2);
        bufp->chgCData(oldp+2276,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3))
                                    ? 1U : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3))
                                             ? 2U : 
                                            (3U & (- (IData)(
                                                             (2U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits_FUNCT3)))))))),2);
        bufp->chgCData(oldp+2277,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_RDold),5);
        bufp->chgCData(oldp+2278,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_RDold),7);
        bufp->chgBit(oldp+2279,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((0x1bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                        | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                           | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                              | (0x1cU 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType))))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_1__io_instruction_valid))));
        bufp->chgCData(oldp+2280,((0x1fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                             << 3U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                               >> 0x1dU)))),7);
        bufp->chgBit(oldp+2281,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                        | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_1__io_instruction_valid))));
        bufp->chgCData(oldp+2282,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                            >> 2U))),7);
        bufp->chgBit(oldp+2283,((((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                     | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_1__io_instruction_valid))));
        bufp->chgIData(oldp+2284,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_IMM),21);
        bufp->chgCData(oldp+2285,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3),3);
        bufp->chgCData(oldp+2286,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                         >> 0xeU))),2);
        bufp->chgCData(oldp+2287,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType),5);
        bufp->chgCData(oldp+2288,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__needs_ALU)
                                          ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__next_ALU_port_0)
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_needs_branch_unit)
                                              ? 0U : 
                                             (((0xcU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                               & (((4U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3)) 
                                                      | ((6U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3)) 
                                                         | (7U 
                                                            == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3))))) 
                                                  & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                     >> 7U)))
                                               ? 1U
                                               : (- (IData)(
                                                            ((8U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                                             | (0U 
                                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)))))))))),2);
        bufp->chgCData(oldp+2289,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                    | ((0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                       | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_5) 
                                          | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_6))))
                                    ? 0U : (((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                             | (8U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)))
                                             ? 1U : 2U))),2);
        bufp->chgBit(oldp+2290,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__needs_ALU));
        bufp->chgBit(oldp+2291,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_needs_branch_unit));
        bufp->chgBit(oldp+2292,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                 & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2293,(((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                 & (1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2294,(((4U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                 | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                    | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                       | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                          | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                             | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_needs_branch_unit))))))));
        bufp->chgCData(oldp+2295,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType))
                                    ? 1U : ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType)) 
                                            << 1U))),2);
        bufp->chgCData(oldp+2296,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3))
                                    ? 1U : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3))
                                             ? 2U : 
                                            (3U & (- (IData)(
                                                             (2U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits_FUNCT3)))))))),2);
        bufp->chgCData(oldp+2297,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_RDold),5);
        bufp->chgCData(oldp+2298,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_RDold),7);
        bufp->chgBit(oldp+2299,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((0x1bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                        | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                           | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                              | (0x1cU 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType))))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_2__io_instruction_valid))));
        bufp->chgCData(oldp+2300,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                            >> 7U))),7);
        bufp->chgBit(oldp+2301,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                        | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_2__io_instruction_valid))));
        bufp->chgCData(oldp+2302,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                            >> 0xcU))),7);
        bufp->chgBit(oldp+2303,((((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                     | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_2__io_instruction_valid))));
        bufp->chgIData(oldp+2304,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_IMM),21);
        bufp->chgCData(oldp+2305,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3),3);
        bufp->chgCData(oldp+2306,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                         >> 0x18U))),2);
        bufp->chgCData(oldp+2307,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType),5);
        bufp->chgCData(oldp+2308,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__needs_ALU)
                                          ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__next_ALU_port_0)
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_needs_branch_unit)
                                              ? 0U : 
                                             (((0xcU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                               & (((4U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3)) 
                                                      | ((6U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3)) 
                                                         | (7U 
                                                            == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3))))) 
                                                  & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                                     >> 0x11U)))
                                               ? 1U
                                               : (- (IData)(
                                                            ((8U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                                             | (0U 
                                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)))))))))),2);
        bufp->chgCData(oldp+2309,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                    | ((0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                       | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_5) 
                                          | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_6))))
                                    ? 0U : (((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                             | (8U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)))
                                             ? 1U : 2U))),2);
        bufp->chgBit(oldp+2310,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__needs_ALU));
        bufp->chgBit(oldp+2311,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_needs_branch_unit));
        bufp->chgBit(oldp+2312,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                 & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2313,(((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                 & (1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2314,(((4U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                 | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                    | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                       | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                          | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                             | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_needs_branch_unit))))))));
        bufp->chgCData(oldp+2315,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType))
                                    ? 1U : ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType)) 
                                            << 1U))),2);
        bufp->chgCData(oldp+2316,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3))
                                    ? 1U : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3))
                                             ? 2U : 
                                            (3U & (- (IData)(
                                                             (2U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits_FUNCT3)))))))),2);
        bufp->chgCData(oldp+2317,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_RDold),5);
        bufp->chgCData(oldp+2318,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_RDold),7);
        bufp->chgBit(oldp+2319,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((0x1bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                        | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                           | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                              | (0x1cU 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType))))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_3__io_instruction_valid))));
        bufp->chgCData(oldp+2320,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                            >> 0x11U))),7);
        bufp->chgBit(oldp+2321,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_3) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                     | ((0x19U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                        | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType))))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_3__io_instruction_valid))));
        bufp->chgCData(oldp+2322,((0x1fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                            >> 0x16U))),7);
        bufp->chgBit(oldp+2323,((((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                  | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                     | (0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)))) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_3__io_instruction_valid))));
        bufp->chgIData(oldp+2324,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_IMM),21);
        bufp->chgCData(oldp+2325,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3),3);
        bufp->chgCData(oldp+2326,((3U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                         >> 2U))),2);
        bufp->chgCData(oldp+2327,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType),5);
        bufp->chgCData(oldp+2328,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__needs_ALU)
                                          ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__next_ALU_port_0)
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_needs_branch_unit)
                                              ? 0U : 
                                             (((0xcU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                               & (((4U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3)) 
                                                   | ((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3)) 
                                                      | ((6U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3)) 
                                                         | (7U 
                                                            == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3))))) 
                                                  & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                     >> 0x1bU)))
                                               ? 1U
                                               : (- (IData)(
                                                            ((8U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                                             | (0U 
                                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)))))))))),2);
        bufp->chgCData(oldp+2329,((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                    | ((0x18U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                       | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_5) 
                                          | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_6))))
                                    ? 0U : (((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                             | (8U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)))
                                             ? 1U : 2U))),2);
        bufp->chgBit(oldp+2330,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__needs_ALU));
        bufp->chgBit(oldp+2331,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_needs_branch_unit));
        bufp->chgBit(oldp+2332,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_2) 
                                 & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2333,(((0xcU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                 & (1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT____VdfgRegularize_h662e6b9b_0_1)))));
        bufp->chgBit(oldp+2334,(((4U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                 | ((0xdU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                    | ((5U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                       | ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                          | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                             | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_needs_branch_unit))))))));
        bufp->chgCData(oldp+2335,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType))
                                    ? 1U : ((8U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType)) 
                                            << 1U))),2);
        bufp->chgCData(oldp+2336,(((0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3))
                                    ? 1U : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3))
                                             ? 2U : 
                                            (3U & (- (IData)(
                                                             (2U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits_FUNCT3)))))))),2);
        bufp->chgBit(oldp+2337,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+2338,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap));
        bufp->chgBit(oldp+2339,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+2340,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2341,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2342,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__empty));
        bufp->chgBit(oldp+2343,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__do_enq));
        bufp->chgWData(oldp+2344,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1]),438);
        bufp->chgWData(oldp+2358,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT____Vcellinp__ram_ext__W0_data),438);
        bufp->chgWData(oldp+2372,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[0]),438);
        bufp->chgWData(oldp+2386,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[1]),438);
        bufp->chgBit(oldp+2400,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2401,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_0__io_instruction_valid));
        bufp->chgCData(oldp+2402,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__next_ALU_port_0),2);
        bufp->chgCData(oldp+2403,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__next_ALU_port_1),2);
        bufp->chgCData(oldp+2404,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__next_ALU_port_2),2);
        bufp->chgBit(oldp+2405,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_1__io_instruction_valid));
        bufp->chgCData(oldp+2406,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__next_ALU_port_0),2);
        bufp->chgCData(oldp+2407,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__next_ALU_port_1),2);
        bufp->chgCData(oldp+2408,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__next_ALU_port_2),2);
        bufp->chgBit(oldp+2409,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_2__io_instruction_valid));
        bufp->chgCData(oldp+2410,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__next_ALU_port_0),2);
        bufp->chgCData(oldp+2411,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__next_ALU_port_1),2);
        bufp->chgCData(oldp+2412,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__next_ALU_port_2),2);
        bufp->chgBit(oldp+2413,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT____Vcellinp__decoders_3__io_instruction_valid));
        bufp->chgCData(oldp+2414,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__next_ALU_port_0),2);
        bufp->chgCData(oldp+2415,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__next_ALU_port_1),2);
        bufp->chgCData(oldp+2416,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__next_ALU_port_2),2);
        bufp->chgBit(oldp+2417,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+2418,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap));
        bufp->chgBit(oldp+2419,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+2420,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2421,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2422,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__empty));
        bufp->chgBit(oldp+2423,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__do_enq));
        bufp->chgWData(oldp+2424,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1]),104);
        bufp->chgWData(oldp+2428,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory[0]),104);
        bufp->chgWData(oldp+2432,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory[1]),104);
        bufp->chgBit(oldp+2436,(vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__predictions_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2437,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp_io_flush));
        bufp->chgBit(oldp+2438,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full)))));
        bufp->chgBit(oldp+2439,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__io_deq_valid_0));
        bufp->chgBit(oldp+2440,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_hit));
        bufp->chgIData(oldp+2441,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_target),32);
        bufp->chgCData(oldp+2442,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_br_type),3);
        bufp->chgSData(oldp+2443,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_GHR),16);
        bufp->chgBit(oldp+2444,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_T_NT));
        bufp->chgBit(oldp+2445,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__BTB_Q__io_deq_ready));
        bufp->chgBit(oldp+2446,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___BTB_Q_io_deq_valid));
        bufp->chgBit(oldp+2447,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty)
                                  ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_hit)
                                  : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_en_d0) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_addr_d0])))));
        bufp->chgIData(oldp+2448,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_target
                                    : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_en_d0)
                                        ? (IData)((
                                                   vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_addr_d0] 
                                                   >> 1U))
                                        : 0U))),32);
        bufp->chgCData(oldp+2449,((7U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty)
                                          ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_br_type)
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_en_d0)
                                              ? (IData)(
                                                        (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_addr_d0] 
                                                         >> 0x21U))
                                              : 0U)))),3);
        bufp->chgSData(oldp+2450,((0xffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty)
                                               ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_GHR)
                                               : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                   ? (IData)(
                                                             (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_addr_d0] 
                                                              >> 0x24U))
                                                   : 0U)))),16);
        bufp->chgBit(oldp+2451,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty)
                                  ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_T_NT)
                                  : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_en_d0) 
                                     & (IData)((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_addr_d0] 
                                                >> 0x34U))))));
        bufp->chgBit(oldp+2452,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_deq));
        bufp->chgCData(oldp+2453,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+2454,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+2455,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2456,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2457,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty));
        bufp->chgBit(oldp+2458,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full));
        bufp->chgBit(oldp+2459,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_enq));
        bufp->chgCData(oldp+2460,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value)))),4);
        bufp->chgQData(oldp+2461,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_en_d0)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT___R0_addr_d0]
                                    : 0ULL)),53);
        bufp->chgQData(oldp+2463,((((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_T_NT)) 
                                    << 0x34U) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_GHR)) 
                                                  << 0x24U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_br_type)) 
                                                     << 0x21U) 
                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_target)) 
                                                        << 1U) 
                                                       | (QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_bits_hit))))))),53);
        bufp->chgQData(oldp+2465,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[0]),53);
        bufp->chgQData(oldp+2467,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[1]),53);
        bufp->chgQData(oldp+2469,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[2]),53);
        bufp->chgQData(oldp+2471,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[3]),53);
        bufp->chgQData(oldp+2473,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[4]),53);
        bufp->chgQData(oldp+2475,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[5]),53);
        bufp->chgQData(oldp+2477,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[6]),53);
        bufp->chgQData(oldp+2479,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[7]),53);
        bufp->chgQData(oldp+2481,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[8]),53);
        bufp->chgQData(oldp+2483,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[9]),53);
        bufp->chgQData(oldp+2485,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[10]),53);
        bufp->chgQData(oldp+2487,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[11]),53);
        bufp->chgQData(oldp+2489,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[12]),53);
        bufp->chgQData(oldp+2491,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[13]),53);
        bufp->chgQData(oldp+2493,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[14]),53);
        bufp->chgQData(oldp+2495,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[15]),53);
        bufp->chgBit(oldp+2497,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full)))));
        bufp->chgBit(oldp+2498,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__PC_Q__io_enq_valid));
        bufp->chgIData(oldp+2499,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux),32);
        bufp->chgBit(oldp+2500,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_deq));
        bufp->chgCData(oldp+2501,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+2502,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+2503,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2504,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2505,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty));
        bufp->chgBit(oldp+2506,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full));
        bufp->chgBit(oldp+2507,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq));
        bufp->chgCData(oldp+2508,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value)))),4);
        if (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_107[0U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_107[1U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_107[2U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
        } else {
            __Vtemp_107[0U] = 0U;
            __Vtemp_107[1U] = 0U;
            __Vtemp_107[2U] = 0U;
        }
        bufp->chgWData(oldp+2509,(__Vtemp_107),65);
        __Vtemp_108[0U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux;
        __Vtemp_108[1U] = 0U;
        __Vtemp_108[2U] = 0U;
        bufp->chgWData(oldp+2512,(__Vtemp_108),65);
        bufp->chgWData(oldp+2515,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[0]),65);
        bufp->chgWData(oldp+2518,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[1]),65);
        bufp->chgWData(oldp+2521,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[2]),65);
        bufp->chgWData(oldp+2524,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[3]),65);
        bufp->chgWData(oldp+2527,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[4]),65);
        bufp->chgWData(oldp+2530,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[5]),65);
        bufp->chgWData(oldp+2533,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[6]),65);
        bufp->chgWData(oldp+2536,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[7]),65);
        bufp->chgWData(oldp+2539,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[8]),65);
        bufp->chgWData(oldp+2542,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[9]),65);
        bufp->chgWData(oldp+2545,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[10]),65);
        bufp->chgWData(oldp+2548,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[11]),65);
        bufp->chgWData(oldp+2551,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[12]),65);
        bufp->chgWData(oldp+2554,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[13]),65);
        bufp->chgWData(oldp+2557,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[14]),65);
        bufp->chgWData(oldp+2560,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[15]),65);
        bufp->chgCData(oldp+2563,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT),7);
        bufp->chgCData(oldp+2564,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS),7);
        bufp->chgIData(oldp+2565,((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out)),32);
        bufp->chgBit(oldp+2566,((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__flushing_event)))));
        bufp->chgIData(oldp+2567,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_reg),32);
        bufp->chgBit(oldp+2568,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__is_ret));
        bufp->chgBit(oldp+2569,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__flushing_event));
        bufp->chgBit(oldp+2570,((1U & ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full)) 
                                       & (~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__flushing_event))))));
        bufp->chgIData(oldp+2571,(((IData)(4U) + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_16)),32);
        bufp->chgBit(oldp+2572,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))));
        bufp->chgBit(oldp+2573,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))));
        bufp->chgSData(oldp+2574,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___predecoder_io_GHR),16);
        bufp->chgBit(oldp+2575,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_valid_REG));
        bufp->chgBit(oldp+2576,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___BTB_io_BTB_hit));
        bufp->chgIData(oldp+2577,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___BTB_io_BTB_output_BTB_target),32);
        bufp->chgCData(oldp+2578,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___BTB_io_BTB_output_BTBbr_type_t),3);
        bufp->chgBit(oldp+2579,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__BTB__io_commit_valid));
        bufp->chgCData(oldp+2580,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__access_fetch_packet_index),3);
        bufp->chgSData(oldp+2581,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_hit_REG),16);
        bufp->chgSData(oldp+2582,((0xfffU & (vlSelf->top__DOT__io_frontend_memory_request_bits_addr 
                                             >> 4U))),12);
        bufp->chgBit(oldp+2583,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__hazard_reg)
                                  ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_valid)
                                  : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_en_d0) 
                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_addr_d0])))));
        bufp->chgIData(oldp+2584,((0x3ffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__hazard_reg)
                                                ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_tag
                                                : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_en_d0)
                                                    ? (IData)(
                                                              (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_addr_d0] 
                                                               >> 1U))
                                                    : 0U)))),18);
        bufp->chgCData(oldp+2585,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__hazard_reg)
                                          ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_fetch_packet_index)
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_en_d0)
                                              ? (IData)(
                                                        (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT__Memory
                                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_addr_d0] 
                                                         >> 0x36U))
                                              : 0U)))),2);
        bufp->chgSData(oldp+2586,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT____Vcellinp__BTB_memory__io_wr_addr),12);
        bufp->chgIData(oldp+2587,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT____Vcellinp__BTB_memory__io_data_in_BTB_tag),18);
        bufp->chgBit(oldp+2588,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__hazard_reg));
        bufp->chgBit(oldp+2589,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_valid));
        bufp->chgIData(oldp+2590,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_tag),18);
        bufp->chgIData(oldp+2591,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_target),32);
        bufp->chgCData(oldp+2592,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTBbr_type_t),3);
        bufp->chgCData(oldp+2593,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff_BTB_fetch_packet_index),2);
        bufp->chgQData(oldp+2594,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0ULL)),56);
        bufp->chgQData(oldp+2596,((((QData)((IData)(vlSelf->top__DOT__io_commit_bits_fetch_packet_index)) 
                                    << 0x36U) | (((QData)((IData)(vlSelf->top__DOT__io_commit_bits_br_type)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->top__DOT__io_commit_bits_expected_PC)) 
                                                     << 0x13U) 
                                                    | (QData)((IData)(
                                                                      (1U 
                                                                       | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT____Vcellinp__BTB_memory__io_data_in_BTB_tag 
                                                                          << 1U)))))))),56);
        bufp->chgBit(oldp+2598,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_wr_valid));
        bufp->chgBit(oldp+2599,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_rd_valid));
        bufp->chgCData(oldp+2600,((0x7fU & (IData)(
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out 
                                                    >> 0x20U)))),7);
        bufp->chgCData(oldp+2601,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT____Vcellinp__RAS_memory__io_rd_addr),7);
        bufp->chgQData(oldp+2602,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out),39);
        bufp->chgQData(oldp+2604,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT____Vcellinp__RAS_memory__io_data_in),39);
        bufp->chgBit(oldp+2606,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__hazard_reg));
        bufp->chgQData(oldp+2607,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__din_buff),39);
        bufp->chgQData(oldp+2609,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0ULL)),39);
        bufp->chgBit(oldp+2611,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___gshare_io_T_NT));
        bufp->chgBit(oldp+2612,(((IData)(vlSelf->top__DOT__dut__DOT__BRU__DOT__branch_commit) 
                                 & ((0U != (IData)(vlSelf->top__DOT__dut__DOT___FTQ_io_FTQ_br_type)) 
                                    & (IData)(vlSelf->top__DOT__io_commit_valid)))));
        bufp->chgSData(oldp+2613,((0xffffU & (vlSelf->top__DOT__io_frontend_memory_request_bits_addr 
                                              ^ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___predecoder_io_GHR)))),16);
        bufp->chgSData(oldp+2614,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__hashed_commit_addr),16);
        bufp->chgSData(oldp+2615,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT_io_addrC_REG),16);
        bufp->chgBit(oldp+2616,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT_io_writeEnableC_REG));
        bufp->chgBit(oldp+2617,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__REG));
        bufp->chgSData(oldp+2618,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0]
                                    : 0U)),16);
        bufp->chgSData(oldp+2619,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data),16);
        bufp->chgCData(oldp+2620,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__REG)
                                          ? ((3U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data))
                                              ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data)
                                              : ((IData)(1U) 
                                                 + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data)))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data) 
                                             - ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R0_en_d0) 
                                                & (0U 
                                                   != 
                                                   vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R0_addr_d0])))))),2);
        bufp->chgCData(oldp+2621,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data),2);
        bufp->chgCData(oldp+2622,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0]
                                    : 0U)),2);
        bufp->chgQData(oldp+2623,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__ram),53);
        bufp->chgBit(oldp+2625,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__full));
        bufp->chgBit(oldp+2626,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__do_enq));
        bufp->chgBit(oldp+2627,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__io_fetch_packet_ready_REG));
        bufp->chgBit(oldp+2628,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_valid));
        bufp->chgIData(oldp+2629,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC),32);
        bufp->chgBit(oldp+2630,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                  ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_valid_bits_0)
                                  : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0) 
                                     & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][1U]))));
        bufp->chgBit(oldp+2631,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_valid_bits_1));
        bufp->chgBit(oldp+2632,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_valid_bits_2));
        bufp->chgBit(oldp+2633,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_valid_bits_3));
        bufp->chgIData(oldp+2634,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_instructions_0_instruction),32);
        bufp->chgCData(oldp+2635,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                            ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_0_packet_index)
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    << 0x1cU) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                      >> 4U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2636,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                             ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_0_ROB_index)
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                  << 0x18U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    >> 8U))
                                                 : 0U)))),6);
        bufp->chgIData(oldp+2637,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_instructions_1_instruction),32);
        bufp->chgCData(oldp+2638,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                            ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_1_packet_index)
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    << 0x12U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                      >> 0xeU))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2639,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                             ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_1_ROB_index)
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                  << 0xeU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 0x12U))
                                                 : 0U)))),6);
        bufp->chgIData(oldp+2640,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_instructions_2_instruction),32);
        bufp->chgCData(oldp+2641,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                            ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_2_packet_index)
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][4U] 
                                                    << 8U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][4U] 
                                                      >> 0x18U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2642,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                             ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_2_ROB_index)
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                  << 4U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][4U] 
                                                    >> 0x1cU))
                                                 : 0U)))),6);
        bufp->chgIData(oldp+2643,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_instructions_3_instruction),32);
        bufp->chgCData(oldp+2644,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                            ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_3_packet_index)
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    << 0x1eU) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                      >> 2U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2645,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                             ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_instructions_3_ROB_index)
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0x1aU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 6U))
                                                 : 0U)))),6);
        bufp->chgSData(oldp+2646,((0xffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                               ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_GHR)
                                               : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                   ? 
                                                  ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    << 0x14U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                      >> 0xcU))
                                                   : 0U)))),16);
        bufp->chgCData(oldp+2647,((0x7fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                             ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_NEXT)
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][7U] 
                                                  << 4U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 0x1cU))
                                                 : 0U)))),7);
        bufp->chgCData(oldp+2648,((0x7fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                             ? (IData)(vlSelf->top__DOT__io_frontend_memory_response_bits_TOS)
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][7U] 
                                                  << 0x1dU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][7U] 
                                                    >> 3U))
                                                 : 0U)))),7);
        bufp->chgBit(oldp+2649,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_deq));
        bufp->chgCData(oldp+2650,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+2651,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+2652,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2653,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2654,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty));
        bufp->chgBit(oldp+2655,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full))));
        bufp->chgBit(oldp+2656,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq));
        bufp->chgCData(oldp+2657,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value)))),4);
        if (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_109[0U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_109[1U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_109[2U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_109[3U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_109[4U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_109[5U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_109[6U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_109[7U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][7U];
        } else {
            __Vtemp_109[0U] = Vtop__ConstPool__CONST_h9513bbd8_0[0U];
            __Vtemp_109[1U] = Vtop__ConstPool__CONST_h9513bbd8_0[1U];
            __Vtemp_109[2U] = Vtop__ConstPool__CONST_h9513bbd8_0[2U];
            __Vtemp_109[3U] = Vtop__ConstPool__CONST_h9513bbd8_0[3U];
            __Vtemp_109[4U] = Vtop__ConstPool__CONST_h9513bbd8_0[4U];
            __Vtemp_109[5U] = Vtop__ConstPool__CONST_h9513bbd8_0[5U];
            __Vtemp_109[6U] = Vtop__ConstPool__CONST_h9513bbd8_0[6U];
            __Vtemp_109[7U] = Vtop__ConstPool__CONST_h9513bbd8_0[7U];
        }
        bufp->chgWData(oldp+2658,(__Vtemp_109),234);
        bufp->chgWData(oldp+2666,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[0]),234);
        bufp->chgWData(oldp+2674,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[1]),234);
        bufp->chgWData(oldp+2682,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[2]),234);
        bufp->chgWData(oldp+2690,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[3]),234);
        bufp->chgWData(oldp+2698,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[4]),234);
        bufp->chgWData(oldp+2706,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[5]),234);
        bufp->chgWData(oldp+2714,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[6]),234);
        bufp->chgWData(oldp+2722,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[7]),234);
        bufp->chgWData(oldp+2730,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[8]),234);
        bufp->chgWData(oldp+2738,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[9]),234);
        bufp->chgWData(oldp+2746,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[10]),234);
        bufp->chgWData(oldp+2754,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[11]),234);
        bufp->chgWData(oldp+2762,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[12]),234);
        bufp->chgWData(oldp+2770,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[13]),234);
        bufp->chgWData(oldp+2778,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[14]),234);
        bufp->chgWData(oldp+2786,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[15]),234);
        bufp->chgBit(oldp+2794,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__io_prediction_ready_REG));
        bufp->chgCData(oldp+2795,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                            >> 8U))),6);
        bufp->chgCData(oldp+2796,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                            >> 0x12U))),6);
        bufp->chgCData(oldp+2797,((0x3fU & ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                             << 4U) 
                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                               >> 0x1cU)))),6);
        bufp->chgCData(oldp+2798,((0x3fU & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                            >> 6U))),6);
        bufp->chgBit(oldp+2799,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR));
        bufp->chgBit(oldp+2800,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL));
        bufp->chgBit(oldp+2801,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL));
        bufp->chgBit(oldp+2802,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR));
        bufp->chgBit(oldp+2803,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH));
        bufp->chgBit(oldp+2804,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken));
        bufp->chgBit(oldp+2805,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH) 
                                 | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL) 
                                    | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR)))));
        bufp->chgBit(oldp+2806,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_1));
        bufp->chgBit(oldp+2807,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_1));
        bufp->chgBit(oldp+2808,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_1));
        bufp->chgBit(oldp+2809,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT_2));
        bufp->chgBit(oldp+2810,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_1) 
                                 | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_1) 
                                    | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_1)))));
        bufp->chgBit(oldp+2811,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_2));
        bufp->chgBit(oldp+2812,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_2));
        bufp->chgBit(oldp+2813,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_2));
        bufp->chgBit(oldp+2814,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT_1));
        bufp->chgBit(oldp+2815,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_3));
        bufp->chgBit(oldp+2816,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_3));
        bufp->chgBit(oldp+2817,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_3));
        bufp->chgBit(oldp+2818,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT_0));
        bufp->chgBit(oldp+2819,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH));
        bufp->chgBit(oldp+2820,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET));
        bufp->chgBit(oldp+2821,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL));
        bufp->chgCData(oldp+2822,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__dominant_branch_index),2);
        bufp->chgIData(oldp+2823,((0xfffffff0U & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC)),32);
        bufp->chgIData(oldp+2824,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__target_address),32);
        bufp->chgBit(oldp+2825,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_valid));
        bufp->chgBit(oldp+2826,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__output_ready));
        bufp->chgBit(oldp+2827,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid));
        bufp->chgSData(oldp+2828,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__GHR),16);
        bufp->chgBit(oldp+2829,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_bits_T_NT));
        bufp->chgBit(oldp+2830,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____Vcellinp__final_fetch_packet_out_Q__io_enq_bits_valid_bits_0));
        bufp->chgBit(oldp+2831,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_valid_bits_1) 
                                 & ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT_0)) 
                                    & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_valid)))));
        bufp->chgBit(oldp+2832,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_valid_bits_2) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_valid) 
                                    & (0U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_15))))));
        bufp->chgBit(oldp+2833,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_valid_bits_3) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_valid) 
                                    & (0U == (3U & 
                                              ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_15) 
                                               + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT_2))))))));
        bufp->chgBit(oldp+2834,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+2835,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap));
        bufp->chgBit(oldp+2836,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+2837,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2838,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2839,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__empty));
        bufp->chgBit(oldp+2840,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq));
        bufp->chgWData(oldp+2841,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1]),234);
        bufp->chgWData(oldp+2849,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT____Vcellinp__ram_ext__W0_data),234);
        bufp->chgWData(oldp+2857,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[0]),234);
        bufp->chgWData(oldp+2865,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[1]),234);
        bufp->chgBit(oldp+2873,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2874,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_4) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))));
        bufp->chgIData(oldp+2875,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_bits_T_NT)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__target_address
                                    : ((IData)(0x10U) 
                                       + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC))),32);
        bufp->chgCData(oldp+2876,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH)
                                    ? 1U : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET)
                                             ? 4U : 
                                            ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL)
                                              ? 5U : 
                                             ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR)
                                               ? 3U
                                               : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL) 
                                                  << 1U)))))),3);
        bufp->chgIData(oldp+2877,(((IData)(0x10U) + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC)),32);
        bufp->chgBit(oldp+2878,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+2879,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap));
        bufp->chgBit(oldp+2880,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+2881,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+2882,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+2883,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__empty));
        bufp->chgBit(oldp+2884,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__do_enq));
        __Vtemp_114[0U] = (IData)(((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC)) 
                                   << 1U));
        __Vtemp_114[1U] = ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_bits_T_NT)
                              ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__target_address
                              : ((IData)(0x10U) + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC)) 
                            << 2U) | (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC)) 
                                               << 1U) 
                                              >> 0x20U)));
        __Vtemp_114[2U] = (0xc0U | ((((IData)(0x10U) 
                                      + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC) 
                                     << 8U) | ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH)
                                                  ? 1U
                                                  : 
                                                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET)
                                                   ? 4U
                                                   : 
                                                  ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL)
                                                    ? 5U
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR)
                                                     ? 3U
                                                     : 
                                                    ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL) 
                                                     << 1U))))) 
                                                << 3U) 
                                               | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_bits_T_NT) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_bits_T_NT)
                                                       ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__target_address
                                                       : 
                                                      ((IData)(0x10U) 
                                                       + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC)) 
                                                     >> 0x1eU)))));
        __Vtemp_114[3U] = (((IData)(0x10U) + vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_bits_fetch_PC) 
                           >> 0x18U);
        bufp->chgWData(oldp+2885,(__Vtemp_114),104);
        bufp->chgWData(oldp+2889,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory[0]),104);
        bufp->chgWData(oldp+2893,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory[1]),104);
        bufp->chgBit(oldp+2897,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2898,(vlSelf->top__DOT__dut__DOT__frontend__DOT____Vcellinp__instruction_queue__io_enq_valid));
        bufp->chgBit(oldp+2899,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__io_decoded_fetch_packet_ready_REG));
        bufp->chgBit(oldp+2900,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_valid));
        bufp->chgIData(oldp+2901,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                    ? vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0U]
                                    : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                        ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0U]
                                        : 0U))),32);
        bufp->chgBit(oldp+2902,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U]
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U])))));
        bufp->chgBit(oldp+2903,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                           >> 1U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                           >> 1U))))));
        bufp->chgCData(oldp+2904,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                 << 0x1eU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                   >> 2U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                  << 0x1eU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                    >> 2U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2905,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD),7);
        bufp->chgBit(oldp+2906,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid));
        bufp->chgCData(oldp+2907,((0x7fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                 << 0x11U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                   >> 0xfU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                  << 0x11U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                    >> 0xfU))
                                                 : 0U)))),7);
        bufp->chgBit(oldp+2908,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                           >> 0x16U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                              >> 0x16U))))));
        bufp->chgCData(oldp+2909,((0x7fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                 << 9U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                   >> 0x17U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                  << 9U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                    >> 0x17U))
                                                 : 0U)))),7);
        bufp->chgBit(oldp+2910,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                           >> 0x1eU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                              >> 0x1eU))))));
        bufp->chgIData(oldp+2911,((0x1fffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                  << 1U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                    >> 0x1fU))
                                                 : 
                                                ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                  ? 
                                                 ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                   << 1U) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                     >> 0x1fU))
                                                  : 0U)))),21);
        bufp->chgCData(oldp+2912,((7U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                              << 0xcU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                >> 0x14U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                  << 0xcU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    >> 0x14U))
                                              : 0U)))),3);
        bufp->chgCData(oldp+2913,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                              << 9U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                >> 0x17U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                  << 9U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    >> 0x17U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2914,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                 << 7U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                   >> 0x19U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                  << 7U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                    >> 0x19U))
                                                 : 0U)))),6);
        bufp->chgCData(oldp+2915,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                << 1U) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][2U] 
                                                  >> 0x1fU))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    << 1U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U] 
                                                      >> 0x1fU))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2916,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                << 0x1dU) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                  >> 3U))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    << 0x1dU) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                      >> 3U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2917,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                 << 0x19U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                   >> 7U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                  << 0x19U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 7U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2918,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                              << 0x14U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                >> 0xcU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                  << 0x14U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 0xcU))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2919,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                              << 0x12U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                >> 0xeU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                  << 0x12U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 0xeU))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2920,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x10U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x10U))))));
        bufp->chgBit(oldp+2921,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x11U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x11U))))));
        bufp->chgBit(oldp+2922,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x12U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x12U))))));
        bufp->chgBit(oldp+2923,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x13U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x13U))))));
        bufp->chgBit(oldp+2924,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x14U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+2925,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x15U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x15U))))));
        bufp->chgCData(oldp+2926,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                              << 0xaU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                >> 0x16U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                  << 0xaU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 0x16U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2927,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                              << 8U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                >> 0x18U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                  << 8U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 0x18U))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2928,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x1aU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x1aU))))));
        bufp->chgBit(oldp+2929,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                           >> 0x1bU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                              >> 0x1bU))))));
        bufp->chgCData(oldp+2930,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                                 << 4U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][3U] 
                                                   >> 0x1cU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][4U] 
                                                  << 4U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U] 
                                                    >> 0x1cU))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2931,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD),7);
        bufp->chgBit(oldp+2932,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD_valid));
        bufp->chgCData(oldp+2933,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1),7);
        bufp->chgBit(oldp+2934,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1_valid));
        bufp->chgCData(oldp+2935,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2),7);
        bufp->chgBit(oldp+2936,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2_valid));
        bufp->chgIData(oldp+2937,((0x1fffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                  << 7U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][4U] 
                                                    >> 0x19U))
                                                 : 
                                                ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                  ? 
                                                 ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                   << 7U) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][4U] 
                                                     >> 0x19U))
                                                  : 0U)))),21);
        bufp->chgCData(oldp+2938,((7U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                              << 0x12U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                >> 0xeU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                  << 0x12U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                    >> 0xeU))
                                              : 0U)))),3);
        bufp->chgCData(oldp+2939,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                              << 0xfU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                >> 0x11U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                  << 0xfU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                    >> 0x11U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2940,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                 << 0xdU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                   >> 0x13U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                  << 0xdU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                    >> 0x13U))
                                                 : 0U)))),6);
        bufp->chgCData(oldp+2941,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                << 7U) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                  >> 0x19U))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                    << 7U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                      >> 0x19U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2942,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                << 3U) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][5U] 
                                                  >> 0x1dU))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    << 3U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U] 
                                                      >> 0x1dU))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2943,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                 << 0x1fU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                   >> 1U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0x1fU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 1U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2944,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                              << 0x1aU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                >> 6U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0x1aU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 6U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2945,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                              << 0x18U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                >> 8U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0x18U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 8U))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2946,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0xaU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0xaU))))));
        bufp->chgBit(oldp+2947,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0xbU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0xbU))))));
        bufp->chgBit(oldp+2948,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0xcU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0xcU))))));
        bufp->chgBit(oldp+2949,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0xdU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0xdU))))));
        bufp->chgBit(oldp+2950,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0xeU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0xeU))))));
        bufp->chgBit(oldp+2951,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0xfU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0xfU))))));
        bufp->chgCData(oldp+2952,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                              << 0x10U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                >> 0x10U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0x10U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 0x10U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2953,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                              << 0xeU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                >> 0x12U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0xeU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 0x12U))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2954,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0x14U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0x14U))))));
        bufp->chgBit(oldp+2955,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                           >> 0x15U)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                              >> 0x15U))))));
        bufp->chgCData(oldp+2956,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                 << 0xaU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][6U] 
                                                   >> 0x16U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                  << 0xaU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U] 
                                                    >> 0x16U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2957,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD),7);
        bufp->chgBit(oldp+2958,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD_valid));
        bufp->chgCData(oldp+2959,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1),7);
        bufp->chgBit(oldp+2960,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1_valid));
        bufp->chgCData(oldp+2961,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2),7);
        bufp->chgBit(oldp+2962,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2_valid));
        bufp->chgIData(oldp+2963,((0x1fffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                  << 0xdU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][7U] 
                                                    >> 0x13U))
                                                 : 
                                                ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                  ? 
                                                 ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                   << 0xdU) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][7U] 
                                                     >> 0x13U))
                                                  : 0U)))),21);
        bufp->chgCData(oldp+2964,((7U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                              << 0x18U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                >> 8U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                  << 0x18U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                    >> 8U))
                                              : 0U)))),3);
        bufp->chgCData(oldp+2965,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                              << 0x15U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                >> 0xbU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                  << 0x15U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                    >> 0xbU))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2966,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                 << 0x13U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                   >> 0xdU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                  << 0x13U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                    >> 0xdU))
                                                 : 0U)))),6);
        bufp->chgCData(oldp+2967,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                << 0xdU) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                  >> 0x13U))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                    << 0xdU) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                      >> 0x13U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2968,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                << 9U) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                  >> 0x17U))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                    << 9U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                      >> 0x17U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2969,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                 << 5U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][8U] 
                                                   >> 0x1bU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                  << 5U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U] 
                                                    >> 0x1bU))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2970,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U]
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U]
                                              : 0U)))),2);
        bufp->chgCData(oldp+2971,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                              << 0x1eU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                                >> 2U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                  << 0x1eU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                    >> 2U))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2972,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 4U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                           >> 4U))))));
        bufp->chgBit(oldp+2973,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 5U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                           >> 5U))))));
        bufp->chgBit(oldp+2974,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 6U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                           >> 6U))))));
        bufp->chgBit(oldp+2975,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 7U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                           >> 7U))))));
        bufp->chgBit(oldp+2976,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 8U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                           >> 8U))))));
        bufp->chgBit(oldp+2977,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 9U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                           >> 9U))))));
        bufp->chgCData(oldp+2978,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                              << 0x16U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                                >> 0xaU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                  << 0x16U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                    >> 0xaU))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2979,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                              << 0x14U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                                >> 0xcU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                  << 0x14U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                    >> 0xcU))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2980,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 0xeU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                              >> 0xeU))))));
        bufp->chgBit(oldp+2981,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                           >> 0xfU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                              >> 0xfU))))));
        bufp->chgCData(oldp+2982,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                                 << 0x10U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][9U] 
                                                   >> 0x10U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                  << 0x10U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                    >> 0x10U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2983,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RD),7);
        bufp->chgBit(oldp+2984,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RD_valid));
        bufp->chgCData(oldp+2985,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1),7);
        bufp->chgBit(oldp+2986,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1_valid));
        bufp->chgCData(oldp+2987,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2),7);
        bufp->chgBit(oldp+2988,(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2_valid));
        bufp->chgIData(oldp+2989,((0x1fffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                  << 0x13U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xaU] 
                                                    >> 0xdU))
                                                 : 
                                                ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                  ? 
                                                 ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                   << 0x13U) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                                     >> 0xdU))
                                                  : 0U)))),21);
        bufp->chgCData(oldp+2990,((7U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                              << 0x1eU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                >> 2U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                  << 0x1eU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    >> 2U))
                                              : 0U)))),3);
        bufp->chgCData(oldp+2991,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                              << 0x1bU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                >> 5U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                  << 0x1bU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    >> 5U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2992,((0x3fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                 << 0x19U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                   >> 7U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                  << 0x19U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    >> 7U))
                                                 : 0U)))),6);
        bufp->chgCData(oldp+2993,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                << 0x13U) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                  >> 0xdU))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    << 0x13U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                      >> 0xdU))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2994,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                << 0xfU) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                  >> 0x11U))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    << 0xfU) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                      >> 0x11U))
                                                : 0U)))),4);
        bufp->chgCData(oldp+2995,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                 << 0xbU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                   >> 0x15U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                  << 0xbU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    >> 0x15U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+2996,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                              << 6U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                >> 0x1aU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                  << 6U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    >> 0x1aU))
                                              : 0U)))),2);
        bufp->chgCData(oldp+2997,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                              << 4U) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                                >> 0x1cU))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                  << 4U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                                    >> 0x1cU))
                                              : 0U)))),2);
        bufp->chgBit(oldp+2998,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                           >> 0x1eU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                              >> 0x1eU))))));
        bufp->chgBit(oldp+2999,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xbU] 
                                           >> 0x1fU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU] 
                                              >> 0x1fU))))));
        bufp->chgBit(oldp+3000,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU]
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU])))));
        bufp->chgBit(oldp+3001,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 1U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                           >> 1U))))));
        bufp->chgBit(oldp+3002,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 2U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                           >> 2U))))));
        bufp->chgBit(oldp+3003,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 3U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                           >> 3U))))));
        bufp->chgCData(oldp+3004,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                              << 0x1cU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                                >> 4U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                  << 0x1cU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                    >> 4U))
                                              : 0U)))),2);
        bufp->chgCData(oldp+3005,((3U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                          ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                              << 0x1aU) 
                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                                >> 6U))
                                          : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                              ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                  << 0x1aU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                    >> 6U))
                                              : 0U)))),2);
        bufp->chgBit(oldp+3006,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 8U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                           >> 8U))))));
        bufp->chgBit(oldp+3007,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 9U) : 
                                       ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                        & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                           >> 9U))))));
        bufp->chgBit(oldp+3008,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 0xaU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                              >> 0xaU))))));
        bufp->chgBit(oldp+3009,((1U & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                        ? (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                           [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                           >> 0xbU)
                                        : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) 
                                           & (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                              >> 0xbU))))));
        bufp->chgSData(oldp+3010,((0xffffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                               ? ((
                                                   vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                                   << 0x14U) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                     [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                                     >> 0xcU))
                                               : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                   ? 
                                                  ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                    << 0x14U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                      >> 0xcU))
                                                   : 0U)))),16);
        bufp->chgCData(oldp+3011,((0x7fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                 << 4U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xcU] 
                                                   >> 0x1cU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                  << 4U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU] 
                                                    >> 0x1cU))
                                                 : 0U)))),7);
        bufp->chgCData(oldp+3012,((0x7fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                 << 0x1dU) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                   >> 3U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                  << 0x1dU) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                    >> 3U))
                                                 : 0U)))),7);
        bufp->chgCData(oldp+3013,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                            ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                << 0x16U) 
                                               | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                  >> 0xaU))
                                            : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                ? (
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                    << 0x16U) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                      >> 0xaU))
                                                : 0U)))),4);
        bufp->chgCData(oldp+3014,((0xffU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                 << 0x12U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][0xdU] 
                                                   >> 0xeU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                  << 0x12U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU] 
                                                    >> 0xeU))
                                                 : 0U)))),8);
        bufp->chgBit(oldp+3015,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__do_deq));
        bufp->chgCData(oldp+3016,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+3017,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+3018,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__maybe_full));
        bufp->chgBit(oldp+3019,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ptr_match));
        bufp->chgBit(oldp+3020,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty));
        bufp->chgBit(oldp+3021,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__full));
        bufp->chgBit(oldp+3022,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__do_enq));
        bufp->chgCData(oldp+3023,((0xfU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value)))),4);
        if (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_115[0U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_115[1U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_115[2U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_115[3U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_115[4U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_115[5U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_115[6U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_115[7U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][7U];
            __Vtemp_115[8U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U];
            __Vtemp_115[9U] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U];
            __Vtemp_115[0xaU] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xaU];
            __Vtemp_115[0xbU] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU];
            __Vtemp_115[0xcU] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU];
            __Vtemp_115[0xdU] = vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU];
        } else {
            __Vtemp_115[0U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[0U];
            __Vtemp_115[1U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[1U];
            __Vtemp_115[2U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[2U];
            __Vtemp_115[3U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[3U];
            __Vtemp_115[4U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[4U];
            __Vtemp_115[5U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[5U];
            __Vtemp_115[6U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[6U];
            __Vtemp_115[7U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[7U];
            __Vtemp_115[8U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[8U];
            __Vtemp_115[9U] = Vtop__ConstPool__CONST_hdcbf1b3c_0[9U];
            __Vtemp_115[0xaU] = Vtop__ConstPool__CONST_hdcbf1b3c_0[0xaU];
            __Vtemp_115[0xbU] = Vtop__ConstPool__CONST_hdcbf1b3c_0[0xbU];
            __Vtemp_115[0xcU] = Vtop__ConstPool__CONST_hdcbf1b3c_0[0xcU];
            __Vtemp_115[0xdU] = Vtop__ConstPool__CONST_hdcbf1b3c_0[0xdU];
        }
        bufp->chgWData(oldp+3024,(__Vtemp_115),438);
        bufp->chgWData(oldp+3038,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[0]),438);
        bufp->chgWData(oldp+3052,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[1]),438);
        bufp->chgWData(oldp+3066,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[2]),438);
        bufp->chgWData(oldp+3080,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[3]),438);
        bufp->chgWData(oldp+3094,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[4]),438);
        bufp->chgWData(oldp+3108,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[5]),438);
        bufp->chgWData(oldp+3122,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[6]),438);
        bufp->chgWData(oldp+3136,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[7]),438);
        bufp->chgWData(oldp+3150,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[8]),438);
        bufp->chgWData(oldp+3164,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[9]),438);
        bufp->chgWData(oldp+3178,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[10]),438);
        bufp->chgWData(oldp+3192,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[11]),438);
        bufp->chgWData(oldp+3206,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[12]),438);
        bufp->chgWData(oldp+3220,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[13]),438);
        bufp->chgWData(oldp+3234,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[14]),438);
        bufp->chgWData(oldp+3248,(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[15]),438);
        bufp->chgBit(oldp+3262,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__wrap_1][1U] 
                                       >> 1U))));
        bufp->chgBit(oldp+3263,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__fire));
        bufp->chgBit(oldp+3264,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_1));
        bufp->chgBit(oldp+3265,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_2));
        bufp->chgBit(oldp+3266,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_3));
        bufp->chgBit(oldp+3267,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_4));
        bufp->chgBit(oldp+3268,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_5));
        bufp->chgBit(oldp+3269,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_6));
        bufp->chgBit(oldp+3270,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_7));
        bufp->chgBit(oldp+3271,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_8));
        bufp->chgBit(oldp+3272,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_9));
        bufp->chgBit(oldp+3273,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_10));
        bufp->chgBit(oldp+3274,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_11));
        bufp->chgBit(oldp+3275,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_12));
        bufp->chgBit(oldp+3276,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_13));
        bufp->chgBit(oldp+3277,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_14));
        bufp->chgBit(oldp+3278,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_15));
        bufp->chgBit(oldp+3279,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_16));
        bufp->chgBit(oldp+3280,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_17));
        bufp->chgBit(oldp+3281,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_18));
        bufp->chgBit(oldp+3282,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_19));
        bufp->chgBit(oldp+3283,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_20));
        bufp->chgBit(oldp+3284,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_21));
        bufp->chgBit(oldp+3285,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_22));
        bufp->chgBit(oldp+3286,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_23));
        bufp->chgBit(oldp+3287,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_24));
        bufp->chgBit(oldp+3288,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_25));
        bufp->chgBit(oldp+3289,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_26));
        bufp->chgBit(oldp+3290,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_27));
        bufp->chgBit(oldp+3291,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_28));
        bufp->chgBit(oldp+3292,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_29));
        bufp->chgBit(oldp+3293,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_30));
        bufp->chgBit(oldp+3294,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_31));
        bufp->chgBit(oldp+3295,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_32));
        bufp->chgBit(oldp+3296,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_33));
        bufp->chgBit(oldp+3297,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_34));
        bufp->chgBit(oldp+3298,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_35));
        bufp->chgBit(oldp+3299,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_36));
        bufp->chgBit(oldp+3300,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_37));
        bufp->chgBit(oldp+3301,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_38));
        bufp->chgBit(oldp+3302,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_39));
        bufp->chgBit(oldp+3303,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_40));
        bufp->chgBit(oldp+3304,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_41));
        bufp->chgBit(oldp+3305,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_42));
        bufp->chgBit(oldp+3306,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_43));
        bufp->chgBit(oldp+3307,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_44));
        bufp->chgBit(oldp+3308,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_45));
        bufp->chgBit(oldp+3309,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_46));
        bufp->chgBit(oldp+3310,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_47));
        bufp->chgBit(oldp+3311,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_48));
        bufp->chgBit(oldp+3312,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_49));
        bufp->chgBit(oldp+3313,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_50));
        bufp->chgBit(oldp+3314,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_51));
        bufp->chgBit(oldp+3315,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_52));
        bufp->chgBit(oldp+3316,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_53));
        bufp->chgBit(oldp+3317,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_54));
        bufp->chgBit(oldp+3318,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_55));
        bufp->chgBit(oldp+3319,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_56));
        bufp->chgBit(oldp+3320,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_57));
        bufp->chgBit(oldp+3321,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_58));
        bufp->chgBit(oldp+3322,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_59));
        bufp->chgBit(oldp+3323,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_60));
        bufp->chgBit(oldp+3324,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_61));
        bufp->chgBit(oldp+3325,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_62));
        bufp->chgBit(oldp+3326,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_63));
        bufp->chgBit(oldp+3327,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__ready_memory_64));
        bufp->chgBit(oldp+3328,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_1));
        bufp->chgBit(oldp+3329,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_2));
        bufp->chgBit(oldp+3330,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_3));
        bufp->chgBit(oldp+3331,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_4));
        bufp->chgBit(oldp+3332,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_5));
        bufp->chgBit(oldp+3333,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_6));
        bufp->chgBit(oldp+3334,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_7));
        bufp->chgBit(oldp+3335,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_8));
        bufp->chgBit(oldp+3336,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_9));
        bufp->chgBit(oldp+3337,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_10));
        bufp->chgBit(oldp+3338,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_11));
        bufp->chgBit(oldp+3339,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_12));
        bufp->chgBit(oldp+3340,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_13));
        bufp->chgBit(oldp+3341,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_14));
        bufp->chgBit(oldp+3342,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_15));
        bufp->chgBit(oldp+3343,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_16));
        bufp->chgBit(oldp+3344,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_17));
        bufp->chgBit(oldp+3345,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_18));
        bufp->chgBit(oldp+3346,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_19));
        bufp->chgBit(oldp+3347,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_20));
        bufp->chgBit(oldp+3348,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_21));
        bufp->chgBit(oldp+3349,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_22));
        bufp->chgBit(oldp+3350,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_23));
        bufp->chgBit(oldp+3351,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_24));
        bufp->chgBit(oldp+3352,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_25));
        bufp->chgBit(oldp+3353,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_26));
        bufp->chgBit(oldp+3354,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_27));
        bufp->chgBit(oldp+3355,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_28));
        bufp->chgBit(oldp+3356,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_29));
        bufp->chgBit(oldp+3357,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_30));
        bufp->chgBit(oldp+3358,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_31));
        bufp->chgBit(oldp+3359,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_32));
        bufp->chgBit(oldp+3360,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_33));
        bufp->chgBit(oldp+3361,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_34));
        bufp->chgBit(oldp+3362,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_35));
        bufp->chgBit(oldp+3363,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_36));
        bufp->chgBit(oldp+3364,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_37));
        bufp->chgBit(oldp+3365,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_38));
        bufp->chgBit(oldp+3366,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_39));
        bufp->chgBit(oldp+3367,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_40));
        bufp->chgBit(oldp+3368,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_41));
        bufp->chgBit(oldp+3369,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_42));
        bufp->chgBit(oldp+3370,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_43));
        bufp->chgBit(oldp+3371,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_44));
        bufp->chgBit(oldp+3372,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_45));
        bufp->chgBit(oldp+3373,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_46));
        bufp->chgBit(oldp+3374,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_47));
        bufp->chgBit(oldp+3375,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_48));
        bufp->chgBit(oldp+3376,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_49));
        bufp->chgBit(oldp+3377,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_50));
        bufp->chgBit(oldp+3378,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_51));
        bufp->chgBit(oldp+3379,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_52));
        bufp->chgBit(oldp+3380,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_53));
        bufp->chgBit(oldp+3381,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_54));
        bufp->chgBit(oldp+3382,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_55));
        bufp->chgBit(oldp+3383,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_56));
        bufp->chgBit(oldp+3384,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_57));
        bufp->chgBit(oldp+3385,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_58));
        bufp->chgBit(oldp+3386,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_59));
        bufp->chgBit(oldp+3387,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_60));
        bufp->chgBit(oldp+3388,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_61));
        bufp->chgBit(oldp+3389,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_62));
        bufp->chgBit(oldp+3390,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_63));
        bufp->chgBit(oldp+3391,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_64));
        bufp->chgCData(oldp+3392,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                 << 0x11U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                   >> 0xfU))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                  << 0x11U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                    >> 0xfU))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+3393,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))),5);
        bufp->chgCData(oldp+3394,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))),5);
        bufp->chgCData(oldp+3395,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))),5);
        bufp->chgCData(oldp+3396,((0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                             ? ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                 << 9U) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                   >> 0x17U))
                                             : ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                 ? 
                                                ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                  << 9U) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                    >> 0x17U))
                                                 : 0U)))),5);
        bufp->chgCData(oldp+3397,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))),5);
        bufp->chgCData(oldp+3398,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))),5);
        bufp->chgCData(oldp+3399,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))),5);
        bufp->chgCData(oldp+3400,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD))),5);
        bufp->chgCData(oldp+3401,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD))),5);
        bufp->chgCData(oldp+3402,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD))),5);
        bufp->chgCData(oldp+3403,((0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RD))),5);
        bufp->chgBit(oldp+3404,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_wr_en_0));
        bufp->chgBit(oldp+3405,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_wr_en_1));
        bufp->chgBit(oldp+3406,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_wr_en_2));
        bufp->chgBit(oldp+3407,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_wr_en_3));
        bufp->chgCData(oldp+3408,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0),7);
        bufp->chgCData(oldp+3409,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_1),7);
        bufp->chgCData(oldp+3410,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_2),7);
        bufp->chgCData(oldp+3411,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_3),7);
        bufp->chgCData(oldp+3412,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                      ? 
                                                     ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                       << 0x11U) 
                                                      | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                         >> 0xfU))
                                                      : 
                                                     ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                       ? 
                                                      ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                        << 0x11U) 
                                                       | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                          >> 0xfU))
                                                       : 0U))))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                           ? 
                                                          ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                            << 0x11U) 
                                                           | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                              >> 0xfU))
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                            ? 
                                                           ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                             << 0x11U) 
                                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                               >> 0xfU))
                                                            : 0U))))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                              << 0x11U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                                >> 0xfU))
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                              ? 
                                                             ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                               << 0x11U) 
                                                              | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                 >> 0xfU))
                                                              : 0U)))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                            ? 
                                                           ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                             << 0x11U) 
                                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                               >> 0xfU))
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                              << 0x11U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                >> 0xfU))
                                                             : 0U)))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                              << 0x11U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                                >> 0xfU))
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                              ? 
                                                             ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                               << 0x11U) 
                                                              | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                 >> 0xfU))
                                                              : 0U)))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                            ? 
                                                           ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                             << 0x11U) 
                                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                               >> 0xfU))
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                              << 0x11U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                >> 0xfU))
                                                             : 0U))))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3413,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1)))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3414,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3415,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3416,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                      ? 
                                                     ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                       << 9U) 
                                                      | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                         >> 0x17U))
                                                      : 
                                                     ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                       ? 
                                                      ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                        [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                        << 9U) 
                                                       | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                          [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                          >> 0x17U))
                                                       : 0U))))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                           ? 
                                                          ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                            [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                            << 9U) 
                                                           | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                              >> 0x17U))
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                            ? 
                                                           ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                             << 9U) 
                                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                               >> 0x17U))
                                                            : 0U))))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                              << 9U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                                >> 0x17U))
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                              ? 
                                                             ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                               << 9U) 
                                                              | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                 >> 0x17U))
                                                              : 0U)))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                            ? 
                                                           ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                             << 9U) 
                                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                               >> 0x17U))
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                              << 9U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                >> 0x17U))
                                                             : 0U)))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                              << 9U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                                >> 0x17U))
                                                             : 
                                                            ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                              ? 
                                                             ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                               << 9U) 
                                                              | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                 >> 0x17U))
                                                              : 0U)))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__empty)
                                                            ? 
                                                           ((vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                             [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                             << 9U) 
                                                            | (vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                               [vlSelf->top__DOT__dut__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q__DOT__wrap_1][1U] 
                                                               >> 0x17U))
                                                            : 
                                                           ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0)
                                                             ? 
                                                            ((vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                              [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                              << 9U) 
                                                             | (vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                >> 0x17U))
                                                             : 0U))))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3417,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2)))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3418,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3419,(((0xdfU >= (0xffU 
                                              & ((IData)(7U) 
                                                 * 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)))))
                                    ? (0x7fU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))))))) 
                                                | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (7U 
                                                    & (((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)))))))
                                    : 0U)),7);
        bufp->chgCData(oldp+3420,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_0),7);
        bufp->chgCData(oldp+3421,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_1),7);
        bufp->chgCData(oldp+3422,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_2),7);
        bufp->chgCData(oldp+3423,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_3),7);
        bufp->chgCData(oldp+3424,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_4),7);
        bufp->chgCData(oldp+3425,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_5),7);
        bufp->chgCData(oldp+3426,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_6),7);
        bufp->chgCData(oldp+3427,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_7),7);
        bufp->chgCData(oldp+3428,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_8),7);
        bufp->chgCData(oldp+3429,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_9),7);
        bufp->chgCData(oldp+3430,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_10),7);
        bufp->chgCData(oldp+3431,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_11),7);
        bufp->chgCData(oldp+3432,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_12),7);
        bufp->chgCData(oldp+3433,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_13),7);
        bufp->chgCData(oldp+3434,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_14),7);
        bufp->chgCData(oldp+3435,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_15),7);
        bufp->chgCData(oldp+3436,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_16),7);
        bufp->chgCData(oldp+3437,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_17),7);
        bufp->chgCData(oldp+3438,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_18),7);
        bufp->chgCData(oldp+3439,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_19),7);
        bufp->chgCData(oldp+3440,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_20),7);
        bufp->chgCData(oldp+3441,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_21),7);
        bufp->chgCData(oldp+3442,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_22),7);
        bufp->chgCData(oldp+3443,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_23),7);
        bufp->chgCData(oldp+3444,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_24),7);
        bufp->chgCData(oldp+3445,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_25),7);
        bufp->chgCData(oldp+3446,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_26),7);
        bufp->chgCData(oldp+3447,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_27),7);
        bufp->chgCData(oldp+3448,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_28),7);
        bufp->chgCData(oldp+3449,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_29),7);
        bufp->chgCData(oldp+3450,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_30),7);
        bufp->chgCData(oldp+3451,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT_31),7);
        bufp->chgBit(oldp+3452,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__fire))));
        bufp->chgBit(oldp+3453,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__WAW_handler__io_decoder_RD_valid_bits_1));
        bufp->chgBit(oldp+3454,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__WAW_handler__io_decoder_RD_valid_bits_2));
        bufp->chgBit(oldp+3455,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_0));
        bufp->chgBit(oldp+3456,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_1));
        bufp->chgBit(oldp+3457,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_2));
        bufp->chgBit(oldp+3458,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_3));
        bufp->chgBit(oldp+3459,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_0) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT____VdfgRegularize_h9fa3630a_1_5))));
        bufp->chgBit(oldp+3460,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_1) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT____VdfgRegularize_h9fa3630a_1_5))));
        bufp->chgBit(oldp+3461,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_2) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT____VdfgRegularize_h9fa3630a_1_5))));
        bufp->chgBit(oldp+3462,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid_3) 
                                 & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT____VdfgRegularize_h9fa3630a_1_5))));
        bufp->chgCData(oldp+3463,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer),7);
        bufp->chgBit(oldp+3464,((0x41U > (0x7fU & ((IData)(4U) 
                                                   + (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets))))));
        bufp->chgBit(oldp+3465,((0U != (0x1fU & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets) 
                                                 >> 2U)))));
        bufp->chgCData(oldp+3466,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__back_pointer),7);
        bufp->chgCData(oldp+3467,((0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer))),6);
        bufp->chgCData(oldp+3468,((0x3fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__back_pointer))),6);
        bufp->chgBit(oldp+3469,(((IData)(vlSelf->top__DOT__io_commit_bits_RD_valid_0) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                                    & ((0U != (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_21)) 
                                       & (IData)(vlSelf->top__DOT__io_commit_valid))))));
        bufp->chgBit(oldp+3470,(((IData)(vlSelf->top__DOT__io_commit_bits_RD_valid_1) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                                    & ((0U != (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_20)) 
                                       & (IData)(vlSelf->top__DOT__io_commit_valid))))));
        bufp->chgBit(oldp+3471,(((IData)(vlSelf->top__DOT__io_commit_bits_RD_valid_2) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                                    & ((0U != (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_19)) 
                                       & (IData)(vlSelf->top__DOT__io_commit_valid))))));
        bufp->chgBit(oldp+3472,(((IData)(vlSelf->top__DOT__io_commit_bits_RD_valid_3) 
                                 & ((IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                                    & ((0U != (IData)(vlSelf->__VdfgRegularize_hd87f99a1_1_18)) 
                                       & (IData)(vlSelf->top__DOT__io_commit_valid))))));
        bufp->chgCData(oldp+3473,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets),7);
        bufp->chgBit(oldp+3474,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+3475,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__wrap));
        bufp->chgBit(oldp+3476,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+3477,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+3478,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+3479,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__empty));
        bufp->chgBit(oldp+3480,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__do_enq));
        bufp->chgWData(oldp+3481,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__wrap_1]),104);
        bufp->chgWData(oldp+3485,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT____Vcellinp__ram_ext__W0_data),104);
        bufp->chgWData(oldp+3489,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory[0]),104);
        bufp->chgWData(oldp+3493,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__ram_ext__DOT__Memory[1]),104);
        bufp->chgBit(oldp+3497,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__predictions_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgCData(oldp+3498,((0x7fU & ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD) 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1)) 
                                             & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1_valid)))
                                             ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0)
                                             : ((0xdfU 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(7U) 
                                                     * 
                                                     (0x1fU 
                                                      & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1)))))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1)))))
                                                   ? 0U
                                                   : 
                                                  (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (((IData)(6U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))))))) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                    (7U 
                                                     & (((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS1))))))
                                                 : 0U)))),7);
        bufp->chgCData(oldp+3499,((0x7fU & ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD) 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2)) 
                                             & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2_valid)))
                                             ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0)
                                             : ((0xdfU 
                                                 >= 
                                                 (0xffU 
                                                  & ((IData)(7U) 
                                                     * 
                                                     (0x1fU 
                                                      & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2)))))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2)))))
                                                   ? 0U
                                                   : 
                                                  (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                   (((IData)(6U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))))))) 
                                                 | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                    (7U 
                                                     & (((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RS2))))))
                                                 : 0U)))),7);
        bufp->chgCData(oldp+3500,((0x7fU & ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD) 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)) 
                                             & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD_valid) 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1_valid)))
                                             ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_1)
                                             : ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD) 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)) 
                                                 & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                                    & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1_valid)))
                                                 ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0)
                                                 : 
                                                ((0xdfU 
                                                  >= 
                                                  (0xffU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)))))
                                                  ? 
                                                 (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1)))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))))))) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS1))))))
                                                  : 0U))))),7);
        bufp->chgCData(oldp+3501,((0x7fU & ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD) 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)) 
                                             & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD_valid) 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2_valid)))
                                             ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_1)
                                             : ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD) 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)) 
                                                 & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                                    & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2_valid)))
                                                 ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0)
                                                 : 
                                                ((0xdfU 
                                                  >= 
                                                  (0xffU 
                                                   & ((IData)(7U) 
                                                      * 
                                                      (0x1fU 
                                                       & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)))))
                                                  ? 
                                                 (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * 
                                                        (0x1fU 
                                                         & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2)))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))))))) 
                                                  | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RS2))))))
                                                  : 0U))))),7);
        bufp->chgCData(oldp+3502,((0x7fU & ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD) 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)) 
                                             & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD_valid) 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1_valid)))
                                             ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_2)
                                             : ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD) 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)) 
                                                 & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD_valid) 
                                                    & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1_valid)))
                                                 ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_1)
                                                 : 
                                                ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD) 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)) 
                                                  & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1_valid)))
                                                  ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0)
                                                  : 
                                                 ((0xdfU 
                                                   >= 
                                                   (0xffU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1)))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * 
                                                           (0x1fU 
                                                            & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * 
                                                           (0x1fU 
                                                            & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS1))))))
                                                   : 0U)))))),7);
        bufp->chgCData(oldp+3503,((0x7fU & ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD) 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)) 
                                             & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_2_RD_valid) 
                                                & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2_valid)))
                                             ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_2)
                                             : ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD) 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)) 
                                                 & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_1_RD_valid) 
                                                    & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2_valid)))
                                                 ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_1)
                                                 : 
                                                ((((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD) 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)) 
                                                  & ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_0_RD_valid) 
                                                     & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2_valid)))
                                                  ? (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values_0)
                                                  : 
                                                 ((0xdfU 
                                                   >= 
                                                   (0xffU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0x1fU 
                                                        & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0x1fU 
                                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2)))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * 
                                                           (0x1fU 
                                                            & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))))))) 
                                                   | (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__RAT__DOT___GEN[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * 
                                                           (0x1fU 
                                                            & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0x1fU 
                                                           & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT___instruction_queue_io_deq_bits_decoded_instruction_3_RS2))))))
                                                   : 0U)))))),7);
        bufp->chgCData(oldp+3504,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer),8);
        bufp->chgBit(oldp+3505,((1U & vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][1U])));
        bufp->chgBit(oldp+3506,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][1U] 
                                       >> 1U))));
        bufp->chgBit(oldp+3507,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][3U] 
                                       >> 0x1aU))));
        bufp->chgBit(oldp+3508,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][3U] 
                                       >> 0x1bU))));
        bufp->chgBit(oldp+3509,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][6U] 
                                       >> 0x14U))));
        bufp->chgBit(oldp+3510,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][6U] 
                                       >> 0x15U))));
        bufp->chgBit(oldp+3511,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][9U] 
                                       >> 0xeU))));
        bufp->chgBit(oldp+3512,((1U & (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1][9U] 
                                       >> 0xfU))));
        bufp->chgBit(oldp+3513,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+3514,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap));
        bufp->chgBit(oldp+3515,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1));
        bufp->chgBit(oldp+3516,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__maybe_full));
        bufp->chgBit(oldp+3517,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ptr_match));
        bufp->chgBit(oldp+3518,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__empty));
        bufp->chgBit(oldp+3519,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__do_enq));
        bufp->chgWData(oldp+3520,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__wrap_1]),438);
        bufp->chgWData(oldp+3534,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT____Vcellinp__ram_ext__W0_data),438);
        bufp->chgWData(oldp+3548,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory[0]),438);
        bufp->chgWData(oldp+3562,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__ram_ext__DOT__Memory[1]),438);
        bufp->chgBit(oldp+3576,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+3577,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__unnamedblk1__DOT__outputs_ready));
    }
    bufp->chgBit(oldp+3578,(vlSelf->top__DOT__clock));
    bufp->chgBit(oldp+3579,(vlSelf->top__DOT__reset));
    bufp->chgBit(oldp+3580,(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__hasBeenResetReg));
    bufp->chgBit(oldp+3581,(((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__hasBeenResetReg) 
                             & (~ (IData)(vlSelf->top__DOT__reset)))));
    bufp->chgBit(oldp+3582,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__backend__DOT__FU3__DOT__hasBeenResetReg) 
                                      & (~ (IData)(vlSelf->top__DOT__reset)))))));
    bufp->chgBit(oldp+3583,(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg));
    bufp->chgBit(oldp+3584,(((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg) 
                             & (~ (IData)(vlSelf->top__DOT__reset)))));
    bufp->chgBit(oldp+3585,((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg) 
                                      & (~ (IData)(vlSelf->top__DOT__reset)))))));
}

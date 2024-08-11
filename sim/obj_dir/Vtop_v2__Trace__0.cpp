// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_v2__Syms.h"


void Vtop_v2___024root__trace_chg_0_sub_0(Vtop_v2___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_v2___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root__trace_chg_0\n"); );
    // Init
    Vtop_v2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_v2___024root*>(voidSelf);
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop_v2___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<8>/*255:0*/ Vtop_v2__ConstPool__CONST_h9513bbd8_0;
extern const VlWide<8>/*255:0*/ Vtop_v2__ConstPool__CONST_h5b979c07_0;
extern const VlWide<14>/*447:0*/ Vtop_v2__ConstPool__CONST_h9fd76c70_0;
extern const VlWide<14>/*447:0*/ Vtop_v2__ConstPool__CONST_h862b0a92_0;
extern const VlWide<11>/*351:0*/ Vtop_v2__ConstPool__CONST_hf2cc239e_0;
extern const VlWide<9>/*287:0*/ Vtop_v2__ConstPool__CONST_h4d451b67_0;

void Vtop_v2___024root__trace_chg_0_sub_0(Vtop_v2___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<8>/*255:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<8>/*255:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<5>/*159:0*/ __Vtemp_26;
    VlWide<10>/*319:0*/ __Vtemp_47;
    VlWide<14>/*447:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<14>/*447:0*/ __Vtemp_62;
    VlWide<7>/*223:0*/ __Vtemp_71;
    VlWide<7>/*223:0*/ __Vtemp_77;
    VlWide<7>/*223:0*/ __Vtemp_86;
    VlWide<7>/*223:0*/ __Vtemp_92;
    VlWide<7>/*223:0*/ __Vtemp_98;
    VlWide<7>/*223:0*/ __Vtemp_99;
    VlWide<4>/*127:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<6>/*191:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_109;
    VlWide<8>/*255:0*/ __Vtemp_114;
    VlWide<8>/*255:0*/ __Vtemp_115;
    VlWide<8>/*255:0*/ __Vtemp_117;
    VlWide<8>/*255:0*/ __Vtemp_119;
    VlWide<14>/*447:0*/ __Vtemp_120;
    VlWide<14>/*447:0*/ __Vtemp_122;
    VlWide<8>/*255:0*/ __Vtemp_146;
    VlWide<3>/*95:0*/ __Vtemp_147;
    VlWide<10>/*319:0*/ __Vtemp_172;
    VlWide<11>/*351:0*/ __Vtemp_174;
    VlWide<11>/*351:0*/ __Vtemp_175;
    VlWide<11>/*351:0*/ __Vtemp_176;
    VlWide<8>/*255:0*/ __Vtemp_177;
    VlWide<3>/*95:0*/ __Vtemp_180;
    VlWide<8>/*255:0*/ __Vtemp_181;
    VlWide<9>/*287:0*/ __Vtemp_183;
    VlWide<9>/*287:0*/ __Vtemp_185;
    VlWide<14>/*447:0*/ __Vtemp_187;
    VlWide<14>/*447:0*/ __Vtemp_189;
    VlWide<6>/*191:0*/ __Vtemp_190;
    VlWide<6>/*191:0*/ __Vtemp_191;
    VlWide<4>/*127:0*/ __Vtemp_194;
    VlWide<4>/*127:0*/ __Vtemp_197;
    VlWide<4>/*127:0*/ __Vtemp_200;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__j),32);
    }
    if (VL_UNLIKELY(((vlSelf->__Vm_traceActivity[1U] 
                      | vlSelf->__Vm_traceActivity[2U]) 
                     | vlSelf->__Vm_traceActivity[3U]))) {
        __Vtemp_1[0U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC)) 
                                    << 0x20U) | (QData)((IData)(
                                                                (((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))
                                                                  ? 0U
                                                                  : 
                                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                                   ? 
                                                                  ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                    << 0x1fU) 
                                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                      [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                                      >> 1U))
                                                                   : 0U)))))) 
                          << 1U) | ((~ ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))) 
                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0) 
                                       & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U])));
        __Vtemp_1[1U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC)) 
                                    << 0x20U) | (QData)((IData)(
                                                                (((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))
                                                                  ? 0U
                                                                  : 
                                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                                   ? 
                                                                  ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                    << 0x1fU) 
                                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                      [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                                      >> 1U))
                                                                   : 0U)))))) 
                          >> 0x1fU) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC)) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))
                                                                     ? 0U
                                                                     : 
                                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                                      ? 
                                                                     ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                       << 0x1fU) 
                                                                      | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                         [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                                         >> 1U))
                                                                      : 0U))))) 
                                                >> 0x20U)) 
                                       << 1U));
        __Vtemp_1[2U] = ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC)) 
                                    << 0x20U) | (QData)((IData)(
                                                                (((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))
                                                                  ? 0U
                                                                  : 
                                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                                   ? 
                                                                  ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                    << 0x1fU) 
                                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                                                                      [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                                      >> 1U))
                                                                   : 0U))))) 
                                  >> 0x20U)) >> 0x1fU);
        bufp->chgWData(oldp+1,(__Vtemp_1),65);
        __Vtemp_2[0U] = ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq)
                          ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux
                          : 0U);
        __Vtemp_2[1U] = 0U;
        __Vtemp_2[2U] = 0U;
        bufp->chgWData(oldp+4,(__Vtemp_2),65);
        bufp->chgQData(oldp+7,((((QData)((IData)(((IData)(4U) 
                                                  + vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_22))) 
                                 << 2U) | (QData)((IData)(
                                                          ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL) 
                                                             & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid)) 
                                                            << 1U) 
                                                           | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET) 
                                                              & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))))))),34);
        __Vtemp_8[0U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11)))))) 
                          << 0x1eU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__GHR) 
                                        << 0xeU) | 
                                       (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT) 
                                         << 7U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS))));
        __Vtemp_8[1U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11)))))) 
                          >> 2U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                               << 0xaU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11))))) 
                                             >> 0x20U)) 
                                    << 0x1eU));
        __Vtemp_8[2U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_12)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_13) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_14)))))) 
                          << 8U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                               << 0xaU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11))))) 
                                             >> 0x20U)) 
                                    >> 2U));
        __Vtemp_8[3U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_15)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_16) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_17)))))) 
                          << 0x12U) | (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_12)) 
                                                  << 0xaU) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_13) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_14)))))) 
                                        >> 0x18U) | 
                                       ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_12)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_13) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_14))))) 
                                                 >> 0x20U)) 
                                        << 8U)));
        __Vtemp_8[4U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20)))))) 
                          << 0x1cU) | (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_15)) 
                                                  << 0xaU) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_16) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_17)))))) 
                                        >> 0xeU) | 
                                       ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_15)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_16) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_17))))) 
                                                 >> 0x20U)) 
                                        << 0x12U)));
        __Vtemp_8[5U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20)))))) 
                          >> 4U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                               << 0xaU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20))))) 
                                             >> 0x20U)) 
                                    << 0x1cU));
        __Vtemp_8[6U] = ((0xffffc000U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_0 
                                         << 0xaU)) 
                         | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_8) 
                             << 6U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                                  << 0xaU) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20))))) 
                                                >> 0x20U)) 
                                       >> 4U)));
        __Vtemp_8[7U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_0 
                         >> 0x16U);
        bufp->chgWData(oldp+9,(__Vtemp_8),234);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[3U]))) {
        bufp->chgQData(oldp+17,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellout__prediction_skid_buffer__io_deq_bits),53);
        bufp->chgQData(oldp+19,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT____Vcellout__BTB_Q__io_deq_bits),53);
        bufp->chgQData(oldp+21,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT____Vcellinp__ram_ext__W0_data),53);
        __Vtemp_9[0U] = 0U;
        __Vtemp_9[1U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux 
                         << 1U);
        __Vtemp_9[2U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux 
                         >> 0x1fU);
        bufp->chgWData(oldp+23,(__Vtemp_9),65);
        bufp->chgBit(oldp+26,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__is_ret));
        bufp->chgIData(oldp+27,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux),32);
        bufp->chgSData(oldp+28,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___predecoder_io_GHR),16);
        bufp->chgIData(oldp+29,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC),32);
        bufp->chgSData(oldp+30,((0xfffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC 
                                           >> 4U))),12);
        bufp->chgIData(oldp+31,(((IData)(4U) + vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_22)),32);
        bufp->chgBit(oldp+32,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_wr_valid));
        bufp->chgBit(oldp+33,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_rd_valid));
        bufp->chgCData(oldp+34,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT____Vcellinp__RAS_memory__io_rd_addr),7);
        bufp->chgQData(oldp+35,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT____Vcellinp__RAS_memory__io_data_in),39);
        bufp->chgSData(oldp+37,((0xffffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC 
                                            ^ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___predecoder_io_GHR)))),16);
        bufp->chgQData(oldp+38,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___GEN),53);
        bufp->chgCData(oldp+40,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH)
                                  ? 1U : ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET)
                                           ? 4U : ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL)
                                                    ? 5U
                                                    : 
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR)
                                                     ? 3U
                                                     : 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL) 
                                                     << 1U)))))),3);
        bufp->chgBit(oldp+41,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR));
        bufp->chgBit(oldp+42,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL));
        bufp->chgCData(oldp+43,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT),4);
        bufp->chgBit(oldp+44,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken));
        bufp->chgBit(oldp+45,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken_1));
        bufp->chgBit(oldp+46,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken_2));
        bufp->chgBit(oldp+47,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken_3));
        bufp->chgBit(oldp+48,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH));
        bufp->chgBit(oldp+49,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET));
        bufp->chgBit(oldp+50,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL));
        bufp->chgCData(oldp+51,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__dominant_branch_index),2);
        bufp->chgIData(oldp+52,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__dominant_instruction),32);
        bufp->chgIData(oldp+53,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__imm_imm),21);
        bufp->chgIData(oldp+54,(((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL)) 
                                        | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET)))
                                  ? 0U : (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__imm_imm 
                                                          >> 0x14U)))) 
                                           << 0x15U) 
                                          | vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__imm_imm))),32);
        bufp->chgIData(oldp+55,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__target_address),32);
        bufp->chgWData(oldp+56,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT____Vcellinp__ram_ext__W0_data),234);
        bufp->chgWData(oldp+64,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_0),110);
        bufp->chgWData(oldp+68,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__Vcellinp__ram_ext__W0_data),110);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+72,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_awready_reg));
        bufp->chgBit(oldp+73,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg))));
        __Vtemp_10[0U] = (IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                   << 0x1eU) | (QData)((IData)(
                                                               (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                                                 << 0x16U) 
                                                                | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                                                    << 0x13U) 
                                                                   | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                                                       << 0x11U) 
                                                                      | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                                                             << 0xcU) 
                                                                            | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                                                                << 9U) 
                                                                               | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                                                                << 5U) 
                                                                                | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg) 
                                                                                << 1U))))))))))));
        __Vtemp_10[1U] = (IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                    << 0x1eU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                                                  << 0x16U) 
                                                                 | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                                                     << 0x13U) 
                                                                    | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                                                        << 0x11U) 
                                                                       | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg) 
                                                                           << 0x10U) 
                                                                          | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                                                              << 0xcU) 
                                                                             | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                                                                << 5U) 
                                                                                | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg) 
                                                                                << 1U))))))))))) 
                                  >> 0x20U));
        __Vtemp_10[2U] = 0U;
        bufp->chgWData(oldp+74,(__Vtemp_10),70);
        bufp->chgBit(oldp+77,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_wready_reg));
        bufp->chgBit(oldp+78,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_reg))));
        bufp->chgQData(oldp+79,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)) 
                                  << 6U) | (QData)((IData)(
                                                           (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg) 
                                                             << 2U) 
                                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg) 
                                                               << 1U)))))),38);
        bufp->chgBit(oldp+81,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg))));
        bufp->chgBit(oldp+82,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_reg));
        bufp->chgSData(oldp+83,(((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg) 
                                 << 3U)),11);
        bufp->chgBit(oldp+84,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_reg));
        bufp->chgBit(oldp+85,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg))));
        bufp->chgBit(oldp+86,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg))));
        bufp->chgBit(oldp+87,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_reg));
        bufp->chgQData(oldp+88,((((QData)((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg)) 
                                  << 0x24U) | (((QData)((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_reg)) 
                                                << 4U) 
                                               | (QData)((IData)(
                                                                 ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_reg) 
                                                                  << 1U)))))),44);
        bufp->chgBit(oldp+90,((1U & (~ (IData)((0U 
                                                != (IData)(vlSelf->top_v2__DOT__SOC__DOT__AXI_debug_printer__DOT__AXI_debug_printer_STATE)))))));
        bufp->chgBit(oldp+91,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg) 
                                     >> 1U))));
        bufp->chgBit(oldp+92,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_reg) 
                                     >> 1U))));
        bufp->chgQData(oldp+93,(vlSelf->top_v2__DOT__SOC__DOT___axi_interconnect_io_s_AXI_port_1_AXI_W_bits),38);
        bufp->chgBit(oldp+95,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg) 
                                     >> 1U))));
        bufp->chgBit(oldp+96,(vlSelf->top_v2__DOT__SOC__DOT___AXI_debug_printer_io_s_AXI_AXI_B_valid));
        bufp->chgBit(oldp+97,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg) 
                                     >> 1U))));
        __Vtemp_11[0U] = (IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                   << 0x1eU) | (QData)((IData)(
                                                               (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                                                 << 0x16U) 
                                                                | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                                                    << 0x13U) 
                                                                   | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                                                       << 0x11U) 
                                                                      | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                                                             << 0xcU) 
                                                                            | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                                                                << 9U) 
                                                                               | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                                                                << 5U)))))))))));
        __Vtemp_11[1U] = (IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                    << 0x1eU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                                                  << 0x16U) 
                                                                 | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                                                     << 0x13U) 
                                                                    | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                                                        << 0x11U) 
                                                                       | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg) 
                                                                           << 0x10U) 
                                                                          | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                                                              << 0xcU) 
                                                                             | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                                                                << 9U) 
                                                                                | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                                                                << 5U)))))))))) 
                                  >> 0x20U));
        __Vtemp_11[2U] = 0U;
        bufp->chgWData(oldp+98,(__Vtemp_11),70);
        bufp->chgBit(oldp+101,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg) 
                                      >> 1U))));
        bufp->chgIData(oldp+102,(vlSelf->top_v2__DOT__SOC__DOT__AXI_debug_printer__DOT__print_data),32);
        bufp->chgCData(oldp+103,(vlSelf->top_v2__DOT__SOC__DOT__AXI_debug_printer__DOT__AXI_debug_printer_STATE),2);
        bufp->chgBit(oldp+104,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg))));
        bufp->chgBit(oldp+105,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg))));
        bufp->chgBit(oldp+106,((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgQData(oldp+107,((((QData)((IData)(
                                                   ((1U 
                                                     == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))
                                                     ? 
                                                    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                                     : 0U))) 
                                   << 6U) | (QData)((IData)(
                                                            ((0x3cU 
                                                              & ((- (IData)(
                                                                            (1U 
                                                                             == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))) 
                                                                 << 2U)) 
                                                             | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_3) 
                                                                << 1U)))))),38);
        bufp->chgBit(oldp+109,((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+110,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg))));
        bufp->chgSData(oldp+111,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg) 
                                   << 3U) | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg) 
                                             << 1U))),11);
        bufp->chgBit(oldp+112,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg))));
        bufp->chgBit(oldp+113,(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_instruction_cache_AXI_port_AXI_AR_valid));
        __Vtemp_12[0U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                             ? 7U : 0U) << 0x16U) | 
                          ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                              ? 5U : 0U) << 0x13U) 
                           | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11) 
                              << 0x11U)));
        __Vtemp_12[1U] = 0U;
        __Vtemp_12[2U] = 0U;
        bufp->chgWData(oldp+114,(__Vtemp_12),70);
        bufp->chgBit(oldp+117,((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+118,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_reg))));
        bufp->chgQData(oldp+119,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg)) 
                                   << 0x24U) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)) 
                                                 << 4U) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg) 
                                                                    << 2U) 
                                                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg) 
                                                                      << 1U))))))),44);
        bufp->chgBit(oldp+121,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+122,(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AW_valid));
        __Vtemp_13[0U] = (IData)((((QData)((IData)(
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                     ? 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                      ? 
                                                     ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                                       << 0x11U) 
                                                      | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                         >> 0xfU))
                                                      : 0U)
                                                     : 0U))) 
                                   << 0x1eU) | (QData)((IData)(
                                                               (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5) 
                                                                 << 0x16U) 
                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                                      ? 5U
                                                                      : 0U) 
                                                                    << 0x13U) 
                                                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid) 
                                                                      << 0x11U)))))));
        __Vtemp_13[1U] = (IData)(((((QData)((IData)(
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                      ? 
                                                     ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                       ? 
                                                      ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                        [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                                        << 0x11U) 
                                                       | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                          [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                          >> 0xfU))
                                                       : 0U)
                                                      : 0U))) 
                                    << 0x1eU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5) 
                                                                  << 0x16U) 
                                                                 | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                                       ? 5U
                                                                       : 0U) 
                                                                     << 0x13U) 
                                                                    | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid) 
                                                                       << 0x11U)))))) 
                                  >> 0x20U));
        __Vtemp_13[2U] = 0U;
        bufp->chgWData(oldp+123,(__Vtemp_13),70);
        bufp->chgBit(oldp+126,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+127,((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgQData(oldp+128,((((QData)((IData)(
                                                   ((1U 
                                                     == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))
                                                     ? 
                                                    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                                     : 0U))) 
                                   << 6U) | (QData)((IData)(
                                                            ((0x3cU 
                                                              & ((- (IData)(
                                                                            (1U 
                                                                             == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)))) 
                                                                 << 2U)) 
                                                             | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_7) 
                                                                << 1U)))))),38);
        bufp->chgBit(oldp+130,((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+131,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+132,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+133,(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AR_valid));
        __Vtemp_14[0U] = (IData)((((QData)((IData)(
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                     ? 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                      ? 
                                                     ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                       << 0x19U) 
                                                      | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                         >> 7U))
                                                      : 0U)
                                                     : 0U))) 
                                   << 0x1eU) | (QData)((IData)(
                                                               ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                                   ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_he49e9fcb_0_2)
                                                                   : 0U) 
                                                                 << 0x16U) 
                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                                      ? 5U
                                                                      : 0U) 
                                                                    << 0x13U) 
                                                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                                                      << 0x11U)))))));
        __Vtemp_14[1U] = (IData)(((((QData)((IData)(
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                      ? 
                                                     ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                       ? 
                                                      ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                        [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                        << 0x19U) 
                                                       | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                          [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                          >> 7U))
                                                       : 0U)
                                                      : 0U))) 
                                    << 0x1eU) | (QData)((IData)(
                                                                ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                                    ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_he49e9fcb_0_2)
                                                                    : 0U) 
                                                                  << 0x16U) 
                                                                 | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                                       ? 5U
                                                                       : 0U) 
                                                                     << 0x13U) 
                                                                    | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                                                       << 0x11U)))))) 
                                  >> 0x20U));
        __Vtemp_14[2U] = 0U;
        bufp->chgWData(oldp+134,(__Vtemp_14),70);
        bufp->chgBit(oldp+137,((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+138,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_reg) 
                                      >> 1U))));
        bufp->chgWData(oldp+139,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__io_commit),169);
        bufp->chgBit(oldp+145,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush));
        bufp->chgQData(oldp+146,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__io_revert),33);
        bufp->chgBit(oldp+148,((1U & ((~ ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))) 
                                      | ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T)) 
                                         & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full)))))));
        bufp->chgBit(oldp+149,((1U & (~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match) 
                                         & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+150,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT___instruction_cache_io_CPU_response_valid));
        __Vtemp_20[0U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_1)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_2) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_3)))))) 
                           << 0x1eU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_13) 
                                         << 0xeU) | 
                                        (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_14) 
                                          << 7U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_15))));
        __Vtemp_20[1U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_1)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_2) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_3)))))) 
                           >> 2U) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_1)) 
                                                << 0xaU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_2) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_3))))) 
                                              >> 0x20U)) 
                                     << 0x1eU));
        __Vtemp_20[2U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_4)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_5) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_6)))))) 
                           << 8U) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_1)) 
                                                << 0xaU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_2) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_3))))) 
                                              >> 0x20U)) 
                                     >> 2U));
        __Vtemp_20[3U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_7)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_8) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_9)))))) 
                           << 0x12U) | (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_4)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_5) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_6)))))) 
                                         >> 0x18U) 
                                        | ((IData)(
                                                   ((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_4)) 
                                                      << 0xaU) 
                                                     | (QData)((IData)(
                                                                       (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_5) 
                                                                         << 6U) 
                                                                        | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_6))))) 
                                                    >> 0x20U)) 
                                           << 8U)));
        __Vtemp_20[4U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_10)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_11) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_12)))))) 
                           << 0x1cU) | (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_7)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_8) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_9)))))) 
                                         >> 0xeU) | 
                                        ((IData)(((
                                                   ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_7)) 
                                                    << 0xaU) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_8) 
                                                                       << 6U) 
                                                                      | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_9))))) 
                                                  >> 0x20U)) 
                                         << 0x12U)));
        __Vtemp_20[5U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_10)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_11) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_12)))))) 
                           >> 4U) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_10)) 
                                                << 0xaU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_11) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_12))))) 
                                              >> 0x20U)) 
                                     << 0x1cU));
        __Vtemp_20[6U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_0 
                           << 0xaU) | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_55) 
                                        << 6U) | ((IData)(
                                                          ((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_10)) 
                                                             << 0xaU) 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_11) 
                                                                                << 6U) 
                                                                               | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_12))))) 
                                                           >> 0x20U)) 
                                                  >> 4U)));
        __Vtemp_20[7U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_0 
                          >> 0x16U);
        bufp->chgWData(oldp+151,(__Vtemp_20),234);
        bufp->chgBit(oldp+159,(((0U != (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_23)) 
                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__fire_store))));
        bufp->chgWData(oldp+160,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__io_backend_memory_request_bits),72);
        bufp->chgBit(oldp+163,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__output_valid_r_1));
        bufp->chgQData(oldp+164,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT___data_cache_io_backend_memory_response_bits),36);
        bufp->chgCData(oldp+166,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_MEMRS),4);
        bufp->chgCData(oldp+167,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_INTRS),4);
        bufp->chgBit(oldp+168,(((7U & ((3U & ((0U != 
                                               (7U 
                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                   >> 2U))) 
                                              + VL_SHIFTR_III(2,2,32, 
                                                              (3U 
                                                               & (- (IData)(
                                                                            (0U 
                                                                             != 
                                                                             (7U 
                                                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                                                >> 2U)))))), 1U))) 
                                       + (3U & ((0U 
                                                 != 
                                                 (7U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                     >> 2U))) 
                                                + (0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                       >> 2U))))))) 
                                >= (7U & ((3U & ((1U 
                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_INTRS)) 
                                                 + 
                                                 (1U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_INTRS) 
                                                     >> 1U)))) 
                                          + (3U & (
                                                   (1U 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_INTRS) 
                                                       >> 2U)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_INTRS) 
                                                       >> 3U)))))))));
        bufp->chgBit(oldp+169,(((7U & ((3U & ((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready)) 
                                              + (1U 
                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready) 
                                                    >> 1U)))) 
                                       + (3U & ((1U 
                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready) 
                                                    >> 2U)) 
                                                + (1U 
                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready) 
                                                      >> 3U)))))) 
                                >= (7U & ((3U & ((1U 
                                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_MEMRS)) 
                                                 + 
                                                 (1U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_MEMRS) 
                                                     >> 1U)))) 
                                          + (3U & (
                                                   (1U 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_MEMRS) 
                                                       >> 2U)) 
                                                   + 
                                                   (1U 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_MEMRS) 
                                                       >> 3U)))))))));
        bufp->chgWData(oldp+170,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___FTQ_io_FTQ),110);
        __Vtemp_21[0U] = (IData)((((QData)((IData)(
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                                     ? 
                                                    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                                     : 0U))) 
                                   << 0x2aU) | (((QData)((IData)(
                                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                                                   ? 
                                                                  vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                                                   : 0U))) 
                                                 << 0x19U) 
                                                | (QData)((IData)(
                                                                  ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                                                      ? 
                                                                     vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                                                     [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                                                      : 0U) 
                                                                    << 8U) 
                                                                   | ((0xffffff80U 
                                                                       & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                                                                           << 7U) 
                                                                          & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                                                             [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                             << 6U))) 
                                                                      | ((0xffffffc0U 
                                                                          & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                                                                              << 6U) 
                                                                             & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 5U))) 
                                                                         | ((0xffffffe0U 
                                                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                << 5U) 
                                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 4U))) 
                                                                            | ((0xfffffff0U 
                                                                                & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                << 4U) 
                                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 3U))) 
                                                                               | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0]) 
                                                                                << 3U) 
                                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0]) 
                                                                                << 2U) 
                                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0]) 
                                                                                << 1U) 
                                                                                | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0]))))))))))))));
        __Vtemp_21[1U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                            [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                             : 0U) << 0x1bU) | (IData)(
                                                       ((((QData)((IData)(
                                                                          ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                                                            ? 
                                                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                                                           [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                                                            : 0U))) 
                                                          << 0x2aU) 
                                                         | (((QData)((IData)(
                                                                             ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                                                               ? 
                                                                              vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                                                              [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                                                               : 0U))) 
                                                             << 0x19U) 
                                                            | (QData)((IData)(
                                                                              ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                                                                 ? 
                                                                                vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                                                                 : 0U) 
                                                                                << 8U) 
                                                                               | ((0xffffff80U 
                                                                                & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                << 7U) 
                                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 6U))) 
                                                                                | ((0xffffffc0U 
                                                                                & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                << 6U) 
                                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 5U))) 
                                                                                | ((0xffffffe0U 
                                                                                & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                << 5U) 
                                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 4U))) 
                                                                                | ((0xfffffff0U 
                                                                                & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                << 4U) 
                                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0] 
                                                                                << 3U))) 
                                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0]) 
                                                                                << 3U) 
                                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0]) 
                                                                                << 2U) 
                                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0]) 
                                                                                << 1U) 
                                                                                | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0) 
                                                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0]))))))))))))) 
                                                        >> 0x20U)));
        __Vtemp_26[0U] = __Vtemp_21[0U];
        __Vtemp_26[1U] = __Vtemp_21[1U];
        __Vtemp_26[2U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                             ? (0x3fffffffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U])
                             : 0U) << 0x14U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT____VdfgRegularize_h1c10e421_1_6) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                                     ? 
                                                    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                                     : 0U) 
                                                   >> 5U)));
        __Vtemp_26[3U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT____VdfgRegularize_h2c562b4e_0_1 
                           << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__io_ROB_output_ROB_index_REG) 
                                         << 0x12U) 
                                        | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                                             ? (0x3fffffffU 
                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U])
                                             : 0U) 
                                           >> 0xcU)));
        __Vtemp_26[4U] = ((0x1000000U & ((IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__row_valid_mem 
                                                  >> 
                                                  (0x3fU 
                                                   & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__front_pointer)))) 
                                         << 0x18U)) 
                          | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT____VdfgRegularize_h2c562b4e_0_1 
                             >> 8U));
        bufp->chgWData(oldp+174,(__Vtemp_26),153);
        bufp->chgCData(oldp+179,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT__commit_row_complete),4);
        bufp->chgBit(oldp+180,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT__commit_valid));
        bufp->chgBit(oldp+181,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT__branch_commit));
        bufp->chgWData(oldp+182,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_FU_outputs),772);
        bufp->chgBit(oldp+207,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__full)))));
        bufp->chgBit(oldp+208,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__empty)))));
        bufp->chgWData(oldp+209,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory
                                 [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap_1]),110);
        bufp->chgCData(oldp+213,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___ROB_io_ROB_index),6);
        bufp->chgCData(oldp+214,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__back_pointer))),4);
        bufp->chgCData(oldp+215,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__front_pointer),5);
        bufp->chgCData(oldp+216,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__back_pointer),5);
        bufp->chgCData(oldp+217,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__front_pointer))),4);
        bufp->chgWData(oldp+218,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__FTQ),1760);
        bufp->chgBit(oldp+273,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__dq));
        bufp->chgBit(oldp+274,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__full));
        bufp->chgBit(oldp+275,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__full)))));
        bufp->chgBit(oldp+276,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT____Vcellinp__ROB__io_ROB_packet_valid));
        __Vtemp_47[6U] = ((0xc0000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U]) 
                          | ((0xfU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U]) 
                             | ((0x20000000U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                                 (3U 
                                                  & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                                     >> 0xdU))] 
                                                 >> 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                                     >> 8U))) 
                                                << 0x1dU)) 
                                | ((0x10000000U & (
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                                    (3U 
                                                     & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x1fU 
                                                     & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U])) 
                                                   << 0x1cU)) 
                                   | (0xffffff0U & 
                                      vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U])))));
        __Vtemp_49[0U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U];
        __Vtemp_49[1U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U];
        __Vtemp_49[2U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[2U];
        __Vtemp_49[3U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[3U];
        __Vtemp_49[4U] = ((0xfffffff0U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U]) 
                          | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__initialReady) 
                              << 2U) | (3U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U])));
        __Vtemp_49[5U] = ((0xfU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[5U]) 
                          | (0xfffffff0U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[5U]));
        __Vtemp_49[6U] = __Vtemp_47[6U];
        __Vtemp_49[7U] = ((0x3fffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U]) 
                          | (0xc0000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U]));
        __Vtemp_49[8U] = ((0x3fffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U]) 
                          | (0xc0000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U]));
        __Vtemp_49[9U] = ((0xff000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U]) 
                          | ((0x800000U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                            (3U & (
                                                   vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                   >> 7U))] 
                                            >> (0x1fU 
                                                & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                   >> 2U))) 
                                           << 0x17U)) 
                             | ((0x400000U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                               (3U 
                                                & ((0x7fffffeU 
                                                    & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                       << 1U)) 
                                                   | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U] 
                                                      >> 0x1fU)))] 
                                               >> (0x1fU 
                                                   & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U] 
                                                      >> 0x1aU))) 
                                              << 0x16U)) 
                                | (0x3fffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U]))));
        __Vtemp_49[0xaU] = ((0xffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU]) 
                            | (0xff000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU]));
        __Vtemp_49[0xbU] = ((0xffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU]) 
                            | (0xff000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU]));
        __Vtemp_49[0xcU] = ((0xfffc0000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU]) 
                            | ((0x20000U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                             (3U & 
                                              (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                               >> 1U))] 
                                             >> (0x1fU 
                                                 & ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                                     << 4U) 
                                                    | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU] 
                                                       >> 0x1cU)))) 
                                            << 0x11U)) 
                               | ((0x10000U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                                (3U 
                                                 & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU] 
                                                    >> 0x19U))] 
                                                >> 
                                                (0x1fU 
                                                 & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU] 
                                                    >> 0x14U))) 
                                               << 0x10U)) 
                                  | (0xffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU]))));
        __Vtemp_49[0xdU] = (0x3ffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU]);
        bufp->chgWData(oldp+277,(__Vtemp_49),434);
        bufp->chgCData(oldp+291,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_PC_file_exec_addr),6);
        bufp->chgIData(oldp+292,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_en_d0)
                                   ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][2U] 
                                       << 0x1aU) | 
                                      (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][1U] 
                                       >> 6U)) : 0U)),32);
        bufp->chgBit(oldp+293,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__full));
        bufp->chgCData(oldp+294,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__front_pointer),7);
        bufp->chgCData(oldp+295,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__back_pointer),7);
        bufp->chgBit(oldp+296,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate));
        bufp->chgQData(oldp+297,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__row_valid_mem),64);
        bufp->chgCData(oldp+299,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__front_index),6);
        bufp->chgCData(oldp+300,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__io_ROB_output_ROB_index_REG),6);
        __Vtemp_50[0U] = (IData)((((QData)((IData)(
                                                   (0xffU 
                                                    & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U]))) 
                                   << 0x1eU) | (QData)((IData)(
                                                               ((0x3fffc000U 
                                                                 & ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                                                     << 0x18U) 
                                                                    | (0xffc000U 
                                                                       & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U] 
                                                                          >> 8U)))) 
                                                                | ((0x3f80U 
                                                                    & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U] 
                                                                       >> 1U)) 
                                                                   | (0x7fU 
                                                                      & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U] 
                                                                         >> 0xfU))))))));
        __Vtemp_50[1U] = ((0xffffffc0U & ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU] 
                                           << 0x14U) 
                                          | (0xfffc0U 
                                             & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                                >> 0xcU)))) 
                          | (IData)(((((QData)((IData)(
                                                       (0xffU 
                                                        & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U]))) 
                                       << 0x1eU) | (QData)((IData)(
                                                                   ((0x3fffc000U 
                                                                     & ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                                                         << 0x18U) 
                                                                        | (0xffc000U 
                                                                           & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U] 
                                                                              >> 8U)))) 
                                                                    | ((0x3f80U 
                                                                        & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U] 
                                                                           >> 1U)) 
                                                                       | (0x7fU 
                                                                          & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U] 
                                                                             >> 0xfU))))))) 
                                     >> 0x20U)));
        __Vtemp_50[2U] = (0x3fU & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU] 
                                   >> 0xcU));
        bufp->chgWData(oldp+301,(__Vtemp_50),70);
        bufp->chgCData(oldp+304,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_0) 
                                  << 1U)),2);
        bufp->chgCData(oldp+305,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                  << 1U)),2);
        bufp->chgCData(oldp+306,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                  << 1U)),2);
        bufp->chgCData(oldp+307,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid) 
                                  << 1U)),2);
        bufp->chgIData(oldp+308,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                               << 0xaU)) 
                                  | ((0x8000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                                 >> 3U)) 
                                     | ((0x6000U & 
                                         (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                          << 1U)) | 
                                        ((0x1fe0U & 
                                          (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[3U] 
                                           >> 0x10U)) 
                                         | (0x1fU & 
                                            ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U] 
                                              << 3U) 
                                             | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[3U] 
                                                >> 0x1dU)))))))),17);
        bufp->chgIData(oldp+309,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                               << 9U)) 
                                  | ((0x8000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U] 
                                                 << 3U)) 
                                     | ((0x6000U & 
                                         (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U] 
                                          << 7U)) | 
                                        ((0x1fe0U & 
                                          (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                           >> 0xaU)) 
                                         | (0x1fU & 
                                            (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                             >> 0x17U))))))),17);
        bufp->chgIData(oldp+310,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                               << 8U)) 
                                  | ((0x8000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U] 
                                                 << 9U)) 
                                     | ((0x6000U & 
                                         (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U] 
                                          << 0xdU)) 
                                        | ((0x1fe0U 
                                            & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                               >> 4U)) 
                                           | (0x1fU 
                                              & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                 >> 0x11U))))))),17);
        bufp->chgIData(oldp+311,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
                                               << 7U)) 
                                  | ((0x8000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU] 
                                                 << 0xfU)) 
                                     | ((0x6000U & 
                                         (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                          >> 0xdU)) 
                                        | ((0x1fe0U 
                                            & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                               << 2U)) 
                                           | (0x1fU 
                                              & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                                 >> 0xbU))))))),17);
        bufp->chgCData(oldp+312,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____Vcellinp__ROB_WB_banks_0__io_addrB),6);
        bufp->chgBit(oldp+313,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_13));
        bufp->chgCData(oldp+314,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgBit(oldp+315,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_9));
        bufp->chgCData(oldp+316,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgBit(oldp+317,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_5));
        bufp->chgCData(oldp+318,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____Vcellinp__ROB_WB_banks_0__io_addrE),6);
        bufp->chgBit(oldp+319,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_1));
        bufp->chgCData(oldp+320,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+321,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+322,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+323,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+324,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+325,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+326,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+327,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_0))),2);
        bufp->chgCData(oldp+328,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_13))))),2);
        bufp->chgCData(oldp+329,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate))))),2);
        bufp->chgBit(oldp+330,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_13));
        bufp->chgBit(oldp+331,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_9));
        bufp->chgBit(oldp+332,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_5));
        bufp->chgBit(oldp+333,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_1));
        bufp->chgCData(oldp+334,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+335,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+336,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+337,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+338,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+339,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+340,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+341,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_0))),2);
        bufp->chgCData(oldp+342,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_13))))),2);
        bufp->chgBit(oldp+343,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_13));
        bufp->chgBit(oldp+344,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_9));
        bufp->chgBit(oldp+345,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_5));
        bufp->chgBit(oldp+346,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_1));
        bufp->chgCData(oldp+347,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+348,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+349,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+350,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+351,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+352,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+353,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+354,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_0))),2);
        bufp->chgCData(oldp+355,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_13))))),2);
        bufp->chgBit(oldp+356,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_13));
        bufp->chgBit(oldp+357,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_9));
        bufp->chgBit(oldp+358,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_5));
        bufp->chgBit(oldp+359,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_1));
        bufp->chgCData(oldp+360,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+361,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+362,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+363,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+364,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+365,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+366,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+367,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_0))),2);
        bufp->chgCData(oldp+368,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_13))))),2);
        bufp->chgIData(oldp+369,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+370,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT____Vcellinp__mem_ext__W0_data),17);
        bufp->chgIData(oldp+371,((0x1ffffU & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate))))),17);
        bufp->chgIData(oldp+372,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+373,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT____Vcellinp__mem_ext__W0_data),17);
        bufp->chgIData(oldp+374,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+375,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT____Vcellinp__mem_ext__W0_data),17);
        bufp->chgIData(oldp+376,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+377,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT____Vcellinp__mem_ext__W0_data),17);
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0) {
            __Vtemp_52[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U];
            __Vtemp_52[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][1U];
            __Vtemp_52[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][2U];
        } else {
            __Vtemp_52[0U] = 0U;
            __Vtemp_52[1U] = 0U;
            __Vtemp_52[2U] = 0U;
        }
        bufp->chgWData(oldp+378,(__Vtemp_52),70);
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_en_d0) {
            __Vtemp_54[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][0U];
            __Vtemp_54[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][1U];
            __Vtemp_54[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][2U];
        } else {
            __Vtemp_54[0U] = 0U;
            __Vtemp_54[1U] = 0U;
            __Vtemp_54[2U] = 0U;
        }
        bufp->chgWData(oldp+381,(__Vtemp_54),70);
        bufp->chgWData(oldp+384,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT____Vcellinp__mem_ext__W0_data),70);
        __Vtemp_57[0U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate)));
        __Vtemp_57[1U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate)));
        __Vtemp_57[2U] = (0x3fU & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate))));
        bufp->chgWData(oldp+387,(__Vtemp_57),70);
        bufp->chgIData(oldp+390,(((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU] 
                                   << 0xeU) | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                               >> 0x12U))),32);
        bufp->chgBit(oldp+391,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__empty)))));
        __Vtemp_62[0U] = (IData)((0x3ffffffffffULL 
                                  & (((QData)((IData)(
                                                      vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U])))));
        __Vtemp_62[1U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[0U] 
                           << 0xaU) | (IData)(((0x3ffffffffffULL 
                                                & (((QData)((IData)(
                                                                    vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U])))) 
                                               >> 0x20U)));
        __Vtemp_62[2U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[0U] 
                           >> 0x16U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[1U] 
                                        << 0xaU));
        __Vtemp_62[3U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[1U] 
                           >> 0x16U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[2U] 
                                        << 0xaU));
        __Vtemp_62[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[0U] 
                           << 4U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[2U] 
                                     >> 0x16U));
        __Vtemp_62[5U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[0U] 
                           >> 0x1cU) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[1U] 
                                        << 4U));
        __Vtemp_62[6U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[0U] 
                           << 0x1eU) | ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[1U] 
                                         >> 0x1cU) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[2U] 
                                           << 4U)));
        __Vtemp_62[7U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[0U] 
                           >> 2U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[1U] 
                                     << 0x1eU));
        __Vtemp_62[8U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[1U] 
                           >> 2U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[2U] 
                                     << 0x1eU));
        __Vtemp_62[9U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[0U] 
                           << 0x18U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[2U] 
                                        >> 2U));
        __Vtemp_62[0xaU] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[0U] 
                             >> 8U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[1U] 
                                       << 0x18U));
        __Vtemp_62[0xbU] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[1U] 
                             >> 8U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[2U] 
                                       << 0x18U));
        __Vtemp_62[0xcU] = ((0xfffc0000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU]) 
                            | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[2U] 
                               >> 8U));
        __Vtemp_62[0xdU] = (0x3ffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU]);
        bufp->chgWData(oldp+392,(__Vtemp_62),434);
        bufp->chgCData(oldp+406,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready),4);
        bufp->chgCData(oldp+407,((((IData)((0U != (7U 
                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                      >> 2U)))) 
                                   << 3U) | (((IData)(
                                                      (0U 
                                                       != 
                                                       (7U 
                                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                           >> 2U)))) 
                                              << 2U) 
                                             | (3U 
                                                & (- (IData)(
                                                             (0U 
                                                              != 
                                                              (7U 
                                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                                                  >> 2U))))))))),4);
        bufp->chgWData(oldp+408,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG),90);
        bufp->chgWData(oldp+411,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG),90);
        bufp->chgWData(oldp+414,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG),90);
        bufp->chgWData(oldp+417,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG),90);
        bufp->chgBit(oldp+420,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0_io_FU_input_valid_REG));
        bufp->chgBit(oldp+421,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1_io_FU_input_valid_REG));
        bufp->chgBit(oldp+422,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2_io_FU_input_valid_REG));
        bufp->chgBit(oldp+423,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU_io_FU_input_valid_REG));
        bufp->chgWData(oldp+424,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_1),186);
        bufp->chgWData(oldp+430,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___AGU_io_FU_output),193);
        bufp->chgBit(oldp+437,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+438,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+439,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_is_unsigned_REG));
        bufp->chgIData(oldp+440,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_address_REG),32);
        bufp->chgIData(oldp+441,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_wr_data_REG),32);
        bufp->chgCData(oldp+442,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+443,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_memory_type_REG),2);
        bufp->chgCData(oldp+444,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_access_width_REG),2);
        bufp->chgBit(oldp+445,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__hasBeenResetReg));
        bufp->chgBit(oldp+446,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__unnamedblk1__DOT__is_load));
        bufp->chgBit(oldp+447,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__unnamedblk1__DOT__is_store));
        bufp->chgWData(oldp+448,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_4),186);
        __Vtemp_71[0U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                             ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG)
                             : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG)) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____Vcellinp__ROB_WB_banks_0__io_addrB) 
                                        << 7U) | ((
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                                                     ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG)
                                                     : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG)) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_7) 
                                                     << 1U))));
        __Vtemp_71[1U] = 0U;
        __Vtemp_71[2U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG
                             : 0U) << 0x17U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1) 
                                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG)) 
                                                << 0x16U));
        __Vtemp_71[3U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG
                             : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG) 
                           << 0x18U) | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1) 
                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG)) 
                                         << 0x17U) 
                                        | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG
                                             : 0U) 
                                           >> 9U)));
        __Vtemp_71[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0 
                           << 0x19U) | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_40) 
                                         << 0x18U) 
                                        | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG
                                             : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG) 
                                           >> 8U)));
        __Vtemp_71[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_h3c5920b7_2_0) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0 
                                        >> 7U));
        __Vtemp_71[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h04ee65bd_2_0;
        bufp->chgWData(oldp+454,(__Vtemp_71),193);
        bufp->chgBit(oldp+461,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1));
        bufp->chgBit(oldp+462,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__monitor_output_REG));
        __Vtemp_77[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_77[1U] = 0U;
        __Vtemp_77[2U] = 0U;
        __Vtemp_77[3U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                          << 0x18U);
        __Vtemp_77[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_77[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result 
                                        >> 7U));
        __Vtemp_77[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+463,(__Vtemp_77),193);
        bufp->chgIData(oldp+470,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgIData(oldp+471,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+472,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgCData(oldp+473,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+474,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgCData(oldp+475,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+476,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+477,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgBit(oldp+478,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgIData(oldp+479,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+480,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+481,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        __Vtemp_86[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_86[1U] = 0U;
        __Vtemp_86[2U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG 
                           << 0x17U) | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG) 
                                        << 0x16U));
        __Vtemp_86[3U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG 
                           << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG) 
                                         << 0x17U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG 
                                           >> 9U)));
        __Vtemp_86[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_86[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG 
                                        >> 7U));
        __Vtemp_86[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+482,(__Vtemp_86),193);
        bufp->chgIData(oldp+489,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+490,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgBit(oldp+491,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG));
        bufp->chgBit(oldp+492,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG));
        bufp->chgIData(oldp+493,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG),32);
        bufp->chgCData(oldp+494,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+495,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgIData(oldp+496,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG),32);
        bufp->chgCData(oldp+497,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgCData(oldp+498,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+499,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgBit(oldp+500,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_valid_REG));
        bufp->chgBit(oldp+501,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__BRANCH));
        bufp->chgBit(oldp+502,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__EQ));
        bufp->chgBit(oldp+503,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__NE));
        bufp->chgBit(oldp+504,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__LT));
        bufp->chgBit(oldp+505,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__GE));
        bufp->chgBit(oldp+506,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__LTU));
        bufp->chgBit(oldp+507,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__GEU));
        bufp->chgBit(oldp+508,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__JAL));
        bufp->chgBit(oldp+509,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__JALR));
        bufp->chgWData(oldp+510,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_3),186);
        __Vtemp_92[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_92[1U] = 0U;
        __Vtemp_92[2U] = 0U;
        __Vtemp_92[3U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                          << 0x18U);
        __Vtemp_92[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_92[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result 
                                        >> 7U));
        __Vtemp_92[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+516,(__Vtemp_92),193);
        bufp->chgBit(oldp+523,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__monitor_output_REG));
        bufp->chgIData(oldp+524,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgIData(oldp+525,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+526,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgCData(oldp+527,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+528,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgCData(oldp+529,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+530,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgBit(oldp+531,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgIData(oldp+532,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+533,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+534,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgWData(oldp+535,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_2),186);
        __Vtemp_98[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_98[1U] = 0U;
        __Vtemp_98[2U] = 0U;
        __Vtemp_98[3U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                          << 0x18U);
        __Vtemp_98[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_98[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result 
                                        >> 7U));
        __Vtemp_98[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+541,(__Vtemp_98),193);
        bufp->chgBit(oldp+548,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__monitor_output_REG));
        bufp->chgIData(oldp+549,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgIData(oldp+550,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+551,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgCData(oldp+552,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+553,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgCData(oldp+554,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+555,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgBit(oldp+556,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgIData(oldp+557,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+558,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+559,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgCData(oldp+560,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_h6171c202_4_32))
                                   : 0U)),6);
        bufp->chgCData(oldp+561,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_h6171c202_4_33))
                                   : 0U)),6);
        bufp->chgCData(oldp+562,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_h6171c202_4_34))
                                   : 0U)),6);
        bufp->chgCData(oldp+563,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_h6171c202_4_35))
                                   : 0U)),6);
        bufp->chgCData(oldp+564,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_h6171c202_4_36))
                                   : 0U)),6);
        bufp->chgCData(oldp+565,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_h6171c202_4_37))
                                   : 0U)),6);
        bufp->chgCData(oldp+566,((0x3fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits[2U] 
                                           >> 4U))),6);
        bufp->chgCData(oldp+567,((0x3fU & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits[2U] 
                                            << 4U) 
                                           | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits[1U] 
                                              >> 0x1cU)))),6);
        bufp->chgIData(oldp+568,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R7_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R7_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+569,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R6_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R6_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+570,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R5_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R5_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+571,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R4_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R4_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+572,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R3_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R3_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+573,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R2_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R2_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+574,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R1_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R1_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+575,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),32);
        bufp->chgCData(oldp+576,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_h3c5920b7_2_0))),6);
        bufp->chgCData(oldp+577,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG))),6);
        bufp->chgCData(oldp+578,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG))),6);
        bufp->chgCData(oldp+579,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_h3c5920b7_2_67))),6);
        bufp->chgBit(oldp+580,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid));
        bufp->chgBit(oldp+581,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid_1));
        bufp->chgBit(oldp+582,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid_2));
        bufp->chgBit(oldp+583,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid_3));
        bufp->chgIData(oldp+584,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0),32);
        bufp->chgIData(oldp+585,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_3),32);
        bufp->chgIData(oldp+586,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_h3c5920b7_2_67)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_3)),32);
        bufp->chgIData(oldp+587,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgIData(oldp+588,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgIData(oldp+589,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_h3c5920b7_2_0)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0)),32);
        bufp->chgBit(oldp+590,((0U != (7U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                             >> 2U)))));
        bufp->chgBit(oldp+591,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_0_valid));
        bufp->chgWData(oldp+592,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2),90);
        bufp->chgBit(oldp+595,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_1_valid));
        bufp->chgWData(oldp+596,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3),90);
        bufp->chgBit(oldp+599,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_2_valid));
        bufp->chgWData(oldp+600,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4),90);
        bufp->chgBit(oldp+603,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_3_valid));
        bufp->chgWData(oldp+604,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5),90);
        bufp->chgBit(oldp+607,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions) 
                                   >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgWData(oldp+608,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___INT_RS_io_RF_inputs_0_bits),90);
        bufp->chgBit(oldp+611,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions) 
                                   >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgWData(oldp+612,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___INT_RS_io_RF_inputs_1_bits),90);
        bufp->chgBit(oldp+615,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions) 
                                   >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgWData(oldp+616,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___INT_RS_io_RF_inputs_2_bits),90);
        bufp->chgSData(oldp+619,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions),16);
        bufp->chgWData(oldp+620,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__reservation_station),1456);
        bufp->chgSData(oldp+666,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__RS1_match),16);
        bufp->chgSData(oldp+667,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__RS2_match),16);
        bufp->chgCData(oldp+668,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_RS_index),4);
        bufp->chgBit(oldp+669,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid));
        bufp->chgCData(oldp+670,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_RS_index),4);
        bufp->chgBit(oldp+671,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid));
        bufp->chgCData(oldp+672,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_RS_index),4);
        bufp->chgBit(oldp+673,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid));
        bufp->chgCData(oldp+674,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries),5);
        bufp->chgCData(oldp+675,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary),4);
        bufp->chgCData(oldp+676,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_1),4);
        bufp->chgCData(oldp+677,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_2),4);
        bufp->chgCData(oldp+678,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_3),4);
        bufp->chgBit(oldp+679,((0U != (7U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__availalbe_RS_entries) 
                                             >> 2U)))));
        bufp->chgBit(oldp+680,((IData)(((0x100000U 
                                         == (0x300000U 
                                             & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hfcd7553a_3_4)))));
        bufp->chgBit(oldp+681,((IData)(((0x4000U == 
                                         (0xc000U & 
                                          vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hfcd7553a_3_5)))));
        bufp->chgBit(oldp+682,((IData)(((0x100U == 
                                         (0x300U & 
                                          vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hfcd7553a_3_6)))));
        bufp->chgBit(oldp+683,((IData)(((4U == (0xcU 
                                                & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hfcd7553a_3_7)))));
        bufp->chgIData(oldp+684,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MOB_io_reserved_pointers),20);
        bufp->chgBit(oldp+685,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_valid));
        bufp->chgWData(oldp+686,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits),90);
        bufp->chgWData(oldp+689,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__reservation_station),1968);
        bufp->chgCData(oldp+751,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__front_pointer),5);
        bufp->chgCData(oldp+752,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__back_pointer),5);
        bufp->chgCData(oldp+753,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__front_pointer))),4);
        bufp->chgCData(oldp+754,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__back_pointer))),4);
        bufp->chgCData(oldp+755,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__written_vec),4);
        bufp->chgSData(oldp+756,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__RS1_match),16);
        bufp->chgSData(oldp+757,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__RS2_match),16);
        bufp->chgCData(oldp+758,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__availalbe_RS_entries),5);
        bufp->chgBit(oldp+759,((0U != (7U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__availalbe_MOB_entries) 
                                             >> 2U)))));
        __Vtemp_99[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[0U];
        __Vtemp_99[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[1U];
        __Vtemp_99[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[2U];
        __Vtemp_99[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[3U];
        __Vtemp_99[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[4U];
        __Vtemp_99[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[5U];
        __Vtemp_99[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid;
        bufp->chgWData(oldp+760,(__Vtemp_99),193);
        bufp->chgSData(oldp+767,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_stores),16);
        bufp->chgSData(oldp+768,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_loads),16);
        bufp->chgSData(oldp+769,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_23),16);
        bufp->chgCData(oldp+770,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__written_vec),4);
        bufp->chgCData(oldp+771,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__front_pointer),5);
        bufp->chgCData(oldp+772,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__back_pointer),5);
        bufp->chgCData(oldp+773,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__front_pointer))),4);
        bufp->chgCData(oldp+774,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__back_pointer))),4);
        bufp->chgWData(oldp+775,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB),1424);
        bufp->chgQData(oldp+820,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__age_vector),64);
        bufp->chgQData(oldp+822,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__byte_sels),64);
        bufp->chgWData(oldp+824,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__wr_bytes),512);
        bufp->chgBit(oldp+840,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[2U] 
                                             >> 0x16U)))));
        bufp->chgBit(oldp+841,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[2U] 
                                             >> 0x16U)))));
        bufp->chgBit(oldp+842,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[5U] 
                                             >> 0xfU)))));
        bufp->chgBit(oldp+843,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[5U] 
                                             >> 0xfU)))));
        bufp->chgBit(oldp+844,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[8U] 
                                             >> 8U)))));
        bufp->chgBit(oldp+845,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[8U] 
                                             >> 8U)))));
        bufp->chgBit(oldp+846,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xbU] 
                                             >> 1U)))));
        bufp->chgBit(oldp+847,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xbU] 
                                             >> 1U)))));
        bufp->chgBit(oldp+848,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xdU] 
                                             >> 0x1aU)))));
        bufp->chgBit(oldp+849,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xdU] 
                                             >> 0x1aU)))));
        bufp->chgBit(oldp+850,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x10U] 
                                             >> 0x13U)))));
        bufp->chgBit(oldp+851,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x10U] 
                                             >> 0x13U)))));
        bufp->chgBit(oldp+852,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x13U] 
                                             >> 0xcU)))));
        bufp->chgBit(oldp+853,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x13U] 
                                             >> 0xcU)))));
        bufp->chgBit(oldp+854,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x16U] 
                                             >> 5U)))));
        bufp->chgBit(oldp+855,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x16U] 
                                             >> 5U)))));
        bufp->chgBit(oldp+856,((1U == (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x18U] 
                                       >> 0x1eU))));
        bufp->chgBit(oldp+857,((2U == (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x18U] 
                                       >> 0x1eU))));
        bufp->chgBit(oldp+858,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1bU] 
                                             >> 0x17U)))));
        bufp->chgBit(oldp+859,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1bU] 
                                             >> 0x17U)))));
        bufp->chgBit(oldp+860,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1eU] 
                                             >> 0x10U)))));
        bufp->chgBit(oldp+861,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1eU] 
                                             >> 0x10U)))));
        bufp->chgBit(oldp+862,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x21U] 
                                             >> 9U)))));
        bufp->chgBit(oldp+863,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x21U] 
                                             >> 9U)))));
        bufp->chgBit(oldp+864,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x24U] 
                                             >> 2U)))));
        bufp->chgBit(oldp+865,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x24U] 
                                             >> 2U)))));
        bufp->chgBit(oldp+866,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x26U] 
                                             >> 0x1bU)))));
        bufp->chgBit(oldp+867,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x26U] 
                                             >> 0x1bU)))));
        bufp->chgBit(oldp+868,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x29U] 
                                             >> 0x14U)))));
        bufp->chgBit(oldp+869,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x29U] 
                                             >> 0x14U)))));
        bufp->chgBit(oldp+870,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x2cU] 
                                             >> 0xdU)))));
        bufp->chgBit(oldp+871,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x2cU] 
                                             >> 0xdU)))));
        bufp->chgBit(oldp+872,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__fire_store));
        bufp->chgCData(oldp+873,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__load_index),4);
        bufp->chgCData(oldp+874,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_load_index),4);
        bufp->chgCData(oldp+875,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_store_index),4);
        bufp->chgCData(oldp+876,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__response_age),4);
        bufp->chgIData(oldp+877,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__data_out),32);
        bufp->chgCData(oldp+878,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__availalbe_MOB_entries),5);
        bufp->chgBit(oldp+879,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__empty)))));
        bufp->chgWData(oldp+880,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.io_deq_bits),192);
        bufp->chgBit(oldp+886,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__empty));
        bufp->chgBit(oldp+887,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__empty)))));
        bufp->chgWData(oldp+888,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.io_deq_bits),192);
        bufp->chgBit(oldp+894,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid));
        bufp->chgWData(oldp+895,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits),192);
        bufp->chgBit(oldp+901,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__incoming_is_load));
        bufp->chgBit(oldp+902,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__incoming_is_store));
        bufp->chgBit(oldp+903,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT____Vcellinp__frontend__io_renamed_decoded_fetch_packet_ready));
        bufp->chgBit(oldp+904,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__full)))));
        bufp->chgBit(oldp+905,((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__full)) 
                                      & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__empty))))));
        bufp->chgWData(oldp+906,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.io_deq_bits),110);
        bufp->chgBit(oldp+910,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__io_predictions_in_ready_REG));
        bufp->chgBit(oldp+911,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty)))));
        bufp->chgWData(oldp+912,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data),110);
        bufp->chgCData(oldp+916,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__maybe_full) 
                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ptr_match)) 
                                   << 4U) | (0xfU & 
                                             ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__enq_ptr_value) 
                                              - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value))))),5);
        bufp->chgCData(oldp+917,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+918,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+919,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__maybe_full));
        bufp->chgBit(oldp+920,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ptr_match));
        bufp->chgBit(oldp+921,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty));
        bufp->chgBit(oldp+922,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__full));
        bufp->chgBit(oldp+923,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq));
        bufp->chgBit(oldp+924,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq));
        bufp->chgCData(oldp+925,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq)
                                           ? ((0xfU 
                                               == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value))
                                               ? 0U
                                               : ((IData)(1U) 
                                                  + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value)))
                                           : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value)))),4);
        bufp->chgWData(oldp+926,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT____Vcellinp__ram_ext__W0_data),110);
        __Vtemp_102[0U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq)));
        __Vtemp_102[1U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq)));
        __Vtemp_102[2U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq)));
        __Vtemp_102[3U] = (0x3fffU & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq))));
        bufp->chgWData(oldp+930,(__Vtemp_102),110);
        bufp->chgWData(oldp+934,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+938,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[1]),110);
        bufp->chgWData(oldp+942,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[2]),110);
        bufp->chgWData(oldp+946,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[3]),110);
        bufp->chgWData(oldp+950,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[4]),110);
        bufp->chgWData(oldp+954,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[5]),110);
        bufp->chgWData(oldp+958,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[6]),110);
        bufp->chgWData(oldp+962,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[7]),110);
        bufp->chgWData(oldp+966,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[8]),110);
        bufp->chgWData(oldp+970,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[9]),110);
        bufp->chgWData(oldp+974,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[10]),110);
        bufp->chgWData(oldp+978,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[11]),110);
        bufp->chgWData(oldp+982,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[12]),110);
        bufp->chgWData(oldp+986,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[13]),110);
        bufp->chgWData(oldp+990,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[14]),110);
        bufp->chgWData(oldp+994,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[15]),110);
        bufp->chgBit(oldp+998,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__io_fetch_packet_ready_REG));
        bufp->chgBit(oldp+999,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__empty)))));
        bufp->chgWData(oldp+1000,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1]),234);
        bufp->chgBit(oldp+1008,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__io_predictions_in_ready_REG));
        bufp->chgBit(oldp+1009,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__empty)))));
        bufp->chgWData(oldp+1010,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.io_deq_bits),110);
        bufp->chgBit(oldp+1014,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__full)))));
        bufp->chgBit(oldp+1015,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__empty)))));
        bufp->chgWData(oldp+1016,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.io_deq_bits),434);
        bufp->chgBit(oldp+1030,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__empty)))));
        bufp->chgBit(oldp+1031,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__monitor_output_REG));
        bufp->chgBit(oldp+1032,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1033,((0x3ffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U])) 
                                       << 0x22U) | 
                                      (((QData)((IData)(
                                                        vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                        [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][1U])) 
                                        << 2U) | ((QData)((IData)(
                                                                  vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][0U])) 
                                                  >> 0x1eU))))),42);
        bufp->chgWData(oldp+1035,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1038,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType),5);
        bufp->chgBit(oldp+1039,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1040,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__needs_ALU));
        bufp->chgCData(oldp+1041,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1042,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1043,((0x3ffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U])) 
                                       << 0x18U) | 
                                      ((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U])) 
                                       >> 8U)))),42);
        bufp->chgWData(oldp+1045,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1048,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType),5);
        bufp->chgBit(oldp+1049,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1050,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__needs_ALU));
        bufp->chgCData(oldp+1051,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1052,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1053,((0x3ffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U])) 
                                       << 0xeU) | ((QData)((IData)(
                                                                   vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U])) 
                                                   >> 0x12U)))),42);
        bufp->chgWData(oldp+1055,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1058,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType),5);
        bufp->chgBit(oldp+1059,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1060,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__needs_ALU));
        bufp->chgCData(oldp+1061,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1062,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1063,((0x3ffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][6U])) 
                                       << 0x24U) | 
                                      (((QData)((IData)(
                                                        vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                        [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][5U])) 
                                        << 4U) | ((QData)((IData)(
                                                                  vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U])) 
                                                  >> 0x1cU))))),42);
        bufp->chgWData(oldp+1065,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1068,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType),5);
        bufp->chgBit(oldp+1069,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1070,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__needs_ALU));
        bufp->chgCData(oldp+1071,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1072,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full)))));
        bufp->chgBit(oldp+1073,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_valid));
        bufp->chgBit(oldp+1074,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__BTB_Q__io_deq_ready));
        bufp->chgBit(oldp+1075,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___BTB_Q_io_deq_valid));
        bufp->chgCData(oldp+1076,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value))))),5);
        bufp->chgBit(oldp+1077,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T));
        bufp->chgBit(oldp+1078,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_enq));
        bufp->chgBit(oldp+1079,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_deq));
        bufp->chgQData(oldp+1080,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT___ram_ext_R0_data),53);
        bufp->chgCData(oldp+1082,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1083,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1084,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1085,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1086,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty));
        bufp->chgBit(oldp+1087,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full));
        bufp->chgCData(oldp+1088,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value)))),4);
        bufp->chgQData(oldp+1089,((0x1fffffffffffffULL 
                                   & (- (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_enq))))),53);
        bufp->chgQData(oldp+1091,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[0]),53);
        bufp->chgQData(oldp+1093,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[1]),53);
        bufp->chgQData(oldp+1095,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[2]),53);
        bufp->chgQData(oldp+1097,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[3]),53);
        bufp->chgQData(oldp+1099,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[4]),53);
        bufp->chgQData(oldp+1101,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[5]),53);
        bufp->chgQData(oldp+1103,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[6]),53);
        bufp->chgQData(oldp+1105,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[7]),53);
        bufp->chgQData(oldp+1107,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[8]),53);
        bufp->chgQData(oldp+1109,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[9]),53);
        bufp->chgQData(oldp+1111,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[10]),53);
        bufp->chgQData(oldp+1113,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[11]),53);
        bufp->chgQData(oldp+1115,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[12]),53);
        bufp->chgQData(oldp+1117,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[13]),53);
        bufp->chgQData(oldp+1119,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[14]),53);
        bufp->chgQData(oldp+1121,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[15]),53);
        bufp->chgBit(oldp+1123,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full)))));
        bufp->chgBit(oldp+1124,((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T)) 
                                       & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full))))));
        bufp->chgCData(oldp+1125,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value))))),5);
        bufp->chgBit(oldp+1126,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_104[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_104[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_104[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
        } else {
            __Vtemp_104[0U] = 0U;
            __Vtemp_104[1U] = 0U;
            __Vtemp_104[2U] = 0U;
        }
        bufp->chgWData(oldp+1127,(__Vtemp_104),65);
        bufp->chgCData(oldp+1130,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1131,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1132,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1133,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1134,(((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))));
        bufp->chgBit(oldp+1135,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full));
        __Vtemp_107[0U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq)));
        __Vtemp_107[1U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq)));
        __Vtemp_107[2U] = (1U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq))));
        bufp->chgWData(oldp+1136,(__Vtemp_107),65);
        bufp->chgWData(oldp+1139,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[0]),65);
        bufp->chgWData(oldp+1142,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[1]),65);
        bufp->chgWData(oldp+1145,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[2]),65);
        bufp->chgWData(oldp+1148,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[3]),65);
        bufp->chgWData(oldp+1151,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[4]),65);
        bufp->chgWData(oldp+1154,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[5]),65);
        bufp->chgWData(oldp+1157,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[6]),65);
        bufp->chgWData(oldp+1160,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[7]),65);
        bufp->chgWData(oldp+1163,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[8]),65);
        bufp->chgWData(oldp+1166,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[9]),65);
        bufp->chgWData(oldp+1169,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[10]),65);
        bufp->chgWData(oldp+1172,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[11]),65);
        bufp->chgWData(oldp+1175,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[12]),65);
        bufp->chgWData(oldp+1178,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[13]),65);
        bufp->chgWData(oldp+1181,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[14]),65);
        bufp->chgWData(oldp+1184,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[15]),65);
        bufp->chgQData(oldp+1187,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT)) 
                                    << 0x27U) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS)) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out))))),46);
        bufp->chgBit(oldp+1189,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T)))));
        bufp->chgIData(oldp+1190,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_reg),32);
        bufp->chgIData(oldp+1191,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__flush_PC_reg),32);
        bufp->chgBit(oldp+1192,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__REG));
        bufp->chgBit(oldp+1193,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__bp__io_predict_valid));
        bufp->chgBit(oldp+1194,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_valid_REG));
        bufp->chgBit(oldp+1195,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_hit_REG) 
                                  == (0x3ffffU & (IData)(
                                                         (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out 
                                                          >> 0x25U)))) 
                                 & ((IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out 
                                             >> 0x37U)) 
                                    & ((3U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out)) 
                                       >= (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__access_fetch_packet_index))))));
        bufp->chgQData(oldp+1196,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_output_BTB_valid_REG)) 
                                    << 0x37U) | (0x7fffffffffffffULL 
                                                 & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out))),56);
        __Vtemp_108[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[0U];
        __Vtemp_108[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[1U];
        __Vtemp_108[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[2U];
        __Vtemp_108[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[3U];
        __Vtemp_108[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[4U];
        __Vtemp_108[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT___GEN_3) 
                            << 8U) | vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[5U]);
        bufp->chgWData(oldp+1198,(__Vtemp_108),169);
        bufp->chgCData(oldp+1204,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__access_fetch_packet_index),3);
        bufp->chgSData(oldp+1205,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_hit_REG),16);
        bufp->chgBit(oldp+1206,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_output_BTB_valid_REG));
        bufp->chgQData(oldp+1207,((0x80000000000000ULL 
                                   | (((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_104)) 
                                       << 0x25U) | 
                                      (((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_48)) 
                                        << 5U) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_46) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_47)))))))),56);
        bufp->chgQData(oldp+1209,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out),56);
        bufp->chgSData(oldp+1211,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT____Vcellinp__BTB_memory__io_wr_addr),12);
        bufp->chgBit(oldp+1212,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT___GEN_3));
        bufp->chgQData(oldp+1213,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0ULL)),56);
        bufp->chgBit(oldp+1215,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__hazard_reg));
        bufp->chgQData(oldp+1216,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff),56);
        bufp->chgQData(oldp+1218,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT____Vcellinp__mem_ext__W0_data),56);
        bufp->chgQData(oldp+1220,((0xffffffffffffffULL 
                                   & (- (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT___GEN_3))))),56);
        bufp->chgCData(oldp+1222,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_revert_NEXT),7);
        bufp->chgCData(oldp+1223,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_revert_TOS),7);
        bufp->chgBit(oldp+1224,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_revert_valid));
        bufp->chgIData(oldp+1225,((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out)),32);
        bufp->chgCData(oldp+1226,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT),7);
        bufp->chgCData(oldp+1227,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS),7);
        bufp->chgCData(oldp+1228,((0x7fU & (IData)(
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out 
                                                    >> 0x20U)))),7);
        bufp->chgQData(oldp+1229,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out),39);
        bufp->chgBit(oldp+1231,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__hazard_reg));
        bufp->chgQData(oldp+1232,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__din_buff),39);
        bufp->chgQData(oldp+1234,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0ULL)),39);
        bufp->chgBit(oldp+1236,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0) 
                                 & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0] 
                                    >> 1U))));
        bufp->chgBit(oldp+1237,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__io_valid_REG));
        bufp->chgWData(oldp+1238,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___GEN_0),169);
        bufp->chgSData(oldp+1244,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__hashed_commit_addr),16);
        bufp->chgSData(oldp+1245,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT_io_addrC_REG),16);
        bufp->chgBit(oldp+1246,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT_io_writeEnableC_REG));
        bufp->chgBit(oldp+1247,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__REG));
        bufp->chgSData(oldp+1248,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0]
                                    : 0U)),16);
        bufp->chgSData(oldp+1249,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data),16);
        bufp->chgCData(oldp+1250,((3U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__REG)
                                          ? ((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data))
                                              ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data)
                                              : ((IData)(1U) 
                                                 + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data)))
                                          : ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data) 
                                             - ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R0_en_d0) 
                                                & (0U 
                                                   != 
                                                   vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R0_addr_d0])))))),2);
        bufp->chgCData(oldp+1251,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data),2);
        bufp->chgCData(oldp+1252,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0]
                                    : 0U)),2);
        bufp->chgBit(oldp+1253,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__full)))));
        bufp->chgBit(oldp+1254,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__full));
        bufp->chgQData(oldp+1255,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__ram),53);
        bufp->chgBit(oldp+1257,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__do_enq));
        bufp->chgBit(oldp+1258,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__io_fetch_packet_ready_REG));
        bufp->chgBit(oldp+1259,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_valid));
        __Vtemp_109[0U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11)))))) 
                            << 0x1eU) | ((0x3fffc000U 
                                          & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                               ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_13)
                                               : ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                   ? 
                                                  ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                    << 0x12U) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                      >> 0xeU))
                                                   : 0U)) 
                                             << 0xeU)) 
                                         | ((0x3f80U 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                                  ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_14)
                                                  : 
                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                   ? 
                                                  ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                    << 0x19U) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                      [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                      >> 7U))
                                                   : 0U)) 
                                                << 7U)) 
                                            | (0x7fU 
                                               & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                                   ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_ha38ca812_0_15)
                                                   : 
                                                  ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                    ? 
                                                   vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U]
                                                    : 0U))))));
        __Vtemp_114[0U] = __Vtemp_109[0U];
        __Vtemp_114[1U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11)))))) 
                            >> 2U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                                 << 0xaU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11))))) 
                                               >> 0x20U)) 
                                      << 0x1eU));
        __Vtemp_114[2U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_12)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_13) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_14)))))) 
                            << 8U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_9)) 
                                                 << 0xaU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_10) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_11))))) 
                                               >> 0x20U)) 
                                      >> 2U));
        __Vtemp_114[3U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_15)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_16) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_17)))))) 
                            << 0x12U) | (((IData)((
                                                   ((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_12)) 
                                                    << 0xaU) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_13) 
                                                                       << 6U) 
                                                                      | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_14)))))) 
                                          >> 0x18U) 
                                         | ((IData)(
                                                    ((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_12)) 
                                                       << 0xaU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_13) 
                                                                          << 6U) 
                                                                         | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_14))))) 
                                                     >> 0x20U)) 
                                            << 8U)));
        __Vtemp_114[4U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20)))))) 
                            << 0x1cU) | (((IData)((
                                                   ((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_15)) 
                                                    << 0xaU) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_16) 
                                                                       << 6U) 
                                                                      | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_17)))))) 
                                          >> 0xeU) 
                                         | ((IData)(
                                                    ((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_15)) 
                                                       << 0xaU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_16) 
                                                                          << 6U) 
                                                                         | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_17))))) 
                                                     >> 0x20U)) 
                                            << 0x12U)));
        __Vtemp_114[5U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20)))))) 
                            >> 4U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                                 << 0xaU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20))))) 
                                               >> 0x20U)) 
                                      << 0x1cU));
        __Vtemp_114[6U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_0 
                            << 0xaU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_1) 
                                         << 6U) | ((IData)(
                                                           ((((QData)((IData)(vlSelf->__VdfgRegularize_h6171c202_4_18)) 
                                                              << 0xaU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_19) 
                                                                                << 6U) 
                                                                                | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_20))))) 
                                                            >> 0x20U)) 
                                                   >> 4U)));
        __Vtemp_114[7U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_0 
                           >> 0x16U);
        bufp->chgWData(oldp+1260,(__Vtemp_114),234);
        bufp->chgCData(oldp+1268,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value))))),5);
        bufp->chgBit(oldp+1269,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq));
        bufp->chgBit(oldp+1270,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_deq));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_115[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_115[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_115[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_115[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_115[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_115[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_115[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_115[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][7U];
        } else {
            __Vtemp_115[0U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[0U];
            __Vtemp_115[1U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[1U];
            __Vtemp_115[2U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[2U];
            __Vtemp_115[3U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[3U];
            __Vtemp_115[4U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[4U];
            __Vtemp_115[5U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[5U];
            __Vtemp_115[6U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[6U];
            __Vtemp_115[7U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[7U];
        }
        bufp->chgWData(oldp+1271,(__Vtemp_115),234);
        bufp->chgCData(oldp+1279,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1280,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1281,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1282,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1283,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty));
        bufp->chgBit(oldp+1284,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full))));
        bufp->chgCData(oldp+1285,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value)))),4);
        bufp->chgWData(oldp+1286,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____Vcellinp__ram_ext__W0_data),234);
        __Vtemp_117[0U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[1U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[2U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[3U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[4U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[5U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[6U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_117[7U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        bufp->chgWData(oldp+1294,(__Vtemp_117),234);
        bufp->chgWData(oldp+1302,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[0]),234);
        bufp->chgWData(oldp+1310,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[1]),234);
        bufp->chgWData(oldp+1318,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[2]),234);
        bufp->chgWData(oldp+1326,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[3]),234);
        bufp->chgWData(oldp+1334,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[4]),234);
        bufp->chgWData(oldp+1342,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[5]),234);
        bufp->chgWData(oldp+1350,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[6]),234);
        bufp->chgWData(oldp+1358,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[7]),234);
        bufp->chgWData(oldp+1366,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[8]),234);
        bufp->chgWData(oldp+1374,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[9]),234);
        bufp->chgWData(oldp+1382,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[10]),234);
        bufp->chgWData(oldp+1390,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[11]),234);
        bufp->chgWData(oldp+1398,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[12]),234);
        bufp->chgWData(oldp+1406,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[13]),234);
        bufp->chgWData(oldp+1414,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[14]),234);
        bufp->chgWData(oldp+1422,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[15]),234);
        bufp->chgBit(oldp+1430,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__io_prediction_ready_REG));
        bufp->chgCData(oldp+1431,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_control),4);
        bufp->chgBit(oldp+1432,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL));
        bufp->chgBit(oldp+1433,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR));
        bufp->chgBit(oldp+1434,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH));
        bufp->chgBit(oldp+1435,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_1));
        bufp->chgBit(oldp+1436,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_1));
        bufp->chgBit(oldp+1437,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_1));
        bufp->chgBit(oldp+1438,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_2));
        bufp->chgBit(oldp+1439,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_2));
        bufp->chgBit(oldp+1440,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_2));
        bufp->chgBit(oldp+1441,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_3));
        bufp->chgBit(oldp+1442,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_3));
        bufp->chgBit(oldp+1443,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_3));
        bufp->chgIData(oldp+1444,((0xfffffff0U & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_hc521a72f_0_0)),32);
        bufp->chgIData(oldp+1445,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__expected_next_PC),32);
        bufp->chgBit(oldp+1446,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__output_ready));
        bufp->chgBit(oldp+1447,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid));
        bufp->chgSData(oldp+1448,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__GHR),16);
        bufp->chgBit(oldp+1449,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__full)))));
        bufp->chgCData(oldp+1450,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap) 
                                               - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1))))),2);
        bufp->chgBit(oldp+1451,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap));
        bufp->chgBit(oldp+1452,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+1453,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1454,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1455,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__empty));
        bufp->chgBit(oldp+1456,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__full));
        bufp->chgBit(oldp+1457,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq));
        __Vtemp_119[0U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[1U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[2U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[3U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[4U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[5U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[6U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_119[7U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        bufp->chgWData(oldp+1458,(__Vtemp_119),234);
        bufp->chgWData(oldp+1466,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[0]),234);
        bufp->chgWData(oldp+1474,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[1]),234);
        bufp->chgBit(oldp+1482,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+1483,((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__full)) 
                                       & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__empty))))));
        bufp->chgBit(oldp+1484,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__io_decoded_fetch_packet_ready_REG));
        bufp->chgBit(oldp+1485,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__empty)))));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_120[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_120[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_120[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_120[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_120[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_120[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_120[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_120[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][7U];
            __Vtemp_120[8U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U];
            __Vtemp_120[9U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U];
            __Vtemp_120[0xaU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xaU];
            __Vtemp_120[0xbU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU];
            __Vtemp_120[0xcU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU];
            __Vtemp_120[0xdU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU];
        } else {
            __Vtemp_120[0U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0U];
            __Vtemp_120[1U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[1U];
            __Vtemp_120[2U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[2U];
            __Vtemp_120[3U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[3U];
            __Vtemp_120[4U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[4U];
            __Vtemp_120[5U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[5U];
            __Vtemp_120[6U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[6U];
            __Vtemp_120[7U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[7U];
            __Vtemp_120[8U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[8U];
            __Vtemp_120[9U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[9U];
            __Vtemp_120[0xaU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xaU];
            __Vtemp_120[0xbU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xbU];
            __Vtemp_120[0xcU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xcU];
            __Vtemp_120[0xdU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xdU];
        }
        bufp->chgWData(oldp+1486,(__Vtemp_120),434);
        bufp->chgCData(oldp+1500,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value))))),5);
        bufp->chgCData(oldp+1501,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1502,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1503,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__maybe_full));
        bufp->chgBit(oldp+1504,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ptr_match));
        bufp->chgBit(oldp+1505,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__empty));
        bufp->chgBit(oldp+1506,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__full));
        bufp->chgBit(oldp+1507,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq));
        bufp->chgBit(oldp+1508,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq));
        bufp->chgCData(oldp+1509,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value)))),4);
        bufp->chgWData(oldp+1510,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT____Vcellinp__ram_ext__W0_data),434);
        __Vtemp_122[0U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[1U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[2U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[3U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[4U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[5U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[6U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[7U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[8U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[8U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[9U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[9U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[0xaU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xaU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[0xbU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xbU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[0xcU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xcU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_122[0xdU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xdU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        bufp->chgWData(oldp+1524,(__Vtemp_122),434);
        bufp->chgWData(oldp+1538,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[0]),434);
        bufp->chgWData(oldp+1552,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[1]),434);
        bufp->chgWData(oldp+1566,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[2]),434);
        bufp->chgWData(oldp+1580,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[3]),434);
        bufp->chgWData(oldp+1594,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[4]),434);
        bufp->chgWData(oldp+1608,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[5]),434);
        bufp->chgWData(oldp+1622,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[6]),434);
        bufp->chgWData(oldp+1636,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[7]),434);
        bufp->chgWData(oldp+1650,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[8]),434);
        bufp->chgWData(oldp+1664,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[9]),434);
        bufp->chgWData(oldp+1678,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[10]),434);
        bufp->chgWData(oldp+1692,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[11]),434);
        bufp->chgWData(oldp+1706,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[12]),434);
        bufp->chgWData(oldp+1720,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[13]),434);
        bufp->chgWData(oldp+1734,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[14]),434);
        bufp->chgWData(oldp+1748,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[15]),434);
        bufp->chgCData(oldp+1762,(((2U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                           (3U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                                  >> 1U))] 
                                           >> (0x1fU 
                                               & ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                                   << 4U) 
                                                  | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU] 
                                                     >> 0x1cU)))) 
                                          << 1U)) | 
                                   (1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                          (3U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU] 
                                                 >> 0x19U))] 
                                          >> (0x1fU 
                                              & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU] 
                                                 >> 0x14U)))))),2);
        bufp->chgCData(oldp+1763,(((2U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                           (3U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                  >> 7U))] 
                                           >> (0x1fU 
                                               & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                  >> 2U))) 
                                          << 1U)) | 
                                   (1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                          (3U & ((0x7fffffeU 
                                                  & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U] 
                                                     << 1U)) 
                                                 | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U] 
                                                    >> 0x1fU)))] 
                                          >> (0x1fU 
                                              & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U] 
                                                 >> 0x1aU)))))),2);
        bufp->chgCData(oldp+1764,(((2U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                           (3U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                                  >> 0xdU))] 
                                           >> (0x1fU 
                                               & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                                  >> 8U))) 
                                          << 1U)) | 
                                   (1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
                                          (3U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U] 
                                                 >> 5U))] 
                                          >> (0x1fU 
                                              & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U]))))),2);
        bufp->chgCData(oldp+1765,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__initialReady),2);
        bufp->chgWData(oldp+1766,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__ready_memory),65);
        bufp->chgIData(oldp+1769,((((IData)(vlSelf->__VdfgRegularize_h6171c202_4_102) 
                                    << 0xfU) | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_101) 
                                                 << 0xaU) 
                                                | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_100) 
                                                    << 5U) 
                                                   | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99))))),20);
        bufp->chgIData(oldp+1770,((((IData)(vlSelf->__VdfgRegularize_h6171c202_4_98) 
                                    << 0xfU) | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_97) 
                                                 << 0xaU) 
                                                | (((IData)(vlSelf->__VdfgRegularize_h6171c202_4_96) 
                                                    << 5U) 
                                                   | (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95))))),20);
        bufp->chgIData(oldp+1771,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_RD_values),20);
        bufp->chgCData(oldp+1772,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_wr_en),4);
        bufp->chgIData(oldp+1773,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values),28);
        bufp->chgIData(oldp+1774,(((((0xdfU >= (0xffU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_3))))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_3))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_3)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_3)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_3)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_3))))))
                                      : 0U) << 0x15U) 
                                   | ((((0xdfU >= (0xffU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_2))))
                                         ? (0x7fU & 
                                            (((0U == 
                                               (0x1fU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_2))))
                                               ? 0U
                                               : (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_2)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_2)))))) 
                                             | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                (7U 
                                                 & (((IData)(7U) 
                                                     * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_2)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_2))))))
                                         : 0U) << 0xeU) 
                                      | ((((0xdfU >= 
                                            (0xffU 
                                             & ((IData)(7U) 
                                                * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_6))))
                                            ? (0x7fU 
                                               & (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_6))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_6)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_6)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_6)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_6))))))
                                            : 0U) << 7U) 
                                         | ((0xdfU 
                                             >= (0xffU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_8))))
                                             ? (0x7fU 
                                                & (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_8))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_8)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_8)))))) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_8)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_ha86dd9af_0_8))))))
                                             : 0U))))),28);
        bufp->chgIData(oldp+1775,(((((0xdfU >= (0xffU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_102))))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_102))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_102)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_102)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_102)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_102))))))
                                      : 0U) << 0x15U) 
                                   | ((((0xdfU >= (0xffU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_101))))
                                         ? (0x7fU & 
                                            (((0U == 
                                               (0x1fU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_101))))
                                               ? 0U
                                               : (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_101)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_101)))))) 
                                             | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                (7U 
                                                 & (((IData)(7U) 
                                                     * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_101)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_101))))))
                                         : 0U) << 0xeU) 
                                      | ((((0xdfU >= 
                                            (0xffU 
                                             & ((IData)(7U) 
                                                * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_100))))
                                            ? (0x7fU 
                                               & (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_100))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_100)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_100)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_100)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_100))))))
                                            : 0U) << 7U) 
                                         | ((0xdfU 
                                             >= (0xffU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99))))
                                             ? (0x7fU 
                                                & (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99)))))) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_99))))))
                                             : 0U))))),28);
        bufp->chgIData(oldp+1776,(((((0xdfU >= (0xffU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_98))))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_98))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_98)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_98)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_98)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_98))))))
                                      : 0U) << 0x15U) 
                                   | ((((0xdfU >= (0xffU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_97))))
                                         ? (0x7fU & 
                                            (((0U == 
                                               (0x1fU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_97))))
                                               ? 0U
                                               : (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_97)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_97)))))) 
                                             | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                (7U 
                                                 & (((IData)(7U) 
                                                     * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_97)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_97))))))
                                         : 0U) << 0xeU) 
                                      | ((((0xdfU >= 
                                            (0xffU 
                                             & ((IData)(7U) 
                                                * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_96))))
                                            ? (0x7fU 
                                               & (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_96))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_96)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_96)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_96)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_96))))))
                                            : 0U) << 7U) 
                                         | ((0xdfU 
                                             >= (0xffU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95))))
                                             ? (0x7fU 
                                                & (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95)))))) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_h6171c202_4_95))))))
                                             : 0U))))),28);
        bufp->chgWData(oldp+1777,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__commit_RAT),224);
        bufp->chgWData(oldp+1784,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT),224);
        bufp->chgCData(oldp+1791,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____Vcellinp__WAW_handler__io_decoder_RD_valid_bits),4);
        bufp->chgCData(oldp+1792,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid),4);
        bufp->chgCData(oldp+1793,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT___GEN_4),4);
        bufp->chgCData(oldp+1794,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer),7);
        bufp->chgBit(oldp+1795,((0x41U > (0x7fU & ((IData)(4U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets))))));
        bufp->chgBit(oldp+1796,((0U != (0x1fU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets) 
                                                 >> 2U)))));
        bufp->chgCData(oldp+1797,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__back_pointer),7);
        bufp->chgCData(oldp+1798,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer))),6);
        bufp->chgCData(oldp+1799,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__back_pointer))),6);
        bufp->chgCData(oldp+1800,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__allocate_valid),4);
        bufp->chgCData(oldp+1801,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets),7);
        bufp->chgWData(oldp+1802,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__valid_commit_ptr),448);
        bufp->chgQData(oldp+1816,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__valid_commit_valid),64);
        bufp->chgBit(oldp+1818,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg));
        bufp->chgBit(oldp+1819,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__unnamedblk1__DOT__outputs_ready));
        bufp->chgIData(oldp+1820,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en),32);
        bufp->chgCData(oldp+1821,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[0U] 
                                         >> 4U))),2);
        bufp->chgCData(oldp+1822,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[0U] 
                                         >> 6U))),2);
        bufp->chgCData(oldp+1823,((0x3fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[1U] 
                                            >> 0xdU))),6);
        bufp->chgIData(oldp+1824,(((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[2U] 
                                    << 0x18U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[1U] 
                                                 >> 8U))),32);
        bufp->chgCData(oldp+1825,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE),2);
        bufp->chgCData(oldp+1826,((0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                            >> 0x12U))),5);
        bufp->chgCData(oldp+1827,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                         >> 5U))),2);
        __Vtemp_146[0U] = (IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
                                    << 0x38U) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut)) 
                                                  << 0x30U) 
                                                 | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut)) 
                                                     << 0x28U) 
                                                    | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut)) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut) 
                                                                           << 0x18U) 
                                                                          | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut) 
                                                                              << 0x10U) 
                                                                             | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut)))))))))));
        __Vtemp_146[1U] = (IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
                                     << 0x38U) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut)) 
                                                   << 0x30U) 
                                                  | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut)) 
                                                      << 0x28U) 
                                                     | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut) 
                                                                            << 0x18U) 
                                                                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut) 
                                                                               << 0x10U) 
                                                                              | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut)))))))))) 
                                   >> 0x20U));
        __Vtemp_146[2U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__dataOut))));
        __Vtemp_146[3U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__dataOut))));
        __Vtemp_146[4U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__dataOut))));
        __Vtemp_146[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__dataOut))));
        __Vtemp_146[6U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__dataOut))));
        __Vtemp_146[7U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__dataOut))));
        bufp->chgWData(oldp+1828,(__Vtemp_146),256);
        bufp->chgWData(oldp+1836,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_AW_DATA_BUFFER),256);
        bufp->chgCData(oldp+1844,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE),2);
        bufp->chgIData(oldp+1845,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_counter),32);
        bufp->chgWData(oldp+1846,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_read_buffer),256);
        bufp->chgCData(oldp+1854,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE),2);
        bufp->chgIData(oldp+1855,(((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[2U] 
                                        << 0x18U) | 
                                       (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[1U] 
                                        >> 8U)) : 0U)),32);
        bufp->chgCData(oldp+1856,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_set),6);
        bufp->chgCData(oldp+1857,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_access_width),2);
        bufp->chgBit(oldp+1858,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__valid_hit_REG));
        bufp->chgBit(oldp+1859,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__valid_miss_REG));
        bufp->chgBit(oldp+1860,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__valid_write_hit_REG));
        bufp->chgCData(oldp+1861,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__hit_set_REG),6);
        bufp->chgCData(oldp+1862,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__hit_MOB_index_REG),4);
        bufp->chgIData(oldp+1863,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__miss_address_REG),32);
        bufp->chgCData(oldp+1864,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__miss_set_REG),6);
        bufp->chgIData(oldp+1865,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_write_data_REG),32);
        bufp->chgIData(oldp+1866,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r),32);
        bufp->chgIData(oldp+1867,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r_1),32);
        bufp->chgBit(oldp+1868,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid));
        bufp->chgBit(oldp+1869,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid));
        bufp->chgCData(oldp+1870,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_0_REG),5);
        bufp->chgCData(oldp+1871,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_1_REG),5);
        bufp->chgCData(oldp+1872,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_2_REG),5);
        bufp->chgCData(oldp+1873,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_3_REG),5);
        bufp->chgWData(oldp+1874,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__MSHRs),2460);
        bufp->chgCData(oldp+1951,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__MSHR_front_pointer),3);
        bufp->chgBit(oldp+1952,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__output_valid_r));
        bufp->chgBit(oldp+1953,((1U & (~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full))))));
        __Vtemp_147[0U] = (IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__dataOut)) 
                                    << 0x2aU) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__dataOut)) 
                                                  << 0x15U) 
                                                 | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__dataOut)))));
        __Vtemp_147[1U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__dataOut 
                            << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__dataOut)) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__dataOut)) 
                                                      << 0x15U) 
                                                     | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__dataOut)))) 
                                                 >> 0x20U)));
        __Vtemp_147[2U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__dataOut 
                           >> 1U);
        __Vtemp_172[2U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
                                      << 0x38U) | (
                                                   ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut)) 
                                                    << 0x30U) 
                                                   | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut)) 
                                                       << 0x28U) 
                                                      | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut)) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut))))))))))) 
                            >> 0x11U) | ((IData)(((
                                                   ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
                                                    << 0x38U) 
                                                   | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut)) 
                                                       << 0x30U) 
                                                      | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut)) 
                                                          << 0x28U) 
                                                         | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut)) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut) 
                                                                                << 0x18U) 
                                                                               | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut)))))))))) 
                                                  >> 0x20U)) 
                                         << 0xfU));
        __Vtemp_174[9U] = ((((0x53U >= (0x7fU & ((IData)(0x15U) 
                                                 * 
                                                 ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                   ? 
                                                  (2U 
                                                   & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                      << 1U))
                                                   : 1U))))
                              ? (0x1fffffU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(0x15U) 
                                                    * 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                      ? 
                                                     (2U 
                                                      & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                         << 1U))
                                                      : 1U))))
                                                ? 0U
                                                : (
                                                   __Vtemp_147[
                                                   (((IData)(0x14U) 
                                                     + 
                                                     (0x7fU 
                                                      & ((IData)(0x15U) 
                                                         * 
                                                         ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                           ? 
                                                          (2U 
                                                           & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                              << 1U))
                                                           : 1U)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(0x15U) 
                                                        * 
                                                        ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                          ? 
                                                         (2U 
                                                          & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                             << 1U))
                                                          : 1U)))))) 
                                              | (__Vtemp_147[
                                                 (3U 
                                                  & (((IData)(0x15U) 
                                                      * 
                                                      ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                        ? 
                                                       (2U 
                                                        & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                           << 1U))
                                                        : 1U)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(0x15U) 
                                                     * 
                                                     ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                       ? 
                                                      (2U 
                                                       & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                          << 1U))
                                                       : 1U))))))
                              : 0U) << 0x14U) | ((0x7f80U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__dataOut) 
                                                     << 7U)) 
                                                 | ((0x7fffU 
                                                     & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__dataOut) 
                                                        >> 1U)) 
                                                    | ((0x7fffU 
                                                        & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__dataOut) 
                                                           >> 9U)) 
                                                       | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__dataOut) 
                                                          >> 0x11U)))));
        __Vtemp_174[0xaU] = (((0x53U >= (0x7fU & ((IData)(0x15U) 
                                                  * 
                                                  ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                    ? 
                                                   (2U 
                                                    & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                       << 1U))
                                                    : 1U))))
                               ? (0x1fffffU & (((0U 
                                                 == 
                                                 (0x1fU 
                                                  & ((IData)(0x15U) 
                                                     * 
                                                     ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                       ? 
                                                      (2U 
                                                       & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                          << 1U))
                                                       : 1U))))
                                                 ? 0U
                                                 : 
                                                (__Vtemp_147[
                                                 (((IData)(0x14U) 
                                                   + 
                                                   (0x7fU 
                                                    & ((IData)(0x15U) 
                                                       * 
                                                       ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                         ? 
                                                        (2U 
                                                         & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                            << 1U))
                                                         : 1U)))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x15U) 
                                                      * 
                                                      ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                        ? 
                                                       (2U 
                                                        & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                           << 1U))
                                                        : 1U)))))) 
                                               | (__Vtemp_147[
                                                  (3U 
                                                   & (((IData)(0x15U) 
                                                       * 
                                                       ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                         ? 
                                                        (2U 
                                                         & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                            << 1U))
                                                         : 1U)) 
                                                      >> 5U))] 
                                                  >> 
                                                  (0x1fU 
                                                   & ((IData)(0x15U) 
                                                      * 
                                                      ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_0_T)
                                                        ? 
                                                       (2U 
                                                        & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___tag_hit_OH_1_T)) 
                                                           << 1U))
                                                        : 1U))))))
                               : 0U) >> 0xcU);
        __Vtemp_175[0U] = (IData)((0x200000000020ULL 
                                   | ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r_1)) 
                                      << 7U)));
        __Vtemp_175[1U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
                                      << 0x38U) | (
                                                   ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut)) 
                                                    << 0x30U) 
                                                   | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut)) 
                                                       << 0x28U) 
                                                      | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut)) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut))))))))))) 
                            << 0xfU) | (IData)(((0x200000000020ULL 
                                                 | ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r_1)) 
                                                    << 7U)) 
                                                >> 0x20U)));
        __Vtemp_175[2U] = __Vtemp_172[2U];
        __Vtemp_175[3U] = (((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
                                       << 0x38U) | 
                                      (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut)) 
                                        << 0x30U) | 
                                       (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut)) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut) 
                                                               << 0x18U) 
                                                              | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut) 
                                                                  << 0x10U) 
                                                                 | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut) 
                                                                     << 8U) 
                                                                    | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut)))))))))) 
                                     >> 0x20U)) >> 0x11U) 
                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__dataOut) 
                               << 0x1fU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__dataOut) 
                                             << 0x17U) 
                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__dataOut) 
                                               << 0xfU))));
        __Vtemp_175[4U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__dataOut) 
                                        << 7U)) | (
                                                   (0x7fffU 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__dataOut) 
                                                       >> 1U)) 
                                                   | ((0x7fffU 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__dataOut) 
                                                          >> 9U)) 
                                                      | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__dataOut) 
                                                         >> 0x11U)))) 
                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__dataOut) 
                               << 0x1fU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__dataOut) 
                                             << 0x17U) 
                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__dataOut) 
                                               << 0xfU))));
        __Vtemp_175[5U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__dataOut) 
                                        << 7U)) | (
                                                   (0x7fffU 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__dataOut) 
                                                       >> 1U)) 
                                                   | ((0x7fffU 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__dataOut) 
                                                          >> 9U)) 
                                                      | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__dataOut) 
                                                         >> 0x11U)))) 
                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__dataOut) 
                               << 0x1fU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__dataOut) 
                                             << 0x17U) 
                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__dataOut) 
                                               << 0xfU))));
        __Vtemp_175[6U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__dataOut) 
                                        << 7U)) | (
                                                   (0x7fffU 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__dataOut) 
                                                       >> 1U)) 
                                                   | ((0x7fffU 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__dataOut) 
                                                          >> 9U)) 
                                                      | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__dataOut) 
                                                         >> 0x11U)))) 
                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__dataOut) 
                               << 0x1fU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__dataOut) 
                                             << 0x17U) 
                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__dataOut) 
                                               << 0xfU))));
        __Vtemp_175[7U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__dataOut) 
                                        << 7U)) | (
                                                   (0x7fffU 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__dataOut) 
                                                       >> 1U)) 
                                                   | ((0x7fffU 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__dataOut) 
                                                          >> 9U)) 
                                                      | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__dataOut) 
                                                         >> 0x11U)))) 
                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__dataOut) 
                               << 0x1fU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__dataOut) 
                                             << 0x17U) 
                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__dataOut) 
                                               << 0xfU))));
        __Vtemp_175[8U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__dataOut) 
                                        << 7U)) | (
                                                   (0x7fffU 
                                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__dataOut) 
                                                       >> 1U)) 
                                                   | ((0x7fffU 
                                                       & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__dataOut) 
                                                          >> 9U)) 
                                                      | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__dataOut) 
                                                         >> 0x11U)))) 
                           | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__dataOut) 
                               << 0x1fU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__dataOut) 
                                             << 0x17U) 
                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__dataOut) 
                                               << 0xfU))));
        __Vtemp_175[9U] = __Vtemp_174[9U];
        __Vtemp_175[0xaU] = __Vtemp_174[0xaU];
        bufp->chgWData(oldp+1954,(__Vtemp_175),336);
        bufp->chgBit(oldp+1965,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__empty)))));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_176[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_176[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_176[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_176[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_176[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_176[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_176[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_176[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][7U];
            __Vtemp_176[8U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][8U];
            __Vtemp_176[9U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U];
            __Vtemp_176[0xaU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU];
        } else {
            __Vtemp_176[0U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[0U];
            __Vtemp_176[1U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[1U];
            __Vtemp_176[2U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[2U];
            __Vtemp_176[3U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[3U];
            __Vtemp_176[4U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[4U];
            __Vtemp_176[5U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[5U];
            __Vtemp_176[6U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[6U];
            __Vtemp_176[7U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[7U];
            __Vtemp_176[8U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[8U];
            __Vtemp_176[9U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[9U];
            __Vtemp_176[0xaU] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[0xaU];
        }
        bufp->chgWData(oldp+1966,(__Vtemp_176),336);
        bufp->chgCData(oldp+1977,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match)) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__enq_ptr_value) 
                                               - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value))))),3);
        bufp->chgCData(oldp+1978,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__enq_ptr_value),2);
        bufp->chgCData(oldp+1979,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value),2);
        bufp->chgBit(oldp+1980,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1981,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1982,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__empty));
        bufp->chgBit(oldp+1983,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full))));
        bufp->chgCData(oldp+1984,((3U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__empty)
                                          ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value)
                                          : ((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value))
                                              ? 0U : 
                                             ((IData)(1U) 
                                              + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value)))))),2);
        bufp->chgBit(oldp+1985,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__full)))));
        bufp->chgBit(oldp+1986,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___final_response_buffer_io_deq_valid));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full) {
            __Vtemp_177[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[0U];
            __Vtemp_177[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[1U];
            __Vtemp_177[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[2U];
            __Vtemp_177[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[3U];
            __Vtemp_177[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[4U];
            __Vtemp_177[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[5U];
            __Vtemp_177[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[6U];
            __Vtemp_177[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[7U];
        } else {
            __Vtemp_177[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[0U];
            __Vtemp_177[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[1U];
            __Vtemp_177[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[2U];
            __Vtemp_177[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[3U];
            __Vtemp_177[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[4U];
            __Vtemp_177[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[5U];
            __Vtemp_177[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[6U];
            __Vtemp_177[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[7U];
        }
        bufp->chgWData(oldp+1987,(__Vtemp_177),256);
        bufp->chgBit(oldp+1995,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__full));
        bufp->chgWData(oldp+1996,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram),256);
        bufp->chgBit(oldp+2004,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__unnamedblk1__DOT__do_enq));
        bufp->chgBit(oldp+2005,((1U & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en)));
        bufp->chgCData(oldp+2006,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr),8);
        bufp->chgCData(oldp+2007,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2008,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut),8);
        bufp->chgCData(oldp+2009,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2010,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 1U))));
        bufp->chgCData(oldp+2011,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2012,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut),8);
        bufp->chgCData(oldp+2013,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2014,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2015,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2016,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__dataOut),8);
        bufp->chgCData(oldp+2017,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2018,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2019,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2020,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__dataOut),8);
        bufp->chgCData(oldp+2021,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2022,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xcU))));
        bufp->chgCData(oldp+2023,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2024,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__dataOut),8);
        bufp->chgCData(oldp+2025,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2026,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xdU))));
        bufp->chgCData(oldp+2027,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2028,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__dataOut),8);
        bufp->chgCData(oldp+2029,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2030,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xeU))));
        bufp->chgCData(oldp+2031,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2032,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__dataOut),8);
        bufp->chgCData(oldp+2033,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2034,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xfU))));
        bufp->chgCData(oldp+2035,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2036,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__dataOut),8);
        bufp->chgCData(oldp+2037,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2038,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x10U))));
        bufp->chgCData(oldp+2039,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2040,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__dataOut),8);
        bufp->chgCData(oldp+2041,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2042,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x11U))));
        bufp->chgCData(oldp+2043,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2044,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__dataOut),8);
        bufp->chgCData(oldp+2045,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2046,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x12U))));
        bufp->chgCData(oldp+2047,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2048,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__dataOut),8);
        bufp->chgCData(oldp+2049,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2050,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x13U))));
        bufp->chgCData(oldp+2051,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2052,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__dataOut),8);
        bufp->chgCData(oldp+2053,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2054,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 2U))));
        bufp->chgCData(oldp+2055,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2056,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut),8);
        bufp->chgCData(oldp+2057,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2058,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x14U))));
        bufp->chgCData(oldp+2059,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2060,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__dataOut),8);
        bufp->chgCData(oldp+2061,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2062,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x15U))));
        bufp->chgCData(oldp+2063,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2064,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__dataOut),8);
        bufp->chgCData(oldp+2065,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2066,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x16U))));
        bufp->chgCData(oldp+2067,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2068,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__dataOut),8);
        bufp->chgCData(oldp+2069,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2070,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x17U))));
        bufp->chgCData(oldp+2071,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2072,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__dataOut),8);
        bufp->chgCData(oldp+2073,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2074,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x18U))));
        bufp->chgCData(oldp+2075,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2076,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__dataOut),8);
        bufp->chgCData(oldp+2077,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2078,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x19U))));
        bufp->chgCData(oldp+2079,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2080,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__dataOut),8);
        bufp->chgCData(oldp+2081,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2082,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1aU))));
        bufp->chgCData(oldp+2083,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2084,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__dataOut),8);
        bufp->chgCData(oldp+2085,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2086,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1bU))));
        bufp->chgCData(oldp+2087,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2088,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__dataOut),8);
        bufp->chgCData(oldp+2089,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2090,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1cU))));
        bufp->chgCData(oldp+2091,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2092,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__dataOut),8);
        bufp->chgCData(oldp+2093,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2094,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1dU))));
        bufp->chgCData(oldp+2095,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2096,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__dataOut),8);
        bufp->chgCData(oldp+2097,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2098,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 3U))));
        bufp->chgCData(oldp+2099,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2100,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut),8);
        bufp->chgCData(oldp+2101,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2102,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1eU))));
        bufp->chgCData(oldp+2103,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2104,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__dataOut),8);
        bufp->chgCData(oldp+2105,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2106,((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+2107,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2108,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__dataOut),8);
        bufp->chgCData(oldp+2109,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2110,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 4U))));
        bufp->chgCData(oldp+2111,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2112,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut),8);
        bufp->chgCData(oldp+2113,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2114,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 5U))));
        bufp->chgCData(oldp+2115,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2116,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut),8);
        bufp->chgCData(oldp+2117,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2118,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 6U))));
        bufp->chgCData(oldp+2119,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2120,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut),8);
        bufp->chgCData(oldp+2121,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2122,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 7U))));
        bufp->chgCData(oldp+2123,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2124,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut),8);
        bufp->chgCData(oldp+2125,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2126,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 8U))));
        bufp->chgCData(oldp+2127,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2128,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__dataOut),8);
        bufp->chgCData(oldp+2129,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2130,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 9U))));
        bufp->chgCData(oldp+2131,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2132,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__dataOut),8);
        bufp->chgCData(oldp+2133,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2134,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full)))));
        bufp->chgBit(oldp+2135,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__final_response_buffer__io_enq_valid));
        bufp->chgWData(oldp+2136,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14),256);
        bufp->chgBit(oldp+2144,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full));
        bufp->chgWData(oldp+2145,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram),256);
        bufp->chgBit(oldp+2153,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__do_enq));
        bufp->chgBit(oldp+2154,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__full)))));
        bufp->chgIData(oldp+2155,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[0U]
                                    : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[0U])),32);
        bufp->chgBit(oldp+2156,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_26));
        bufp->chgBit(oldp+2157,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__full));
        bufp->chgBit(oldp+2158,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__unnamedblk1__DOT__do_enq));
        bufp->chgBit(oldp+2159,((IData)(((0U == (0x60U 
                                                 & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2160,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_0__io_addr),6);
        bufp->chgIData(oldp+2161,(((0U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2162,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__dataOut),21);
        bufp->chgIData(oldp+2163,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_0__io_addr]),21);
        bufp->chgBit(oldp+2164,((IData)(((0x20U == 
                                          (0x60U & 
                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2165,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_1__io_addr),6);
        bufp->chgIData(oldp+2166,(((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2167,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__dataOut),21);
        bufp->chgIData(oldp+2168,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_1__io_addr]),21);
        bufp->chgBit(oldp+2169,((IData)(((0x40U == 
                                          (0x60U & 
                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2170,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_2__io_addr),6);
        bufp->chgIData(oldp+2171,(((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2172,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__dataOut),21);
        bufp->chgIData(oldp+2173,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_2__io_addr]),21);
        bufp->chgBit(oldp+2174,((IData)(((0x60U == 
                                          (0x60U & 
                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2175,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_3__io_addr),6);
        bufp->chgIData(oldp+2176,(((3U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2177,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__dataOut),21);
        bufp->chgIData(oldp+2178,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_3__io_addr]),21);
        bufp->chgCData(oldp+2179,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__unnamedblk1__DOT__active_tag),5);
        bufp->chgBit(oldp+2180,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__miss));
        bufp->chgWData(oldp+2181,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_AW_DATA_BUFFER),256);
        bufp->chgCData(oldp+2189,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE),2);
        bufp->chgIData(oldp+2190,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__write_counter),32);
        bufp->chgWData(oldp+2191,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_read_buffer),256);
        bufp->chgCData(oldp+2199,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__cache_state),2);
        bufp->chgWData(oldp+2200,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__fetch_PC_buf),65);
        bufp->chgWData(oldp+2203,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address),65);
        bufp->chgIData(oldp+2206,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__current_packet),31);
        bufp->chgBit(oldp+2207,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__cache_valid));
        bufp->chgBit(oldp+2208,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__axi_response_valid));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____VdfgRegularize_h0bfca6b6_0_2) {
            __Vtemp_180[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[0U];
            __Vtemp_180[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[1U];
            __Vtemp_180[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[2U];
        } else {
            __Vtemp_180[0U] = 0U;
            __Vtemp_180[1U] = 0U;
            __Vtemp_180[2U] = 0U;
        }
        bufp->chgWData(oldp+2209,(__Vtemp_180),65);
        bufp->chgCData(oldp+2212,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory_io_wr_addr_REG),6);
        bufp->chgCData(oldp+2213,(((2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___LRU_memory_io_data_out))
                                    ? (1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___LRU_memory_io_data_out)))
                                    : 2U)),2);
        bufp->chgIData(oldp+2214,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_oh_vec_0_REG),21);
        bufp->chgIData(oldp+2215,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_oh_vec_1_REG),21);
        bufp->chgBit(oldp+2216,((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__cache_state))));
        bufp->chgBit(oldp+2217,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_REG_2));
        bufp->chgBit(oldp+2218,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit));
        bufp->chgBit(oldp+2219,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__miss_REG_2));
        bufp->chgWData(oldp+2220,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_instruction_data),256);
        bufp->chgBit(oldp+2228,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_0_instruction_REG));
        bufp->chgBit(oldp+2229,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_1_instruction_REG));
        bufp->chgBit(oldp+2230,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_2_instruction_REG));
        bufp->chgBit(oldp+2231,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_3_instruction_REG));
        bufp->chgWData(oldp+2232,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__current_data),278);
        bufp->chgBit(oldp+2241,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__full)))));
        bufp->chgBit(oldp+2242,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___CPU_response_valid_T));
        bufp->chgWData(oldp+2243,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_19),234);
        bufp->chgBit(oldp+2251,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__full));
        bufp->chgWData(oldp+2252,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__ram),234);
        bufp->chgBit(oldp+2260,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__do_enq));
        bufp->chgCData(oldp+2261,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__LRU_memory__io_rd_addr),6);
        bufp->chgCData(oldp+2262,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___LRU_memory_io_data_out),2);
        bufp->chgCData(oldp+2263,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__LRU_memory__io_data_in),2);
        bufp->chgBit(oldp+2264,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__hazard_reg));
        bufp->chgCData(oldp+2265,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__din_buff),2);
        bufp->chgCData(oldp+2266,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0U)),2);
        bufp->chgBit(oldp+2267,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full)))));
        bufp->chgBit(oldp+2268,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__final_response_buffer__io_enq_valid));
        bufp->chgWData(oldp+2269,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10),256);
        bufp->chgBit(oldp+2277,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_14));
        bufp->chgBit(oldp+2278,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___final_response_buffer_io_deq_valid));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full) {
            __Vtemp_181[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[0U];
            __Vtemp_181[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[1U];
            __Vtemp_181[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[2U];
            __Vtemp_181[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[3U];
            __Vtemp_181[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[4U];
            __Vtemp_181[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[5U];
            __Vtemp_181[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[6U];
            __Vtemp_181[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[7U];
        } else {
            __Vtemp_181[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[0U];
            __Vtemp_181[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[1U];
            __Vtemp_181[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[2U];
            __Vtemp_181[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[3U];
            __Vtemp_181[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[4U];
            __Vtemp_181[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[5U];
            __Vtemp_181[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[6U];
            __Vtemp_181[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_10[7U];
        }
        bufp->chgWData(oldp+2279,(__Vtemp_181),256);
        bufp->chgBit(oldp+2287,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full));
        bufp->chgWData(oldp+2288,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram),256);
        bufp->chgBit(oldp+2296,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__do_enq));
        bufp->chgCData(oldp+2297,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__fetch_PC_buf[1U] 
                                         >> 3U))),2);
        bufp->chgCData(oldp+2298,((0xfU & (0x137fU 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, 
                                                               (3U 
                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__fetch_PC_buf[1U] 
                                                                   >> 3U)), 2U))))),4);
        bufp->chgIData(oldp+2299,(((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                    : 0U)),32);
        bufp->chgCData(oldp+2300,((0xfU & (- (IData)(
                                                     (1U 
                                                      == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))))),4);
        bufp->chgBit(oldp+2301,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_3));
        bufp->chgCData(oldp+2302,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg),8);
        bufp->chgCData(oldp+2303,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg),2);
        bufp->chgCData(oldp+2304,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                                    ? 7U : 0U)),8);
        bufp->chgCData(oldp+2305,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                                    ? 5U : 0U)),3);
        bufp->chgCData(oldp+2306,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11),2);
        bufp->chgCData(oldp+2307,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg),8);
        bufp->chgIData(oldp+2308,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg),32);
        bufp->chgCData(oldp+2309,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg),2);
        bufp->chgBit(oldp+2310,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg));
        bufp->chgIData(oldp+2311,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                    ? ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                        ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                            << 0x11U) 
                                           | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                              >> 0xfU))
                                        : 0U) : 0U)),32);
        bufp->chgCData(oldp+2312,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5),8);
        bufp->chgCData(oldp+2313,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                    ? 5U : 0U)),3);
        bufp->chgCData(oldp+2314,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid),2);
        bufp->chgIData(oldp+2315,(((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                    : 0U)),32);
        bufp->chgCData(oldp+2316,((0xfU & (- (IData)(
                                                     (1U 
                                                      == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)))))),4);
        bufp->chgBit(oldp+2317,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_7));
        bufp->chgIData(oldp+2318,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                    ? ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                        ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                            << 0x19U) 
                                           | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                              >> 7U))
                                        : 0U) : 0U)),32);
        bufp->chgCData(oldp+2319,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                    ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_he49e9fcb_0_2)
                                    : 0U)),8);
        bufp->chgCData(oldp+2320,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                    ? 5U : 0U)),3);
        bufp->chgCData(oldp+2321,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid),2);
        bufp->chgIData(oldp+2322,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg),32);
        bufp->chgCData(oldp+2323,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg),8);
        bufp->chgCData(oldp+2324,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg),3);
        bufp->chgCData(oldp+2325,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg),2);
        bufp->chgBit(oldp+2326,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg));
        bufp->chgCData(oldp+2327,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg),4);
        bufp->chgCData(oldp+2328,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg),3);
        bufp->chgCData(oldp+2329,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg),4);
        bufp->chgCData(oldp+2330,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg),4);
        bufp->chgIData(oldp+2331,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg),32);
        bufp->chgCData(oldp+2332,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg),4);
        bufp->chgBit(oldp+2333,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg));
        bufp->chgCData(oldp+2334,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg),8);
        bufp->chgCData(oldp+2335,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg),8);
        bufp->chgIData(oldp+2336,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_reg),32);
        bufp->chgBit(oldp+2337,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_reg));
        bufp->chgQData(oldp+2338,(((QData)((IData)(
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                     ? 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                      ? 
                                                     ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                                       << 0x11U) 
                                                      | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                         >> 0xfU))
                                                      : 0U)
                                                     : 0U))) 
                                   << 0x20U)),64);
        bufp->chgSData(oldp+2340,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5) 
                                   << 8U)),16);
        bufp->chgCData(oldp+2341,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                     ? 5U : 0U) << 3U)),6);
        bufp->chgCData(oldp+2342,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid) 
                                   << 2U)),4);
        bufp->chgCData(oldp+2343,(((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AW_valid) 
                                   << 1U)),2);
        bufp->chgCData(oldp+2344,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg),2);
        bufp->chgQData(oldp+2345,((((QData)((IData)(
                                                    ((1U 
                                                      == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))
                                                      ? 
                                                     vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                                      : 0U))) 
                                    << 0x20U) | (QData)((IData)(
                                                                ((1U 
                                                                  == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))
                                                                  ? 
                                                                 vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                                                  : 0U))))),64);
        bufp->chgCData(oldp+2347,(((0xf0U & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)))) 
                                             << 4U)) 
                                   | (0xfU & (- (IData)(
                                                        (1U 
                                                         == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))))))),8);
        bufp->chgCData(oldp+2348,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_7) 
                                    << 1U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_3))),2);
        bufp->chgCData(oldp+2349,((((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)) 
                                    << 1U) | (1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))),2);
        bufp->chgCData(oldp+2350,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg),2);
        bufp->chgSData(oldp+2351,((0xffffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg) 
                                               << 8U) 
                                              | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg)))),16);
        bufp->chgCData(oldp+2352,((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg) 
                                            << 2U) 
                                           | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg)))),4);
        bufp->chgCData(oldp+2353,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg),2);
        bufp->chgCData(oldp+2354,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT____Vcellinp__axi_interconnect_inst__s_axi_bready),2);
        bufp->chgQData(oldp+2355,(((QData)((IData)(
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                     ? 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                      ? 
                                                     ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                       << 0x19U) 
                                                      | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                         [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                         >> 7U))
                                                      : 0U)
                                                     : 0U))) 
                                   << 0x20U)),64);
        bufp->chgSData(oldp+2357,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                      ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_he49e9fcb_0_2)
                                      : 0U) << 8U) 
                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                                       ? 7U : 0U))),16);
        bufp->chgCData(oldp+2358,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                      ? 5U : 0U) << 3U) 
                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                                       ? 5U : 0U))),6);
        bufp->chgCData(oldp+2359,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                    << 2U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11))),4);
        bufp->chgCData(oldp+2360,((((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AR_valid) 
                                    << 1U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_instruction_cache_AXI_port_AXI_AR_valid))),2);
        bufp->chgCData(oldp+2361,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg),2);
        bufp->chgSData(oldp+2362,((0xffffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg) 
                                               << 8U) 
                                              | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg)))),16);
        bufp->chgQData(oldp+2363,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)))),64);
        bufp->chgCData(oldp+2365,((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg) 
                                            << 2U) 
                                           | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg)))),4);
        bufp->chgCData(oldp+2366,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg))))),2);
        bufp->chgCData(oldp+2367,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_reg),2);
        bufp->chgCData(oldp+2368,((((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)) 
                                    << 1U) | (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))),2);
        bufp->chgQData(oldp+2369,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)))),64);
        bufp->chgSData(oldp+2371,((0xffffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                               << 8U) 
                                              | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg)))),16);
        bufp->chgCData(oldp+2372,((0x3fU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                             << 3U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg)))),6);
        bufp->chgCData(oldp+2373,((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                            << 2U) 
                                           | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg)))),4);
        bufp->chgCData(oldp+2374,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg))))),2);
        bufp->chgCData(oldp+2375,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg)))),8);
        bufp->chgCData(oldp+2376,((0x3fU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                             << 3U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg)))),6);
        bufp->chgCData(oldp+2377,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg)))),8);
        bufp->chgCData(oldp+2378,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg)))),8);
        bufp->chgCData(oldp+2379,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg),2);
        bufp->chgCData(oldp+2380,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT____Vcellinp__axi_interconnect_inst__m_axi_awready),2);
        bufp->chgQData(oldp+2381,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)))),64);
        bufp->chgCData(oldp+2383,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg)))),8);
        bufp->chgCData(oldp+2384,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg))))),2);
        bufp->chgCData(oldp+2385,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_reg),2);
        bufp->chgCData(oldp+2386,(((2U & ((~ (IData)(
                                                     (0U 
                                                      != (IData)(vlSelf->top_v2__DOT__SOC__DOT__AXI_debug_printer__DOT__AXI_debug_printer_STATE)))) 
                                          << 1U)) | (IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_wready_reg))),2);
        bufp->chgSData(oldp+2387,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg),16);
        bufp->chgCData(oldp+2388,((((IData)(vlSelf->top_v2__DOT__SOC__DOT___AXI_debug_printer_io_s_AXI_AXI_B_valid) 
                                    << 1U) | (IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_reg))),2);
        bufp->chgCData(oldp+2389,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg),2);
        bufp->chgCData(oldp+2390,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg),2);
        bufp->chgCData(oldp+2391,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_reg),2);
        bufp->chgSData(oldp+2392,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg),16);
        bufp->chgQData(oldp+2393,((QData)((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_reg))),64);
        bufp->chgCData(oldp+2395,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_reg),2);
        bufp->chgCData(oldp+2396,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_reg),2);
        bufp->chgCData(oldp+2397,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg),2);
        bufp->chgIData(oldp+2398,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__i),32);
        bufp->chgIData(oldp+2399,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__j),32);
        bufp->chgCData(oldp+2400,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__state_reg),3);
        bufp->chgCData(oldp+2401,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__state_next),3);
        bufp->chgBit(oldp+2402,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__match));
        bufp->chgBit(oldp+2403,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg));
        bufp->chgBit(oldp+2404,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_next));
        bufp->chgCData(oldp+2405,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_next),8);
        bufp->chgIData(oldp+2406,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_next),32);
        bufp->chgBit(oldp+2407,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_valid_reg));
        bufp->chgBit(oldp+2408,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_valid_next));
        bufp->chgCData(oldp+2409,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_next),8);
        bufp->chgCData(oldp+2410,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_next),3);
        bufp->chgCData(oldp+2411,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_next),2);
        bufp->chgBit(oldp+2412,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_next));
        bufp->chgCData(oldp+2413,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_next),4);
        bufp->chgCData(oldp+2414,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_next),3);
        bufp->chgCData(oldp+2415,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_next),4);
        bufp->chgCData(oldp+2416,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_next),4);
        bufp->chgBit(oldp+2417,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_auser_reg));
        bufp->chgBit(oldp+2418,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_auser_next));
        bufp->chgCData(oldp+2419,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_next),2);
        bufp->chgBit(oldp+2420,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_buser_reg));
        bufp->chgCData(oldp+2421,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_next),2);
        bufp->chgCData(oldp+2422,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_next),2);
        bufp->chgCData(oldp+2423,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_next),2);
        bufp->chgCData(oldp+2424,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_next),2);
        bufp->chgCData(oldp+2425,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_next),2);
        bufp->chgCData(oldp+2426,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_next),2);
        bufp->chgCData(oldp+2427,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_next),2);
        bufp->chgCData(oldp+2428,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_next),2);
        bufp->chgCData(oldp+2429,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_int),8);
        bufp->chgIData(oldp+2430,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_int),32);
        bufp->chgCData(oldp+2431,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_int),2);
        bufp->chgBit(oldp+2432,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_int));
        bufp->chgBit(oldp+2433,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_ruser_int));
        bufp->chgBit(oldp+2434,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_int));
        bufp->chgBit(oldp+2435,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rready_int_reg));
        bufp->chgBit(oldp+2436,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rready_int_early));
        bufp->chgIData(oldp+2437,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_int),32);
        bufp->chgCData(oldp+2438,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_int),4);
        bufp->chgBit(oldp+2439,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_int));
        bufp->chgBit(oldp+2440,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wuser_int));
        bufp->chgBit(oldp+2441,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_int));
        bufp->chgBit(oldp+2442,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wready_int_reg));
        bufp->chgBit(oldp+2443,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wready_int_early));
        bufp->chgBit(oldp+2444,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                       >> 1U))));
        bufp->chgCData(oldp+2445,(0U),8);
        bufp->chgIData(oldp+2446,((IData)((((QData)((IData)(
                                                            ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                              ? 
                                                             ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                               ? 
                                                              ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                                                << 0x11U) 
                                                               | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                                                  >> 0xfU))
                                                               : 0U)
                                                              : 0U))) 
                                            << 0x20U) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, 
                                                               (1U 
                                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                   >> 1U)), 5U))))),32);
        bufp->chgCData(oldp+2447,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5) 
                                             << 8U) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgCData(oldp+2448,(((5U >= (7U & ((IData)(3U) 
                                                 * 
                                                 (1U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                     >> 1U)))))
                                    ? (7U & ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                                ? 5U
                                                : 0U) 
                                              << 3U) 
                                             >> (7U 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (1U 
                                                     & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                        >> 1U))))))
                                    : 0U)),3);
        bufp->chgCData(oldp+2449,((3U & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid) 
                                          << 2U) >> 
                                         (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2450,(0U));
        bufp->chgCData(oldp+2451,(0U),4);
        bufp->chgCData(oldp+2452,(0U),3);
        bufp->chgBit(oldp+2453,((1U & (((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AW_valid) 
                                        << 1U) >> (1U 
                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                      >> 1U))))));
        bufp->chgBit(oldp+2454,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgIData(oldp+2455,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_wdata),32);
        bufp->chgCData(oldp+2456,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_wstrb),4);
        bufp->chgBit(oldp+2457,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_wlast));
        bufp->chgBit(oldp+2458,((1U & ((((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)) 
                                         << 1U) | (1U 
                                                   == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2459,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgCData(oldp+2460,((0xffU & ((0xffffU 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgCData(oldp+2461,((3U & ((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg))) 
                                         >> (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2462,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2463,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT____Vcellinp__axi_interconnect_inst__s_axi_bready) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgIData(oldp+2464,((IData)((((QData)((IData)(
                                                            ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                              ? 
                                                             ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                               ? 
                                                              ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                                                << 0x19U) 
                                                               | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                                                  >> 7U))
                                                               : 0U)
                                                              : 0U))) 
                                            << 0x20U) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, 
                                                               (1U 
                                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                   >> 1U)), 5U))))),32);
        bufp->chgCData(oldp+2465,((0xffU & (((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_he49e9fcb_0_2)
                                                : 0U) 
                                              << 8U) 
                                             | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                                                 ? 7U
                                                 : 0U)) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgCData(oldp+2466,(((5U >= (7U & ((IData)(3U) 
                                                 * 
                                                 (1U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                     >> 1U)))))
                                    ? (7U & (((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                 ? 5U
                                                 : 0U) 
                                               << 3U) 
                                              | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)
                                                  ? 5U
                                                  : 0U)) 
                                             >> (7U 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (1U 
                                                     & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                        >> 1U))))))
                                    : 0U)),3);
        bufp->chgCData(oldp+2467,((3U & ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                           << 2U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_11)) 
                                         >> (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2468,((1U & ((((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AR_valid) 
                                         << 1U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_instruction_cache_AXI_port_AXI_AR_valid)) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2469,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgCData(oldp+2470,((0xffU & ((0xffffU 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgIData(oldp+2471,((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg))) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, 
                                                               (1U 
                                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                   >> 1U)), 5U))))),32);
        bufp->chgCData(oldp+2472,((3U & ((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg))) 
                                         >> (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2473,((1U & ((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg)))) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2474,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_rvalid));
        bufp->chgBit(oldp+2475,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_rready));
        bufp->chgCData(oldp+2476,(0U),8);
        bufp->chgIData(oldp+2477,((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg))) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 5U))))),32);
        bufp->chgCData(oldp+2478,((0xffU & ((0xffffU 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 3U))))),8);
        bufp->chgCData(oldp+2479,(((5U >= (7U & ((IData)(3U) 
                                                 * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg))))
                                    ? (7U & ((0x3fU 
                                              & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg))) 
                                             >> (7U 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))))
                                    : 0U)),3);
        bufp->chgCData(oldp+2480,((3U & ((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg))) 
                                         >> (3U & VL_SHIFTL_III(2,2,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 1U))))),2);
        bufp->chgBit(oldp+2481,((1U & ((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg)))) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgCData(oldp+2482,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgCData(oldp+2483,(((5U >= (7U & ((IData)(3U) 
                                                 * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg))))
                                    ? (7U & ((0x3fU 
                                              & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg))) 
                                             >> (7U 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))))
                                    : 0U)),3);
        bufp->chgCData(oldp+2484,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgCData(oldp+2485,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgBit(oldp+2486,(0U));
        bufp->chgBit(oldp+2487,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2488,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT____Vcellinp__axi_interconnect_inst__m_axi_awready) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgIData(oldp+2489,((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg))) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 5U))))),32);
        bufp->chgCData(oldp+2490,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgBit(oldp+2491,((1U & ((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg)))) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2492,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_wvalid));
        bufp->chgBit(oldp+2493,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_wready));
        bufp->chgCData(oldp+2494,((0xffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 3U))))),8);
        bufp->chgCData(oldp+2495,(0U),2);
        bufp->chgBit(oldp+2496,((1U & ((((IData)(vlSelf->top_v2__DOT__SOC__DOT___AXI_debug_printer_io_s_AXI_AXI_B_valid) 
                                         << 1U) | (IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_reg)) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2497,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2498,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2499,((1U & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgCData(oldp+2500,((0xffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 3U))))),8);
        bufp->chgIData(oldp+2501,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_rdata),32);
        bufp->chgBit(oldp+2502,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_rlast));
        bufp->chgBit(oldp+2503,((1U & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2504,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgCData(oldp+2505,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__request),4);
        bufp->chgCData(oldp+2506,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__acknowledge),4);
        bufp->chgCData(oldp+2507,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_reg),4);
        bufp->chgBit(oldp+2508,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_valid_reg));
        bufp->chgCData(oldp+2509,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg),2);
        bufp->chgBit(oldp+2510,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))));
        bufp->chgBit(oldp+2511,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_ruser_reg));
        bufp->chgCData(oldp+2512,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_next),2);
        bufp->chgCData(oldp+2513,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rid_reg),8);
        bufp->chgIData(oldp+2514,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rdata_reg),32);
        bufp->chgCData(oldp+2515,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rresp_reg),2);
        bufp->chgBit(oldp+2516,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rlast_reg));
        bufp->chgBit(oldp+2517,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_ruser_reg));
        bufp->chgBit(oldp+2518,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rvalid_reg));
        bufp->chgBit(oldp+2519,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rvalid_next));
        bufp->chgBit(oldp+2520,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_r_int_to_output));
        bufp->chgBit(oldp+2521,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_r_int_to_temp));
        bufp->chgBit(oldp+2522,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_r_temp_to_output));
        bufp->chgBit(oldp+2523,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wuser_reg));
        bufp->chgCData(oldp+2524,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_next),2);
        bufp->chgIData(oldp+2525,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wdata_reg),32);
        bufp->chgCData(oldp+2526,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wstrb_reg),4);
        bufp->chgBit(oldp+2527,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wlast_reg));
        bufp->chgBit(oldp+2528,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wuser_reg));
        bufp->chgBit(oldp+2529,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wvalid_reg));
        bufp->chgBit(oldp+2530,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wvalid_next));
        bufp->chgBit(oldp+2531,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_w_int_to_output));
        bufp->chgBit(oldp+2532,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_w_int_to_temp));
        bufp->chgBit(oldp+2533,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_w_temp_to_output));
        bufp->chgCData(oldp+2534,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__mask_reg),4);
        bufp->chgCData(oldp+2535,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__input_padded),4);
        bufp->chgSData(oldp+2536,((0xffffU & vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)),16);
        bufp->chgBit(oldp+2537,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_state_reg));
        bufp->chgBit(oldp+2538,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_state_next));
        bufp->chgCData(oldp+2539,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_state_reg),2);
        bufp->chgCData(oldp+2540,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_state_next),2);
        bufp->chgBit(oldp+2541,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__mem_wr_en));
        bufp->chgBit(oldp+2542,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__mem_rd_en));
        bufp->chgCData(oldp+2543,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_id_reg),8);
        bufp->chgCData(oldp+2544,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_id_next),8);
        bufp->chgSData(oldp+2545,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_addr_reg),16);
        bufp->chgSData(oldp+2546,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_addr_next),16);
        bufp->chgCData(oldp+2547,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_count_reg),8);
        bufp->chgCData(oldp+2548,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_count_next),8);
        bufp->chgCData(oldp+2549,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_size_reg),3);
        bufp->chgCData(oldp+2550,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_size_next),3);
        bufp->chgCData(oldp+2551,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_burst_reg),2);
        bufp->chgCData(oldp+2552,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_burst_next),2);
        bufp->chgCData(oldp+2553,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_id_reg),8);
        bufp->chgCData(oldp+2554,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_id_next),8);
        bufp->chgSData(oldp+2555,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_addr_reg),16);
        bufp->chgSData(oldp+2556,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_addr_next),16);
        bufp->chgCData(oldp+2557,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_count_reg),8);
        bufp->chgCData(oldp+2558,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_count_next),8);
        bufp->chgCData(oldp+2559,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_size_reg),3);
        bufp->chgCData(oldp+2560,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_size_next),3);
        bufp->chgCData(oldp+2561,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_burst_reg),2);
        bufp->chgCData(oldp+2562,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_burst_next),2);
        bufp->chgBit(oldp+2563,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_awready_next));
        bufp->chgBit(oldp+2564,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_wready_next));
        bufp->chgCData(oldp+2565,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_next),8);
        bufp->chgBit(oldp+2566,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_next));
        bufp->chgBit(oldp+2567,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_next));
        bufp->chgCData(oldp+2568,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_next),8);
        bufp->chgBit(oldp+2569,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_next));
        bufp->chgBit(oldp+2570,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_next));
        bufp->chgCData(oldp+2571,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_pipe_reg),8);
        bufp->chgIData(oldp+2572,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_pipe_reg),32);
        bufp->chgBit(oldp+2573,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_pipe_reg));
        bufp->chgBit(oldp+2574,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_pipe_reg));
        bufp->chgSData(oldp+2575,((0x3fffU & (vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg 
                                              >> 2U))),14);
        bufp->chgSData(oldp+2576,((0x3fffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_addr_reg) 
                                              >> 2U))),14);
        bufp->chgSData(oldp+2577,((0x3fffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_addr_reg) 
                                              >> 2U))),14);
        bufp->chgIData(oldp+2578,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__i),32);
        bufp->chgBit(oldp+2579,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en));
        bufp->chgWData(oldp+2580,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0.__PVT___mem_ext_R0_data),278);
        bufp->chgWData(oldp+2589,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0.__Vcellinp__mem_ext__W0_data),278);
        __Vtemp_183[0U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[1U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[2U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[3U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[4U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[5U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[6U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[7U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        __Vtemp_183[8U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[8U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_0__io_wr_en))));
        bufp->chgWData(oldp+2598,(__Vtemp_183),278);
        bufp->chgBit(oldp+2607,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en));
        bufp->chgWData(oldp+2608,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1.__PVT___mem_ext_R0_data),278);
        bufp->chgWData(oldp+2617,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1.__Vcellinp__mem_ext__W0_data),278);
        __Vtemp_185[0U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[1U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[2U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[3U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[4U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[5U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[6U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[7U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        __Vtemp_185[8U] = (Vtop_v2__ConstPool__CONST_h4d451b67_0[8U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__data_memory_1__io_wr_en))));
        bufp->chgWData(oldp+2626,(__Vtemp_185),278);
        bufp->chgBit(oldp+2635,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2636,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T_1) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__empty) 
                                       | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T))))));
        bufp->chgWData(oldp+2637,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___GEN),434);
        bufp->chgBit(oldp+2651,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___io_predictions_in_ready_T));
        bufp->chgCData(oldp+2652,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2653,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2654,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2655,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2656,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2657,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2658,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2659,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2660,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap_1]),434);
        bufp->chgWData(oldp+2674,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__Vcellinp__ram_ext__W0_data),434);
        __Vtemp_187[0U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[1U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[1U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[2U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[2U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[3U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[3U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[4U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[4U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[5U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[5U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[6U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[6U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[7U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[7U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[8U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[8U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[9U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[9U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[0xaU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xaU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[0xbU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xbU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[0xcU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xcU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_187[0xdU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xdU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2688,(__Vtemp_187),434);
        bufp->chgWData(oldp+2702,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ram_ext__DOT__Memory[0]),434);
        bufp->chgWData(oldp+2716,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ram_ext__DOT__Memory[1]),434);
        bufp->chgBit(oldp+2730,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2731,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2732,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty) 
                                       | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq))))));
        bufp->chgWData(oldp+2733,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597),434);
        bufp->chgWData(oldp+2747,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits),434);
        bufp->chgCData(oldp+2761,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2762,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap));
        bufp->chgBit(oldp+2763,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2764,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2765,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2766,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__empty));
        bufp->chgBit(oldp+2767,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2768,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2769,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap_1]),434);
        bufp->chgWData(oldp+2783,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__Vcellinp__ram_ext__W0_data),434);
        __Vtemp_189[0U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[1U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[1U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[2U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[2U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[3U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[3U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[4U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[4U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[5U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[5U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[6U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[6U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[7U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[7U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[8U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[8U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[9U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[9U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[0xaU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xaU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[0xbU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xbU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[0xcU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xcU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_189[0xdU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xdU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2797,(__Vtemp_189),434);
        bufp->chgWData(oldp+2811,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ram_ext__DOT__Memory[0]),434);
        bufp->chgWData(oldp+2825,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ram_ext__DOT__Memory[1]),434);
        bufp->chgBit(oldp+2839,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2840,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__full)))));
        bufp->chgBit(oldp+2841,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_load_Q_io_enq_valid_T_14));
        bufp->chgWData(oldp+2842,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218),192);
        bufp->chgCData(oldp+2848,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ptr_match)) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__enq_ptr_value) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__deq_ptr_value))))),3);
        bufp->chgBit(oldp+2849,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT____Vcellinp__FU_output_load_Q__io_flush));
        bufp->chgCData(oldp+2850,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__enq_ptr_value),2);
        bufp->chgCData(oldp+2851,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__deq_ptr_value),2);
        bufp->chgBit(oldp+2852,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2853,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2854,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__full));
        bufp->chgBit(oldp+2855,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2856,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__deq_ptr_value]),192);
        bufp->chgWData(oldp+2862,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__Vcellinp__ram_ext__W0_data),192);
        __Vtemp_190[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_190[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_190[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_190[3U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_190[4U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_190[5U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        bufp->chgWData(oldp+2868,(__Vtemp_190),192);
        bufp->chgWData(oldp+2874,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[0]),192);
        bufp->chgWData(oldp+2880,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[1]),192);
        bufp->chgWData(oldp+2886,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[2]),192);
        bufp->chgWData(oldp+2892,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[3]),192);
        bufp->chgBit(oldp+2898,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2899,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__full)))));
        bufp->chgBit(oldp+2900,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_store_Q_io_enq_valid_T_14));
        bufp->chgWData(oldp+2901,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219),192);
        bufp->chgCData(oldp+2907,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ptr_match)) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__enq_ptr_value) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__deq_ptr_value))))),3);
        bufp->chgCData(oldp+2908,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__enq_ptr_value),2);
        bufp->chgCData(oldp+2909,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__deq_ptr_value),2);
        bufp->chgBit(oldp+2910,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2911,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2912,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__empty));
        bufp->chgBit(oldp+2913,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__full));
        bufp->chgBit(oldp+2914,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2915,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__deq_ptr_value]),192);
        bufp->chgWData(oldp+2921,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__Vcellinp__ram_ext__W0_data),192);
        __Vtemp_191[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_191[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_191[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_191[3U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_191[4U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_191[5U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        bufp->chgWData(oldp+2927,(__Vtemp_191),192);
        bufp->chgWData(oldp+2933,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[0]),192);
        bufp->chgWData(oldp+2939,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[1]),192);
        bufp->chgWData(oldp+2945,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[2]),192);
        bufp->chgWData(oldp+2951,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[3]),192);
        bufp->chgBit(oldp+2957,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2958,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2959,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_10) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))));
        bufp->chgCData(oldp+2960,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2961,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2962,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2963,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2964,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2965,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2966,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2967,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2968,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap_1]),110);
        __Vtemp_194[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_194[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_194[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_194[3U] = (0x3fffU & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2972,(__Vtemp_194),110);
        bufp->chgWData(oldp+2976,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+2980,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[1]),110);
        bufp->chgBit(oldp+2984,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2985,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2986,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T_1)))));
        bufp->chgCData(oldp+2987,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2988,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2989,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2990,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2991,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2992,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2993,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2994,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2995,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap_1]),110);
        bufp->chgWData(oldp+2999,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__Vcellinp__ram_ext__W0_data),110);
        __Vtemp_197[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_197[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_197[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_197[3U] = (0x3fffU & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+3003,(__Vtemp_197),110);
        bufp->chgWData(oldp+3007,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+3011,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[1]),110);
        bufp->chgBit(oldp+3015,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+3016,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+3017,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq)))));
        bufp->chgCData(oldp+3018,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+3019,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+3020,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+3021,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+3022,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+3023,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__empty));
        bufp->chgBit(oldp+3024,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+3025,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+3026,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__Vcellinp__ram_ext__W0_data),110);
        __Vtemp_200[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_200[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_200[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_200[3U] = (0x3fffU & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+3030,(__Vtemp_200),110);
        bufp->chgWData(oldp+3034,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+3038,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[1]),110);
        bufp->chgBit(oldp+3042,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__unnamedblk1__DOT__do_deq));
    }
    bufp->chgBit(oldp+3043,(vlSelf->clock));
    bufp->chgBit(oldp+3044,(vlSelf->reset));
    bufp->chgBit(oldp+3045,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__hasBeenResetReg) 
                             & (~ (IData)(vlSelf->reset)))));
    bufp->chgQData(oldp+3046,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index),64);
    bufp->chgBit(oldp+3048,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg) 
                             & (~ (IData)(vlSelf->reset)))));
    bufp->chgCData(oldp+3049,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_next),4);
    bufp->chgBit(oldp+3050,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_valid_next));
    bufp->chgCData(oldp+3051,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_next),2);
    bufp->chgBit(oldp+3052,((1U & vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_valid
                             [1U])));
    bufp->chgCData(oldp+3053,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc
                              [1U]),2);
    bufp->chgCData(oldp+3054,((0xfU & ((IData)(1U) 
                                       << vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc
                                       [1U]))),4);
    bufp->chgCData(oldp+3055,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__mask_next),4);
    bufp->chgBit(oldp+3056,((1U & vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_valid
                             [1U])));
    bufp->chgCData(oldp+3057,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc
                              [1U]),2);
    bufp->chgCData(oldp+3058,((0xfU & ((IData)(1U) 
                                       << vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc
                                       [1U]))),4);
    bufp->chgCData(oldp+3059,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_valid[0]),2);
    bufp->chgCData(oldp+3060,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_valid[1]),2);
    bufp->chgCData(oldp+3061,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc[0]),2);
    bufp->chgCData(oldp+3062,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc[1]),2);
    bufp->chgCData(oldp+3063,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_valid[0]),2);
    bufp->chgCData(oldp+3064,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_valid[1]),2);
    bufp->chgCData(oldp+3065,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc[0]),2);
    bufp->chgCData(oldp+3066,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc[1]),2);
}

void Vtop_v2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_v2___024root__trace_cleanup\n"); );
    // Init
    Vtop_v2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_v2___024root*>(voidSelf);
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}

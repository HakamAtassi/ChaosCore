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
extern const VlWide<8>/*255:0*/ Vtop_v2__ConstPool__CONST_h9e67c271_0;

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
    VlWide<8>/*255:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<5>/*159:0*/ __Vtemp_25;
    VlWide<10>/*319:0*/ __Vtemp_46;
    VlWide<14>/*447:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_53;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<14>/*447:0*/ __Vtemp_61;
    VlWide<7>/*223:0*/ __Vtemp_70;
    VlWide<7>/*223:0*/ __Vtemp_76;
    VlWide<7>/*223:0*/ __Vtemp_85;
    VlWide<7>/*223:0*/ __Vtemp_91;
    VlWide<7>/*223:0*/ __Vtemp_97;
    VlWide<7>/*223:0*/ __Vtemp_98;
    VlWide<4>/*127:0*/ __Vtemp_101;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<6>/*191:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<8>/*255:0*/ __Vtemp_113;
    VlWide<8>/*255:0*/ __Vtemp_114;
    VlWide<8>/*255:0*/ __Vtemp_116;
    VlWide<8>/*255:0*/ __Vtemp_118;
    VlWide<14>/*447:0*/ __Vtemp_119;
    VlWide<14>/*447:0*/ __Vtemp_121;
    VlWide<8>/*255:0*/ __Vtemp_145;
    VlWide<3>/*95:0*/ __Vtemp_146;
    VlWide<10>/*319:0*/ __Vtemp_171;
    VlWide<11>/*351:0*/ __Vtemp_173;
    VlWide<11>/*351:0*/ __Vtemp_174;
    VlWide<11>/*351:0*/ __Vtemp_175;
    VlWide<8>/*255:0*/ __Vtemp_176;
    VlWide<3>/*95:0*/ __Vtemp_178;
    VlWide<3>/*95:0*/ __Vtemp_180;
    VlWide<9>/*287:0*/ __Vtemp_182;
    VlWide<8>/*255:0*/ __Vtemp_183;
    VlWide<14>/*447:0*/ __Vtemp_185;
    VlWide<14>/*447:0*/ __Vtemp_187;
    VlWide<6>/*191:0*/ __Vtemp_188;
    VlWide<6>/*191:0*/ __Vtemp_189;
    VlWide<4>/*127:0*/ __Vtemp_192;
    VlWide<4>/*127:0*/ __Vtemp_195;
    VlWide<4>/*127:0*/ __Vtemp_198;
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+0,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__hasBeenResetReg));
        bufp->chgBit(oldp+1,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg));
        bufp->chgIData(oldp+2,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__i),32);
        bufp->chgIData(oldp+3,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__j),32);
        bufp->chgIData(oldp+4,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__i),32);
    }
    if (VL_UNLIKELY(((vlSelf->__Vm_traceActivity[2U] 
                      | vlSelf->__Vm_traceActivity[3U]) 
                     | vlSelf->__Vm_traceActivity[4U]))) {
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
        bufp->chgWData(oldp+5,(__Vtemp_1),65);
        __Vtemp_2[0U] = ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq)
                          ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux
                          : 0U);
        __Vtemp_2[1U] = 0U;
        __Vtemp_2[2U] = 0U;
        bufp->chgWData(oldp+8,(__Vtemp_2),65);
        bufp->chgQData(oldp+11,((((QData)((IData)(((IData)(4U) 
                                                   + vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_22))) 
                                  << 2U) | (QData)((IData)(
                                                           ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL) 
                                                              & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET) 
                                                               & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))))))),34);
        __Vtemp_8[0U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11)))))) 
                          << 0x1eU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__GHR) 
                                        << 0xeU) | 
                                       (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT) 
                                         << 7U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS))));
        __Vtemp_8[1U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11)))))) 
                          >> 2U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                               << 0xaU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11))))) 
                                             >> 0x20U)) 
                                    << 0x1eU));
        __Vtemp_8[2U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_12)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_13) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_14)))))) 
                          << 8U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                               << 0xaU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11))))) 
                                             >> 0x20U)) 
                                    >> 2U));
        __Vtemp_8[3U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_15)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_16) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_17)))))) 
                          << 0x12U) | (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_12)) 
                                                  << 0xaU) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_13) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_14)))))) 
                                        >> 0x18U) | 
                                       ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_12)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_13) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_14))))) 
                                                 >> 0x20U)) 
                                        << 8U)));
        __Vtemp_8[4U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20)))))) 
                          << 0x1cU) | (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_15)) 
                                                  << 0xaU) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_16) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_17)))))) 
                                        >> 0xeU) | 
                                       ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_15)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_16) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_17))))) 
                                                 >> 0x20U)) 
                                        << 0x12U)));
        __Vtemp_8[5U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                    << 0xaU) | (QData)((IData)(
                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                 << 6U) 
                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20)))))) 
                          >> 4U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                               << 0xaU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20))))) 
                                             >> 0x20U)) 
                                    << 0x1cU));
        __Vtemp_8[6U] = ((0xffffc000U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_0 
                                         << 0xaU)) 
                         | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_8) 
                             << 6U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                                  << 0xaU) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                     << 6U) 
                                                                    | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20))))) 
                                                >> 0x20U)) 
                                       >> 4U)));
        __Vtemp_8[7U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_0 
                         >> 0x16U);
        bufp->chgWData(oldp+13,(__Vtemp_8),234);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgQData(oldp+21,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellout__prediction_skid_buffer__io_deq_bits),53);
        bufp->chgQData(oldp+23,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT____Vcellout__BTB_Q__io_deq_bits),53);
        bufp->chgQData(oldp+25,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT____Vcellinp__ram_ext__W0_data),53);
        __Vtemp_9[0U] = 0U;
        __Vtemp_9[1U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux 
                         << 1U);
        __Vtemp_9[2U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux 
                         >> 0x1fU);
        bufp->chgWData(oldp+27,(__Vtemp_9),65);
        bufp->chgBit(oldp+30,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__is_ret));
        bufp->chgIData(oldp+31,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_mux),32);
        bufp->chgSData(oldp+32,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___predecoder_io_GHR),16);
        bufp->chgIData(oldp+33,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC),32);
        bufp->chgSData(oldp+34,((0xfffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC 
                                           >> 4U))),12);
        bufp->chgIData(oldp+35,(((IData)(4U) + vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_22)),32);
        bufp->chgBit(oldp+36,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_wr_valid));
        bufp->chgBit(oldp+37,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_rd_valid));
        bufp->chgCData(oldp+38,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT____Vcellinp__RAS_memory__io_rd_addr),7);
        bufp->chgQData(oldp+39,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT____Vcellinp__RAS_memory__io_data_in),39);
        bufp->chgSData(oldp+41,((0xffffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__gshare__io_predict_PC 
                                            ^ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___predecoder_io_GHR)))),16);
        bufp->chgQData(oldp+42,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___GEN),53);
        bufp->chgCData(oldp+44,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH)
                                  ? 1U : ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET)
                                           ? 4U : ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL)
                                                    ? 5U
                                                    : 
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR)
                                                     ? 3U
                                                     : 
                                                    ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL) 
                                                     << 1U)))))),3);
        bufp->chgBit(oldp+45,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JALR));
        bufp->chgBit(oldp+46,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL));
        bufp->chgCData(oldp+47,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__T_NT),4);
        bufp->chgBit(oldp+48,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken));
        bufp->chgBit(oldp+49,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken_1));
        bufp->chgBit(oldp+50,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken_2));
        bufp->chgBit(oldp+51,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_taken_3));
        bufp->chgBit(oldp+52,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_BRANCH));
        bufp->chgBit(oldp+53,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET));
        bufp->chgBit(oldp+54,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_CALL));
        bufp->chgCData(oldp+55,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__dominant_branch_index),2);
        bufp->chgIData(oldp+56,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__dominant_instruction),32);
        bufp->chgIData(oldp+57,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__imm_imm),21);
        bufp->chgIData(oldp+58,(((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_JAL)) 
                                        | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_RET)))
                                  ? 0U : (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__imm_imm 
                                                          >> 0x14U)))) 
                                           << 0x15U) 
                                          | vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__imm_imm))),32);
        bufp->chgIData(oldp+59,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__target_address),32);
        bufp->chgWData(oldp+60,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT____Vcellinp__ram_ext__W0_data),234);
        bufp->chgWData(oldp+68,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_0),110);
        bufp->chgWData(oldp+72,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__Vcellinp__ram_ext__W0_data),110);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+76,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_awready_reg));
        bufp->chgBit(oldp+77,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg))));
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
        bufp->chgWData(oldp+78,(__Vtemp_10),70);
        bufp->chgBit(oldp+81,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_wready_reg));
        bufp->chgBit(oldp+82,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_reg))));
        bufp->chgQData(oldp+83,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)) 
                                  << 6U) | (QData)((IData)(
                                                           (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg) 
                                                             << 2U) 
                                                            | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg) 
                                                               << 1U)))))),38);
        bufp->chgBit(oldp+85,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg))));
        bufp->chgBit(oldp+86,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_reg));
        bufp->chgSData(oldp+87,(((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg) 
                                 << 3U)),11);
        bufp->chgBit(oldp+88,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_reg));
        bufp->chgBit(oldp+89,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg))));
        bufp->chgBit(oldp+90,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg))));
        bufp->chgBit(oldp+91,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_reg));
        bufp->chgQData(oldp+92,((((QData)((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg)) 
                                  << 0x24U) | (((QData)((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_reg)) 
                                                << 4U) 
                                               | (QData)((IData)(
                                                                 ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_reg) 
                                                                  << 1U)))))),44);
        bufp->chgBit(oldp+94,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg) 
                                     >> 1U))));
        bufp->chgBit(oldp+95,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_reg) 
                                     >> 1U))));
        bufp->chgBit(oldp+96,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg) 
                                     >> 1U))));
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
        bufp->chgBit(oldp+102,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg))));
        bufp->chgBit(oldp+103,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg))));
        bufp->chgBit(oldp+104,((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgQData(oldp+105,((((QData)((IData)(
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
                                                             | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_0) 
                                                                << 1U)))))),38);
        bufp->chgBit(oldp+107,((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+108,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg))));
        bufp->chgSData(oldp+109,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg) 
                                   << 3U) | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg) 
                                             << 1U))),11);
        bufp->chgBit(oldp+110,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg))));
        bufp->chgBit(oldp+111,((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+112,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_reg))));
        bufp->chgQData(oldp+113,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg)) 
                                   << 0x24U) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)) 
                                                 << 4U) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg) 
                                                                    << 2U) 
                                                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg) 
                                                                      << 1U))))))),44);
        bufp->chgBit(oldp+115,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+116,(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AW_valid));
        __Vtemp_12[0U] = (IData)((((QData)((IData)(
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
        __Vtemp_12[1U] = (IData)(((((QData)((IData)(
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
        __Vtemp_12[2U] = 0U;
        bufp->chgWData(oldp+117,(__Vtemp_12),70);
        bufp->chgBit(oldp+120,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+121,((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgQData(oldp+122,((((QData)((IData)(
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
        bufp->chgBit(oldp+124,((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+125,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+126,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg) 
                                      >> 1U))));
        bufp->chgBit(oldp+127,(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AR_valid));
        __Vtemp_13[0U] = (IData)((((QData)((IData)(
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
                                                                   ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_h6d09639e_0_2)
                                                                   : 0U) 
                                                                 << 0x16U) 
                                                                | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                                      ? 5U
                                                                      : 0U) 
                                                                    << 0x13U) 
                                                                   | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                                                      << 0x11U)))))));
        __Vtemp_13[1U] = (IData)(((((QData)((IData)(
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
                                                                    ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_h6d09639e_0_2)
                                                                    : 0U) 
                                                                  << 0x16U) 
                                                                 | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                                                       ? 5U
                                                                       : 0U) 
                                                                     << 0x13U) 
                                                                    | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                                                       << 0x11U)))))) 
                                  >> 0x20U));
        __Vtemp_13[2U] = 0U;
        bufp->chgWData(oldp+128,(__Vtemp_13),70);
        bufp->chgBit(oldp+131,((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))));
        bufp->chgBit(oldp+132,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_reg) 
                                      >> 1U))));
        bufp->chgWData(oldp+133,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__io_commit),169);
        bufp->chgBit(oldp+139,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush));
        bufp->chgQData(oldp+140,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__io_revert),33);
        bufp->chgBit(oldp+142,((1U & ((~ ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))) 
                                      | ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T)) 
                                         & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full)))))));
        bufp->chgBit(oldp+143,((1U & (~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match) 
                                         & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full))))));
        bufp->chgBit(oldp+144,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT___instruction_cache_io_CPU_response_valid));
        __Vtemp_19[0U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_1)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_2) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_3)))))) 
                           << 0x1eU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_13) 
                                         << 0xeU) | 
                                        (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_14) 
                                          << 7U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_15))));
        __Vtemp_19[1U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_1)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_2) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_3)))))) 
                           >> 2U) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_1)) 
                                                << 0xaU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_2) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_3))))) 
                                              >> 0x20U)) 
                                     << 0x1eU));
        __Vtemp_19[2U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_4)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_5) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_6)))))) 
                           << 8U) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_1)) 
                                                << 0xaU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_2) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_3))))) 
                                              >> 0x20U)) 
                                     >> 2U));
        __Vtemp_19[3U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_7)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_8) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_9)))))) 
                           << 0x12U) | (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_4)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_5) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_6)))))) 
                                         >> 0x18U) 
                                        | ((IData)(
                                                   ((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_4)) 
                                                      << 0xaU) 
                                                     | (QData)((IData)(
                                                                       (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_5) 
                                                                         << 6U) 
                                                                        | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_6))))) 
                                                    >> 0x20U)) 
                                           << 8U)));
        __Vtemp_19[4U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_10)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_11) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_12)))))) 
                           << 0x1cU) | (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_7)) 
                                                   << 0xaU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_8) 
                                                                      << 6U) 
                                                                     | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_9)))))) 
                                         >> 0xeU) | 
                                        ((IData)(((
                                                   ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_7)) 
                                                    << 0xaU) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_8) 
                                                                       << 6U) 
                                                                      | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_9))))) 
                                                  >> 0x20U)) 
                                         << 0x12U)));
        __Vtemp_19[5U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_10)) 
                                     << 0xaU) | (QData)((IData)(
                                                                (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_11) 
                                                                  << 6U) 
                                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_12)))))) 
                           >> 4U) | ((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_10)) 
                                                << 0xaU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_11) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_12))))) 
                                              >> 0x20U)) 
                                     << 0x1cU));
        __Vtemp_19[6U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_0 
                           << 0xaU) | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_55) 
                                        << 6U) | ((IData)(
                                                          ((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_10)) 
                                                             << 0xaU) 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_11) 
                                                                                << 6U) 
                                                                               | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_12))))) 
                                                           >> 0x20U)) 
                                                  >> 4U)));
        __Vtemp_19[7U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_0 
                          >> 0x16U);
        bufp->chgWData(oldp+145,(__Vtemp_19),234);
        bufp->chgBit(oldp+153,(((0U != (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_23)) 
                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__fire_store))));
        bufp->chgWData(oldp+154,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__io_backend_memory_request_bits),72);
        bufp->chgBit(oldp+157,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__output_valid_r_1));
        bufp->chgQData(oldp+158,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT___data_cache_io_backend_memory_response_bits),36);
        bufp->chgCData(oldp+160,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_MEMRS),4);
        bufp->chgCData(oldp+161,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__needs_INTRS),4);
        bufp->chgBit(oldp+162,(((7U & ((3U & ((0U != 
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
        bufp->chgBit(oldp+163,(((7U & ((3U & ((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready)) 
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
        bufp->chgWData(oldp+164,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___FTQ_io_FTQ),110);
        __Vtemp_20[0U] = (IData)((((QData)((IData)(
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
        __Vtemp_20[1U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
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
        __Vtemp_25[0U] = __Vtemp_20[0U];
        __Vtemp_25[1U] = __Vtemp_20[1U];
        __Vtemp_25[2U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                             ? (0x3fffffffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U])
                             : 0U) << 0x14U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT____VdfgRegularize_h9fa3630a_1_6) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                                     ? 
                                                    vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                                     : 0U) 
                                                   >> 5U)));
        __Vtemp_25[3U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT____VdfgRegularize_hfa6af0cb_0_1 
                           << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__io_ROB_output_ROB_index_REG) 
                                         << 0x12U) 
                                        | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0)
                                             ? (0x3fffffffU 
                                                & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U])
                                             : 0U) 
                                           >> 0xcU)));
        __Vtemp_25[4U] = ((0x1000000U & ((IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__row_valid_mem 
                                                  >> 
                                                  (0x3fU 
                                                   & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__front_pointer)))) 
                                         << 0x18U)) 
                          | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT____VdfgRegularize_hfa6af0cb_0_1 
                             >> 8U));
        bufp->chgWData(oldp+168,(__Vtemp_25),153);
        bufp->chgCData(oldp+173,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT__commit_row_complete),4);
        bufp->chgBit(oldp+174,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT__commit_valid));
        bufp->chgBit(oldp+175,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT__branch_commit));
        bufp->chgWData(oldp+176,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_FU_outputs),772);
        bufp->chgBit(oldp+201,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__full)))));
        bufp->chgBit(oldp+202,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__empty)))));
        bufp->chgWData(oldp+203,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory
                                 [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap_1]),110);
        bufp->chgCData(oldp+207,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___ROB_io_ROB_index),6);
        bufp->chgCData(oldp+208,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__back_pointer))),4);
        bufp->chgCData(oldp+209,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__front_pointer),5);
        bufp->chgCData(oldp+210,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__back_pointer),5);
        bufp->chgCData(oldp+211,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__front_pointer))),4);
        bufp->chgWData(oldp+212,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__FTQ),1760);
        bufp->chgBit(oldp+267,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__dq));
        bufp->chgBit(oldp+268,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__FTQ__DOT__full));
        bufp->chgBit(oldp+269,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__full)))));
        bufp->chgBit(oldp+270,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT____Vcellinp__ROB__io_ROB_packet_valid));
        __Vtemp_46[6U] = ((0xc0000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[6U]) 
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
        __Vtemp_48[0U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U];
        __Vtemp_48[1U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U];
        __Vtemp_48[2U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[2U];
        __Vtemp_48[3U] = vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[3U];
        __Vtemp_48[4U] = ((0xfffffff0U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U]) 
                          | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__initialReady) 
                              << 2U) | (3U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U])));
        __Vtemp_48[5U] = ((0xfU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[5U]) 
                          | (0xfffffff0U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[5U]));
        __Vtemp_48[6U] = __Vtemp_46[6U];
        __Vtemp_48[7U] = ((0x3fffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U]) 
                          | (0xc0000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U]));
        __Vtemp_48[8U] = ((0x3fffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U]) 
                          | (0xc0000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[8U]));
        __Vtemp_48[9U] = ((0xff000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[9U]) 
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
        __Vtemp_48[0xaU] = ((0xffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU]) 
                            | (0xff000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU]));
        __Vtemp_48[0xbU] = ((0xffffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU]) 
                            | (0xff000000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xbU]));
        __Vtemp_48[0xcU] = ((0xfffc0000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU]) 
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
        __Vtemp_48[0xdU] = (0x3ffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU]);
        bufp->chgWData(oldp+271,(__Vtemp_48),434);
        bufp->chgCData(oldp+285,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_PC_file_exec_addr),6);
        bufp->chgIData(oldp+286,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_en_d0)
                                   ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][2U] 
                                       << 0x1aU) | 
                                      (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][1U] 
                                       >> 6U)) : 0U)),32);
        bufp->chgBit(oldp+287,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__full));
        bufp->chgCData(oldp+288,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__front_pointer),7);
        bufp->chgCData(oldp+289,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__back_pointer),7);
        bufp->chgBit(oldp+290,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate));
        bufp->chgQData(oldp+291,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__row_valid_mem),64);
        bufp->chgCData(oldp+293,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__front_index),6);
        bufp->chgCData(oldp+294,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__io_ROB_output_ROB_index_REG),6);
        __Vtemp_49[0U] = (IData)((((QData)((IData)(
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
        __Vtemp_49[1U] = ((0xffffffc0U & ((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU] 
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
        __Vtemp_49[2U] = (0x3fU & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU] 
                                   >> 0xcU));
        bufp->chgWData(oldp+295,(__Vtemp_49),70);
        bufp->chgCData(oldp+298,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_0) 
                                  << 1U)),2);
        bufp->chgCData(oldp+299,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                  << 1U)),2);
        bufp->chgCData(oldp+300,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG) 
                                  << 1U)),2);
        bufp->chgCData(oldp+301,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid) 
                                  << 1U)),2);
        bufp->chgIData(oldp+302,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
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
        bufp->chgIData(oldp+303,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
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
        bufp->chgIData(oldp+304,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
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
        bufp->chgIData(oldp+305,(((0x10000U & (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U] 
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
        bufp->chgCData(oldp+306,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____Vcellinp__ROB_WB_banks_0__io_addrB),6);
        bufp->chgBit(oldp+307,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_13));
        bufp->chgCData(oldp+308,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgBit(oldp+309,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_9));
        bufp->chgCData(oldp+310,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgBit(oldp+311,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_5));
        bufp->chgCData(oldp+312,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____Vcellinp__ROB_WB_banks_0__io_addrE),6);
        bufp->chgBit(oldp+313,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_1));
        bufp->chgCData(oldp+314,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+315,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+316,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+317,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+318,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+319,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+320,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+321,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_0))),2);
        bufp->chgCData(oldp+322,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_0__DOT___GEN_13))))),2);
        bufp->chgCData(oldp+323,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate))))),2);
        bufp->chgBit(oldp+324,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_13));
        bufp->chgBit(oldp+325,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_9));
        bufp->chgBit(oldp+326,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_5));
        bufp->chgBit(oldp+327,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_1));
        bufp->chgCData(oldp+328,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+329,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+330,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+331,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+332,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+333,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+334,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+335,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_0))),2);
        bufp->chgCData(oldp+336,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_1__DOT___GEN_13))))),2);
        bufp->chgBit(oldp+337,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_13));
        bufp->chgBit(oldp+338,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_9));
        bufp->chgBit(oldp+339,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_5));
        bufp->chgBit(oldp+340,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_1));
        bufp->chgCData(oldp+341,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+342,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+343,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+344,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+345,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+346,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+347,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+348,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_0))),2);
        bufp->chgCData(oldp+349,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_2__DOT___GEN_13))))),2);
        bufp->chgBit(oldp+350,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_13));
        bufp->chgBit(oldp+351,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_9));
        bufp->chgBit(oldp+352,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_5));
        bufp->chgBit(oldp+353,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_1));
        bufp->chgCData(oldp+354,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),2);
        bufp->chgCData(oldp+355,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_1) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid))),2);
        bufp->chgCData(oldp+356,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_1))))),2);
        bufp->chgCData(oldp+357,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_5) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+358,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_5))))),2);
        bufp->chgCData(oldp+359,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_9) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG))),2);
        bufp->chgCData(oldp+360,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_9))))),2);
        bufp->chgCData(oldp+361,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_13) 
                                  & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_0))),2);
        bufp->chgCData(oldp+362,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_WB_banks_3__DOT___GEN_13))))),2);
        bufp->chgIData(oldp+363,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+364,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_0__DOT____Vcellinp__mem_ext__W0_data),17);
        bufp->chgIData(oldp+365,((0x1ffffU & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate))))),17);
        bufp->chgIData(oldp+366,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+367,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_1__DOT____Vcellinp__mem_ext__W0_data),17);
        bufp->chgIData(oldp+368,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+369,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_2__DOT____Vcellinp__mem_ext__W0_data),17);
        bufp->chgIData(oldp+370,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),17);
        bufp->chgIData(oldp+371,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__ROB_entry_banks_3__DOT____Vcellinp__mem_ext__W0_data),17);
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_en_d0) {
            __Vtemp_51[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][0U];
            __Vtemp_51[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][1U];
            __Vtemp_51[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R1_addr_d0][2U];
        } else {
            __Vtemp_51[0U] = 0U;
            __Vtemp_51[1U] = 0U;
            __Vtemp_51[2U] = 0U;
        }
        bufp->chgWData(oldp+372,(__Vtemp_51),70);
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_en_d0) {
            __Vtemp_53[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][0U];
            __Vtemp_53[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][1U];
            __Vtemp_53[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT__mem_ext__DOT___R0_addr_d0][2U];
        } else {
            __Vtemp_53[0U] = 0U;
            __Vtemp_53[1U] = 0U;
            __Vtemp_53[2U] = 0U;
        }
        bufp->chgWData(oldp+375,(__Vtemp_53),70);
        bufp->chgWData(oldp+378,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__shared_mem__DOT____Vcellinp__mem_ext__W0_data),70);
        __Vtemp_56[0U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate)));
        __Vtemp_56[1U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate)));
        __Vtemp_56[2U] = (0x3fU & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT__allocate))));
        bufp->chgWData(oldp+381,(__Vtemp_56),70);
        bufp->chgIData(oldp+384,(((vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU] 
                                   << 0xeU) | (vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU] 
                                               >> 0x12U))),32);
        bufp->chgBit(oldp+385,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__empty)))));
        __Vtemp_61[0U] = (IData)((0x3ffffffffffULL 
                                  & (((QData)((IData)(
                                                      vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U])))));
        __Vtemp_61[1U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[0U] 
                           << 0xaU) | (IData)(((0x3ffffffffffULL 
                                                & (((QData)((IData)(
                                                                    vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0U])))) 
                                               >> 0x20U)));
        __Vtemp_61[2U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[0U] 
                           >> 0x16U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[1U] 
                                        << 0xaU));
        __Vtemp_61[3U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[1U] 
                           >> 0x16U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[2U] 
                                        << 0xaU));
        __Vtemp_61[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[0U] 
                           << 4U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2[2U] 
                                     >> 0x16U));
        __Vtemp_61[5U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[0U] 
                           >> 0x1cU) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[1U] 
                                        << 4U));
        __Vtemp_61[6U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[0U] 
                           << 0x1eU) | ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[1U] 
                                         >> 0x1cU) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3[2U] 
                                           << 4U)));
        __Vtemp_61[7U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[0U] 
                           >> 2U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[1U] 
                                     << 0x1eU));
        __Vtemp_61[8U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[1U] 
                           >> 2U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[2U] 
                                     << 0x1eU));
        __Vtemp_61[9U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[0U] 
                           << 0x18U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4[2U] 
                                        >> 2U));
        __Vtemp_61[0xaU] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[0U] 
                             >> 8U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[1U] 
                                       << 0x18U));
        __Vtemp_61[0xbU] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[1U] 
                             >> 8U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[2U] 
                                       << 0x18U));
        __Vtemp_61[0xcU] = ((0xfffc0000U & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xcU]) 
                            | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5[2U] 
                               >> 8U));
        __Vtemp_61[0xdU] = (0x3ffffU & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xdU]);
        bufp->chgWData(oldp+386,(__Vtemp_61),434);
        bufp->chgCData(oldp+400,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___backend_io_MEMRS_ready),4);
        bufp->chgCData(oldp+401,((((IData)((0U != (7U 
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
        bufp->chgWData(oldp+402,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_0_decoded_instruction_REG),90);
        bufp->chgWData(oldp+405,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_1_decoded_instruction_REG),90);
        bufp->chgWData(oldp+408,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_2_decoded_instruction_REG),90);
        bufp->chgWData(oldp+411,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__read_decoded_instructions_3_decoded_instruction_REG),90);
        bufp->chgBit(oldp+414,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0_io_FU_input_valid_REG));
        bufp->chgBit(oldp+415,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1_io_FU_input_valid_REG));
        bufp->chgBit(oldp+416,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2_io_FU_input_valid_REG));
        bufp->chgBit(oldp+417,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU_io_FU_input_valid_REG));
        bufp->chgWData(oldp+418,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_1),186);
        bufp->chgWData(oldp+424,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___AGU_io_FU_output),193);
        bufp->chgBit(oldp+431,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_valid_REG));
        bufp->chgCData(oldp+432,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+433,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_is_unsigned_REG));
        bufp->chgIData(oldp+434,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_address_REG),32);
        bufp->chgIData(oldp+435,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_wr_data_REG),32);
        bufp->chgCData(oldp+436,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+437,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_memory_type_REG),2);
        bufp->chgCData(oldp+438,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__io_FU_output_bits_access_width_REG),2);
        bufp->chgBit(oldp+439,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__unnamedblk1__DOT__is_load));
        bufp->chgBit(oldp+440,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__unnamedblk1__DOT__is_store));
        bufp->chgWData(oldp+441,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_4),186);
        __Vtemp_70[0U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                             ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG)
                             : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG)) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____Vcellinp__ROB_WB_banks_0__io_addrB) 
                                        << 7U) | ((
                                                   ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                                                     ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG)
                                                     : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG)) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_7) 
                                                     << 1U))));
        __Vtemp_70[1U] = 0U;
        __Vtemp_70[2U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG
                             : 0U) << 0x17U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1) 
                                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG)) 
                                                << 0x16U));
        __Vtemp_70[3U] = ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG
                             : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG) 
                           << 0x18U) | ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1) 
                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG)) 
                                         << 0x17U) 
                                        | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG
                                             : 0U) 
                                           >> 9U)));
        __Vtemp_70[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0 
                           << 0x19U) | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_40) 
                                         << 0x18U) 
                                        | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1)
                                             ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG
                                             : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG) 
                                           >> 8U)));
        __Vtemp_70[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_hfa895d08_2_0) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0 
                                        >> 7U));
        __Vtemp_70[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__ROB__DOT____VdfgRegularize_h698e326b_2_0;
        bufp->chgWData(oldp+447,(__Vtemp_70),193);
        bufp->chgBit(oldp+454,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__REG_1));
        bufp->chgBit(oldp+455,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__monitor_output_REG));
        __Vtemp_76[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_76[1U] = 0U;
        __Vtemp_76[2U] = 0U;
        __Vtemp_76[3U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                          << 0x18U);
        __Vtemp_76[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_76[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result 
                                        >> 7U));
        __Vtemp_76[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+456,(__Vtemp_76),193);
        bufp->chgIData(oldp+463,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgIData(oldp+464,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+465,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgCData(oldp+466,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+467,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgCData(oldp+468,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+469,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+470,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgBit(oldp+471,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgIData(oldp+472,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+473,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+474,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        __Vtemp_85[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_85[1U] = 0U;
        __Vtemp_85[2U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG 
                           << 0x17U) | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG) 
                                        << 0x16U));
        __Vtemp_85[3U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG 
                           << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG) 
                                         << 0x17U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG 
                                           >> 9U)));
        __Vtemp_85[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_85[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG 
                                        >> 7U));
        __Vtemp_85[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+475,(__Vtemp_85),193);
        bufp->chgIData(oldp+482,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+483,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgBit(oldp+484,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_valid_REG));
        bufp->chgBit(oldp+485,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_branch_taken_REG));
        bufp->chgIData(oldp+486,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_target_address_REG),32);
        bufp->chgCData(oldp+487,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+488,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgIData(oldp+489,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_RD_data_REG),32);
        bufp->chgCData(oldp+490,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_ROB_index_REG),6);
        bufp->chgCData(oldp+491,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgCData(oldp+492,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgBit(oldp+493,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__io_FU_output_valid_REG));
        bufp->chgBit(oldp+494,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__BRANCH));
        bufp->chgBit(oldp+495,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__EQ));
        bufp->chgBit(oldp+496,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__NE));
        bufp->chgBit(oldp+497,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__LT));
        bufp->chgBit(oldp+498,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__GE));
        bufp->chgBit(oldp+499,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__LTU));
        bufp->chgBit(oldp+500,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__GEU));
        bufp->chgBit(oldp+501,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__JAL));
        bufp->chgBit(oldp+502,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU0__DOT__branch_unit__DOT__unnamedblk1__DOT__JALR));
        bufp->chgWData(oldp+503,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_3),186);
        __Vtemp_91[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_91[1U] = 0U;
        __Vtemp_91[2U] = 0U;
        __Vtemp_91[3U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                          << 0x18U);
        __Vtemp_91[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_91[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result 
                                        >> 7U));
        __Vtemp_91[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+509,(__Vtemp_91),193);
        bufp->chgBit(oldp+516,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__monitor_output_REG));
        bufp->chgIData(oldp+517,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgIData(oldp+518,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+519,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgCData(oldp+520,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+521,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgCData(oldp+522,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+523,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgBit(oldp+524,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgIData(oldp+525,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+526,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+527,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgWData(oldp+528,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___GEN_2),186);
        __Vtemp_97[0U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG) 
                           << 0xdU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_ROB_index_REG) 
                                        << 7U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG) 
                                                   << 3U) 
                                                  | ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG) 
                                                     << 1U))));
        __Vtemp_97[1U] = 0U;
        __Vtemp_97[2U] = 0U;
        __Vtemp_97[3U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                          << 0x18U);
        __Vtemp_97[4U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result 
                           << 0x19U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG) 
                                         << 0x18U) 
                                        | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG 
                                           >> 8U)));
        __Vtemp_97[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG) 
                           << 0x19U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result 
                                        >> 7U));
        __Vtemp_97[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG;
        bufp->chgWData(oldp+534,(__Vtemp_97),193);
        bufp->chgBit(oldp+541,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__monitor_output_REG));
        bufp->chgIData(oldp+542,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result),32);
        bufp->chgIData(oldp+543,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_PC_REG),32);
        bufp->chgCData(oldp+544,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_fetch_packet_index_REG),2);
        bufp->chgCData(oldp+545,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG),7);
        bufp->chgBit(oldp+546,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_valid_REG));
        bufp->chgCData(oldp+547,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_MOB_index_REG),4);
        bufp->chgCData(oldp+548,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_FTQ_index_REG),4);
        bufp->chgBit(oldp+549,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_valid_REG));
        bufp->chgIData(oldp+550,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__IMM_signed),32);
        bufp->chgIData(oldp+551,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__operand2_unsigned),32);
        bufp->chgCData(oldp+552,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__unnamedblk1__DOT__shamt),5);
        bufp->chgCData(oldp+553,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_32))
                                   : 0U)),6);
        bufp->chgCData(oldp+554,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_33))
                                   : 0U)),6);
        bufp->chgCData(oldp+555,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_34))
                                   : 0U)),6);
        bufp->chgCData(oldp+556,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_35))
                                   : 0U)),6);
        bufp->chgCData(oldp+557,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_36))
                                   : 0U)),6);
        bufp->chgCData(oldp+558,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid)
                                   ? (0x3fU & (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_37))
                                   : 0U)),6);
        bufp->chgCData(oldp+559,((0x3fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits[2U] 
                                           >> 4U))),6);
        bufp->chgCData(oldp+560,((0x3fU & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits[2U] 
                                            << 4U) 
                                           | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits[1U] 
                                              >> 0x1cU)))),6);
        bufp->chgIData(oldp+561,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R7_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R7_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+562,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R6_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R6_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+563,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R5_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R5_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+564,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R4_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R4_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+565,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R3_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R3_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+566,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R2_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R2_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+567,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R1_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R1_addr_d0]
                                   : 0U)),32);
        bufp->chgIData(oldp+568,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R0_en_d0)
                                   ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_PRF__DOT__mem_ext__DOT___R0_addr_d0]
                                   : 0U)),32);
        bufp->chgCData(oldp+569,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_hfa895d08_2_0))),6);
        bufp->chgCData(oldp+570,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG))),6);
        bufp->chgCData(oldp+571,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG))),6);
        bufp->chgCData(oldp+572,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_hfa895d08_2_67))),6);
        bufp->chgBit(oldp+573,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid));
        bufp->chgBit(oldp+574,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid_1));
        bufp->chgBit(oldp+575,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid_2));
        bufp->chgBit(oldp+576,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RD_valid_3));
        bufp->chgIData(oldp+577,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0),32);
        bufp->chgIData(oldp+578,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_3),32);
        bufp->chgIData(oldp+579,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_hfa895d08_2_67)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_3)),32);
        bufp->chgIData(oldp+580,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__io_FU_output_bits_RD_REG)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU2__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgIData(oldp+581,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__io_FU_output_bits_RD_REG)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__FU1__DOT__ALU__DOT__arithmetic_result)),32);
        bufp->chgIData(oldp+582,(((0U == (0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____VdfgRegularize_hfa895d08_2_0)))
                                   ? 0U : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_PRF__io_wdata_0)),32);
        bufp->chgBit(oldp+583,((0U != (7U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries) 
                                             >> 2U)))));
        bufp->chgBit(oldp+584,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_0_valid));
        bufp->chgWData(oldp+585,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_2),90);
        bufp->chgBit(oldp+588,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_1_valid));
        bufp->chgWData(oldp+589,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_3),90);
        bufp->chgBit(oldp+592,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_2_valid));
        bufp->chgWData(oldp+593,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_4),90);
        bufp->chgBit(oldp+596,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____Vcellinp__INT_RS__io_backend_packet_3_valid));
        bufp->chgWData(oldp+597,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT___GEN_5),90);
        bufp->chgBit(oldp+600,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid) 
                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions) 
                                   >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_RS_index)))));
        bufp->chgWData(oldp+601,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___INT_RS_io_RF_inputs_0_bits),90);
        bufp->chgBit(oldp+604,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid) 
                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions) 
                                   >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_RS_index)))));
        bufp->chgWData(oldp+605,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___INT_RS_io_RF_inputs_1_bits),90);
        bufp->chgBit(oldp+608,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid) 
                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions) 
                                   >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_RS_index)))));
        bufp->chgWData(oldp+609,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___INT_RS_io_RF_inputs_2_bits),90);
        bufp->chgSData(oldp+612,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__schedulable_instructions),16);
        bufp->chgWData(oldp+613,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__reservation_station),1456);
        bufp->chgSData(oldp+659,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__RS1_match),16);
        bufp->chgSData(oldp+660,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__RS2_match),16);
        bufp->chgCData(oldp+661,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_RS_index),4);
        bufp->chgBit(oldp+662,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port0_valid));
        bufp->chgCData(oldp+663,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_RS_index),4);
        bufp->chgBit(oldp+664,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port1_valid));
        bufp->chgCData(oldp+665,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_RS_index),4);
        bufp->chgBit(oldp+666,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__port2_valid));
        bufp->chgCData(oldp+667,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__availalbe_RS_entries),5);
        bufp->chgCData(oldp+668,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary),4);
        bufp->chgCData(oldp+669,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_1),4);
        bufp->chgCData(oldp+670,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_2),4);
        bufp->chgCData(oldp+671,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__unnamedblk1__DOT__allocateIndexBinary_3),4);
        bufp->chgBit(oldp+672,((0U != (7U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__availalbe_RS_entries) 
                                             >> 2U)))));
        bufp->chgBit(oldp+673,((IData)(((0x100000U 
                                         == (0x300000U 
                                             & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[1U])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hf3f37da3_3_4)))));
        bufp->chgBit(oldp+674,((IData)(((0x4000U == 
                                         (0xc000U & 
                                          vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[4U])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hf3f37da3_3_5)))));
        bufp->chgBit(oldp+675,((IData)(((0x100U == 
                                         (0x300U & 
                                          vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[7U])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hf3f37da3_3_6)))));
        bufp->chgBit(oldp+676,((IData)(((4U == (0xcU 
                                                & vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits[0xaU])) 
                                        & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT____VdfgRegularize_hf3f37da3_3_7)))));
        bufp->chgIData(oldp+677,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MOB_io_reserved_pointers),20);
        bufp->chgBit(oldp+678,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_valid));
        bufp->chgWData(oldp+679,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT___MEM_RS_io_RF_inputs_3_bits),90);
        bufp->chgWData(oldp+682,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__reservation_station),1968);
        bufp->chgCData(oldp+744,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__front_pointer),5);
        bufp->chgCData(oldp+745,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__back_pointer),5);
        bufp->chgCData(oldp+746,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__front_pointer))),4);
        bufp->chgCData(oldp+747,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__back_pointer))),4);
        bufp->chgCData(oldp+748,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__written_vec),4);
        bufp->chgSData(oldp+749,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__RS1_match),16);
        bufp->chgSData(oldp+750,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__RS2_match),16);
        bufp->chgCData(oldp+751,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MEM_RS__DOT__availalbe_RS_entries),5);
        bufp->chgBit(oldp+752,((0U != (7U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__availalbe_MOB_entries) 
                                             >> 2U)))));
        __Vtemp_98[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[0U];
        __Vtemp_98[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[1U];
        __Vtemp_98[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[2U];
        __Vtemp_98[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[3U];
        __Vtemp_98[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[4U];
        __Vtemp_98[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits[5U];
        __Vtemp_98[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid;
        bufp->chgWData(oldp+753,(__Vtemp_98),193);
        bufp->chgSData(oldp+760,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_stores),16);
        bufp->chgSData(oldp+761,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_loads),16);
        bufp->chgSData(oldp+762,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_23),16);
        bufp->chgCData(oldp+763,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__written_vec),4);
        bufp->chgCData(oldp+764,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__front_pointer),5);
        bufp->chgCData(oldp+765,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__back_pointer),5);
        bufp->chgCData(oldp+766,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__front_pointer))),4);
        bufp->chgCData(oldp+767,((0xfU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__back_pointer))),4);
        bufp->chgWData(oldp+768,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB),1424);
        bufp->chgQData(oldp+813,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__age_vector),64);
        bufp->chgQData(oldp+815,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__byte_sels),64);
        bufp->chgWData(oldp+817,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__wr_bytes),512);
        bufp->chgBit(oldp+833,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[2U] 
                                             >> 0x16U)))));
        bufp->chgBit(oldp+834,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[2U] 
                                             >> 0x16U)))));
        bufp->chgBit(oldp+835,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[5U] 
                                             >> 0xfU)))));
        bufp->chgBit(oldp+836,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[5U] 
                                             >> 0xfU)))));
        bufp->chgBit(oldp+837,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[8U] 
                                             >> 8U)))));
        bufp->chgBit(oldp+838,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[8U] 
                                             >> 8U)))));
        bufp->chgBit(oldp+839,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xbU] 
                                             >> 1U)))));
        bufp->chgBit(oldp+840,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xbU] 
                                             >> 1U)))));
        bufp->chgBit(oldp+841,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xdU] 
                                             >> 0x1aU)))));
        bufp->chgBit(oldp+842,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0xdU] 
                                             >> 0x1aU)))));
        bufp->chgBit(oldp+843,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x10U] 
                                             >> 0x13U)))));
        bufp->chgBit(oldp+844,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x10U] 
                                             >> 0x13U)))));
        bufp->chgBit(oldp+845,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x13U] 
                                             >> 0xcU)))));
        bufp->chgBit(oldp+846,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x13U] 
                                             >> 0xcU)))));
        bufp->chgBit(oldp+847,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x16U] 
                                             >> 5U)))));
        bufp->chgBit(oldp+848,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x16U] 
                                             >> 5U)))));
        bufp->chgBit(oldp+849,((1U == (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x18U] 
                                       >> 0x1eU))));
        bufp->chgBit(oldp+850,((2U == (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x18U] 
                                       >> 0x1eU))));
        bufp->chgBit(oldp+851,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1bU] 
                                             >> 0x17U)))));
        bufp->chgBit(oldp+852,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1bU] 
                                             >> 0x17U)))));
        bufp->chgBit(oldp+853,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1eU] 
                                             >> 0x10U)))));
        bufp->chgBit(oldp+854,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x1eU] 
                                             >> 0x10U)))));
        bufp->chgBit(oldp+855,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x21U] 
                                             >> 9U)))));
        bufp->chgBit(oldp+856,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x21U] 
                                             >> 9U)))));
        bufp->chgBit(oldp+857,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x24U] 
                                             >> 2U)))));
        bufp->chgBit(oldp+858,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x24U] 
                                             >> 2U)))));
        bufp->chgBit(oldp+859,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x26U] 
                                             >> 0x1bU)))));
        bufp->chgBit(oldp+860,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x26U] 
                                             >> 0x1bU)))));
        bufp->chgBit(oldp+861,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x29U] 
                                             >> 0x14U)))));
        bufp->chgBit(oldp+862,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x29U] 
                                             >> 0x14U)))));
        bufp->chgBit(oldp+863,((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x2cU] 
                                             >> 0xdU)))));
        bufp->chgBit(oldp+864,((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__MOB[0x2cU] 
                                             >> 0xdU)))));
        bufp->chgBit(oldp+865,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__fire_store));
        bufp->chgCData(oldp+866,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__load_index),4);
        bufp->chgCData(oldp+867,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_load_index),4);
        bufp->chgCData(oldp+868,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__possible_FU_store_index),4);
        bufp->chgCData(oldp+869,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__response_age),4);
        bufp->chgIData(oldp+870,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__data_out),32);
        bufp->chgCData(oldp+871,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__availalbe_MOB_entries),5);
        bufp->chgBit(oldp+872,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__empty)))));
        bufp->chgWData(oldp+873,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.io_deq_bits),192);
        bufp->chgBit(oldp+879,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__empty));
        bufp->chgBit(oldp+880,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__empty)))));
        bufp->chgWData(oldp+881,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.io_deq_bits),192);
        bufp->chgBit(oldp+887,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_valid));
        bufp->chgWData(oldp+888,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_arbiter_io_out_bits),192);
        bufp->chgBit(oldp+894,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__incoming_is_load));
        bufp->chgBit(oldp+895,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__unnamedblk1__DOT__incoming_is_store));
        bufp->chgBit(oldp+896,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT____Vcellinp__frontend__io_renamed_decoded_fetch_packet_ready));
        bufp->chgBit(oldp+897,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__full)))));
        bufp->chgBit(oldp+898,((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__full)) 
                                      & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__empty))))));
        bufp->chgWData(oldp+899,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.io_deq_bits),110);
        bufp->chgBit(oldp+903,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__io_predictions_in_ready_REG));
        bufp->chgBit(oldp+904,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty)))));
        bufp->chgWData(oldp+905,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT___ram_ext_R0_data),110);
        bufp->chgCData(oldp+909,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__maybe_full) 
                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ptr_match)) 
                                   << 4U) | (0xfU & 
                                             ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__enq_ptr_value) 
                                              - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value))))),5);
        bufp->chgCData(oldp+910,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+911,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+912,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__maybe_full));
        bufp->chgBit(oldp+913,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ptr_match));
        bufp->chgBit(oldp+914,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty));
        bufp->chgBit(oldp+915,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__full));
        bufp->chgBit(oldp+916,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq));
        bufp->chgBit(oldp+917,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq));
        bufp->chgCData(oldp+918,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq)
                                           ? ((0xfU 
                                               == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value))
                                               ? 0U
                                               : ((IData)(1U) 
                                                  + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value)))
                                           : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__deq_ptr_value)))),4);
        bufp->chgWData(oldp+919,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT____Vcellinp__ram_ext__W0_data),110);
        __Vtemp_101[0U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq)));
        __Vtemp_101[1U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq)));
        __Vtemp_101[2U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq)));
        __Vtemp_101[3U] = (0x3fffU & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_enq))));
        bufp->chgWData(oldp+923,(__Vtemp_101),110);
        bufp->chgWData(oldp+927,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+931,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[1]),110);
        bufp->chgWData(oldp+935,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[2]),110);
        bufp->chgWData(oldp+939,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[3]),110);
        bufp->chgWData(oldp+943,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[4]),110);
        bufp->chgWData(oldp+947,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[5]),110);
        bufp->chgWData(oldp+951,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[6]),110);
        bufp->chgWData(oldp+955,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[7]),110);
        bufp->chgWData(oldp+959,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[8]),110);
        bufp->chgWData(oldp+963,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[9]),110);
        bufp->chgWData(oldp+967,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[10]),110);
        bufp->chgWData(oldp+971,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[11]),110);
        bufp->chgWData(oldp+975,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[12]),110);
        bufp->chgWData(oldp+979,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[13]),110);
        bufp->chgWData(oldp+983,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[14]),110);
        bufp->chgWData(oldp+987,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__ram_ext__DOT__Memory[15]),110);
        bufp->chgBit(oldp+991,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__io_fetch_packet_ready_REG));
        bufp->chgBit(oldp+992,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__empty)))));
        bufp->chgWData(oldp+993,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                 [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1]),234);
        bufp->chgBit(oldp+1001,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__io_predictions_in_ready_REG));
        bufp->chgBit(oldp+1002,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__empty)))));
        bufp->chgWData(oldp+1003,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.io_deq_bits),110);
        bufp->chgBit(oldp+1007,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__full)))));
        bufp->chgBit(oldp+1008,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__empty)))));
        bufp->chgWData(oldp+1009,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.io_deq_bits),434);
        bufp->chgBit(oldp+1023,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__empty)))));
        bufp->chgBit(oldp+1024,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__monitor_output_REG));
        bufp->chgBit(oldp+1025,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1026,((0x3ffffffffffULL 
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
        bufp->chgWData(oldp+1028,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_0_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1031,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__instructionType),5);
        bufp->chgBit(oldp+1032,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1033,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__needs_ALU));
        bufp->chgCData(oldp+1034,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_0__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1035,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1036,((0x3ffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U])) 
                                       << 0x18U) | 
                                      ((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][2U])) 
                                       >> 8U)))),42);
        bufp->chgWData(oldp+1038,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_1_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1041,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__instructionType),5);
        bufp->chgBit(oldp+1042,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1043,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__needs_ALU));
        bufp->chgCData(oldp+1044,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_1__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1045,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1046,((0x3ffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                       [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][4U])) 
                                       << 0xeU) | ((QData)((IData)(
                                                                   vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory
                                                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1][3U])) 
                                                   >> 0x12U)))),42);
        bufp->chgWData(oldp+1048,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_2_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1051,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__instructionType),5);
        bufp->chgBit(oldp+1052,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1053,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__needs_ALU));
        bufp->chgCData(oldp+1054,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_2__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1055,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__io_decoded_instruction_valid));
        bufp->chgQData(oldp+1056,((0x3ffffffffffULL 
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
        bufp->chgWData(oldp+1058,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___decoders_3_io_decoded_instruction_bits),90);
        bufp->chgCData(oldp+1061,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__instructionType),5);
        bufp->chgBit(oldp+1062,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__needs_branch_unit));
        bufp->chgBit(oldp+1063,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__needs_ALU));
        bufp->chgCData(oldp+1064,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoders_3__DOT__next_ALU_port),6);
        bufp->chgBit(oldp+1065,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full)))));
        bufp->chgBit(oldp+1066,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_prediction_valid));
        bufp->chgBit(oldp+1067,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__BTB_Q__io_deq_ready));
        bufp->chgBit(oldp+1068,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___BTB_Q_io_deq_valid));
        bufp->chgCData(oldp+1069,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value))))),5);
        bufp->chgBit(oldp+1070,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T));
        bufp->chgBit(oldp+1071,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_enq));
        bufp->chgBit(oldp+1072,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_deq));
        bufp->chgQData(oldp+1073,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT___ram_ext_R0_data),53);
        bufp->chgCData(oldp+1075,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1076,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1077,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1078,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1079,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__empty));
        bufp->chgBit(oldp+1080,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full));
        bufp->chgCData(oldp+1081,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__deq_ptr_value)))),4);
        bufp->chgQData(oldp+1082,((0x1fffffffffffffULL 
                                   & (- (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__do_enq))))),53);
        bufp->chgQData(oldp+1084,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[0]),53);
        bufp->chgQData(oldp+1086,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[1]),53);
        bufp->chgQData(oldp+1088,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[2]),53);
        bufp->chgQData(oldp+1090,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[3]),53);
        bufp->chgQData(oldp+1092,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[4]),53);
        bufp->chgQData(oldp+1094,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[5]),53);
        bufp->chgQData(oldp+1096,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[6]),53);
        bufp->chgQData(oldp+1098,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[7]),53);
        bufp->chgQData(oldp+1100,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[8]),53);
        bufp->chgQData(oldp+1102,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[9]),53);
        bufp->chgQData(oldp+1104,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[10]),53);
        bufp->chgQData(oldp+1106,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[11]),53);
        bufp->chgQData(oldp+1108,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[12]),53);
        bufp->chgQData(oldp+1110,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[13]),53);
        bufp->chgQData(oldp+1112,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[14]),53);
        bufp->chgQData(oldp+1114,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__ram_ext__DOT__Memory[15]),53);
        bufp->chgBit(oldp+1116,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full)))));
        bufp->chgBit(oldp+1117,((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T)) 
                                       & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__BTB_Q__DOT__full))))));
        bufp->chgCData(oldp+1118,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value))))),5);
        bufp->chgBit(oldp+1119,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_103[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_103[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_103[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
        } else {
            __Vtemp_103[0U] = 0U;
            __Vtemp_103[1U] = 0U;
            __Vtemp_103[2U] = 0U;
        }
        bufp->chgWData(oldp+1120,(__Vtemp_103),65);
        bufp->chgCData(oldp+1123,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1124,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1125,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1126,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1127,(((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__maybe_full)) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ptr_match))));
        bufp->chgBit(oldp+1128,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full));
        __Vtemp_106[0U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq)));
        __Vtemp_106[1U] = (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq)));
        __Vtemp_106[2U] = (1U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq))));
        bufp->chgWData(oldp+1129,(__Vtemp_106),65);
        bufp->chgWData(oldp+1132,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[0]),65);
        bufp->chgWData(oldp+1135,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[1]),65);
        bufp->chgWData(oldp+1138,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[2]),65);
        bufp->chgWData(oldp+1141,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[3]),65);
        bufp->chgWData(oldp+1144,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[4]),65);
        bufp->chgWData(oldp+1147,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[5]),65);
        bufp->chgWData(oldp+1150,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[6]),65);
        bufp->chgWData(oldp+1153,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[7]),65);
        bufp->chgWData(oldp+1156,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[8]),65);
        bufp->chgWData(oldp+1159,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[9]),65);
        bufp->chgWData(oldp+1162,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[10]),65);
        bufp->chgWData(oldp+1165,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[11]),65);
        bufp->chgWData(oldp+1168,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[12]),65);
        bufp->chgWData(oldp+1171,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[13]),65);
        bufp->chgWData(oldp+1174,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[14]),65);
        bufp->chgWData(oldp+1177,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__ram_ext__DOT__Memory[15]),65);
        bufp->chgQData(oldp+1180,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT)) 
                                    << 0x27U) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS)) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out))))),46);
        bufp->chgBit(oldp+1182,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___bp_io_flush_T)))));
        bufp->chgIData(oldp+1183,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__PC_reg),32);
        bufp->chgIData(oldp+1184,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__flush_PC_reg),32);
        bufp->chgBit(oldp+1185,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__PC_gen__DOT__REG));
        bufp->chgBit(oldp+1186,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__bp__io_predict_valid));
        bufp->chgBit(oldp+1187,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_valid_REG));
        bufp->chgBit(oldp+1188,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_hit_REG) 
                                  == (0x3ffffU & (IData)(
                                                         (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out 
                                                          >> 0x25U)))) 
                                 & ((IData)((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out 
                                             >> 0x37U)) 
                                    & ((3U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out)) 
                                       >= (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__access_fetch_packet_index))))));
        bufp->chgQData(oldp+1189,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_output_BTB_valid_REG)) 
                                    << 0x37U) | (0x7fffffffffffffULL 
                                                 & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out))),56);
        __Vtemp_107[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[0U];
        __Vtemp_107[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[1U];
        __Vtemp_107[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[2U];
        __Vtemp_107[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[3U];
        __Vtemp_107[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[4U];
        __Vtemp_107[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT___GEN_3) 
                            << 8U) | vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__BRU__DOT___GEN[5U]);
        bufp->chgWData(oldp+1191,(__Vtemp_107),169);
        bufp->chgCData(oldp+1197,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__access_fetch_packet_index),3);
        bufp->chgSData(oldp+1198,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_hit_REG),16);
        bufp->chgBit(oldp+1199,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__io_BTB_output_BTB_valid_REG));
        bufp->chgQData(oldp+1200,((0x80000000000000ULL 
                                   | (((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_104)) 
                                       << 0x25U) | 
                                      (((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_48)) 
                                        << 5U) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_46) 
                                                                   << 2U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_47)))))))),56);
        bufp->chgQData(oldp+1202,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT___BTB_memory_io_data_out),56);
        bufp->chgSData(oldp+1204,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT____Vcellinp__BTB_memory__io_wr_addr),12);
        bufp->chgBit(oldp+1205,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT___GEN_3));
        bufp->chgQData(oldp+1206,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0ULL)),56);
        bufp->chgBit(oldp+1208,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__hazard_reg));
        bufp->chgQData(oldp+1209,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT__din_buff),56);
        bufp->chgQData(oldp+1211,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT____Vcellinp__mem_ext__W0_data),56);
        bufp->chgQData(oldp+1213,((0xffffffffffffffULL 
                                   & (- (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__BTB__DOT__BTB_memory__DOT___GEN_3))))),56);
        bufp->chgCData(oldp+1215,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_revert_NEXT),7);
        bufp->chgCData(oldp+1216,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_revert_TOS),7);
        bufp->chgBit(oldp+1217,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT____Vcellinp__RAS__io_revert_valid));
        bufp->chgIData(oldp+1218,((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out)),32);
        bufp->chgCData(oldp+1219,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__NEXT),7);
        bufp->chgCData(oldp+1220,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__TOS),7);
        bufp->chgCData(oldp+1221,((0x7fU & (IData)(
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out 
                                                    >> 0x20U)))),7);
        bufp->chgQData(oldp+1222,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT___RAS_memory_io_data_out),39);
        bufp->chgBit(oldp+1224,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__hazard_reg));
        bufp->chgQData(oldp+1225,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__din_buff),39);
        bufp->chgQData(oldp+1227,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__RAS__DOT__RAS_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0ULL)),39);
        bufp->chgBit(oldp+1229,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0) 
                                 & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                    [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0] 
                                    >> 1U))));
        bufp->chgBit(oldp+1230,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__io_valid_REG));
        bufp->chgWData(oldp+1231,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT___GEN_0),169);
        bufp->chgSData(oldp+1237,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__hashed_commit_addr),16);
        bufp->chgSData(oldp+1238,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT_io_addrC_REG),16);
        bufp->chgBit(oldp+1239,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT_io_writeEnableC_REG));
        bufp->chgBit(oldp+1240,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__REG));
        bufp->chgSData(oldp+1241,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0]
                                    : 0U)),16);
        bufp->chgSData(oldp+1242,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data),16);
        bufp->chgCData(oldp+1243,((3U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__REG)
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
        bufp->chgCData(oldp+1244,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT___mem_ext_R0_data),2);
        bufp->chgCData(oldp+1245,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__gshare__DOT__PHT__DOT__mem_ext__DOT___R1_addr_d0]
                                    : 0U)),2);
        bufp->chgBit(oldp+1246,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__full)))));
        bufp->chgBit(oldp+1247,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__full));
        bufp->chgQData(oldp+1248,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__ram),53);
        bufp->chgBit(oldp+1250,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__bp__DOT__prediction_skid_buffer__DOT__do_enq));
        bufp->chgBit(oldp+1251,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__io_fetch_packet_ready_REG));
        bufp->chgBit(oldp+1252,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT___instruction_Q_io_deq_valid));
        __Vtemp_108[0U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11)))))) 
                            << 0x1eU) | ((0x3fffc000U 
                                          & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty)
                                               ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_13)
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
                                                  ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_14)
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
                                                   ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____VdfgRegularize_h759557b6_0_15)
                                                   : 
                                                  ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0)
                                                    ? 
                                                   vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U]
                                                    : 0U))))));
        __Vtemp_113[0U] = __Vtemp_108[0U];
        __Vtemp_113[1U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11)))))) 
                            >> 2U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                                 << 0xaU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11))))) 
                                               >> 0x20U)) 
                                      << 0x1eU));
        __Vtemp_113[2U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_12)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_13) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_14)))))) 
                            << 8U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_9)) 
                                                 << 0xaU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_10) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_11))))) 
                                               >> 0x20U)) 
                                      >> 2U));
        __Vtemp_113[3U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_15)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_16) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_17)))))) 
                            << 0x12U) | (((IData)((
                                                   ((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_12)) 
                                                    << 0xaU) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_13) 
                                                                       << 6U) 
                                                                      | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_14)))))) 
                                          >> 0x18U) 
                                         | ((IData)(
                                                    ((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_12)) 
                                                       << 0xaU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_13) 
                                                                          << 6U) 
                                                                         | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_14))))) 
                                                     >> 0x20U)) 
                                            << 8U)));
        __Vtemp_113[4U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20)))))) 
                            << 0x1cU) | (((IData)((
                                                   ((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_15)) 
                                                    << 0xaU) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_16) 
                                                                       << 6U) 
                                                                      | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_17)))))) 
                                          >> 0xeU) 
                                         | ((IData)(
                                                    ((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_15)) 
                                                       << 0xaU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_16) 
                                                                          << 6U) 
                                                                         | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_17))))) 
                                                     >> 0x20U)) 
                                            << 0x12U)));
        __Vtemp_113[5U] = (((IData)((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                      << 0xaU) | (QData)((IData)(
                                                                 (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                   << 6U) 
                                                                  | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20)))))) 
                            >> 4U) | ((IData)(((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                                 << 0xaU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                    << 6U) 
                                                                   | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20))))) 
                                               >> 0x20U)) 
                                      << 0x1cU));
        __Vtemp_113[6U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_0 
                            << 0xaU) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_1) 
                                         << 6U) | ((IData)(
                                                           ((((QData)((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_18)) 
                                                              << 0xaU) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_19) 
                                                                                << 6U) 
                                                                                | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_20))))) 
                                                            >> 0x20U)) 
                                                   >> 4U)));
        __Vtemp_113[7U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_0 
                           >> 0x16U);
        bufp->chgWData(oldp+1253,(__Vtemp_113),234);
        bufp->chgCData(oldp+1261,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value))))),5);
        bufp->chgBit(oldp+1262,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq));
        bufp->chgBit(oldp+1263,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_deq));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_114[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_114[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_114[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_114[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_114[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_114[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_114[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_114[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT___R0_addr_d0][7U];
        } else {
            __Vtemp_114[0U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[0U];
            __Vtemp_114[1U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[1U];
            __Vtemp_114[2U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[2U];
            __Vtemp_114[3U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[3U];
            __Vtemp_114[4U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[4U];
            __Vtemp_114[5U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[5U];
            __Vtemp_114[6U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[6U];
            __Vtemp_114[7U] = Vtop_v2__ConstPool__CONST_h9513bbd8_0[7U];
        }
        bufp->chgWData(oldp+1264,(__Vtemp_114),234);
        bufp->chgCData(oldp+1272,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1273,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1274,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1275,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1276,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__empty));
        bufp->chgBit(oldp+1277,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ptr_match) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__maybe_full))));
        bufp->chgCData(oldp+1278,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__deq_ptr_value)))),4);
        bufp->chgWData(oldp+1279,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT____Vcellinp__ram_ext__W0_data),234);
        __Vtemp_116[0U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[1U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[2U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[3U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[4U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[5U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[6U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        __Vtemp_116[7U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__do_enq))));
        bufp->chgWData(oldp+1287,(__Vtemp_116),234);
        bufp->chgWData(oldp+1295,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[0]),234);
        bufp->chgWData(oldp+1303,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[1]),234);
        bufp->chgWData(oldp+1311,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[2]),234);
        bufp->chgWData(oldp+1319,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[3]),234);
        bufp->chgWData(oldp+1327,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[4]),234);
        bufp->chgWData(oldp+1335,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[5]),234);
        bufp->chgWData(oldp+1343,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[6]),234);
        bufp->chgWData(oldp+1351,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[7]),234);
        bufp->chgWData(oldp+1359,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[8]),234);
        bufp->chgWData(oldp+1367,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[9]),234);
        bufp->chgWData(oldp+1375,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[10]),234);
        bufp->chgWData(oldp+1383,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[11]),234);
        bufp->chgWData(oldp+1391,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[12]),234);
        bufp->chgWData(oldp+1399,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[13]),234);
        bufp->chgWData(oldp+1407,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[14]),234);
        bufp->chgWData(oldp+1415,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__instruction_Q__DOT__ram_ext__DOT__Memory[15]),234);
        bufp->chgBit(oldp+1423,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__io_prediction_ready_REG));
        bufp->chgCData(oldp+1424,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__is_control),4);
        bufp->chgBit(oldp+1425,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL));
        bufp->chgBit(oldp+1426,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR));
        bufp->chgBit(oldp+1427,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH));
        bufp->chgBit(oldp+1428,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_1));
        bufp->chgBit(oldp+1429,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_1));
        bufp->chgBit(oldp+1430,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_1));
        bufp->chgBit(oldp+1431,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_2));
        bufp->chgBit(oldp+1432,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_2));
        bufp->chgBit(oldp+1433,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_2));
        bufp->chgBit(oldp+1434,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JAL_3));
        bufp->chgBit(oldp+1435,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_JALR_3));
        bufp->chgBit(oldp+1436,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__curr_is_BRANCH_3));
        bufp->chgIData(oldp+1437,((0xfffffff0U & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT____VdfgRegularize_h5399b261_0_0)),32);
        bufp->chgIData(oldp+1438,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__expected_next_PC),32);
        bufp->chgBit(oldp+1439,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__output_ready));
        bufp->chgBit(oldp+1440,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid));
        bufp->chgSData(oldp+1441,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__GHR),16);
        bufp->chgBit(oldp+1442,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__full)))));
        bufp->chgCData(oldp+1443,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap) 
                                               - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1))))),2);
        bufp->chgBit(oldp+1444,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap));
        bufp->chgBit(oldp+1445,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__wrap_1));
        bufp->chgBit(oldp+1446,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1447,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1448,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__empty));
        bufp->chgBit(oldp+1449,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__full));
        bufp->chgBit(oldp+1450,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq));
        __Vtemp_118[0U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[1U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[2U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[3U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[4U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[5U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[6U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        __Vtemp_118[7U] = (Vtop_v2__ConstPool__CONST_h5b979c07_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__do_enq))));
        bufp->chgWData(oldp+1451,(__Vtemp_118),234);
        bufp->chgWData(oldp+1459,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[0]),234);
        bufp->chgWData(oldp+1467,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__ram_ext__DOT__Memory[1]),234);
        bufp->chgBit(oldp+1475,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__final_fetch_packet_out_Q__DOT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+1476,((1U & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__full)) 
                                       & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__empty))))));
        bufp->chgBit(oldp+1477,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__io_decoded_fetch_packet_ready_REG));
        bufp->chgBit(oldp+1478,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__empty)))));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_119[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_119[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_119[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_119[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_119[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_119[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_119[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_119[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][7U];
            __Vtemp_119[8U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][8U];
            __Vtemp_119[9U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][9U];
            __Vtemp_119[0xaU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xaU];
            __Vtemp_119[0xbU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xbU];
            __Vtemp_119[0xcU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xcU];
            __Vtemp_119[0xdU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT___R0_addr_d0][0xdU];
        } else {
            __Vtemp_119[0U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0U];
            __Vtemp_119[1U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[1U];
            __Vtemp_119[2U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[2U];
            __Vtemp_119[3U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[3U];
            __Vtemp_119[4U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[4U];
            __Vtemp_119[5U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[5U];
            __Vtemp_119[6U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[6U];
            __Vtemp_119[7U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[7U];
            __Vtemp_119[8U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[8U];
            __Vtemp_119[9U] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[9U];
            __Vtemp_119[0xaU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xaU];
            __Vtemp_119[0xbU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xbU];
            __Vtemp_119[0xcU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xcU];
            __Vtemp_119[0xdU] = Vtop_v2__ConstPool__CONST_h9fd76c70_0[0xdU];
        }
        bufp->chgWData(oldp+1479,(__Vtemp_119),434);
        bufp->chgCData(oldp+1493,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ptr_match)) 
                                    << 4U) | (0xfU 
                                              & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__enq_ptr_value) 
                                                 - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value))))),5);
        bufp->chgCData(oldp+1494,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__enq_ptr_value),4);
        bufp->chgCData(oldp+1495,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value),4);
        bufp->chgBit(oldp+1496,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__maybe_full));
        bufp->chgBit(oldp+1497,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ptr_match));
        bufp->chgBit(oldp+1498,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__empty));
        bufp->chgBit(oldp+1499,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__full));
        bufp->chgBit(oldp+1500,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq));
        bufp->chgBit(oldp+1501,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq));
        bufp->chgCData(oldp+1502,((0xfU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq)
                                            ? ((0xfU 
                                                == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value))
                                                ? 0U
                                                : ((IData)(1U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value)))
                                            : (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__deq_ptr_value)))),4);
        bufp->chgWData(oldp+1503,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT____Vcellinp__ram_ext__W0_data),434);
        __Vtemp_121[0U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[1U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[1U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[2U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[2U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[3U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[3U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[4U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[4U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[5U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[5U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[6U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[6U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[7U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[7U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[8U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[8U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[9U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[9U] 
                           & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[0xaU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xaU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[0xbU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xbU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[0xcU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xcU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        __Vtemp_121[0xdU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xdU] 
                             & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_enq))));
        bufp->chgWData(oldp+1517,(__Vtemp_121),434);
        bufp->chgWData(oldp+1531,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[0]),434);
        bufp->chgWData(oldp+1545,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[1]),434);
        bufp->chgWData(oldp+1559,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[2]),434);
        bufp->chgWData(oldp+1573,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[3]),434);
        bufp->chgWData(oldp+1587,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[4]),434);
        bufp->chgWData(oldp+1601,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[5]),434);
        bufp->chgWData(oldp+1615,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[6]),434);
        bufp->chgWData(oldp+1629,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[7]),434);
        bufp->chgWData(oldp+1643,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[8]),434);
        bufp->chgWData(oldp+1657,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[9]),434);
        bufp->chgWData(oldp+1671,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[10]),434);
        bufp->chgWData(oldp+1685,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[11]),434);
        bufp->chgWData(oldp+1699,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[12]),434);
        bufp->chgWData(oldp+1713,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[13]),434);
        bufp->chgWData(oldp+1727,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[14]),434);
        bufp->chgWData(oldp+1741,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__ram_ext__DOT__Memory[15]),434);
        bufp->chgCData(oldp+1755,(((2U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
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
        bufp->chgCData(oldp+1756,(((2U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
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
        bufp->chgCData(oldp+1757,(((2U & ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_588[
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
        bufp->chgCData(oldp+1758,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__initialReady),2);
        bufp->chgWData(oldp+1759,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__ready_memory),65);
        bufp->chgIData(oldp+1762,((((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102) 
                                    << 0xfU) | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101) 
                                                 << 0xaU) 
                                                | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100) 
                                                    << 5U) 
                                                   | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99))))),20);
        bufp->chgIData(oldp+1763,((((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98) 
                                    << 0xfU) | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97) 
                                                 << 0xaU) 
                                                | (((IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96) 
                                                    << 5U) 
                                                   | (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95))))),20);
        bufp->chgIData(oldp+1764,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_RD_values),20);
        bufp->chgCData(oldp+1765,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___WAW_handler_io_RAT_wr_en),4);
        bufp->chgIData(oldp+1766,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___WAW_handler_io_FL_RD_values),28);
        bufp->chgIData(oldp+1767,(((((0xdfU >= (0xffU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_3))))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_3))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_3)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_3)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_3)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_3))))))
                                      : 0U) << 0x15U) 
                                   | ((((0xdfU >= (0xffU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_2))))
                                         ? (0x7fU & 
                                            (((0U == 
                                               (0x1fU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_2))))
                                               ? 0U
                                               : (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_2)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_2)))))) 
                                             | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                (7U 
                                                 & (((IData)(7U) 
                                                     * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_2)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_2))))))
                                         : 0U) << 0xeU) 
                                      | ((((0xdfU >= 
                                            (0xffU 
                                             & ((IData)(7U) 
                                                * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_6))))
                                            ? (0x7fU 
                                               & (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_6))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_6)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_6)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_6)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_6))))))
                                            : 0U) << 7U) 
                                         | ((0xdfU 
                                             >= (0xffU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_8))))
                                             ? (0x7fU 
                                                & (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_8))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_8)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_8)))))) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_8)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__WAW_handler__DOT____VdfgRegularize_h440ec619_0_8))))))
                                             : 0U))))),28);
        bufp->chgIData(oldp+1768,(((((0xdfU >= (0xffU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102))))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_102))))))
                                      : 0U) << 0x15U) 
                                   | ((((0xdfU >= (0xffU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101))))
                                         ? (0x7fU & 
                                            (((0U == 
                                               (0x1fU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101))))
                                               ? 0U
                                               : (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101)))))) 
                                             | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                (7U 
                                                 & (((IData)(7U) 
                                                     * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_101))))))
                                         : 0U) << 0xeU) 
                                      | ((((0xdfU >= 
                                            (0xffU 
                                             & ((IData)(7U) 
                                                * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100))))
                                            ? (0x7fU 
                                               & (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_100))))))
                                            : 0U) << 7U) 
                                         | ((0xdfU 
                                             >= (0xffU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99))))
                                             ? (0x7fU 
                                                & (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99)))))) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_99))))))
                                             : 0U))))),28);
        bufp->chgIData(oldp+1769,(((((0xdfU >= (0xffU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98))))
                                      ? (0x7fU & ((
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_98))))))
                                      : 0U) << 0x15U) 
                                   | ((((0xdfU >= (0xffU 
                                                   & ((IData)(7U) 
                                                      * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97))))
                                         ? (0x7fU & 
                                            (((0U == 
                                               (0x1fU 
                                                & ((IData)(7U) 
                                                   * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97))))
                                               ? 0U
                                               : (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                  (((IData)(6U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97)))))) 
                                             | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                (7U 
                                                 & (((IData)(7U) 
                                                     * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97)) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_97))))))
                                         : 0U) << 0xeU) 
                                      | ((((0xdfU >= 
                                            (0xffU 
                                             & ((IData)(7U) 
                                                * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96))))
                                            ? (0x7fU 
                                               & (((0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96))))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                    (((IData)(6U) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96)))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x20U) 
                                                     - 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96)))))) 
                                                  | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (7U 
                                                      & (((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96)) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_96))))))
                                            : 0U) << 7U) 
                                         | ((0xdfU 
                                             >= (0xffU 
                                                 & ((IData)(7U) 
                                                    * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95))))
                                             ? (0x7fU 
                                                & (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95))))
                                                     ? 0U
                                                     : 
                                                    (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95)))))) 
                                                   | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT[
                                                      (7U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSelf->__VdfgRegularize_hd87f99a1_4_95))))))
                                             : 0U))))),28);
        bufp->chgWData(oldp+1770,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__commit_RAT),224);
        bufp->chgWData(oldp+1777,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__RAT__DOT__speculative_RAT),224);
        bufp->chgCData(oldp+1784,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____Vcellinp__WAW_handler__io_decoder_RD_valid_bits),4);
        bufp->chgCData(oldp+1785,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT____Vcellinp__free_list__io_rename_valid),4);
        bufp->chgCData(oldp+1786,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT___GEN_4),4);
        bufp->chgCData(oldp+1787,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer),7);
        bufp->chgBit(oldp+1788,((0x41U > (0x7fU & ((IData)(4U) 
                                                   + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets))))));
        bufp->chgBit(oldp+1789,((0U != (0x1fU & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets) 
                                                 >> 2U)))));
        bufp->chgCData(oldp+1790,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__back_pointer),7);
        bufp->chgCData(oldp+1791,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__front_pointer))),6);
        bufp->chgCData(oldp+1792,((0x3fU & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__back_pointer))),6);
        bufp->chgCData(oldp+1793,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__allocate_valid),4);
        bufp->chgCData(oldp+1794,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__available_elemets),7);
        bufp->chgWData(oldp+1795,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__valid_commit_ptr),448);
        bufp->chgQData(oldp+1809,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__valid_commit_valid),64);
        bufp->chgBit(oldp+1811,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__unnamedblk1__DOT__outputs_ready));
        bufp->chgIData(oldp+1812,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en),32);
        bufp->chgCData(oldp+1813,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[0U] 
                                         >> 4U))),2);
        bufp->chgCData(oldp+1814,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[0U] 
                                         >> 6U))),2);
        bufp->chgCData(oldp+1815,((0x3fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[1U] 
                                            >> 0xdU))),6);
        bufp->chgIData(oldp+1816,(((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[2U] 
                                    << 0x18U) | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[1U] 
                                                 >> 8U))),32);
        bufp->chgCData(oldp+1817,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE),2);
        bufp->chgCData(oldp+1818,((0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                            >> 0x12U))),5);
        bufp->chgCData(oldp+1819,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                         >> 5U))),2);
        __Vtemp_145[0U] = (IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
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
        __Vtemp_145[1U] = (IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
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
        __Vtemp_145[2U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__dataOut))));
        __Vtemp_145[3U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__dataOut))));
        __Vtemp_145[4U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__dataOut))));
        __Vtemp_145[5U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__dataOut))));
        __Vtemp_145[6U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__dataOut))));
        __Vtemp_145[7U] = (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__dataOut) 
                            << 0x18U) | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__dataOut) 
                                          << 0x10U) 
                                         | (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__dataOut) 
                                             << 8U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__dataOut))));
        bufp->chgWData(oldp+1820,(__Vtemp_145),256);
        bufp->chgWData(oldp+1828,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_AW_DATA_BUFFER),256);
        bufp->chgCData(oldp+1836,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE),2);
        bufp->chgIData(oldp+1837,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_counter),32);
        bufp->chgWData(oldp+1838,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_read_buffer),256);
        bufp->chgCData(oldp+1846,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE),2);
        bufp->chgIData(oldp+1847,(((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[2U] 
                                        << 0x18U) | 
                                       (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_25[1U] 
                                        >> 8U)) : 0U)),32);
        bufp->chgCData(oldp+1848,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_set),6);
        bufp->chgCData(oldp+1849,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__active_access_width),2);
        bufp->chgBit(oldp+1850,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__valid_hit_REG));
        bufp->chgBit(oldp+1851,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__valid_miss_REG));
        bufp->chgBit(oldp+1852,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__valid_write_hit_REG));
        bufp->chgCData(oldp+1853,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__hit_set_REG),6);
        bufp->chgCData(oldp+1854,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__hit_MOB_index_REG),4);
        bufp->chgIData(oldp+1855,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__miss_address_REG),32);
        bufp->chgCData(oldp+1856,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__miss_set_REG),6);
        bufp->chgIData(oldp+1857,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_write_data_REG),32);
        bufp->chgIData(oldp+1858,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r),32);
        bufp->chgIData(oldp+1859,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r_1),32);
        bufp->chgBit(oldp+1860,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid));
        bufp->chgBit(oldp+1861,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid));
        bufp->chgCData(oldp+1862,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_0_REG),5);
        bufp->chgCData(oldp+1863,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_1_REG),5);
        bufp->chgCData(oldp+1864,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_2_REG),5);
        bufp->chgCData(oldp+1865,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_hit_OH_3_REG),5);
        bufp->chgWData(oldp+1866,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__MSHRs),2460);
        bufp->chgCData(oldp+1943,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__MSHR_front_pointer),3);
        bufp->chgBit(oldp+1944,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__output_valid_r));
        bufp->chgBit(oldp+1945,((1U & (~ ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match) 
                                          & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full))))));
        __Vtemp_146[0U] = (IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__dataOut)) 
                                    << 0x2aU) | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__dataOut)) 
                                                  << 0x15U) 
                                                 | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__dataOut)))));
        __Vtemp_146[1U] = ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__dataOut 
                            << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__dataOut)) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__dataOut)) 
                                                      << 0x15U) 
                                                     | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__dataOut)))) 
                                                 >> 0x20U)));
        __Vtemp_146[2U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__dataOut 
                           >> 1U);
        __Vtemp_171[2U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
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
        __Vtemp_173[9U] = ((((0x53U >= (0x7fU & ((IData)(0x15U) 
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
                                                   __Vtemp_146[
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
                                              | (__Vtemp_146[
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
        __Vtemp_173[0xaU] = (((0x53U >= (0x7fU & ((IData)(0x15U) 
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
                                                (__Vtemp_146[
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
                                               | (__Vtemp_146[
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
        __Vtemp_174[0U] = (IData)((0x200000000020ULL 
                                   | ((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q_io_enq_bits_read_address_r_1)) 
                                      << 7U)));
        __Vtemp_174[1U] = (((IData)((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
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
        __Vtemp_174[2U] = __Vtemp_171[2U];
        __Vtemp_174[3U] = (((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut)) 
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
        __Vtemp_174[4U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__dataOut) 
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
        __Vtemp_174[5U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__dataOut) 
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
        __Vtemp_174[6U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__dataOut) 
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
        __Vtemp_174[7U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__dataOut) 
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
        __Vtemp_174[8U] = (((0x7f80U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__dataOut) 
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
        __Vtemp_174[9U] = __Vtemp_173[9U];
        __Vtemp_174[0xaU] = __Vtemp_173[0xaU];
        bufp->chgWData(oldp+1946,(__Vtemp_174),336);
        bufp->chgBit(oldp+1957,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__empty)))));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0) {
            __Vtemp_175[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U];
            __Vtemp_175[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U];
            __Vtemp_175[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][2U];
            __Vtemp_175[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][3U];
            __Vtemp_175[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][4U];
            __Vtemp_175[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][5U];
            __Vtemp_175[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][6U];
            __Vtemp_175[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][7U];
            __Vtemp_175[8U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][8U];
            __Vtemp_175[9U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U];
            __Vtemp_175[0xaU] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU];
        } else {
            __Vtemp_175[0U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[0U];
            __Vtemp_175[1U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[1U];
            __Vtemp_175[2U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[2U];
            __Vtemp_175[3U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[3U];
            __Vtemp_175[4U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[4U];
            __Vtemp_175[5U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[5U];
            __Vtemp_175[6U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[6U];
            __Vtemp_175[7U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[7U];
            __Vtemp_175[8U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[8U];
            __Vtemp_175[9U] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[9U];
            __Vtemp_175[0xaU] = Vtop_v2__ConstPool__CONST_hf2cc239e_0[0xaU];
        }
        bufp->chgWData(oldp+1958,(__Vtemp_175),336);
        bufp->chgCData(oldp+1969,(((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full) 
                                     & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match)) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__enq_ptr_value) 
                                               - (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value))))),3);
        bufp->chgCData(oldp+1970,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__enq_ptr_value),2);
        bufp->chgCData(oldp+1971,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value),2);
        bufp->chgBit(oldp+1972,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full));
        bufp->chgBit(oldp+1973,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match));
        bufp->chgBit(oldp+1974,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__empty));
        bufp->chgBit(oldp+1975,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ptr_match) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__maybe_full))));
        bufp->chgCData(oldp+1976,((3U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__empty)
                                          ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value)
                                          : ((3U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value))
                                              ? 0U : 
                                             ((IData)(1U) 
                                              + (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__deq_ptr_value)))))),2);
        bufp->chgBit(oldp+1977,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__full)))));
        bufp->chgBit(oldp+1978,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___final_response_buffer_io_deq_valid));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full) {
            __Vtemp_176[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[0U];
            __Vtemp_176[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[1U];
            __Vtemp_176[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[2U];
            __Vtemp_176[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[3U];
            __Vtemp_176[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[4U];
            __Vtemp_176[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[5U];
            __Vtemp_176[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[6U];
            __Vtemp_176[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[7U];
        } else {
            __Vtemp_176[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[0U];
            __Vtemp_176[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[1U];
            __Vtemp_176[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[2U];
            __Vtemp_176[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[3U];
            __Vtemp_176[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[4U];
            __Vtemp_176[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[5U];
            __Vtemp_176[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[6U];
            __Vtemp_176[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[7U];
        }
        bufp->chgWData(oldp+1979,(__Vtemp_176),256);
        bufp->chgBit(oldp+1987,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__full));
        bufp->chgWData(oldp+1988,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram),256);
        bufp->chgBit(oldp+1996,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__unnamedblk1__DOT__do_enq));
        bufp->chgBit(oldp+1997,((1U & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en)));
        bufp->chgCData(oldp+1998,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr),8);
        bufp->chgCData(oldp+1999,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2000,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__dataOut),8);
        bufp->chgCData(oldp+2001,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_0__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2002,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 1U))));
        bufp->chgCData(oldp+2003,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2004,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__dataOut),8);
        bufp->chgCData(oldp+2005,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_1__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2006,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2007,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2008,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__dataOut),8);
        bufp->chgCData(oldp+2009,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_10__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2010,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2011,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2012,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__dataOut),8);
        bufp->chgCData(oldp+2013,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_11__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2014,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xcU))));
        bufp->chgCData(oldp+2015,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2016,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__dataOut),8);
        bufp->chgCData(oldp+2017,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_12__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2018,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xdU))));
        bufp->chgCData(oldp+2019,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2020,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__dataOut),8);
        bufp->chgCData(oldp+2021,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_13__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2022,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xeU))));
        bufp->chgCData(oldp+2023,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2024,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__dataOut),8);
        bufp->chgCData(oldp+2025,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_14__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2026,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0xfU))));
        bufp->chgCData(oldp+2027,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[3U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2028,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__dataOut),8);
        bufp->chgCData(oldp+2029,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_15__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2030,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x10U))));
        bufp->chgCData(oldp+2031,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2032,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__dataOut),8);
        bufp->chgCData(oldp+2033,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_16__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2034,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x11U))));
        bufp->chgCData(oldp+2035,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2036,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__dataOut),8);
        bufp->chgCData(oldp+2037,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_17__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2038,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x12U))));
        bufp->chgCData(oldp+2039,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2040,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__dataOut),8);
        bufp->chgCData(oldp+2041,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_18__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2042,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x13U))));
        bufp->chgCData(oldp+2043,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[4U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2044,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__dataOut),8);
        bufp->chgCData(oldp+2045,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_19__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2046,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 2U))));
        bufp->chgCData(oldp+2047,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2048,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__dataOut),8);
        bufp->chgCData(oldp+2049,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_2__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2050,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x14U))));
        bufp->chgCData(oldp+2051,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2052,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__dataOut),8);
        bufp->chgCData(oldp+2053,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_20__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2054,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x15U))));
        bufp->chgCData(oldp+2055,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2056,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__dataOut),8);
        bufp->chgCData(oldp+2057,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_21__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2058,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x16U))));
        bufp->chgCData(oldp+2059,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2060,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__dataOut),8);
        bufp->chgCData(oldp+2061,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_22__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2062,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x17U))));
        bufp->chgCData(oldp+2063,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[5U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2064,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__dataOut),8);
        bufp->chgCData(oldp+2065,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_23__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2066,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x18U))));
        bufp->chgCData(oldp+2067,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2068,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__dataOut),8);
        bufp->chgCData(oldp+2069,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_24__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2070,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x19U))));
        bufp->chgCData(oldp+2071,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2072,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__dataOut),8);
        bufp->chgCData(oldp+2073,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_25__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2074,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1aU))));
        bufp->chgCData(oldp+2075,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2076,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__dataOut),8);
        bufp->chgCData(oldp+2077,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_26__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2078,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1bU))));
        bufp->chgCData(oldp+2079,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[6U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2080,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__dataOut),8);
        bufp->chgCData(oldp+2081,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_27__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2082,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1cU))));
        bufp->chgCData(oldp+2083,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2084,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__dataOut),8);
        bufp->chgCData(oldp+2085,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_28__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2086,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1dU))));
        bufp->chgCData(oldp+2087,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2088,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__dataOut),8);
        bufp->chgCData(oldp+2089,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_29__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2090,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 3U))));
        bufp->chgCData(oldp+2091,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[0U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2092,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__dataOut),8);
        bufp->chgCData(oldp+2093,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_3__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2094,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 0x1eU))));
        bufp->chgCData(oldp+2095,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2096,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__dataOut),8);
        bufp->chgCData(oldp+2097,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_30__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2098,((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                 >> 0x1fU)));
        bufp->chgCData(oldp+2099,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[7U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2100,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__dataOut),8);
        bufp->chgCData(oldp+2101,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_31__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2102,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 4U))));
        bufp->chgCData(oldp+2103,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2104,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__dataOut),8);
        bufp->chgCData(oldp+2105,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_4__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2106,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 5U))));
        bufp->chgCData(oldp+2107,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2108,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__dataOut),8);
        bufp->chgCData(oldp+2109,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_5__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2110,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 6U))));
        bufp->chgCData(oldp+2111,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U] 
                                                >> 0x10U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2112,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__dataOut),8);
        bufp->chgCData(oldp+2113,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_6__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2114,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 7U))));
        bufp->chgCData(oldp+2115,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[1U] 
                                       >> 0x18U) : 0U)),8);
        bufp->chgCData(oldp+2116,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__dataOut),8);
        bufp->chgCData(oldp+2117,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_7__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2118,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 8U))));
        bufp->chgCData(oldp+2119,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U])
                                    : 0U)),8);
        bufp->chgCData(oldp+2120,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__dataOut),8);
        bufp->chgCData(oldp+2121,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_8__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2122,((1U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_wr_en 
                                       >> 9U))));
        bufp->chgCData(oldp+2123,(((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_STATE))
                                    ? (0xffU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__cacheable_response_Q__DOT__ram[2U] 
                                                >> 8U))
                                    : 0U)),8);
        bufp->chgCData(oldp+2124,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__dataOut),8);
        bufp->chgCData(oldp+2125,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__data_memories_9__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__data_memories_0__io_addr]),8);
        bufp->chgBit(oldp+2126,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full)))));
        bufp->chgBit(oldp+2127,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__final_response_buffer__io_enq_valid));
        bufp->chgWData(oldp+2128,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14),256);
        bufp->chgBit(oldp+2136,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full));
        bufp->chgWData(oldp+2137,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram),256);
        bufp->chgBit(oldp+2145,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__do_enq));
        bufp->chgBit(oldp+2146,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__full)))));
        bufp->chgIData(oldp+2147,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__full)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__final_response_buffer__DOT__ram[0U]
                                    : vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_14[0U])),32);
        bufp->chgBit(oldp+2148,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_26));
        bufp->chgBit(oldp+2149,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__full));
        bufp->chgBit(oldp+2150,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__non_cacheable_response_Q__DOT__unnamedblk1__DOT__do_enq));
        bufp->chgBit(oldp+2151,((IData)(((0U == (0x60U 
                                                 & vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2152,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_0__io_addr),6);
        bufp->chgIData(oldp+2153,(((0U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2154,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__dataOut),21);
        bufp->chgIData(oldp+2155,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_0__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_0__io_addr]),21);
        bufp->chgBit(oldp+2156,((IData)(((0x20U == 
                                          (0x60U & 
                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2157,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_1__io_addr),6);
        bufp->chgIData(oldp+2158,(((1U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2159,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__dataOut),21);
        bufp->chgIData(oldp+2160,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_1__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_1__io_addr]),21);
        bufp->chgBit(oldp+2161,((IData)(((0x40U == 
                                          (0x60U & 
                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2162,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_2__io_addr),6);
        bufp->chgIData(oldp+2163,(((2U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2164,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__dataOut),21);
        bufp->chgIData(oldp+2165,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_2__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_2__io_addr]),21);
        bufp->chgBit(oldp+2166,((IData)(((0x60U == 
                                          (0x60U & 
                                           vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U])) 
                                         & (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__DATA_CACHE_NEXT_STATE))))));
        bufp->chgCData(oldp+2167,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_3__io_addr),6);
        bufp->chgIData(oldp+2168,(((3U == (3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0U] 
                                                 >> 5U)))
                                    ? (0x1fU & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_22[0x12U] 
                                                >> 0x12U))
                                    : 0U)),21);
        bufp->chgIData(oldp+2169,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__dataOut),21);
        bufp->chgIData(oldp+2170,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__tag_memories_3__DOT__ram_ext__DOT__Memory
                                  [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____Vcellinp__tag_memories_3__io_addr]),21);
        bufp->chgCData(oldp+2171,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__unnamedblk1__DOT__active_tag),5);
        bufp->chgBit(oldp+2172,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__request_valid));
        __Vtemp_178[0U] = 0U;
        __Vtemp_178[1U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__request_addr 
                           << 1U);
        __Vtemp_178[2U] = (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__request_addr 
                           >> 0x1fU);
        bufp->chgWData(oldp+2173,(__Vtemp_178),65);
        bufp->chgBit(oldp+2176,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__resp_ready));
        bufp->chgBit(oldp+2177,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__miss));
        bufp->chgWData(oldp+2178,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_AW_DATA_BUFFER),256);
        bufp->chgCData(oldp+2186,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE),2);
        bufp->chgIData(oldp+2187,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__write_counter),32);
        bufp->chgWData(oldp+2188,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_read_buffer),256);
        bufp->chgCData(oldp+2196,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__cache_state),2);
        bufp->chgWData(oldp+2197,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__fetch_PC_buf),65);
        bufp->chgWData(oldp+2200,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address),65);
        bufp->chgIData(oldp+2203,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__current_packet),31);
        bufp->chgIData(oldp+2204,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__request_addr),32);
        bufp->chgBit(oldp+2205,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__cache_valid));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____VdfgRegularize_h6e0fa456_1_1) {
            __Vtemp_180[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[0U];
            __Vtemp_180[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[1U];
            __Vtemp_180[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[2U];
        } else {
            __Vtemp_180[0U] = 0U;
            __Vtemp_180[1U] = 0U;
            __Vtemp_180[2U] = 0U;
        }
        bufp->chgWData(oldp+2206,(__Vtemp_180),65);
        bufp->chgCData(oldp+2209,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory_io_wr_addr_REG),6);
        bufp->chgCData(oldp+2210,(((2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___LRU_memory_io_data_out))
                                    ? (1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___LRU_memory_io_data_out)))
                                    : 2U)),2);
        bufp->chgIData(oldp+2211,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_oh_vec_0_REG),21);
        bufp->chgIData(oldp+2212,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_oh_vec_1_REG),21);
        bufp->chgBit(oldp+2213,((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__cache_state))));
        bufp->chgBit(oldp+2214,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_REG_2));
        bufp->chgBit(oldp+2215,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit));
        bufp->chgBit(oldp+2216,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__miss_REG_2));
        bufp->chgWData(oldp+2217,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__hit_instruction_data),256);
        bufp->chgBit(oldp+2225,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_0_instruction_REG));
        bufp->chgBit(oldp+2226,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_1_instruction_REG));
        bufp->chgBit(oldp+2227,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_2_instruction_REG));
        bufp->chgBit(oldp+2228,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_bits_instructions_3_instruction_REG));
        __Vtemp_182[0U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[0U];
        __Vtemp_182[1U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[1U];
        __Vtemp_182[2U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[2U];
        __Vtemp_182[3U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[3U];
        __Vtemp_182[4U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[4U];
        __Vtemp_182[5U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[5U];
        __Vtemp_182[6U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[6U];
        __Vtemp_182[7U] = Vtop_v2__ConstPool__CONST_h9e67c271_0[7U];
        __Vtemp_182[8U] = (0x200000U | (0x1fffffU & 
                                        ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[2U] 
                                          << 0x14U) 
                                         | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__replay_address[1U] 
                                            >> 0xcU))));
        bufp->chgWData(oldp+2229,(__Vtemp_182),278);
        bufp->chgBit(oldp+2238,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__full)))));
        bufp->chgBit(oldp+2239,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___CPU_response_valid_T));
        bufp->chgWData(oldp+2240,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_12),234);
        bufp->chgBit(oldp+2248,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__full));
        bufp->chgWData(oldp+2249,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__ram),234);
        bufp->chgBit(oldp+2257,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__CPU_response_skid_buffer__DOT__do_enq));
        bufp->chgCData(oldp+2258,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__LRU_memory__io_rd_addr),6);
        bufp->chgCData(oldp+2259,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___LRU_memory_io_data_out),2);
        bufp->chgCData(oldp+2260,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__LRU_memory__io_data_in),2);
        bufp->chgBit(oldp+2261,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__hazard_reg));
        bufp->chgCData(oldp+2262,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__din_buff),2);
        bufp->chgCData(oldp+2263,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__mem_ext__DOT___R0_en_d0)
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__mem_ext__DOT__Memory
                                   [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__LRU_memory__DOT__mem_ext__DOT___R0_addr_d0]
                                    : 0U)),2);
        bufp->chgBit(oldp+2264,((1U & (~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full)))));
        bufp->chgBit(oldp+2265,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__final_response_buffer__io_enq_valid));
        bufp->chgWData(oldp+2266,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7),256);
        bufp->chgBit(oldp+2274,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full) 
                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__final_response_buffer__io_enq_valid))));
        if (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full) {
            __Vtemp_183[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[0U];
            __Vtemp_183[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[1U];
            __Vtemp_183[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[2U];
            __Vtemp_183[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[3U];
            __Vtemp_183[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[4U];
            __Vtemp_183[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[5U];
            __Vtemp_183[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[6U];
            __Vtemp_183[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram[7U];
        } else {
            __Vtemp_183[0U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[0U];
            __Vtemp_183[1U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[1U];
            __Vtemp_183[2U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[2U];
            __Vtemp_183[3U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[3U];
            __Vtemp_183[4U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[4U];
            __Vtemp_183[5U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[5U];
            __Vtemp_183[6U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[6U];
            __Vtemp_183[7U] = vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_7[7U];
        }
        bufp->chgWData(oldp+2275,(__Vtemp_183),256);
        bufp->chgBit(oldp+2283,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__full));
        bufp->chgWData(oldp+2284,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__ram),256);
        bufp->chgBit(oldp+2292,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__final_response_buffer__DOT__do_enq));
        bufp->chgCData(oldp+2293,((3U & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__fetch_PC_buf[1U] 
                                         >> 3U))),2);
        bufp->chgCData(oldp+2294,((0xfU & (0x137fU 
                                           >> (0xfU 
                                               & VL_SHIFTL_III(4,4,32, 
                                                               (3U 
                                                                & (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__fetch_PC_buf[1U] 
                                                                   >> 3U)), 2U))))),4);
        bufp->chgIData(oldp+2295,(((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                    : 0U)),32);
        bufp->chgCData(oldp+2296,((0xfU & (- (IData)(
                                                     (1U 
                                                      == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))))),4);
        bufp->chgBit(oldp+2297,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_0));
        bufp->chgCData(oldp+2298,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg),8);
        bufp->chgCData(oldp+2299,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg),2);
        bufp->chgCData(oldp+2300,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg),8);
        bufp->chgIData(oldp+2301,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg),32);
        bufp->chgCData(oldp+2302,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg),2);
        bufp->chgBit(oldp+2303,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg));
        bufp->chgIData(oldp+2304,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                    ? ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                        ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0xaU] 
                                            << 0x11U) 
                                           | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][9U] 
                                              >> 0xfU))
                                        : 0U) : 0U)),32);
        bufp->chgCData(oldp+2305,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5),8);
        bufp->chgCData(oldp+2306,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                    ? 5U : 0U)),3);
        bufp->chgCData(oldp+2307,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid),2);
        bufp->chgIData(oldp+2308,(((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE))
                                    ? vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_AW_DATA_BUFFER[0U]
                                    : 0U)),32);
        bufp->chgCData(oldp+2309,((0xfU & (- (IData)(
                                                     (1U 
                                                      == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)))))),4);
        bufp->chgBit(oldp+2310,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_7));
        bufp->chgIData(oldp+2311,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                    ? ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_en_d0)
                                        ? ((vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                            [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][1U] 
                                            << 0x19U) 
                                           | (vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT__Memory
                                              [vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_request_Q__DOT__ram_ext__DOT___R0_addr_d0][0U] 
                                              >> 7U))
                                        : 0U) : 0U)),32);
        bufp->chgCData(oldp+2312,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                    ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_h6d09639e_0_2)
                                    : 0U)),8);
        bufp->chgCData(oldp+2313,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                    ? 5U : 0U)),3);
        bufp->chgCData(oldp+2314,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid),2);
        bufp->chgIData(oldp+2315,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg),32);
        bufp->chgCData(oldp+2316,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg),8);
        bufp->chgCData(oldp+2317,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg),3);
        bufp->chgCData(oldp+2318,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg),2);
        bufp->chgBit(oldp+2319,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg));
        bufp->chgCData(oldp+2320,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg),4);
        bufp->chgCData(oldp+2321,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg),3);
        bufp->chgCData(oldp+2322,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg),4);
        bufp->chgCData(oldp+2323,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg),4);
        bufp->chgIData(oldp+2324,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg),32);
        bufp->chgCData(oldp+2325,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg),4);
        bufp->chgBit(oldp+2326,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg));
        bufp->chgCData(oldp+2327,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg),8);
        bufp->chgCData(oldp+2328,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg),8);
        bufp->chgIData(oldp+2329,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_reg),32);
        bufp->chgBit(oldp+2330,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_reg));
        bufp->chgQData(oldp+2331,(((QData)((IData)(
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
        bufp->chgSData(oldp+2333,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5) 
                                   << 8U)),16);
        bufp->chgCData(oldp+2334,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid)
                                     ? 5U : 0U) << 3U)),6);
        bufp->chgCData(oldp+2335,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid) 
                                   << 2U)),4);
        bufp->chgCData(oldp+2336,(((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AW_valid) 
                                   << 1U)),2);
        bufp->chgCData(oldp+2337,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg),2);
        bufp->chgQData(oldp+2338,((((QData)((IData)(
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
        bufp->chgCData(oldp+2340,(((0xf0U & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)))) 
                                             << 4U)) 
                                   | (0xfU & (- (IData)(
                                                        (1U 
                                                         == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))))))),8);
        bufp->chgCData(oldp+2341,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_7) 
                                    << 1U) | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT___GEN_0))),2);
        bufp->chgCData(oldp+2342,((((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)) 
                                    << 1U) | (1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))),2);
        bufp->chgCData(oldp+2343,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg),2);
        bufp->chgSData(oldp+2344,((0xffffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg) 
                                               << 8U) 
                                              | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg)))),16);
        bufp->chgCData(oldp+2345,((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg) 
                                            << 2U) 
                                           | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg)))),4);
        bufp->chgCData(oldp+2346,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg),2);
        bufp->chgCData(oldp+2347,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT____Vcellinp__axi_interconnect_inst__s_axi_bready),2);
        bufp->chgQData(oldp+2348,(((QData)((IData)(
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
        bufp->chgSData(oldp+2350,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                     ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_h6d09639e_0_2)
                                     : 0U) << 8U)),16);
        bufp->chgCData(oldp+2351,((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                     ? 5U : 0U) << 3U)),6);
        bufp->chgCData(oldp+2352,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                   << 2U)),4);
        bufp->chgCData(oldp+2353,(((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AR_valid) 
                                   << 1U)),2);
        bufp->chgCData(oldp+2354,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg),2);
        bufp->chgSData(oldp+2355,((0xffffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg) 
                                               << 8U) 
                                              | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg)))),16);
        bufp->chgQData(oldp+2356,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)))),64);
        bufp->chgCData(oldp+2358,((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg) 
                                            << 2U) 
                                           | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg)))),4);
        bufp->chgCData(oldp+2359,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg))))),2);
        bufp->chgCData(oldp+2360,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_reg),2);
        bufp->chgCData(oldp+2361,((((2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)) 
                                    << 1U) | (2U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE)))),2);
        bufp->chgQData(oldp+2362,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)))),64);
        bufp->chgSData(oldp+2364,((0xffffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                               << 8U) 
                                              | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg)))),16);
        bufp->chgCData(oldp+2365,((0x3fU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                             << 3U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg)))),6);
        bufp->chgCData(oldp+2366,((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                            << 2U) 
                                           | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg)))),4);
        bufp->chgCData(oldp+2367,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg))))),2);
        bufp->chgCData(oldp+2368,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg)))),8);
        bufp->chgCData(oldp+2369,((0x3fU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                             << 3U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg)))),6);
        bufp->chgCData(oldp+2370,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg)))),8);
        bufp->chgCData(oldp+2371,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg)))),8);
        bufp->chgCData(oldp+2372,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg),2);
        bufp->chgCData(oldp+2373,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_awready_reg),2);
        bufp->chgQData(oldp+2374,((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)))),64);
        bufp->chgCData(oldp+2376,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg) 
                                             << 4U) 
                                            | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg)))),8);
        bufp->chgCData(oldp+2377,((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg))))),2);
        bufp->chgCData(oldp+2378,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_reg),2);
        bufp->chgCData(oldp+2379,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_wready_reg),2);
        bufp->chgSData(oldp+2380,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg),16);
        bufp->chgCData(oldp+2381,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_reg),2);
        bufp->chgCData(oldp+2382,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg),2);
        bufp->chgCData(oldp+2383,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg),2);
        bufp->chgCData(oldp+2384,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_reg),2);
        bufp->chgSData(oldp+2385,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg),16);
        bufp->chgQData(oldp+2386,((QData)((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_reg))),64);
        bufp->chgCData(oldp+2388,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_reg),2);
        bufp->chgCData(oldp+2389,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_reg),2);
        bufp->chgCData(oldp+2390,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg),2);
        bufp->chgCData(oldp+2391,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__state_reg),3);
        bufp->chgCData(oldp+2392,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__state_next),3);
        bufp->chgBit(oldp+2393,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__match));
        bufp->chgBit(oldp+2394,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg));
        bufp->chgBit(oldp+2395,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_next));
        bufp->chgCData(oldp+2396,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_next),8);
        bufp->chgIData(oldp+2397,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_next),32);
        bufp->chgBit(oldp+2398,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_valid_reg));
        bufp->chgBit(oldp+2399,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_valid_next));
        bufp->chgCData(oldp+2400,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_next),8);
        bufp->chgCData(oldp+2401,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_next),3);
        bufp->chgCData(oldp+2402,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_next),2);
        bufp->chgBit(oldp+2403,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_next));
        bufp->chgCData(oldp+2404,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_next),4);
        bufp->chgCData(oldp+2405,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_next),3);
        bufp->chgCData(oldp+2406,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_next),4);
        bufp->chgCData(oldp+2407,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_next),4);
        bufp->chgBit(oldp+2408,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_auser_reg));
        bufp->chgBit(oldp+2409,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_auser_next));
        bufp->chgCData(oldp+2410,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_next),2);
        bufp->chgBit(oldp+2411,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_buser_reg));
        bufp->chgCData(oldp+2412,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_next),2);
        bufp->chgCData(oldp+2413,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_next),2);
        bufp->chgCData(oldp+2414,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_next),2);
        bufp->chgCData(oldp+2415,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_next),2);
        bufp->chgCData(oldp+2416,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_next),2);
        bufp->chgCData(oldp+2417,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_next),2);
        bufp->chgCData(oldp+2418,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_next),2);
        bufp->chgCData(oldp+2419,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_next),2);
        bufp->chgCData(oldp+2420,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_int),8);
        bufp->chgIData(oldp+2421,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_int),32);
        bufp->chgCData(oldp+2422,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_int),2);
        bufp->chgBit(oldp+2423,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_int));
        bufp->chgBit(oldp+2424,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_ruser_int));
        bufp->chgBit(oldp+2425,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_int));
        bufp->chgBit(oldp+2426,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rready_int_reg));
        bufp->chgBit(oldp+2427,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rready_int_early));
        bufp->chgIData(oldp+2428,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_int),32);
        bufp->chgCData(oldp+2429,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_int),4);
        bufp->chgBit(oldp+2430,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_int));
        bufp->chgBit(oldp+2431,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wuser_int));
        bufp->chgBit(oldp+2432,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_int));
        bufp->chgBit(oldp+2433,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wready_int_reg));
        bufp->chgBit(oldp+2434,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wready_int_early));
        bufp->chgBit(oldp+2435,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                       >> 1U))));
        bufp->chgCData(oldp+2436,(0U),8);
        bufp->chgIData(oldp+2437,((IData)((((QData)((IData)(
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
        bufp->chgCData(oldp+2438,((0xffU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT___GEN_5) 
                                             << 8U) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgCData(oldp+2439,(((5U >= (7U & ((IData)(3U) 
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
        bufp->chgCData(oldp+2440,((3U & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__write_request_valid) 
                                          << 2U) >> 
                                         (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2441,(0U));
        bufp->chgCData(oldp+2442,(0U),4);
        bufp->chgCData(oldp+2443,(0U),3);
        bufp->chgBit(oldp+2444,((1U & (((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AW_valid) 
                                        << 1U) >> (1U 
                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                      >> 1U))))));
        bufp->chgBit(oldp+2445,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_awready_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgIData(oldp+2446,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_wdata),32);
        bufp->chgCData(oldp+2447,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_wstrb),4);
        bufp->chgBit(oldp+2448,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_wlast));
        bufp->chgBit(oldp+2449,((1U & ((((1U == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__AXI_REQUEST_STATE)) 
                                         << 1U) | (1U 
                                                   == (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__AXI_REQUEST_STATE))) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2450,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_wready_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgCData(oldp+2451,((0xffU & ((0xffffU 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_id_reg))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgCData(oldp+2452,((3U & ((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_bresp_reg))) 
                                         >> (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2453,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_bvalid_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2454,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT____Vcellinp__axi_interconnect_inst__s_axi_bready) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgIData(oldp+2455,((IData)((((QData)((IData)(
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
        bufp->chgCData(oldp+2456,((0xffU & ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
                                               ? (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT____VdfgRegularize_h6d09639e_0_2)
                                               : 0U) 
                                             << 8U) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgCData(oldp+2457,(((5U >= (7U & ((IData)(3U) 
                                                 * 
                                                 (1U 
                                                  & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                     >> 1U)))))
                                    ? (7U & ((((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid)
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
        bufp->chgCData(oldp+2458,((3U & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__data_cache__DOT__read_request_valid) 
                                          << 2U) >> 
                                         (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2459,((1U & (((IData)(vlSelf->top_v2__DOT__SOC__DOT___ChaosCore_tile_io_data_cache_AXI_port_AXI_AR_valid) 
                                        << 1U) >> (1U 
                                                   & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                      >> 1U))))));
        bufp->chgBit(oldp+2460,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_arready_reg) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgCData(oldp+2461,((0xffU & ((0xffffU 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rid_reg))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, 
                                                                (1U 
                                                                 & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                    >> 1U)), 3U))))),8);
        bufp->chgIData(oldp+2462,((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rdata_reg))) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, 
                                                               (1U 
                                                                & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                                   >> 1U)), 5U))))),32);
        bufp->chgCData(oldp+2463,((3U & ((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rresp_reg))) 
                                         >> (2U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))))),2);
        bufp->chgBit(oldp+2464,((1U & ((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rlast_reg)))) 
                                       >> (1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg) 
                                                 >> 1U))))));
        bufp->chgBit(oldp+2465,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_rvalid));
        bufp->chgBit(oldp+2466,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_s_axi_rready));
        bufp->chgCData(oldp+2467,(0U),8);
        bufp->chgIData(oldp+2468,((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg))) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 5U))))),32);
        bufp->chgCData(oldp+2469,((0xffU & ((0xffffU 
                                             & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg) 
                                                 << 8U) 
                                                | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_len_reg))) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 3U))))),8);
        bufp->chgCData(oldp+2470,(((5U >= (7U & ((IData)(3U) 
                                                 * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg))))
                                    ? (7U & ((0x3fU 
                                              & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_size_reg))) 
                                             >> (7U 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))))
                                    : 0U)),3);
        bufp->chgCData(oldp+2471,((3U & ((0xfU & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_burst_reg))) 
                                         >> (3U & VL_SHIFTL_III(2,2,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 1U))))),2);
        bufp->chgBit(oldp+2472,((1U & ((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_lock_reg)))) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgCData(oldp+2473,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_cache_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgCData(oldp+2474,(((5U >= (7U & ((IData)(3U) 
                                                 * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg))))
                                    ? (7U & ((0x3fU 
                                              & (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_prot_reg))) 
                                             >> (7U 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))))
                                    : 0U)),3);
        bufp->chgCData(oldp+2475,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_qos_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgCData(oldp+2476,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_region_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgBit(oldp+2477,(0U));
        bufp->chgBit(oldp+2478,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_awvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2479,((1U & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_awready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgIData(oldp+2480,((IData)(((((QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wdata_reg))) 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,6,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 5U))))),32);
        bufp->chgCData(oldp+2481,((0xfU & ((0xffU & 
                                            (((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg) 
                                              << 4U) 
                                             | (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wstrb_reg))) 
                                           >> (7U & 
                                               VL_SHIFTL_III(3,3,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 2U))))),4);
        bufp->chgBit(oldp+2482,((1U & ((3U & (- (IData)((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wlast_reg)))) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2483,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_wvalid));
        bufp->chgBit(oldp+2484,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_wready));
        bufp->chgCData(oldp+2485,((0xffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_reg) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 3U))))),8);
        bufp->chgCData(oldp+2486,(0U),2);
        bufp->chgBit(oldp+2487,((1U & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2488,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_bready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2489,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_arvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2490,((1U & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgCData(oldp+2491,((0xffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_reg) 
                                            >> (0xfU 
                                                & VL_SHIFTL_III(4,4,32, (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg), 3U))))),8);
        bufp->chgIData(oldp+2492,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_rdata),32);
        bufp->chgBit(oldp+2493,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__current_m_axi_rlast));
        bufp->chgBit(oldp+2494,((1U & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgBit(oldp+2495,((1U & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_rready_reg) 
                                       >> (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_select_reg)))));
        bufp->chgCData(oldp+2496,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__request),4);
        bufp->chgCData(oldp+2497,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__acknowledge),4);
        bufp->chgCData(oldp+2498,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_reg),4);
        bufp->chgBit(oldp+2499,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_valid_reg));
        bufp->chgCData(oldp+2500,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg),2);
        bufp->chgBit(oldp+2501,((1U & (IData)(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_reg))));
        bufp->chgBit(oldp+2502,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_ruser_reg));
        bufp->chgCData(oldp+2503,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__s_axi_rvalid_next),2);
        bufp->chgCData(oldp+2504,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rid_reg),8);
        bufp->chgIData(oldp+2505,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rdata_reg),32);
        bufp->chgCData(oldp+2506,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rresp_reg),2);
        bufp->chgBit(oldp+2507,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rlast_reg));
        bufp->chgBit(oldp+2508,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_ruser_reg));
        bufp->chgBit(oldp+2509,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rvalid_reg));
        bufp->chgBit(oldp+2510,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_s_axi_rvalid_next));
        bufp->chgBit(oldp+2511,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_r_int_to_output));
        bufp->chgBit(oldp+2512,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_r_int_to_temp));
        bufp->chgBit(oldp+2513,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_r_temp_to_output));
        bufp->chgBit(oldp+2514,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wuser_reg));
        bufp->chgCData(oldp+2515,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__m_axi_wvalid_next),2);
        bufp->chgIData(oldp+2516,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wdata_reg),32);
        bufp->chgCData(oldp+2517,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wstrb_reg),4);
        bufp->chgBit(oldp+2518,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wlast_reg));
        bufp->chgBit(oldp+2519,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wuser_reg));
        bufp->chgBit(oldp+2520,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wvalid_reg));
        bufp->chgBit(oldp+2521,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__temp_m_axi_wvalid_next));
        bufp->chgBit(oldp+2522,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_w_int_to_output));
        bufp->chgBit(oldp+2523,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_w_int_to_temp));
        bufp->chgBit(oldp+2524,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__store_axi_w_temp_to_output));
        bufp->chgCData(oldp+2525,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__mask_reg),4);
        bufp->chgCData(oldp+2526,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__input_padded),4);
        bufp->chgSData(oldp+2527,((0xffffU & vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg)),16);
        bufp->chgBit(oldp+2528,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_state_reg));
        bufp->chgBit(oldp+2529,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_state_next));
        bufp->chgCData(oldp+2530,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_state_reg),2);
        bufp->chgCData(oldp+2531,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_state_next),2);
        bufp->chgBit(oldp+2532,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__mem_wr_en));
        bufp->chgBit(oldp+2533,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__mem_rd_en));
        bufp->chgCData(oldp+2534,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_id_reg),8);
        bufp->chgCData(oldp+2535,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_id_next),8);
        bufp->chgSData(oldp+2536,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_addr_reg),16);
        bufp->chgSData(oldp+2537,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_addr_next),16);
        bufp->chgCData(oldp+2538,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_count_reg),8);
        bufp->chgCData(oldp+2539,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_count_next),8);
        bufp->chgCData(oldp+2540,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_size_reg),3);
        bufp->chgCData(oldp+2541,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_size_next),3);
        bufp->chgCData(oldp+2542,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_burst_reg),2);
        bufp->chgCData(oldp+2543,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_burst_next),2);
        bufp->chgCData(oldp+2544,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_id_reg),8);
        bufp->chgCData(oldp+2545,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_id_next),8);
        bufp->chgSData(oldp+2546,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_addr_reg),16);
        bufp->chgSData(oldp+2547,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_addr_next),16);
        bufp->chgCData(oldp+2548,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_count_reg),8);
        bufp->chgCData(oldp+2549,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_count_next),8);
        bufp->chgCData(oldp+2550,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_size_reg),3);
        bufp->chgCData(oldp+2551,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_size_next),3);
        bufp->chgCData(oldp+2552,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_burst_reg),2);
        bufp->chgCData(oldp+2553,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_burst_next),2);
        bufp->chgBit(oldp+2554,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_awready_next));
        bufp->chgBit(oldp+2555,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_wready_next));
        bufp->chgCData(oldp+2556,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bid_next),8);
        bufp->chgBit(oldp+2557,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_bvalid_next));
        bufp->chgBit(oldp+2558,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_arready_next));
        bufp->chgCData(oldp+2559,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_next),8);
        bufp->chgBit(oldp+2560,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_next));
        bufp->chgBit(oldp+2561,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_next));
        bufp->chgCData(oldp+2562,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rid_pipe_reg),8);
        bufp->chgIData(oldp+2563,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rdata_pipe_reg),32);
        bufp->chgBit(oldp+2564,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rlast_pipe_reg));
        bufp->chgBit(oldp+2565,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__s_axi_rvalid_pipe_reg));
        bufp->chgSData(oldp+2566,((0x3fffU & (vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__axi_addr_reg 
                                              >> 2U))),14);
        bufp->chgSData(oldp+2567,((0x3fffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__read_addr_reg) 
                                              >> 2U))),14);
        bufp->chgSData(oldp+2568,((0x3fffU & ((IData)(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__write_addr_reg) 
                                              >> 2U))),14);
        bufp->chgWData(oldp+2569,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0.__PVT___mem_ext_R0_data),278);
        bufp->chgWData(oldp+2578,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_1.__PVT___mem_ext_R0_data),278);
        bufp->chgBit(oldp+2587,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2588,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T_1) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__empty) 
                                       | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T))))));
        bufp->chgWData(oldp+2589,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___GEN),434);
        bufp->chgBit(oldp+2603,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___io_predictions_in_ready_T));
        bufp->chgCData(oldp+2604,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2605,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2606,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2607,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2608,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2609,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2610,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2611,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2612,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__wrap_1]),434);
        bufp->chgWData(oldp+2626,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__Vcellinp__ram_ext__W0_data),434);
        __Vtemp_185[0U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[1U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[1U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[2U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[2U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[3U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[3U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[4U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[4U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[5U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[5U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[6U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[6U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[7U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[7U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[8U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[8U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[9U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[9U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[0xaU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xaU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[0xbU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xbU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[0xcU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xcU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        __Vtemp_185[0xdU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xdU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2640,(__Vtemp_185),434);
        bufp->chgWData(oldp+2654,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ram_ext__DOT__Memory[0]),434);
        bufp->chgWData(oldp+2668,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__ram_ext__DOT__Memory[1]),434);
        bufp->chgBit(oldp+2682,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__decoded_fetch_packet_out_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2683,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2684,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & ((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__empty) 
                                       | (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq))))));
        bufp->chgWData(oldp+2685,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT___GEN_597),434);
        bufp->chgWData(oldp+2699,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.io_deq_bits),434);
        bufp->chgCData(oldp+2713,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2714,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap));
        bufp->chgBit(oldp+2715,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2716,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2717,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2718,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__empty));
        bufp->chgBit(oldp+2719,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2720,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2721,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__wrap_1]),434);
        bufp->chgWData(oldp+2735,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__Vcellinp__ram_ext__W0_data),434);
        __Vtemp_187[0U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[1U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[1U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[2U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[2U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[3U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[3U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[4U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[4U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[5U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[5U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[6U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[6U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[7U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[7U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[8U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[8U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[9U] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[9U] 
                           & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[0xaU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xaU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[0xbU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xbU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[0xcU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xcU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        __Vtemp_187[0xdU] = (Vtop_v2__ConstPool__CONST_h862b0a92_0[0xdU] 
                             & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2749,(__Vtemp_187),434);
        bufp->chgWData(oldp+2763,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ram_ext__DOT__Memory[0]),434);
        bufp->chgWData(oldp+2777,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__ram_ext__DOT__Memory[1]),434);
        bufp->chgBit(oldp+2791,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2792,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__full)))));
        bufp->chgBit(oldp+2793,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_load_Q_io_enq_valid_T_14));
        bufp->chgWData(oldp+2794,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_218),192);
        bufp->chgCData(oldp+2800,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ptr_match)) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__enq_ptr_value) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__deq_ptr_value))))),3);
        bufp->chgBit(oldp+2801,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT____Vcellinp__FU_output_load_Q__io_flush));
        bufp->chgCData(oldp+2802,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__enq_ptr_value),2);
        bufp->chgCData(oldp+2803,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__deq_ptr_value),2);
        bufp->chgBit(oldp+2804,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2805,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2806,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__full));
        bufp->chgBit(oldp+2807,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2808,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__deq_ptr_value]),192);
        bufp->chgWData(oldp+2814,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__Vcellinp__ram_ext__W0_data),192);
        __Vtemp_188[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_188[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_188[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_188[3U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_188[4U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        __Vtemp_188[5U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__do_enq)));
        bufp->chgWData(oldp+2820,(__Vtemp_188),192);
        bufp->chgWData(oldp+2826,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[0]),192);
        bufp->chgWData(oldp+2832,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[1]),192);
        bufp->chgWData(oldp+2838,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[2]),192);
        bufp->chgWData(oldp+2844,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__ram_ext__DOT__Memory[3]),192);
        bufp->chgBit(oldp+2850,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_load_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2851,((1U & (~ (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__full)))));
        bufp->chgBit(oldp+2852,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___FU_output_store_Q_io_enq_valid_T_14));
        bufp->chgWData(oldp+2853,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT___GEN_219),192);
        bufp->chgCData(oldp+2859,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ptr_match)) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__enq_ptr_value) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__deq_ptr_value))))),3);
        bufp->chgCData(oldp+2860,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__enq_ptr_value),2);
        bufp->chgCData(oldp+2861,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__deq_ptr_value),2);
        bufp->chgBit(oldp+2862,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2863,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2864,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__empty));
        bufp->chgBit(oldp+2865,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__full));
        bufp->chgBit(oldp+2866,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2867,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__deq_ptr_value]),192);
        bufp->chgWData(oldp+2873,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__Vcellinp__ram_ext__W0_data),192);
        __Vtemp_189[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_189[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_189[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_189[3U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_189[4U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        __Vtemp_189[5U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__do_enq)));
        bufp->chgWData(oldp+2879,(__Vtemp_189),192);
        bufp->chgWData(oldp+2885,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[0]),192);
        bufp->chgWData(oldp+2891,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[1]),192);
        bufp->chgWData(oldp+2897,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[2]),192);
        bufp->chgWData(oldp+2903,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__ram_ext__DOT__Memory[3]),192);
        bufp->chgBit(oldp+2909,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__MOB__DOT__FU_output_store_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2910,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2911,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT___GEN_10) 
                                 & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__input_fetch_packet_valid))));
        bufp->chgCData(oldp+2912,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2913,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2914,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2915,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2916,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2917,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2918,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2919,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2920,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__wrap_1]),110);
        __Vtemp_192[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_192[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_192[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_192[3U] = (0x3fffU & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2924,(__Vtemp_192),110);
        bufp->chgWData(oldp+2928,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+2932,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[1]),110);
        bufp->chgBit(oldp+2936,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_fetch__DOT__predecoder__DOT__predictions_out_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2937,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2938,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT___predictions_out_valid_T_1)))));
        bufp->chgCData(oldp+2939,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2940,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2941,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2942,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2943,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2944,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2945,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2946,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2947,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory
                                  [vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__wrap_1]),110);
        bufp->chgWData(oldp+2951,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__Vcellinp__ram_ext__W0_data),110);
        __Vtemp_195[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_195[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_195[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_195[3U] = (0x3fffU & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2955,(__Vtemp_195),110);
        bufp->chgWData(oldp+2959,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+2963,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[1]),110);
        bufp->chgBit(oldp+2967,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__decoders__DOT__predictions_out_Q.__PVT__unnamedblk1__DOT__do_deq));
        bufp->chgBit(oldp+2968,((1U & (~ ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match) 
                                          & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full))))));
        bufp->chgBit(oldp+2969,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__FTQ_queue__DOT__do_deq) 
                                 & ((~ (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__flush)) 
                                    & (IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__instruction_queue__DOT__do_deq)))));
        bufp->chgCData(oldp+2970,(((((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full) 
                                     & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match)) 
                                    << 1U) | (1U & 
                                              ((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap) 
                                               - (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap_1))))),2);
        bufp->chgBit(oldp+2971,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap));
        bufp->chgBit(oldp+2972,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__wrap_1));
        bufp->chgBit(oldp+2973,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full));
        bufp->chgBit(oldp+2974,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match));
        bufp->chgBit(oldp+2975,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__empty));
        bufp->chgBit(oldp+2976,(((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ptr_match) 
                                 & (IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__maybe_full))));
        bufp->chgBit(oldp+2977,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq));
        bufp->chgWData(oldp+2978,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__Vcellinp__ram_ext__W0_data),110);
        __Vtemp_198[0U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_198[1U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_198[2U] = (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq)));
        __Vtemp_198[3U] = (0x3fffU & (- (IData)((IData)(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__do_enq))));
        bufp->chgWData(oldp+2982,(__Vtemp_198),110);
        bufp->chgWData(oldp+2986,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[0]),110);
        bufp->chgWData(oldp+2990,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__ram_ext__DOT__Memory[1]),110);
        bufp->chgBit(oldp+2994,(vlSymsp->TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__predictions_out_Q.__PVT__unnamedblk1__DOT__do_deq));
    }
    bufp->chgBit(oldp+2995,(vlSelf->top_v2__DOT__clock));
    bufp->chgBit(oldp+2996,(vlSelf->top_v2__DOT__reset));
    bufp->chgBit(oldp+2997,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__AGU__DOT__hasBeenResetReg) 
                             & (~ (IData)(vlSelf->top_v2__DOT__reset)))));
    bufp->chgQData(oldp+2998,(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__backend__DOT__INT_RS__DOT__allocate_index),64);
    bufp->chgBit(oldp+3000,(((IData)(vlSelf->top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__ChaosCore__DOT__frontend__DOT__rename__DOT__free_list__DOT__hasBeenResetReg) 
                             & (~ (IData)(vlSelf->top_v2__DOT__reset)))));
    bufp->chgCData(oldp+3001,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_next),4);
    bufp->chgBit(oldp+3002,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_valid_next));
    bufp->chgCData(oldp+3003,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__grant_encoded_next),2);
    bufp->chgBit(oldp+3004,((1U & vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_valid
                             [1U])));
    bufp->chgCData(oldp+3005,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc
                              [1U]),2);
    bufp->chgCData(oldp+3006,((0xfU & ((IData)(1U) 
                                       << vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc
                                       [1U]))),4);
    bufp->chgCData(oldp+3007,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__mask_next),4);
    bufp->chgBit(oldp+3008,((1U & vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_valid
                             [1U])));
    bufp->chgCData(oldp+3009,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc
                              [1U]),2);
    bufp->chgCData(oldp+3010,((0xfU & ((IData)(1U) 
                                       << vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc
                                       [1U]))),4);
    bufp->chgCData(oldp+3011,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_valid[0]),2);
    bufp->chgCData(oldp+3012,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_valid[1]),2);
    bufp->chgCData(oldp+3013,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc[0]),2);
    bufp->chgCData(oldp+3014,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_inst__DOT__stage_enc[1]),2);
    bufp->chgCData(oldp+3015,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_valid[0]),2);
    bufp->chgCData(oldp+3016,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_valid[1]),2);
    bufp->chgCData(oldp+3017,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc[0]),2);
    bufp->chgCData(oldp+3018,(vlSelf->top_v2__DOT__SOC__DOT__axi_interconnect__DOT__NOC__DOT__axi_interconnect_inst__DOT__arb_inst__DOT__priority_encoder_masked__DOT__stage_enc[1]),2);
    bufp->chgIData(oldp+3019,(vlSelf->top_v2__DOT__axi_ram__DOT__ram__DOT__j),32);
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
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}

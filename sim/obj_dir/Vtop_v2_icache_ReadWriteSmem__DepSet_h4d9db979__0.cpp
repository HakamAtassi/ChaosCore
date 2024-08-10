// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_v2.h for the primary calling header

#include "Vtop_v2__pch.h"
#include "Vtop_v2__Syms.h"
#include "Vtop_v2_icache_ReadWriteSmem.h"

extern const VlWide<9>/*287:0*/ Vtop_v2__ConstPool__CONST_h16a7ccb2_0;

VL_INLINE_OPT void Vtop_v2_icache_ReadWriteSmem___nba_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0__0(Vtop_v2_icache_ReadWriteSmem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_v2_icache_ReadWriteSmem___nba_sequent__TOP__top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT__data_memory_0__0\n"); );
    // Body
    vlSelf->__PVT__mem_ext__DOT___R0_en_d0 = 1U;
    vlSelf->__PVT__mem_ext__DOT___R0_addr_d0 = vlSymsp->TOP.top_v2__DOT__SOC__DOT__ChaosCore_tile__DOT__instruction_cache__DOT____Vcellinp__LRU_memory__io_rd_addr;
    if (vlSelf->__PVT__mem_ext__DOT___R0_en_d0) {
        vlSelf->__PVT___mem_ext_R0_data[0U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][0U];
        vlSelf->__PVT___mem_ext_R0_data[1U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][1U];
        vlSelf->__PVT___mem_ext_R0_data[2U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][2U];
        vlSelf->__PVT___mem_ext_R0_data[3U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][3U];
        vlSelf->__PVT___mem_ext_R0_data[4U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][4U];
        vlSelf->__PVT___mem_ext_R0_data[5U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][5U];
        vlSelf->__PVT___mem_ext_R0_data[6U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][6U];
        vlSelf->__PVT___mem_ext_R0_data[7U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][7U];
        vlSelf->__PVT___mem_ext_R0_data[8U] = vlSelf->__PVT__mem_ext__DOT__Memory
            [vlSelf->__PVT__mem_ext__DOT___R0_addr_d0][8U];
    } else {
        vlSelf->__PVT___mem_ext_R0_data[0U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[0U];
        vlSelf->__PVT___mem_ext_R0_data[1U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[1U];
        vlSelf->__PVT___mem_ext_R0_data[2U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[2U];
        vlSelf->__PVT___mem_ext_R0_data[3U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[3U];
        vlSelf->__PVT___mem_ext_R0_data[4U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[4U];
        vlSelf->__PVT___mem_ext_R0_data[5U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[5U];
        vlSelf->__PVT___mem_ext_R0_data[6U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[6U];
        vlSelf->__PVT___mem_ext_R0_data[7U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[7U];
        vlSelf->__PVT___mem_ext_R0_data[8U] = Vtop_v2__ConstPool__CONST_h16a7ccb2_0[8U];
    }
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAXI_master_slave_tb.h for the primary calling header

#include "VAXI_master_slave_tb__pch.h"
#include "VAXI_master_slave_tb___024root.h"

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_static__TOP(VAXI_master_slave_tb___024root* vlSelf);

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_static(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_static\n"); );
    // Body
    VAXI_master_slave_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_static__TOP(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg = 0U;
}

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_final(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__stl(VAXI_master_slave_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VAXI_master_slave_tb___024root___eval_phase__stl(VAXI_master_slave_tb___024root* vlSelf);

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_settle(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VAXI_master_slave_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("axi_master_slave_tb.sv", 8, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VAXI_master_slave_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__stl(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VAXI_master_slave_tb___024root___stl_sequent__TOP__0(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_W_valid 
        = (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_B_ready 
        = (4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid 
        = (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_R_ready 
        = (3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata 
        = ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE))
            ? vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER[0U]
            : 0U);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg) 
           & (3U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)));
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg;
    if ((1U & (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg)))) {
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
             & (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next = 0U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next 
        = ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg) 
           & (4U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)));
    if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
            if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
                 & (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = 1U;
                if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))) {
                    if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                               | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = 1U;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
            if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                       | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = 1U;
            }
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg;
    if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg) {
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg) {
            if ((1U & ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                       | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg))))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next = 1U;
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next 
                    = (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg));
                if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 1U;
                }
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next 
                    = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg;
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next 
                    = (0xffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg) 
                                - (IData)(1U)));
                if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next 
                        = (0xffffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg) 
                                      + ((IData)(1U) 
                                         << (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg))));
                }
            }
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next 
                = ((1U & (~ ((3U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                             | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg))))) 
                   || (0U < (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg)));
        }
    } else {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg) 
             & (0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 1U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = 0U;
        }
    }
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
        = vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg;
    if ((0U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
        if (vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 0U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
                = (0xffffU & vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS);
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
        }
    } else if ((1U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 1U;
        if (((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg) 
             & (2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next 
                = (0xffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg) 
                            - (IData)(1U)));
            if ((0U >= (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = 0U;
                if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                           | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
                    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
                }
            }
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next 
                = ((0U < (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg))
                    ? 1U : ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                                   | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))
                             ? 0U : 2U));
            if ((0U != (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg))) {
                vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next 
                    = (0xffffU & ((IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg) 
                                  + ((IData)(1U) << (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg))));
            }
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 1U;
        }
    } else if ((2U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg))) {
        if ((1U & ((4U == (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE)) 
                   | (~ (IData)(vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg))))) {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = 1U;
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 0U;
        } else {
            vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = 2U;
        }
    }
}

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_stl(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VAXI_master_slave_tb___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VAXI_master_slave_tb___024root___eval_triggers__stl(VAXI_master_slave_tb___024root* vlSelf);

VL_ATTR_COLD bool VAXI_master_slave_tb___024root___eval_phase__stl(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VAXI_master_slave_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VAXI_master_slave_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__act(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge AXI_master_slave_tb.clock)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VAXI_master_slave_tb___024root___dump_triggers__nba(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge AXI_master_slave_tb.clock)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VAXI_master_slave_tb___024root___ctor_var_reset(VAXI_master_slave_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAXI_master_slave_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAXI_master_slave_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->AXI_master_slave_tb__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_W_valid = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_B_ready = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_AR_valid = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT___AXI_master_AXI_R_ready = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT____Vcellinp__axi_ram__s_axi_wdata = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(256, vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_AW_DATA_BUFFER);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_REQUEST_STATE = VL_RAND_RESET_I(3);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__AXI_master__DOT__AXI_MASTER_WRITE_ADDRESS = VL_RAND_RESET_I(32);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_state_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_reg = VL_RAND_RESET_I(2);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_state_next = VL_RAND_RESET_I(2);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__mem_wr_en = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_reg = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_id_next = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_reg = VL_RAND_RESET_I(16);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_addr_next = VL_RAND_RESET_I(16);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_reg = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_count_next = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_reg = VL_RAND_RESET_I(3);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_size_next = VL_RAND_RESET_I(3);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_reg = VL_RAND_RESET_I(2);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__read_burst_next = VL_RAND_RESET_I(2);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_reg = VL_RAND_RESET_I(16);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_addr_next = VL_RAND_RESET_I(16);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_reg = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_count_next = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_reg = VL_RAND_RESET_I(3);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_size_next = VL_RAND_RESET_I(3);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_reg = VL_RAND_RESET_I(2);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__write_burst_next = VL_RAND_RESET_I(2);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_awready_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_wready_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_bvalid_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_arready_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_reg = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rid_next = VL_RAND_RESET_I(8);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rlast_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_reg = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__s_axi_rvalid_next = VL_RAND_RESET_I(1);
    vlSelf->AXI_master_slave_tb__DOT__uut__DOT__axi_ram__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__AXI_master_slave_tb__DOT__clock__0 = VL_RAND_RESET_I(1);
}

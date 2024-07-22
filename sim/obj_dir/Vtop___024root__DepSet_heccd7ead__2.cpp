// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Init
    VlWide<4>/*127:0*/ top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452;
    VL_ZERO_W(128, top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452);
    // Body
    if (vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_451) {
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_26 
            = ((~ ((0x1aU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_412))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_347));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_27 
            = ((~ ((0x1bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_413))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_348));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_28 
            = ((~ ((0x1cU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_414))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_349));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_29 
            = ((~ ((0x1dU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_415))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_350));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_30 
            = ((~ ((0x1eU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_416))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_351));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_31 
            = ((~ ((0x1fU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_417))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_352));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_32 
            = ((~ ((0x20U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_418))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_353));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_33 
            = ((~ ((0x21U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_419))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_354));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_34 
            = ((~ ((0x22U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_420))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_355));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_35 
            = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_421))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_356));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_36 
            = ((~ ((0x24U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_422))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_357));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_37 
            = ((~ ((0x25U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_423))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_358));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_38 
            = ((~ ((0x26U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_424))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_359));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_39 
            = ((~ ((0x27U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_425))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_360));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_40 
            = ((~ ((0x28U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_426))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_361));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_41 
            = ((~ ((0x29U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_427))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_362));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_42 
            = ((~ ((0x2aU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_428))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_363));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_43 
            = ((~ ((0x2bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_429))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_364));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_44 
            = ((~ ((0x2cU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_430))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_365));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_45 
            = ((~ ((0x2dU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_431))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_366));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_46 
            = ((~ ((0x2eU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_432))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_367));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_47 
            = ((~ ((0x2fU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_433))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_368));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_48 
            = ((~ ((0x30U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_434))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_369));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_49 
            = ((~ ((0x31U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_435))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_370));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_50 
            = ((~ ((0x32U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_436))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_371));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_51 
            = ((~ ((0x33U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_437))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_372));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_52 
            = ((~ ((0x34U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_438))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_373));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_53 
            = ((~ ((0x35U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_439))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_374));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_54 
            = ((~ ((0x36U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_440))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_375));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_55 
            = ((~ ((0x37U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_441))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_376));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_56 
            = ((~ ((0x38U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_442))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_377));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_57 
            = ((~ ((0x39U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_443))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_378));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_58 
            = ((~ ((0x3aU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_444))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_379));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_59 
            = ((~ ((0x3bU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_445))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_380));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_60 
            = ((~ ((0x3cU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_446))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_381));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_61 
            = ((~ ((0x3dU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_447))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_382));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_62 
            = ((~ ((0x3eU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_448))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_383));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_63 
            = ((~ ((0x3fU == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_449))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_384));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_64 
            = ((~ ((0x40U == (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RD)) 
                   | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_450))) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_385));
    } else {
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_26 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_412)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_347));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_27 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_413)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_348));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_28 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_414)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_349));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_29 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_415)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_350));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_30 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_416)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_351));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_31 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_417)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_352));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_32 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_418)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_353));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_33 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_419)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_354));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_34 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_420)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_355));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_35 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_421)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_356));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_36 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_422)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_357));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_37 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_423)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_358));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_38 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_424)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_359));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_39 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_425)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_360));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_40 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_426)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_361));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_41 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_427)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_362));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_42 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_428)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_363));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_43 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_429)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_364));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_44 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_430)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_365));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_45 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_431)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_366));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_46 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_432)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_367));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_47 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_433)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_368));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_48 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_434)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_369));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_49 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_435)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_370));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_50 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_436)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_371));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_51 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_437)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_372));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_52 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_438)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_373));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_53 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_439)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_374));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_54 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_440)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_375));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_55 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_441)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_376));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_56 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_442)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_377));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_57 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_443)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_378));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_58 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_444)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_379));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_59 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_445)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_380));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_60 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_446)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_381));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_61 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_447)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_382));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_62 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_448)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_383));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_63 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_449)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_384));
        vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_64 
            = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_450)) 
               & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_385));
    }
    vlSelf->top__DOT__dut__DOT____Vcellinp__frontend__io_renamed_decoded_fetch_packet_ready 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__full)) 
           & (IData)(vlSelf->top__DOT__dut__DOT____VdfgRegularize_hdc37454e_1_0));
    vlSelf->top__DOT__dut__DOT____Vcellinp__ROB__io_ROB_packet_valid 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__renamed_decoded_fetch_packet_Q__DOT__empty)) 
           & (IData)(vlSelf->top__DOT__dut__DOT____VdfgRegularize_hdc37454e_1_0));
    vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_deq 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty)) 
           & ((IData)(vlSelf->top__DOT__io_frontend_memory_request_ready) 
              & ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty)) 
                 | (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__PC_Q__io_enq_valid))));
    vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__do_enq 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__empty) 
               & (IData)(vlSelf->top__DOT__io_frontend_memory_request_ready))) 
           & ((~ (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT__PC_Q__DOT__full)) 
              & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__instruction_fetch__DOT____Vcellinp__PC_Q__io_enq_valid)));
    top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[0U] 
        = (IData)((((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_63)) 
                    << 0x3fU) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_62)) 
                                  << 0x3eU) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_61)) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_60)) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_59)) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_58)) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_57)) 
                                                            << 0x39U) 
                                                           | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_56)) 
                                                               << 0x38U) 
                                                              | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_55)) 
                                                                  << 0x37U) 
                                                                 | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_54)) 
                                                                     << 0x36U) 
                                                                    | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_53)) 
                                                                        << 0x35U) 
                                                                       | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_52)) 
                                                                           << 0x34U) 
                                                                          | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_51)) 
                                                                              << 0x33U) 
                                                                             | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_50)) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_49)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_48)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_47)) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_46)) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_45)) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_44)) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_43)) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_42)) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_41)) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_40)) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_39)) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_38)) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_37)) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_36)) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_35)) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_34)) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_33)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_32)) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (1U 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_31) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_30) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_29) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_28) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_27) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_26) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_25) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_24) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_23) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_22) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_21) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_20) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_19) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_18) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_17) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_16) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_15) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_14) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_13) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_12) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_11) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_10) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_9) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_8) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_7) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_6) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_5) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_4) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_3) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_2) 
                                                                                << 2U) 
                                                                                | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_1) 
                                                                                << 1U)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[1U] 
        = (IData)(((((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_63)) 
                     << 0x3fU) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_62)) 
                                   << 0x3eU) | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_61)) 
                                                 << 0x3dU) 
                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_60)) 
                                                    << 0x3cU) 
                                                   | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_59)) 
                                                       << 0x3bU) 
                                                      | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_58)) 
                                                          << 0x3aU) 
                                                         | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_57)) 
                                                             << 0x39U) 
                                                            | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_56)) 
                                                                << 0x38U) 
                                                               | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_55)) 
                                                                   << 0x37U) 
                                                                  | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_54)) 
                                                                      << 0x36U) 
                                                                     | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_53)) 
                                                                         << 0x35U) 
                                                                        | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_52)) 
                                                                            << 0x34U) 
                                                                           | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_51)) 
                                                                               << 0x33U) 
                                                                              | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_50)) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_49)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_48)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_47)) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_46)) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_45)) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_44)) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_43)) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_42)) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_41)) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_40)) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_39)) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_38)) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_37)) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_36)) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_35)) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_34)) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_33)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_32)) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (1U 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_31) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_30) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_29) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_28) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_27) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_26) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_25) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_24) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_23) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_22) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_21) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_20) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_19) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_18) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_17) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_16) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_15) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_14) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_13) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_12) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_11) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_10) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_9) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_8) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_7) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_6) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_5) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_4) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_3) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_2) 
                                                                                << 2U) 
                                                                                | ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_1) 
                                                                                << 1U)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) 
                   >> 0x20U));
    top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[2U] 
        = (IData)((0xfffffffffffffffeULL | (QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_64))));
    top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[3U] 
        = (IData)(((0xfffffffffffffffeULL | (QData)((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT__comb_ready_bits_64))) 
                   >> 0x20U));
    vlSelf->top__DOT__dut__DOT__ROB__DOT__allocate 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__ROB__DOT__full)) 
           & (IData)(vlSelf->top__DOT__dut__DOT____Vcellinp__ROB__io_ROB_packet_valid));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RS1) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RS1))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RS2) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_0_RS2))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RS1) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RS1))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RS2) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_1_RS2))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RS1) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RS1))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RS2) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_2_RS2))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RS1) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RS1))));
    vlSelf->top__DOT__dut__DOT___frontend_io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready 
        = (1U & (top__DOT__dut__DOT__frontend__DOT__rename__DOT___GEN_452[
                 ((IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RS2) 
                  >> 5U)] >> (0x1fU & (IData)(vlSelf->top__DOT__dut__DOT__frontend__DOT__rename__DOT___renamed_decoded_fetch_packet_Q_io_deq_bits_decoded_instruction_3_RS2))));
}

void Vtop___024root___timing_resume(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h2fd9cb34__0.resume("@(posedge top.clock)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtop___024root___timing_commit(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h2fd9cb34__0.commit("@(posedge top.clock)");
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
void Vtop___024root___eval_act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___timing_resume(vlSelf);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call VsvsimTestbench::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "VsvsimTestbench__Dpi.h"
#include "VsvsimTestbench.h"

#ifndef VL_DPIDECL_getBitWidth_clock_
#define VL_DPIDECL_getBitWidth_clock_
void getBitWidth_clock(int* value) {
    // DPI export at ../generated-sources/testbench.sv:84:17
    return VsvsimTestbench::getBitWidth_clock(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_can_allocate_
#define VL_DPIDECL_getBitWidth_io_can_allocate_
void getBitWidth_io_can_allocate(int* value) {
    // DPI export at ../generated-sources/testbench.sv:118:17
    return VsvsimTestbench::getBitWidth_io_can_allocate(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_can_reallocate_
#define VL_DPIDECL_getBitWidth_io_can_reallocate_
void getBitWidth_io_can_reallocate(int* value) {
    // DPI export at ../generated-sources/testbench.sv:130:17
    return VsvsimTestbench::getBitWidth_io_can_reallocate(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_GHR_
#define VL_DPIDECL_getBitWidth_io_commit_bits_GHR_
void getBitWidth_io_commit_bits_GHR(int* value) {
    // DPI export at ../generated-sources/testbench.sv:358:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_GHR(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_NEXT_
#define VL_DPIDECL_getBitWidth_io_commit_bits_NEXT_
void getBitWidth_io_commit_bits_NEXT(int* value) {
    // DPI export at ../generated-sources/testbench.sv:324:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_NEXT(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RAT_index_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RAT_index_
void getBitWidth_io_commit_bits_RAT_index(int* value) {
    // DPI export at ../generated-sources/testbench.sv:307:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RAT_index(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_0_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_0_
void getBitWidth_io_commit_bits_RD_0(int* value) {
    // DPI export at ../generated-sources/testbench.sv:222:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_0(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_1_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_1_
void getBitWidth_io_commit_bits_RD_1(int* value) {
    // DPI export at ../generated-sources/testbench.sv:239:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_1(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_2_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_2_
void getBitWidth_io_commit_bits_RD_2(int* value) {
    // DPI export at ../generated-sources/testbench.sv:256:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_2(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_3_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_3_
void getBitWidth_io_commit_bits_RD_3(int* value) {
    // DPI export at ../generated-sources/testbench.sv:273:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_3(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_0_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_0_
void getBitWidth_io_commit_bits_RD_valid_0(int* value) {
    // DPI export at ../generated-sources/testbench.sv:154:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_0(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_1_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_1_
void getBitWidth_io_commit_bits_RD_valid_1(int* value) {
    // DPI export at ../generated-sources/testbench.sv:171:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_1(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_2_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_2_
void getBitWidth_io_commit_bits_RD_valid_2(int* value) {
    // DPI export at ../generated-sources/testbench.sv:188:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_2(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_3_
#define VL_DPIDECL_getBitWidth_io_commit_bits_RD_valid_3_
void getBitWidth_io_commit_bits_RD_valid_3(int* value) {
    // DPI export at ../generated-sources/testbench.sv:205:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_RD_valid_3(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_ROB_index_
#define VL_DPIDECL_getBitWidth_io_commit_bits_ROB_index_
void getBitWidth_io_commit_bits_ROB_index(int* value) {
    // DPI export at ../generated-sources/testbench.sv:443:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_ROB_index(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_TOS_
#define VL_DPIDECL_getBitWidth_io_commit_bits_TOS_
void getBitWidth_io_commit_bits_TOS(int* value) {
    // DPI export at ../generated-sources/testbench.sv:341:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_TOS(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_T_NT_
#define VL_DPIDECL_getBitWidth_io_commit_bits_T_NT_
void getBitWidth_io_commit_bits_T_NT(int* value) {
    // DPI export at ../generated-sources/testbench.sv:460:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_T_NT(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_br_type_
#define VL_DPIDECL_getBitWidth_io_commit_bits_br_type_
void getBitWidth_io_commit_bits_br_type(int* value) {
    // DPI export at ../generated-sources/testbench.sv:426:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_br_type(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_expected_PC_
#define VL_DPIDECL_getBitWidth_io_commit_bits_expected_PC_
void getBitWidth_io_commit_bits_expected_PC(int* value) {
    // DPI export at ../generated-sources/testbench.sv:375:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_expected_PC(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_fetch_PC_
#define VL_DPIDECL_getBitWidth_io_commit_bits_fetch_PC_
void getBitWidth_io_commit_bits_fetch_PC(int* value) {
    // DPI export at ../generated-sources/testbench.sv:477:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_fetch_PC(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_fetch_packet_index_
#define VL_DPIDECL_getBitWidth_io_commit_bits_fetch_packet_index_
void getBitWidth_io_commit_bits_fetch_packet_index(int* value) {
    // DPI export at ../generated-sources/testbench.sv:409:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_fetch_packet_index(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_free_list_front_pointer_
#define VL_DPIDECL_getBitWidth_io_commit_bits_free_list_front_pointer_
void getBitWidth_io_commit_bits_free_list_front_pointer(int* value) {
    // DPI export at ../generated-sources/testbench.sv:290:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_free_list_front_pointer(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_bits_is_misprediction_
#define VL_DPIDECL_getBitWidth_io_commit_bits_is_misprediction_
void getBitWidth_io_commit_bits_is_misprediction(int* value) {
    // DPI export at ../generated-sources/testbench.sv:392:17
    return VsvsimTestbench::getBitWidth_io_commit_bits_is_misprediction(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_commit_valid_
#define VL_DPIDECL_getBitWidth_io_commit_valid_
void getBitWidth_io_commit_valid(int* value) {
    // DPI export at ../generated-sources/testbench.sv:494:17
    return VsvsimTestbench::getBitWidth_io_commit_valid(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_free_list_front_pointer_
#define VL_DPIDECL_getBitWidth_io_free_list_front_pointer_
void getBitWidth_io_free_list_front_pointer(int* value) {
    // DPI export at ../generated-sources/testbench.sv:142:17
    return VsvsimTestbench::getBitWidth_io_free_list_front_pointer(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_rename_valid_0_
#define VL_DPIDECL_getBitWidth_io_rename_valid_0_
void getBitWidth_io_rename_valid_0(int* value) {
    // DPI export at ../generated-sources/testbench.sv:607:17
    return VsvsimTestbench::getBitWidth_io_rename_valid_0(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_rename_valid_1_
#define VL_DPIDECL_getBitWidth_io_rename_valid_1_
void getBitWidth_io_rename_valid_1(int* value) {
    // DPI export at ../generated-sources/testbench.sv:624:17
    return VsvsimTestbench::getBitWidth_io_rename_valid_1(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_rename_valid_2_
#define VL_DPIDECL_getBitWidth_io_rename_valid_2_
void getBitWidth_io_rename_valid_2(int* value) {
    // DPI export at ../generated-sources/testbench.sv:641:17
    return VsvsimTestbench::getBitWidth_io_rename_valid_2(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_rename_valid_3_
#define VL_DPIDECL_getBitWidth_io_rename_valid_3_
void getBitWidth_io_rename_valid_3(int* value) {
    // DPI export at ../generated-sources/testbench.sv:658:17
    return VsvsimTestbench::getBitWidth_io_rename_valid_3(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_valid_0_
#define VL_DPIDECL_getBitWidth_io_renamed_valid_0_
void getBitWidth_io_renamed_valid_0(int* value) {
    // DPI export at ../generated-sources/testbench.sv:511:17
    return VsvsimTestbench::getBitWidth_io_renamed_valid_0(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_valid_1_
#define VL_DPIDECL_getBitWidth_io_renamed_valid_1_
void getBitWidth_io_renamed_valid_1(int* value) {
    // DPI export at ../generated-sources/testbench.sv:523:17
    return VsvsimTestbench::getBitWidth_io_renamed_valid_1(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_valid_2_
#define VL_DPIDECL_getBitWidth_io_renamed_valid_2_
void getBitWidth_io_renamed_valid_2(int* value) {
    // DPI export at ../generated-sources/testbench.sv:535:17
    return VsvsimTestbench::getBitWidth_io_renamed_valid_2(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_valid_3_
#define VL_DPIDECL_getBitWidth_io_renamed_valid_3_
void getBitWidth_io_renamed_valid_3(int* value) {
    // DPI export at ../generated-sources/testbench.sv:547:17
    return VsvsimTestbench::getBitWidth_io_renamed_valid_3(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_values_0_
#define VL_DPIDECL_getBitWidth_io_renamed_values_0_
void getBitWidth_io_renamed_values_0(int* value) {
    // DPI export at ../generated-sources/testbench.sv:559:17
    return VsvsimTestbench::getBitWidth_io_renamed_values_0(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_values_1_
#define VL_DPIDECL_getBitWidth_io_renamed_values_1_
void getBitWidth_io_renamed_values_1(int* value) {
    // DPI export at ../generated-sources/testbench.sv:571:17
    return VsvsimTestbench::getBitWidth_io_renamed_values_1(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_values_2_
#define VL_DPIDECL_getBitWidth_io_renamed_values_2_
void getBitWidth_io_renamed_values_2(int* value) {
    // DPI export at ../generated-sources/testbench.sv:583:17
    return VsvsimTestbench::getBitWidth_io_renamed_values_2(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_io_renamed_values_3_
#define VL_DPIDECL_getBitWidth_io_renamed_values_3_
void getBitWidth_io_renamed_values_3(int* value) {
    // DPI export at ../generated-sources/testbench.sv:595:17
    return VsvsimTestbench::getBitWidth_io_renamed_values_3(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidth_reset_
#define VL_DPIDECL_getBitWidth_reset_
void getBitWidth_reset(int* value) {
    // DPI export at ../generated-sources/testbench.sv:101:17
    return VsvsimTestbench::getBitWidth_reset(value);
}
#endif

#ifndef VL_DPIDECL_getBits_clock_
#define VL_DPIDECL_getBits_clock_
void getBits_clock(svBitVecVal* value_clock) {
    // DPI export at ../generated-sources/testbench.sv:94:17
    return VsvsimTestbench::getBits_clock(value_clock);
}
#endif

#ifndef VL_DPIDECL_getBits_io_can_allocate_
#define VL_DPIDECL_getBits_io_can_allocate_
void getBits_io_can_allocate(svBitVecVal* value_io_can_allocate) {
    // DPI export at ../generated-sources/testbench.sv:123:17
    return VsvsimTestbench::getBits_io_can_allocate(value_io_can_allocate);
}
#endif

#ifndef VL_DPIDECL_getBits_io_can_reallocate_
#define VL_DPIDECL_getBits_io_can_reallocate_
void getBits_io_can_reallocate(svBitVecVal* value_io_can_reallocate) {
    // DPI export at ../generated-sources/testbench.sv:135:17
    return VsvsimTestbench::getBits_io_can_reallocate(value_io_can_reallocate);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_GHR_
#define VL_DPIDECL_getBits_io_commit_bits_GHR_
void getBits_io_commit_bits_GHR(svBitVecVal* value_io_commit_bits_GHR) {
    // DPI export at ../generated-sources/testbench.sv:368:17
    return VsvsimTestbench::getBits_io_commit_bits_GHR(value_io_commit_bits_GHR);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_NEXT_
#define VL_DPIDECL_getBits_io_commit_bits_NEXT_
void getBits_io_commit_bits_NEXT(svBitVecVal* value_io_commit_bits_NEXT) {
    // DPI export at ../generated-sources/testbench.sv:334:17
    return VsvsimTestbench::getBits_io_commit_bits_NEXT(value_io_commit_bits_NEXT);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RAT_index_
#define VL_DPIDECL_getBits_io_commit_bits_RAT_index_
void getBits_io_commit_bits_RAT_index(svBitVecVal* value_io_commit_bits_RAT_index) {
    // DPI export at ../generated-sources/testbench.sv:317:17
    return VsvsimTestbench::getBits_io_commit_bits_RAT_index(value_io_commit_bits_RAT_index);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_0_
#define VL_DPIDECL_getBits_io_commit_bits_RD_0_
void getBits_io_commit_bits_RD_0(svBitVecVal* value_io_commit_bits_RD_0) {
    // DPI export at ../generated-sources/testbench.sv:232:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_0(value_io_commit_bits_RD_0);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_1_
#define VL_DPIDECL_getBits_io_commit_bits_RD_1_
void getBits_io_commit_bits_RD_1(svBitVecVal* value_io_commit_bits_RD_1) {
    // DPI export at ../generated-sources/testbench.sv:249:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_1(value_io_commit_bits_RD_1);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_2_
#define VL_DPIDECL_getBits_io_commit_bits_RD_2_
void getBits_io_commit_bits_RD_2(svBitVecVal* value_io_commit_bits_RD_2) {
    // DPI export at ../generated-sources/testbench.sv:266:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_2(value_io_commit_bits_RD_2);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_3_
#define VL_DPIDECL_getBits_io_commit_bits_RD_3_
void getBits_io_commit_bits_RD_3(svBitVecVal* value_io_commit_bits_RD_3) {
    // DPI export at ../generated-sources/testbench.sv:283:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_3(value_io_commit_bits_RD_3);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_valid_0_
#define VL_DPIDECL_getBits_io_commit_bits_RD_valid_0_
void getBits_io_commit_bits_RD_valid_0(svBitVecVal* value_io_commit_bits_RD_valid_0) {
    // DPI export at ../generated-sources/testbench.sv:164:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_valid_0(value_io_commit_bits_RD_valid_0);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_valid_1_
#define VL_DPIDECL_getBits_io_commit_bits_RD_valid_1_
void getBits_io_commit_bits_RD_valid_1(svBitVecVal* value_io_commit_bits_RD_valid_1) {
    // DPI export at ../generated-sources/testbench.sv:181:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_valid_1(value_io_commit_bits_RD_valid_1);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_valid_2_
#define VL_DPIDECL_getBits_io_commit_bits_RD_valid_2_
void getBits_io_commit_bits_RD_valid_2(svBitVecVal* value_io_commit_bits_RD_valid_2) {
    // DPI export at ../generated-sources/testbench.sv:198:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_valid_2(value_io_commit_bits_RD_valid_2);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_RD_valid_3_
#define VL_DPIDECL_getBits_io_commit_bits_RD_valid_3_
void getBits_io_commit_bits_RD_valid_3(svBitVecVal* value_io_commit_bits_RD_valid_3) {
    // DPI export at ../generated-sources/testbench.sv:215:17
    return VsvsimTestbench::getBits_io_commit_bits_RD_valid_3(value_io_commit_bits_RD_valid_3);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_ROB_index_
#define VL_DPIDECL_getBits_io_commit_bits_ROB_index_
void getBits_io_commit_bits_ROB_index(svBitVecVal* value_io_commit_bits_ROB_index) {
    // DPI export at ../generated-sources/testbench.sv:453:17
    return VsvsimTestbench::getBits_io_commit_bits_ROB_index(value_io_commit_bits_ROB_index);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_TOS_
#define VL_DPIDECL_getBits_io_commit_bits_TOS_
void getBits_io_commit_bits_TOS(svBitVecVal* value_io_commit_bits_TOS) {
    // DPI export at ../generated-sources/testbench.sv:351:17
    return VsvsimTestbench::getBits_io_commit_bits_TOS(value_io_commit_bits_TOS);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_T_NT_
#define VL_DPIDECL_getBits_io_commit_bits_T_NT_
void getBits_io_commit_bits_T_NT(svBitVecVal* value_io_commit_bits_T_NT) {
    // DPI export at ../generated-sources/testbench.sv:470:17
    return VsvsimTestbench::getBits_io_commit_bits_T_NT(value_io_commit_bits_T_NT);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_br_type_
#define VL_DPIDECL_getBits_io_commit_bits_br_type_
void getBits_io_commit_bits_br_type(svBitVecVal* value_io_commit_bits_br_type) {
    // DPI export at ../generated-sources/testbench.sv:436:17
    return VsvsimTestbench::getBits_io_commit_bits_br_type(value_io_commit_bits_br_type);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_expected_PC_
#define VL_DPIDECL_getBits_io_commit_bits_expected_PC_
void getBits_io_commit_bits_expected_PC(svBitVecVal* value_io_commit_bits_expected_PC) {
    // DPI export at ../generated-sources/testbench.sv:385:17
    return VsvsimTestbench::getBits_io_commit_bits_expected_PC(value_io_commit_bits_expected_PC);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_fetch_PC_
#define VL_DPIDECL_getBits_io_commit_bits_fetch_PC_
void getBits_io_commit_bits_fetch_PC(svBitVecVal* value_io_commit_bits_fetch_PC) {
    // DPI export at ../generated-sources/testbench.sv:487:17
    return VsvsimTestbench::getBits_io_commit_bits_fetch_PC(value_io_commit_bits_fetch_PC);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_fetch_packet_index_
#define VL_DPIDECL_getBits_io_commit_bits_fetch_packet_index_
void getBits_io_commit_bits_fetch_packet_index(svBitVecVal* value_io_commit_bits_fetch_packet_index) {
    // DPI export at ../generated-sources/testbench.sv:419:17
    return VsvsimTestbench::getBits_io_commit_bits_fetch_packet_index(value_io_commit_bits_fetch_packet_index);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_free_list_front_pointer_
#define VL_DPIDECL_getBits_io_commit_bits_free_list_front_pointer_
void getBits_io_commit_bits_free_list_front_pointer(svBitVecVal* value_io_commit_bits_free_list_front_pointer) {
    // DPI export at ../generated-sources/testbench.sv:300:17
    return VsvsimTestbench::getBits_io_commit_bits_free_list_front_pointer(value_io_commit_bits_free_list_front_pointer);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_bits_is_misprediction_
#define VL_DPIDECL_getBits_io_commit_bits_is_misprediction_
void getBits_io_commit_bits_is_misprediction(svBitVecVal* value_io_commit_bits_is_misprediction) {
    // DPI export at ../generated-sources/testbench.sv:402:17
    return VsvsimTestbench::getBits_io_commit_bits_is_misprediction(value_io_commit_bits_is_misprediction);
}
#endif

#ifndef VL_DPIDECL_getBits_io_commit_valid_
#define VL_DPIDECL_getBits_io_commit_valid_
void getBits_io_commit_valid(svBitVecVal* value_io_commit_valid) {
    // DPI export at ../generated-sources/testbench.sv:504:17
    return VsvsimTestbench::getBits_io_commit_valid(value_io_commit_valid);
}
#endif

#ifndef VL_DPIDECL_getBits_io_free_list_front_pointer_
#define VL_DPIDECL_getBits_io_free_list_front_pointer_
void getBits_io_free_list_front_pointer(svBitVecVal* value_io_free_list_front_pointer) {
    // DPI export at ../generated-sources/testbench.sv:147:17
    return VsvsimTestbench::getBits_io_free_list_front_pointer(value_io_free_list_front_pointer);
}
#endif

#ifndef VL_DPIDECL_getBits_io_rename_valid_0_
#define VL_DPIDECL_getBits_io_rename_valid_0_
void getBits_io_rename_valid_0(svBitVecVal* value_io_rename_valid_0) {
    // DPI export at ../generated-sources/testbench.sv:617:17
    return VsvsimTestbench::getBits_io_rename_valid_0(value_io_rename_valid_0);
}
#endif

#ifndef VL_DPIDECL_getBits_io_rename_valid_1_
#define VL_DPIDECL_getBits_io_rename_valid_1_
void getBits_io_rename_valid_1(svBitVecVal* value_io_rename_valid_1) {
    // DPI export at ../generated-sources/testbench.sv:634:17
    return VsvsimTestbench::getBits_io_rename_valid_1(value_io_rename_valid_1);
}
#endif

#ifndef VL_DPIDECL_getBits_io_rename_valid_2_
#define VL_DPIDECL_getBits_io_rename_valid_2_
void getBits_io_rename_valid_2(svBitVecVal* value_io_rename_valid_2) {
    // DPI export at ../generated-sources/testbench.sv:651:17
    return VsvsimTestbench::getBits_io_rename_valid_2(value_io_rename_valid_2);
}
#endif

#ifndef VL_DPIDECL_getBits_io_rename_valid_3_
#define VL_DPIDECL_getBits_io_rename_valid_3_
void getBits_io_rename_valid_3(svBitVecVal* value_io_rename_valid_3) {
    // DPI export at ../generated-sources/testbench.sv:668:17
    return VsvsimTestbench::getBits_io_rename_valid_3(value_io_rename_valid_3);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_valid_0_
#define VL_DPIDECL_getBits_io_renamed_valid_0_
void getBits_io_renamed_valid_0(svBitVecVal* value_io_renamed_valid_0) {
    // DPI export at ../generated-sources/testbench.sv:516:17
    return VsvsimTestbench::getBits_io_renamed_valid_0(value_io_renamed_valid_0);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_valid_1_
#define VL_DPIDECL_getBits_io_renamed_valid_1_
void getBits_io_renamed_valid_1(svBitVecVal* value_io_renamed_valid_1) {
    // DPI export at ../generated-sources/testbench.sv:528:17
    return VsvsimTestbench::getBits_io_renamed_valid_1(value_io_renamed_valid_1);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_valid_2_
#define VL_DPIDECL_getBits_io_renamed_valid_2_
void getBits_io_renamed_valid_2(svBitVecVal* value_io_renamed_valid_2) {
    // DPI export at ../generated-sources/testbench.sv:540:17
    return VsvsimTestbench::getBits_io_renamed_valid_2(value_io_renamed_valid_2);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_valid_3_
#define VL_DPIDECL_getBits_io_renamed_valid_3_
void getBits_io_renamed_valid_3(svBitVecVal* value_io_renamed_valid_3) {
    // DPI export at ../generated-sources/testbench.sv:552:17
    return VsvsimTestbench::getBits_io_renamed_valid_3(value_io_renamed_valid_3);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_values_0_
#define VL_DPIDECL_getBits_io_renamed_values_0_
void getBits_io_renamed_values_0(svBitVecVal* value_io_renamed_values_0) {
    // DPI export at ../generated-sources/testbench.sv:564:17
    return VsvsimTestbench::getBits_io_renamed_values_0(value_io_renamed_values_0);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_values_1_
#define VL_DPIDECL_getBits_io_renamed_values_1_
void getBits_io_renamed_values_1(svBitVecVal* value_io_renamed_values_1) {
    // DPI export at ../generated-sources/testbench.sv:576:17
    return VsvsimTestbench::getBits_io_renamed_values_1(value_io_renamed_values_1);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_values_2_
#define VL_DPIDECL_getBits_io_renamed_values_2_
void getBits_io_renamed_values_2(svBitVecVal* value_io_renamed_values_2) {
    // DPI export at ../generated-sources/testbench.sv:588:17
    return VsvsimTestbench::getBits_io_renamed_values_2(value_io_renamed_values_2);
}
#endif

#ifndef VL_DPIDECL_getBits_io_renamed_values_3_
#define VL_DPIDECL_getBits_io_renamed_values_3_
void getBits_io_renamed_values_3(svBitVecVal* value_io_renamed_values_3) {
    // DPI export at ../generated-sources/testbench.sv:600:17
    return VsvsimTestbench::getBits_io_renamed_values_3(value_io_renamed_values_3);
}
#endif

#ifndef VL_DPIDECL_getBits_reset_
#define VL_DPIDECL_getBits_reset_
void getBits_reset(svBitVecVal* value_reset) {
    // DPI export at ../generated-sources/testbench.sv:111:17
    return VsvsimTestbench::getBits_reset(value_reset);
}
#endif

#ifndef VL_DPIDECL_setBits_clock_
#define VL_DPIDECL_setBits_clock_
void setBits_clock(const svBitVecVal* value_clock) {
    // DPI export at ../generated-sources/testbench.sv:89:17
    return VsvsimTestbench::setBits_clock(value_clock);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_GHR_
#define VL_DPIDECL_setBits_io_commit_bits_GHR_
void setBits_io_commit_bits_GHR(const svBitVecVal* value_io_commit_bits_GHR) {
    // DPI export at ../generated-sources/testbench.sv:363:17
    return VsvsimTestbench::setBits_io_commit_bits_GHR(value_io_commit_bits_GHR);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_NEXT_
#define VL_DPIDECL_setBits_io_commit_bits_NEXT_
void setBits_io_commit_bits_NEXT(const svBitVecVal* value_io_commit_bits_NEXT) {
    // DPI export at ../generated-sources/testbench.sv:329:17
    return VsvsimTestbench::setBits_io_commit_bits_NEXT(value_io_commit_bits_NEXT);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RAT_index_
#define VL_DPIDECL_setBits_io_commit_bits_RAT_index_
void setBits_io_commit_bits_RAT_index(const svBitVecVal* value_io_commit_bits_RAT_index) {
    // DPI export at ../generated-sources/testbench.sv:312:17
    return VsvsimTestbench::setBits_io_commit_bits_RAT_index(value_io_commit_bits_RAT_index);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_0_
#define VL_DPIDECL_setBits_io_commit_bits_RD_0_
void setBits_io_commit_bits_RD_0(const svBitVecVal* value_io_commit_bits_RD_0) {
    // DPI export at ../generated-sources/testbench.sv:227:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_0(value_io_commit_bits_RD_0);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_1_
#define VL_DPIDECL_setBits_io_commit_bits_RD_1_
void setBits_io_commit_bits_RD_1(const svBitVecVal* value_io_commit_bits_RD_1) {
    // DPI export at ../generated-sources/testbench.sv:244:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_1(value_io_commit_bits_RD_1);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_2_
#define VL_DPIDECL_setBits_io_commit_bits_RD_2_
void setBits_io_commit_bits_RD_2(const svBitVecVal* value_io_commit_bits_RD_2) {
    // DPI export at ../generated-sources/testbench.sv:261:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_2(value_io_commit_bits_RD_2);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_3_
#define VL_DPIDECL_setBits_io_commit_bits_RD_3_
void setBits_io_commit_bits_RD_3(const svBitVecVal* value_io_commit_bits_RD_3) {
    // DPI export at ../generated-sources/testbench.sv:278:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_3(value_io_commit_bits_RD_3);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_valid_0_
#define VL_DPIDECL_setBits_io_commit_bits_RD_valid_0_
void setBits_io_commit_bits_RD_valid_0(const svBitVecVal* value_io_commit_bits_RD_valid_0) {
    // DPI export at ../generated-sources/testbench.sv:159:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_valid_0(value_io_commit_bits_RD_valid_0);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_valid_1_
#define VL_DPIDECL_setBits_io_commit_bits_RD_valid_1_
void setBits_io_commit_bits_RD_valid_1(const svBitVecVal* value_io_commit_bits_RD_valid_1) {
    // DPI export at ../generated-sources/testbench.sv:176:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_valid_1(value_io_commit_bits_RD_valid_1);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_valid_2_
#define VL_DPIDECL_setBits_io_commit_bits_RD_valid_2_
void setBits_io_commit_bits_RD_valid_2(const svBitVecVal* value_io_commit_bits_RD_valid_2) {
    // DPI export at ../generated-sources/testbench.sv:193:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_valid_2(value_io_commit_bits_RD_valid_2);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_RD_valid_3_
#define VL_DPIDECL_setBits_io_commit_bits_RD_valid_3_
void setBits_io_commit_bits_RD_valid_3(const svBitVecVal* value_io_commit_bits_RD_valid_3) {
    // DPI export at ../generated-sources/testbench.sv:210:17
    return VsvsimTestbench::setBits_io_commit_bits_RD_valid_3(value_io_commit_bits_RD_valid_3);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_ROB_index_
#define VL_DPIDECL_setBits_io_commit_bits_ROB_index_
void setBits_io_commit_bits_ROB_index(const svBitVecVal* value_io_commit_bits_ROB_index) {
    // DPI export at ../generated-sources/testbench.sv:448:17
    return VsvsimTestbench::setBits_io_commit_bits_ROB_index(value_io_commit_bits_ROB_index);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_TOS_
#define VL_DPIDECL_setBits_io_commit_bits_TOS_
void setBits_io_commit_bits_TOS(const svBitVecVal* value_io_commit_bits_TOS) {
    // DPI export at ../generated-sources/testbench.sv:346:17
    return VsvsimTestbench::setBits_io_commit_bits_TOS(value_io_commit_bits_TOS);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_T_NT_
#define VL_DPIDECL_setBits_io_commit_bits_T_NT_
void setBits_io_commit_bits_T_NT(const svBitVecVal* value_io_commit_bits_T_NT) {
    // DPI export at ../generated-sources/testbench.sv:465:17
    return VsvsimTestbench::setBits_io_commit_bits_T_NT(value_io_commit_bits_T_NT);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_br_type_
#define VL_DPIDECL_setBits_io_commit_bits_br_type_
void setBits_io_commit_bits_br_type(const svBitVecVal* value_io_commit_bits_br_type) {
    // DPI export at ../generated-sources/testbench.sv:431:17
    return VsvsimTestbench::setBits_io_commit_bits_br_type(value_io_commit_bits_br_type);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_expected_PC_
#define VL_DPIDECL_setBits_io_commit_bits_expected_PC_
void setBits_io_commit_bits_expected_PC(const svBitVecVal* value_io_commit_bits_expected_PC) {
    // DPI export at ../generated-sources/testbench.sv:380:17
    return VsvsimTestbench::setBits_io_commit_bits_expected_PC(value_io_commit_bits_expected_PC);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_fetch_PC_
#define VL_DPIDECL_setBits_io_commit_bits_fetch_PC_
void setBits_io_commit_bits_fetch_PC(const svBitVecVal* value_io_commit_bits_fetch_PC) {
    // DPI export at ../generated-sources/testbench.sv:482:17
    return VsvsimTestbench::setBits_io_commit_bits_fetch_PC(value_io_commit_bits_fetch_PC);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_fetch_packet_index_
#define VL_DPIDECL_setBits_io_commit_bits_fetch_packet_index_
void setBits_io_commit_bits_fetch_packet_index(const svBitVecVal* value_io_commit_bits_fetch_packet_index) {
    // DPI export at ../generated-sources/testbench.sv:414:17
    return VsvsimTestbench::setBits_io_commit_bits_fetch_packet_index(value_io_commit_bits_fetch_packet_index);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_free_list_front_pointer_
#define VL_DPIDECL_setBits_io_commit_bits_free_list_front_pointer_
void setBits_io_commit_bits_free_list_front_pointer(const svBitVecVal* value_io_commit_bits_free_list_front_pointer) {
    // DPI export at ../generated-sources/testbench.sv:295:17
    return VsvsimTestbench::setBits_io_commit_bits_free_list_front_pointer(value_io_commit_bits_free_list_front_pointer);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_bits_is_misprediction_
#define VL_DPIDECL_setBits_io_commit_bits_is_misprediction_
void setBits_io_commit_bits_is_misprediction(const svBitVecVal* value_io_commit_bits_is_misprediction) {
    // DPI export at ../generated-sources/testbench.sv:397:17
    return VsvsimTestbench::setBits_io_commit_bits_is_misprediction(value_io_commit_bits_is_misprediction);
}
#endif

#ifndef VL_DPIDECL_setBits_io_commit_valid_
#define VL_DPIDECL_setBits_io_commit_valid_
void setBits_io_commit_valid(const svBitVecVal* value_io_commit_valid) {
    // DPI export at ../generated-sources/testbench.sv:499:17
    return VsvsimTestbench::setBits_io_commit_valid(value_io_commit_valid);
}
#endif

#ifndef VL_DPIDECL_setBits_io_rename_valid_0_
#define VL_DPIDECL_setBits_io_rename_valid_0_
void setBits_io_rename_valid_0(const svBitVecVal* value_io_rename_valid_0) {
    // DPI export at ../generated-sources/testbench.sv:612:17
    return VsvsimTestbench::setBits_io_rename_valid_0(value_io_rename_valid_0);
}
#endif

#ifndef VL_DPIDECL_setBits_io_rename_valid_1_
#define VL_DPIDECL_setBits_io_rename_valid_1_
void setBits_io_rename_valid_1(const svBitVecVal* value_io_rename_valid_1) {
    // DPI export at ../generated-sources/testbench.sv:629:17
    return VsvsimTestbench::setBits_io_rename_valid_1(value_io_rename_valid_1);
}
#endif

#ifndef VL_DPIDECL_setBits_io_rename_valid_2_
#define VL_DPIDECL_setBits_io_rename_valid_2_
void setBits_io_rename_valid_2(const svBitVecVal* value_io_rename_valid_2) {
    // DPI export at ../generated-sources/testbench.sv:646:17
    return VsvsimTestbench::setBits_io_rename_valid_2(value_io_rename_valid_2);
}
#endif

#ifndef VL_DPIDECL_setBits_io_rename_valid_3_
#define VL_DPIDECL_setBits_io_rename_valid_3_
void setBits_io_rename_valid_3(const svBitVecVal* value_io_rename_valid_3) {
    // DPI export at ../generated-sources/testbench.sv:663:17
    return VsvsimTestbench::setBits_io_rename_valid_3(value_io_rename_valid_3);
}
#endif

#ifndef VL_DPIDECL_setBits_reset_
#define VL_DPIDECL_setBits_reset_
void setBits_reset(const svBitVecVal* value_reset) {
    // DPI export at ../generated-sources/testbench.sv:106:17
    return VsvsimTestbench::setBits_reset(value_reset);
}
#endif

#ifndef VL_DPIDECL_simulation_disableTrace_
#define VL_DPIDECL_simulation_disableTrace_
void simulation_disableTrace() {
    // DPI export at ../generated-sources/testbench.sv:718:17
    return VsvsimTestbench::simulation_disableTrace();
}
#endif

#ifndef VL_DPIDECL_simulation_enableTrace_
#define VL_DPIDECL_simulation_enableTrace_
void simulation_enableTrace() {
    // DPI export at ../generated-sources/testbench.sv:707:17
    return VsvsimTestbench::simulation_enableTrace();
}
#endif

#ifndef VL_DPIDECL_simulation_initializeTrace_
#define VL_DPIDECL_simulation_initializeTrace_
void simulation_initializeTrace(const char* traceFilePath) {
    // DPI export at ../generated-sources/testbench.sv:690:17
    return VsvsimTestbench::simulation_initializeTrace(traceFilePath);
}
#endif


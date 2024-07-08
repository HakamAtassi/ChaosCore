// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VSVSIMTESTBENCH__DPI_H_
#define VERILATED_VSVSIMTESTBENCH__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at ../generated-sources/testbench.sv:84:17
    extern void getBitWidth_clock(int* value);
    // DPI export at ../generated-sources/testbench.sv:118:17
    extern void getBitWidth_io_can_allocate(int* value);
    // DPI export at ../generated-sources/testbench.sv:130:17
    extern void getBitWidth_io_can_reallocate(int* value);
    // DPI export at ../generated-sources/testbench.sv:358:17
    extern void getBitWidth_io_commit_bits_GHR(int* value);
    // DPI export at ../generated-sources/testbench.sv:324:17
    extern void getBitWidth_io_commit_bits_NEXT(int* value);
    // DPI export at ../generated-sources/testbench.sv:307:17
    extern void getBitWidth_io_commit_bits_RAT_index(int* value);
    // DPI export at ../generated-sources/testbench.sv:222:17
    extern void getBitWidth_io_commit_bits_RD_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:239:17
    extern void getBitWidth_io_commit_bits_RD_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:256:17
    extern void getBitWidth_io_commit_bits_RD_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:273:17
    extern void getBitWidth_io_commit_bits_RD_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:154:17
    extern void getBitWidth_io_commit_bits_RD_valid_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:171:17
    extern void getBitWidth_io_commit_bits_RD_valid_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:188:17
    extern void getBitWidth_io_commit_bits_RD_valid_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:205:17
    extern void getBitWidth_io_commit_bits_RD_valid_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:443:17
    extern void getBitWidth_io_commit_bits_ROB_index(int* value);
    // DPI export at ../generated-sources/testbench.sv:341:17
    extern void getBitWidth_io_commit_bits_TOS(int* value);
    // DPI export at ../generated-sources/testbench.sv:460:17
    extern void getBitWidth_io_commit_bits_T_NT(int* value);
    // DPI export at ../generated-sources/testbench.sv:426:17
    extern void getBitWidth_io_commit_bits_br_type(int* value);
    // DPI export at ../generated-sources/testbench.sv:375:17
    extern void getBitWidth_io_commit_bits_expected_PC(int* value);
    // DPI export at ../generated-sources/testbench.sv:477:17
    extern void getBitWidth_io_commit_bits_fetch_PC(int* value);
    // DPI export at ../generated-sources/testbench.sv:409:17
    extern void getBitWidth_io_commit_bits_fetch_packet_index(int* value);
    // DPI export at ../generated-sources/testbench.sv:290:17
    extern void getBitWidth_io_commit_bits_free_list_front_pointer(int* value);
    // DPI export at ../generated-sources/testbench.sv:392:17
    extern void getBitWidth_io_commit_bits_is_misprediction(int* value);
    // DPI export at ../generated-sources/testbench.sv:494:17
    extern void getBitWidth_io_commit_valid(int* value);
    // DPI export at ../generated-sources/testbench.sv:142:17
    extern void getBitWidth_io_free_list_front_pointer(int* value);
    // DPI export at ../generated-sources/testbench.sv:607:17
    extern void getBitWidth_io_rename_valid_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:624:17
    extern void getBitWidth_io_rename_valid_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:641:17
    extern void getBitWidth_io_rename_valid_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:658:17
    extern void getBitWidth_io_rename_valid_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:511:17
    extern void getBitWidth_io_renamed_valid_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:523:17
    extern void getBitWidth_io_renamed_valid_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:535:17
    extern void getBitWidth_io_renamed_valid_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:547:17
    extern void getBitWidth_io_renamed_valid_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:559:17
    extern void getBitWidth_io_renamed_values_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:571:17
    extern void getBitWidth_io_renamed_values_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:583:17
    extern void getBitWidth_io_renamed_values_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:595:17
    extern void getBitWidth_io_renamed_values_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:101:17
    extern void getBitWidth_reset(int* value);
    // DPI export at ../generated-sources/testbench.sv:94:17
    extern void getBits_clock(svBitVecVal* value_clock);
    // DPI export at ../generated-sources/testbench.sv:123:17
    extern void getBits_io_can_allocate(svBitVecVal* value_io_can_allocate);
    // DPI export at ../generated-sources/testbench.sv:135:17
    extern void getBits_io_can_reallocate(svBitVecVal* value_io_can_reallocate);
    // DPI export at ../generated-sources/testbench.sv:368:17
    extern void getBits_io_commit_bits_GHR(svBitVecVal* value_io_commit_bits_GHR);
    // DPI export at ../generated-sources/testbench.sv:334:17
    extern void getBits_io_commit_bits_NEXT(svBitVecVal* value_io_commit_bits_NEXT);
    // DPI export at ../generated-sources/testbench.sv:317:17
    extern void getBits_io_commit_bits_RAT_index(svBitVecVal* value_io_commit_bits_RAT_index);
    // DPI export at ../generated-sources/testbench.sv:232:17
    extern void getBits_io_commit_bits_RD_0(svBitVecVal* value_io_commit_bits_RD_0);
    // DPI export at ../generated-sources/testbench.sv:249:17
    extern void getBits_io_commit_bits_RD_1(svBitVecVal* value_io_commit_bits_RD_1);
    // DPI export at ../generated-sources/testbench.sv:266:17
    extern void getBits_io_commit_bits_RD_2(svBitVecVal* value_io_commit_bits_RD_2);
    // DPI export at ../generated-sources/testbench.sv:283:17
    extern void getBits_io_commit_bits_RD_3(svBitVecVal* value_io_commit_bits_RD_3);
    // DPI export at ../generated-sources/testbench.sv:164:17
    extern void getBits_io_commit_bits_RD_valid_0(svBitVecVal* value_io_commit_bits_RD_valid_0);
    // DPI export at ../generated-sources/testbench.sv:181:17
    extern void getBits_io_commit_bits_RD_valid_1(svBitVecVal* value_io_commit_bits_RD_valid_1);
    // DPI export at ../generated-sources/testbench.sv:198:17
    extern void getBits_io_commit_bits_RD_valid_2(svBitVecVal* value_io_commit_bits_RD_valid_2);
    // DPI export at ../generated-sources/testbench.sv:215:17
    extern void getBits_io_commit_bits_RD_valid_3(svBitVecVal* value_io_commit_bits_RD_valid_3);
    // DPI export at ../generated-sources/testbench.sv:453:17
    extern void getBits_io_commit_bits_ROB_index(svBitVecVal* value_io_commit_bits_ROB_index);
    // DPI export at ../generated-sources/testbench.sv:351:17
    extern void getBits_io_commit_bits_TOS(svBitVecVal* value_io_commit_bits_TOS);
    // DPI export at ../generated-sources/testbench.sv:470:17
    extern void getBits_io_commit_bits_T_NT(svBitVecVal* value_io_commit_bits_T_NT);
    // DPI export at ../generated-sources/testbench.sv:436:17
    extern void getBits_io_commit_bits_br_type(svBitVecVal* value_io_commit_bits_br_type);
    // DPI export at ../generated-sources/testbench.sv:385:17
    extern void getBits_io_commit_bits_expected_PC(svBitVecVal* value_io_commit_bits_expected_PC);
    // DPI export at ../generated-sources/testbench.sv:487:17
    extern void getBits_io_commit_bits_fetch_PC(svBitVecVal* value_io_commit_bits_fetch_PC);
    // DPI export at ../generated-sources/testbench.sv:419:17
    extern void getBits_io_commit_bits_fetch_packet_index(svBitVecVal* value_io_commit_bits_fetch_packet_index);
    // DPI export at ../generated-sources/testbench.sv:300:17
    extern void getBits_io_commit_bits_free_list_front_pointer(svBitVecVal* value_io_commit_bits_free_list_front_pointer);
    // DPI export at ../generated-sources/testbench.sv:402:17
    extern void getBits_io_commit_bits_is_misprediction(svBitVecVal* value_io_commit_bits_is_misprediction);
    // DPI export at ../generated-sources/testbench.sv:504:17
    extern void getBits_io_commit_valid(svBitVecVal* value_io_commit_valid);
    // DPI export at ../generated-sources/testbench.sv:147:17
    extern void getBits_io_free_list_front_pointer(svBitVecVal* value_io_free_list_front_pointer);
    // DPI export at ../generated-sources/testbench.sv:617:17
    extern void getBits_io_rename_valid_0(svBitVecVal* value_io_rename_valid_0);
    // DPI export at ../generated-sources/testbench.sv:634:17
    extern void getBits_io_rename_valid_1(svBitVecVal* value_io_rename_valid_1);
    // DPI export at ../generated-sources/testbench.sv:651:17
    extern void getBits_io_rename_valid_2(svBitVecVal* value_io_rename_valid_2);
    // DPI export at ../generated-sources/testbench.sv:668:17
    extern void getBits_io_rename_valid_3(svBitVecVal* value_io_rename_valid_3);
    // DPI export at ../generated-sources/testbench.sv:516:17
    extern void getBits_io_renamed_valid_0(svBitVecVal* value_io_renamed_valid_0);
    // DPI export at ../generated-sources/testbench.sv:528:17
    extern void getBits_io_renamed_valid_1(svBitVecVal* value_io_renamed_valid_1);
    // DPI export at ../generated-sources/testbench.sv:540:17
    extern void getBits_io_renamed_valid_2(svBitVecVal* value_io_renamed_valid_2);
    // DPI export at ../generated-sources/testbench.sv:552:17
    extern void getBits_io_renamed_valid_3(svBitVecVal* value_io_renamed_valid_3);
    // DPI export at ../generated-sources/testbench.sv:564:17
    extern void getBits_io_renamed_values_0(svBitVecVal* value_io_renamed_values_0);
    // DPI export at ../generated-sources/testbench.sv:576:17
    extern void getBits_io_renamed_values_1(svBitVecVal* value_io_renamed_values_1);
    // DPI export at ../generated-sources/testbench.sv:588:17
    extern void getBits_io_renamed_values_2(svBitVecVal* value_io_renamed_values_2);
    // DPI export at ../generated-sources/testbench.sv:600:17
    extern void getBits_io_renamed_values_3(svBitVecVal* value_io_renamed_values_3);
    // DPI export at ../generated-sources/testbench.sv:111:17
    extern void getBits_reset(svBitVecVal* value_reset);
    // DPI export at ../generated-sources/testbench.sv:89:17
    extern void setBits_clock(const svBitVecVal* value_clock);
    // DPI export at ../generated-sources/testbench.sv:363:17
    extern void setBits_io_commit_bits_GHR(const svBitVecVal* value_io_commit_bits_GHR);
    // DPI export at ../generated-sources/testbench.sv:329:17
    extern void setBits_io_commit_bits_NEXT(const svBitVecVal* value_io_commit_bits_NEXT);
    // DPI export at ../generated-sources/testbench.sv:312:17
    extern void setBits_io_commit_bits_RAT_index(const svBitVecVal* value_io_commit_bits_RAT_index);
    // DPI export at ../generated-sources/testbench.sv:227:17
    extern void setBits_io_commit_bits_RD_0(const svBitVecVal* value_io_commit_bits_RD_0);
    // DPI export at ../generated-sources/testbench.sv:244:17
    extern void setBits_io_commit_bits_RD_1(const svBitVecVal* value_io_commit_bits_RD_1);
    // DPI export at ../generated-sources/testbench.sv:261:17
    extern void setBits_io_commit_bits_RD_2(const svBitVecVal* value_io_commit_bits_RD_2);
    // DPI export at ../generated-sources/testbench.sv:278:17
    extern void setBits_io_commit_bits_RD_3(const svBitVecVal* value_io_commit_bits_RD_3);
    // DPI export at ../generated-sources/testbench.sv:159:17
    extern void setBits_io_commit_bits_RD_valid_0(const svBitVecVal* value_io_commit_bits_RD_valid_0);
    // DPI export at ../generated-sources/testbench.sv:176:17
    extern void setBits_io_commit_bits_RD_valid_1(const svBitVecVal* value_io_commit_bits_RD_valid_1);
    // DPI export at ../generated-sources/testbench.sv:193:17
    extern void setBits_io_commit_bits_RD_valid_2(const svBitVecVal* value_io_commit_bits_RD_valid_2);
    // DPI export at ../generated-sources/testbench.sv:210:17
    extern void setBits_io_commit_bits_RD_valid_3(const svBitVecVal* value_io_commit_bits_RD_valid_3);
    // DPI export at ../generated-sources/testbench.sv:448:17
    extern void setBits_io_commit_bits_ROB_index(const svBitVecVal* value_io_commit_bits_ROB_index);
    // DPI export at ../generated-sources/testbench.sv:346:17
    extern void setBits_io_commit_bits_TOS(const svBitVecVal* value_io_commit_bits_TOS);
    // DPI export at ../generated-sources/testbench.sv:465:17
    extern void setBits_io_commit_bits_T_NT(const svBitVecVal* value_io_commit_bits_T_NT);
    // DPI export at ../generated-sources/testbench.sv:431:17
    extern void setBits_io_commit_bits_br_type(const svBitVecVal* value_io_commit_bits_br_type);
    // DPI export at ../generated-sources/testbench.sv:380:17
    extern void setBits_io_commit_bits_expected_PC(const svBitVecVal* value_io_commit_bits_expected_PC);
    // DPI export at ../generated-sources/testbench.sv:482:17
    extern void setBits_io_commit_bits_fetch_PC(const svBitVecVal* value_io_commit_bits_fetch_PC);
    // DPI export at ../generated-sources/testbench.sv:414:17
    extern void setBits_io_commit_bits_fetch_packet_index(const svBitVecVal* value_io_commit_bits_fetch_packet_index);
    // DPI export at ../generated-sources/testbench.sv:295:17
    extern void setBits_io_commit_bits_free_list_front_pointer(const svBitVecVal* value_io_commit_bits_free_list_front_pointer);
    // DPI export at ../generated-sources/testbench.sv:397:17
    extern void setBits_io_commit_bits_is_misprediction(const svBitVecVal* value_io_commit_bits_is_misprediction);
    // DPI export at ../generated-sources/testbench.sv:499:17
    extern void setBits_io_commit_valid(const svBitVecVal* value_io_commit_valid);
    // DPI export at ../generated-sources/testbench.sv:612:17
    extern void setBits_io_rename_valid_0(const svBitVecVal* value_io_rename_valid_0);
    // DPI export at ../generated-sources/testbench.sv:629:17
    extern void setBits_io_rename_valid_1(const svBitVecVal* value_io_rename_valid_1);
    // DPI export at ../generated-sources/testbench.sv:646:17
    extern void setBits_io_rename_valid_2(const svBitVecVal* value_io_rename_valid_2);
    // DPI export at ../generated-sources/testbench.sv:663:17
    extern void setBits_io_rename_valid_3(const svBitVecVal* value_io_rename_valid_3);
    // DPI export at ../generated-sources/testbench.sv:106:17
    extern void setBits_reset(const svBitVecVal* value_reset);
    // DPI export at ../generated-sources/testbench.sv:718:17
    extern void simulation_disableTrace();
    // DPI export at ../generated-sources/testbench.sv:707:17
    extern void simulation_enableTrace();
    // DPI export at ../generated-sources/testbench.sv:690:17
    extern void simulation_initializeTrace(const char* traceFilePath);

    // DPI IMPORTS
    // DPI import at ../generated-sources/testbench.sv:685:32
    extern void run_simulation(int timesteps);
    // DPI import at ../generated-sources/testbench.sv:674:31
    extern int simulation_body();

#ifdef __cplusplus
}
#endif

#endif  // guard

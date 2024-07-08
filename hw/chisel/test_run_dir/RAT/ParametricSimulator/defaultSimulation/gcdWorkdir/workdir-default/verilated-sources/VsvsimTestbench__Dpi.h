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
    // DPI export at ../generated-sources/testbench.sv:90:17
    extern void getBitWidth_clock(int* value);
    // DPI export at ../generated-sources/testbench.sv:220:17
    extern void getBitWidth_io_RAT_RD_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:232:17
    extern void getBitWidth_io_RAT_RD_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:244:17
    extern void getBitWidth_io_RAT_RD_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:256:17
    extern void getBitWidth_io_RAT_RD_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:172:17
    extern void getBitWidth_io_RAT_RS1_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:184:17
    extern void getBitWidth_io_RAT_RS1_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:196:17
    extern void getBitWidth_io_RAT_RS1_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:208:17
    extern void getBitWidth_io_RAT_RS1_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:124:17
    extern void getBitWidth_io_RAT_RS2_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:136:17
    extern void getBitWidth_io_RAT_RS2_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:148:17
    extern void getBitWidth_io_RAT_RS2_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:160:17
    extern void getBitWidth_io_RAT_RS2_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:292:17
    extern void getBitWidth_io_active_checkpoint_value(int* value);
    // DPI export at ../generated-sources/testbench.sv:268:17
    extern void getBitWidth_io_checkpoints_empty(int* value);
    // DPI export at ../generated-sources/testbench.sv:280:17
    extern void getBitWidth_io_checkpoints_full(int* value);
    // DPI export at ../generated-sources/testbench.sv:355:17
    extern void getBitWidth_io_create_checkpoint(int* value);
    // DPI export at ../generated-sources/testbench.sv:321:17
    extern void getBitWidth_io_free_checkpoint(int* value);
    // DPI export at ../generated-sources/testbench.sv:372:17
    extern void getBitWidth_io_free_list_RD_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:389:17
    extern void getBitWidth_io_free_list_RD_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:406:17
    extern void getBitWidth_io_free_list_RD_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:423:17
    extern void getBitWidth_io_free_list_RD_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:440:17
    extern void getBitWidth_io_free_list_wr_en_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:457:17
    extern void getBitWidth_io_free_list_wr_en_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:474:17
    extern void getBitWidth_io_free_list_wr_en_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:491:17
    extern void getBitWidth_io_free_list_wr_en_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:508:17
    extern void getBitWidth_io_instruction_RD_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:525:17
    extern void getBitWidth_io_instruction_RD_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:542:17
    extern void getBitWidth_io_instruction_RD_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:559:17
    extern void getBitWidth_io_instruction_RD_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:644:17
    extern void getBitWidth_io_instruction_RS1_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:661:17
    extern void getBitWidth_io_instruction_RS1_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:678:17
    extern void getBitWidth_io_instruction_RS1_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:695:17
    extern void getBitWidth_io_instruction_RS1_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:576:17
    extern void getBitWidth_io_instruction_RS2_0(int* value);
    // DPI export at ../generated-sources/testbench.sv:593:17
    extern void getBitWidth_io_instruction_RS2_1(int* value);
    // DPI export at ../generated-sources/testbench.sv:610:17
    extern void getBitWidth_io_instruction_RS2_2(int* value);
    // DPI export at ../generated-sources/testbench.sv:627:17
    extern void getBitWidth_io_instruction_RS2_3(int* value);
    // DPI export at ../generated-sources/testbench.sv:338:17
    extern void getBitWidth_io_restore_checkpoint(int* value);
    // DPI export at ../generated-sources/testbench.sv:304:17
    extern void getBitWidth_io_restore_checkpoint_value(int* value);
    // DPI export at ../generated-sources/testbench.sv:107:17
    extern void getBitWidth_reset(int* value);
    // DPI export at ../generated-sources/testbench.sv:100:17
    extern void getBits_clock(svBitVecVal* value_clock);
    // DPI export at ../generated-sources/testbench.sv:225:17
    extern void getBits_io_RAT_RD_0(svBitVecVal* value_io_RAT_RD_0);
    // DPI export at ../generated-sources/testbench.sv:237:17
    extern void getBits_io_RAT_RD_1(svBitVecVal* value_io_RAT_RD_1);
    // DPI export at ../generated-sources/testbench.sv:249:17
    extern void getBits_io_RAT_RD_2(svBitVecVal* value_io_RAT_RD_2);
    // DPI export at ../generated-sources/testbench.sv:261:17
    extern void getBits_io_RAT_RD_3(svBitVecVal* value_io_RAT_RD_3);
    // DPI export at ../generated-sources/testbench.sv:177:17
    extern void getBits_io_RAT_RS1_0(svBitVecVal* value_io_RAT_RS1_0);
    // DPI export at ../generated-sources/testbench.sv:189:17
    extern void getBits_io_RAT_RS1_1(svBitVecVal* value_io_RAT_RS1_1);
    // DPI export at ../generated-sources/testbench.sv:201:17
    extern void getBits_io_RAT_RS1_2(svBitVecVal* value_io_RAT_RS1_2);
    // DPI export at ../generated-sources/testbench.sv:213:17
    extern void getBits_io_RAT_RS1_3(svBitVecVal* value_io_RAT_RS1_3);
    // DPI export at ../generated-sources/testbench.sv:129:17
    extern void getBits_io_RAT_RS2_0(svBitVecVal* value_io_RAT_RS2_0);
    // DPI export at ../generated-sources/testbench.sv:141:17
    extern void getBits_io_RAT_RS2_1(svBitVecVal* value_io_RAT_RS2_1);
    // DPI export at ../generated-sources/testbench.sv:153:17
    extern void getBits_io_RAT_RS2_2(svBitVecVal* value_io_RAT_RS2_2);
    // DPI export at ../generated-sources/testbench.sv:165:17
    extern void getBits_io_RAT_RS2_3(svBitVecVal* value_io_RAT_RS2_3);
    // DPI export at ../generated-sources/testbench.sv:297:17
    extern void getBits_io_active_checkpoint_value(svBitVecVal* value_io_active_checkpoint_value);
    // DPI export at ../generated-sources/testbench.sv:273:17
    extern void getBits_io_checkpoints_empty(svBitVecVal* value_io_checkpoints_empty);
    // DPI export at ../generated-sources/testbench.sv:285:17
    extern void getBits_io_checkpoints_full(svBitVecVal* value_io_checkpoints_full);
    // DPI export at ../generated-sources/testbench.sv:365:17
    extern void getBits_io_create_checkpoint(svBitVecVal* value_io_create_checkpoint);
    // DPI export at ../generated-sources/testbench.sv:331:17
    extern void getBits_io_free_checkpoint(svBitVecVal* value_io_free_checkpoint);
    // DPI export at ../generated-sources/testbench.sv:382:17
    extern void getBits_io_free_list_RD_0(svBitVecVal* value_io_free_list_RD_0);
    // DPI export at ../generated-sources/testbench.sv:399:17
    extern void getBits_io_free_list_RD_1(svBitVecVal* value_io_free_list_RD_1);
    // DPI export at ../generated-sources/testbench.sv:416:17
    extern void getBits_io_free_list_RD_2(svBitVecVal* value_io_free_list_RD_2);
    // DPI export at ../generated-sources/testbench.sv:433:17
    extern void getBits_io_free_list_RD_3(svBitVecVal* value_io_free_list_RD_3);
    // DPI export at ../generated-sources/testbench.sv:450:17
    extern void getBits_io_free_list_wr_en_0(svBitVecVal* value_io_free_list_wr_en_0);
    // DPI export at ../generated-sources/testbench.sv:467:17
    extern void getBits_io_free_list_wr_en_1(svBitVecVal* value_io_free_list_wr_en_1);
    // DPI export at ../generated-sources/testbench.sv:484:17
    extern void getBits_io_free_list_wr_en_2(svBitVecVal* value_io_free_list_wr_en_2);
    // DPI export at ../generated-sources/testbench.sv:501:17
    extern void getBits_io_free_list_wr_en_3(svBitVecVal* value_io_free_list_wr_en_3);
    // DPI export at ../generated-sources/testbench.sv:518:17
    extern void getBits_io_instruction_RD_0(svBitVecVal* value_io_instruction_RD_0);
    // DPI export at ../generated-sources/testbench.sv:535:17
    extern void getBits_io_instruction_RD_1(svBitVecVal* value_io_instruction_RD_1);
    // DPI export at ../generated-sources/testbench.sv:552:17
    extern void getBits_io_instruction_RD_2(svBitVecVal* value_io_instruction_RD_2);
    // DPI export at ../generated-sources/testbench.sv:569:17
    extern void getBits_io_instruction_RD_3(svBitVecVal* value_io_instruction_RD_3);
    // DPI export at ../generated-sources/testbench.sv:654:17
    extern void getBits_io_instruction_RS1_0(svBitVecVal* value_io_instruction_RS1_0);
    // DPI export at ../generated-sources/testbench.sv:671:17
    extern void getBits_io_instruction_RS1_1(svBitVecVal* value_io_instruction_RS1_1);
    // DPI export at ../generated-sources/testbench.sv:688:17
    extern void getBits_io_instruction_RS1_2(svBitVecVal* value_io_instruction_RS1_2);
    // DPI export at ../generated-sources/testbench.sv:705:17
    extern void getBits_io_instruction_RS1_3(svBitVecVal* value_io_instruction_RS1_3);
    // DPI export at ../generated-sources/testbench.sv:586:17
    extern void getBits_io_instruction_RS2_0(svBitVecVal* value_io_instruction_RS2_0);
    // DPI export at ../generated-sources/testbench.sv:603:17
    extern void getBits_io_instruction_RS2_1(svBitVecVal* value_io_instruction_RS2_1);
    // DPI export at ../generated-sources/testbench.sv:620:17
    extern void getBits_io_instruction_RS2_2(svBitVecVal* value_io_instruction_RS2_2);
    // DPI export at ../generated-sources/testbench.sv:637:17
    extern void getBits_io_instruction_RS2_3(svBitVecVal* value_io_instruction_RS2_3);
    // DPI export at ../generated-sources/testbench.sv:348:17
    extern void getBits_io_restore_checkpoint(svBitVecVal* value_io_restore_checkpoint);
    // DPI export at ../generated-sources/testbench.sv:314:17
    extern void getBits_io_restore_checkpoint_value(svBitVecVal* value_io_restore_checkpoint_value);
    // DPI export at ../generated-sources/testbench.sv:117:17
    extern void getBits_reset(svBitVecVal* value_reset);
    // DPI export at ../generated-sources/testbench.sv:95:17
    extern void setBits_clock(const svBitVecVal* value_clock);
    // DPI export at ../generated-sources/testbench.sv:360:17
    extern void setBits_io_create_checkpoint(const svBitVecVal* value_io_create_checkpoint);
    // DPI export at ../generated-sources/testbench.sv:326:17
    extern void setBits_io_free_checkpoint(const svBitVecVal* value_io_free_checkpoint);
    // DPI export at ../generated-sources/testbench.sv:377:17
    extern void setBits_io_free_list_RD_0(const svBitVecVal* value_io_free_list_RD_0);
    // DPI export at ../generated-sources/testbench.sv:394:17
    extern void setBits_io_free_list_RD_1(const svBitVecVal* value_io_free_list_RD_1);
    // DPI export at ../generated-sources/testbench.sv:411:17
    extern void setBits_io_free_list_RD_2(const svBitVecVal* value_io_free_list_RD_2);
    // DPI export at ../generated-sources/testbench.sv:428:17
    extern void setBits_io_free_list_RD_3(const svBitVecVal* value_io_free_list_RD_3);
    // DPI export at ../generated-sources/testbench.sv:445:17
    extern void setBits_io_free_list_wr_en_0(const svBitVecVal* value_io_free_list_wr_en_0);
    // DPI export at ../generated-sources/testbench.sv:462:17
    extern void setBits_io_free_list_wr_en_1(const svBitVecVal* value_io_free_list_wr_en_1);
    // DPI export at ../generated-sources/testbench.sv:479:17
    extern void setBits_io_free_list_wr_en_2(const svBitVecVal* value_io_free_list_wr_en_2);
    // DPI export at ../generated-sources/testbench.sv:496:17
    extern void setBits_io_free_list_wr_en_3(const svBitVecVal* value_io_free_list_wr_en_3);
    // DPI export at ../generated-sources/testbench.sv:513:17
    extern void setBits_io_instruction_RD_0(const svBitVecVal* value_io_instruction_RD_0);
    // DPI export at ../generated-sources/testbench.sv:530:17
    extern void setBits_io_instruction_RD_1(const svBitVecVal* value_io_instruction_RD_1);
    // DPI export at ../generated-sources/testbench.sv:547:17
    extern void setBits_io_instruction_RD_2(const svBitVecVal* value_io_instruction_RD_2);
    // DPI export at ../generated-sources/testbench.sv:564:17
    extern void setBits_io_instruction_RD_3(const svBitVecVal* value_io_instruction_RD_3);
    // DPI export at ../generated-sources/testbench.sv:649:17
    extern void setBits_io_instruction_RS1_0(const svBitVecVal* value_io_instruction_RS1_0);
    // DPI export at ../generated-sources/testbench.sv:666:17
    extern void setBits_io_instruction_RS1_1(const svBitVecVal* value_io_instruction_RS1_1);
    // DPI export at ../generated-sources/testbench.sv:683:17
    extern void setBits_io_instruction_RS1_2(const svBitVecVal* value_io_instruction_RS1_2);
    // DPI export at ../generated-sources/testbench.sv:700:17
    extern void setBits_io_instruction_RS1_3(const svBitVecVal* value_io_instruction_RS1_3);
    // DPI export at ../generated-sources/testbench.sv:581:17
    extern void setBits_io_instruction_RS2_0(const svBitVecVal* value_io_instruction_RS2_0);
    // DPI export at ../generated-sources/testbench.sv:598:17
    extern void setBits_io_instruction_RS2_1(const svBitVecVal* value_io_instruction_RS2_1);
    // DPI export at ../generated-sources/testbench.sv:615:17
    extern void setBits_io_instruction_RS2_2(const svBitVecVal* value_io_instruction_RS2_2);
    // DPI export at ../generated-sources/testbench.sv:632:17
    extern void setBits_io_instruction_RS2_3(const svBitVecVal* value_io_instruction_RS2_3);
    // DPI export at ../generated-sources/testbench.sv:343:17
    extern void setBits_io_restore_checkpoint(const svBitVecVal* value_io_restore_checkpoint);
    // DPI export at ../generated-sources/testbench.sv:309:17
    extern void setBits_io_restore_checkpoint_value(const svBitVecVal* value_io_restore_checkpoint_value);
    // DPI export at ../generated-sources/testbench.sv:112:17
    extern void setBits_reset(const svBitVecVal* value_reset);
    // DPI export at ../generated-sources/testbench.sv:755:17
    extern void simulation_disableTrace();
    // DPI export at ../generated-sources/testbench.sv:744:17
    extern void simulation_enableTrace();
    // DPI export at ../generated-sources/testbench.sv:727:17
    extern void simulation_initializeTrace(const char* traceFilePath);

    // DPI IMPORTS
    // DPI import at ../generated-sources/testbench.sv:722:32
    extern void run_simulation(int timesteps);
    // DPI import at ../generated-sources/testbench.sv:711:31
    extern int simulation_body();

#ifdef __cplusplus
}
#endif

#endif  // guard

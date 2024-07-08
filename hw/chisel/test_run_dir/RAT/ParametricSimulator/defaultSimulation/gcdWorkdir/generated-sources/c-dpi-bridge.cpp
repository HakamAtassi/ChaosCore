#include <stdint.h>

#ifdef SVSIM_ENABLE_VERILATOR_SUPPORT
#include "verilated-sources/VsvsimTestbench__Dpi.h"
#endif
#ifdef SVSIM_ENABLE_VCS_SUPPORT
#include "vc_hdrs.h"
#endif

extern "C" {

int port_getter(int id, int *bitWidth, void (**getter)(uint8_t*)) {
  switch (id) {
    case 0: // clock
      getBitWidth_clock(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_clock;
      return 0;
    case 1: // reset
      getBitWidth_reset(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_reset;
      return 0;
    case 2: // io_RAT_RS2_0
      getBitWidth_io_RAT_RS2_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS2_0;
      return 0;
    case 3: // io_RAT_RS2_1
      getBitWidth_io_RAT_RS2_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS2_1;
      return 0;
    case 4: // io_RAT_RS2_2
      getBitWidth_io_RAT_RS2_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS2_2;
      return 0;
    case 5: // io_RAT_RS2_3
      getBitWidth_io_RAT_RS2_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS2_3;
      return 0;
    case 6: // io_RAT_RS1_0
      getBitWidth_io_RAT_RS1_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS1_0;
      return 0;
    case 7: // io_RAT_RS1_1
      getBitWidth_io_RAT_RS1_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS1_1;
      return 0;
    case 8: // io_RAT_RS1_2
      getBitWidth_io_RAT_RS1_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS1_2;
      return 0;
    case 9: // io_RAT_RS1_3
      getBitWidth_io_RAT_RS1_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RS1_3;
      return 0;
    case 10: // io_RAT_RD_0
      getBitWidth_io_RAT_RD_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RD_0;
      return 0;
    case 11: // io_RAT_RD_1
      getBitWidth_io_RAT_RD_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RD_1;
      return 0;
    case 12: // io_RAT_RD_2
      getBitWidth_io_RAT_RD_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RD_2;
      return 0;
    case 13: // io_RAT_RD_3
      getBitWidth_io_RAT_RD_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_RAT_RD_3;
      return 0;
    case 14: // io_checkpoints_empty
      getBitWidth_io_checkpoints_empty(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_checkpoints_empty;
      return 0;
    case 15: // io_checkpoints_full
      getBitWidth_io_checkpoints_full(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_checkpoints_full;
      return 0;
    case 16: // io_active_checkpoint_value
      getBitWidth_io_active_checkpoint_value(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_active_checkpoint_value;
      return 0;
    case 17: // io_restore_checkpoint_value
      getBitWidth_io_restore_checkpoint_value(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_restore_checkpoint_value;
      return 0;
    case 18: // io_free_checkpoint
      getBitWidth_io_free_checkpoint(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_checkpoint;
      return 0;
    case 19: // io_restore_checkpoint
      getBitWidth_io_restore_checkpoint(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_restore_checkpoint;
      return 0;
    case 20: // io_create_checkpoint
      getBitWidth_io_create_checkpoint(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_create_checkpoint;
      return 0;
    case 21: // io_free_list_RD_0
      getBitWidth_io_free_list_RD_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_RD_0;
      return 0;
    case 22: // io_free_list_RD_1
      getBitWidth_io_free_list_RD_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_RD_1;
      return 0;
    case 23: // io_free_list_RD_2
      getBitWidth_io_free_list_RD_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_RD_2;
      return 0;
    case 24: // io_free_list_RD_3
      getBitWidth_io_free_list_RD_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_RD_3;
      return 0;
    case 25: // io_free_list_wr_en_0
      getBitWidth_io_free_list_wr_en_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_wr_en_0;
      return 0;
    case 26: // io_free_list_wr_en_1
      getBitWidth_io_free_list_wr_en_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_wr_en_1;
      return 0;
    case 27: // io_free_list_wr_en_2
      getBitWidth_io_free_list_wr_en_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_wr_en_2;
      return 0;
    case 28: // io_free_list_wr_en_3
      getBitWidth_io_free_list_wr_en_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_wr_en_3;
      return 0;
    case 29: // io_instruction_RD_0
      getBitWidth_io_instruction_RD_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RD_0;
      return 0;
    case 30: // io_instruction_RD_1
      getBitWidth_io_instruction_RD_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RD_1;
      return 0;
    case 31: // io_instruction_RD_2
      getBitWidth_io_instruction_RD_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RD_2;
      return 0;
    case 32: // io_instruction_RD_3
      getBitWidth_io_instruction_RD_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RD_3;
      return 0;
    case 33: // io_instruction_RS2_0
      getBitWidth_io_instruction_RS2_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS2_0;
      return 0;
    case 34: // io_instruction_RS2_1
      getBitWidth_io_instruction_RS2_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS2_1;
      return 0;
    case 35: // io_instruction_RS2_2
      getBitWidth_io_instruction_RS2_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS2_2;
      return 0;
    case 36: // io_instruction_RS2_3
      getBitWidth_io_instruction_RS2_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS2_3;
      return 0;
    case 37: // io_instruction_RS1_0
      getBitWidth_io_instruction_RS1_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS1_0;
      return 0;
    case 38: // io_instruction_RS1_1
      getBitWidth_io_instruction_RS1_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS1_1;
      return 0;
    case 39: // io_instruction_RS1_2
      getBitWidth_io_instruction_RS1_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS1_2;
      return 0;
    case 40: // io_instruction_RS1_3
      getBitWidth_io_instruction_RS1_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_instruction_RS1_3;
      return 0;
    default:
      return -1;
  }
}

int port_setter(int id, int *bitWidth, void (**setter)(const uint8_t*)) {
  switch (id) {
    case 0: // clock
      getBitWidth_clock(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_clock;
      return 0;
    case 1: // reset
      getBitWidth_reset(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_reset;
      return 0;
    case 17: // io_restore_checkpoint_value
      getBitWidth_io_restore_checkpoint_value(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_restore_checkpoint_value;
      return 0;
    case 18: // io_free_checkpoint
      getBitWidth_io_free_checkpoint(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_checkpoint;
      return 0;
    case 19: // io_restore_checkpoint
      getBitWidth_io_restore_checkpoint(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_restore_checkpoint;
      return 0;
    case 20: // io_create_checkpoint
      getBitWidth_io_create_checkpoint(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_create_checkpoint;
      return 0;
    case 21: // io_free_list_RD_0
      getBitWidth_io_free_list_RD_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_RD_0;
      return 0;
    case 22: // io_free_list_RD_1
      getBitWidth_io_free_list_RD_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_RD_1;
      return 0;
    case 23: // io_free_list_RD_2
      getBitWidth_io_free_list_RD_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_RD_2;
      return 0;
    case 24: // io_free_list_RD_3
      getBitWidth_io_free_list_RD_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_RD_3;
      return 0;
    case 25: // io_free_list_wr_en_0
      getBitWidth_io_free_list_wr_en_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_wr_en_0;
      return 0;
    case 26: // io_free_list_wr_en_1
      getBitWidth_io_free_list_wr_en_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_wr_en_1;
      return 0;
    case 27: // io_free_list_wr_en_2
      getBitWidth_io_free_list_wr_en_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_wr_en_2;
      return 0;
    case 28: // io_free_list_wr_en_3
      getBitWidth_io_free_list_wr_en_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_free_list_wr_en_3;
      return 0;
    case 29: // io_instruction_RD_0
      getBitWidth_io_instruction_RD_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RD_0;
      return 0;
    case 30: // io_instruction_RD_1
      getBitWidth_io_instruction_RD_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RD_1;
      return 0;
    case 31: // io_instruction_RD_2
      getBitWidth_io_instruction_RD_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RD_2;
      return 0;
    case 32: // io_instruction_RD_3
      getBitWidth_io_instruction_RD_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RD_3;
      return 0;
    case 33: // io_instruction_RS2_0
      getBitWidth_io_instruction_RS2_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS2_0;
      return 0;
    case 34: // io_instruction_RS2_1
      getBitWidth_io_instruction_RS2_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS2_1;
      return 0;
    case 35: // io_instruction_RS2_2
      getBitWidth_io_instruction_RS2_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS2_2;
      return 0;
    case 36: // io_instruction_RS2_3
      getBitWidth_io_instruction_RS2_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS2_3;
      return 0;
    case 37: // io_instruction_RS1_0
      getBitWidth_io_instruction_RS1_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS1_0;
      return 0;
    case 38: // io_instruction_RS1_1
      getBitWidth_io_instruction_RS1_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS1_1;
      return 0;
    case 39: // io_instruction_RS1_2
      getBitWidth_io_instruction_RS1_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS1_2;
      return 0;
    case 40: // io_instruction_RS1_3
      getBitWidth_io_instruction_RS1_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_instruction_RS1_3;
      return 0;
    default:
      return -1;
  }
}

} // extern "C"


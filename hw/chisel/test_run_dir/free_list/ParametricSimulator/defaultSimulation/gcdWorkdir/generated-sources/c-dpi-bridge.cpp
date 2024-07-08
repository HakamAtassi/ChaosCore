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
    case 2: // io_can_allocate
      getBitWidth_io_can_allocate(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_can_allocate;
      return 0;
    case 3: // io_can_reallocate
      getBitWidth_io_can_reallocate(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_can_reallocate;
      return 0;
    case 4: // io_free_list_front_pointer
      getBitWidth_io_free_list_front_pointer(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_free_list_front_pointer;
      return 0;
    case 5: // io_commit_bits_RD_valid_0
      getBitWidth_io_commit_bits_RD_valid_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_valid_0;
      return 0;
    case 6: // io_commit_bits_RD_valid_1
      getBitWidth_io_commit_bits_RD_valid_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_valid_1;
      return 0;
    case 7: // io_commit_bits_RD_valid_2
      getBitWidth_io_commit_bits_RD_valid_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_valid_2;
      return 0;
    case 8: // io_commit_bits_RD_valid_3
      getBitWidth_io_commit_bits_RD_valid_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_valid_3;
      return 0;
    case 9: // io_commit_bits_RD_0
      getBitWidth_io_commit_bits_RD_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_0;
      return 0;
    case 10: // io_commit_bits_RD_1
      getBitWidth_io_commit_bits_RD_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_1;
      return 0;
    case 11: // io_commit_bits_RD_2
      getBitWidth_io_commit_bits_RD_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_2;
      return 0;
    case 12: // io_commit_bits_RD_3
      getBitWidth_io_commit_bits_RD_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RD_3;
      return 0;
    case 13: // io_commit_bits_free_list_front_pointer
      getBitWidth_io_commit_bits_free_list_front_pointer(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_free_list_front_pointer;
      return 0;
    case 14: // io_commit_bits_RAT_index
      getBitWidth_io_commit_bits_RAT_index(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_RAT_index;
      return 0;
    case 15: // io_commit_bits_NEXT
      getBitWidth_io_commit_bits_NEXT(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_NEXT;
      return 0;
    case 16: // io_commit_bits_TOS
      getBitWidth_io_commit_bits_TOS(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_TOS;
      return 0;
    case 17: // io_commit_bits_GHR
      getBitWidth_io_commit_bits_GHR(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_GHR;
      return 0;
    case 18: // io_commit_bits_expected_PC
      getBitWidth_io_commit_bits_expected_PC(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_expected_PC;
      return 0;
    case 19: // io_commit_bits_is_misprediction
      getBitWidth_io_commit_bits_is_misprediction(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_is_misprediction;
      return 0;
    case 20: // io_commit_bits_fetch_packet_index
      getBitWidth_io_commit_bits_fetch_packet_index(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_fetch_packet_index;
      return 0;
    case 21: // io_commit_bits_br_type
      getBitWidth_io_commit_bits_br_type(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_br_type;
      return 0;
    case 22: // io_commit_bits_ROB_index
      getBitWidth_io_commit_bits_ROB_index(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_ROB_index;
      return 0;
    case 23: // io_commit_bits_T_NT
      getBitWidth_io_commit_bits_T_NT(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_T_NT;
      return 0;
    case 24: // io_commit_bits_fetch_PC
      getBitWidth_io_commit_bits_fetch_PC(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_bits_fetch_PC;
      return 0;
    case 25: // io_commit_valid
      getBitWidth_io_commit_valid(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_commit_valid;
      return 0;
    case 26: // io_renamed_valid_0
      getBitWidth_io_renamed_valid_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_valid_0;
      return 0;
    case 27: // io_renamed_valid_1
      getBitWidth_io_renamed_valid_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_valid_1;
      return 0;
    case 28: // io_renamed_valid_2
      getBitWidth_io_renamed_valid_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_valid_2;
      return 0;
    case 29: // io_renamed_valid_3
      getBitWidth_io_renamed_valid_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_valid_3;
      return 0;
    case 30: // io_renamed_values_0
      getBitWidth_io_renamed_values_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_values_0;
      return 0;
    case 31: // io_renamed_values_1
      getBitWidth_io_renamed_values_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_values_1;
      return 0;
    case 32: // io_renamed_values_2
      getBitWidth_io_renamed_values_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_values_2;
      return 0;
    case 33: // io_renamed_values_3
      getBitWidth_io_renamed_values_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_renamed_values_3;
      return 0;
    case 34: // io_rename_valid_0
      getBitWidth_io_rename_valid_0(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_rename_valid_0;
      return 0;
    case 35: // io_rename_valid_1
      getBitWidth_io_rename_valid_1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_rename_valid_1;
      return 0;
    case 36: // io_rename_valid_2
      getBitWidth_io_rename_valid_2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_rename_valid_2;
      return 0;
    case 37: // io_rename_valid_3
      getBitWidth_io_rename_valid_3(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_rename_valid_3;
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
    case 5: // io_commit_bits_RD_valid_0
      getBitWidth_io_commit_bits_RD_valid_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_valid_0;
      return 0;
    case 6: // io_commit_bits_RD_valid_1
      getBitWidth_io_commit_bits_RD_valid_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_valid_1;
      return 0;
    case 7: // io_commit_bits_RD_valid_2
      getBitWidth_io_commit_bits_RD_valid_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_valid_2;
      return 0;
    case 8: // io_commit_bits_RD_valid_3
      getBitWidth_io_commit_bits_RD_valid_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_valid_3;
      return 0;
    case 9: // io_commit_bits_RD_0
      getBitWidth_io_commit_bits_RD_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_0;
      return 0;
    case 10: // io_commit_bits_RD_1
      getBitWidth_io_commit_bits_RD_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_1;
      return 0;
    case 11: // io_commit_bits_RD_2
      getBitWidth_io_commit_bits_RD_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_2;
      return 0;
    case 12: // io_commit_bits_RD_3
      getBitWidth_io_commit_bits_RD_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RD_3;
      return 0;
    case 13: // io_commit_bits_free_list_front_pointer
      getBitWidth_io_commit_bits_free_list_front_pointer(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_free_list_front_pointer;
      return 0;
    case 14: // io_commit_bits_RAT_index
      getBitWidth_io_commit_bits_RAT_index(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_RAT_index;
      return 0;
    case 15: // io_commit_bits_NEXT
      getBitWidth_io_commit_bits_NEXT(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_NEXT;
      return 0;
    case 16: // io_commit_bits_TOS
      getBitWidth_io_commit_bits_TOS(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_TOS;
      return 0;
    case 17: // io_commit_bits_GHR
      getBitWidth_io_commit_bits_GHR(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_GHR;
      return 0;
    case 18: // io_commit_bits_expected_PC
      getBitWidth_io_commit_bits_expected_PC(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_expected_PC;
      return 0;
    case 19: // io_commit_bits_is_misprediction
      getBitWidth_io_commit_bits_is_misprediction(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_is_misprediction;
      return 0;
    case 20: // io_commit_bits_fetch_packet_index
      getBitWidth_io_commit_bits_fetch_packet_index(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_fetch_packet_index;
      return 0;
    case 21: // io_commit_bits_br_type
      getBitWidth_io_commit_bits_br_type(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_br_type;
      return 0;
    case 22: // io_commit_bits_ROB_index
      getBitWidth_io_commit_bits_ROB_index(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_ROB_index;
      return 0;
    case 23: // io_commit_bits_T_NT
      getBitWidth_io_commit_bits_T_NT(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_T_NT;
      return 0;
    case 24: // io_commit_bits_fetch_PC
      getBitWidth_io_commit_bits_fetch_PC(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_bits_fetch_PC;
      return 0;
    case 25: // io_commit_valid
      getBitWidth_io_commit_valid(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_commit_valid;
      return 0;
    case 34: // io_rename_valid_0
      getBitWidth_io_rename_valid_0(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_rename_valid_0;
      return 0;
    case 35: // io_rename_valid_1
      getBitWidth_io_rename_valid_1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_rename_valid_1;
      return 0;
    case 36: // io_rename_valid_2
      getBitWidth_io_rename_valid_2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_rename_valid_2;
      return 0;
    case 37: // io_rename_valid_3
      getBitWidth_io_rename_valid_3(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_rename_valid_3;
      return 0;
    default:
      return -1;
  }
}

} // extern "C"


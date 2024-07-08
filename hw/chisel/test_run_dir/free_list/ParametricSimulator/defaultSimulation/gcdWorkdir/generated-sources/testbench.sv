module svsimTestbench;
  reg  [$bits(dut.clock)-1:0] clock;
  reg  [$bits(dut.reset)-1:0] reset;
  wire [$bits(dut.io_can_allocate)-1:0] io_can_allocate;
  wire [$bits(dut.io_can_reallocate)-1:0] io_can_reallocate;
  wire [$bits(dut.io_free_list_front_pointer)-1:0] io_free_list_front_pointer;
  reg  [$bits(dut.io_commit_bits_RD_valid_0)-1:0] io_commit_bits_RD_valid_0;
  reg  [$bits(dut.io_commit_bits_RD_valid_1)-1:0] io_commit_bits_RD_valid_1;
  reg  [$bits(dut.io_commit_bits_RD_valid_2)-1:0] io_commit_bits_RD_valid_2;
  reg  [$bits(dut.io_commit_bits_RD_valid_3)-1:0] io_commit_bits_RD_valid_3;
  reg  [$bits(dut.io_commit_bits_RD_0)-1:0] io_commit_bits_RD_0;
  reg  [$bits(dut.io_commit_bits_RD_1)-1:0] io_commit_bits_RD_1;
  reg  [$bits(dut.io_commit_bits_RD_2)-1:0] io_commit_bits_RD_2;
  reg  [$bits(dut.io_commit_bits_RD_3)-1:0] io_commit_bits_RD_3;
  reg  [$bits(dut.io_commit_bits_free_list_front_pointer)-1:0] io_commit_bits_free_list_front_pointer;
  reg  [$bits(dut.io_commit_bits_RAT_index)-1:0] io_commit_bits_RAT_index;
  reg  [$bits(dut.io_commit_bits_NEXT)-1:0] io_commit_bits_NEXT;
  reg  [$bits(dut.io_commit_bits_TOS)-1:0] io_commit_bits_TOS;
  reg  [$bits(dut.io_commit_bits_GHR)-1:0] io_commit_bits_GHR;
  reg  [$bits(dut.io_commit_bits_expected_PC)-1:0] io_commit_bits_expected_PC;
  reg  [$bits(dut.io_commit_bits_is_misprediction)-1:0] io_commit_bits_is_misprediction;
  reg  [$bits(dut.io_commit_bits_fetch_packet_index)-1:0] io_commit_bits_fetch_packet_index;
  reg  [$bits(dut.io_commit_bits_br_type)-1:0] io_commit_bits_br_type;
  reg  [$bits(dut.io_commit_bits_ROB_index)-1:0] io_commit_bits_ROB_index;
  reg  [$bits(dut.io_commit_bits_T_NT)-1:0] io_commit_bits_T_NT;
  reg  [$bits(dut.io_commit_bits_fetch_PC)-1:0] io_commit_bits_fetch_PC;
  reg  [$bits(dut.io_commit_valid)-1:0] io_commit_valid;
  wire [$bits(dut.io_renamed_valid_0)-1:0] io_renamed_valid_0;
  wire [$bits(dut.io_renamed_valid_1)-1:0] io_renamed_valid_1;
  wire [$bits(dut.io_renamed_valid_2)-1:0] io_renamed_valid_2;
  wire [$bits(dut.io_renamed_valid_3)-1:0] io_renamed_valid_3;
  wire [$bits(dut.io_renamed_values_0)-1:0] io_renamed_values_0;
  wire [$bits(dut.io_renamed_values_1)-1:0] io_renamed_values_1;
  wire [$bits(dut.io_renamed_values_2)-1:0] io_renamed_values_2;
  wire [$bits(dut.io_renamed_values_3)-1:0] io_renamed_values_3;
  reg  [$bits(dut.io_rename_valid_0)-1:0] io_rename_valid_0;
  reg  [$bits(dut.io_rename_valid_1)-1:0] io_rename_valid_1;
  reg  [$bits(dut.io_rename_valid_2)-1:0] io_rename_valid_2;
  reg  [$bits(dut.io_rename_valid_3)-1:0] io_rename_valid_3;

free_list dut (
    .clock(clock),
    .reset(reset),
    .io_can_allocate(io_can_allocate),
    .io_can_reallocate(io_can_reallocate),
    .io_free_list_front_pointer(io_free_list_front_pointer),
    .io_commit_bits_RD_valid_0(io_commit_bits_RD_valid_0),
    .io_commit_bits_RD_valid_1(io_commit_bits_RD_valid_1),
    .io_commit_bits_RD_valid_2(io_commit_bits_RD_valid_2),
    .io_commit_bits_RD_valid_3(io_commit_bits_RD_valid_3),
    .io_commit_bits_RD_0(io_commit_bits_RD_0),
    .io_commit_bits_RD_1(io_commit_bits_RD_1),
    .io_commit_bits_RD_2(io_commit_bits_RD_2),
    .io_commit_bits_RD_3(io_commit_bits_RD_3),
    .io_commit_bits_free_list_front_pointer(io_commit_bits_free_list_front_pointer),
    .io_commit_bits_RAT_index(io_commit_bits_RAT_index),
    .io_commit_bits_NEXT(io_commit_bits_NEXT),
    .io_commit_bits_TOS(io_commit_bits_TOS),
    .io_commit_bits_GHR(io_commit_bits_GHR),
    .io_commit_bits_expected_PC(io_commit_bits_expected_PC),
    .io_commit_bits_is_misprediction(io_commit_bits_is_misprediction),
    .io_commit_bits_fetch_packet_index(io_commit_bits_fetch_packet_index),
    .io_commit_bits_br_type(io_commit_bits_br_type),
    .io_commit_bits_ROB_index(io_commit_bits_ROB_index),
    .io_commit_bits_T_NT(io_commit_bits_T_NT),
    .io_commit_bits_fetch_PC(io_commit_bits_fetch_PC),
    .io_commit_valid(io_commit_valid),
    .io_renamed_valid_0(io_renamed_valid_0),
    .io_renamed_valid_1(io_renamed_valid_1),
    .io_renamed_valid_2(io_renamed_valid_2),
    .io_renamed_valid_3(io_renamed_valid_3),
    .io_renamed_values_0(io_renamed_values_0),
    .io_renamed_values_1(io_renamed_values_1),
    .io_renamed_values_2(io_renamed_values_2),
    .io_renamed_values_3(io_renamed_values_3),
    .io_rename_valid_0(io_rename_valid_0),
    .io_rename_valid_1(io_rename_valid_1),
    .io_rename_valid_2(io_rename_valid_2),
    .io_rename_valid_3(io_rename_valid_3)
);

  // Port 0: clock
  export "DPI-C" function getBitWidth_clock;
  function void getBitWidth_clock;
    output int value;
    value = $bits(dut.clock);
  endfunction
  export "DPI-C" function setBits_clock;
  function void setBits_clock;
    input bit [$bits(dut.clock)-1:0] value_clock;
    clock = value_clock;
  endfunction
  export "DPI-C" function getBits_clock;
  function void getBits_clock;
    output bit [$bits(dut.clock)-1:0] value_clock;
    value_clock = clock;
  endfunction

  // Port 1: reset
  export "DPI-C" function getBitWidth_reset;
  function void getBitWidth_reset;
    output int value;
    value = $bits(dut.reset);
  endfunction
  export "DPI-C" function setBits_reset;
  function void setBits_reset;
    input bit [$bits(dut.reset)-1:0] value_reset;
    reset = value_reset;
  endfunction
  export "DPI-C" function getBits_reset;
  function void getBits_reset;
    output bit [$bits(dut.reset)-1:0] value_reset;
    value_reset = reset;
  endfunction

  // Port 2: io_can_allocate
  export "DPI-C" function getBitWidth_io_can_allocate;
  function void getBitWidth_io_can_allocate;
    output int value;
    value = $bits(dut.io_can_allocate);
  endfunction
  export "DPI-C" function getBits_io_can_allocate;
  function void getBits_io_can_allocate;
    output bit [$bits(dut.io_can_allocate)-1:0] value_io_can_allocate;
    value_io_can_allocate = io_can_allocate;
  endfunction

  // Port 3: io_can_reallocate
  export "DPI-C" function getBitWidth_io_can_reallocate;
  function void getBitWidth_io_can_reallocate;
    output int value;
    value = $bits(dut.io_can_reallocate);
  endfunction
  export "DPI-C" function getBits_io_can_reallocate;
  function void getBits_io_can_reallocate;
    output bit [$bits(dut.io_can_reallocate)-1:0] value_io_can_reallocate;
    value_io_can_reallocate = io_can_reallocate;
  endfunction

  // Port 4: io_free_list_front_pointer
  export "DPI-C" function getBitWidth_io_free_list_front_pointer;
  function void getBitWidth_io_free_list_front_pointer;
    output int value;
    value = $bits(dut.io_free_list_front_pointer);
  endfunction
  export "DPI-C" function getBits_io_free_list_front_pointer;
  function void getBits_io_free_list_front_pointer;
    output bit [$bits(dut.io_free_list_front_pointer)-1:0] value_io_free_list_front_pointer;
    value_io_free_list_front_pointer = io_free_list_front_pointer;
  endfunction

  // Port 5: io_commit_bits_RD_valid_0
  export "DPI-C" function getBitWidth_io_commit_bits_RD_valid_0;
  function void getBitWidth_io_commit_bits_RD_valid_0;
    output int value;
    value = $bits(dut.io_commit_bits_RD_valid_0);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_valid_0;
  function void setBits_io_commit_bits_RD_valid_0;
    input bit [$bits(dut.io_commit_bits_RD_valid_0)-1:0] value_io_commit_bits_RD_valid_0;
    io_commit_bits_RD_valid_0 = value_io_commit_bits_RD_valid_0;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_valid_0;
  function void getBits_io_commit_bits_RD_valid_0;
    output bit [$bits(dut.io_commit_bits_RD_valid_0)-1:0] value_io_commit_bits_RD_valid_0;
    value_io_commit_bits_RD_valid_0 = io_commit_bits_RD_valid_0;
  endfunction

  // Port 6: io_commit_bits_RD_valid_1
  export "DPI-C" function getBitWidth_io_commit_bits_RD_valid_1;
  function void getBitWidth_io_commit_bits_RD_valid_1;
    output int value;
    value = $bits(dut.io_commit_bits_RD_valid_1);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_valid_1;
  function void setBits_io_commit_bits_RD_valid_1;
    input bit [$bits(dut.io_commit_bits_RD_valid_1)-1:0] value_io_commit_bits_RD_valid_1;
    io_commit_bits_RD_valid_1 = value_io_commit_bits_RD_valid_1;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_valid_1;
  function void getBits_io_commit_bits_RD_valid_1;
    output bit [$bits(dut.io_commit_bits_RD_valid_1)-1:0] value_io_commit_bits_RD_valid_1;
    value_io_commit_bits_RD_valid_1 = io_commit_bits_RD_valid_1;
  endfunction

  // Port 7: io_commit_bits_RD_valid_2
  export "DPI-C" function getBitWidth_io_commit_bits_RD_valid_2;
  function void getBitWidth_io_commit_bits_RD_valid_2;
    output int value;
    value = $bits(dut.io_commit_bits_RD_valid_2);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_valid_2;
  function void setBits_io_commit_bits_RD_valid_2;
    input bit [$bits(dut.io_commit_bits_RD_valid_2)-1:0] value_io_commit_bits_RD_valid_2;
    io_commit_bits_RD_valid_2 = value_io_commit_bits_RD_valid_2;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_valid_2;
  function void getBits_io_commit_bits_RD_valid_2;
    output bit [$bits(dut.io_commit_bits_RD_valid_2)-1:0] value_io_commit_bits_RD_valid_2;
    value_io_commit_bits_RD_valid_2 = io_commit_bits_RD_valid_2;
  endfunction

  // Port 8: io_commit_bits_RD_valid_3
  export "DPI-C" function getBitWidth_io_commit_bits_RD_valid_3;
  function void getBitWidth_io_commit_bits_RD_valid_3;
    output int value;
    value = $bits(dut.io_commit_bits_RD_valid_3);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_valid_3;
  function void setBits_io_commit_bits_RD_valid_3;
    input bit [$bits(dut.io_commit_bits_RD_valid_3)-1:0] value_io_commit_bits_RD_valid_3;
    io_commit_bits_RD_valid_3 = value_io_commit_bits_RD_valid_3;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_valid_3;
  function void getBits_io_commit_bits_RD_valid_3;
    output bit [$bits(dut.io_commit_bits_RD_valid_3)-1:0] value_io_commit_bits_RD_valid_3;
    value_io_commit_bits_RD_valid_3 = io_commit_bits_RD_valid_3;
  endfunction

  // Port 9: io_commit_bits_RD_0
  export "DPI-C" function getBitWidth_io_commit_bits_RD_0;
  function void getBitWidth_io_commit_bits_RD_0;
    output int value;
    value = $bits(dut.io_commit_bits_RD_0);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_0;
  function void setBits_io_commit_bits_RD_0;
    input bit [$bits(dut.io_commit_bits_RD_0)-1:0] value_io_commit_bits_RD_0;
    io_commit_bits_RD_0 = value_io_commit_bits_RD_0;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_0;
  function void getBits_io_commit_bits_RD_0;
    output bit [$bits(dut.io_commit_bits_RD_0)-1:0] value_io_commit_bits_RD_0;
    value_io_commit_bits_RD_0 = io_commit_bits_RD_0;
  endfunction

  // Port a: io_commit_bits_RD_1
  export "DPI-C" function getBitWidth_io_commit_bits_RD_1;
  function void getBitWidth_io_commit_bits_RD_1;
    output int value;
    value = $bits(dut.io_commit_bits_RD_1);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_1;
  function void setBits_io_commit_bits_RD_1;
    input bit [$bits(dut.io_commit_bits_RD_1)-1:0] value_io_commit_bits_RD_1;
    io_commit_bits_RD_1 = value_io_commit_bits_RD_1;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_1;
  function void getBits_io_commit_bits_RD_1;
    output bit [$bits(dut.io_commit_bits_RD_1)-1:0] value_io_commit_bits_RD_1;
    value_io_commit_bits_RD_1 = io_commit_bits_RD_1;
  endfunction

  // Port b: io_commit_bits_RD_2
  export "DPI-C" function getBitWidth_io_commit_bits_RD_2;
  function void getBitWidth_io_commit_bits_RD_2;
    output int value;
    value = $bits(dut.io_commit_bits_RD_2);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_2;
  function void setBits_io_commit_bits_RD_2;
    input bit [$bits(dut.io_commit_bits_RD_2)-1:0] value_io_commit_bits_RD_2;
    io_commit_bits_RD_2 = value_io_commit_bits_RD_2;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_2;
  function void getBits_io_commit_bits_RD_2;
    output bit [$bits(dut.io_commit_bits_RD_2)-1:0] value_io_commit_bits_RD_2;
    value_io_commit_bits_RD_2 = io_commit_bits_RD_2;
  endfunction

  // Port c: io_commit_bits_RD_3
  export "DPI-C" function getBitWidth_io_commit_bits_RD_3;
  function void getBitWidth_io_commit_bits_RD_3;
    output int value;
    value = $bits(dut.io_commit_bits_RD_3);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RD_3;
  function void setBits_io_commit_bits_RD_3;
    input bit [$bits(dut.io_commit_bits_RD_3)-1:0] value_io_commit_bits_RD_3;
    io_commit_bits_RD_3 = value_io_commit_bits_RD_3;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RD_3;
  function void getBits_io_commit_bits_RD_3;
    output bit [$bits(dut.io_commit_bits_RD_3)-1:0] value_io_commit_bits_RD_3;
    value_io_commit_bits_RD_3 = io_commit_bits_RD_3;
  endfunction

  // Port d: io_commit_bits_free_list_front_pointer
  export "DPI-C" function getBitWidth_io_commit_bits_free_list_front_pointer;
  function void getBitWidth_io_commit_bits_free_list_front_pointer;
    output int value;
    value = $bits(dut.io_commit_bits_free_list_front_pointer);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_free_list_front_pointer;
  function void setBits_io_commit_bits_free_list_front_pointer;
    input bit [$bits(dut.io_commit_bits_free_list_front_pointer)-1:0] value_io_commit_bits_free_list_front_pointer;
    io_commit_bits_free_list_front_pointer = value_io_commit_bits_free_list_front_pointer;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_free_list_front_pointer;
  function void getBits_io_commit_bits_free_list_front_pointer;
    output bit [$bits(dut.io_commit_bits_free_list_front_pointer)-1:0] value_io_commit_bits_free_list_front_pointer;
    value_io_commit_bits_free_list_front_pointer = io_commit_bits_free_list_front_pointer;
  endfunction

  // Port e: io_commit_bits_RAT_index
  export "DPI-C" function getBitWidth_io_commit_bits_RAT_index;
  function void getBitWidth_io_commit_bits_RAT_index;
    output int value;
    value = $bits(dut.io_commit_bits_RAT_index);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_RAT_index;
  function void setBits_io_commit_bits_RAT_index;
    input bit [$bits(dut.io_commit_bits_RAT_index)-1:0] value_io_commit_bits_RAT_index;
    io_commit_bits_RAT_index = value_io_commit_bits_RAT_index;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_RAT_index;
  function void getBits_io_commit_bits_RAT_index;
    output bit [$bits(dut.io_commit_bits_RAT_index)-1:0] value_io_commit_bits_RAT_index;
    value_io_commit_bits_RAT_index = io_commit_bits_RAT_index;
  endfunction

  // Port f: io_commit_bits_NEXT
  export "DPI-C" function getBitWidth_io_commit_bits_NEXT;
  function void getBitWidth_io_commit_bits_NEXT;
    output int value;
    value = $bits(dut.io_commit_bits_NEXT);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_NEXT;
  function void setBits_io_commit_bits_NEXT;
    input bit [$bits(dut.io_commit_bits_NEXT)-1:0] value_io_commit_bits_NEXT;
    io_commit_bits_NEXT = value_io_commit_bits_NEXT;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_NEXT;
  function void getBits_io_commit_bits_NEXT;
    output bit [$bits(dut.io_commit_bits_NEXT)-1:0] value_io_commit_bits_NEXT;
    value_io_commit_bits_NEXT = io_commit_bits_NEXT;
  endfunction

  // Port 10: io_commit_bits_TOS
  export "DPI-C" function getBitWidth_io_commit_bits_TOS;
  function void getBitWidth_io_commit_bits_TOS;
    output int value;
    value = $bits(dut.io_commit_bits_TOS);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_TOS;
  function void setBits_io_commit_bits_TOS;
    input bit [$bits(dut.io_commit_bits_TOS)-1:0] value_io_commit_bits_TOS;
    io_commit_bits_TOS = value_io_commit_bits_TOS;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_TOS;
  function void getBits_io_commit_bits_TOS;
    output bit [$bits(dut.io_commit_bits_TOS)-1:0] value_io_commit_bits_TOS;
    value_io_commit_bits_TOS = io_commit_bits_TOS;
  endfunction

  // Port 11: io_commit_bits_GHR
  export "DPI-C" function getBitWidth_io_commit_bits_GHR;
  function void getBitWidth_io_commit_bits_GHR;
    output int value;
    value = $bits(dut.io_commit_bits_GHR);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_GHR;
  function void setBits_io_commit_bits_GHR;
    input bit [$bits(dut.io_commit_bits_GHR)-1:0] value_io_commit_bits_GHR;
    io_commit_bits_GHR = value_io_commit_bits_GHR;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_GHR;
  function void getBits_io_commit_bits_GHR;
    output bit [$bits(dut.io_commit_bits_GHR)-1:0] value_io_commit_bits_GHR;
    value_io_commit_bits_GHR = io_commit_bits_GHR;
  endfunction

  // Port 12: io_commit_bits_expected_PC
  export "DPI-C" function getBitWidth_io_commit_bits_expected_PC;
  function void getBitWidth_io_commit_bits_expected_PC;
    output int value;
    value = $bits(dut.io_commit_bits_expected_PC);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_expected_PC;
  function void setBits_io_commit_bits_expected_PC;
    input bit [$bits(dut.io_commit_bits_expected_PC)-1:0] value_io_commit_bits_expected_PC;
    io_commit_bits_expected_PC = value_io_commit_bits_expected_PC;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_expected_PC;
  function void getBits_io_commit_bits_expected_PC;
    output bit [$bits(dut.io_commit_bits_expected_PC)-1:0] value_io_commit_bits_expected_PC;
    value_io_commit_bits_expected_PC = io_commit_bits_expected_PC;
  endfunction

  // Port 13: io_commit_bits_is_misprediction
  export "DPI-C" function getBitWidth_io_commit_bits_is_misprediction;
  function void getBitWidth_io_commit_bits_is_misprediction;
    output int value;
    value = $bits(dut.io_commit_bits_is_misprediction);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_is_misprediction;
  function void setBits_io_commit_bits_is_misprediction;
    input bit [$bits(dut.io_commit_bits_is_misprediction)-1:0] value_io_commit_bits_is_misprediction;
    io_commit_bits_is_misprediction = value_io_commit_bits_is_misprediction;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_is_misprediction;
  function void getBits_io_commit_bits_is_misprediction;
    output bit [$bits(dut.io_commit_bits_is_misprediction)-1:0] value_io_commit_bits_is_misprediction;
    value_io_commit_bits_is_misprediction = io_commit_bits_is_misprediction;
  endfunction

  // Port 14: io_commit_bits_fetch_packet_index
  export "DPI-C" function getBitWidth_io_commit_bits_fetch_packet_index;
  function void getBitWidth_io_commit_bits_fetch_packet_index;
    output int value;
    value = $bits(dut.io_commit_bits_fetch_packet_index);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_fetch_packet_index;
  function void setBits_io_commit_bits_fetch_packet_index;
    input bit [$bits(dut.io_commit_bits_fetch_packet_index)-1:0] value_io_commit_bits_fetch_packet_index;
    io_commit_bits_fetch_packet_index = value_io_commit_bits_fetch_packet_index;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_fetch_packet_index;
  function void getBits_io_commit_bits_fetch_packet_index;
    output bit [$bits(dut.io_commit_bits_fetch_packet_index)-1:0] value_io_commit_bits_fetch_packet_index;
    value_io_commit_bits_fetch_packet_index = io_commit_bits_fetch_packet_index;
  endfunction

  // Port 15: io_commit_bits_br_type
  export "DPI-C" function getBitWidth_io_commit_bits_br_type;
  function void getBitWidth_io_commit_bits_br_type;
    output int value;
    value = $bits(dut.io_commit_bits_br_type);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_br_type;
  function void setBits_io_commit_bits_br_type;
    input bit [$bits(dut.io_commit_bits_br_type)-1:0] value_io_commit_bits_br_type;
    io_commit_bits_br_type = value_io_commit_bits_br_type;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_br_type;
  function void getBits_io_commit_bits_br_type;
    output bit [$bits(dut.io_commit_bits_br_type)-1:0] value_io_commit_bits_br_type;
    value_io_commit_bits_br_type = io_commit_bits_br_type;
  endfunction

  // Port 16: io_commit_bits_ROB_index
  export "DPI-C" function getBitWidth_io_commit_bits_ROB_index;
  function void getBitWidth_io_commit_bits_ROB_index;
    output int value;
    value = $bits(dut.io_commit_bits_ROB_index);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_ROB_index;
  function void setBits_io_commit_bits_ROB_index;
    input bit [$bits(dut.io_commit_bits_ROB_index)-1:0] value_io_commit_bits_ROB_index;
    io_commit_bits_ROB_index = value_io_commit_bits_ROB_index;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_ROB_index;
  function void getBits_io_commit_bits_ROB_index;
    output bit [$bits(dut.io_commit_bits_ROB_index)-1:0] value_io_commit_bits_ROB_index;
    value_io_commit_bits_ROB_index = io_commit_bits_ROB_index;
  endfunction

  // Port 17: io_commit_bits_T_NT
  export "DPI-C" function getBitWidth_io_commit_bits_T_NT;
  function void getBitWidth_io_commit_bits_T_NT;
    output int value;
    value = $bits(dut.io_commit_bits_T_NT);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_T_NT;
  function void setBits_io_commit_bits_T_NT;
    input bit [$bits(dut.io_commit_bits_T_NT)-1:0] value_io_commit_bits_T_NT;
    io_commit_bits_T_NT = value_io_commit_bits_T_NT;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_T_NT;
  function void getBits_io_commit_bits_T_NT;
    output bit [$bits(dut.io_commit_bits_T_NT)-1:0] value_io_commit_bits_T_NT;
    value_io_commit_bits_T_NT = io_commit_bits_T_NT;
  endfunction

  // Port 18: io_commit_bits_fetch_PC
  export "DPI-C" function getBitWidth_io_commit_bits_fetch_PC;
  function void getBitWidth_io_commit_bits_fetch_PC;
    output int value;
    value = $bits(dut.io_commit_bits_fetch_PC);
  endfunction
  export "DPI-C" function setBits_io_commit_bits_fetch_PC;
  function void setBits_io_commit_bits_fetch_PC;
    input bit [$bits(dut.io_commit_bits_fetch_PC)-1:0] value_io_commit_bits_fetch_PC;
    io_commit_bits_fetch_PC = value_io_commit_bits_fetch_PC;
  endfunction
  export "DPI-C" function getBits_io_commit_bits_fetch_PC;
  function void getBits_io_commit_bits_fetch_PC;
    output bit [$bits(dut.io_commit_bits_fetch_PC)-1:0] value_io_commit_bits_fetch_PC;
    value_io_commit_bits_fetch_PC = io_commit_bits_fetch_PC;
  endfunction

  // Port 19: io_commit_valid
  export "DPI-C" function getBitWidth_io_commit_valid;
  function void getBitWidth_io_commit_valid;
    output int value;
    value = $bits(dut.io_commit_valid);
  endfunction
  export "DPI-C" function setBits_io_commit_valid;
  function void setBits_io_commit_valid;
    input bit [$bits(dut.io_commit_valid)-1:0] value_io_commit_valid;
    io_commit_valid = value_io_commit_valid;
  endfunction
  export "DPI-C" function getBits_io_commit_valid;
  function void getBits_io_commit_valid;
    output bit [$bits(dut.io_commit_valid)-1:0] value_io_commit_valid;
    value_io_commit_valid = io_commit_valid;
  endfunction

  // Port 1a: io_renamed_valid_0
  export "DPI-C" function getBitWidth_io_renamed_valid_0;
  function void getBitWidth_io_renamed_valid_0;
    output int value;
    value = $bits(dut.io_renamed_valid_0);
  endfunction
  export "DPI-C" function getBits_io_renamed_valid_0;
  function void getBits_io_renamed_valid_0;
    output bit [$bits(dut.io_renamed_valid_0)-1:0] value_io_renamed_valid_0;
    value_io_renamed_valid_0 = io_renamed_valid_0;
  endfunction

  // Port 1b: io_renamed_valid_1
  export "DPI-C" function getBitWidth_io_renamed_valid_1;
  function void getBitWidth_io_renamed_valid_1;
    output int value;
    value = $bits(dut.io_renamed_valid_1);
  endfunction
  export "DPI-C" function getBits_io_renamed_valid_1;
  function void getBits_io_renamed_valid_1;
    output bit [$bits(dut.io_renamed_valid_1)-1:0] value_io_renamed_valid_1;
    value_io_renamed_valid_1 = io_renamed_valid_1;
  endfunction

  // Port 1c: io_renamed_valid_2
  export "DPI-C" function getBitWidth_io_renamed_valid_2;
  function void getBitWidth_io_renamed_valid_2;
    output int value;
    value = $bits(dut.io_renamed_valid_2);
  endfunction
  export "DPI-C" function getBits_io_renamed_valid_2;
  function void getBits_io_renamed_valid_2;
    output bit [$bits(dut.io_renamed_valid_2)-1:0] value_io_renamed_valid_2;
    value_io_renamed_valid_2 = io_renamed_valid_2;
  endfunction

  // Port 1d: io_renamed_valid_3
  export "DPI-C" function getBitWidth_io_renamed_valid_3;
  function void getBitWidth_io_renamed_valid_3;
    output int value;
    value = $bits(dut.io_renamed_valid_3);
  endfunction
  export "DPI-C" function getBits_io_renamed_valid_3;
  function void getBits_io_renamed_valid_3;
    output bit [$bits(dut.io_renamed_valid_3)-1:0] value_io_renamed_valid_3;
    value_io_renamed_valid_3 = io_renamed_valid_3;
  endfunction

  // Port 1e: io_renamed_values_0
  export "DPI-C" function getBitWidth_io_renamed_values_0;
  function void getBitWidth_io_renamed_values_0;
    output int value;
    value = $bits(dut.io_renamed_values_0);
  endfunction
  export "DPI-C" function getBits_io_renamed_values_0;
  function void getBits_io_renamed_values_0;
    output bit [$bits(dut.io_renamed_values_0)-1:0] value_io_renamed_values_0;
    value_io_renamed_values_0 = io_renamed_values_0;
  endfunction

  // Port 1f: io_renamed_values_1
  export "DPI-C" function getBitWidth_io_renamed_values_1;
  function void getBitWidth_io_renamed_values_1;
    output int value;
    value = $bits(dut.io_renamed_values_1);
  endfunction
  export "DPI-C" function getBits_io_renamed_values_1;
  function void getBits_io_renamed_values_1;
    output bit [$bits(dut.io_renamed_values_1)-1:0] value_io_renamed_values_1;
    value_io_renamed_values_1 = io_renamed_values_1;
  endfunction

  // Port 20: io_renamed_values_2
  export "DPI-C" function getBitWidth_io_renamed_values_2;
  function void getBitWidth_io_renamed_values_2;
    output int value;
    value = $bits(dut.io_renamed_values_2);
  endfunction
  export "DPI-C" function getBits_io_renamed_values_2;
  function void getBits_io_renamed_values_2;
    output bit [$bits(dut.io_renamed_values_2)-1:0] value_io_renamed_values_2;
    value_io_renamed_values_2 = io_renamed_values_2;
  endfunction

  // Port 21: io_renamed_values_3
  export "DPI-C" function getBitWidth_io_renamed_values_3;
  function void getBitWidth_io_renamed_values_3;
    output int value;
    value = $bits(dut.io_renamed_values_3);
  endfunction
  export "DPI-C" function getBits_io_renamed_values_3;
  function void getBits_io_renamed_values_3;
    output bit [$bits(dut.io_renamed_values_3)-1:0] value_io_renamed_values_3;
    value_io_renamed_values_3 = io_renamed_values_3;
  endfunction

  // Port 22: io_rename_valid_0
  export "DPI-C" function getBitWidth_io_rename_valid_0;
  function void getBitWidth_io_rename_valid_0;
    output int value;
    value = $bits(dut.io_rename_valid_0);
  endfunction
  export "DPI-C" function setBits_io_rename_valid_0;
  function void setBits_io_rename_valid_0;
    input bit [$bits(dut.io_rename_valid_0)-1:0] value_io_rename_valid_0;
    io_rename_valid_0 = value_io_rename_valid_0;
  endfunction
  export "DPI-C" function getBits_io_rename_valid_0;
  function void getBits_io_rename_valid_0;
    output bit [$bits(dut.io_rename_valid_0)-1:0] value_io_rename_valid_0;
    value_io_rename_valid_0 = io_rename_valid_0;
  endfunction

  // Port 23: io_rename_valid_1
  export "DPI-C" function getBitWidth_io_rename_valid_1;
  function void getBitWidth_io_rename_valid_1;
    output int value;
    value = $bits(dut.io_rename_valid_1);
  endfunction
  export "DPI-C" function setBits_io_rename_valid_1;
  function void setBits_io_rename_valid_1;
    input bit [$bits(dut.io_rename_valid_1)-1:0] value_io_rename_valid_1;
    io_rename_valid_1 = value_io_rename_valid_1;
  endfunction
  export "DPI-C" function getBits_io_rename_valid_1;
  function void getBits_io_rename_valid_1;
    output bit [$bits(dut.io_rename_valid_1)-1:0] value_io_rename_valid_1;
    value_io_rename_valid_1 = io_rename_valid_1;
  endfunction

  // Port 24: io_rename_valid_2
  export "DPI-C" function getBitWidth_io_rename_valid_2;
  function void getBitWidth_io_rename_valid_2;
    output int value;
    value = $bits(dut.io_rename_valid_2);
  endfunction
  export "DPI-C" function setBits_io_rename_valid_2;
  function void setBits_io_rename_valid_2;
    input bit [$bits(dut.io_rename_valid_2)-1:0] value_io_rename_valid_2;
    io_rename_valid_2 = value_io_rename_valid_2;
  endfunction
  export "DPI-C" function getBits_io_rename_valid_2;
  function void getBits_io_rename_valid_2;
    output bit [$bits(dut.io_rename_valid_2)-1:0] value_io_rename_valid_2;
    value_io_rename_valid_2 = io_rename_valid_2;
  endfunction

  // Port 25: io_rename_valid_3
  export "DPI-C" function getBitWidth_io_rename_valid_3;
  function void getBitWidth_io_rename_valid_3;
    output int value;
    value = $bits(dut.io_rename_valid_3);
  endfunction
  export "DPI-C" function setBits_io_rename_valid_3;
  function void setBits_io_rename_valid_3;
    input bit [$bits(dut.io_rename_valid_3)-1:0] value_io_rename_valid_3;
    io_rename_valid_3 = value_io_rename_valid_3;
  endfunction
  export "DPI-C" function getBits_io_rename_valid_3;
  function void getBits_io_rename_valid_3;
    output bit [$bits(dut.io_rename_valid_3)-1:0] value_io_rename_valid_3;
    value_io_rename_valid_3 = io_rename_valid_3;
  endfunction

  // Simulation
  import "DPI-C" context task simulation_body();
  initial begin
    simulation_body();
  end
  `ifdef SVSIM_BACKEND_SUPPORTS_DELAY_IN_PUBLIC_FUNCTIONS
  export "DPI-C" task run_simulation;
  task run_simulation;
    input int timesteps;
    #timesteps;
  endtask
  `else
  import "DPI-C" function void run_simulation(int timesteps);
  `endif

  // Tracing
  export "DPI-C" function simulation_initializeTrace;
  function void simulation_initializeTrace;
    input string traceFilePath;
    `ifdef SVSIM_ENABLE_VCD_TRACING_SUPPORT
      $dumpfile({traceFilePath,".vcd"});
      $dumpvars(0, dut);
    `endif
    `ifdef SVSIM_ENABLE_VPD_TRACING_SUPPORT
      $vcdplusfile({traceFilePath,".vpd"});
      $dumpvars(0, dut);
      $vcdpluson(0, dut);
    `endif
    `ifdef SVSIM_ENABLE_FSDB_TRACING_SUPPORT
      $fsdbDumpfile({traceFilePath,".fsdb"});
      $fsdbDumpvars(0, dut);
    `endif
  endfunction
  export "DPI-C" function simulation_enableTrace;
  function void simulation_enableTrace;
    `ifdef SVSIM_ENABLE_VCD_TRACING_SUPPORT
    $dumpon;
    `elsif SVSIM_ENABLE_VPD_TRACING_SUPPORT
    $dumpon;
    `endif
    `ifdef SVSIM_ENABLE_FSDB_TRACING_SUPPORT
    $fsdbDumpon;
    `endif
  endfunction
  export "DPI-C" function simulation_disableTrace;
  function void simulation_disableTrace;
    `ifdef SVSIM_ENABLE_VCD_TRACING_SUPPORT
    $dumpoff;
    `elsif SVSIM_ENABLE_VPD_TRACING_SUPPORT
    $dumpoff;
    `endif
    `ifdef SVSIM_ENABLE_FSDB_TRACING_SUPPORT
    $fsdbDumpoff;
    `endif
  endfunction

endmodule

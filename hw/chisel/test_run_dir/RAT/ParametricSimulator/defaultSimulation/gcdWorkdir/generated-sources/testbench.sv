module svsimTestbench;
  reg  [$bits(dut.clock)-1:0] clock;
  reg  [$bits(dut.reset)-1:0] reset;
  wire [$bits(dut.io_RAT_RS2_0)-1:0] io_RAT_RS2_0;
  wire [$bits(dut.io_RAT_RS2_1)-1:0] io_RAT_RS2_1;
  wire [$bits(dut.io_RAT_RS2_2)-1:0] io_RAT_RS2_2;
  wire [$bits(dut.io_RAT_RS2_3)-1:0] io_RAT_RS2_3;
  wire [$bits(dut.io_RAT_RS1_0)-1:0] io_RAT_RS1_0;
  wire [$bits(dut.io_RAT_RS1_1)-1:0] io_RAT_RS1_1;
  wire [$bits(dut.io_RAT_RS1_2)-1:0] io_RAT_RS1_2;
  wire [$bits(dut.io_RAT_RS1_3)-1:0] io_RAT_RS1_3;
  wire [$bits(dut.io_RAT_RD_0)-1:0] io_RAT_RD_0;
  wire [$bits(dut.io_RAT_RD_1)-1:0] io_RAT_RD_1;
  wire [$bits(dut.io_RAT_RD_2)-1:0] io_RAT_RD_2;
  wire [$bits(dut.io_RAT_RD_3)-1:0] io_RAT_RD_3;
  wire [$bits(dut.io_checkpoints_empty)-1:0] io_checkpoints_empty;
  wire [$bits(dut.io_checkpoints_full)-1:0] io_checkpoints_full;
  wire [$bits(dut.io_active_checkpoint_value)-1:0] io_active_checkpoint_value;
  reg  [$bits(dut.io_restore_checkpoint_value)-1:0] io_restore_checkpoint_value;
  reg  [$bits(dut.io_free_checkpoint)-1:0] io_free_checkpoint;
  reg  [$bits(dut.io_restore_checkpoint)-1:0] io_restore_checkpoint;
  reg  [$bits(dut.io_create_checkpoint)-1:0] io_create_checkpoint;
  reg  [$bits(dut.io_free_list_RD_0)-1:0] io_free_list_RD_0;
  reg  [$bits(dut.io_free_list_RD_1)-1:0] io_free_list_RD_1;
  reg  [$bits(dut.io_free_list_RD_2)-1:0] io_free_list_RD_2;
  reg  [$bits(dut.io_free_list_RD_3)-1:0] io_free_list_RD_3;
  reg  [$bits(dut.io_free_list_wr_en_0)-1:0] io_free_list_wr_en_0;
  reg  [$bits(dut.io_free_list_wr_en_1)-1:0] io_free_list_wr_en_1;
  reg  [$bits(dut.io_free_list_wr_en_2)-1:0] io_free_list_wr_en_2;
  reg  [$bits(dut.io_free_list_wr_en_3)-1:0] io_free_list_wr_en_3;
  reg  [$bits(dut.io_instruction_RD_0)-1:0] io_instruction_RD_0;
  reg  [$bits(dut.io_instruction_RD_1)-1:0] io_instruction_RD_1;
  reg  [$bits(dut.io_instruction_RD_2)-1:0] io_instruction_RD_2;
  reg  [$bits(dut.io_instruction_RD_3)-1:0] io_instruction_RD_3;
  reg  [$bits(dut.io_instruction_RS2_0)-1:0] io_instruction_RS2_0;
  reg  [$bits(dut.io_instruction_RS2_1)-1:0] io_instruction_RS2_1;
  reg  [$bits(dut.io_instruction_RS2_2)-1:0] io_instruction_RS2_2;
  reg  [$bits(dut.io_instruction_RS2_3)-1:0] io_instruction_RS2_3;
  reg  [$bits(dut.io_instruction_RS1_0)-1:0] io_instruction_RS1_0;
  reg  [$bits(dut.io_instruction_RS1_1)-1:0] io_instruction_RS1_1;
  reg  [$bits(dut.io_instruction_RS1_2)-1:0] io_instruction_RS1_2;
  reg  [$bits(dut.io_instruction_RS1_3)-1:0] io_instruction_RS1_3;

RAT dut (
    .clock(clock),
    .reset(reset),
    .io_RAT_RS2_0(io_RAT_RS2_0),
    .io_RAT_RS2_1(io_RAT_RS2_1),
    .io_RAT_RS2_2(io_RAT_RS2_2),
    .io_RAT_RS2_3(io_RAT_RS2_3),
    .io_RAT_RS1_0(io_RAT_RS1_0),
    .io_RAT_RS1_1(io_RAT_RS1_1),
    .io_RAT_RS1_2(io_RAT_RS1_2),
    .io_RAT_RS1_3(io_RAT_RS1_3),
    .io_RAT_RD_0(io_RAT_RD_0),
    .io_RAT_RD_1(io_RAT_RD_1),
    .io_RAT_RD_2(io_RAT_RD_2),
    .io_RAT_RD_3(io_RAT_RD_3),
    .io_checkpoints_empty(io_checkpoints_empty),
    .io_checkpoints_full(io_checkpoints_full),
    .io_active_checkpoint_value(io_active_checkpoint_value),
    .io_restore_checkpoint_value(io_restore_checkpoint_value),
    .io_free_checkpoint(io_free_checkpoint),
    .io_restore_checkpoint(io_restore_checkpoint),
    .io_create_checkpoint(io_create_checkpoint),
    .io_free_list_RD_0(io_free_list_RD_0),
    .io_free_list_RD_1(io_free_list_RD_1),
    .io_free_list_RD_2(io_free_list_RD_2),
    .io_free_list_RD_3(io_free_list_RD_3),
    .io_free_list_wr_en_0(io_free_list_wr_en_0),
    .io_free_list_wr_en_1(io_free_list_wr_en_1),
    .io_free_list_wr_en_2(io_free_list_wr_en_2),
    .io_free_list_wr_en_3(io_free_list_wr_en_3),
    .io_instruction_RD_0(io_instruction_RD_0),
    .io_instruction_RD_1(io_instruction_RD_1),
    .io_instruction_RD_2(io_instruction_RD_2),
    .io_instruction_RD_3(io_instruction_RD_3),
    .io_instruction_RS2_0(io_instruction_RS2_0),
    .io_instruction_RS2_1(io_instruction_RS2_1),
    .io_instruction_RS2_2(io_instruction_RS2_2),
    .io_instruction_RS2_3(io_instruction_RS2_3),
    .io_instruction_RS1_0(io_instruction_RS1_0),
    .io_instruction_RS1_1(io_instruction_RS1_1),
    .io_instruction_RS1_2(io_instruction_RS1_2),
    .io_instruction_RS1_3(io_instruction_RS1_3)
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

  // Port 2: io_RAT_RS2_0
  export "DPI-C" function getBitWidth_io_RAT_RS2_0;
  function void getBitWidth_io_RAT_RS2_0;
    output int value;
    value = $bits(dut.io_RAT_RS2_0);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS2_0;
  function void getBits_io_RAT_RS2_0;
    output bit [$bits(dut.io_RAT_RS2_0)-1:0] value_io_RAT_RS2_0;
    value_io_RAT_RS2_0 = io_RAT_RS2_0;
  endfunction

  // Port 3: io_RAT_RS2_1
  export "DPI-C" function getBitWidth_io_RAT_RS2_1;
  function void getBitWidth_io_RAT_RS2_1;
    output int value;
    value = $bits(dut.io_RAT_RS2_1);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS2_1;
  function void getBits_io_RAT_RS2_1;
    output bit [$bits(dut.io_RAT_RS2_1)-1:0] value_io_RAT_RS2_1;
    value_io_RAT_RS2_1 = io_RAT_RS2_1;
  endfunction

  // Port 4: io_RAT_RS2_2
  export "DPI-C" function getBitWidth_io_RAT_RS2_2;
  function void getBitWidth_io_RAT_RS2_2;
    output int value;
    value = $bits(dut.io_RAT_RS2_2);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS2_2;
  function void getBits_io_RAT_RS2_2;
    output bit [$bits(dut.io_RAT_RS2_2)-1:0] value_io_RAT_RS2_2;
    value_io_RAT_RS2_2 = io_RAT_RS2_2;
  endfunction

  // Port 5: io_RAT_RS2_3
  export "DPI-C" function getBitWidth_io_RAT_RS2_3;
  function void getBitWidth_io_RAT_RS2_3;
    output int value;
    value = $bits(dut.io_RAT_RS2_3);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS2_3;
  function void getBits_io_RAT_RS2_3;
    output bit [$bits(dut.io_RAT_RS2_3)-1:0] value_io_RAT_RS2_3;
    value_io_RAT_RS2_3 = io_RAT_RS2_3;
  endfunction

  // Port 6: io_RAT_RS1_0
  export "DPI-C" function getBitWidth_io_RAT_RS1_0;
  function void getBitWidth_io_RAT_RS1_0;
    output int value;
    value = $bits(dut.io_RAT_RS1_0);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS1_0;
  function void getBits_io_RAT_RS1_0;
    output bit [$bits(dut.io_RAT_RS1_0)-1:0] value_io_RAT_RS1_0;
    value_io_RAT_RS1_0 = io_RAT_RS1_0;
  endfunction

  // Port 7: io_RAT_RS1_1
  export "DPI-C" function getBitWidth_io_RAT_RS1_1;
  function void getBitWidth_io_RAT_RS1_1;
    output int value;
    value = $bits(dut.io_RAT_RS1_1);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS1_1;
  function void getBits_io_RAT_RS1_1;
    output bit [$bits(dut.io_RAT_RS1_1)-1:0] value_io_RAT_RS1_1;
    value_io_RAT_RS1_1 = io_RAT_RS1_1;
  endfunction

  // Port 8: io_RAT_RS1_2
  export "DPI-C" function getBitWidth_io_RAT_RS1_2;
  function void getBitWidth_io_RAT_RS1_2;
    output int value;
    value = $bits(dut.io_RAT_RS1_2);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS1_2;
  function void getBits_io_RAT_RS1_2;
    output bit [$bits(dut.io_RAT_RS1_2)-1:0] value_io_RAT_RS1_2;
    value_io_RAT_RS1_2 = io_RAT_RS1_2;
  endfunction

  // Port 9: io_RAT_RS1_3
  export "DPI-C" function getBitWidth_io_RAT_RS1_3;
  function void getBitWidth_io_RAT_RS1_3;
    output int value;
    value = $bits(dut.io_RAT_RS1_3);
  endfunction
  export "DPI-C" function getBits_io_RAT_RS1_3;
  function void getBits_io_RAT_RS1_3;
    output bit [$bits(dut.io_RAT_RS1_3)-1:0] value_io_RAT_RS1_3;
    value_io_RAT_RS1_3 = io_RAT_RS1_3;
  endfunction

  // Port a: io_RAT_RD_0
  export "DPI-C" function getBitWidth_io_RAT_RD_0;
  function void getBitWidth_io_RAT_RD_0;
    output int value;
    value = $bits(dut.io_RAT_RD_0);
  endfunction
  export "DPI-C" function getBits_io_RAT_RD_0;
  function void getBits_io_RAT_RD_0;
    output bit [$bits(dut.io_RAT_RD_0)-1:0] value_io_RAT_RD_0;
    value_io_RAT_RD_0 = io_RAT_RD_0;
  endfunction

  // Port b: io_RAT_RD_1
  export "DPI-C" function getBitWidth_io_RAT_RD_1;
  function void getBitWidth_io_RAT_RD_1;
    output int value;
    value = $bits(dut.io_RAT_RD_1);
  endfunction
  export "DPI-C" function getBits_io_RAT_RD_1;
  function void getBits_io_RAT_RD_1;
    output bit [$bits(dut.io_RAT_RD_1)-1:0] value_io_RAT_RD_1;
    value_io_RAT_RD_1 = io_RAT_RD_1;
  endfunction

  // Port c: io_RAT_RD_2
  export "DPI-C" function getBitWidth_io_RAT_RD_2;
  function void getBitWidth_io_RAT_RD_2;
    output int value;
    value = $bits(dut.io_RAT_RD_2);
  endfunction
  export "DPI-C" function getBits_io_RAT_RD_2;
  function void getBits_io_RAT_RD_2;
    output bit [$bits(dut.io_RAT_RD_2)-1:0] value_io_RAT_RD_2;
    value_io_RAT_RD_2 = io_RAT_RD_2;
  endfunction

  // Port d: io_RAT_RD_3
  export "DPI-C" function getBitWidth_io_RAT_RD_3;
  function void getBitWidth_io_RAT_RD_3;
    output int value;
    value = $bits(dut.io_RAT_RD_3);
  endfunction
  export "DPI-C" function getBits_io_RAT_RD_3;
  function void getBits_io_RAT_RD_3;
    output bit [$bits(dut.io_RAT_RD_3)-1:0] value_io_RAT_RD_3;
    value_io_RAT_RD_3 = io_RAT_RD_3;
  endfunction

  // Port e: io_checkpoints_empty
  export "DPI-C" function getBitWidth_io_checkpoints_empty;
  function void getBitWidth_io_checkpoints_empty;
    output int value;
    value = $bits(dut.io_checkpoints_empty);
  endfunction
  export "DPI-C" function getBits_io_checkpoints_empty;
  function void getBits_io_checkpoints_empty;
    output bit [$bits(dut.io_checkpoints_empty)-1:0] value_io_checkpoints_empty;
    value_io_checkpoints_empty = io_checkpoints_empty;
  endfunction

  // Port f: io_checkpoints_full
  export "DPI-C" function getBitWidth_io_checkpoints_full;
  function void getBitWidth_io_checkpoints_full;
    output int value;
    value = $bits(dut.io_checkpoints_full);
  endfunction
  export "DPI-C" function getBits_io_checkpoints_full;
  function void getBits_io_checkpoints_full;
    output bit [$bits(dut.io_checkpoints_full)-1:0] value_io_checkpoints_full;
    value_io_checkpoints_full = io_checkpoints_full;
  endfunction

  // Port 10: io_active_checkpoint_value
  export "DPI-C" function getBitWidth_io_active_checkpoint_value;
  function void getBitWidth_io_active_checkpoint_value;
    output int value;
    value = $bits(dut.io_active_checkpoint_value);
  endfunction
  export "DPI-C" function getBits_io_active_checkpoint_value;
  function void getBits_io_active_checkpoint_value;
    output bit [$bits(dut.io_active_checkpoint_value)-1:0] value_io_active_checkpoint_value;
    value_io_active_checkpoint_value = io_active_checkpoint_value;
  endfunction

  // Port 11: io_restore_checkpoint_value
  export "DPI-C" function getBitWidth_io_restore_checkpoint_value;
  function void getBitWidth_io_restore_checkpoint_value;
    output int value;
    value = $bits(dut.io_restore_checkpoint_value);
  endfunction
  export "DPI-C" function setBits_io_restore_checkpoint_value;
  function void setBits_io_restore_checkpoint_value;
    input bit [$bits(dut.io_restore_checkpoint_value)-1:0] value_io_restore_checkpoint_value;
    io_restore_checkpoint_value = value_io_restore_checkpoint_value;
  endfunction
  export "DPI-C" function getBits_io_restore_checkpoint_value;
  function void getBits_io_restore_checkpoint_value;
    output bit [$bits(dut.io_restore_checkpoint_value)-1:0] value_io_restore_checkpoint_value;
    value_io_restore_checkpoint_value = io_restore_checkpoint_value;
  endfunction

  // Port 12: io_free_checkpoint
  export "DPI-C" function getBitWidth_io_free_checkpoint;
  function void getBitWidth_io_free_checkpoint;
    output int value;
    value = $bits(dut.io_free_checkpoint);
  endfunction
  export "DPI-C" function setBits_io_free_checkpoint;
  function void setBits_io_free_checkpoint;
    input bit [$bits(dut.io_free_checkpoint)-1:0] value_io_free_checkpoint;
    io_free_checkpoint = value_io_free_checkpoint;
  endfunction
  export "DPI-C" function getBits_io_free_checkpoint;
  function void getBits_io_free_checkpoint;
    output bit [$bits(dut.io_free_checkpoint)-1:0] value_io_free_checkpoint;
    value_io_free_checkpoint = io_free_checkpoint;
  endfunction

  // Port 13: io_restore_checkpoint
  export "DPI-C" function getBitWidth_io_restore_checkpoint;
  function void getBitWidth_io_restore_checkpoint;
    output int value;
    value = $bits(dut.io_restore_checkpoint);
  endfunction
  export "DPI-C" function setBits_io_restore_checkpoint;
  function void setBits_io_restore_checkpoint;
    input bit [$bits(dut.io_restore_checkpoint)-1:0] value_io_restore_checkpoint;
    io_restore_checkpoint = value_io_restore_checkpoint;
  endfunction
  export "DPI-C" function getBits_io_restore_checkpoint;
  function void getBits_io_restore_checkpoint;
    output bit [$bits(dut.io_restore_checkpoint)-1:0] value_io_restore_checkpoint;
    value_io_restore_checkpoint = io_restore_checkpoint;
  endfunction

  // Port 14: io_create_checkpoint
  export "DPI-C" function getBitWidth_io_create_checkpoint;
  function void getBitWidth_io_create_checkpoint;
    output int value;
    value = $bits(dut.io_create_checkpoint);
  endfunction
  export "DPI-C" function setBits_io_create_checkpoint;
  function void setBits_io_create_checkpoint;
    input bit [$bits(dut.io_create_checkpoint)-1:0] value_io_create_checkpoint;
    io_create_checkpoint = value_io_create_checkpoint;
  endfunction
  export "DPI-C" function getBits_io_create_checkpoint;
  function void getBits_io_create_checkpoint;
    output bit [$bits(dut.io_create_checkpoint)-1:0] value_io_create_checkpoint;
    value_io_create_checkpoint = io_create_checkpoint;
  endfunction

  // Port 15: io_free_list_RD_0
  export "DPI-C" function getBitWidth_io_free_list_RD_0;
  function void getBitWidth_io_free_list_RD_0;
    output int value;
    value = $bits(dut.io_free_list_RD_0);
  endfunction
  export "DPI-C" function setBits_io_free_list_RD_0;
  function void setBits_io_free_list_RD_0;
    input bit [$bits(dut.io_free_list_RD_0)-1:0] value_io_free_list_RD_0;
    io_free_list_RD_0 = value_io_free_list_RD_0;
  endfunction
  export "DPI-C" function getBits_io_free_list_RD_0;
  function void getBits_io_free_list_RD_0;
    output bit [$bits(dut.io_free_list_RD_0)-1:0] value_io_free_list_RD_0;
    value_io_free_list_RD_0 = io_free_list_RD_0;
  endfunction

  // Port 16: io_free_list_RD_1
  export "DPI-C" function getBitWidth_io_free_list_RD_1;
  function void getBitWidth_io_free_list_RD_1;
    output int value;
    value = $bits(dut.io_free_list_RD_1);
  endfunction
  export "DPI-C" function setBits_io_free_list_RD_1;
  function void setBits_io_free_list_RD_1;
    input bit [$bits(dut.io_free_list_RD_1)-1:0] value_io_free_list_RD_1;
    io_free_list_RD_1 = value_io_free_list_RD_1;
  endfunction
  export "DPI-C" function getBits_io_free_list_RD_1;
  function void getBits_io_free_list_RD_1;
    output bit [$bits(dut.io_free_list_RD_1)-1:0] value_io_free_list_RD_1;
    value_io_free_list_RD_1 = io_free_list_RD_1;
  endfunction

  // Port 17: io_free_list_RD_2
  export "DPI-C" function getBitWidth_io_free_list_RD_2;
  function void getBitWidth_io_free_list_RD_2;
    output int value;
    value = $bits(dut.io_free_list_RD_2);
  endfunction
  export "DPI-C" function setBits_io_free_list_RD_2;
  function void setBits_io_free_list_RD_2;
    input bit [$bits(dut.io_free_list_RD_2)-1:0] value_io_free_list_RD_2;
    io_free_list_RD_2 = value_io_free_list_RD_2;
  endfunction
  export "DPI-C" function getBits_io_free_list_RD_2;
  function void getBits_io_free_list_RD_2;
    output bit [$bits(dut.io_free_list_RD_2)-1:0] value_io_free_list_RD_2;
    value_io_free_list_RD_2 = io_free_list_RD_2;
  endfunction

  // Port 18: io_free_list_RD_3
  export "DPI-C" function getBitWidth_io_free_list_RD_3;
  function void getBitWidth_io_free_list_RD_3;
    output int value;
    value = $bits(dut.io_free_list_RD_3);
  endfunction
  export "DPI-C" function setBits_io_free_list_RD_3;
  function void setBits_io_free_list_RD_3;
    input bit [$bits(dut.io_free_list_RD_3)-1:0] value_io_free_list_RD_3;
    io_free_list_RD_3 = value_io_free_list_RD_3;
  endfunction
  export "DPI-C" function getBits_io_free_list_RD_3;
  function void getBits_io_free_list_RD_3;
    output bit [$bits(dut.io_free_list_RD_3)-1:0] value_io_free_list_RD_3;
    value_io_free_list_RD_3 = io_free_list_RD_3;
  endfunction

  // Port 19: io_free_list_wr_en_0
  export "DPI-C" function getBitWidth_io_free_list_wr_en_0;
  function void getBitWidth_io_free_list_wr_en_0;
    output int value;
    value = $bits(dut.io_free_list_wr_en_0);
  endfunction
  export "DPI-C" function setBits_io_free_list_wr_en_0;
  function void setBits_io_free_list_wr_en_0;
    input bit [$bits(dut.io_free_list_wr_en_0)-1:0] value_io_free_list_wr_en_0;
    io_free_list_wr_en_0 = value_io_free_list_wr_en_0;
  endfunction
  export "DPI-C" function getBits_io_free_list_wr_en_0;
  function void getBits_io_free_list_wr_en_0;
    output bit [$bits(dut.io_free_list_wr_en_0)-1:0] value_io_free_list_wr_en_0;
    value_io_free_list_wr_en_0 = io_free_list_wr_en_0;
  endfunction

  // Port 1a: io_free_list_wr_en_1
  export "DPI-C" function getBitWidth_io_free_list_wr_en_1;
  function void getBitWidth_io_free_list_wr_en_1;
    output int value;
    value = $bits(dut.io_free_list_wr_en_1);
  endfunction
  export "DPI-C" function setBits_io_free_list_wr_en_1;
  function void setBits_io_free_list_wr_en_1;
    input bit [$bits(dut.io_free_list_wr_en_1)-1:0] value_io_free_list_wr_en_1;
    io_free_list_wr_en_1 = value_io_free_list_wr_en_1;
  endfunction
  export "DPI-C" function getBits_io_free_list_wr_en_1;
  function void getBits_io_free_list_wr_en_1;
    output bit [$bits(dut.io_free_list_wr_en_1)-1:0] value_io_free_list_wr_en_1;
    value_io_free_list_wr_en_1 = io_free_list_wr_en_1;
  endfunction

  // Port 1b: io_free_list_wr_en_2
  export "DPI-C" function getBitWidth_io_free_list_wr_en_2;
  function void getBitWidth_io_free_list_wr_en_2;
    output int value;
    value = $bits(dut.io_free_list_wr_en_2);
  endfunction
  export "DPI-C" function setBits_io_free_list_wr_en_2;
  function void setBits_io_free_list_wr_en_2;
    input bit [$bits(dut.io_free_list_wr_en_2)-1:0] value_io_free_list_wr_en_2;
    io_free_list_wr_en_2 = value_io_free_list_wr_en_2;
  endfunction
  export "DPI-C" function getBits_io_free_list_wr_en_2;
  function void getBits_io_free_list_wr_en_2;
    output bit [$bits(dut.io_free_list_wr_en_2)-1:0] value_io_free_list_wr_en_2;
    value_io_free_list_wr_en_2 = io_free_list_wr_en_2;
  endfunction

  // Port 1c: io_free_list_wr_en_3
  export "DPI-C" function getBitWidth_io_free_list_wr_en_3;
  function void getBitWidth_io_free_list_wr_en_3;
    output int value;
    value = $bits(dut.io_free_list_wr_en_3);
  endfunction
  export "DPI-C" function setBits_io_free_list_wr_en_3;
  function void setBits_io_free_list_wr_en_3;
    input bit [$bits(dut.io_free_list_wr_en_3)-1:0] value_io_free_list_wr_en_3;
    io_free_list_wr_en_3 = value_io_free_list_wr_en_3;
  endfunction
  export "DPI-C" function getBits_io_free_list_wr_en_3;
  function void getBits_io_free_list_wr_en_3;
    output bit [$bits(dut.io_free_list_wr_en_3)-1:0] value_io_free_list_wr_en_3;
    value_io_free_list_wr_en_3 = io_free_list_wr_en_3;
  endfunction

  // Port 1d: io_instruction_RD_0
  export "DPI-C" function getBitWidth_io_instruction_RD_0;
  function void getBitWidth_io_instruction_RD_0;
    output int value;
    value = $bits(dut.io_instruction_RD_0);
  endfunction
  export "DPI-C" function setBits_io_instruction_RD_0;
  function void setBits_io_instruction_RD_0;
    input bit [$bits(dut.io_instruction_RD_0)-1:0] value_io_instruction_RD_0;
    io_instruction_RD_0 = value_io_instruction_RD_0;
  endfunction
  export "DPI-C" function getBits_io_instruction_RD_0;
  function void getBits_io_instruction_RD_0;
    output bit [$bits(dut.io_instruction_RD_0)-1:0] value_io_instruction_RD_0;
    value_io_instruction_RD_0 = io_instruction_RD_0;
  endfunction

  // Port 1e: io_instruction_RD_1
  export "DPI-C" function getBitWidth_io_instruction_RD_1;
  function void getBitWidth_io_instruction_RD_1;
    output int value;
    value = $bits(dut.io_instruction_RD_1);
  endfunction
  export "DPI-C" function setBits_io_instruction_RD_1;
  function void setBits_io_instruction_RD_1;
    input bit [$bits(dut.io_instruction_RD_1)-1:0] value_io_instruction_RD_1;
    io_instruction_RD_1 = value_io_instruction_RD_1;
  endfunction
  export "DPI-C" function getBits_io_instruction_RD_1;
  function void getBits_io_instruction_RD_1;
    output bit [$bits(dut.io_instruction_RD_1)-1:0] value_io_instruction_RD_1;
    value_io_instruction_RD_1 = io_instruction_RD_1;
  endfunction

  // Port 1f: io_instruction_RD_2
  export "DPI-C" function getBitWidth_io_instruction_RD_2;
  function void getBitWidth_io_instruction_RD_2;
    output int value;
    value = $bits(dut.io_instruction_RD_2);
  endfunction
  export "DPI-C" function setBits_io_instruction_RD_2;
  function void setBits_io_instruction_RD_2;
    input bit [$bits(dut.io_instruction_RD_2)-1:0] value_io_instruction_RD_2;
    io_instruction_RD_2 = value_io_instruction_RD_2;
  endfunction
  export "DPI-C" function getBits_io_instruction_RD_2;
  function void getBits_io_instruction_RD_2;
    output bit [$bits(dut.io_instruction_RD_2)-1:0] value_io_instruction_RD_2;
    value_io_instruction_RD_2 = io_instruction_RD_2;
  endfunction

  // Port 20: io_instruction_RD_3
  export "DPI-C" function getBitWidth_io_instruction_RD_3;
  function void getBitWidth_io_instruction_RD_3;
    output int value;
    value = $bits(dut.io_instruction_RD_3);
  endfunction
  export "DPI-C" function setBits_io_instruction_RD_3;
  function void setBits_io_instruction_RD_3;
    input bit [$bits(dut.io_instruction_RD_3)-1:0] value_io_instruction_RD_3;
    io_instruction_RD_3 = value_io_instruction_RD_3;
  endfunction
  export "DPI-C" function getBits_io_instruction_RD_3;
  function void getBits_io_instruction_RD_3;
    output bit [$bits(dut.io_instruction_RD_3)-1:0] value_io_instruction_RD_3;
    value_io_instruction_RD_3 = io_instruction_RD_3;
  endfunction

  // Port 21: io_instruction_RS2_0
  export "DPI-C" function getBitWidth_io_instruction_RS2_0;
  function void getBitWidth_io_instruction_RS2_0;
    output int value;
    value = $bits(dut.io_instruction_RS2_0);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS2_0;
  function void setBits_io_instruction_RS2_0;
    input bit [$bits(dut.io_instruction_RS2_0)-1:0] value_io_instruction_RS2_0;
    io_instruction_RS2_0 = value_io_instruction_RS2_0;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS2_0;
  function void getBits_io_instruction_RS2_0;
    output bit [$bits(dut.io_instruction_RS2_0)-1:0] value_io_instruction_RS2_0;
    value_io_instruction_RS2_0 = io_instruction_RS2_0;
  endfunction

  // Port 22: io_instruction_RS2_1
  export "DPI-C" function getBitWidth_io_instruction_RS2_1;
  function void getBitWidth_io_instruction_RS2_1;
    output int value;
    value = $bits(dut.io_instruction_RS2_1);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS2_1;
  function void setBits_io_instruction_RS2_1;
    input bit [$bits(dut.io_instruction_RS2_1)-1:0] value_io_instruction_RS2_1;
    io_instruction_RS2_1 = value_io_instruction_RS2_1;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS2_1;
  function void getBits_io_instruction_RS2_1;
    output bit [$bits(dut.io_instruction_RS2_1)-1:0] value_io_instruction_RS2_1;
    value_io_instruction_RS2_1 = io_instruction_RS2_1;
  endfunction

  // Port 23: io_instruction_RS2_2
  export "DPI-C" function getBitWidth_io_instruction_RS2_2;
  function void getBitWidth_io_instruction_RS2_2;
    output int value;
    value = $bits(dut.io_instruction_RS2_2);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS2_2;
  function void setBits_io_instruction_RS2_2;
    input bit [$bits(dut.io_instruction_RS2_2)-1:0] value_io_instruction_RS2_2;
    io_instruction_RS2_2 = value_io_instruction_RS2_2;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS2_2;
  function void getBits_io_instruction_RS2_2;
    output bit [$bits(dut.io_instruction_RS2_2)-1:0] value_io_instruction_RS2_2;
    value_io_instruction_RS2_2 = io_instruction_RS2_2;
  endfunction

  // Port 24: io_instruction_RS2_3
  export "DPI-C" function getBitWidth_io_instruction_RS2_3;
  function void getBitWidth_io_instruction_RS2_3;
    output int value;
    value = $bits(dut.io_instruction_RS2_3);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS2_3;
  function void setBits_io_instruction_RS2_3;
    input bit [$bits(dut.io_instruction_RS2_3)-1:0] value_io_instruction_RS2_3;
    io_instruction_RS2_3 = value_io_instruction_RS2_3;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS2_3;
  function void getBits_io_instruction_RS2_3;
    output bit [$bits(dut.io_instruction_RS2_3)-1:0] value_io_instruction_RS2_3;
    value_io_instruction_RS2_3 = io_instruction_RS2_3;
  endfunction

  // Port 25: io_instruction_RS1_0
  export "DPI-C" function getBitWidth_io_instruction_RS1_0;
  function void getBitWidth_io_instruction_RS1_0;
    output int value;
    value = $bits(dut.io_instruction_RS1_0);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS1_0;
  function void setBits_io_instruction_RS1_0;
    input bit [$bits(dut.io_instruction_RS1_0)-1:0] value_io_instruction_RS1_0;
    io_instruction_RS1_0 = value_io_instruction_RS1_0;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS1_0;
  function void getBits_io_instruction_RS1_0;
    output bit [$bits(dut.io_instruction_RS1_0)-1:0] value_io_instruction_RS1_0;
    value_io_instruction_RS1_0 = io_instruction_RS1_0;
  endfunction

  // Port 26: io_instruction_RS1_1
  export "DPI-C" function getBitWidth_io_instruction_RS1_1;
  function void getBitWidth_io_instruction_RS1_1;
    output int value;
    value = $bits(dut.io_instruction_RS1_1);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS1_1;
  function void setBits_io_instruction_RS1_1;
    input bit [$bits(dut.io_instruction_RS1_1)-1:0] value_io_instruction_RS1_1;
    io_instruction_RS1_1 = value_io_instruction_RS1_1;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS1_1;
  function void getBits_io_instruction_RS1_1;
    output bit [$bits(dut.io_instruction_RS1_1)-1:0] value_io_instruction_RS1_1;
    value_io_instruction_RS1_1 = io_instruction_RS1_1;
  endfunction

  // Port 27: io_instruction_RS1_2
  export "DPI-C" function getBitWidth_io_instruction_RS1_2;
  function void getBitWidth_io_instruction_RS1_2;
    output int value;
    value = $bits(dut.io_instruction_RS1_2);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS1_2;
  function void setBits_io_instruction_RS1_2;
    input bit [$bits(dut.io_instruction_RS1_2)-1:0] value_io_instruction_RS1_2;
    io_instruction_RS1_2 = value_io_instruction_RS1_2;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS1_2;
  function void getBits_io_instruction_RS1_2;
    output bit [$bits(dut.io_instruction_RS1_2)-1:0] value_io_instruction_RS1_2;
    value_io_instruction_RS1_2 = io_instruction_RS1_2;
  endfunction

  // Port 28: io_instruction_RS1_3
  export "DPI-C" function getBitWidth_io_instruction_RS1_3;
  function void getBitWidth_io_instruction_RS1_3;
    output int value;
    value = $bits(dut.io_instruction_RS1_3);
  endfunction
  export "DPI-C" function setBits_io_instruction_RS1_3;
  function void setBits_io_instruction_RS1_3;
    input bit [$bits(dut.io_instruction_RS1_3)-1:0] value_io_instruction_RS1_3;
    io_instruction_RS1_3 = value_io_instruction_RS1_3;
  endfunction
  export "DPI-C" function getBits_io_instruction_RS1_3;
  function void getBits_io_instruction_RS1_3;
    output bit [$bits(dut.io_instruction_RS1_3)-1:0] value_io_instruction_RS1_3;
    value_io_instruction_RS1_3 = io_instruction_RS1_3;
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

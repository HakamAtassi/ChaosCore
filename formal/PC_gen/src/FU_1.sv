// Generated by CIRCT firtool-1.76.0

// Include register initializers in init blocks unless synthesis is set
`ifndef RANDOMIZE
  `ifdef RANDOMIZE_REG_INIT
    `define RANDOMIZE
  `endif // RANDOMIZE_REG_INIT
`endif // not def RANDOMIZE
`ifndef SYNTHESIS
  `ifndef ENABLE_INITIAL_REG_
    `define ENABLE_INITIAL_REG_
  `endif // not def ENABLE_INITIAL_REG_
`endif // not def SYNTHESIS

// Standard header to adapt well known macros for register randomization.

// RANDOM may be set to an expression that produces a 32-bit random unsigned value.
`ifndef RANDOM
  `define RANDOM $random
`endif // not def RANDOM

// Users can define INIT_RANDOM as general code that gets injected into the
// initializer block for modules with registers.
`ifndef INIT_RANDOM
  `define INIT_RANDOM
`endif // not def INIT_RANDOM

// If using random initialization, you can also define RANDOMIZE_DELAY to
// customize the delay used, otherwise 0.002 is used.
`ifndef RANDOMIZE_DELAY
  `define RANDOMIZE_DELAY 0.002
`endif // not def RANDOMIZE_DELAY

// Define INIT_RANDOM_PROLOG_ for use in our modules below.
`ifndef INIT_RANDOM_PROLOG_
  `ifdef RANDOMIZE
    `ifdef VERILATOR
      `define INIT_RANDOM_PROLOG_ `INIT_RANDOM
    `else  // VERILATOR
      `define INIT_RANDOM_PROLOG_ `INIT_RANDOM #`RANDOMIZE_DELAY begin end
    `endif // VERILATOR
  `else  // RANDOMIZE
    `define INIT_RANDOM_PROLOG_
  `endif // RANDOMIZE
`endif // not def INIT_RANDOM_PROLOG_
module FU_1(	// src/main/scala/Backend/FU.scala:384:7
  input         clock,	// src/main/scala/Backend/FU.scala:384:7
                reset,	// src/main/scala/Backend/FU.scala:384:7
                io_flush,	// src/main/scala/Backend/FU.scala:391:16
  output        io_FU_input_ready,	// src/main/scala/Backend/FU.scala:391:16
  input         io_FU_input_valid,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready,	// src/main/scala/Backend/FU.scala:391:16
  input  [6:0]  io_FU_input_bits_decoded_instruction_RD,	// src/main/scala/Backend/FU.scala:391:16
  input         io_FU_input_bits_decoded_instruction_RD_valid,	// src/main/scala/Backend/FU.scala:391:16
  input  [6:0]  io_FU_input_bits_decoded_instruction_RS1,	// src/main/scala/Backend/FU.scala:391:16
  input         io_FU_input_bits_decoded_instruction_RS1_valid,	// src/main/scala/Backend/FU.scala:391:16
  input  [6:0]  io_FU_input_bits_decoded_instruction_RS2,	// src/main/scala/Backend/FU.scala:391:16
  input         io_FU_input_bits_decoded_instruction_RS2_valid,	// src/main/scala/Backend/FU.scala:391:16
  input  [20:0] io_FU_input_bits_decoded_instruction_IMM,	// src/main/scala/Backend/FU.scala:391:16
  input  [2:0]  io_FU_input_bits_decoded_instruction_FUNCT3,	// src/main/scala/Backend/FU.scala:391:16
  input  [1:0]  io_FU_input_bits_decoded_instruction_packet_index,	// src/main/scala/Backend/FU.scala:391:16
  input  [5:0]  io_FU_input_bits_decoded_instruction_ROB_index,	// src/main/scala/Backend/FU.scala:391:16
  input  [3:0]  io_FU_input_bits_decoded_instruction_MOB_index,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_FTQ_index,	// src/main/scala/Backend/FU.scala:391:16
  input  [4:0]  io_FU_input_bits_decoded_instruction_instructionType,	// src/main/scala/Backend/FU.scala:391:16
  input  [1:0]  io_FU_input_bits_decoded_instruction_portID,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_RS_type,	// src/main/scala/Backend/FU.scala:391:16
  input         io_FU_input_bits_decoded_instruction_needs_ALU,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_needs_branch_unit,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_needs_CSRs,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_SUBTRACT,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_MULTIPLY,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_IS_IMM,	// src/main/scala/Backend/FU.scala:391:16
  input  [1:0]  io_FU_input_bits_decoded_instruction_memory_type,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_decoded_instruction_access_width,	// src/main/scala/Backend/FU.scala:391:16
  input  [31:0] io_FU_input_bits_RS1_data,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_RS2_data,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_input_bits_fetch_PC,	// src/main/scala/Backend/FU.scala:391:16
  output        io_FU_output_valid,	// src/main/scala/Backend/FU.scala:391:16
  output [6:0]  io_FU_output_bits_RD,	// src/main/scala/Backend/FU.scala:391:16
  output [31:0] io_FU_output_bits_RD_data,	// src/main/scala/Backend/FU.scala:391:16
  output        io_FU_output_bits_RD_valid,	// src/main/scala/Backend/FU.scala:391:16
  output [31:0] io_FU_output_bits_fetch_PC,	// src/main/scala/Backend/FU.scala:391:16
  output        io_FU_output_bits_branch_taken,	// src/main/scala/Backend/FU.scala:391:16
  output [31:0] io_FU_output_bits_target_address,	// src/main/scala/Backend/FU.scala:391:16
  output        io_FU_output_bits_branch_valid,	// src/main/scala/Backend/FU.scala:391:16
  output [31:0] io_FU_output_bits_address,	// src/main/scala/Backend/FU.scala:391:16
  output [1:0]  io_FU_output_bits_memory_type,	// src/main/scala/Backend/FU.scala:391:16
                io_FU_output_bits_access_width,	// src/main/scala/Backend/FU.scala:391:16
  output        io_FU_output_bits_is_unsigned,	// src/main/scala/Backend/FU.scala:391:16
  output [31:0] io_FU_output_bits_wr_data,	// src/main/scala/Backend/FU.scala:391:16
  output [3:0]  io_FU_output_bits_MOB_index,	// src/main/scala/Backend/FU.scala:391:16
  output [5:0]  io_FU_output_bits_ROB_index,	// src/main/scala/Backend/FU.scala:391:16
  output [3:0]  io_FU_output_bits_FTQ_index,	// src/main/scala/Backend/FU.scala:391:16
  output [1:0]  io_FU_output_bits_fetch_packet_index	// src/main/scala/Backend/FU.scala:391:16
);

  reg  monitor_output_REG;	// src/main/scala/Backend/FU.scala:442:30
  wire monitor_output = monitor_output_REG;	// src/main/scala/Backend/FU.scala:441:30, :442:30
  always @(posedge clock)	// src/main/scala/Backend/FU.scala:384:7
    monitor_output_REG <= io_FU_input_valid;	// src/main/scala/Backend/FU.scala:442:30
  `ifdef ENABLE_INITIAL_REG_	// src/main/scala/Backend/FU.scala:384:7
    `ifdef FIRRTL_BEFORE_INITIAL	// src/main/scala/Backend/FU.scala:384:7
      `FIRRTL_BEFORE_INITIAL	// src/main/scala/Backend/FU.scala:384:7
    `endif // FIRRTL_BEFORE_INITIAL
    initial begin	// src/main/scala/Backend/FU.scala:384:7
      automatic logic [31:0] _RANDOM[0:0];	// src/main/scala/Backend/FU.scala:384:7
      `ifdef INIT_RANDOM_PROLOG_	// src/main/scala/Backend/FU.scala:384:7
        `INIT_RANDOM_PROLOG_	// src/main/scala/Backend/FU.scala:384:7
      `endif // INIT_RANDOM_PROLOG_
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/Backend/FU.scala:384:7
        _RANDOM[/*Zero width*/ 1'b0] = `RANDOM;	// src/main/scala/Backend/FU.scala:384:7
        monitor_output_REG = _RANDOM[/*Zero width*/ 1'b0][1];	// src/main/scala/Backend/FU.scala:384:7, :442:30
      `endif // RANDOMIZE_REG_INIT
    end // initial
    `ifdef FIRRTL_AFTER_INITIAL	// src/main/scala/Backend/FU.scala:384:7
      `FIRRTL_AFTER_INITIAL	// src/main/scala/Backend/FU.scala:384:7
    `endif // FIRRTL_AFTER_INITIAL
  `endif // ENABLE_INITIAL_REG_
  ALU ALU (	// src/main/scala/Backend/FU.scala:411:39
    .clock                                                (clock),
    .reset                                                (reset),
    .io_flush                                             (io_flush),
    .io_FU_input_valid                                    (io_FU_input_valid),
    .io_FU_input_bits_decoded_instruction_RD
      (io_FU_input_bits_decoded_instruction_RD),
    .io_FU_input_bits_decoded_instruction_RD_valid
      (io_FU_input_bits_decoded_instruction_RD_valid),
    .io_FU_input_bits_decoded_instruction_IMM
      (io_FU_input_bits_decoded_instruction_IMM),
    .io_FU_input_bits_decoded_instruction_FUNCT3
      (io_FU_input_bits_decoded_instruction_FUNCT3),
    .io_FU_input_bits_decoded_instruction_packet_index
      (io_FU_input_bits_decoded_instruction_packet_index),
    .io_FU_input_bits_decoded_instruction_ROB_index
      (io_FU_input_bits_decoded_instruction_ROB_index),
    .io_FU_input_bits_decoded_instruction_MOB_index
      (io_FU_input_bits_decoded_instruction_MOB_index),
    .io_FU_input_bits_decoded_instruction_FTQ_index
      (io_FU_input_bits_decoded_instruction_FTQ_index),
    .io_FU_input_bits_decoded_instruction_instructionType
      (io_FU_input_bits_decoded_instruction_instructionType),
    .io_FU_input_bits_decoded_instruction_SUBTRACT
      (io_FU_input_bits_decoded_instruction_SUBTRACT),
    .io_FU_input_bits_decoded_instruction_MULTIPLY
      (io_FU_input_bits_decoded_instruction_MULTIPLY),
    .io_FU_input_bits_decoded_instruction_IS_IMM
      (io_FU_input_bits_decoded_instruction_IS_IMM),
    .io_FU_input_bits_RS1_data                            (io_FU_input_bits_RS1_data),
    .io_FU_input_bits_RS2_data                            (io_FU_input_bits_RS2_data),
    .io_FU_input_bits_fetch_PC                            (io_FU_input_bits_fetch_PC),
    .io_FU_output_valid                                   (io_FU_output_valid),
    .io_FU_output_bits_RD                                 (io_FU_output_bits_RD),
    .io_FU_output_bits_RD_data                            (io_FU_output_bits_RD_data),
    .io_FU_output_bits_RD_valid                           (io_FU_output_bits_RD_valid),
    .io_FU_output_bits_fetch_PC                           (io_FU_output_bits_fetch_PC),
    .io_FU_output_bits_MOB_index                          (io_FU_output_bits_MOB_index),
    .io_FU_output_bits_ROB_index                          (io_FU_output_bits_ROB_index),
    .io_FU_output_bits_FTQ_index                          (io_FU_output_bits_FTQ_index),
    .io_FU_output_bits_fetch_packet_index
      (io_FU_output_bits_fetch_packet_index)
  );	// src/main/scala/Backend/FU.scala:411:39
  assign io_FU_input_ready = 1'h1;	// src/main/scala/Backend/FU.scala:384:7
  assign io_FU_output_bits_branch_taken = 1'h0;	// src/main/scala/Backend/FU.scala:384:7
  assign io_FU_output_bits_target_address = 32'h0;	// src/main/scala/Backend/FU.scala:384:7, :411:39
  assign io_FU_output_bits_branch_valid = 1'h0;	// src/main/scala/Backend/FU.scala:384:7
  assign io_FU_output_bits_address = 32'h0;	// src/main/scala/Backend/FU.scala:384:7, :411:39
  assign io_FU_output_bits_memory_type = 2'h0;	// src/main/scala/Backend/FU.scala:384:7, :411:39
  assign io_FU_output_bits_access_width = 2'h0;	// src/main/scala/Backend/FU.scala:384:7, :411:39
  assign io_FU_output_bits_is_unsigned = 1'h0;	// src/main/scala/Backend/FU.scala:384:7
  assign io_FU_output_bits_wr_data = 32'h0;	// src/main/scala/Backend/FU.scala:384:7, :411:39
endmodule


// Generated by CIRCT firtool-1.62.0
// Standard header to adapt well known macros for prints and assertions.

// Users can define 'PRINTF_COND' to add an extra gate to prints.
`ifndef PRINTF_COND_
  `ifdef PRINTF_COND
    `define PRINTF_COND_ (`PRINTF_COND)
  `else  // PRINTF_COND
    `define PRINTF_COND_ 1
  `endif // PRINTF_COND
`endif // not def PRINTF_COND_

// Users can define 'ASSERT_VERBOSE_COND' to add an extra gate to assert error printing.
`ifndef ASSERT_VERBOSE_COND_
  `ifdef ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ (`ASSERT_VERBOSE_COND)
  `else  // ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ 1
  `endif // ASSERT_VERBOSE_COND
`endif // not def ASSERT_VERBOSE_COND_

// Users can define 'STOP_COND' to add an extra gate to stop conditions.
`ifndef STOP_COND_
  `ifdef STOP_COND
    `define STOP_COND_ (`STOP_COND)
  `else  // STOP_COND
    `define STOP_COND_ 1
  `endif // STOP_COND
`endif // not def STOP_COND_

module FU_1(
  input         clock,
                reset,
                io_flush,
  output        io_FU_input_ready,
  input         io_FU_input_valid,
                io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready,
                io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready,
  input  [4:0]  io_FU_input_bits_decoded_instruction_RD,
  input  [6:0]  io_FU_input_bits_decoded_instruction_PRD,
                io_FU_input_bits_decoded_instruction_PRDold,
  input         io_FU_input_bits_decoded_instruction_RD_valid,
  input  [6:0]  io_FU_input_bits_decoded_instruction_RS1,
  input         io_FU_input_bits_decoded_instruction_RS1_valid,
  input  [6:0]  io_FU_input_bits_decoded_instruction_RS2,
  input         io_FU_input_bits_decoded_instruction_RS2_valid,
  input  [20:0] io_FU_input_bits_decoded_instruction_IMM,
  input  [2:0]  io_FU_input_bits_decoded_instruction_FUNCT3,
  input  [1:0]  io_FU_input_bits_decoded_instruction_packet_index,
  input  [5:0]  io_FU_input_bits_decoded_instruction_ROB_index,
  input  [3:0]  io_FU_input_bits_decoded_instruction_MOB_index,
  input  [4:0]  io_FU_input_bits_decoded_instruction_instructionType,
  input  [1:0]  io_FU_input_bits_decoded_instruction_portID,
                io_FU_input_bits_decoded_instruction_RS_type,
  input         io_FU_input_bits_decoded_instruction_needs_ALU,
                io_FU_input_bits_decoded_instruction_needs_branch_unit,
                io_FU_input_bits_decoded_instruction_needs_CSRs,
                io_FU_input_bits_decoded_instruction_SUBTRACT,
                io_FU_input_bits_decoded_instruction_MULTIPLY,
                io_FU_input_bits_decoded_instruction_IS_IMM,
  input  [1:0]  io_FU_input_bits_decoded_instruction_memory_type,
                io_FU_input_bits_decoded_instruction_access_width,
  input  [31:0] io_FU_input_bits_RS1_data,
                io_FU_input_bits_RS2_data,
                io_FU_input_bits_fetch_PC,
  output        io_FU_output_valid,
  output [6:0]  io_FU_output_bits_PRD,
  output [31:0] io_FU_output_bits_RD_data,
  output        io_FU_output_bits_RD_valid,
  output [31:0] io_FU_output_bits_fetch_PC,
  output        io_FU_output_bits_branch_taken,
  output [31:0] io_FU_output_bits_target_address,
  output        io_FU_output_bits_branch_valid,
  output [31:0] io_FU_output_bits_address,
  output [1:0]  io_FU_output_bits_memory_type,
                io_FU_output_bits_access_width,
  output        io_FU_output_bits_is_unsigned,
  output [31:0] io_FU_output_bits_wr_data,
  output [3:0]  io_FU_output_bits_MOB_index,
  output [5:0]  io_FU_output_bits_ROB_index,
  output [1:0]  io_FU_output_bits_fetch_packet_index
);

  ALU ALU (
    .clock                                                (clock),
    .reset                                                (reset),
    .io_flush                                             (io_flush),
    .io_FU_input_valid                                    (io_FU_input_valid),
    .io_FU_input_bits_decoded_instruction_PRD
      (io_FU_input_bits_decoded_instruction_PRD),
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
    .io_FU_output_bits_PRD                                (io_FU_output_bits_PRD),
    .io_FU_output_bits_RD_data                            (io_FU_output_bits_RD_data),
    .io_FU_output_bits_RD_valid                           (io_FU_output_bits_RD_valid),
    .io_FU_output_bits_fetch_PC                           (io_FU_output_bits_fetch_PC),
    .io_FU_output_bits_MOB_index                          (io_FU_output_bits_MOB_index),
    .io_FU_output_bits_ROB_index                          (io_FU_output_bits_ROB_index),
    .io_FU_output_bits_fetch_packet_index
      (io_FU_output_bits_fetch_packet_index)
  );
  assign io_FU_input_ready = 1'h1;
  assign io_FU_output_bits_branch_taken = 1'h0;
  assign io_FU_output_bits_target_address = 32'h0;
  assign io_FU_output_bits_branch_valid = 1'h0;
  assign io_FU_output_bits_address = 32'h0;
  assign io_FU_output_bits_memory_type = 2'h0;
  assign io_FU_output_bits_access_width = 2'h0;
  assign io_FU_output_bits_is_unsigned = 1'h0;
  assign io_FU_output_bits_wr_data = 32'h0;
endmodule

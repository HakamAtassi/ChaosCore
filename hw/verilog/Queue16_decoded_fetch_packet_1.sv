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

module Queue16_decoded_fetch_packet_1(
  input         clock,
                reset,
                io_enq_valid,
  input  [31:0] io_enq_bits_fetch_PC,
  input         io_enq_bits_decoded_instruction_0_ready_bits_RS1_ready,
                io_enq_bits_decoded_instruction_0_ready_bits_RS2_ready,
  input  [4:0]  io_enq_bits_decoded_instruction_0_RDold,
  input  [6:0]  io_enq_bits_decoded_instruction_0_RD,
  input         io_enq_bits_decoded_instruction_0_RD_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_0_RS1,
  input         io_enq_bits_decoded_instruction_0_RS1_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_0_RS2,
  input         io_enq_bits_decoded_instruction_0_RS2_valid,
  input  [20:0] io_enq_bits_decoded_instruction_0_IMM,
  input  [2:0]  io_enq_bits_decoded_instruction_0_FUNCT3,
  input  [1:0]  io_enq_bits_decoded_instruction_0_packet_index,
  input  [5:0]  io_enq_bits_decoded_instruction_0_ROB_index,
  input  [3:0]  io_enq_bits_decoded_instruction_0_MOB_index,
  input  [4:0]  io_enq_bits_decoded_instruction_0_instructionType,
  input  [1:0]  io_enq_bits_decoded_instruction_0_portID,
                io_enq_bits_decoded_instruction_0_RS_type,
  input         io_enq_bits_decoded_instruction_0_needs_ALU,
                io_enq_bits_decoded_instruction_0_needs_branch_unit,
                io_enq_bits_decoded_instruction_0_needs_CSRs,
                io_enq_bits_decoded_instruction_0_SUBTRACT,
                io_enq_bits_decoded_instruction_0_MULTIPLY,
                io_enq_bits_decoded_instruction_0_IS_IMM,
  input  [1:0]  io_enq_bits_decoded_instruction_0_memory_type,
                io_enq_bits_decoded_instruction_0_access_width,
  input         io_enq_bits_decoded_instruction_1_ready_bits_RS1_ready,
                io_enq_bits_decoded_instruction_1_ready_bits_RS2_ready,
  input  [4:0]  io_enq_bits_decoded_instruction_1_RDold,
  input  [6:0]  io_enq_bits_decoded_instruction_1_RD,
  input         io_enq_bits_decoded_instruction_1_RD_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_1_RS1,
  input         io_enq_bits_decoded_instruction_1_RS1_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_1_RS2,
  input         io_enq_bits_decoded_instruction_1_RS2_valid,
  input  [20:0] io_enq_bits_decoded_instruction_1_IMM,
  input  [2:0]  io_enq_bits_decoded_instruction_1_FUNCT3,
  input  [1:0]  io_enq_bits_decoded_instruction_1_packet_index,
  input  [5:0]  io_enq_bits_decoded_instruction_1_ROB_index,
  input  [3:0]  io_enq_bits_decoded_instruction_1_MOB_index,
  input  [4:0]  io_enq_bits_decoded_instruction_1_instructionType,
  input  [1:0]  io_enq_bits_decoded_instruction_1_portID,
                io_enq_bits_decoded_instruction_1_RS_type,
  input         io_enq_bits_decoded_instruction_1_needs_ALU,
                io_enq_bits_decoded_instruction_1_needs_branch_unit,
                io_enq_bits_decoded_instruction_1_needs_CSRs,
                io_enq_bits_decoded_instruction_1_SUBTRACT,
                io_enq_bits_decoded_instruction_1_MULTIPLY,
                io_enq_bits_decoded_instruction_1_IS_IMM,
  input  [1:0]  io_enq_bits_decoded_instruction_1_memory_type,
                io_enq_bits_decoded_instruction_1_access_width,
  input         io_enq_bits_decoded_instruction_2_ready_bits_RS1_ready,
                io_enq_bits_decoded_instruction_2_ready_bits_RS2_ready,
  input  [4:0]  io_enq_bits_decoded_instruction_2_RDold,
  input  [6:0]  io_enq_bits_decoded_instruction_2_RD,
  input         io_enq_bits_decoded_instruction_2_RD_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_2_RS1,
  input         io_enq_bits_decoded_instruction_2_RS1_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_2_RS2,
  input         io_enq_bits_decoded_instruction_2_RS2_valid,
  input  [20:0] io_enq_bits_decoded_instruction_2_IMM,
  input  [2:0]  io_enq_bits_decoded_instruction_2_FUNCT3,
  input  [1:0]  io_enq_bits_decoded_instruction_2_packet_index,
  input  [5:0]  io_enq_bits_decoded_instruction_2_ROB_index,
  input  [3:0]  io_enq_bits_decoded_instruction_2_MOB_index,
  input  [4:0]  io_enq_bits_decoded_instruction_2_instructionType,
  input  [1:0]  io_enq_bits_decoded_instruction_2_portID,
                io_enq_bits_decoded_instruction_2_RS_type,
  input         io_enq_bits_decoded_instruction_2_needs_ALU,
                io_enq_bits_decoded_instruction_2_needs_branch_unit,
                io_enq_bits_decoded_instruction_2_needs_CSRs,
                io_enq_bits_decoded_instruction_2_SUBTRACT,
                io_enq_bits_decoded_instruction_2_MULTIPLY,
                io_enq_bits_decoded_instruction_2_IS_IMM,
  input  [1:0]  io_enq_bits_decoded_instruction_2_memory_type,
                io_enq_bits_decoded_instruction_2_access_width,
  input         io_enq_bits_decoded_instruction_3_ready_bits_RS1_ready,
                io_enq_bits_decoded_instruction_3_ready_bits_RS2_ready,
  input  [4:0]  io_enq_bits_decoded_instruction_3_RDold,
  input  [6:0]  io_enq_bits_decoded_instruction_3_RD,
  input         io_enq_bits_decoded_instruction_3_RD_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_3_RS1,
  input         io_enq_bits_decoded_instruction_3_RS1_valid,
  input  [6:0]  io_enq_bits_decoded_instruction_3_RS2,
  input         io_enq_bits_decoded_instruction_3_RS2_valid,
  input  [20:0] io_enq_bits_decoded_instruction_3_IMM,
  input  [2:0]  io_enq_bits_decoded_instruction_3_FUNCT3,
  input  [1:0]  io_enq_bits_decoded_instruction_3_packet_index,
  input  [5:0]  io_enq_bits_decoded_instruction_3_ROB_index,
  input  [3:0]  io_enq_bits_decoded_instruction_3_MOB_index,
  input  [4:0]  io_enq_bits_decoded_instruction_3_instructionType,
  input  [1:0]  io_enq_bits_decoded_instruction_3_portID,
                io_enq_bits_decoded_instruction_3_RS_type,
  input         io_enq_bits_decoded_instruction_3_needs_ALU,
                io_enq_bits_decoded_instruction_3_needs_branch_unit,
                io_enq_bits_decoded_instruction_3_needs_CSRs,
                io_enq_bits_decoded_instruction_3_SUBTRACT,
                io_enq_bits_decoded_instruction_3_MULTIPLY,
                io_enq_bits_decoded_instruction_3_IS_IMM,
  input  [1:0]  io_enq_bits_decoded_instruction_3_memory_type,
                io_enq_bits_decoded_instruction_3_access_width,
  input         io_enq_bits_valid_bits_0,
                io_enq_bits_valid_bits_1,
                io_enq_bits_valid_bits_2,
                io_enq_bits_valid_bits_3,
  input  [15:0] io_enq_bits_GHR,
  input  [6:0]  io_enq_bits_TOS,
                io_enq_bits_NEXT,
  input         io_enq_bits_prediction_hit,
  input  [31:0] io_enq_bits_prediction_target,
  input  [2:0]  io_enq_bits_prediction_br_type,
  input         io_enq_bits_prediction_T_NT,
  input  [7:0]  io_enq_bits_free_list_front_pointer,
  input         io_deq_ready,
  output        io_deq_valid,
  output [31:0] io_deq_bits_fetch_PC,
  output [4:0]  io_deq_bits_decoded_instruction_0_RDold,
  output [6:0]  io_deq_bits_decoded_instruction_0_RD,
  output        io_deq_bits_decoded_instruction_0_RD_valid,
  output [6:0]  io_deq_bits_decoded_instruction_0_RS1,
  output        io_deq_bits_decoded_instruction_0_RS1_valid,
  output [6:0]  io_deq_bits_decoded_instruction_0_RS2,
  output        io_deq_bits_decoded_instruction_0_RS2_valid,
  output [20:0] io_deq_bits_decoded_instruction_0_IMM,
  output [2:0]  io_deq_bits_decoded_instruction_0_FUNCT3,
  output [1:0]  io_deq_bits_decoded_instruction_0_packet_index,
  output [5:0]  io_deq_bits_decoded_instruction_0_ROB_index,
  output [3:0]  io_deq_bits_decoded_instruction_0_MOB_index,
  output [4:0]  io_deq_bits_decoded_instruction_0_instructionType,
  output [1:0]  io_deq_bits_decoded_instruction_0_portID,
                io_deq_bits_decoded_instruction_0_RS_type,
  output        io_deq_bits_decoded_instruction_0_needs_ALU,
                io_deq_bits_decoded_instruction_0_needs_branch_unit,
                io_deq_bits_decoded_instruction_0_needs_CSRs,
                io_deq_bits_decoded_instruction_0_SUBTRACT,
                io_deq_bits_decoded_instruction_0_MULTIPLY,
                io_deq_bits_decoded_instruction_0_IS_IMM,
  output [1:0]  io_deq_bits_decoded_instruction_0_memory_type,
                io_deq_bits_decoded_instruction_0_access_width,
  output [4:0]  io_deq_bits_decoded_instruction_1_RDold,
  output [6:0]  io_deq_bits_decoded_instruction_1_RD,
  output        io_deq_bits_decoded_instruction_1_RD_valid,
  output [6:0]  io_deq_bits_decoded_instruction_1_RS1,
  output        io_deq_bits_decoded_instruction_1_RS1_valid,
  output [6:0]  io_deq_bits_decoded_instruction_1_RS2,
  output        io_deq_bits_decoded_instruction_1_RS2_valid,
  output [20:0] io_deq_bits_decoded_instruction_1_IMM,
  output [2:0]  io_deq_bits_decoded_instruction_1_FUNCT3,
  output [1:0]  io_deq_bits_decoded_instruction_1_packet_index,
  output [5:0]  io_deq_bits_decoded_instruction_1_ROB_index,
  output [3:0]  io_deq_bits_decoded_instruction_1_MOB_index,
  output [4:0]  io_deq_bits_decoded_instruction_1_instructionType,
  output [1:0]  io_deq_bits_decoded_instruction_1_portID,
                io_deq_bits_decoded_instruction_1_RS_type,
  output        io_deq_bits_decoded_instruction_1_needs_ALU,
                io_deq_bits_decoded_instruction_1_needs_branch_unit,
                io_deq_bits_decoded_instruction_1_needs_CSRs,
                io_deq_bits_decoded_instruction_1_SUBTRACT,
                io_deq_bits_decoded_instruction_1_MULTIPLY,
                io_deq_bits_decoded_instruction_1_IS_IMM,
  output [1:0]  io_deq_bits_decoded_instruction_1_memory_type,
                io_deq_bits_decoded_instruction_1_access_width,
  output [4:0]  io_deq_bits_decoded_instruction_2_RDold,
  output [6:0]  io_deq_bits_decoded_instruction_2_RD,
  output        io_deq_bits_decoded_instruction_2_RD_valid,
  output [6:0]  io_deq_bits_decoded_instruction_2_RS1,
  output        io_deq_bits_decoded_instruction_2_RS1_valid,
  output [6:0]  io_deq_bits_decoded_instruction_2_RS2,
  output        io_deq_bits_decoded_instruction_2_RS2_valid,
  output [20:0] io_deq_bits_decoded_instruction_2_IMM,
  output [2:0]  io_deq_bits_decoded_instruction_2_FUNCT3,
  output [1:0]  io_deq_bits_decoded_instruction_2_packet_index,
  output [5:0]  io_deq_bits_decoded_instruction_2_ROB_index,
  output [3:0]  io_deq_bits_decoded_instruction_2_MOB_index,
  output [4:0]  io_deq_bits_decoded_instruction_2_instructionType,
  output [1:0]  io_deq_bits_decoded_instruction_2_portID,
                io_deq_bits_decoded_instruction_2_RS_type,
  output        io_deq_bits_decoded_instruction_2_needs_ALU,
                io_deq_bits_decoded_instruction_2_needs_branch_unit,
                io_deq_bits_decoded_instruction_2_needs_CSRs,
                io_deq_bits_decoded_instruction_2_SUBTRACT,
                io_deq_bits_decoded_instruction_2_MULTIPLY,
                io_deq_bits_decoded_instruction_2_IS_IMM,
  output [1:0]  io_deq_bits_decoded_instruction_2_memory_type,
                io_deq_bits_decoded_instruction_2_access_width,
  output [4:0]  io_deq_bits_decoded_instruction_3_RDold,
  output [6:0]  io_deq_bits_decoded_instruction_3_RD,
  output        io_deq_bits_decoded_instruction_3_RD_valid,
  output [6:0]  io_deq_bits_decoded_instruction_3_RS1,
  output        io_deq_bits_decoded_instruction_3_RS1_valid,
  output [6:0]  io_deq_bits_decoded_instruction_3_RS2,
  output        io_deq_bits_decoded_instruction_3_RS2_valid,
  output [20:0] io_deq_bits_decoded_instruction_3_IMM,
  output [2:0]  io_deq_bits_decoded_instruction_3_FUNCT3,
  output [1:0]  io_deq_bits_decoded_instruction_3_packet_index,
  output [5:0]  io_deq_bits_decoded_instruction_3_ROB_index,
  output [3:0]  io_deq_bits_decoded_instruction_3_MOB_index,
  output [4:0]  io_deq_bits_decoded_instruction_3_instructionType,
  output [1:0]  io_deq_bits_decoded_instruction_3_portID,
                io_deq_bits_decoded_instruction_3_RS_type,
  output        io_deq_bits_decoded_instruction_3_needs_ALU,
                io_deq_bits_decoded_instruction_3_needs_branch_unit,
                io_deq_bits_decoded_instruction_3_needs_CSRs,
                io_deq_bits_decoded_instruction_3_SUBTRACT,
                io_deq_bits_decoded_instruction_3_MULTIPLY,
                io_deq_bits_decoded_instruction_3_IS_IMM,
  output [1:0]  io_deq_bits_decoded_instruction_3_memory_type,
                io_deq_bits_decoded_instruction_3_access_width,
  output        io_deq_bits_valid_bits_0,
                io_deq_bits_valid_bits_1,
                io_deq_bits_valid_bits_2,
                io_deq_bits_valid_bits_3,
  output [15:0] io_deq_bits_GHR,
  output [6:0]  io_deq_bits_TOS,
                io_deq_bits_NEXT,
  output        io_deq_bits_prediction_hit,
  output [31:0] io_deq_bits_prediction_target,
  output [2:0]  io_deq_bits_prediction_br_type,
  output        io_deq_bits_prediction_T_NT,
  output [7:0]  io_deq_bits_free_list_front_pointer,
  input         io_flush
);

  wire         io_enq_ready;
  wire [446:0] _ram_ext_R0_data;
  reg  [3:0]   enq_ptr_value;
  reg  [3:0]   deq_ptr_value;
  reg          maybe_full;
  wire         ptr_match = enq_ptr_value == deq_ptr_value;
  wire         empty = ptr_match & ~maybe_full;
  wire         do_enq = io_enq_ready & io_enq_valid;
  assign io_enq_ready = ~(ptr_match & maybe_full);
  always @(posedge clock) begin
    if (reset) begin
      enq_ptr_value <= 4'h0;
      deq_ptr_value <= 4'h0;
      maybe_full <= 1'h0;
    end
    else begin
      automatic logic do_deq;
      do_deq = io_deq_ready & ~empty;
      if (io_flush) begin
        enq_ptr_value <= 4'h0;
        deq_ptr_value <= 4'h0;
      end
      else begin
        if (do_enq)
          enq_ptr_value <= enq_ptr_value + 4'h1;
        if (do_deq)
          deq_ptr_value <= deq_ptr_value + 4'h1;
      end
      maybe_full <= ~io_flush & (do_enq == do_deq ? maybe_full : do_enq);
    end
  end // always @(posedge)
  ram_16x447 ram_ext (
    .R0_addr (deq_ptr_value),
    .R0_en   (1'h1),
    .R0_clk  (clock),
    .R0_data (_ram_ext_R0_data),
    .W0_addr (enq_ptr_value),
    .W0_en   (do_enq),
    .W0_clk  (clock),
    .W0_data
      ({io_enq_bits_free_list_front_pointer,
        io_enq_bits_prediction_T_NT,
        io_enq_bits_prediction_br_type,
        io_enq_bits_prediction_target,
        io_enq_bits_prediction_hit,
        io_enq_bits_NEXT,
        io_enq_bits_TOS,
        io_enq_bits_GHR,
        io_enq_bits_valid_bits_3,
        io_enq_bits_valid_bits_2,
        io_enq_bits_valid_bits_1,
        io_enq_bits_valid_bits_0,
        io_enq_bits_decoded_instruction_3_access_width,
        io_enq_bits_decoded_instruction_3_memory_type,
        io_enq_bits_decoded_instruction_3_IS_IMM,
        io_enq_bits_decoded_instruction_3_MULTIPLY,
        io_enq_bits_decoded_instruction_3_SUBTRACT,
        io_enq_bits_decoded_instruction_3_needs_CSRs,
        io_enq_bits_decoded_instruction_3_needs_branch_unit,
        io_enq_bits_decoded_instruction_3_needs_ALU,
        io_enq_bits_decoded_instruction_3_RS_type,
        io_enq_bits_decoded_instruction_3_portID,
        io_enq_bits_decoded_instruction_3_instructionType,
        io_enq_bits_decoded_instruction_3_MOB_index,
        io_enq_bits_decoded_instruction_3_ROB_index,
        io_enq_bits_decoded_instruction_3_packet_index,
        io_enq_bits_decoded_instruction_3_FUNCT3,
        io_enq_bits_decoded_instruction_3_IMM,
        io_enq_bits_decoded_instruction_3_RS2_valid,
        io_enq_bits_decoded_instruction_3_RS2,
        io_enq_bits_decoded_instruction_3_RS1_valid,
        io_enq_bits_decoded_instruction_3_RS1,
        io_enq_bits_decoded_instruction_3_RD_valid,
        io_enq_bits_decoded_instruction_3_RD,
        io_enq_bits_decoded_instruction_3_RDold,
        io_enq_bits_decoded_instruction_2_access_width,
        io_enq_bits_decoded_instruction_2_memory_type,
        io_enq_bits_decoded_instruction_2_IS_IMM,
        io_enq_bits_decoded_instruction_2_MULTIPLY,
        io_enq_bits_decoded_instruction_2_SUBTRACT,
        io_enq_bits_decoded_instruction_2_needs_CSRs,
        io_enq_bits_decoded_instruction_2_needs_branch_unit,
        io_enq_bits_decoded_instruction_2_needs_ALU,
        io_enq_bits_decoded_instruction_2_RS_type,
        io_enq_bits_decoded_instruction_2_portID,
        io_enq_bits_decoded_instruction_2_instructionType,
        io_enq_bits_decoded_instruction_2_MOB_index,
        io_enq_bits_decoded_instruction_2_ROB_index,
        io_enq_bits_decoded_instruction_2_packet_index,
        io_enq_bits_decoded_instruction_2_FUNCT3,
        io_enq_bits_decoded_instruction_2_IMM,
        io_enq_bits_decoded_instruction_2_RS2_valid,
        io_enq_bits_decoded_instruction_2_RS2,
        io_enq_bits_decoded_instruction_2_RS1_valid,
        io_enq_bits_decoded_instruction_2_RS1,
        io_enq_bits_decoded_instruction_2_RD_valid,
        io_enq_bits_decoded_instruction_2_RD,
        io_enq_bits_decoded_instruction_2_RDold,
        io_enq_bits_decoded_instruction_1_access_width,
        io_enq_bits_decoded_instruction_1_memory_type,
        io_enq_bits_decoded_instruction_1_IS_IMM,
        io_enq_bits_decoded_instruction_1_MULTIPLY,
        io_enq_bits_decoded_instruction_1_SUBTRACT,
        io_enq_bits_decoded_instruction_1_needs_CSRs,
        io_enq_bits_decoded_instruction_1_needs_branch_unit,
        io_enq_bits_decoded_instruction_1_needs_ALU,
        io_enq_bits_decoded_instruction_1_RS_type,
        io_enq_bits_decoded_instruction_1_portID,
        io_enq_bits_decoded_instruction_1_instructionType,
        io_enq_bits_decoded_instruction_1_MOB_index,
        io_enq_bits_decoded_instruction_1_ROB_index,
        io_enq_bits_decoded_instruction_1_packet_index,
        io_enq_bits_decoded_instruction_1_FUNCT3,
        io_enq_bits_decoded_instruction_1_IMM,
        io_enq_bits_decoded_instruction_1_RS2_valid,
        io_enq_bits_decoded_instruction_1_RS2,
        io_enq_bits_decoded_instruction_1_RS1_valid,
        io_enq_bits_decoded_instruction_1_RS1,
        io_enq_bits_decoded_instruction_1_RD_valid,
        io_enq_bits_decoded_instruction_1_RD,
        io_enq_bits_decoded_instruction_1_RDold,
        io_enq_bits_decoded_instruction_0_access_width,
        io_enq_bits_decoded_instruction_0_memory_type,
        io_enq_bits_decoded_instruction_0_IS_IMM,
        io_enq_bits_decoded_instruction_0_MULTIPLY,
        io_enq_bits_decoded_instruction_0_SUBTRACT,
        io_enq_bits_decoded_instruction_0_needs_CSRs,
        io_enq_bits_decoded_instruction_0_needs_branch_unit,
        io_enq_bits_decoded_instruction_0_needs_ALU,
        io_enq_bits_decoded_instruction_0_RS_type,
        io_enq_bits_decoded_instruction_0_portID,
        io_enq_bits_decoded_instruction_0_instructionType,
        io_enq_bits_decoded_instruction_0_MOB_index,
        io_enq_bits_decoded_instruction_0_ROB_index,
        io_enq_bits_decoded_instruction_0_packet_index,
        io_enq_bits_decoded_instruction_0_FUNCT3,
        io_enq_bits_decoded_instruction_0_IMM,
        io_enq_bits_decoded_instruction_0_RS2_valid,
        io_enq_bits_decoded_instruction_0_RS2,
        io_enq_bits_decoded_instruction_0_RS1_valid,
        io_enq_bits_decoded_instruction_0_RS1,
        io_enq_bits_decoded_instruction_0_RD_valid,
        io_enq_bits_decoded_instruction_0_RD,
        io_enq_bits_decoded_instruction_0_RDold,
        io_enq_bits_fetch_PC})
  );
  assign io_deq_valid = ~empty;
  assign io_deq_bits_fetch_PC = _ram_ext_R0_data[31:0];
  assign io_deq_bits_decoded_instruction_0_RDold = _ram_ext_R0_data[36:32];
  assign io_deq_bits_decoded_instruction_0_RD = _ram_ext_R0_data[43:37];
  assign io_deq_bits_decoded_instruction_0_RD_valid = _ram_ext_R0_data[44];
  assign io_deq_bits_decoded_instruction_0_RS1 = _ram_ext_R0_data[51:45];
  assign io_deq_bits_decoded_instruction_0_RS1_valid = _ram_ext_R0_data[52];
  assign io_deq_bits_decoded_instruction_0_RS2 = _ram_ext_R0_data[59:53];
  assign io_deq_bits_decoded_instruction_0_RS2_valid = _ram_ext_R0_data[60];
  assign io_deq_bits_decoded_instruction_0_IMM = _ram_ext_R0_data[81:61];
  assign io_deq_bits_decoded_instruction_0_FUNCT3 = _ram_ext_R0_data[84:82];
  assign io_deq_bits_decoded_instruction_0_packet_index = _ram_ext_R0_data[86:85];
  assign io_deq_bits_decoded_instruction_0_ROB_index = _ram_ext_R0_data[92:87];
  assign io_deq_bits_decoded_instruction_0_MOB_index = _ram_ext_R0_data[96:93];
  assign io_deq_bits_decoded_instruction_0_instructionType = _ram_ext_R0_data[101:97];
  assign io_deq_bits_decoded_instruction_0_portID = _ram_ext_R0_data[103:102];
  assign io_deq_bits_decoded_instruction_0_RS_type = _ram_ext_R0_data[105:104];
  assign io_deq_bits_decoded_instruction_0_needs_ALU = _ram_ext_R0_data[106];
  assign io_deq_bits_decoded_instruction_0_needs_branch_unit = _ram_ext_R0_data[107];
  assign io_deq_bits_decoded_instruction_0_needs_CSRs = _ram_ext_R0_data[108];
  assign io_deq_bits_decoded_instruction_0_SUBTRACT = _ram_ext_R0_data[109];
  assign io_deq_bits_decoded_instruction_0_MULTIPLY = _ram_ext_R0_data[110];
  assign io_deq_bits_decoded_instruction_0_IS_IMM = _ram_ext_R0_data[111];
  assign io_deq_bits_decoded_instruction_0_memory_type = _ram_ext_R0_data[113:112];
  assign io_deq_bits_decoded_instruction_0_access_width = _ram_ext_R0_data[115:114];
  assign io_deq_bits_decoded_instruction_1_RDold = _ram_ext_R0_data[120:116];
  assign io_deq_bits_decoded_instruction_1_RD = _ram_ext_R0_data[127:121];
  assign io_deq_bits_decoded_instruction_1_RD_valid = _ram_ext_R0_data[128];
  assign io_deq_bits_decoded_instruction_1_RS1 = _ram_ext_R0_data[135:129];
  assign io_deq_bits_decoded_instruction_1_RS1_valid = _ram_ext_R0_data[136];
  assign io_deq_bits_decoded_instruction_1_RS2 = _ram_ext_R0_data[143:137];
  assign io_deq_bits_decoded_instruction_1_RS2_valid = _ram_ext_R0_data[144];
  assign io_deq_bits_decoded_instruction_1_IMM = _ram_ext_R0_data[165:145];
  assign io_deq_bits_decoded_instruction_1_FUNCT3 = _ram_ext_R0_data[168:166];
  assign io_deq_bits_decoded_instruction_1_packet_index = _ram_ext_R0_data[170:169];
  assign io_deq_bits_decoded_instruction_1_ROB_index = _ram_ext_R0_data[176:171];
  assign io_deq_bits_decoded_instruction_1_MOB_index = _ram_ext_R0_data[180:177];
  assign io_deq_bits_decoded_instruction_1_instructionType = _ram_ext_R0_data[185:181];
  assign io_deq_bits_decoded_instruction_1_portID = _ram_ext_R0_data[187:186];
  assign io_deq_bits_decoded_instruction_1_RS_type = _ram_ext_R0_data[189:188];
  assign io_deq_bits_decoded_instruction_1_needs_ALU = _ram_ext_R0_data[190];
  assign io_deq_bits_decoded_instruction_1_needs_branch_unit = _ram_ext_R0_data[191];
  assign io_deq_bits_decoded_instruction_1_needs_CSRs = _ram_ext_R0_data[192];
  assign io_deq_bits_decoded_instruction_1_SUBTRACT = _ram_ext_R0_data[193];
  assign io_deq_bits_decoded_instruction_1_MULTIPLY = _ram_ext_R0_data[194];
  assign io_deq_bits_decoded_instruction_1_IS_IMM = _ram_ext_R0_data[195];
  assign io_deq_bits_decoded_instruction_1_memory_type = _ram_ext_R0_data[197:196];
  assign io_deq_bits_decoded_instruction_1_access_width = _ram_ext_R0_data[199:198];
  assign io_deq_bits_decoded_instruction_2_RDold = _ram_ext_R0_data[204:200];
  assign io_deq_bits_decoded_instruction_2_RD = _ram_ext_R0_data[211:205];
  assign io_deq_bits_decoded_instruction_2_RD_valid = _ram_ext_R0_data[212];
  assign io_deq_bits_decoded_instruction_2_RS1 = _ram_ext_R0_data[219:213];
  assign io_deq_bits_decoded_instruction_2_RS1_valid = _ram_ext_R0_data[220];
  assign io_deq_bits_decoded_instruction_2_RS2 = _ram_ext_R0_data[227:221];
  assign io_deq_bits_decoded_instruction_2_RS2_valid = _ram_ext_R0_data[228];
  assign io_deq_bits_decoded_instruction_2_IMM = _ram_ext_R0_data[249:229];
  assign io_deq_bits_decoded_instruction_2_FUNCT3 = _ram_ext_R0_data[252:250];
  assign io_deq_bits_decoded_instruction_2_packet_index = _ram_ext_R0_data[254:253];
  assign io_deq_bits_decoded_instruction_2_ROB_index = _ram_ext_R0_data[260:255];
  assign io_deq_bits_decoded_instruction_2_MOB_index = _ram_ext_R0_data[264:261];
  assign io_deq_bits_decoded_instruction_2_instructionType = _ram_ext_R0_data[269:265];
  assign io_deq_bits_decoded_instruction_2_portID = _ram_ext_R0_data[271:270];
  assign io_deq_bits_decoded_instruction_2_RS_type = _ram_ext_R0_data[273:272];
  assign io_deq_bits_decoded_instruction_2_needs_ALU = _ram_ext_R0_data[274];
  assign io_deq_bits_decoded_instruction_2_needs_branch_unit = _ram_ext_R0_data[275];
  assign io_deq_bits_decoded_instruction_2_needs_CSRs = _ram_ext_R0_data[276];
  assign io_deq_bits_decoded_instruction_2_SUBTRACT = _ram_ext_R0_data[277];
  assign io_deq_bits_decoded_instruction_2_MULTIPLY = _ram_ext_R0_data[278];
  assign io_deq_bits_decoded_instruction_2_IS_IMM = _ram_ext_R0_data[279];
  assign io_deq_bits_decoded_instruction_2_memory_type = _ram_ext_R0_data[281:280];
  assign io_deq_bits_decoded_instruction_2_access_width = _ram_ext_R0_data[283:282];
  assign io_deq_bits_decoded_instruction_3_RDold = _ram_ext_R0_data[288:284];
  assign io_deq_bits_decoded_instruction_3_RD = _ram_ext_R0_data[295:289];
  assign io_deq_bits_decoded_instruction_3_RD_valid = _ram_ext_R0_data[296];
  assign io_deq_bits_decoded_instruction_3_RS1 = _ram_ext_R0_data[303:297];
  assign io_deq_bits_decoded_instruction_3_RS1_valid = _ram_ext_R0_data[304];
  assign io_deq_bits_decoded_instruction_3_RS2 = _ram_ext_R0_data[311:305];
  assign io_deq_bits_decoded_instruction_3_RS2_valid = _ram_ext_R0_data[312];
  assign io_deq_bits_decoded_instruction_3_IMM = _ram_ext_R0_data[333:313];
  assign io_deq_bits_decoded_instruction_3_FUNCT3 = _ram_ext_R0_data[336:334];
  assign io_deq_bits_decoded_instruction_3_packet_index = _ram_ext_R0_data[338:337];
  assign io_deq_bits_decoded_instruction_3_ROB_index = _ram_ext_R0_data[344:339];
  assign io_deq_bits_decoded_instruction_3_MOB_index = _ram_ext_R0_data[348:345];
  assign io_deq_bits_decoded_instruction_3_instructionType = _ram_ext_R0_data[353:349];
  assign io_deq_bits_decoded_instruction_3_portID = _ram_ext_R0_data[355:354];
  assign io_deq_bits_decoded_instruction_3_RS_type = _ram_ext_R0_data[357:356];
  assign io_deq_bits_decoded_instruction_3_needs_ALU = _ram_ext_R0_data[358];
  assign io_deq_bits_decoded_instruction_3_needs_branch_unit = _ram_ext_R0_data[359];
  assign io_deq_bits_decoded_instruction_3_needs_CSRs = _ram_ext_R0_data[360];
  assign io_deq_bits_decoded_instruction_3_SUBTRACT = _ram_ext_R0_data[361];
  assign io_deq_bits_decoded_instruction_3_MULTIPLY = _ram_ext_R0_data[362];
  assign io_deq_bits_decoded_instruction_3_IS_IMM = _ram_ext_R0_data[363];
  assign io_deq_bits_decoded_instruction_3_memory_type = _ram_ext_R0_data[365:364];
  assign io_deq_bits_decoded_instruction_3_access_width = _ram_ext_R0_data[367:366];
  assign io_deq_bits_valid_bits_0 = _ram_ext_R0_data[368];
  assign io_deq_bits_valid_bits_1 = _ram_ext_R0_data[369];
  assign io_deq_bits_valid_bits_2 = _ram_ext_R0_data[370];
  assign io_deq_bits_valid_bits_3 = _ram_ext_R0_data[371];
  assign io_deq_bits_GHR = _ram_ext_R0_data[387:372];
  assign io_deq_bits_TOS = _ram_ext_R0_data[394:388];
  assign io_deq_bits_NEXT = _ram_ext_R0_data[401:395];
  assign io_deq_bits_prediction_hit = _ram_ext_R0_data[402];
  assign io_deq_bits_prediction_target = _ram_ext_R0_data[434:403];
  assign io_deq_bits_prediction_br_type = _ram_ext_R0_data[437:435];
  assign io_deq_bits_prediction_T_NT = _ram_ext_R0_data[438];
  assign io_deq_bits_free_list_front_pointer = _ram_ext_R0_data[446:439];
endmodule


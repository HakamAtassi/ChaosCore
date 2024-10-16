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

module BRU(
  input         io_FTQ_valid,
  input  [31:0] io_FTQ_fetch_PC,
                io_FTQ_predicted_PC,
  input         io_FTQ_T_NT,
  input  [2:0]  io_FTQ_br_type,
  input  [1:0]  io_FTQ_dominant_index,
  input  [31:0] io_FTQ_resolved_PC,
  input         io_ROB_output_row_valid,
  input  [31:0] io_ROB_output_fetch_PC,
  input  [5:0]  io_ROB_output_ROB_index,
  input  [15:0] io_ROB_output_GHR,
  input  [6:0]  io_ROB_output_NEXT,
                io_ROB_output_TOS,
  input  [7:0]  io_ROB_output_free_list_front_pointer,
  input         io_ROB_output_ROB_entries_0_valid,
  input  [1:0]  io_ROB_output_ROB_entries_0_memory_type,
  input  [6:0]  io_ROB_output_ROB_entries_0_RD,
  input         io_ROB_output_ROB_entries_0_RD_valid,
  input  [4:0]  io_ROB_output_ROB_entries_0_RDold,
  input         io_ROB_output_ROB_entries_1_valid,
  input  [1:0]  io_ROB_output_ROB_entries_1_memory_type,
  input  [6:0]  io_ROB_output_ROB_entries_1_RD,
  input         io_ROB_output_ROB_entries_1_RD_valid,
  input  [4:0]  io_ROB_output_ROB_entries_1_RDold,
  input         io_ROB_output_ROB_entries_2_valid,
  input  [1:0]  io_ROB_output_ROB_entries_2_memory_type,
  input  [6:0]  io_ROB_output_ROB_entries_2_RD,
  input         io_ROB_output_ROB_entries_2_RD_valid,
  input  [4:0]  io_ROB_output_ROB_entries_2_RDold,
  input         io_ROB_output_ROB_entries_3_valid,
  input  [1:0]  io_ROB_output_ROB_entries_3_memory_type,
  input  [6:0]  io_ROB_output_ROB_entries_3_RD,
  input         io_ROB_output_ROB_entries_3_RD_valid,
  input  [4:0]  io_ROB_output_ROB_entries_3_RDold,
  input         io_ROB_output_complete_0,
                io_ROB_output_complete_1,
                io_ROB_output_complete_2,
                io_ROB_output_complete_3,
                io_ROB_output_violation_0,
                io_ROB_output_violation_1,
                io_ROB_output_violation_2,
                io_ROB_output_violation_3,
  output        io_commit_valid,
  output [31:0] io_commit_bits_fetch_PC,
  output        io_commit_bits_T_NT,
  output [5:0]  io_commit_bits_ROB_index,
  output [2:0]  io_commit_bits_br_type,
  output [1:0]  io_commit_bits_fetch_packet_index,
  output        io_commit_bits_is_misprediction,
                io_commit_bits_violation,
  output [31:0] io_commit_bits_expected_PC,
  output [15:0] io_commit_bits_GHR,
  output [6:0]  io_commit_bits_TOS,
                io_commit_bits_NEXT,
  output [7:0]  io_commit_bits_free_list_front_pointer,
  output [4:0]  io_commit_bits_RDold_0,
                io_commit_bits_RDold_1,
                io_commit_bits_RDold_2,
                io_commit_bits_RDold_3,
  output [6:0]  io_commit_bits_RD_0,
                io_commit_bits_RD_1,
                io_commit_bits_RD_2,
                io_commit_bits_RD_3,
  output        io_commit_bits_RD_valid_0,
                io_commit_bits_RD_valid_1,
                io_commit_bits_RD_valid_2,
                io_commit_bits_RD_valid_3
);

  wire commit_valid =
    io_ROB_output_row_valid
    & (io_ROB_output_complete_0 & io_ROB_output_ROB_entries_0_valid
       | ~io_ROB_output_ROB_entries_0_valid
       | io_ROB_output_ROB_entries_0_memory_type == 2'h2
       & io_ROB_output_ROB_entries_0_valid)
    & (io_ROB_output_complete_1 & io_ROB_output_ROB_entries_1_valid
       | ~io_ROB_output_ROB_entries_1_valid
       | io_ROB_output_ROB_entries_1_memory_type == 2'h2
       & io_ROB_output_ROB_entries_1_valid)
    & (io_ROB_output_complete_2 & io_ROB_output_ROB_entries_2_valid
       | ~io_ROB_output_ROB_entries_2_valid
       | io_ROB_output_ROB_entries_2_memory_type == 2'h2
       & io_ROB_output_ROB_entries_2_valid)
    & (io_ROB_output_complete_3 & io_ROB_output_ROB_entries_3_valid
       | ~io_ROB_output_ROB_entries_3_valid
       | io_ROB_output_ROB_entries_3_memory_type == 2'h2
       & io_ROB_output_ROB_entries_3_valid);
  wire branch_commit =
    commit_valid & io_ROB_output_fetch_PC == io_FTQ_fetch_PC & io_FTQ_valid;
  assign io_commit_valid = commit_valid;
  assign io_commit_bits_fetch_PC = io_ROB_output_fetch_PC;
  assign io_commit_bits_T_NT = branch_commit & io_FTQ_T_NT;
  assign io_commit_bits_ROB_index = io_ROB_output_ROB_index;
  assign io_commit_bits_br_type = branch_commit ? io_FTQ_br_type : 3'h0;
  assign io_commit_bits_fetch_packet_index = branch_commit ? io_FTQ_dominant_index : 2'h0;
  assign io_commit_bits_is_misprediction =
    branch_commit & io_FTQ_predicted_PC != io_FTQ_resolved_PC;
  assign io_commit_bits_violation =
    io_ROB_output_violation_0 | io_ROB_output_violation_1 | io_ROB_output_violation_2
    | io_ROB_output_violation_3;
  assign io_commit_bits_expected_PC = branch_commit ? io_FTQ_resolved_PC : 32'h0;
  assign io_commit_bits_GHR = io_ROB_output_GHR;
  assign io_commit_bits_TOS = io_ROB_output_TOS;
  assign io_commit_bits_NEXT = io_ROB_output_NEXT;
  assign io_commit_bits_free_list_front_pointer = io_ROB_output_free_list_front_pointer;
  assign io_commit_bits_RDold_0 = io_ROB_output_ROB_entries_0_RDold;
  assign io_commit_bits_RDold_1 = io_ROB_output_ROB_entries_1_RDold;
  assign io_commit_bits_RDold_2 = io_ROB_output_ROB_entries_2_RDold;
  assign io_commit_bits_RDold_3 = io_ROB_output_ROB_entries_3_RDold;
  assign io_commit_bits_RD_0 = io_ROB_output_ROB_entries_0_RD;
  assign io_commit_bits_RD_1 = io_ROB_output_ROB_entries_1_RD;
  assign io_commit_bits_RD_2 = io_ROB_output_ROB_entries_2_RD;
  assign io_commit_bits_RD_3 = io_ROB_output_ROB_entries_3_RD;
  assign io_commit_bits_RD_valid_0 = io_ROB_output_ROB_entries_0_RD_valid;
  assign io_commit_bits_RD_valid_1 = io_ROB_output_ROB_entries_1_RD_valid;
  assign io_commit_bits_RD_valid_2 = io_ROB_output_ROB_entries_2_RD_valid;
  assign io_commit_bits_RD_valid_3 = io_ROB_output_ROB_entries_3_RD_valid;
endmodule


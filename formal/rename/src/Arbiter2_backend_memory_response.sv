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

module Arbiter2_backend_memory_response(
  output        io_in_0_ready,
  input         io_in_0_valid,
  input  [31:0] io_in_0_bits_addr,
                io_in_0_bits_PRD,
                io_in_0_bits_fetch_packet_index,
  input  [5:0]  io_in_0_bits_ROB_index,
  input  [31:0] io_in_0_bits_data,
  input  [3:0]  io_in_0_bits_MOB_index,
  output        io_in_1_ready,
  input         io_in_1_valid,
  input  [31:0] io_in_1_bits_addr,
                io_in_1_bits_PRD,
                io_in_1_bits_fetch_packet_index,
  input  [5:0]  io_in_1_bits_ROB_index,
  input  [31:0] io_in_1_bits_data,
  input  [3:0]  io_in_1_bits_MOB_index,
  input         io_out_ready,
  output        io_out_valid,
  output [31:0] io_out_bits_addr,
                io_out_bits_PRD,
                io_out_bits_fetch_packet_index,
  output [5:0]  io_out_bits_ROB_index,
  output [31:0] io_out_bits_data,
  output [3:0]  io_out_bits_MOB_index
);

  assign io_in_0_ready = io_out_ready;
  assign io_in_1_ready = ~io_in_0_valid & io_out_ready;
  assign io_out_valid = io_in_0_valid | io_in_1_valid;
  assign io_out_bits_addr = io_in_0_valid ? io_in_0_bits_addr : io_in_1_bits_addr;
  assign io_out_bits_PRD = io_in_0_valid ? io_in_0_bits_PRD : io_in_1_bits_PRD;
  assign io_out_bits_fetch_packet_index =
    io_in_0_valid ? io_in_0_bits_fetch_packet_index : io_in_1_bits_fetch_packet_index;
  assign io_out_bits_ROB_index =
    io_in_0_valid ? io_in_0_bits_ROB_index : io_in_1_bits_ROB_index;
  assign io_out_bits_data = io_in_0_valid ? io_in_0_bits_data : io_in_1_bits_data;
  assign io_out_bits_MOB_index =
    io_in_0_valid ? io_in_0_bits_MOB_index : io_in_1_bits_MOB_index;
endmodule

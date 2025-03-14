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

module Queue3_backend_memory_response(
  input         clock,
                reset,
  output        io_enq_ready,
  input         io_enq_valid,
  input  [31:0] io_enq_bits_addr,
                io_enq_bits_PRD,
                io_enq_bits_fetch_packet_index,
  input  [5:0]  io_enq_bits_ROB_index,
  input  [31:0] io_enq_bits_data,
  input  [3:0]  io_enq_bits_MOB_index,
  input         io_deq_ready,
  output        io_deq_valid,
  output [31:0] io_deq_bits_addr,
                io_deq_bits_PRD,
                io_deq_bits_fetch_packet_index,
  output [5:0]  io_deq_bits_ROB_index,
  output [31:0] io_deq_bits_data,
  output [3:0]  io_deq_bits_MOB_index
);

  wire         do_deq;
  wire [137:0] _ram_ext_R0_data;
  reg  [1:0]   enq_ptr_value;
  reg  [1:0]   deq_ptr_value;
  reg          maybe_full;
  wire         ptr_match = enq_ptr_value == deq_ptr_value;
  wire         empty = ptr_match & ~maybe_full;
  wire         full = ptr_match & maybe_full;
  wire         io_deq_valid_0 = io_enq_valid | ~empty;
  assign do_deq = ~empty & io_deq_ready & io_deq_valid_0;
  wire         do_enq = ~(empty & io_deq_ready) & ~full & io_enq_valid;
  always @(posedge clock) begin
    if (reset) begin
      enq_ptr_value <= 2'h0;
      deq_ptr_value <= 2'h0;
      maybe_full <= 1'h0;
    end
    else begin
      if (do_enq) begin
        if (enq_ptr_value == 2'h2)
          enq_ptr_value <= 2'h0;
        else
          enq_ptr_value <= enq_ptr_value + 2'h1;
      end
      if (do_deq) begin
        if (deq_ptr_value == 2'h2)
          deq_ptr_value <= 2'h0;
        else
          deq_ptr_value <= deq_ptr_value + 2'h1;
      end
      if (~(do_enq == do_deq))
        maybe_full <= do_enq;
    end
  end // always @(posedge)
  ram_3x138 ram_ext (
    .R0_addr
      (do_deq ? (deq_ptr_value == 2'h2 ? 2'h0 : deq_ptr_value + 2'h1) : deq_ptr_value),
    .R0_en   (1'h1),
    .R0_clk  (clock),
    .R0_data (_ram_ext_R0_data),
    .W0_addr (enq_ptr_value),
    .W0_en   (do_enq),
    .W0_clk  (clock),
    .W0_data
      ({io_enq_bits_MOB_index,
        io_enq_bits_data,
        io_enq_bits_ROB_index,
        io_enq_bits_fetch_packet_index,
        io_enq_bits_PRD,
        io_enq_bits_addr})
  );
  assign io_enq_ready = ~full;
  assign io_deq_valid = io_deq_valid_0;
  assign io_deq_bits_addr = empty ? io_enq_bits_addr : _ram_ext_R0_data[31:0];
  assign io_deq_bits_PRD = empty ? io_enq_bits_PRD : _ram_ext_R0_data[63:32];
  assign io_deq_bits_fetch_packet_index =
    empty ? io_enq_bits_fetch_packet_index : _ram_ext_R0_data[95:64];
  assign io_deq_bits_ROB_index = empty ? io_enq_bits_ROB_index : _ram_ext_R0_data[101:96];
  assign io_deq_bits_data = empty ? io_enq_bits_data : _ram_ext_R0_data[133:102];
  assign io_deq_bits_MOB_index =
    empty ? io_enq_bits_MOB_index : _ram_ext_R0_data[137:134];
endmodule


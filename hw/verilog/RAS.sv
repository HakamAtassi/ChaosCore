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

module RAS(
  input         clock,
                reset,
  input  [31:0] io_wr_addr,
  input         io_wr_valid,
                io_rd_valid,
  input  [6:0]  io_revert_NEXT,
                io_revert_TOS,
  input         io_revert_valid,
  output [31:0] io_ret_addr,
  output [6:0]  io_NEXT,
                io_TOS
);

  wire [6:0]  NOS;
  wire [38:0] _RAS_memory_io_data_out;
  reg  [6:0]  NEXT;
  reg  [6:0]  TOS;
  assign NOS = _RAS_memory_io_data_out[38:32];
  always @(posedge clock) begin
    if (reset) begin
      NEXT <= 7'h0;
      TOS <= 7'h0;
    end
    else if (io_revert_valid) begin
      NEXT <= io_revert_NEXT;
      TOS <= io_revert_TOS;
    end
    else if (io_wr_valid) begin
      NEXT <= NEXT + 7'h1;
      TOS <= NEXT;
    end
    else if (io_rd_valid)
      TOS <= NOS;
  end // always @(posedge)
  SDPReadWriteSmem RAS_memory (
    .clock       (clock),
    .reset       (reset),
    .io_rd_addr
      (io_wr_valid ? NEXT : io_rd_valid ? NOS : io_revert_valid ? io_revert_TOS : TOS),
    .io_data_out (_RAS_memory_io_data_out),
    .io_wr_addr  (NEXT),
    .io_wr_en    (io_wr_valid),
    .io_data_in  ({TOS, io_wr_addr})
  );
  assign io_ret_addr = _RAS_memory_io_data_out[31:0];
  assign io_NEXT = NEXT;
  assign io_TOS = TOS;
endmodule


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

module debug_printer(
  input         clock,
                reset,
  output        io_memory_request_ready,
  input         io_memory_request_valid,
  input  [31:0] io_memory_request_bits_addr,
                io_memory_request_bits_wr_data,
  input         io_memory_request_bits_wr_en
);

  `ifndef SYNTHESIS
    always @(posedge clock) begin
      if ((`PRINTF_COND_) & io_memory_request_bits_addr == 32'h400
          & io_memory_request_valid & ~reset)
        $fwrite(32'h80000002, "%c", io_memory_request_bits_wr_data);
    end // always @(posedge)
  `endif // not def SYNTHESIS
  assign io_memory_request_ready = 1'h1;
endmodule

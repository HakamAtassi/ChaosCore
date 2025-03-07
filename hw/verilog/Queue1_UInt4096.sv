// Generated by CIRCT firtool-1.62.0
module Queue1_UInt4096(
  input           clock,
                  reset,
  output          io_enq_ready,
  input           io_enq_valid,
  input  [4095:0] io_enq_bits,
  input           io_deq_ready,
  output          io_deq_valid,
  output [4095:0] io_deq_bits,
  output          io_count
);

  reg  [4095:0] ram;
  reg           full;
  wire          _GEN = io_enq_valid | full;
  wire          do_enq = ~(~full & io_deq_ready) & ~full & io_enq_valid;
  always @(posedge clock) begin
    if (do_enq)
      ram <= io_enq_bits;
    if (reset)
      full <= 1'h0;
    else if (~(do_enq == (full & io_deq_ready & _GEN)))
      full <= do_enq;
  end // always @(posedge)
  assign io_enq_ready = ~full;
  assign io_deq_valid = _GEN;
  assign io_deq_bits = full ? ram : io_enq_bits;
  assign io_count = full;
endmodule


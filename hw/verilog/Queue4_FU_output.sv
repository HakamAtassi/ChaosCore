// Generated by CIRCT firtool-1.62.0
// Standard header to adapt well known macros for prints and assertions.

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

module Queue4_FU_output(
  input                                                                                                                                                                                                                                                                                                                                                                                                             clock,
                                                                                                                                                                                                                                                                                                                                                                                                                    reset,
  output                                                                                                                                                                                                                                                                                                                                                                                                            io_enq_ready,
  input                                                                                                                                                                                                                                                                                                                                                                                                             io_enq_valid,
  input  struct packed {logic [6:0] RD; logic [31:0] RD_data; logic RD_valid; logic [31:0] fetch_PC; logic branch_taken; logic [31:0] target_address; logic branch_valid; logic [31:0] address; logic [1:0] memory_type; logic [1:0] access_width; logic is_unsigned; logic [31:0] wr_data; logic [3:0] MOB_index; logic [5:0] ROB_index; logic [3:0] FTQ_index; logic [1:0] fetch_packet_index; logic exception; } io_enq_bits,
  input                                                                                                                                                                                                                                                                                                                                                                                                             io_deq_ready,
  output                                                                                                                                                                                                                                                                                                                                                                                                            io_deq_valid,
  output struct packed {logic [6:0] RD; logic [31:0] RD_data; logic RD_valid; logic [31:0] fetch_PC; logic branch_taken; logic [31:0] target_address; logic branch_valid; logic [31:0] address; logic [1:0] memory_type; logic [1:0] access_width; logic is_unsigned; logic [31:0] wr_data; logic [3:0] MOB_index; logic [5:0] ROB_index; logic [3:0] FTQ_index; logic [1:0] fetch_packet_index; logic exception; } io_deq_bits,
  output [2:0]                                                                                                                                                                                                                                                                                                                                                                                                      io_count,
  input                                                                                                                                                                                                                                                                                                                                                                                                             io_flush
);

  wire         _GEN;
  wire [1:0]   _GEN_0;
  wire [3:0]   _GEN_1;
  wire [5:0]   _GEN_2;
  wire [3:0]   _GEN_3;
  wire [31:0]  _GEN_4;
  wire         _GEN_5;
  wire [1:0]   _GEN_6;
  wire [1:0]   _GEN_7;
  wire [31:0]  _GEN_8;
  wire         _GEN_9;
  wire [31:0]  _GEN_10;
  wire         _GEN_11;
  wire [31:0]  _GEN_12;
  wire         _GEN_13;
  wire [31:0]  _GEN_14;
  wire [6:0]   _GEN_15;
  wire         _GEN_16;
  wire         _GEN_17;
  wire         _GEN_18;
  wire         _GEN_19;
  wire         _GEN_20;
  wire         _GEN_21;
  wire         _GEN_22;
  wire         _GEN_23;
  wire         _GEN_24;
  wire         _GEN_25;
  wire         _GEN_26;
  wire         _GEN_27;
  wire         _GEN_28;
  wire         _GEN_29;
  wire         _GEN_30;
  wire         _GEN_31;
  wire         _GEN_32;
  wire [191:0] _ram_ext_R0_data;
  wire
    struct packed {logic RD; logic RD_data; logic RD_valid; logic fetch_PC; logic branch_taken; logic target_address; logic branch_valid; logic address; logic memory_type; logic access_width; logic is_unsigned; logic wr_data; logic MOB_index; logic ROB_index; logic FTQ_index; logic fetch_packet_index; logic exception; }
    _GEN_33 = /*cast(bit)*/17'h0;
  wire
    struct packed {logic [6:0] RD; logic [31:0] RD_data; logic RD_valid; logic [31:0] fetch_PC; logic branch_taken; logic [31:0] target_address; logic branch_valid; logic [31:0] address; logic [1:0] memory_type; logic [1:0] access_width; logic is_unsigned; logic [31:0] wr_data; logic [3:0] MOB_index; logic [5:0] ROB_index; logic [3:0] FTQ_index; logic [1:0] fetch_packet_index; logic exception; }
    _GEN_34 = /*cast(bit)*/192'h0;
  reg  [1:0]   enq_ptr_value;
  reg  [1:0]   deq_ptr_value;
  reg          maybe_full;
  wire         ptr_match = enq_ptr_value == deq_ptr_value;
  wire         empty = ptr_match & ~maybe_full;
  wire         full = ptr_match & maybe_full;
  wire         do_enq = ~full & io_enq_valid;
  assign _GEN_32 = do_enq | _GEN_33.RD;
  assign _GEN_31 = do_enq | _GEN_33.RD_data;
  assign _GEN_30 = do_enq | _GEN_33.RD_valid;
  assign _GEN_29 = do_enq | _GEN_33.fetch_PC;
  assign _GEN_28 = do_enq | _GEN_33.branch_taken;
  assign _GEN_27 = do_enq | _GEN_33.target_address;
  assign _GEN_26 = do_enq | _GEN_33.branch_valid;
  assign _GEN_25 = do_enq | _GEN_33.address;
  assign _GEN_24 = do_enq | _GEN_33.memory_type;
  assign _GEN_23 = do_enq | _GEN_33.access_width;
  assign _GEN_22 = do_enq | _GEN_33.is_unsigned;
  assign _GEN_21 = do_enq | _GEN_33.wr_data;
  assign _GEN_20 = do_enq | _GEN_33.MOB_index;
  assign _GEN_19 = do_enq | _GEN_33.ROB_index;
  assign _GEN_18 = do_enq | _GEN_33.FTQ_index;
  assign _GEN_17 = do_enq | _GEN_33.fetch_packet_index;
  assign _GEN_16 = do_enq | _GEN_33.exception;
  assign _GEN_15 = do_enq ? io_enq_bits.RD : _GEN_34.RD;
  assign _GEN_14 = do_enq ? io_enq_bits.RD_data : _GEN_34.RD_data;
  assign _GEN_13 = do_enq ? io_enq_bits.RD_valid : _GEN_34.RD_valid;
  assign _GEN_12 = do_enq ? io_enq_bits.fetch_PC : _GEN_34.fetch_PC;
  assign _GEN_11 = do_enq ? io_enq_bits.branch_taken : _GEN_34.branch_taken;
  assign _GEN_10 = do_enq ? io_enq_bits.target_address : _GEN_34.target_address;
  assign _GEN_9 = do_enq ? io_enq_bits.branch_valid : _GEN_34.branch_valid;
  assign _GEN_8 = do_enq ? io_enq_bits.address : _GEN_34.address;
  assign _GEN_7 = do_enq ? io_enq_bits.memory_type : _GEN_34.memory_type;
  assign _GEN_6 = do_enq ? io_enq_bits.access_width : _GEN_34.access_width;
  assign _GEN_5 = do_enq ? io_enq_bits.is_unsigned : _GEN_34.is_unsigned;
  assign _GEN_4 = do_enq ? io_enq_bits.wr_data : _GEN_34.wr_data;
  assign _GEN_3 = do_enq ? io_enq_bits.MOB_index : _GEN_34.MOB_index;
  assign _GEN_2 = do_enq ? io_enq_bits.ROB_index : _GEN_34.ROB_index;
  assign _GEN_1 = do_enq ? io_enq_bits.FTQ_index : _GEN_34.FTQ_index;
  assign _GEN_0 = do_enq ? io_enq_bits.fetch_packet_index : _GEN_34.fetch_packet_index;
  assign _GEN = do_enq ? io_enq_bits.exception : _GEN_34.exception;
  always @(posedge clock) begin
    if (reset) begin
      enq_ptr_value <= 2'h0;
      deq_ptr_value <= 2'h0;
      maybe_full <= 1'h0;
    end
    else begin
      automatic logic do_deq;
      do_deq = io_deq_ready & ~empty;
      if (io_flush) begin
        enq_ptr_value <= 2'h0;
        deq_ptr_value <= 2'h0;
      end
      else begin
        if (do_enq)
          enq_ptr_value <= enq_ptr_value + 2'h1;
        if (do_deq)
          deq_ptr_value <= deq_ptr_value + 2'h1;
      end
      maybe_full <= ~io_flush & (do_enq == do_deq ? maybe_full : do_enq);
    end
  end // always @(posedge)
  ram_4x192 ram_ext (
    .R0_addr (deq_ptr_value),
    .R0_en   (1'h1),
    .R0_clk  (clock),
    .R0_data (_ram_ext_R0_data),
    .W0_addr (enq_ptr_value),
    .W0_en   (do_enq),
    .W0_clk  (clock),
    .W0_data
      ({_GEN,
        _GEN_0,
        _GEN_1,
        _GEN_2,
        _GEN_3,
        _GEN_4,
        _GEN_5,
        _GEN_6,
        _GEN_7,
        _GEN_8,
        _GEN_9,
        _GEN_10,
        _GEN_11,
        _GEN_12,
        _GEN_13,
        _GEN_14,
        _GEN_15}),
    .W0_mask
      ({_GEN_16,
        {2{_GEN_17}},
        {4{_GEN_18}},
        {6{_GEN_19}},
        {4{_GEN_20}},
        {32{_GEN_21}},
        _GEN_22,
        {2{_GEN_23}},
        {2{_GEN_24}},
        {32{_GEN_25}},
        _GEN_26,
        {32{_GEN_27}},
        _GEN_28,
        {32{_GEN_29}},
        _GEN_30,
        {32{_GEN_31}},
        {7{_GEN_32}}})
  );
  assign io_enq_ready = ~full;
  assign io_deq_valid = ~empty;
  assign io_deq_bits = /*cast(bit)*/_ram_ext_R0_data;
  assign io_count = {maybe_full & ptr_match, enq_ptr_value - deq_ptr_value};
endmodule

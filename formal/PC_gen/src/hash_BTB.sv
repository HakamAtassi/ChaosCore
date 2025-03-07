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
module hash_BTB(	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
  input         clock,	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
                reset,	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
  input  [31:0] io_predict_PC,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  input         io_predict_valid,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  output        io_BTB_hit,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
                io_BTB_output_BTB_valid,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  output [31:0] io_BTB_output_BTB_target,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  output [2:0]  io_BTB_output_BTB_br_type,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  input         io_commit_valid,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  input  [31:0] io_commit_bits_fetch_PC,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  input  [2:0]  io_commit_bits_br_type,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  input  [1:0]  io_commit_bits_fetch_packet_index,	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
  input  [31:0] io_commit_bits_expected_PC	// src/main/scala/Frontend/BP/hash_BTB.scala:92:16
);

  wire        _BTB_memory_io_data_out_BTB_valid;	// src/main/scala/Frontend/BP/hash_BTB.scala:113:28
  wire [17:0] _BTB_memory_io_data_out_BTB_tag;	// src/main/scala/Frontend/BP/hash_BTB.scala:113:28
  wire [1:0]  _BTB_memory_io_data_out_BTB_fetch_packet_index;	// src/main/scala/Frontend/BP/hash_BTB.scala:113:28
  reg  [2:0]  access_fetch_packet_index;	// src/main/scala/Frontend/BP/hash_BTB.scala:143:44
  reg  [15:0] io_BTB_hit_REG;	// src/main/scala/Frontend/BP/hash_BTB.scala:145:32
  reg         io_BTB_output_BTB_valid_REG;	// src/main/scala/Frontend/BP/hash_BTB.scala:147:39
  always @(posedge clock) begin	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
    access_fetch_packet_index <= io_predict_PC[4:2];	// src/main/scala/Frontend/BP/hash_BTB.scala:143:44, src/main/scala/utils.scala:197:63
    io_BTB_hit_REG <= io_predict_PC[31:16];	// src/main/scala/Frontend/BP/hash_BTB.scala:145:32, src/main/scala/utils.scala:112:15
    io_BTB_output_BTB_valid_REG <= io_predict_valid;	// src/main/scala/Frontend/BP/hash_BTB.scala:147:39
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_REG_	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
    `ifdef FIRRTL_BEFORE_INITIAL	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
      `FIRRTL_BEFORE_INITIAL	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
    `endif // FIRRTL_BEFORE_INITIAL
    initial begin	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
      automatic logic [31:0] _RANDOM[0:0];	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
      `ifdef INIT_RANDOM_PROLOG_	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
        `INIT_RANDOM_PROLOG_	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
      `endif // INIT_RANDOM_PROLOG_
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
        _RANDOM[/*Zero width*/ 1'b0] = `RANDOM;	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
        access_fetch_packet_index = _RANDOM[/*Zero width*/ 1'b0][2:0];	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7, :143:44
        io_BTB_hit_REG = _RANDOM[/*Zero width*/ 1'b0][18:3];	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7, :143:44, :145:32
        io_BTB_output_BTB_valid_REG = _RANDOM[/*Zero width*/ 1'b0][19];	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7, :143:44, :147:39
      `endif // RANDOMIZE_REG_INIT
    end // initial
    `ifdef FIRRTL_AFTER_INITIAL	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
      `FIRRTL_AFTER_INITIAL	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7
    `endif // FIRRTL_AFTER_INITIAL
  `endif // ENABLE_INITIAL_REG_
  hash_BTB_mem BTB_memory (	// src/main/scala/Frontend/BP/hash_BTB.scala:113:28
    .clock                              (clock),
    .reset                              (reset),
    .io_rd_addr                         (io_predict_PC[15:4]),	// src/main/scala/Frontend/BP/hash_BTB.scala:115:50, :119:29
    .io_data_out_BTB_valid              (_BTB_memory_io_data_out_BTB_valid),
    .io_data_out_BTB_tag                (_BTB_memory_io_data_out_BTB_tag),
    .io_data_out_BTB_target             (io_BTB_output_BTB_target),
    .io_data_out_BTB_br_type           (io_BTB_output_BTB_br_type),
    .io_data_out_BTB_fetch_packet_index (_BTB_memory_io_data_out_BTB_fetch_packet_index),
    .io_wr_addr                         (io_commit_bits_fetch_PC[15:4]),	// src/main/scala/Frontend/BP/hash_BTB.scala:116:60, :120:29
    .io_wr_en                           (io_commit_valid),
    .io_data_in_BTB_tag                 ({2'h0, io_commit_bits_fetch_PC[31:16]}),	// src/main/scala/Frontend/BP/hash_BTB.scala:128:49, src/main/scala/utils.scala:112:15
    .io_data_in_BTB_target              (io_commit_bits_expected_PC),
    .io_data_in_BTB_br_type            (io_commit_bits_br_type),
    .io_data_in_BTB_fetch_packet_index  (io_commit_bits_fetch_packet_index)
  );	// src/main/scala/Frontend/BP/hash_BTB.scala:113:28
  assign io_BTB_hit =
    {2'h0, io_BTB_hit_REG} == _BTB_memory_io_data_out_BTB_tag
    & _BTB_memory_io_data_out_BTB_valid
    & {1'h0, _BTB_memory_io_data_out_BTB_fetch_packet_index} >= access_fetch_packet_index;	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7, :113:28, :128:49, :143:44, :145:{32,52,72,99,133}
  assign io_BTB_output_BTB_valid = io_BTB_output_BTB_valid_REG;	// src/main/scala/Frontend/BP/hash_BTB.scala:88:7, :147:39
endmodule


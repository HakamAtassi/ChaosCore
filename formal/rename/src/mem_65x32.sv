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

// VCS coverage exclude_file
module mem_65x32(
  input  [6:0]  R0_addr,
  input         R0_en,
                R0_clk,
  output [31:0] R0_data,
  input  [6:0]  R1_addr,
  input         R1_en,
                R1_clk,
  output [31:0] R1_data,
  input  [6:0]  R2_addr,
  input         R2_en,
                R2_clk,
  output [31:0] R2_data,
  input  [6:0]  R3_addr,
  input         R3_en,
                R3_clk,
  output [31:0] R3_data,
  input  [6:0]  R4_addr,
  input         R4_en,
                R4_clk,
  output [31:0] R4_data,
  input  [6:0]  R5_addr,
  input         R5_en,
                R5_clk,
  output [31:0] R5_data,
  input  [6:0]  R6_addr,
  input         R6_en,
                R6_clk,
  output [31:0] R6_data,
  input  [6:0]  R7_addr,
  input         R7_en,
                R7_clk,
  output [31:0] R7_data,
  input  [6:0]  W0_addr,
  input         W0_en,
                W0_clk,
  input  [31:0] W0_data,
  input  [6:0]  W1_addr,
  input         W1_en,
                W1_clk,
  input  [31:0] W1_data,
  input  [6:0]  W2_addr,
  input         W2_en,
                W2_clk,
  input  [31:0] W2_data,
  input  [6:0]  W3_addr,
  input         W3_en,
                W3_clk,
  input  [31:0] W3_data
);

  reg [31:0] Memory[0:64];
  reg        _R0_en_d0;
  reg [6:0]  _R0_addr_d0;
  always @(posedge R0_clk) begin
    _R0_en_d0 <= R0_en;
    _R0_addr_d0 <= R0_addr;
  end // always @(posedge)
  reg        _R1_en_d0;
  reg [6:0]  _R1_addr_d0;
  always @(posedge R1_clk) begin
    _R1_en_d0 <= R1_en;
    _R1_addr_d0 <= R1_addr;
  end // always @(posedge)
  reg        _R2_en_d0;
  reg [6:0]  _R2_addr_d0;
  always @(posedge R2_clk) begin
    _R2_en_d0 <= R2_en;
    _R2_addr_d0 <= R2_addr;
  end // always @(posedge)
  reg        _R3_en_d0;
  reg [6:0]  _R3_addr_d0;
  always @(posedge R3_clk) begin
    _R3_en_d0 <= R3_en;
    _R3_addr_d0 <= R3_addr;
  end // always @(posedge)
  reg        _R4_en_d0;
  reg [6:0]  _R4_addr_d0;
  always @(posedge R4_clk) begin
    _R4_en_d0 <= R4_en;
    _R4_addr_d0 <= R4_addr;
  end // always @(posedge)
  reg        _R5_en_d0;
  reg [6:0]  _R5_addr_d0;
  always @(posedge R5_clk) begin
    _R5_en_d0 <= R5_en;
    _R5_addr_d0 <= R5_addr;
  end // always @(posedge)
  reg        _R6_en_d0;
  reg [6:0]  _R6_addr_d0;
  always @(posedge R6_clk) begin
    _R6_en_d0 <= R6_en;
    _R6_addr_d0 <= R6_addr;
  end // always @(posedge)
  reg        _R7_en_d0;
  reg [6:0]  _R7_addr_d0;
  always @(posedge R7_clk) begin
    _R7_en_d0 <= R7_en;
    _R7_addr_d0 <= R7_addr;
  end // always @(posedge)
  always @(posedge W0_clk) begin
    if (W0_en & 1'h1)
      Memory[W0_addr] <= W0_data;
    if (W1_en & 1'h1)
      Memory[W1_addr] <= W1_data;
    if (W2_en & 1'h1)
      Memory[W2_addr] <= W2_data;
    if (W3_en & 1'h1)
      Memory[W3_addr] <= W3_data;
  end // always @(posedge)
  assign R0_data = _R0_en_d0 ? Memory[_R0_addr_d0] : 32'bx;
  assign R1_data = _R1_en_d0 ? Memory[_R1_addr_d0] : 32'bx;
  assign R2_data = _R2_en_d0 ? Memory[_R2_addr_d0] : 32'bx;
  assign R3_data = _R3_en_d0 ? Memory[_R3_addr_d0] : 32'bx;
  assign R4_data = _R4_en_d0 ? Memory[_R4_addr_d0] : 32'bx;
  assign R5_data = _R5_en_d0 ? Memory[_R5_addr_d0] : 32'bx;
  assign R6_data = _R6_en_d0 ? Memory[_R6_addr_d0] : 32'bx;
  assign R7_data = _R7_en_d0 ? Memory[_R7_addr_d0] : 32'bx;
endmodule


// Generated by CIRCT firtool-1.62.0
// VCS coverage exclude_file
module mem_65536x2(
  input  [15:0] R0_addr,
  input         R0_en,
                R0_clk,
  output [1:0]  R0_data,
  input  [15:0] R1_addr,
  input         R1_en,
                R1_clk,
  output [1:0]  R1_data,
  input  [15:0] W0_addr,
  input         W0_en,
                W0_clk,
  input  [1:0]  W0_data
);

  reg [1:0]  Memory[0:65535];
  reg        _R0_en_d0;
  reg [15:0] _R0_addr_d0;
  always @(posedge R0_clk) begin
    _R0_en_d0 <= R0_en;
    _R0_addr_d0 <= R0_addr;
  end // always @(posedge)
  reg        _R1_en_d0;
  reg [15:0] _R1_addr_d0;
  always @(posedge R1_clk) begin
    _R1_en_d0 <= R1_en;
    _R1_addr_d0 <= R1_addr;
  end // always @(posedge)
  always @(posedge W0_clk) begin
    if (W0_en & 1'h1)
      Memory[W0_addr] <= W0_data;
  end // always @(posedge)
  assign R0_data = _R0_en_d0 ? Memory[_R0_addr_d0] : 2'bx;
  assign R1_data = _R1_en_d0 ? Memory[_R1_addr_d0] : 2'bx;
endmodule

module PHT_memory(
  input         clock,
  input  [15:0] io_addrA,
  output [15:0] io_readDataA,
  input  [15:0] io_addrB,
  output [15:0] io_readDataB,
  input  [15:0] io_addrC,
  input  [1:0]  io_writeDataC,
  input         io_writeEnableC
);

  wire [1:0] _mem_ext_R0_data;
  wire [1:0] _mem_ext_R1_data;
  mem_65536x2 mem_ext (
    .R0_addr (io_addrB),
    .R0_en   (1'h1),
    .R0_clk  (clock),
    .R0_data (_mem_ext_R0_data),
    .R1_addr (io_addrA),
    .R1_en   (1'h1),
    .R1_clk  (clock),
    .R1_data (_mem_ext_R1_data),
    .W0_addr (io_addrC),
    .W0_en   (io_writeEnableC),
    .W0_clk  (clock),
    .W0_data (io_writeDataC)
  );
  assign io_readDataA = {14'h0, _mem_ext_R1_data};
  assign io_readDataB = {14'h0, _mem_ext_R0_data};
endmodule

module gshare(
  input         clock,
                reset,
  input  [15:0] io_predict_GHR,
  input  [31:0] io_predict_PC,
  input         io_predict_valid,
  output        io_T_NT,
                io_valid,
  input  [15:0] io_commit_GHR,
  input  [31:0] io_commit_PC,
  input         io_commit_valid,
                io_commit_branch_direction
);

  wire [15:0] _PHT_io_readDataA;
  wire [15:0] _PHT_io_readDataB;
  wire [15:0] hashed_predict_addr = io_predict_PC[15:0] ^ io_predict_GHR;
  wire [15:0] hashed_commit_addr = io_commit_PC[15:0] ^ io_commit_GHR;
  reg         io_valid_REG;
  reg  [15:0] PHT_io_addrC_REG;
  reg         PHT_io_writeEnableC_REG;
  reg         REG;
  always @(posedge clock) begin
    io_valid_REG <= io_predict_valid;
    PHT_io_addrC_REG <= hashed_commit_addr;
    PHT_io_writeEnableC_REG <= io_commit_valid;
    REG <= io_commit_branch_direction;
  end // always @(posedge)
  PHT_memory PHT (
    .clock           (clock),
    .io_addrA        (hashed_predict_addr),
    .io_readDataA    (_PHT_io_readDataA),
    .io_addrB        (hashed_commit_addr),
    .io_readDataB    (_PHT_io_readDataB),
    .io_addrC        (PHT_io_addrC_REG),
    .io_writeDataC
      (REG
         ? (_PHT_io_readDataB[1:0] != 2'h3
              ? _PHT_io_readDataB[1:0] + 2'h1
              : _PHT_io_readDataB[1:0])
         : (|(_PHT_io_readDataB[1:0]))
             ? _PHT_io_readDataB[1:0] - 2'h1
             : _PHT_io_readDataB[1:0]),
    .io_writeEnableC (PHT_io_writeEnableC_REG)
  );
  assign io_T_NT = _PHT_io_readDataA[1];
  assign io_valid = io_valid_REG;
endmodule

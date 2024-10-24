// Generated by CIRCT firtool-1.76.0
// VCS coverage exclude_file
module mem_64x2(	// src/main/scala/memories/memories.scala:266:24
  input  [5:0] R0_addr,
  input        R0_en,
               R0_clk,
  output [1:0] R0_data,
  input  [5:0] W0_addr,
  input        W0_en,
               W0_clk,
  input  [1:0] W0_data,
  input  [5:0] W1_addr,
  input        W1_en,
               W1_clk,
  input  [1:0] W1_data,
  input  [5:0] W2_addr,
  input        W2_en,
               W2_clk,
  input  [1:0] W2_data,
  input  [5:0] W3_addr,
  input        W3_en,
               W3_clk,
  input  [1:0] W3_data,
  input  [5:0] W4_addr,
  input        W4_en,
               W4_clk,
  input  [1:0] W4_data
);

  reg [1:0] Memory[0:63];	// src/main/scala/memories/memories.scala:266:24
  reg       _R0_en_d0;	// src/main/scala/memories/memories.scala:266:24
  reg [5:0] _R0_addr_d0;	// src/main/scala/memories/memories.scala:266:24
  always @(posedge R0_clk) begin	// src/main/scala/memories/memories.scala:266:24
    _R0_en_d0 <= R0_en;	// src/main/scala/memories/memories.scala:266:24
    _R0_addr_d0 <= R0_addr;	// src/main/scala/memories/memories.scala:266:24
  end // always @(posedge)
  always @(posedge W0_clk) begin	// src/main/scala/memories/memories.scala:266:24
    if (W0_en & 1'h1)	// src/main/scala/memories/memories.scala:266:24
      Memory[W0_addr] <= W0_data;	// src/main/scala/memories/memories.scala:266:24
    if (W1_en & 1'h1)	// src/main/scala/memories/memories.scala:266:24
      Memory[W1_addr] <= W1_data;	// src/main/scala/memories/memories.scala:266:24
    if (W2_en & 1'h1)	// src/main/scala/memories/memories.scala:266:24
      Memory[W2_addr] <= W2_data;	// src/main/scala/memories/memories.scala:266:24
    if (W3_en & 1'h1)	// src/main/scala/memories/memories.scala:266:24
      Memory[W3_addr] <= W3_data;	// src/main/scala/memories/memories.scala:266:24
    if (W4_en & 1'h1)	// src/main/scala/memories/memories.scala:266:24
      Memory[W4_addr] <= W4_data;	// src/main/scala/memories/memories.scala:266:24
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_MEM_	// src/main/scala/memories/memories.scala:266:24
    `ifdef RANDOMIZE_REG_INIT	// src/main/scala/memories/memories.scala:266:24
      reg [31:0] _RANDOM;	// src/main/scala/memories/memories.scala:266:24
    `endif // RANDOMIZE_REG_INIT
    reg [31:0] _RANDOM_MEM;	// src/main/scala/memories/memories.scala:266:24
    initial begin	// src/main/scala/memories/memories.scala:266:24
      `INIT_RANDOM_PROLOG_	// src/main/scala/memories/memories.scala:266:24
      `ifdef RANDOMIZE_MEM_INIT	// src/main/scala/memories/memories.scala:266:24
        for (logic [6:0] i = 7'h0; i < 7'h40; i += 7'h1) begin
          _RANDOM_MEM = `RANDOM;	// src/main/scala/memories/memories.scala:266:24
          Memory[i[5:0]] = _RANDOM_MEM[1:0];	// src/main/scala/memories/memories.scala:266:24
        end
      `endif // RANDOMIZE_MEM_INIT
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/memories/memories.scala:266:24
        _RANDOM = {`RANDOM};	// src/main/scala/memories/memories.scala:266:24
        _R0_en_d0 = _RANDOM[0];	// src/main/scala/memories/memories.scala:266:24
        _R0_addr_d0 = _RANDOM[6:1];	// src/main/scala/memories/memories.scala:266:24
      `endif // RANDOMIZE_REG_INIT
    end // initial
  `endif // ENABLE_INITIAL_MEM_
  assign R0_data = _R0_en_d0 ? Memory[_R0_addr_d0] : 2'bx;	// src/main/scala/memories/memories.scala:266:24
endmodule


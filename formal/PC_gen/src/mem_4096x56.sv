// Generated by CIRCT firtool-1.76.0
// VCS coverage exclude_file
module mem_4096x56(	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
  input  [11:0] R0_addr,
  input         R0_en,
                R0_clk,
  output [55:0] R0_data,
  input  [11:0] W0_addr,
  input         W0_en,
                W0_clk,
  input  [55:0] W0_data
);

  reg [55:0] Memory[0:4095];	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
  reg        _R0_en_d0;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
  reg [11:0] _R0_addr_d0;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
  always @(posedge R0_clk) begin	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
    _R0_en_d0 <= R0_en;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
    _R0_addr_d0 <= R0_addr;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
  end // always @(posedge)
  always @(posedge W0_clk) begin	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
    if (W0_en & 1'h1)	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
      Memory[W0_addr] <= W0_data;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_MEM_	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
    `ifdef RANDOMIZE_REG_INIT	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
      reg [31:0] _RANDOM;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
    `endif // RANDOMIZE_REG_INIT
    reg [63:0] _RANDOM_MEM;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
    initial begin	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
      `INIT_RANDOM_PROLOG_	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
      `ifdef RANDOMIZE_MEM_INIT	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
        for (logic [12:0] i = 13'h0; i < 13'h1000; i += 13'h1) begin
          for (logic [6:0] j = 7'h0; j < 7'h40; j += 7'h20) begin
            _RANDOM_MEM[j +: 32] = `RANDOM;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
          end
          Memory[i[11:0]] = _RANDOM_MEM[55:0];	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
        end
      `endif // RANDOMIZE_MEM_INIT
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
        _RANDOM = {`RANDOM};	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
        _R0_en_d0 = _RANDOM[0];	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
        _R0_addr_d0 = _RANDOM[12:1];	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
      `endif // RANDOMIZE_REG_INIT
    end // initial
  `endif // ENABLE_INITIAL_MEM_
  assign R0_data = _R0_en_d0 ? Memory[_R0_addr_d0] : 56'bx;	// src/main/scala/Frontend/BP/hash_BTB.scala:55:24
endmodule


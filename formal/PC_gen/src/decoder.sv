// Generated by CIRCT firtool-1.76.0

// Users can define 'STOP_COND' to add an extra gate to stop conditions.
`ifndef STOP_COND_
  `ifdef STOP_COND
    `define STOP_COND_ (`STOP_COND)
  `else  // STOP_COND
    `define STOP_COND_ 1
  `endif // STOP_COND
`endif // not def STOP_COND_

// Users can define 'ASSERT_VERBOSE_COND' to add an extra gate to assert error printing.
`ifndef ASSERT_VERBOSE_COND_
  `ifdef ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ (`ASSERT_VERBOSE_COND)
  `else  // ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ 1
  `endif // ASSERT_VERBOSE_COND
`endif // not def ASSERT_VERBOSE_COND_

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
module decoder(	// src/main/scala/Frontend/decoder.scala:40:7
  input         clock,	// src/main/scala/Frontend/decoder.scala:40:7
                reset,	// src/main/scala/Frontend/decoder.scala:40:7
                io_instruction_valid,	// src/main/scala/Frontend/decoder.scala:43:16
  input  [31:0] io_instruction_bits_instruction,	// src/main/scala/Frontend/decoder.scala:43:16
  input  [3:0]  io_instruction_bits_packet_index,	// src/main/scala/Frontend/decoder.scala:43:16
  output [6:0]  io_decoded_instruction_bits_RD,	// src/main/scala/Frontend/decoder.scala:43:16
  output        io_decoded_instruction_bits_RD_valid,	// src/main/scala/Frontend/decoder.scala:43:16
  output [6:0]  io_decoded_instruction_bits_RS1,	// src/main/scala/Frontend/decoder.scala:43:16
  output        io_decoded_instruction_bits_RS1_valid,	// src/main/scala/Frontend/decoder.scala:43:16
  output [6:0]  io_decoded_instruction_bits_RS2,	// src/main/scala/Frontend/decoder.scala:43:16
  output        io_decoded_instruction_bits_RS2_valid,	// src/main/scala/Frontend/decoder.scala:43:16
  output [20:0] io_decoded_instruction_bits_IMM,	// src/main/scala/Frontend/decoder.scala:43:16
  output [2:0]  io_decoded_instruction_bits_FUNCT3,	// src/main/scala/Frontend/decoder.scala:43:16
  output [1:0]  io_decoded_instruction_bits_packet_index,	// src/main/scala/Frontend/decoder.scala:43:16
  output [4:0]  io_decoded_instruction_bits_instructionType,	// src/main/scala/Frontend/decoder.scala:43:16
  output [1:0]  io_decoded_instruction_bits_portID,	// src/main/scala/Frontend/decoder.scala:43:16
                io_decoded_instruction_bits_RS_type,	// src/main/scala/Frontend/decoder.scala:43:16
  output        io_decoded_instruction_bits_needs_ALU,	// src/main/scala/Frontend/decoder.scala:43:16
                io_decoded_instruction_bits_needs_branch_unit,	// src/main/scala/Frontend/decoder.scala:43:16
                io_decoded_instruction_bits_SUBTRACT,	// src/main/scala/Frontend/decoder.scala:43:16
                io_decoded_instruction_bits_MULTIPLY,	// src/main/scala/Frontend/decoder.scala:43:16
                io_decoded_instruction_bits_IS_IMM,	// src/main/scala/Frontend/decoder.scala:43:16
  output [1:0]  io_decoded_instruction_bits_memory_type,	// src/main/scala/Frontend/decoder.scala:43:16
                io_decoded_instruction_bits_access_width	// src/main/scala/Frontend/decoder.scala:43:16
);

  wire [8:0] _GEN = {9{io_instruction_bits_instruction[31]}};	// src/main/scala/utils.scala:154:18, :155:{17,25}
  wire [4:0] instructionType = io_instruction_bits_instruction[6:2];	// src/main/scala/Frontend/decoder.scala:55:34, :65:{56,63}
  wire       _is_MEM_T = instructionType == 5'h0;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T_1 = instructionType == 5'h4;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T_11 = instructionType == 5'h5;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_MEM_T_1 = instructionType == 5'h8;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T = instructionType == 5'hC;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T_9 = instructionType == 5'hD;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T_3 = instructionType == 5'h18;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T_7 = instructionType == 5'h19;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _is_INT_T_5 = instructionType == 5'h1B;	// src/main/scala/Frontend/decoder.scala:65:56
  wire       _io_decoded_instruction_bits_RD_valid_T_13 = instructionType == 5'h1C;	// src/main/scala/Frontend/decoder.scala:65:56
  `ifndef SYNTHESIS	// src/main/scala/Frontend/decoder.scala:66:11
    always @(posedge clock) begin	// src/main/scala/Frontend/decoder.scala:66:11
      if (~reset
          & ~(_is_MEM_T | instructionType == 5'h1 | instructionType == 5'h2
              | instructionType == 5'h3 | _is_INT_T_1 | _is_INT_T_11
              | instructionType == 5'h6 | _is_MEM_T_1 | instructionType == 5'h9
              | instructionType == 5'hA | instructionType == 5'hB | _is_INT_T
              | _is_INT_T_9 | instructionType == 5'hE | instructionType == 5'h10
              | instructionType == 5'h11 | instructionType == 5'h12
              | instructionType == 5'h13 | instructionType == 5'h14
              | instructionType == 5'h16 | _is_INT_T_3 | _is_INT_T_7 | _is_INT_T_5
              | _io_decoded_instruction_bits_RD_valid_T_13
              | instructionType == 5'h1E)) begin	// src/main/scala/Frontend/decoder.scala:65:56, :66:11
        if (`ASSERT_VERBOSE_COND_)	// src/main/scala/Frontend/decoder.scala:66:11
          $error("Assertion failed: Enum state must be valid, got %d!\n",
                 instructionType);	// src/main/scala/Frontend/decoder.scala:65:56, :66:11
        if (`STOP_COND_)	// src/main/scala/Frontend/decoder.scala:66:11
          $fatal;	// src/main/scala/Frontend/decoder.scala:66:11
      end
    end // always @(posedge)
  `endif // not def SYNTHESIS
  wire       _needs_ALU_T_1 = io_instruction_bits_instruction[31:25] == 7'h20;	// src/main/scala/Frontend/decoder.scala:62:34, :73:91
  wire       needs_branch_unit = _is_INT_T_3 | _is_INT_T_5 | _is_INT_T_7;	// src/main/scala/Frontend/decoder.scala:65:56, :84:{63,92}
  wire       needs_ALU =
    _is_INT_T & (_needs_ALU_T_1 | io_instruction_bits_instruction[31:25] == 7'h0)
    | _is_INT_T_1 | _is_INT_T_9 | _is_INT_T_11;	// src/main/scala/Frontend/decoder.scala:62:34, :65:56, :73:91, :86:60, :87:{55,66,80}, :88:{63,92}
  reg  [1:0] next_ALU_port_0;	// src/main/scala/Frontend/decoder.scala:174:32
  reg  [1:0] next_ALU_port_1;	// src/main/scala/Frontend/decoder.scala:174:32
  reg  [1:0] next_ALU_port_2;	// src/main/scala/Frontend/decoder.scala:174:32
  always @(posedge clock) begin	// src/main/scala/Frontend/decoder.scala:40:7
    if (reset) begin	// src/main/scala/Frontend/decoder.scala:40:7
      next_ALU_port_0 <= 2'h0;	// src/main/scala/Frontend/decoder.scala:174:32
      next_ALU_port_1 <= 2'h1;	// src/main/scala/Frontend/decoder.scala:174:32
      next_ALU_port_2 <= 2'h2;	// src/main/scala/Frontend/decoder.scala:174:32
    end
    else if (needs_ALU) begin	// src/main/scala/Frontend/decoder.scala:87:80, :88:{63,92}
      next_ALU_port_0 <= next_ALU_port_1;	// src/main/scala/Frontend/decoder.scala:174:32
      next_ALU_port_1 <= next_ALU_port_2;	// src/main/scala/Frontend/decoder.scala:174:32
      next_ALU_port_2 <= next_ALU_port_0;	// src/main/scala/Frontend/decoder.scala:174:32
    end
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_REG_	// src/main/scala/Frontend/decoder.scala:40:7
    `ifdef FIRRTL_BEFORE_INITIAL	// src/main/scala/Frontend/decoder.scala:40:7
      `FIRRTL_BEFORE_INITIAL	// src/main/scala/Frontend/decoder.scala:40:7
    `endif // FIRRTL_BEFORE_INITIAL
    initial begin	// src/main/scala/Frontend/decoder.scala:40:7
      automatic logic [31:0] _RANDOM[0:0];	// src/main/scala/Frontend/decoder.scala:40:7
      `ifdef INIT_RANDOM_PROLOG_	// src/main/scala/Frontend/decoder.scala:40:7
        `INIT_RANDOM_PROLOG_	// src/main/scala/Frontend/decoder.scala:40:7
      `endif // INIT_RANDOM_PROLOG_
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/Frontend/decoder.scala:40:7
        _RANDOM[/*Zero width*/ 1'b0] = `RANDOM;	// src/main/scala/Frontend/decoder.scala:40:7
        next_ALU_port_0 = _RANDOM[/*Zero width*/ 1'b0][1:0];	// src/main/scala/Frontend/decoder.scala:40:7, :174:32
        next_ALU_port_1 = _RANDOM[/*Zero width*/ 1'b0][3:2];	// src/main/scala/Frontend/decoder.scala:40:7, :174:32
        next_ALU_port_2 = _RANDOM[/*Zero width*/ 1'b0][5:4];	// src/main/scala/Frontend/decoder.scala:40:7, :174:32
      `endif // RANDOMIZE_REG_INIT
    end // initial
    `ifdef FIRRTL_AFTER_INITIAL	// src/main/scala/Frontend/decoder.scala:40:7
      `FIRRTL_AFTER_INITIAL	// src/main/scala/Frontend/decoder.scala:40:7
    `endif // FIRRTL_AFTER_INITIAL
  `endif // ENABLE_INITIAL_REG_
  assign io_decoded_instruction_bits_RD = {2'h0, io_instruction_bits_instruction[11:7]};	// src/main/scala/Frontend/decoder.scala:40:7, :58:34, :126:54
  assign io_decoded_instruction_bits_RD_valid =
    (_is_INT_T | _is_INT_T_1 | _is_MEM_T | _is_INT_T_5 | _is_INT_T_7 | _is_INT_T_9
     | _is_INT_T_11 | _io_decoded_instruction_bits_RD_valid_T_13) & io_instruction_valid;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :103:77, :104:77, :105:77, :106:77, :107:77, :108:77, :109:77, :110:77
  assign io_decoded_instruction_bits_RS1 = {2'h0, io_instruction_bits_instruction[19:15]};	// src/main/scala/Frontend/decoder.scala:40:7, :56:34, :128:54
  assign io_decoded_instruction_bits_RS1_valid =
    (_is_INT_T | _is_INT_T_1 | _is_MEM_T | _is_MEM_T_1 | _is_INT_T_7 | _is_INT_T_3)
    & io_instruction_valid;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :113:89, :114:89, :115:89, :116:89, :117:89, :118:89
  assign io_decoded_instruction_bits_RS2 = {2'h0, io_instruction_bits_instruction[24:20]};	// src/main/scala/Frontend/decoder.scala:40:7, :57:34, :129:54
  assign io_decoded_instruction_bits_RS2_valid =
    (_is_INT_T | _is_MEM_T_1 | _is_INT_T_3) & io_instruction_valid;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :121:89, :122:89, :123:89
  assign io_decoded_instruction_bits_IMM =
    io_instruction_bits_instruction[6:0] == 7'h63
      ? {{9{io_instruction_bits_instruction[31]}},
         io_instruction_bits_instruction[7],
         io_instruction_bits_instruction[30:25],
         io_instruction_bits_instruction[11:8],
         1'h0}
      : io_instruction_bits_instruction[6:0] == 7'h6F
          ? {io_instruction_bits_instruction[31],
             io_instruction_bits_instruction[19:12],
             io_instruction_bits_instruction[20],
             io_instruction_bits_instruction[30:21],
             1'h0}
          : io_instruction_bits_instruction[6:0] == 7'h13
            | io_instruction_bits_instruction[6:0] == 7'h3
            | io_instruction_bits_instruction[6:0] == 7'h67
              ? {_GEN, io_instruction_bits_instruction[31:20]}
              : io_instruction_bits_instruction[6:0] == 7'h23
                  ? {_GEN,
                     io_instruction_bits_instruction[31:25],
                     io_instruction_bits_instruction[11:7]}
                  : io_instruction_bits_instruction[6:0] == 7'h17
                    | io_instruction_bits_instruction[6:0] == 7'h37
                      ? {io_instruction_bits_instruction[31],
                         io_instruction_bits_instruction[31:12]}
                      : 21'h0;	// src/main/scala/Frontend/decoder.scala:40:7, :55:34, :58:34, src/main/scala/utils.scala:119:{30,48,59}, :120:30, :121:30, :122:30, :124:{30,48,59,77,88}, :128:17, :132:42, :133:42, :134:42, :135:42, :138:{17,25}, :140:24, :143:40, :144:40, :145:40, :146:40, :149:{18,26}, :150:24, :153:44, :154:18, :155:{17,25}, :156:22, :159:44, :164:{17,25}, :165:22, :168:44, :172:{17,25}, :174:17
  assign io_decoded_instruction_bits_FUNCT3 = io_instruction_bits_instruction[14:12];	// src/main/scala/Frontend/decoder.scala:40:7, :61:34
  assign io_decoded_instruction_bits_packet_index = io_instruction_bits_packet_index[1:0];	// src/main/scala/Frontend/decoder.scala:40:7, :158:54
  assign io_decoded_instruction_bits_instructionType = instructionType;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56
  assign io_decoded_instruction_bits_portID =
    needs_ALU
      ? next_ALU_port_0
      : needs_branch_unit
          ? 2'h0
          : _is_INT_T
            & (io_instruction_bits_instruction[14:12] == 3'h4
               | io_instruction_bits_instruction[14:12] == 3'h5
               | io_instruction_bits_instruction[14:12] == 3'h6
               | (&(io_instruction_bits_instruction[14:12])))
            & io_instruction_bits_instruction[25]
              ? 2'h1
              : {2{_is_MEM_T_1 | _is_MEM_T}};	// src/main/scala/Frontend/decoder.scala:40:7, :61:34, :62:34, :65:56, :83:{59,71,81,91,101,111,121,131,142,151}, :84:{63,92}, :87:80, :88:{63,92}, :156:62, :174:32, :176:20, :177:44, :181:34, :182:44, :183:27, :185:30, :186:44, :187:29, :188:44, :190:44
  assign io_decoded_instruction_bits_RS_type =
    _is_INT_T | _is_INT_T_1 | _is_INT_T_3 | _is_INT_T_5 | _is_INT_T_7 | _is_INT_T_9
    | _is_INT_T_11
      ? 2'h0
      : _is_MEM_T | _is_MEM_T_1 ? 2'h1 : 2'h2;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :196:{47,79,111,140,170,199}, :197:49, :199:17, :200:46, :201:23, :202:46, :204:46
  assign io_decoded_instruction_bits_needs_ALU = needs_ALU;	// src/main/scala/Frontend/decoder.scala:40:7, :87:80, :88:{63,92}
  assign io_decoded_instruction_bits_needs_branch_unit = needs_branch_unit;	// src/main/scala/Frontend/decoder.scala:40:7, :84:{63,92}
  assign io_decoded_instruction_bits_SUBTRACT =
    (_is_INT_T | _is_INT_T_1) & _needs_ALU_T_1;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :73:{50,81,91}
  assign io_decoded_instruction_bits_MULTIPLY =
    _is_INT_T & io_instruction_bits_instruction[31:25] == 7'h1;	// src/main/scala/Frontend/decoder.scala:40:7, :62:34, :65:56, :72:{49,59}
  assign io_decoded_instruction_bits_IS_IMM =
    _is_INT_T_1 | _is_INT_T_9 | _is_INT_T_11 | _is_MEM_T_1 | _is_MEM_T | _is_INT_T_3
    | _is_INT_T_5 | _is_INT_T_7;	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :74:54, :75:51, :76:53, :77:53, :78:52, :79:54, :80:51
  assign io_decoded_instruction_bits_memory_type = _is_MEM_T ? 2'h1 : {_is_MEM_T_1, 1'h0};	// src/main/scala/Frontend/decoder.scala:40:7, :65:56, :138:35, :139:62, :140:42, :141:62, :143:62
  assign io_decoded_instruction_bits_access_width =
    io_instruction_bits_instruction[14:12] == 3'h0
      ? 2'h1
      : io_instruction_bits_instruction[14:12] == 3'h1
          ? 2'h2
          : {2{io_instruction_bits_instruction[14:12] == 3'h2}};	// src/main/scala/Frontend/decoder.scala:40:7, :61:34, :146:63, :147:{18,31}, :148:63, :149:{24,37}, :150:63, :151:{24,37}, :152:63
endmodule


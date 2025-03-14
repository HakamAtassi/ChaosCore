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
module branch_unit(	// src/main/scala/Backend/FU.scala:242:7
  input         clock,	// src/main/scala/Backend/FU.scala:242:7
                io_flush,	// src/main/scala/Backend/FU.scala:245:16
                io_FU_input_valid,	// src/main/scala/Backend/FU.scala:245:16
  input  [6:0]  io_FU_input_bits_decoded_instruction_RD,	// src/main/scala/Backend/FU.scala:245:16
  input         io_FU_input_bits_decoded_instruction_RD_valid,	// src/main/scala/Backend/FU.scala:245:16
  input  [20:0] io_FU_input_bits_decoded_instruction_IMM,	// src/main/scala/Backend/FU.scala:245:16
  input  [2:0]  io_FU_input_bits_decoded_instruction_FUNCT3,	// src/main/scala/Backend/FU.scala:245:16
  input  [1:0]  io_FU_input_bits_decoded_instruction_packet_index,	// src/main/scala/Backend/FU.scala:245:16
  input  [5:0]  io_FU_input_bits_decoded_instruction_ROB_index,	// src/main/scala/Backend/FU.scala:245:16
  input  [3:0]  io_FU_input_bits_decoded_instruction_MOB_index,	// src/main/scala/Backend/FU.scala:245:16
                io_FU_input_bits_decoded_instruction_FTQ_index,	// src/main/scala/Backend/FU.scala:245:16
  input  [4:0]  io_FU_input_bits_decoded_instruction_instructionType,	// src/main/scala/Backend/FU.scala:245:16
  input  [31:0] io_FU_input_bits_RS1_data,	// src/main/scala/Backend/FU.scala:245:16
                io_FU_input_bits_RS2_data,	// src/main/scala/Backend/FU.scala:245:16
                io_FU_input_bits_fetch_PC,	// src/main/scala/Backend/FU.scala:245:16
  output        io_FU_output_valid,	// src/main/scala/Backend/FU.scala:245:16
  output [6:0]  io_FU_output_bits_RD,	// src/main/scala/Backend/FU.scala:245:16
  output [31:0] io_FU_output_bits_RD_data,	// src/main/scala/Backend/FU.scala:245:16
  output        io_FU_output_bits_RD_valid,	// src/main/scala/Backend/FU.scala:245:16
  output [31:0] io_FU_output_bits_fetch_PC,	// src/main/scala/Backend/FU.scala:245:16
  output        io_FU_output_bits_branch_taken,	// src/main/scala/Backend/FU.scala:245:16
  output [31:0] io_FU_output_bits_target_address,	// src/main/scala/Backend/FU.scala:245:16
  output        io_FU_output_bits_branch_valid,	// src/main/scala/Backend/FU.scala:245:16
  output [3:0]  io_FU_output_bits_MOB_index,	// src/main/scala/Backend/FU.scala:245:16
  output [5:0]  io_FU_output_bits_ROB_index,	// src/main/scala/Backend/FU.scala:245:16
  output [3:0]  io_FU_output_bits_FTQ_index,	// src/main/scala/Backend/FU.scala:245:16
  output [1:0]  io_FU_output_bits_fetch_packet_index	// src/main/scala/Backend/FU.scala:245:16
);

  reg [31:0] io_FU_output_bits_fetch_PC_REG;	// src/main/scala/Backend/FU.scala:349:56
  reg [1:0]  io_FU_output_bits_fetch_packet_index_REG;	// src/main/scala/Backend/FU.scala:350:56
  reg        io_FU_output_bits_branch_valid_REG;	// src/main/scala/Backend/FU.scala:354:53
  reg        io_FU_output_bits_branch_taken_REG;	// src/main/scala/Backend/FU.scala:357:56
  reg [31:0] io_FU_output_bits_target_address_REG;	// src/main/scala/Backend/FU.scala:358:56
  reg [6:0]  io_FU_output_bits_RD_REG;	// src/main/scala/Backend/FU.scala:361:56
  reg        io_FU_output_bits_RD_valid_REG;	// src/main/scala/Backend/FU.scala:362:56
  reg [31:0] io_FU_output_bits_RD_data_REG;	// src/main/scala/Backend/FU.scala:363:56
  reg [5:0]  io_FU_output_bits_ROB_index_REG;	// src/main/scala/Backend/FU.scala:364:56
  reg [3:0]  io_FU_output_bits_FTQ_index_REG;	// src/main/scala/Backend/FU.scala:365:56
  reg [3:0]  io_FU_output_bits_MOB_index_REG;	// src/main/scala/Backend/FU.scala:366:56
  reg        io_FU_output_valid_REG;	// src/main/scala/Backend/FU.scala:377:56
  always @(posedge clock) begin	// src/main/scala/Backend/FU.scala:242:7
    automatic logic [31:0] _instruction_PC_T_1 =
      io_FU_input_bits_fetch_PC
      + {28'h0, io_FU_input_bits_decoded_instruction_packet_index, 2'h0};	// src/main/scala/Backend/FU.scala:242:7, :267:60
    automatic logic        BRANCH =
      io_FU_input_bits_decoded_instruction_instructionType == 5'h18;	// src/main/scala/Backend/FU.scala:280:41
    automatic logic        EQ =
      io_FU_input_bits_RS1_data == io_FU_input_bits_RS2_data & BRANCH
      & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h0;	// src/main/scala/Backend/FU.scala:242:7, :280:41, :281:{68,78}, :299:{37,58}
    automatic logic        NE =
      io_FU_input_bits_RS1_data != io_FU_input_bits_RS2_data & BRANCH
      & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h1;	// src/main/scala/Backend/FU.scala:242:7, :280:41, :282:{68,78}, :300:{37,58}
    automatic logic        LT =
      $signed(io_FU_input_bits_RS1_data) < $signed(io_FU_input_bits_RS2_data) & BRANCH
      & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h4;	// src/main/scala/Backend/FU.scala:242:7, :280:41, :283:{68,78}, :301:{39,58}
    automatic logic        GE =
      $signed(io_FU_input_bits_RS1_data) >= $signed(io_FU_input_bits_RS2_data) & BRANCH
      & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h5;	// src/main/scala/Backend/FU.scala:280:41, :284:{68,78}, :302:{38,58}
    automatic logic        LTU =
      io_FU_input_bits_RS1_data < io_FU_input_bits_RS2_data & BRANCH
      & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h6;	// src/main/scala/Backend/FU.scala:280:41, :285:{68,78}, :303:{39,58}
    automatic logic        GEU =
      io_FU_input_bits_RS1_data >= io_FU_input_bits_RS2_data & BRANCH
      & (&io_FU_input_bits_decoded_instruction_FUNCT3);	// src/main/scala/Backend/FU.scala:280:41, :286:{68,78}, :304:{38,58}
    automatic logic        JAL =
      io_FU_input_bits_decoded_instruction_instructionType == 5'h1B;	// src/main/scala/Backend/FU.scala:305:36
    automatic logic        JALR =
      io_FU_input_bits_decoded_instruction_instructionType == 5'h19;	// src/main/scala/Backend/FU.scala:306:36
    automatic logic [31:0] _GEN =
      {{19{io_FU_input_bits_decoded_instruction_IMM[12]}},
       io_FU_input_bits_decoded_instruction_IMM[12:0]};	// src/main/scala/Backend/FU.scala:325:{15,21}, :338:76
    io_FU_output_bits_fetch_PC_REG <= io_FU_input_bits_fetch_PC;	// src/main/scala/Backend/FU.scala:349:56
    io_FU_output_bits_fetch_packet_index_REG <=
      io_FU_input_bits_decoded_instruction_packet_index;	// src/main/scala/Backend/FU.scala:350:56
    io_FU_output_bits_branch_valid_REG <= BRANCH | JAL | JALR;	// src/main/scala/Backend/FU.scala:280:41, :305:36, :306:36, :354:{53,61,68}
    io_FU_output_bits_branch_taken_REG <= EQ | NE | LT | GE | LTU | GEU | JAL | JALR;	// src/main/scala/Backend/FU.scala:281:68, :282:68, :283:68, :284:68, :285:68, :286:68, :299:58, :300:58, :301:58, :302:58, :303:58, :304:58, :305:36, :306:36, :338:{21,35}, :339:{21,35}, :340:{21,35}, :341:{21,35}, :342:{21,35}, :343:{21,35}, :344:{21,35}, :345:21, :357:56
    io_FU_output_bits_target_address_REG <=
      EQ
        ? _instruction_PC_T_1 + _GEN
        : NE
            ? _instruction_PC_T_1 + _GEN
            : LT
                ? _instruction_PC_T_1 + _GEN
                : GE
                    ? _instruction_PC_T_1 + _GEN
                    : LTU
                        ? _instruction_PC_T_1 + _GEN
                        : GEU
                            ? _instruction_PC_T_1 + _GEN
                            : JAL
                                ? _instruction_PC_T_1
                                  + {{11{io_FU_input_bits_decoded_instruction_IMM[20]}},
                                     io_FU_input_bits_decoded_instruction_IMM}
                                : JALR
                                    ? io_FU_input_bits_RS1_data
                                      + {{20{io_FU_input_bits_decoded_instruction_IMM[11]}},
                                         io_FU_input_bits_decoded_instruction_IMM[11:0]}
                                    : io_FU_input_bits_fetch_PC + 32'h10;	// src/main/scala/Backend/FU.scala:267:60, :281:68, :282:68, :283:68, :284:68, :285:68, :286:68, :299:58, :300:58, :301:58, :302:58, :303:58, :304:58, :305:36, :306:36, :313:{21,50}, :328:15, :331:{15,21}, :338:{21,58,76}, :339:{21,58,76}, :340:{21,58,76}, :341:{21,58,76}, :342:{21,58,76}, :343:{21,58,76}, :344:{21,58,76}, :345:{21,58,76}, :358:56
    io_FU_output_bits_RD_REG <= io_FU_input_bits_decoded_instruction_RD;	// src/main/scala/Backend/FU.scala:361:56
    io_FU_output_bits_RD_valid_REG <= io_FU_input_bits_decoded_instruction_RD_valid;	// src/main/scala/Backend/FU.scala:362:56
    io_FU_output_bits_RD_data_REG <= _instruction_PC_T_1 + 32'h4;	// src/main/scala/Backend/FU.scala:267:60, :363:{56,72}
    io_FU_output_bits_ROB_index_REG <= io_FU_input_bits_decoded_instruction_ROB_index;	// src/main/scala/Backend/FU.scala:364:56
    io_FU_output_bits_FTQ_index_REG <= io_FU_input_bits_decoded_instruction_FTQ_index;	// src/main/scala/Backend/FU.scala:365:56
    io_FU_output_bits_MOB_index_REG <= io_FU_input_bits_decoded_instruction_MOB_index;	// src/main/scala/Backend/FU.scala:366:56
    io_FU_output_valid_REG <= io_FU_input_valid & ~io_flush;	// src/main/scala/Backend/FU.scala:377:{56,75,78}
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_REG_	// src/main/scala/Backend/FU.scala:242:7
    `ifdef FIRRTL_BEFORE_INITIAL	// src/main/scala/Backend/FU.scala:242:7
      `FIRRTL_BEFORE_INITIAL	// src/main/scala/Backend/FU.scala:242:7
    `endif // FIRRTL_BEFORE_INITIAL
    initial begin	// src/main/scala/Backend/FU.scala:242:7
      automatic logic [31:0] _RANDOM[0:3];	// src/main/scala/Backend/FU.scala:242:7
      `ifdef INIT_RANDOM_PROLOG_	// src/main/scala/Backend/FU.scala:242:7
        `INIT_RANDOM_PROLOG_	// src/main/scala/Backend/FU.scala:242:7
      `endif // INIT_RANDOM_PROLOG_
      `ifdef RANDOMIZE_REG_INIT	// src/main/scala/Backend/FU.scala:242:7
        for (logic [2:0] i = 3'h0; i < 3'h4; i += 3'h1) begin
          _RANDOM[i[1:0]] = `RANDOM;	// src/main/scala/Backend/FU.scala:242:7
        end	// src/main/scala/Backend/FU.scala:242:7
        io_FU_output_bits_fetch_PC_REG = _RANDOM[2'h0];	// src/main/scala/Backend/FU.scala:242:7, :349:56
        io_FU_output_bits_fetch_packet_index_REG = _RANDOM[2'h1][1:0];	// src/main/scala/Backend/FU.scala:242:7, :350:56
        io_FU_output_bits_branch_valid_REG = _RANDOM[2'h1][2];	// src/main/scala/Backend/FU.scala:242:7, :350:56, :354:53
        io_FU_output_bits_branch_taken_REG = _RANDOM[2'h1][3];	// src/main/scala/Backend/FU.scala:242:7, :350:56, :357:56
        io_FU_output_bits_target_address_REG = {_RANDOM[2'h1][31:4], _RANDOM[2'h2][3:0]};	// src/main/scala/Backend/FU.scala:242:7, :350:56, :358:56
        io_FU_output_bits_RD_REG = _RANDOM[2'h2][10:4];	// src/main/scala/Backend/FU.scala:242:7, :358:56, :361:56
        io_FU_output_bits_RD_valid_REG = _RANDOM[2'h2][11];	// src/main/scala/Backend/FU.scala:242:7, :358:56, :362:56
        io_FU_output_bits_RD_data_REG = {_RANDOM[2'h2][31:12], _RANDOM[2'h3][11:0]};	// src/main/scala/Backend/FU.scala:242:7, :358:56, :363:56
        io_FU_output_bits_ROB_index_REG = _RANDOM[2'h3][17:12];	// src/main/scala/Backend/FU.scala:242:7, :363:56, :364:56
        io_FU_output_bits_FTQ_index_REG = _RANDOM[2'h3][21:18];	// src/main/scala/Backend/FU.scala:242:7, :363:56, :365:56
        io_FU_output_bits_MOB_index_REG = _RANDOM[2'h3][25:22];	// src/main/scala/Backend/FU.scala:242:7, :363:56, :366:56
        io_FU_output_valid_REG = _RANDOM[2'h3][26];	// src/main/scala/Backend/FU.scala:242:7, :363:56, :377:56
      `endif // RANDOMIZE_REG_INIT
    end // initial
    `ifdef FIRRTL_AFTER_INITIAL	// src/main/scala/Backend/FU.scala:242:7
      `FIRRTL_AFTER_INITIAL	// src/main/scala/Backend/FU.scala:242:7
    `endif // FIRRTL_AFTER_INITIAL
  `endif // ENABLE_INITIAL_REG_
  assign io_FU_output_valid = io_FU_output_valid_REG;	// src/main/scala/Backend/FU.scala:242:7, :377:56
  assign io_FU_output_bits_RD = io_FU_output_bits_RD_REG;	// src/main/scala/Backend/FU.scala:242:7, :361:56
  assign io_FU_output_bits_RD_data = io_FU_output_bits_RD_data_REG;	// src/main/scala/Backend/FU.scala:242:7, :363:56
  assign io_FU_output_bits_RD_valid = io_FU_output_bits_RD_valid_REG;	// src/main/scala/Backend/FU.scala:242:7, :362:56
  assign io_FU_output_bits_fetch_PC = io_FU_output_bits_fetch_PC_REG;	// src/main/scala/Backend/FU.scala:242:7, :349:56
  assign io_FU_output_bits_branch_taken = io_FU_output_bits_branch_taken_REG;	// src/main/scala/Backend/FU.scala:242:7, :357:56
  assign io_FU_output_bits_target_address = io_FU_output_bits_target_address_REG;	// src/main/scala/Backend/FU.scala:242:7, :358:56
  assign io_FU_output_bits_branch_valid = io_FU_output_bits_branch_valid_REG;	// src/main/scala/Backend/FU.scala:242:7, :354:53
  assign io_FU_output_bits_MOB_index = io_FU_output_bits_MOB_index_REG;	// src/main/scala/Backend/FU.scala:242:7, :366:56
  assign io_FU_output_bits_ROB_index = io_FU_output_bits_ROB_index_REG;	// src/main/scala/Backend/FU.scala:242:7, :364:56
  assign io_FU_output_bits_FTQ_index = io_FU_output_bits_FTQ_index_REG;	// src/main/scala/Backend/FU.scala:242:7, :365:56
  assign io_FU_output_bits_fetch_packet_index = io_FU_output_bits_fetch_packet_index_REG;	// src/main/scala/Backend/FU.scala:242:7, :350:56
endmodule


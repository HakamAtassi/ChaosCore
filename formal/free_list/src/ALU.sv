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

module ALU(
  input         clock,
                reset,
                io_flush,
                io_FU_input_valid,
  input  [6:0]  io_FU_input_bits_decoded_instruction_PRD,
  input         io_FU_input_bits_decoded_instruction_RD_valid,
  input  [20:0] io_FU_input_bits_decoded_instruction_IMM,
  input  [2:0]  io_FU_input_bits_decoded_instruction_FUNCT3,
  input  [1:0]  io_FU_input_bits_decoded_instruction_packet_index,
  input  [5:0]  io_FU_input_bits_decoded_instruction_ROB_index,
  input  [3:0]  io_FU_input_bits_decoded_instruction_MOB_index,
  input  [4:0]  io_FU_input_bits_decoded_instruction_instructionType,
  input         io_FU_input_bits_decoded_instruction_SUBTRACT,
                io_FU_input_bits_decoded_instruction_MULTIPLY,
                io_FU_input_bits_decoded_instruction_IS_IMM,
  input  [31:0] io_FU_input_bits_RS1_data,
                io_FU_input_bits_RS2_data,
                io_FU_input_bits_fetch_PC,
  output        io_FU_output_valid,
  output [6:0]  io_FU_output_bits_PRD,
  output [31:0] io_FU_output_bits_RD_data,
  output        io_FU_output_bits_RD_valid,
  output [31:0] io_FU_output_bits_fetch_PC,
  output [3:0]  io_FU_output_bits_MOB_index,
  output [5:0]  io_FU_output_bits_ROB_index,
  output [1:0]  io_FU_output_bits_fetch_packet_index
);

  reg [31:0] arithmetic_result;
  reg [31:0] io_FU_output_bits_fetch_PC_REG;
  reg [1:0]  io_FU_output_bits_fetch_packet_index_REG;
  reg [6:0]  io_FU_output_bits_PRD_REG;
  reg        io_FU_output_bits_RD_valid_REG;
  reg [3:0]  io_FU_output_bits_MOB_index_REG;
  reg [5:0]  io_FU_output_bits_ROB_index_REG;
  reg        io_FU_output_valid_REG;
  always @(posedge clock) begin
    if (reset)
      arithmetic_result <= 32'h0;
    else begin
      automatic logic [31:0] IMM_signed =
        {{19{io_FU_input_bits_decoded_instruction_IMM[12]}},
         io_FU_input_bits_decoded_instruction_IMM[12:0]};
      automatic logic [31:0] operand2_unsigned =
        io_FU_input_bits_decoded_instruction_IS_IMM
          ? IMM_signed
          : io_FU_input_bits_RS2_data;
      automatic logic [4:0]  shamt =
        (|(operand2_unsigned[31:5])) ? 5'h0 : operand2_unsigned[4:0];
      automatic logic [31:0] _GEN = {27'h0, shamt};
      automatic logic        _REMU_T =
        io_FU_input_bits_decoded_instruction_instructionType == 5'hC;
      automatic logic        _SLTU_T_1 =
        io_FU_input_bits_decoded_instruction_instructionType == 5'h4;
      automatic logic        _MUL_T_1 =
        io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h0;
      automatic logic        _DIVU_T_1 =
        io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h5;
      automatic logic [62:0] _sll_result_T = {31'h0, io_FU_input_bits_RS1_data} << shamt;
      arithmetic_result <=
        (_REMU_T | _SLTU_T_1) & _MUL_T_1 & ~io_FU_input_bits_decoded_instruction_MULTIPLY
        & ~io_FU_input_bits_decoded_instruction_SUBTRACT
          ? io_FU_input_bits_RS1_data + operand2_unsigned
          : (_REMU_T | _SLTU_T_1) & _MUL_T_1
            & ~io_FU_input_bits_decoded_instruction_MULTIPLY
            & io_FU_input_bits_decoded_instruction_SUBTRACT
              ? io_FU_input_bits_RS1_data - operand2_unsigned
              : (_REMU_T | _SLTU_T_1)
                & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h4
                & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                  ? io_FU_input_bits_RS1_data ^ operand2_unsigned
                  : (_REMU_T | _SLTU_T_1)
                    & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h6
                    & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                      ? io_FU_input_bits_RS1_data | operand2_unsigned
                      : (_REMU_T | _SLTU_T_1)
                        & (&io_FU_input_bits_decoded_instruction_FUNCT3)
                        & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                          ? io_FU_input_bits_RS1_data & operand2_unsigned
                          : (_REMU_T | _SLTU_T_1)
                            & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h1
                            & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                              ? _sll_result_T[31:0]
                              : (_REMU_T | _SLTU_T_1) & _DIVU_T_1
                                & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                                & ~io_FU_input_bits_decoded_instruction_SUBTRACT
                                  ? io_FU_input_bits_RS1_data >> _GEN
                                  : (_REMU_T | _SLTU_T_1) & _DIVU_T_1
                                    & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                                    & io_FU_input_bits_decoded_instruction_SUBTRACT
                                      ? $signed($signed(io_FU_input_bits_RS1_data)
                                                >>> _GEN)
                                      : (_REMU_T | _SLTU_T_1)
                                        & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h2
                                        & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                                          ? {31'h0,
                                             $signed(io_FU_input_bits_RS1_data) < $signed(io_FU_input_bits_decoded_instruction_IS_IMM
                                                                                            ? IMM_signed
                                                                                            : io_FU_input_bits_RS2_data)}
                                          : (_REMU_T | _SLTU_T_1)
                                            & io_FU_input_bits_decoded_instruction_FUNCT3 == 3'h3
                                            & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                                              ? {31'h0,
                                                 io_FU_input_bits_RS1_data < operand2_unsigned}
                                              : io_FU_input_bits_decoded_instruction_instructionType == 5'hD
                                                & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                                                  ? {io_FU_input_bits_decoded_instruction_IMM[19:0],
                                                     12'h0}
                                                  : io_FU_input_bits_decoded_instruction_instructionType == 5'h5
                                                    & ~io_FU_input_bits_decoded_instruction_MULTIPLY
                                                      ? io_FU_input_bits_fetch_PC
                                                        + {28'h0,
                                                           io_FU_input_bits_decoded_instruction_packet_index,
                                                           2'h0}
                                                        + {io_FU_input_bits_decoded_instruction_IMM[19:0],
                                                           12'h0}
                                                      : 32'h0;
    end
    io_FU_output_bits_fetch_PC_REG <= io_FU_input_bits_fetch_PC;
    io_FU_output_bits_fetch_packet_index_REG <=
      io_FU_input_bits_decoded_instruction_packet_index;
    io_FU_output_bits_PRD_REG <= io_FU_input_bits_decoded_instruction_PRD;
    io_FU_output_bits_RD_valid_REG <= io_FU_input_bits_decoded_instruction_RD_valid;
    io_FU_output_bits_MOB_index_REG <= io_FU_input_bits_decoded_instruction_MOB_index;
    io_FU_output_bits_ROB_index_REG <= io_FU_input_bits_decoded_instruction_ROB_index;
    io_FU_output_valid_REG <= io_FU_input_valid & ~io_flush;
  end // always @(posedge)
  assign io_FU_output_valid = io_FU_output_valid_REG;
  assign io_FU_output_bits_PRD = io_FU_output_bits_PRD_REG;
  assign io_FU_output_bits_RD_data = arithmetic_result;
  assign io_FU_output_bits_RD_valid = io_FU_output_bits_RD_valid_REG;
  assign io_FU_output_bits_fetch_PC = io_FU_output_bits_fetch_PC_REG;
  assign io_FU_output_bits_MOB_index = io_FU_output_bits_MOB_index_REG;
  assign io_FU_output_bits_ROB_index = io_FU_output_bits_ROB_index_REG;
  assign io_FU_output_bits_fetch_packet_index = io_FU_output_bits_fetch_packet_index_REG;
endmodule

// Generated by CIRCT firtool-1.62.0
module decoder(
  input         clock,
                reset,
  input  [31:0] io_instruction_instruction,
  input  [3:0]  io_instruction_packet_index,
  input  [5:0]  io_instruction_ROB_index,
  output        io_decoded_instruction_RD_valid,
  output [5:0]  io_decoded_instruction_RD,
                io_decoded_instruction_RS1,
                io_decoded_instruction_RS2,
  output [31:0] io_decoded_instruction_IMM,
  output [2:0]  io_decoded_instruction_FUNCT3,
  output [3:0]  io_decoded_instruction_packet_index,
  output [5:0]  io_decoded_instruction_ROB_index,
  output [4:0]  io_decoded_instruction_instructionType,
  output [1:0]  io_decoded_instruction_portID,
                io_decoded_instruction_RS_type,
  output        io_decoded_instruction_needs_ALU,
                io_decoded_instruction_needs_branch_unit,
                io_decoded_instruction_SUBTRACT,
                io_decoded_instruction_MULTIPLY,
                io_decoded_instruction_IMMEDIATE
);

  wire       _is_INT_T = io_instruction_instruction[6:2] == 5'hC;
  wire       IMMEDIATE = io_instruction_instruction[6:2] == 5'h4;
  wire       _is_INT_T_3 = io_instruction_instruction[6:2] == 5'h18;
  wire       _is_INT_T_5 = io_instruction_instruction[6:2] == 5'h1B;
  wire       _is_INT_T_7 = io_instruction_instruction[6:2] == 5'h19;
  wire       needs_branch_unit = _is_INT_T_3 | _is_INT_T_5 | _is_INT_T_7;
  wire       needs_ALU =
    _is_INT_T
    & (io_instruction_instruction[27] | io_instruction_instruction[31:25] == 7'h0)
    | IMMEDIATE;
  wire       _is_MEM_T_1 = io_instruction_instruction[6:2] == 5'h8;
  wire       _is_MEM_T = io_instruction_instruction[6:2] == 5'h0;
  reg  [1:0] ALU_port;
  always @(posedge clock) begin
    if (reset)
      ALU_port <= 2'h0;
    else if (needs_ALU) begin
      if (ALU_port == 2'h2)
        ALU_port <= 2'h0;
      else
        ALU_port <= ALU_port + 2'h1;
    end
  end // always @(posedge)
  assign io_decoded_instruction_RD_valid = 1'h0;
  assign io_decoded_instruction_RD = {1'h0, io_instruction_instruction[11:7]};
  assign io_decoded_instruction_RS1 = {1'h0, io_instruction_instruction[19:15]};
  assign io_decoded_instruction_RS2 = {1'h0, io_instruction_instruction[24:20]};
  assign io_decoded_instruction_IMM =
    io_instruction_instruction[6:0] == 7'h63
      ? {19'h0, io_instruction_instruction[31:25], io_instruction_instruction[11:7], 1'h0}
      : io_instruction_instruction[6:0] == 7'h6F
          ? {11'h0,
             io_instruction_instruction[31],
             io_instruction_instruction[19:12],
             io_instruction_instruction[20],
             io_instruction_instruction[30:21],
             1'h0}
          : io_instruction_instruction[6:0] == 7'h13
            | io_instruction_instruction[6:0] == 7'h3
            | io_instruction_instruction[6:0] == 7'h67
              ? io_instruction_instruction
              : io_instruction_instruction[6:0] == 7'h23
                  ? {20'h0,
                     io_instruction_instruction[31:25],
                     io_instruction_instruction[11:7]}
                  : io_instruction_instruction[6:0] == 7'h33
                      ? {io_instruction_instruction[31:12], 12'h0}
                      : 32'h0;
  assign io_decoded_instruction_FUNCT3 = io_instruction_instruction[14:12];
  assign io_decoded_instruction_packet_index = io_instruction_packet_index;
  assign io_decoded_instruction_ROB_index = io_instruction_ROB_index;
  assign io_decoded_instruction_instructionType = io_instruction_instruction[6:2];
  assign io_decoded_instruction_portID =
    needs_ALU
      ? ALU_port
      : _is_INT_T
        & (io_instruction_instruction[14:12] == 3'h4
           | io_instruction_instruction[14:12] == 3'h5
           | io_instruction_instruction[14:12] == 3'h6
           | (&(io_instruction_instruction[14:12]))) & io_instruction_instruction[25]
          ? 2'h1
          : needs_branch_unit ? 2'h0 : {2{_is_MEM_T_1 | _is_MEM_T}};
  assign io_decoded_instruction_RS_type =
    _is_INT_T | IMMEDIATE | _is_INT_T_3 | _is_INT_T_5 | _is_INT_T_7
      ? 2'h0
      : _is_MEM_T | _is_MEM_T_1 ? 2'h1 : 2'h2;
  assign io_decoded_instruction_needs_ALU = needs_ALU;
  assign io_decoded_instruction_needs_branch_unit = needs_branch_unit;
  assign io_decoded_instruction_SUBTRACT = _is_INT_T & io_instruction_instruction[27];
  assign io_decoded_instruction_MULTIPLY = _is_INT_T & io_instruction_instruction[25];
  assign io_decoded_instruction_IMMEDIATE = IMMEDIATE;
endmodule

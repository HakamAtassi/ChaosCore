// Generated by CIRCT firtool-1.62.0
module branch_decoder(
  input  [31:0] io_fetch_PC,
                io_instruction,
  input         io_valid,
                io_BTB_resp_hit,
  input  [3:0]  io_BTB_resp_idx,
  input  [31:0] io_BTB_resp_RAS,
                io_BTB_resp_target,
  output        io_T_NT,
                io_metadata_JAL,
                io_metadata_JALR,
                io_metadata_BR,
                io_metadata_Call,
                io_metadata_Ret,
  output [31:0] io_metadata_Imm,
                io_metadata_instruction_PC,
                io_metadata_RAS,
                io_metadata_BTB_target
);

  wire [31:0] imm;
  wire        JAL = io_instruction[6:0] == 7'h6F;
  wire        JALR = io_instruction[6:0] == 7'h67;
  wire        BR = io_instruction[6:0] == 7'h63;
  wire        _Call_T_2 = io_instruction[11:7] == 5'h1;
  wire        Ret = JALR & io_instruction[19:15] == 5'h1 & imm[19:0] == 20'h0;
  assign imm =
    BR
      ? {20'h0,
         io_instruction[31],
         io_instruction[7],
         io_instruction[30:25],
         io_instruction[11:8]}
      : JAL
          ? {12'h0,
             io_instruction[31],
             io_instruction[19:12],
             io_instruction[20],
             io_instruction[30:21]}
          : JALR ? {20'h0, io_instruction[31:20]} : 32'h0;
  assign io_T_NT =
    JAL
      ? io_valid
      : JALR
          ? io_valid & (Ret | io_BTB_resp_hit & io_BTB_resp_idx[0])
          : BR & io_valid & io_BTB_resp_idx[0];
  assign io_metadata_JAL = JAL;
  assign io_metadata_JALR = JALR;
  assign io_metadata_BR = BR;
  assign io_metadata_Call = JAL & _Call_T_2 | JALR & _Call_T_2;
  assign io_metadata_Ret = Ret;
  assign io_metadata_Imm = imm;
  assign io_metadata_instruction_PC = io_fetch_PC;
  assign io_metadata_RAS = io_BTB_resp_RAS;
  assign io_metadata_BTB_target = io_BTB_resp_target;
endmodule

module branch_decoder_1(
  input  [31:0] io_fetch_PC,
                io_instruction,
  input         io_valid,
                io_BTB_resp_hit,
  input  [3:0]  io_BTB_resp_idx,
  input  [31:0] io_BTB_resp_RAS,
                io_BTB_resp_target,
  output        io_T_NT,
                io_metadata_JAL,
                io_metadata_JALR,
                io_metadata_BR,
                io_metadata_Call,
                io_metadata_Ret,
  output [31:0] io_metadata_Imm,
                io_metadata_instruction_PC,
                io_metadata_RAS,
                io_metadata_BTB_target
);

  wire [31:0] imm;
  wire        JAL = io_instruction[6:0] == 7'h6F;
  wire        JALR = io_instruction[6:0] == 7'h67;
  wire        BR = io_instruction[6:0] == 7'h63;
  wire        _Call_T_2 = io_instruction[11:7] == 5'h1;
  wire        Ret = JALR & io_instruction[19:15] == 5'h1 & imm[19:0] == 20'h0;
  assign imm =
    BR
      ? {20'h0,
         io_instruction[31],
         io_instruction[7],
         io_instruction[30:25],
         io_instruction[11:8]}
      : JAL
          ? {12'h0,
             io_instruction[31],
             io_instruction[19:12],
             io_instruction[20],
             io_instruction[30:21]}
          : JALR ? {20'h0, io_instruction[31:20]} : 32'h0;
  assign io_T_NT =
    JAL
      ? io_valid
      : JALR
          ? io_valid & (Ret | io_BTB_resp_hit & io_BTB_resp_idx[1])
          : BR & io_valid & io_BTB_resp_idx[1];
  assign io_metadata_JAL = JAL;
  assign io_metadata_JALR = JALR;
  assign io_metadata_BR = BR;
  assign io_metadata_Call = JAL & _Call_T_2 | JALR & _Call_T_2;
  assign io_metadata_Ret = Ret;
  assign io_metadata_Imm = imm;
  assign io_metadata_instruction_PC = io_fetch_PC + 32'h4;
  assign io_metadata_RAS = io_BTB_resp_RAS;
  assign io_metadata_BTB_target = io_BTB_resp_target;
endmodule

module branch_decoder_2(
  input  [31:0] io_fetch_PC,
                io_instruction,
  input         io_valid,
                io_BTB_resp_hit,
  input  [3:0]  io_BTB_resp_idx,
  input  [31:0] io_BTB_resp_RAS,
                io_BTB_resp_target,
  output        io_T_NT,
                io_metadata_JAL,
                io_metadata_JALR,
                io_metadata_BR,
                io_metadata_Call,
                io_metadata_Ret,
  output [31:0] io_metadata_Imm,
                io_metadata_instruction_PC,
                io_metadata_RAS,
                io_metadata_BTB_target
);

  wire [31:0] imm;
  wire        JAL = io_instruction[6:0] == 7'h6F;
  wire        JALR = io_instruction[6:0] == 7'h67;
  wire        BR = io_instruction[6:0] == 7'h63;
  wire        _Call_T_2 = io_instruction[11:7] == 5'h1;
  wire        Ret = JALR & io_instruction[19:15] == 5'h1 & imm[19:0] == 20'h0;
  assign imm =
    BR
      ? {20'h0,
         io_instruction[31],
         io_instruction[7],
         io_instruction[30:25],
         io_instruction[11:8]}
      : JAL
          ? {12'h0,
             io_instruction[31],
             io_instruction[19:12],
             io_instruction[20],
             io_instruction[30:21]}
          : JALR ? {20'h0, io_instruction[31:20]} : 32'h0;
  assign io_T_NT =
    JAL
      ? io_valid
      : JALR
          ? io_valid & (Ret | io_BTB_resp_hit & io_BTB_resp_idx[2])
          : BR & io_valid & io_BTB_resp_idx[2];
  assign io_metadata_JAL = JAL;
  assign io_metadata_JALR = JALR;
  assign io_metadata_BR = BR;
  assign io_metadata_Call = JAL & _Call_T_2 | JALR & _Call_T_2;
  assign io_metadata_Ret = Ret;
  assign io_metadata_Imm = imm;
  assign io_metadata_instruction_PC = io_fetch_PC + 32'h8;
  assign io_metadata_RAS = io_BTB_resp_RAS;
  assign io_metadata_BTB_target = io_BTB_resp_target;
endmodule

module branch_decoder_3(
  input  [31:0] io_fetch_PC,
                io_instruction,
  input         io_valid,
                io_BTB_resp_hit,
  input  [3:0]  io_BTB_resp_idx,
  input  [31:0] io_BTB_resp_RAS,
                io_BTB_resp_target,
  output        io_T_NT,
                io_metadata_JAL,
                io_metadata_JALR,
                io_metadata_BR,
                io_metadata_Call,
                io_metadata_Ret,
  output [31:0] io_metadata_Imm,
                io_metadata_instruction_PC,
                io_metadata_RAS,
                io_metadata_BTB_target
);

  wire [31:0] imm;
  wire        JAL = io_instruction[6:0] == 7'h6F;
  wire        JALR = io_instruction[6:0] == 7'h67;
  wire        BR = io_instruction[6:0] == 7'h63;
  wire        _Call_T_2 = io_instruction[11:7] == 5'h1;
  wire        Ret = JALR & io_instruction[19:15] == 5'h1 & imm[19:0] == 20'h0;
  assign imm =
    BR
      ? {20'h0,
         io_instruction[31],
         io_instruction[7],
         io_instruction[30:25],
         io_instruction[11:8]}
      : JAL
          ? {12'h0,
             io_instruction[31],
             io_instruction[19:12],
             io_instruction[20],
             io_instruction[30:21]}
          : JALR ? {20'h0, io_instruction[31:20]} : 32'h0;
  assign io_T_NT =
    JAL
      ? io_valid
      : JALR
          ? io_valid & (Ret | io_BTB_resp_hit & io_BTB_resp_idx[3])
          : BR & io_valid & io_BTB_resp_idx[3];
  assign io_metadata_JAL = JAL;
  assign io_metadata_JALR = JALR;
  assign io_metadata_BR = BR;
  assign io_metadata_Call = JAL & _Call_T_2 | JALR & _Call_T_2;
  assign io_metadata_Ret = Ret;
  assign io_metadata_Imm = imm;
  assign io_metadata_instruction_PC = io_fetch_PC + 32'hC;
  assign io_metadata_RAS = io_BTB_resp_RAS;
  assign io_metadata_BTB_target = io_BTB_resp_target;
endmodule

module decode_validate(
  input         clock,
                reset,
                io_BTB_resp_hit,
  input  [3:0]  io_BTB_resp_idx,
  input         io_BTB_resp_T_NT,
  input  [31:0] io_BTB_resp_RAS,
                io_BTB_resp_target,
  input  [15:0] io_BTB_resp_GHR,
  input  [31:0] io_fetch_packet_fetch_PC,
                io_fetch_packet_instructions_0,
                io_fetch_packet_instructions_1,
                io_fetch_packet_instructions_2,
                io_fetch_packet_instructions_3,
  input         io_fetch_packet_valid_bits_0,
                io_fetch_packet_valid_bits_1,
                io_fetch_packet_valid_bits_2,
                io_fetch_packet_valid_bits_3,
                io_input_valid,
  output        io_kill,
                io_redirect,
  output [31:0] io_PC_redirect,
  output [15:0] io_GHR_redirect,
  output [31:0] io_final_fetch_packet_fetch_PC,
                io_final_fetch_packet_instructions_0,
                io_final_fetch_packet_instructions_1,
                io_final_fetch_packet_instructions_2,
                io_final_fetch_packet_instructions_3,
  output        io_final_fetch_packet_valid_bits_0,
                io_final_fetch_packet_valid_bits_1,
                io_final_fetch_packet_valid_bits_2,
                io_final_fetch_packet_valid_bits_3,
                io_call_valid,
  output [31:0] io_call_addr,
  output        io_ret_valid
);

  wire        validate_flag;
  wire [31:0] PC_next;
  wire [31:0] PC_expected;
  wire        _decoders_3_io_T_NT;
  wire        _decoders_3_io_metadata_JAL;
  wire        _decoders_3_io_metadata_JALR;
  wire        _decoders_3_io_metadata_BR;
  wire        _decoders_3_io_metadata_Call;
  wire        _decoders_3_io_metadata_Ret;
  wire [31:0] _decoders_3_io_metadata_Imm;
  wire [31:0] _decoders_3_io_metadata_instruction_PC;
  wire [31:0] _decoders_3_io_metadata_RAS;
  wire [31:0] _decoders_3_io_metadata_BTB_target;
  wire        _decoders_2_io_T_NT;
  wire        _decoders_2_io_metadata_JAL;
  wire        _decoders_2_io_metadata_JALR;
  wire        _decoders_2_io_metadata_BR;
  wire        _decoders_2_io_metadata_Call;
  wire        _decoders_2_io_metadata_Ret;
  wire [31:0] _decoders_2_io_metadata_Imm;
  wire [31:0] _decoders_2_io_metadata_instruction_PC;
  wire [31:0] _decoders_2_io_metadata_RAS;
  wire [31:0] _decoders_2_io_metadata_BTB_target;
  wire        _decoders_1_io_T_NT;
  wire        _decoders_1_io_metadata_JAL;
  wire        _decoders_1_io_metadata_JALR;
  wire        _decoders_1_io_metadata_BR;
  wire        _decoders_1_io_metadata_Call;
  wire        _decoders_1_io_metadata_Ret;
  wire [31:0] _decoders_1_io_metadata_Imm;
  wire [31:0] _decoders_1_io_metadata_instruction_PC;
  wire [31:0] _decoders_1_io_metadata_RAS;
  wire [31:0] _decoders_1_io_metadata_BTB_target;
  wire        _decoders_0_io_T_NT;
  wire        _decoders_0_io_metadata_JAL;
  wire        _decoders_0_io_metadata_JALR;
  wire        _decoders_0_io_metadata_BR;
  wire        _decoders_0_io_metadata_Call;
  wire        _decoders_0_io_metadata_Ret;
  wire [31:0] _decoders_0_io_metadata_Imm;
  wire [31:0] _decoders_0_io_metadata_instruction_PC;
  wire [31:0] _decoders_0_io_metadata_RAS;
  wire [31:0] _decoders_0_io_metadata_BTB_target;
  reg         metadata_reg_0_JAL;
  reg         metadata_reg_0_JALR;
  reg         metadata_reg_0_BR;
  reg         metadata_reg_0_Call;
  reg         metadata_reg_0_Ret;
  reg  [31:0] metadata_reg_0_Imm;
  reg  [31:0] metadata_reg_0_instruction_PC;
  reg  [31:0] metadata_reg_0_RAS;
  reg  [31:0] metadata_reg_0_BTB_target;
  reg         metadata_reg_1_JAL;
  reg         metadata_reg_1_JALR;
  reg         metadata_reg_1_BR;
  reg         metadata_reg_1_Call;
  reg         metadata_reg_1_Ret;
  reg  [31:0] metadata_reg_1_Imm;
  reg  [31:0] metadata_reg_1_instruction_PC;
  reg  [31:0] metadata_reg_1_RAS;
  reg  [31:0] metadata_reg_1_BTB_target;
  reg         metadata_reg_2_JAL;
  reg         metadata_reg_2_JALR;
  reg         metadata_reg_2_BR;
  reg         metadata_reg_2_Call;
  reg         metadata_reg_2_Ret;
  reg  [31:0] metadata_reg_2_Imm;
  reg  [31:0] metadata_reg_2_instruction_PC;
  reg  [31:0] metadata_reg_2_RAS;
  reg  [31:0] metadata_reg_2_BTB_target;
  reg         metadata_reg_3_JAL;
  reg         metadata_reg_3_JALR;
  reg         metadata_reg_3_BR;
  reg         metadata_reg_3_Call;
  reg         metadata_reg_3_Ret;
  reg  [31:0] metadata_reg_3_Imm;
  reg  [31:0] metadata_reg_3_instruction_PC;
  reg  [31:0] metadata_reg_3_RAS;
  reg  [31:0] metadata_reg_3_BTB_target;
  reg         T_NT_reg_1;
  reg         T_NT_reg_2;
  reg         T_NT_reg_3;
  reg  [15:0] GHR_reg;
  wire        use_RAS =
    T_NT_reg_3
      ? metadata_reg_3_Ret
      : T_NT_reg_2
          ? metadata_reg_2_Ret
          : T_NT_reg_1 ? metadata_reg_1_Ret : metadata_reg_0_Ret;
  wire [31:0] metadata_out_instruction_PC =
    T_NT_reg_3
      ? metadata_reg_3_instruction_PC
      : T_NT_reg_2
          ? metadata_reg_2_instruction_PC
          : T_NT_reg_1 ? metadata_reg_1_instruction_PC : metadata_reg_0_instruction_PC;
  reg  [31:0] PC_next_reg;
  reg         FSM1_state;
  reg         FSM2_state;
  wire        PC_mismatch = PC_expected != io_fetch_packet_fetch_PC & io_input_valid;
  assign PC_expected = FSM1_state ? PC_next_reg : PC_next;
  assign PC_next =
    (T_NT_reg_3
       ? metadata_reg_3_JALR
       : T_NT_reg_2
           ? metadata_reg_2_JALR
           : T_NT_reg_1 ? metadata_reg_1_JALR : metadata_reg_0_JALR) & ~use_RAS
      ? (T_NT_reg_3
           ? metadata_reg_3_BTB_target
           : T_NT_reg_2
               ? metadata_reg_2_BTB_target
               : T_NT_reg_1 ? metadata_reg_1_BTB_target : metadata_reg_0_BTB_target)
      : use_RAS
          ? (T_NT_reg_3
               ? metadata_reg_3_RAS
               : T_NT_reg_2
                   ? metadata_reg_2_RAS
                   : T_NT_reg_1 ? metadata_reg_1_RAS : metadata_reg_0_RAS)
          : (T_NT_reg_3
               ? metadata_reg_3_BR
               : T_NT_reg_2
                   ? metadata_reg_2_BR
                   : T_NT_reg_1 ? metadata_reg_1_BR : metadata_reg_0_BR)
            | (T_NT_reg_3
                 ? metadata_reg_3_JAL
                 : T_NT_reg_2
                     ? metadata_reg_2_JAL
                     : T_NT_reg_1 ? metadata_reg_1_JAL : metadata_reg_0_JAL)
              ? metadata_out_instruction_PC
                + (T_NT_reg_3
                     ? metadata_reg_3_Imm
                     : T_NT_reg_2
                         ? metadata_reg_2_Imm
                         : T_NT_reg_1 ? metadata_reg_1_Imm : metadata_reg_0_Imm)
              : io_fetch_packet_fetch_PC + 32'h10;
  assign validate_flag =
    ~(_decoders_3_io_T_NT | _decoders_2_io_T_NT | _decoders_1_io_T_NT)
    & ~_decoders_0_io_T_NT;
  always @(posedge clock) begin
    metadata_reg_0_JAL <= _decoders_0_io_metadata_JAL;
    metadata_reg_0_JALR <= _decoders_0_io_metadata_JALR;
    metadata_reg_0_BR <= _decoders_0_io_metadata_BR;
    metadata_reg_0_Call <= _decoders_0_io_metadata_Call;
    metadata_reg_0_Ret <= _decoders_0_io_metadata_Ret;
    metadata_reg_0_Imm <= _decoders_0_io_metadata_Imm;
    metadata_reg_0_instruction_PC <= _decoders_0_io_metadata_instruction_PC;
    metadata_reg_0_RAS <= _decoders_0_io_metadata_RAS;
    metadata_reg_0_BTB_target <= _decoders_0_io_metadata_BTB_target;
    metadata_reg_1_JAL <= _decoders_1_io_metadata_JAL;
    metadata_reg_1_JALR <= _decoders_1_io_metadata_JALR;
    metadata_reg_1_BR <= _decoders_1_io_metadata_BR;
    metadata_reg_1_Call <= _decoders_1_io_metadata_Call;
    metadata_reg_1_Ret <= _decoders_1_io_metadata_Ret;
    metadata_reg_1_Imm <= _decoders_1_io_metadata_Imm;
    metadata_reg_1_instruction_PC <= _decoders_1_io_metadata_instruction_PC;
    metadata_reg_1_RAS <= _decoders_1_io_metadata_RAS;
    metadata_reg_1_BTB_target <= _decoders_1_io_metadata_BTB_target;
    metadata_reg_2_JAL <= _decoders_2_io_metadata_JAL;
    metadata_reg_2_JALR <= _decoders_2_io_metadata_JALR;
    metadata_reg_2_BR <= _decoders_2_io_metadata_BR;
    metadata_reg_2_Call <= _decoders_2_io_metadata_Call;
    metadata_reg_2_Ret <= _decoders_2_io_metadata_Ret;
    metadata_reg_2_Imm <= _decoders_2_io_metadata_Imm;
    metadata_reg_2_instruction_PC <= _decoders_2_io_metadata_instruction_PC;
    metadata_reg_2_RAS <= _decoders_2_io_metadata_RAS;
    metadata_reg_2_BTB_target <= _decoders_2_io_metadata_BTB_target;
    metadata_reg_3_JAL <= _decoders_3_io_metadata_JAL;
    metadata_reg_3_JALR <= _decoders_3_io_metadata_JALR;
    metadata_reg_3_BR <= _decoders_3_io_metadata_BR;
    metadata_reg_3_Call <= _decoders_3_io_metadata_Call;
    metadata_reg_3_Ret <= _decoders_3_io_metadata_Ret;
    metadata_reg_3_Imm <= _decoders_3_io_metadata_Imm;
    metadata_reg_3_instruction_PC <= _decoders_3_io_metadata_instruction_PC;
    metadata_reg_3_RAS <= _decoders_3_io_metadata_RAS;
    metadata_reg_3_BTB_target <= _decoders_3_io_metadata_BTB_target;
    T_NT_reg_1 <= _decoders_1_io_T_NT;
    T_NT_reg_2 <= _decoders_2_io_T_NT;
    T_NT_reg_3 <= _decoders_3_io_T_NT;
    GHR_reg <= io_BTB_resp_GHR;
    if (reset) begin
      PC_next_reg <= 32'h0;
      FSM1_state <= 1'h1;
      FSM2_state <= 1'h1;
    end
    else begin
      automatic logic PC_match;
      PC_match = PC_expected == io_fetch_packet_fetch_PC & io_input_valid;
      if (FSM1_state | io_input_valid) begin
      end
      else
        PC_next_reg <= PC_next;
      if (FSM1_state)
        FSM1_state <= ~(FSM1_state & io_input_valid) & FSM1_state;
      else
        FSM1_state <= ~io_input_valid | FSM1_state;
      if (FSM2_state)
        FSM2_state <= ~(FSM2_state & PC_match) & FSM2_state;
      else
        FSM2_state <= PC_match | FSM2_state;
    end
  end // always @(posedge)
  branch_decoder decoders_0 (
    .io_fetch_PC                (io_fetch_packet_fetch_PC),
    .io_instruction             (io_fetch_packet_instructions_0),
    .io_valid                   (io_fetch_packet_valid_bits_0),
    .io_BTB_resp_hit            (io_BTB_resp_hit),
    .io_BTB_resp_idx            (io_BTB_resp_idx),
    .io_BTB_resp_RAS            (io_BTB_resp_RAS),
    .io_BTB_resp_target         (io_BTB_resp_target),
    .io_T_NT                    (_decoders_0_io_T_NT),
    .io_metadata_JAL            (_decoders_0_io_metadata_JAL),
    .io_metadata_JALR           (_decoders_0_io_metadata_JALR),
    .io_metadata_BR             (_decoders_0_io_metadata_BR),
    .io_metadata_Call           (_decoders_0_io_metadata_Call),
    .io_metadata_Ret            (_decoders_0_io_metadata_Ret),
    .io_metadata_Imm            (_decoders_0_io_metadata_Imm),
    .io_metadata_instruction_PC (_decoders_0_io_metadata_instruction_PC),
    .io_metadata_RAS            (_decoders_0_io_metadata_RAS),
    .io_metadata_BTB_target     (_decoders_0_io_metadata_BTB_target)
  );
  branch_decoder_1 decoders_1 (
    .io_fetch_PC                (io_fetch_packet_fetch_PC),
    .io_instruction             (io_fetch_packet_instructions_1),
    .io_valid                   (io_fetch_packet_valid_bits_1),
    .io_BTB_resp_hit            (io_BTB_resp_hit),
    .io_BTB_resp_idx            (io_BTB_resp_idx),
    .io_BTB_resp_RAS            (io_BTB_resp_RAS),
    .io_BTB_resp_target         (io_BTB_resp_target),
    .io_T_NT                    (_decoders_1_io_T_NT),
    .io_metadata_JAL            (_decoders_1_io_metadata_JAL),
    .io_metadata_JALR           (_decoders_1_io_metadata_JALR),
    .io_metadata_BR             (_decoders_1_io_metadata_BR),
    .io_metadata_Call           (_decoders_1_io_metadata_Call),
    .io_metadata_Ret            (_decoders_1_io_metadata_Ret),
    .io_metadata_Imm            (_decoders_1_io_metadata_Imm),
    .io_metadata_instruction_PC (_decoders_1_io_metadata_instruction_PC),
    .io_metadata_RAS            (_decoders_1_io_metadata_RAS),
    .io_metadata_BTB_target     (_decoders_1_io_metadata_BTB_target)
  );
  branch_decoder_2 decoders_2 (
    .io_fetch_PC                (io_fetch_packet_fetch_PC),
    .io_instruction             (io_fetch_packet_instructions_2),
    .io_valid                   (io_fetch_packet_valid_bits_2),
    .io_BTB_resp_hit            (io_BTB_resp_hit),
    .io_BTB_resp_idx            (io_BTB_resp_idx),
    .io_BTB_resp_RAS            (io_BTB_resp_RAS),
    .io_BTB_resp_target         (io_BTB_resp_target),
    .io_T_NT                    (_decoders_2_io_T_NT),
    .io_metadata_JAL            (_decoders_2_io_metadata_JAL),
    .io_metadata_JALR           (_decoders_2_io_metadata_JALR),
    .io_metadata_BR             (_decoders_2_io_metadata_BR),
    .io_metadata_Call           (_decoders_2_io_metadata_Call),
    .io_metadata_Ret            (_decoders_2_io_metadata_Ret),
    .io_metadata_Imm            (_decoders_2_io_metadata_Imm),
    .io_metadata_instruction_PC (_decoders_2_io_metadata_instruction_PC),
    .io_metadata_RAS            (_decoders_2_io_metadata_RAS),
    .io_metadata_BTB_target     (_decoders_2_io_metadata_BTB_target)
  );
  branch_decoder_3 decoders_3 (
    .io_fetch_PC                (io_fetch_packet_fetch_PC),
    .io_instruction             (io_fetch_packet_instructions_3),
    .io_valid                   (io_fetch_packet_valid_bits_3),
    .io_BTB_resp_hit            (io_BTB_resp_hit),
    .io_BTB_resp_idx            (io_BTB_resp_idx),
    .io_BTB_resp_RAS            (io_BTB_resp_RAS),
    .io_BTB_resp_target         (io_BTB_resp_target),
    .io_T_NT                    (_decoders_3_io_T_NT),
    .io_metadata_JAL            (_decoders_3_io_metadata_JAL),
    .io_metadata_JALR           (_decoders_3_io_metadata_JALR),
    .io_metadata_BR             (_decoders_3_io_metadata_BR),
    .io_metadata_Call           (_decoders_3_io_metadata_Call),
    .io_metadata_Ret            (_decoders_3_io_metadata_Ret),
    .io_metadata_Imm            (_decoders_3_io_metadata_Imm),
    .io_metadata_instruction_PC (_decoders_3_io_metadata_instruction_PC),
    .io_metadata_RAS            (_decoders_3_io_metadata_RAS),
    .io_metadata_BTB_target     (_decoders_3_io_metadata_BTB_target)
  );
  assign io_kill = PC_mismatch;
  assign io_redirect = PC_mismatch;
  assign io_PC_redirect = PC_expected;
  assign io_GHR_redirect = GHR_reg;
  assign io_final_fetch_packet_fetch_PC = io_fetch_packet_fetch_PC;
  assign io_final_fetch_packet_instructions_0 = io_fetch_packet_instructions_0;
  assign io_final_fetch_packet_instructions_1 = io_fetch_packet_instructions_1;
  assign io_final_fetch_packet_instructions_2 = io_fetch_packet_instructions_2;
  assign io_final_fetch_packet_instructions_3 = io_fetch_packet_instructions_3;
  assign io_final_fetch_packet_valid_bits_0 =
    validate_flag & io_fetch_packet_valid_bits_0 & FSM2_state;
  assign io_final_fetch_packet_valid_bits_1 =
    validate_flag & io_fetch_packet_valid_bits_1 & FSM2_state;
  assign io_final_fetch_packet_valid_bits_2 =
    validate_flag & io_fetch_packet_valid_bits_2 & FSM2_state;
  assign io_final_fetch_packet_valid_bits_3 =
    validate_flag & io_fetch_packet_valid_bits_3 & FSM2_state;
  assign io_call_valid =
    T_NT_reg_3
      ? metadata_reg_3_Call
      : T_NT_reg_2
          ? metadata_reg_2_Call
          : T_NT_reg_1 ? metadata_reg_1_Call : metadata_reg_0_Call;
  assign io_call_addr = metadata_out_instruction_PC;
  assign io_ret_valid = use_RAS;
endmodule

`ifndef VERILATOR
module testbench;
  reg [4095:0] vcdfile;
  reg clock;
`else
module testbench(input clock, output reg genclock);
  initial genclock = 1;
`endif
  reg genclock = 1;
  reg [31:0] cycle = 0;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready;
  reg [0:0] PI_io_FU_outputs_2_bits_branch_valid;
  reg [6:0] PI_io_FU_outputs_2_bits_PRD;
  reg [2:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3;
  reg [20:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IMM;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid;
  reg [3:0] PI_io_FU_outputs_3_bits_MOB_index;
  reg [0:0] PI_io_partial_commit_valid_2;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_access_width;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_portID;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type;
  reg [3:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index;
  reg [0:0] PI_io_partial_commit_valid_3;
  reg [3:0] PI_io_partial_commit_MOB_index_1;
  reg [0:0] PI_io_partial_commit_MOB_valid_1;
  reg [1:0] PI_io_FU_outputs_3_bits_access_width;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT;
  reg [5:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_access_width;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU;
  reg [0:0] PI_io_decoded_fetch_packet_bits_prediction_hit;
  reg [0:0] PI_io_renamed_decoded_fetch_packet_ready;
  reg [6:0] PI_io_FU_outputs_3_bits_PRD;
  reg [0:0] PI_io_FU_outputs_3_bits_RD_valid;
  reg [2:0] PI_io_commit_bits_br_type;
  reg [0:0] PI_io_flush;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs;
  reg [0:0] PI_io_FU_outputs_2_bits_is_unsigned;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRD;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold;
  reg [6:0] PI_io_FU_outputs_1_bits_PRD;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2;
  reg [3:0] PI_io_FU_outputs_2_bits_MOB_index;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid;
  reg [6:0] PI_io_partial_commit_PRD_0;
  reg [31:0] PI_io_FU_outputs_2_bits_wr_data;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid;
  reg [5:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs;
  reg [4:0] PI_io_partial_commit_RD_2;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRD;
  reg [3:0] PI_io_partial_commit_MOB_index_2;
  reg [5:0] PI_io_FU_outputs_0_bits_ROB_index;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid;
  reg [0:0] PI_io_FU_outputs_0_bits_branch_taken;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_access_width;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid;
  reg [31:0] PI_io_FU_outputs_0_bits_wr_data;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type;
  reg [31:0] PI_io_FU_outputs_1_bits_address;
  reg [31:0] PI_io_FU_outputs_0_bits_RD_data;
  reg [0:0] PI_io_FU_outputs_2_bits_RD_valid;
  reg [0:0] PI_io_FU_outputs_3_bits_branch_valid;
  reg [6:0] PI_io_partial_commit_PRD_3;
  reg [5:0] PI_io_commit_bits_ROB_index;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRD;
  reg [31:0] PI_io_FU_outputs_3_bits_wr_data;
  reg [31:0] PI_io_decoded_fetch_packet_bits_prediction_target;
  reg [0:0] PI_io_FU_outputs_3_valid;
  reg [3:0] PI_io_FU_outputs_0_bits_MOB_index;
  reg [1:0] PI_io_FU_outputs_2_bits_access_width;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index;
  reg [2:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type;
  reg [0:0] PI_io_commit_bits_RD_valid_1;
  reg [0:0] PI_io_partial_commit_RD_valid_3;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD;
  reg [6:0] PI_io_partial_commit_PRDold_2;
  reg [31:0] PI_io_FU_outputs_3_bits_fetch_PC;
  reg [1:0] PI_io_FU_outputs_1_bits_memory_type;
  reg [0:0] PI_io_partial_commit_MOB_valid_3;
  reg [0:0] PI_io_commit_bits_RD_valid_0;
  reg [1:0] PI_io_FU_outputs_2_bits_memory_type;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready;
  reg [1:0] PI_io_FU_outputs_1_bits_access_width;
  reg [0:0] PI_io_commit_bits_T_NT;
  reg [0:0] PI_io_FU_outputs_0_bits_is_unsigned;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM;
  reg [31:0] PI_io_FU_outputs_1_bits_wr_data;
  reg [5:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index;
  reg [20:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IMM;
  reg [1:0] PI_io_FU_outputs_1_bits_fetch_packet_index;
  reg [15:0] PI_io_decoded_fetch_packet_bits_GHR;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type;
  reg [31:0] PI_io_FU_outputs_3_bits_target_address;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1;
  reg [31:0] PI_io_FU_outputs_2_bits_address;
  reg [0:0] PI_io_partial_commit_valid_1;
  reg [0:0] PI_io_FU_outputs_1_bits_branch_valid;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRD;
  reg [31:0] PI_io_FU_outputs_3_bits_address;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT;
  reg [4:0] PI_io_commit_bits_RD_2;
  reg [31:0] PI_io_FU_outputs_0_bits_address;
  reg [0:0] PI_io_FU_outputs_3_bits_is_unsigned;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid;
  reg [3:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT;
  reg [7:0] PI_io_commit_bits_free_list_front_pointer;
  reg [31:0] PI_io_commit_bits_fetch_PC;
  reg [31:0] PI_io_FU_outputs_2_bits_RD_data;
  reg [0:0] PI_io_decoded_fetch_packet_bits_valid_bits_1;
  reg [3:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index;
  reg [0:0] PI_io_commit_valid;
  reg [0:0] PI_io_FU_outputs_1_bits_RD_valid;
  reg [6:0] PI_io_partial_commit_PRDold_0;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit;
  reg [1:0] PI_io_FU_outputs_2_bits_fetch_packet_index;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2;
  reg [0:0] PI_io_FU_outputs_2_valid;
  reg [31:0] PI_io_decoded_fetch_packet_bits_fetch_PC;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU;
  reg [3:0] PI_io_partial_commit_MOB_index_0;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index;
  reg [4:0] PI_io_partial_commit_RD_0;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_portID;
  reg [0:0] PI_io_commit_bits_RD_valid_2;
  reg [3:0] PI_io_partial_commit_MOB_index_3;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD;
  reg [5:0] PI_io_FU_outputs_3_bits_ROB_index;
  reg [0:0] PI_io_partial_commit_RD_valid_1;
  reg [0:0] PI_io_FU_outputs_2_bits_branch_taken;
  reg [6:0] PI_io_FU_outputs_0_bits_PRD;
  reg [5:0] PI_io_FU_outputs_2_bits_ROB_index;
  reg [3:0] PI_io_FU_outputs_1_bits_MOB_index;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY;
  reg [0:0] PI_io_FU_outputs_1_bits_is_unsigned;
  reg [0:0] PI_io_decoded_fetch_packet_bits_prediction_T_NT;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType;
  reg [31:0] PI_io_FU_outputs_3_bits_RD_data;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM;
  reg [31:0] PI_io_FU_outputs_2_bits_fetch_PC;
  reg [0:0] PI_io_partial_commit_RD_valid_2;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type;
  reg [31:0] PI_io_commit_bits_expected_PC;
  reg [0:0] PI_io_FU_outputs_1_bits_branch_taken;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index;
  reg [5:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index;
  reg [4:0] PI_io_commit_bits_RD_1;
  reg [0:0] PI_io_partial_commit_MOB_valid_0;
  reg [6:0] PI_io_decoded_fetch_packet_bits_TOS;
  reg [31:0] PI_io_FU_outputs_1_bits_RD_data;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold;
  reg [6:0] PI_io_decoded_fetch_packet_bits_NEXT;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_access_width;
  reg [4:0] PI_io_commit_bits_RD_0;
  reg [0:0] PI_io_partial_commit_RD_valid_0;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type;
  reg [6:0] PI_io_commit_bits_PRD_3;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_portID;
  reg [6:0] PI_io_commit_bits_PRD_0;
  reg [31:0] PI_io_FU_outputs_0_bits_target_address;
  reg [0:0] PI_io_commit_bits_RD_valid_3;
  reg [5:0] PI_io_FU_outputs_1_bits_ROB_index;
  reg [0:0] PI_io_partial_commit_MOB_valid_2;
  reg [7:0] PI_io_decoded_fetch_packet_bits_free_list_front_pointer;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_portID;
  reg [0:0] PI_reset;
  reg [6:0] PI_io_partial_commit_PRDold_3;
  reg [1:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs;
  reg [0:0] PI_io_commit_bits_is_misprediction;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType;
  reg [2:0] PI_io_decoded_fetch_packet_bits_prediction_br_type;
  reg [6:0] PI_io_commit_bits_TOS;
  reg [1:0] PI_io_FU_outputs_3_bits_memory_type;
  reg [31:0] PI_io_FU_outputs_2_bits_target_address;
  reg [6:0] PI_io_commit_bits_PRD_2;
  reg [1:0] PI_io_commit_bits_fetch_packet_index;
  reg [6:0] PI_io_commit_bits_PRD_1;
  reg [0:0] PI_io_decoded_fetch_packet_valid;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready;
  reg [6:0] PI_io_partial_commit_PRD_1;
  reg [6:0] PI_io_commit_bits_NEXT;
  reg [0:0] PI_io_decoded_fetch_packet_bits_valid_bits_3;
  reg [0:0] PI_io_FU_outputs_3_bits_branch_taken;
  reg [4:0] PI_io_commit_bits_RD_3;
  reg [0:0] PI_io_FU_outputs_1_valid;
  wire [0:0] PI_clock = clock;
  reg [1:0] PI_io_FU_outputs_0_bits_memory_type;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2;
  reg [0:0] PI_io_FU_outputs_0_bits_branch_valid;
  reg [1:0] PI_io_FU_outputs_0_bits_fetch_packet_index;
  reg [0:0] PI_io_partial_commit_valid_0;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU;
  reg [6:0] PI_io_partial_commit_PRDold_1;
  reg [15:0] PI_io_commit_bits_GHR;
  reg [1:0] PI_io_FU_outputs_3_bits_fetch_packet_index;
  reg [0:0] PI_io_decoded_fetch_packet_bits_valid_bits_2;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM;
  reg [31:0] PI_io_FU_outputs_1_bits_fetch_PC;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1;
  reg [6:0] PI_io_partial_commit_PRD_2;
  reg [1:0] PI_io_FU_outputs_0_bits_access_width;
  reg [20:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IMM;
  reg [2:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3;
  reg [31:0] PI_io_FU_outputs_0_bits_fetch_PC;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1;
  reg [0:0] PI_io_FU_outputs_0_bits_RD_valid;
  reg [4:0] PI_io_partial_commit_RD_3;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU;
  reg [5:0] PI_io_partial_commit_ROB_index;
  reg [4:0] PI_io_partial_commit_RD_1;
  reg [3:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index;
  reg [20:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IMM;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1;
  reg [31:0] PI_io_FU_outputs_1_bits_target_address;
  reg [0:0] PI_io_decoded_fetch_packet_bits_valid_bits_0;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD;
  reg [2:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3;
  reg [0:0] PI_io_FU_outputs_0_valid;
  reg [0:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM;
  reg [4:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType;
  reg [6:0] PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold;
  rename UUT (
    .io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready),
    .io_FU_outputs_2_bits_branch_valid(PI_io_FU_outputs_2_bits_branch_valid),
    .io_FU_outputs_2_bits_PRD(PI_io_FU_outputs_2_bits_PRD),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IMM),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid),
    .io_FU_outputs_3_bits_MOB_index(PI_io_FU_outputs_3_bits_MOB_index),
    .io_partial_commit_valid_2(PI_io_partial_commit_valid_2),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_access_width(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_access_width),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_portID(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_portID),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index),
    .io_partial_commit_valid_3(PI_io_partial_commit_valid_3),
    .io_partial_commit_MOB_index_1(PI_io_partial_commit_MOB_index_1),
    .io_partial_commit_MOB_valid_1(PI_io_partial_commit_MOB_valid_1),
    .io_FU_outputs_3_bits_access_width(PI_io_FU_outputs_3_bits_access_width),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RD(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_access_width(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_access_width),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU),
    .io_decoded_fetch_packet_bits_prediction_hit(PI_io_decoded_fetch_packet_bits_prediction_hit),
    .io_renamed_decoded_fetch_packet_ready(PI_io_renamed_decoded_fetch_packet_ready),
    .io_FU_outputs_3_bits_PRD(PI_io_FU_outputs_3_bits_PRD),
    .io_FU_outputs_3_bits_RD_valid(PI_io_FU_outputs_3_bits_RD_valid),
    .io_commit_bits_br_type(PI_io_commit_bits_br_type),
    .io_flush(PI_io_flush),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs),
    .io_FU_outputs_2_bits_is_unsigned(PI_io_FU_outputs_2_bits_is_unsigned),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_PRD(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRD),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold),
    .io_FU_outputs_1_bits_PRD(PI_io_FU_outputs_1_bits_PRD),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RS2(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2),
    .io_FU_outputs_2_bits_MOB_index(PI_io_FU_outputs_2_bits_MOB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid),
    .io_partial_commit_PRD_0(PI_io_partial_commit_PRD_0),
    .io_FU_outputs_2_bits_wr_data(PI_io_FU_outputs_2_bits_wr_data),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs),
    .io_partial_commit_RD_2(PI_io_partial_commit_RD_2),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_PRD(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRD),
    .io_partial_commit_MOB_index_2(PI_io_partial_commit_MOB_index_2),
    .io_FU_outputs_0_bits_ROB_index(PI_io_FU_outputs_0_bits_ROB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid),
    .io_FU_outputs_0_bits_branch_taken(PI_io_FU_outputs_0_bits_branch_taken),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_access_width(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_access_width),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid),
    .io_FU_outputs_0_bits_wr_data(PI_io_FU_outputs_0_bits_wr_data),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type),
    .io_FU_outputs_1_bits_address(PI_io_FU_outputs_1_bits_address),
    .io_FU_outputs_0_bits_RD_data(PI_io_FU_outputs_0_bits_RD_data),
    .io_FU_outputs_2_bits_RD_valid(PI_io_FU_outputs_2_bits_RD_valid),
    .io_FU_outputs_3_bits_branch_valid(PI_io_FU_outputs_3_bits_branch_valid),
    .io_partial_commit_PRD_3(PI_io_partial_commit_PRD_3),
    .io_commit_bits_ROB_index(PI_io_commit_bits_ROB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_PRD(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRD),
    .io_FU_outputs_3_bits_wr_data(PI_io_FU_outputs_3_bits_wr_data),
    .io_decoded_fetch_packet_bits_prediction_target(PI_io_decoded_fetch_packet_bits_prediction_target),
    .io_FU_outputs_3_valid(PI_io_FU_outputs_3_valid),
    .io_FU_outputs_0_bits_MOB_index(PI_io_FU_outputs_0_bits_MOB_index),
    .io_FU_outputs_2_bits_access_width(PI_io_FU_outputs_2_bits_access_width),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type),
    .io_commit_bits_RD_valid_1(PI_io_commit_bits_RD_valid_1),
    .io_partial_commit_RD_valid_3(PI_io_partial_commit_RD_valid_3),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RD(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD),
    .io_partial_commit_PRDold_2(PI_io_partial_commit_PRDold_2),
    .io_FU_outputs_3_bits_fetch_PC(PI_io_FU_outputs_3_bits_fetch_PC),
    .io_FU_outputs_1_bits_memory_type(PI_io_FU_outputs_1_bits_memory_type),
    .io_partial_commit_MOB_valid_3(PI_io_partial_commit_MOB_valid_3),
    .io_commit_bits_RD_valid_0(PI_io_commit_bits_RD_valid_0),
    .io_FU_outputs_2_bits_memory_type(PI_io_FU_outputs_2_bits_memory_type),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready),
    .io_FU_outputs_1_bits_access_width(PI_io_FU_outputs_1_bits_access_width),
    .io_commit_bits_T_NT(PI_io_commit_bits_T_NT),
    .io_FU_outputs_0_bits_is_unsigned(PI_io_FU_outputs_0_bits_is_unsigned),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM),
    .io_FU_outputs_1_bits_wr_data(PI_io_FU_outputs_1_bits_wr_data),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IMM),
    .io_FU_outputs_1_bits_fetch_packet_index(PI_io_FU_outputs_1_bits_fetch_packet_index),
    .io_decoded_fetch_packet_bits_GHR(PI_io_decoded_fetch_packet_bits_GHR),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type),
    .io_FU_outputs_3_bits_target_address(PI_io_FU_outputs_3_bits_target_address),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RS1(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1),
    .io_FU_outputs_2_bits_address(PI_io_FU_outputs_2_bits_address),
    .io_partial_commit_valid_1(PI_io_partial_commit_valid_1),
    .io_FU_outputs_1_bits_branch_valid(PI_io_FU_outputs_1_bits_branch_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_PRD(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRD),
    .io_FU_outputs_3_bits_address(PI_io_FU_outputs_3_bits_address),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT),
    .io_commit_bits_RD_2(PI_io_commit_bits_RD_2),
    .io_FU_outputs_0_bits_address(PI_io_FU_outputs_0_bits_address),
    .io_FU_outputs_3_bits_is_unsigned(PI_io_FU_outputs_3_bits_is_unsigned),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT),
    .io_commit_bits_free_list_front_pointer(PI_io_commit_bits_free_list_front_pointer),
    .io_commit_bits_fetch_PC(PI_io_commit_bits_fetch_PC),
    .io_FU_outputs_2_bits_RD_data(PI_io_FU_outputs_2_bits_RD_data),
    .io_decoded_fetch_packet_bits_valid_bits_1(PI_io_decoded_fetch_packet_bits_valid_bits_1),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index),
    .io_commit_valid(PI_io_commit_valid),
    .io_FU_outputs_1_bits_RD_valid(PI_io_FU_outputs_1_bits_RD_valid),
    .io_partial_commit_PRDold_0(PI_io_partial_commit_PRDold_0),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit),
    .io_FU_outputs_2_bits_fetch_packet_index(PI_io_FU_outputs_2_bits_fetch_packet_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RS2(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2),
    .io_FU_outputs_2_valid(PI_io_FU_outputs_2_valid),
    .io_decoded_fetch_packet_bits_fetch_PC(PI_io_decoded_fetch_packet_bits_fetch_PC),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU),
    .io_partial_commit_MOB_index_0(PI_io_partial_commit_MOB_index_0),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index),
    .io_partial_commit_RD_0(PI_io_partial_commit_RD_0),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_portID(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_portID),
    .io_commit_bits_RD_valid_2(PI_io_commit_bits_RD_valid_2),
    .io_partial_commit_MOB_index_3(PI_io_partial_commit_MOB_index_3),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RS2(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RD(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD),
    .io_FU_outputs_3_bits_ROB_index(PI_io_FU_outputs_3_bits_ROB_index),
    .io_partial_commit_RD_valid_1(PI_io_partial_commit_RD_valid_1),
    .io_FU_outputs_2_bits_branch_taken(PI_io_FU_outputs_2_bits_branch_taken),
    .io_FU_outputs_0_bits_PRD(PI_io_FU_outputs_0_bits_PRD),
    .io_FU_outputs_2_bits_ROB_index(PI_io_FU_outputs_2_bits_ROB_index),
    .io_FU_outputs_1_bits_MOB_index(PI_io_FU_outputs_1_bits_MOB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY),
    .io_FU_outputs_1_bits_is_unsigned(PI_io_FU_outputs_1_bits_is_unsigned),
    .io_decoded_fetch_packet_bits_prediction_T_NT(PI_io_decoded_fetch_packet_bits_prediction_T_NT),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType),
    .io_FU_outputs_3_bits_RD_data(PI_io_FU_outputs_3_bits_RD_data),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM),
    .io_FU_outputs_2_bits_fetch_PC(PI_io_FU_outputs_2_bits_fetch_PC),
    .io_partial_commit_RD_valid_2(PI_io_partial_commit_RD_valid_2),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type),
    .io_commit_bits_expected_PC(PI_io_commit_bits_expected_PC),
    .io_FU_outputs_1_bits_branch_taken(PI_io_FU_outputs_1_bits_branch_taken),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index),
    .io_commit_bits_RD_1(PI_io_commit_bits_RD_1),
    .io_partial_commit_MOB_valid_0(PI_io_partial_commit_MOB_valid_0),
    .io_decoded_fetch_packet_bits_TOS(PI_io_decoded_fetch_packet_bits_TOS),
    .io_FU_outputs_1_bits_RD_data(PI_io_FU_outputs_1_bits_RD_data),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold),
    .io_decoded_fetch_packet_bits_NEXT(PI_io_decoded_fetch_packet_bits_NEXT),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_access_width(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_access_width),
    .io_commit_bits_RD_0(PI_io_commit_bits_RD_0),
    .io_partial_commit_RD_valid_0(PI_io_partial_commit_RD_valid_0),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type),
    .io_commit_bits_PRD_3(PI_io_commit_bits_PRD_3),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_portID(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_portID),
    .io_commit_bits_PRD_0(PI_io_commit_bits_PRD_0),
    .io_FU_outputs_0_bits_target_address(PI_io_FU_outputs_0_bits_target_address),
    .io_commit_bits_RD_valid_3(PI_io_commit_bits_RD_valid_3),
    .io_FU_outputs_1_bits_ROB_index(PI_io_FU_outputs_1_bits_ROB_index),
    .io_partial_commit_MOB_valid_2(PI_io_partial_commit_MOB_valid_2),
    .io_decoded_fetch_packet_bits_free_list_front_pointer(PI_io_decoded_fetch_packet_bits_free_list_front_pointer),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_portID(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_portID),
    .reset(PI_reset),
    .io_partial_commit_PRDold_3(PI_io_partial_commit_PRDold_3),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs),
    .io_commit_bits_is_misprediction(PI_io_commit_bits_is_misprediction),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType),
    .io_decoded_fetch_packet_bits_prediction_br_type(PI_io_decoded_fetch_packet_bits_prediction_br_type),
    .io_commit_bits_TOS(PI_io_commit_bits_TOS),
    .io_FU_outputs_3_bits_memory_type(PI_io_FU_outputs_3_bits_memory_type),
    .io_FU_outputs_2_bits_target_address(PI_io_FU_outputs_2_bits_target_address),
    .io_commit_bits_PRD_2(PI_io_commit_bits_PRD_2),
    .io_commit_bits_fetch_packet_index(PI_io_commit_bits_fetch_packet_index),
    .io_commit_bits_PRD_1(PI_io_commit_bits_PRD_1),
    .io_decoded_fetch_packet_valid(PI_io_decoded_fetch_packet_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready),
    .io_partial_commit_PRD_1(PI_io_partial_commit_PRD_1),
    .io_commit_bits_NEXT(PI_io_commit_bits_NEXT),
    .io_decoded_fetch_packet_bits_valid_bits_3(PI_io_decoded_fetch_packet_bits_valid_bits_3),
    .io_FU_outputs_3_bits_branch_taken(PI_io_FU_outputs_3_bits_branch_taken),
    .io_commit_bits_RD_3(PI_io_commit_bits_RD_3),
    .io_FU_outputs_1_valid(PI_io_FU_outputs_1_valid),
    .clock(PI_clock),
    .io_FU_outputs_0_bits_memory_type(PI_io_FU_outputs_0_bits_memory_type),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RS2(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2),
    .io_FU_outputs_0_bits_branch_valid(PI_io_FU_outputs_0_bits_branch_valid),
    .io_FU_outputs_0_bits_fetch_packet_index(PI_io_FU_outputs_0_bits_fetch_packet_index),
    .io_partial_commit_valid_0(PI_io_partial_commit_valid_0),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU),
    .io_partial_commit_PRDold_1(PI_io_partial_commit_PRDold_1),
    .io_commit_bits_GHR(PI_io_commit_bits_GHR),
    .io_FU_outputs_3_bits_fetch_packet_index(PI_io_FU_outputs_3_bits_fetch_packet_index),
    .io_decoded_fetch_packet_bits_valid_bits_2(PI_io_decoded_fetch_packet_bits_valid_bits_2),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM),
    .io_FU_outputs_1_bits_fetch_PC(PI_io_FU_outputs_1_bits_fetch_PC),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RS1(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1),
    .io_partial_commit_PRD_2(PI_io_partial_commit_PRD_2),
    .io_FU_outputs_0_bits_access_width(PI_io_FU_outputs_0_bits_access_width),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IMM),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3),
    .io_FU_outputs_0_bits_fetch_PC(PI_io_FU_outputs_0_bits_fetch_PC),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_RS1(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1),
    .io_FU_outputs_0_bits_RD_valid(PI_io_FU_outputs_0_bits_RD_valid),
    .io_partial_commit_RD_3(PI_io_partial_commit_RD_3),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU),
    .io_partial_commit_ROB_index(PI_io_partial_commit_ROB_index),
    .io_partial_commit_RD_1(PI_io_partial_commit_RD_1),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IMM),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_RS1(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1),
    .io_FU_outputs_1_bits_target_address(PI_io_FU_outputs_1_bits_target_address),
    .io_decoded_fetch_packet_bits_valid_bits_0(PI_io_decoded_fetch_packet_bits_valid_bits_0),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_RD(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD),
    .io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3(PI_io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3),
    .io_FU_outputs_0_valid(PI_io_FU_outputs_0_valid),
    .io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM(PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM),
    .io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType(PI_io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType),
    .io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold(PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold)
  );
`ifndef VERILATOR
  initial begin
    if ($value$plusargs("vcd=%s", vcdfile)) begin
      $dumpfile(vcdfile);
      $dumpvars(0, testbench);
    end
    #5 clock = 0;
    while (genclock) begin
      #5 clock = 0;
      #5 clock = 1;
    end
  end
`endif
  initial begin
`ifndef VERILATOR
    #1;
`endif
    // UUT.$auto$async2sync.\cc:228:execute$39703  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39705  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39707  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39709  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39711  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39713  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39715  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39717  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39719  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39721  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39723  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39725  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39727  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39729  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39731  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39733  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39735  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39737  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39739  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39741  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39743  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39745  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39747  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39749  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39751  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39753  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39755  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39757  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39759  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39761  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39763  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39765  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39767  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39769  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39771  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39773  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39775  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$39777  = 1'b0;
    UUT.RAT.commit_RAT_0 = 7'b0000000;
    UUT.RAT.commit_RAT_1 = 7'b0000000;
    UUT.RAT.commit_RAT_10 = 7'b0000000;
    UUT.RAT.commit_RAT_11 = 7'b0000000;
    UUT.RAT.commit_RAT_12 = 7'b0000000;
    UUT.RAT.commit_RAT_13 = 7'b0000000;
    UUT.RAT.commit_RAT_14 = 7'b0000000;
    UUT.RAT.commit_RAT_15 = 7'b0000000;
    UUT.RAT.commit_RAT_16 = 7'b0000000;
    UUT.RAT.commit_RAT_17 = 7'b0000000;
    UUT.RAT.commit_RAT_18 = 7'b0000000;
    UUT.RAT.commit_RAT_19 = 7'b0000000;
    UUT.RAT.commit_RAT_2 = 7'b0000000;
    UUT.RAT.commit_RAT_20 = 7'b0000000;
    UUT.RAT.commit_RAT_21 = 7'b0000000;
    UUT.RAT.commit_RAT_22 = 7'b0000000;
    UUT.RAT.commit_RAT_23 = 7'b0000000;
    UUT.RAT.commit_RAT_24 = 7'b0000000;
    UUT.RAT.commit_RAT_25 = 7'b0000000;
    UUT.RAT.commit_RAT_26 = 7'b0000000;
    UUT.RAT.commit_RAT_27 = 7'b0000000;
    UUT.RAT.commit_RAT_28 = 7'b0000000;
    UUT.RAT.commit_RAT_29 = 7'b0000000;
    UUT.RAT.commit_RAT_3 = 7'b0000000;
    UUT.RAT.commit_RAT_30 = 7'b0000000;
    UUT.RAT.commit_RAT_31 = 7'b0000000;
    UUT.RAT.commit_RAT_4 = 7'b0000000;
    UUT.RAT.commit_RAT_5 = 7'b0000000;
    UUT.RAT.commit_RAT_6 = 7'b0000000;
    UUT.RAT.commit_RAT_7 = 7'b0000000;
    UUT.RAT.commit_RAT_8 = 7'b0000000;
    UUT.RAT.commit_RAT_9 = 7'b0000000;
    UUT.RAT.speculative_RAT_0 = 7'b0000000;
    UUT.RAT.speculative_RAT_1 = 7'b0000000;
    UUT.RAT.speculative_RAT_10 = 7'b0000000;
    UUT.RAT.speculative_RAT_11 = 7'b0000000;
    UUT.RAT.speculative_RAT_12 = 7'b0000000;
    UUT.RAT.speculative_RAT_13 = 7'b0000000;
    UUT.RAT.speculative_RAT_14 = 7'b0000000;
    UUT.RAT.speculative_RAT_15 = 7'b0000000;
    UUT.RAT.speculative_RAT_16 = 7'b0000000;
    UUT.RAT.speculative_RAT_17 = 7'b0000000;
    UUT.RAT.speculative_RAT_18 = 7'b0000000;
    UUT.RAT.speculative_RAT_19 = 7'b0000000;
    UUT.RAT.speculative_RAT_2 = 7'b0000000;
    UUT.RAT.speculative_RAT_20 = 7'b0000000;
    UUT.RAT.speculative_RAT_21 = 7'b0000000;
    UUT.RAT.speculative_RAT_22 = 7'b0000000;
    UUT.RAT.speculative_RAT_23 = 7'b0000000;
    UUT.RAT.speculative_RAT_24 = 7'b0000000;
    UUT.RAT.speculative_RAT_25 = 7'b0000000;
    UUT.RAT.speculative_RAT_26 = 7'b0000000;
    UUT.RAT.speculative_RAT_27 = 7'b0000000;
    UUT.RAT.speculative_RAT_28 = 7'b0000000;
    UUT.RAT.speculative_RAT_29 = 7'b0000000;
    UUT.RAT.speculative_RAT_3 = 7'b0000000;
    UUT.RAT.speculative_RAT_30 = 7'b0000000;
    UUT.RAT.speculative_RAT_31 = 7'b0000000;
    UUT.RAT.speculative_RAT_4 = 7'b0000000;
    UUT.RAT.speculative_RAT_5 = 7'b0000000;
    UUT.RAT.speculative_RAT_6 = 7'b0000000;
    UUT.RAT.speculative_RAT_7 = 7'b0000000;
    UUT.RAT.speculative_RAT_8 = 7'b0000000;
    UUT.RAT.speculative_RAT_9 = 7'b0000000;
    UUT.formal_RAT_0 = 7'b0000000;
    UUT.formal_RAT_1 = 7'b0000000;
    UUT.formal_RAT_10 = 7'b0000000;
    UUT.formal_RAT_11 = 7'b0000000;
    UUT.formal_RAT_12 = 7'b0000000;
    UUT.formal_RAT_13 = 7'b0000000;
    UUT.formal_RAT_14 = 7'b0000000;
    UUT.formal_RAT_15 = 7'b0000000;
    UUT.formal_RAT_16 = 7'b0000000;
    UUT.formal_RAT_17 = 7'b0000000;
    UUT.formal_RAT_18 = 7'b0000000;
    UUT.formal_RAT_19 = 7'b0000000;
    UUT.formal_RAT_2 = 7'b0000000;
    UUT.formal_RAT_20 = 7'b0000000;
    UUT.formal_RAT_21 = 7'b0000000;
    UUT.formal_RAT_22 = 7'b0000000;
    UUT.formal_RAT_23 = 7'b0000000;
    UUT.formal_RAT_24 = 7'b0000000;
    UUT.formal_RAT_25 = 7'b0000000;
    UUT.formal_RAT_26 = 7'b0000000;
    UUT.formal_RAT_27 = 7'b0000000;
    UUT.formal_RAT_28 = 7'b0000000;
    UUT.formal_RAT_29 = 7'b0000000;
    UUT.formal_RAT_3 = 7'b0000000;
    UUT.formal_RAT_30 = 7'b0000000;
    UUT.formal_RAT_31 = 7'b0000000;
    UUT.formal_RAT_4 = 7'b0000000;
    UUT.formal_RAT_5 = 7'b0000000;
    UUT.formal_RAT_6 = 7'b0000000;
    UUT.formal_RAT_7 = 7'b0000000;
    UUT.formal_RAT_8 = 7'b0000000;
    UUT.formal_RAT_9 = 7'b0000000;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39779  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39781  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39783  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39785  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39787  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39789  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39791  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39793  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39795  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39797  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39799  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39801  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39803  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39805  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39807  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39809  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39811  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39813  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39815  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39817  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39819  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39821  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39823  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39825  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39827  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39829  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39831  = 1'b0;
    // UUT.free_list.$auto$async2sync.\cc:228:execute$39833  = 1'b0;
    UUT.free_list.REG = 6'b000000;
    UUT.free_list.REG_1 = 6'b000000;
    UUT.free_list.REG_2 = 6'b000000;
    UUT.free_list.REG_3 = 6'b000000;
    UUT.free_list.commit_free_list_buffer_0 = 1'b0;
    UUT.free_list.commit_free_list_buffer_1 = 1'b0;
    UUT.free_list.commit_free_list_buffer_10 = 1'b0;
    UUT.free_list.commit_free_list_buffer_11 = 1'b0;
    UUT.free_list.commit_free_list_buffer_12 = 1'b0;
    UUT.free_list.commit_free_list_buffer_13 = 1'b0;
    UUT.free_list.commit_free_list_buffer_14 = 1'b0;
    UUT.free_list.commit_free_list_buffer_15 = 1'b0;
    UUT.free_list.commit_free_list_buffer_16 = 1'b0;
    UUT.free_list.commit_free_list_buffer_17 = 1'b0;
    UUT.free_list.commit_free_list_buffer_18 = 1'b0;
    UUT.free_list.commit_free_list_buffer_19 = 1'b0;
    UUT.free_list.commit_free_list_buffer_2 = 1'b0;
    UUT.free_list.commit_free_list_buffer_20 = 1'b0;
    UUT.free_list.commit_free_list_buffer_21 = 1'b0;
    UUT.free_list.commit_free_list_buffer_22 = 1'b0;
    UUT.free_list.commit_free_list_buffer_23 = 1'b0;
    UUT.free_list.commit_free_list_buffer_24 = 1'b0;
    UUT.free_list.commit_free_list_buffer_25 = 1'b0;
    UUT.free_list.commit_free_list_buffer_26 = 1'b0;
    UUT.free_list.commit_free_list_buffer_27 = 1'b0;
    UUT.free_list.commit_free_list_buffer_28 = 1'b0;
    UUT.free_list.commit_free_list_buffer_29 = 1'b0;
    UUT.free_list.commit_free_list_buffer_3 = 1'b0;
    UUT.free_list.commit_free_list_buffer_30 = 1'b0;
    UUT.free_list.commit_free_list_buffer_31 = 1'b0;
    UUT.free_list.commit_free_list_buffer_32 = 1'b0;
    UUT.free_list.commit_free_list_buffer_33 = 1'b0;
    UUT.free_list.commit_free_list_buffer_34 = 1'b0;
    UUT.free_list.commit_free_list_buffer_35 = 1'b0;
    UUT.free_list.commit_free_list_buffer_36 = 1'b0;
    UUT.free_list.commit_free_list_buffer_37 = 1'b0;
    UUT.free_list.commit_free_list_buffer_38 = 1'b0;
    UUT.free_list.commit_free_list_buffer_39 = 1'b0;
    UUT.free_list.commit_free_list_buffer_4 = 1'b0;
    UUT.free_list.commit_free_list_buffer_40 = 1'b0;
    UUT.free_list.commit_free_list_buffer_41 = 1'b0;
    UUT.free_list.commit_free_list_buffer_42 = 1'b0;
    UUT.free_list.commit_free_list_buffer_43 = 1'b0;
    UUT.free_list.commit_free_list_buffer_44 = 1'b0;
    UUT.free_list.commit_free_list_buffer_45 = 1'b0;
    UUT.free_list.commit_free_list_buffer_46 = 1'b0;
    UUT.free_list.commit_free_list_buffer_47 = 1'b0;
    UUT.free_list.commit_free_list_buffer_48 = 1'b0;
    UUT.free_list.commit_free_list_buffer_49 = 1'b0;
    UUT.free_list.commit_free_list_buffer_5 = 1'b0;
    UUT.free_list.commit_free_list_buffer_50 = 1'b0;
    UUT.free_list.commit_free_list_buffer_51 = 1'b0;
    UUT.free_list.commit_free_list_buffer_52 = 1'b0;
    UUT.free_list.commit_free_list_buffer_53 = 1'b0;
    UUT.free_list.commit_free_list_buffer_54 = 1'b0;
    UUT.free_list.commit_free_list_buffer_55 = 1'b0;
    UUT.free_list.commit_free_list_buffer_56 = 1'b0;
    UUT.free_list.commit_free_list_buffer_57 = 1'b0;
    UUT.free_list.commit_free_list_buffer_58 = 1'b0;
    UUT.free_list.commit_free_list_buffer_59 = 1'b0;
    UUT.free_list.commit_free_list_buffer_6 = 1'b0;
    UUT.free_list.commit_free_list_buffer_60 = 1'b0;
    UUT.free_list.commit_free_list_buffer_61 = 1'b0;
    UUT.free_list.commit_free_list_buffer_62 = 1'b0;
    UUT.free_list.commit_free_list_buffer_63 = 1'b0;
    UUT.free_list.commit_free_list_buffer_7 = 1'b0;
    UUT.free_list.commit_free_list_buffer_8 = 1'b0;
    UUT.free_list.commit_free_list_buffer_9 = 1'b0;
    UUT.free_list.free_list_buffer_0 = 1'b0;
    UUT.free_list.free_list_buffer_1 = 1'b0;
    UUT.free_list.free_list_buffer_10 = 1'b0;
    UUT.free_list.free_list_buffer_11 = 1'b0;
    UUT.free_list.free_list_buffer_12 = 1'b0;
    UUT.free_list.free_list_buffer_13 = 1'b0;
    UUT.free_list.free_list_buffer_14 = 1'b0;
    UUT.free_list.free_list_buffer_15 = 1'b0;
    UUT.free_list.free_list_buffer_16 = 1'b0;
    UUT.free_list.free_list_buffer_17 = 1'b0;
    UUT.free_list.free_list_buffer_18 = 1'b0;
    UUT.free_list.free_list_buffer_19 = 1'b0;
    UUT.free_list.free_list_buffer_2 = 1'b0;
    UUT.free_list.free_list_buffer_20 = 1'b0;
    UUT.free_list.free_list_buffer_21 = 1'b0;
    UUT.free_list.free_list_buffer_22 = 1'b0;
    UUT.free_list.free_list_buffer_23 = 1'b0;
    UUT.free_list.free_list_buffer_24 = 1'b0;
    UUT.free_list.free_list_buffer_25 = 1'b0;
    UUT.free_list.free_list_buffer_26 = 1'b0;
    UUT.free_list.free_list_buffer_27 = 1'b0;
    UUT.free_list.free_list_buffer_28 = 1'b0;
    UUT.free_list.free_list_buffer_29 = 1'b0;
    UUT.free_list.free_list_buffer_3 = 1'b0;
    UUT.free_list.free_list_buffer_30 = 1'b0;
    UUT.free_list.free_list_buffer_31 = 1'b0;
    UUT.free_list.free_list_buffer_32 = 1'b0;
    UUT.free_list.free_list_buffer_33 = 1'b0;
    UUT.free_list.free_list_buffer_34 = 1'b0;
    UUT.free_list.free_list_buffer_35 = 1'b0;
    UUT.free_list.free_list_buffer_36 = 1'b0;
    UUT.free_list.free_list_buffer_37 = 1'b0;
    UUT.free_list.free_list_buffer_38 = 1'b0;
    UUT.free_list.free_list_buffer_39 = 1'b0;
    UUT.free_list.free_list_buffer_4 = 1'b0;
    UUT.free_list.free_list_buffer_40 = 1'b0;
    UUT.free_list.free_list_buffer_41 = 1'b0;
    UUT.free_list.free_list_buffer_42 = 1'b0;
    UUT.free_list.free_list_buffer_43 = 1'b0;
    UUT.free_list.free_list_buffer_44 = 1'b0;
    UUT.free_list.free_list_buffer_45 = 1'b0;
    UUT.free_list.free_list_buffer_46 = 1'b0;
    UUT.free_list.free_list_buffer_47 = 1'b0;
    UUT.free_list.free_list_buffer_48 = 1'b0;
    UUT.free_list.free_list_buffer_49 = 1'b0;
    UUT.free_list.free_list_buffer_5 = 1'b0;
    UUT.free_list.free_list_buffer_50 = 1'b0;
    UUT.free_list.free_list_buffer_51 = 1'b0;
    UUT.free_list.free_list_buffer_52 = 1'b0;
    UUT.free_list.free_list_buffer_53 = 1'b0;
    UUT.free_list.free_list_buffer_54 = 1'b0;
    UUT.free_list.free_list_buffer_55 = 1'b0;
    UUT.free_list.free_list_buffer_56 = 1'b0;
    UUT.free_list.free_list_buffer_57 = 1'b0;
    UUT.free_list.free_list_buffer_58 = 1'b0;
    UUT.free_list.free_list_buffer_59 = 1'b0;
    UUT.free_list.free_list_buffer_6 = 1'b0;
    UUT.free_list.free_list_buffer_60 = 1'b0;
    UUT.free_list.free_list_buffer_61 = 1'b0;
    UUT.free_list.free_list_buffer_62 = 1'b0;
    UUT.free_list.free_list_buffer_63 = 1'b0;
    UUT.free_list.free_list_buffer_7 = 1'b0;
    UUT.free_list.free_list_buffer_8 = 1'b0;
    UUT.free_list.free_list_buffer_9 = 1'b0;
    UUT.free_list.hasBeenResetReg = 1'b0;
    UUT.hasBeenResetReg = 1'b0;
    UUT.input_RS1_0 = 5'b00000;
    UUT.input_RS1_1 = 5'b00001;
    UUT.input_RS1_2 = 5'b00001;
    UUT.input_RS1_3 = 5'b00001;
    UUT.input_RS2_0 = 5'b00000;
    UUT.input_RS2_1 = 5'b00001;
    UUT.input_RS2_2 = 5'b00001;
    UUT.input_RS2_3 = 5'b00001;
    UUT.io_decoded_fetch_packet_ready_REG = 1'b0;
    UUT.ready_memory_1 = 1'b0;
    UUT.ready_memory_10 = 1'b0;
    UUT.ready_memory_11 = 1'b0;
    UUT.ready_memory_12 = 1'b0;
    UUT.ready_memory_13 = 1'b0;
    UUT.ready_memory_14 = 1'b0;
    UUT.ready_memory_15 = 1'b0;
    UUT.ready_memory_16 = 1'b0;
    UUT.ready_memory_17 = 1'b0;
    UUT.ready_memory_18 = 1'b0;
    UUT.ready_memory_19 = 1'b0;
    UUT.ready_memory_2 = 1'b0;
    UUT.ready_memory_20 = 1'b0;
    UUT.ready_memory_21 = 1'b0;
    UUT.ready_memory_22 = 1'b0;
    UUT.ready_memory_23 = 1'b0;
    UUT.ready_memory_24 = 1'b0;
    UUT.ready_memory_25 = 1'b0;
    UUT.ready_memory_26 = 1'b0;
    UUT.ready_memory_27 = 1'b0;
    UUT.ready_memory_28 = 1'b0;
    UUT.ready_memory_29 = 1'b0;
    UUT.ready_memory_3 = 1'b0;
    UUT.ready_memory_30 = 1'b0;
    UUT.ready_memory_31 = 1'b0;
    UUT.ready_memory_32 = 1'b0;
    UUT.ready_memory_33 = 1'b0;
    UUT.ready_memory_34 = 1'b0;
    UUT.ready_memory_35 = 1'b0;
    UUT.ready_memory_36 = 1'b0;
    UUT.ready_memory_37 = 1'b0;
    UUT.ready_memory_38 = 1'b0;
    UUT.ready_memory_39 = 1'b0;
    UUT.ready_memory_4 = 1'b0;
    UUT.ready_memory_40 = 1'b0;
    UUT.ready_memory_41 = 1'b0;
    UUT.ready_memory_42 = 1'b0;
    UUT.ready_memory_43 = 1'b0;
    UUT.ready_memory_44 = 1'b0;
    UUT.ready_memory_45 = 1'b0;
    UUT.ready_memory_46 = 1'b0;
    UUT.ready_memory_47 = 1'b0;
    UUT.ready_memory_48 = 1'b0;
    UUT.ready_memory_49 = 1'b0;
    UUT.ready_memory_5 = 1'b0;
    UUT.ready_memory_50 = 1'b0;
    UUT.ready_memory_51 = 1'b0;
    UUT.ready_memory_52 = 1'b0;
    UUT.ready_memory_53 = 1'b0;
    UUT.ready_memory_54 = 1'b0;
    UUT.ready_memory_55 = 1'b0;
    UUT.ready_memory_56 = 1'b0;
    UUT.ready_memory_57 = 1'b0;
    UUT.ready_memory_58 = 1'b0;
    UUT.ready_memory_59 = 1'b0;
    UUT.ready_memory_6 = 1'b0;
    UUT.ready_memory_60 = 1'b0;
    UUT.ready_memory_61 = 1'b0;
    UUT.ready_memory_62 = 1'b0;
    UUT.ready_memory_63 = 1'b0;
    UUT.ready_memory_64 = 1'b0;
    UUT.ready_memory_7 = 1'b0;
    UUT.ready_memory_8 = 1'b0;
    UUT.ready_memory_9 = 1'b0;
    UUT.renamed_decoded_fetch_packet_Q.maybe_full = 1'b0;
    UUT.renamed_decoded_fetch_packet_Q.wrap = 1'b0;
    UUT.renamed_decoded_fetch_packet_Q.wrap_1 = 1'b0;
    UUT.renamed_decoded_fetch_packet_Q.ram_ext.Memory[1'b0] = 483'b000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
    UUT.renamed_decoded_fetch_packet_Q.ram_ext.Memory[1'b1] = 483'b000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100001000000110100000000000000000000000000000000000000000000000000000000000000000000000000000100001000000101100000000000000000000000000000000000000000000000000000000000000000000000000000100001000000011100000000000000000000000000000000000000000000000000000000000000000000000000000100001000000010100000000000000000000000000000000000000;

    // state 0
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready = 1'b0;
    PI_io_FU_outputs_2_bits_branch_valid = 1'b0;
    PI_io_FU_outputs_2_bits_PRD = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3 = 3'b000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IMM = 21'b000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid = 1'b0;
    PI_io_FU_outputs_3_bits_MOB_index = 4'b0000;
    PI_io_partial_commit_valid_2 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_access_width = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_portID = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index = 4'b0000;
    PI_io_partial_commit_valid_3 = 1'b0;
    PI_io_partial_commit_MOB_index_1 = 4'b0000;
    PI_io_partial_commit_MOB_valid_1 = 1'b0;
    PI_io_FU_outputs_3_bits_access_width = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index = 6'b000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD = 5'b10000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_access_width = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU = 1'b0;
    PI_io_decoded_fetch_packet_bits_prediction_hit = 1'b0;
    PI_io_renamed_decoded_fetch_packet_ready = 1'b1;
    PI_io_FU_outputs_3_bits_PRD = 7'b0000000;
    PI_io_FU_outputs_3_bits_RD_valid = 1'b0;
    PI_io_commit_bits_br_type = 3'b000;
    PI_io_flush = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs = 1'b0;
    PI_io_FU_outputs_2_bits_is_unsigned = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRD = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold = 7'b0000000;
    PI_io_FU_outputs_1_bits_PRD = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2 = 7'b0000000;
    PI_io_FU_outputs_2_bits_MOB_index = 4'b0000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid = 1'b0;
    PI_io_partial_commit_PRD_0 = 7'b0000000;
    PI_io_FU_outputs_2_bits_wr_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index = 6'b000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs = 1'b0;
    PI_io_partial_commit_RD_2 = 5'b00000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRD = 7'b0000000;
    PI_io_partial_commit_MOB_index_2 = 4'b0000;
    PI_io_FU_outputs_0_bits_ROB_index = 6'b000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid = 1'b0;
    PI_io_FU_outputs_0_bits_branch_taken = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_access_width = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid = 1'b0;
    PI_io_FU_outputs_0_bits_wr_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type = 2'b00;
    PI_io_FU_outputs_1_bits_address = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_0_bits_RD_data = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_2_bits_RD_valid = 1'b0;
    PI_io_FU_outputs_3_bits_branch_valid = 1'b0;
    PI_io_partial_commit_PRD_3 = 7'b0000000;
    PI_io_commit_bits_ROB_index = 6'b000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRD = 7'b0000000;
    PI_io_FU_outputs_3_bits_wr_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_prediction_target = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_3_valid = 1'b0;
    PI_io_FU_outputs_0_bits_MOB_index = 4'b0000;
    PI_io_FU_outputs_2_bits_access_width = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3 = 3'b000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type = 2'b00;
    PI_io_commit_bits_RD_valid_1 = 1'b0;
    PI_io_partial_commit_RD_valid_3 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD = 5'b10000;
    PI_io_partial_commit_PRDold_2 = 7'b1000000;
    PI_io_FU_outputs_3_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_1_bits_memory_type = 2'b00;
    PI_io_partial_commit_MOB_valid_3 = 1'b0;
    PI_io_commit_bits_RD_valid_0 = 1'b0;
    PI_io_FU_outputs_2_bits_memory_type = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready = 1'b0;
    PI_io_FU_outputs_1_bits_access_width = 2'b00;
    PI_io_commit_bits_T_NT = 1'b0;
    PI_io_FU_outputs_0_bits_is_unsigned = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM = 1'b0;
    PI_io_FU_outputs_1_bits_wr_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index = 6'b000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IMM = 21'b000000000000000000000;
    PI_io_FU_outputs_1_bits_fetch_packet_index = 2'b00;
    PI_io_decoded_fetch_packet_bits_GHR = 16'b0000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type = 2'b00;
    PI_io_FU_outputs_3_bits_target_address = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1 = 7'b0000000;
    PI_io_FU_outputs_2_bits_address = 32'b00000000000000000000000000000000;
    PI_io_partial_commit_valid_1 = 1'b0;
    PI_io_FU_outputs_1_bits_branch_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRD = 7'b0000000;
    PI_io_FU_outputs_3_bits_address = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT = 1'b0;
    PI_io_commit_bits_RD_2 = 5'b00000;
    PI_io_FU_outputs_0_bits_address = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_3_bits_is_unsigned = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index = 4'b0000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT = 1'b0;
    PI_io_commit_bits_free_list_front_pointer = 8'b00000000;
    PI_io_commit_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_2_bits_RD_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_valid_bits_1 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index = 4'b0000;
    PI_io_commit_valid = 1'b0;
    PI_io_FU_outputs_1_bits_RD_valid = 1'b0;
    PI_io_partial_commit_PRDold_0 = 7'b1000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit = 1'b0;
    PI_io_FU_outputs_2_bits_fetch_packet_index = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2 = 7'b0000000;
    PI_io_FU_outputs_2_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU = 1'b0;
    PI_io_partial_commit_MOB_index_0 = 4'b0000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index = 2'b00;
    PI_io_partial_commit_RD_0 = 5'b00000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_portID = 2'b00;
    PI_io_commit_bits_RD_valid_2 = 1'b0;
    PI_io_partial_commit_MOB_index_3 = 4'b0000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2 = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD = 5'b10000;
    PI_io_FU_outputs_3_bits_ROB_index = 6'b000000;
    PI_io_partial_commit_RD_valid_1 = 1'b0;
    PI_io_FU_outputs_2_bits_branch_taken = 1'b0;
    PI_io_FU_outputs_0_bits_PRD = 7'b0000000;
    PI_io_FU_outputs_2_bits_ROB_index = 6'b000000;
    PI_io_FU_outputs_1_bits_MOB_index = 4'b0000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY = 1'b0;
    PI_io_FU_outputs_1_bits_is_unsigned = 1'b0;
    PI_io_decoded_fetch_packet_bits_prediction_T_NT = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType = 5'b00000;
    PI_io_FU_outputs_3_bits_RD_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM = 1'b0;
    PI_io_FU_outputs_2_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_partial_commit_RD_valid_2 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type = 2'b00;
    PI_io_commit_bits_expected_PC = 32'b00000000000000000000000000000000;
    PI_io_FU_outputs_1_bits_branch_taken = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index = 6'b000000;
    PI_io_commit_bits_RD_1 = 5'b00000;
    PI_io_partial_commit_MOB_valid_0 = 1'b0;
    PI_io_decoded_fetch_packet_bits_TOS = 7'b0000000;
    PI_io_FU_outputs_1_bits_RD_data = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_NEXT = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_access_width = 2'b00;
    PI_io_commit_bits_RD_0 = 5'b00000;
    PI_io_partial_commit_RD_valid_0 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type = 2'b00;
    PI_io_commit_bits_PRD_3 = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_portID = 2'b00;
    PI_io_commit_bits_PRD_0 = 7'b0000000;
    PI_io_FU_outputs_0_bits_target_address = 32'b00000000000000000000000000000000;
    PI_io_commit_bits_RD_valid_3 = 1'b0;
    PI_io_FU_outputs_1_bits_ROB_index = 6'b000000;
    PI_io_partial_commit_MOB_valid_2 = 1'b0;
    PI_io_decoded_fetch_packet_bits_free_list_front_pointer = 8'b00000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_portID = 2'b00;
    PI_reset = 1'b1;
    PI_io_partial_commit_PRDold_3 = 7'b1000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs = 1'b0;
    PI_io_commit_bits_is_misprediction = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType = 5'b00000;
    PI_io_decoded_fetch_packet_bits_prediction_br_type = 3'b000;
    PI_io_commit_bits_TOS = 7'b0000000;
    PI_io_FU_outputs_3_bits_memory_type = 2'b00;
    PI_io_FU_outputs_2_bits_target_address = 32'b00000000000000000000000000000000;
    PI_io_commit_bits_PRD_2 = 7'b0000000;
    PI_io_commit_bits_fetch_packet_index = 2'b00;
    PI_io_commit_bits_PRD_1 = 7'b0000000;
    PI_io_decoded_fetch_packet_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready = 1'b0;
    PI_io_partial_commit_PRD_1 = 7'b0000000;
    PI_io_commit_bits_NEXT = 7'b0000000;
    PI_io_decoded_fetch_packet_bits_valid_bits_3 = 1'b0;
    PI_io_FU_outputs_3_bits_branch_taken = 1'b0;
    PI_io_commit_bits_RD_3 = 5'b00000;
    PI_io_FU_outputs_1_valid = 1'b0;
    PI_io_FU_outputs_0_bits_memory_type = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2 = 7'b0000000;
    PI_io_FU_outputs_0_bits_branch_valid = 1'b0;
    PI_io_FU_outputs_0_bits_fetch_packet_index = 2'b00;
    PI_io_partial_commit_valid_0 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU = 1'b0;
    PI_io_partial_commit_PRDold_1 = 7'b1000000;
    PI_io_commit_bits_GHR = 16'b0000000000000000;
    PI_io_FU_outputs_3_bits_fetch_packet_index = 2'b00;
    PI_io_decoded_fetch_packet_bits_valid_bits_2 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType = 5'b00000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM = 1'b0;
    PI_io_FU_outputs_1_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1 = 7'b0000000;
    PI_io_partial_commit_PRD_2 = 7'b0000000;
    PI_io_FU_outputs_0_bits_access_width = 2'b00;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IMM = 21'b000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3 = 3'b000;
    PI_io_FU_outputs_0_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1 = 7'b0000000;
    PI_io_FU_outputs_0_bits_RD_valid = 1'b0;
    PI_io_partial_commit_RD_3 = 5'b00000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU = 1'b0;
    PI_io_partial_commit_ROB_index = 6'b000000;
    PI_io_partial_commit_RD_1 = 5'b00000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index = 4'b0000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IMM = 21'b000000000000000000000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1 = 7'b0000000;
    PI_io_FU_outputs_1_bits_target_address = 32'b00000000000000000000000000000000;
    PI_io_decoded_fetch_packet_bits_valid_bits_0 = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD = 5'b10000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3 = 3'b000;
    PI_io_FU_outputs_0_valid = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM = 1'b0;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType = 5'b00000;
    PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold = 7'b0000000;
  end
  always @(posedge clock) begin
    // state 1
    if (cycle == 0) begin
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready <= 1'b0;
      PI_io_FU_outputs_2_bits_branch_valid <= 1'b0;
      PI_io_FU_outputs_2_bits_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3 <= 3'b000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid <= 1'b0;
      PI_io_FU_outputs_3_bits_MOB_index <= 4'b0000;
      PI_io_partial_commit_valid_2 <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_portID <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index <= 4'b0000;
      PI_io_partial_commit_valid_3 <= 1'b1;
      PI_io_partial_commit_MOB_index_1 <= 4'b0000;
      PI_io_partial_commit_MOB_valid_1 <= 1'b0;
      PI_io_FU_outputs_3_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD <= 5'b10000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU <= 1'b0;
      PI_io_decoded_fetch_packet_bits_prediction_hit <= 1'b0;
      PI_io_renamed_decoded_fetch_packet_ready <= 1'b1;
      PI_io_FU_outputs_3_bits_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_RD_valid <= 1'b0;
      PI_io_commit_bits_br_type <= 3'b000;
      PI_io_flush <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs <= 1'b0;
      PI_io_FU_outputs_2_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold <= 7'b0000000;
      PI_io_FU_outputs_1_bits_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid <= 1'b1;
      PI_io_partial_commit_PRD_0 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs <= 1'b0;
      PI_io_partial_commit_RD_2 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRD <= 7'b0000000;
      PI_io_partial_commit_MOB_index_2 <= 4'b0000;
      PI_io_FU_outputs_0_bits_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid <= 1'b1;
      PI_io_FU_outputs_0_bits_branch_taken <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type <= 2'b00;
      PI_io_FU_outputs_1_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_0_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_2_bits_RD_valid <= 1'b0;
      PI_io_FU_outputs_3_bits_branch_valid <= 1'b0;
      PI_io_partial_commit_PRD_3 <= 7'b0000000;
      PI_io_commit_bits_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_prediction_target <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_3_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_MOB_index <= 4'b0000;
      PI_io_FU_outputs_2_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3 <= 3'b000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type <= 2'b00;
      PI_io_commit_bits_RD_valid_1 <= 1'b0;
      PI_io_partial_commit_RD_valid_3 <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD <= 5'b00000;
      PI_io_partial_commit_PRDold_2 <= 7'b1000100;
      PI_io_FU_outputs_3_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_1_bits_memory_type <= 2'b00;
      PI_io_partial_commit_MOB_valid_3 <= 1'b0;
      PI_io_commit_bits_RD_valid_0 <= 1'b0;
      PI_io_FU_outputs_2_bits_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready <= 1'b0;
      PI_io_FU_outputs_1_bits_access_width <= 2'b00;
      PI_io_commit_bits_T_NT <= 1'b0;
      PI_io_FU_outputs_0_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM <= 1'b0;
      PI_io_FU_outputs_1_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IMM <= 21'b000000000000000000000;
      PI_io_FU_outputs_1_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_GHR <= 16'b0000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type <= 2'b00;
      PI_io_FU_outputs_3_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_partial_commit_valid_1 <= 1'b1;
      PI_io_FU_outputs_1_bits_branch_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT <= 1'b0;
      PI_io_commit_bits_RD_2 <= 5'b00000;
      PI_io_FU_outputs_0_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_3_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT <= 1'b0;
      PI_io_commit_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_commit_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_2_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_1 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index <= 4'b0000;
      PI_io_commit_valid <= 1'b1;
      PI_io_FU_outputs_1_bits_RD_valid <= 1'b0;
      PI_io_partial_commit_PRDold_0 <= 7'b1000001;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit <= 1'b0;
      PI_io_FU_outputs_2_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2 <= 7'b0000000;
      PI_io_FU_outputs_2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU <= 1'b0;
      PI_io_partial_commit_MOB_index_0 <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index <= 2'b00;
      PI_io_partial_commit_RD_0 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_portID <= 2'b00;
      PI_io_commit_bits_RD_valid_2 <= 1'b0;
      PI_io_partial_commit_MOB_index_3 <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD <= 5'b00000;
      PI_io_FU_outputs_3_bits_ROB_index <= 6'b000000;
      PI_io_partial_commit_RD_valid_1 <= 1'b1;
      PI_io_FU_outputs_2_bits_branch_taken <= 1'b0;
      PI_io_FU_outputs_0_bits_PRD <= 7'b0000000;
      PI_io_FU_outputs_2_bits_ROB_index <= 6'b000000;
      PI_io_FU_outputs_1_bits_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY <= 1'b0;
      PI_io_FU_outputs_1_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_prediction_T_NT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType <= 5'b00000;
      PI_io_FU_outputs_3_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM <= 1'b0;
      PI_io_FU_outputs_2_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_partial_commit_RD_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type <= 2'b00;
      PI_io_commit_bits_expected_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_1_bits_branch_taken <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index <= 6'b000000;
      PI_io_commit_bits_RD_1 <= 5'b00000;
      PI_io_partial_commit_MOB_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_TOS <= 7'b0000000;
      PI_io_FU_outputs_1_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_NEXT <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_access_width <= 2'b00;
      PI_io_commit_bits_RD_0 <= 5'b00000;
      PI_io_partial_commit_RD_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type <= 2'b00;
      PI_io_commit_bits_PRD_3 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_portID <= 2'b00;
      PI_io_commit_bits_PRD_0 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_valid_3 <= 1'b0;
      PI_io_FU_outputs_1_bits_ROB_index <= 6'b000000;
      PI_io_partial_commit_MOB_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_portID <= 2'b00;
      PI_reset <= 1'b0;
      PI_io_partial_commit_PRDold_3 <= 7'b1000011;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs <= 1'b0;
      PI_io_commit_bits_is_misprediction <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_prediction_br_type <= 3'b000;
      PI_io_commit_bits_TOS <= 7'b0000000;
      PI_io_FU_outputs_3_bits_memory_type <= 2'b00;
      PI_io_FU_outputs_2_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_PRD_2 <= 7'b0000000;
      PI_io_commit_bits_fetch_packet_index <= 2'b00;
      PI_io_commit_bits_PRD_1 <= 7'b0000000;
      PI_io_decoded_fetch_packet_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready <= 1'b0;
      PI_io_partial_commit_PRD_1 <= 7'b0000000;
      PI_io_commit_bits_NEXT <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_3 <= 1'b1;
      PI_io_FU_outputs_3_bits_branch_taken <= 1'b0;
      PI_io_commit_bits_RD_3 <= 5'b00000;
      PI_io_FU_outputs_1_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_branch_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_fetch_packet_index <= 2'b00;
      PI_io_partial_commit_valid_0 <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU <= 1'b0;
      PI_io_partial_commit_PRDold_1 <= 7'b1100001;
      PI_io_commit_bits_GHR <= 16'b0000000000000000;
      PI_io_FU_outputs_3_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_valid_bits_2 <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM <= 1'b0;
      PI_io_FU_outputs_1_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1 <= 7'b0000000;
      PI_io_partial_commit_PRD_2 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3 <= 3'b000;
      PI_io_FU_outputs_0_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1 <= 7'b0010000;
      PI_io_FU_outputs_0_bits_RD_valid <= 1'b0;
      PI_io_partial_commit_RD_3 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU <= 1'b0;
      PI_io_partial_commit_ROB_index <= 6'b000000;
      PI_io_partial_commit_RD_1 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1 <= 7'b0000000;
      PI_io_FU_outputs_1_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_0 <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD <= 5'b01000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3 <= 3'b000;
      PI_io_FU_outputs_0_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold <= 7'b0000000;
    end

    // state 2
    if (cycle == 1) begin
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready <= 1'b0;
      PI_io_FU_outputs_2_bits_branch_valid <= 1'b0;
      PI_io_FU_outputs_2_bits_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3 <= 3'b000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid <= 1'b0;
      PI_io_FU_outputs_3_bits_MOB_index <= 4'b0000;
      PI_io_partial_commit_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_portID <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index <= 4'b0000;
      PI_io_partial_commit_valid_3 <= 1'b0;
      PI_io_partial_commit_MOB_index_1 <= 4'b0000;
      PI_io_partial_commit_MOB_valid_1 <= 1'b0;
      PI_io_FU_outputs_3_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD <= 5'b10000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU <= 1'b0;
      PI_io_decoded_fetch_packet_bits_prediction_hit <= 1'b0;
      PI_io_renamed_decoded_fetch_packet_ready <= 1'b1;
      PI_io_FU_outputs_3_bits_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_RD_valid <= 1'b0;
      PI_io_commit_bits_br_type <= 3'b000;
      PI_io_flush <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs <= 1'b0;
      PI_io_FU_outputs_2_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold <= 7'b0000000;
      PI_io_FU_outputs_1_bits_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid <= 1'b0;
      PI_io_partial_commit_PRD_0 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs <= 1'b0;
      PI_io_partial_commit_RD_2 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRD <= 7'b0000000;
      PI_io_partial_commit_MOB_index_2 <= 4'b0000;
      PI_io_FU_outputs_0_bits_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid <= 1'b1;
      PI_io_FU_outputs_0_bits_branch_taken <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type <= 2'b00;
      PI_io_FU_outputs_1_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_0_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_2_bits_RD_valid <= 1'b0;
      PI_io_FU_outputs_3_bits_branch_valid <= 1'b0;
      PI_io_partial_commit_PRD_3 <= 7'b0000000;
      PI_io_commit_bits_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_prediction_target <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_3_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_MOB_index <= 4'b0000;
      PI_io_FU_outputs_2_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3 <= 3'b000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type <= 2'b00;
      PI_io_commit_bits_RD_valid_1 <= 1'b0;
      PI_io_partial_commit_RD_valid_3 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD <= 5'b10000;
      PI_io_partial_commit_PRDold_2 <= 7'b0000000;
      PI_io_FU_outputs_3_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_1_bits_memory_type <= 2'b00;
      PI_io_partial_commit_MOB_valid_3 <= 1'b0;
      PI_io_commit_bits_RD_valid_0 <= 1'b0;
      PI_io_FU_outputs_2_bits_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready <= 1'b0;
      PI_io_FU_outputs_1_bits_access_width <= 2'b00;
      PI_io_commit_bits_T_NT <= 1'b0;
      PI_io_FU_outputs_0_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM <= 1'b0;
      PI_io_FU_outputs_1_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IMM <= 21'b000000000000000000000;
      PI_io_FU_outputs_1_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_GHR <= 16'b0000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type <= 2'b00;
      PI_io_FU_outputs_3_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_partial_commit_valid_1 <= 1'b0;
      PI_io_FU_outputs_1_bits_branch_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT <= 1'b0;
      PI_io_commit_bits_RD_2 <= 5'b00000;
      PI_io_FU_outputs_0_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_3_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT <= 1'b0;
      PI_io_commit_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_commit_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_2_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_1 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index <= 4'b0000;
      PI_io_commit_valid <= 1'b0;
      PI_io_FU_outputs_1_bits_RD_valid <= 1'b0;
      PI_io_partial_commit_PRDold_0 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit <= 1'b0;
      PI_io_FU_outputs_2_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2 <= 7'b0000000;
      PI_io_FU_outputs_2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU <= 1'b0;
      PI_io_partial_commit_MOB_index_0 <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index <= 2'b00;
      PI_io_partial_commit_RD_0 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_portID <= 2'b00;
      PI_io_commit_bits_RD_valid_2 <= 1'b0;
      PI_io_partial_commit_MOB_index_3 <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD <= 5'b10000;
      PI_io_FU_outputs_3_bits_ROB_index <= 6'b000000;
      PI_io_partial_commit_RD_valid_1 <= 1'b0;
      PI_io_FU_outputs_2_bits_branch_taken <= 1'b0;
      PI_io_FU_outputs_0_bits_PRD <= 7'b0000000;
      PI_io_FU_outputs_2_bits_ROB_index <= 6'b000000;
      PI_io_FU_outputs_1_bits_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY <= 1'b0;
      PI_io_FU_outputs_1_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_prediction_T_NT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType <= 5'b00000;
      PI_io_FU_outputs_3_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM <= 1'b0;
      PI_io_FU_outputs_2_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_partial_commit_RD_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type <= 2'b00;
      PI_io_commit_bits_expected_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_1_bits_branch_taken <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index <= 6'b000000;
      PI_io_commit_bits_RD_1 <= 5'b00000;
      PI_io_partial_commit_MOB_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_TOS <= 7'b0000000;
      PI_io_FU_outputs_1_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_NEXT <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_access_width <= 2'b00;
      PI_io_commit_bits_RD_0 <= 5'b00000;
      PI_io_partial_commit_RD_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type <= 2'b00;
      PI_io_commit_bits_PRD_3 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_portID <= 2'b00;
      PI_io_commit_bits_PRD_0 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_valid_3 <= 1'b0;
      PI_io_FU_outputs_1_bits_ROB_index <= 6'b000000;
      PI_io_partial_commit_MOB_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_portID <= 2'b00;
      PI_reset <= 1'b0;
      PI_io_partial_commit_PRDold_3 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs <= 1'b0;
      PI_io_commit_bits_is_misprediction <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_prediction_br_type <= 3'b000;
      PI_io_commit_bits_TOS <= 7'b0000000;
      PI_io_FU_outputs_3_bits_memory_type <= 2'b00;
      PI_io_FU_outputs_2_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_PRD_2 <= 7'b0000000;
      PI_io_commit_bits_fetch_packet_index <= 2'b00;
      PI_io_commit_bits_PRD_1 <= 7'b0000000;
      PI_io_decoded_fetch_packet_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready <= 1'b0;
      PI_io_partial_commit_PRD_1 <= 7'b0000000;
      PI_io_commit_bits_NEXT <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_3 <= 1'b0;
      PI_io_FU_outputs_3_bits_branch_taken <= 1'b0;
      PI_io_commit_bits_RD_3 <= 5'b00000;
      PI_io_FU_outputs_1_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_branch_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_fetch_packet_index <= 2'b00;
      PI_io_partial_commit_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU <= 1'b0;
      PI_io_partial_commit_PRDold_1 <= 7'b0000000;
      PI_io_commit_bits_GHR <= 16'b0000000000000000;
      PI_io_FU_outputs_3_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_valid_bits_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM <= 1'b0;
      PI_io_FU_outputs_1_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid <= 1'b1;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1 <= 7'b0000000;
      PI_io_partial_commit_PRD_2 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3 <= 3'b000;
      PI_io_FU_outputs_0_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_RD_valid <= 1'b0;
      PI_io_partial_commit_RD_3 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU <= 1'b0;
      PI_io_partial_commit_ROB_index <= 6'b000000;
      PI_io_partial_commit_RD_1 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1 <= 7'b0000000;
      PI_io_FU_outputs_1_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD <= 5'b10000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3 <= 3'b000;
      PI_io_FU_outputs_0_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold <= 7'b0000000;
    end

    // state 3
    if (cycle == 2) begin
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready <= 1'b0;
      PI_io_FU_outputs_2_bits_branch_valid <= 1'b0;
      PI_io_FU_outputs_2_bits_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3 <= 3'b000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid <= 1'b0;
      PI_io_FU_outputs_3_bits_MOB_index <= 4'b0000;
      PI_io_partial_commit_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_portID <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index <= 4'b0000;
      PI_io_partial_commit_valid_3 <= 1'b0;
      PI_io_partial_commit_MOB_index_1 <= 4'b0000;
      PI_io_partial_commit_MOB_valid_1 <= 1'b0;
      PI_io_FU_outputs_3_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU <= 1'b0;
      PI_io_decoded_fetch_packet_bits_prediction_hit <= 1'b0;
      PI_io_renamed_decoded_fetch_packet_ready <= 1'b0;
      PI_io_FU_outputs_3_bits_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_RD_valid <= 1'b0;
      PI_io_commit_bits_br_type <= 3'b000;
      PI_io_flush <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs <= 1'b0;
      PI_io_FU_outputs_2_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold <= 7'b0000000;
      PI_io_FU_outputs_1_bits_PRD <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid <= 1'b0;
      PI_io_partial_commit_PRD_0 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs <= 1'b0;
      PI_io_partial_commit_RD_2 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRD <= 7'b0000000;
      PI_io_partial_commit_MOB_index_2 <= 4'b0000;
      PI_io_FU_outputs_0_bits_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_branch_taken <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type <= 2'b00;
      PI_io_FU_outputs_1_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_0_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_2_bits_RD_valid <= 1'b0;
      PI_io_FU_outputs_3_bits_branch_valid <= 1'b0;
      PI_io_partial_commit_PRD_3 <= 7'b0000000;
      PI_io_commit_bits_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_prediction_target <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_3_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_MOB_index <= 4'b0000;
      PI_io_FU_outputs_2_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3 <= 3'b000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type <= 2'b00;
      PI_io_commit_bits_RD_valid_1 <= 1'b0;
      PI_io_partial_commit_RD_valid_3 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RD <= 5'b00000;
      PI_io_partial_commit_PRDold_2 <= 7'b0000000;
      PI_io_FU_outputs_3_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_1_bits_memory_type <= 2'b00;
      PI_io_partial_commit_MOB_valid_3 <= 1'b0;
      PI_io_commit_bits_RD_valid_0 <= 1'b0;
      PI_io_FU_outputs_2_bits_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready <= 1'b0;
      PI_io_FU_outputs_1_bits_access_width <= 2'b00;
      PI_io_commit_bits_T_NT <= 1'b0;
      PI_io_FU_outputs_0_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM <= 1'b0;
      PI_io_FU_outputs_1_bits_wr_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index <= 6'b000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IMM <= 21'b000000000000000000000;
      PI_io_FU_outputs_1_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_GHR <= 16'b0000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type <= 2'b00;
      PI_io_FU_outputs_3_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS1 <= 7'b0000000;
      PI_io_FU_outputs_2_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_partial_commit_valid_1 <= 1'b0;
      PI_io_FU_outputs_1_bits_branch_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRD <= 7'b0000000;
      PI_io_FU_outputs_3_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT <= 1'b0;
      PI_io_commit_bits_RD_2 <= 5'b00000;
      PI_io_FU_outputs_0_bits_address <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_3_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT <= 1'b0;
      PI_io_commit_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_commit_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_2_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_1 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index <= 4'b0000;
      PI_io_commit_valid <= 1'b0;
      PI_io_FU_outputs_1_bits_RD_valid <= 1'b0;
      PI_io_partial_commit_PRDold_0 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit <= 1'b0;
      PI_io_FU_outputs_2_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2 <= 7'b0000000;
      PI_io_FU_outputs_2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU <= 1'b0;
      PI_io_partial_commit_MOB_index_0 <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index <= 2'b00;
      PI_io_partial_commit_RD_0 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_portID <= 2'b00;
      PI_io_commit_bits_RD_valid_2 <= 1'b0;
      PI_io_partial_commit_MOB_index_3 <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS2 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD <= 5'b00000;
      PI_io_FU_outputs_3_bits_ROB_index <= 6'b000000;
      PI_io_partial_commit_RD_valid_1 <= 1'b0;
      PI_io_FU_outputs_2_bits_branch_taken <= 1'b0;
      PI_io_FU_outputs_0_bits_PRD <= 7'b0000000;
      PI_io_FU_outputs_2_bits_ROB_index <= 6'b000000;
      PI_io_FU_outputs_1_bits_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY <= 1'b0;
      PI_io_FU_outputs_1_bits_is_unsigned <= 1'b0;
      PI_io_decoded_fetch_packet_bits_prediction_T_NT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType <= 5'b00000;
      PI_io_FU_outputs_3_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM <= 1'b0;
      PI_io_FU_outputs_2_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_partial_commit_RD_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type <= 2'b00;
      PI_io_commit_bits_expected_PC <= 32'b00000000000000000000000000000000;
      PI_io_FU_outputs_1_bits_branch_taken <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index <= 6'b000000;
      PI_io_commit_bits_RD_1 <= 5'b00000;
      PI_io_partial_commit_MOB_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_TOS <= 7'b0000000;
      PI_io_FU_outputs_1_bits_RD_data <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_NEXT <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_access_width <= 2'b00;
      PI_io_commit_bits_RD_0 <= 5'b00000;
      PI_io_partial_commit_RD_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type <= 2'b00;
      PI_io_commit_bits_PRD_3 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_portID <= 2'b00;
      PI_io_commit_bits_PRD_0 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_valid_3 <= 1'b0;
      PI_io_FU_outputs_1_bits_ROB_index <= 6'b000000;
      PI_io_partial_commit_MOB_valid_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_portID <= 2'b00;
      PI_reset <= 1'b0;
      PI_io_partial_commit_PRDold_3 <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs <= 1'b0;
      PI_io_commit_bits_is_misprediction <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_prediction_br_type <= 3'b000;
      PI_io_commit_bits_TOS <= 7'b0000000;
      PI_io_FU_outputs_3_bits_memory_type <= 2'b00;
      PI_io_FU_outputs_2_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_PRD_2 <= 7'b0000000;
      PI_io_commit_bits_fetch_packet_index <= 2'b00;
      PI_io_commit_bits_PRD_1 <= 7'b0000000;
      PI_io_decoded_fetch_packet_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready <= 1'b0;
      PI_io_partial_commit_PRD_1 <= 7'b0000000;
      PI_io_commit_bits_NEXT <= 7'b0000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_3 <= 1'b0;
      PI_io_FU_outputs_3_bits_branch_taken <= 1'b0;
      PI_io_commit_bits_RD_3 <= 5'b00000;
      PI_io_FU_outputs_1_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_memory_type <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS2 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_branch_valid <= 1'b0;
      PI_io_FU_outputs_0_bits_fetch_packet_index <= 2'b00;
      PI_io_partial_commit_valid_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU <= 1'b0;
      PI_io_partial_commit_PRDold_1 <= 7'b0000000;
      PI_io_commit_bits_GHR <= 16'b0000000000000000;
      PI_io_FU_outputs_3_bits_fetch_packet_index <= 2'b00;
      PI_io_decoded_fetch_packet_bits_valid_bits_2 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM <= 1'b0;
      PI_io_FU_outputs_1_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RS1 <= 7'b0000000;
      PI_io_partial_commit_PRD_2 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_access_width <= 2'b00;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3 <= 3'b000;
      PI_io_FU_outputs_0_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_RS1 <= 7'b0000000;
      PI_io_FU_outputs_0_bits_RD_valid <= 1'b0;
      PI_io_partial_commit_RD_3 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU <= 1'b0;
      PI_io_partial_commit_ROB_index <= 6'b000000;
      PI_io_partial_commit_RD_1 <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index <= 4'b0000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_IMM <= 21'b000000000000000000000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_RS1 <= 7'b0000000;
      PI_io_FU_outputs_1_bits_target_address <= 32'b00000000000000000000000000000000;
      PI_io_decoded_fetch_packet_bits_valid_bits_0 <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_RD <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3 <= 3'b000;
      PI_io_FU_outputs_0_valid <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM <= 1'b0;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType <= 5'b00000;
      PI_io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold <= 7'b0000000;
    end

    genclock <= cycle < 3;
    cycle <= cycle + 1;
  end
endmodule

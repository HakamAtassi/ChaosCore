typedef struct {
    logic [32-1:0] fetch_PC;
    ERROR
    ERROR
} fetch_packet;

typedef struct {
    log2Ceil set_bits;
    32 - log2Ceil(L1_instructionCacheBlockSizeBytes) tag_bits;
    log2Ceil instruction_offset_bits;
    log2Ceil fetch_packet_bits;
    logic [tag_bits-1:0] tag;
    logic [set_bits-1:0] set;
    logic [fetch_packet_bits-1:0] fetch_packet;
    logic [instruction_offset_bits-1:0] instruction_offset;
} instruction_cache_address_packet;

typedef struct {
    decoded_instruction(parameters) decoded_instruction;
    logic [32-1:0] RS1_data;
    logic [32-1:0] RS2_data;
    logic [32-1:0] fetch_PC;
} read_decoded_instruction;

typedef struct {
    logic hit;
    logic [32-1:0] target;
    _br_type br_type;
    logic [GHRWidth-1:0] GHR;
    logic T_NT;
} prediction;

typedef struct {
    logic row_valid;
    logic [32-1:0] fetch_PC;
    logic [log2Ceil(RATCheckpointCount)-1:0] RAT_index;
    logic [log2Ceil(ROBEntries)-1:0] ROB_index;
    logic [physicalRegBits + 1-1:0] free_list_front_pointer;
    ERROR
    ERROR
} ROB_output;

typedef struct {
    logic [32-1:0] addr;
    logic [32-1:0] wr_data;
    logic wr_en;
} memory_request;

typedef struct {
    logic valid;
    memory_type_t memory_type;
    logic [log2Ceil(ROBEntries)-1:0] ROB_index;
    logic [32-1:0] address;
    access_width_t access_width;
    logic [physicalRegBits-1:0] RD;
    logic [32-1:0] data;
    logic pending;
    logic loaded;
    logic committed;
    logic violation;
    logic fired;
} MOB_entry;

typedef struct {
    logic busy;
    logic exception;
} ROB_WB;

typedef struct {
    decoded_instruction(parameters) decoded_instruction;
    logic valid;
} RS_entry;

typedef struct {
    log2Ceil nextBits;
    log2Ceil tosBits;
    log2Ceil nosBits;
    logic [32-1:0] PC;
} revert;

typedef struct {
    32 - log2Ceil(BTBEntries) BTB_tag_size;
    logic BTB_valid;
    logic [BTB_tag_size-1:0] BTB_tag;
    logic [32-1:0] BTB_target;
    _br_type BTB_br_type;
    logic [log2Ceil(fetchWidth)-1:0] BTB_fetch_packet_index;
} BTB_entry;

typedef struct {
    logic [32-1:0] data;
} memory_response;

typedef struct {
    logic [32-1:0] call_addr;
    logic call;
    logic ret;
} RAS_update;

typedef struct {
    logic [32-1:0] fetch_PC;
    logic T_NT;
    logic [log2Ceil(ROBEntries)-1:0] ROB_index;
    _br_type br_type;
    logic [log2Ceil(fetchWidth)-1:0] fetch_packet_index;
    logic is_misprediction;
    logic [32-1:0] expected_PC;
    logic [GHRWidth-1:0] GHR;
    logic [log2Ceil(RASEntries)-1:0] TOS;
    logic [log2Ceil(RASEntries)-1:0] NEXT;
    logic [log2Ceil(RATCheckpointCount)-1:0] RAT_index;
    logic [physicalRegBits + 1-1:0] free_list_front_pointer;
    ERROR
    ERROR
} commit;

typedef struct {
    logic [32-1:0] addr;
    logic [32-1:0] data;
    memory_type_t memory_type;
    access_width_t access_width;
    logic [log2Ceil(MOBEntries)-1:0] MOB_index;
} backend_memory_request;

typedef struct {
    log2Ceil set_bits;
    log2Ceil byte_offset_bits;
    32 - set_bits tag_bits;
    L1_instructionCacheBlockSizeBytes data_bits;
    logic valid;
    logic [tag_bits-1:0] tag;
    logic [data_bits-1:0] data;
} instruction_cache_data_line;

typedef struct {
    decoded_instruction(parameters) decoded_instruction;
    logic [32-1:0] fetch_PC;
    logic committed;
    logic valid;
} MEMRS_entry;

typedef struct {
    logic [32-1:0] addr;
    logic [32-1:0] wr_data;
    logic wr_en;
} DRAM_request;

typedef struct {
    logic [32-1:0] fetch_PC;
    logic [log2Ceil(RATCheckpointCount)-1:0] RAT_index;
    logic [physicalRegBits + 1-1:0] free_list_front_pointer;
} ROB_shared;

typedef struct {
    logic valid;
    logic is_branch;
    memory_type_t memory_type;
    logic [physicalRegBits-1:0] RD;
    logic RD_valid;
} ROB_entry;

typedef struct {
    logic RS1_ready;
    logic RS2_ready;
} sources_ready;

typedef struct {
    logic [log2Ceil(RASEntries)-1:0] NEXT;
    logic [log2Ceil(RASEntries)-1:0] TOS;
    logic [32-1:0] ret_addr;
} RAS_read;

typedef struct {
    memory_type_t memory_type;
    logic [physicalRegBits-1:0] RD;
    access_width_t access_width;
    logic unsigned;
    logic [32-1:0] address;
    logic [32-1:0] wr_data;
} memory_access;

typedef struct {
    logic [32-1:0] fetch_PC;
    ERROR
    ERROR
    logic [log2Ceil(RATCheckpointCount)-1:0] RAT_index;
    logic [physicalRegBits + 1-1:0] free_list_front_pointer;
} decoded_fetch_packet;

typedef struct {
    logic [physicalRegBits-1:0] RD;
    logic [32-1:0] RD_data;
    logic RD_valid;
    logic [32-1:0] fetch_PC;
    logic branch_taken;
    logic [32-1:0] target_address;
    logic branch_valid;
    logic [32-1:0] address;
    memory_type_t memory_type;
    access_width_t access_width;
    logic unsigned;
    logic [32-1:0] wr_data;
    logic [log2Ceil(MOBEntries)-1:0] MOB_index;
    logic [log2Ceil(ROBEntries)-1:0] ROB_index;
    logic [log2Ceil(FTQEntries)-1:0] FTQ_index;
    logic [log2Ceil(fetchWidth)-1:0] fetch_packet_index;
} FU_output;

typedef struct {
    logic valid;
    logic is_misprediction;
    logic [32-1:0] expected_PC;
    logic [GHRWidth-1:0] GHR;
    logic [log2Ceil(RASEntries)-1:0] NEXT;
    logic [log2Ceil(RASEntries)-1:0] TOS;
} misprediction;

typedef struct {
    _br_type br_type;
    logic [32-1:0] Imm;
    logic [32-1:0] instruction_PC;
    logic [32-1:0] RAS;
    logic [32-1:0] BTB_target;
    logic is_control;
} metadata;

typedef struct {
    logic [32-1:0] instruction;
    logic [log2Ceil(fetchWidth*4)-1:0] packet_index;
    logic [log2Ceil(ROBEntries)-1:0] ROB_index;
} Instruction;

typedef struct {
    logic [32-1:0] addr;
    logic [32-1:0] data;
    memory_type_t memory_type;
    access_width_t access_width;
    logic [log2Ceil(MOBEntries)-1:0] MOB_index;
} backend_memory_response;

typedef struct {
    logic [32-1:0] PC;
    logic [fetchWidth-1:0] index;
} PC_file;

typedef struct {
    sources_ready() ready_bits;
    logic [physicalRegBits-1:0] RD;
    logic RD_valid;
    logic [physicalRegBits-1:0] RS1;
    logic RS1_valid;
    logic [physicalRegBits-1:0] RS2;
    logic RS2_valid;
    logic [21-1:0] IMM;
    logic [3-1:0] FUNCT3;
    logic [log2Ceil(fetchWidth)-1:0] packet_index;
    logic [log2Ceil(ROBEntries)-1:0] ROB_index;
    logic [log2Ceil(MOBEntries)-1:0] MOB_index;
    logic [log2Ceil(FTQEntries)-1:0] FTQ_index;
    InstructionType instructionType;
    logic [log2Ceil(4)-1:0] portID;
    RS_types RS_type;
    logic needs_ALU;
    logic needs_branch_unit;
    logic needs_CSRs;
    logic SUBTRACT;
    logic MULTIPLY;
    logic IS_IMM;
    memory_type_t memory_type;
    access_width_t access_width;
} decoded_instruction;

typedef struct {
    logic [256-1:0] data;
} DRAM_response;

typedef struct {
    logic valid;
    logic [32-1:0] fetch_PC;
    logic is_misprediction;
    logic [32-1:0] predicted_PC;
    logic T_NT;
    _br_type br_type;
    logic [GHRWidth-1:0] GHR;
    logic [log2Ceil(RASEntries)-1:0] NEXT;
    logic [log2Ceil(RASEntries)-1:0] TOS;
    logic [log2Ceil(fetchWidth)-1:0] dominant_index;
    logic [32-1:0] resolved_PC;
} FTQ_entry;


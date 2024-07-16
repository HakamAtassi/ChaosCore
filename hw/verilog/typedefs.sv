interface fetch_packet;
    logic[1-1:0] fetch_PC;
    logic[fetchWidth-1:0] valid_bits[fetchWidth];
    Instruction instructions[fetchWidth]();
endinterface;

interface instruction_cache_address_packet;
    localparam set_bits = $clog2(L1_instructionCacheSets);
    localparam tag_bits = 32 - $clog2(L1_instructionCacheBlockSizeBytes)-set_bits;
    localparam instruction_offset_bits = $clog2(L1_instructionCacheBlockSizeBytes/4);
    localparam fetch_packet_bits = $clog2(L1_instructionCacheBlockSizeBytes/4/fetchWidth);
    logic[tag_bits-1:0] tag;
    logic[set_bits-1:0] set;
    logic[fetch_packet_bits-1:0] fetch_packet;
    logic[instruction_offset_bits-1:0] instruction_offset;
endinterface;

interface read_decoded_instruction;
    decoded_instruction decoded_instruction();
    logic[1-1:0] RS1_data;
    logic[1-1:0] RS2_data;
    logic[1-1:0] fetch_PC;
endinterface;

interface prediction;
    logic[1-1:0] hit;
    logic[1-1:0] target;
    br_type_t br_type;
    logic[GHRWidth-1:0] GHR;
    logic[1-1:0] T_NT;
endinterface;

interface ROB_output;
    logic[1-1:0] row_valid;
    logic[1-1:0] fetch_PC;
    logic[1-1:0] RAT_index;
    logic[1-1:0] ROB_index;
    logic[1-1:0] free_list_front_pointer;
    ROB_entry ROB_entries[fetchWidth]();
    logic[fetchWidth-1:0] complete[fetchWidth];
endinterface;

interface memory_request;
    logic[1-1:0] addr;
    logic[1-1:0] wr_data;
    logic[1-1:0] wr_en;
endinterface;

interface MOB_entry;
    logic[1-1:0] valid;
    memory_type_t memory_type;
    logic[1-1:0] ROB_index;
    logic[1-1:0] address;
    access_width_t access_width;
    logic[physicalRegBits-1:0] RD;
    logic[1-1:0] data;
    logic[1-1:0] pending;
    logic[1-1:0] loaded;
    logic[1-1:0] committed;
    logic[1-1:0] violation;
    logic[1-1:0] fired;
endinterface;

interface ROB_WB;
    logic[1-1:0] busy;
    logic[1-1:0] exception;
endinterface;

interface RS_entry;
    decoded_instruction decoded_instruction();
    logic[1-1:0] valid;
endinterface;

interface decoded_instruction;
    sources_ready ready_bits();
    logic[physicalRegBits-1:0] RD;
    logic[1-1:0] RD_valid;
    logic[physicalRegBits-1:0] RS1;
    logic[1-1:0] RS1_valid;
    logic[physicalRegBits-1:0] RS2;
    logic[1-1:0] RS2_valid;
    logic[1-1:0] IMM;
    logic[1-1:0] FUNCT3;
    logic[1-1:0] packet_index;
    logic[1-1:0] ROB_index;
    logic[1-1:0] MOB_index;
    logic[1-1:0] FTQ_index;
    InstructionType instructionType;
    logic[1-1:0] portID;
    RS_types RS_type;
    logic[1-1:0] needs_ALU;
    logic[1-1:0] needs_branch_unit;
    logic[1-1:0] needs_CSRs;
    logic[1-1:0] SUBTRACT;
    logic[1-1:0] MULTIPLY;
    logic[1-1:0] IS_IMM;
    memory_type_t memory_type;
    access_width_t access_width;
endinterface;

interface revert;
    localparam nextBits = $clog2(RASEntries);
    localparam tosBits = $clog2(RASEntries);
    localparam nosBits = $clog2(RASEntries);
    logic[1-1:0] PC;
endinterface;

interface BTB_entry;
    localparam BTB_tag_size = 32 - $clog2(BTBEntries) - 2;
    logic[1-1:0] BTB_valid;
    logic[BTB_tag_size-1:0] BTB_tag;
    logic[1-1:0] BTB_target;
    br_type_t BTBbr_type_t;
    logic[1-1:0] BTB_fetch_packet_index;
endinterface;

interface memory_response;
    logic[1-1:0] data;
endinterface;

interface RAS_update;
    logic[1-1:0] call_addr;
    logic[1-1:0] call;
    logic[1-1:0] ret;
endinterface;

interface commit;
    logic[1-1:0] fetch_PC;
    logic[1-1:0] T_NT;
    logic[1-1:0] ROB_index;
    br_type_t br_type;
    logic[1-1:0] fetch_packet_index;
    logic[1-1:0] is_misprediction;
    logic[1-1:0] expected_PC;
    logic[GHRWidth-1:0] GHR;
    logic[1-1:0] TOS;
    logic[1-1:0] NEXT;
    logic[1-1:0] RAT_index;
    logic[1-1:0] free_list_front_pointer;
    logic[fetchWidth-1:0] RD[fetchWidth];
    logic[fetchWidth-1:0] RD_valid[fetchWidth];
endinterface;

interface backend_memory_request;
    logic[1-1:0] addr;
    logic[1-1:0] data;
    memory_type_t memory_type;
    access_width_t access_width;
    logic[1-1:0] MOB_index;
endinterface;

interface instruction_cache_data_line;
    localparam set_bits = $clog2(L1_instructionCacheSets);
    localparam byte_offset_bits = $clog2(L1_instructionCacheBlockSizeBytes);
    localparam tag_bits = 32 - set_bits - byte_offset_bits;
    localparam data_bits = L1_instructionCacheBlockSizeBytes*8;
    logic[1-1:0] valid;
    logic[tag_bits-1:0] tag;
    logic[data_bits-1:0] data;
endinterface;

interface MEMRS_entry;
    decoded_instruction decoded_instruction();
    logic[1-1:0] fetch_PC;
    logic[1-1:0] committed;
    logic[1-1:0] valid;
endinterface;

interface DRAM_request;
    logic[1-1:0] addr;
    logic[1-1:0] wr_data;
    logic[1-1:0] wr_en;
endinterface;

interface ROB_shared;
    logic[1-1:0] fetch_PC;
    logic[1-1:0] RAT_index;
    logic[1-1:0] free_list_front_pointer;
endinterface;

interface ROB_entry;
    logic[1-1:0] valid;
    logic[1-1:0] is_branch;
    memory_type_t memory_type;
    logic[physicalRegBits-1:0] RD;
    logic[1-1:0] RD_valid;
endinterface;

interface sources_ready;
    logic[1-1:0] RS1_ready;
    logic[1-1:0] RS2_ready;
endinterface;

interface RAS_read;
    logic[1-1:0] NEXT;
    logic[1-1:0] TOS;
    logic[1-1:0] ret_addr;
endinterface;

interface memory_access;
    memory_type_t memory_type;
    logic[physicalRegBits-1:0] RD;
    access_width_t access_width;
    logic[1-1:0] is_unsigned;
    logic[1-1:0] address;
    logic[1-1:0] wr_data;
endinterface;

interface decoded_fetch_packet;
    logic[1-1:0] fetch_PC;
    decoded_instruction decoded_instruction[fetchWidth]();
    logic[fetchWidth-1:0] valid_bits[fetchWidth];
    logic[1-1:0] RAT_index;
    logic[1-1:0] free_list_front_pointer;
endinterface;

interface FU_output;
    logic[physicalRegBits-1:0] RD;
    logic[1-1:0] RD_data;
    logic[1-1:0] RD_valid;
    logic[1-1:0] fetch_PC;
    logic[1-1:0] branch_taken;
    logic[1-1:0] target_address;
    logic[1-1:0] branch_valid;
    logic[1-1:0] address;
    memory_type_t memory_type;
    access_width_t access_width;
    logic[1-1:0] is_unsigned;
    logic[1-1:0] wr_data;
    logic[1-1:0] MOB_index;
    logic[1-1:0] ROB_index;
    logic[1-1:0] FTQ_index;
    logic[1-1:0] fetch_packet_index;
endinterface;

interface misprediction;
    logic[1-1:0] valid;
    logic[1-1:0] is_misprediction;
    logic[1-1:0] expected_PC;
    logic[GHRWidth-1:0] GHR;
    logic[1-1:0] NEXT;
    logic[1-1:0] TOS;
endinterface;

interface metadata;
    br_type_t br_type;
    logic[1-1:0] Imm;
    logic[1-1:0] instruction_PC;
    logic[1-1:0] RAS;
    logic[1-1:0] BTB_target;
    logic[1-1:0] is_control;
endinterface;

interface Instruction;
    logic[1-1:0] instruction;
    logic[1-1:0] packet_index;
    logic[1-1:0] ROB_index;
endinterface;

interface backend_memory_response;
    logic[1-1:0] addr;
    logic[1-1:0] data;
    memory_type_t memory_type;
    access_width_t access_width;
    logic[1-1:0] MOB_index;
endinterface;

interface DRAM_response;
    logic[1-1:0] data;
endinterface;

interface FTQ_entry;
    logic[1-1:0] valid;
    logic[1-1:0] fetch_PC;
    logic[1-1:0] is_misprediction;
    logic[1-1:0] predicted_PC;
    logic[1-1:0] T_NT;
    br_type_t br_type;
    logic[GHRWidth-1:0] GHR;
    logic[1-1:0] NEXT;
    logic[1-1:0] TOS;
    logic[1-1:0] dominant_index;
    logic[1-1:0] resolved_PC;
endinterface;


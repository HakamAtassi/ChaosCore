def generate_null_allocate():
    allocate_input = {}
    allocate_input["valid"]                        =  0
    allocate_input["fetch_PC"]                     =  0
    allocate_input["RS1_ready"]                    =  [0]*4
    allocate_input["RS2_ready"]                    =  [0]*4
    allocate_input["RD"]                           =  [0]*4
    allocate_input["RD_valid"]                     =  [0]*4
    allocate_input["RS1"]                          =  [0]*4
    allocate_input["RS1_valid"]                    =  [0]*4
    allocate_input["RS2"]                          =  [0]*4
    allocate_input["RS2_valid"]                    =  [0]*4
    allocate_input["IMM"]                          =  [0]*4
    allocate_input["FUNCT3"]                       =  [0]*4
    allocate_input["packet_index"]                 =  [0]*4
    allocate_input["ROB_index"]                    =  [0]*4
    allocate_input["instructionType"]              =  [0]*4
    allocate_input["portID"]                       =  [0]*4
    allocate_input["RS_type"]                      =  [0]*4
    allocate_input["needs_ALU"]                    =  [0]*4
    allocate_input["needs_branch_unit"]            =  [0]*4
    allocate_input["needs_CSRs"]                   =  [0]*4
    allocate_input["SUBTRACT"]                     =  [0]*4
    allocate_input["MULTIPLY"]                     =  [0]*4
    allocate_input["IMMEDIATE"]                    =  [0]*4
    allocate_input["is_branch"]                    =  [0]*4
    allocate_input["IS_LOAD"]                      =  [0]*4
    allocate_input["IS_STORE"]                     =  [0]*4
    allocate_input["valid_bits"]                   =  [0]*4

    return allocate_input

def generate_null_FU_outputs():

    FU_inputs = {}

    FU_inputs["valid"]              = [0]*4
    FU_inputs["RD"]                 = [0]*4
    FU_inputs["RD_data"]            = [0]*4
    FU_inputs["RD_valid"]           = [0]*4
    FU_inputs["instruction_PC"]     = [0]*4
    FU_inputs["branch_taken"]       = [0]*4
    FU_inputs["target_address"]     = [0]*4
    FU_inputs["branch_valid"]       = [0]*4
    FU_inputs["ROB_index"]          = [0]*4
    FU_inputs["fetch_packet_index"] = [0]*4

    return FU_inputs

def generate_null_commit():
    commit_inputs = {}
    commit_inputs["valid"] = 0
    commit_inputs["fetch_PC"] = 0
    commit_inputs["T_NT"] = 0
    commit_inputs["ROB_index"] = 0
    commit_inputs["br_type"] = 0
    commit_inputs["fetch_packet_index"] = 0
    commit_inputs["is_misprediction"] = 0
    commit_inputs["expected_PC"] = 0
    commit_inputs["GHR"] = 0
    commit_inputs["TOS"] = 0
    commit_inputs["NEXT"] = 0
    commit_inputs["RAT_IDX"] = 0
    return commit_inputs

def generate_null_PC_file_inputs():
    PC_file_inputs = {}
    PC_file_inputs["addr"]                        =  0
    return PC_file_inputs



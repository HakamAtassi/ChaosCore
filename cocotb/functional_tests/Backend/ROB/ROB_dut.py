import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate
from cocotb.binary import BinaryValue

def generate_null_allocate():
    allocate_input = {}
    allocate_input["valid"]                        =  0
    allocate_input["fetch_PC"]                     =  0
    allocate_input["RS1_ready"]                    =  [0, 0, 0, 0]
    allocate_input["RS2_ready"]                    =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [0, 0, 0, 0]
    allocate_input["IS_STORE"]                     =  [0, 0, 0, 0]
    allocate_input["valid_bits"]                   =  [0, 0, 0, 0]

    return allocate_input

def generate_null_FU_inputs():

    FU_inputs = {}

    FU_inputs["valid"] = [0, 0, 0, 0]
    FU_inputs["RD"] = [0, 0, 0, 0]
    FU_inputs["RD_data"] = [0, 0, 0, 0]
    FU_inputs["RD_valid"] = [0, 0, 0, 0]
    FU_inputs["instruction_PC"] = [0, 0, 0, 0]
    FU_inputs["branch_taken"] = [0, 0, 0, 0]
    FU_inputs["target_address"] = [0, 0, 0, 0]
    FU_inputs["branch_valid"] = [0, 0, 0, 0]
    FU_inputs["ROB_index"] = [0, 0, 0, 0]
    FU_inputs["fetch_packet_index"] = [0, 0, 0, 0]

    return FU_inputs



class ROB_dut:
    def __init__(self, dut):    # modify as needed (parameters, etc...)
        self.dut = dut

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0

    def write_allocate(self, allocate_inputs = generate_null_allocate()):
        getattr(self.dut, f"io_ROB_packet_valid").value                                                   = allocate_inputs["valid"]      
        getattr(self.dut, f"io_ROB_packet_bits_fetch_PC").value                                           = allocate_inputs["fetch_PC"]
        for i in range(4):
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value   = allocate_inputs["RS1_ready"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value   = allocate_inputs["RS2_ready"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD").value                     = allocate_inputs["RD"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD_valid").value               = allocate_inputs["RD_valid"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1").value                    = allocate_inputs["RS1"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1_valid").value              = allocate_inputs["RS1_valid"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2") .value                   = allocate_inputs["RS2"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2_valid").value              = allocate_inputs["RS2_valid"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMM").value                    = allocate_inputs["IMM"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_FUNCT3").value                 = allocate_inputs["FUNCT3"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_packet_index").value           = allocate_inputs["packet_index"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ROB_index").value              = allocate_inputs["ROB_index"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_instructionType").value        = allocate_inputs["instructionType"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_portID").value                 = allocate_inputs["portID"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS_type").value                = allocate_inputs["RS_type"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_ALU").value              = allocate_inputs["needs_ALU"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_branch_unit").value      = allocate_inputs["needs_branch_unit"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_CSRs").value             = allocate_inputs["needs_CSRs"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_SUBTRACT").value               = allocate_inputs["SUBTRACT"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_MULTIPLY").value               = allocate_inputs["MULTIPLY"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMMEDIATE").value              = allocate_inputs["IMMEDIATE"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_LOAD").value                = allocate_inputs["IS_LOAD"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_STORE").value               = allocate_inputs["IS_STORE"][i]
            getattr(self.dut, f"io_ROB_packet_bits_valid_bits_{i}").value                                 = allocate_inputs["valid_bits"][i]




    def get_shared_mem(self):
        shared_mem={}
        shared_mem["row_valid"] = [0]*64
        shared_mem["fetch_PC"]  = [0]*64
        shared_mem["RAT_IDX"]   = [0]*64

        for i in range(64):
            line = int(getattr(self.dut, f"shared_mem.mem_ext.Memory")[i].value)
            line = BinaryValue(value=line, n_bits=37, bigEndian=False)

            shared_mem["row_valid"][i]  = int(line[0])
            shared_mem["fetch_PC"][i]   = int(line[32:1])
            shared_mem["RAT_IDX"][i]    = int(line[36:33])
        return shared_mem

    def get_WB_mem(self):
        ROB_entries = []
        for bank in range(4):
            WB_mem={}
            WB_mem["busy"]      = [0]*64
            WB_mem["exception"]  = [0]*64

            for i in range(64):
                line = int(getattr(self.dut, f"ROB_WB_banks_{bank}.mem_ext.Memory")[i].value)
                line = BinaryValue(value=line, n_bits=2, bigEndian=False)
                WB_mem["busy"][i]         = int(line[0])
                WB_mem["exception"][i]    = int(line[1])

            ROB_entries.append(WB_mem)

        return ROB_entries


    def get_ROB_entry(self):
        ROB_entries = []
        for bank in range(4):
            entry_mem={}
            entry_mem["valid"]      = [0]*64
            entry_mem["is_branch"]  = [0]*64
            entry_mem["is_load"]    = [0]*64
            entry_mem["is_store"]   = [0]*64

            for i in range(64):
                line = int(getattr(self.dut, f"ROB_entry_banks_{bank}.mem_ext.Memory")[i].value)
                line = BinaryValue(value=line, n_bits=4, bigEndian=False)
                entry_mem["valid"][i]      = int(line[0])
                entry_mem["is_branch"][i]  = int(line[1])
                entry_mem["is_load"][i]    = int(line[2])
                entry_mem["is_store"][i]   = int(line[3])

            ROB_entries.append(entry_mem)

        return ROB_entries

    def print_ROB(self, bank):
        shared_mem = self.get_shared_mem()
        WB_mem = self.get_WB_mem()
        entry_mem = self.get_ROB_entry()

        # Create headers for each part of the row
        shared_headers  = ["row_valid", "fetch_PC", "RAT_IDX"]
        wb_headers      = ["busy", "exception"]
        entry_headers   = [f"Valid[{bank}]", f"Branch[{bank}]", f"Load[{bank}]", f"Store[{bank}]"]

        header = shared_headers + wb_headers + entry_headers

        rows = []
        for i in range(64):
            row = [
                shared_mem["row_valid"][i],
                shared_mem["fetch_PC"][i],
                shared_mem["RAT_IDX"][i]
            ]

            row.append(WB_mem[bank]["busy"][i])
            row.append(WB_mem[bank]["exception"][i])

            row.append(entry_mem[bank]["valid"][i])
            row.append(entry_mem[bank]["is_branch"][i])
            row.append(entry_mem[bank]["is_load"][i])
            row.append(entry_mem[bank]["is_store"][i])

            rows.append(row)

        # Print the tabulated data
        print(tabulate(rows, headers=header, tablefmt="grid"))

    def get_allocate_ready(self):
        return self.dut.io_ROB_packet_ready.value

    def write_FU(self, FU_inputs = generate_null_FU_inputs()):

        for i in range(4):
            getattr(self.dut, f"io_FU_outputs_{i}_valid").value                       = FU_inputs["valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD").value                     = FU_inputs["RD"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value                = FU_inputs["RD_data"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value               = FU_inputs["RD_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_instruction_PC").value         = FU_inputs["instruction_PC"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value           = FU_inputs["branch_taken"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value         = FU_inputs["target_address"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value           = FU_inputs["branch_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value              = FU_inputs["ROB_index"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value     = FU_inputs["fetch_packet_index"][i]


#    def get_commit(self):

        #commit = {}

        #commit["valid"]             = getattr(self.dut, f"io_commit_valid").value
        #commit["fetch_PC"]          = getattr(self.dut, f"io_commit_fetch_PC").value
        #commit["T_NT"]              = getattr(self.dut, f"io_commit_T_NT").value
        #commit["br_type"]           = getattr(self.dut, f"io_commit_br_type").value
        #commit["packet_index"]      = getattr(self.dut, f"io_commit_fetch_packet_index").value
        #commit["is_misprediction"]  = getattr(self.dut, f"io_commit_is_misprediction").value
        #commit["expected_PC"]       = getattr(self.dut, f"io_commit_expected_PC").value
        #commit["GHR"]               = getattr(self.dut, f"io_commit_GHR").value
        #commit["TOS"]               = getattr(self.dut, f"io_commit_TOS").value
        #commit["NEXT"]              = getattr(self.dut, f"io_commit_NEXT").value
        #commit["RAT_IDX"]           = getattr(self.dut, f"io_commit_RAT_IDX").value

        #return commit

    def get_ROB_output(self):
        ROB_output = {}

        ROB_output["valid"] = getattr(self.dut, f"io_ROB_output_valid")
        ROB_output["fetch_PC"] = getattr(self.dut, f"io_ROB_output_bits_fetch_PC")
        ROB_output["RAT_IDX"] = getattr(self.dut, f"io_ROB_output_bits_RAT_IDX")
        ROB_output["ROB_index"]  = getattr(self.dut, f"io_ROB_index")
        
        ROB_output["entry_valid"]   = [0]*4
        ROB_output["is_branch"]     = [0]*4
        ROB_output["is_load"]       = [0]*4
        ROB_output["is_store"]      = [0]*4

        for i in range(4):
            ROB_output["entry_valid"][i]      = getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_valid")
            ROB_output["is_branch"][i]  = getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_branch")
            ROB_output["is_load"][i]    = getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_load")
            ROB_output["is_store"][i]   = getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_store")
        
        return ROB_output


    """
    input         clock,
                    reset,
    output        io_ROB_packet_ready,
    input         io_ROB_packet_valid,
  input  [31:0] io_ROB_packet_bits_fetch_PC,
  input         io_ROB_packet_bits_decoded_instruction_0_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_0_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_RD,
  input         io_ROB_packet_bits_decoded_instruction_0_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_RS1,
  input         io_ROB_packet_bits_decoded_instruction_0_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_RS2,
  input         io_ROB_packet_bits_decoded_instruction_0_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_0_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_0_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_0_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_0_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_0_portID,
                io_ROB_packet_bits_decoded_instruction_0_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_0_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_0_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_0_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_0_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_0_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_0_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_0_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_0_IS_STORE,
                io_ROB_packet_bits_decoded_instruction_1_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_1_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_RD,
  input         io_ROB_packet_bits_decoded_instruction_1_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_RS1,
  input         io_ROB_packet_bits_decoded_instruction_1_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_RS2,
  input         io_ROB_packet_bits_decoded_instruction_1_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_1_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_1_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_1_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_1_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_1_portID,
                io_ROB_packet_bits_decoded_instruction_1_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_1_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_1_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_1_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_1_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_1_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_1_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_1_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_1_IS_STORE,
                io_ROB_packet_bits_decoded_instruction_2_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_2_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_RD,
  input         io_ROB_packet_bits_decoded_instruction_2_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_RS1,
  input         io_ROB_packet_bits_decoded_instruction_2_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_RS2,
  input         io_ROB_packet_bits_decoded_instruction_2_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_2_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_2_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_2_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_2_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_2_portID,
                io_ROB_packet_bits_decoded_instruction_2_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_2_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_2_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_2_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_2_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_2_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_2_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_2_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_2_IS_STORE,
                io_ROB_packet_bits_decoded_instruction_3_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_3_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_RD,
  input         io_ROB_packet_bits_decoded_instruction_3_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_RS1,
  input         io_ROB_packet_bits_decoded_instruction_3_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_RS2,
  input         io_ROB_packet_bits_decoded_instruction_3_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_3_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_3_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_3_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_3_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_3_portID,
                io_ROB_packet_bits_decoded_instruction_3_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_3_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_3_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_3_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_3_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_3_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_3_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_3_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_3_IS_STORE,
                io_ROB_packet_bits_valid_bits_0,
                io_ROB_packet_bits_valid_bits_1,
                io_ROB_packet_bits_valid_bits_2,
                io_ROB_packet_bits_valid_bits_3,
  input  [3:0]  io_ROB_packet_bits_RAT_IDX,
  input         io_FU_outputs_0_valid,
  input  [63:0] io_FU_outputs_0_bits_RD,
  input  [31:0] io_FU_outputs_0_bits_RD_data,
  input         io_FU_outputs_0_bits_RD_valid,
  input  [31:0] io_FU_outputs_0_bits_instruction_PC,
  input         io_FU_outputs_0_bits_branch_taken,
  input  [31:0] io_FU_outputs_0_bits_target_address,
  input         io_FU_outputs_0_bits_branch_valid,
  input  [5:0]  io_FU_outputs_0_bits_ROB_index,
  input  [1:0]  io_FU_outputs_0_bits_fetch_packet_index,
  input         io_FU_outputs_1_valid,
  input  [63:0] io_FU_outputs_1_bits_RD,
  input  [31:0] io_FU_outputs_1_bits_RD_data,
  input         io_FU_outputs_1_bits_RD_valid,
  input  [31:0] io_FU_outputs_1_bits_instruction_PC,
  input         io_FU_outputs_1_bits_branch_taken,
  input  [31:0] io_FU_outputs_1_bits_target_address,
  input         io_FU_outputs_1_bits_branch_valid,
  input  [5:0]  io_FU_outputs_1_bits_ROB_index,
  input  [1:0]  io_FU_outputs_1_bits_fetch_packet_index,
  input         io_FU_outputs_2_valid,
  input  [63:0] io_FU_outputs_2_bits_RD,
  input  [31:0] io_FU_outputs_2_bits_RD_data,
  input         io_FU_outputs_2_bits_RD_valid,
  input  [31:0] io_FU_outputs_2_bits_instruction_PC,
  input         io_FU_outputs_2_bits_branch_taken,
  input  [31:0] io_FU_outputs_2_bits_target_address,
  input         io_FU_outputs_2_bits_branch_valid,
  input  [5:0]  io_FU_outputs_2_bits_ROB_index,
  input  [1:0]  io_FU_outputs_2_bits_fetch_packet_index,
  input         io_FU_outputs_3_valid,
  input  [63:0] io_FU_outputs_3_bits_RD,
  input  [31:0] io_FU_outputs_3_bits_RD_data,
  input         io_FU_outputs_3_bits_RD_valid,
  input  [31:0] io_FU_outputs_3_bits_instruction_PC,
  input         io_FU_outputs_3_bits_branch_taken,
  input  [31:0] io_FU_outputs_3_bits_target_address,
  input         io_FU_outputs_3_bits_branch_valid,
  input  [5:0]  io_FU_outputs_3_bits_ROB_index,
  input  [1:0]  io_FU_outputs_3_bits_fetch_packet_index,
  output        io_ROB_output_valid,
  output [31:0] io_ROB_output_bits_fetch_PC,
  output [3:0]  io_ROB_output_bits_RAT_IDX,
  output        io_ROB_output_bits_ROB_entries_0_valid,
                io_ROB_output_bits_ROB_entries_0_is_branch,
                io_ROB_output_bits_ROB_entries_0_is_load,
                io_ROB_output_bits_ROB_entries_0_is_store,
                io_ROB_output_bits_ROB_entries_1_valid,
                io_ROB_output_bits_ROB_entries_1_is_branch,
                io_ROB_output_bits_ROB_entries_1_is_load,
                io_ROB_output_bits_ROB_entries_1_is_store,
                io_ROB_output_bits_ROB_entries_2_valid,
                io_ROB_output_bits_ROB_entries_2_is_branch,
                io_ROB_output_bits_ROB_entries_2_is_load,
                io_ROB_output_bits_ROB_entries_2_is_store,
                io_ROB_output_bits_ROB_entries_3_valid,
                io_ROB_output_bits_ROB_entries_3_is_branch,
                io_ROB_output_bits_ROB_entries_3_is_load,
                io_ROB_output_bits_ROB_entries_3_is_store,
  input         io_commit_valid,
  input  [31:0] io_commit_fetch_PC,
  input         io_commit_T_NT,
  input  [2:0]  io_commit_br_type,
  input  [1:0]  io_commit_fetch_packet_index,
  input         io_commit_is_misprediction,
  input  [31:0] io_commit_expected_PC,
  input  [15:0] io_commit_GHR,
  input  [6:0]  io_commit_TOS,
                io_commit_NEXT,
  input  [3:0]  io_commit_RAT_IDX,
  input  [5:0]  io_PC_file_exec_addr,
  output [5:0]  io_PC_file_exec_data

"""
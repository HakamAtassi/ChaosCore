
import sys
from cocotb.clock import Clock
from cocotb.types import LogicArray
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate


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



class ROB_model:
    def __init__(self):
        self.shared_mem = {}
        self.shared_mem["row_valid"]    = [0]*64
        self.shared_mem["fetch_PC"]     = [0]*64
        self.shared_mem["RAT_IDX"]      = [0]*64

        self.WB_mem = [{} for _ in range(4)]
        for i in range(4):
            self.WB_mem[i]["busy"]      = [0]*64
            self.WB_mem[i]["except"]    = [0]*64

        self.entry_mem = [{} for _ in range(4)]
        for i in range(4):
            self.entry_mem[i]["valid"]         = [0]*64
            self.entry_mem[i]["is_branch"]     = [0]*64
            self.entry_mem[i]["is_load"]       = [0]*64
            self.entry_mem[i]["is_store"]      = [0]*64


        self.front_pointer = 0
        self.back_pointer = 0

    def is_full(self):
        if(abs(self.front_pointer - self.back_pointer) == 63): return True
        else: return False
        
    def increment_front_pointer(self): self.front_pointer = (self.front_pointer + 1) % 64
    def increment_back_pointer(self):  self.back_pointer  = (self.back_pointer + 1)  % 64

    def write_ROB_packet(self, allocate_inputs):  # allocate

        if(not allocate_inputs["valid"]): return 
        if(self.is_full()): return 

        # write shared mem
        self.shared_mem[self.back_pointer]["fetch_PC"] = allocate_inputs["fetch_PC"]
        self.shared_mem[self.back_pointer]["valid"]    = 1
        #self.shared_mem[self.front_pointer]["RAT_IDX"]  = 

        # write WB_mem
        for i in range(4):
            self.WB_mem[i]["busy"][self.back_pointer] = 0
            self.WB_mem[i]["except"][self.back_pointer] = 0

        # write entry_mem
        for i in range(4):
            self.entry_mem[i]["valid"][self.back_pointer]       = allocate_inputs["valid"][i]
            self.entry_mem[i]["is_branch"][self.back_pointer]   = allocate_inputs["is_branch"][i]
            self.entry_mem[i]["is_load"][self.back_pointer]     = allocate_inputs["IS_LOAD"][i]
            self.entry_mem[i]["is_store"][self.back_pointer]    = allocate_inputs["IS_STORE"][i]

        self.increment_back_pointer()

    def read_ROB_packet(self):
        return not self.full

    def write_FU_outputs(self, FU_outputs):

        for i in range(4):
            ROB_index = FU_outputs["ROB_index"][i]
            bank_index = FU_outputs["fetch_packet_index"][i]

            if(self.WB_mem[bank_index]["busy"][ROB_index] == 0):
                self.WB_mem[bank_index]["busy"][ROB_index] = FU_outputs["valid"][i]


    def read_ROB_output(self):

        ROB_output = {}

        ROB_output["valid"]             = self.shared_mem["row_valid"][self.front_pointer]
        ROB_output["fetch_PC"]          = self.shared_mem["row_valid"][self.front_pointer]
        ROB_output["RAT_IDX"]           = 0
        ROB_output["ROB_index"]         = self.front_pointer
        
        ROB_output["entry_valid"]   = [0]*4
        ROB_output["is_branch"]     = [0]*4
        ROB_output["is_load"]       = [0]*4
        ROB_output["is_store"]      = [0]*4

        for i in range(4):
            ROB_output["entry_valid"][i]        = self.entry_mem[i]["valid"][self.front_pointer]
            ROB_output["is_branch"][i]          = self.entry_mem[i]["is_branch"][self.front_pointer]
            ROB_output["is_load"][i]            = self.entry_mem[i]["is_load"][self.front_pointer]
            ROB_output["is_store"][i]           = self.entry_mem[i]["is_store"][self.front_pointer]


        can_commit = 1
        for i in range(4):

            is_load_store       = self.entry_mem[i]["is_load"][self.front_pointer] | self.entry_mem[i]["is_store"][self.front_pointer]
            is_entry_valid      = self.entry_mem[i]["valid"][self.front_pointer]
            is_entry_complete   = self.WB_mem[i]["busy"][self.front_pointer]

            can_commit = can_commit & (is_load_store | (is_entry_complete & is_entry_valid))

        if(can_commit): self.increment_front_pointer()

    def write_commit(self, commit_inputs):
        if(commit_inputs["valid"] & commit_inputs["is_misprediction"]):
            self.back_pointer  = 0
            self.front_pointer = 0

    def read_ROB_index(self):
        return self.back_pointer







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

    def write_ROB_packet(self, allocate_inputs = generate_null_allocate()):
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

    def read_ROB_packet(self):
        allocate_inputs = {}
        allocate_inputs["ready"]  = getattr(self.dut, f"io_ROB_packet_ready").value
        allocate_inputs["valid"]      = getattr(self.dut, f"io_ROB_packet_valid").value                                                   
        allocate_inputs["fetch_PC"]   = getattr(self.dut, f"io_ROB_packet_bits_fetch_PC").value                                           
        for i in range(4):
            allocate_inputs["RS1_ready"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value
            allocate_inputs["RS2_ready"][i]= getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value
            allocate_inputs["RD"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD").value                     
            allocate_inputs["RD_valid"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD_valid").value               
            allocate_inputs["RS1"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1").value                    
            allocate_inputs["RS1_valid"][i]  = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1_valid").value              
            allocate_inputs["RS2"][i] - getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2") .value                   
            allocate_inputs["RS2_valid"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2_valid").value              
            allocate_inputs["IMM"][i]= getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMM").value                    
            allocate_inputs["FUNCT3"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_FUNCT3").value                 
            allocate_inputs["packet_index"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_packet_index").value           
            allocate_inputs["ROB_index"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ROB_index").value              
            allocate_inputs["instructionType"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_instructionType").value        
            allocate_inputs["portID"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_portID").value                 
            allocate_inputs["RS_type"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS_type").value                
            allocate_inputs["needs_ALU"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_ALU").value              
            allocate_inputs["needs_branch_unit"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_branch_unit").value      
            allocate_inputs["needs_CSRs"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_CSRs").value             
            allocate_inputs["SUBTRACT"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_SUBTRACT").value               
            allocate_inputs["MULTIPLY"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_MULTIPLY").value               
            allocate_inputs["IMMEDIATE"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMMEDIATE").value              
            allocate_inputs["IS_LOAD"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_LOAD").value                
            allocate_inputs["IS_STORE"][i] = getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_STORE").value               
            allocate_inputs["valid_bits"][i] = getattr(self.dut, f"io_ROB_packet_bits_valid_bits_{i}").value                                 
        return allocate_inputs

    def write_FU_outputs(self, FU_inputs = generate_null_FU_outputs()):

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

    def read_ROB_output(self):
        ROB_output = {}

        ROB_output["valid"]             = LogicArray(getattr(self.dut, f"io_ROB_output_valid"))
        ROB_output["fetch_PC"]          = LogicArray(getattr(self.dut, f"io_ROB_output_bits_fetch_PC"))
        ROB_output["RAT_IDX"]           = LogicArray(getattr(self.dut, f"io_ROB_output_bits_RAT_IDX"))
        ROB_output["ROB_index"]         = LogicArray(getattr(self.dut, f"io_ROB_index"))
        
        ROB_output["entry_valid"]   = [0]*4
        ROB_output["is_branch"]     = [0]*4
        ROB_output["is_load"]       = [0]*4
        ROB_output["is_store"]      = [0]*4

        for i in range(4):
            ROB_output["entry_valid"][i]        = LogicArray(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_valid"))
            ROB_output["is_branch"][i]          = LogicArray(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_branch"))
            ROB_output["is_load"][i]            = LogicArray(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_load"))
            ROB_output["is_store"][i]           = LogicArray(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_store"))
        
        return ROB_output

    def read_ROB_index(self):
        outputs = {}
        outputs["ROB_index"]                    = LogicArray(getattr(self.dut, f"io_ROB_index"))
        return outputs

    def write_commit(self, commit_inputs=generate_null_commit()):
        getattr(self.dut, f"io_commit_valid").value                 = commit_inputs["valid"]
        getattr(self.dut, f"io_commit_fetch_PC").value              = commit_inputs["fetch_PC"]
        getattr(self.dut, f"io_commit_T_NT").value                  = commit_inputs["T_NT"]
        getattr(self.dut, f"io_commit_ROB_index").value             = commit_inputs["ROB_index"]
        getattr(self.dut, f"io_commit_br_type").value               = commit_inputs["br_type"]
        getattr(self.dut, f"io_commit_fetch_packet_index").value    = commit_inputs["fetch_packet_index"]
        getattr(self.dut, f"io_commit_is_misprediction").value      = commit_inputs["is_misprediction"]
        getattr(self.dut, f"io_commit_expected_PC").value           = commit_inputs["expected_PC"]
        getattr(self.dut, f"io_commit_GHR").value                   = commit_inputs["GHR"]
        getattr(self.dut, f"io_commit_TOS").value                   = commit_inputs["TOS"]
        getattr(self.dut, f"io_commit_NEXT").value                  = commit_inputs["NEXT"]
        getattr(self.dut, f"io_commit_RAT_IDX").value               = commit_inputs["RAT_IDX"]

    def write_PC_file_exec_addr(self, PC_file_inputs=generate_null_PC_file_inputs()):
        getattr(self.dut, f"io_PC_file_exec_addr").value            = PC_file_inputs["addr"]

    def read_PC_file_exec_data(self):
        outputs = {}
        outputs["data"] = LogicArray(getattr(self.dut, f"io_PC_file_exec_data"))
        return outputs

    def get_shared_mem(self):
        shared_mem={}
        shared_mem["row_valid"] = [0]*64
        shared_mem["fetch_PC"]  = [0]*64
        shared_mem["RAT_IDX"]   = [0]*64

        for i in range(64):
            line = LogicArray(getattr(self.dut, f"shared_mem.mem_ext.Memory")[i].value)

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
                line = LogicArray(getattr(self.dut, f"ROB_WB_banks_{bank}.mem_ext.Memory")[i].value)
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
                line = LogicArray(getattr(self.dut, f"ROB_entry_banks_{bank}.mem_ext.Memory")[i].value)
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

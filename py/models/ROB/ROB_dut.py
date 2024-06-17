import sys
from cocotb.clock import Clock
from cocotb.types import LogicArray
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate
from .signals import *

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

    ##############
    # ROB PACKET #
    ##############

    def ROB_packet_valid(self): # ROB packet valid
        return self.dut.io_ROB_packet_valid

    def ROB_packet_ready(self): # ROB packet ready
        return self.dut.io_ROB_packet_ready

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
        allocate_inputs = generate_null_allocate()
        allocate_inputs["ready"]                    = int(getattr(self.dut, f"io_ROB_packet_ready").value)
        allocate_inputs["valid"]                    = int(getattr(self.dut, f"io_ROB_packet_valid").value                               )                    
        allocate_inputs["fetch_PC"]                 = int(getattr(self.dut, f"io_ROB_packet_bits_fetch_PC").value                       )                    
        for i in range(4):
            allocate_inputs["RS1_ready"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value)
            allocate_inputs["RS2_ready"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value)
            allocate_inputs["RD"][i]                = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD").value                     )
            allocate_inputs["RD_valid"][i]          = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD_valid").value               )
            allocate_inputs["RS1"][i]               = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1").value                    )
            allocate_inputs["RS1_valid"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1_valid").value              )
            allocate_inputs["RS2"][i]               = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2") .value                   )
            allocate_inputs["RS2_valid"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2_valid").value              )
            allocate_inputs["IMM"][i]               = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMM").value                    )
            allocate_inputs["FUNCT3"][i]            = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_FUNCT3").value                 )
            allocate_inputs["packet_index"][i]      = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_packet_index").value           )
            allocate_inputs["ROB_index"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ROB_index").value              )
            allocate_inputs["instructionType"][i]   = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_instructionType").value        )
            allocate_inputs["portID"][i]            = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_portID").value                 )
            allocate_inputs["RS_type"][i]           = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS_type").value                )
            allocate_inputs["needs_ALU"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_ALU").value              )
            allocate_inputs["needs_branch_unit"][i] = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_branch_unit").value      )
            allocate_inputs["needs_CSRs"][i]        = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_CSRs").value             )
            allocate_inputs["SUBTRACT"][i]          = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_SUBTRACT").value               )
            allocate_inputs["MULTIPLY"][i]          = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_MULTIPLY").value               )
            allocate_inputs["IMMEDIATE"][i]         = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMMEDIATE").value              )
            allocate_inputs["IS_LOAD"][i]           = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_LOAD").value                )
            allocate_inputs["IS_STORE"][i]          = int(getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_STORE").value               )
            allocate_inputs["valid_bits"][i]        = int(getattr(self.dut, f"io_ROB_packet_bits_valid_bits_{i}").value                                 )
        return allocate_inputs


    ##############
    # FU PACKET #
    ##############

    def FU_output_valid(self, index):
        return getattr(self.dut, f"io_FU_outputs_{index}_valid")


    def write_FU_outputs(self, index, FU_inputs = generate_null_FU_outputs()):

        getattr(self.dut, f"io_FU_outputs_{index}_valid").value                       = FU_inputs["valid"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_RD").value                     = FU_inputs["RD"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_RD_data").value                = FU_inputs["RD_data"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_RD_valid").value               = FU_inputs["RD_valid"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_instruction_PC").value         = FU_inputs["instruction_PC"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_branch_taken").value           = FU_inputs["branch_taken"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_target_address").value         = FU_inputs["target_address"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_branch_valid").value           = FU_inputs["branch_valid"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_ROB_index").value              = FU_inputs["ROB_index"]
        getattr(self.dut, f"io_FU_outputs_{index}_bits_fetch_packet_index").value     = FU_inputs["fetch_packet_index"]

    def read_FU_outputs(self, index):
        FU_inputs = {}
        FU_inputs["valid"]               = getattr(self.dut, f"io_FU_outputs_{index}_valid").value
        FU_inputs["RD"]                  = getattr(self.dut, f"io_FU_outputs_{index}_bits_RD").value
        FU_inputs["RD_data"]             = getattr(self.dut, f"io_FU_outputs_{index}_bits_RD_data").value
        FU_inputs["RD_valid"]            = getattr(self.dut, f"io_FU_outputs_{index}_bits_RD_valid").value
        FU_inputs["instruction_PC"]      = getattr(self.dut, f"io_FU_outputs_{index}_bits_instruction_PC").value
        FU_inputs["branch_taken"]        = getattr(self.dut, f"io_FU_outputs_{index}_bits_branch_taken").value
        FU_inputs["target_address"]      = getattr(self.dut, f"io_FU_outputs_{index}_bits_target_address").value
        FU_inputs["branch_valid"]        = getattr(self.dut, f"io_FU_outputs_{index}_bits_branch_valid").value
        FU_inputs["ROB_index"]           = getattr(self.dut, f"io_FU_outputs_{index}_bits_ROB_index").value
        FU_inputs["fetch_packet_index"]  = getattr(self.dut, f"io_FU_outputs_{index}_bits_fetch_packet_index").value
        return FU_inputs

    ##############
    # ROB OUTPUT #
    ##############

    def ROB_output_valid(self):
        return getattr(self.dut, f"io_ROB_output_valid")

    def read_ROB_output(self):
        ROB_output = {}

        ROB_output["valid"]             = int(getattr(self.dut, f"io_ROB_output_valid").value)
        ROB_output["fetch_PC"]          = int(getattr(self.dut, f"io_ROB_output_bits_fetch_PC").value)
        ROB_output["RAT_IDX"]           = int(getattr(self.dut, f"io_ROB_output_bits_RAT_IDX").value)
        ROB_output["ROB_index"]         = int(getattr(self.dut, f"io_ROB_index").value)

        ROB_output["entry_valid"]   = [0]*4
        ROB_output["is_branch"]     = [0]*4
        ROB_output["is_load"]       = [0]*4
        ROB_output["is_store"]      = [0]*4

        for i in range(4):
            ROB_output["entry_valid"][i]        = int(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_valid").value)
            ROB_output["is_branch"][i]          = int(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_branch").value)
            ROB_output["is_load"][i]            = int(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_load").value)
            ROB_output["is_store"][i]           = int(getattr(self.dut, f"io_ROB_output_bits_ROB_entries_{i}_is_store").value)
        
        return ROB_output

    #############
    # ROB INDEX #
    #############

    def read_ROB_index(self):
        outputs = {}
        outputs["ROB_index"]                    = getattr(self.dut, f"io_ROB_index")
        return outputs
    
    ##########
    # COMMIT #
    ##########

    def commit_valid(self):
        return getattr(self.dut, "io_commit_valid")

    def read_commit(self, commit_inputs=generate_null_commit()):
        commit_inputs = {}
        commit_inputs["valid"] = getattr(self.dut, f"io_commit_valid").value
        commit_inputs["fetch_PC"] = getattr(self.dut, f"io_commit_fetch_PC").value
        commit_inputs["T_NT"] = getattr(self.dut, f"io_commit_T_NT").value
        commit_inputs["ROB_index"] = getattr(self.dut, f"io_commit_ROB_index").value
        commit_inputs["br_type"] = getattr(self.dut, f"io_commit_br_type").value
        commit_inputs["fetch_packet_index"] = getattr(self.dut, f"io_commit_fetch_packet_index").value
        commit_inputs["is_misprediction"] = getattr(self.dut, f"io_commit_is_misprediction").value
        commit_inputs["expected_PC"] = getattr(self.dut, f"io_commit_expected_PC").value
        commit_inputs["GHR"] = getattr(self.dut, f"io_commit_GHR").value
        commit_inputs["TOS"] = getattr(self.dut, f"io_commit_TOS").value
        commit_inputs["NEXT"] = getattr(self.dut, f"io_commit_NEXT").value
        commit_inputs["RAT_IDX"] = getattr(self.dut, f"io_commit_RAT_IDX").value
        return commit_inputs

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

    ################
    # PC FILE ADDR #
    ################

    def read_PC_file_exec_addr(self, PC_file_inputs=generate_null_PC_file_inputs()):
        return getattr(self.dut, f"io_PC_file_exec_addr").value

    def write_PC_file_exec_addr(self, PC_file_inputs=generate_null_PC_file_inputs()):
        getattr(self.dut, f"io_PC_file_exec_addr").value            = PC_file_inputs["addr"]

    ################
    # PC FILE DATA #
    ################

    def read_PC_file_exec_data(self):
        outputs = {}
        outputs["data"] = LogicArray(getattr(self.dut, f"io_PC_file_exec_data"))
        return outputs

    #...

    def shared_memory_notif(self):
        return self.dut.shared_memory_update_notif

    def read_shared_mem(self):
        shared_mem={}
        shared_mem["row_valid"] = [0]*64
        shared_mem["fetch_PC"]  = [0]*64
        shared_mem["RAT_IDX"]   = [0]*64

        for i in range(64):
            line = getattr(self.dut, f"shared_mem.mem_ext.Memory")[i].value
            line = LogicArray(line)

            shared_mem["row_valid"][i]  = int((line[0:0]).integer)
            shared_mem["fetch_PC"][i]   = int((line[32:1]).integer)
            shared_mem["RAT_IDX"][i]    = int((line[36:33]).integer)
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

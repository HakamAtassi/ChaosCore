import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate
import random


def generate_null_decoded_fetch_packet():
    decoded_fetch_packet = {}
    decoded_fetch_packet["valid"]                   = 0
    decoded_fetch_packet["fetch_PC"]                = 0
    decoded_fetch_packet["ready"]                   = 0
    decoded_fetch_packet["RAT_index"]               = 0
    decoded_fetch_packet["free_list_front_pointer"] = 0

    decoded_fetch_packet["RS1_ready"]               = [0]*4
    decoded_fetch_packet["RS2_ready"]               = [0]*4
    decoded_fetch_packet["RD"]                      = [0]*4
    decoded_fetch_packet["RD_valid"]                = [0]*4
    decoded_fetch_packet["RS1"]                     = [0]*4
    decoded_fetch_packet["RS1_valid"]               = [0]*4
    decoded_fetch_packet["RS2"]                     = [0]*4
    decoded_fetch_packet["RS2_valid"]               = [0]*4
    decoded_fetch_packet["IMM"]                     = [0]*4
    decoded_fetch_packet["FUNCT3"]                  = [0]*4
    decoded_fetch_packet["packet_index"]            = [0]*4
    decoded_fetch_packet["ROB_index"]               = [0]*4
    decoded_fetch_packet["instructionType"]         = [0]*4
    decoded_fetch_packet["portID"]                  = [0]*4
    decoded_fetch_packet["RS_type"]                 = [0]*4
    decoded_fetch_packet["needs_ALU"]               = [0]*4
    decoded_fetch_packet["needs_branch_unit"]       = [0]*4
    decoded_fetch_packet["needs_CSRs"]              = [0]*4
    decoded_fetch_packet["SUBTRACT"]                = [0]*4
    decoded_fetch_packet["MULTIPLY"]                = [0]*4
    decoded_fetch_packet["IS_IMM"]                  = [0]*4
    decoded_fetch_packet["is_load"]                 = [0]*4
    decoded_fetch_packet["is_store"]                = [0]*4
    decoded_fetch_packet["valid_bits"]              = [0]*4

    return decoded_fetch_packet


  #input  [3:0]  io_commit_bits_RAT_index,
  #input  [7:0]  io_commit_bits_free_list_front_pointer,
  #input  [6:0]  io_commit_bits_RD_0,
                #io_commit_bits_RD_1,
                #io_commit_bits_RD_2,
                #io_commit_bits_RD_3,
  #input         io_commit_bits_RD_valid_0,
                #io_commit_bits_RD_valid_1,
                #io_commit_bits_RD_valid_2,
                #io_commit_bits_RD_valid_3,


def generate_null_commit():
    commit = {}
    commit["valid"]                 = 0
    commit["fetch_PC"]              = 0
    commit["T_NT"]                  = 0
    commit["ROB_index"]             = 0
    commit["br_type"]               = 0
    commit["fetch_packet_index"]    = 0
    commit["is_misprediction"]      = 0
    commit["expected_PC"]           = 0
    commit["GHR"]                   = 0
    commit["TOS"]                   = 0
    commit["NEXT"]                  = 0
    commit["RAT_index"]             = 0
    commit["free_list_front_pointer"] = 0

    commit["RD"]                    =   [0]*4
    commit["RD_valid"]              =   [0]*4
    return commit

def generate_null_FU_outputs():
    FU_outputs = {}

    FU_outputs["valid"]                 = [0]*4
    FU_outputs["RD"]                    = [0]*4
    FU_outputs["RD_data"]               = [0]*4
    FU_outputs["RD_valid"]              = [0]*4
    FU_outputs["fetch_PC"]              = [0]*4
    FU_outputs["branch_taken"]          = [0]*4
    FU_outputs["target_address"]        = [0]*4
    FU_outputs["branch_valid"]          = [0]*4
    FU_outputs["ROB_index"]             = [0]*4
    FU_outputs["fetch_packet_index"]    = [0]*4

    return FU_outputs


class rename_dut:
    def __init__(self, dut):
        self.dut = dut

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0


    ##########
    # INPUTS #
    ##########


    def write_flush(self, flush):
        self.dut.io_flush = flush

    def write_decoded_fetch_packet(self, decoded_fetch_packet=generate_null_decoded_fetch_packet()):
        
        self.dut.io_decoded_fetch_packet_valid.value                            = decoded_fetch_packet["valid"]
        self.dut.io_decoded_fetch_packet_bits_fetch_PC.value                    = decoded_fetch_packet["fetch_PC"]
        self.dut.io_decoded_fetch_packet_bits_RAT_index.value                   = decoded_fetch_packet["RAT_index"]
        self.dut.io_decoded_fetch_packet_bits_free_list_front_pointer.value     = decoded_fetch_packet["free_list_front_pointer"]
        #self.dut.io_renamed_decoded_fetch_packet_ready.value                    = decoded_fetch_packet["ready"]

        for i in range(4):
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value     =     decoded_fetch_packet["RS1_ready"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value     =     decoded_fetch_packet["RS2_ready"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value                       =     decoded_fetch_packet["RD"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value                 =     decoded_fetch_packet["RD_valid"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value                      =     decoded_fetch_packet["RS1"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value                =     decoded_fetch_packet["RS1_valid"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value                      =     decoded_fetch_packet["RS2"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value                =     decoded_fetch_packet["RS2_valid"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value                      =     decoded_fetch_packet["IMM"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value                   =     decoded_fetch_packet["FUNCT3"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value             =     decoded_fetch_packet["packet_index"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value          =     decoded_fetch_packet["instructionType"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value                   =     decoded_fetch_packet["portID"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value                  =     decoded_fetch_packet["RS_type"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value                =     decoded_fetch_packet["needs_ALU"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value        =     decoded_fetch_packet["needs_branch_unit"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value               =     decoded_fetch_packet["needs_CSRs"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value                 =     decoded_fetch_packet["SUBTRACT"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value                 =     decoded_fetch_packet["MULTIPLY"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value                   =     decoded_fetch_packet["IS_IMM"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_is_load").value                  =     decoded_fetch_packet["is_load"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_is_store").value                 =     decoded_fetch_packet["is_store"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value                =     decoded_fetch_packet["ROB_index"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_valid_bits_{i}").value                                   =     decoded_fetch_packet["valid_bits"][i]


    def write_commit(self, commit):
        self.dut.io_commit_valid.value                        = commit["valid"]
        self.dut.io_commit_bits_fetch_PC.value                = commit["fetch_PC"]
        self.dut.io_commit_bits_T_NT.value                    = commit["T_NT"]
        self.dut.io_commit_bits_ROB_index.value               = commit["ROB_index"]
        self.dut.io_commit_bits_br_type.value                 = commit["br_type"]
        self.dut.io_commit_bits_fetch_packet_index.value      = commit["fetch_packet_index"]
        self.dut.io_commit_bits_is_misprediction.value        = commit["is_misprediction"]
        self.dut.io_commit_bits_expected_PC.value             = commit["expected_PC"]
        self.dut.io_commit_bits_GHR.value                     = commit["GHR"]
        self.dut.io_commit_bits_TOS.value                     = commit["TOS"]
        self.dut.io_commit_bits_NEXT.value                    = commit["NEXT"]
        self.dut.io_commit_bits_RAT_index.value               = commit["RAT_index"]
        self.dut.io_commit_bits_free_list_front_pointer.value = commit["free_list_front_pointer"]

        for i in range(4):
            getattr(self.dut, f"io_commit_bits_RD_{i}").value         = commit["RD"][i]
            getattr(self.dut, f"io_commit_bits_RD_valid_{i}").value   = commit["RD_valid"][i]

    def write_FU_outputs(self, FU_outputs = generate_null_FU_outputs()):
        for i in range(4):
            getattr(self.dut, f"io_FU_outputs_{i}_valid").value                     = FU_outputs["valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD").value                   = FU_outputs["RD"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value              = FU_outputs["RD_data"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value             = FU_outputs["RD_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_PC").value             = FU_outputs["fetch_PC"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value         = FU_outputs["branch_taken"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value       = FU_outputs["target_address"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value         = FU_outputs["branch_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value            = FU_outputs["ROB_index"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value   = FU_outputs["fetch_packet_index"][i]

    def inputs(self, flush, decoded_fetch_packet, commit, FU_outputs):
        self.write_flush(flush)
        self.write_decoded_fetch_packet(decoded_fetch_packet)
        self.write_commit(commit)
        self.write_FU_outputs(FU_outputs)


    ###########
    # OUTPUTS #
    ###########
    def read_commit(self):
        commit = generate_null_commit()
        commit["valid"] = int(self.dut.io_commit_valid.value)
        commit["fetch_PC"] = int(self.dut.io_commit_bits_fetch_PC.value)
        commit["T_NT"] = int(self.dut.io_commit_bits_T_NT.value)
        commit["ROB_index"] = int(self.dut.io_commit_bits_ROB_index.value)
        commit["br_type"] = int(self.dut.io_commit_bits_br_type.value)
        commit["fetch_packet_index"] = int(self.dut.io_commit_bits_fetch_packet_index.value)
        commit["is_misprediction"] = int(self.dut.io_commit_bits_is_misprediction.value)
        commit["expected_PC"] = int(self.dut.io_commit_bits_expected_PC.value)
        commit["GHR"] = int(self.dut.io_commit_bits_GHR.value)
        commit["TOS"] = int(self.dut.io_commit_bits_TOS.value)
        commit["NEXT"] = int(self.dut.io_commit_bits_NEXT.value)
        commit["RAT_index"] = int(self.dut.io_commit_bits_RAT_index.value)
        commit["free_list_front_pointer"] = int(self.dut.io_commit_bits_free_list_front_pointer.value)


        commit["RD"] = []
        commit["RD_valid"] = []
        for i in range(4):
            commit["RD"].append(int(getattr(self.dut, f"io_commit_bits_RD_{i}").value))
            commit["RD_valid"].append(int(getattr(self.dut, f"io_commit_bits_RD_valid_{i}").value))
        
        return commit

    def read_decoded_fetch_packet(self):
        decoded_fetch_packet = {}
        decoded_fetch_packet["valid"] = int(self.dut.io_decoded_fetch_packet_valid.value)
        decoded_fetch_packet["fetch_PC"] = int(self.dut.io_decoded_fetch_packet_bits_fetch_PC.value)

        decoded_fetch_packet["RD"]                  = [0]*4
        decoded_fetch_packet["RD_valid"]            = [0]*4
        decoded_fetch_packet["RS1"]                 = [0]*4
        decoded_fetch_packet["RS1_valid"]           = [0]*4
        decoded_fetch_packet["RS2"]                 = [0]*4
        decoded_fetch_packet["RS2_valid"]           = [0]*4
        decoded_fetch_packet["IMM"]                 = [0]*4
        decoded_fetch_packet["FUNCT3"]              = [0]*4
        decoded_fetch_packet["packet_index"]        = [0]*4
        decoded_fetch_packet["instructionType"]     = [0]*4
        decoded_fetch_packet["portID"]              = [0]*4
        decoded_fetch_packet["RS_type"]             = [0]*4
        decoded_fetch_packet["needs_ALU"]           = [0]*4
        decoded_fetch_packet["needs_branch_unit"]   = [0]*4
        decoded_fetch_packet["needs_CSRs"]          = [0]*4
        decoded_fetch_packet["SUBTRACT"]            = [0]*4
        decoded_fetch_packet["MULTIPLY"]            = [0]*4
        decoded_fetch_packet["IS_IMM"]              = [0]*4
        decoded_fetch_packet["is_load"]             = [0]*4
        decoded_fetch_packet["is_store"]            = [0]*4
        decoded_fetch_packet["valid_bits"]          = [0]*4

        for i in range(4):
            decoded_fetch_packet["RS1_ready"]               = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value)
            decoded_fetch_packet["RS2_ready"]               = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value)
            decoded_fetch_packet["RD"][i]                   = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value)
            decoded_fetch_packet["RD_valid"][i]             = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value)
            decoded_fetch_packet["RS1"][i]                  = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value)
            decoded_fetch_packet["RS1_valid"][i]            = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value)
            decoded_fetch_packet["RS2"][i]                  = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value)
            decoded_fetch_packet["RS2_valid"][i]            = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value)
            decoded_fetch_packet["IMM"][i]                  = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value)
            decoded_fetch_packet["FUNCT3"][i]               = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value)
            decoded_fetch_packet["packet_index"][i]         = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value)
            decoded_fetch_packet["instructionType"][i]      = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value)
            decoded_fetch_packet["portID"][i]               = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value)
            decoded_fetch_packet["RS_type"][i]              = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value)
            decoded_fetch_packet["needs_ALU"][i]            = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value)
            decoded_fetch_packet["needs_branch_unit"][i]    = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value)
            decoded_fetch_packet["needs_CSRs"][i]           = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value)
            decoded_fetch_packet["SUBTRACT"][i]             = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value)
            decoded_fetch_packet["MULTIPLY"][i]             = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value)
            decoded_fetch_packet["IS_IMM"][i]               = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value)
            decoded_fetch_packet["is_load"][i]              = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_is_load").value)
            decoded_fetch_packet["is_store"][i]             = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_is_store").value)
            decoded_fetch_packet["valid_bits"][i]           = int(getattr(self.dut, f"io_decoded_fetch_packet_bits_valid_bits_{i}").value)

        return decoded_fetch_packet

    def read_FU_outputs(self):
        FU_outputs = generate_null_FU_outputs()
        for i in range(4):
            FU_outputs["valid"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_valid").value))
            FU_outputs["RD"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_RD").value))
            FU_outputs["RD_data"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value))
            FU_outputs["RD_valid"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value))
            FU_outputs["fetch_PC"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_PC").value))
            FU_outputs["branch_taken"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value))
            FU_outputs["target_address"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value))
            FU_outputs["branch_valid"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value))
            FU_outputs["ROB_index"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value))
            FU_outputs["fetch_packet_index"].append(int(getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value))
        
        return FU_outputs


    def renamed_decoded_fetch_packet_valid(self):
        return  self.dut.io_renamed_decoded_fetch_packet_valid

    def read_renamed_decoded_fetch_packet(self):
        renamed_decoded_fetch_packet = {}
        renamed_decoded_fetch_packet["valid"]           = int(self.dut.io_renamed_decoded_fetch_packet_valid.value)
        renamed_decoded_fetch_packet["fetch_PC"]        = int(self.dut.io_renamed_decoded_fetch_packet_bits_fetch_PC.value)
        renamed_decoded_fetch_packet["RAT_index"]       = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_RAT_index").value)

        renamed_decoded_fetch_packet["RS1_ready"]           = [0]*4
        renamed_decoded_fetch_packet["RS2_ready"]           = [0]*4
        renamed_decoded_fetch_packet["RD"]                  = [0]*4
        renamed_decoded_fetch_packet["RD_valid"]            = [0]*4
        renamed_decoded_fetch_packet["RS1"]                 = [0]*4
        renamed_decoded_fetch_packet["RS1_valid"]           = [0]*4
        renamed_decoded_fetch_packet["RS2"]                 = [0]*4
        renamed_decoded_fetch_packet["RS2_valid"]           = [0]*4
        renamed_decoded_fetch_packet["IMM"]                 = [0]*4
        renamed_decoded_fetch_packet["FUNCT3"]              = [0]*4
        renamed_decoded_fetch_packet["packet_index"]        = [0]*4
        renamed_decoded_fetch_packet["instructionType"]     = [0]*4
        renamed_decoded_fetch_packet["portID"]              = [0]*4
        renamed_decoded_fetch_packet["RS_type"]             = [0]*4
        renamed_decoded_fetch_packet["needs_ALU"]           = [0]*4
        renamed_decoded_fetch_packet["needs_branch_unit"]   = [0]*4
        renamed_decoded_fetch_packet["needs_CSRs"]          = [0]*4
        renamed_decoded_fetch_packet["SUBTRACT"]            = [0]*4
        renamed_decoded_fetch_packet["MULTIPLY"]            = [0]*4
        renamed_decoded_fetch_packet["IS_IMM"]              = [0]*4
        renamed_decoded_fetch_packet["is_load"]             = [0]*4
        renamed_decoded_fetch_packet["is_store"]            = [0]*4
        renamed_decoded_fetch_packet["valid_bits"]          = [0]*4

        for i in range(4):
            renamed_decoded_fetch_packet["RS1_ready"][i]            = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value)
            renamed_decoded_fetch_packet["RS2_ready"][i]            = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value)
            renamed_decoded_fetch_packet["RD"][i]                   = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value)
            renamed_decoded_fetch_packet["RD_valid"][i]             = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value)
            renamed_decoded_fetch_packet["RS1"][i]                  = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value)
            renamed_decoded_fetch_packet["RS1_valid"][i]            = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value)
            renamed_decoded_fetch_packet["RS2"][i]                  = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value)
            renamed_decoded_fetch_packet["RS2_valid"][i]            = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value)
            renamed_decoded_fetch_packet["IMM"][i]                  = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value)
            renamed_decoded_fetch_packet["FUNCT3"][i]               = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value)
            renamed_decoded_fetch_packet["packet_index"][i]         = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value)
            renamed_decoded_fetch_packet["instructionType"][i]      = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value)
            renamed_decoded_fetch_packet["portID"][i]               = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value)
            renamed_decoded_fetch_packet["RS_type"][i]              = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value)
            renamed_decoded_fetch_packet["needs_ALU"][i]            = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value)
            renamed_decoded_fetch_packet["needs_branch_unit"][i]    = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value)
            renamed_decoded_fetch_packet["needs_CSRs"][i]           = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value)
            renamed_decoded_fetch_packet["SUBTRACT"][i]             = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value)
            renamed_decoded_fetch_packet["MULTIPLY"][i]             = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value)
            renamed_decoded_fetch_packet["IS_IMM"][i]               = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_IMM").value)
            renamed_decoded_fetch_packet["is_load"][i]              = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_is_load").value)
            renamed_decoded_fetch_packet["is_store"][i]             = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_is_store").value)
            renamed_decoded_fetch_packet["valid_bits"][i]           = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_valid_bits_{i}").value)

        return renamed_decoded_fetch_packet


    def read_flush(self):
        return int(self.dut.io_flush.value)

    def read_restore_checkpoint(self):
        return int(self.dut.restore_checkpoint.value)

    def read_restore_checkpoint_value(self):
        return int(self.dut.restore_checkpoint.value)

    def read_create_checkpoint(self):
        return int(self.dut.create_checkpoint.value)

    def free_checkpoint(self):
        return int(self.dut.free_checkpoint.value)






    def read_RAT_memories(self):
        RAT_memories = []

        for i in range(16):
            RAT = [0]*32
            for j in range(32):
                RAT[j] = int(getattr(self.dut.RAT, f"RAT_memories_{i}_{j}").value)
            RAT_memories.append(RAT)
        return RAT_memories




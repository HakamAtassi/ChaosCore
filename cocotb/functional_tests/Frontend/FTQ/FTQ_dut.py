import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate


def generate_null_FU_inputs():
    inputs = {}
    for i in range(4):
        inputs["valid"]                 =   [0]*4
        inputs["RD"]                    =   [0]*4
        inputs["RD_data"]               =   [0]*4
        inputs["RD_valid"]              =   [0]*4
        inputs["instruction_PC"]        =   [0]*4
        inputs["branch_taken"]          =   [0]*4
        inputs["target_address"]        =   [0]*4
        inputs["branch_valid"]          =   [0]*4
        inputs["ROB_index"]             =   [0]*4
        inputs["fetch_packet_index"]    =   [0]*4
        return inputs

def generate_null_predictions():
    inputs = {}
    inputs["valid"]                     =   0
    inputs["dominant_index"]            =   0
    inputs["fetch_PC"]                  =   0
    inputs["predicted_PC"]              =   0
    inputs["resolved_PC"]               =   0
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    return inputs

def generate_null_commit():
    inputs = {}

    inputs["valid"]                     =   0
    inputs["fetch_PC"]                  =   0
    inputs["T_NT"]                      =   0
    inputs["br_type"]                   =   0
    inputs["is_misprediction"]          =   0
    inputs["expected_PC"]               =   0
    inputs["GHR"]                       =   0
    inputs["TOS"]                       =   0
    inputs["NEXT"]                      =   0
    return inputs

class FTQ_dut:
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

    def write_FU_inputs(self, inputs=generate_null_FU_inputs()):

        for i in range(4):
            getattr(self.dut, f"io_FU_outputs_{i}_valid").value                         =   inputs["valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD").value                       =   inputs["RD"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value                  =   inputs["RD_data"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value                 =   inputs["RD_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_instruction_PC").value           =   inputs["instruction_PC"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value             =   inputs["branch_taken"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value           =   inputs["target_address"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value             =   inputs["branch_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value                =   inputs["ROB_index"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value       =   inputs["fetch_packet_index"][i]


    def write_predictions(self, inputs=generate_null_predictions()):
        getattr(self.dut, f"io_predictions_valid").value                                =   inputs["valid"]
        #getattr(self.dut, f"io_predictions_bits_valid").value                           =   inputs[""]
        #getattr(self.dut, f"io_predictions_bits_is_misprediction").value                =   inputs[""]
        getattr(self.dut, f"io_predictions_bits_dominant_index").value                  =   inputs["dominant_index"]
        getattr(self.dut, f"io_predictions_bits_fetch_PC").value                        =   inputs["fetch_PC"]
        getattr(self.dut, f"io_predictions_bits_predicted_PC").value           =   inputs["predicted_PC"]
        getattr(self.dut, f"io_predictions_bits_GHR").value                             =   inputs["GHR"]
        getattr(self.dut, f"io_predictions_bits_NEXT").value                            =   inputs["NEXT"]
        getattr(self.dut, f"io_predictions_bits_TOS").value                             =   inputs["TOS"]
        getattr(self.dut, f"io_predictions_bits_resolved_PC").value                     =   inputs["resolved_PC"]

    def write_commit(self, inputs=generate_null_commit()):
        getattr(self.dut, f"io_commit_valid").value                                     =   inputs["valid"]
        getattr(self.dut, f"io_commit_fetch_PC").value                                  =   inputs["fetch_PC"]
        getattr(self.dut, f"io_commit_T_NT").value                                      =   inputs["T_NT"]
        getattr(self.dut, f"io_commit_br_type").value                                   =   inputs["br_type"]
        getattr(self.dut, f"io_commit_is_misprediction").value                          =   inputs["is_misprediction"]
        getattr(self.dut, f"io_commit_expected_PC").value                               =   inputs["expected_PC"]
        getattr(self.dut, f"io_commit_GHR").value                                       =   inputs["GHR"]
        getattr(self.dut, f"io_commit_TOS").value                                       =   inputs["TOS"]
        getattr(self.dut, f"io_commit_NEXT").value                                      =   inputs["NEXT"]

    def get_outputs(self):
        outputs = {}

        outputs["ready"] = getattr(self.dut, f"io_predictions_ready").value
        outputs["valid"] = getattr(self.dut, f"io_FTQ_valid").value
        outputs["dominant_index"] = getattr(self.dut, f"io_FTQ_dominant_index").value
        outputs["fetch_PC"] = getattr(self.dut, f"io_FTQ_fetch_PC").value
        outputs["is_misprediction"] = getattr(self.dut, f"io_FTQ_is_misprediction").value
        outputs["predicted_PC"] = getattr(self.dut, f"io_FTQ_predicted_PC").value
        outputs["GHR"] = getattr(self.dut, f"io_FTQ_GHR").value
        outputs["NEXT"] = getattr(self.dut, f"io_FTQ_NEXT").value
        outputs["TOS"] = getattr(self.dut, f"io_FTQ_TOS").value
        outputs["resolved_PC"] = getattr(self.dut, f"io_FTQ_resolved_PC")
        return outputs

    def get_FTQ_contents(self):
        FTQ = {}
        FTQ["valid"]                = [0]*16
        FTQ["dominant_index"]       = [0]*16
        FTQ["fetch_PC"]             = [0]*16
        FTQ["is_misprediction"]     = [0]*16
        FTQ["predicted_PC"]         = [0]*16
        FTQ["GHR"]                  = [0]*16
        FTQ["NEXT"]                 = [0]*16
        FTQ["TOS"]                  = [0]*16
        FTQ["RAT_index"]              = [0]*16
        FTQ["resolved_PC"]          = [0]*16

        for i in range(16):
            FTQ["valid"][i] = getattr(self.dut, f"FTQ_{i}_valid").value
            FTQ["dominant_index"][i] = getattr(self.dut, f"FTQ_{i}_dominant_index").value
            FTQ["fetch_PC"][i] = getattr(self.dut, f"FTQ_{i}_fetch_PC").value
            FTQ["is_misprediction"][i] = getattr(self.dut, f"FTQ_{i}_is_misprediction").value
            FTQ["predicted_PC"][i] = getattr(self.dut, f"FTQ_{i}_predicted_PC").value
            FTQ["GHR"][i] = getattr(self.dut, f"FTQ_{i}_GHR").value
            FTQ["NEXT"][i] = getattr(self.dut, f"FTQ_{i}_NEXT").value
            FTQ["TOS"][i] = getattr(self.dut, f"FTQ_{i}_TOS").value
            FTQ["resolved_PC"][i] = getattr(self.dut, f"FTQ_{i}_resolved_PC").value


        return FTQ

    def print_FTQ(self):
        FTQ = self.get_FTQ_contents()

        # Create headers
        headers = FTQ.keys()

        # Transpose the dictionary values to align with headers
        rows = list(zip(*FTQ.values()))

        # Print the table with headers
        print(tabulate(rows, headers=headers, tablefmt="grid"))


    # complete class body...

    # Suggestions: 

    # Module set outputs ready

    # Module Write functions

    # Module Read functions

    # Module print visualizers


"""
input         clock,
            reset,
            io_FU_outputs_0_valid,
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
output        io_predictions_ready,
input         io_predictions_valid,
            io_predictions_bits_valid,
input  [1:0]  io_predictions_bits_dominant_index,
input  [31:0] io_predictions_bits_fetch_PC,
input         io_predictions_bits_is_misprediction,
input  [31:0] io_predictions_bits_predicted_expected_PC,
input  [15:0] io_predictions_bits_GHR,
input  [6:0]  io_predictions_bits_NEXT,
            io_predictions_bits_TOS,
input  [3:0]  io_predictions_bits_RAT_index,
input         io_commit_valid,
input  [31:0] io_commit_fetch_PC,
input         io_commit_T_NT,
            io_commit_is_BR,
            io_commit_is_misprediction,
input  [31:0] io_commit_expected_PC,
input  [15:0] io_commit_GHR,
input  [6:0]  io_commit_TOS,
            io_commit_NEXT,
input  [3:0]  io_commit_RAT_index,
output        io_FTQ_valid,
output [1:0]  io_FTQ_dominant_index,
output [31:0] io_FTQ_fetch_PC,
output        io_FTQ_is_misprediction,
output [31:0] io_FTQ_predicted_expected_PC,
output [15:0] io_FTQ_GHR,
output [6:0]  io_FTQ_NEXT,
            io_FTQ_TOS,
output [3:0]  io_FTQ_RAT_index
"""
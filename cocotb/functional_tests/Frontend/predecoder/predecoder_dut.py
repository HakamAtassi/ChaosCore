import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate

# Add helper functions as needed

def generate_null_fetch_packet():
    inputs = {}

    inputs["valid"]         = 0
    inputs["fetch_PC"]      = 0
    inputs["valid_bits"]    = [0]*4
    inputs["instruction"]   = [0]*4
    inputs["packet_index"]  = [0]*4
    inputs["ROB_index"]     = [0]*4

    return inputs

def generate_null_prediction():
    inputs = {}

    inputs["valid"] = 0
    inputs["hit"] = 0
    inputs["target"] = 0
    inputs["br_type"] = 0
    inputs["br_mask"] = 0
    inputs["GHR"] = 0
    inputs["T_NT"] = 0

    return inputs

def generate_null_RAS():
    inputs = {}
    inputs["NEXT"] = 0
    inputs["TOS"]  = 0
    inputs["ret_addr"] = 0

    #io_RAS_read_NEXT
    #io_RAS_read_TOS
    #io_RAS_read_ret_addr

    return inputs

class predecoder_dut:
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

    def write_fetch_packet(self, inputs=generate_null_fetch_packet()):
        getattr(self.dut, f"io_fetch_packet_valid").value           = inputs["valid"]
        getattr(self.dut, f"io_fetch_packet_bits_fetch_PC").value   = inputs["fetch_PC"]
        for i in range(4):
            getattr(self.dut, f"io_fetch_packet_bits_valid_bits_{i}").value                 = inputs["valid_bits"][i]
            getattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_instruction").value   = inputs["instruction"][i]
            getattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_packet_index").value  = inputs["packet_index"][i]
            getattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_ROB_index").value     = inputs["ROB_index"][i]

    def write_prediction(self, inputs=generate_null_prediction()):
        getattr(self.dut, f"io_prediction_valid").value             = inputs["valid"]
        getattr(self.dut, f"io_prediction_bits_hit").value          = inputs["hit"]
        getattr(self.dut, f"io_prediction_bits_target").value       = inputs["target"]
        getattr(self.dut, f"io_prediction_bits_br_type").value      = inputs["br_type"]
        getattr(self.dut, f"io_prediction_bits_br_mask").value      = inputs["br_mask"]
        getattr(self.dut, f"io_prediction_bits_GHR").value          = inputs["GHR"]
        getattr(self.dut, f"io_prediction_bits_T_NT").value         = inputs["T_NT"]

    def write_RAS(self, inputs=generate_null_RAS()):
        getattr(self.dut, "io_RAS_read_NEXT").value        = inputs["NEXT"]
        getattr(self.dut, "io_RAS_read_TOS").value         = inputs["TOS"]
        getattr(self.dut, "io_RAS_read_ret_addr").value    = inputs["ret_addr"]


    # Set ready bits?
    def set_final_fetch_packet_ready(self, ready=0):
        getattr(self.dut, "io_final_fetch_packet_ready").value = ready

    def set_FTQ_ready(self, ready=0):
        getattr(self.dut, "io_predictions_ready").value = ready

    def get_fetch_packet_ready(self):
        return getattr(self.dut, "io_fetch_packet_ready").value 

    def get_prediction_ready(self):
        return getattr(self.dut, "io_prediction_ready").value 

    # Read outputs?

    def get_final_fetch_packet(self):

        outputs = {}
        outputs["valid"]    = [getattr(self.dut, f"io_final_fetch_packet_valid").value]*4
        outputs["PC"]       = [getattr(self.dut, f"io_final_fetch_packet_bits_fetch_PC").value]*4

        outputs["instruction_valid"]    = [0]*4
        outputs["instruction"]          = [0]*4
        outputs["packet_index"]         = [0]*4
        outputs["ROB_index"]            = [0]*4
        for i in range(4):
            outputs["instruction_valid"][i]    = getattr(self.dut, f"io_final_fetch_packet_bits_valid_bits_{i}").value
            outputs["instruction"][i]          = getattr(self.dut, f"io_final_fetch_packet_bits_instructions_{i}_instruction").value
            outputs["packet_index"][i]         = getattr(self.dut, f"io_final_fetch_packet_bits_instructions_{i}_packet_index").value
            outputs["ROB_index"][i]            = getattr(self.dut, f"io_final_fetch_packet_bits_instructions_{i}_ROB_index").value
        return outputs   

    def get_revert(self):
        outputs = {}
        outputs["valid"]    = getattr(self.dut, f"io_revert_valid").value
        outputs["GHR"]      = getattr(self.dut, f"io_revert_bits_GHR").value
        outputs["PC"]       = getattr(self.dut, f"io_revert_bits_PC").value
        return outputs

    def get_RAS_update(self):
        outputs = {}
        outputs["valid"]    = getattr(self.dut, f"io_revert_valid").value
        outputs["GHR"]      = getattr(self.dut, f"io_revert_bits_GHR").value
        outputs["PC"]       = getattr(self.dut, f"io_revert_bits_PC").value
        return outputs

    def get_RAS_read(self):
        outputs = {}
        outputs["call_addr"]    = getattr(self.dut, f"io_RAS_update_call_addr").value
        outputs["is_call"]      = getattr(self.dut, f"io_RAS_update_call").value
        outputs["is_ret"]       = getattr(self.dut, f"io_RAS_update_ret").value
        return outputs

    def get_FTQ_read(self):
        outputs = {}
        #outputs[""] = getattr(self.dut, "io_predictions_bits_valid").value

        outputs["valid"]            = int(getattr(self.dut, "io_predictions_valid").value)
        outputs["instruction_PC"]   = int(getattr(self.dut, "io_predictions_bits_instruction_PC").value)
        outputs["is_misprediction"] = int(getattr(self.dut, "io_predictions_bits_is_misprediction").value)
        outputs["expected_PC"]      = int(getattr(self.dut, "io_predictions_bits_predicted_expected_PC").value)
        outputs["GHR"]              = int(getattr(self.dut, "io_predictions_bits_GHR").value)
        outputs["NEXT"]             = int(getattr(self.dut, "io_predictions_bits_NEXT").value)
        outputs["TOS"]              = int(getattr(self.dut, "io_predictions_bits_TOS").value)
        outputs["RAT_IDX"]          = int(getattr(self.dut, "io_predictions_bits_RAT_IDX").value)

        return outputs


    def get_expected_address(self):
        return int(self.dut.PC_expected.value)


    # Print functions #
    def print_final_fetch_packet(self):
        outputs = self.get_final_fetch_packet()
        headers = ["Data Name"] + [f"Entry {i}" for i in range(len(outputs["instruction_valid"]))]
        table = []

        for key in outputs:
            row = [key] + [hex(value) for value in outputs[key]]
            table.append(row)

        print(tabulate(table, headers=headers, tablefmt="grid"))


"""
  input         clock,
                reset,
  output        io_prediction_ready,
  input         io_prediction_valid,
                io_prediction_bits_hit,
  input  [31:0] io_prediction_bits_target,
  input  [1:0]  io_prediction_bits_br_type,
  input  [3:0]  io_prediction_bits_br_mask,
  input  [15:0] io_prediction_bits_GHR,
  input         io_prediction_bits_T_NT,
  output        io_fetch_packet_ready,
  input         io_fetch_packet_valid,
  input  [31:0] io_fetch_packet_bits_fetch_PC,
  input         io_fetch_packet_bits_valid_bits_0,
                io_fetch_packet_bits_valid_bits_1,
                io_fetch_packet_bits_valid_bits_2,
                io_fetch_packet_bits_valid_bits_3,
  input  [31:0] io_fetch_packet_bits_instructions_0_instruction,
  input  [3:0]  io_fetch_packet_bits_instructions_0_packet_index,
  input  [5:0]  io_fetch_packet_bits_instructions_0_ROB_index,
  input  [31:0] io_fetch_packet_bits_instructions_1_instruction,
  input  [3:0]  io_fetch_packet_bits_instructions_1_packet_index,
  input  [5:0]  io_fetch_packet_bits_instructions_1_ROB_index,
  input  [31:0] io_fetch_packet_bits_instructions_2_instruction,
  input  [3:0]  io_fetch_packet_bits_instructions_2_packet_index,
  input  [5:0]  io_fetch_packet_bits_instructions_2_ROB_index,
  input  [31:0] io_fetch_packet_bits_instructions_3_instruction,
  input  [3:0]  io_fetch_packet_bits_instructions_3_packet_index,
  input  [5:0]  io_fetch_packet_bits_instructions_3_ROB_index,
  input  [6:0]  io_RAS_read_NEXT,
                io_RAS_read_TOS,
  input  [31:0] io_RAS_read_ret_addr,
  input         io_revert_ready,
  output        io_revert_valid,
  output [15:0] io_revert_bits_GHR,
  output [31:0] io_revert_bits_PC,
  input         io_final_fetch_packet_ready,
  output        io_final_fetch_packet_valid,
  output [31:0] io_final_fetch_packet_bits_fetch_PC,
  output        io_final_fetch_packet_bits_valid_bits_0,
                io_final_fetch_packet_bits_valid_bits_1,
                io_final_fetch_packet_bits_valid_bits_2,
                io_final_fetch_packet_bits_valid_bits_3,
  output [31:0] io_final_fetch_packet_bits_instructions_0_instruction,
  output [3:0]  io_final_fetch_packet_bits_instructions_0_packet_index,
  output [5:0]  io_final_fetch_packet_bits_instructions_0_ROB_index,
  output [31:0] io_final_fetch_packet_bits_instructions_1_instruction,
  output [3:0]  io_final_fetch_packet_bits_instructions_1_packet_index,
  output [5:0]  io_final_fetch_packet_bits_instructions_1_ROB_index,
  output [31:0] io_final_fetch_packet_bits_instructions_2_instruction,
  output [3:0]  io_final_fetch_packet_bits_instructions_2_packet_index,
  output [5:0]  io_final_fetch_packet_bits_instructions_2_ROB_index,
  output [31:0] io_final_fetch_packet_bits_instructions_3_instruction,
  output [3:0]  io_final_fetch_packet_bits_instructions_3_packet_index,
  output [5:0]  io_final_fetch_packet_bits_instructions_3_ROB_index,
  output [31:0] io_RAS_update_call_addr,
  output        io_RAS_update_call,
                io_RAS_update_ret,
  input         io_predictions_ready,
  output        io_predictions_valid,
                io_predictions_bits_valid,
  output [31:0] io_predictions_bits_instruction_PC,
  output        io_predictions_bits_is_misprediction,
  output [31:0] io_predictions_bits_predicted_expected_PC,
  output [15:0] io_predictions_bits_GHR,
  output [6:0]  io_predictions_bits_NEXT,
                io_predictions_bits_TOS,
  output [3:0]  io_predictions_bits_RAT_IDX
"""
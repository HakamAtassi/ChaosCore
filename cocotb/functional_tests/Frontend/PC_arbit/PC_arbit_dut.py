import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly

# Add helper functions as needed

def generate_null_commit_inputs():
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
    commit_inputs["RAT_index"] = 0
    return commit_inputs

def generate_null_prediction_inputs():
    prediction_inputs = {}
    prediction_inputs["valid"] = 0
    prediction_inputs["hit"] = 0
    prediction_inputs["target"] = 0
    prediction_inputs["br_type"] = 0
    prediction_inputs["br_mask"] = 0
    prediction_inputs["GHR"] = 0
    prediction_inputs["T_NT"] = 0

    return prediction_inputs

def generate_null_revert_inputs():
    revert_inputs = {}
    revert_inputs["valid"] = 0
    revert_inputs["GHR"] = 0
    revert_inputs["PC"] = 0

    return revert_inputs

def generate_null_RAS_read_inputs():
    RAS_read_inputs = {}

    RAS_read_inputs["NEXT"] = 0
    RAS_read_inputs["TOS"] = 0
    RAS_read_inputs["ret_addr"] = 0

    return RAS_read_inputs


class PC_arbit_dut:
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

    def write_commit(self, commit_inputs=generate_null_commit_inputs()):

        getattr(self.dut, f"io_commit_valid").value = commit_inputs["valid"]
        getattr(self.dut, f"io_commit_fetch_PC").value = commit_inputs["fetch_PC"]
        getattr(self.dut, f"io_commit_T_NT").value = commit_inputs["T_NT"]
        getattr(self.dut, f"io_commit_ROB_index").value = commit_inputs["ROB_index"]
        getattr(self.dut, f"io_commit_br_type").value = commit_inputs["br_type"]
        getattr(self.dut, f"io_commit_fetch_packet_index").value = commit_inputs["fetch_packet_index"]
        getattr(self.dut, f"io_commit_is_misprediction").value = commit_inputs["is_misprediction"]
        getattr(self.dut, f"io_commit_expected_PC").value = commit_inputs["expected_PC"]
        getattr(self.dut, f"io_commit_GHR").value = commit_inputs["GHR"]
        getattr(self.dut, f"io_commit_TOS").value = commit_inputs["TOS"]
        getattr(self.dut, f"io_commit_NEXT").value = commit_inputs["NEXT"]
        getattr(self.dut, f"io_commit_RAT_index").value = commit_inputs["RAT_index"]

    def write_prediction(self, prediction_inputs=generate_null_prediction_inputs()):

        getattr(self.dut, f"io_prediction_valid").value = prediction_inputs["valid"]
        getattr(self.dut, f"io_prediction_bits_hit").value = prediction_inputs["hit"]
        getattr(self.dut, f"io_prediction_bits_target").value = prediction_inputs["target"]
        getattr(self.dut, f"io_prediction_bits_br_type").value = prediction_inputs["br_type"]
        getattr(self.dut, f"io_prediction_bits_br_mask").value = prediction_inputs["br_mask"]
        getattr(self.dut, f"io_prediction_bits_GHR").value = prediction_inputs["GHR"]
        getattr(self.dut, f"io_prediction_bits_T_NT").value = prediction_inputs["T_NT"]


    def write_revert(self, revert_inputs=generate_null_revert_inputs()):
        getattr(self.dut, f"io_revert_valid").value         = revert_inputs["valid"]
        getattr(self.dut, f"io_revert_bits_GHR").value      = revert_inputs["GHR"]
        getattr(self.dut, f"io_revert_bits_PC").value       = revert_inputs["PC"]
        pass

    def write_RAS(self, RAS_read_inputs=generate_null_RAS_read_inputs()):
        getattr(self.dut, f"io_RAS_read_NEXT").value   = RAS_read_inputs["NEXT"]
        getattr(self.dut, f"io_RAS_read_TOS").value   = RAS_read_inputs["TOS"]
        getattr(self.dut, f"io_RAS_read_ret_addr").value   = RAS_read_inputs["ret_addr"]

    def get_outputs(self):
        outputs = {}
        outputs["prediction_ready"] =getattr(self.dut, f"io_prediction_ready").value
        outputs["revert_ready"]     =getattr(self.dut, f"io_revert_ready").value
        outputs["valid"]            =getattr(self.dut, f"io_PC_next_valid").value
        outputs["PC"]               =getattr(self.dut, f"io_PC_next_bits").value
        return outputs

    def set_ready(self, ready):
        self.dut.io_PC_next_ready = ready


"""
  input         clock,
                reset,
                io_commit_valid,
  input  [31:0] io_commit_fetch_PC,
  input         io_commit_T_NT,
  input  [5:0]  io_commit_ROB_index,
  input  [2:0]  io_commit_br_type,
  input  [1:0]  io_commit_fetch_packet_index,
  input         io_commit_is_misprediction,
  input  [31:0] io_commit_expected_PC,
  input  [15:0] io_commit_GHR,
  input  [6:0]  io_commit_TOS,
                io_commit_NEXT,
  input  [3:0]  io_commit_RAT_index,
  output        io_prediction_ready,
  input         io_prediction_valid,
                io_prediction_bits_hit,
  input  [31:0] io_prediction_bits_target,
  input  [2:0]  io_prediction_bits_br_type,
  input  [3:0]  io_prediction_bits_br_mask,
  input  [15:0] io_prediction_bits_GHR,
  input         io_prediction_bits_T_NT,
  output        io_revert_ready,
  input         io_revert_valid,
  input  [15:0] io_revert_bits_GHR,
  input  [31:0] io_revert_bits_PC,
  input  [6:0]  io_RAS_read_NEXT,
                io_RAS_read_TOS,
  input  [31:0] io_RAS_read_ret_addr,
  input         io_PC_next_ready,
  output        io_PC_next_valid,
  output [31:0] io_PC_next_bits
"""

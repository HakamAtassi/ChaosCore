import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from cocotb.binary import BinaryValue
from tabulate import tabulate

# Add helper functions as needed

def generate_null_predict():
    predict_inputs = {}
    predict_inputs["valid"]  = 0
    predict_inputs["bits"]   = 0
    return predict_inputs

def generate_null_commit():
    commit_inputs = {}
    commit_inputs["valid"]                      = 0
    commit_inputs["fetch_PC"]                   = 0
    commit_inputs["T_NT"]                       = 0
    commit_inputs["is_misprediction"]           = 0
    commit_inputs["expected_PC"]                = 0
    commit_inputs["GHR"]                        = 0
    commit_inputs["TOS"]                        = 0
    commit_inputs["NEXT"]                       = 0
    commit_inputs["RAT_IDX"]                    = 0
    commit_inputs["br_type"]                    = 0
    commit_inputs["fetch_packet_index"]         = 0
    return commit_inputs

def generate_null_RAS_update():
    RAS_update = {}
    RAS_update["call_addr"]     = 0
    RAS_update["call"]   = 0
    RAS_update["ret"]    = 0
    return RAS_update

def generate_null_revert():
    revert_inputs = {}
    revert_inputs["valid"]    = 0
    revert_inputs["GHR"]      = 0
    revert_inputs["PC"]       = 0
    return revert_inputs

def decode_BTB_line(BTB_line):
    outputs = {}
    outputs["BTB_valid"]    = BTB_line[0]
    outputs["BTB_tag"]      = BTB_line[18:1]
    outputs["BTB_target"]   = BTB_line[50:19]
    outputs["BTB_br_type"]  = BTB_line[53:51]
    return outputs

"""
assign io_data_out_BTB_valid = hazard_reg ? din_buff_BTB_valid : _mem_ext_R0_data[0];
assign io_data_out_BTB_tag = hazard_reg ? din_buff_BTB_tag : _mem_ext_R0_data[18:1];
assign io_data_out_BTB_target = hazard_reg ? din_buff_BTB_target : _mem_ext_R0_data[50:19];
assign io_data_out_BTB_br_type = hazard_reg ? din_buff_BTB_br_type : _mem_ext_R0_data[53:51];
"""


class BP_dut:
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


    def write_predict(self, inputs=generate_null_predict()):
        getattr(self.dut, f"io_predict_valid").value          = inputs["valid"]
        getattr(self.dut, f"io_predict_bits").value           = inputs["bits"]

    def write_commit(self, inputs=generate_null_commit()):
        getattr(self.dut, f"io_commit_valid").value                   =   inputs["valid"]
        getattr(self.dut, f"io_commit_fetch_PC").value                =   inputs["fetch_PC"]
        getattr(self.dut, f"io_commit_T_NT").value                    =   inputs["T_NT"]
        getattr(self.dut, f"io_commit_is_misprediction").value        =   inputs["is_misprediction"]
        getattr(self.dut, f"io_commit_expected_PC").value             =   inputs["expected_PC"]
        getattr(self.dut, f"io_commit_GHR").value                     =   inputs["GHR"]
        getattr(self.dut, f"io_commit_TOS").value                     =   inputs["TOS"]
        getattr(self.dut, f"io_commit_NEXT").value                    =   inputs["NEXT"]
        getattr(self.dut, f"io_commit_RAT_IDX").value                 =   inputs["RAT_IDX"]
        getattr(self.dut, f"io_commit_fetch_packet_index").value      =   inputs["fetch_packet_index"]
        getattr(self.dut, f"io_commit_br_type").value                 =   inputs["br_type"]



    def write_RAS_update(self, inputs=generate_null_RAS_update()):
        getattr(self.dut, f"io_RAS_update_call_addr").value           =   inputs["call_addr"]
        getattr(self.dut, f"io_RAS_update_call").value                =   inputs["call"]
        getattr(self.dut, f"io_RAS_update_ret").value                 =   inputs["ret"]

    def write_revert(self, inputs=generate_null_revert()):
        getattr(self.dut, f"io_revert_valid").value                   =   inputs["valid"]
        getattr(self.dut, f"io_revert_bits_GHR").value                =   inputs["GHR"]
        getattr(self.dut, f"io_revert_bits_PC").value                 =   inputs["PC"]

    #outputs["ready"] = getattr(self.dut, f"io_predict_ready").value
    #outputs[""] = getattr(self.dut, f"io_revert_ready").value

    def get_prediction_outputs(self):
        outputs = {}
        outputs["valid"] = getattr(self.dut, f"io_prediction_valid").value
        outputs["hit"] = getattr(self.dut, f"io_prediction_bits_hit").value
        outputs["target"] = getattr(self.dut, f"io_prediction_bits_target").value
        outputs["br_type"] = getattr(self.dut, f"io_prediction_bits_br_type").value
        outputs["br_mask"] = getattr(self.dut, f"io_prediction_bits_br_mask").value
        outputs["GHR"] = getattr(self.dut, f"io_prediction_bits_GHR").value
        outputs["T_NT"] = getattr(self.dut, f"io_prediction_bits_T_NT").value
        return outputs

    def get_RAS_read_outputs(self):
        outputs = {}
        outputs["update_ret"] = getattr(self.dut, f"io_RAS_update_ret").value
        outputs["NEXT"] = getattr(self.dut, f"io_RAS_read_NEXT").value
        outputs["TOS"] = getattr(self.dut, f"io_RAS_read_TOS").value
        outputs["ret_addr"] = getattr(self.dut, f"io_RAS_read_ret_addr").value
        return outputs

    # Get internal memories

    def get_RAS_contents(self):
        #BP.RAS.RAS_memory.mem_ext
        RAS = [0]*128
        for i in range(128):
            RAS[i] = getattr(self.dut, f"RAS.RAS_memory.mem_ext.Memory")[i].value
        return RAS

    def get_PHT_contents(self):
        #BP.gshare.PHT.mem_ext
        PHT = [0]*4096
        for i in range(4096):
            PHT[i] = getattr(self.dut, f"gshare.PHT.mem_ext.Memory")[i].value
        return PHT

    def set_PHT(self):
        #BP.gshare.PHT.mem_ext
        for i in range(4096):
           getattr(self.dut, f"gshare.PHT.mem_ext.Memory")[i].value = 0b11

    def get_BTB_contents(self):
        #BP.BTB.BTB_memory.mem_ext
        BTB = {}

        BTB["BTB_valid"]     = [0]*4096
        BTB["BTB_tag"]       = [0]*4096
        BTB["BTB_target"]    = [0]*4096
        BTB["BTB_br_type"]   = [0]*4096
        for i in range(4096):
            # FIXME: there has to be a better way...
            BTB_line = int(getattr(self.dut, f"BTB.BTB_memory.mem_ext.Memory")[i].value)
            BTB_line = BinaryValue(value=BTB_line, n_bits=54 ,bigEndian=False)
            
            BTB["BTB_valid"][i]     = hex(decode_BTB_line(BTB_line)["BTB_valid"])
            BTB["BTB_tag"][i]       = hex(decode_BTB_line(BTB_line)["BTB_tag"])
            BTB["BTB_target"][i]    = hex(decode_BTB_line(BTB_line)["BTB_target"])
            BTB["BTB_br_type"][i]   = hex(decode_BTB_line(BTB_line)["BTB_br_type"])
        return BTB

    # print internal memories
    def print_RAS_contents(self):
        RAS = self.get_RAS_contents()
        table = [[i, RAS[i]] for i in range(len(RAS))]
        print(tabulate(table, headers=["Index", "RAS Value"], tablefmt="grid"))

    def print_PHT_contents(self):
        PHT = self.get_PHT_contents()
        table = [[i, PHT[i]] for i in range(len(PHT))]
        print(tabulate(table, headers=["Index", "PHT Value"], tablefmt="grid"))

    def print_BTB_contents(self):
        BTB = self.get_BTB_contents()
        #table = [[i, BTB[i]] for i in range(len(BTB))]
        #print(tabulate(BTB))
        #for i in range(len(BTB)):
            #print(BTB[i])
        print(tabulate(BTB, headers="keys", tablefmt="grid"))

    def print_GHR_contents(self):
        GHR = self.get_GHR_contents()
        table = [["GHR Value", GHR]]
        print(tabulate(table, headers=["GHR", "Value"], tablefmt="grid"))


"""
  input         clock,
                reset,
  output        io_predict_ready,
  input         io_predict_valid,
  input  [31:0] io_predict_bits,
  input         io_commit_valid,
  input  [31:0] io_commit_fetch_PC,
  input         io_commit_T_NT,
                io_commit_is_BR,
                io_commit_is_misprediction,
  input  [31:0] io_commit_expected_PC,
  input  [15:0] io_commit_GHR,
  input  [6:0]  io_commit_TOS,
                io_commit_NEXT,
  input  [3:0]  io_commit_RAT_IDX,
  input  [31:0] io_RAS_update_call_addr,
  input         io_RAS_update_call,
                io_RAS_update_ret,
  output [6:0]  io_RAS_read_NEXT,
                io_RAS_read_TOS,
  output [31:0] io_RAS_read_ret_addr,
  output        io_revert_ready,
  input         io_revert_valid,
  input  [15:0] io_revert_bits_GHR,
  input  [31:0] io_revert_bits_PC,
  input         io_prediction_ready,
  output        io_prediction_valid,
                io_prediction_bits_hit,
  output [31:0] io_prediction_bits_target,
  output [1:0]  io_prediction_bits_br_type,
  output [3:0]  io_prediction_bits_br_mask,
  output [15:0] io_prediction_bits_GHR,
  output        io_prediction_bits_T_NT
"""
#io_commit_fetch_packet_index
#io_commit_br_type

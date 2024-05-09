from Channels import *
from cocotb.handle import Force, Release
import cocotb
from cocotb.triggers import RisingEdge, ReadOnly
import random
import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path



class QDut:
    def __init__(self, dut):
        self.dut=dut

    def clock(self):
        return self.dut.clock

    def write_to_Q(self, addr, valid):
        self.dut.io_data_in.value=addr
        self.dut.io_wr_en.value=valid

    def read_from_Q(self, valid):
        self.dut.io_rd_en.value=valid

    def clear_Q(self, valid):
        self.dut.io_clear.value=valid

"""
  input         clock,
                reset,
  input  [31:0] io_data_in,
  input         io_wr_en,
                io_rd_en,
                io_clear,
  output [31:0] io_data_out,
  output        io_full,
                io_empty
"""
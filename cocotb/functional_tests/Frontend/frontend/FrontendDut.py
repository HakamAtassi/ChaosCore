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



class FrontendDut:
    def __init__(self, dut, dram_model):
        self.dut=dut
        self.outstanding_dram_request = False
        self.remaining_dram_latency=0
        self.dram_model = dram_model


        # dram glue logic

        self.dram_request_valid = 0
        self.dram_request_address = 0x0

    def clock(self):
        return self.dut.clock

    def init_dram(self, file):
        # write binary file to cache. 

        pass

    def write_from_dram(self, data, valid=1):
        self.dut.io_dram_data_valid.value = valid
        self.dut.io_dram_data_bits.value = data

    async def cycle(self):

        # drive signals
        dram_data, dram_valid =  self.dram_model.update(self.dram_request_address, 32, self.dram_request_valid)
        self.write_from_dram(dram_data, dram_valid)

        # read signals
        await ReadOnly()
        self.dram_request_valid =  self.dut.io_cache_addr_valid.value 
        self.dram_request_address = self.dut.io_cache_addr_bits.value 

        await RisingEdge(self.clock())


    def get_PC_queue(self):
        PC_Q = []
        for entry in self.dut.PC_Q.queue.ram_ext.Memory:
            PC_Q.append(hex(int(entry.value)))
           
        full =  self.dut.PC_Q.io_full.value
        empty =  self.dut.PC_Q.io_empty.value

        return PC_Q, full, empty

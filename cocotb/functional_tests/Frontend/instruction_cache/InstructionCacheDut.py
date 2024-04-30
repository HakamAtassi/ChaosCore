import sys
from time import sleep
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path
from model_utils import *

class InstructionCacheDut:
    def __init__(self, dut, DRAM=None):
        self.dut = dut
        self.DRAM = DRAM
        self.dram_latency = 0   # a counter for randomizing dram latency.

    ### INTERFACE ###

    def clock(self):
        return self.dut.clock

    def cpu_read_ready(self):
        """is the cache ready for a read request from the cpu?"""
        ready = int(self.dut.io_cpu_addr_ready.value)
        return ready == 1
    
    def dram_write_ready(self):
        """is the cache ready for a write request from the cpu?"""
        ready = int(self.dut.io_dram_data_ready.value)
        return ready == 1

    def cpu_read_valid(self):
        """is the cache's output valid"""
        valid = int(self.dut.io_cache_data_valid.value)
        return valid == 1

    def cpu_dram_ready(self):
        valid = int(self.dut.io_dram_data_ready.value)
        return valid == 1

    def dram_resp(self, data, valid):
        self.dut.io_dram_data_valid.value = valid
        self.dut.io_dram_data_bits.value = data


    def cpu_read_resp(self):
        """returns caches output as ((i0,i1,i2,i3),(v0,v1,v2,v3))"""
        instructions = (hex(int(self.dut.io_cache_data_bits_instructions_0.value)),
                        hex(int(self.dut.io_cache_data_bits_instructions_1.value)),
                        hex(int(self.dut.io_cache_data_bits_instructions_2.value)),
                        hex(int(self.dut.io_cache_data_bits_instructions_3.value)))

        valid = (hex(int(self.dut.io_cache_data_bits_valid_bits_0.value)),
                 hex(int(self.dut.io_cache_data_bits_valid_bits_1.value)),
                 hex(int(self.dut.io_cache_data_bits_valid_bits_2.value)),
                 hex(int(self.dut.io_cache_data_bits_valid_bits_3.value)))

        return (instructions, valid)
    
    def read_data_memory(self,way, addr):
        line = int(getattr(self.dut, f"data_memory_{way}.ram_ext.Memory")[addr].value)
        return line & ((1<<256) - 1)
    
    def get_cache_state(self):
        cache_state=[[] for _ in range(2)]
        for way in range(2):
            for set in range(64):
                cache_state[way].append(self.read_data_memory(way, set))
        return cache_state
    ### UTILS ###

    async def dram_request_write(self, data):
        """request a write from the dram"""
        self.dut.io_dram_data_valid.value = 1
        self.dut.io_dram_data_bits.value = data
        await RisingEdge(self.dut.clock)
        self.dut.io_dram_data_valid.value = 0
        self.dut.io_dram_data_bits.value = 0



    async def cpu_read(self, address, valid):
        """request a read from the cpu"""

        self.dut.io_cpu_addr_valid.value = valid     # set valid
        self.dut.io_cpu_addr_bits.value = address    # pass address

        #await RisingEdge(self.dut.clock)

        #self.dut.io_cpu_addr_valid.value = 0
        #self.dut.io_cpu_addr_bits.value = 0

        #if(self.cpu_read_valid() == False):
            ## Cache missed. Generate DRAM response
            #self.dram_latency = random.randint(1,100)
            #self.outstanding_dram_request = True
            #self.outstanding_dram_address = address

    async def wait_dram_resp(self):
        while(self.dram_latency):
            await self.dram_cycle()
            await RisingEdge(self.dut.clock)

    async def dram_cycle(self):
        if(self.dram_latency == 0 and self.outstanding_dram_request == True):
            dram_data = self.DRAM.read(address=align(self.outstanding_dram_address, bytes=32), size=32)    # Get dram line
            await self.dram_request_write(dram_data) # write to cache
            self.outstanding_dram_request = False
        elif(self.dram_latency > 0 and self.outstanding_dram_request == True):
            self.dram_latency-=1


"""
module L1_instruction_cache(
  input          clock,
                 reset,
  output         io_cpu_addr_ready,
  input          io_cpu_addr_valid,
  input  [31:0]  io_cpu_addr_bits,
  output         io_dram_data_ready,
  input          io_dram_data_valid,
  input  [255:0] io_dram_data_bits,
  input          io_kill,
                 io_cache_data_ready,
  output         io_cache_data_valid,
  output [31:0]  io_cache_data_bits_fetch_PC,
                 io_cache_data_bits_instructions_0,
                 io_cache_data_bits_instructions_1,
                 io_cache_data_bits_instructions_2,
                 io_cache_data_bits_instructions_3,
  output         io_cache_data_bits_valid_bits_0,
                 io_cache_data_bits_valid_bits_1,
                 io_cache_data_bits_valid_bits_2,
                 io_cache_data_bits_valid_bits_3,
  input          io_cache_addr_ready,
  output         io_cache_addr_valid,
  output [31:0]  io_cache_addr_bits
);
"""
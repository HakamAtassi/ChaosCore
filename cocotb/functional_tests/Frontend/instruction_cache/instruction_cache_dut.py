import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from cocotb.binary import BinaryValue

from SimpleDRAM import *

from tabulate import tabulate

# Add helper functions as needed

class instruction_cache_dut:
    def __init__(self, dut, DRAM, DRAM_line_size=32):    # modify as needed (parameters, etc...)
        self.dut = dut
        self.DRAM = DRAM

        # Control signals
        self.DRAM_request       = False
        self.DRAM_request_addr  = 0x0
        self.DRAM_request_size  = DRAM_line_size

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0

    def request_read(self, address=0, valid=0):
        getattr(self.dut, f"io_cpu_addr_valid").value = valid
        getattr(self.dut, f"io_cpu_addr_bits").value = address

    def request_allocate(self, data=0, valid=0):
        getattr(self.dut, f"io_DRAM_resp_valid").value      = valid
        getattr(self.dut, f"io_DRAM_resp_bits_data").value  = data

    def set_dram_ready(self, ready):
        #getattr(self.dut ,f"io_cpu_addr_ready").value = ready
        getattr(self.dut ,f"io_DRAM_request_ready").value = ready

    def set_cache_ready(self, ready):
        getattr(self.dut ,f"io_cache_data_ready").value = ready

    def get_cache_output(self):
        output = {}

        output["packet_valid"] = getattr(self.dut, f"io_cache_data_valid").value
        output["fetch_PC"] = getattr(self.dut, f"io_cache_data_bits_fetch_PC").value
        
        output["DRAM_request_valid"]    = getattr(self.dut, f"io_DRAM_request_valid").value
        output["DRAM_addr"]             = getattr(self.dut, f"io_DRAM_request_bits_addr").value

        output["cpu_addr_ready"]        = getattr(self.dut, f"io_cpu_addr_ready").value
        

        output["instruction_valid"] = [0]*4
        output["instruction"] = [0]*4
        output["packet_index"] = [0]*4
        output["ROB_index"] = [0]*4

        for i in range(4):
            output["instruction_valid"][i]     = getattr(self.dut, f"io_cache_data_bits_valid_bits_{i}").value
            output["instruction"][i]           = getattr(self.dut, f"io_cache_data_bits_instructions_{i}_instruction").value
            output["packet_index"][i]          = getattr(self.dut, f"io_cache_data_bits_instructions_{i}_packet_index").value
            output["ROB_index"][i]             = getattr(self.dut, f"io_cache_data_bits_instructions_{i}_ROB_index").value

        return output

    def get_cache_contents(self):
        cache = [{"valid": [0]*64, "tag": [0]*64, "data": [0]*64} for _ in range(2)]

        for way in range(2):
            for i in range(64):
                # Retrieve the memory line
                line = int(getattr(self.dut, f"data_memory_{way}.mem_ext.Memory")[i])
                # Convert to BinaryValue
                line = BinaryValue(value=line, n_bits=278, bigEndian=False)
                # Extract valid, tag, and data
                valid = line[0]
                tag = int(line[21:1])
                data = int(line[277:22])
                # Store in the cache
                cache[way]["valid"][i] = valid
                cache[way]["tag"][i] = tag
                cache[way]["data"][i] = data

        return cache

    def print_cache_contents(self):
        cache = self.get_cache_contents()
        # Format cache contents for printing
        formatted_cache = []
        for way in range(2):
            for i in range(64):
                formatted_cache.append([way, i, hex(cache[way]["valid"][i]), hex(cache[way]["tag"][i]), hex(cache[way]["data"][i])])
        print(tabulate(formatted_cache, headers=["Way", "Index", "Valid", "Tag", "Data"]))

    async def update(self):
        # await cycle
        # if needs memory (from prev cycle)
            # send data from dram model
        # await ReadOnly()
        # set mem addr flag, size, etc

        await RisingEdge(self.dut.clock)

        # Clear writes from prev cycle (so you dont write twice)
        self.request_allocate()

        if(self.DRAM_request):
            data = self.DRAM.read(address=self.DRAM_request_addr, size=self.DRAM_request_size)
            self.request_allocate(data, 1)

        await ReadOnly()

        self.DRAM_request       =   self.get_cache_output()["DRAM_request_valid"]
        self.DRAM_request_addr  =   self.get_cache_output()["DRAM_addr"]


    async def wait_response(self):
        while(1):
            if(self.get_cache_output()["packet_valid"]):
                return 
            await self.update()

    def get_cache_state(self):
        pass




"""
input          clock,
                reset,
output         io_cpu_addr_ready,
input          io_cpu_addr_valid,
input  [31:0]  io_cpu_addr_bits,
input          io_kill,
output         io_DRAM_resp_ready,
input          io_DRAM_resp_valid,
input  [127:0] io_DRAM_resp_bits_data,
input          io_cache_data_ready,
output         io_cache_data_valid,
output [31:0]  io_cache_data_bits_fetch_PC,
output         io_cache_data_bits_valid_bits_0,
                io_cache_data_bits_valid_bits_1,
                io_cache_data_bits_valid_bits_2,
                io_cache_data_bits_valid_bits_3,
output [31:0]  io_cache_data_bits_instructions_0_instruction,
output [3:0]   io_cache_data_bits_instructions_0_packet_index,
output [5:0]   io_cache_data_bits_instructions_0_ROB_index,
output [31:0]  io_cache_data_bits_instructions_1_instruction,
output [3:0]   io_cache_data_bits_instructions_1_packet_index,
output [5:0]   io_cache_data_bits_instructions_1_ROB_index,
output [31:0]  io_cache_data_bits_instructions_2_instruction,
output [3:0]   io_cache_data_bits_instructions_2_packet_index,
output [5:0]   io_cache_data_bits_instructions_2_ROB_index,
output [31:0]  io_cache_data_bits_instructions_3_instruction,
output [3:0]   io_cache_data_bits_instructions_3_packet_index,
output [5:0]   io_cache_data_bits_instructions_3_ROB_index,
input          io_DRAM_request_ready,
output         io_DRAM_request_valid,
output [31:0]  io_DRAM_request_bits_addr,
                io_DRAM_request_bits_wr_data,
output         io_DRAM_request_bits_wr_en
"""
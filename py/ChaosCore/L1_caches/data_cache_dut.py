
import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
from enum import Enum


class memory_type_t(Enum):
    NONE = 0
    LOAD = 1
    STORE = 2

class access_width_t(Enum):
    NONE = 0
    B = 1  # Byte
    HW = 2 # Half-word
    W = 3  # Word

class data_cache_dut:
    def __init__(self, dut):
        self.L1_data_cache = dut

    #################
    # CLOCK / RESET #
    #################

    async def clock(self):  # Do not touch
        await RisingEdge(self.L1_data_cache.clock)

    async def reset(self):  # Do not touch
        await RisingEdge(self.L1_data_cache.clock)
        self.L1_data_cache.reset.value = 1
        await RisingEdge(self.L1_data_cache.clock)
        self.L1_data_cache.reset.value = 0


    def write_CPU_request(self, valid, addr, data, memory_type, access_width, MOB_index):
        self.L1_data_cache.io_CPU_request_valid.value                = valid
        self.L1_data_cache.io_CPU_request_bits_addr.value            = addr
        self.L1_data_cache.io_CPU_request_bits_data.value            = data
        self.L1_data_cache.io_CPU_request_bits_memory_type.value     = memory_type.value
        self.L1_data_cache.io_CPU_request_bits_access_width.value    = access_width.value
        self.L1_data_cache.io_CPU_request_bits_MOB_index.value       = MOB_index


    def write_CPU_response_ready(self, ready):
        self.L1_data_cache.io_CPU_response_ready.value = ready


    def read_CPU_response(self):
        cache_response          = {}
        cache_response["bits"]  = {}
        cache_response["valid"]             = int(self.L1_data_cache.io_CPU_response_valid.value)
        cache_response["bits"]["data"]      = int(self.L1_data_cache.io_CPU_response_bits_data.value)
        cache_response["bits"]["MOB_index"] = self.L1_data_cache.io_CPU_response_bits_MOB_index.value
        return cache_response



#output        io_CPU_request_ready,
#input         io_CPU_request_valid,
#input  [31:0] io_CPU_request_bits_addr,
#io_CPU_request_bits_data,
#input  [1:0]  io_CPU_request_bits_memory_type,
#io_CPU_request_bits_access_width,
#input  [3:0]  io_CPU_request_bits_MOB_index,

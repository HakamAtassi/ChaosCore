
from cocotbext.axi import AxiBus, AxiRam
from L1_caches import data_cache_dut
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam
from cocotb.triggers import RisingEdge, ReadOnly
from enum import Enum
from L1_caches.data_cache_dut import *
import random


class L1_data_cache_TB:
    def __init__(self, dut, memory_capacity=512*(2**20)):
        # Top level Module #
        self.L1_data_cache = data_cache_dut(dut)

        # init AXI slave memory
        # For now, use 256MB of random data
        self.memory_capacity = memory_capacity
        self.axi_ram = AxiRam(AxiBus.from_prefix(
            dut, "m_axi"), dut.clock, dut.reset, size=self.memory_capacity)

    def init_sequence(self, randomize=False):
        # INIT MEMORY
        for i in range(self.memory_capacity):
            if randomize:
                # Generating a random 4-byte word
                word = random.getrandbits(32)
            else:
                # Generating a BIST sequence word
                word = i & 0xFF
            self.axi_ram.write(i, word.to_bytes(1, byteorder='little'))
        # self.axi_ram.hexdump(0x0000, 1024, prefix="RAM")

    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.L1_data_cache.reset()

    async def clock(self):
        await self.L1_data_cache.clock()

    ######################
    # CACHE READ REQUEST #
    ######################

    async def write_CPU_request(self, valid, addr, data, memory_type, access_width, MOB_index):
        self.L1_data_cache.write_CPU_request(
            valid, addr, data, memory_type, access_width, MOB_index)
        await self.clock()
        self.L1_data_cache.write_CPU_request(
            0, 0, 0, memory_type_t.NONE, access_width_t.NONE, 0)

    def read_CPU_response(self):
        return self.L1_data_cache.read_CPU_response()

    ###############
    # CACHE READY #
    ###############

    def write_CPU_response_ready(self, ready):
        self.L1_data_cache.write_CPU_response_ready(ready)

    def get_CPU_request_ready(self):
        return self.L1_data_cache.io_CPU_request_ready.value

    async def wait_cache_hit(self):
        for _ in range(100000):
            await self.clock()
            if (int(self.read_CPU_response()["valid"])):
                return
        assert False, "Error: Cache did not return for 1000 cycles"

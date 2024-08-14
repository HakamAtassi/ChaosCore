
from cocotbext.axi import AxiBus, AxiRam
from L1_caches import instruction_cache_dut
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam
from cocotb.triggers import RisingEdge, ReadOnly
import random


class L1_instruction_cache_TB:
    def __init__(self, dut):
        # Top level Module #
        self.L1_instruction_cache = instruction_cache_dut(dut)

        # init AXI slave memory
        # For now, use 256MB of random data
        self.memory_capacity = 256*(2**20)
        self.axi_ram = AxiRam(AxiBus.from_prefix(dut, "m_axi"), dut.clock, dut.reset, size=self.memory_capacity)


    def init_sequence(self):
        # INIT MEMORY 
        for i in range(256*2**10):
            # Writing a 4-byte word to memory
            self.axi_ram.write(i*4, (i & 0xFFFF_FFFF).to_bytes(4, byteorder='little'))

        #self.axi_ram.hexdump(0x0000, 256*4, prefix="RAM")

    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.L1_instruction_cache.reset()

    async def clock(self):
        await self.L1_instruction_cache.clock()


    ######################
    # CACHE READ REQUEST #
    ######################

    async def write_CPU_read_request(self, address, valid):
        self.L1_instruction_cache.write_CPU_read_request(address, valid)
        await self.L1_instruction_cache.clock()
        self.L1_instruction_cache.write_CPU_read_request()


    def CPU_read_response(self):
        return self.L1_instruction_cache.read_CPU_read_response()


    def set_CPU_response(self, ready):
        self.L1_instruction_cache.set_CPU_response(ready)



    async def wait_cache_hit(self):
        for _ in range(100000):
            await self.clock()
            if(int(self.L1_instruction_cache.read_CPU_read_response()["valid"])):
                return

        assert False, "Error: Cache did not return for 1000 cycles"
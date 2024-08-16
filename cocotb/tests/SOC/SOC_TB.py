
from cocotbext.axi import AxiBus, AxiRam
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam
from cocotb.triggers import RisingEdge, ReadOnly
import random


class SOC_TB:
    def __init__(self, dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/hello_world.bin"):
        # Top level Module #
        self.dut = dut

        # init AXI slave memory
        # For now, use 256MB of random data
        self.memory_capacity = 256*(2**20)
        self.axi_ram = AxiRam(AxiBus.from_prefix(dut, "m_axi"), dut.clock, dut.reset, size=self.memory_capacity)

        with open(binary, "rb") as f:
            binary_data = f.read()
        
        # Write binary data to AXI RAM
        for i, byte in enumerate(binary_data):
            self.axi_ram.write(i, byte.to_bytes(1, byteorder='little'))
        
        # Optionally, dump a portion of memory to verify
        self.axi_ram.hexdump(0x0000, min(len(binary_data), 1024), prefix="RAM")  # Dump up to 1KB or file size

    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.clock()
        self.dut.reset.value = 1
        await self.clock()
        await self.clock()
        await self.clock()
        self.dut.reset.value = 0
        await self.clock()


    async def clock(self):
        await RisingEdge(self.dut.clock)


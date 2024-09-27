
from cocotbext.axi import AxiBus, AxiRam
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam
from cocotb.triggers import RisingEdge, ReadOnly
import random

from monitors.rename_mon import *
from monitors.memory_mon import *
from monitors.SOC_mon import *


class SOC_TB:
    def __init__(self, dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/hello_world.bin"):
        # Top level Module #
        self.dut = dut

        # init AXI slave memory
        # For now, use 256MB of random data
        self.memory_capacity = 256*(2**20)
        self.axi_ram = AxiRam(AxiBus.from_prefix(dut, "m_axi"), dut.clock, dut.reset, size=self.memory_capacity)

        self.axi_ram.write_if.log.setLevel(logging.CRITICAL)
        self.axi_ram.read_if.log.setLevel(logging.CRITICAL)



        with open(binary, "rb") as f:
            binary_data = f.read()
        
        # Write binary data to AXI RAM
        for i, byte in enumerate(binary_data):
            self.axi_ram.write(i, byte.to_bytes(1, byteorder='little'))
        
        # Optionally, dump a portion of memory to verify
        self.axi_ram.hexdump(0x0000, len(binary_data), prefix="RAM")  # Dump up to 1KB or file size



        # TOP MONITOR #
        self.SOC_monitor = SOC_mon(self.dut.ChaosCore_tile.ChaosCore)   # this monitors instructions and their commit/value...


        # INIT MONITORS #
        self.rename_monitor = rename_mon(self.dut.ChaosCore_tile.ChaosCore.frontend.rename)
        self.memory_monitor = memory_mon(self.dut.ChaosCore_tile.ChaosCore.backend.MOB)

        

    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.clock()
        self.dut.reset.value = 1
        await self.clock()
        await self.clock()
        await self.clock()
        await self.clock()
        await self.clock()
        await self.clock()
        await self.clock()
        self.dut.reset.value = 0
        await self.clock()


    async def clock(self):
        try:
            #self.rename_monitor.monitor()
            #self.memory_monitor.monitor()
            #self.SOC_monitor.monitor()
            #ROB_commit_valid = int(self.dut.ChaosCore_tile.ChaosCore.ROB.commit_valid.value)
            #ROB_fetch_PC = int(self.dut.ChaosCore_tile.ChaosCore.ROB.commit_fetch_PC.value)
            #if(ROB_commit_valid == 1  and ROB_fetch_PC == 0x800004c0):
                #sim_time = cocotb.utils.get_sim_time("ns")
                #print(f"found @ {sim_time}")
            await RisingEdge(self.dut.clock)
        except(AssertionError):
            await RisingEdge(self.dut.clock)
            #await RisingEdge(self.dut.clock)
            #await RisingEdge(self.dut.clock)
            assert False

    def get_RS_mapping(self, reg):
        return int(getattr(self.dut, f"ChaosCore_tile.ChaosCore.frontend.rename.RAT.commit_RAT_{reg}"))

    def get_RS_data(self, reg):
        return int(self.dut.ChaosCore_tile.ChaosCore.backend.INT_PRF.mem_ext.Memory[reg])

    def riscv_test_pass(self):
        PRS_31 = self.get_RS_mapping(31)
        x31_data = self.get_RS_data(PRS_31)
        if(x31_data == 0x42424230):
            return True
        else: 
            return False




from cocotbext.axi import AxiBus, AxiRam
from L1_caches import instruction_cache_dut
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam


class L1_instruction_cache_TB:
    def __init__(self, dut):
        # Top level Module #
        self.L1_instruction_cache = instruction_cache_dut(dut)

        # init AXI slave memory
        # For now, use 256MB of random data
        memory_capacity = 256*(2**20)
        axi_ram = AxiRam(AxiBus.from_prefix(dut, "m_axi"), dut.clock, dut.reset, size=memory_capacity)
        #for i in range(axi_ram):
            #AxiRam.memory = 0x42

        




    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.ChaosCore_dut.reset()

    async def update(self): # clock with memory access
        await self.ChaosCore_dut.update()

    ################
    # START AGENTS #
    ################

    #def start(self):
        ## Set external readies
        #self.ChaosCore_dut.write_dmem_request_ready(1)
        #self.ChaosCore_dut.write_imem_request_ready(1)




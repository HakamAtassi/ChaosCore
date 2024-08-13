
import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly


class data_cache_dut:
    def __init__(self, dut):
        self.L1_data_cache = dut

    #################
    # CLOCK / RESET #
    #################

    def clock(self):  # Do not touch
        return self.ChaosCore.clock

    async def reset(self):  # Do not touch
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 1
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 0

    

      




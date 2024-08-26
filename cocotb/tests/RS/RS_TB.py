
import cocotb
from L1_caches import data_cache_dut
from cocotb.triggers import RisingEdge, ReadOnly
from enum import Enum
import random

from model_utils import *
from drivers.driver import *

class RS_TB:
    def __init__(self, dut):
        # Top level Module #
        self.RS = dut

        self.driver = driver(dut)


    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        self.RS.reset.value = 1
        await self.clock()
        await self.clock()
        self.RS.reset.value = 0
        await self.clock()

    async def clock(self):
        await RisingEdge(self.RS.clock)


    async def update(self):
        await self.driver.update()


    async def post_simulation(self):
        await self.driver.post_simulation()



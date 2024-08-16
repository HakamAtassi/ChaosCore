import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from SOC_TB import *
from L1_caches import instruction_cache_dut

@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    SOC = SOC_TB(dut)     # construct TB
    await SOC.reset()                      # Reset



    for _ in range(10000):
        await SOC.clock()

    assert False

    


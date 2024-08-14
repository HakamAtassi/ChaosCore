import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from L1_data_cache_TB import *
from L1_caches import *

@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset


@cocotb.test()
async def test_read(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    await L1_cache.write_CPU_request(valid = 1, addr = 0x20, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=0)

    for _ in range(1000):
        await L1_cache.clock()




import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

import os

from cocotb_utils import *
from ChaosCore_dut import *
from SimpleDRAM import SimpleDRAM

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ChaosCore_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_reset(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "bins/hello_world.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 



    dut = ChaosCore_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_dram_ready(1)   # dram ready for request (from cache)

    await RisingEdge(dut.clock())

    for _ in range(1000):
        await dut.update()


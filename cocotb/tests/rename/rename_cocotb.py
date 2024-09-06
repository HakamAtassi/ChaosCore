import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from model_utils import *
from cocotb_utils import *



@cocotb.test()
async def test_reset(dut):
    #Set seed
    random.seed(0x42)

    #Start lock
    await cocotb.start(generateClock(dut))

@cocotb.test()
async def test_rename0(dut):
    #Set seed
    random.seed(0x42)

    #Start clock
    await cocotb.start(generateClock(dut))

    dut.reset.value = 1
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)




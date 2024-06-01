import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *
from MEMRS_dut import *

@cocotb.test()
async def reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
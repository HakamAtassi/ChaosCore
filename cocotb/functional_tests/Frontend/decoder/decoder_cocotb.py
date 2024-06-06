import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from decoder_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = decoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


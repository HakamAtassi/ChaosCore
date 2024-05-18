import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *


@cocotb.test()
async def test_dff_simple(dut):
    """ Test that d propagates to q """

    await cocotb.start(generateClock(dut)) 

    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
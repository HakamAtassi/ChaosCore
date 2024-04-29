import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from instructionCache import *  # import model
from cocotb_utils import *

SETS = 64
WAYS = 2
BLOCKSIZE = 32
FETCHWIDTH = 4

@cocotb.test()
async def instructionCacheFuzz_hits_only(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    cache = instructionCache(sets=SETS, ways=WAYS, blockSize=BLOCKSIZE, fetchWidth=FETCHWIDTH)
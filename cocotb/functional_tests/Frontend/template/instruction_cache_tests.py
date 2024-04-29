import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer

import random
import sys
from pathlib import Path
sys.path.append(str(Path("../../../lib/models/instructionCache/").resolve()))
sys.path.append(str(Path("../../../lib/models/genericLRU/").resolve()))
sys.path.append(str(Path("../../../lib/").resolve()))
from utils import *
from instructionCache import *


SETS = 64
WAYS = 2
BLOCKSIZE = 32
FETCHWIDTH = 4

async def generateClock(dut):
    while(1):
        dut.clock.value = 0
        await Timer(1, units="ns")
        dut.clock.value = 1
        await Timer(1, units="ns")

async def reset(dut):
    dut.reset.value = 0
    await RisingEdge(dut.clock)
    dut.reset.value = 1
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)

@cocotb.test()
async def instructionCacheFuzz_hits_only(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    # initialize an instruction memory
    # construct a pool of memory addresses of various characteristics (max tag, min tag, set collision, empty data, etc)
    # use this pool of (memory, data) pairs to initialize the actual cache and the modela
    # create a queue of memory requests using this pool of (memory, data) pairs
    # Buffer the results of each such that they are synchronized
    # Compare results...
    ######
    ######

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

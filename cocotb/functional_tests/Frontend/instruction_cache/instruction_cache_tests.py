import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

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

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    cache = instructionCache(sets=SETS, ways=WAYS, blockSize=BLOCKSIZE, fetchWidth=FETCHWIDTH)
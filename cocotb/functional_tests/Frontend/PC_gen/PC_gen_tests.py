import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from InstructionCache import *
from SimpleDRAM import *

from cocotb_utils import *      # import verif utils
from model_utils import *


SETS = 64
WAYS = 2
BLOCKSIZE = 32
FETCHWIDTH = 4


@cocotb.test()
async def instruction_cache_kill_miss_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    model_dram = SimpleDRAM(sizeKB=1<<10)
    model_dram.randomize()
    dut = InstructionCacheDut(dut, model_dram)  # Extend dut

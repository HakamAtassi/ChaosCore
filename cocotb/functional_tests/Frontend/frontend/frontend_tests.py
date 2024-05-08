import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path

from InstructionCache import *
from SimpleDRAM import *

from cocotb_utils import *      # import verif utils
from model_utils import *
from Channels import *
from FrontendDut import *


@cocotb.test()
async def test0(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    model_dram = SimpleDRAM(sizeKB=1<<10)
    dut = FrontendDut(dut, model_dram)



    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await reset(dut.dut)


    #dut.dram_model.randomize()
    dut.dram_model.write(0, fuzz("I"), 4)
    dut.dram_model.print()

    

    for _ in range(1000):
        await dut.cycle()

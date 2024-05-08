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
async def instruction_cache_kill_miss_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    model_dram = SimpleDRAM(sizeKB=1<<10)
    dut = FrontendDut(dut, model_dram)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await reset(dut.dut)

    #print(hex(fuzz(instruction_type='I')))

    dut.set_output_Q_ready()

    for i in range(0, (1<<20), 4):
        model_dram.write(i, fuzz(instruction_type='I'), 4)
    
    for _ in range(200):

        dut.update()


        await RisingEdge(dut.clock())

    model_dram.print()



    
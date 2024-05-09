import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.handle import Force, Release
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

    dut.dut.io_fetch_packet_ready.value = 1


    #dut.dram_model.randomize()
    dut.dram_model.write(0, fuzz("I"), 4)
    dut.dram_model.write(4, fuzz("I"), 4)
    dut.dram_model.write(8, fuzz("I"), 4)
    dut.dram_model.write(12, 0xff5ff06f, 4)

    #dut.dram_model.print()

    

    for _ in range(1000):
        await dut.cycle()


@cocotb.test()
async def test_PC_queue(dut):

    await cocotb.start(generateClock(dut)) 

    model_dram = SimpleDRAM(sizeKB=1<<10)
    dut = FrontendDut(dut, model_dram)



    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await reset(dut.dut)
    await ReadOnly()

    print(dut.get_PC_queue()[0])
    print(f"full: {dut.get_PC_queue()[1]}")
    print(f"empty: {dut.get_PC_queue()[2]}")

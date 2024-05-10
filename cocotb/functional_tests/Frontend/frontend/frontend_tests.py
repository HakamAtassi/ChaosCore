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
    dut.dram_model.write(0*4, fuzz("I"), 4)
    dut.dram_model.write(1*4, fuzz("I"), 4)
    dut.dram_model.write(2*4, fuzz("I"), 4)
    dut.dram_model.write(3*4, fuzz("I"), 4)
    dut.dram_model.write(4*4, fuzz("I"), 4)
    dut.dram_model.write(5*4, fuzz("I"), 4)
    dut.dram_model.write(6*4, fuzz("I"), 4)
    dut.dram_model.write(7*4, fuzz("I"), 4)
    dut.dram_model.write(8*4, fuzz("I"), 4)
    dut.dram_model.write(9*4, fuzz("I"), 4)
    dut.dram_model.write(10*4, fuzz("I"), 4)
    dut.dram_model.write(11*4, fuzz("I"), 4)
    dut.dram_model.write(12*4, fuzz("I"), 4)
    dut.dram_model.write(13*4, fuzz("I"), 4)
    dut.dram_model.write(14*4, fuzz("I"), 4)
    dut.dram_model.write(15*4, fuzz("I"), 4)
    dut.dram_model.write(16*4, fuzz("I"), 4)
    dut.dram_model.write(17*4, fuzz("I"), 4)
    dut.dram_model.write(18*4, fuzz("I"), 4)
    dut.dram_model.write(19*4, fuzz("I"), 4)
    dut.dram_model.write(20*4, fuzz("I"), 4)
    dut.dram_model.write(21*4, fuzz("I"), 4)
    dut.dram_model.write(22*4, fuzz("I"), 4)
    dut.dram_model.write(23*4, 0xfa5ff06f, 4)

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

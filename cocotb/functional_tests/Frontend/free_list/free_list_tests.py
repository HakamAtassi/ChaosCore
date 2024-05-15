import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *      # import verif utils
from model_utils import *

from FreeListDut import *

@cocotb.test()
async def test0(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 


    await reset(dut)
    

    dut = FreeListDut(dut)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await RisingEdge(dut.clock())
    dut.rename([0b0, 0b0, 0b0, 0b0])
    await ReadOnly()

    first_out = dut.get_renamed_regs()

    assert first_out == [0,1,2,3]

    await RisingEdge(dut.clock())
    dut.rename([0b1, 0b1, 0b1, 0b1])


    await RisingEdge(dut.clock())
    dut.rename([0b0, 0b0, 0b0, 0b0])
    await ReadOnly()
    first_out = dut.get_renamed_regs()
    assert first_out == [4,5,6,7]

    
@cocotb.test()
async def test1(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    

    dut = FreeListDut(dut)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await RisingEdge(dut.clock())
    
    # Read once
    # free once with random data
    # read 92 times 
    # check if freed values match


    dut.rename([0b1, 0b1, 0b1, 0b1])
    await RisingEdge(dut.clock())
    dut.rename([0b0, 0b0, 0b0, 0b0])


    dut.free([42,66,11,73] ,[0b1, 0b1, 0b1, 0b1])
    await RisingEdge(dut.clock())

    dut.free([42,66,11,73] ,[0b0, 0b0, 0b0, 0b0])
    await RisingEdge(dut.clock())

    for _ in range(0, 124, 4):
        dut.rename([0b1, 0b1, 0b1, 0b1])
        await RisingEdge(dut.clock())

    
    await ReadOnly()

    first_out = dut.get_renamed_regs()
    assert first_out == [42, 66, 11, 73]


@cocotb.test()
async def test2(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    

    dut = FreeListDut(dut)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await RisingEdge(dut.clock())
    

    # test basic empty signal


    for _ in range(0, 64, 4):
        dut.rename([0b1, 0b1, 0b1, 0b1])
        await RisingEdge(dut.clock())

    dut.rename([0b0, 0b0, 0b0, 0b0])
    
    dut.free([42,61,11,33] ,[0b1, 0b1, 0b1, 0b1])
    await RisingEdge(dut.clock())

    dut.free([42,61,11,33] ,[0b0, 0b0, 0b0, 0b0])

    await RisingEdge(dut.clock())
    


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


@cocotb.test()
async def test3(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    

    #dut = FreeListDut(dut)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    await RisingEdge(dut.clock)
    

    # test basic empty signal


    dut.io_free_valid_0.value = 0
    dut.io_free_valid_1.value = 1
    dut.io_free_valid_2.value = 0
    dut.io_free_valid_3.value = 1

    dut.io_free_values_0.value = 7
    dut.io_free_values_1.value = 5
    dut.io_free_values_2.value = 3
    dut.io_free_values_3.value = 1



    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
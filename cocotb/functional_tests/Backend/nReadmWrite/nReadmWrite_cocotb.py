import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from model_utils import *

from nReadmWriteDut import *

@cocotb.test()
async def simple_reset(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


@cocotb.test()
async def simple_writes(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    for i in range(64):
        dut.write(addr_in=[i,0,0,0], wr_en=[1,0,0,0], data_in=[i,0,0,0])
        await RisingEdge(dut.clock())
        dut.write()
    
    for i in range(64):
        dut.read(addr_in=[i,0,0,0,0,0,0,0])
        await RisingEdge(dut.clock())
        await ReadOnly()
        outputs = dut.get_output()
        assert outputs[0] == i
        await ReadWrite()

@cocotb.test()
async def simple_writes_4_wide(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    for i in range(0,64,4):
        dut.write(addr_in=[i,i+1,i+2,i+3], wr_en=[1,1,1,1], data_in=[i,i+1,i+2,i+3])
        await RisingEdge(dut.clock())
        dut.write()
    
    for i in range(64):
        dut.read(addr_in=[i,0,0,0,0,0,0,0])
        await RisingEdge(dut.clock())
        await ReadOnly()
        outputs = dut.get_output()
        assert outputs[0] == i
        await ReadWrite()

@cocotb.test()
async def simple_writes_4_wide_8_wide(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    for i in range(0,64,4):
        dut.write(addr_in=[i,i+1,i+2,i+3], wr_en=[1,1,1,1], data_in=[i,i+1,i+2,i+3])
        await RisingEdge(dut.clock())
        dut.write()
    
    for i in range(0,64,8):
        dut.read(addr_in=[i,i+1,i+2,i+3,i+4,i+5,i+6,i+7])
        await RisingEdge(dut.clock())
        await ReadOnly()
        outputs = dut.get_output()
        assert outputs[0] == i + 0
        assert outputs[1] == i + 1
        assert outputs[2] == i + 2
        assert outputs[3] == i + 3
        assert outputs[4] == i + 4
        assert outputs[5] == i + 5
        assert outputs[6] == i + 6
        assert outputs[7] == i + 7
        await ReadWrite()
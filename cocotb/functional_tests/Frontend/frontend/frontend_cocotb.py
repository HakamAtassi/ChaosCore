import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from frontend_dut import *
from SimpleDRAM import *

@cocotb.test()
async def reset(dut):

    await cocotb.start(generateClock(dut)) 

    dram=SimpleDRAM(sizeKB=1, bin="../bins/addi.bin")
    dram.print()
    dut = frontend_dut(dut, DRAM=dram)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def palceholder(dut):

    await cocotb.start(generateClock(dut)) 

    dram=SimpleDRAM(sizeKB=1, bin="../bins/addi.bin")
    #dram.print()
    dut = frontend_dut(dut, DRAM=dram)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    #assert False

@cocotb.test()
async def test_PC_increment(dut):

    await cocotb.start(generateClock(dut)) 

    dram=SimpleDRAM(sizeKB=1, bin="../bins/addi.bin")
    dut = frontend_dut(dut, DRAM=dram)  # wrap dut with helper class
    await dut.reset()   # reset module

    for i in range(0,256, 16):
        await ReadOnly()
        assert dut.get_PC() == i
        await RisingEdge(dut.clock())



##############################
## General non-branch tests ##
##############################
# test general functionality of internal modules

@cocotb.test()
async def test_PC_queue(dut):

    await cocotb.start(generateClock(dut)) 

    dram=SimpleDRAM(sizeKB=1, bin="../bins/addi.bin")
    dut = frontend_dut(dut, DRAM=dram)  # wrap dut with helper class
    await dut.reset()   # reset module

    for i in range(0,240+16, 16):
        await ReadOnly()
        assert dut.get_PC() == i
        await RisingEdge(dut.clock())

    # DRAM never responded. PC queue should be full

    await ReadOnly()

    PC_Q = dut.get_PC_Q()
    print(PC_Q)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    print(dut.get_PC())

    assert False

# Cache test
@cocotb.test()
async def cache(dut):

    await cocotb.start(generateClock(dut)) 

    dram=SimpleDRAM(sizeKB=1, bin="../bins/addi.bin")
    #dram.print()
    dut = frontend_dut(dut, DRAM=dram)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    for _ in range(100):
        await dut.update()

    # check cache contents    

    dut.print_cache()

    #assert False

# Output tests


# Predecoded tests


# instruction tests


# commit tests

# RAT tests

#################
# Branch tests ##
#################
# test general functionality of internal (branch based) modules

# RAS tests


# BP tests

# FTQ tests

# BTB tests

# PHT tests

# Decoder tests



################
## EDGE CASES ##
################
# Invoke pathological cases that attempt to break the core
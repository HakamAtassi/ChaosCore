import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from frontend_dut import *
from SimpleDRAM import SimpleDRAM

@cocotb.test()
async def test_reset(dut):

    DRAM = SimpleDRAM(sizeKB=2, bin="../bins/addi.bin")

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_check_outputs(dut):

    DRAM = SimpleDRAM(sizeKB=2, bin="../bins/addi.bin")

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module


    await dut.wait_decoder_outputs_valid()

    await ReadOnly()

    dut.print_decoder_outputs()

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    assert False

import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from PC_arbit_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = PC_arbit_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_increment(dut):

    await cocotb.start(generateClock(dut)) 

    dut = PC_arbit_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_ready(1)

    await ReadOnly()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["PC"] == 0x00

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["PC"] == 0x10
    
    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["PC"] == 0x20


@cocotb.test()
async def test_revert(dut):

    await cocotb.start(generateClock(dut)) 

    dut = PC_arbit_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module


    dut.set_ready(1)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["PC"] == 0x50
    
    await RisingEdge(dut.clock())
    await ReadOnly()

    revert_inputs = generate_null_revert_inputs()

    await RisingEdge(dut.clock())

    revert_inputs["valid"]  = 1
    revert_inputs["PC"]     = 0xdead0000

    dut.write_revert(revert_inputs=revert_inputs)

    await RisingEdge(dut.clock())
    dut.write_revert()

    await ReadOnly() 


    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["PC"] == 0xdead0000





import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *
from model_utils import *
from RASDut import *
from RAS import *

@cocotb.test()
async def simple_call_ret_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    # extend dut
    dut = RASDut(dut)

    dut.push(addr=0x1, valid=1)
    await RisingEdge(dut.clock())
    dut.push(addr=0x0, valid=0)


    dut.pop(valid=1)
    await RisingEdge(dut.clock())
    dut.pop(valid=0)
    await ReadOnly()

    assert dut.get_output()[0] == 0x1

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


@cocotb.test()
async def simple_call_ret_test2(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    # extend dut
    dut = RASDut(dut)

    dut.push(addr=0x1, valid=1)
    await RisingEdge(dut.clock())
    dut.push(addr=0x2, valid=1)
    await RisingEdge(dut.clock())
    dut.push(addr=0x3, valid=1)
    await RisingEdge(dut.clock())
    dut.push(addr=0, valid=0)

    dut.pop(valid=1)
    await ReadOnly()
    assert dut.get_output()[0] == 0x3

    await RisingEdge(dut.clock())
    await ReadOnly()
    assert dut.get_output()[0] == 0x2
    await RisingEdge(dut.clock())
    await ReadOnly()
    assert dut.get_output()[0] == 0x1
    await RisingEdge(dut.clock())
    dut.pop(valid=0)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


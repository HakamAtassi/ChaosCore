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
from QDut import *


@cocotb.test()
async def test0(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    dut = QDut(dut)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.write_to_Q(0xdead0000, 1)
    await RisingEdge(dut.clock())
    dut.write_to_Q(0xdead0010, 1)
    await RisingEdge(dut.clock())
    dut.write_to_Q(0xdead0020, 1)
    await RisingEdge(dut.clock())
    dut.write_to_Q(0xdead0030, 1)
    await RisingEdge(dut.clock())
    dut.write_to_Q(0xdead0030, 0)

    dut.read_from_Q(1)


    await RisingEdge(dut.clock())
    dut.read_from_Q(0)


    await RisingEdge(dut.clock())
    dut.read_from_Q(0)



    await RisingEdge(dut.clock())
    dut.clear_Q(1)

    await RisingEdge(dut.clock())
    dut.clear_Q(0)
    




    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())




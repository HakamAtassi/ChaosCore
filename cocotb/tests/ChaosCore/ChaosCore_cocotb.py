import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from ChaosCore_TB import *


@cocotb.test()
async def test_increment(dut):

    await cocotb.start(generateClock(dut))


    bin = "/home/hakam/Repos/ChaosCore/cocotb/tests/ChaosCore/../../../sim/binaries/bin/hello_world.bin"
    ChaosCore_tb = ChaosCore_TB(dut, bin)

    await ChaosCore_tb.reset()

    ChaosCore_tb.start()

    for _ in range(3000):
        await ChaosCore_tb.update()

    ChaosCore_tb.stop()

    assert False
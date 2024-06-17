import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from ChaosCore import ChaosCore_dut
from SimpleDRAM import *
from ChaosCore_TB import *


@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut))

    base_dir = os.path.dirname(__file__)
    bin = "../../binaries/bin/increment.bin"
    bin = os.path.join(base_dir, bin)

    imem = SimpleDRAM(sizeKB=4, bin=bin)
    dmem = SimpleDRAM(sizeKB=4)

    # wrap dut with helper class
    dut = ChaosCore_dut(dut, imem=imem, dmem=dmem)

    ChaosCore_tb = ChaosCore_TB(dut)

    await ChaosCore_tb.reset()

    ChaosCore_tb.start()

    dut.write_dmem_request_ready(1)
    dut.write_imem_request_ready(1)

    # await dut.reset()  # reset module

    for _ in range(1000):
        await ChaosCore_tb.update()
        # await dut.update()

    assert False

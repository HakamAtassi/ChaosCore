import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *
from Gshare import *
from model_utils import *


@cocotb.test()
async def gshare_fuzzing(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    GHR_width=16

    # extend dut
    #dut = GshareDut(dut, GHR_width=GHR_width)
    #gshare_model = PHT(GHR_width=GHR_width)

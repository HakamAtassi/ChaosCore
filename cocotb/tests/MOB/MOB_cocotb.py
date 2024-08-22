import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from MOB_TB import *

from model_utils import *

@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    MOB = MOB_TB(dut)     # construct TB
    await MOB.reset()     # Reset

    await MOB.clock()
    await MOB.clock()
    await MOB.clock()
    await MOB.clock()

@cocotb.test()
async def test_fuzz(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    MOB = MOB_TB(dut)     # construct TB
    await MOB.reset()     # Reset



    


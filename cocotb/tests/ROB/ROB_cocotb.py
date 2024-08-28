import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from model_utils import *
from cocotb_utils import *

from ROB_TB import *


@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    ROB = ROB_TB(dut)     # construct TB
    await ROB.reset()     # Reset

    await ROB.verify()

    await ROB.clock()
    await ROB.clock()
    await ROB.clock()
    await ROB.clock()

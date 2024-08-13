import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from L1_instruction_cache_TB import *


@cocotb.test()
async def test_increment(dut):

    L1_instruction_cache_TB(dut)


    assert True
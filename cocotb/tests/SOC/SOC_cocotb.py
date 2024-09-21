import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from SOC_TB import *
from L1_caches import instruction_cache_dut

import logging


@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/vec_add.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/if.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/hello_world.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/bubble_sort.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/printf.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/multiply.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/test.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/branch_test.bin")     # construct TB

    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/beq.bin")     # construct TB
    SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/instret.bin")     # construct TB

    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/riscv-tests/isa/rv32ui-p-srai")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/rv32ui-p-srai.bin")     # construct TB
    await SOC.reset()                      # Reset

    for _ in range(15000):
    #while 1:
        await SOC.clock()

    assert False

    


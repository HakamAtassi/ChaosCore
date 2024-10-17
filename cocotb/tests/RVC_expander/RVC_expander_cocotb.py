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
from instruction.RVC_expander_dut import *

@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    RVC_expander = RVC_expander_dut(dut)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB

    await RVC_expander.reset()                      # Reset


@cocotb.test()
async def test_instruction(dut):
    # Set seed
    #random.seed(0x42)

    RVC_expander = RVC_expander_dut(dut)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    await RVC_expander.reset()                      # Reset

    # for i in range(10000):
    #     c_instr = random.randint(0x0,0xffff)
    c_instr = (0b000 << 13) + (0x0 << 2) + 0b01
    expander = expander_model(c_instr)
    model_expanded_instr = expander.expand()

    RVC_expander.write_instruction(c_instr)
    await RVC_expander.clock()
    result = RVC_expander.read_instruction()
    print(f"{c_instr:#0{6}x}\t{model_expanded_instr:#0{8}x}\t{int(result):#0{8}x}")

    try:
        assert model_expanded_instr == result
    except(AssertionError):
        print(f"{c_instr:#0{6}x}\t{model_expanded_instr:#0{8}x}\t{int(result):#0{8}x}")
        print(hex(expander.lwsp_imm))
        print(hex(expander.swsp_imm))
        print(hex(expander.lsw_imm))
        print(hex(expander.j_imm))
        print(hex(expander.b_imm))
        print(hex(expander.shamt))
        print(hex(expander.lui_imm))
        print(hex(expander.addi16sp_imm))
        print(hex(expander.addi4spn_imm))
        assert False



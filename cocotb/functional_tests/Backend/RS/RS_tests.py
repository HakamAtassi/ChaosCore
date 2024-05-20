import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *
from model_utils import *

from RSDut import *


@cocotb.test()
async def simple_typical_0(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    dut = RSDut(dut)

    dut.print_RS()

    dut.write_RS(RD_valid=1, RD=5, RS1_ready=0, RS1_valid=1, RS1_bits=2, RS2_ready=1, RS2_is_imm=0, RS2_valid=1, RS2_bits=4, uOp=3, valid=1)
    
    await RisingEdge(dut.clock())
    dut.write_RS(RD_valid=1, RD=5, RS1_ready=0, RS1_valid=1, RS1_bits=6, RS2_ready=1, RS2_is_imm=0, RS2_valid=1, RS2_bits=4, uOp=1, valid=1)
    await ReadOnly()
    dut.print_RS()

    await RisingEdge(dut.clock())
    dut.write_RS(RD_valid=1, RD=5, RS1_ready=0, RS1_valid=1, RS1_bits=6, RS2_ready=1, RS2_is_imm=0, RS2_valid=1, RS2_bits=4, uOp=1, valid=1)
    await ReadOnly()
    dut.print_RS()

    await RisingEdge(dut.clock())
    dut.write_RS(RD_valid=1, RD=5, RS1_ready=0, RS1_valid=1, RS1_bits=6, RS2_ready=1, RS2_is_imm=0, RS2_valid=1, RS2_bits=4, uOp=1, valid=1)
    await ReadOnly()
    dut.print_RS()

    await RisingEdge(dut.clock())
    dut.write_RS(RD_valid=1, RD=5, RS1_ready=0, RS1_valid=1, RS1_bits=6, RS2_ready=1, RS2_is_imm=0, RS2_valid=1, RS2_bits=4, uOp=1, valid=1)
    await ReadOnly()
    dut.print_RS()



    await RisingEdge(dut.clock())
    dut.write_RS(RD_valid=1, RD=5, RS1_ready=0, RS1_valid=1, RS1_bits=6, RS2_ready=1, RS2_is_imm=0, RS2_valid=1, RS2_bits=4, uOp=1, valid=0)
    await ReadOnly()
    dut.print_RS()


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.broadcoast(RD=2, data=1234, valid=1)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_RS()
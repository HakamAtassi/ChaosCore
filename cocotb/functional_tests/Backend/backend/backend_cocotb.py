import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from model_utils import *

from backendDut import *

@cocotb.test()
async def simple_reset(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

@cocotb.test()
async def pass_input(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    dut = backendDut(dut)


    packet0 = BackendPacket(valid = 1,
                            RD_valid = 1,
                            RD = 3,
                            RS1 = 1,
                            RS2 = 7,
                            IMM = 0,
                            FUNCT3 = 0,
                            packet_index = 0,
                            ROB_index = 0,
                            instructionType = 0,
                            portID = 0,
                            RS_type = 0,
                            needs_ALU = 1,
                            needs_branch_unit = 0,
                            SUBTRACT = 0,
                            MULTIPLY = 0,
                            IMMEDIATE = 0,
                            IS_LOAD = 0,
                            IS_STORE = 0,
                            RS1_ready = 1,
                            RS2_ready = 1,
                            ready = 0)

    packet1 = BackendPacket()
    packet2 = BackendPacket()
    packet3 = BackendPacket()
    


    await RisingEdge(dut.clock())

    dut.write(packet0, packet1, packet2, packet3)



    await RisingEdge(dut.clock())
    dut.write()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
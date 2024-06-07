import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from ROB_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_print_ROB(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.print_ROB_entry()

@cocotb.test()
async def test_ROB_write(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"] = 1
    allocate_input["fetch_PC"] = [0,0,0,0]
    allocate_input["ready_bits_RS1_ready"] = [0,0,0,0]
    allocate_input["ready_bits_RS2_ready"] = [0,0,0,0]
    allocate_input["RD"] = [0,0,0,0]
    allocate_input["RD_valid"] = [0,0,0,0]
    allocate_input["RS1"] = [0,0,0,0]
    allocate_input["RS1_valid"] = [0,0,0,0]
    allocate_input["RS2"] = [0,0,0,0]
    allocate_input["RS2_valid"] = [0,0,0,0]
    allocate_input["IMM"] = [0,0,0,0]
    allocate_input["FUNCT3"] = [0,0,0,0]
    allocate_input["packet_index"] = [0,0,0,0]
    allocate_input["ROB_index"] = [0,0,0,0]
    allocate_input["instructionType"] = [0,0,0,0]
    allocate_input["portID"] = [0,0,0,0]
    allocate_input["RS_type"] = [0,0,0,0]
    allocate_input["needs_ALU"] = [0,0,0,0]
    allocate_input["needs_branch_unit"] = [1,0,0,0]
    allocate_input["needs_CSRs"] = [0,0,0,0]
    allocate_input["SUBTRACT"] = [0,0,0,0]
    allocate_input["MULTIPLY"] = [0,0,0,0]
    allocate_input["IMMEDIATE"] = [0,0,0,0]
    allocate_input["IS_LOAD"] = [0,0,0,0]
    allocate_input["IS_STORE"] = [0,0,0,0]

    dut.write_allocate(allocate_input)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_ROB_entry()

    assert False
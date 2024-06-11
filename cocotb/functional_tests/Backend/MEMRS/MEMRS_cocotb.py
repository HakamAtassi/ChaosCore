import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from MEMRS_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_print_MEMRS(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.print_MEMRS()


@cocotb.test()
async def test_write_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]

    dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_MEMRS()

    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1



@cocotb.test()
async def test_write_many(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]

    dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate(allocate_inputs)
    await RisingEdge(dut.clock())
    dut.write_allocate(allocate_inputs)
    await RisingEdge(dut.clock())
    dut.write_allocate(allocate_inputs)
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await RisingEdge(dut.clock())

    dut.print_MEMRS()

    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1
    
    assert dut.get_MEMRS_contents()["RS2"][1]          == 5
    assert dut.get_MEMRS_contents()["RS1"][1]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][1]     == 1

    assert dut.get_MEMRS_contents()["RS2"][2]          == 5
    assert dut.get_MEMRS_contents()["RS1"][2]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][2]     == 1

    assert dut.get_MEMRS_contents()["RS2"][3]          == 5
    assert dut.get_MEMRS_contents()["RS1"][3]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][3]     == 1

    assert dut.get_MEMRS_contents()["RS2"][4]          == 0
    assert dut.get_MEMRS_contents()["RS1"][4]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][4]     == 0


@cocotb.test()
async def test_full(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]


    for i in range(16):
        await RisingEdge(dut.clock())
        dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1

    assert dut.get_MEMRS_contents()["RS2"][15]          == 5
    assert dut.get_MEMRS_contents()["RS1"][15]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][15]     == 1

    assert dut.get_allocate_ready() == [0,0,0,0]


@cocotb.test()
async def test_full_but_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]


    for i in range(15):
        await RisingEdge(dut.clock())
        dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1

    assert dut.get_MEMRS_contents()["RS2"][14]          == 5
    assert dut.get_MEMRS_contents()["RS1"][14]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][14]     == 1

    assert dut.get_MEMRS_contents()["RS2"][15]          == 0
    assert dut.get_MEMRS_contents()["RS1"][15]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][15]     == 0

    assert dut.get_allocate_ready() == [1,0,0,0]


@cocotb.test()
async def test_full_but_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]


    for i in range(14):
        await RisingEdge(dut.clock())
        dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1

    assert dut.get_MEMRS_contents()["RS2"][13]          == 5
    assert dut.get_MEMRS_contents()["RS1"][13]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][13]     == 1

    assert dut.get_MEMRS_contents()["RS2"][14]          == 0
    assert dut.get_MEMRS_contents()["RS1"][14]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][14]     == 0

    assert dut.get_MEMRS_contents()["RS2"][15]          == 0
    assert dut.get_MEMRS_contents()["RS1"][15]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][15]     == 0

    assert dut.get_allocate_ready() == [1,1,0,0]

@cocotb.test()
async def test_full_but_3(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]


    for i in range(13):
        await RisingEdge(dut.clock())
        dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1


    assert dut.get_MEMRS_contents()["RS2"][13]          == 0
    assert dut.get_MEMRS_contents()["RS1"][13]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][13]     == 0

    assert dut.get_MEMRS_contents()["RS2"][14]          == 0
    assert dut.get_MEMRS_contents()["RS1"][14]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][14]     == 0

    assert dut.get_MEMRS_contents()["RS2"][15]          == 0
    assert dut.get_MEMRS_contents()["RS1"][15]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][15]     == 0

    assert dut.get_allocate_ready() == [1,1,1,0]



@cocotb.test()
async def test_full_but_4(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]


    for i in range(12):
        await RisingEdge(dut.clock())
        dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1

    assert dut.get_MEMRS_contents()["RS2"][12]          == 0
    assert dut.get_MEMRS_contents()["RS1"][12]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][12]     == 0

    assert dut.get_MEMRS_contents()["RS2"][13]          == 0
    assert dut.get_MEMRS_contents()["RS1"][13]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][13]     == 0

    assert dut.get_MEMRS_contents()["RS2"][14]          == 0
    assert dut.get_MEMRS_contents()["RS1"][14]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][14]     == 0

    assert dut.get_MEMRS_contents()["RS2"][15]          == 0
    assert dut.get_MEMRS_contents()["RS1"][15]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][15]     == 0

    assert dut.get_allocate_ready() == [1,1,1,1]


@cocotb.test()
async def test_write_1_FU_complete(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [1, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [1, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]

    dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()


    assert dut.get_MEMRS_contents()["valid"][0]          == 1
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3

    assert dut.get_MEMRS_contents()["RS2_ready"][0]          == 0
    assert dut.get_MEMRS_contents()["RS1_ready"][0]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1


    ## write from FU
    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"] = [1,1,0,0]
    FU_inputs["RD"] = [3,5,0,0]
    FU_inputs["RD_data"] = [0,0,0,0]
    FU_inputs["RD_valid"] = [1,1,0,0]
    FU_inputs["instruction_PC"] = [0,0,0,0]
    FU_inputs["branch_taken"] = [0,0,0,0]
    FU_inputs["target_address"] = [0,0,0,0]
    FU_inputs["branch_valid"] = [0,0,0,0]
    FU_inputs["ROB_index"] = [0,0,0,0]
    FU_inputs["fetch_packet_index"] = [0,0,0,0]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()


    assert dut.get_MEMRS_contents()["RS2_ready"][0]          == 1
    assert dut.get_MEMRS_contents()["RS1_ready"][0]          == 1

@cocotb.test()
async def test_good_to_go(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [3, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [1, 0, 0, 0]
    allocate_inputs["RS2"] = [5, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [1, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]

    dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()


    assert dut.get_MEMRS_contents()["valid"][0]          == 1
    assert dut.get_MEMRS_contents()["RS2"][0]          == 5
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3

    assert dut.get_MEMRS_contents()["RS2_ready"][0]          == 0
    assert dut.get_MEMRS_contents()["RS1_ready"][0]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1


    ## write from FU
    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"] = [1,1,0,0]
    FU_inputs["RD"] = [3,5,0,0]
    FU_inputs["RD_data"] = [0,0,0,0]
    FU_inputs["RD_valid"] = [1,1,0,0]
    FU_inputs["instruction_PC"] = [0,0,0,0]
    FU_inputs["branch_taken"] = [0,0,0,0]
    FU_inputs["target_address"] = [0,0,0,0]
    FU_inputs["branch_valid"] = [0,0,0,0]
    FU_inputs["ROB_index"] = [0,0,0,0]
    FU_inputs["fetch_packet_index"] = [0,0,0,0]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()



    assert dut.get_MEMRS_contents()["RS2_ready"][0]          == 1
    assert dut.get_MEMRS_contents()["RS1_ready"][0]          == 1


    await RisingEdge(dut.clock())
    ## commit

    commit_inputs = generate_null_commit_input()

    commit_inputs["valid"]                  = 1
    commit_inputs["fetch_PC"]               = 0
    commit_inputs["T_NT"]                   = 0
    commit_inputs["ROB_index"]              = 0
    commit_inputs["br_type"]                = 0
    commit_inputs["fetch_packet_index"]     = 0
    commit_inputs["is_misprediction"]       = 0
    commit_inputs["expected_PC"]            = 0
    commit_inputs["GHR"]                    = 0
    commit_inputs["TOS"]                    = 0
    commit_inputs["NEXT"]                   = 0
    commit_inputs["RAT_IDX"]                = 0

    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    dut.print_MEMRS()

    assert dut.get_output()["valid"] == 1
    assert dut.get_output()["RS1"] == 3
    assert dut.get_output()["RS2"] == 5


@cocotb.test()
async def test_good_to_go_backed_up(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [1, 1, 1, 1]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [1, 3, 1, 3]
    allocate_inputs["RS1_valid"] = [1, 1, 1, 1]
    allocate_inputs["RS2"] = [2, 4, 2, 4]
    allocate_inputs["RS2_valid"] = [1, 1, 1, 1]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 1, 2, 3]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [1, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]

    dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()


    assert dut.get_MEMRS_contents()["valid"][0]          == 1
    assert dut.get_MEMRS_contents()["RS1"][0]          == 1
    assert dut.get_MEMRS_contents()["RS1"][1]          == 3
    assert dut.get_MEMRS_contents()["RS1"][2]          == 1
    assert dut.get_MEMRS_contents()["RS1"][3]          == 3
    
    assert dut.get_MEMRS_contents()["RS2"][0]          == 2
    assert dut.get_MEMRS_contents()["RS2"][1]          == 4
    assert dut.get_MEMRS_contents()["RS2"][2]          == 2
    assert dut.get_MEMRS_contents()["RS2"][3]          == 4


    assert dut.get_MEMRS_contents()["RS2_ready"][0]          == 0
    assert dut.get_MEMRS_contents()["RS1_ready"][0]          == 0
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1


    ## write from FU
    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"] = [1, 1, 1, 1]
    FU_inputs["RD"] = [1,2,3,4]
    FU_inputs["RD_data"] = [0,0,0,0]
    FU_inputs["RD_valid"] = [1, 1, 1, 1]
    FU_inputs["instruction_PC"] = [0,0,0,0]
    FU_inputs["branch_taken"] = [0,0,0,0]
    FU_inputs["target_address"] = [0,0,0,0]
    FU_inputs["branch_valid"] = [0,0,0,0]
    FU_inputs["ROB_index"] = [0,0,0,0]
    FU_inputs["fetch_packet_index"] = [0,0,0,0]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()

    dut.print_MEMRS()

    assert dut.get_MEMRS_contents()["RS2_ready"][0]          == 1
    assert dut.get_MEMRS_contents()["RS1_ready"][0]          == 1

    assert dut.get_MEMRS_contents()["RS2_ready"][1]          == 1
    assert dut.get_MEMRS_contents()["RS1_ready"][1]          == 1

    assert dut.get_MEMRS_contents()["RS2_ready"][2]          == 1
    assert dut.get_MEMRS_contents()["RS1_ready"][2]          == 1

    assert dut.get_MEMRS_contents()["RS2_ready"][3]          == 1
    assert dut.get_MEMRS_contents()["RS1_ready"][3]          == 1


    await RisingEdge(dut.clock())
    ## commit

    commit_inputs = generate_null_commit_input()

    commit_inputs["valid"]                  = 1
    commit_inputs["fetch_PC"]               = 0
    commit_inputs["T_NT"]                   = 0
    commit_inputs["ROB_index"]              = 3
    commit_inputs["br_type"]                = 0
    commit_inputs["fetch_packet_index"]     = 0
    commit_inputs["is_misprediction"]       = 0
    commit_inputs["expected_PC"]            = 0
    commit_inputs["GHR"]                    = 0
    commit_inputs["TOS"]                    = 0
    commit_inputs["NEXT"]                   = 0
    commit_inputs["RAT_IDX"]                = 0

    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())

    commit_inputs["ROB_index"] = 2
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())

    commit_inputs["ROB_index"] = 1
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())

    commit_inputs["ROB_index"] = 0
    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    dut.print_MEMRS()

    assert dut.get_output()["valid"] == 1

    assert dut.get_output()["RS1"] == 1
    assert dut.get_output()["RS2"] == 2

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_output()["valid"] == 1
    assert dut.get_output()["RS1"] == 3
    assert dut.get_output()["RS2"] == 4

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_output()["valid"] == 1
    assert dut.get_output()["RS1"] == 1
    assert dut.get_output()["RS2"] == 2

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.get_output()["valid"]
    assert dut.get_output()["RS1"] == 3
    assert dut.get_output()["RS2"] == 4


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

@cocotb.test()
async def test_write_1_not_first(dut):

    await cocotb.start(generateClock(dut)) 

    dut = MEMRS_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    allocate_inputs = generate_null_allocate_inputs()


    allocate_inputs["valid"] = [0, 1, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [0, 3, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [0, 7, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [0, 1, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]

    dut.write_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_MEMRS()

    assert dut.get_MEMRS_contents()["RS2"][0]          == 7
    assert dut.get_MEMRS_contents()["RS1"][0]          == 3
    assert dut.get_MEMRS_contents()["SUBTRACT"][0]     == 1



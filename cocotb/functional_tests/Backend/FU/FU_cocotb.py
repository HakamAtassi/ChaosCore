import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
from tabulate import tabulate

from cocotb_utils import *
from FU_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_addi(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 123
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 9
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123+9)

@cocotb.test()
async def test_xori(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 123
    FU_inputs["FUNCT3"] = 0x4
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123^44)

@cocotb.test()
async def test_andi(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 123
    FU_inputs["FUNCT3"] = 0x7
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123&44)

@cocotb.test()
async def test_ori(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 123
    FU_inputs["FUNCT3"] = 0x6
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123|44)

@cocotb.test()
async def test_slli(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 5
    FU_inputs["FUNCT3"] = 0x1
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (44<<5)

@cocotb.test()
async def test_srli(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 5
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (44>>5)




@cocotb.test()
async def test_srai(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 5
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 1
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (44>>5)

@cocotb.test()
async def test_srai_signed(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 1
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 1
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 2**32 - 44 # -7 in signed 2s comp. 
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == ((2**32) - 22)

@cocotb.test()
async def test_slti_t(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 124
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123<124)


@cocotb.test()
async def test_slti_f(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 123
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 124
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (124<123)

@cocotb.test()
async def test_slti_t_signed(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = (2**21 - 5) # -5
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = (2**32 - 6) # -5
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (-6<-5)

@cocotb.test()
async def test_slti_f_signed(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = (2**21 - 6) # -5
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b00100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = (2**32 - 5) # -5
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (-5<-6)


## test OP (non imm) ##


@cocotb.test()
async def test_add(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 9
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123+9)

@cocotb.test()
async def test_sub_pos(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 1
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 9
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123-9)

@cocotb.test()
async def test_sub_neg(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 1
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 9
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == 2**32 - (123-9)

@cocotb.test()
async def test_xor(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x4
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123^44)

@cocotb.test()
async def test_and(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x7
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123&44)

@cocotb.test()
async def test_or(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x6
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123|44)

@cocotb.test()
async def test_sll(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x1
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 5
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (44<<5)

@cocotb.test()
async def test_srl(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 5
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (44>>5)




@cocotb.test()
async def test_sra(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 1
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 44
    FU_inputs["RS2_data"] = 5
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (44>>5)

@cocotb.test()
async def test_sra_signed(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 1
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 2**32 - 44 # -7 in signed 2s comp. 
    FU_inputs["RS2_data"] =  1
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == ((2**32) - 22)

@cocotb.test()
async def test_slt_t(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 124
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (123<124)


@cocotb.test()
async def test_slt_f(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 124
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (124<123)

@cocotb.test()
async def test_slt_t_signed(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = (2**32 - 6) # -5
    FU_inputs["RS2_data"] =  (2**32 - 5) # -5
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (-6<-5)

@cocotb.test()
async def test_slt_f_signed(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0x2
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01100
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = (2**32 - 5) # -5
    FU_inputs["RS2_data"] = (2**32 - 6) # -5
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (-5<-6)




## test branches ##




@cocotb.test()
async def test_beq_t(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0x0ffe
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 1
    assert dut.get_outputs()["target_address"] == 0xc0de0ffe

@cocotb.test()
async def test_beq_nt(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0xc0fe
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 125
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 0
    assert dut.get_outputs()["target_address"] == 0xc0de0010


@cocotb.test()
async def test_bne_t(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0x0ffe
    FU_inputs["FUNCT3"] = 0x1
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 125
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 1
    assert dut.get_outputs()["target_address"] == 0xc0de0ffe

@cocotb.test()
async def test_bne_nt(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0xc0fe
    FU_inputs["FUNCT3"] = 0x1
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 123
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 0
    assert dut.get_outputs()["target_address"] == 0xc0de0010



@cocotb.test()
async def test_blt_t(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0x0ffe
    FU_inputs["FUNCT3"] = 0x4
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 125
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 1
    assert dut.get_outputs()["target_address"] == 0xc0de0ffe

@cocotb.test()
async def test_blt_nt(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0xcafe
    FU_inputs["FUNCT3"] = 0x4
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 123
    FU_inputs["RS2_data"] = 122
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 0
    assert dut.get_outputs()["target_address"] == 0xc0de0010

@cocotb.test()
async def test_bge_t(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0xffe
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 125
    FU_inputs["RS2_data"] = 122
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 1
    assert dut.get_outputs()["target_address"] == 0xc0de0ffe

@cocotb.test()
async def test_bge_nt(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0xffe
    FU_inputs["FUNCT3"] = 0x5
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b11000
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 1
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 121
    FU_inputs["RS2_data"] = 122
    FU_inputs["PC"] = 0xc0de0000

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["branch_taken"] == 0
    assert dut.get_outputs()["target_address"] == 0xc0de0010


#FIXME: add BLT U and BGE U 


@cocotb.test()
async def test_LUI(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FU_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = 1
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 10
    FU_inputs["RD_valid"] = 1
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 1
    FU_inputs["FUNCT3"] = 0x0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0b01101
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 1
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 1
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 0
    FU_inputs["RS2_data"] =  0
    FU_inputs["PC"] = 0

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_outputs()

    assert dut.get_outputs()["valid"] == 1
    assert dut.get_outputs()["RD"] == 10
    assert dut.get_outputs()["RD_data"] == (1<<12)


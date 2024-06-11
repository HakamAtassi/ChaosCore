import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from SimpleDRAM import SimpleDRAM

from cocotb_utils import *
from MEMFU_dut import *

@cocotb.test()
async def test_reset(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    await dut.update()


@cocotb.test()
async def test_reset(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 0
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0
    FU_inputs["RS1_valid"]          = 0
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 0
    FU_inputs["IMM"]                = 0
    FU_inputs["FUNCT3"]             = 0
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["IS_LOAD"]            = 0
    FU_inputs["IS_STORE"]           = 0
    FU_inputs["RS1_data"]           = 0
    FU_inputs["RS2_data"]           = 0
    FU_inputs["io_FU_input_bits_PC"]= 0

    dut.write_FU(FU_inputs)


@cocotb.test()
async def test_SW(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x2
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b01000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["IS_LOAD"]            = 0
    FU_inputs["IS_STORE"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEEEE_EEEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0

    # check memory access port


    assert dut.get_DRAM_outputs()["resp_ready"]       == 1
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEEEE_EEEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1


@cocotb.test()
async def test_SH(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x1
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b01000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["IS_LOAD"]            = 0
    FU_inputs["IS_STORE"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEEEE_EEEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0
    # check memory access port


    assert dut.get_DRAM_outputs()["resp_ready"]       == 1
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEEEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1

@cocotb.test()
async def test_SB(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x1
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b01000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["IS_LOAD"]            = 0
    FU_inputs["IS_STORE"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0

    # check memory access port


    assert dut.get_DRAM_outputs()["resp_ready"]       == 1
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1


@cocotb.test()
async def test_LB(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x1
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b01000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["IS_LOAD"]            = 0
    FU_inputs["IS_STORE"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0

    # check memory access port


    assert dut.get_DRAM_outputs()["resp_ready"]       == 1
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1


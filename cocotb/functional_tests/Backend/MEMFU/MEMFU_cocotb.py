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

    dut.set_DRAM_ready(1)

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
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
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

    dut.set_DRAM_ready(1)

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
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEEEE_EEEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEEEE_EEEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1


    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_DRAM_outputs()["request_valid"]    == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0




@cocotb.test()
async def test_SH(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

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
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEEEE_EEEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEEEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1


    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_DRAM_outputs()["request_valid"]    == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0



@cocotb.test()
async def test_SB(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

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
    FU_inputs["FUNCT3"]             = 0x0
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
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 1
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0xEEEE_EEEE
    FU_inputs["PC"]                 = 0xdeed

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0xEE
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 1


    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()

    print(dut.get_FU_outputs())

    print(hex(dut.get_FU_outputs()["instruction_PC"]))

    # check FU output port (towards RF)
    assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 0

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_DRAM_outputs()["request_valid"]    == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

# test loads
@cocotb.test()
async def test_LW(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x2
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    dut.write_dram_resp(data=0x1234_5678, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == 0x1234_5678

# test loads
@cocotb.test()
async def test_LHW(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x1
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    dut.write_dram_resp(data=0x1234_5678, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == 0x5678

@cocotb.test()
async def test_LB(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x0
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    dut.write_dram_resp(data=0x1234_5678, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == 0x78


@cocotb.test()
async def test_LHW_signed(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x1
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    negative_value = -42
    signed_HW_16 = 2**16 + negative_value
    signed_HW_32 = 2**32 + negative_value
    dut.write_dram_resp(data=signed_HW_16, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == signed_HW_32

@cocotb.test()
async def test_LB_signed(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x0
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    negative_value = -42
    signed_HW_8 = 2**8 + negative_value
    signed_HW_32 = 2**32 + negative_value
    dut.write_dram_resp(data=signed_HW_8, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == signed_HW_32

@cocotb.test()
async def test_LBU_signed(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x4
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    negative_value = -42
    signed_HW_8 = 2**8 + negative_value
    signed_HW_32 = 2**32 + negative_value
    dut.write_dram_resp(data=signed_HW_8, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == signed_HW_8

@cocotb.test()
async def test_LHWU_signed(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x5
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    # memory response

    negative_value = -42
    signed_HW_16 = 2**16 + negative_value
    signed_HW_32 = 2**32 + negative_value
    dut.write_dram_resp(data=signed_HW_16, valid = 1)
    await RisingEdge(dut.clock())
    dut.write_dram_resp()

    await ReadOnly()


    #assert dut.get_FU_outputs()["instruction_PC"]   == 0xdeed
    assert dut.get_FU_outputs()["valid"]            == 1
    assert dut.get_FU_outputs()["RD_valid"]         == 1
    assert dut.get_FU_outputs()["RD"]               == 15
    assert dut.get_FU_outputs()["RD_data"]          == signed_HW_16




# test valid/ready FSM stuff


@cocotb.test()
async def test_ready_after_waiting_request(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(0)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x5
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await ReadOnly()


    dut.get_FU_ready() == 0


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.set_DRAM_ready(1)

    await ReadOnly()
    dut.get_FU_ready() == 0

    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.get_FU_ready() == 1



@cocotb.test()
async def test_ready_after_accepted_request(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = MEMFU_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_DRAM_ready(1)

    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 15
    FU_inputs["RD_valid"]           = 1
    FU_inputs["RS1"]                = 10
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0xdead
    FU_inputs["FUNCT3"]             = 0x5
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0b0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 1
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 1
    FU_inputs["is_load"]            = 1
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0xbeef
    FU_inputs["RS2_data"]           = 0x0
    FU_inputs["PC"]                 = 0x0

    dut.write_FU(FU_inputs)

    await ReadOnly()

    # check memory access port
    assert dut.get_DRAM_outputs()["request_valid"]    == 1
    assert dut.get_DRAM_outputs()["request_addr"]     == 0xbeef+0xdead
    assert dut.get_DRAM_outputs()["request_wr_data"]  == 0
    assert dut.get_DRAM_outputs()["request_wr_en"]    == 0

    await RisingEdge(dut.clock())
    await ReadOnly()


    dut.get_FU_ready() == 1






import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from rename_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_rename_1_RD(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [2, 0, 0, 0]
    rename_inputs["RD_valid"]           = [1, 0, 0, 0]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 1

@cocotb.test()
async def test_rename_1_RD_x0(dut):
    # x0 name should be constant

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [0, 0, 0, 0]
    rename_inputs["RD_valid"]           = [1, 1, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 0
    assert dut.get_outputs()["RD"][1] == 0
    assert dut.get_outputs()["RD"][2] == 0
    assert dut.get_outputs()["RD"][3] == 0




@cocotb.test()
async def test_rename_2_with_stall(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [1, 0, 0, 0]
    rename_inputs["RD_valid"]           = [1, 0, 0, 0]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [1, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 1

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()

    assert dut.get_outputs()["RD"][0] == 2


@cocotb.test()
async def test_rename_4_at_a_time(dut): 

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [1, 2, 3, 4]
    rename_inputs["RD_valid"]           = [1, 1, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()
    assert dut.get_outputs()["RD"] == [1,2,3,4]

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()

    assert dut.get_outputs()["RD"] == [5,6,7,8]

@cocotb.test()
async def test_rename_3_at_a_time_with_bubble(dut): 

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [1, 0, 3, 4]
    rename_inputs["RD_valid"]           = [1, 0, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 1
    assert dut.get_outputs()["RD"][2] == 2
    assert dut.get_outputs()["RD"][3] == 3


@cocotb.test()
async def test_rename_then_use(dut): 

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [10, 11, 12, 13]
    rename_inputs["RD_valid"]           = [1, 1, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()
    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 1
    assert dut.get_outputs()["RD"][1] == 2
    assert dut.get_outputs()["RD"][2] == 3
    assert dut.get_outputs()["RD"][3] == 4


    await RisingEdge(dut.clock())

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [1, 2, 3, 4]
    rename_inputs["RD_valid"]           = [1, 1, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [1, 1, 1, 1]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()
    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 5
    assert dut.get_outputs()["RD"][1] == 6
    assert dut.get_outputs()["RD"][2] == 7
    assert dut.get_outputs()["RD"][3] == 8


    await RisingEdge(dut.clock())

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [0, 0, 0, 0]
    rename_inputs["RD_valid"]           = [0, 0, 0, 0]
    rename_inputs["RS1"]                = [1, 2, 3, 4]
    rename_inputs["RS1_valid"]          = [1, 1, 1, 1]
    rename_inputs["RS2"]                = [1, 2, 3, 4]
    rename_inputs["RS2_valid"]          = [1, 1, 1, 1]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [1, 1, 1, 1]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()
    await ReadOnly()
    print(dut.get_outputs())
    assert dut.get_outputs()["RS1"][0] == 5
    assert dut.get_outputs()["RS1"][1] == 6
    assert dut.get_outputs()["RS1"][2] == 7
    assert dut.get_outputs()["RS1"][3] == 8

    assert dut.get_outputs()["RS2"][0] == 5
    assert dut.get_outputs()["RS2"][1] == 6
    assert dut.get_outputs()["RS2"][2] == 7
    assert dut.get_outputs()["RS2"][3] == 8


    await RisingEdge(dut.clock())


@cocotb.test()
async def test_single_checkpoint(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [2, 4, 6, 8]
    rename_inputs["RD_valid"]           = [1, 1, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 1

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    # create checkpoint 

    dut.create_checkpoint(1)
    await RisingEdge(dut.clock())
    dut.create_checkpoint(0)
    await RisingEdge(dut.clock())

    for i in range(16):
        dut.print_RAT(i)

    assert dut.get_RAT(0) == dut.get_RAT(1)

    assert dut.get_outputs()["RAT_IDX"] == 1


@cocotb.test()
async def test_rename_4_at_a_time_with_hazard(dut): 

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    rename_inputs = generate_null_rename_inputs()


   #10074:	04800793          	li	x15,72
   #10078:	40f02023          	sw	x15,1024(x0) # 400 <main-0xfc74>
   #1007c:	04500793          	li	x15,69
   #10080:	40f02023          	sw	x15,1024(x0) # 400 <main-0xfc74>

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [15, 0, 15, 0]
    rename_inputs["RD_valid"]           = [1, 0, 1, 1]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 15, 0, 15]
    rename_inputs["RS2_valid"]          = [0, 1, 0, 1]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()

    await ReadOnly()
    assert dut.get_outputs()["RD"][0] == 1
    assert dut.get_outputs()["RD"][2] == 2

    assert dut.get_outputs()["RS2"][1] == 1
    assert dut.get_outputs()["RS2"][3] == 2

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


@cocotb.test()
async def test_set_ready(dut): 

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    # LI (do a RD rename)
    # FU outputs (set that RD as ready)
    # get ready value
    # SW (optional)


    rename_inputs = generate_null_rename_inputs()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [7, 9, 0, 0]
    rename_inputs["RD_valid"]           = [1, 1, 0, 0]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [123, 123, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [4, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"]            = [0, 0, 0, 0]
    rename_inputs["IS_STORE"]           = [0, 0, 0, 0]
    rename_inputs["valid_bit"]          = [0, 0, 0, 0]

    dut.rename(rename_inputs)

    await RisingEdge(dut.clock())
    dut.rename()
    await ReadOnly()


    assert dut.get_outputs()["RD"][0] == 1

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    print(dut.get_RAT(0))
    print(dut.get_ready(0))


    FU_inputs = generate_null_FU_inputs()

    FU_inputs["valid"] = [1,1,0,0]
    FU_inputs["RD"] = [1,2,0,0]
    FU_inputs["RD_data"] = [0,0,0,0]
    FU_inputs["RD_valid"] = [1,0,0,0]
    FU_inputs["instruction_PC"] = [0,0,0,0]
    FU_inputs["branch_taken"] = [0,0,0,0]
    FU_inputs["target_address"] = [0,0,0,0]
    FU_inputs["branch_valid"] = [0,0,0,0]
    FU_inputs["ROB_index"] = [0,0,0,0]
    FU_inputs["fetch_packet_index"] = [0,0,0,0]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()


    await ReadOnly()
    
    print(dut.get_RAT(0))
    print(dut.get_ready(0))

    assert dut.get_ready(0)[7] == 1
    assert dut.get_ready(0)[9] == 1



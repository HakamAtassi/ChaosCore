import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from rename import *

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
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()

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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 0, 0, 0]


    dut.write_decoded_fetch_packet(rename_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][0] == 1

    await RisingEdge(dut.clock())

    await ReadOnly()

@cocotb.test()
async def test_rename_4_RD(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class

    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [2, 4, 6, 7]
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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 1, 1, 1]


    dut.write_decoded_fetch_packet(rename_inputs)

    await RisingEdge(dut.clock())
    dut.write_decoded_fetch_packet()

    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][1] == 2
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][2] == 3
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][3] == 4


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [0, 0, 0, 0]
    rename_inputs["RD_valid"]           = [0, 0, 0, 0]
    rename_inputs["RS1"]                = [2, 4, 6, 7]
    rename_inputs["RS1_valid"]          = [1, 1, 1, 1]
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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 1, 1, 1]


    dut.write_decoded_fetch_packet(rename_inputs)

    await RisingEdge(dut.clock())
    dut.write_decoded_fetch_packet()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][1] == 2
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][2] == 3
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][3] == 4


@cocotb.test()
async def test_rename_RS(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class

    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [2, 4, 6, 7]
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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 1, 1, 1]


    dut.write_decoded_fetch_packet(rename_inputs)

    await RisingEdge(dut.clock())

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [0, 0, 0, 0]
    rename_inputs["RD_valid"]           = [0, 0, 0, 0]
    rename_inputs["RS1"]                = [2, 4, 6, 7]
    rename_inputs["RS1_valid"]          = [1, 1, 1, 1]
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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 1, 1, 1]


    dut.write_decoded_fetch_packet(rename_inputs)



    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][1] == 2
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][2] == 3
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][3] == 4

    await RisingEdge(dut.clock())
    await ReadOnly()


    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][1] == 2
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][2] == 3
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][3] == 4


@cocotb.test()
async def test_rename_bypass(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class

    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [5, 0, 0, 0]
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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 1, 0, 0]

    dut.write_decoded_fetch_packet(rename_inputs)

    await RisingEdge(dut.clock())
    dut.write_decoded_fetch_packet()

    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][1] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RS1_ready"][1] == 0

    await RisingEdge(dut.clock())

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [0, 0, 0, 0]
    rename_inputs["RD_valid"]           = [0, 0, 0, 0]
    rename_inputs["RS1"]                = [5, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [1, 0, 0, 0]
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
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 0, 0, 0]


    dut.write_decoded_fetch_packet(rename_inputs)
    await RisingEdge(dut.clock())
    dut.write_decoded_fetch_packet()


    
    FU_outputs = generate_null_FU_outputs()
    FU_outputs["valid"]=                [1,0,0,0]
    FU_outputs["RD"]=                   [1,0,0,0]
    FU_outputs["RD_data"]=              [0,0,0,0]
    FU_outputs["RD_valid"]=             [1,0,0,0]
    FU_outputs["fetch_PC"]=             [0]*4
    FU_outputs["branch_taken"]=         [0]*4
    FU_outputs["target_address"]=       [0]*4
    FU_outputs["branch_valid"]=         [0]*4
    FU_outputs["ROB_index"]=            [0]*4
    FU_outputs["fetch_packet_index"]=   [0]*4
    dut.write_FU_outputs(FU_outputs)


    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RS1"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["RS1_ready"][0] == 1
    assert dut.rename_renamed_decoded_fetch_packet()["valid_bits"][0] == 1





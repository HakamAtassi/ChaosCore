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
async def test_rename_1_RD(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    model = rename_model()

    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()


    for _ in range(100):
        dut.inputs()

        model.inputs()
        model.eval()

        # try eval...

        #assertions




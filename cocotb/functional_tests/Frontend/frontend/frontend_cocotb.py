import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from frontend_dut import *
from SimpleDRAM import SimpleDRAM

@cocotb.test()
async def test_reset(dut):

    DRAM = SimpleDRAM(sizeKB=2, bin="../bins/addi.bin")

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_decoder_out(dut):

    DRAM = SimpleDRAM(sizeKB=2, bin="../bins/addi.bin")

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module


    await dut.wait_decoder_outputs_valid()

    #await ReadOnly()


    assert dut.get_decoder_outputs()["RS1"][0]                  == 0
    assert dut.get_decoder_outputs()["RS2"][0]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][0]            == 1
    assert dut.get_decoder_outputs()["IMM"][0]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][0]            == 1  # FIXME: the name of this flag should be changed to IS_IMMEDIATE
    # in the hardware and in the tests...

    assert dut.get_decoder_outputs()["RS1"][1]                  == 0
    assert dut.get_decoder_outputs()["RS2"][1]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][1]            == 1
    assert dut.get_decoder_outputs()["IMM"][1]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][1]            == 1 

    assert dut.get_decoder_outputs()["RS1"][2]                  == 0
    assert dut.get_decoder_outputs()["RS2"][2]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][2]            == 1
    assert dut.get_decoder_outputs()["IMM"][2]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][2]            == 1 

    assert dut.get_decoder_outputs()["RS1"][3]                  == 0
    assert dut.get_decoder_outputs()["RS2"][3]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][3]            == 1
    assert dut.get_decoder_outputs()["IMM"][3]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][3]            == 1 

    await dut.wait_decoder_outputs_valid()

    dut.print_decoder_outputs()


    assert dut.get_decoder_outputs()["RS1"][0]                  == 0
    assert dut.get_decoder_outputs()["RS2"][0]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][0]            == 1
    assert dut.get_decoder_outputs()["IMM"][0]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][0]            == 1 
    # in the hardware and in the tests...

    assert dut.get_decoder_outputs()["RS1"][1]                  == 0
    assert dut.get_decoder_outputs()["RS2"][1]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][1]            == 1
    assert dut.get_decoder_outputs()["IMM"][1]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][1]            == 1 

    assert dut.get_decoder_outputs()["RS1"][2]                  == 0
    assert dut.get_decoder_outputs()["RS2"][2]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][2]            == 1
    assert dut.get_decoder_outputs()["IMM"][2]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][2]            == 1 

    assert dut.get_decoder_outputs()["RS1"][3]                  == 0
    assert dut.get_decoder_outputs()["RS2"][3]                  == 0
    assert dut.get_decoder_outputs()["needs_ALU"][3]            == 1
    assert dut.get_decoder_outputs()["IMM"][3]                  == 0
    assert dut.get_decoder_outputs()["IMMEDIATE"][3]            == 1 


@cocotb.test()
async def test_predecoder_stall(dut):
    """Test that the predecoder doesnt change state/lose outputs when its output is not ready"""

    DRAM = SimpleDRAM(sizeKB=2, bin="../bins/addi.bin")

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module




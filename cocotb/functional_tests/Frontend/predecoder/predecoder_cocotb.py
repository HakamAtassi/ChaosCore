import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from predecoder_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_addi_passthrough(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)


    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.get_final_fetch_packet()["valid"] == 1
    dut.get_final_fetch_packet()["packet_index"] == 0

    dut.get_final_fetch_packet()["instruction_valid"][0] == 1
    dut.get_final_fetch_packet()["instruction_valid"][1] == 1
    dut.get_final_fetch_packet()["instruction_valid"][2] == 1
    dut.get_final_fetch_packet()["instruction_valid"][3] == 1

    dut.get_final_fetch_packet()["packet_index"][0] == 0
    dut.get_final_fetch_packet()["packet_index"][1] == 1
    dut.get_final_fetch_packet()["packet_index"][2] == 2
    dut.get_final_fetch_packet()["packet_index"][3] == 3

    dut.print_final_fetch_packet()

@cocotb.test()
async def test_addi_with_prediction_invalid(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   0

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)


    await RisingEdge(dut.clock())
    await ReadOnly()


    dut.get_final_fetch_packet()["valid"] == 0
    dut.get_final_fetch_packet()["packet_index"] == 0


    dut.print_final_fetch_packet()

@cocotb.test()
async def test_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.set_final_fetch_packet_ready(1)
    dut.set_FTQ_ready(1)

    await ReadOnly()

    assert dut.get_fetch_packet_ready() == 1
    assert dut.get_prediction_ready() == 1

    await RisingEdge(dut.clock())

    dut.set_final_fetch_packet_ready(0)
    dut.set_FTQ_ready(1)

    await ReadOnly()

    assert dut.get_fetch_packet_ready() == 0
    assert dut.get_prediction_ready() == 0

    await RisingEdge(dut.clock())

    dut.set_final_fetch_packet_ready(1)
    dut.set_FTQ_ready(0)

    await ReadOnly()

    assert dut.get_fetch_packet_ready() == 0
    assert dut.get_prediction_ready() == 0


# Test FTQ, RAS, and prediction correction

@cocotb.test()
async def test_JAL_then_correct(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    assert False

@cocotb.test()
async def test_JAL_then_incorrect(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    assert False
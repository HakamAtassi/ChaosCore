import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

import os

from cocotb_utils import *
from ChaosCore_dut import *
from SimpleDRAM import SimpleDRAM

@cocotb.test()
async def test_reset(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "bins/hello_world.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 



    dut = ChaosCore_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module



@cocotb.test()
async def test_hello_world(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "bins/hello_world.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 



    dut = ChaosCore_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_dram_ready(1)   # dram ready for request (from cache)


    for _ in range(100):
        await ReadOnly()
        if(dut.get_instruction_fetch_output()["valid"] == 1):
            break;
        await dut.update()

    print(dut.get_instruction_fetch_output())

    assert dut.get_instruction_fetch_output()["valid"] == 1
    assert dut.get_instruction_fetch_output()["instruction"][0] == 0x04800793
    assert dut.get_instruction_fetch_output()["instruction"][1] == 0x40f02023
    assert dut.get_instruction_fetch_output()["instruction"][2] == 0x04500793
    assert dut.get_instruction_fetch_output()["instruction"][3] == 0x40f02023

    assert dut.get_instruction_fetch_output()["valid_bits"][0]  == 1
    assert dut.get_instruction_fetch_output()["valid_bits"][1]  == 1
    assert dut.get_instruction_fetch_output()["valid_bits"][2]  == 1
    assert dut.get_instruction_fetch_output()["valid_bits"][3]  == 1


    for _ in range(100):
        await ReadOnly()
        if(dut.get_frontend_output()["fetch_packet_valid"] == 1):
            break;
        await dut.update()

    assert dut.get_frontend_output()["fetch_packet_valid"] == 1

   #10074:	04800793          	li	x15,72
   #10078:	40f02023          	sw	x15,1024(x0) # 400 <main-0xfc74>
   #1007c:	04500793          	li	x15,69
   #10080:	40f02023          	sw	x15,1024(x0) # 400 <main-0xfc74>

    assert dut.get_frontend_output()["valid_bits"]  == [1,1,1,1]
    assert dut.get_frontend_output()["IS_STORE"]    == [0,1,0,1]
    assert dut.get_frontend_output()["needs_ALU"]   == [1,0,1,0]
    assert dut.get_frontend_output()["RS_type"]     == [0,1,0,1]

    assert dut.get_frontend_output()["RD"][0]        == 1
    assert dut.get_frontend_output()["RD"][2]        == 2

    assert dut.get_frontend_output()["RS2"][1]        == 1  # First rename maps x15 => 0
    assert dut.get_frontend_output()["RS2"][3]        == 2  # Second rename maps x15 => 1


    assert dut.get_frontend_output()["RD_valid"]    == [1, 0, 1, 0]

    for _ in range(100):
        await ReadOnly()
        if(dut.get_frontend_output()["fetch_packet_valid"] == 1):
            break;
        await dut.update()

    assert dut.get_frontend_output()["fetch_packet_valid"] == 1


    assert dut.get_frontend_output()["valid_bits"]  == [1,1,1,1]
    assert dut.get_frontend_output()["IS_STORE"]    == [0,1,1,0]
    assert dut.get_frontend_output()["needs_ALU"]   == [1,0,0,1]
    assert dut.get_frontend_output()["RS_type"]     == [0,1,1,0]

    #assert dut.get_frontend_output()["RD"][1]        == 3
    #assert dut.get_frontend_output()["RD"][2]        == 4

    #assert dut.get_frontend_output()["RS2"][1]        == 3  # First rename maps x15 => 0
    #assert dut.get_frontend_output()["RS2"][3]        == 4  # Second rename maps x15 => 1



    for i in range(200):
        await dut.update()

    print(dut.get_PRF())

    assert False
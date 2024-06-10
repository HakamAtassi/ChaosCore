import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from instruction_cache_dut import *
from model_utils import *
from SimpleDRAM import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.request_read(1, 1)
    await RisingEdge(dut.clock())
    dut.request_read()

    for _ in range(10):
        await dut.update()


    dut.print_cache_contents()

@cocotb.test()
async def test_write_1_all_ready(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()

    
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_cache_ready(1)  # CPU ready to accept data (from cache)
    dut.set_dram_ready(1)   # dram ready for request (from cache)

    assert dut.get_cache_output()["cpu_addr_ready"] == 1    # Cache ready to accept request from CPU


    dut.request_read(address=0x0, valid = 1)
    await RisingEdge(dut.clock())
    dut.request_read()

    await dut.wait_response()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3


    await dut.update()

    assert dut.get_cache_output()["cpu_addr_ready"] == 1
    assert dut.get_cache_output()["fetch_PC"] == 0x0

    await dut.update()
    await dut.update()
    await dut.update()

@cocotb.test()
async def test_write_2_all_ready(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()

    
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_cache_ready(1)  # CPU ready to accept data (from cache)
    dut.set_dram_ready(1)   # dram ready for request (from cache)

    assert dut.get_cache_output()["cpu_addr_ready"] == 1    # Cache ready to accept request from CPU


    dut.request_read(address=0x0, valid = 1)
    await RisingEdge(dut.clock())
    dut.request_read()

    await dut.wait_response()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3


    await dut.update()

    assert dut.get_cache_output()["cpu_addr_ready"] == 1
    assert dut.get_cache_output()["fetch_PC"] == 0x0
    # Try another read (hit)

    await RisingEdge(dut.clock())

    dut.request_read(address=0x10, valid = 1)

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_cache_output()["packet_valid"]

    assert dut.get_cache_output()["fetch_PC"] == 0x10
    assert dut.get_cache_output()["instruction"][0] == 4
    assert dut.get_cache_output()["instruction"][1] == 5
    assert dut.get_cache_output()["instruction"][2] == 6
    assert dut.get_cache_output()["instruction"][3] == 7

@cocotb.test()
async def test_write_3_all_ready(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()

    
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # rese            cache_valid := hitt module

    dut.set_cache_ready(1)  # CPU ready to accept data (from cache)
    dut.set_dram_ready(1)   # dram ready for request (from cache)

    assert dut.get_cache_output()["cpu_addr_ready"] == 1    # Cache ready to accept request from CPU


    dut.request_read(address=0x0, valid = 1)
    await RisingEdge(dut.clock())
    dut.request_read()

    await dut.wait_response()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["fetch_PC"] == 0x0
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3


    await dut.update()

    assert dut.get_cache_output()["cpu_addr_ready"] == 1

    # Try another read (hit)

    await RisingEdge(dut.clock())

    dut.request_read(address=0x10, valid = 1)

    await RisingEdge(dut.clock())
    dut.request_read()
    await ReadOnly()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["fetch_PC"] == 0x10
    assert dut.get_cache_output()["instruction"][0] == 4
    assert dut.get_cache_output()["instruction"][1] == 5
    assert dut.get_cache_output()["instruction"][2] == 6
    assert dut.get_cache_output()["instruction"][3] == 7



    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.request_read(address=0x20, valid = 1)

    await RisingEdge(dut.clock())
    dut.request_read()
    await ReadOnly()

    assert dut.get_cache_output()["packet_valid"] == 0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

@cocotb.test()
async def test_write_1_cpu_not_ready(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()

    
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_cache_ready(0)  # CPU not ready to accept data (from cache)
    dut.set_dram_ready(1)   # dram ready for request (from cache)

    assert dut.get_cache_output()["cpu_addr_ready"] == 1    # Cache ready to accept request from CPU


    dut.request_read(address=0x0, valid = 1)
    await RisingEdge(dut.clock())
    dut.request_read()

    await dut.wait_response()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["fetch_PC"] == 0x0
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    assert dut.get_cache_output()["packet_valid"]   # hold response for as long as needed
    assert dut.get_cache_output()["fetch_PC"] == 0x00
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3

    # cpu now ready for response

    dut.set_cache_ready(1)
    await dut.update()

    assert dut.get_cache_output()["packet_valid"] == 0

@cocotb.test()
async def test_write_1_DRAM_not_ready(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()

    
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_cache_ready(1)  # CPU ready to accept data (from cache)
    dut.set_dram_ready(0)   # dram ready for request (from cache)

    assert dut.get_cache_output()["cpu_addr_ready"] == 1    # Cache ready to accept request from CPU


    dut.request_read(address=0x0, valid = 1)
    await RisingEdge(dut.clock())
    dut.request_read()

    for _ in range(100):
        await RisingEdge(dut.clock())
    
    dut.set_dram_ready(1)
    
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    dut.request_allocate(DRAM.read(0, 32), 1)
    await RisingEdge(dut.clock())
    dut.request_allocate()

    await ReadOnly()


    
    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3


@cocotb.test()
async def test_reads_fifo_style_all_ready(dut):

    await cocotb.start(generateClock(dut)) 

    DRAM = SimpleDRAM()

    
    

    for i in range(1024):
        DRAM.write(i*4, i, 4) # init dram

    dut = instruction_cache_dut(dut, DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_cache_ready(1)  # CPU ready to accept data (from cache)
    dut.set_dram_ready(1)   # dram ready for request (from cache)

    assert dut.get_cache_output()["cpu_addr_ready"] == 1    # Cache ready to accept request from CPU


    dut.request_read(address=0x0, valid = 1)    # accepted
    await RisingEdge(dut.clock())

    dut.request_read(address=0x10, valid = 1)    # placed, not accepted

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.request_allocate(DRAM.read(0, 32), 1)
    await RisingEdge(dut.clock())
    dut.request_allocate()
    await ReadOnly()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["instruction"][0] == 0
    assert dut.get_cache_output()["instruction"][1] == 1
    assert dut.get_cache_output()["instruction"][2] == 2
    assert dut.get_cache_output()["instruction"][3] == 3
    assert dut.get_cache_output()["fetch_PC"] == 0x0

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_cache_output()["packet_valid"]
    assert dut.get_cache_output()["fetch_PC"] == 0x10
    assert dut.get_cache_output()["instruction"][0] == 4
    assert dut.get_cache_output()["instruction"][1] == 5
    assert dut.get_cache_output()["instruction"][2] == 6
    assert dut.get_cache_output()["instruction"][3] == 7



# add fetch_PC tests
import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from L1_instruction_cache_TB import *
from L1_caches import instruction_cache_dut

@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_instruction_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset


@cocotb.test()
async def test_miss_hit(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_instruction_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()                    # INIT axi ram

    # Set response valid
    L1_cache.set_CPU_response(1)

    # Wait a bit for no particular reason
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()

    # Perform a request
    await L1_cache.write_CPU_read_request(address=0, valid = 1)

    # Should miss
    assert L1_cache.CPU_read_response()["valid"] == 0

    # wait for hit
    await L1_cache.wait_cache_hit()

    # assert 
    assert L1_cache.CPU_read_response()["valid"] == 1
    assert L1_cache.CPU_read_response()["bits"]["instruction"][0] == 0x0
    assert L1_cache.CPU_read_response()["bits"]["instruction"][1] == 0x1
    assert L1_cache.CPU_read_response()["bits"]["instruction"][2] == 0x2
    assert L1_cache.CPU_read_response()["bits"]["instruction"][3] == 0x3



    # Perform the same request
    await L1_cache.write_CPU_read_request(address=0, valid = 1)
    await L1_cache.clock()

    # should hit
    assert L1_cache.CPU_read_response()["valid"] == 1
    assert L1_cache.CPU_read_response()["bits"]["instruction"][0] == 0x0
    assert L1_cache.CPU_read_response()["bits"]["instruction"][1] == 0x1
    assert L1_cache.CPU_read_response()["bits"]["instruction"][2] == 0x2
    assert L1_cache.CPU_read_response()["bits"]["instruction"][3] == 0x3


    # Read the next instrs in the same line
    await L1_cache.write_CPU_read_request(address=16, valid = 1)
    await L1_cache.clock()

    assert L1_cache.CPU_read_response()["valid"] == 1
    assert L1_cache.CPU_read_response()["bits"]["instruction"][0] == 0x4
    assert L1_cache.CPU_read_response()["bits"]["instruction"][1] == 0x5
    assert L1_cache.CPU_read_response()["bits"]["instruction"][2] == 0x6
    assert L1_cache.CPU_read_response()["bits"]["instruction"][3] == 0x7


@cocotb.test()
async def test_sweep_sets(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_instruction_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()                    # INIT axi ram

    # Set response valid
    L1_cache.set_CPU_response(1)

    # Wait a bit for no particular reason
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()

    for set in range(64):

        set_sweep_addr = set*32

        # Perform a request
        await L1_cache.write_CPU_read_request(address=set_sweep_addr, valid = 1)

        # Should miss
        assert L1_cache.CPU_read_response()["valid"] == 0

        # wait for hit
        await L1_cache.wait_cache_hit()

        # assert 
        assert L1_cache.CPU_read_response()["valid"] == 1
        assert L1_cache.CPU_read_response()["bits"]["instruction"][0] == set*8 + 0x0
        assert L1_cache.CPU_read_response()["bits"]["instruction"][1] == set*8 + 0x1
        assert L1_cache.CPU_read_response()["bits"]["instruction"][2] == set*8 + 0x2
        assert L1_cache.CPU_read_response()["bits"]["instruction"][3] == set*8 + 0x3



        # Perform the same request
        await L1_cache.write_CPU_read_request(address=set_sweep_addr, valid = 1)
        await L1_cache.clock()

        # should hit
        assert L1_cache.CPU_read_response()["valid"] == 1
        assert L1_cache.CPU_read_response()["bits"]["instruction"][0] == set*8 + 0x0
        assert L1_cache.CPU_read_response()["bits"]["instruction"][1] == set*8 + 0x1
        assert L1_cache.CPU_read_response()["bits"]["instruction"][2] == set*8 + 0x2
        assert L1_cache.CPU_read_response()["bits"]["instruction"][3] == set*8 + 0x3

        # Perform the same request
        await L1_cache.write_CPU_read_request(address=set_sweep_addr+16, valid = 1)
        await L1_cache.clock()

        # should hit
        assert L1_cache.CPU_read_response()["valid"] == 1
        assert L1_cache.CPU_read_response()["bits"]["instruction"][0] == set*8 + 0x4
        assert L1_cache.CPU_read_response()["bits"]["instruction"][1] == set*8 + 0x5
        assert L1_cache.CPU_read_response()["bits"]["instruction"][2] == set*8 + 0x6
        assert L1_cache.CPU_read_response()["bits"]["instruction"][3] == set*8 + 0x7


@cocotb.test()
async def test_AXI_not_ready(dut):
    """Test that the core stops accepting responses, and that nothing is dropped, when a miss occurs during which the AXI 
    bus is not ready."""
    """It should accept a response, miss, see that the bus is not ready, and stall, I think"""
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = instruction_cache_dut(dut)     # construct TB
    await L1_cache.reset()                      # Reset

    # Set response valid
    L1_cache.set_CPU_response(1)

    # Set AXI AR not ready
    L1_cache.set_AXI_AR_ready(0)

    # Wait a bit for no particular reason
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()



    # access set 0
    L1_cache.write_CPU_read_request(address=0x40, valid = 1)
    await L1_cache.clock()
    L1_cache.write_CPU_read_request()

    ## Check AXI request
    await ReadOnly()
    assert L1_cache.read_AXI_AR()["valid"]  == 1
    assert L1_cache.read_AXI_AR()["bits"]["araddr"]  == 0x40


    ## Check AXI request not dropped

    for i in range(10):
        await L1_cache.clock()
        assert L1_cache.read_AXI_AR()["valid"]  == 1
        assert L1_cache.read_AXI_AR()["bits"]["araddr"]  == 0x40


    # Set AXI AR ready
    L1_cache.set_AXI_AR_ready(1)
    await L1_cache.clock()


    # Check AXI AR accepted
    await ReadOnly()
    assert L1_cache.read_AXI_AR()["valid"]  == 0


@cocotb.test()
async def test_CPU_not_ready(dut):
    """test that responses are not dropped if they are generated when the CPU is not ready"""
    """Should test after normal hit or when coming out of miss"""
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_instruction_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()                    # INIT axi ram

    # Set response valid
    L1_cache.set_CPU_response(0)

    # Wait a bit for no particular reason
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()

    await L1_cache.write_CPU_read_request(address=0x40, valid = 1)

    await L1_cache.wait_cache_hit()

    assert L1_cache.CPU_read_response()["valid"]   == 1

    await L1_cache.clock()
    assert L1_cache.CPU_read_response()["valid"]   == 1

    await L1_cache.clock()
    assert L1_cache.CPU_read_response()["valid"]   == 1




#@cocotb.test()
#async def test_kill(dut):
    ## Set seed
    #random.seed(0x42)

    ## Start lock
    #await cocotb.start(generateClock(dut))

    ## Bring up TB
    #L1_cache = L1_instruction_cache_TB(dut)     # construct TB
    #await L1_cache.reset()                      # Reset
    #L1_cache.init_sequence()                    # INIT axi ram

    ## Set response valid
    #L1_cache.set_CPU_response(1)

    ## Wait a bit for no particular reason
    #await L1_cache.clock()
    #await L1_cache.clock()
    #await L1_cache.clock()
    #await L1_cache.clock()











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




# Assertions:
# Black box:
# Data output is correct (every valid & ready has a corresponding response)
# Valid mask is correct
# PC is correct
# When valid, AXI data does not change (no AXI drops)
# On kill, accept AXI request then discard it. 
# White box:
# Ways are being selected correctly. 



# Every cycle, perform a request.
# When a request is created, queue the expected response
# When a response is generated, compare the expected response to the actual response

@cocotb.test()
async def test_fuzz_no_kill(dut):
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



# Every cycle, perform a request with possible kill
# When a request is created, queue the expected response
# When a response is generated, compare the expected response to the actual response

@cocotb.test()
async def test_fuzz(dut):
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










import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os
from model_utils import *

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

    # For good address coverage, you want to generate an address pool and sample from it
    # Generating random addresses will just cause a large number of misses and very poor address reuse (you would basically only test misses)
    # To create good addresses, you must generate a few (4-5) tags to select from for each set. Byte offset does not matter as long as it's instruction aligned
    # To generate an address, just pick a set (random, sweep, doesnt matter), and then sample a tag for that set. Generate a byte offset, then put it all together. 

    TAGS_PER_SET = 5
    BITS_PER_TAG = 21

    tag_groups = [0]*64


    for set in range(64):
        tag_groups[set] = [0]*TAGS_PER_SET
        for _ in range(TAGS_PER_SET):
            tag_groups[set].append(random.getrandbits(10)) # limit tag size because large memories are slow to simulate

    for iteration in range(25000):
        # Generate random request 

        set = random.randrange(0, 63)
        tag = random.sample(sorted(tag_groups[set]), 1)[0]

        byte_offset = random.randrange(0, 7)*4  

        valid = random.sample(sorted([0,1,2,3]), 1)[0]  # 1/(n-1) chance of valid request
        valid = (valid == 0)

        address = generateAddr(tag, set, byte_offset, 64, 32)

        # Perform self checking request

        await L1_cache.self_checking_request(address, valid)






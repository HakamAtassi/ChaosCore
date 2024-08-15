import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from L1_data_cache_TB import *
from L1_caches import *

@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset


@cocotb.test()
async def test_read(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)     # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()                    # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    for i in range(0, 1024, 4):
        await L1_cache.write_CPU_request(valid = 1, addr = i, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=0)

        await L1_cache.wait_cache_hit()

        _i = i & 0xFF

        assert L1_cache.read_CPU_response()["valid"] == 1
        assert L1_cache.read_CPU_response()["bits"]["data"] ==  int.from_bytes([_i+3, _i+2, _i+1, _i], byteorder='big') 



        await L1_cache.clock()


@cocotb.test()
async def test_output_format(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    for i in range(0, 1024):
        await L1_cache.write_CPU_request(valid = 1, addr = i, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)

        await L1_cache.wait_cache_hit()

        assert L1_cache.read_CPU_response()["valid"] == 1
        assert L1_cache.read_CPU_response()["bits"]["data"] == i & 0xFF


@cocotb.test()
async def test_hit_latency(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    await L1_cache.write_CPU_request(valid = 1, addr = 0x0, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)

    #await L1_cache.wait_cache_hit()


    for _ in range(100):
        await L1_cache.clock()

    await L1_cache.write_CPU_request(valid = 1, addr = 0x1, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)

    await L1_cache.clock()
    await ReadOnly()
    assert L1_cache.read_CPU_response()["valid"] == 1
    assert L1_cache.read_CPU_response()["bits"]["data"] == 1 & 0xFF


@cocotb.test()
async def test_burst_of_requests_to_miss_line(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    await L1_cache.write_CPU_request(valid = 1, addr = 0x20, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x21, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x22, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x23, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)

    for _ in range(1000):
        await L1_cache.clock()

@cocotb.test()
async def test_write(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    await L1_cache.write_CPU_request(valid = 1, addr = 0x0, data=0xF1 ,memory_type=memory_type_t.STORE, access_width=access_width_t.B, MOB_index=0)

    for _ in range(1000):
        await L1_cache.clock()

    await L1_cache.write_CPU_request(valid = 1, addr = 0x0, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=0)

    await L1_cache.wait_cache_hit()
    assert L1_cache.read_CPU_response()["valid"] == 1
    assert L1_cache.read_CPU_response()["bits"]["data"] == 0xF1

    await L1_cache.write_CPU_request(valid = 1, addr = 0x0, data=0x0D0C_0B0A ,memory_type=memory_type_t.STORE, access_width=access_width_t.W, MOB_index=0)

    await L1_cache.write_CPU_request(valid = 1, addr = 0x0, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=0)

    await L1_cache.wait_cache_hit()
    assert L1_cache.read_CPU_response()["valid"] == 1
    assert L1_cache.read_CPU_response()["bits"]["data"] == 0x0D0C_0B0A


    for _ in range(1000):
        await L1_cache.clock()

@cocotb.test()
async def test_MOB_resp(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    await L1_cache.write_CPU_request(valid = 1, addr = 0x4, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)

    await L1_cache.wait_cache_hit()
    assert L1_cache.read_CPU_response()["valid"] == 1
    assert L1_cache.read_CPU_response()["bits"]["data"] == 0x4
    assert L1_cache.read_CPU_response()["bits"]["MOB_index"] == 8

    await L1_cache.write_CPU_request(valid = 1, addr = 0x4, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)

    await L1_cache.wait_cache_hit()
    assert L1_cache.read_CPU_response()["valid"] == 1
    assert L1_cache.read_CPU_response()["bits"]["data"] == 0x4
    assert L1_cache.read_CPU_response()["bits"]["MOB_index"] == 8


@cocotb.test()
async def test_LRU(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    tag     = 4
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)

    for _ in range(15):
        await L1_cache.clock()

    # Request read from new tag
    tag     = 5
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    for _ in range(15):
        await L1_cache.clock()

    # Request read from new tag
    tag     = 6
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    for _ in range(15):
        await L1_cache.clock()

    # Request read from new tag
    tag     = 7
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)

    await L1_cache.wait_cache_hit()

    for _ in range(100):
        await L1_cache.clock()


    # check that allocates were performed to expected cache ways
    tag     = 4
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    await L1_cache.wait_cache_hit()

    # Request read from new tag
    tag     = 5
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    await L1_cache.wait_cache_hit()

    # Request read from new tag
    tag     = 6
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    await L1_cache.wait_cache_hit()

    # Request read from new tag
    tag     = 7
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    await L1_cache.wait_cache_hit()

    # Request read from new tag
    tag     = 9
    set     = 1
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)


    for _ in range(10):
        await L1_cache.clock()


@cocotb.test()
async def test_burst_accesses(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read


    await L1_cache.write_CPU_request(valid = 1, addr = 0x22, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x102, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x202, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=3)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x402, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=4)





    await L1_cache.write_CPU_request(valid = 1, addr = 0x24, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x104, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x204, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x404, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)


    #await L1_cache.write_CPU_request(valid = 1, addr = 0xB, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0xC, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0xD, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0xE, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0xF, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=8)


    for _ in range(100):
        await L1_cache.clock()


@cocotb.test()
async def test_backpressure(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(0)    # Set CPU not ready. 

    # Request read

    await L1_cache.write_CPU_request(valid = 1, addr = 0x1, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x2, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x3, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)


    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()

    L1_cache.write_CPU_response_ready(1)    # Set CPU not ready. 


    for _ in range(100):
        await L1_cache.clock()
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

from model_utils import *

import logging

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
    await L1_cache.clock()
    await ReadOnly()
    assert L1_cache.read_CPU_response()["valid"] == 1
    assert L1_cache.read_CPU_response()["bits"]["data"] == 1 & 0xFF


    await L1_cache.clock()
    await L1_cache.clock()
    await L1_cache.clock()


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

    await L1_cache.write_CPU_request(valid = 1, addr = 0x20, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=3)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x21, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=4)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x22, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=5)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x23, data=0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=6)

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
    L1_cache = L1_data_cache_TB(dut, 256*(2**10))            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read

    tag     = 4
    set     = 0
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0xdeadbeef ,memory_type=memory_type_t.STORE, access_width=access_width_t.W, MOB_index=8)

    for _ in range(25):
        await L1_cache.clock()

    # Request read from new tag
    tag     = 5
    set     = 0
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.STORE, access_width=access_width_t.W, MOB_index=8)


    for _ in range(25):
        await L1_cache.clock()

    ## Request read from new tag
    tag     = 6
    set     = 0
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.STORE, access_width=access_width_t.W, MOB_index=8)


    for _ in range(25):
        await L1_cache.clock()

    # Request read from new tag
    tag     = 7
    set     = 0
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.STORE, access_width=access_width_t.W, MOB_index=8)

    for _ in range(25):
        await L1_cache.clock()

    # Request read from new tag
    tag     = 20
    set     = 0
    offset  = 0
    address = (tag<<11) + (set<<5) + (offset<<0)

    await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)

    for _ in range(30):
        await L1_cache.clock()



#    tag     = 10
    #set     = 0
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0, memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)

    #for _ in range(15):
        #await L1_cache.clock()

    #tag     = 11
    #set     = 0
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0, memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)

    #for _ in range(15):
        #await L1_cache.clock()

    #tag     = 12
    #set     = 0
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0, memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)

    #for _ in range(15):
        #await L1_cache.clock()


    ## check that allocates were performed to expected cache ways
    #tag     = 4
    #set     = 1
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    #await L1_cache.wait_cache_hit()

    ## Request read from new tag
    #tag     = 5
    #set     = 1
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    #await L1_cache.wait_cache_hit()

    ## Request read from new tag
    #tag     = 6
    #set     = 1
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    #await L1_cache.wait_cache_hit()

    ## Request read from new tag
    #tag     = 7
    #set     = 1
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)

    #await L1_cache.write_CPU_request(valid = 1, addr = address, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.W, MOB_index=8)


    #await L1_cache.wait_cache_hit()

    ## Request read from new tag
    #tag     = 9
    #set     = 1
    #offset  = 0
    #address = (tag<<11) + (set<<5) + (offset<<0)


    #for _ in range(10):
        #await L1_cache.clock()
    assert False

@cocotb.test()
async def test_burst_accesses(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut, 256*(2**10))            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)

    # Request read


    await L1_cache.write_CPU_request(valid = 1, addr = 0x22, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x102, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x202, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=3)
    await L1_cache.write_CPU_request(valid = 1, addr = 0x402, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=4)





    await L1_cache.write_CPU_request(valid = 1, addr = 0x502, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0x104, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0x204, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)
    #await L1_cache.write_CPU_request(valid = 1, addr = 0x404, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=2)


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


@cocotb.test()
async def test_non_cacheable(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut)            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)    # Set CPU not ready. 

    # Request read

    for _ in range(20):
        await L1_cache.clock()


    await L1_cache.write_CPU_request(valid = 1, addr = 0x8000_0000, data=0x42 ,memory_type=memory_type_t.STORE, access_width=access_width_t.B, MOB_index=1)

    for _ in range(20):
        await L1_cache.clock()

    await L1_cache.write_CPU_request(valid = 1, addr = 0x8000_0000, data=0x0 ,memory_type=memory_type_t.LOAD, access_width=access_width_t.B, MOB_index=1)


    for _ in range(100):
        await L1_cache.clock()




@cocotb.test()
async def test_fuzz(dut):

    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    L1_cache = L1_data_cache_TB(dut, 256*(2**10))            # construct TB
    await L1_cache.reset()                      # Reset
    L1_cache.init_sequence()      # INIT axi ram

    # Set response port ready
    L1_cache.write_CPU_response_ready(1)    # Set CPU not ready. 

    # Request read


    TAGS_PER_SET = 10
    BITS_PER_TAG = 21
    tag_groups = [0]*64

    for set in range(64):
        tag_groups[set] = [0]*TAGS_PER_SET
        for _ in range(TAGS_PER_SET):
            tag_groups[set].append(random.getrandbits(5)) # limit tag size because large memories are slow to simulate

    MOB_index = 0
    for iteration in range(25_000):
        # Generate address
        set = random.randrange(0, 63)
        tag = random.sample(sorted(tag_groups[set]), 1)[0]


        # Generate request
        

        valid = random.choice([0,1,2,3])  # 1/(n-1) chance of valid request
        valid = (valid == 0)
        
        memory_type = random.choice([memory_type_t.LOAD, memory_type_t.STORE])
        access_width = random.choice([(access_width_t.B, 1), (access_width_t.HW, 2), (access_width_t.W, 4)])

        # byte offsets must be aligned
        byte_offset = random.randrange(0, (32-access_width[1])//access_width[1])*access_width[1] 


        address = generateAddr(tag, set, byte_offset, 64, 32)

        data = random.getrandbits(32)
        MOB_index+=1
        MOB_index%=16

        # Perform self checking request
        await L1_cache.self_checking_request(valid, address, data, memory_type, access_width[0], MOB_index)






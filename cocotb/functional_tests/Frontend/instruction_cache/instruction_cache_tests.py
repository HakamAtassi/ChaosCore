import sys
from time import sleep
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from InstructionCache import *  # import model
from SimpleDRAM import *
from cocotb_utils import *      # import verif utils
from model_utils import *

from InstructionCacheDut import *

SETS = 64
WAYS = 2
BLOCKSIZE = 32
FETCHWIDTH = 4


@cocotb.test()
async def instruction_cache_kill_miss_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    model_dram = SimpleDRAM(sizeKB=1<<10)
    model_dram.randomize()
    dut = InstructionCacheDut(dut, model_dram)  # Extend dut

    await FallingEdge(dut.clock())

    for _ in range(1000):


        dut.read(address=0x1234, valid=1)
        await FallingEdge(dut.clock())
        dut.read(address=0, valid=0)

        assert dut.is_miss() == True, "Should be miss"
        assert dut.is_cache_input_ready() == False, "Should not be ready during miss"

        latency = random.randint(0,20)
        for _ in range(latency):
            await FallingEdge(dut.clock())
        dut.kill(valid=1)


        await FallingEdge(dut.clock())

        dut.kill(valid=0)
        assert dut.is_cache_input_ready() == True, "Should be ready after kill request"
        assert dut.is_cache_output_valid() == False, "Output should not be valid after kill request"

        await FallingEdge(dut.clock())
        await FallingEdge(dut.clock())


@cocotb.test()
async def instruction_cache_kill_hit_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    model_dram = SimpleDRAM(sizeKB=1<<10)
    model_dram.randomize()
    dut = InstructionCacheDut(dut, model_dram)  # Extend dut

    await FallingEdge(dut.clock())


    dut.read(address=0x1234, valid=1)
    await FallingEdge(dut.clock())
    dut.read(address=0, valid=0)

    for _ in range(100):    # allocate into cache (for hit)
        dut.update_dram()
        await FallingEdge(dut.clock())

    dut.read(address=0x1234, valid=1)   # confirm hit
    await FallingEdge(dut.clock())
    dut.read(address=0, valid=0)
    assert dut.is_hit() == True, "Should be hit"
    assert dut.is_cache_input_ready() == True, "Should be ready after hit"

    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


    # test kill + hit
    dut.read(address=0x1234, valid=1)
    dut.kill(valid=1)

    await FallingEdge(dut.clock())
    dut.read(address=0x1234, valid=0)
    dut.kill(valid=0)
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    assert dut.is_cache_input_ready() == True, "Should be ready after kill request"
    assert dut.is_cache_output_valid() == False, "Output should not be valid after kill request"

    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())

    """
    for _ in range(1000):


        dut.read(address=0x1234, valid=1)
        await FallingEdge(dut.clock())
        dut.read(address=0, valid=0)

        assert dut.is_miss() == True, "Should be miss"
        assert dut.is_cache_input_ready() == False, "Should not be ready during miss"

        latency = random.randint(0,20)
        for _ in range(latency):
            await FallingEdge(dut.clock())
        dut.kill(valid=1)


        await FallingEdge(dut.clock())

        dut.kill(valid=0)
        assert dut.is_cache_input_ready() == True, "Should be ready after kill request"
        assert dut.is_cache_output_valid() == False, "Output should not be valid after kill request"

        await FallingEdge(dut.clock())
        await FallingEdge(dut.clock())
    """




@cocotb.test()
async def instruction_cache_fuzz(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    model_dram = SimpleDRAM(sizeKB=1<<10)
    model_dram.randomize()
    dut = InstructionCacheDut(dut, model_dram)  # Extend dut
    cache_model = InstructionCache(sets=SETS, ways=WAYS, blockSize=BLOCKSIZE, fetchWidth=FETCHWIDTH, dram = model_dram)

    request_queue        = []

    model_responses      = []
    model_cache_states   = []
    
    dut_responses        = []
    dut_cache_states     = []

    addrBits        = 20
    byteOffsetBits  = 5
    setBits         = 6
    tagBits         = addrBits-byteOffsetBits-setBits

    batchSize=1000
    for _ in range(batchSize):
        tag = random.randint(0,(1<<tagBits)-1)
        set = random.randint(0,63)
        byteOffset = random.randint(0, 31)
        addr = generateAddr(tag, set, byteOffset, sets=64, blockSize=32)
        request_queue.append(addr)

    while(request_queue):

        await FallingEdge(dut.clock())

        # deassert signals
        dut.read(address=0, valid=0)
        dut.write_from_dram(data=0, valid=0)

        if(dut.is_cache_output_valid()):   # store cache resp
            dut_responses.append(dut.get_cache_data())
            dut_cache_states.append(dut.get_cache_state())

        if(dut.is_cache_input_ready()): # place inputs
            curr_addr = request_queue.pop(0)
            #print(f"Requested read from {hex(curr_addr)}: Tag: {getTag(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} Set: {getSet(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} BO:{getByteOffset(curr_addr, blockSize=BLOCKSIZE)}")
            dut.read(address=curr_addr, valid=1)
            model_responses.append(cache_model.read(address=curr_addr)[0])
            model_cache_states.append(cache_model.get_cache_state())

        dut.update_dram()
        await RisingEdge(dut.clock())


        
        if(model_responses and dut_responses):  # perform checks
            model_out = model_responses.pop(0)
            dut_out = dut_responses.pop(0)
            #print(f"{model_out[0][0]} == {dut_out[0][0]}")
            #print(f"{model_out[0][1]} == {dut_out[0][1]}")
            #print(f"{model_out[0][2]} == {dut_out[0][2]}")
            #print(f"{model_out[0][3]} == {dut_out[0][3]}")
            assert model_out[0][0]  == dut_out[0][0] , "data mismatch"
            assert model_out[0][1]  == dut_out[0][1] , "data mismatch"
            assert model_out[0][2]  == dut_out[0][2] , "data mismatch"
            assert model_out[0][3]  == dut_out[0][3] , "data mismatch"

            assert model_out[1][0]  == dut_out[1][0] , "valid mismatch"
            assert model_out[1][1]  == dut_out[1][1] , "valid mismatch"
            assert model_out[1][2]  == dut_out[1][2] , "valid mismatch"
            assert model_out[1][3]  == dut_out[1][3] , "valid mismatch"
            #print("Responses match")

            model_state = model_cache_states.pop(0)
            dut_state = dut_cache_states.pop(0)

            #print("\n")
            #for way in range(2):
                #for set in range(64):
                    #print(f"Model[{way}][{set}]={hex(model_state[way][set])}")
                    #print(f"Dut  [{way}][{set}]={hex(dut_state[way][set])}")

            assert compare_cache_states(model_state, dut_state), "Cache states diverge"
            #print("Cache states match")


@cocotb.test()
async def instruction_cache_from_set(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    model_dram = SimpleDRAM(sizeKB=1<<10)
    model_dram.randomize()
    dut = InstructionCacheDut(dut, model_dram)  # Extend dut
    cache_model = InstructionCache(sets=SETS, ways=WAYS, blockSize=BLOCKSIZE, fetchWidth=FETCHWIDTH, dram = model_dram)

    set_size = 100
    request_set        = [0]*set_size

    model_responses      = []
    model_cache_states   = []
    
    dut_responses        = []
    dut_cache_states     = []

    addrBits        = 20
    byteOffsetBits  = 5
    setBits         = 6
    tagBits         = addrBits-byteOffsetBits-setBits

    batchSize=100000
    for i in range(set_size):
        tag = random.randint(0,(1<<tagBits)-1)
        set = random.randint(0,63)
        byteOffset = random.randint(0, 31)
        addr = generateAddr(tag, set, byteOffset, sets=64, blockSize=32)
        request_set[i]=addr

    for i in range(batchSize):
        await FallingEdge(dut.clock())

        dut.read(address=0, valid=0)
        dut.write_from_dram(data=0, valid=0)

        if(dut.is_cache_output_valid()):
            dut_responses.append(dut.get_cache_data())
            dut_cache_states.append(dut.get_cache_state())

        if(dut.is_cache_input_ready()):
            curr_addr = random.choice(request_set)
            #print(f"{i}: Requested read from {hex(curr_addr)}: Tag: {getTag(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} Set: {getSet(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} BO:{getByteOffset(curr_addr, blockSize=BLOCKSIZE)}")
            dut.read(address=curr_addr, valid=1)
            model_responses.append(cache_model.read(address=curr_addr)[0])
            model_cache_states.append(cache_model.get_cache_state())

        dut.update_dram()
        await RisingEdge(dut.clock())

        
        if(model_responses and dut_responses):  # perform checks
            model_out = model_responses.pop(0)
            dut_out = dut_responses.pop(0)
            #print(f"{model_out[0][0]} == {dut_out[0][0]}")
            #print(f"{model_out[0][1]} == {dut_out[0][1]}")
            #print(f"{model_out[0][2]} == {dut_out[0][2]}")
            #print(f"{model_out[0][3]} == {dut_out[0][3]}")
            assert model_out[0][0]  == dut_out[0][0] , "data mismatch"
            assert model_out[0][1]  == dut_out[0][1] , "data mismatch"
            assert model_out[0][2]  == dut_out[0][2] , "data mismatch"
            assert model_out[0][3]  == dut_out[0][3] , "data mismatch"

            assert model_out[1][0]  == dut_out[1][0] , "valid mismatch"
            assert model_out[1][1]  == dut_out[1][1] , "valid mismatch"
            assert model_out[1][2]  == dut_out[1][2] , "valid mismatch"
            assert model_out[1][3]  == dut_out[1][3] , "valid mismatch"
            #print("Responses match")

            model_state = model_cache_states.pop(0)
            dut_state = dut_cache_states.pop(0)

            #print("\n")
            #for way in range(2):
                #for set in range(64):
                    #print(f"Model[{way}][{set}]={hex(model_state[way][set])}")
                    #print(f"Dut  [{way}][{set}]={hex(dut_state[way][set])}")

            assert compare_cache_states(model_state, dut_state), "Cache states diverge"
            #print("Cache states match")








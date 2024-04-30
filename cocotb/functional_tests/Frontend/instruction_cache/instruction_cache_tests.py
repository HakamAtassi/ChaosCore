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
async def instruction_cache_pipelined_hits(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut_dram = SimpleDRAM(sizeKB=1<<10)
    dut = InstructionCacheDut(dut, DRAM=dut_dram)  # Extend dut

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await dut.cpu_read(address=0x1234, valid=1)
    await RisingEdge(dut.clock())
    await dut.cpu_read(address=0, valid=0)

    await FallingEdge(dut.clock())
    # Assertions
    assert dut.cpu_read_valid() == 0, "Read should miss"
    assert dut.cpu_read_ready() == 0, "should not be ready after miss"
    assert dut.cpu_dram_ready() == 1, "should be ready for dram after miss"
    # Assertions end
    await RisingEdge(dut.clock())

    dut.dram_resp(data=0xdeadbeef, valid=1)
    await RisingEdge(dut.clock())
    dut.dram_resp(data=0x0, valid=0)
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    await dut.cpu_read(address=0x1234, valid=1)
    await RisingEdge(dut.clock())
    await dut.cpu_read(address=0x1234, valid=1)
    await RisingEdge(dut.clock())
    await dut.cpu_read(address=0x1234, valid=1)
    await RisingEdge(dut.clock())




@cocotb.test()
async def instruction_cache_fuzz(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    ###########################
    # Test stategy (Fuzzing)  #
    ###########################

    # initialize dram models#
    # generate address and data
    # write to both model and dut dram model instances
    
    #

    # generate & queue N read requests
    # Send request to model & queue response.
    # Send request to dut. On valid, queue response. 

    #

    # Compare queue elements
    # Compare cache states


    batch_size = 1000     # generate tests in batches of 10_000. Run for as long as you want.

    request_queue   = []

    model_responses     = []
    model_read_sets     = []
    model_hit_way       = []
    model_cache_states   = []
    
    dut_responses       = []
    dut_read_sets       = []
    dut_hit_way         = []
    dut_cache_states     = []

    addrBits        = 20
    byteOffsetBits  = 5
    setBits         = 6
    tagBits         = addrBits-byteOffsetBits-setBits


    # initialize memories
    # both memories are identical
    print(f"Starting ram init...")
    model_dram = SimpleDRAM(sizeKB=1<<10)
    dut_dram = SimpleDRAM(sizeKB=1<<10)

    model_dram.randomize()
    #dut_dram.randomize()


    #model_dram.print()
    #model_dram.print()


    dut = InstructionCacheDut(dut, model_dram)  # Extend dut
    cache_model = InstructionCache(sets=SETS, ways=WAYS, blockSize=BLOCKSIZE, fetchWidth=FETCHWIDTH, dram = model_dram)
    
    for _ in range(10):
        # generate requests
        for sample in range(batch_size):
            tag = random.randint(0,(1<<tagBits)-1)
            set = random.randint(0,63)
            byteOffset = random.randint(0, 31)
            addr = generateAddr(tag, set, byteOffset, sets=64, blockSize=32)

            request_queue.append(addr)

        # Generate responses

        print(f"Ram Init complete...")
        await RisingEdge(dut.clock())
        while request_queue:
            sleep(0)

            if(dut.cpu_read_valid()):
                dut_response = dut.cpu_read_resp() # queue from dut
                dut_responses.append(dut_response)

                dut_cache_state = dut.get_cache_state()
                dut_cache_states.append(dut_cache_state)


            if(dut.cpu_read_ready()):   # Place new inputs
                curr_addr=request_queue.pop(0)              # dequeue from requests
                #print(f"Requested read from {hex(curr_addr)}: Tag: {getTag(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} Set: {getSet(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} BO:{getByteOffset(curr_addr, blockSize=BLOCKSIZE)}")
                await dut.cpu_request_read(curr_addr)             # send to dut
                
                model_response=cache_model.read(curr_addr)     # send to model
                model_cache_state=cache_model.get_cache_state()  # send to model
                #model_hit_way=cache_model.get_hit_way(curr_addr)[0]      # send to model
                #model_read_set=cache_model.get_read_set(curr_addr)[0]     # send to model

                

                model_responses.append(model_response[0])            # read + queue from model
                model_cache_states.append(model_cache_state)
                #model_hit_way.append(model_hit_way)
                #model_read_set.append(model_read_set)

            if(model_responses and dut_responses):  # perform checks
                # compare responses (interface)

                # compare read sets
                # compare hit way
                # compare hit way

                # compare cache state

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
                print("Responses match")

                model_state = model_cache_states.pop(0)
                dut_state = dut_cache_states.pop(0)

                #print("\n")
                #for way in range(2):
                    #for set in range(64):
                        #print(f"Model[{way}][{set}]={hex(model_state[way][set])}")
                        #print(f"Dut  [{way}][{set}]={hex(dut_state[way][set])}")

                assert compare_cache_states(model_state, dut_state), "Cache states diverge"
                print("Cache states match")

            await RisingEdge(dut.clock())
            await dut.dram_cycle()


@cocotb.test()
async def instruction_cache_from_sets(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    ###########################
    # Test stategy (Fuzzing)  #
    ###########################

    # initialize dram models#
    # generate address and data
    # write to both model and dut dram model instances
    
    #

    # generate & queue N read requests
    # Send request to model & queue response.
    # Send request to dut. On valid, queue response. 

    #

    # Compare queue elements
    # Compare cache states


    batch_size = 1000     # generate tests in batches of 10_000. Run for as long as you want.

    request_queue   = []

    model_responses     = []
    model_read_sets     = []
    model_hit_way       = []
    model_cache_states   = []
    
    dut_responses       = []
    dut_read_sets       = []
    dut_hit_way         = []
    dut_cache_states     = []

    addrBits        = 20
    byteOffsetBits  = 5
    setBits         = 6
    tagBits         = addrBits-byteOffsetBits-setBits


    # initialize memories
    # both memories are identical
    print(f"Starting ram init...")
    model_dram = SimpleDRAM(sizeKB=1<<10)
    dut_dram = SimpleDRAM(sizeKB=1<<10)
    print(f"Ram Init complete...")

    model_dram.randomize()
    #dut_dram.randomize()


    #model_dram.print()
    #model_dram.print()


    dut = InstructionCacheDut(dut, model_dram)  # Extend dut
    cache_model = InstructionCache(sets=SETS, ways=WAYS, blockSize=BLOCKSIZE, fetchWidth=FETCHWIDTH, dram = model_dram)
    
    

    for _ in range(10):
        # generate requests
        address_set={}
        for sample in range(10):
            tag = random.randint(0, (1 << tagBits) - 1)
            set = random.randint(0, 63)
            byteOffset = random.randint(0, 31)
            addr = generateAddr(tag, set, byteOffset, sets=64, blockSize=32)

            # Insert the address into the address_set dictionary with appropriate keys
            address_set[sample] = addr


        # Generate responses

        await RisingEdge(dut.clock())
        for _ in range(1000):
            sleep(0)

            if(dut.cpu_read_valid()):
                dut_response = dut.cpu_read_resp() # queue from dut
                dut_responses.append(dut_response)

                dut_cache_state = dut.get_cache_state()
                dut_cache_states.append(dut_cache_state)
                

            if(dut.cpu_read_ready()):   # Place new inputs
                curr_addr = random.choice(address_set)
                #curr_addr=request_queue.pop(0)              # dequeue from requests
                print(f"Requested read from {hex(curr_addr)}: Tag: {getTag(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} Set: {getSet(curr_addr, sets=SETS, blockSize=BLOCKSIZE)} BO:{getByteOffset(curr_addr, blockSize=BLOCKSIZE)}")
                await dut.cpu_request_read(curr_addr)             # send to dut
                
                model_response=cache_model.read(curr_addr)     # send to model
                model_cache_state=cache_model.get_cache_state()  # send to model

                model_responses.append(model_response[0])            # read + queue from model
                model_cache_states.append(model_cache_state)

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

            await RisingEdge(dut.clock())
            await dut.dram_cycle()



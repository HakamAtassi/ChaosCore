import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *
from model_utils import *
from RASDut import *
from RAS import *

@cocotb.test()
async def simple_call_ret_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = RASDut(dut)

    dut.push(addr=0x1, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0x0, valid=0)


    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    dut.pop(valid=0)

    assert dut.get_output()[0] == 0x1

    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


@cocotb.test()
async def simple_call_ret_test2(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = RASDut(dut)

    dut.push(addr=0x1, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0x2, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0x3, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0, valid=0)

    dut.pop(valid=1)
    assert dut.get_output()[0] == 0x3
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x2
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x1
    dut.pop(valid=0)

    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


@cocotb.test()
async def simple_call_ret_test3(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = RASDut(dut)

    dut.push(addr=0x1, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0x2, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0x3, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0, valid=0)

    dut.pop(valid=1)
    assert dut.get_output()[0] == 0x3
    await FallingEdge(dut.clock())
    dut.pop(valid=0)


    dut.push(addr=0x5, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0, valid=0)

    dut.push(addr=0x6, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0, valid=0)

    dut.pop(valid=1)
    assert dut.get_output()[0] == 0x6
    await FallingEdge(dut.clock())
    dut.pop(valid=0)

    dut.pop(valid=1)
    assert dut.get_output()[0] == 0x5
    await FallingEdge(dut.clock())
    dut.pop(valid=0)

    dut.pop(valid=1)
    assert dut.get_output()[0] == 0x2
    await FallingEdge(dut.clock())
    dut.pop(valid=0)

    dut.pop(valid=1)
    assert dut.get_output()[0] == 0x1
    await FallingEdge(dut.clock())
    dut.pop(valid=0)

    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


@cocotb.test()
async def call_ret_directed(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)


    # extend dut
    dut = RASDut(dut)


    dut.push(addr=0x1, valid=1)
    await FallingEdge(dut.clock())

    dut.push(addr=0x2, valid=1)
    await FallingEdge(dut.clock())

    dut.push(addr=0x3, valid=1)
    await FallingEdge(dut.clock())

    dut.push(addr=0x4, valid=1)
    await FallingEdge(dut.clock())

    dut.push(addr=0x5, valid=1)
    await FallingEdge(dut.clock())
    dut.push(addr=0, valid=0)

    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x5
    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    dut.pop(valid=1)
    await FallingEdge(dut.clock())


    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


@cocotb.test()
async def call_ret_fuzzing(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)


    # extend dut
    dut = RASDut(dut)
    model = RAS(entries=128)

    batch_size = 10000
    request_queue = []

    dut_responses = []
    model_responses = []

    for _ in range(batch_size):
        operation = random.choice(["call", "ret"])
        call_address = random.randint(0, (1<<32)-1)
        valid = random.randint(0, 1)    # mix in some idle cycles as well

        request_queue.append((operation, call_address, valid))


    while(request_queue):
        await FallingEdge(dut.clock())
        dut.push(call_address, valid=0)
        dut.pop(valid=0)

        request = request_queue.pop(0)

        operation = request[0]
        call_address = request[1]
        valid = request[2]

        model_responses.append(model.tos())
        dut_responses.append(dut.get_output()[0])   # sample dut after it updates

        if(valid):
            if(operation=="call"):
                dut.push(call_address, valid=1)
                model.push(call_address)
            elif(operation=="ret"):
                dut.pop(valid=1)
                model.pop()


        if(model_responses and dut_responses):
            assert model_responses.pop(0) == dut_responses.pop(0), "responses dont match"


        await RisingEdge(dut.clock())
        
@cocotb.test()
async def call_ret_revert_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = RASDut(dut)

    dut.push(addr=0x1, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x1
    assert dut.get_TOS_reg() == 0x0
    assert dut.get_NEXT_reg() == 0x1
    dut.push(addr=0x0, valid=0)

    dut.push(addr=0x2, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x2
    assert dut.get_TOS_reg() == 0x1
    assert dut.get_NEXT_reg() == 0x2
    dut.push(addr=0x0, valid=0)

    dut.push(addr=0x3, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x3
    assert dut.get_TOS_reg() == 0x2
    assert dut.get_NEXT_reg() == 0x3
    dut.push(addr=0x0, valid=0)

    dut.push(addr=0x4, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x4
    assert dut.get_TOS_reg() == 0x3
    assert dut.get_NEXT_reg() == 0x4
    dut.push(addr=0x0, valid=0)

    dut.push(addr=0x5, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x5
    assert dut.get_TOS_reg() == 0x4
    assert dut.get_NEXT_reg() == 0x5
    dut.push(addr=0x0, valid=0)


    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x4
    assert dut.get_TOS_reg() == 0x3
    assert dut.get_NEXT_reg() == 0x5
    dut.pop(valid=0)

    dut.push(addr=0x6, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x6
    assert dut.get_TOS_reg() == 0x5
    assert dut.get_NEXT_reg() == 0x6
    dut.push(addr=0x0, valid=0)

    ## test revert

    dut.revert(TOS=1, NEXT=2, valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x2
    assert dut.get_TOS_reg() == 0x1
    assert dut.get_NEXT_reg() == 0x2
    dut.revert(TOS=1, NEXT=2, valid=0)

    dut.pop(valid=1)
    await FallingEdge(dut.clock())
    assert dut.get_output()[0] == 0x1
    assert dut.get_TOS_reg() == 0x0
    assert dut.get_NEXT_reg() == 0x2
    dut.pop(valid=0)
    

    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
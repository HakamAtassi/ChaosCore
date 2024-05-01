import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *
from Gshare import *
from model_utils import *

from GshareDut import *

@cocotb.test()
async def gshare_fuzzing(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    GHR_width=16

    # extend dut
    dut = GshareDut(dut, GHR_width=GHR_width)
    gshare_model = PHT(GHR_width=GHR_width)



    # request queues
    batch_size = 100000
    commit_queue = []
    predict_queue = []

    dut_response_queue = []
    model_response_queue = []

    set_size = 250
    addr_set = [0]*set_size

    for i in range(set_size):
        addr_set[i] = random.randint(0, (1<<32)-1)



    for _ in range(batch_size):
        commit_valid = random.randint(0,1)
        predict_valid = random.randint(0,1)

        commit_addr  = random.choice(addr_set)
        predict_addr = random.choice(addr_set)

        commit_GHR = random.randint(0,(1<<GHR_width)-1)
        predict_GHR = random.randint(0,(1<<GHR_width)-1)

        commit_resolved_direction = random.randint(0, 1)

        commit_queue.append((commit_addr, commit_GHR, commit_resolved_direction,commit_valid))
        predict_queue.append((predict_addr, predict_GHR, predict_valid))


    while(commit_queue or predict_queue):

        await FallingEdge(dut.clock())
        
        dut.predict(PC=0, GHR=0, valid=0)
        dut.commit(PC=0, GHR=0, resolved_direction=0, valid=0)

        commit_request = commit_queue.pop(0)
        predict_request = predict_queue.pop(0)

        # Place inputs
        dut.commit(PC=commit_request[0], GHR=commit_request[1], resolved_direction=commit_request[2], valid=commit_request[3])
        dut.predict(PC=predict_request[0], GHR=predict_request[1], valid=predict_request[2])

        if(commit_request[3]):
            gshare_model.commit(PC=commit_request[0], GHR=commit_request[1], resolved_direction=commit_request[2])   # commit always processed first (write first...)

        if(predict_request[2]):
            model_response=gshare_model.predict(PC=predict_request[0], GHR=predict_request[1])
            model_response_queue.append(model_response)

        # Buffer outputs
        if(dut.is_output_valid()):
            dut_response_queue.append(dut.get_output())

        if(dut_response_queue and model_response_queue):
            model_response = model_response_queue.pop(0)
            dut_response = dut_response_queue.pop(0)
            #print(f"{dut_response} == {model_response}")
            assert model_response == dut_response


        await RisingEdge(dut.clock())



    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


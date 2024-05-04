import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *
from model_utils import *
from BPDut import *
from BP import *


@cocotb.test()
async def simple_typical_0(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = BPDut(dut)
    model = BP(RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4)

    # Try miss

    dut.predict(0xdeadbeef, valid=1)
    await FallingEdge(dut.clock())
    dut.predict(0xdeadbeef, valid=0)

    assert dut.is_prediction_valid() == 1, "prediction not valid"
    model_BTB, model_T_NT, model_GHR = model.predict(address=0xdeadbeef)
    dut_BTB, dut_T_NT, dut_GHR=dut.get_prediction()

    model_BTB == dut_BTB
    model_T_NT == dut_T_NT
    model_GHR == dut_GHR

    # try commit
    dut.commit(PC=0xdeadbeef, GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0010, misprediction=0, TOS=0, NEXT=0, valid=1)     # request prediction
    model.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0011, NEXT=0, TOS=0, misprediction=0)

    await FallingEdge(dut.clock())

    # type predict
    dut.predict(0xdeadbeef, valid=1)
    await FallingEdge(dut.clock())
    dut.predict(0xdeadbeef, valid=0)

    assert dut.is_prediction_valid() == 1, "prediction not valid"
    model_BTB, model_T_NT, model_GHR = model.predict(address = 0xdeadbeef)
    dut_BTB, dut_T_NT, dut_GHR=dut.get_prediction()

    model_BTB == dut_BTB
    model_T_NT == dut_T_NT
    model_GHR == dut_GHR

    # try commit (2)
    dut.commit(PC=0xdeadbe42, GHR=0, T_NT=1, target=0xdeadc042, br_type=0b00, br_mask=0b0010, misprediction=0, TOS=0, NEXT=0, valid=1)     # request prediction
    model.commit(address=0xdeadbe42, commit_GHR=0, T_NT=1, target=0xdeadc042, br_type=0b00, br_mask=0b0011, NEXT=0, TOS=0, misprediction=0)

    await FallingEdge(dut.clock())

    # type predict
    dut.predict(0xdeadbe42, valid=1)
    await FallingEdge(dut.clock())
    dut.predict(0xdeadbe42, valid=0)

    assert dut.is_prediction_valid() == 1, "prediction not valid"
    model_BTB, model_T_NT, model_GHR = model.predict(address = 0xdeadbe42)
    dut_BTB, dut_T_NT, dut_GHR=dut.get_prediction()

    model_BTB == dut_BTB
    model_T_NT == dut_T_NT
    model_GHR == dut_GHR



    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())

@cocotb.test()
async def test_RAS_revert(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = BPDut(dut)
    model = BP(RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4)

    # Try miss


    # commit some stuff
    dut.commit(PC=0xdeadbeef, GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0010, misprediction=0, TOS=0, NEXT=0, valid=1)     # request prediction
    model.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0011, NEXT=0, TOS=0, misprediction=0)
    await FallingEdge(dut.clock())
    dut.commit(PC=0xdeadbeef, GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0010, misprediction=0, TOS=0, NEXT=0, valid=1)     # request prediction
    model.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0011, NEXT=0, TOS=0, misprediction=0)
    await FallingEdge(dut.clock())
    dut.commit(PC=0xdeadbeef, GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0010, misprediction=0, TOS=0, NEXT=0, valid=1)     # request prediction
    model.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0011, NEXT=0, TOS=0, misprediction=0)
    await FallingEdge(dut.clock())

    # update RAS
    dut.RAS_update(call=1, ret=0, call_addr=0xdead0001)
    model.RAS_update(call=1, ret=0, call_addr=0xdead0001)
    await FallingEdge(dut.clock())

    dut.RAS_update(call=1, ret=0, call_addr=0xdead0002)
    model.RAS_update(call=1, ret=0, call_addr=0xdead0002)
    await FallingEdge(dut.clock())

    dut.RAS_update(call=1, ret=0, call_addr=0xdead0003)
    model.RAS_update(call=1, ret=0, call_addr=0xdead0003)
    await FallingEdge(dut.clock())

    dut.RAS_update(call=1, ret=0, call_addr=0xdead0004)
    model.RAS_update(call=1, ret=0, call_addr=0xdead0004)
    await FallingEdge(dut.clock())
    dut.RAS_update(call=0, ret=0, call_addr=0)

    await FallingEdge(dut.clock())

    assert model.RAS_read() == dut.get_RAS()


    dut.RAS_update(call=0, ret=1, call_addr=0)
    model.RAS_update(call=0, ret=1, call_addr=0)
    await FallingEdge(dut.clock())
    dut.RAS_update(call=0, ret=0, call_addr=0)

    assert model.RAS_read() == dut.get_RAS()

    model.commit(address=0xdead0000, commit_GHR=0xff42, T_NT=0, target=0xdeadffff, br_type=0b00, br_mask=0b0001, NEXT=1, TOS=0,  misprediction=1)
    dut.commit(PC=0xdead0000, GHR=0xff42, T_NT=0, target=0xdeadffff, br_type=0b00, br_mask=0b0001, NEXT=1, TOS=0,  misprediction=1, valid=1)
    await FallingEdge(dut.clock())
    dut.commit(PC=0xdead0000, GHR=0xff42, T_NT=0, target=0xdeadffff, br_type=0b00, br_mask=0b0001, NEXT=1, TOS=0,  misprediction=1, valid=0)
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


    dut.predict(0xdead0000, valid=1)
    await FallingEdge(dut.clock())
    dut.predict(0xdead0000, valid=0)

    assert dut.is_prediction_valid() == 1, "prediction not valid"
    model_BTB, model_T_NT, model_GHR = model.predict(address = 0xdead0000)
    dut_BTB, dut_T_NT, dut_GHR=dut.get_prediction()

    model_BTB == dut_BTB
    model_T_NT == dut_T_NT
    model_GHR == dut_GHR


    assert model.RAS_read() == dut.get_RAS()
    assert model.RAS_read()[2] == 0xdead0001


@cocotb.test()
async def BP_fuzzing(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = BPDut(dut)
    model = BP(RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4)

    address_set = generate_address_set(100)

    request_queue = []
    batch_size = 1000

    for _ in range(batch_size):
        commit = generate_random_commit_request(address_set)
        revert = generate_random_revert_request(address_set)
        predict = generate_random_predict_request(address_set)
        RAS_update = generate_random_RAS_update(address_set)

        ## TODO: randomize...

        request = (commit, revert, predict, RAS_update)
        request_queue.append(request)


    dut_predictions = []
    dut_RAS_outputs = []

    model_predictions = []
    model_RAS_outputs = []

    dut.set_prediction_read(1)

    while(request_queue):
        await FallingEdge(dut.clock())

        # read new outputs
        if(dut.is_prediction_valid()):  # read prediction output
            dut_predictions.append(dut.get_prediction())

        if(True):   # read RAS output
            dut_RAS_outputs.append(dut.get_RAS())

        (commit_request, revert_request, predict_request, RAS_update) = request_queue.pop(0)

        # place new inputs
        if(dut.is_commit_ready()):
            dut.commit(*commit_request)
            if(commit_request[-1]):
                model.commit(*commit_request[:-1])

        if(dut.is_predict_ready()):
            dut.predict(*predict_request)

        if(predict_request[-1]):
            model_predictions.append(model.predict(*predict_request[:-1]))
                
                
        if(dut.is_revert_ready()):
            pass
            #dut.RAS_revert(*revert_request)

        if(True):   # RAS update ready
            pass
            #dut.RAS_update(*RAS_update)

        if(model_predictions and dut_predictions):
            
            #model_response = model_predictions.pop(0)
            model_BTB_resp, model_T_NT_resp, model_GHR_resp = model_predictions.pop(0)
            dut_BTB_resp, dut_T_NT_resp, dut_GHR_resp = dut_predictions.pop(0)

            #print(f"{model_BTB_resp} {dut_BTB_resp}")
            assert model_BTB_resp == dut_BTB_resp, "BTB responses do not match"
            assert model_T_NT_resp == dut_T_NT_resp, "T_NT responses do not match"
            #assert model_GHR_resp.read() == dut_GHR_resp, "GHR responses do not match"

        await RisingEdge(dut.clock())

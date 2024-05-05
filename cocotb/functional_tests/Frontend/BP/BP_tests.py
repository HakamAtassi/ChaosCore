import sys
import random
import cocotb.triggers
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
    batch_size = 10000

    for _ in range(batch_size):
        commit_msg = commit(generate_random_commit_request(address_set))
        revert_msg = revert(generate_random_revert_request(address_set))
        predict_msg = predict(generate_random_predict_request(address_set))
        RAS_update_msg = RAS_update(generate_random_RAS_update(address_set))


        request = (commit_msg, revert_msg, predict_msg, RAS_update_msg)
        request_queue.append(request)


    dut_predictions = []
    dut_RAS_outputs = []
    dut_PHT_states = []

    model_predictions = []
    model_PHT_states = []
    model_RAS_outputs = []

    dut.set_prediction_read(1)  # would normally be driven by !full of an output queue...

    while(request_queue):
        await RisingEdge(dut.clock())


        # write phase
        (commit_request, revert_request, predict_request, RAS_update_request) = request_queue.pop(0)

        # place new inputs
        dut.commit(commit_request)
        dut.predict(predict_request)
        dut.RAS_revert(revert_request)


        await cocotb.triggers.ReadOnly()
        # read phase



        # read new outputs
        if(dut.is_prediction_valid() == 1):  # read prediction output
            dut_predictions.append(dut.get_prediction())
            #dut_PHT_states.append(dut.get_PHT_state())

        if(True):   # read RAS output
            dut_RAS_outputs.append(dut.get_RAS())

                
        model_result = model.send_all_requests(commit_request, revert_request, predict_request, RAS_update_request)
        if(model_result):
            model_predictions.append(model_result)
            #model_PHT_states.append(model.get_PHT_state())

        if(model_predictions and dut_predictions):
            model_BTB_resp, model_T_NT_resp, model_GHR_resp = model_predictions.pop(0)
            dut_BTB_resp, dut_T_NT_resp, dut_GHR_resp = dut_predictions.pop(0)

            #await Timer(1, units="ns")
            #print(f"{model_BTB_resp} {dut_BTB_resp}")
            #print(f"{hex(model_GHR_resp)} {hex(dut_GHR_resp)}")
            #print(hex(model_GHR_resp.read()))
            #dut_PHT_state = dut_PHT_states.pop(0)
            #model_PHT_state = model_PHT_states.pop(0)

            try:
                assert model_BTB_resp == dut_BTB_resp, "BTB responses do not match"
                assert model_T_NT_resp == dut_T_NT_resp, "T_NT responses do not match"
                #assert dut_PHT_state == model_PHT_state, "PHT states diverge"
                assert model_GHR_resp == dut_GHR_resp, "GHR responses do not match"
            except:
                await RisingEdge(dut.clock())
                assert False


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())




    A = dut.get_PHT_state()
    B = model.get_PHT_state()


    assert A == B
import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from FTQ_dut import *

@cocotb.test()
async def reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def buffer_prediction(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    #place prediction
    prediction = generateNullPrediction()

    prediction["input_valid"] = 1
    prediction["entry_valid"] = 1
    prediction["instruction_PC"] = 0xdeadbee0
    prediction["is_misprediction"] = 0
    prediction["predicted_expected_PC"] = 0xc0ffe0
    prediction["GHR"] = 0x1
    prediction["NEXT"] = 0x2
    prediction["TOS"] = 0x3

    dut.send_frontend_prediction(prediction)

    await RisingEdge(dut.clock())

    dut.send_frontend_prediction(generateNullPrediction())
    await ReadOnly()

    assert dut.get_back_pointer() == 1
    assert dut.get_front_pointer() == 0

    #dut.print_FTQ()

    assert dut.get_FTQ_entry(0)["valid"] == 0x1
    assert dut.get_FTQ_entry(0)["instruction_PC"] == 0xdeadbee0
    assert dut.get_FTQ_entry(0)["is_misprediction"] == 0x0
    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xc0ffe0
    assert dut.get_FTQ_entry(0)["GHR"] == 0x1
    assert dut.get_FTQ_entry(0)["NEXT"] == 0x2
    assert dut.get_FTQ_entry(0)["TOS"] == 0x3

    await RisingEdge(dut.clock())

@cocotb.test()
async def buffer_predictions(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    for i in range(16):
        instruction_PC         =   random.randint(0, (1<<32)-1)
        predicted_expected_PC   =   random.randint(0, (1<<32)-1)
        GHR                     =   random.randint(0, (1<<16)-1)
        NEXT                    =   random.randint(0, (1<<7)-1)
        TOS                     =   random.randint(0, (1<<7)-1)

        #place prediction
        prediction = generateNullPrediction()

        prediction["input_valid"] = 1
        prediction["entry_valid"] = 1
        prediction["instruction_PC"] = instruction_PC
        prediction["is_misprediction"] = 0
        prediction["predicted_expected_PC"] = predicted_expected_PC
        prediction["GHR"] = GHR
        prediction["NEXT"] = NEXT
        prediction["TOS"] = TOS

        dut.send_frontend_prediction(prediction)

        await RisingEdge(dut.clock())

        await ReadOnly()

        assert dut.get_back_pointer() == i+1
        assert dut.get_front_pointer() == 0

        dut.print_FTQ()

        #assert dut.get_outputs()["ready"] == 1

        assert dut.get_FTQ_entry(i)["valid"] == 0x1
        assert dut.get_FTQ_entry(i)["instruction_PC"] == instruction_PC
        assert dut.get_FTQ_entry(i)["is_misprediction"] == 0x0
        assert dut.get_FTQ_entry(i)["predicted_expected_PC"] == predicted_expected_PC
        assert dut.get_FTQ_entry(i)["GHR"] == GHR
        assert dut.get_FTQ_entry(i)["NEXT"] == NEXT
        assert dut.get_FTQ_entry(i)["TOS"] == TOS

        #await RisingEdge(dut.clock())
        await ReadWrite()

    assert dut.get_outputs()["ready"] == 0




@cocotb.test()
async def FU_broadcast(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    #place prediction
    prediction = generateNullPrediction()

    prediction["input_valid"]               = 1
    prediction["entry_valid"]               = 1
    prediction["instruction_PC"]            = 0xdeadbee0
    prediction["is_misprediction"]          = 0
    prediction["predicted_expected_PC"]     = 0xc0ffe0
    prediction["GHR"]                       = 0x1
    prediction["NEXT"]                      = 0x2
    prediction["TOS"]                       = 0x3

    dut.send_frontend_prediction(prediction)

    await RisingEdge(dut.clock())

    dut.send_frontend_prediction(generateNullPrediction())
    await ReadOnly()

    assert dut.get_back_pointer() == 1
    assert dut.get_front_pointer() == 0

    #dut.print_FTQ()

    assert dut.get_FTQ_entry(0)["valid"] == 0x1
    assert dut.get_FTQ_entry(0)["instruction_PC"] == 0xdeadbee0
    assert dut.get_FTQ_entry(0)["is_misprediction"] == 0x0
    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xc0ffe0
    assert dut.get_FTQ_entry(0)["GHR"] == 0x1
    assert dut.get_FTQ_entry(0)["NEXT"] == 0x2
    assert dut.get_FTQ_entry(0)["TOS"] == 0x3

    await RisingEdge(dut.clock())

    await ReadOnly()

    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xc0ffe0    # frontend thinks 0xdeadbee0 jumps to 0xc0ffe0

    # Send FU broadcast

    await RisingEdge(dut.clock())

    FU_result = generateNullFUInput()

    FU_result["instruction_PC"]             =   0xdeadbee0
    FU_result["branch_taken"]               =   0
    FU_result["target_address"]             =   0xface
    FU_result["branch_valid"]               =   0

    dut.send_FU_result(FU_result)

    await RisingEdge(dut.clock())

    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_entry(0)["valid"] == 0x1
    assert dut.get_FTQ_entry(0)["instruction_PC"] == 0xdeadbee0
    assert dut.get_FTQ_entry(0)["is_misprediction"] == 0x1
    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xface  # store actual address
    assert dut.get_FTQ_entry(0)["GHR"] == 0x1
    assert dut.get_FTQ_entry(0)["NEXT"] == 0x2
    assert dut.get_FTQ_entry(0)["TOS"] == 0x3



@cocotb.test()
async def broadcast_commit(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    #place prediction
    prediction = generateNullPrediction()

    prediction["input_valid"]               = 1
    prediction["entry_valid"]               = 1
    prediction["instruction_PC"]            = 0xdeadbee0
    prediction["is_misprediction"]          = 0
    prediction["predicted_expected_PC"]     = 0xc0ffe0
    prediction["GHR"]                       = 0x1
    prediction["NEXT"]                      = 0x2
    prediction["TOS"]                       = 0x3

    dut.send_frontend_prediction(prediction)

    await RisingEdge(dut.clock())

    dut.send_frontend_prediction(generateNullPrediction())
    await ReadOnly()

    assert dut.get_back_pointer() == 1
    assert dut.get_front_pointer() == 0

    #dut.print_FTQ()

    assert dut.get_FTQ_entry(0)["valid"] == 0x1
    assert dut.get_FTQ_entry(0)["instruction_PC"] == 0xdeadbee0
    assert dut.get_FTQ_entry(0)["is_misprediction"] == 0x0
    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xc0ffe0
    assert dut.get_FTQ_entry(0)["GHR"] == 0x1
    assert dut.get_FTQ_entry(0)["NEXT"] == 0x2
    assert dut.get_FTQ_entry(0)["TOS"] == 0x3

    await RisingEdge(dut.clock())

    await ReadOnly()

    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xc0ffe0    # frontend thinks 0xdeadbee0 jumps to 0xc0ffe0

    # Send FU broadcast

    await RisingEdge(dut.clock())

    FU_result = generateNullFUInput()

    FU_result["instruction_PC"]             =   0xdeadbee0
    FU_result["branch_taken"]               =   0
    FU_result["target_address"]             =   0xface
    FU_result["branch_valid"]               =   0

    dut.send_FU_result(FU_result)

    await RisingEdge(dut.clock())
    dut.send_FU_result(generateNullFUInput())

    await ReadOnly()


    assert dut.get_FTQ_entry(0)["valid"] == 0x1
    assert dut.get_FTQ_entry(0)["instruction_PC"] == 0xdeadbee0
    assert dut.get_FTQ_entry(0)["is_misprediction"] == 0x1
    assert dut.get_FTQ_entry(0)["predicted_expected_PC"] == 0xface  # store actual address
    assert dut.get_FTQ_entry(0)["GHR"] == 0x1
    assert dut.get_FTQ_entry(0)["NEXT"] == 0x2
    assert dut.get_FTQ_entry(0)["TOS"] == 0x3

    await RisingEdge(dut.clock())

    # Perform ROB commit

    commit_inputs = generateNullFUInput()

    commit_inputs["is_branch"]             =   1
    commit_inputs["valid"]                 =   1

    dut.send_commit(commit_inputs)

    await ReadOnly()



    assert dut.get_outputs()["valid"]            ==   1
    assert dut.get_outputs()["is_misprediction"] ==   1


    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_FTQ()


    assert dut.get_back_pointer() == 1
    assert dut.get_front_pointer() == 1


# TODO:

# test the timing of various things (pointer update, clearing, etc...)
# test counter rollover
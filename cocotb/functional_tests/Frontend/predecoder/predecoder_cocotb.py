import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from predecoder_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_addi_passthrough(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)


    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.get_final_fetch_packet()["valid"] == 1
    dut.get_final_fetch_packet()["packet_index"] == 0

    dut.get_final_fetch_packet()["instruction_valid"][0] == 1
    dut.get_final_fetch_packet()["instruction_valid"][1] == 1
    dut.get_final_fetch_packet()["instruction_valid"][2] == 1
    dut.get_final_fetch_packet()["instruction_valid"][3] == 1

    dut.get_final_fetch_packet()["packet_index"][0] == 0
    dut.get_final_fetch_packet()["packet_index"][1] == 1
    dut.get_final_fetch_packet()["packet_index"][2] == 2
    dut.get_final_fetch_packet()["packet_index"][3] == 3

    dut.print_final_fetch_packet()

@cocotb.test()
async def test_addi_with_prediction_invalid(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   0

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)


    await RisingEdge(dut.clock())
    await ReadOnly()


    dut.get_final_fetch_packet()["valid"] == 0
    dut.get_final_fetch_packet()["packet_index"] == 0


    dut.print_final_fetch_packet()

@cocotb.test()
async def test_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.set_final_fetch_packet_ready(1)
    dut.set_FTQ_ready(1)

    await ReadOnly()

    assert dut.get_fetch_packet_ready() == 1
    assert dut.get_prediction_ready() == 1

    await RisingEdge(dut.clock())

    dut.set_final_fetch_packet_ready(0)
    dut.set_FTQ_ready(1)

    await ReadOnly()

    assert dut.get_fetch_packet_ready() == 0
    assert dut.get_prediction_ready() == 0

    await RisingEdge(dut.clock())

    dut.set_final_fetch_packet_ready(1)
    dut.set_FTQ_ready(0)

    await ReadOnly()

    assert dut.get_fetch_packet_ready() == 0
    assert dut.get_prediction_ready() == 0



@cocotb.test()
async def test_nonbranch_PC_invalidation(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x13   # JAL to 0xc0de
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    # pass the expected PC fetch packet
    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0xdeadbee0         # Pass expected address

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1


    await ReadOnly()

    # check what predecoder is expecting...
    assert dut.get_expected_address() == 0x10

    await RisingEdge(dut.clock())
    await ReadOnly()
    
    dut.get_revert()["valid"] == 1  # following PC packet was expected. Revert should be invalid
    dut.get_revert()["PC"] == 0x10  # following PC packet was expected. Revert should be invalid



@cocotb.test()
async def test_nonbranch_PC_validation(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module


    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x13   # JAL to 0xc0de
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()
    assert dut.get_expected_address() == 0x0
    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0x10
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()
    assert dut.get_expected_address() == 0x10
    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0x20
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()
    assert dut.get_expected_address() == 0x20
    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0x30
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()
    assert dut.get_expected_address() == 0x30
    await RisingEdge(dut.clock())
    
@cocotb.test()
async def test_RAS_update(dut):
    "Should have expected address of 0xc0de0 due to RET"
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await ReadOnly()
    assert dut.get_expected_address() == 0x0    # first expected address is 0x0
    assert dut.get_revert()["valid"] == 0
    await ReadWrite()

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()
    RAS_input            = generate_null_RAS()

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x00008067   # JALR x0, 0(x1) / RET
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    RAS_input["ret_addr"]                   =   0xc0de0

    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    dut.write_RAS(RAS_input)


    await ReadOnly()
    assert dut.get_expected_address() == 0x0    # first expected address is 0x0
    assert dut.get_revert()["valid"] == 0
    await RisingEdge(dut.clock())

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0xc0de0

    fetch_packet_input["instruction"][0]    =   0x13   # JALR x0, 0(x1) / RET
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    dut.write_RAS(RAS_input)


    await ReadOnly()
    assert dut.get_revert()["valid"] == 0
    assert dut.get_expected_address() == 0xc0de0


    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0xc0df0
    
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    dut.write_RAS(RAS_input)

    await ReadOnly()
    assert dut.get_expected_address() == 0xc0df0
    assert dut.get_revert()["valid"] == 0
    await RisingEdge(dut.clock())


# Test FTQ, RAS, and prediction correction

@cocotb.test()
async def test_JAL_then_correct(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x0de0c06f   # JAL to 0xc0de
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    # pass the expected PC fetch packet
    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0xc0de         # Pass expected address

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1


    await ReadOnly()

    # check what predecoder is expecting...
    assert dut.get_expected_address() == 0xc0de

    await RisingEdge(dut.clock())
    await ReadOnly()
    
    dut.get_revert()["valid"] == 0  # following PC packet was expected. Revert should be invalid



@cocotb.test()
async def test_JAL_then_incorrect(dut):
    """Test that when a JAL takes place, it sets the expected address accordingly and invalidates the following invalid PC fetch packet"""
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x0de0c06f   # JAL to 0xc0de
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    # pass the expected PC fetch packet
    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0xbeef         # Pass unexpected address

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    await ReadOnly()

    assert dut.get_expected_address() == 0xc0de

    await RisingEdge(dut.clock())
    await ReadOnly()
    
    dut.get_revert()["valid"] == 1
    dut.get_revert()["PC"] == 0xc0de

    #dut.get_final_fetch_packet()["valid"] == 0
    dut.get_final_fetch_packet()["valid"] == [0,0,0,0]
    dut.get_final_fetch_packet()["instruction_valid"] == [0,0,0,0]


@cocotb.test()
async def test_JAL_output_invalidation(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x0de0c06f   # JAL to 0xc0de
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.get_final_fetch_packet()["valid"] = [1,1,1,1]
    dut.get_final_fetch_packet()["instruction_valid"] = [1,0,0,0]
    dut.print_final_fetch_packet()



@cocotb.test()
async def test_JALR_output_invalidation(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0

    fetch_packet_input["instruction"][0]    =   0x00008067   # RET
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      


    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.get_final_fetch_packet()["valid"] = [1,1,1,1]
    dut.get_final_fetch_packet()["instruction_valid"] = [1,0,0,0]
    dut.print_final_fetch_packet()


# test RAS update
@cocotb.test()
async def test_call_RAS_update(dut):

    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module



    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()


    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very usefull test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x0de0c0ef   # CALL (JAL x1, 0xc0de)
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0xc0de

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    prediction_input["valid"] =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()

    assert dut.get_expected_address() == 0xc0de
    assert dut.get_revert()["valid"] == 0
    assert dut.get_RAS_read()["is_call"]   == 1
    assert dut.get_RAS_read()["call_addr"] == 0x0

    assert dut.get_final_fetch_packet()["instruction_valid"] == [1,0,0,0]

@cocotb.test()
async def test_FTQ_JAL(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x0de0c0ef   # CALL (JAL x1, 0xc0de)
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    prediction_input["valid"] = 1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0xc0de
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await ReadOnly()

    assert dut.get_expected_address() == 0xc0de
    assert dut.get_revert()["valid"] == 0

    dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0xc0de
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==

@cocotb.test()
async def test_FTQ_JAL_many_branches(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x0de0c0ef   # CALL (JAL x1, 0xc0de)
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x6ef0b0ef   # CALL (again)
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    prediction_input["valid"] = 1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0xc0de
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await ReadOnly()

    assert dut.get_expected_address() == 0xc0de
    assert dut.get_revert()["valid"] == 0

    assert dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0xc0de  # Should only consider first JAL
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==


@cocotb.test()
async def test_FTQ_JAL_second_instruction(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x13   # CALL (JAL x1, 0xc0de)
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x6e10b0ef   # CALL (again)
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    prediction_input["valid"] = 1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0xbee4
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await ReadOnly()

    assert dut.get_expected_address() == 0xbee4
    assert dut.get_revert()["valid"] == 0

    assert dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0xbee4  # Should only consider first JAL
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==

@cocotb.test()
async def test_FTQ_JAL_first_instruction_invalid(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x0de0c0ef   # CALL (JAL x1, 0xc0de)
    fetch_packet_input["valid_bits"][0]     =   0      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x6e10b0ef   # CALL (again)
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    prediction_input["valid"] = 1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0xbee4
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await ReadOnly()

    assert dut.get_expected_address() == 0xbee4
    assert dut.get_revert()["valid"] == 0

    assert dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0xbee4  # Should only consider first JAL
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==

@cocotb.test()
async def test_FTQ_BEQ(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x7e000fe3  # BEQ x0, x0, 0xc0d0
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    fetch_packet_input["fetch_PC"]  =   0xFFE
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()

    assert dut.get_expected_address() == 0xFFE
    assert dut.get_revert()["valid"] == 0

    assert dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0xFFE  # Should only consider first JAL
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==


@cocotb.test()
async def test_FTQ_BEQ_second_instruction(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x7e000fe3  # BEQ x0, x0, 0xFFE
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    fetch_packet_input["fetch_PC"]  =   0xFFE+4
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()

    assert dut.get_expected_address() == 0xFFE+4
    assert dut.get_revert()["valid"] == 0

    assert dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0xFFE+4  # Should only consider first JAL
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==



@cocotb.test()
async def test_FTQ_BEQ_NT(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x7e000fe3   # NOP
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13  # BEQ x0, x0, 0xFFE
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   0

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    fetch_packet_input["fetch_PC"]  =   0x10
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)
    await ReadOnly()

    assert dut.get_expected_address() == 0x10
    assert dut.get_revert()["valid"] == 0

    assert dut.get_FTQ_read()["valid"] == 1

    assert dut.get_FTQ_read()["fetch_PC"] ==  0x0
    assert dut.get_FTQ_read()["is_misprediction"] == 0
    assert dut.get_FTQ_read()["predicted_PC"] == 0x10
    #assert dut.get_FTQ_read()["GHR"] ==
    #assert dut.get_FTQ_read()["NEXT"] ==
    #assert dut.get_FTQ_read()["TOS"] ==
    #assert dut.get_FTQ_read()["RAT_IDX"] ==


# FIXME: Add resolved_PC test they should default to the next address if no branches are taken


@cocotb.test()
async def test_BEQ_GHR(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x7e000fe3  # BEQ x0, x0, 0xFFE 
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13  # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    fetch_packet_input["fetch_PC"]  =   0x10
    dut.write_fetch_packet()
    dut.write_prediction()
    await ReadOnly()

    assert dut.get_GHR() == 1


@cocotb.test()
async def test_BEQ_GHR_many(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x7e000fe3  # BEQ x0, x0, 0xFFE 
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13  # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    fetch_packet_input["fetch_PC"]  =   0x10
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)


    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_GHR() == 0b11


@cocotb.test()
async def test_FTQ_BEQ_GHR_many_2(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x7e000fe3  # BEQ x0, x0, 0xFFE 
    fetch_packet_input["valid_bits"][0]     =   1      # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13  # NOP
    fetch_packet_input["valid_bits"][1]     =   1      # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    fetch_packet_input["fetch_PC"]  =   0x10
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    fetch_packet_input["fetch_PC"]  =   0x20

    prediction_input["T_NT"]      =   0
    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_GHR() == 0b110

@cocotb.test()
async def test_FTQ_BEQ_GHR_non_branch(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x13    # NOP
    fetch_packet_input["valid_bits"][0]     =   1       # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13    # NOP
    fetch_packet_input["valid_bits"][1]     =   1       # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   1

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    await ReadOnly()

    assert dut.get_GHR() == 0b00


@cocotb.test()
async def test_FTQ_BEQ_GHR_RET(dut):
    """Check that JALs request an FTQ write due to FTQ"""
    # Each FTQ push should store the address of the taken branch (if any) 
    # and/or information indicating that none of the branches were taken
    # Naturally, each fetch packet can only have 1 valid taken branch
    await cocotb.start(generateClock(dut)) 

    dut = predecoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    fetch_packet_input   = generate_null_fetch_packet()
    prediction_input     = generate_null_prediction()

    # fetch packet
    fetch_packet_input["valid"]     =   1
    fetch_packet_input["fetch_PC"]  =   0x0     # This is not a very useful test because the call address being written to the RAS is 0 since its happening straight out of reset

    fetch_packet_input["instruction"][0]    =   0x00008067   # RET
    fetch_packet_input["valid_bits"][0]     =   1       # Valid
    fetch_packet_input["packet_index"][0]   =   0      

    fetch_packet_input["instruction"][1]    =   0x13    # NOP
    fetch_packet_input["valid_bits"][1]     =   1       # Valid
    fetch_packet_input["packet_index"][1]   =   1      

    fetch_packet_input["instruction"][2]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][2]     =   1      # Valid
    fetch_packet_input["packet_index"][2]   =   2      

    fetch_packet_input["instruction"][3]    =   0x13   # NOP
    fetch_packet_input["valid_bits"][3]     =   1      # Valid
    fetch_packet_input["packet_index"][3]   =   3      

    # prediction
    prediction_input["valid"]     =   1
    prediction_input["hit"]       =   1
    prediction_input["target"]    =   0xFFE # IMPORTANT! The BTB stores target FETCH PACKET addresses. So whatever address the BTB returns, the instruciton offset must be added to it. 
    prediction_input["br_type"]   =   0
    prediction_input["br_mask"]   =   0
    prediction_input["GHR"]       =   0
    prediction_input["T_NT"]      =   0

    dut.write_fetch_packet(fetch_packet_input)
    dut.write_prediction(prediction_input)

    await RisingEdge(dut.clock())

    await ReadOnly()

    assert dut.get_GHR() == 0b01
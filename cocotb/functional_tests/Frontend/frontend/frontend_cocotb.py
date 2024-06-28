import sys
import random
import numpy as np
from cocotb.clock import Clock
import os
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from frontend_dut import *
from SimpleDRAM import SimpleDRAM

@cocotb.test()
async def test_reset(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_decoder_out_addi(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module


    dut.set_backend_ready(1)
    dut.set_FTQ_ready(1)


    await dut.wait_decoder_outputs_valid()
    await ReadOnly()

    dut.print_renamed_decoded_fetch_packet()


    #await dut.wait_decoder_outputs_valid() # this is broken
    await dut.update()
    await dut.update()
    await dut.update()
    await dut.update()

    assert dut.get_decoder_outputs()["RD"]                      == [1,2,3,4]
    assert dut.get_decoder_outputs()["RD_valid"]                == [1,1,1,1]
    assert dut.get_decoder_outputs()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_decoder_outputs()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_decoder_outputs()["packet_index"]            == [0,1,2,3]
    assert dut.get_decoder_outputs()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_decoder_outputs()["RS1"]                     == [0,0,0,0]
    assert dut.get_decoder_outputs()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_decoder_outputs()["is_load"]                 == [0,0,0,0]
    assert dut.get_decoder_outputs()["is_store"]                == [0,0,0,0]


    await dut.update()
    await dut.update()




    dut.print_renamed_decoded_fetch_packet()

    assert dut.get_decoder_outputs()["RD"]                      == [5,6,7,8]
    assert dut.get_decoder_outputs()["RD_valid"]                == [1,1,1,1]
    assert dut.get_decoder_outputs()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_decoder_outputs()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_decoder_outputs()["packet_index"]            == [0,1,2,3]
    assert dut.get_decoder_outputs()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_decoder_outputs()["RS1"]                     == [0,0,0,0]
    assert dut.get_decoder_outputs()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_decoder_outputs()["is_load"]                 == [0,0,0,0]
    assert dut.get_decoder_outputs()["is_store"]                == [0,0,0,0]



@cocotb.test()
async def test_rename_out_addi(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_backend_ready(1)
    dut.set_FTQ_ready(1)

    
    for _ in range(100):
        ReadOnly()
        if(dut.get_instruction_Q_outputs()["valid"] == 1):
            break
        await dut.update()

    # check inputs into rename



    assert dut.get_instruction_Q_outputs()["RD"]                      == [1,2,3,4]
    assert dut.get_instruction_Q_outputs()["RD_valid"]                == [1,1,1,1]
    assert dut.get_instruction_Q_outputs()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_instruction_Q_outputs()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_instruction_Q_outputs()["packet_index"]            == [0,1,2,3]
    assert dut.get_instruction_Q_outputs()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_instruction_Q_outputs()["RS1"]                     == [0,0,0,0]
    assert dut.get_instruction_Q_outputs()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_instruction_Q_outputs()["is_load"]                 == [0,0,0,0]
    assert dut.get_instruction_Q_outputs()["is_store"]                == [0,0,0,0]

    await dut.update()  # wait for rename to complete

    # check rename outputs
    assert dut.get_renamed_decoded_fetch_packet()["RD"]                      == [0,1,2,3]
    assert dut.get_renamed_decoded_fetch_packet()["RD_valid"]                == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["packet_index"]            == [0,1,2,3]
    assert dut.get_renamed_decoded_fetch_packet()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_renamed_decoded_fetch_packet()["RS1"]                     == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["is_load"]                 == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["is_store"]                == [0,0,0,0]


    # check new inputs into rename
    for _ in range(100):
        ReadOnly()
        if(dut.get_instruction_Q_outputs()["valid"] == 1):
            break
        await dut.update()


    assert dut.get_instruction_Q_outputs()["RD"]                      == [5,6,7,8]
    assert dut.get_instruction_Q_outputs()["RD_valid"]                == [1,1,1,1]
    assert dut.get_instruction_Q_outputs()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_instruction_Q_outputs()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_instruction_Q_outputs()["packet_index"]            == [0,1,2,3]
    assert dut.get_instruction_Q_outputs()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_instruction_Q_outputs()["RS1"]                     == [0,0,0,0]
    assert dut.get_instruction_Q_outputs()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_instruction_Q_outputs()["is_load"]                 == [0,0,0,0]
    assert dut.get_instruction_Q_outputs()["is_store"]                == [0,0,0,0]


    await dut.update()  # wait for rename to complete

    # check rename outputs
    assert dut.get_renamed_decoded_fetch_packet()["RD"]                      == [4,5,6,7]
    assert dut.get_renamed_decoded_fetch_packet()["RD_valid"]                == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["packet_index"]            == [0,1,2,3]
    assert dut.get_renamed_decoded_fetch_packet()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_renamed_decoded_fetch_packet()["RS1"]                     == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["is_load"]                 == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["is_store"]                == [0,0,0,0]


@cocotb.test()
async def test_frontend_outputs(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_backend_ready(1)
    dut.set_FTQ_ready(1)

    
    for _ in range(100):
        ReadOnly()
        if(dut.get_renamed_decoded_fetch_packet()["fetch_packet_valid"] == 1):
            break
        await dut.update()


    assert dut.get_renamed_decoded_fetch_packet()["RD"]                      == [0,1,2,3]
    assert dut.get_renamed_decoded_fetch_packet()["RD_valid"]                == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["needs_ALU"]               == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["needs_branch_unit"]       == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["packet_index"]            == [0,1,2,3]
    assert dut.get_renamed_decoded_fetch_packet()["IMMEDIATE"]               == [1,1,1,1]

    assert dut.get_renamed_decoded_fetch_packet()["RS1"]                     == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["RS1_valid"]               == [1,1,1,1]
    assert dut.get_renamed_decoded_fetch_packet()["is_load"]                 == [0,0,0,0]
    assert dut.get_renamed_decoded_fetch_packet()["is_store"]                == [0,0,0,0]


@cocotb.test()
async def test_mispredictions(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/beq.bin")
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 

    dut = frontend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    dut.set_backend_ready(1)
    dut.set_FTQ_ready(1)

    
    for _ in range(20):
        await dut.update()

    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit_inputs()
    commit_inputs["valid"] = 1
    commit_inputs["fetch_PC"] = 0x10
    commit_inputs["T_NT"] = 0
    commit_inputs["ROB_index"] = 1
    commit_inputs["br_type"] = 0
    commit_inputs["fetch_packet_index"] = 0
    commit_inputs["is_misprediction"] = 1
    commit_inputs["expected_PC"] = 0
    commit_inputs["GHR"] = 0
    commit_inputs["TOS"] = 0
    commit_inputs["NEXT"] = 0
    commit_inputs["RAT_index"] = 0

    dut.write_commit(data = commit_inputs)
    await RisingEdge(dut.clock())
    await ReadWrite()
    dut.write_commit()

    for _ in range(10):
        await dut.update()

    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit_inputs()
    commit_inputs["valid"] = 1
    commit_inputs["fetch_PC"] = 0x10
    commit_inputs["T_NT"] = 0
    commit_inputs["ROB_index"] = 1
    commit_inputs["br_type"] = 0
    commit_inputs["fetch_packet_index"] = 0
    commit_inputs["is_misprediction"] = 1
    commit_inputs["expected_PC"] = 0
    commit_inputs["GHR"] = 0
    commit_inputs["TOS"] = 0
    commit_inputs["NEXT"] = 0
    commit_inputs["RAT_index"] = 0

    dut.write_commit(data = commit_inputs)
    await RisingEdge(dut.clock())
    await ReadWrite()
    dut.write_commit()

    for _ in range(100):
        await dut.update()


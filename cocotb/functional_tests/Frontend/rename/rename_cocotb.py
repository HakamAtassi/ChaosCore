import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from rename import *
from agents import rename_agent

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_rename_1_RD(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class

    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    rename_inputs = generate_null_decoded_fetch_packet()

    dut.dut.io_renamed_decoded_fetch_packet_ready = 1

    rename_inputs["valid"] = 1
    rename_inputs["fetch_PC"] = 0
    rename_inputs["ready"] = 1

    rename_inputs["RS1_ready"]          = [0, 0, 0, 0]
    rename_inputs["RS2_ready"]          = [0, 0, 0, 0]
    rename_inputs["RD"]                 = [2, 0, 0, 0]
    rename_inputs["RD_valid"]           = [1, 0, 0, 0]
    rename_inputs["RS1"]                = [0, 0, 0, 0]
    rename_inputs["RS1_valid"]          = [0, 0, 0, 0]
    rename_inputs["RS2"]                = [0, 0, 0, 0]
    rename_inputs["RS2_valid"]          = [0, 0, 0, 0]
    rename_inputs["IMM"]                = [0, 0, 0, 0]
    rename_inputs["FUNCT3"]             = [0, 0, 0, 0]
    rename_inputs["packet_index"]       = [0, 0, 0, 0]
    rename_inputs["ROB_index"]          = [0, 0, 0, 0]
    rename_inputs["instructionType"]    = [0, 0, 0, 0]
    rename_inputs["portID"]             = [0, 0, 0, 0]
    rename_inputs["RS_type"]            = [0, 0, 0, 0]
    rename_inputs["needs_ALU"]          = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"]  = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"]         = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"]           = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"]           = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"]          = [0, 0, 0, 0]
    rename_inputs["is_load"]            = [0, 0, 0, 0]
    rename_inputs["is_store"]           = [0, 0, 0, 0]
    rename_inputs["valid_bits"]         = [1, 0, 0, 0]


    dut.write_decoded_fetch_packet(rename_inputs)

    await RisingEdge(dut.clock())

    await ReadOnly()
    assert dut.rename_renamed_decoded_fetch_packet()["RD"][0] == 1

    await RisingEdge(dut.clock())

    await ReadOnly()

@cocotb.test()
async def test_simple_fuzz(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    dut_agent = rename_agent(dut)



    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    
    
    # set ouputs to ready
    dut.dut.io_renamed_decoded_fetch_packet_ready = 1


    decoded_fetch_packet = generate_null_decoded_fetch_packet()
    commit               = generate_null_commit()
    flush                = 0
    FU_outputs           = generate_null_FU_outputs()


    commit_pool         = []

    dut_agent.start()

    for _ in range(400):
        # randomize fetch packet #
        # random RS1, RS2, RS2 value
        # random RD valid, RS1 valid, RS2 valid
        # random valid fetch packet
        # random instruction valid
        # random is_branch
        decoded_fetch_packet["valid"]                   = random.randint(0,1)
        decoded_fetch_packet["RD"]                      = [random.randint(0,31) for _ in range(4)]
        decoded_fetch_packet["RS1"]                     = [random.randint(0,31) for _ in range(4)]
        decoded_fetch_packet["RS2"]                     = [random.randint(0,31) for _ in range(4)]
        decoded_fetch_packet["RD_valid"]                = [random.randint(0,1) for _ in range(4)]
        decoded_fetch_packet["RS1_valid"]               = [random.randint(0,1) for _ in range(4)]
        decoded_fetch_packet["RS2_valid"]               = [random.randint(0,1) for _ in range(4)]

        #decoded_fetch_packet["needs_branch_unit"]       = [random.randint(0,1) for _ in range(4)]
        decoded_fetch_packet["valid_bits"]              = [random.randint(0,1) for _ in range(4)]



        # randomize commit/flush #
        # random commit valid
        # random is_misprediction
        # random RAT index
        # random free list front pointer
        commit["valid"]                     =   random.randint(0, 1)
        commit["is_misprediction"]          =   0
        commit["RAT_index"]                 =   0
        commit["free_list_front_pointer"]   =   0
        commit["RD"]                        =  [random.randint(0,63) for _ in range(4)]
        commit["RD_valid"]                  =  [random.randint(0,1)  for _ in range(4)]
        
        flush = commit["valid"] & commit["is_misprediction"]

        # randomize FU_input #
        # random RD
        # random RD valid
        # random result valid
        FU_outputs["valid"]                 = [random.randint(0,1) for _ in range(4)]
        FU_outputs["RD_valid"]              = [random.randint(0,1) for _ in range(4)]
        FU_outputs["RD"]                    = [random.randint(0,63) for _ in range(4)]





        dut.write_decoded_fetch_packet(decoded_fetch_packet)
        dut.write_commit(commit)
        dut.write_flush(flush)
        dut.write_FU_outputs(FU_outputs)


        await RisingEdge(dut.clock())

    dut_agent.stop()


    assert False





@cocotb.test()
async def test_fuzz_while_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = rename_dut(dut)  # wrap dut with helper class
    dut_agent = rename_agent(dut)



    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    
    
    # set ouputs to ready
    dut.dut.io_renamed_decoded_fetch_packet_ready = 1


    decoded_fetch_packet = generate_null_decoded_fetch_packet()
    commit               = generate_null_commit()
    flush                = 0
    FU_outputs           = generate_null_FU_outputs()

    for _ in range(400):
        # randomize fetch packet #
        # random RS1, RS2, RS2 value
        # random RD valid, RS1 valid, RS2 valid
        # random valid fetch packet
        # random instruction valid
        # random is_branch
        decoded_fetch_packet["valid"]                   = random.randint(0,1)
        decoded_fetch_packet["RD"]                      = [random.randint(0,31) for _ in range(4)]
        decoded_fetch_packet["RS1"]                     = [random.randint(0,31) for _ in range(4)]
        decoded_fetch_packet["RS2"]                     = [random.randint(0,31) for _ in range(4)]
        decoded_fetch_packet["RD_valid"]                = [random.randint(0,1) for _ in range(4)]
        decoded_fetch_packet["RS1_valid"]               = [random.randint(0,1) for _ in range(4)]
        decoded_fetch_packet["RS2_valid"]               = [random.randint(0,1) for _ in range(4)]

        decoded_fetch_packet["needs_branch_unit"]       = [random.randint(0,1) for _ in range(4)]
        decoded_fetch_packet["valid_bits"]              = [random.randint(0,1) for _ in range(4)]




        # randomize commit/flush #
        # random commit valid
        # random is_misprediction
        # random RAT index
        # random free list front pointer
        commit["valid"]                     =   random.randint(0, 1)
        commit["is_misprediction"]          =   random.randint(0, 1)
        commit["RAT_index"]                 =   random.randint(0, 1)
        commit["free_list_front_pointer"]   =   random.randint(0, 63)
        commit["RD"]                        =  [random.randint(0,63) for _ in range(4)]
        commit["RD_valid"]                  =  [random.randint(0,1)  for _ in range(4)]
        
        flush = commit["valid"] & commit["is_misprediction"]

        # randomize FU_input #
        # random RD
        # random RD valid
        # random result valid
        FU_outputs["valid"]                 = [random.randint(0,1) for _ in range(4)]
        FU_outputs["RD_valid"]              = [random.randint(0,1) for _ in range(4)]
        FU_outputs["RD"]                    = [random.randint(0,63) for _ in range(4)]





        dut.write_decoded_fetch_packet(decoded_fetch_packet)
        dut.write_commit(commit)
        dut.write_flush(flush)
        dut.write_FU_outputs(FU_outputs)


        await RisingEdge(dut.clock())




        pass


# test back pressure
#...
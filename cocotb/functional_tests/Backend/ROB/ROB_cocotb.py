import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from ROB_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_print_ROB(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.print_ROB(0)
    dut.print_ROB(1)
    dut.print_ROB(2)
    dut.print_ROB(3)


@cocotb.test()
async def test_write_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 0, 0, 0]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 0, 0, 0]
    allocate_input["IS_STORE"]                     =  [1, 0, 0, 0]

    dut.write_allocate(allocate_input)

    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_ROB(0)
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1


@cocotb.test()
async def test_write_4(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    dut.write_allocate(allocate_input)

    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_ROB(0)
    dut.print_ROB(1)
    dut.print_ROB(2)
    dut.print_ROB(3)
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1



@cocotb.test()
async def test_many_writes(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())


    await ReadOnly()

    dut.print_ROB(0)
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1


    assert dut.get_shared_mem()["fetch_PC"][1] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][1] == 1

    assert dut.get_ROB_entry()[0]["is_load"][1] == 1
    assert dut.get_ROB_entry()[0]["is_store"][1] == 1

    assert dut.get_ROB_entry()[1]["is_load"][1] == 1
    assert dut.get_ROB_entry()[1]["is_store"][1] == 1

    assert dut.get_ROB_entry()[2]["is_load"][1] == 1
    assert dut.get_ROB_entry()[2]["is_store"][1] == 1

    assert dut.get_ROB_entry()[3]["is_load"][1] == 1
    assert dut.get_ROB_entry()[3]["is_store"][1] == 1

    assert dut.get_shared_mem()["fetch_PC"][2] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][2] == 1

    assert dut.get_ROB_entry()[0]["is_load"][2] == 1
    assert dut.get_ROB_entry()[0]["is_store"][2] == 1

    assert dut.get_ROB_entry()[1]["is_load"][2] == 1
    assert dut.get_ROB_entry()[1]["is_store"][2] == 1

    assert dut.get_ROB_entry()[2]["is_load"][2] == 1
    assert dut.get_ROB_entry()[2]["is_store"][2] == 1

    assert dut.get_ROB_entry()[3]["is_load"][2] == 1
    assert dut.get_ROB_entry()[3]["is_store"][2] == 1



@cocotb.test()
async def test_many_full(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    assert dut.get_allocate_ready() == 1

    for i in range(64):
        dut.write_allocate(allocate_input)
        await RisingEdge(dut.clock())

    await ReadOnly()

    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1

    assert dut.get_shared_mem()["fetch_PC"][63] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][63] == 1

    assert dut.get_ROB_entry()[0]["is_load"][63] == 1
    assert dut.get_ROB_entry()[0]["is_store"][63] == 1

    assert dut.get_ROB_entry()[1]["is_load"][63] == 1
    assert dut.get_ROB_entry()[1]["is_store"][63] == 1

    assert dut.get_ROB_entry()[2]["is_load"][63] == 1
    assert dut.get_ROB_entry()[2]["is_store"][63] == 1

    assert dut.get_ROB_entry()[3]["is_load"][63] == 1
    assert dut.get_ROB_entry()[3]["is_store"][63] == 1

    assert dut.get_allocate_ready() == 0


@cocotb.test()
async def test_FU_all_valid(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    assert dut.get_allocate_ready() == 1

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"] = [1, 1, 1, 1]
    FU_inputs["RD"] = [0, 0, 0, 0]
    FU_inputs["RD_data"] = [0, 0, 0, 0]
    FU_inputs["RD_valid"] = [0, 0, 0, 0]
    FU_inputs["instruction_PC"] = [0, 0, 0, 0]
    FU_inputs["branch_taken"] = [0, 0, 0, 0]
    FU_inputs["target_address"] = [0, 0, 0, 0]
    FU_inputs["branch_valid"] = [0, 0, 0, 0]
    FU_inputs["ROB_index"] = [0, 0, 0, 0]
    FU_inputs["fetch_packet_index"] = [0, 1, 2, 3]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.print_ROB(1)

    assert dut.get_WB_mem()[0]["busy"][0] == 1
    assert dut.get_WB_mem()[1]["busy"][0] == 1
    assert dut.get_WB_mem()[2]["busy"][0] == 1
    assert dut.get_WB_mem()[3]["busy"][0] == 1


    assert dut.get_allocate_ready() == 1


@cocotb.test()
async def test_FU_not_all_valid(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    assert dut.get_allocate_ready() == 1

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"] = [1, 0, 0, 1]
    FU_inputs["RD"] = [0, 0, 0, 0]
    FU_inputs["RD_data"] = [0, 0, 0, 0]
    FU_inputs["RD_valid"] = [0, 0, 0, 0]
    FU_inputs["instruction_PC"] = [0, 0, 0, 0]
    FU_inputs["branch_taken"] = [0, 0, 0, 0]
    FU_inputs["target_address"] = [0, 0, 0, 0]
    FU_inputs["branch_valid"] = [0, 0, 0, 0]
    FU_inputs["ROB_index"] = [0, 0, 0, 0]
    FU_inputs["fetch_packet_index"] = [0, 1, 2, 3]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.print_ROB(1)

    assert dut.get_WB_mem()[0]["busy"][0] == 1
    assert dut.get_WB_mem()[1]["busy"][0] == 0
    assert dut.get_WB_mem()[2]["busy"][0] == 0
    assert dut.get_WB_mem()[3]["busy"][0] == 1


    assert dut.get_allocate_ready() == 1


@cocotb.test()
async def test_FU_all_valid_diff_rows(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    assert dut.get_allocate_ready() == 1

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xdead
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1

    assert dut.get_shared_mem()["fetch_PC"][1] == 0xdead
    assert dut.get_shared_mem()["row_valid"][1] == 1

    assert dut.get_ROB_entry()[0]["is_load"][1] == 1
    assert dut.get_ROB_entry()[0]["is_store"][1] == 1

    assert dut.get_ROB_entry()[1]["is_load"][1] == 1
    assert dut.get_ROB_entry()[1]["is_store"][1] == 1

    assert dut.get_ROB_entry()[2]["is_load"][1] == 1
    assert dut.get_ROB_entry()[2]["is_store"][1] == 1

    assert dut.get_ROB_entry()[3]["is_load"][1] == 1
    assert dut.get_ROB_entry()[3]["is_store"][1] == 1

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"] = [1, 1, 1, 1]
    FU_inputs["RD"] = [0, 0, 0, 0]
    FU_inputs["RD_data"] = [0, 0, 0, 0]
    FU_inputs["RD_valid"] = [0, 0, 0, 0]
    FU_inputs["instruction_PC"] = [0, 0, 0, 0]
    FU_inputs["branch_taken"] = [0, 0, 0, 0]
    FU_inputs["target_address"] = [0, 0, 0, 0]
    FU_inputs["branch_valid"] = [0, 0, 0, 0]
    FU_inputs["ROB_index"] = [0, 1, 0, 1]
    FU_inputs["fetch_packet_index"] = [0, 0, 1, 1]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.print_ROB(1)

    assert dut.get_WB_mem()[0]["busy"][0] == 1
    assert dut.get_WB_mem()[1]["busy"][0] == 1
    assert dut.get_WB_mem()[2]["busy"][0] == 0
    assert dut.get_WB_mem()[3]["busy"][0] == 0

    assert dut.get_WB_mem()[0]["busy"][1] == 1
    assert dut.get_WB_mem()[1]["busy"][1] == 1
    assert dut.get_WB_mem()[2]["busy"][1] == 0
    assert dut.get_WB_mem()[3]["busy"][1] == 0

    assert dut.get_allocate_ready() == 1


@cocotb.test()
async def test_FU_all_valid_single_bank(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    assert dut.get_allocate_ready() == 1

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1

    assert dut.get_shared_mem()["fetch_PC"][1] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][1] == 1

    assert dut.get_ROB_entry()[0]["is_load"][1] == 1
    assert dut.get_ROB_entry()[0]["is_store"][1] == 1

    assert dut.get_ROB_entry()[1]["is_load"][1] == 1
    assert dut.get_ROB_entry()[1]["is_store"][1] == 1

    assert dut.get_ROB_entry()[2]["is_load"][1] == 1
    assert dut.get_ROB_entry()[2]["is_store"][1] == 1

    assert dut.get_ROB_entry()[3]["is_load"][1] == 1
    assert dut.get_ROB_entry()[3]["is_store"][1] == 1

    assert dut.get_shared_mem()["fetch_PC"][2] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][2] == 1

    assert dut.get_ROB_entry()[0]["is_load"][2] == 1
    assert dut.get_ROB_entry()[0]["is_store"][2] == 1

    assert dut.get_ROB_entry()[1]["is_load"][2] == 1
    assert dut.get_ROB_entry()[1]["is_store"][2] == 1

    assert dut.get_ROB_entry()[2]["is_load"][2] == 1
    assert dut.get_ROB_entry()[2]["is_store"][2] == 1

    assert dut.get_ROB_entry()[3]["is_load"][2] == 1
    assert dut.get_ROB_entry()[3]["is_store"][2] == 1

    assert dut.get_shared_mem()["fetch_PC"][3] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][3] == 1

    assert dut.get_ROB_entry()[0]["is_load"][3] == 1
    assert dut.get_ROB_entry()[0]["is_store"][3] == 1

    assert dut.get_ROB_entry()[1]["is_load"][3] == 1
    assert dut.get_ROB_entry()[1]["is_store"][3] == 1

    assert dut.get_ROB_entry()[2]["is_load"][3] == 1
    assert dut.get_ROB_entry()[2]["is_store"][3] == 1

    assert dut.get_ROB_entry()[3]["is_load"][3] == 1
    assert dut.get_ROB_entry()[3]["is_store"][3] == 1

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"] = [1, 1, 1, 1]
    FU_inputs["RD"] = [0, 0, 0, 0]
    FU_inputs["RD_data"] = [0, 0, 0, 0]
    FU_inputs["RD_valid"] = [0, 0, 0, 0]
    FU_inputs["instruction_PC"] = [0, 0, 0, 0]
    FU_inputs["branch_taken"] = [0, 0, 0, 0]
    FU_inputs["target_address"] = [0, 0, 0, 0]
    FU_inputs["branch_valid"] = [0, 0, 0, 0]
    FU_inputs["ROB_index"] = [0, 1, 2, 3]
    FU_inputs["fetch_packet_index"] = [0, 0, 0, 0]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.print_ROB(1)

    assert dut.get_WB_mem()[0]["busy"][0] == 1
    assert dut.get_WB_mem()[1]["busy"][0] == 0
    assert dut.get_WB_mem()[2]["busy"][0] == 0
    assert dut.get_WB_mem()[3]["busy"][0] == 0

    assert dut.get_WB_mem()[0]["busy"][1] == 1
    assert dut.get_WB_mem()[1]["busy"][1] == 0
    assert dut.get_WB_mem()[2]["busy"][1] == 0
    assert dut.get_WB_mem()[3]["busy"][1] == 0

    assert dut.get_WB_mem()[0]["busy"][2] == 1
    assert dut.get_WB_mem()[1]["busy"][2] == 0
    assert dut.get_WB_mem()[2]["busy"][2] == 0
    assert dut.get_WB_mem()[3]["busy"][2] == 0

    assert dut.get_WB_mem()[0]["busy"][3] == 1
    assert dut.get_WB_mem()[1]["busy"][3] == 0
    assert dut.get_WB_mem()[2]["busy"][3] == 0
    assert dut.get_WB_mem()[3]["busy"][3] == 0

    assert dut.get_allocate_ready() == 1






@cocotb.test()
async def test_basic_commit(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_input = generate_null_allocate()

    allocate_input["valid"]                        =  1
    allocate_input["fetch_PC"]                     =  0xfee0
    allocate_input["valid_bits"]                   =  [1, 1, 1, 1]
    allocate_input["ready_bits_RS1_ready"]         =  [0, 0, 0, 0]
    allocate_input["ready_bits_RS2_ready"]         =  [0, 0, 0, 0]
    allocate_input["RD"]                           =  [0, 0, 0, 0]
    allocate_input["RD_valid"]                     =  [0, 0, 0, 0]
    allocate_input["RS1"]                          =  [0, 0, 0, 0]
    allocate_input["RS1_valid"]                    =  [0, 0, 0, 0]
    allocate_input["RS2"]                          =  [0, 0, 0, 0]
    allocate_input["RS2_valid"]                    =  [0, 0, 0, 0]
    allocate_input["IMM"]                          =  [0, 0, 0, 0]
    allocate_input["FUNCT3"]                       =  [0, 0, 0, 0]
    allocate_input["packet_index"]                 =  [0, 0, 0, 0]
    allocate_input["ROB_index"]                    =  [0, 0, 0, 0]
    allocate_input["instructionType"]              =  [0, 0, 0, 0]
    allocate_input["portID"]                       =  [0, 0, 0, 0]
    allocate_input["RS_type"]                      =  [0, 0, 0, 0]
    allocate_input["needs_ALU"]                    =  [0, 0, 0, 0]
    allocate_input["needs_branch_unit"]            =  [0, 0, 0, 0]
    allocate_input["needs_CSRs"]                   =  [0, 0, 0, 0]
    allocate_input["SUBTRACT"]                     =  [0, 0, 0, 0]
    allocate_input["MULTIPLY"]                     =  [0, 0, 0, 0]
    allocate_input["IMMEDIATE"]                    =  [0, 0, 0, 0]
    allocate_input["IS_LOAD"]                      =  [1, 1, 1, 1]
    allocate_input["IS_STORE"]                     =  [1, 1, 1, 1]

    assert dut.get_allocate_ready() == 1

    dut.write_allocate(allocate_input)
    await RisingEdge(dut.clock())
    dut.write_allocate()
    await ReadOnly()
    
    assert dut.get_shared_mem()["fetch_PC"][0] == 0xfee0
    assert dut.get_shared_mem()["row_valid"][0] == 1

    assert dut.get_ROB_entry()[0]["is_load"][0] == 1
    assert dut.get_ROB_entry()[0]["is_store"][0] == 1

    assert dut.get_ROB_entry()[1]["is_load"][0] == 1
    assert dut.get_ROB_entry()[1]["is_store"][0] == 1

    assert dut.get_ROB_entry()[2]["is_load"][0] == 1
    assert dut.get_ROB_entry()[2]["is_store"][0] == 1

    assert dut.get_ROB_entry()[3]["is_load"][0] == 1
    assert dut.get_ROB_entry()[3]["is_store"][0] == 1

    await RisingEdge(dut.clock())

    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"] = [1, 1, 1, 1]
    FU_inputs["RD"] = [0, 0, 0, 0]
    FU_inputs["RD_data"] = [0, 0, 0, 0]
    FU_inputs["RD_valid"] = [0, 0, 0, 0]
    FU_inputs["instruction_PC"] = [0, 0, 0, 0]
    FU_inputs["branch_taken"] = [0, 0, 0, 0]
    FU_inputs["target_address"] = [0, 0, 0, 0]
    FU_inputs["branch_valid"] = [0, 0, 0, 0]
    FU_inputs["ROB_index"] = [0, 0, 0, 0]
    FU_inputs["fetch_packet_index"] = [0, 1, 2, 3]

    dut.write_FU(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU()
    await ReadOnly()

    dut.print_ROB(1)

    assert dut.get_WB_mem()[0]["busy"][0] == 1
    assert dut.get_WB_mem()[1]["busy"][0] == 1
    assert dut.get_WB_mem()[2]["busy"][0] == 1
    assert dut.get_WB_mem()[3]["busy"][0] == 1

    assert dut.get_ROB_output()["valid"] == 1
    assert dut.get_ROB_output()["is_load"] == [1,1,1,1]
    assert dut.get_ROB_output()["is_store"] == [1,1,1,1]


    
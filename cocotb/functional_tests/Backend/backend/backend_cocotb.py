import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from backend_dut import *
from SimpleDRAM import SimpleDRAM

@cocotb.test()
async def test_reset(dut):

    base_dir = os.path.dirname(__file__)
    bin_absolute_path = os.path.join(base_dir, "../../binaries/bin/addi.bin")
    print(bin_absolute_path)
    DRAM = SimpleDRAM(sizeKB=4, bin=bin_absolute_path)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_print(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.get_INTRS_contents()
    dut.get_INTRS_contents()

    dut.get_outputs()
    dut.get_PRF()

    backend_packet = generate_null_backend_packet()


@cocotb.test()
async def test_addi_RS_allocate(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.get_INTRS_contents()
    dut.get_INTRS_contents()

    dut.get_outputs()

    dut.get_PRF()


    # Addi, x0, 1, x0
    # Addi, x1, 1, x0
    # Addi, x2, 1, x0
    # Addi, x3, 1, x0

    backend_packet = generate_null_backend_packet()

    backend_packet["backend_packet_valid"]              = 1
    backend_packet["fetch_PC"]                          = 0x0
    backend_packet["io_backend_packet_bits_RAT_index"]    = 0x0

    backend_packet["RS1_ready"]             = [1, 1, 1, 1]
    backend_packet["RS1"]                   = [0, 0, 0, 0]
    backend_packet["RS1_valid"]             = [1, 1, 1, 1]

    backend_packet["RS2_ready"]             = [1, 1, 1, 1]
    backend_packet["RS2"]                   = [0, 0, 0, 0]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]

    backend_packet["RD"]                    = [0, 1, 2, 3]
    backend_packet["RD_valid"]              = [1, 1, 1, 1]

    backend_packet["IMM"]                   = [1, 1, 1, 1]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [0, 0, 0, 0]
    backend_packet["instructionType"]       = [0, 0, 0, 0]
    backend_packet["portID"]                = [0, 0, 0, 0]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [1, 1, 1, 1]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [1, 1, 1, 1]
    backend_packet["is_load"]               = [0, 0, 0, 0]
    backend_packet["is_store"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [1, 1, 1, 1]


    dut.write_decoded_instruction(backend_packet)

    await RisingEdge(dut.clock())
    dut.write_decoded_instruction()
    await ReadOnly()

    print(dut.get_INTRS_contents())

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 1
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 1
    assert dut.get_INTRS_contents()["RD"][2] == 2
    assert dut.get_INTRS_contents()["RD"][3] == 3

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 1

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0


    assert dut.get_INTRS_contents()["IMM"][0] == 1
    assert dut.get_INTRS_contents()["IMM"][1] == 1
    assert dut.get_INTRS_contents()["IMM"][2] == 1
    assert dut.get_INTRS_contents()["IMM"][3] == 1
    assert dut.get_INTRS_contents()["IMM"][4] == 0

    assert dut.get_INTRS_contents()["IMMEDIATE"][0] == 1
    assert dut.get_INTRS_contents()["IMMEDIATE"][1] == 1
    assert dut.get_INTRS_contents()["IMMEDIATE"][2] == 1
    assert dut.get_INTRS_contents()["IMMEDIATE"][3] == 1
    assert dut.get_INTRS_contents()["IMMEDIATE"][4] == 0






    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


@cocotb.test()
async def test_addi_RS_deallocate_port_contention(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.get_INTRS_contents()
    dut.get_INTRS_contents()

    dut.get_outputs()

    dut.get_PRF()


    # Addi, x0, 1, x0
    # Addi, x1, 1, x0
    # Addi, x2, 1, x0
    # Addi, x3, 1, x0

    backend_packet = generate_null_backend_packet()

    backend_packet["backend_packet_valid"]              = 1
    backend_packet["fetch_PC"]                          = 0x0
    backend_packet["io_backend_packet_bits_RAT_index"]    = 0x0

    backend_packet["RS1_ready"]             = [1, 1, 1, 1]
    backend_packet["RS1"]                   = [0, 0, 0, 0]
    backend_packet["RS1_valid"]             = [0, 0, 0, 0]

    backend_packet["RS2_ready"]             = [1, 1, 1, 1]
    backend_packet["RS2"]                   = [0, 0, 0, 0]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]

    backend_packet["RD"]                    = [0, 1, 2, 3]
    backend_packet["RD_valid"]              = [1, 1, 1, 1]

    backend_packet["IMM"]                   = [0, 0, 0, 0]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [0, 0, 0, 0]
    backend_packet["instructionType"]       = [0, 0, 0, 0]
    backend_packet["portID"]                = [0, 0, 0, 0]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [1, 1, 1, 1]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [1, 1, 1, 1]
    backend_packet["is_load"]               = [0, 0, 0, 0]
    backend_packet["is_store"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [1, 1, 1, 1]


    dut.write_decoded_instruction(backend_packet)

    await RisingEdge(dut.clock())
    dut.write_decoded_instruction()
    await ReadOnly()    # inputs in RS

    print(dut.get_INTRS_contents())
    print("")

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 1
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 1
    assert dut.get_INTRS_contents()["RD"][2] == 2
    assert dut.get_INTRS_contents()["RD"][3] == 3

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 1

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0

  

    await RisingEdge(dut.clock())       # 1 should be deallocated
    await ReadOnly()


    print(dut.get_INTRS_contents())
    print("")

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 0
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 1
    assert dut.get_INTRS_contents()["RD"][2] == 2
    assert dut.get_INTRS_contents()["RD"][3] == 0

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 0

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0



    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


@cocotb.test()
async def test_addi_RS_deallocate_many_free_ports(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.get_INTRS_contents()
    dut.get_INTRS_contents()

    dut.get_outputs()

    dut.get_PRF()


    # Addi, x0, 1, x0
    # Addi, x1, 1, x0
    # Addi, x2, 1, x0
    # Addi, x3, 1, x0

    backend_packet = generate_null_backend_packet()

    backend_packet["backend_packet_valid"]              = 1
    backend_packet["fetch_PC"]                          = 0x0
    backend_packet["io_backend_packet_bits_RAT_index"]    = 0x0

    backend_packet["RS1_ready"]             = [1, 1, 1, 1]
    backend_packet["RS1"]                   = [0, 0, 0, 0]
    backend_packet["RS1_valid"]             = [0, 0, 0, 0]

    backend_packet["RS2_ready"]             = [1, 1, 1, 1]
    backend_packet["RS2"]                   = [0, 0, 0, 0]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]

    backend_packet["RD"]                    = [0, 1, 2, 3]
    backend_packet["RD_valid"]              = [1, 1, 1, 1]

    backend_packet["IMM"]                   = [1, 1, 1, 1]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [7, 8, 9, 10]
    backend_packet["instructionType"]       = [4, 4, 4, 4]
    backend_packet["portID"]                = [0, 1, 2, 2]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [1, 1, 1, 1]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [1, 1, 1, 1]
    backend_packet["is_load"]               = [0, 0, 0, 0]
    backend_packet["is_store"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [1, 1, 1, 1]


    dut.write_decoded_instruction(backend_packet)

    await RisingEdge(dut.clock())
    dut.write_decoded_instruction()
    await ReadOnly()    # inputs in RS

    #print(dut.get_INTRS_contents())
    #print("")

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 1
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 1
    assert dut.get_INTRS_contents()["RD"][2] == 2
    assert dut.get_INTRS_contents()["RD"][3] == 3

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 1

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0

  

    await RisingEdge(dut.clock())       # 1 should be deallocated
    await ReadOnly()


    #print(dut.get_INTRS_contents())
    #print("")

    assert dut.get_INTRS_contents()["valid"][0] == 0
    assert dut.get_INTRS_contents()["valid"][1] == 0
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 0
    assert dut.get_INTRS_contents()["RD"][2] == 2
    assert dut.get_INTRS_contents()["RD"][3] == 0

    assert dut.get_INTRS_contents()["RD_valid"][0] == 0
    assert dut.get_INTRS_contents()["RD_valid"][1] == 0
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 0

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 0

    assert dut.get_FU_inputs(0)["input_valid"]  == 1
    assert dut.get_FU_inputs(0)["IMM"]          == 1
    assert dut.get_FU_inputs(0)["RD"]           == 0

    assert dut.get_FU_inputs(1)["input_valid"]  == 1
    assert dut.get_FU_inputs(1)["IMM"]          == 1
    assert dut.get_FU_inputs(1)["RD"]           == 1
    
    assert dut.get_FU_inputs(2)["input_valid"]  == 1
    assert dut.get_FU_inputs(2)["IMM"]          == 1
    assert dut.get_FU_inputs(2)["RD"]           == 3

    print(dut.get_FU_inputs(0))
    print(dut.get_FU_inputs(1))
    print(dut.get_FU_inputs(2))

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_FU_outputs(0)["valid"] == 1
    assert dut.get_FU_outputs(1)["valid"] == 1
    assert dut.get_FU_outputs(2)["valid"] == 1

    assert dut.get_FU_outputs(0)["RD"] == 0
    assert dut.get_FU_outputs(1)["RD"] == 1
    assert dut.get_FU_outputs(2)["RD"] == 3

    assert dut.get_FU_outputs(0)["RD_valid"] == 1
    assert dut.get_FU_outputs(1)["RD_valid"] == 1
    assert dut.get_FU_outputs(2)["RD_valid"] == 1

    assert dut.get_FU_outputs(0)["RD_data"] == 1
    assert dut.get_FU_outputs(1)["RD_data"] == 1
    assert dut.get_FU_outputs(2)["RD_data"] == 1

    assert dut.get_FU_outputs(0)["ROB_index"] == 7
    assert dut.get_FU_outputs(1)["ROB_index"] == 8
    assert dut.get_FU_outputs(2)["ROB_index"] == 10

    print(dut.get_FU_outputs(0))
    print(dut.get_FU_outputs(1))
    print(dut.get_FU_outputs(2))


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_PRF())

    dut.get_PRF()[0] == 1
    dut.get_PRF()[1] == 1
    dut.get_PRF()[3] == 1

@cocotb.test()
async def test_addi_RS_deallocate_many_free_ports_2(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    dut.get_INTRS_contents()
    dut.get_INTRS_contents()

    dut.get_outputs()

    dut.get_PRF()


    # Addi, x0, 1, x0
    # Addi, x1, 1, x0
    # Addi, x2, 1, x0
    # Addi, x3, 1, x0

    backend_packet = generate_null_backend_packet()

    backend_packet["backend_packet_valid"]              = 1
    backend_packet["fetch_PC"]                          = 0x0
    backend_packet["io_backend_packet_bits_RAT_index"]    = 0x0

    backend_packet["RS1_ready"]             = [1, 1, 1, 1]
    backend_packet["RS1"]                   = [0, 0, 0, 0]
    backend_packet["RS1_valid"]             = [0, 0, 0, 0]

    backend_packet["RS2_ready"]             = [1, 1, 1, 1]
    backend_packet["RS2"]                   = [0, 0, 0, 0]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]

    backend_packet["RD"]                    = [22, 25, 19, 7]
    backend_packet["RD_valid"]              = [1, 1, 1, 1]

    backend_packet["IMM"]                   = [7, 77, 123, 55]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [7, 8, 9, 10]
    backend_packet["instructionType"]       = [4, 4, 4, 4]
    backend_packet["portID"]                = [0, 1, 2, 2]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [1, 1, 1, 1]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [1, 1, 1, 1]
    backend_packet["is_load"]               = [0, 0, 0, 0]
    backend_packet["is_store"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [1, 1, 1, 1]


    dut.write_decoded_instruction(backend_packet)

    await RisingEdge(dut.clock())
    dut.write_decoded_instruction()
    await ReadOnly()    # inputs in RS

    #print(dut.get_INTRS_contents())
    #print("")

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 1
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 22
    assert dut.get_INTRS_contents()["RD"][1] == 25
    assert dut.get_INTRS_contents()["RD"][2] == 19
    assert dut.get_INTRS_contents()["RD"][3] == 7

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 1

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0

  

    await RisingEdge(dut.clock())       # 1 should be deallocated
    await ReadOnly()


    #print(dut.get_INTRS_contents())
    #print("")



    assert dut.get_INTRS_contents()["valid"][0] == 0
    assert dut.get_INTRS_contents()["valid"][1] == 0
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 0
    assert dut.get_INTRS_contents()["RD"][2] == 19
    assert dut.get_INTRS_contents()["RD"][3] == 0

    assert dut.get_INTRS_contents()["RD_valid"][0] == 0
    assert dut.get_INTRS_contents()["RD_valid"][1] == 0
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 0

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 0

    assert dut.get_FU_inputs(0)["input_valid"]  == 1
    assert dut.get_FU_inputs(0)["IMM"]          == 7
    assert dut.get_FU_inputs(0)["RD"]           == 22

    assert dut.get_FU_inputs(1)["input_valid"]  == 1
    assert dut.get_FU_inputs(1)["IMM"]          == 77
    assert dut.get_FU_inputs(1)["RD"]           == 25
    
    assert dut.get_FU_inputs(2)["input_valid"]  == 1
    assert dut.get_FU_inputs(2)["IMM"]          == 55
    assert dut.get_FU_inputs(2)["RD"]           == 7

    print(dut.get_FU_inputs(0))
    print(dut.get_FU_inputs(1))
    print(dut.get_FU_inputs(2))

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_FU_outputs(0)["valid"] == 1
    assert dut.get_FU_outputs(1)["valid"] == 1
    assert dut.get_FU_outputs(2)["valid"] == 1

    assert dut.get_FU_outputs(0)["RD"] == 22
    assert dut.get_FU_outputs(1)["RD"] == 25
    assert dut.get_FU_outputs(2)["RD"] == 7

    assert dut.get_FU_outputs(0)["RD_valid"] == 1
    assert dut.get_FU_outputs(1)["RD_valid"] == 1
    assert dut.get_FU_outputs(2)["RD_valid"] == 1

    assert dut.get_FU_outputs(0)["RD_data"] == 7
    assert dut.get_FU_outputs(1)["RD_data"] == 77
    assert dut.get_FU_outputs(2)["RD_data"] == 55

    assert dut.get_FU_outputs(0)["ROB_index"] == 7
    assert dut.get_FU_outputs(1)["ROB_index"] == 8
    assert dut.get_FU_outputs(2)["ROB_index"] == 10

    print(dut.get_FU_outputs(0))
    print(dut.get_FU_outputs(1))
    print(dut.get_FU_outputs(2))


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_PRF())

    dut.get_PRF()[0] == 1
    dut.get_PRF()[1] == 1
    dut.get_PRF()[3] == 1



@cocotb.test()
async def test_addi_RS_deallocate_many_free_ports_2_init_PRF(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    for i in range(64):
        getattr(dut.dut, f"INT_PRF.mem_ext.Memory")[i].value = 7

    await RisingEdge(dut.clock())

    # Addi, x0, 1, x0
    # Addi, x1, 1, x0
    # Addi, x2, 1, x0
    # Addi, x3, 1, x0

    backend_packet = generate_null_backend_packet()

    backend_packet["backend_packet_valid"]              = 1
    backend_packet["fetch_PC"]                          = 0x0
    backend_packet["io_backend_packet_bits_RAT_index"]    = 0x0

    backend_packet["RS1_ready"]             = [1, 1, 1, 1]
    backend_packet["RS1"]                   = [0, 0, 0, 0]
    backend_packet["RS1_valid"]             = [0, 0, 0, 0]

    backend_packet["RS2_ready"]             = [1, 1, 1, 1]
    backend_packet["RS2"]                   = [0, 0, 0, 0]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]

    backend_packet["RD"]                    = [22, 25, 19, 7]
    backend_packet["RD_valid"]              = [1, 1, 1, 1]

    backend_packet["IMM"]                   = [7, 77, 123, 55]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [7, 8, 9, 10]
    backend_packet["instructionType"]       = [4, 4, 4, 4]
    backend_packet["portID"]                = [0, 1, 2, 2]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [1, 1, 1, 1]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [1, 1, 1, 1]
    backend_packet["is_load"]               = [0, 0, 0, 0]
    backend_packet["is_store"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [1, 1, 1, 1]


    dut.write_decoded_instruction(backend_packet)

    await RisingEdge(dut.clock())
    dut.write_decoded_instruction()
    await ReadOnly()    # inputs in RS

    #print(dut.get_INTRS_contents())
    #print("")

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 1
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 22
    assert dut.get_INTRS_contents()["RD"][1] == 25
    assert dut.get_INTRS_contents()["RD"][2] == 19
    assert dut.get_INTRS_contents()["RD"][3] == 7

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 1

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0

  

    await RisingEdge(dut.clock())       # 1 should be deallocated
    await ReadOnly()


    #print(dut.get_INTRS_contents())
    #print("")



    assert dut.get_INTRS_contents()["valid"][0] == 0
    assert dut.get_INTRS_contents()["valid"][1] == 0
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 0
    assert dut.get_INTRS_contents()["RD"][2] == 19
    assert dut.get_INTRS_contents()["RD"][3] == 0

    assert dut.get_INTRS_contents()["RD_valid"][0] == 0
    assert dut.get_INTRS_contents()["RD_valid"][1] == 0
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 0

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 0

    assert dut.get_FU_inputs(0)["input_valid"]  == 1
    assert dut.get_FU_inputs(0)["IMM"]          == 7
    assert dut.get_FU_inputs(0)["RD"]           == 22

    assert dut.get_FU_inputs(1)["input_valid"]  == 1
    assert dut.get_FU_inputs(1)["IMM"]          == 77
    assert dut.get_FU_inputs(1)["RD"]           == 25
    
    assert dut.get_FU_inputs(2)["input_valid"]  == 1
    assert dut.get_FU_inputs(2)["IMM"]          == 55
    assert dut.get_FU_inputs(2)["RD"]           == 7

    print(dut.get_FU_inputs(0))
    print(dut.get_FU_inputs(1))
    print(dut.get_FU_inputs(2))

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_FU_outputs(0)["valid"] == 1
    assert dut.get_FU_outputs(1)["valid"] == 1
    assert dut.get_FU_outputs(2)["valid"] == 1

    assert dut.get_FU_outputs(0)["RD"] == 22
    assert dut.get_FU_outputs(1)["RD"] == 25
    assert dut.get_FU_outputs(2)["RD"] == 7

    assert dut.get_FU_outputs(0)["RD_valid"] == 1
    assert dut.get_FU_outputs(1)["RD_valid"] == 1
    assert dut.get_FU_outputs(2)["RD_valid"] == 1

    assert dut.get_FU_outputs(0)["RD_data"] == 7 + 7
    assert dut.get_FU_outputs(1)["RD_data"] == 77 + 7
    assert dut.get_FU_outputs(2)["RD_data"] == 55 + 7

    assert dut.get_FU_outputs(0)["ROB_index"] == 7
    assert dut.get_FU_outputs(1)["ROB_index"] == 8
    assert dut.get_FU_outputs(2)["ROB_index"] == 10

    print(dut.get_FU_outputs(0))
    print(dut.get_FU_outputs(1))
    print(dut.get_FU_outputs(2))


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_PRF())

    dut.get_PRF()[0] == 1
    dut.get_PRF()[1] == 1
    dut.get_PRF()[3] == 1



@cocotb.test()
async def test_addi_RS_reg_read_RD(dut):

    base_dir = os.path.dirname(__file__)
    DRAM = SimpleDRAM(sizeKB=4)

    await cocotb.start(generateClock(dut)) 

    dut = backend_dut(dut, DRAM=DRAM)  # wrap dut with helper class
    await dut.reset()   # reset module

    for i in range(64):
        getattr(dut.dut, f"INT_PRF.mem_ext.Memory")[i].value = i

    await RisingEdge(dut.clock())


    backend_packet = generate_null_backend_packet()

    backend_packet["backend_packet_valid"]              = 1
    backend_packet["fetch_PC"]                          = 0x0
    backend_packet["io_backend_packet_bits_RAT_index"]    = 0x0

    backend_packet["RS1_ready"]             = [1, 1, 1, 1]
    backend_packet["RS1"]                   = [1, 2, 3, 4]
    backend_packet["RS1_valid"]             = [1, 1, 1, 1]

    backend_packet["RS2_ready"]             = [1, 1, 1, 1]
    backend_packet["RS2"]                   = [5, 6, 7, 8]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]

    backend_packet["RD"]                    = [9, 10, 11, 12]
    backend_packet["RD_valid"]              = [1, 1, 1, 1]

    backend_packet["IMM"]                   = [0, 0, 0, 0]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [7, 8, 9, 10]
    backend_packet["instructionType"]       = [12, 12, 12, 12]
    backend_packet["portID"]                = [0, 1, 2, 2]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [1, 1, 1, 1]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [0, 0, 0, 0]
    backend_packet["is_load"]               = [0, 0, 0, 0]
    backend_packet["is_store"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [1, 1, 1, 1]


    dut.write_decoded_instruction(backend_packet)

    await RisingEdge(dut.clock())
    dut.write_decoded_instruction()
    await ReadOnly()    # inputs in RS

    #print(dut.get_INTRS_contents())
    #print("")

    assert dut.get_INTRS_contents()["valid"][0] == 1
    assert dut.get_INTRS_contents()["valid"][1] == 1
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 1
    assert dut.get_INTRS_contents()["valid"][4] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 9
    assert dut.get_INTRS_contents()["RD"][1] == 10
    assert dut.get_INTRS_contents()["RD"][2] == 11
    assert dut.get_INTRS_contents()["RD"][3] == 12

    assert dut.get_INTRS_contents()["RD_valid"][0] == 1
    assert dut.get_INTRS_contents()["RD_valid"][1] == 1
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 1

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][4] == 0

  

    await RisingEdge(dut.clock())       # 1 should be deallocated
    await ReadOnly()


    #print(dut.get_INTRS_contents())
    #print("")



    assert dut.get_INTRS_contents()["valid"][0] == 0
    assert dut.get_INTRS_contents()["valid"][1] == 0
    assert dut.get_INTRS_contents()["valid"][2] == 1
    assert dut.get_INTRS_contents()["valid"][3] == 0

    assert dut.get_INTRS_contents()["RD"][0] == 0
    assert dut.get_INTRS_contents()["RD"][1] == 0
    assert dut.get_INTRS_contents()["RD"][2] == 11
    assert dut.get_INTRS_contents()["RD"][3] == 0

    assert dut.get_INTRS_contents()["RD_valid"][0] == 0
    assert dut.get_INTRS_contents()["RD_valid"][1] == 0
    assert dut.get_INTRS_contents()["RD_valid"][2] == 1
    assert dut.get_INTRS_contents()["RD_valid"][3] == 0

    assert dut.get_INTRS_contents()["needs_ALU"][0] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][1] == 0
    assert dut.get_INTRS_contents()["needs_ALU"][2] == 1
    assert dut.get_INTRS_contents()["needs_ALU"][3] == 0

    assert dut.get_FU_inputs(0)["input_valid"]  == 1
    assert dut.get_FU_inputs(0)["IMM"]          == 0
    assert dut.get_FU_inputs(0)["RD"]           == 9
    assert dut.get_FU_inputs(0)["RS1_data"]      == 1
    assert dut.get_FU_inputs(0)["RS2_data"]      == 5

    assert dut.get_FU_inputs(1)["input_valid"]  == 1
    assert dut.get_FU_inputs(1)["IMM"]          == 0
    assert dut.get_FU_inputs(1)["RD"]           == 10
    assert dut.get_FU_inputs(1)["RS1_data"]      == 2
    assert dut.get_FU_inputs(1)["RS2_data"]      == 6
    
    assert dut.get_FU_inputs(2)["input_valid"]  == 1
    assert dut.get_FU_inputs(2)["IMM"]          == 0
    assert dut.get_FU_inputs(2)["RD"]           == 12
    assert dut.get_FU_inputs(2)["RS1_data"]      == 4
    assert dut.get_FU_inputs(2)["RS2_data"]      == 8

    print(dut.get_FU_inputs(0))
    print(dut.get_FU_inputs(1))
    print(dut.get_FU_inputs(2))

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_FU_outputs(0)["valid"] == 1
    assert dut.get_FU_outputs(1)["valid"] == 1
    assert dut.get_FU_outputs(2)["valid"] == 1

    assert dut.get_FU_outputs(0)["RD"] == 9
    assert dut.get_FU_outputs(1)["RD"] == 10
    assert dut.get_FU_outputs(2)["RD"] == 12

    assert dut.get_FU_outputs(0)["RD_valid"] == 1
    assert dut.get_FU_outputs(1)["RD_valid"] == 1
    assert dut.get_FU_outputs(2)["RD_valid"] == 1

    assert dut.get_FU_outputs(0)["RD_data"] == 6
    assert dut.get_FU_outputs(1)["RD_data"] == 8
    assert dut.get_FU_outputs(2)["RD_data"] == 12

    assert dut.get_FU_outputs(0)["ROB_index"] == 7
    assert dut.get_FU_outputs(1)["ROB_index"] == 8
    assert dut.get_FU_outputs(2)["ROB_index"] == 10

    print(dut.get_FU_outputs(0))
    print(dut.get_FU_outputs(1))
    print(dut.get_FU_outputs(2))


    await RisingEdge(dut.clock())
    await ReadOnly()

    print(dut.get_PRF())

    dut.get_PRF()[0] == 1
    dut.get_PRF()[1] == 1
    dut.get_PRF()[3] == 1





## Test Memory Operations ##



import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from FTQ_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_write_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x110



@cocotb.test()
async def test_FU_broadcast(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [1,0,0,0]
    FU_inputs["target_address"]        =   [0x1234,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [1,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234

@cocotb.test()
async def test_FU_broadcast_higher_priority(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [1,0,0,0]
    FU_inputs["target_address"]        =   [0x1234,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [1,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [1,0,0,0]
    FU_inputs["target_address"]        =   [0xc0de,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [0,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0xc0de


@cocotb.test()
async def test_FU_broadcast_lower_priority(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [1,0,0,0]
    FU_inputs["target_address"]        =   [0x1234,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [1,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [1,0,0,0]
    FU_inputs["target_address"]        =   [0xc0de,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [3,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234

@cocotb.test()
async def test_FU_broadcast_parallel(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0x100,0x100,0x100]
    FU_inputs["branch_taken"]          =   [1,1,1,1]
    FU_inputs["target_address"]        =   [0x1234,0xc0de,0xbeef,0xeee0]
    FU_inputs["branch_valid"]          =   [1,1,1,1]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [0,1,2,3]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234

@cocotb.test()
async def test_FU_broadcast_parallel_random_order(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0x100,0x100,0x100]
    FU_inputs["branch_taken"]          =   [1,1,1,1]
    FU_inputs["target_address"]        =   [0x1234,0xc0de,0xbeef,0xeee0]
    FU_inputs["branch_valid"]          =   [1,1,1,1]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [3,1,0,2]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0xbeef

    # This is currently not supported





@cocotb.test()
async def test_FU_broadcast_none_taken(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [1,0,0,0]
    FU_inputs["target_address"]        =   [0x1234,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [1,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    FU_inputs = generate_null_FU_inputs()


    FU_inputs["valid"]                 =   [1,0,0,0]
    FU_inputs["RD"]                    =   [0,0,0,0]
    FU_inputs["RD_data"]               =   [0,0,0,0]
    FU_inputs["RD_valid"]              =   [0,0,0,0]
    FU_inputs["instruction_PC"]        =   [0x100,0,0,0]
    FU_inputs["branch_taken"]          =   [0,0,0,0]
    FU_inputs["target_address"]        =   [0xc0de,0,0,0]
    FU_inputs["branch_valid"]          =   [1,0,0,0]
    FU_inputs["ROB_index"]             =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]    =   [3,0,0,0]


    dut.write_FU_inputs(FU_inputs)

    await RisingEdge(dut.clock())
    dut.write_FU_inputs()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x1234



@cocotb.test()
async def test_full(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())

    for i in range(16):
        dut.write_predictions(inputs)

        await RisingEdge(dut.clock())

    await ReadOnly()
    dut.print_FTQ()

    assert dut.get_outputs()["ready"] == 0

@cocotb.test()
async def test_write_1_read_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = FTQ_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_predictions()

    inputs["valid"]                     =   1
    inputs["dominant_index"]            =   3
    inputs["fetch_PC"]                  =   0x100
    inputs["predicted_PC"]              =   0xdeadbee0
    inputs["resolved_PC"]               =   0x110
    inputs["GHR"]                       =   0
    inputs["NEXT"]                      =   0
    inputs["TOS"]                       =   0
    inputs["RAT_IDX"]                   =   0

    dut.write_predictions(inputs)

    await RisingEdge(dut.clock())
    dut.write_predictions()
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0]      ==  1
    assert dut.get_FTQ_contents()["fetch_PC"][0]   ==  256
    assert dut.get_FTQ_contents()["resolved_PC"][0]   ==  0x110


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    assert dut.get_FTQ_contents()["valid"][0] == 1

    commit_inputs = generate_null_commit()

    commit_inputs["valid"] = 1
    commit_inputs["fetch_PC"] = 0x100
    commit_inputs["T_NT"] = 0
    commit_inputs["is_BR"] = 0
    commit_inputs["is_misprediction"] = 0
    commit_inputs["expected_PC"] = 0
    commit_inputs["GHR"] = 0
    commit_inputs["TOS"] = 0
    commit_inputs["NEXT"] = 0
    commit_inputs["RAT_IDX"] = 0

    dut.write_commit(commit_inputs)


    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_FTQ()

    assert dut.get_FTQ_contents()["valid"][0] == 0


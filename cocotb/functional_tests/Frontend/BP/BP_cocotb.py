import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from BP_dut import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_BTB_write(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0x020
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0x10
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][2] ==  hex(0x10)

@cocotb.test()
async def test_BTB_overwrite(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0x020
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0x10
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    commit_inputs["expected_PC"]        = 0xbee0
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][2] ==  hex(0xbee0)

@cocotb.test()
async def test_BTB_indexing(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0x4
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0x10
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][0] ==  hex(0x10)


@cocotb.test()
async def test_BTB_indexing_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 12
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][0] ==  hex(0xc0de)

@cocotb.test()
async def test_BTB_indexing_4(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0x10000
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][0] ==  hex(0xc0de)


@cocotb.test()
async def test_BTB_non_branch(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 12
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 0
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][2] ==  hex(0x0)

@cocotb.test()
async def test_BTB_NT(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 12
    commit_inputs["T_NT"]               = 0
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0xF
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    
    dut.print_BTB_contents()

    assert dut.get_BTB_contents()["BTB_target"][2] ==  hex(0x0)


@cocotb.test()
async def test_1_PHT_write(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0x0
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit()
    await ReadOnly()

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_PHT_contents()


    assert dut.get_PHT_contents()[0] == 1


@cocotb.test()
async def test_2_PHT_write(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0x0
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit()


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_PHT_contents()


    assert dut.get_PHT_contents()[0] == 2


@cocotb.test()
async def test_3_PHT_write(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0x0
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit()


    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_PHT_contents()


    assert dut.get_PHT_contents()[0] == 3


@cocotb.test()
async def test_PHT_up_down(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0
    commit_inputs["T_NT"]               = 1
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0x0
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)

    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit()


    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit()
    await RisingEdge(dut.clock())
    await ReadOnly()
    dut.print_PHT_contents()


    assert dut.get_PHT_contents()[0] == 3


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    commit_inputs = generate_null_commit()

    commit_inputs["valid"]              = 1
    commit_inputs["fetch_PC"]           = 0
    commit_inputs["T_NT"]               = 0
    commit_inputs["br_type"]            = 1
    commit_inputs["is_misprediction"]   = 0
    commit_inputs["expected_PC"]        = 0xc0de
    commit_inputs["GHR"]                = 0x0
    commit_inputs["TOS"]                = 0
    commit_inputs["NEXT"]               = 0
    commit_inputs["RAT_IDX"]            = 0

    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    dut.write_commit(commit_inputs)
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_PHT_contents()[0] == 0
    await ReadOnly()

@cocotb.test()
async def test_RAS(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    RAS_input = generate_null_RAS_update()


    RAS_input["call_addr"]     = 0xce00
    RAS_input["call"]   = 1
    RAS_input["ret"]    = 0


    dut.write_RAS_update(RAS_input)

    await RisingEdge(dut.clock())
    dut.write_RAS_update()
    await ReadOnly()

    dut.print_RAS_contents()

    dut.get_RAS_contents()[0] == 0xce00

@cocotb.test()
async def test_RAS_call(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    RAS_input = generate_null_RAS_update()


    RAS_input["call_addr"]     = 0xce00
    RAS_input["call"]   = 1
    RAS_input["ret"]    = 0


    dut.write_RAS_update(RAS_input)

    await RisingEdge(dut.clock())
    RAS_input["call_addr"]     = 0xbeef
    dut.write_RAS_update(RAS_input)
    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_RAS_contents()

    assert dut.get_RAS_contents()[0] == 0xce00
    assert dut.get_RAS_contents()[1] == 0xbeef


@cocotb.test()
async def test_RAS_call_ret(dut):

    await cocotb.start(generateClock(dut)) 

    dut = BP_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    RAS_input = generate_null_RAS_update()


    RAS_input["call_addr"]     = 0xce00
    RAS_input["call"]   = 1
    RAS_input["ret"]    = 0


    dut.write_RAS_update(RAS_input)

    await RisingEdge(dut.clock())
    RAS_input["call_addr"]     = 0xbeef
    RAS_input["call"]   = 1
    RAS_input["ret"]    = 0
    dut.write_RAS_update(RAS_input)
    await RisingEdge(dut.clock())

    RAS_input["call"]   = 0
    RAS_input["ret"]    = 1
    dut.write_RAS_update(RAS_input)
    await RisingEdge(dut.clock())

    await ReadOnly()

    assert dut.get_RAS_read_outputs()["ret_addr"]   ==  0xce00
    assert dut.get_RAS_read_outputs()["TOS"]        ==  0
    assert dut.get_RAS_read_outputs()["NEXT"]       ==  2   # 2 incase the pop was a mispredict



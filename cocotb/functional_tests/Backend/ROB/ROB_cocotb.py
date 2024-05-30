import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from ROB_dut import *

@cocotb.test()
async def reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def allocate_all_valid(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [1,1,1,1]
    allocate_inputs["is_branch"]         = [1,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    entry_row = dut.get_ROB_entry_row(0)

    assert entry_row == [0b11,0b11,0b11,0b11]

@cocotb.test()
async def allocate_first_invalid(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [0,1,1,1]
    allocate_inputs["is_branch"]         = [1,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    entry_row = dut.get_ROB_entry_row(0)

    assert entry_row == [0b00,0b11,0b11,0b11]

@cocotb.test()
async def allocate_first_not_branch(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [1,1,1,1]
    allocate_inputs["is_branch"]         = [0,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    entry_row = dut.get_ROB_entry_row(0)

    assert entry_row == [0b01,0b11,0b11,0b11]

@cocotb.test()
async def allocate_first_not_branch(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [1,1,1,1]
    allocate_inputs["is_branch"]         = [0,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    entry_row = dut.get_ROB_entry_row(0)

    assert entry_row == [0b01,0b11,0b11,0b11]


@cocotb.test()
async def allocate_multiple(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [1,1,1,1]
    allocate_inputs["is_branch"]         = [1,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())

    dut.send_allocate()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    assert dut.get_front_pointer() == 0
    assert dut.get_back_pointer() == 4


@cocotb.test()
async def busy(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [1,1,1,1]
    allocate_inputs["is_branch"]         = [1,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())

    dut.send_allocate()

    await ReadOnly()


    FU_inputs = generateNullFUInput()

    await RisingEdge(dut.clock())

    FU_inputs["valid"]                  =   [1,1,1,1]
    FU_inputs["branch_valid"]           =   [0,0,0,0]
    FU_inputs["ROB_index"]              =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]     =   [0,1,2,3]

    dut.send_FU(FU_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_ROB()
    dut.print_busy()

    assert dut.get_ROB_busy_row(0) == [1,1,1,1]


@cocotb.test()
async def busy_random(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()

    allocate_inputs["valid"] = 1
    allocate_inputs["instruction_valid"] = [1,1,1,1]
    allocate_inputs["is_branch"]         = [1,1,1,1]

    dut.send_allocate(allocate_inputs)

    await RisingEdge(dut.clock())

    dut.send_allocate()

    await ReadOnly()


    FU_inputs = generateNullFUInput()

    await RisingEdge(dut.clock())

    FU_inputs["valid"]                  =   [1,1,1,1]
    FU_inputs["branch_valid"]           =   [0,0,0,0]
    FU_inputs["ROB_index"]              =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]     =   [0,1,2,3]

    dut.send_FU(FU_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_ROB()
    dut.print_busy()

    assert dut.get_ROB_busy_row(0) == [1,1,1,1]
    assert dut.get_back_pointer() == 1

@cocotb.test()
async def allocate_many(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()


    for _ in range(64):
        allocate_inputs["valid"] = 1
        allocate_inputs["instruction_valid"] = [1,1,1,1]
        allocate_inputs["is_branch"]         = [1,1,1,1]

        dut.send_allocate(allocate_inputs)

        await RisingEdge(dut.clock())


    dut.send_allocate()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    dut.print_ROB()


    assert dut.get_back_pointer() == 64
    assert dut.get_front_pointer() == 0



@cocotb.test()
async def allocate_many_FU_broadcast(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    allocate_inputs = generateNullAllocate()


    for _ in range(64):
        allocate_inputs["valid"] = 1
        allocate_inputs["instruction_valid"] = [1,1,1,1]
        allocate_inputs["is_branch"]         = [1,1,1,1]

        dut.send_allocate(allocate_inputs)

        await RisingEdge(dut.clock())

    dut.send_allocate()
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    assert dut.get_back_pointer() == 64
    assert dut.get_front_pointer() == 0

    #
    # broadcast entire first row
    #



    await RisingEdge(dut.clock())



    await RisingEdge(dut.clock())

    FU_inputs = generateNullFUInput()
    FU_inputs["valid"]                  =   [1,1,1,1]
    FU_inputs["branch_valid"]           =   [0,0,0,0]
    FU_inputs["ROB_index"]              =   [0,0,0,0]
    FU_inputs["fetch_packet_index"]     =   [0,1,2,3]

    dut.send_FU(FU_inputs)

    await RisingEdge(dut.clock())
    await ReadOnly()


    dut.print_ROB()
    dut.print_busy()

    assert dut.get_back_pointer() == 64
    assert dut.get_front_pointer() == 1

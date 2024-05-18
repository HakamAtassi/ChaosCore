import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *
from RAT_dut import *

@cocotb.test()
async def RAT_startup(dut):
    await Timer(1, "ns")


@cocotb.test()
async def RAT_write_read(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = RAT_dut(dut)

    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[1,2,3,4], free_list_RD=[40,41,42,43], free_list_valid=[1,1,1,1])


    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[0,0,0,0], free_list_RD=[0,0,0,0], free_list_valid=[0,0,0,0])

    await RisingEdge(dut.clock())
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    await RisingEdge(dut.clock())

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

@cocotb.test()
async def RAT_write_read_checkpoint_read(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = RAT_dut(dut)

    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[1,2,3,4], free_list_RD=[40,41,42,43], free_list_valid=[1,1,1,1])


    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[0,0,0,0], free_list_RD=[0,0,0,0], free_list_valid=[0,0,0,0])

    await RisingEdge(dut.clock())
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    await RisingEdge(dut.clock())

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

    dut.create_checkpoint(valid=1)
    await RisingEdge(dut.clock())
    dut.create_checkpoint(valid=0)

    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

@cocotb.test()
async def RAT_write_read_many_checkpoints_read(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = RAT_dut(dut)

    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[1,2,3,4], free_list_RD=[40,41,42,43], free_list_valid=[1,1,1,1])


    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[0,0,0,0], free_list_RD=[0,0,0,0], free_list_valid=[0,0,0,0])

    await RisingEdge(dut.clock())
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    await RisingEdge(dut.clock())

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

    for _ in range(10):
        dut.create_checkpoint(valid=1)
        await RisingEdge(dut.clock())

    dut.create_checkpoint(valid=0)
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]


@cocotb.test()
async def RAT_write_read_15_checkpoints_read(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = RAT_dut(dut)

    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[1,2,3,4], free_list_RD=[40,41,42,43], free_list_valid=[1,1,1,1])


    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[0,0,0,0], free_list_RD=[0,0,0,0], free_list_valid=[0,0,0,0])

    await RisingEdge(dut.clock())
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    await RisingEdge(dut.clock())

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

    for _ in range(15):
        dut.create_checkpoint(valid=1)
        await RisingEdge(dut.clock())

    dut.create_checkpoint(valid=0)
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_full() == 1

    RD, RS1, RS2 = dut.get_outputs()

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]




@cocotb.test()
async def RAT_write_read_15_checkpoints_read_free(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = RAT_dut(dut)

    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[1,2,3,4], free_list_RD=[40,41,42,43], free_list_valid=[1,1,1,1])


    await RisingEdge(dut.clock())
    dut.write(instruction_RD=[0,0,0,0], free_list_RD=[0,0,0,0], free_list_valid=[0,0,0,0])

    await RisingEdge(dut.clock())
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    await RisingEdge(dut.clock())

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

    for _ in range(15):
        dut.create_checkpoint(valid=1)
        await RisingEdge(dut.clock())

    dut.create_checkpoint(valid=0)
    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_full() == 1

    RD, RS1, RS2 = dut.get_outputs()

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]

    await RisingEdge(dut.clock())

    dut.free_checkpoint(valid=1)
    await RisingEdge(dut.clock())
    await ReadOnly()
    assert dut.get_full() == 0

    await RisingEdge(dut.clock())

    for _ in range(14):
        dut.free_checkpoint(valid=1)
        await RisingEdge(dut.clock())


    dut.read(instruction_RD=[1,2,3,4], instruction_RS1=[1,2,3,4], instruction_RS2=[1,2,3,4])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RD, RS1, RS2 = dut.get_outputs()

    assert RD  == [40,41,42,43]
    assert RS1 == [40,41,42,43]
    assert RS2 == [40,41,42,43]
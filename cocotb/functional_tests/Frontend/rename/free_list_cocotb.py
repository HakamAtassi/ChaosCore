import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *
from free_list_dut import *

@cocotb.test()
async def test_startup(dut):
    await Timer(1, "ns")


@cocotb.test()
async def free_list_check_first_read(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = free_list_dut(dut)

    dut.dequeue_registers([1,1,1,1])

    await ReadOnly()

    values = dut.get_outputs()

    assert values == [0,1,2,3]

@cocotb.test()
async def free_list_check_many_reads(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = free_list_dut(dut)

    dut.dequeue_registers([1,1,1,1])
    await ReadOnly()
    values = dut.get_outputs()
    assert values == [0,1,2,3]

    await RisingEdge(dut.clock())

    dut.dequeue_registers([1,1,1,1])
    await ReadOnly()
    values = dut.get_outputs()
    assert values == [4,5,6,7]

    await RisingEdge(dut.clock())

    dut.dequeue_registers([1,1,1,1])
    await ReadOnly()
    values = dut.get_outputs()
    assert values == [8,9,10,11]

@cocotb.test()
async def free_list_check_many_unordered_reads(dut):
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut = free_list_dut(dut)

    dut.dequeue_registers([1,1,0,0])
    await ReadOnly()
    values = dut.get_outputs()
    assert values[0:2] == [0,1]

    await RisingEdge(dut.clock())

    dut.dequeue_registers([1,1,0,0])
    await ReadOnly()
    values = dut.get_outputs()
    assert values[0:2] == [2,3]

    await RisingEdge(dut.clock())

    dut.dequeue_registers([0,0,1,1])
    await ReadOnly()
    values = dut.get_outputs()
    assert values[2] == 4
    assert values[3] == 5

    await RisingEdge(dut.clock())

    dut.dequeue_registers([1,1,1,1])
    await ReadOnly()
    values = dut.get_outputs()
    assert values[0] == 6
    assert values[1] == 7
    assert values[2] == 8
    assert values[3] == 9
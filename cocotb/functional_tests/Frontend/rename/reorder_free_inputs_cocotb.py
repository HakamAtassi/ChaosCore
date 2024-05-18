import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *
from reorder_free_inputs_dut import *


@cocotb.test()
async def test_startup(dut):
    await Timer(1, "ns")


@cocotb.test()
async def reorder_free_inputs_no_change(dut):

    dut = reorder_free_inputs_dut(dut)

    dut.place_input([0,1,2,3],[1,1,1,1])
    await Timer(1, "ns")
    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values == [0,1,2,3]
    assert sorted_valid  == [1,1,1,1]


@cocotb.test()
async def reorder_first_element_invalid(dut):
    dut = reorder_free_inputs_dut(dut)
    dut.place_input([7,6,5,4],[0,1,1,1])
    await Timer(1, "ns")
    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:3] == [6,5,4]
    assert sorted_valid  == [1,1,1,0]


@cocotb.test()
async def reorder_last_element_invalid(dut):
    dut = reorder_free_inputs_dut(dut)
    dut.place_input([7,6,5,4],[1,1,1,0])
    await Timer(1, "ns")
    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:3] == [7,6,5]
    assert sorted_valid  == [1,1,1,0]


@cocotb.test()
async def reorder_middle_elements_invalid(dut):
    dut = reorder_free_inputs_dut(dut)
    dut.place_input([7,6,5,4],[1,1,0,1])
    await Timer(1, "ns")

    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:3] == [7,6,4]
    assert sorted_valid  == [1,1,1,0]

    dut.place_input([7,6,5,4],[1,0,1,1])
    await Timer(1, "ns")

    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:3] == [7,5,4]
    assert sorted_valid  == [1,1,1,0]

@cocotb.test()
async def reorder_multiple_invalid(dut):
    dut = reorder_free_inputs_dut(dut)
    dut.place_input([7,6,5,4],[1,0,0,1])
    await Timer(1, "ns")

    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:2] == [7,4]
    assert sorted_valid  == [1,1,0,0]

    dut.place_input([7,6,5,4],[0,0,1,1])
    await Timer(1, "ns")

    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:2] == [5,4]
    assert sorted_valid  == [1,1,0,0]

    dut.place_input([7,6,5,4],[1,1,0,0])
    await Timer(1, "ns")

    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:2] == [7,6]
    assert sorted_valid  == [1,1,0,0]

@cocotb.test()
async def reorder_max_width(dut):
    dut = reorder_free_inputs_dut(dut)
    dut.place_input([63,63,63,63],[1,1,1,1])
    await Timer(1, "ns")
    sorted_values, sorted_valid = dut.get_output()
    assert sorted_values[0:4] == [63,63,63,63]
    assert sorted_valid  == [1,1,1,1]
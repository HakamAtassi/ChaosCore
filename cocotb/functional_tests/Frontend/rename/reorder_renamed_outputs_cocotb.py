import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path

from cocotb_utils import *
from reorder_renamed_outputs_dut import *


@cocotb.test()
async def test_startup(dut):
    await Timer(1, "ns")


@cocotb.test()
async def reorder_renamed_outputs_no_change(dut):

    dut = reorder_renamed_outputs_dut(dut)

    dut.place_input([6,2,7,5], [1,1,1,1])

    await Timer(1, "ns")

    sorted_values = dut.get_output()
    assert sorted_values == [6,2,7,5]


@cocotb.test()
async def reorder_renamed_outputs_last_invalid(dut):

    dut = reorder_renamed_outputs_dut(dut)

    dut.place_input([6,2,7,5], [1,1,1,0])

    await Timer(1, "ns")

    sorted_values = dut.get_output()
    assert sorted_values[0:3] == [6,2,7]


@cocotb.test()
async def reorder_renamed_outputs_first_last_invalid(dut):

    dut = reorder_renamed_outputs_dut(dut)

    dut.place_input([6,2,7,5], [0,1,1,0])

    await Timer(1, "ns")

    sorted_values = dut.get_output()
    assert sorted_values[1:3] == [6,2]


@cocotb.test()
async def reorder_renamed_outputs_random_invalid(dut):

    dut = reorder_renamed_outputs_dut(dut)

    dut.place_input([6,2,7,5], [0,1,0,1])

    await Timer(1, "ns")

    sorted_values = dut.get_output()
    assert sorted_values[1] == 6
    assert sorted_values[3] == 2
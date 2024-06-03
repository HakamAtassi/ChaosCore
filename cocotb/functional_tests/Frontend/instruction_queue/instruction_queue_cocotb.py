import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from instruction_queue_dut import *

@cocotb.test()
async def reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


# tests

# check ready bits

@cocotb.test()
async def ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    ready = dut.get_ready()

    assert ready["ready"][0] == 1
    assert ready["ready"][1] == 1
    assert ready["ready"][2] == 1
    assert ready["ready"][3] == 1

@cocotb.test()
async def write_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.print_fifo_contents()


    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x4
    inputs["RS2"][0] = 0x7
    inputs["valid"][0] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x4
    assert dut.get_fifo_contents()["RS2"][0] == 0x7


@cocotb.test()
async def write_4(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.print_fifo_contents()


    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x1
    inputs["RS2"][0] = 0x2
    inputs["valid"][0] = 1

    inputs["RS1"][1] = 0x3
    inputs["RS2"][1] = 0x4
    inputs["valid"][1] = 1

    inputs["RS1"][2] = 0x5
    inputs["RS2"][2] = 0x6
    inputs["valid"][2] = 1

    inputs["RS1"][3] = 0x7
    inputs["RS2"][3] = 0x8
    inputs["valid"][3] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x1
    assert dut.get_fifo_contents()["RS2"][0] == 0x2

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8


@cocotb.test()
async def write_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.print_fifo_contents()


    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x1
    inputs["RS2"][0] = 0x2
    inputs["valid"][0] = 1


    inputs["RS1"][3] = 0x3
    inputs["RS2"][3] = 0x4
    inputs["valid"][3] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x1
    assert dut.get_fifo_contents()["RS2"][0] == 0x2

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][1] = 0x5
    inputs["RS2"][1] = 0x6
    inputs["valid"][1] = 1

    inputs["RS1"][2] = 0x7
    inputs["RS2"][2] = 0x8
    inputs["valid"][2] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8


@cocotb.test()
async def read_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.print_fifo_contents()


    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x1
    inputs["RS2"][0] = 0x2
    inputs["valid"][0] = 1

    inputs["RS1"][1] = 0x3
    inputs["RS2"][1] = 0x4
    inputs["valid"][1] = 1

    inputs["RS1"][2] = 0x5
    inputs["RS2"][2] = 0x6
    inputs["valid"][2] = 1

    inputs["RS1"][3] = 0x7
    inputs["RS2"][3] = 0x8
    inputs["valid"][3] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x1
    assert dut.get_fifo_contents()["RS2"][0] == 0x2

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.get_outputs()["valid"][0]   == 1
    dut.get_outputs()["RS1"][0]     == 1
    dut.get_outputs()["RS2"][0]     == 2

    dut.get_outputs()["valid"][1]   == 1
    dut.get_outputs()["RS1"][1]     == 3
    dut.get_outputs()["RS2"][1]     == 4

    dut.get_outputs()["valid"][2]   == 1
    dut.get_outputs()["RS1"][2]     == 5
    dut.get_outputs()["RS2"][2]     == 6

    dut.get_outputs()["valid"][3]   == 1
    dut.get_outputs()["RS1"][3]     == 7
    dut.get_outputs()["RS2"][3]     == 8


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    read = generate_null_read()
    read["ready"][0] = 1

    dut.read_fifo(read)

    await RisingEdge(dut.clock())

    dut.read_fifo(generate_null_read())

    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x0
    assert dut.get_fifo_contents()["RS2"][0] == 0x0

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8

@cocotb.test()
async def read_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.print_fifo_contents()


    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x1
    inputs["RS2"][0] = 0x2
    inputs["valid"][0] = 1

    inputs["RS1"][1] = 0x3
    inputs["RS2"][1] = 0x4
    inputs["valid"][1] = 1

    inputs["RS1"][2] = 0x5
    inputs["RS2"][2] = 0x6
    inputs["valid"][2] = 1

    inputs["RS1"][3] = 0x7
    inputs["RS2"][3] = 0x8
    inputs["valid"][3] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x1
    assert dut.get_fifo_contents()["RS2"][0] == 0x2

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.get_outputs()["valid"][0]   == 1
    dut.get_outputs()["RS1"][0]     == 1
    dut.get_outputs()["RS2"][0]     == 2

    dut.get_outputs()["valid"][1]   == 1
    dut.get_outputs()["RS1"][1]     == 3
    dut.get_outputs()["RS2"][1]     == 4

    dut.get_outputs()["valid"][2]   == 1
    dut.get_outputs()["RS1"][2]     == 5
    dut.get_outputs()["RS2"][2]     == 6

    dut.get_outputs()["valid"][3]   == 1
    dut.get_outputs()["RS1"][3]     == 7
    dut.get_outputs()["RS2"][3]     == 8


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    read = generate_null_read()
    read["ready"][0] = 1
    read["ready"][1] = 1

    dut.read_fifo(read)

    await RisingEdge(dut.clock())

    dut.read_fifo(generate_null_read())

    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x0
    assert dut.get_fifo_contents()["RS2"][0] == 0x0

    assert dut.get_fifo_contents()["RS1"][1] == 0x0
    assert dut.get_fifo_contents()["RS2"][1] == 0x0

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8

@cocotb.test()
async def read_not_themometer_coded(dut):

    """Should ignore all ready bits after the first 0. Should not free entries with high ready if proceeding a ready 0"""    
    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.print_fifo_contents()


    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x1
    inputs["RS2"][0] = 0x2
    inputs["valid"][0] = 1

    inputs["RS1"][1] = 0x3
    inputs["RS2"][1] = 0x4
    inputs["valid"][1] = 1

    inputs["RS1"][2] = 0x5
    inputs["RS2"][2] = 0x6
    inputs["valid"][2] = 1

    inputs["RS1"][3] = 0x7
    inputs["RS2"][3] = 0x8
    inputs["valid"][3] = 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo(generate_null_input())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x1
    assert dut.get_fifo_contents()["RS2"][0] == 0x2

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    dut.get_outputs()["valid"][0]   == 1
    dut.get_outputs()["RS1"][0]     == 1
    dut.get_outputs()["RS2"][0]     == 2

    dut.get_outputs()["valid"][1]   == 1
    dut.get_outputs()["RS1"][1]     == 3
    dut.get_outputs()["RS2"][1]     == 4

    dut.get_outputs()["valid"][2]   == 1
    dut.get_outputs()["RS1"][2]     == 5
    dut.get_outputs()["RS2"][2]     == 6

    dut.get_outputs()["valid"][3]   == 1
    dut.get_outputs()["RS1"][3]     == 7
    dut.get_outputs()["RS2"][3]     == 8


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    read = generate_null_read()
    read["ready"][0] = 1
    read["ready"][3] = 1

    dut.read_fifo(read)

    await RisingEdge(dut.clock())

    dut.read_fifo(generate_null_read())

    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0x0
    assert dut.get_fifo_contents()["RS2"][0] == 0x0

    assert dut.get_fifo_contents()["RS1"][1] == 0x3
    assert dut.get_fifo_contents()["RS2"][1] == 0x4

    assert dut.get_fifo_contents()["RS1"][2] == 0x5
    assert dut.get_fifo_contents()["RS2"][2] == 0x6

    assert dut.get_fifo_contents()["RS1"][3] == 0x7
    assert dut.get_fifo_contents()["RS2"][3] == 0x8



@cocotb.test()
async def full(dut):
    """should lower its ready bits when it starts to get full"""
    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    inputs = generate_null_input()


    inputs["RS1"][0] = 0x1
    inputs["RS2"][0] = 0x2
    inputs["valid"][0] = 1

    for _ in range(4):
        dut.write_fifo(inputs)
        await RisingEdge(dut.clock())

    dut.write_fifo(generate_null_input())
    await ReadOnly()
    assert dut.get_ready()["ready"] == [1,1,1,1]

    ##
    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)
    await RisingEdge(dut.clock())

    dut.write_fifo(generate_null_input())
    await ReadOnly()

    assert dut.get_ready()["ready"] == [1,1,1,0]

    ##

    await RisingEdge(dut.clock())
    dut.write_fifo(inputs)
    await RisingEdge(dut.clock())

    dut.write_fifo(generate_null_input())
    await ReadOnly()

    assert dut.get_ready()["ready"] == [1,1,0,0]

    ##
    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)
    await RisingEdge(dut.clock())

    dut.write_fifo(generate_null_input())
    await ReadOnly()

    assert dut.get_ready()["ready"] == [1,0,0,0]

    ##

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)
    await RisingEdge(dut.clock())

    dut.write_fifo(generate_null_input())
    await ReadOnly()

    assert dut.get_ready()["ready"] == [0,0,0,0]

    ##

    await RisingEdge(dut.clock())

    read = generate_null_read()
    read["ready"][0] = 1

    dut.read_fifo(read)

    await RisingEdge(dut.clock())

    dut.read_fifo(generate_null_read())

    await ReadOnly()

    assert dut.get_ready()["ready"] == [1,0,0,0]

    ##

    await RisingEdge(dut.clock())

    read = generate_null_read()
    read["ready"][0] = 1

    dut.read_fifo(read)

    await RisingEdge(dut.clock())

    dut.read_fifo(generate_null_read())

    await ReadOnly()

    assert dut.get_ready()["ready"] == [1,1,0,0]

    ##

    await RisingEdge(dut.clock())

    read = generate_null_read()
    read["ready"][0] = 1
    read["ready"][1] = 1

    dut.read_fifo(read)

    await RisingEdge(dut.clock())

    dut.read_fifo(generate_null_read())

    await ReadOnly()

    assert dut.get_ready()["ready"] == [1,1,1,1]
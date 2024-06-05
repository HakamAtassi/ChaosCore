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
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


@cocotb.test()
async def test_write_one(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.print_fifo_contents()

    inputs = generate_null_input()


    inputs["valid"][0]     = 0x1
    inputs["RS1"][0]       = 0x1
    inputs["RS1_valid"][0] = 1

    inputs["RS2"][0]       = 0x2
    inputs["RS2_valid"][0] = 1

    #inputs["valid"][1]      = 0x1
    #inputs["RS2"][1]        = 0x2
    #inputs["RS2_valid"][1]  = 1


    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()


    assert dut.get_fifo_contents()["RS1"][0] == 1
    assert dut.get_fifo_contents()["RS2"][0] == 2




@cocotb.test()
async def test_write_all(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.print_fifo_contents()

    inputs = generate_null_input()


    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,3,4,5]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,7,8,9]
    inputs["RS2_valid"] = [1,1,1,1]



    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 2
    assert dut.get_fifo_contents()["RS2"][0] == 6

    assert dut.get_fifo_contents()["RS1"][1] == 3
    assert dut.get_fifo_contents()["RS2"][1] == 7

    assert dut.get_fifo_contents()["RS1"][2] == 4
    assert dut.get_fifo_contents()["RS2"][2] == 8

    assert dut.get_fifo_contents()["RS1"][3] == 5
    assert dut.get_fifo_contents()["RS2"][3] == 9

@cocotb.test()
async def test_full(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    dut.print_fifo_contents()

    inputs = generate_null_input()


    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,3,4,5]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,7,8,9]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # should be full after this

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 2
    assert dut.get_fifo_contents()["RS2"][0] == 6

    assert dut.get_fifo_contents()["RS1"][1] == 3
    assert dut.get_fifo_contents()["RS2"][1] == 7

    assert dut.get_fifo_contents()["RS1"][2] == 4
    assert dut.get_fifo_contents()["RS2"][2] == 8

    assert dut.get_fifo_contents()["RS1"][3] == 5
    assert dut.get_fifo_contents()["RS2"][3] == 9

    assert dut.get_fifo_contents()["RS1"][4] == 2
    assert dut.get_fifo_contents()["RS2"][4] == 6

    assert dut.get_fifo_contents()["RS1"][5] == 3
    assert dut.get_fifo_contents()["RS2"][5] == 7

    assert dut.get_fifo_contents()["RS1"][6] == 4
    assert dut.get_fifo_contents()["RS2"][6] == 8

    assert dut.get_fifo_contents()["RS1"][7] == 5
    assert dut.get_fifo_contents()["RS2"][7] == 9

    # check if its full

    dut.get_ready() == [0,0,0,0]

@cocotb.test()
async def test_full(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_outputs()["ready"] == [0,0,0,0]


@cocotb.test()
async def test_1_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    inputs["valid"]     = [1,1,1,0]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_outputs()["ready"] == [1,0,0,0]

@cocotb.test()
async def test_2_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    inputs["valid"]     = [1,1,0,0]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_outputs()["ready"] == [1,1,0,0]

@cocotb.test()
async def test_3_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    inputs["valid"]     = [1,0,0,0]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_outputs()["ready"] == [1,1,1,0]

@cocotb.test()
async def test_4_ready(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    inputs["valid"]     = [0,0,0,0]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    dut.print_fifo_contents()

    assert dut.get_outputs()["ready"] == [1,1,1,1]



@cocotb.test()
async def test_dequeue_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,0,0,0]

    dut.write_fifo(inputs)


    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,0,0,0]





@cocotb.test()
async def test_dequeue_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,0,0]

    dut.write_fifo(inputs)


    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,0,0]

@cocotb.test()
async def test_dequeue_3(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,1,0]

    dut.write_fifo(inputs)


    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,1,0]

@cocotb.test()
async def test_dequeue_4(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,1,1]

    dut.write_fifo(inputs)


    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,1,1]



@cocotb.test()
async def test_dequeue_4_write_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,2,2,2]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,6,6,6]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,1,1]

    #
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    # write 1

    inputs = generate_null_input()

    inputs["valid"]     = [1,0,0,0]
    inputs["RS1"]       = [9,0,0,0]
    inputs["RS1_valid"] = [1,0,0,0]

    inputs["RS2"]       = [7,0,0,0]
    inputs["RS2_valid"] = [1,0,0,0]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 7

    dut.print_fifo_contents()

@cocotb.test()
async def test_dequeue_4_write_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,2,2,2]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,6,6,6]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,1,1]

    #
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    # write 1

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,0,0]
    inputs["RS1"]       = [9,9,0,0]
    inputs["RS1_valid"] = [1,1,0,0]

    inputs["RS2"]       = [7,7,0,0]
    inputs["RS2_valid"] = [1,1,0,0]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 7

    assert dut.get_fifo_contents()["RS1"][1] == 9
    assert dut.get_fifo_contents()["RS2"][1] == 7

    dut.print_fifo_contents()

@cocotb.test()
async def test_dequeue_4_write_3(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,2,2,2]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,2,2,2]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,1,1]

    #
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    # write 1

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,0]
    inputs["RS1"]       = [9,9,6,0]
    inputs["RS1_valid"] = [1,1,1,0]

    inputs["RS2"]       = [7,7,3,0]
    inputs["RS2_valid"] = [1,1,1,0]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 7

    assert dut.get_fifo_contents()["RS1"][1] == 9
    assert dut.get_fifo_contents()["RS2"][1] == 7

    assert dut.get_fifo_contents()["RS1"][2] == 6
    assert dut.get_fifo_contents()["RS2"][2] == 3

    dut.print_fifo_contents()

@cocotb.test()
async def test_dequeue_4_write_4(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,2,2,2]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,6,6,6]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [0,0,0,0]

    # Read 1 entry

    await ReadWrite()
    inputs = generate_null_input()
    inputs["ready"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()

    assert dut.get_outputs()["ready"] == [1,1,1,1]

    #
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    # write 1

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [9,9,6,6]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [7,7,3,3]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)  # write 1

    await RisingEdge(dut.clock())
    await ReadOnly()

    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 7

    assert dut.get_fifo_contents()["RS1"][1] == 9
    assert dut.get_fifo_contents()["RS2"][1] == 7

    assert dut.get_fifo_contents()["RS1"][2] == 6
    assert dut.get_fifo_contents()["RS2"][2] == 3

    assert dut.get_fifo_contents()["RS1"][3] == 6
    assert dut.get_fifo_contents()["RS2"][3] == 3

    dut.print_fifo_contents()


@cocotb.test()
async def test_no_bubbles(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,0,1,0]
    inputs["RS1"]       = [9,9,6,6]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [7,7,3,3]
    inputs["RS2_valid"] = [1,1,1,1]


    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()


    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 7

    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 7



@cocotb.test()
async def test_read_write_1(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,0,0]
    inputs["RS1"]       = [9,10,0,0]
    inputs["RS1_valid"] = [1,1,0,0]

    inputs["RS2"]       = [11,12,0,0]
    inputs["RS2_valid"] = [1,1,0,0]


    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()


    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 11

    assert dut.get_fifo_contents()["RS1"][1] == 10
    assert dut.get_fifo_contents()["RS2"][1] == 12

    # write 1, read 1

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,0,0,0] # write 1
    inputs["RS1"]       = [11,0,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [13,0,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    inputs["ready"]     = [1,0,0,0] # read 1

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()
    
    dut.print_fifo_contents()

    #assert dut.get_fifo_contents()["RS1"][0] == 0
    #assert dut.get_fifo_contents()["RS2"][0] == 0

    assert dut.get_fifo_contents()["RS1"][1] == 10
    assert dut.get_fifo_contents()["RS2"][1] == 12

    assert dut.get_fifo_contents()["RS1"][2] == 11
    assert dut.get_fifo_contents()["RS2"][2] == 13


@cocotb.test()
async def test_read_write_2(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,0,0]
    inputs["RS1"]       = [9,10,0,0]
    inputs["RS1_valid"] = [1,1,0,0]

    inputs["RS2"]       = [11,12,0,0]
    inputs["RS2_valid"] = [1,1,0,0]


    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()


    assert dut.get_fifo_contents()["RS1"][0] == 9
    assert dut.get_fifo_contents()["RS2"][0] == 11

    assert dut.get_fifo_contents()["RS1"][1] == 10
    assert dut.get_fifo_contents()["RS2"][1] == 12

    # write 1, read 1

    await RisingEdge(dut.clock())

    inputs = generate_null_input()

    inputs["valid"]     = [1,1,0,0] # write 2
    inputs["RS1"]       = [14,15,0,0]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [16,17,0,0]
    inputs["RS2_valid"] = [1,1,1,1]

    inputs["ready"]     = [1,1,0,0] # read 2

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()
    
    dut.print_fifo_contents()

    assert dut.get_fifo_contents()["RS1"][0] == 0
    assert dut.get_fifo_contents()["RS2"][0] == 0

    assert dut.get_fifo_contents()["RS1"][1] == 0
    assert dut.get_fifo_contents()["RS2"][1] == 0

    assert dut.get_fifo_contents()["RS1"][2] == 14
    assert dut.get_fifo_contents()["RS2"][2] == 16

    assert dut.get_fifo_contents()["RS1"][3] == 15
    assert dut.get_fifo_contents()["RS2"][3] == 17






@cocotb.test()
async def test_no_overwrite(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_queue_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())


    inputs = generate_null_input()


    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [2,3,4,5]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [6,7,8,9]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # should be full after this

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()


    assert dut.get_fifo_contents()["RS1"][0] == 2
    assert dut.get_fifo_contents()["RS2"][0] == 6

    assert dut.get_fifo_contents()["RS1"][1] == 3
    assert dut.get_fifo_contents()["RS2"][1] == 7

    assert dut.get_fifo_contents()["RS1"][2] == 4
    assert dut.get_fifo_contents()["RS2"][2] == 8

    assert dut.get_fifo_contents()["RS1"][3] == 5
    assert dut.get_fifo_contents()["RS2"][3] == 9

    assert dut.get_fifo_contents()["RS1"][4] == 2
    assert dut.get_fifo_contents()["RS2"][4] == 6

    assert dut.get_fifo_contents()["RS1"][5] == 3
    assert dut.get_fifo_contents()["RS2"][5] == 7

    assert dut.get_fifo_contents()["RS1"][6] == 4
    assert dut.get_fifo_contents()["RS2"][6] == 8

    assert dut.get_fifo_contents()["RS1"][7] == 5
    assert dut.get_fifo_contents()["RS2"][7] == 9

    # check if its full

    dut.get_ready() == [0,0,0,0]


    # Try writing again and ensure no overwrite

    await RisingEdge(dut.clock())

    inputs["valid"]     = [1,1,1,1]
    inputs["RS1"]       = [20,20,20,20]
    inputs["RS1_valid"] = [1,1,1,1]

    inputs["RS2"]       = [20,20,20,20]
    inputs["RS2_valid"] = [1,1,1,1]

    dut.write_fifo(inputs)

    await RisingEdge(dut.clock())

    dut.write_fifo(inputs)  # should be full after this

    await RisingEdge(dut.clock())
    dut.write_fifo()
    await ReadOnly()


    dut.get_fifo_contents()["RS1"][0] != 20
    dut.get_fifo_contents()["RS1"][1] != 20
    dut.get_fifo_contents()["RS1"][2] != 20

    dut.get_fifo_contents()["RS2"][0] != 20
    dut.get_fifo_contents()["RS2"][1] != 20
    dut.get_fifo_contents()["RS2"][2] != 20

import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer

import random
import sys
from pathlib import Path


async def generateClock(dut):
    while(1):
        dut.clock.value = 0
        await Timer(1, units="ns")
        dut.clock.value = 1
        await Timer(1, units="ns")

async def reset(dut):
    dut.reset.value = 0
    await RisingEdge(dut.clock)
    dut.reset.value = 1
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)

@cocotb.test()
async def testWrite(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)

    # this test performs a write and checks if its value is available next cycle

    dut.io_wr_addr.value = 0xdeadbeef   # the address being written the stack
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0
    dut.io_wr_valid.value = 0
    await FallingEdge(dut.clock)
    assert dut.io_ret_addr.value == 0xdeadbeef
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

@cocotb.test()
async def testManyWrites(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)

    # this test performs a write and checks if its value is available next cycle

    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x1   # the address being written the stack
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x2
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x3
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x4
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x0
    dut.io_wr_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


@cocotb.test()
async def testReadWriteRead(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)

    # this test performs a write and checks if its value is available next cycle

    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x1   # the address being written the stack
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x2
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x3
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x4
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x5
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x6
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 0
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x7
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_addr.value = 0x8
    dut.io_wr_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_wr_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_rd_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
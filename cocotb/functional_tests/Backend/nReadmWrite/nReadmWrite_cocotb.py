import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from model_utils import *

from nReadmWriteDut import *

@cocotb.test()
async def simple_reset(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


@cocotb.test()
async def simple_writes(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    for i in range(64):
        dut.write(addr_in=[i,0,0,0], wr_en=[1,0,0,0], data_in=[i,0,0,0])
        await RisingEdge(dut.clock())
        dut.write()
    
    for i in range(64):
        dut.read(addr_in=[i,0,0,0,0,0,0,0])
        await RisingEdge(dut.clock())
        await ReadOnly()
        outputs = dut.get_output()
        assert outputs[0] == i
        await ReadWrite()

@cocotb.test()
async def simple_writes_4_wide(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    for i in range(0,64,4):
        dut.write(addr_in=[i,i+1,i+2,i+3], wr_en=[1,1,1,1], data_in=[i,i+1,i+2,i+3])
        await RisingEdge(dut.clock())
        dut.write()
    
    for i in range(64):
        dut.read(addr_in=[i,0,0,0,0,0,0,0])
        await RisingEdge(dut.clock())
        await ReadOnly()
        outputs = dut.get_output()
        assert outputs[0] == i
        await ReadWrite()

@cocotb.test()
async def simple_writes_4_wide_8_wide(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    for i in range(0,64,4):
        dut.write(addr_in=[i,i+1,i+2,i+3], wr_en=[1,1,1,1], data_in=[i,i+1,i+2,i+3])
        await RisingEdge(dut.clock())
        dut.write()
    
    for i in range(0,64,8):
        dut.read(addr_in=[i,i+1,i+2,i+3,i+4,i+5,i+6,i+7])
        await RisingEdge(dut.clock())
        await ReadOnly()
        outputs = dut.get_output()
        assert outputs[0] == i + 0
        assert outputs[1] == i + 1
        assert outputs[2] == i + 2
        assert outputs[3] == i + 3
        assert outputs[4] == i + 4
        assert outputs[5] == i + 5
        assert outputs[6] == i + 6
        assert outputs[7] == i + 7
        await ReadWrite()

@cocotb.test()
async def fuzz_writes_4_wide_8_wide(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)

    dut = nReadmWrite(dut)

    mem=[0]*64

    for _ in range(10000):
        wr_en0   = random.randint(0,1)
        wr_addr0 = random.randint(0, 63)
        wr_data0 = random.randint(0, (1<<32)-1)

        wr_en1   = random.randint(0,1)
        wr_addr1 = random.randint(0, 63)
        wr_data1 = random.randint(0, (1<<32)-1)

        wr_en2   = random.randint(0,1)
        wr_addr2 = random.randint(0, 63)
        wr_data2 = random.randint(0, (1<<32)-1)

        wr_en3   = random.randint(0,1)
        wr_addr3 = random.randint(0, 63)
        wr_data3 = random.randint(0, (1<<32)-1)

        addr_in     =[wr_addr0, wr_addr1, wr_addr2, wr_addr3]
        wr_en       =[wr_en0, wr_en1, wr_en2, wr_en3]
        wr_data_in  =[wr_data0, wr_data1, wr_data2, wr_data3]

        dut.write(addr_in=addr_in, wr_en=wr_en, data_in=wr_data_in)

        if(wr_en0): mem[wr_addr0] = wr_data0; print(f"mem[{wr_addr0}] = {wr_data0}")
        if(wr_en1): mem[wr_addr1] = wr_data1; print(f"mem[{wr_addr1}] = {wr_data1}")
        if(wr_en2): mem[wr_addr2] = wr_data2; print(f"mem[{wr_addr2}] = {wr_data2}")
        if(wr_en3): mem[wr_addr3] = wr_data3; print(f"mem[{wr_addr3}] = {wr_data3}")

        await RisingEdge(dut.clock())

        dut.write()

        rd_addr0 = random.randint(0, 63)
        rd_addr1 = random.randint(0, 63)
        rd_addr2 = random.randint(0, 63)
        rd_addr3 = random.randint(0, 63)
        rd_addr4 = random.randint(0, 63)
        rd_addr5 = random.randint(0, 63)
        rd_addr6 = random.randint(0, 63)
        rd_addr7 = random.randint(0, 63)

        rd_addr_in=[rd_addr0, rd_addr1, rd_addr2, rd_addr3, rd_addr4, rd_addr5, rd_addr6, rd_addr7]

        dut.read(addr_in=rd_addr_in)
    
        await RisingEdge(dut.clock())
        
        await ReadOnly()

        outputs = dut.get_output()

        assert outputs[0] == mem[rd_addr0]
        assert outputs[1] == mem[rd_addr1]
        assert outputs[2] == mem[rd_addr2]
        assert outputs[3] == mem[rd_addr3]
        assert outputs[4] == mem[rd_addr4]
        assert outputs[5] == mem[rd_addr5]
        assert outputs[6] == mem[rd_addr6]
        assert outputs[7] == mem[rd_addr7]

        await ReadWrite()



import random
import numpy as np
import math
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer

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


async def initDmem(dut,lineSizeBytes, ways, sets):
    for i in range(lineSizeBytes):
        for way in range(ways):
            for set in range(sets):
                addr = way*sets + set
                memoryByte = getattr(dut, f"data_memory_{i}").mem_ext.Memory[addr].value = random.randint(0x1,0xFF)



async def initTags(dut, lineSizeBytes, ways, sets):    # doesnt use ways
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    for set in range(sets):
        tagLine=0
        for way in range(ways):
            tagLine = (tagLine<<tagSize) | (set*4+(ways-way-1))
        dut.tag_memory.mem_ext.Memory[set].value = (tagLine & 0xfffffffffffffffffffff)

async def printDmem(dut,lineSizeBytes, ways, sets):
    print("DATA MEM")
    print(f"00 00: ", end="")
    for byte in range(lineSizeBytes):
        print(f"{byte:0{2}} ", end="")
    print("<= byte")
    for way in range(ways):
        for set in range(sets):
            print(f"{way:02} {set:02}: ", end="")
            for i in range(lineSizeBytes):
                addr = way*sets + set
                memoryByte = int(getattr(dut, f"data_memory_{i}").mem_ext.Memory[addr].value)
                print(f"{memoryByte:0{2}x} ",end="")
            print("")

async def printTags(dut,lineSizeBytes, ways, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("TAG MEM")
    for set in range(sets):
        tagLine = 0
        for way in range(ways):
            tagLine = (tagLine << tagSize) | (set*4 + (ways-way))
        data = int(dut.tag_memory.mem_ext.Memory[set].value)
        print(f"{set:02}: {data:0{21}x}")

def constructAddress(tag, set, byteOffset, lineSizeBytes, sets):
    addr = 0
    tagSize = int(np.ceil(np.log2(lineSizeBytes) + np.log2(sets)))
    addr = tag << tagSize
    addr = addr | (set << int(np.log2(lineSizeBytes)))
    addr = addr | (byteOffset)
    return addr

async def requestRead(dut, addr):
    dut.io_controller_addr.value = addr
    dut.io_controller_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_controller_valid.value = 0
    pass

async def requestWrite(dut, addr, data):
    pass

@cocotb.test()
async def test0(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)


    await initDmem(dut, lineSizeBytes=32, ways=4, sets=64)
    await initTags(dut, lineSizeBytes=32, ways=4, sets=64)
    await RisingEdge(dut.clock)
    await printDmem(dut, lineSizeBytes=32, ways=4, sets=64)
    await printTags(dut, lineSizeBytes=32, ways=4, sets=64)


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    await requestRead(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64))


    for _ in range(100):
        await RisingEdge(dut.clock)
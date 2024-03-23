import random
import numpy as np
import math
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
import sys


sys.path.append('../../UVM/cache/model')
#from model.cacheMem import *

from cacheMem import *
sys.path.append('../../UVM/cache')
#from cacheUtils import *
from cacheUtils import *
from utils import *


cmd={
    "LB" : 0x0,
    "LHW": 0x1,
    "LW" : 0x2,

    "NOP" : 0x3,

    "SB" : 0x4,
    "SHW": 0x5,
    "SW" : 0x6,

    "ALLOCATE" : 0x7
}


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
                getattr(dut, f"data_memory_{i}").ram_ext.Memory[addr].value = random.randint(0x1,0xFF)



async def initTags(dut, lineSizeBytes, ways, sets):    # doesnt use ways
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    for set in range(sets):
        tagLine=0
        for way in range(ways):
            #tagLine = (tagLine<<tagSize) | (set*4+(ways-way-1))
            tagLine = (tagLine<<tagSize) | (ways-way-1)
        dut.tag_memory.ram_ext.Memory[set].value = (tagLine & 0xfffffffffffffffffffff)

async def setTags(dut, arr, lineSizeBytes, ways, sets):
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    for set in range(sets):
        tagLine=0
        for way in range(ways):
            tagLine = (tagLine<<tagSize) | arr[way]
        dut.tag_memory.ram_ext.Memory[set].value = (tagLine & 0xfffffffffffffffffffff)


async def printDmem(dut,lineSizeBytes, ways, sets):
    print("DATA MEM")
    print(f"## ##: ", end="")
    for byte in range(lineSizeBytes):
        print(f"{byte:0{2}} ", end="")
    print("<= byte")
    for way in range(ways):
        for set in range(sets):
            print(f"{way:02} {set:02}: ", end="")
            for i in range(lineSizeBytes):
                addr = way*sets + set
                memoryByte = int(getattr(dut, f"data_memory_{i}").ram_ext.Memory[addr].value)
                print(f"{memoryByte:0{2}x} ",end="")
            print("")

async def getDmemByte(dut, byte, way, set):
    return int(getattr(dut, f"data_memory_{31-byte}").ram_ext.Memory[way*64 + set].value)

async def printTags(dut,lineSizeBytes, ways, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("TAG MEM")
    for set in range(sets):
        data = int(dut.tag_memory.ram_ext.Memory[set].value)
        tag0 = data & 0x1F_FFFF
        tag1 = (data>>21) & 0x1F_FFFF
        tag2 = (data>>42) & 0x1F_FFFF
        tag3 = (data>>63) & 0x1F_FFFF
        print(f"{set:02}: {hex(tag3)} {hex(tag2)} {hex(tag1)} {hex(tag0)}")
        #print(f"{set:02}: {data:0{21}x}")


async def printDirty(dut,lineSizeBytes, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("DIRTY MEM")
    for set in range(sets):
        data = int(dut.dirty_memory.mem_ext.Memory[set].value)
        print(f"{set:02}: {data}")

async def printValid(dut,lineSizeBytes, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("Valid MEM")
    for set in range(sets):
        data = int(dut.valid_memory.mem_ext.Memory[set].value)
        print(f"{set:02}: {data}")

async def printPLRU(dut,lineSizeBytes, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("PLRU MEM")
    for set in range(sets):
        data = int(dut.PLRU_memory.mem_ext.Memory[set].value)
        print(f"{set:02}: {data}")

async def getPLRU(dut, line):
    return int(dut.PLRU_memory.mem_ext.Memory[line].value)

async def getValid(dut, line):
    return int(dut.valid_memory.mem_ext.Memory[line].value)

async def getDirty(dut, line):
    return int(dut.dirty_memory.mem_ext.Memory[line].value)

def constructAddress(tag, set, byteOffset, lineSizeBytes, sets):
    addr = 0
    tagSize = int(np.ceil(np.log2(lineSizeBytes) + np.log2(sets)))
    addr = tag << tagSize
    addr = addr | (set << int(np.log2(lineSizeBytes)))
    addr = addr | (byteOffset)
    return addr

async def requestRead(dut, addr, cmd):
    assert cmd <= 0x3, "Write command in Read function"
    dut.io_controller_addr.value = addr
    dut.io_controller_valid.value = 1
    dut.io_controller_cmd.value = cmd
    await RisingEdge(dut.clock)
    dut.io_controller_valid.value = 0
    pass

async def requestWrite(dut, addr, cmd, data):   # This doesnt actually place any data on the allocate line...
    assert cmd >= 0x3, "Read command in Write function"
    dut.io_controller_addr.value = addr
    dut.io_controller_valid.value = 1
    dut.io_controller_data.value = data
    dut.io_controller_cmd.value = cmd
    await RisingEdge(dut.clock)
    dut.io_controller_valid.value = 0
    pass

async def requestAllocate(dut, addr, cmd, line):   # This doesnt actually place any data on the allocate line...
    assert cmd >= 0x3, "Read command in Write function"
    dut.io_controller_addr.value = addr
    dut.io_controller_valid.value = 1
    dut.io_controller_data.value = 0x0
    dut.io_controller_cache_line.value = line
    dut.io_controller_cmd.value = cmd
    await RisingEdge(dut.clock)
    dut.io_controller_valid.value = 0
    pass

def splitLine(line, count, width):
    mask = (1 << width) - 1
    elements = []
    for i in range(count):
        element = (line >> (i * width)) & mask
        elements.insert(0, element)
    return elements

async def getTagArr(dut, set):
    tags= int(dut.tag_memory.ram_ext.Memory[set].value)
    tagArr = list(reversed(splitLine(tags, 4, 21)))
    return tagArr

@cocotb.test()
async def writeRead(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)

    await initDmem(dut, lineSizeBytes=32, ways=4, sets=64)
    await setTags(cocotb.top, [0x4, 0x3, 0x2, 0x1], 32, 4, 64)

    await RisingEdge(dut.clock)
    await printTags(dut, 32, 4, 64)    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    # Try Writing (should miss)

    await requestWrite(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SW"], data=0x42)
    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    print(await getDmemByte(dut, 0, 0, 0))

    await requestAllocate(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], line=0x42)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert await getValid(dut, 0) == 0b0001, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0000, f"Dirty should be 0 (just allocated)"
    assert (await getTagArr(dut, 0))[0] == 0b0, f"allocate tag in way 0"


    await requestWrite(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SB"], data=0xF1)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 0, 0) == 0xF1, f"SB should have succeeded"
    assert int(dut.io_cache_valid.value) == 1, f"SB should have succeeded"
    assert await getValid(dut, 0) == 0b0001, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert await getPLRU(dut, 0) == 0b0001


    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 0, 0) == 0xF1, f"SB should have succeeded"
    assert int(dut.io_cache_valid.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_hit.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_dout.value) == 0xF1, f"SB should have succeeded"
    assert await getValid(dut, 0) == 0b0001, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert await getPLRU(dut, 0) == 0b0001

    await requestRead(dut, constructAddress(tag = 4, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 0, 0) == 0xF1, f"SB should have succeeded"
    assert int(dut.io_cache_valid.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_hit.value) == 0, f"SB should have succeeded"
    assert await getValid(dut, 0) == 0b0001, f"Valid should be asserted (just allocated)"
    assert await getValid(dut, 0) == 0b0001, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert await getPLRU(dut, 0) == 0b0001


    await requestAllocate(dut, constructAddress(tag = 7, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], line=0x42)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert await getValid(dut, 0) == 0b0011, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert (await getTagArr(dut, 0))[0] == 0b0, f"allocate tag in way 0"
    assert (await getTagArr(dut, 0))[1] == 7, f"allocate tag in way 0"
    assert await getPLRU(dut, 0) == 0b0001


    await requestRead(dut, constructAddress(tag = 7, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 0, 0) == 0xF1, f"SB should have succeeded"
    assert int(dut.io_cache_valid.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_hit.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_dout.value) == 0x42, f"SB should have succeeded"
    assert await getValid(dut, 0) == 0b0011, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert await getPLRU(dut, 0) == 0b0011

    # read from existant but invalid tag
    await requestRead(dut, constructAddress(tag = 3, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 0, 0) == 0xF1
    assert int(dut.io_cache_valid.value) == 1
    assert int(dut.io_cache_hit.value) == 0
    assert int(dut.io_cache_dout.value) == 0x42
    assert await getValid(dut, 0) == 0b0011
    assert await getDirty(dut, 0) == 0b0001
    assert await getPLRU(dut, 0) == 0b0011


    await requestAllocate(dut, constructAddress(tag = 15, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], line=0xF9)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert await getValid(dut, 0) == 0b0111, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert (await getTagArr(dut, 0))[2] == 15, f"allocate tag in way 0"
    assert await getPLRU(dut, 0) == 0b0011

    await requestRead(dut, constructAddress(tag = 15, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 2, 0) == 0xF9, f"SB should have succeeded"
    assert int(dut.io_cache_valid.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_hit.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_dout.value) == 0xF9, f"SB should have succeeded"
    assert await getValid(dut, 0) == 0b0111, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert await getPLRU(dut, 0) == 0b0111

    await requestAllocate(dut, constructAddress(tag = 0xdead, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], line=0xFF)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert await getValid(dut, 0) == 0b1111, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert (await getTagArr(dut, 0))[3] == 0xdead, f"allocate tag in way 0"
    assert await getPLRU(dut, 0) == 0b0111

    await requestRead(dut, constructAddress(tag = 0xdead, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    assert await getDmemByte(dut, 0, 3, 0) == 0xFF, f"SB should have succeeded"
    assert int(dut.io_cache_valid.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_hit.value) == 1, f"SB should have succeeded"
    assert int(dut.io_cache_dout.value) == 0xFF, f"SB should have succeeded"
    assert await getValid(dut, 0) == 0b1111, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0001, f"Dirty should be 0 (just allocated)"
    assert await getPLRU(dut, 0) == 0b1000

    # this should reset dirty lsb
    await requestAllocate(dut, constructAddress(tag = 0xface, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], line=0x99)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert await getValid(dut, 0) == 0b1111, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0000 # Bug here
    assert (await getTagArr(dut, 0))[0] == 0xface, f"allocate tag in way 0"
    assert await getPLRU(dut, 0) == 0b1000
    

    # this should reset dirty lsb
    await requestAllocate(dut, constructAddress(tag = 0xface, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], line=0x99)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert await getValid(dut, 0) == 0b1111, f"Valid should be asserted (just allocated)"
    assert await getDirty(dut, 0) == 0b0000 # Bug here
    assert (await getTagArr(dut, 0))[0] == 0xface, f"allocate tag in way 0"
    assert await getPLRU(dut, 0) == 0b1000



    await printTags(dut, 32, 4, 64)    

    for _ in range(100):
        await RisingEdge(dut.clock)


import random
import numpy as np
import math
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer


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

async def requestWrite(dut, addr, cmd, data):
    assert cmd >= 0x3, "Read command in Write function"
    dut.io_controller_addr.value = addr
    dut.io_controller_valid.value = 1
    dut.io_controller_data.value = data
    dut.io_controller_cmd.value = cmd
    await RisingEdge(dut.clock)
    dut.io_controller_valid.value = 0
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

    # for these tests, tag = way (because we forced tag mem to story [3][2][1][0]) <= set 0
    #                                                                [3][2][1][0]  <= set 1
    #                                                                ...
    #                                                                [3][2][1][0]  <= set 63
    #await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    #await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LHW"])
    #await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LB"])

    #await requestRead(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    #await requestRead(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LHW"])
    #await requestRead(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LB"])


    #await requestRead(dut, constructAddress(tag = 2, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    #await requestRead(dut, constructAddress(tag = 2, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LHW"])
    #await requestRead(dut, constructAddress(tag = 2, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LB"])

    #await requestRead(dut, constructAddress(tag = 3, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    #await requestRead(dut, constructAddress(tag = 3, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LHW"])
    #await requestRead(dut, constructAddress(tag = 3, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LB"])
    
    ## test load byte at various offsets
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    for way in range(4):
        for byte in range(32):
            await requestRead(dut, constructAddress(tag = way, set=0, byteOffset=byte, lineSizeBytes=32, sets=64), cmd=cmd["LB"])
        await RisingEdge(dut.clock)

    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    for way in range(4):
        for byte in range(32):
            await requestRead(dut, constructAddress(tag = way, set=31, byteOffset=byte, lineSizeBytes=32, sets=64), cmd=cmd["LB"])
        await RisingEdge(dut.clock)


    for _ in range(100):
        await RisingEdge(dut.clock)



@cocotb.test()
async def test1(dut):

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

    # for these tests, tag = way (because we forced tag mem to story [3][2][1][0]) <= set 0
    #                                                                [3][2][1][0]  <= set 1
    #                                                                ...
    #                                                                [3][2][1][0]  <= set 63
    ## test load byte at various offsets
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    for way in range(4):
        for byte in range(0,32,4):
            await requestRead(dut, constructAddress(tag = way, set=0, byteOffset=byte, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
        await RisingEdge(dut.clock)

    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    for way in range(4):
        for byte in range(0,32,4):
            await requestRead(dut, constructAddress(tag = way, set=31, byteOffset=byte, lineSizeBytes=32, sets=64), cmd=cmd["LB"])
        await RisingEdge(dut.clock)


    for _ in range(100):
        await RisingEdge(dut.clock)

@cocotb.test()
async def test2(dut):

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

    # for these tests, tag = way (because we forced tag mem to story [3][2][1][0]) <= set 0
    #                                                                [3][2][1][0]  <= set 1
    #                                                                ...
    #                                                                [3][2][1][0]  <= set 63
    ## test load byte at various offsets
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    for way in range(4):
        for byte in range(0,32,4):
            await requestRead(dut, constructAddress(tag = 0x42, set=0, byteOffset=byte, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
        await RisingEdge(dut.clock)

    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    for way in range(4):
        for byte in range(0,32,4):
            await requestRead(dut, constructAddress(tag = 0x42, set=31, byteOffset=byte, lineSizeBytes=32, sets=64), cmd=cmd["LB"])
        await RisingEdge(dut.clock)


    for _ in range(100):
        await RisingEdge(dut.clock)

    
@cocotb.test()
async def test3(dut):

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

    # for these tests, tag = way (because we forced tag mem to story [3][2][1][0]) <= set 0
    #                                                                [3][2][1][0]  <= set 1
    #                                                                ...
    #                                                                [3][2][1][0]  <= set 63
    ## test load byte at various offsets
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    await requestWrite(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SW"], data=0x4242_4242)
    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])

    await requestWrite(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SHW"], data=0x0000_7272)
    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await requestWrite(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SB"], data=0x0000_0091)

    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"])
    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LHW"])
    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LB"])

    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    for _ in range(100):
        await RisingEdge(dut.clock)

    
    await printDmem(dut, lineSizeBytes=32, ways=4, sets=64)


@cocotb.test()
async def test4(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)


    await initDmem(dut, lineSizeBytes=32, ways=4, sets=64)
    await initTags(dut, lineSizeBytes=32, ways=4, sets=64)
    await RisingEdge(dut.clock)
    await printDmem(dut, lineSizeBytes=32, ways=4, sets=64)
    await printTags(dut, lineSizeBytes=32, ways=4, sets=64)
    await printDirty(dut, lineSizeBytes=32, sets=64)


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    await requestWrite(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SW"], data=0x42) 
    await requestWrite(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SW"], data=0x42) 
    await requestWrite(dut, constructAddress(tag = 2, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SW"], data=0x42) 
    await requestWrite(dut, constructAddress(tag = 3, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["SW"], data=0x42) 

    await requestRead(dut, constructAddress(tag = 0, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"]) 
    await requestRead(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"]) 
    await requestRead(dut, constructAddress(tag = 2, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"]) 
    await requestRead(dut, constructAddress(tag = 3, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"]) 

    await requestWrite(dut, constructAddress(tag = 0x42, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    #await requestRead(dut, constructAddress(tag = 1, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"]) ## FIX way (allocates in reverse)
    #await requestRead(dut, constructAddress(tag = 2, set=0, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["LW"]) ## FIX way (allocates in reverse)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    #await requestWrite(dut, constructAddress(tag = 0, set=1, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)
    #await requestWrite(dut, constructAddress(tag = 0, set=2, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)
    #await requestWrite(dut, constructAddress(tag = 0, set=2, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)
    #await requestWrite(dut, constructAddress(tag = 0, set=1, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)
    #await requestWrite(dut, constructAddress(tag = 0, set=2, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)
    #await requestWrite(dut, constructAddress(tag = 0, set=3, byteOffset=0, lineSizeBytes=32, sets=64), cmd=cmd["ALLOCATE"], data=0x0)

    
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    await printDmem(dut, lineSizeBytes=32, ways=4, sets=64)
    await printTags(dut, lineSizeBytes=32, ways=4, sets=64)
    await printDirty(dut, lineSizeBytes=32, sets=64)

# TODO: UVM
# Then ... 
# TODO: MSHR stuff
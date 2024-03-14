import random
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

# CACHE LINE STRUCTURE [VALID, DIRTY, PLRU, TAG, DATA] 
def constructCacheline(valid, dirty, plru, tag, data):
    return (((((valid << 2) | (dirty << 1) | (plru << 0)) << 20) | tag) << 512) | data

def getData(line):
    line=int(line)
    data = line & ((1<<512)-1)
    return data
    



# CACHE LINE STRUCTURE [VALID, DIRTY, PLRU, TAG, DATA] 
async def initCache(dut):
    # int memories in the following manner
    #  way 0     way 1       way 2       way 3
    # [1][0][0][0x00][0x00]    [1][0][0][0x01][0x01]      [1][0][0][0x02][0x02]      [1][0][0][0x03][0x03]
    # [1][0][0][0x00][0x00]    [1][0][0][0x01][0x01]      [1][0][0][0x02][0x02]      [1][0][0][0x03][0x03]
    # [1][0][0][0x00][0x00]    [1][0][0][0x01][0x01]      [1][0][0][0x02][0x02]      [1][0][0][0x03][0x03]
    # ...
    #ie, mark valid as 1, tag as an incrementing counter, and data as the way the line resides in

    for set in range(64):
        for way in range(4):
            memory=getattr(dut,f"memories_{way}.mem_ext.Memory")
            memory[set].value = constructCacheline(1, 0, 0, way, way)

def printCache(dut):
    for set in range(64):
        print(f"Set: {set}: ", end="")
        for way in range(4):
            memory=getattr(dut,f"memories_{way}.mem_ext.Memory")
            line=int(memory[set].value)

            print(f"{hex(getData(line))} ", end="")
        print("")

async def requestCacheRead(dut, tag, set, byteOffset):
    dut.io_cpu_addr.value = constructAddress(tag, set, byteOffset)
    dut.io_cpu_valid.value = 1
    dut.io_cpu_data.value = 0
    dut.io_cpu_cmd.value = 0
    await RisingEdge(dut.clock)
    dut.io_cpu_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

async def testCacheRead(dut, tag, set, byteOffset):
    await requestCacheRead(dut, tag, set, byteOffset)

    await FallingEdge(dut.clock)
    assert int(dut.io_cache_valid.value) == 1, "output not valid"
    if(tag in [0,1,2,3]):
        assert int(dut.io_cache_hit.value) == 1, "Access did not hit"
        assert int(dut.io_cache_dout.value) == tag, "Data incorrect"
    else:
        assert int(dut.io_cache_hit.value) == 0, "Access did not miss"
    await RisingEdge(dut.clock)

async def requestCacheWrite(dut, tag, set, byteOffset, data):
    dut.io_cpu_addr.value = constructAddress(tag, set, byteOffset)
    dut.io_cpu_valid.value = 1
    dut.io_cpu_data.value = data
    dut.io_cpu_cmd.value = 1
    await RisingEdge(dut.clock)
    dut.io_cpu_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

def getWord(line, byteOffset): 
    
    return (line >> (byteOffset*8)) & 0xFFFF_FFFF
    



async def testCacheWrite(dut, tag, set, byteOffset, data):
    await requestCacheWrite(dut, tag, set, byteOffset, data)

    await FallingEdge(dut.clock)
    assert int(dut.io_cache_valid.value) == 1, "output not valid"
    if(tag in [0,1,2,3]):
        assert int(dut.io_cache_hit.value) == 1, "Access did not hit"
        # assert int(dut.io_cache_dout.value) == tag, "Data incorrect"
        # check if data has been written...
        memory=getattr(dut,f"memories_{tag}.mem_ext.Memory")
        line=int(memory[set].value)
        writtenWord = getWord(line, byteOffset)
        assert writtenWord == data, f"data not written"
    else:
        assert int(dut.io_cache_hit.value) == 0, "Access did not miss"



    await RisingEdge(dut.clock)




def constructAddress(tag, set, byteOffset):
    return (tag<<12) | (set << 6) | (byteOffset)


@cocotb.test()
async def test0(dut):
    # Test hits across all ways
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)
    await initCache(dut)

    await RisingEdge(dut.clock)
    #printCache(dut)

    for set in range(64):
        await testCacheRead(dut, tag = 0, set = set, byteOffset = 0)    # Hit
        await testCacheRead(dut, tag = 1, set = set, byteOffset = 0)    # Hit
        await testCacheRead(dut, tag = 2, set = set, byteOffset = 0)    # Hit
        await testCacheRead(dut, tag = 3, set = set, byteOffset = 0)    # Hit


    for set in range(64):
        await testCacheRead(dut, tag = 0, set = set, byteOffset = 0)    # Hit
        await testCacheRead(dut, tag = 1, set = set, byteOffset = 0)    # Hit
        await testCacheRead(dut, tag = 2, set = set, byteOffset = 0)    # Hit
        await testCacheRead(dut, tag = 3, set = set, byteOffset = 0)    # Hit



@cocotb.test()
async def test1(dut):
    # Test hits across all ways
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)
    await initCache(dut)

    await RisingEdge(dut.clock)
    #printCache(dut)

    for set in range(64):
        for _ in range(100):
            await testCacheRead(dut, tag = random.randint(0,0xFFFFF), set = set, byteOffset = 0)

@cocotb.test()
async def test2(dut):
    # Test hits across all ways
    # Test edge case
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)
    await initCache(dut)

    await RisingEdge(dut.clock)
    #printCache(dut)

    for set in range(64):
        await testCacheRead(dut, tag = 0x0, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0x1, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0x2, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0x4, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0x8, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0xF, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0xFFFF, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0xFFFF0, set = set, byteOffset = 0)
        await testCacheRead(dut, tag = 0xFFFFF, set = set, byteOffset = 0)


@cocotb.test()
async def test3(dut):
    # Test writes
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)
    await initCache(dut)

    await RisingEdge(dut.clock)
    #printCache(dut)


    for way in range(4):
        for set in range(64):
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 0, data = 0x42)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 4, data = 0x43)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 8, data = 0x44)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 16, data = 0x45)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 20, data = 0x46)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 24, data = 0x47)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 28, data = 0x48)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 32, data = 0x49)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 36, data = 0x4A)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 40, data = 0x4B)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 44, data = 0x4C)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 48, data = 0x4D)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 52, data = 0x4E)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 56, data = 0x4F)
            await testCacheWrite(dut, tag = way, set = set, byteOffset = 60, data = 0x50)
    

    for way in range(4):
        for set in range(64):
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 0, data = 0x42)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 4, data = 0x43)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 8, data = 0x44)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 16, data = 0x45)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 20, data = 0x46)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 24, data = 0x47)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 28, data = 0x48)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 32, data = 0x49)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 36, data = 0x4A)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 40, data = 0x4B)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 44, data = 0x4C)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 48, data = 0x4D)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 52, data = 0x4E)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 56, data = 0x4F)
            await testCacheWrite(dut, tag = way, set = 0x5, byteOffset = 60, data = 0x50)

# fix byte select
# test read, write, data, etc more carefully with valid, dirty and plru for all ways simultanously...

def getMemoryLine(dut, way, set):
    memory=getattr(dut,f"memories_{way}.mem_ext.Memory")
    line=int(memory[set].value)
    return line

def getMetadata(dut, way, set):
    memory=getattr(dut,f"memories_{way}.mem_ext.Memory")
    line=int(memory[set].value)
    return line >> (512 + 20)
    
@cocotb.test()
async def test4(dut):
    # Test a single set very carefully
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 
    await reset(dut)

    await RisingEdge(dut.clock)
    #await initCache(dut)

    await RisingEdge(dut.clock)

    # update 

    memory=getattr(dut,f"memories_{0}.mem_ext.Memory")
    memory[0].value = constructCacheline(1, 0, 0, 0, 0xDEAD0000)

    memory=getattr(dut,f"memories_{1}.mem_ext.Memory")
    memory[0].value = constructCacheline(1, 0, 0, 1, 0xDEAD0001)

    memory=getattr(dut,f"memories_{2}.mem_ext.Memory")
    memory[0].value = constructCacheline(1, 0, 0, 2, 0xDEAD0002)

    memory=getattr(dut,f"memories_{3}.mem_ext.Memory")
    memory[0].value = constructCacheline(1, 0, 0, 3, 0xDEAD0003)

    await RisingEdge(dut.clock)
    printCache(dut)

    line0 = getMemoryLine(dut, 0, 0)
    line1 = getMemoryLine(dut, 1, 0)
    line2 = getMemoryLine(dut, 2, 0)
    line3 = getMemoryLine(dut, 3, 0)

    print(f"{hex(line0)}\n{hex(line1)}\n{hex(line2)}\n{hex(line3)}")


    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check starting metadata
    assert metadata0 == 4, "Metadata incorrect"
    assert metadata1 == 4, "Metadata incorrect"
    assert metadata2 == 4, "Metadata incorrect"
    assert metadata3 == 4, "Metadata incorrect"

    # Request first read
    await requestCacheRead(dut, 0, 0, 0)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 5, "Metadata incorrect" # PLRU should be set after read
    assert metadata1 == 4, "Metadata incorrect"
    assert metadata2 == 4, "Metadata incorrect"
    assert metadata3 == 4, "Metadata incorrect"


    # Request second read (same as above)
    await requestCacheRead(dut, 0, 0, 0)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 5, "Metadata incorrect" # no change
    assert metadata1 == 4, "Metadata incorrect"
    assert metadata2 == 4, "Metadata incorrect"
    assert metadata3 == 4, "Metadata incorrect"


    # Request third read
    await requestCacheRead(dut, 1, 0, 0)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 5, "Metadata incorrect" # no change
    assert metadata1 == 5, "Metadata incorrect" # set plru
    assert metadata2 == 4, "Metadata incorrect"
    assert metadata3 == 4, "Metadata incorrect"

    # Request third read
    await requestCacheRead(dut, 2, 0, 0)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 5, "Metadata incorrect" # no change
    assert metadata1 == 5, "Metadata incorrect" # set plru
    assert metadata2 == 5, "Metadata incorrect" # set plru
    assert metadata3 == 4, "Metadata incorrect"


    # Request read
    await requestCacheRead(dut, 3, 0, 0)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 4, "Metadata incorrect" # reset PLRU
    assert metadata1 == 4, "Metadata incorrect" # reset PLRU 
    assert metadata2 == 4, "Metadata incorrect" # reset PLRU
    assert metadata3 == 5, "Metadata incorrect" # set PLRU

    # Request read
    await requestCacheRead(dut, 1, 0, 0)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 4, "Metadata incorrect" # reset PLRU
    assert metadata1 == 5, "Metadata incorrect" # set PLRU 
    assert metadata2 == 4, "Metadata incorrect" # reset PLRU
    assert metadata3 == 5, "Metadata incorrect" # set PLRU

    # Request read
    await requestCacheRead(dut, 0, 0, 0)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 5, "Metadata incorrect" # set PLRU
    assert metadata1 == 5, "Metadata incorrect" # set PLRU 
    assert metadata2 == 4, "Metadata incorrect" # reset PLRU
    assert metadata3 == 5, "Metadata incorrect" # set PLRU

    # Request read
    await requestCacheRead(dut, 2, 0, 0)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 4, "Metadata incorrect" # reset PLRU
    assert metadata1 == 4, "Metadata incorrect" # reset PLRU 
    assert metadata2 == 5, "Metadata incorrect" # set PLRU
    assert metadata3 == 4, "Metadata incorrect" # reset PLRU

    # Request write
    await requestCacheWrite(dut, 0, 0, 0, 0xdeadc0de)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 7, "Metadata incorrect" # set PLRU
    assert metadata1 == 4, "Metadata incorrect" # reset PLRU 
    assert metadata2 == 5, "Metadata incorrect" # set PLRU
    assert metadata3 == 4, "Metadata incorrect" # reset PLRU

    # Request write
    await requestCacheWrite(dut, 2, 0, 0, 0xdeadc0de)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 7, "Metadata incorrect" # set PLRU
    assert metadata1 == 4, "Metadata incorrect" # set PLRU 
    assert metadata2 == 7, "Metadata incorrect" # set PLRU
    assert metadata3 == 4, "Metadata incorrect" # reset PLRU

    # Request write
    await requestCacheWrite(dut, 3, 0, 0, 0xdeadc0de)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 7, "Metadata incorrect" # set PLRU
    assert metadata1 == 4, "Metadata incorrect" # set PLRU 
    assert metadata2 == 7, "Metadata incorrect" # set PLRU
    assert metadata3 == 7, "Metadata incorrect" # reset PLRU

    # Request write
    await requestCacheWrite(dut, 1, 0, 0, 0xdeadc0de)

    await RisingEdge(dut.clock)

    metadata0 = getMetadata(dut,0,0)
    metadata1 = getMetadata(dut,1,0)
    metadata2 = getMetadata(dut,2,0)
    metadata3 = getMetadata(dut,3,0)

    # Check metadata after read
    assert metadata0 == 6, "Metadata incorrect" # reset PLRU
    assert metadata1 == 7, "Metadata incorrect" # set PLRU 
    assert metadata2 == 6, "Metadata incorrect" # reset PLRU
    assert metadata3 == 6, "Metadata incorrect" # reset PLRU

    ## Check that all words store 0xDEADC0DE


    await RisingEdge(dut.clock)

    line0 = getMemoryLine(dut, 0, 0)
    line1 = getMemoryLine(dut, 1, 0)
    line2 = getMemoryLine(dut, 2, 0)
    line3 = getMemoryLine(dut, 3, 0)

    print(f"{hex(line0)}\n{hex(line1)}\n{hex(line2)}\n{hex(line3)}")
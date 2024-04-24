import random
import numpy as np
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
    await RisingEdge(dut.clock)

async def requestRead(dut, address):
    dut.io_cpu_addr_valid.value = 1
    dut.io_cpu_addr_bits.value = address
    await RisingEdge(dut.clock)
    dut.io_cpu_addr_valid.value = 0




async def generateDramResp(dut, dramData="Random", dramLantecy="Random"):

    if(dramLantecy=="Random"):
        for step in range(random.randint(0,150)):
            await RisingEdge(dut.clock)
    else:
        for step in range(dramLantecy):
            await RisingEdge(dut.clock)

    if(dramData == "Random"):
        dut.io_dram_data_bits.value = random.randint(0,(2**256)-1)
    else:
        dut.io_dram_data_bits.value = dramData

    dut.io_dram_data_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_dram_data_valid.value = 0

def createTestCacheLine(blockSize=32):
    # Constructs a test cache line as [15, 14, 13, ..., 0]
    # where each number is a 4-byte word, and blockSize is assumed to be a multiple of 4.
    cacheLine = 0
    numWords = blockSize // 4  # Number of 4-byte words in the cache line
    for i in range(numWords):
        wordValue = numWords - 1 - i  # Values decrease from 15 to 0
        cacheLine |= (wordValue << (i * 32))  # Shift the word value left by i * 32 bits (4 bytes)
    return cacheLine

async def waitNCycles(dut, N):
    for i in range(N):
        await RisingEdge(dut.clock)

def constructCacheAddr(instruction, set, tag, totalSets=64, blockSize=32):
    # [tag][set][instruction][byte]
    byteOffset = 0
    setOffset =  int(np.log2(blockSize)) + byteOffset
    tagOffset = int(np.log2(totalSets)) + setOffset
    addr = (tag<<tagOffset) | (set<<setOffset) | (instruction<<2)

    return addr


async def requestReadVerif(dut, instruction, set, tag, totalSets, blockSize):
    address = constructCacheAddr(instruction, set, tag, totalSets=64, blockSize=32)

    dut.io_cpu_addr_valid.value = 1
    dut.io_cpu_addr_bits.value = address

    await FallingEdge(dut.clock)

    # confirm correct set read from memories
    assert dut.data_memory_0.io_addr.value == set, "Set not correct indexed in DUT"
    assert dut.data_memory_1.io_addr.value == set, "Set not correct indexed in DUT"
    assert dut.LRU_memory.io_rd_addr.value == set, "Set not correct indexed in DUT"

    await RisingEdge(dut.clock)
    dut.io_cpu_addr_valid.value = 0

@cocotb.test()
async def testFirstCacheLine(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 

    # Plan:
    # After reset, check if ready. 
    # Attempt read from address 0. Expected match but invalid.
    # Check cache from cpu side not ready due to miss. Check cache ready from dram side due to miss
    # Send dram data. 
    # Check allocated correctly. 
    # Check replay status. 
    # Check hit overall and for each fetch packet. 
    # Ensure output data and validity is correct. 
    # Ensure readiness correct throughout.


    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after reset"

    await requestRead(dut, 0x0)

    await FallingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 0, "Cache ready after miss"
    assert dut.io_cache_data_0_valid.value == 0, "Hit occured on invalid cache line"
    assert dut.io_cache_data_1_valid.value == 0, "Hit occured on invalid cache line"
    assert dut.miss.value == 1, "Miss not high after miss"

    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    
    assert dut.cache_state.value == 1, "Cache not in allocate state after DRAM response"

    await generateDramResp(dut)
    ## Check allocation in progress
    
    await RisingEdge(dut.clock)
    ## Check replay is in progress.

    assert dut.cache_state.value == 2, "Cache not in replay state after DRAM response"


    await FallingEdge(dut.clock)
    ## Check cache response on output

    assert dut.io_cache_data_0_valid.value == 1, "Cache response after miss not output after replay"
    assert dut.io_cache_data_1_valid.value == 1, "Cache response after miss not output after replay"



@cocotb.test()
async def testFirstCacheLineUnaligned(dut):
    random.seed(0x41)
    await cocotb.start(generateClock(dut)) 

    # Plan:
    # After reset, check if ready. 
    # Attempt read from address 0x0000_0004. Expected match but invalid.
    # Check cache from cpu side not ready due to miss. Check cache ready from dram side due to miss
    # Send dram data. 
    # Check allocated correctly. 
    # Check replay status. 
    # Check hit overall and for each fetch packet. 
    # Ensure output data and validity is correct. 
    # Ensure readiness correct throughout.


    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after reset"

    await requestRead(dut, 0x0000_0004)

    await FallingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 0, "Cache ready after miss"
    assert dut.io_cache_data_0_valid.value == 0, "Hit occured on invalid cache line"
    assert dut.io_cache_data_1_valid.value == 0, "Hit occured on invalid cache line"
    assert dut.miss.value == 1, "Miss not high after miss"

    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    
    assert dut.cache_state.value == 1, "Cache not in allocate state after DRAM response"

    await generateDramResp(dut)
    ## Check allocation in progress
    
    await RisingEdge(dut.clock)
    ## Check replay is in progress.

    assert dut.cache_state.value == 2, "Cache not in replay state after DRAM response"


    await FallingEdge(dut.clock)
    ## Check cache response on output

    assert dut.io_cache_data_0_valid.value == 0, "lower fetch instr valid on misaligned fetch"
    assert dut.io_cache_data_1_valid.value == 1, "higher fetch instr invalid on misaligned fetch"




#TODO: Things I need to verify
#TODO: Need to check the cache ignores dram responses when its not expecting any
#TODO: Need to check that the cache doesnt accept requests directly following a miss




@cocotb.test()
async def testLRU(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 

    # Plan:
    # After reset, request some random address
    # Wait for allocation
    # Perform many reads, confirm hit way is constant and correct
    # Perform read from same set, different address. 
    # confirm hit takes place
    # Ensure LRU is updated correctly
    # perform many reads to both addresses to ensure A) no misses occur B) LRU is updated correctly after each read
        


    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after reset"

    addressA = constructCacheAddr(instruction=0,set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    addressB = constructCacheAddr(instruction=0,set=0, tag=0xBEEF, totalSets=64, blockSize=32)

    await requestReadVerif(dut, instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)    # Request again


    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)

    assert dut.input_tag.value == 0xDEAD, "Input Tag incorrectly constructed."

    await RisingEdge(dut.clock)
    await generateDramResp(dut)


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    await requestReadVerif(dut, instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)    # Request again
    assert dut.miss.value == 0, "Miss should be low after allocate"
    assert dut.hit.value == 0, "Hit and miss are contradictory after allocate"

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    #########
    #########
    #########


    await requestReadVerif(dut, instruction=0, set=0, tag=0xBEEF, totalSets=64, blockSize=32)    # Request Same set, diff tag.


    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)

    assert dut.input_tag.value == 0xBEEF, "Input Tag incorrectly constructed."

    await RisingEdge(dut.clock)
    await generateDramResp(dut)


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)



    await requestReadVerif(dut, instruction=0, set=0, tag=0xBEEF, totalSets=64, blockSize=32)    # Request same set, diff tag.
    await RisingEdge(dut.clock)

    assert dut.LRU_memory.io_rd_addr.value == 0, "Set not correct indexed in DUT"
    assert dut.LRU_memory.io_data_in.value == 0b01, "LRU data in not correct    "


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    await requestReadVerif(dut, instruction=0, set=0, tag=0xBEEF, totalSets=64, blockSize=32)    # should be hit
    await FallingEdge(dut.clock)
    assert dut.io_cache_data_0_valid.value == 1, "lower fetch instr valid on misaligned fetch"
    assert dut.io_cache_data_1_valid.value == 1, "higher fetch instr invalid on misaligned fetch"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)    # should be hit
    await FallingEdge(dut.clock)
    assert dut.io_cache_data_0_valid.value == 1, "lower fetch instr valid on misaligned fetch"
    assert dut.io_cache_data_1_valid.value == 1, "higher fetch instr invalid on misaligned fetch"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)    # should be hit
    await FallingEdge(dut.clock)
    assert dut.io_cache_data_0_valid.value == 1, "lower fetch instr valid on misaligned fetch"
    assert dut.io_cache_data_1_valid.value == 1, "higher fetch instr invalid on misaligned fetch"
    await RisingEdge(dut.clock)
    
    await requestReadVerif(dut, instruction=0, set=0, tag=0xBEEF, totalSets=64, blockSize=32)    # should be hit
    await FallingEdge(dut.clock)
    assert dut.io_cache_data_0_valid.value == 1, "lower fetch instr valid on misaligned fetch"
    assert dut.io_cache_data_1_valid.value == 1, "higher fetch instr invalid on misaligned fetch"
    await RisingEdge(dut.clock)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

# TODO: Test the use of each set. 
# TODO: Test allocation after way is used.
# TODO: Test data is read correctly. 
# TODO: Test packets are aligned correctly. 



@cocotb.test()
async def testReads(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 

    # Plan:
    # Read address and return known data. 
    # Read another address and return known data. 
    # read from both in a pipelined fashion

    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after reset"

    addressA = constructCacheAddr(instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    addressB = constructCacheAddr(instruction=0, set=0, tag=0xBEEF, totalSets=64, blockSize=32)

    # Request 0

    await requestReadVerif(dut, instruction=7, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await generateDramResp(dut, dramData=0xDEAD_BEEF_0000_0000)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    # Active again...
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    #assert dut.io_cache_data_0_bits.value == 0xBEEF, "Data not valid after miss"

    #assert dut.io_cache_data_1_valid.value == 1, "Data not valid after miss"
    #assert dut.io_cache_data_1_bits.value == 0x0, "Data not valid after miss"

    await RisingEdge(dut.clock)
    # Request 1

    await requestReadVerif(dut, instruction=7, set=0, tag=0xBEEF, totalSets=64, blockSize=32)
    await generateDramResp(dut, dramData=0xDEAD_BEEF_0000_0000)
    await RisingEdge(dut.clock)
    await FallingEdge(dut.clock)
    # Active again...
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"

    assert dut.io_cache_data_1_valid.value == 0, "instruction 2 should be invalid with unaligned access"
    assert dut.io_cache_data_1_bits.value == 0x0, "Data not valid after miss"

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    # Now read pipelined

    await requestReadVerif(dut, instruction=7, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"

    assert dut.io_cache_data_1_valid.value == 0, "instruction 2 should be invalid with unaligned access"
    assert dut.io_cache_data_1_bits.value == 0x0, "Data not valid after miss"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=7, set=0, tag=0xBEEF, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=7, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"

    assert dut.io_cache_data_1_valid.value == 0, "instruction 2 should be invalid with unaligned access"
    assert dut.io_cache_data_1_bits.value == 0x0, "Data not valid after miss"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=7, set=0, tag=0xBEEF, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=7, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"

    assert dut.io_cache_data_1_valid.value == 0, "instruction 2 should be invalid with unaligned access"
    assert dut.io_cache_data_1_bits.value == 0x0, "Data not valid after miss"
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=7, set=0, tag=0xBEEF, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after allocate"
    assert dut.io_cache_data_0_valid.value == 1, "Data not valid after miss"
    assert dut.io_cache_data_0_bits.value == 0xDEAD_BEEF, "Data not valid after miss"
    await RisingEdge(dut.clock)


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


@cocotb.test()
async def testPacketMuxing(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 

    # Plan:
    # Read from set 0 and ensure packet alignment functionality works as expected 

    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 1, "Cache not ready after reset"

    addressA = constructCacheAddr(instruction=0,set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    addressB = constructCacheAddr(instruction=0,set=0, tag=0xBEEF, totalSets=64, blockSize=32)

    # Request 0

    await requestReadVerif(dut, instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await generateDramResp(dut, dramData=createTestCacheLine())

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)



    await requestReadVerif(dut, instruction=0, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)
    assert dut.io_cache_data_0_valid.value == 1
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_0_bits.value == 0
    assert dut.io_cache_data_1_bits.value == 1
    await RisingEdge(dut.clock)


    await requestReadVerif(dut, instruction=2, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 1
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_0_bits.value == 2
    assert dut.io_cache_data_1_bits.value == 3
    await RisingEdge(dut.clock)


    await requestReadVerif(dut, instruction=4, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 1
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_0_bits.value == 4
    assert dut.io_cache_data_1_bits.value == 5
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=6, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 1
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_0_bits.value == 6
    assert dut.io_cache_data_1_bits.value == 7
    await RisingEdge(dut.clock)


    ## TEST UNALIGNED FETCHES

    await requestReadVerif(dut, instruction=1, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 0
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_1_bits.value == 1  
    await RisingEdge(dut.clock)


    await requestReadVerif(dut, instruction=3, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 0
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_1_bits.value == 3  
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=5, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 0
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_1_bits.value == 5  
    await RisingEdge(dut.clock)

    await requestReadVerif(dut, instruction=7, set=0, tag=0xDEAD, totalSets=64, blockSize=32)
    await FallingEdge(dut.clock)

    assert dut.io_cache_data_0_valid.value == 0
    assert dut.io_cache_data_1_valid.value == 1

    assert dut.io_cache_data_1_bits.value == 7  
    await RisingEdge(dut.clock)


## TODO: test addressing of sets etc...
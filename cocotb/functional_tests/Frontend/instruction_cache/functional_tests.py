import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer

import random
import sys
from pathlib import Path
sys.path.append(str(Path("../../../lib/models/instructionCache/").resolve()))
sys.path.append(str(Path("../../../lib/models/genericLRU/").resolve()))
sys.path.append(str(Path("../../../lib/").resolve()))
from utils import *
from instructionCache import *


SETS = 64
WAYS = 2
BLOCKSIZE = 32
FETCHWIDTH = 4

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

def allocateModule(model, addrDataPair):
    # allocate data in the dut
    addr = addrDataPair[0]
    way = addrDataPair[1][0]
    data = bytearray(addrDataPair[1][1])
    cacheLine = genericCacheLine(blockSize=BLOCKSIZE, data=data)
    model.forceWrite(address=addr, way=way, data=cacheLine)

def allocateDut(model, address, line):
    #
    pass

def buildDatabase(memoryDatabase, offset="random"):
    # for each set, build an address with a very high tag, a very low tag, and a normal tag. 
    # the byte offset and fetch packet etc are generated later
    max_tag = (1<<21) - 1
    min_tag = 0
    
    for way in range(WAYS):
        for set in range(SETS):
            byteOffset=0
            if(offset=="random"):
                byteOffset=random.randrange(0, 8)*4

            max_addr = generateAddr(random.randrange(max_tag-100, max_tag), set=set, byteOffset=byteOffset, sets=64, blockSize=32)
            normal_addr = generateAddr(random.randrange(min_tag+100, max_tag-100), set=set, byteOffset=byteOffset, sets=64, blockSize=32)
            min_addr = generateAddr(random.randrange(min_tag, min_tag+100), set=set, byteOffset=byteOffset, sets=64, blockSize=32)

            memoryDatabase.update({max_addr: (way, bytearray(random.getrandbits(8) for _ in range(32)))})
            memoryDatabase.update({normal_addr: (way, bytearray(random.getrandbits(8) for _ in range(32)))})
            memoryDatabase.update({min_addr: (way, bytearray(random.getrandbits(8) for _ in range(32)))})
        

def allocateDut(dut, addrDataPair):
    addr = addrDataPair[0]
    way, data = addrDataPair[1]
    dataInt = int.from_bytes(data, byteorder='big')
    set = getSet(addr, sets=SETS, blockSize=BLOCKSIZE)
    tag = getTag(addr, sets=SETS, blockSize=BLOCKSIZE)
    validBit = 1
    dataWidth = len(data) * 8  # Data width in bits
    tagWidth = 21
    concatenatedValue = (validBit << (tagWidth + dataWidth)) | (tag << dataWidth) | dataInt
    getattr(dut, f"data_memory_{way}").ram_ext.Memory[set].value = concatenatedValue

def printDut(dut):
    print("\n\n=====")
    print("Printing DUT memory")
    print("=====")
    for way in range(WAYS):
        print("\n\n=====")
        print(f"Way {way}")
        print("=====")
        for setNumber in range(SETS):
            memoryValue = int(getattr(dut, f"data_memory_{way}").ram_ext.Memory[setNumber].value)
            # Print the set number and memory values
            print(f"Set: {setNumber:2d} |", end=" ")
            
            # Print the bytes in reverse order
            for i in range(BLOCKSIZE):
                # Extract the byte in the reverse order
                byte = 0xFF & (memoryValue >> ((BLOCKSIZE - 1 - i) * 8))
                print(f"{byte:02x}", end=" ")
            print("")


def requestModelTransaction(model, transaction):
    type = transaction[0]
    addr = transaction[1]
    data = transaction[2]
    if(type == "read"):
        return model.read(address = addr)
    elif(type == "allocate"):
        return model.allocate(address = addr, data=data)
    else:
        exit()

def requestDutTransaction(dut, transaction):
    type = transaction[0]
    addr = transaction[1]
    data = transaction[2]
    if(type == "read"):
        dut.io_cpu_addr_valid.value = 1
        dut.io_cpu_addr_bits.value = addr
    elif(type == "allocate"): # FIXME: update this so that it takes any latency
        dut.io_dram_data_valid.value = 1
        dut.io_dram_data_bits.value = data
    else:
        exit()

def deassertRequestDutTransaction(dut):
    dut.io_dram_data_valid.value = 0
    dut.io_dram_data_bits.value = 0
    dut.io_cpu_addr_bits.value = 0
    dut.io_cpu_addr_valid.value = 0

@cocotb.test()
async def instructionCacheFuzz_hits_only(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    # initialize an instruction memory
    # construct a pool of memory addresses of various characteristics (max tag, min tag, set collision, empty data, etc)
    # use this pool of (memory, data) pairs to initialize the actual cache and the modela
    # create a queue of memory requests using this pool of (memory, data) pairs
    # Buffer the results of each such that they are synchronized
    # Compare results...
    ######
    ######

    model = instructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4)    # instantiate model
    transactionRequestQ = []    # create transaction queue
    modelOutputQ = []    # create model output queue
    dutOutputQ = []    # create dut output queue
    waySet = set()


    # construct address/data database
    memoryDatabase = {}
    hitDatabase = []
    buildDatabase(memoryDatabase, offset=0)

    # initialize model and DUT
    
    for i in range(1<<12): # once a set/way has been allocated, do not overwrite, as to maintain
        # a database of effective guaranteed hit addresses. 
        addrDataPair = random.choice(list(memoryDatabase.items()))

        setIndex = getSet(addrDataPair[0], sets=SETS, blockSize=BLOCKSIZE)
        way = addrDataPair[1][0]
        
        if (setIndex, way) not in waySet:    # Way set combo not yet allocated
            waySet.add((setIndex, way))
            hitDatabase.append(addrDataPair)
            allocateModule(model, addrDataPair)
            allocateDut(dut, addrDataPair)

    await RisingEdge(dut.clock)
    #model.print()
    #printDut(dut)

    # TODO: compare starting states...

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    for _ in range(10000): # generate test stim
        #operation=random.choice(["read", "allocate"])
        operation=random.choice(["read"])
        #addrDataPair = random.choice(list(memoryDatabase.items()))
        addrDataPair = random.choice(hitDatabase)   # select from database of guaranteed hits
        sequenceItem = (operation, addrDataPair[0], bytearray(random.getrandbits(8) for _ in range(32)))
        transactionRequestQ.append(sequenceItem)
     

    while(transactionRequestQ):
        if(dut.io_cpu_addr_ready.value == 1):
            transaction = transactionRequestQ.pop(0)
            requestDutTransaction(dut, transaction)

            modelOutputQ.append(requestModelTransaction(model, transaction))

        if(dut.io_resp_valid.value == 1):
            #await FallingEdge(dut.clock)
            instructions=[0]*4
            validBits=0
            for i in range(FETCHWIDTH):
                instructions[i]=hex(int((getattr(dut, f"io_cache_data_instructions_{i}").value)))
                validBits = validBits<<1 | int((getattr(dut, f"io_cache_data_valid_bits_{i}").value))
            dutOutputQ.append((instructions, validBits))
            

        if(modelOutputQ and dutOutputQ):
            # compare outputs
            # dequeue
            dutOutput=dutOutputQ.pop(0)
            modelOutput = modelOutputQ.pop(0)
            assert dutOutput == modelOutput

        await RisingEdge(dut.clock)
        deassertRequestDutTransaction(dut)

@cocotb.test()
async def instructionCacheFuzz_hits_only_random_offset(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 

    # initialize an instruction memory
    # construct a pool of memory addresses of various characteristics (max tag, min tag, set collision, empty data, etc)
    # use this pool of (memory, data) pairs to initialize the actual cache and the model
    # create a queue of memory requests using this pool of (memory, data) pairs
    # Buffer the results of each such that they are synchronized
    # Compare results...
    ######
    ######

    model = instructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4)    # instantiate model
    transactionRequestQ = []    # create transaction queue
    modelOutputQ = []    # create model output queue
    dutOutputQ = []    # create dut output queue
    waySet = set()


    # construct address/data database
    memoryDatabase = {}
    hitDatabase = []
    buildDatabase(memoryDatabase)

    # initialize model and DUT
    
    for i in range(1<<12): # once a set/way has been allocated, do not overwrite, as to maintain
        # a database of effective guaranteed hit addresses. 
        addrDataPair = random.choice(list(memoryDatabase.items()))

        setIndex = getSet(addrDataPair[0], sets=SETS, blockSize=BLOCKSIZE)
        way = addrDataPair[1][0]
        
        if (setIndex, way) not in waySet:    # Way set combo not yet allocated
            waySet.add((setIndex, way))
            hitDatabase.append(addrDataPair)
            allocateModule(model, addrDataPair)
            allocateDut(dut, addrDataPair)

    await RisingEdge(dut.clock)
    #model.print()
    #printDut(dut)

    # TODO: compare starting states...

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    for _ in range(10000): # generate test stim
        #operation=random.choice(["read", "allocate"])
        operation=random.choice(["read"])
        #addrDataPair = random.choice(list(memoryDatabase.items()))
        addrDataPair = random.choice(hitDatabase)   # select from database of guaranteed hits
        sequenceItem = (operation, addrDataPair[0], bytearray(random.getrandbits(8) for _ in range(32)))
        transactionRequestQ.append(sequenceItem)
     

    while(transactionRequestQ):
        if(dut.io_cpu_addr_ready.value == 1):
            transaction = transactionRequestQ.pop(0)
            requestDutTransaction(dut, transaction)
            modelOutputQ.append(requestModelTransaction(model, transaction))
        if(dut.io_resp_valid.value == 1):
            instructions=[0]*4
            validBits=0
            for i in range(FETCHWIDTH):
                instructions[i]=hex(int((getattr(dut, f"io_cache_data_instructions_{i}").value)))
                validBits = validBits<<1 | int((getattr(dut, f"io_cache_data_valid_bits_{i}").value))
            dutOutputQ.append((instructions, validBits))
            

        if(modelOutputQ and dutOutputQ):
            dutOutput=dutOutputQ.pop(0)
            modelOutput = modelOutputQ.pop(0)
            assert dutOutput == modelOutput

        await RisingEdge(dut.clock)
        deassertRequestDutTransaction(dut)


@cocotb.test()
async def test0(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    dut.io_cpu_addr_valid.value = 1
    dut.io_cpu_addr_bits.value = generateAddr(0xdead, set=0, byteOffset=0, sets=64, blockSize=32)
    await RisingEdge(dut.clock)
    dut.io_cpu_addr_valid.value = 0
    await generateDramResp(dut, dramData=(0xdead)<<(30*8), dramLantecy="Random")
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.io_cpu_addr_valid.value = 1
    dut.io_cpu_addr_bits.value = generateAddr(0xdead, set=0, byteOffset=0, sets=64, blockSize=32)
    await RisingEdge(dut.clock)
    assert dut.io_cache_data_instructions_0.value == 0xdead0000
    await RisingEdge(dut.clock)
    dut.io_cpu_addr_valid.value = 1
    dut.io_cpu_addr_bits.value = generateAddr(0xdead, set=0, byteOffset=16, sets=64, blockSize=32)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert dut.io_cache_data_instructions_0.value == 0x00000000


    dut.io_cpu_addr_bits.value = generateAddr(0xdead, set=0, byteOffset=4, sets=64, blockSize=32)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert dut.io_cache_data_instructions_0.value == 0xdead0000

    dut.io_cpu_addr_bits.value = generateAddr(0xdead, set=0, byteOffset=14, sets=64, blockSize=32)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    assert dut.io_cache_data_instructions_0.value == 0xdead0000
    assert dut.io_cache_data_valid_bits_0.value == 0

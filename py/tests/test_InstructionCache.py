import pytest
import random
from GenericCache import *
from InstructionCache import *
from SimpleDRAM import *
from model_utils import *

@pytest.fixture
def instructionCache():
    instructionCache = InstructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4)
    return instructionCache

def test_allocate_read_simple(instructionCache):
    set = 0
    addr = generateAddr(tag=0, set=set, byteOffset=(0), sets=instructionCache.sets, blockSize=instructionCache.blockSize)
    instructionCache.allocate(address=0, data=0xdeadbeef)
    addr = generateAddr(tag=0, set=set, byteOffset=32-4-4-4-4, sets=instructionCache.sets, blockSize=instructionCache.blockSize)
    read_data=instructionCache.read(address=addr)
    assert read_data[0][0][3] == hex(0xdeadbeef)
    assert read_data[0][1][3] == 0b1
    assert read_data[0][0][2] == hex(0)
    assert read_data[0][1][2] == 0b1
    assert read_data[0][0][1] == hex(0)
    assert read_data[0][1][1] == 0b1
    assert read_data[0][0][0] == hex(0)
    assert read_data[0][1][0] == 0b1


def test_allocate_read_unaligned(instructionCache):
    set = 0
    instructionCache.allocate(address=0, data=0xdeadbeef)
    addr = generateAddr(tag=0, set=set, byteOffset=(32-4), sets=instructionCache.sets, blockSize=instructionCache.blockSize)
    read_data=instructionCache.read(address=addr)
    assert read_data[0][0][3] == hex(0xdeadbeef)
    assert read_data[0][1][3] == 0b1
    assert read_data[0][0][2] == hex(0x0)
    assert read_data[0][1][2] == 0b0
    assert read_data[0][0][1] == hex(0x0)
    assert read_data[0][1][1] == 0b0
    assert read_data[0][0][0] == hex(0x0)
    assert read_data[0][1][0] == 0b0



def test_miss_with_dram(instructionCache):

    model_dram = SimpleDRAM()    
    model_dram.randomize()

    instructionCache = InstructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4, dram=model_dram)

    addr = generateAddr(tag=0, set=0, byteOffset=0, sets=instructionCache.sets, blockSize=instructionCache.blockSize)
    read_data=instructionCache.read(addr)


    assert True # FIXME: not a real test



def test_miss_with_dram(instructionCache):

    #instructionCache.print()
    
    set = 0
    addr = generateAddr(tag=0, set=set, byteOffset=(0), sets=instructionCache.sets, blockSize=instructionCache.blockSize)
    instructionCache.allocate(address=0, data=0xdeadbeef)
    addr = generateAddr(tag=0, set=set, byteOffset=32-4-4-4-4, sets=instructionCache.sets, blockSize=instructionCache.blockSize)
    read_data=instructionCache.read(address=addr)

    assert False 
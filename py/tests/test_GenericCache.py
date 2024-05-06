import pytest
import random
from GenericCache import *
from SimpleDRAM import *
from model_utils import *

@pytest.fixture
def cache():
    cache = GenericCache(sets=64, ways=2, blockSize=32, evictionPolicy=LRU)
    return cache

def test_align(cache):
    addr = 0x4
    addr = align(address=addr, bytes=32)
    assert addr == 0x0

def test_get_set(cache):
    for set in range(64):
        addr = set<<int(np.log2(cache.blockSize))
        assert getSet(addr, cache.sets, cache.blockSize) == set

def test_generate_address(cache):
    for set in range(64):
        addr = set<<int(np.log2(cache.blockSize))
        assert generateAddr(tag=0, set=set, byteOffset=0, sets=cache.sets, blockSize=cache.blockSize) == addr

def test_allocate(cache):
    for set in range(64):
        addr = generateAddr(tag=0, set=set, byteOffset=0, sets=cache.sets, blockSize=cache.blockSize)
        cache.allocate(address = addr, data = 0xdeadbeef)
        assert cache.cacheWays[0].way[set]["data"].read(28, 4) == 0xdeadbeef

def test_allocate_read_allocate(cache):
    for set in range(64):
        # Write way 0
        data0 = random.randint(0,(1<<32)-1)
        addr = generateAddr(tag=0, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)

        cache.allocate(address = addr, data = data0)                        # 
        assert cache.cacheWays[0].way[set]["data"].read(28, 4) == data0

        read_data = cache.read(address = addr, bytes = 4)[0][1]            # (hit, data)
        assert read_data == data0
        
        ##################
        ##################

        # Write way 1
        data1 = random.randint(0,(1<<32)-1)
        addr = generateAddr(tag=1, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)

        cache.allocate(address = addr, data = data1)
        assert cache.cacheWays[1].way[set]["data"].read(28, 4) == data1

        read_data = cache.read(address = addr, bytes = 4)[0][1]            # (hit, data)
        assert read_data == data1

        ###############
        ###############
        # Write way 0
        data2 = random.randint(0,(1<<32)-1)
        addr = generateAddr(tag=1, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)

        cache.allocate(address = addr, data = data2)
        assert cache.cacheWays[0].way[set]["data"].read(28, 4) == data2

        read_data = cache.read(address = addr, bytes = 4)[0][1]            # (hit, data)
        assert read_data == data2


def test_allocate_read_write(cache):
    for set in range(64):
        # Write way 0
        data = 0xdeadbeef
        addr = generateAddr(tag=0, set=set, byteOffset=0, sets=cache.sets, blockSize=cache.blockSize)

        cache.allocate(address = addr, data = data)
        assert cache.cacheWays[0].way[set]["data"].read(28, 4) == data

        read_data = cache.read(address = addr, bytes = 32)[0][1]
        print(hex(read_data))
        #assert read_data == hex(data)

        addr = generateAddr(tag=0, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)
        cache.write(address = addr, bytes = 4, data=0x42)

        #print(hex(cache.cacheWays[0].way[set]["data"].read(28, 4)))

        read_data = cache.read(address = addr, bytes = 4)[0][1]
        print(hex(read_data))

        assert read_data == 0x42
        

def test_read_write(cache):
    # Write way 0
    set=0
    addr = generateAddr(tag=0, set=set, byteOffset=0, sets=cache.sets, blockSize=cache.blockSize)
    data = 0xdeadbeef

    cache.allocate(address = addr, data = data)

    addr = generateAddr(tag=0, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)
    read_data = cache.read(address = addr, bytes = 4)[0][1]
    assert read_data == 0xdeadbeef


    addr = generateAddr(tag=0, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)
    cache.write(address = addr, bytes = 4, data=0x42)
    read_data = cache.read(address = addr, bytes = 4)[0][1]
    assert read_data == 0x42


def test_allocate_read_hit(cache):

    for set in range(cache.sets):
        addr = generateAddr(tag=0, set=set, byteOffset=0, sets=cache.sets, blockSize=cache.blockSize)
        data = 0xdeadbeef

        cache.allocate(address = addr, data = data)

        addr = generateAddr(tag=0, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)
        resp = cache.read(address = addr, bytes = 4)[0]
        assert resp[0] == 1
        assert resp[1] == 0xdeadbeef

def test_allocate_read_miss(cache):

    for set in range(cache.sets):
        addr = generateAddr(tag=0, set=set, byteOffset=0, sets=cache.sets, blockSize=cache.blockSize)
        data = 0xdeadbeef

        cache.allocate(address = addr, data = data)

        addr = generateAddr(tag=123, set=set, byteOffset=28, sets=cache.sets, blockSize=cache.blockSize)
        resp = cache.read(address = addr, bytes = 4)[0]
        assert resp[0] == 0

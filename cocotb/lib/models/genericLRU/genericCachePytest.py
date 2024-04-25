import pytest
import logging
from pathlib import Path
import sys

# Add the required paths for import
sys.path.append(str(Path("../..").resolve()))

from genericCache import *

# Define some global constants for the cache setup
SETS = 64
WAYS = 2
BLOCK_SIZE = 32

# Test for cache allocation
def test_cache_allocation():
    cache = genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU)
    # Initialize data for cache line
    data = bytearray.fromhex("deadbeef")
    cache_line = genericCacheLine(blockSize=BLOCK_SIZE, data=data)
    
    # Generate an address
    addr = generateAddr(tag=0x1, set=63, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
    
    # Allocate data to the cache
    cache.allocate(address=addr, data=cache_line)
    
    # Verify the data is allocated to the cache
    (hit, read_data), hit_way = cache.read(address=addr, bytes=4)
    assert hit == 1
    assert read_data == data

# Test for cache read operation
def test_cache_read():
    cache = genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU)
    # Initialize data for cache line
    data = bytearray.fromhex("deadbeef" * (BLOCK_SIZE // 4))
    cache_line = genericCacheLine(blockSize=BLOCK_SIZE, data=data)
    
    # Generate an address
    addr = generateAddr(tag=0x1, set=0, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
    
    # Allocate data to the cache
    cache.allocate(address=addr, data=cache_line)
    
    # Verify the cache read operation
    hit, read_data = cache.read(address=addr, bytes=4)
    (hit, read_data), hit_way = cache.read(address=addr, bytes=4)
    assert hit == 1
    assert read_data == data[:4]

# Test for cache write operation
def test_cache_write():
    cache = genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU)
    # Initialize data for cache line
    data = bytearray.fromhex("deadbeef" * (BLOCK_SIZE // 4))
    cache_line = genericCacheLine(blockSize=BLOCK_SIZE, data=data)
    
    # Generate an address
    addr = generateAddr(tag=0x1, set=0, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
    
    # Allocate data to the cache
    cache.allocate(address=addr, data=cache_line)
    
    # Write new data to the cache
    new_data = b'\xab\xcd\xef\x00'
    cache.write(address=addr, bytes=4, data=new_data)
    
    # Verify the write operation
    (hit, read_data), hit_way = cache.read(address=addr, bytes=4)
    assert hit == 1
    assert read_data == new_data


###################################
def test_cache_allocation_all_sets():
    cache = genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU)
    for set in range(SETS):
        # Generate random data with BLOCK_SIZE length
        data = bytearray(random.getrandbits(8) for _ in range(BLOCK_SIZE))
        cache_line = genericCacheLine(blockSize=BLOCK_SIZE, data=data)
        addr = generateAddr(tag=0x1, set=set, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
        cache.allocate(address=addr, data=cache_line)
        wayLine = cache.getWaySet(way=0, set = set)
        valid = wayLine['valid']
        
        # Read data from the cache
        (hit, read_data), hit_way = cache.read(address=addr, bytes=4)
        
        assert hit == 1
        assert valid == 1
        assert read_data == data[0:4], f"Data mismatch at set {set}: expected {data}, got {read_data}"

def test_hit_way():
    # Instantiate the generic cache with the given parameters
    cache = genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU)

    for set in range(SETS):
        # Allocate data to the first cache line at the chosen set
        addrA = generateAddr(tag=0x42, set=set, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
        dataA = bytearray(BLOCK_SIZE)
        dataA[0] = 0x42  # Set a known value for the first byte
        cache_line_A = genericCacheLine(blockSize=BLOCK_SIZE, data=dataA)
        cache.allocate(address=addrA, data=cache_line_A)
        (hit, read_data), hit_way = cache.read(address=addrA, bytes=4)

        assert hit == 1, "Expected cache hit when reading allocated data."
        assert read_data[0] == dataA[0], "Data mismatch: read data does not match allocated data."
        assert hit_way == 0, f"Expected hit in way 0, but got way {hit_way}."

        # Allocate new data to the same set, causing eviction or replacement
        addrB = generateAddr(tag=0x7, set=set, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
        dataB = bytearray(BLOCK_SIZE)
        dataB[0] = 0x07  # Set a known value for the first byte
        cache_line_B = genericCacheLine(blockSize=BLOCK_SIZE, data=dataB)
        cache.allocate(address=addrB, data=cache_line_B)
        (hit, read_data), hit_way = cache.read(address=addrB, bytes=4)

        assert hit == 1, "Expected cache hit when reading allocated data."
        assert read_data[0] == dataB[0], "Data mismatch: read data does not match allocated data."
        assert hit_way == 1, f"Expected hit in way 1, but got way {hit_way}."

        (hitA, read_dataA), hit_wayA = cache.read(address=addrA, bytes=4)
        assert hitA == 1, "Expected cache hit when reading address A."
        assert read_dataA[0] == dataA[0], "Data mismatch: read data does not match allocated data for address A."
        assert hit_wayA == 0, "Expected hit in way 0 for address A."

        (hitB, read_dataB), hit_wayB = cache.read(address=addrB, bytes=4)
        assert hitB == 1, "Expected cache hit when reading address B."
        assert read_dataB[0] == dataB[0], "Data mismatch: read data does not match allocated data for address B."
        assert hit_wayB == 1, "Expected hit in way 1 for address B."
        (hitB, read_dataB), hit_wayB = cache.read(address=addrB, bytes=4)
        assert hitB == 1, "Expected cache hit when reading address B."
        assert read_dataB[0] == dataB[0], "Data mismatch: read data does not match allocated data for address B."
        assert hit_wayB == 1, "Expected hit in way 1 for address B."
        (hitB, read_dataB), hit_wayB = cache.read(address=addrB, bytes=4)
        assert hitB == 1, "Expected cache hit when reading address B."
        assert read_dataB[0] == dataB[0], "Data mismatch: read data does not match allocated data for address B."
        assert hit_wayB == 1, "Expected hit in way 1 for address B."


def test_tag_corner_cases():
   # tag can only be from 0 to  1<<21 for set size of 64 and blocksize of 32
    for set in range(SETS):
        for tag in range((1<<22)-100, (1<<22)):
            cache = genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU)
            # Generate random data with BLOCK_SIZE length
            data = bytearray(random.getrandbits(8) for _ in range(BLOCK_SIZE))
            cache_line = genericCacheLine(blockSize=BLOCK_SIZE, data=data)
            addr = generateAddr(tag=tag, set=set, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
            cache.allocate(address=addr, data=cache_line)
            wayLine = cache.getWaySet(way=0, set = set)
            valid = wayLine['valid']
            
            # Read data from the cache
            (hit, read_data), hit_way = cache.read(address=addr, bytes=4)
            
            assert hit == 1
            assert valid == 1
            assert read_data == data[0:4], f"Data mismatch at set {set}: expected {data}, got {read_data}"

# Run the tests
if __name__ == "__main__":
    pytest.main()

import pytest
from genericCache import *

# Constants for testing
SETS = 64
WAYS = 2
BLOCK_SIZE = 32

# Create a test cache
@pytest.fixture
def cache():
    return genericCache(sets=SETS, ways=WAYS, blockSize=BLOCK_SIZE, evictionPolicy=LRU(sets=SETS, ways=WAYS))

# Test reading data from cache
def test_cache_read(cache):
    # Set up the cache with some known data
    address = 0x100
    data_to_write = bytearray(BLOCK_SIZE)
    data_to_write[:8] = b'abcdefgh'
    cache.write(address, len(data_to_write), data_to_write)
    
    # Perform a read from the cache
    hit, read_data = cache.read(address, 8)
    
    # Check that the read was a hit
    assert hit == True
    
    # Check that the data read matches the data written
    assert read_data == b'abcdefgh'

# Test writing data to cache
def test_cache_write(cache):
    # Define address and data to write
    address = 0x200
    data_to_write = bytearray(BLOCK_SIZE)
    data_to_write[:8] = b'12345678'
    
    # Perform a write to the cache
    hit, way_index = cache.write(address, len(data_to_write), data_to_write)
    
    # Check that the write was successful
    assert hit == True
    
    # Read back the data to verify the write
    hit, way_index, read_data = cache.read(address, len(data_to_write))
    
    # Check that the data read matches the data written
    assert read_data == data_to_write

# Test LRU eviction policy
def test_lru_eviction(cache):
    # Write data to different addresses to fill up the cache
    addresses = [0x100, 0x200]
    data = [b'data1', b'data2']
    
    for i in range(2):
        cache.write(addresses[i], len(data[i]), data[i])
    
    # Check the state of the LRU policy
    assert cache.evictionPolicy.LRU[0][0] == 0b1
    assert cache.evictionPolicy.LRU[0][1] == 0b0
    
    # Access the second address to change the LRU order
    cache.read(0x200, len(data[1]))
    
    # Check the state of the LRU policy after access
    assert cache.evictionPolicy.LRU[0][0] == 0b0
    assert cache.evictionPolicy.LRU[0][1] == 0b1

# Run tests using pytest command
if __name__ == "__main__":
    pytest.main()

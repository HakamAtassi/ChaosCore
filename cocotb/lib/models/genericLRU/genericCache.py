import random
import sys
from pathlib import Path
sys.path.append(str(Path("../..").resolve()))
from utils import *
#sys.path.append('models/genericLRU/')

class genericCacheLine:
    def __init__(self, byteSize):
        self.cacheLine = bytearray(byteSize)

    def read(self, byteOffset, bytes, split=None):
        # read data from byteAddress up until byteAddress+size, not inclusive
        # assert size is a multiple of split
        # separate read data into "split" sized segments. (ex, read 16 bytes of instructions and separate into 4 actual instructions).

        data = self.cacheLine[byteOffset:byteOffset + bytes]

        chunks=None
        if(split!=None):
            assert bytes % split == 0, "Size must be a multiple of split"
            assert byteOffset + bytes <= len(self.cacheLine), "Read out of bounds"
            chunks = [data[i:i + split] for i in range(0, bytes, split)]
        else:
            chunks=data
        
        return chunks

    def write(self, byteOffset, bytes, data):
        # replace the data from byteAddress up until byteAddress+size with "data", not inclusive
        # Ensure the given parameters are valid
        assert len(data) == bytes, "Data size must match the size parameter"
        assert byteOffset+ bytes <= len(self.cacheLine), "Write out of bounds"

        # Replace the data in the cache line with the provided data
        self.cacheLine[byteOffset:byteOffset + bytes] = data


class genericCacheWay():

    def __init__(self, sets, blockSize):
        self.sets = sets
        self.blockSize = blockSize

        self.way = [{"valid": 0, "tag": 0, "data": genericCacheLine(blockSize)} for _ in range(sets)]


    def search(self, address):
        set = getSet(address, sets=self.sets, blockSize=self.blockSize)
        tag = getTag(address, sets=self.sets, blockSize=self.blockSize)

        wayLine = self.way[set]
        match = (wayLine["tag"] == tag)
        valid = (wayLine["valid"] == 1)

        if match and valid:
            return 1
        else:
            return 0


    def read(self, address, bytes, split=None):
        set = getSet(address, sets=self.sets, blockSize=self.blockSize)
        byteOffset = getByteOffset(address, sets=self.sets, blockSize=self.blockSize)
        wayLine = self.way[set]
        if(self.search(address) == 1):    # is a hit
            return (1, wayLine['data'].read(byteOffset, bytes, split))
        else:
            return (0, None)

    def write(self, address, bytes, data):
        set = getSet(address, sets=self.sets, blockSize=self.blockSize)
        tag = getTag(address, sets=self.sets, blockSize=self.blockSize)
        byteOffset = getByteOffset(address, sets=self.sets, blockSize=self.blockSize)

        wayLine = self.way[set]
        match = (wayLine["tag"] == tag)
        valid = (wayLine["valid"] == 1)
        if(match and valid):
            wayLine['data'].write(byteOffset, bytes, data)
            return (1, None)
        return (0, None)


class LRU():
    # a class for the LRU memory
    # on a hit (after read or write access), set the way bit to 1
    # if all bits are 1, reset and only set hit way to 1
    # Otherwise, do nothing
    def __init__(self, sets, ways):
        # Initialize LRU bit vectors for each set
        self.sets = sets
        self.ways = ways
        self.LRU = [[0b0] * ways for _ in range(sets)]

    def allLRUHigh(self, lru_entry):
        # Check if all LRU bits in the given entry are high (1)
        return all(bit == 0b1 for bit in lru_entry)

    def update(self, address, way):
        setIndex = getSet(address)
        LRUEntry = self.LRU[setIndex]
        LRUEntry[way] = 0b1

        if self.all_lru_high(LRUEntry):
            self.LRU[setIndex] = [0b0] * self.ways
            self.LRU[setIndex][way] = 0b1
        else:
            self.LRU[setIndex] = LRUEntry

    def getAllocateWay(self, address):
        setIndex = getSet(address)
        for way in range(self.ways):
            if(self.LRU[setIndex][way]==0b0):
                return way
            return -1   # at least 1 way should be available

class genericCache():    
    def __init__(self, sets, ways, blockSize, evictionPolicy):
        self.cacheWays = [genericCacheWay(sets=sets, blockSize=blockSize) for _ in range (ways)]    # instantiate number of ways
        self.ways = ways
        self.sets = sets
        self.blockSize = blockSize
        self.evictionPolicy = evictionPolicy

    def updateState(self, address, hitWay):
        # update the of the cache ways as needed. 
        # Ex: update PLRU bits
        self.evictionPolicy.update(address, hitWay)

    def search(self, address):
        # Looks up all ways
        # Get index of hit (if any)
        # Return hit, way
        for way in range(self.ways):
            currentWayHitStatus = self.cacheWays[way].search(address)
            if (currentWayHitStatus == 1):
                return (1, way)
        return (0, None)

    def read(self, address, bytes):
        # search cache for way
        # Get hit line
        # Read corresponding word(s) (if any)
        # update state
        # output hit, data
        
        hit, hitWay = self.search(address)  # find which way to request read from
        if(hit == 1):
            self.updateState(address, hitWay)
            return self.cacheWays[hitWay].read(address, bytes)  # perform read to only hit way
        else:
            return (0, None)

    def allocate(self, address, data): # Write to cache from dram or similar
        # Read out all ways
        # Pick allocate way
        # Write to way
        allocateWay = self.evictionPolicy.getAllocateWay(address)
        setIndex = getSet(address)
        self.cacheWays[allocateWay][setIndex] = data    # data should be of type generic cache line

    def write(self, address, bytes, data):   # for a write from the cpu or similar
        # search cache for way
        # Get hit line
        # Modify corresponding word in cache line
        # update state
        # output hit, way
        hit, hitWay = self.search(address)  # find which way to request read from
        if(hit == 1):
            self.updateState(address, hitWay)
            return self.cacheWays[hitWay].write(address, bytes, data)  # perform read to only hit way
        else:
            return (0, None)


if __name__ == "__main__":
    print("Running genericLRU")
    cache = genericCache(sets=64, ways=2, blockSize=32, evictionPolicy=LRU)
    print(cache.read(address=0x0, bytes=0x0))
    
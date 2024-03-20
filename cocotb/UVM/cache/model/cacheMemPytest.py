import pytest
import numpy as np
from cacheMem import *
import logging
logging.basicConfig(level=logging.INFO)


class TestCacheMem:
    @pytest.fixture
    def cache(self):
        cache=cacheMem(sets=64, ways=4, cacheLineSizeBytes=32)
        random.seed(0x42)
        cache.randomizeActiveState()
        return cache

    def testUpdateValid(self, cache):
        assert False

    def testUpdatePLRU(self, cache):
        assert False

    def testUpdateDirty(self, cache):
        assert False

    def testGetSet(self, cache):
        assert False

    def testGetAllocateWay(self, cache):
        assert False

    #######################
    ## INTEGRATION TESTS ##
    #######################

    def testInit(self, cache):
        assert cache.sets == 64
        assert cache.ways == 4
        assert cache.cacheLineSizeBytes == 32
        assert len(cache.dataMemory) == 256  # sets * ways
        assert len(cache.tagMemory) == 64  # one per set
        assert len(cache.dirtyMemory) == 64  # one per set
        assert len(cache.PLRUMemory) == 64  # one per set
        assert len(cache.validMemory) == 64  # one per set

        print(f"{cache.printTags()}")

        ###############
        ## TEST INIT ##
        ###############

        dataMax     =   (1<<(cache.cacheLineSizeBytes*8))-1
        metadataMax =   (1<<(cache.ways))-1
        tagMax =   (1<<(cache.tagSize*cache.ways))-1

        # test all data widths within range        
        for i in range(len(cache.dataMemory)):
            assert cache.dataMemory[i] <= dataMax
        
        for i in range(cache.sets):
            assert cache.validMemory[i] <= metadataMax
            assert cache.PLRUMemory[i]  <= metadataMax
            assert cache.dirtyMemory[i]  <= metadataMax

        for i in range(len(cache.tagMemory)):
            assert cache.tagMemory[i]  <= tagMax
            
    def testReadHit(self, cache):
        # test a random read for each cache set
        # can be hit or miss based on valid bit
        for set in range(cache.sets):
            tagLine = cache.tagMemory[set]
            tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

            randomTagInSet = random.choice(tagArr)
            wordOffset = random.randint(0,int(cache.cacheLineSizeBytes/4-1)) # /4*4 for word alignment
            byteOffset = wordOffset * 4 
            randomAddr = constructAddr(tag=randomTagInSet, _set=set, byteOffset=byteOffset, setSize=cache.sets, lineSize=cache.cacheLineSizeBytes)

            # Buffer old data #
            oldValid = cache.validMemory[set]
            oldDirty = cache.dirtyMemory[set]
            oldTag   = cache.tagMemory[set]
            oldData   = cache.dataMemory[set]

            # Get metadata #
            way = tagArr.index(randomTagInSet)
            validLine = cache.validMemory[set]
            PLRULine  = cache.PLRUMemory[set]
            # Get data #
            dataLine = cache.dataMemory[way*cache.sets + set]
            # Process #
            dataWord = getWord(dataLine, wordOffset)
            validBit = getBit(validLine, way)

            response=cache.requestCMD(addr=randomAddr, data=None, cacheLine=None, cmd="LW")
            
            # Validate response packet #
            assert response.getHit() == validBit
            #assert response.getData() == dataWord
            assert response.getValid() == validBit
            assert response.getAddr() == randomAddr

            # Validate cache state #
            if validBit:
                assert cache.PLRUMemory[set]  == getPLRUNext(PLRULine, way, cache.ways), f"Expected {getPLRUNext(PLRULine, way, cache.ways)} got {cache.PLRUMemory[set]}"
            assert cache.tagMemory[set]   == oldTag,   f"Expected {oldTag}, got {cache.tagMemory[set]}"
            assert cache.validMemory[set] == oldValid, f"Expected {oldValid}, got {cache.validMemory[set]}"
            assert cache.dirtyMemory[set] == oldDirty, f"Expected {oldDirty}, got {cache.dirtyMemory[set]}"
            assert cache.dataMemory[set]  == oldData,  f"Expected {oldData}, got {cache.dataMemory[set]}"

    def testReadMiss(self, cache):
        # test a random read for each cache set
        # can be hit or miss based on valid bit
        for set in range(cache.sets):

            way = random.randint(0, cache.ways-1) 

            tagLine = cache.tagMemory[set]
            tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

            randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set
            while(randomTagInSet in tagArr):
                randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set

            wordOffset = random.randint(0,int(cache.cacheLineSizeBytes/4-1)) # /4*4 for word alignment
            byteOffset = wordOffset * 4 
            randomAddr = constructAddr(tag=randomTagInSet, _set=set, byteOffset=byteOffset, setSize=cache.sets, lineSize=cache.cacheLineSizeBytes)

            # Buffer old data #
            oldValid = cache.validMemory[set]
            oldPLRU = cache.PLRUMemory[set]
            oldDirty = cache.dirtyMemory[set]
            oldTag   = cache.tagMemory[set]
            oldData   = cache.dataMemory[set]

            response=cache.requestCMD(addr=randomAddr, data=None, cacheLine=None, cmd="LW")
            
            # Validate response packet #
            assert response.getHit() == 0b0
            assert response.getAddr() == randomAddr

            # Validate cache state #
            assert cache.PLRUMemory[set]  == oldPLRU,  f"Expected {oldPLRU} got {cache.PLRUMemory[set]}"
            assert cache.tagMemory[set]   == oldTag,   f"Expected {oldTag}, got {cache.tagMemory[set]}"
            assert cache.validMemory[set] == oldValid, f"Expected {oldValid}, got {cache.validMemory[set]}"
            assert cache.dirtyMemory[set] == oldDirty, f"Expected {oldDirty}, got {cache.dirtyMemory[set]}"
            assert cache.dataMemory[set]  == oldData,  f"Expected {oldData}, got {cache.dataMemory[set]}"

    def testWriteHit(self, cache):
        assert False
        pass

    def testWriteMiss(self, cache):
        assert False
        pass

    def testRandomOpHit(self, cache):
        assert False
        pass

    def testRandomOpMiss(self, cache):
        assert False
        pass
    
    def fuzz(self, cache):   # Random tests
        assert False
        pass

    def testAllocatesEvict(self, cache):    # Allocates against dirty, valid data
        assert False
        pass

    def testAllocatesOverwrite(self, cache): # Overwrite clean or invalid data
        assert False
        pass
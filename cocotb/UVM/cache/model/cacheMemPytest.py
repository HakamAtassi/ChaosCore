import pytest
import numpy as np
from cacheMem import *
import logging
logging.basicConfig(level=logging.INFO)


class TestCacheMem:
    @pytest.fixture
    def cache(self):
        random.seed(0x42)
        cache=cacheMem(sets=64, ways=4, cacheLineSizeBytes=32)
        cache.randomizeActiveState()
        return cache

    def testUpdateValid(self, cache):
        for valid in range(0x10):
            for way in range(cache.ways):
                cache.validMemory[0]=valid
                cache.updateValid(0, way)
                nextValid = cache.validMemory[0]
                expectedValid = (valid | (1<<way))
                assert nextValid == expectedValid

    def testUpdatePLRU(self, cache):
        for PLRU in range(0x10):
            for way in range(cache.ways):
                cache.PLRUMemory[0]=PLRU
                cache.updatePLRU(0, way)
                nextPLRU = cache.PLRUMemory[0]
                expectedPLRU=0
                if((PLRU | (1<<way))==((1<<cache.ways)-1)):
                    expectedPLRU=(1<<way)
                else:
                    expectedPLRU=(PLRU | (1<<way))
                assert expectedPLRU == nextPLRU

    def testUpdateDirty(self, cache):
        for dirty in range(0x10):
            for way in range(cache.ways):
                cache.dirtyMemory[0]=dirty
                cache.updateDirty(0, way)
                nextDirty = cache.dirtyMemory[0]
                expectedDirty=0
                expectedDirty=(dirty | (1<<way))
                assert expectedDirty == nextDirty

    def testGetSet(self, cache):
        setOffset = int(np.ceil(np.log2(cache.cacheLineSizeBytes)))
        for set in range(cache.sets):
            addr = set << setOffset
            cacheSet=cache.getSet(addr)
            assert cacheSet == set

    def testGetAllocateWay(self, cache):
        for plru_state in range(0b0000, 0b1111):
            expected_way = None 
            for way in range(cache.ways):
                if (plru_state & (1 << way)) == 0:
                    expected_way = way
                    break
            cache.PLRUMemory[0] = plru_state
            allocated_way = cache.getAllocateWay(0)
            assert allocated_way == expected_way, f"PLRU state {bin(plru_state)}: Expected way {expected_way}, got {allocated_way}"
        cache.PLRUMemory[0] = 0b1111
        with pytest.raises(AssertionError, match="PLRU not updating correctly. Cannot get allocate way."):
            cache.getAllocateWay(0)
    
    def testWriteToLine(self, cache):
        # Tests the correct bytes of a line are modified upon a write (when line is initially all 0s)
        for set in range(cache.sets):
            ## test data with leading 0s ##
            for byteOffset in range(cache.cacheLineSizeBytes): # test all byte offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=byteOffset,bytes=1,data=0x41)
                assert cache.dataMemory[set] == (0x41<<byteOffset*8)

            for halfWordOffset in range(0, cache.cacheLineSizeBytes, 2):    # test all half word offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=halfWordOffset,bytes=2,data=0x41)
                assert cache.dataMemory[set] == (0x41<<halfWordOffset*8)

            for wordOffset in range(0, cache.cacheLineSizeBytes, 4):        # test all word offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=wordOffset,bytes=4,data=0x41)
                assert cache.dataMemory[set] == (0x41<<wordOffset*8)

            ## test data of exact size ##
            for byteOffset in range(cache.cacheLineSizeBytes): # test all byte offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=byteOffset,bytes=1,data=0x4141)
                assert cache.dataMemory[set] == (0x41<<byteOffset*8)

            for halfWordOffset in range(0, cache.cacheLineSizeBytes, 2):    # test all half word offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=halfWordOffset,bytes=2,data=0x4141)
                assert cache.dataMemory[set] == (0x4141<<halfWordOffset*8)

            for wordOffset in range(0, cache.cacheLineSizeBytes, 4):        # test all word offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=wordOffset,bytes=4,data=0x41414242)
                assert cache.dataMemory[set] == (0x41414242<<wordOffset*8)
        
            ## test data with too many digits ##
            for byteOffset in range(cache.cacheLineSizeBytes): # test all byte offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=byteOffset,bytes=1,data=0xdeadbeef)
                assert cache.dataMemory[set] == (0x0000_00ef<<byteOffset*8)

            for halfWordOffset in range(0, cache.cacheLineSizeBytes, 2):    # test all half word offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=halfWordOffset,bytes=2,data=0xdeadbeef)
                assert cache.dataMemory[set] == (0x0000_beef<<halfWordOffset*8)

            for wordOffset in range(0, cache.cacheLineSizeBytes, 4):        # test all word offsets
                cache.dataMemory[set]=0
                cache.write(set=set,way=0,byteOffset=wordOffset,bytes=4,data=0xdeadbeef)
                assert cache.dataMemory[set] == (0xdead_beef<<wordOffset*8)

        # Tests the correct bytes of a line are modified upon a write (when line is initially random)
        for set in range(cache.sets):
            ## test data with leading 0s ##
            for byteOffset in range(cache.cacheLineSizeBytes): # test all byte offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=byteOffset,bytes=1,data=0x41)
                assert (cache.dataMemory[set]>>byteOffset*8)&0xFF == 0x41
                mask = 0xFF << (byteOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            for halfWordOffset in range(0, cache.cacheLineSizeBytes, 2):    # test all half word offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=halfWordOffset,bytes=2,data=0x41)
                assert (cache.dataMemory[set]>>halfWordOffset*8)&0xFFFF == 0x41
                mask = 0xFFFF << (halfWordOffset * 8)
                #assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            for wordOffset in range(0, cache.cacheLineSizeBytes, 4):        # test all word offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=wordOffset,bytes=4,data=0x41)
                assert (cache.dataMemory[set]>>wordOffset*8)&0xFFFF_FFFF == 0x41
                mask = 0xFFFF_FFFF << (wordOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            ## test data of exact size ##
            for byteOffset in range(cache.cacheLineSizeBytes): # test all byte offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=byteOffset,bytes=1,data=0x4141)
                assert (cache.dataMemory[set]>>byteOffset*8)&0xFF == 0x41
                mask = 0xFF << (byteOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            for halfWordOffset in range(0, cache.cacheLineSizeBytes, 2):    # test all half word offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=halfWordOffset,bytes=2,data=0x4141)
                assert (cache.dataMemory[set]>>halfWordOffset*8)&0xFFFF == 0x4141
                mask = 0xFFFF << (halfWordOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            for wordOffset in range(0, cache.cacheLineSizeBytes, 4):        # test all word offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=wordOffset,bytes=4,data=0x41414242)
                assert (cache.dataMemory[set]>>wordOffset*8)&0xFFFF_FFFF == 0x41414242
                mask = 0xFFFF_FFFF << (wordOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)
        
            ## test data with too many digits ##
            for byteOffset in range(cache.cacheLineSizeBytes): # test all byte offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=byteOffset,bytes=1,data=0xdeadbeef)
                assert (cache.dataMemory[set]>>byteOffset*8)&0x0000_00FF == 0xef
                mask = 0xFF << (byteOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            for halfWordOffset in range(0, cache.cacheLineSizeBytes, 2):    # test all half word offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=halfWordOffset,bytes=2,data=0xdeadbeef)
                assert (cache.dataMemory[set]>>halfWordOffset*8)&0xFFFF == 0xbeef
                mask = 0xFFFF << (halfWordOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

            for wordOffset in range(0, cache.cacheLineSizeBytes, 4):        # test all word offsets
                cache.dataMemory[set]=random.randint(0x0, ((1<<(cache.cacheLineSizeBytes*8)-1)))
                originalData = cache.dataMemory[set]  # Save original data for comparison
                cache.write(set=set,way=0,byteOffset=wordOffset,bytes=4,data=0xdeadbeef)
                assert (cache.dataMemory[set]>>wordOffset*8)&0xFFFF_FFFF == 0xdeadbeef
                mask = 0xFFFF_FFFF << (wordOffset * 8)
                assert (cache.dataMemory[set] & ~mask) == (originalData & ~mask)

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
            
    def readHit(self, cache, set):
        # test a random read for each cache set
        # can be hit or miss based on valid bit
        tagLine = cache.tagMemory[set]
        tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

        randomTagInSet = random.choice(tagArr)
        cmd = random.choice([("LB", 0b00), ("LHW", 0b01), ("LW", 0b11)]) #(cmd, alignment requirement)

        byteOffset = random.randint(0,int(cache.cacheLineSizeBytes-1))
        byteOffset=byteOffset & (~cmd[1]) # align accordingly
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
        dataWord = getWord(dataLine, byteOffset)
        validBit = getBit(validLine, way)

        response=cache.requestCMD(addr=randomAddr, data=None, cacheLine=None, cmd=cmd[0])
        
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

    def testReadHitAllSets(self, cache):
        for set in range(cache.sets):
            self.readHit(cache, set)

    def readMiss(self, cache, set):
        # test a random read for each cache set
        # can be hit or miss based on valid bit
        way = random.randint(0, cache.ways-1) 

        tagLine = cache.tagMemory[set]
        tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

        randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set

        while(randomTagInSet in tagArr):
            randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set

        cmd = random.choice([("LB", 0b00), ("LHW", 0b01), ("LW", 0b11)]) #(cmd, alignment requirement)

        byteOffset = random.randint(0,int(cache.cacheLineSizeBytes-1))
        byteOffset = byteOffset & (~cmd[1]) # align accordingly

        randomAddr = constructAddr(tag=randomTagInSet, _set=set, byteOffset=byteOffset, setSize=cache.sets, lineSize=cache.cacheLineSizeBytes)

        # Buffer old data #
        oldValid = cache.validMemory[set]
        oldPLRU = cache.PLRUMemory[set]
        oldDirty = cache.dirtyMemory[set]
        oldTag   = cache.tagMemory[set]
        oldData   = cache.dataMemory[set]

        response=cache.requestCMD(addr=randomAddr, data=None, cacheLine=None, cmd=cmd[0])
        
        # Validate response packet #
        assert response.getHit() == 0b0
        assert response.getAddr() == randomAddr

        # Validate cache state #
        assert cache.PLRUMemory[set]  == oldPLRU,  f"Expected {oldPLRU} got {cache.PLRUMemory[set]}"
        assert cache.tagMemory[set]   == oldTag,   f"Expected {oldTag}, got {cache.tagMemory[set]}"
        assert cache.validMemory[set] == oldValid, f"Expected {oldValid}, got {cache.validMemory[set]}"
        assert cache.dirtyMemory[set] == oldDirty, f"Expected {oldDirty}, got {cache.dirtyMemory[set]}"
        assert cache.dataMemory[set]  == oldData,  f"Expected {oldData}, got {cache.dataMemory[set]}"

    def testReadMissAllSets(self, cache):
        for set in range(cache.sets):
            self.readMiss(cache, set)

    def writeHit(self, cache, set):
        # test a random read for each cache set
        # can be hit or miss based on valid bit
        tagLine = cache.tagMemory[set]
        tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

        randomTagInSet = random.choice(tagArr)

        cmd = random.choice([("SB", 0b00), ("SHW", 0b01), ("SW", 0b11)]) #(cmd, alignment requirement)

        byteOffset = random.randint(0,int(cache.cacheLineSizeBytes-1))
        byteOffset=byteOffset & (~cmd[1]) # align accordingly
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
        dataWord = getWord(dataLine, byteOffset)
        validBit = getBit(validLine, way)

        wrData = 0
        if(cmd[0] == "SW"):
            wrData = random.randint(0x0, 0xFFFF_FFFF)
        elif(cmd[0] == "SHW"):
            wrData = random.randint(0x0, 0xFFFF)
        elif(cmd[0] == "SB"):
            wrData = random.randint(0x0, 0xFF)
        else:
            assert False, "cmd not valid"

        response=cache.requestCMD(addr=randomAddr, data=wrData, cacheLine=None, cmd=cmd[0])

        actualData = (cache.dataMemory[way*cache.sets + set] >> (byteOffset*8))
        if(cmd[0] == "SW"):
            actualData &= 0xFFFF_FFFF
        elif(cmd[0] == "SHW"):
            actualData &= 0xFFFF
        elif(cmd[0] == "SB"):
            actualData &= 0xFF
        else:
            assert False, "cmd not valid"
        
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
        assert cache.dirtyMemory[set] == (oldDirty | (1<<way)), f"Expected {oldDirty}, got {cache.dirtyMemory[set]}" 
        assert actualData  == wrData,  f"Expected {wrData}, got {actualData}"

    def testWriteMissAllSets(self, cache):
        for set in range(cache.sets):
            self.writeMiss(cache, set)

    def writeMiss(self, cache, set):
            way = random.randint(0, cache.ways-1) 

            tagLine = cache.tagMemory[set]
            tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

            randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set
            while(randomTagInSet in tagArr):
                randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set

            cmd = random.choice([("SB", 0b00), ("SHW", 0b01), ("SW", 0b11)]) #(cmd, alignment requirement)

            byteOffset = random.randint(0,int(cache.cacheLineSizeBytes-1))
            byteOffset = byteOffset & (~cmd[1]) # align accordingly

            randomAddr = constructAddr(tag=randomTagInSet, _set=set, byteOffset=byteOffset, setSize=cache.sets, lineSize=cache.cacheLineSizeBytes)

            # Buffer old data #
            oldValid = cache.validMemory[set]
            oldPLRU = cache.PLRUMemory[set]
            oldDirty = cache.dirtyMemory[set]
            oldTag   = cache.tagMemory[set]
            oldData   = cache.dataMemory[set]

            response=cache.requestCMD(addr=randomAddr, data=random.randint(0,0xFFFF_FFFF), cacheLine=None, cmd=cmd[0])
            
            # Validate response packet #
            assert response.getHit() == 0b0
            assert response.getAddr() == randomAddr

            # Validate cache state #
            assert cache.PLRUMemory[set]  == oldPLRU,  f"Expected {oldPLRU} got {cache.PLRUMemory[set]}"
            assert cache.tagMemory[set]   == oldTag,   f"Expected {oldTag}, got {cache.tagMemory[set]}"
            assert cache.validMemory[set] == oldValid, f"Expected {oldValid}, got {cache.validMemory[set]}"
            assert cache.dirtyMemory[set] == oldDirty, f"Expected {oldDirty}, got {cache.dirtyMemory[set]}"
            assert cache.dataMemory[set]  == oldData,  f"Expected \n{hex(oldData)}, got \n{hex(cache.dataMemory[set])}. CMD: {cmd[0]}, {cmd[1]}. BO {byteOffset}"

    def testWriteMissAllSets(self, cache):
        # test a random read for each cache set
        # can be hit or miss based on valid bit
        for set in range(cache.sets):
            self.writeMiss(cache, set)

    def testRandomOpHit(self, cache):
        for _ in range(100000):
            test = random.choice([self.readHit, self.writeHit])
            test(cache, random.randint(0,cache.sets-1))

    def testRandomOpMiss(self, cache):
        for _ in range(100000):
            test = random.choice([self.readMiss, self.writeMiss])
            test(cache, random.randint(0,cache.sets-1))
    
    def testFuzzLoadStore(self, cache):   # Random tests
        for _ in range(100000):
            test = random.choice([self.readMiss, self.writeMiss, self.writeMiss, self.writeHit])
            test(cache, random.randint(0,cache.sets-1))

    def allocate(self, cache, set):
        tagLine = cache.tagMemory[set]
        tagArr = splitLine(tagLine, cache.ways, cache.tagSize)

        randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set
        while(randomTagInSet in tagArr):
            randomTagInSet = random.randint(0x0, (1<<cache.tagSize)-1)  # Randomize till not in tag set

        cmd = "ALLOCATE"

        byteOffset = 0
        randomAddr = constructAddr(tag=randomTagInSet, _set=set, byteOffset=byteOffset, setSize=cache.sets, lineSize=cache.cacheLineSizeBytes)

        # Buffer old data #
        oldValid = cache.validMemory[set]
        oldDirty = cache.dirtyMemory[set]
        oldTag   = cache.tagMemory[set]
        dirtyLine = cache.dirtyMemory[set]

        validLine = cache.validMemory[set]
        PLRULine  = cache.PLRUMemory[set]
        oldPLRU  = cache.PLRUMemory[set]

        # Get metadata #
        way = 0
        for i in range(cache.ways):
            if((PLRULine & (1<<i))==0b0):
                way = i
                break

        # Get data #
        dataLine = cache.dataMemory[way*cache.sets + set]
        # Process #
        dataWord = getWord(dataLine, byteOffset)
        validBit = getBit(validLine, way)
        dirtyBit = getBit(dirtyLine, way)

        allocateLine = random.randint(0x0, ((1<<(cache.cacheLineSizeBytes)-1)))
        response=cache.requestCMD(addr=randomAddr, data=None, cacheLine=allocateLine, cmd=cmd)

        tagLine = cache.tagMemory[set]
        actualData = (cache.dataMemory[way*cache.sets + set])

        # Validate response packet #
        assert response.getHit() == 0b0
        #assert response.getData() == dataWord
        assert response.getWriteback() == validBit & dirtyBit
        assert response.getAddr() == randomAddr

        # Validate cache state #
        assert cache.PLRUMemory[set]  == oldPLRU
        assert splitLine(cache.tagMemory[set], cache.ways, cache.tagSize)[cache.ways -1 -way]   == randomTagInSet, f"{hex(splitLine(tagLine, 4, cache.tagSize)[cache.ways-1-way])}, {hex(randomTagInSet)}"
        assert cache.validMemory[set] == (oldValid | (1<<way)), f"Expected {oldValid}, got {cache.validMemory[set]}"
        assert cache.dirtyMemory[set] == (oldDirty & (~(1<<way))), f"Expected {oldDirty & (~(1<<way))}, got {cache.dirtyMemory[set]}" 
        assert actualData == allocateLine

    def testAllocateEvictAllSets(self, cache):
        for set in range(cache.sets):
            self.allocate(cache,set)

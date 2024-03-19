from utils import *
import random
import numpy as np

cacheCommands={
    "LB":  0b0000,
    "LHW": 0b0001,
    "LW":  0b0010,

    "NOP":  0b0011,

    "SB":  0b0100,
    "SHW": 0b0101,
    "SW":  0b0110,

    "ALLOCATE": 0b0111, 
    
    "FW":  0b1000
}

cmdToBytes={
    "LB":  1,
    "LHW": 2,
    "LW":  4,

    "SB":  1,
    "SHW": 2,
    "SW":  4,
}


class cacheMem():
    def __init__(self, sets=64, ways=4, cacheLineSizeBytes=32):

        self.sets = sets
        self.ways = ways
        self.cacheLineSizeBytes = cacheLineSizeBytes

        self.setBits = int(np.log2(sets))
        self.byteOffsetBits = int(np.log2(cacheLineSizeBytes))
        self.tagSize = int(32 - self.byteOffsetBits - self.setBits )

        print("Initialized memory with following config:")
        print(f"sets: {self.sets}")
        print(f"ways: {self.ways}")
        print(f"Block size: {self.cacheLineSizeBytes}")
        dmemSize = self.cacheLineSizeBytes*self.ways*self.sets*8
        plruSize = self.ways*self.sets
        dirtySize = self.ways*self.sets
        tagsSize = self.tagSize*self.ways*self.sets
        totalSize = tagsSize + dirtySize + plruSize + dmemSize
        print(f"Total Data size: {dmemSize/8}B")
        print(f"Total required memory (including metadata): {totalSize/8}B")

        ## DMEM
        self.dataMemory=[0]*sets*ways
        ## Tags
        self.tagMemory=[0]*sets
        ## Dirty
        self.dirtyMemory=[0]*sets
        ## PLRU
        self.PLRUMemory=[0]*sets

    def addrToTag(self, addr):
        return (addr >> (self.byteOffsetBits + self.setBits)) & ((1<<self.tagSize)-1)

    def requestCMD(self, addr, data ,cmd):
        """ Decodes the way (if any) and set, then passes control to read/write functions"""
        assert cmd in cacheCommands

        tagLine = self.getTagLine(addr)
        tagArray = splitLine(tagLine, self.ways, 21)
        tag = self.addrToTag(addr)
        
        byteOffset = addr & ((1<<self.byteOffsetBits)-1)
        
        bytes = cmdToBytes[cmd]

        # find hit way (if any)
        if tag in tagArray:
            hitWay = self.ways - 1 - tagArray.index(tag) # [3, 2, 1, 0] <= index and way are reversed
            set = self.getSet(addr)
            print(hitWay)
            ## Update PLRU
            self.updatePLRU(set, hitWay)
            if cmd in ["SW", "SHW", "SB"]:
                return (1, self.write(set, hitWay=hitWay, byteOffset=byteOffset, bytes=bytes, data=data))
            elif cmd in ["LW", "LHW", "LB"]:
                return (1, self.read(set, hitWay, byteOffset, bytes))
            elif cmd in ["ALLOCATE"]:
                pass
            elif cmd in ["NOP"]:
                pass
            else:
                assert False, "CMD in requestCMD() not valid"

        else:
            return (0, None)

    def updatePLRU(self, set, way):
        PLRU = self.PLRUMemory[set]
        if((PLRU | (1<<way)) == 0xF):
            self.PLRUMemory[set] = (1<<way)
        else:
            self.PLRUMemory[set] = PLRU | (1<<way)

    def getSet(self, addr):
        setMask = (1<<self.setBits)-1
        addr = addr >> self.byteOffsetBits
        addr = addr & setMask
        return addr


    def read(self, set, way, byteOffset, bytes):
        assert bytes in [1,2,4] # Read 1, 2, or 4 bytes from addr
        cacheAddr = way * self.sets + set
        cacheLine = self.getDmemLine(cacheAddr)

        result = 0
        if(bytes>=1): result |= (getByte(cacheLine, byteOffset + 0) << 0)
        if(bytes>=2): result |= (getByte(cacheLine, byteOffset + 1) << 8)
        if(bytes>=3): result |= (getByte(cacheLine, byteOffset + 2) << 16)
        if(bytes>=4): result |= (getByte(cacheLine, byteOffset + 3) << 24)

        return result

    def write(self, set, way, byteOffset, bytes, data):
        assert bytes in [1,2,4] # Write 1, 2, or 4 bytes from addr

        cacheAddr = way * self.sets + set
        cacheLine = self.getDmemLine(cacheAddr)

        if(bytes>=1): 
            mask = ~(0xFF << (byteOffset+0))
            cacheLine&=mask # set this part of the word to 0
            cacheLine|=((data&0xFF)<<(byteOffset+00))
            data = data>>8
        if(bytes>=2): 
            mask = ~(0xFF << (byteOffset+8))
            cacheLine&=mask
            cacheLine|=((data&0xFF)<<(byteOffset+8))
            data = data>>8
        if(bytes>=3): 
            mask = ~(0xFF << (byteOffset+16))
            cacheLine&=mask
            cacheLine|=((data&0xFF)<<(byteOffset+16))
            data = data>>8
        if(bytes>=4): 
            mask = ~(0xFF << (byteOffset+24))
            cacheLine&=mask
            cacheLine|=((data&0xFF)<<(byteOffset+24))
        
        self.setDmemLine(cacheAddr, cacheLine)

    def evict(self, addr, cacheLine):
        pass

    def allocate(self, addr, cacheLine):
        pass

    def getDmemLine(self, line):
        return self.dataMemory[line]

    def setDmemLine(self, line, data):
        self.dataMemory[line]=data

    def printDmem(self):
        print("Data Memory")
        for way in range(self.ways):
            for set in range(self.sets):
                print(f"{way:02} {set:02}: ",end="")
                for byte in range(self.cacheLineSizeBytes):
                    print(f"{getByte(self.getDmemLine(way*self.sets + set), byte):0{2}x}",end=" ")

                print("")

    def getTagLine(self, line):
        return self.tagMemory[line]

    def printTags(self):
        print("Tag Memory")
        tagPos=int(np.ceil(self.tagSize/4))
        for set in range(self.sets):
            print(f"{set:02}: ",end="")
            for way in range(self.ways):
                print(f"{getTag(self.getTagLine(set), way, self.tagSize):0{tagPos}x}",end=" ")
            print("")

    def getDirtyLine(self, line):
        return self.dirtyMemory[line]

    def printDirty(self):
        print("Dirty Memory")
        tagPos=int(np.ceil(self.tagSize/4))
        for set in range(self.sets):
            print(f"{set:02}: ",end="")
            for way in range(self.ways):
                print(f"{getDirtyBit(self.getTagLine(set), way)}",end=" ")
            print("")

    def getPLRULine(self, line):
        return self.PLRUMemory[line]

    def printPLRU(self):
        print("PLRU Memory")
        tagPos=int(np.ceil(self.tagSize/4))
        for set in range(self.sets):
            print(f"{set:02}: ",end="")
            for way in range(self.ways):
                print(f"{getPLRUBit(self.getPLRULine(set), way)}",end=" ")
            print("")

    ####################
    ## INIT FUNCTIONS ##
    ####################

    def initTagMem(self):
        for set in range(self.sets):
            tagLine=0x0
            for way in range(self.ways):
                tagLine |= ((self.ways - 1 - way) <<(way*self.tagSize))
            self.tagMemory[set] = tagLine

    def initDMem(self):
        for way in range(self.ways):
            for set in range(self.sets):
                cacheLine=0
                for byte in range(self.cacheLineSizeBytes):
                    cacheLine |= (random.randint(0x0,0xFF) << (byte*8))
                self.dataMemory[way * self.sets + set] = cacheLine


if __name__=="__main__":
    random.seed(0x42)
    _cacheMem = cacheMem()

    _cacheMem.initTagMem()
    _cacheMem.initDMem()

    #_cacheMem.printTags()
    #_cacheMem.printPLRU()
    #_cacheMem.printDirty()

    _cacheMem.printTags()
    _cacheMem.printDmem()

    result=_cacheMem.requestCMD(addr=(0x0<<11), data=0x0, cmd="LW")
    print(f"{hex(result[1])}")


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

class cacheMemInterface():
    # Reseponse packet class for the cache memory
    def __init__(self):
        self.hit = 0
        self.data = 0
        self.addr = 0
        self.valid = 0
        self.evictionLine = 0
        self.writeback = 0

    def setHit(self,hit):
        self.hit = hit

    def setData(self, data):
        self.data = data

    def setAddr(self, addr):
        self.addr = addr

    def setEvictionLine(self, evictionLine):
        self.evictionLine = evictionLine

    def setValid(self, valid):
        self.valid = valid

    def setWriteback(self, writeback):
        self.writeback = writeback

    def getHit(self):           return self.hit
    def getData(self):          return self.data
    def getAddr(self):          return self.addr
    def getValid(self):         return self.valid
    def getEvictionLine(self):  return self.evictionLine
    def getWriteback(self):     return self.writeback

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
        dmemSize  = self.cacheLineSizeBytes*self.ways*self.sets*8
        plruSize  = self.ways*self.sets * 4
        dirtySize = self.ways*self.sets * 4
        validSize = self.ways*self.sets * 4
        tagsSize  = self.tagSize*self.ways*self.sets
        totalSize = tagsSize + dirtySize + plruSize + dmemSize + validSize
        print(f"Total Data size: {dmemSize/8}B")
        print(f"Total required memory (including metadata): {totalSize/8}B")

        ## DMEM
        self.dataMemory  =  [0]*sets*ways
        ## Tags
        self.tagMemory   =  [0]*sets
        ## Dirty
        self.dirtyMemory =  [0]*sets
        ## PLRU
        self.PLRUMemory  =  [0]*sets
        ## Valid
        self.validMemory =  [0]*sets


    def randomizeActiveState(self): # Intended to recreate a cache state after it has been active for some time
        random.seed(0x42)
        self.randomizeTagMem() # randomize tags
        self.randomizeDMem()
        self.randomizePLRU()
        self.randomizeDirty()
        self.randomizeValid()


    def resetMemory(self, mem):
        for i in range(len(mem)):
            mem[i] = 0

    def setMemory(self, mem):
        for i in range(len(mem)):
            mem[i] = 1
    
    def addrToTag(self, addr):
        return (addr >> (self.byteOffsetBits + self.setBits)) & ((1<<self.tagSize)-1)

    def getAllocateWay(self, set):
        PLRU = self.PLRUMemory[set]
        for i in range(self.ways):
            if((PLRU & 0b1) == 0b0):
                return i 
            PLRU>>=1
        assert False, "PLRU not updating correctly. Cannot get allocate way."

    def getValid(self, set, way):
        validLine = self.validMemory[set]
        valid = ((validLine >> way) & 0b1)
        return valid

    def getDirty(self, set, way):
        dirtyLine = self.dirtyMemory[set]
        dirty = ((dirtyLine >> way) & 0b1)
        return dirty

    def updateValid(self, set, way):
        mask = 1<<way
        validLine = self.validMemory[set]
        validLine |= mask
        self.validMemory[set] = validLine

    def requestCMD(self, addr, data, cacheLine, cmd):
        """ Decodes the way (if any) and set, then passes control to read/write functions"""
        assert cmd in cacheCommands
        set = self.getSet(addr)
        tagLine = self.getTagLine(set)
        tagArray = splitLine(tagLine, self.ways, 21) #FIXME: dont hardcode tagsize
        tag = self.addrToTag(addr)

        byteOffset = addr & ((1<<self.byteOffsetBits)-1)
        
        response = cacheMemInterface()

        if(cmd in ["LHW", "SHW"]):
            assert (addr & 0b1)==0b0, f"Exception, LHW alignment invalid. cmd HW, {bin(addr)}"

        if(cmd in ["LW", "SW"]):
            assert (addr & 0b11)==0b0, f"Exception, LW alignment invalid.  cmd W, {bin(addr)}"

        if (cmd not in cacheCommands):
            assert False, "CMD in requestCMD() not valid"


        # find hit way (if any)
        hitWay = self.ways - 1
        hit=0
        if tag in tagArray:
            hitWay = self.ways - 1 - tagArray.index(tag) # hit in tag
            hit=1
            ## Update PLRU
        valid = self.getValid(set, hitWay) # was that entry valid?
        if cmd in ["SW", "SHW", "SB"]:
            bytes = cmdToBytes[cmd]
            if hit:
                self.updatePLRU(set, hitWay)
                self.updateDirty(set, hitWay)
            response.setData(self.write(set, hitWay, byteOffset, bytes, data))
            response.setAddr(addr)
            response.setHit(hit & valid)
            response.setValid(valid) # redundancy...
            return response
        elif cmd in ["LW", "LHW", "LB"]:
            if hit & valid:
                self.updatePLRU(set, hitWay)
            response.setValid(valid) # Validity of the data, not the output
            bytes = cmdToBytes[cmd]
            response.setAddr(addr)
            response.setHit(hit & valid)
            response.setData(self.read(set, hitWay, byteOffset, bytes))
            return response

        if cmd in ["ALLOCATE"]:
            # Step 1: get allocate way (PLRU)
            # Step 2: read old data (eviction line)
            # Step 3: write new line
            # Step 4: Clear dirty

            allocateWay = self.getAllocateWay(set)
            dirty = self.getDirty(set, allocateWay) # was that entry valid?
            valid = self.getValid(set, allocateWay) # was that entry valid?

            response.setEvictionLine(self.dataMemory[allocateWay*self.sets + set])
            response.setHit(0) # Sure about this?
            response.setAddr(addr)
            response.setValid(valid) #FIXME: is this right?
            response.setWriteback(valid & dirty) #FIXME: is this right?
            self.dataMemory[allocateWay*self.sets + set] = cacheLine

            self.tagMemory[set] &= ~(((1<<self.tagSize)-1)<<(self.tagSize*allocateWay))
            self.tagMemory[set] |= ((tag)<<(self.tagSize*allocateWay))

            self.clearDirty(set, allocateWay)
            self.updateValid(set, allocateWay)
            return response
        if cmd in ["NOP"]:
            return (0, addr, None)
        return -1

    def updatePLRU(self, set, way):
        PLRU = self.PLRUMemory[set]
        if((PLRU | (1<<way)) == 0xF):
            self.PLRUMemory[set] = (1<<way)
        else:
            self.PLRUMemory[set] = PLRU | (1<<way)

    def updateDirty(self, set, way):
        Dirty = self.dirtyMemory[set]
        self.dirtyMemory[set] = (1<<(way)) | Dirty

    def clearDirty(self, set, way):
        Dirty = self.dirtyMemory[set]
        self.dirtyMemory[set] = (~(1<<(way))) & Dirty

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
            mask = ~(0xFF << (byteOffset*8+0))
            cacheLine&=mask # set this part of the word to 0
            cacheLine|=((data&0xFF)<<(byteOffset*8+0))
            data = data>>8
        if(bytes>=2): 
            mask = ~(0xFF << (byteOffset*8+8))
            cacheLine&=mask
            cacheLine|=((data&0xFF)<<(byteOffset*8+8))
            data = data>>8
        if(bytes>=3): 
            mask = ~(0xFF << (byteOffset*8+16))
            cacheLine&=mask
            cacheLine|=((data&0xFF)<<(byteOffset*8+16))
            data = data>>8
        if(bytes>=4): 
            mask = ~(0xFF << (byteOffset*8+24))
            cacheLine&=mask
            cacheLine|=((data&0xFF)<<(byteOffset*8+24))
        
        self.setDmemLine(cacheAddr, cacheLine)
        return None

    def evict(self, addr, cacheLine):
        pass

    def allocate(self, addr, cacheLine):
        pass

    def getDmemLine(self, line):
        return self.dataMemory[line]

    def setDmemLine(self, line, data):
        self.dataMemory[line]=data

    def printDmem(self):
        print("Model Data Memory")
        #for way in range(self.ways):
            #for set in range(self.sets):
                #print(f"{way:02} {set:02}: ",end="")
                #for byte in range(self.cacheLineSizeBytes):
                    #print(f"{getByte(self.getDmemLine(way*self.sets + set), (self.cacheLineSizeBytes -1 - byte)):0{2}x}",end=" ")
                #print("")

        for way in range(self.ways):
            for set in range(self.sets):
                print(f"{way:02} {set:02}: ",end="")
                line = self.getDmemLine(way*self.sets + set)
                print(f"{line:064x}")

    def getTagLine(self, line):
        return self.tagMemory[line]

    def printTags(self):
        print("Model Tag Memory")
        tagPos=int(np.ceil(self.tagSize/4))
        for set in range(self.sets):
            print(f"{set:02}: ",end="")
            for way in range(self.ways):
                print(f"{getTag(self.getTagLine(set), self.ways -1 - way, self.tagSize):0{tagPos}x}",end=" ")
            print("")
            #print(f"{hex(self.getTagLine(set))}")

    def getDirtyLine(self, line):
        return self.dirtyMemory[line]

    def printDirty(self):
        print("Model Dirty Memory")
        tagPos=int(np.ceil(self.tagSize/4))
        for set in range(self.sets):
            print(f"{set:02}: ",end="")
            #for way in range(self.ways):
                #print(f"{getDirtyBit(self.getDirtyLine(set), self.ways - 1 - way)}",end=" ")
            #print("")
            print(f"{hex(self.getDirtyLine(set))}")

    def getPLRULine(self, line):
        return self.PLRUMemory[line]

    def printPLRU(self):
        print("Model PLRU Memory")
        tagPos=int(np.ceil(self.tagSize/4))
        for set in range(self.sets):
            print(f"{set:02}: ",end="")
            #for way in range(self.ways):
                #print(f"{getPLRUBit(self.getPLRULine(set), self.ways - 1 - way)}",end=" ")
            print(f"{hex(self.getPLRULine(set))}")

    ####################
    ## INIT FUNCTIONS ##
    ####################

    def randomizeTagMem(self):   # init with unique random set
        tagMax = (1<<self.tagSize) -1
        for set in range(self.sets):
            tagSet = []
            tagLine=0x0
            while(len(tagSet) < 4):
                randomTag = random.randint(0x0, tagMax)
                if randomTag not in tagSet:
                    tagLine = tagLine | (randomTag <<((len(tagSet))*self.tagSize))
                    tagSet.append(randomTag)
            self.tagMemory[set] = tagLine
        
    def randomizeDMem(self):     # init with fully random data
        for way in range(self.ways):
            for set in range(self.sets):
                cacheLine=0
                for byte in range(self.cacheLineSizeBytes):
                    cacheLine |= (random.randint(0x0,0xFF) << (byte*8))
                self.dataMemory[way * self.sets + set] = cacheLine

    def randomizePLRU(self):     # init with fully random data
        for set in range(self.sets):
            self.PLRUMemory[set] = random.randint(0x0, 0xE)

    def randomizeDirty(self):     # init with fully random data
        for set in range(self.sets):
            self.dirtyMemory[set] = random.randint(0x0, 0xF)

    def randomizeValid(self):     # init with fully random data
        for set in range(self.sets):
            self.validMemory[set] = random.randint(0x0, 0xF)

# TODO: Confirm printing and "way" problems are fixed
# TODO: Address fixmes, etc

if __name__=="__main__":
    random.seed(0x42)
    _cacheMem = cacheMem()
    _cacheMem.randomizeActiveState()

    #_cacheMem.printTags()
    _cacheMem.printDmem()
    #_cacheMem.printValid()

    
    result=_cacheMem.requestCMD(addr=3206341344, data=0xe44e065, cmd="SHW", cacheLine=None)

    _cacheMem.printDmem()
    #print(f"hit {result.hit}")
    #print(f"data {hex(result.data)}")


    #_cacheMem.randomizeDMem()
    #_cacheMem.randomizeTagMem()
    #_cacheMem.printTags()

    #_cacheMem.printDirty()
    #_cacheMem.printTags()
    #_cacheMem.printDmem()
    #_cacheMem.printPLRU()

    #result=_cacheMem.requestCMD(addr=(0x0<<11)+(63<<5) + (0<<0), data=0x42, cacheLine=None, cmd="SW")
    #result=_cacheMem.requestCMD(addr=(0x1<<11)+(63<<5) + (0<<0), data=0x42, cacheLine=None, cmd="SW")
    #result=_cacheMem.requestCMD(addr=(0x2<<11)+(63<<5) + (0<<0), data=0x42, cacheLine=None, cmd="SW")
    #result=_cacheMem.requestCMD(addr=(0x3<<11)+(63<<5) + (0<<0), data=0x42, cacheLine=None, cmd="SW")
    #result=_cacheMem.requestCMD(addr=(0x0<<11)+(63<<5) + (0<<0), data=0x42, cacheLine=None, cmd="SW")

    #_cacheMem.printPLRU()

    #result=_cacheMem.requestCMD(addr=(0x7<<11)+(63<<5) + (0<<0), data=0x0, cacheLine=0x42, cmd="ALLOCATE") 
    #result=_cacheMem.requestCMD(addr=(0x7<<11)+(63<<5) + (0<<0), data=0x0, cacheLine=0x42, cmd="ALLOCATE") #FIXME: how to handle allocate to way that already exists?

    #_cacheMem.printPLRU() # wrong
    #_cacheMem.printDirty()

    #_cacheMem.printDmem()
    print("Done")
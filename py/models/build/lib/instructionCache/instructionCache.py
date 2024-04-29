import random
import sys
from pathlib import Path
sys.path.append(str(Path("../..").resolve()))
from utils import *
sys.path.append('models/instructionCache')
#
sys.path.append(str(Path("../genericLRU").resolve()))
sys.path.append('models/instructionCache')
from genericCache import *
sys.path.append(str(Path("../instructionCache").resolve()))

validator = [[0b11, 0b01], [0b1111, 0b0111, 0b0011, 0b0001]]

class fetchPacketProcessor:
    # Takes in a byte array and constructs an actual fetch packet of validated instructions
    def __init__(self, fetchWidth):
        self.fetchWidth = fetchWidth
        self.instructionArr = None
        self.validArr = None
        # Determine which validation mask to use based on fetchWidth
        self.validator = validator[int(np.log2(fetchWidth))-1]
        self.instructionIndexMask = (1 << int(np.log2(fetchWidth))) - 1

    def separate(self, byteArr):
        # Split the byte array into instructions (4 bytes each) of count fetchWidth
        instructions = []
        # Process the array in chunks of 4 bytes (32-bit instructions)
        for i in range(0, len(byteArr), 4):
            instruction = byteArr[i:i + 4]
            # Add the instruction to the list if there are enough bytes (4 bytes)
            if len(instruction) == 4:
                instructions.append(instruction)
            # Break if we reach the fetchWidth
            if len(instructions) == self.fetchWidth:
                break
        return instructions

    def getRelativeIndex(self, PC): # get the index of the instruction relative to the fetchWidth packet
        # Calculate the instruction index using PC and the instruction index mask
        instructionIndex = (PC >> 2) & self.instructionIndexMask
        return instructionIndex

    def validate(self, PC):
        # Use the instruction index to retrieve the validation mask
        instructionIndex = self.getRelativeIndex(PC)
        return self.validator[instructionIndex]

    def processFetchPacket(self, PC, byteArray):
        # Separate the byte array into instructions
        instructions = self.separate(byteArray)
        # Validate the instructions using the PC
        validBits = self.validate(PC)
        return (instructions, validBits)


class instructionCache():
    def __init__(self, sets, ways, blockSize, fetchWidth):
        self.cache = genericCache(sets=sets, ways=ways, blockSize=blockSize, evictionPolicy=LRU)
        self.sets = sets
        self.ways = ways
        self.blockSize = blockSize
        self.fetchWidth = fetchWidth
        self.addressMask = 0xFFFF_FFFF-(1 << int(np.log2(fetchWidth)+2))+1  # mask such that all memory accesses alias to the nearest fetch packet
        self.fetchPacketProcessor = fetchPacketProcessor(fetchWidth=fetchWidth)

    def allocate(self, address, data):
        self.cache.allocate(address,data)

    def forceWrite(self, address, way, data):
        self.cache.forceWrite(address, way, data)

    def read(self, address):
        fetchPacketPC = self.addressMask & address
        (hit, fetchPacketByteArr), hit_way = self.cache.read(address=fetchPacketPC, bytes=4*self.fetchWidth)
        instructions=None
        validBits=None
        if(hit):
            instructions, validBits = self.fetchPacketProcessor.processFetchPacket(address, fetchPacketByteArr)
            
            for i in range(len(instructions)):
                instructions[i] = hex(int.from_bytes(instructions[i], byteorder='big'))
        return instructions, validBits

    def print(self):
        self.cache.print()

SETS = 64
WAYS = 2
BLOCK_SIZE = 32

if __name__=="__main__":
    instructionCache0 = instructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4)

    addrA = generateAddr(tag=0x42, set=0, byteOffset=0, sets=SETS, blockSize=BLOCK_SIZE)
    addrA = 0x8B074c90
    addrA=0x2E928
    dataA = bytearray.fromhex("deadbeef")
    cache_line_A = genericCacheLine(blockSize=BLOCK_SIZE, data=dataA)
    instructionCache0.allocate(address=addrA, data=cache_line_A)

    test = instructionCache0.read(address=addrA)
    print(test[0])
    
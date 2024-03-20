import numpy as np
import logging

def getByteCacheLine(cacheLine, byte):
    pass

def getHalfWordCacheLine(cacheLine, byte):
    pass

def getWordCacheLine(cacheLine, byte):
    pass

def shiftByBytes(din, byteShift):
    pass

def getByte(cacheLine, byteIndex):
    shifted = cacheLine >> (byteIndex * 8)
    byteValue = shifted & 0xFF
    return byteValue

def getTag(tagLine, tagIndex, tagSize):
    shifted = tagLine >> (tagIndex * tagSize)
    tagValue = shifted & ((1<<tagSize)-1)
    return tagValue

def getDirtyBit(dirtyLine, index):
    shifted = dirtyLine >> (index * 1)
    DirtyValue = shifted & 0b1
    return DirtyValue

def getPLRUBit(tagLine, tagIndex):
    shifted = tagLine >> (tagIndex * 1)
    tagValue = shifted & 0b1
    return tagValue

def splitLine(line, count, width):
    mask = (1 << width) - 1
    elements = []
    for i in range(count):
        element = (line >> (i * width)) & mask
        elements.insert(0, element)
    return elements

def constructAddr(tag, _set, byteOffset, setSize, lineSize):
    setBits = int(np.ceil(np.log2(setSize)))
    lineBits = int(np.ceil(np.log2(lineSize)))
    
    addr = (tag<<(setBits+lineBits)) | (_set << lineBits) | byteOffset
    return addr

def getBit(word, bit):
    return (word>>bit) & 0b1

def getWord(line, word):
    word = line >> (word*32)
    word = word & 0xFFFF_FFFF
    return word

def getPLRUNext(PLRU, way, totalWays):
    allBitsSet = (1 << totalWays) - 1  # Replace total_ways with the actual number of ways
    if PLRU | (1 << way) == allBitsSet: 
        return 1 << way  # This could be your specific way to indicate 'next' in PLRU
    else:
        return PLRU | (1 << way)  # Typically you'd update PLRU to reflect recent usage



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

def getDirtyBit(tagLine, tagIndex):
    shifted = tagLine >> (tagIndex * 1)
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

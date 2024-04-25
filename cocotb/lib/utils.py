import numpy as np

def getSet(address, sets, blockSize):
    block_number = address // blockSize
    setIndex = block_number % sets
    return setIndex

def getTag(address, sets, blockSize):
    block_number = address // blockSize
    tag = block_number // sets
    return tag


def getByteOffset(address, blockSize):
    num_bits = int(np.log2(blockSize))
    mask = (1 << num_bits) - 1
    byteOffset = address & mask
    return byteOffset

def generateAddr(tag, set, byteOffset, sets, blockSize):
    numSetBits = (sets - 1).bit_length()
    numBlockBits = (blockSize - 1).bit_length()
    address = (tag << (numSetBits + numBlockBits)) | (set << numBlockBits) | byteOffset
    return address
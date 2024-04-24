import numpy as np

def getSet(address, sets, blockSize):
    block_number = address // blockSize
    setIndex = block_number % sets
    return setIndex

def getTag(address, sets, blockSize):
    block_number = address // blockSize
    tag = block_number // sets
    return tag


def getByteOffset(address, block_size):
    num_bits = int(np.log2(block_size))
    mask = (1 << num_bits) - 1
    byteOffset = address & mask
    return byteOffset

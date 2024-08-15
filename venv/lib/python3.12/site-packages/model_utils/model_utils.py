import numpy as np
from cocotb.types import LogicArray
from cocotb.types.range import Range
import random

def unsigned(op: int, bits:int):
    """cast to 32 bits and set unsigned as needed"""
    if(op<0): return (2**bits + op) & 0xffff_ffff
    else: return op & 0xffff_ffff

def signed(op: int, bits:int):
    """cast to negative number if MSB is set"""
    is_negative = op & (1<<(bits-1))
    if(is_negative): return op - (1 << bits) - 1
    else: return op


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


def align(address, bytes):
    """Align address downwards to bytes"""
    return address & ~(bytes - 1)


def compare_cache_states(state0, state1):
    for way in range(len(state0)):
        for line in range(len(state0[way])):
            if state0[way][line] != state1[way][line]:
                return False
    return True


#####################
## INSTRUCTION GEN ##
#####################
## BASE TYPES ##
################
def validate(opcode=0, rs1=0, rs2=0, rd=0, funct3=0, funct7=0):
    rv32i_opcodes = [
        0b0010011,
        0b0000011,
        0b1100111,
        0b0010111,
        0b1100011,
        0b0110011,
        0b0001111,
        0b0011011,
        0b0110111,
        0b1101111,
        0b1110011,
    ]
    # assert opcode in rv32i_opcodes, "Invalid opcode"
    assert rs1 <= 0b11111, f"rs1 {rs1} exceeds max value"
    assert rs2 <= 0b11111, f"rs2 {rs2} exceeds max value"
    assert rd <= 0b11111, f"rd {rd} exceeds max value"
    assert funct3 <= 0b111, f"funct3 {funct3} exceeds max value"
    assert funct7 <= 0b1111111, f"funct7 {funct7} exceeds max value"


def generate_J_type(opcode, rd, imm):
    validate(opcode=opcode, rd=rd)
    assert imm < (((1 << 20) - 1) << 1), "imm exceeds max value"
    imm = imm & 0b111111111111
    imm_19_12 = (imm >> 12) & 0b1111
    imm_11 = (imm >> 11) & 1
    imm_10_1 = (imm >> 1) & 0b1111111111
    imm_20 = (imm >> 20) & 1
    opcode = format(0b1101111, "07b")

    imm_20 = format(imm_20, "01b")
    imm_19_12 = format(imm_19_12, "08b")
    imm_11 = format(imm_11, "01b")
    imm_10_1 = format(imm_10_1, "010b")
    rd = format(rd, "05b")

    instruction = imm_20 + imm_10_1 + imm_11 + imm_19_12 + rd + opcode
    return int(instruction, 2)


def generate_B_type(opcode, rs1, rs2, imm, funct3):
    validate(opcode=opcode, rs1=rs1, rs2=rs2, funct3=funct3)
    # assert imm < (1 << 13) and imm >= -(1 << 13), "imm exceeds max value"
    imm = imm & 0b1111111111111
    imm11 = (imm >> 12) & 1
    imm4_1 = (imm >> 1) & 0b1111
    imm10_5 = (imm >> 5) & 0b111111
    imm12 = (imm >> 11) & 1

    opcode = format(opcode, "07b")
    imm12 = format(imm12, "01b")
    imm11 = format(imm11, "01b")
    imm10_5 = format(imm10_5, "06b")
    imm4_1 = format(imm4_1, "04b")
    funct3 = format(funct3, "03b")
    rs1 = format(rs1, "05b")
    rs2 = format(rs2, "05b")

    instruction = imm12 + imm10_5 + rs2 + rs1 + funct3 + imm4_1 + imm11 + opcode
    return int(instruction, 2)


def generate_I_type(opcode, rs1, rd, imm):
    validate(opcode=opcode, rs1=rs1, rd=rd)
    assert imm < (1 << 12) and imm >= -(1 << 12), "imm exceeds max value"
    imm = imm & 0b111111111111

    opcode = format(opcode, "07b")
    rd = format(rd, "05b")
    funct3 = format(0b000, "03b")
    rs1 = format(rs1, "05b")
    imm = format(imm, "012b")

    instruction = imm + rs1 + funct3 + rd + opcode
    return int(instruction, 2)


def generate_U_type(opcode, rd, imm):
    validate(opcode=opcode, rd=rd)
    assert imm < (1 << 20) and imm >= 0, "imm exceeds max value"
    imm = imm & 0b11111111111111111111

    opcode = format(opcode, "07b")
    imm = format(imm, "020b")
    rd = format(rd, "05b")

    instruction = imm + rd + opcode
    return int(instruction, 2)


def generate_S_type(opcode, rs1, rs2, imm, funct3):
    validate(opcode=opcode, rs1=rs1, rs2=rs2, funct3=funct3)
    assert imm < (1 << 11) - 1, "imm exceeds max value"
    imm11_5 = (imm >> 5) & 0b111_1111
    imm4_0 = imm & 0b11111

    opcode = format(opcode, "07b")
    imm4_0 = format(imm4_0, "05b")
    funct3 = format(funct3, "03b")
    rs1 = format(rs1, "05b")
    rs2 = format(rs2, "05b")
    imm11_5 = format(imm11_5, "07b")

    instruction = imm11_5 + rs2 + rs1 + funct3 + imm4_0 + opcode
    return int(instruction, 2)


def generate_R_type(opcode, rs1, rs2, rd, funct3, funct7):
    validate(opcode=opcode, rs1=rs1, rs2=rs2, rd=rd, funct3=funct3, funct7=funct7)
    opcode = format(opcode, "07b")
    rs1 = format(rs1, "05b")
    rs2 = format(rs2, "05b")
    rd = format(rd, "05b")
    funct3 = format(funct3, "03b")
    funct7 = format(funct7, "07b")

    instruction = funct7 + rs2 + rs1 + funct3 + rd + opcode
    return int(instruction, 2)


# decode utils #

def sign_extend(value, from_size, to_size):
    MSB = (value & (1<<(from_size-1))) > 0
    
    if(MSB):
        negative_value = value - (2**from_size)
        sign_extended_value = (2**to_size) + negative_value
        return sign_extended_value
    else:
        return value


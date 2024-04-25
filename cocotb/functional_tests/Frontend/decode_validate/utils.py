def generateBR(rs1, rs2, imm):
    opcode = 0b1100011
    funct3 = 0b000  # Assuming BEQ (branch if equal) for simplicity
    imm11 = (imm >> 11) & 0b1
    imm10_5 = (imm >> 5) & 0b111111
    imm4_1 = (imm >> 1) & 0b1111
    imm12 = (imm >> 12) & 0b1
    imm_field = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1)
    instruction = (opcode) | (funct3 << 12) | (rs1 << 15) | (rs2 << 20) | (imm_field)
    return instruction

def generateJALR(rs1, rd):
    opcode = 0b1100111
    funct3 = 0b000
    imm = 0
    instruction = (opcode) | (rd << 7) | (funct3 << 12) | (rs1 << 15) | (imm << 20)
    return instruction

def generateJAL(rd, imm):
    opcode = 0b1101111
    imm20 = (imm >> 20) & 0b1  # Extract imm[20]
    imm10_1 = (imm >> 1) & 0b1111111111  # Extract imm[10:1]
    imm11 = (imm >> 11) & 0b1  # Extract imm[11]
    imm19_12 = (imm >> 12) & 0b11111111  # Extract imm[19:12]
    imm_field = (imm20 << 31) | (imm19_12 << 12) | (imm11 << 20) | (imm10_1)
    instruction = opcode | (rd << 7) | imm_field
    print(hex(instruction))
    print(imm)
    
    return instruction

def generateADD(rs1, rs2, rd):
    opcode = 0b0110011
    funct3 = 0b000  # ADD function code
    funct7 = 0b0000000  # Standard ADD function
    instruction = (opcode) | (rd << 7) | (funct3 << 12) | (rs1 << 15) | (rs2 << 20) | (funct7 << 25)
    return instruction

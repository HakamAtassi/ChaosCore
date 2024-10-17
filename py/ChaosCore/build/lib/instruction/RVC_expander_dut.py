import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
import math

def decBinary(arr, n, shift):
    if n == 0:
        return
    k = int(math.log2(n)) 
    while (n > 0):
        arr[k+shift] = n % 2
        k = k - 1
        n = n//2

def binaryDec(arr, n):
    ans = 0
    for i in range(0, n):
        ans = ans + (arr[i] << (n - i - 1))
    return ans

def concat(concat_list:list, bits_list:list): 
 
    bits_list_real = []
    for val in concat_list:
        if val == 0:
            bits = 0
        else:
            bits = int(math.log2(val)) + 1
        bits_list_real.append(bits)
 
    bin_list = [[0 for i in range(0, bits)] for bits in bits_list]
 
    final_size = 0
    for bits in bits_list:
        final_size += bits
    c = [0 for i in range(0, final_size)]

    for i in range(len(bin_list)):
        decBinary(bin_list[i], concat_list[i], bits_list[i] - bits_list_real[i]); 
 
    iin = 0
    for bit in range(len(concat_list)):
        for i in range(0, bits_list[bit]): 
            c[iin] = bin_list[bit][i]
            iin = iin + 1
 
    return (binaryDec(c, final_size))

def bit_slice(num:int, msb:int, lsb:int):
    mask = (0x1 << (msb-lsb+1)) - 1
    return (num >> lsb) & mask

class expander_model:
    def __init__(self, instruction:int):
        self.instruction = instruction
        x = instruction
        s = bit_slice
        self.lwsp_imm = concat([s(x,3,2), s(x,12,12), s(x,6,4), 0],[2,1,3,2])
        self.swsp_imm = concat([s(x,8,7), s(x,12,9), 0], [2,4,2])
        self.lsw_imm = concat([s(x,5,5), s(x,12,10), s(x,6,6), 0], [1,3,1,2])
        self.j_imm = concat([s(x,12,12), s(x,8,8), s(x,10,9), s(x,6,6), s(x,7,7), s(x,2,2), s(x,11,11), s(x,5,4), 0],[1,1,2,1,1,1,1,2,2])
        self.b_imm = concat([s(x,12,12), s(x,6,5), s(x,2,2), s(x,11,10), s(x,4,3), 0],[1,2,1,2,2,1])
        self.shamt = concat([s(x,12,12), s(x,6,2)],[1,5])
        self.lui_imm = concat([self.shamt, 0],[6, 12])
        self.addi16sp_imm = concat([s(x,12,12), s(x,4,3), s(x,5,5), s(x,2,2), s(x,6,6), 0],[1,2,1,1,1,4])
        self.addi4spn_imm = concat([s(x,10,7), s(x,12,11), s(x,5,5), s(x,6,6), 0],[4,2,1,1,2])
        # print(hex(self.lwsp_imm))
        # print(hex(self.swsp_imm))
        # print(hex(self.lsw_imm))
        # print(hex(self.j_imm))
        # print(hex(self.b_imm))
        # print(hex(self.shamt))
        # print(hex(self.lui_imm))
        # print(hex(self.addi16sp_imm))
        # print(hex(self.addi4spn_imm))


        self.FUNCT3 = s(x,15,13)
        self.FUNCT6 = s(x,15,10)
        self.RD = s(x,11,7)
        self.lower_imm = s(x,6,2)
        self.imm_5 = s(x,12,12)

        self.Q0 = s(x,1,0) == 0
        self.Q1 = s(x,1,0) == 1
        self.Q2 = s(x,1,0) == 2

    def expand(self):
        ADDI4SPN   = self.FUNCT3 == 0b000 and self.Q0 and bit_slice(self.instruction,12,5) != 0
        LW         = self.FUNCT3 == 0b010 and self.Q0
        SW         = self.FUNCT3 == 0b110 and self.Q0

        NOP        = self.FUNCT3 == 0b000 and self.Q1 and (self.RD == 0) and (concat([self.imm_5, self.lower_imm],[1,5]) != 0)
        ADDI       = self.FUNCT3 == 0b000 and self.Q1 and (self.RD != 0) and (concat([self.imm_5, self.lower_imm],[1,5]) != 0)
        JAL        = self.FUNCT3 == 0b001 and self.Q1
        LI         = self.FUNCT3 == 0b010 and self.Q1 and (self.RD != 0) 
        ADDI16SP   = self.FUNCT3 == 0b011 and self.Q1 and (self.RD == 2)
        LUI        = self.FUNCT3 == 0b011 and self.Q1 and (self.RD != 0) and (self.RD != 2) and (self.lower_imm != 0)

        SRLI       = self.FUNCT6 == 0b10000 and self.Q1 and (self.lower_imm != 0) and (self.imm_5 == 0) 
        SRAI       = self.FUNCT6 == 0b10001 and self.Q1 and (self.lower_imm != 0) and (self.imm_5 == 0) 
        ANDI       = self.FUNCT3 == 0b100 and bit_slice(self.instruction,11,10) == 0b10 and self.Q1
        SUB        = self.FUNCT6 == 0b10011 and self.Q1
        XOR        = self.FUNCT6 == 0b10001 and self.Q1
        OR         = self.FUNCT6 == 0b10001 and self.Q1
        AND        = self.FUNCT6 == 0b10001 and self.Q1

        J          = self.FUNCT3 == 0b101 and self.Q1

        BEQZ       = self.FUNCT3 == 0b110 and self.Q1
        BNEZ       = self.FUNCT3 == 0b111 and self.Q1

        SLLI       = self.FUNCT3 == 0b000 and self.Q2 and (self.imm_5 == 0) and (self.lower_imm != 0) and (self.RD != 0)
        JR         = self.FUNCT3 == 0b100 and self.Q2 and (self.imm_5 == 0) and (self.lower_imm == 0) and (self.RD != 0)
        MV         = self.FUNCT3 == 0b100 and self.Q2 and (self.RD != 0)
        EBREAK     = self.FUNCT3 == 0b100 and self.Q2 and (bit_slice(self.instruction,12,2) == 0b10000000000)
        JALR       = self.FUNCT3 == 0b100 and self.Q2 and (self.imm_5 == 1) and (self.lower_imm == 0) and (self.RD != 0)
        ADD        = self.FUNCT3 == 0b100 and self.Q2 and (self.imm_5 == 1) and (self.lower_imm != 0) and (self.RD != 0)

        LWSP       = self.FUNCT3 == 0b010 and self.Q2 and (self.RD != 0)
        SWSP       = self.FUNCT3 == 0b110 and self.Q2

        if (not (ADDI4SPN or LW or SW or NOP or ADDI or JAL or LI or ADDI16SP or LUI or SRLI or SRAI or ANDI or SUB or XOR or OR or AND or J or BEQZ or BNEZ or SLLI or JR or MV or EBREAK or JALR or ADD or LWSP or SWSP)):
            return 0

        CR  = JR or JALR or MV or ADD 
        CI  = LWSP or LI or LUI or ADDI or ADDI16SP or SLLI
        CSS = SWSP
        CIW = ADDI4SPN
        CL  = LW
        CS  = SW
        CA  = AND or OR or XOR or SUB
        CB  = BEQZ or BNEZ or SRLI or SRAI or ANDI
        CJ  = J or JAL 

        imm = 0
        if(LWSP):
            imm = self.lwsp_imm
        elif(SWSP):
            imm = self.swsp_imm
        elif(LW or SW):
            imm = self.lsw_imm
        elif(CJ):
            imm = self.j_imm
        elif(BNEZ or BEQZ):
            imm = self.b_imm
        elif(SRLI or SRAI or SLLI or ADDI or LI):
            imm = self.shamt
        elif(LUI):
            imm = self.lui_imm
        elif(ADDI16SP):
            imm = self.addi16sp_imm
        elif(ADDI4SPN):
            imm = self.addi4spn_imm

        funct3 = 0
        if(LW or LWSP or SW or SWSP): 
            funct3 = 0x2
        elif (BNEZ or SLLI): 
            funct3 = 0x1
        elif (XOR): 
            funct3 = 0x4
        elif (OR): 
            funct3 = 0x6
        elif (AND): 
            funct3 = 0x7
        elif (SRLI or SRAI): 
            funct3 = 0x5
        

        funct7 = 0
        if(SUB or SRAI):
            funct7 = 0x20

        if (CR or CI):
            rd_rs1 = bit_slice(self.instruction,11,7)
        else:
            rd_rs1 = concat([1, bit_slice(self.instruction,9,7)],[2,3])

        if (CR or CSS):
            rd_rs2 = bit_slice(self.instruction,6,2)
        else:
            rd_rs2 = concat([1, bit_slice(self.instruction,4,2)],[2,3])

        rd = 0
        rs1 = 0
        rs2 = 0
        if (CR or CI or CA or CB):
            rs1 = rd_rs1
            rd = rd_rs1
        elif(CL or CS):
            rs1 = rd_rs1
        
        if (CR or CSS or CS or CA):
            rs2 = rd_rs2
        elif(CIW or CL):
            rd = rd_rs2

        expanded_instruction = 0

        #Get opcode
        if(LW or LWSP):
            opcode = 0b0000011
        elif (SW or SWSP): 
            opcode = 0b0100011
            expanded_instruction = concat([bit_slice(imm,11,5), rs2, rs1, funct3, bit_slice(imm,4,0), opcode],[7,5,5,3,5,7])
        elif (JAL or J):
            opcode = 0b1101111
            expanded_instruction = concat([bit_slice(imm,20,20), bit_slice(imm,10,1), bit_slice(imm,11,11), bit_slice(imm,19,12), rd, opcode],[1,10,1,8,5,7])
        elif (JALR or JR):
            opcode = 0b1100111
        elif (BEQZ or BNEZ): 
            opcode = 0b1100011
            expanded_instruction = concat([bit_slice(imm,12,12), bit_slice(imm,10,5), rs2, rs1, funct3, bit_slice(imm,4,1), bit_slice(imm,11,11), opcode],[1,6,5,5,3,4,1,7])
        elif (LUI): 
            opcode = 0b0110111
            expanded_instruction = concat([bit_slice(imm,31,12), rd, opcode],[20,5,7])
        elif (EBREAK): 
            opcode = 0b1110011
        elif (SUB or XOR or OR or AND or ADD): 
            opcode = 0b0110011
            expanded_instruction = concat([funct7, rs2, rs1, funct3, rd, opcode],[7,5,5,3,5,7])
        elif (ADDI4SPN or NOP or ADDI or LI or ADDI16SP or SRLI or SRAI or ANDI or SLLI or MV): 
            opcode = 0b0010011

        if(LW or LWSP or ADDI4SPN or NOP or ADDI or LI or ADDI16SP or SRLI or SRAI or ANDI or SLLI or MV or EBREAK):
            expanded_instruction = concat([bit_slice(imm,11,0), rs1, funct3, rd, opcode],[12,5,3,5,7])

        #print("immediate: ", hex(imm))
        return expanded_instruction
        
                 

class RVC_expander_dut:
    def __init__(self, dut):
        self.RVC_expander = dut

    #################
    # CLOCK / RESET #
    #################

    async def clock(self):  # Do not touch
        await RisingEdge(self.RVC_expander.clock)

    async def reset(self):  # Do not touch
        await RisingEdge(self.RVC_expander.clock)
        self.RVC_expander.reset.value = 1
        await RisingEdge(self.RVC_expander.clock)
        self.RVC_expander.reset.value = 0

    def write_instruction(self, instruction:int):
        self.RVC_expander.io_compressed_instr_bits_instruction.value = instruction
        self.RVC_expander.io_compressed_instr_valid.value = 1
    
    def read_instruction(self):
        return self.RVC_expander.io_instruction_bits_instruction.value

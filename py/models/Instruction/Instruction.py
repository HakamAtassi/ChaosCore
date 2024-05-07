R_type_opcodes = [0b0110011, 0b0111011]
I_type_opcodes = [0b0010011, 0b0000011, 0b1100111, 0b0010111, 0b0001111, 0b0011011]
S_type_opcodes = [0b0100011]
B_type_opcodes = [0b1100011]
U_type_opcodes = [0b0110111, 0b0010111]
J_type_opcodes = [0b1101111]

class Instruction:
    def __init__(self, instruction, PC):
        self.instruction = instruction
        self.opcode      = self.get_opcode()
        self.rs1         = self.get_rs1()
        self.rs2         = self.get_rs2()
        self.rd          = self.get_rd()
        self.imm         = self.get_imm()
        self.funct3      = self.get_funct3()
        self.funct7      = self.get_funct7()
        self.valid       = 1
        self.PC          = PC

        # TODO: add instruction type...

    @staticmethod
    def null():
        return Instruction(0, 0)

    def get_opcode(self):
        return self.instruction & 0b1111111
    
    def get_rs1(self):
        return (self.instruction >> 15) & 0b11111

    def get_rs2(self):
        return (self.instruction >> 20) & 0b11111

    def get_rd(self):
        return (self.instruction >> 7) & 0b11111

    def get_funct3(self):
        return (self.instruction >> 12) & 0b111

    def get_funct7(self):
        return (self.instruction >> 25) & 0b1111111

    def get_imm(self):

        if self.opcode in R_type_opcodes:
            pass
        elif self.opcode in I_type_opcodes:
            self.imm    = (self.instruction >> 20)
            if self.imm & 0x800:
                self.imm |= 0xFFFFF000
        elif self.opcode in S_type_opcodes:
            imm11_5     = (self.instruction >> 25) & 0b1111111
            imm4_0      = (self.instruction >> 7) & 0b11111
            self.imm    = (imm11_5 << 5) | imm4_0
            if self.imm & 0x800:
                self.imm |= 0xFFFFF000
        elif self.opcode in B_type_opcodes:
            imm12       = (self.instruction >> 31) & 1
            imm10_5     = (self.instruction >> 25) & 0b111111
            imm4_1      = (self.instruction >> 8) & 0b1111
            imm11       = (self.instruction >> 7) & 1
            self.imm    = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1)
            if self.imm & 0x1000:
                self.imm |= 0xFFFFE000
        elif self.opcode in U_type_opcodes:
            self.imm    = (self.instruction >> 12)
        elif self.opcode in J_type_opcodes:
            imm19_12    = (self.instruction >> 12) & 0b11111111
            imm11       = (self.instruction >> 20) & 1
            imm10_1     = (self.instruction >> 21) & 0b1111111111
            imm20       = (self.instruction >> 31) & 1
            self.imm    = (imm20 << 20) | (imm19_12 << 12) | (imm11 << 11) | (imm10_1 << 1)
            if self.imm & 0x100000:
                self.imm |= 0xFFF00000
        return self.imm

from model_utils import *
from cocotb.types import LogicArray
from cocotb.types.range import Range


from enum import Enum

INSTR_DICT = {
    #R type base operations
    "add" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "sub" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x20,
        "opcode" : 0b0110011
    },
    "xor" : {
        "type" : "R",
        "funct3" : 0x4, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "or" : {
        "type" : "R",
        "funct3" : 0x6, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "and" : {
        "type" : "R",
        "funct3" : 0x7, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "sll" : {
        "type" : "R",
        "funct3" : 0x1, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "srl" : {
        "type" : "R",
        "funct3" : 0x5, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "sra" : {
        "type" : "R",
        "funct3" : 0x5, 
        "funct7": 0x20,
        "opcode" : 0b0110011
    },
    "slt" : {
        "type" : "R",
        "funct3" : 0x2, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    "sltu" : {
        "type" : "R",
        "funct3" : 0x3, 
        "funct7": 0x0,
        "opcode" : 0b0110011
    },
    #I type 
    "addi" : {
        "type" : "I",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "xori" : {
        "type" : "I",
        "funct3" : 0x4, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "ori" : {
        "type" : "I",
        "funct3" : 0x6, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "andi" : {
        "type" : "I",
        "funct3" : 0x7, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "slli" : {
        "type" : "I",
        "funct3" : 0x1, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "srli" : {
        "type" : "I",
        "funct3" : 0x5, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "srai" : {
        "type" : "I",
        "funct3" : 0x5, 
        "funct7": 0x20,
        "opcode" : 0b0010011
    },
    "slti" : {
        "type" : "I",
        "funct3" : 0x2, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    "sltiu" : {
        "type" : "I",
        "funct3" : 0x3, 
        "funct7": 0x0,
        "opcode" : 0b0010011
    },
    #I type Load
    "lb" : {
        "type" : "I",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b0000011
    },
    "lh" : {
        "type" : "I",
        "funct3" : 0x1, 
        "funct7": 0x0,
        "opcode" : 0b0000011
    },
    "lw" : {
        "type" : "I",
        "funct3" : 0x2, 
        "funct7": 0x0,
        "opcode" : 0b0000011
    },
    "lbu" : {
        "type" : "I",
        "funct3" : 0x4, 
        "funct7": 0x0,
        "opcode" : 0b0000011
    },
    "lhu" : {
        "type" : "I",
        "funct3" : 0x5, 
        "funct7": 0x0,
        "opcode" : 0b0000011
    },
    #S type
    "sb" : {
        "type" : "S",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b0100011
    },
    "sh" : {
        "type" : "S",
        "funct3" : 0x1, 
        "funct7": 0x0,
        "opcode" : 0b0100011
    },
    "sw" : {
        "type" : "S",
        "funct3" : 0x2, 
        "funct7": 0x0,
        "opcode" : 0b0100011
    },
    #Branch
    "beq" : {
        "type" : "B",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b1100011
    },
    "bne" : {
        "type" : "B",
        "funct3" : 0x1, 
        "funct7": 0x0,
        "opcode" : 0b1100011
    },
    "blt" : {
        "type" : "B",
        "funct3" : 0x4, 
        "funct7": 0x0,
        "opcode" : 0b1100011
    },
    "bge" : {
        "type" : "B",
        "funct3" : 0x5, 
        "funct7": 0x0,
        "opcode" : 0b1100011
    },
    "bltu" : {
        "type" : "B",
        "funct3" : 0x6, 
        "funct7": 0x0,
        "opcode" : 0b1100011
    },
    "bgeu" : {
        "type" : "B",
        "funct3" : 0x7, 
        "funct7": 0x0,
        "opcode" : 0b1100011
    },
    #JAL, JALR, LUI, AUIPC, ECALL, EBREAK
    "jal" : {
        "type" : "J",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b1101111
    },
    "jalr" : {
        "type" : "I",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b1100111
    },
    "lui" : {
        "type" : "U",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b0110111
    },
    "auipc" : {
        "type" : "U",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b0010111
    },
    "ecall" : {
        "type" : "I",
        "funct3" : 0x0, 
        "funct7": 0x0,
        "opcode" : 0b1110011
    },
    "ebreak" : {
        "type" : "I",
        "funct3" : 0x0, 
        "funct7": 0x1, #?
        "opcode" : 0b1110011
    },
    #MULTIPLY EXT
    "mul" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x1, 
        "opcode" : 0b0110011
    },
    "mulh" : {
        "type" : "R",
        "funct3" : 0x1, 
        "funct7": 0x1, 
        "opcode" : 0b0110011
    },
    "mulsu" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x2, 
        "opcode" : 0b0110011
    },
    "mulu" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x3, 
        "opcode" : 0b0110011
    },
    "div" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x4, 
        "opcode" : 0b0110011
    },
    "divu" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x5, 
        "opcode" : 0b0110011
    },
    "rem" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x6, 
        "opcode" : 0b0110011
    },
    "remu" : {
        "type" : "R",
        "funct3" : 0x0, 
        "funct7": 0x7, 
        "opcode" : 0b0110011
    },
}


class instruction_type(Enum):
    LOAD        = 0b00000
    LOAD_FP     = 0b00001
    CUSTOM_0    = 0b00010
    MISC_MEM    = 0b00011
    OP_IMM      = 0b00100
    AUIPC       = 0b00101
    OP_IMM_32   = 0b00110

    STORE       = 0b01000
    STORE_FP    = 0b01001
    CUSTOM_1    = 0b01010
    AMO         = 0b01011
    OP          = 0b01100
    LUI         = 0b01101
    OP_32       = 0b01110

    MADD        = 0b10000
    MSUB        = 0b10001
    NMSUB       = 0b10010
    NMADD       = 0b10011
    OP_FP       = 0b10100

    CUSTOM_2    = 0b10110

    BRANCH      = 0b11000
    JALR        = 0b11001

    JAL         = 0b11011
    SYSTEM      = 0b11100
        
    CUSTOM_3    = 0b11110

class instruction:
    def __init__(self, instruction):

        assert instruction <= 0xffffffff, "instruction larger than 32 bits"

        self.instruction = instruction

        self.opcode    = 0
        self.instruction_type = 0

        self.is_R_type = 0
        self.is_I_type = 0
        self.is_S_type = 0
        self.is_B_type = 0
        self.is_U_type = 0
        self.is_J_type = 0

        self.is_CALL    = 0
        self.is_RET     = 0
        self.is_JAL     = 0
        self.is_JALR    = 0
        self.is_BRANCH  = 0


        self.PRD                 =  0 
        self.RD_valid           =  0 
        self.RS1                =  0 
        self.RS1_valid          =  0 
        self.RS2                =  0 
        self.RS2_valid          =  0 
        self.IMM                =  0 
        self.FUNCT3             =  0 
        self.instruction_type   =  0 

        self.decode()

    def decode(self):

        self.opcode             = self.get_opcode()
        self.instruction_type   = self.get_instruction_type()

        self.is_R_type = self.get_is_R_type()
        self.is_I_type = self.get_is_I_type()
        self.is_S_type = self.get_is_S_type()
        self.is_B_type = self.get_is_B_type()
        self.is_U_type = self.get_is_U_type()
        self.is_J_type = self.get_is_J_type()

        self.is_CALL    = self.get_is_CALL()
        self.is_RET     = self.get_is_RET()
        self.is_JAL     = self.get_is_JAL()
        self.is_JALR    = self.get_is_JALR()
        self.is_BRANCH  = self.get_is_BRANCH()

        # CONSTRUCT
        self.PRD                 = self.get_RD()
        self.RD_valid           = self.get_RD_valid()
        self.RS1                = self.get_RS1()
        self.RS1_valid          = self.get_RS1_valid()
        self.RS2                = self.get_RS2()
        self.RS2_valid          = self.get_RS2_valid()
        self.IMM                = self.get_IMM()
        self.IS_IMM             = self.get_IS_IMM()
        self.FUNCT3             = self.get_FUNCT3()


    ############
    ## DECODE ##
    ############

    #----------------------
    # GET INSTRUCTION TYPES 
    #----------------------
    def get_opcode(self):
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        return instruction[6:0].integer

    def get_instruction_type(self):
        opcode_6_2  = LogicArray(self.opcode, Range(6, 'downto', 0))[6:2].integer
        return instruction_type(opcode_6_2)

    def get_is_R_type(self):
        is_R_type = (self.instruction_type == instruction_type.OP)
        return int(is_R_type)

    def get_is_I_type(self):
        instruction_type = self.instruction_type
        is_I_type =  self.instruction_type in [instruction_type.OP_IMM, instruction_type.LOAD, instruction_type.JALR, instruction_type.SYSTEM]
        return int(is_I_type)

    def get_is_S_type(self):
        instruction_type = self.instruction_type
        is_S_type = (self.instruction_type == instruction_type.STORE)
        return int(is_S_type)

    def get_is_B_type(self):
        instruction_type = self.instruction_type
        is_B_type = (self.instruction_type == instruction_type.BRANCH)
        return int(is_B_type)

    def get_is_J_type(self):
        instruction_type = self.instruction_type
        is_J_type = (self.instruction_type == instruction_type.JAL)
        return int(is_J_type)

    def get_is_U_type(self):
        instruction_type = self.instruction_type
        is_U_type = ((self.instruction_type == instruction_type.LUI) | (self.instruction_type == instruction_type.AUIPC))
        return int(is_U_type)

    #------------------------
    # GET INSTRUCTION FIELDS
    #------------------------


    def get_RD(self):
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        return instruction[11:7].integer

    def get_RD_valid(self):
        valid = self.is_R_type | self.is_I_type | self.is_U_type | self.is_J_type
        return int(valid)

    def get_RS1(self):
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        return instruction[19:15].integer

    def get_RS1_valid(self):
        valid = (self.is_R_type | self.is_I_type | self.is_S_type | self.is_B_type)
        return int(valid)

    def get_RS2(self):
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        return instruction[24:20].integer

    def get_RS2_valid(self):
        valid = self.is_R_type | self.is_S_type | self.is_B_type
        return int(valid)
    
    def get_IMM(self):
        
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        if(self.is_I_type):
            imm = instruction[31:20].integer
            return sign_extend(imm, from_size=12, to_size=21)
        elif(self.is_S_type):
            imm_11_5 = instruction[31:25].integer
            imm_4_0 = instruction[11:7].integer
            imm = (imm_11_5 << 5) | (imm_4_0 << 0)
            return sign_extend(imm, from_size=12, to_size=21)
        elif(self.is_B_type):
            imm_12 = instruction[31:31].integer
            imm_10_5 = instruction[30:25].integer
            imm_4_1 = instruction[11:8].integer
            imm_11 = instruction[7:7].integer
            imm = (imm_12 << 12) | (imm_11 << 11) | (imm_10_5 << 5) | (imm_4_1 << 1)
            return sign_extend(imm, from_size=13, to_size=21)
        elif(self.is_U_type):
            imm_31_12 = instruction[31:12].integer
            imm = (imm_31_12 << 0)
            return sign_extend(imm, from_size=20, to_size=21)
        elif(self.is_J_type):
            imm_20      = instruction[31:31].integer
            imm_10_1    = instruction[30:21].integer
            imm_11      = instruction[20:20].integer
            imm_19_12   = instruction[19:12].integer
            imm = (imm_20 << 20) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1)
            return sign_extend(imm, from_size=21, to_size=21)
        return 0


    def get_IS_IMM(self):
        valid = self.is_I_type | self.is_S_type | self.is_B_type | self.is_U_type | self.is_J_type
        return int(valid)

    def get_FUNCT3(self):
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        return instruction[14:12].integer

    def get_is_JAL(self):
        is_JAL = (self.instruction_type == instruction_type.JAL)
        return is_JAL

    def get_is_JALR(self):
        is_JALR = (self.instruction_type == instruction_type.JALR)
        return is_JALR

    def get_is_BRANCH(self):
        is_BRANCH = (self.instruction_type == instruction_type.BRANCH)
        return is_BRANCH

    def get_is_CALL(self):
        is_JALR = self.get_is_JALR()
        if(is_JALR and self.PRD == 1): 
            return True

    def get_is_RET(self):
        is_JALR = self.get_is_JALR()
        if(is_JALR and self.PRD == 0 and self.RS1 == 1 and self.get_IMM() == 0):
            return True

def encode_instruction(
                instruction_name:str, 
                rs1:int = None, 
                rs2:int = None, 
                PRD:int = None, 
                imm:int = None
                ):
    opcode = INSTR_DICT[instruction_name]["opcode"]
    type = INSTR_DICT[instruction_name]["type"]
    funct3 = INSTR_DICT[instruction_name]["funct3"]
    funct7 = INSTR_DICT[instruction_name]["funct7"]
    
    instruction = opcode
    if type == "R":
        if rs1 == None or rs2 == None or PRD == None: 
            raise ValueError("Missing arguments for R type")
        instruction |= (PRD & 0x1f) << 7
        instruction |= (funct3 & 0x7) << 12
        instruction |= (rs1 & 0x1f) << 15
        instruction |= (rs2 & 0x1f) << 20
        instruction |= (funct7 & 0x7f) << 25
    elif type == "I":
        if rs1 == None or imm == None or PRD == None: 
            raise ValueError("Missing arguments for I type")
        instruction |= (PRD & 0x1f) << 7
        instruction |= (funct3 & 0x7) << 12
        instruction |= (rs1 & 0x1f) << 15
        
        instruction |= (imm & 0xfff) << 20
    elif type == "S":
        if rs1 == None or rs2 == None or imm == None: 
            raise ValueError("Missing arguments for S type")
        instruction |= (funct3 & 0x7) << 12
        instruction |= (rs1 & 0x1f) << 15
        instruction |= (rs2 & 0x1f) << 20
        
        instruction |= (imm & 0x1f) << 7
        instruction |= (imm & 0xfe0) << 20
    elif type == "B":
        if rs1 == None or rs2 == None or imm == None: 
            raise ValueError("Missing arguments for B type")
        instruction |= (funct3 & 0x7) << 12
        instruction |= (rs1 & 0x1f) << 15
        instruction |= (rs2 & 0x1f) << 20
        
        instruction |= (imm & 0x800) >> 4
        instruction |= (imm & 0x1e) << 7
        instruction |= (imm & 0x7e0) << 20
        instruction |= (imm & 0x1000) << 19
    elif type == "U":
        if PRD == None or imm == None: 
            raise ValueError("Missing arguments for U type")
        instruction |= (PRD & 0x1f) << 7
        
        instruction |= (imm & 0xfffff000) 
    elif type == "J":
        if PRD == None or imm == None: 
            raise ValueError("Missing arguments for J type")
        instruction |= (PRD & 0x1f) << 7
        
        instruction |= (imm & 0xff000)
        instruction |= (imm & 0x800) << 9
        instruction |= (imm & 0x7fe) << 20
        instruction |= (imm & 0x100000) << 11
    
    return instruction


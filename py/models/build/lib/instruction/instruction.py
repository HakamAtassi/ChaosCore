from model_utils import *
from cocotb.types import LogicArray
from cocotb.types.range import Range


from enum import Enum

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


        self.RD                 =  0 
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
        self.RD                 = self.get_RD()
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
        is_I_type = ((self.instruction_type == instruction_type.OP_IMM) | (self.instruction_type == instruction_type.LOAD) | (self.instruction_type == instruction_type.SYSTEM))
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
        if(is_JALR and self.RD == 1): 
            return True

    def get_is_RET(self):
        is_JALR = self.get_is_JALR()
        if(is_JALR and self.RD == 0 and self.RS1 == 1 and self.get_IMM() == 0):
            return True



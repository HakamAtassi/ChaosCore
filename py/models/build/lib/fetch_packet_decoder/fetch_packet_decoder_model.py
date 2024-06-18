from model_utils import *
from cocotb.types import LogicArray
from cocotb.types.range import Range

from .opcodes import *


def sign_extend(value, from_size, to_size):
    MSB = (value & (1<<(from_size-1))) > 0
    
    if(MSB):
        negative_value = value - (2**from_size)
        sign_extended_value = (2**to_size) + negative_value
        return sign_extended_value
    else:
        return value



class decode_instruction:
    def __init__(self, instruction):

        self.instruction = instruction

        self.opcode    = 0

        self.is_R_type = 0
        self.is_I_type = 0
        self.is_S_type = 0
        self.is_B_type = 0
        self.is_U_type = 0
        self.is_J_type = 0

        self.RD                 =  0 
        self.RD_valid           =  0 
        self.RS1                =  0 
        self.RS1_valid          =  0 
        self.RS2                =  0 
        self.RS2_valid          =  0 
        self.IMM                =  0 
        self.FUNCT3             =  0 
        self.packet_index       =  0 
        self.ROB_index          =  0 
        self.instructionType    =  0 
        self.portID             =  0 
        self.RS_type            =  0 
        self.needs_ALU          =  0 
        self.needs_branch_unit  =  0 
        self.SUBTRACT           =  0 
        self.MULTIPLY           =  0 
        self.IMMEDIATE          =  0 
        self.IS_LOAD            =  0 
        self.IS_STORE           =  0 

        self.decode()

    def decode(self):

        self.opcode             = self.get_opcode()   # first, get opcode
        #self.instructionType    = self.get_instruction_type()   # first, get opcode

        self.is_R_type = self.get_is_R_type()           # then determine instruction type
        self.is_I_type = self.get_is_I_type()
        self.is_S_type = self.get_is_S_type()
        self.is_B_type = self.get_is_B_type()
        self.is_U_type = self.get_is_U_type()
        self.is_J_type = self.get_is_J_type()

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
        self.packet_index       = 0 #self.get_packet_index()  # TODO:
        self.ROB_index          = 0 #self.get_ROB_index()
        self.instructionType    = self.opcode.instructionType
        self.portID             = 0 #self.get_portID()
        self.RS_type            = 0 #self.get_RS_type()
        self.needs_ALU          = self.get_needs_ALU()
        self.needs_branch_unit  = self.get_needs_branch_unit()
        self.SUBTRACT           = 0 #self.get_SUBTRACT()
        self.MULTIPLY           = 0 #self.get_MULTIPLY()
        self.IS_LOAD            = self.get_IS_LOAD()
        self.IS_STORE           = self.get_IS_STORE()



    ############
    ## DECODE ##
    ############

    #----------------------
    # GET INSTRUCTION TYPES 
    #----------------------
    def get_opcode(self):
        instruction = LogicArray(self.instruction, Range(32, 'downto', 0))
        return opcode(instruction[6:0].integer)

    def get_is_R_type(self):
        instructionType = self.opcode.instructionType
        is_R_type = (instructionType == InstructionType.OP)
        return int(is_R_type)

    def get_is_I_type(self):
        instructionType = self.opcode.instructionType
        is_I_type = ((instructionType == InstructionType.OP_IMM) | (instructionType == InstructionType.LOAD) | (instructionType == InstructionType.SYSTEM))
        return int(is_I_type)

    def get_is_S_type(self):
        instructionType = self.opcode.instructionType
        is_S_type = (instructionType == InstructionType.STORE)
        return int(is_S_type)

    def get_is_B_type(self):
        instructionType = self.opcode.instructionType
        is_B_type = (instructionType == InstructionType.BRANCH)
        return int(is_B_type)

    def get_is_J_type(self):
        instructionType = self.opcode.instructionType
        is_J_type = (instructionType == InstructionType.JAL)
        return int(is_J_type)

    def get_is_U_type(self):
        instructionType = self.opcode.instructionType
        is_U_type = ((instructionType == InstructionType.LUI) | (instructionType == InstructionType.AUIPC))
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

    #----------
    # METADATA
    #----------

    def get_IS_LOAD(self):
        instructionType = self.opcode.instructionType
        return int(instructionType == InstructionType.LOAD)

    def get_IS_STORE(self):
        instructionType = self.opcode.instructionType
        return int(instructionType == InstructionType.STORE)

    def get_needs_ALU(self):
        instructionType = self.opcode.instructionType
        needs_ALU = ((instructionType == InstructionType.OP) | (instructionType == InstructionType.OP_IMM) | (instructionType == InstructionType.LUI) |  (instructionType == InstructionType.AUIPC))
        return int(needs_ALU)

    def get_needs_branch_unit(self):
        instructionType = self.instructionType
        needs_branch_unit = ((instructionType == InstructionType.BRANCH) | (instructionType == InstructionType.JAL) | (instructionType == InstructionType.JALR))
        return int(needs_branch_unit)


class fetch_packet_decoder_model:
    def __init__(self):
        pass

    def inputs(self, fetch_packet):
        self.input_fetch_packet = fetch_packet


    def get_decoded_fetch_packet(self):

        decoded_fetch_packet = {}

        decoded_fetch_packet["valid"] = int(self.input_fetch_packet["valid"])
        decoded_fetch_packet["fetch_PC"] =int(self.input_fetch_packet["fetch_PC"]) 

        decoded_fetch_packet["RD"] = [0]*4
        decoded_fetch_packet["RD_valid"] = [0]*4
        decoded_fetch_packet["RS1"] = [0]*4
        decoded_fetch_packet["RS1_valid"] = [0]*4
        decoded_fetch_packet["RS2"] = [0]*4
        decoded_fetch_packet["RS2_valid"] = [0]*4
        decoded_fetch_packet["IMM"] = [0]*4
        decoded_fetch_packet["IS_IMM"] = [0]*4
        decoded_fetch_packet["FUNCT3"] = [0]*4
        decoded_fetch_packet["packet_index"] = [0]*4
        decoded_fetch_packet["ROB_index"] = [0]*4
        decoded_fetch_packet["instructionType"] = [0]*4
        decoded_fetch_packet["portID"] = [0]*4
        decoded_fetch_packet["RS_type"] = [0]*4
        decoded_fetch_packet["needs_ALU"] = [0]*4
        decoded_fetch_packet["needs_branch_unit"] = [0]*4
        decoded_fetch_packet["SUBTRACT"] = [0]*4
        decoded_fetch_packet["MULTIPLY"] = [0]*4
        decoded_fetch_packet["IS_LOAD"] = [0]*4
        decoded_fetch_packet["IS_STORE"] = [0]*4
        decoded_fetch_packet["valid_bits"] = [0]*4



        for i in range(4):
            instruction = self.input_fetch_packet["instruction"][i]
            decoded_instruction = decode_instruction(instruction)
            instruction_valid = self.input_fetch_packet["valid"] &  self.input_fetch_packet["valid_bits"][i]

            decoded_fetch_packet["RD"][i]                  = decoded_instruction.RD
            decoded_fetch_packet["RD_valid"][i]            = decoded_instruction.RD_valid   & instruction_valid
            decoded_fetch_packet["RS1"][i]                 = decoded_instruction.RS1
            decoded_fetch_packet["RS1_valid"][i]           = decoded_instruction.RS1_valid & instruction_valid
            decoded_fetch_packet["RS2"][i]                 = decoded_instruction.RS2
            decoded_fetch_packet["RS2_valid"][i]           = decoded_instruction.RS2_valid & instruction_valid
            decoded_fetch_packet["IMM"][i]                 = decoded_instruction.IMM
            decoded_fetch_packet["IS_IMM"][i]              = decoded_instruction.IS_IMM
            decoded_fetch_packet["FUNCT3"][i]              = decoded_instruction.FUNCT3
            decoded_fetch_packet["packet_index"][i]        = decoded_instruction.packet_index
            decoded_fetch_packet["ROB_index"][i]           = decoded_instruction.ROB_index
            decoded_fetch_packet["instructionType"][i]     = decoded_instruction.instructionType
            decoded_fetch_packet["portID"][i]              = decoded_instruction.portID
            decoded_fetch_packet["RS_type"][i]             = decoded_instruction.RS_type
            decoded_fetch_packet["needs_ALU"][i]           = decoded_instruction.needs_ALU
            decoded_fetch_packet["needs_branch_unit"][i]   = decoded_instruction.needs_branch_unit
            decoded_fetch_packet["SUBTRACT"][i]            = decoded_instruction.SUBTRACT
            decoded_fetch_packet["MULTIPLY"][i]            = decoded_instruction.MULTIPLY
            decoded_fetch_packet["IS_LOAD"][i]             = decoded_instruction.IS_LOAD
            decoded_fetch_packet["IS_STORE"][i]            = decoded_instruction.IS_STORE
            decoded_fetch_packet["valid_bits"][i]          = instruction_valid

        return decoded_fetch_packet
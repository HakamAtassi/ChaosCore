from model_utils import *
from cocotb.types import LogicArray
from cocotb.types.range import Range
from instruction import *

# A model for a standalone decoder
class decode_instruction:
    def __init__(self, input_instruction):
        self.instruction = instruction(input_instruction)

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
        self.instruction_type   =  0 
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

        self.instruction_type    = self.instruction.instruction_type

        self.is_R_type = self.instruction.is_R_type
        self.is_I_type = self.instruction.is_I_type
        self.is_S_type = self.instruction.is_S_type
        self.is_B_type = self.instruction.is_B_type
        self.is_U_type = self.instruction.is_U_type
        self.is_J_type = self.instruction.is_J_type

        # CONSTRUCT
        self.RD                 = self.instruction.RD
        self.RD_valid           = self.instruction.RD_valid
        self.RS1                = self.instruction.RS1
        self.RS1_valid          = self.instruction.RS1_valid
        self.RS2                = self.instruction.RS2
        self.RS2_valid          = self.instruction.RS2_valid
        self.IMM                = self.instruction.IMM
        self.IS_IMM             = self.instruction.IS_IMM
        self.FUNCT3             = self.instruction.FUNCT3

        self.needs_ALU          = self.get_needs_ALU()
        self.needs_branch_unit  = self.get_needs_branch_unit()
        self.IS_LOAD            = self.get_IS_LOAD()
        self.IS_STORE           = self.get_IS_STORE()

        self.packet_index       = 0 #self.get_packet_index()  # TODO:
        self.ROB_index          = 0 #self.get_ROB_index()
        self.portID             = 0 #self.get_portID()
        self.RS_type            = 0 #self.get_RS_type()
        self.SUBTRACT           = 0 #self.get_SUBTRACT()
        self.MULTIPLY           = 0 #self.get_MULTIPLY()



    def get_IS_LOAD(self):
        instruction_type = self.instruction_type
        return int(instruction_type == instruction_type.LOAD)

    def get_IS_STORE(self):
        instruction_type = self.instruction_type
        return int(instruction_type == instruction_type.STORE)

    def get_needs_ALU(self):
        instruction_type = self.instruction_type
        needs_ALU = ((instruction_type == instruction_type.OP) | (instruction_type == instruction_type.OP_IMM) | (instruction_type == instruction_type.LUI) |  (instruction_type == instruction_type.AUIPC))
        return int(needs_ALU)

    def get_needs_branch_unit(self):
        instruction_type = self.instruction_type
        needs_branch_unit = ((instruction_type == instruction_type.BRANCH) | (instruction_type == instruction_type.JAL) | (instruction_type == instruction_type.JALR))
        return int(needs_branch_unit)


class fetch_packet_decoder_model:
    def __init__(self):
        self.decoded_fetch_packet_queue = []
        pass

    def inputs(self, fetch_packet, flush):
        self.input_fetch_packet = fetch_packet
        self.flush = flush

        self.update()

    def update(self):
        decoded_fetch_packet = {}

        decoded_fetch_packet["valid"] = 0
        decoded_fetch_packet["fetch_PC"] = 0 

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


        decoded_fetch_packet["valid"] = int(self.input_fetch_packet["valid"]) and not self.flush
        decoded_fetch_packet["fetch_PC"] =int(self.input_fetch_packet["fetch_PC"]) 


        for i in range(4):
            instruction = self.input_fetch_packet["instruction"][i]
            decoded_instruction = decode_instruction(instruction)
            instruction_valid = self.input_fetch_packet["valid"] &  self.input_fetch_packet["valid_bits"][i]

            decoded_fetch_packet["RD"][i]                  = decoded_instruction.RD
            decoded_fetch_packet["RD_valid"][i]            = decoded_instruction.RD_valid & instruction_valid
            decoded_fetch_packet["RS1"][i]                 = decoded_instruction.RS1
            decoded_fetch_packet["RS1_valid"][i]           = decoded_instruction.RS1_valid & instruction_valid
            decoded_fetch_packet["RS2"][i]                 = decoded_instruction.RS2
            decoded_fetch_packet["RS2_valid"][i]           = decoded_instruction.RS2_valid & instruction_valid
            decoded_fetch_packet["IMM"][i]                 = decoded_instruction.IMM
            decoded_fetch_packet["IS_IMM"][i]              = decoded_instruction.IS_IMM
            decoded_fetch_packet["FUNCT3"][i]              = decoded_instruction.FUNCT3
            decoded_fetch_packet["packet_index"][i]        = decoded_instruction.packet_index
            decoded_fetch_packet["ROB_index"][i]           = decoded_instruction.ROB_index
            decoded_fetch_packet["instructionType"][i]     = decoded_instruction.instruction_type
            decoded_fetch_packet["portID"][i]              = decoded_instruction.portID
            decoded_fetch_packet["RS_type"][i]             = decoded_instruction.RS_type
            decoded_fetch_packet["needs_ALU"][i]           = decoded_instruction.needs_ALU
            decoded_fetch_packet["needs_branch_unit"][i]   = decoded_instruction.needs_branch_unit
            decoded_fetch_packet["SUBTRACT"][i]            = decoded_instruction.SUBTRACT
            decoded_fetch_packet["MULTIPLY"][i]            = decoded_instruction.MULTIPLY
            decoded_fetch_packet["IS_LOAD"][i]             = decoded_instruction.IS_LOAD
            decoded_fetch_packet["IS_STORE"][i]            = decoded_instruction.IS_STORE
            decoded_fetch_packet["valid_bits"][i]          = instruction_valid


        self.decoded_fetch_packet_queue.append(decoded_fetch_packet)
        return 


    def get_decoded_fetch_packet(self):
        return self.decoded_fetch_packet_queue.pop(0)
from tabulate import tabulate
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from model_utils import signed, unsigned
from instruction import instruction_type

from cocotb.types import LogicArray
from cocotb.types.range import Range


class FU_model:
    def __init__(self):
        self.FU_output_queue = []



    def get_valid(self):
        valid = self.valid 
        return valid

    def get_RD(self):
        RD = self.RD
        return RD

    def get_PC(self):
        return self.PC
    
    def get_operation(self):
        instruction_type    = self.instruction_type
        FUNCT3              = self.FUNCT3
        SUBTRACT            = self.SUBTRACT
        operation = "NONE"
        
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x0 and not SUBTRACT): operation = "ADD"   # OP type
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x0 and     SUBTRACT): operation = "SUB"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x4 and not SUBTRACT): operation = "XOR"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x6 and not SUBTRACT): operation = "OR"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x7 and not SUBTRACT): operation = "AND"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x1 and not SUBTRACT): operation = "SLL"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x5 and not SUBTRACT): operation = "SRL"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x5 and     SUBTRACT): operation = "SRA"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x2 and not SUBTRACT): operation = "SLT"
        if(instruction_type == instruction_type.OP and FUNCT3 == 0x3 and not SUBTRACT): operation = "SLTU"

        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x0): operation = "ADDI"   # OP_IMM
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x4): operation = "XORI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x6): operation = "ORI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x7): operation = "ANDI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x1): operation = "SLLI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x5): operation = "SRLI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x5): operation = "SRAI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x2): operation = "SLTI"
        if(instruction_type == instruction_type.OP_IMM and FUNCT3 == 0x3): operation = "SLTIU"

        if(instruction_type == instruction_type.BRANCH and FUNCT3 == 0x0): operation = "BEQ"    # BRANCH
        if(instruction_type == instruction_type.BRANCH and FUNCT3 == 0x1): operation = "BNE"
        if(instruction_type == instruction_type.BRANCH and FUNCT3 == 0x4): operation = "BLT"
        if(instruction_type == instruction_type.BRANCH and FUNCT3 == 0x5): operation = "BGE"
        if(instruction_type == instruction_type.BRANCH and FUNCT3 == 0x6): operation = "BLTU"
        if(instruction_type == instruction_type.BRANCH and FUNCT3 == 0x7): operation = "BGEU"

        if(instruction_type == instruction_type.JAL):                     operation = "JAL"    # JAL
        if(instruction_type == instruction_type.JALR and FUNCT3 == 0x0):  operation = "JALR"   # JALR

        if(instruction_type == instruction_type.LUI):   operation = "LUI"    # LUI
        if(instruction_type == instruction_type.AUIPC): operation = "AUIPC"  # AUIPC

        return operation


    def get_RD_data(self):
        RS1 = self.RS1_data
        RS2 = self.RS2_data
        IMM = self.IMM
        PC  = self.PC
        packet_index = self.packet_index

        RD_data  = 0
        
        operation = self.get_operation()

        # OP
        # Sign irrelevant operations
        if(operation == "ADD"):     RD_data = unsigned(RS1, 32) +  unsigned(RS2, 32)
        if(operation == "SUB"):     RD_data = unsigned(RS1, 32) -  unsigned(RS2, 32)
        if(operation == "XOR"):     RD_data = unsigned(RS1, 32) ^  unsigned(RS2, 32)
        if(operation == "OR"):      RD_data = unsigned(RS1, 32) |  unsigned(RS2, 32)
        if(operation == "AND"):     RD_data = unsigned(RS1, 32) &  unsigned(RS2, 32)
        if(operation == "SLL"):     RD_data = unsigned(RS1, 32) << unsigned(RS2, 32)
        if(operation == "SRL"):     RD_data = unsigned(RS1, 32) >> unsigned(RS2, 32)
        if(operation == "SLTU"):    RD_data = unsigned(RS1, 32) <  unsigned(RS2, 32)
        if(operation == "SRA"):     RD_data = signed(RS1, 32) >>   signed(RS2, 32)
        if(operation == "SLT"):     RD_data = signed(RS1, 32) <    signed(RS2, 32)

        # OP_IMM
        if(operation == "ADDI"):     RD_data = unsigned(RS1, 32) +  unsigned(IMM, 20)
        if(operation == "XORI"):     RD_data = unsigned(RS1, 32) ^  unsigned(IMM, 20)
        if(operation == "ORI"):      RD_data = unsigned(RS1, 32) |  unsigned(IMM, 20)
        if(operation == "ANDI"):     RD_data = unsigned(RS1, 32) &  unsigned(IMM, 20)
        if(operation == "SLLI"):     RD_data = unsigned(RS1, 32) << (unsigned(IMM, 20) & 0x1F)
        if(operation == "SRLI"):     RD_data = unsigned(RS1, 32) >> (unsigned(IMM, 20) & 0x1F)
        if(operation == "SRAI"):     RD_data = signed(RS1, 32) >>   (unsigned(IMM, 20) & 0x1F)
        if(operation == "SLTI"):     RD_data = signed(RS1, 32) <    signed(RS2, 32)
        if(operation == "SLTIU"):    RD_data = unsigned(RS1, 32) <  unsigned(IMM, 20)


        #JAL
        if(operation == "JAL"):     RD_data = PC + packet_index*4 + 4

        #JALR
        if(operation == "JALR"):    RD_data = PC + packet_index*4 + 4

        #LUI
        if(operation == "LUI"):     RD_data = IMM << 12

        #AUIPC
        if(operation == "AUIPC"):   RD_data = PC + packet_index*4 + (IMM << 12)
        
        RD_data = unsigned(RD_data, 32)

        assert RD_data >= 0, "RD data still in python (negative format). Must cast to UInt(32.W)"

        return unsigned(RD_data, 32)

    def get_RD_valid(self):
        RD_valid = 0

        
        # OP type
        if(self.instruction_type == instruction_type.OP): RD_valid = 1
        # OP_IMM type
        if(self.instruction_type == instruction_type.OP_IMM): RD_valid = 1
        # JAL
        if(self.instruction_type == instruction_type.JAL): RD_valid = 1
        # JALR
        if(self.instruction_type == instruction_type.JALR): RD_valid = 1
        # LUI
        if(self.instruction_type == instruction_type.LUI): RD_valid = 1
        # AUIPC
        if(self.instruction_type == instruction_type.AUIPC): RD_valid = 1
        # LOAD
        if(self.instruction_type == instruction_type.LOAD): RD_valid = 1


        return RD_valid

    def get_branch_taken(self):
        operation = self.get_operation()

        RS1 = self.RS1_data
        RS2 = self.RS2_data

        taken = 0

        # OP
        # Sign irrelevant operations
        if(operation == "BEQ"):     taken = signed(RS1, 32)   == signed(RS2, 32)
        if(operation == "BNE"):     taken = signed(RS1, 32)   != signed(RS2, 32)
        if(operation == "BLT"):     taken = signed(RS1, 32)   <  signed(RS2, 32)
        if(operation == "BGE"):     taken = signed(RS1, 32)   >= signed(RS2, 32)
        if(operation == "BLTU"):    taken = unsigned(RS1, 32) <  unsigned(RS2, 32)
        if(operation == "BGEU"):    taken = unsigned(RS1, 32) >= unsigned(RS2, 32)
        if(operation == "JAL"):     taken = 1
        if(operation == "JALR"):    taken = 1

        return taken

    def get_target_address(self):
        fetch_PC = 0

        fetch_packet_index = self.packet_index

        IMM = signed(self.IMM, 12)

        branch_taken = self.get_branch_taken()

        PC = self.PC + (fetch_packet_index*4)

        if(branch_taken): target_address = PC + IMM
        else: target_address = self.PC + 16

        return unsigned(target_address, 32)

    def get_branch_valid(self):
        operation = self.get_operation()
        branch_valid = 0
        # OP
        # Sign irrelevant operations
        if(operation == "BEQ"): branch_valid = 1
        if(operation == "BNE"): branch_valid = 1
        if(operation == "BLT"): branch_valid = 1
        if(operation == "BGE"): branch_valid = 1
        if(operation == "BLTU"):branch_valid = 1
        if(operation == "BGEU"):branch_valid = 1
        if(operation == "JAL"): branch_valid = 1
        if(operation == "JALR"):branch_valid = 1

        return branch_valid

    def get_ROB_index(self):
        return self.ROB_index

    def get_packet_index(self):
        return self.packet_index

    def inputs(self, FU_inputs, flush):
        self.FU_inputs = FU_inputs
        self.flush = flush

        self.update()

    def update(self):
        outputs = {}

        self.valid                  = int(self.FU_inputs["valid"]             )
        self.RS1_ready              = int(self.FU_inputs["RS1_ready"]         )
        self.RS2_ready              = int(self.FU_inputs["RS2_ready"]         )
        self.RD                     = int(self.FU_inputs["RD"]                )
        self.RD_valid               = int(self.FU_inputs["RD_valid"]          )
        self.RS1                    = int(self.FU_inputs["RS1"]               )
        self.RS1_valid              = int(self.FU_inputs["RS1_valid"]         )
        self.RS2                    = int(self.FU_inputs["RS2"]               )
        self.RS2_valid              = int(self.FU_inputs["RS2_valid"]         )
        self.IMM                    = int(self.FU_inputs["IMM"]               )
        self.FUNCT3                 = int(self.FU_inputs["FUNCT3"]            )
        self.packet_index           = int(self.FU_inputs["packet_index"]      )
        self.ROB_index              = int(self.FU_inputs["ROB_index"]         )
        #self.instruction_type       = int(self.FU_inputs["instructionType"]   )
        self.instruction_type       = instruction_type(self.FU_inputs["instructionType"])
        self.portID                 = int(self.FU_inputs["portID"]            )
        self.RS_type                = int(self.FU_inputs["RS_type"]           )
        self.needs_ALU              = int(self.FU_inputs["needs_ALU"]         )
        self.needs_branch_unit      = int(self.FU_inputs["needs_branch_unit"] )
        self.needs_CSRs             = int(self.FU_inputs["needs_CSRs"]        )
        self.SUBTRACT               = int(self.FU_inputs["SUBTRACT"]          )
        self.MULTIPLY               = int(self.FU_inputs["MULTIPLY"]          )
        self.IMMEDIATE              = int(self.FU_inputs["IMMEDIATE"]         )
        self.is_load                = int(self.FU_inputs["is_load"]           )
        self.is_store               = int(self.FU_inputs["is_store"]          )
        self.RS1_data               = int(self.FU_inputs["RS1_data"]          )
        self.RS2_data               = int(self.FU_inputs["RS2_data"]          )
        self.PC                     = int(self.FU_inputs["fetch_PC"]    )


        outputs["valid"]            = self.get_valid() & (~self.flush)

        outputs["RD"]               = self.get_RD()
        outputs["RD_data"]          = self.get_RD_data()
        outputs["RD_valid"]         = self.get_RD_valid()

        outputs["fetch_PC"]         = self.get_PC()
        outputs["branch_taken"]     = self.get_branch_taken()
        outputs["target_address"]   = self.get_target_address()
        outputs["branch_valid"]     = self.get_branch_valid()
        outputs["ROB_index"]        = self.get_ROB_index()
        outputs["packet_index"]     = self.get_packet_index()

        self.FU_output_queue.append(outputs)

    def get_FU_output(self):
        return self.FU_output_queue.pop(0)
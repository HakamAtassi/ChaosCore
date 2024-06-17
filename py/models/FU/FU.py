from tabulate import tabulate
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

from cocotb.types import LogicArray
from cocotb.types.range import Range

def unsigned(op: int, bits:int):
    """cast to 32 bits and set unsigned as needed"""
    if(op<0): return (2**bits + op) & 0xffff_ffff
    else: return op & 0xffff_ffff

def signed(op: int, bits:int):
    """cast to negative number if MSB is set"""
    is_negative = op & 0x8000_0000
    if(is_negative): return -(2**bits - op) 
    else: return op


def generate_null_FU_inputs():
    FU_inputs = {}

    FU_inputs["valid"]              = 0
    FU_inputs["RS1_ready"]          = 0
    FU_inputs["RS2_ready"]          = 0
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0
    FU_inputs["RS1_valid"]          = 0
    FU_inputs["RS2"]                = 0
    FU_inputs["RS2_valid"]          = 0
    FU_inputs["IMM"]                = 0
    FU_inputs["FUNCT3"]             = 0
    FU_inputs["packet_index"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["instructionType"]    = 0
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 0
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["IS_LOAD"]            = 0
    FU_inputs["IS_STORE"]           = 0
    FU_inputs["RS1_data"]           = 0
    FU_inputs["RS2_data"]           = 0
    FU_inputs["PC"]                 = 0

    return FU_inputs


class FU_model:
    def __init__(self):
        pass

    def write_FU_input(self, FU_inputs=generate_null_FU_inputs()):
        self.valid                  = int(FU_inputs["valid"]             )
        self.RS1_ready              = int(FU_inputs["RS1_ready"]         )
        self.RS2_ready              = int(FU_inputs["RS2_ready"]         )
        self.RD                     = int(FU_inputs["RD"]                )
        self.RD_valid               = int(FU_inputs["RD_valid"]          )
        self.RS1                    = int(FU_inputs["RS1"]               )
        self.RS1_valid              = int(FU_inputs["RS1_valid"]         )
        self.RS2                    = int(FU_inputs["RS2"]               )
        self.RS2_valid              = int(FU_inputs["RS2_valid"]         )
        self.IMM                    = int(FU_inputs["IMM"]               )
        self.FUNCT3                 = int(FU_inputs["FUNCT3"]            )
        self.packet_index           = int(FU_inputs["packet_index"]      )
        self.ROB_index              = int(FU_inputs["ROB_index"]         )
        self.instruction_type       = int(FU_inputs["instructionType"]   )
        self.portID                 = int(FU_inputs["portID"]            )
        self.RS_type                = int(FU_inputs["RS_type"]           )
        self.needs_ALU              = int(FU_inputs["needs_ALU"]         )
        self.needs_branch_unit      = int(FU_inputs["needs_branch_unit"] )
        self.needs_CSRs             = int(FU_inputs["needs_CSRs"]        )
        self.SUBTRACT               = int(FU_inputs["SUBTRACT"]          )
        self.MULTIPLY               = int(FU_inputs["MULTIPLY"]          )
        self.IMMEDIATE              = int(FU_inputs["IMMEDIATE"]         )
        self.IS_LOAD                = int(FU_inputs["IS_LOAD"]           )
        self.IS_STORE               = int(FU_inputs["IS_STORE"]          )
        self.RS1_data               = int(FU_inputs["RS1_data"]          )
        self.RS2_data               = int(FU_inputs["RS2_data"]          )
        self.PC                     = int(FU_inputs["PC"]    )

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
        
        if(instruction_type == 0b01100 and FUNCT3 == 0x0 and not SUBTRACT): operation = "ADD"   # OP type
        if(instruction_type == 0b01100 and FUNCT3 == 0x0 and     SUBTRACT): operation = "SUB"
        if(instruction_type == 0b01100 and FUNCT3 == 0x4 and not SUBTRACT): operation = "XOR"
        if(instruction_type == 0b01100 and FUNCT3 == 0x6 and not SUBTRACT): operation = "OR"
        if(instruction_type == 0b01100 and FUNCT3 == 0x7 and not SUBTRACT): operation = "AND"
        if(instruction_type == 0b01100 and FUNCT3 == 0x1 and not SUBTRACT): operation = "SLL"
        if(instruction_type == 0b01100 and FUNCT3 == 0x5 and not SUBTRACT): operation = "SRL"
        if(instruction_type == 0b01100 and FUNCT3 == 0x5 and     SUBTRACT): operation = "SRA"
        if(instruction_type == 0b01100 and FUNCT3 == 0x2 and not SUBTRACT): operation = "SLT"
        if(instruction_type == 0b01100 and FUNCT3 == 0x3 and not SUBTRACT): operation = "SLTU"

        if(instruction_type == 0b00100 and FUNCT3 == 0x0): operation = "ADDI"   # OP_IMM
        if(instruction_type == 0b00100 and FUNCT3 == 0x4): operation = "XORI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x6): operation = "ORI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x7): operation = "ANDI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x1): operation = "SLLI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x5): operation = "SRLI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x5): operation = "SRAI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x2): operation = "SLTI"
        if(instruction_type == 0b00100 and FUNCT3 == 0x3): operation = "SLTIU"

        if(instruction_type == 0b11000 and FUNCT3 == 0x0): operation = "BEQ"    # BRANCH
        if(instruction_type == 0b11000 and FUNCT3 == 0x1): operation = "BNE"
        if(instruction_type == 0b11000 and FUNCT3 == 0x4): operation = "BLT"
        if(instruction_type == 0b11000 and FUNCT3 == 0x5): operation = "BGE"
        if(instruction_type == 0b11000 and FUNCT3 == 0x6): operation = "BLTU"
        if(instruction_type == 0b11000 and FUNCT3 == 0x7): operation = "BGEU"

        if(instruction_type == 0b11011):                    operation = "JAL"    # JAL
        if(instruction_type == 0b11001 and FUNCT3 == 0x0):  operation = "JALR"   # JALR

        if(instruction_type == 0b01101): operation = "LUI"    # LUI
        if(instruction_type == 0b00101): operation = "AUIPC"  # AUIPC

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

        instruction_type    = self.instruction_type
        
        # OP type
        if(instruction_type == 0b01100): RD_valid = 1
        # OP_IMM type
        if(instruction_type == 0b00100): RD_valid = 1
        #JAL
        if(instruction_type == 0b11011): RD_valid = 1
        #JALR
        if(instruction_type == 0b11001): RD_valid = 1
        #LUI
        if(instruction_type == 0b01101): RD_valid = 1
        #AUIPC
        if(instruction_type == 0b00101): RD_valid = 1

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

    def read_FU_output(self):
        outputs = {}
        outputs["valid"]            = self.get_valid()

        outputs["RD"]               = self.get_RD()
        outputs["RD_data"]          = self.get_RD_data()
        outputs["RD_valid"]         = self.get_RD_valid()

        outputs["PC"]               = self.get_PC()
        outputs["branch_taken"]     = self.get_branch_taken()
        outputs["target_address"]   = self.get_target_address()
        outputs["branch_valid"]     = self.get_branch_valid()
        outputs["ROB_index"]        = self.get_ROB_index()
        outputs["packet_index"]     = self.get_packet_index()
        return outputs 




####################
## FU DUT WRAPPER ##
####################


# Add helper functions as needed

class FU_dut:
    def __init__(self, dut):    # modify as needed (parameters, etc...)
        self.dut = dut

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0

    # complete class body...

    def write_FU_input(self, FU_inputs=generate_null_FU_inputs()):

        getattr(self.dut, f"io_FU_input_valid").value                                           = FU_inputs["valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready").value   = FU_inputs["RS1_ready"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready").value   = FU_inputs["RS2_ready"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD").value                     = FU_inputs["RD"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD_valid").value               = FU_inputs["RD_valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1").value                    = FU_inputs["RS1"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1_valid").value              = FU_inputs["RS1_valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2").value                    = FU_inputs["RS2"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2_valid").value              = FU_inputs["RS2_valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMM").value                    = FU_inputs["IMM"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_FUNCT3").value                 = FU_inputs["FUNCT3"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_packet_index").value           = FU_inputs["packet_index"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ROB_index").value              = FU_inputs["ROB_index"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_instructionType").value        = FU_inputs["instructionType"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_portID").value                 = FU_inputs["portID"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS_type").value                = FU_inputs["RS_type"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_ALU").value              = FU_inputs["needs_ALU"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_branch_unit").value      = FU_inputs["needs_branch_unit"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_CSRs").value             = FU_inputs["needs_CSRs"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_SUBTRACT").value               = FU_inputs["SUBTRACT"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_MULTIPLY").value               = FU_inputs["MULTIPLY"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMMEDIATE").value              = FU_inputs["IMMEDIATE"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_LOAD").value                = FU_inputs["IS_LOAD"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_STORE").value               = FU_inputs["IS_STORE"]
        getattr(self.dut, f"io_FU_input_bits_RS1_data").value                                   = FU_inputs["RS1_data"]
        getattr(self.dut, f"io_FU_input_bits_RS2_data").value                                   = FU_inputs["RS2_data"]
        getattr(self.dut, f"io_FU_input_bits_PC").value                                         = FU_inputs["PC"]

    def read_FU_input(self):
        FU_inputs = {}
        FU_inputs["ready"]              = int(getattr(self.dut, f"io_FU_input_ready").value)
        FU_inputs["valid"]              = int(getattr(self.dut, f"io_FU_input_valid").value                                          )
        FU_inputs["RS1_ready"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready").value)
        FU_inputs["RS2_ready"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready").value   )
        FU_inputs["RD"]                 = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD").value                     )
        FU_inputs["RD_valid"]           = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD_valid").value               )
        FU_inputs["RS1"]                = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1").value                    )
        FU_inputs["RS1_valid"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1_valid").value              )
        FU_inputs["RS2"]                = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2").value                    )
        FU_inputs["RS2_valid"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2_valid").value              )
        FU_inputs["IMM"]                = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMM").value                    )
        FU_inputs["FUNCT3"]             = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_FUNCT3").value                 )
        FU_inputs["packet_index"]       = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_packet_index").value           )
        FU_inputs["ROB_index"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ROB_index").value              )
        FU_inputs["instructionType"]    = getattr(self.dut, f"io_FU_input_bits_decoded_instruction_instructionType").value        
        FU_inputs["portID"]             = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_portID").value                 )
        FU_inputs["RS_type"]            = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS_type").value                )
        FU_inputs["needs_ALU"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_ALU").value              )
        FU_inputs["needs_branch_unit"]  = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_branch_unit").value      )
        FU_inputs["needs_CSRs"]         = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_CSRs").value             )
        FU_inputs["SUBTRACT"]           = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_SUBTRACT").value               )
        FU_inputs["MULTIPLY"]           = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_MULTIPLY").value               )
        FU_inputs["IMMEDIATE"]          = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMMEDIATE").value              )
        FU_inputs["IS_LOAD"]            = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_LOAD").value                )
        FU_inputs["IS_STORE"]           = int(getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_STORE").value               )
        FU_inputs["RS1_data"]           = int(getattr(self.dut, f"io_FU_input_bits_RS1_data").value                                   )
        FU_inputs["RS2_data"]           = int(getattr(self.dut, f"io_FU_input_bits_RS2_data").value                                   )
        FU_inputs["PC"]                 = int(getattr(self.dut, f"io_FU_input_bits_PC").value                                         )

        return FU_inputs

    def read_FU_output(self):
        outputs = {}
        outputs["valid"]            = int(getattr(self.dut, f"io_FU_output_valid").value)
        outputs["RD"]               = int(getattr(self.dut, f"io_FU_output_bits_RD").value)
        outputs["RD_data"]          = int(getattr(self.dut, f"io_FU_output_bits_RD_data").value)
        outputs["RD_valid"]         = int(getattr(self.dut, f"io_FU_output_bits_RD_valid").value)
        outputs["PC"]               = int(getattr(self.dut, f"io_FU_output_bits_instruction_PC").value)
        outputs["branch_taken"]     = int(getattr(self.dut, f"io_FU_output_bits_branch_taken").value)
        outputs["target_address"]   = int(getattr(self.dut, f"io_FU_output_bits_target_address").value)
        outputs["branch_valid"]     = int(getattr(self.dut, f"io_FU_output_bits_branch_valid").value)
        outputs["ROB_index"]        = int(getattr(self.dut, f"io_FU_output_bits_ROB_index").value)
        outputs["packet_index"]     = int(getattr(self.dut, f"io_FU_output_bits_fetch_packet_index").value)
        return outputs 

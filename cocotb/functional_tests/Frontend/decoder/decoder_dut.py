import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly

OP = 0b0110011
IMM_OP = 0b0010011
LOAD = 0b11
STORE = 0b0100011
BRANCH = 0b1100011
JAL = 0b1101111
JALR = 0b1100111
LUI = 0b0110111
AUIPC = 0b0010111
ENV = 0b1110011

HAS_RD = [OP, IMM_OP, LOAD, JAL, JALR, LUI, AUIPC, ENV]
ALU_OPS = [OP, IMM_OP]
BRANCH_OPS = [BRANCH, JAL, JALR]
HAS_RS1 = [OP, IMM_OP, LOAD, STORE, BRANCH, JALR]
HAS_RS2 = [OP, BRANCH, STORE]
INT = [OP, IMM_OP, BRANCH, JAL, JALR]
MEM = [LOAD, STORE]
HAS_IMM = [IMM_OP, LOAD, STORE, BRANCH, LUI, AUIPC, JAL, JALR]
ALL_OPS = [IMM_OP, LOAD, STORE, BRANCH, LUI, AUIPC, JAL, JALR, ENV, OP]
        
class decoder_sw:
    
    def __init__(self, 
                 instruction_valid:int, 
                 instruction:int, 
                 packet_index:int, 
                 ROB_index:int, 
                 decoded_instruction_ready:int):
        self.instruction = instruction & 0xffffffff
        self.opcode = (self.instruction >> 0) & 0x7f
        self.RS1 = (self.instruction >> 15) & 0x1f
        self.RS2 = (self.instruction >> 20) & 0x1f
        self.RD = (self.instruction >> 7) & 0x1f
        self.IMM = self.get_imm()
        self.FUNCT3 = (self.instruction >> 12) & 0x7
        self.FUNCT7 = (self.instruction >> 25) & 0x7f
        
        self.RD_valid = int(self.opcode in HAS_RD)
        self.RS1_valid = int(self.opcode in HAS_RS1)
        self.RS2_valid = int(self.opcode in HAS_RS2)
        
        self.MULTIPLY = int((self.opcode == OP) and (self.FUNCT7 == 0x01))
        self.SUBTRACT = int((self.opcode == OP) and (self.FUNCT7 == 0x20))
        self.IMMEDIATE = int(self.opcode == IMM_OP)
        self.IS_LOAD = int(self.opcode == LOAD)
        self.IS_STORE = int(self.opcode == STORE)
        self.needs_ALU = int(((self.opcode == OP) and 
                            (self.FUNCT7 == 0x00 or self.SUBTRACT)) or 
                            self.opcode == IMM_OP)
        self.needs_branch_unit = int(self.opcode in BRANCH_OPS)
        self.needs_CSRs = 0
        self.needs_memory = int(self.opcode in MEM)
        
        self.packet_index = packet_index
        self.ROB_index = ROB_index
        self.instructionType = self.opcode >> 2
        if self.opcode in INT:
            self.RS_type = 0
        elif self.opcode in MEM:
            self.RS_type = 1
        else:
            self.RS_type = 2
            
        if self.needs_ALU:
            self.portID = 0
        elif self.needs_branch_unit:
            self.portID = 0
        elif self.needs_CSRs:
            self.portID = 1
        elif self.needs_memory:
            self.portID = 3
        else:
            self.portID = 0
            
        self.ready_bits_RS1_ready = 0
        self.ready_bits_RS2_ready = 0
        if self.opcode in ALL_OPS:
            self.valid = 1
        else:
            self.valid = 0
            
        
        
        
    def get_imm(self):
        #I Type
        if self.opcode == 0x13 or self.opcode == 0x3 or self.opcode == 0x73 or self.opcode == 0x67:
            return (self.instruction >> 20) & 0xfff
        #S Type
        elif self.opcode == 0x23:
            imm_upper = (self.instruction >> 25) & 0x7f
            imm_lower = (self.instruction >> 7) & 0x1f
            return (imm_upper << 5) + imm_lower
        #B type
        elif self.opcode == 0x63:
            imm_upper = (self.instruction >> 20) & 0x7e0
            imm_lower = (self.instruction >> 7) & 0x1e
            return imm_upper + imm_lower + \
                ((self.instruction & 0x80000000) >> 19) + ((self.instruction & 0x80) << 4)
        #U Type
        elif self.opcode == 0x37 or self.opcode == 0x17:
            return self.instruction & 0xfffff000
        #J Type
        elif self.opcode == 0x6f:
            bit_20 = (self.instruction >> 11) & 0x100000
            bits_10_to_1 = (self.instruction >> 20) & 0x7fe
            bit_11 = (self.instruction >> 9) & 0x800
            bits_19_to_12 = self.instruction & 0xff000
            return bit_20 + bits_19_to_12 + bits_10_to_1 + bit_11
        else:
            return 0x0  
        
    
        

class decoder_dut:
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
        
    def input_instruction(self, instruction):
        self.dut.io_instruction_valid.value = 1
        self.dut.io_instruction_bits_packet_index.value = 1
        self.dut.io_instruction_bits_ROB_index.value = 1
        self.dut.io_decoded_instruction_ready.value = 1
        self.dut.io_instruction_bits_instruction.value = instruction

    def get_output(self):
        outputs = {}
        
        outputs["valid"] = self.dut.io_decoded_instruction_valid.value
        outputs["ready_bits_RS1_ready"] = self.dut.io_decoded_instruction_bits_ready_bits_RS1_ready.value
        outputs["ready_bits_RS2_ready"] = self.dut.io_decoded_instruction_bits_ready_bits_RS2_ready.value
        
        outputs["RD"] = self.dut.io_decoded_instruction_bits_RD.value
        outputs["RD_valid"] = self.dut.io_decoded_instruction_bits_RD_valid.value
        outputs["RS1"] = self.dut.io_decoded_instruction_bits_RS1.value
        outputs["RS1_valid"] = self.dut.io_decoded_instruction_bits_RS1_valid.value
        outputs["RS2"] = self.dut.io_decoded_instruction_bits_RS2.value
        outputs["RS2_valid"] = self.dut.io_decoded_instruction_bits_RS2_valid.value
        outputs["IMM"] = self.dut.io_decoded_instruction_bits_IMM.value
        outputs["FUNCT3"] = self.dut.io_decoded_instruction_bits_FUNCT3.value
        
        outputs["packet_index"] = self.dut.io_decoded_instruction_bits_packet_index.value
        outputs["ROB_index"] = self.dut.io_decoded_instruction_bits_ROB_index.value
        outputs["instructionType"] = self.dut.io_decoded_instruction_bits_instructionType.value
        outputs["portID"] = self.dut.io_decoded_instruction_bits_portID.value
        outputs["RS_type"] = self.dut.io_decoded_instruction_bits_RS_type.value
        
        outputs["needs_ALU"] = self.dut.io_decoded_instruction_bits_needs_ALU.value
        outputs["needs_branch_unit"] = self.dut.io_decoded_instruction_bits_needs_branch_unit.value
        outputs["needs_CSRs"] = self.dut.io_decoded_instruction_bits_needs_CSRs.value
        outputs["SUBTRACT"] = self.dut.io_decoded_instruction_bits_SUBTRACT.value
        outputs["MULTIPLY"] = self.dut.io_decoded_instruction_bits_MULTIPLY.value
        outputs["IMMEDIATE"] = self.dut.io_decoded_instruction_bits_IMMEDIATE.value
        outputs["IS_LOAD"] = self.dut.io_decoded_instruction_bits_IS_LOAD.value
        outputs["IS_STORE"] = self.dut.io_decoded_instruction_bits_IS_STORE.value
        
        return outputs

class fetch_pkt_decoder_dut:
    
    FETCH_WIDTH = 4
    
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
        
    def fetch_packet(self, 
                          fetch_PC:int, 
                          valid_bits:list,
                          decoded_fetch_pkt_rdy_bits:list, 
                          instructions:list,
                          packet_indices:list,
                          ROB_indices:list):
        self.dut.io_fetch_packet_valid.value = 1
        self.dut.io_fetch_packet_bits_fetch_PC.value = fetch_PC
        for i in range(self.FETCH_WIDTH):
            setattr(self.dut, f"io_fetch_packet_bits_valid_bits_{i}", valid_bits[0])
            setattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_instruction", instructions[0])
            setattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_packet_index", packet_indices[0])
            setattr(self.dut, f"io_fetch_packet_bits_instructions_{i}_ROB_index", ROB_indices[0])
            setattr(self.dut, f"io_decoded_fetch_packet_{i}_ready", decoded_fetch_pkt_rdy_bits[0])
            
    def get_output(self):
        outputs = {}
        
        outputs["fetch_packet_ready"] = self.dut.io_fetch_packet_ready
        for i in range(self.FETCH_WIDTH):
            outputs[f"io_decoded_fetch_packet_{i}_valid"] = getattr(self.dut, f"io_decoded_fetch_packet_{i}_valid")
            outputs[f"fetch_packet_{i}_ready"] = getattr(self.dut, f"io_decoded_fetch_packet_{i}_ready")


class BackendPacket:

    def __init__(self,
        valid = 0,
        RD_valid = 0,
        RD = 0,
        RS1 = 0,
        RS2 = 0,
        IMM = 0,
        FUNCT3 = 0,
        packet_index = 0,
        ROB_index = 0,
        instructionType = 0,
        portID = 0,
        RS_type = 0,
        needs_ALU = 0,
        needs_branch_unit = 0,
        SUBTRACT = 0,
        MULTIPLY = 0,
        IMMEDIATE = 0,
        IS_LOAD = 0,
        IS_STORE = 0,
        RS1_ready = 0,
        RS2_ready = 0,
        ready = 0):

        io_backendPacket_valid = valid
        io_backendPacket_bits_decoded_instruction_RD_valid = RD_valid
        io_backendPacket_bits_decoded_instruction_RD = RD
        io_backendPacket_bits_decoded_instruction_RS1 = RS1
        io_backendPacket_bits_decoded_instruction_RS2 = RS2
        io_backendPacket_bits_decoded_instruction_IMM = IMM
        io_backendPacket_bits_decoded_instruction_FUNCT3 = FUNCT3
        io_backendPacket_bits_decoded_instruction_packet_index = packet_index
        io_backendPacket_bits_decoded_instruction_ROB_index = ROB_index
        io_backendPacket_bits_decoded_instruction_instructionType = instructionType
        io_backendPacket_bits_decoded_instruction_portID = portID
        io_backendPacket_bits_decoded_instruction_RS_type = RS_type
        io_backendPacket_bits_decoded_instruction_needs_ALU = needs_ALU
        io_backendPacket_bits_decoded_instruction_needs_branch_unit = needs_branch_unit
        io_backendPacket_bits_decoded_instruction_SUBTRACT = SUBTRACT
        io_backendPacket_bits_decoded_instruction_MULTIPLY = MULTIPLY
        io_backendPacket_bits_decoded_instruction_IMMEDIATE = IMMEDIATE
        io_backendPacket_bits_decoded_instruction_IS_LOAD = IS_LOAD
        io_backendPacket_bits_decoded_instruction_IS_STORE = IS_STORE
        io_backendPacket_bits_ready_bits_RS1_ready = RS1_ready
        io_backendPacket_bits_ready_bits_RS2_ready = RS2_ready
        
        self.io_backendPacket_valid = io_backendPacket_valid
        self.io_backendPacket_bits_decoded_instruction_RD_valid = io_backendPacket_bits_decoded_instruction_RD_valid
        self.io_backendPacket_bits_decoded_instruction_RD = io_backendPacket_bits_decoded_instruction_RD
        self.io_backendPacket_bits_decoded_instruction_RS1 = io_backendPacket_bits_decoded_instruction_RS1
        self.io_backendPacket_bits_decoded_instruction_RS2 = io_backendPacket_bits_decoded_instruction_RS2
        self.io_backendPacket_bits_decoded_instruction_IMM = io_backendPacket_bits_decoded_instruction_IMM
        self.io_backendPacket_bits_decoded_instruction_FUNCT3 = io_backendPacket_bits_decoded_instruction_FUNCT3
        self.io_backendPacket_bits_decoded_instruction_packet_index = io_backendPacket_bits_decoded_instruction_packet_index
        self.io_backendPacket_bits_decoded_instruction_ROB_index = io_backendPacket_bits_decoded_instruction_ROB_index
        self.io_backendPacket_bits_decoded_instruction_instructionType = io_backendPacket_bits_decoded_instruction_instructionType
        self.io_backendPacket_bits_decoded_instruction_portID = io_backendPacket_bits_decoded_instruction_portID
        self.io_backendPacket_bits_decoded_instruction_RS_type = io_backendPacket_bits_decoded_instruction_RS_type
        self.io_backendPacket_bits_decoded_instruction_needs_ALU = io_backendPacket_bits_decoded_instruction_needs_ALU
        self.io_backendPacket_bits_decoded_instruction_needs_branch_unit = io_backendPacket_bits_decoded_instruction_needs_branch_unit
        self.io_backendPacket_bits_decoded_instruction_SUBTRACT = io_backendPacket_bits_decoded_instruction_SUBTRACT
        self.io_backendPacket_bits_decoded_instruction_MULTIPLY = io_backendPacket_bits_decoded_instruction_MULTIPLY
        self.io_backendPacket_bits_decoded_instruction_IMMEDIATE = io_backendPacket_bits_decoded_instruction_IMMEDIATE
        self.io_backendPacket_bits_decoded_instruction_IS_LOAD = io_backendPacket_bits_decoded_instruction_IS_LOAD
        self.io_backendPacket_bits_decoded_instruction_IS_STORE = io_backendPacket_bits_decoded_instruction_IS_STORE
        self.io_backendPacket_bits_ready_bits_RS1_ready = io_backendPacket_bits_ready_bits_RS1_ready
        self.io_backendPacket_bits_ready_bits_RS2_ready = io_backendPacket_bits_ready_bits_RS2_ready


class backendDut:
    def __init__(self, dut):
        self.dut = dut
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock

    def write(self, BackendPacket0=BackendPacket(), BackendPacket1=BackendPacket(), BackendPacket2=BackendPacket(), BackendPacket3=BackendPacket()):

        BackendPackets = [BackendPacket0, BackendPacket1, BackendPacket2, BackendPacket3]

        for i in range(4):
            getattr(self.dut, f"io_backendPacket_{i}_valid").value = BackendPackets[i].io_backendPacket_valid
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_RD_valid").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_RD_valid
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_RD").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_RD
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_RS1").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_RS1
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_RS2").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_RS2
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_IMM").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_IMM
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_FUNCT3").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_FUNCT3
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_packet_index").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_packet_index
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_ROB_index").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_ROB_index
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_instructionType").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_instructionType
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_portID").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_portID
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_RS_type").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_RS_type
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_needs_ALU").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_needs_ALU
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_needs_branch_unit").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_needs_branch_unit
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_SUBTRACT").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_SUBTRACT
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_MULTIPLY").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_MULTIPLY
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_IMMEDIATE").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_IMMEDIATE
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_IS_LOAD").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_IS_LOAD
            getattr(self.dut, f"io_backendPacket_{i}_bits_decoded_instruction_IS_STORE").value = BackendPackets[i].io_backendPacket_bits_decoded_instruction_IS_STORE
            getattr(self.dut, f"io_backendPacket_{i}_bits_ready_bits_RS1_ready").value = BackendPackets[i].io_backendPacket_bits_ready_bits_RS1_ready
            getattr(self.dut, f"io_backendPacket_{i}_bits_ready_bits_RS2_ready").value = BackendPackets[i].io_backendPacket_bits_ready_bits_RS2_ready

    def get_output(self):

        dram_request_valid = getattr(self.dut, f"io_dram_request_valid").value
        dram_request_bits_addr = getattr(self.dut, f"io_dram_request_bits_addr").value
        dram_request_bits_wr_en = getattr(self.dut, f"io_dram_request_bits_wr_data").value
        dram_request_wr_en = getattr(self.dut, f"io_dram_request_wr_en").value

        return {"dram_request_valid" : dram_request_valid,
                "dram_request_bits_addr" : dram_request_bits_addr,
                "dram_request_bits_wr_en" : dram_request_bits_wr_en,
                "dram_request_wr_en" : dram_request_wr_en}


#module backend(
  #input         clock,
                #reset,
  #output        io_backendPacket_0_ready,
  #input         io_backendPacket_0_valid,
                #io_backendPacket_0_bits_decoded_instruction_RD_valid,
  #input  [5:0]  io_backendPacket_0_bits_decoded_instruction_RD,
                #io_backendPacket_0_bits_decoded_instruction_RS1,
                #io_backendPacket_0_bits_decoded_instruction_RS2,
  #input  [31:0] io_backendPacket_0_bits_decoded_instruction_IMM,
  #input  [2:0]  io_backendPacket_0_bits_decoded_instruction_FUNCT3,
  #input  [3:0]  io_backendPacket_0_bits_decoded_instruction_packet_index,
  #input  [5:0]  io_backendPacket_0_bits_decoded_instruction_ROB_index,
  #input  [4:0]  io_backendPacket_0_bits_decoded_instruction_instructionType,
  #input  [1:0]  io_backendPacket_0_bits_decoded_instruction_portID,
                #io_backendPacket_0_bits_decoded_instruction_RS_type,
  #input         io_backendPacket_0_bits_decoded_instruction_needs_ALU,
                #io_backendPacket_0_bits_decoded_instruction_needs_branch_unit,
                #io_backendPacket_0_bits_decoded_instruction_SUBTRACT,
                #io_backendPacket_0_bits_decoded_instruction_MULTIPLY,
                #io_backendPacket_0_bits_decoded_instruction_IMMEDIATE,
                #io_backendPacket_0_bits_decoded_instruction_IS_LOAD,
                #io_backendPacket_0_bits_decoded_instruction_IS_STORE,
                #io_backendPacket_0_bits_ready_bits_RS1_ready,
                #io_backendPacket_0_bits_ready_bits_RS2_ready,
  #output        io_backendPacket_1_ready,
  #input         io_backendPacket_1_valid,
                #io_backendPacket_1_bits_decoded_instruction_RD_valid,
  #input  [5:0]  io_backendPacket_1_bits_decoded_instruction_RD,
                #io_backendPacket_1_bits_decoded_instruction_RS1,
                #io_backendPacket_1_bits_decoded_instruction_RS2,
  #input  [31:0] io_backendPacket_1_bits_decoded_instruction_IMM,
  #input  [2:0]  io_backendPacket_1_bits_decoded_instruction_FUNCT3,
  #input  [3:0]  io_backendPacket_1_bits_decoded_instruction_packet_index,
  #input  [5:0]  io_backendPacket_1_bits_decoded_instruction_ROB_index,
  #input  [4:0]  io_backendPacket_1_bits_decoded_instruction_instructionType,
  #input  [1:0]  io_backendPacket_1_bits_decoded_instruction_portID,
                #io_backendPacket_1_bits_decoded_instruction_RS_type,
  #input         io_backendPacket_1_bits_decoded_instruction_needs_ALU,
                #io_backendPacket_1_bits_decoded_instruction_needs_branch_unit,
                #io_backendPacket_1_bits_decoded_instruction_SUBTRACT,
                #io_backendPacket_1_bits_decoded_instruction_MULTIPLY,
                #io_backendPacket_1_bits_decoded_instruction_IMMEDIATE,
                #io_backendPacket_1_bits_decoded_instruction_IS_LOAD,
                #io_backendPacket_1_bits_decoded_instruction_IS_STORE,
                #io_backendPacket_1_bits_ready_bits_RS1_ready,
                #io_backendPacket_1_bits_ready_bits_RS2_ready,
  #output        io_backendPacket_2_ready,
  #input         io_backendPacket_2_valid,
                #io_backendPacket_2_bits_decoded_instruction_RD_valid,
  #input  [5:0]  io_backendPacket_2_bits_decoded_instruction_RD,
                #io_backendPacket_2_bits_decoded_instruction_RS1,
                #io_backendPacket_2_bits_decoded_instruction_RS2,
  #input  [31:0] io_backendPacket_2_bits_decoded_instruction_IMM,
  #input  [2:0]  io_backendPacket_2_bits_decoded_instruction_FUNCT3,
  #input  [3:0]  io_backendPacket_2_bits_decoded_instruction_packet_index,
  #input  [5:0]  io_backendPacket_2_bits_decoded_instruction_ROB_index,
  #input  [4:0]  io_backendPacket_2_bits_decoded_instruction_instructionType,
  #input  [1:0]  io_backendPacket_2_bits_decoded_instruction_portID,
                #io_backendPacket_2_bits_decoded_instruction_RS_type,
  #input         io_backendPacket_2_bits_decoded_instruction_needs_ALU,
                #io_backendPacket_2_bits_decoded_instruction_needs_branch_unit,
                #io_backendPacket_2_bits_decoded_instruction_SUBTRACT,
                #io_backendPacket_2_bits_decoded_instruction_MULTIPLY,
                #io_backendPacket_2_bits_decoded_instruction_IMMEDIATE,
                #io_backendPacket_2_bits_decoded_instruction_IS_LOAD,
                #io_backendPacket_2_bits_decoded_instruction_IS_STORE,
                #io_backendPacket_2_bits_ready_bits_RS1_ready,
                #io_backendPacket_2_bits_ready_bits_RS2_ready,
  #output        io_backendPacket_3_ready,
  #input         io_backendPacket_3_valid,
                #io_backendPacket_3_bits_decoded_instruction_RD_valid,
  #input  [5:0]  io_backendPacket_3_bits_decoded_instruction_RD,
                #io_backendPacket_3_bits_decoded_instruction_RS1,
                #io_backendPacket_3_bits_decoded_instruction_RS2,
  #input  [31:0] io_backendPacket_3_bits_decoded_instruction_IMM,
  #input  [2:0]  io_backendPacket_3_bits_decoded_instruction_FUNCT3,
  #input  [3:0]  io_backendPacket_3_bits_decoded_instruction_packet_index,
  #input  [5:0]  io_backendPacket_3_bits_decoded_instruction_ROB_index,
  #input  [4:0]  io_backendPacket_3_bits_decoded_instruction_instructionType,
  #input  [1:0]  io_backendPacket_3_bits_decoded_instruction_portID,
                #io_backendPacket_3_bits_decoded_instruction_RS_type,
  #input         io_backendPacket_3_bits_decoded_instruction_needs_ALU,
                #io_backendPacket_3_bits_decoded_instruction_needs_branch_unit,
                #io_backendPacket_3_bits_decoded_instruction_SUBTRACT,
                #io_backendPacket_3_bits_decoded_instruction_MULTIPLY,
                #io_backendPacket_3_bits_decoded_instruction_IMMEDIATE,
                #io_backendPacket_3_bits_decoded_instruction_IS_LOAD,
                #io_backendPacket_3_bits_decoded_instruction_IS_STORE,
                #io_backendPacket_3_bits_ready_bits_RS1_ready,
                #io_backendPacket_3_bits_ready_bits_RS2_ready,
  #output        io_dram_resp_ready,
  #input         io_dram_resp_valid,
  #input  [31:0] io_dram_resp_bits_data,
  #input         io_dram_request_ready,
  #output        io_dram_request_valid,
  #output [31:0] io_dram_request_bits_addr,
                #io_dram_request_bits_wr_data,
  #output        io_dram_request_bits_wr_en
#);
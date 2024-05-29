
class RSDut:
    def __init__(self, dut):
        self.dut = dut
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock

    def set_RS_ready(self):
        self.dut.io_backendPacket_0_ready.value = 1

    def write_RS(self, 
                valid=[0,0,0,0], 
                RD_valid=[0,0,0,0],
                RD=[0,0,0,0], 
                RS1=[0,0,0,0], 
                RS2=[0,0,0,0], 
                IMM=[0,0,0,0], 
                FUNCT3=[0,0,0,0], 
                packet_index=[0,0,0,0], 
                instructionType=[0,0,0,0], 
                portID=[0,0,0,0], 
                RS_type=[0,0,0,0], 
                needs_ALU=[0,0,0,0], 
                needs_branch_unit=[0,0,0,0], 
                SUBTRACT=[0,0,0,0], 
                MULTIPLY=[0,0,0,0], 
                IMMEDIATE=[0,0,0,0], 
                ROB_index=[0,0,0,0], 
                RS1_ready=[0,0,0,0], 
                RS2_ready=[0,0,0,0]):


        for i in range(4):

            getattr(self.dut, f'io_backendPacket_{i}_valid').value = valid[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_RD_valid').value = RD_valid[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_RD').value = RD[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_RS1').value = RS1[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_RS2').value = RS2[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_IMM').value = IMM[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_FUNCT3').value = FUNCT3[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_packet_index').value = packet_index[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_instructionType').value = instructionType[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_portID').value = portID[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_RS_type').value = RS_type[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_needs_ALU').value = needs_ALU[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_needs_branch_unit').value = needs_branch_unit[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_SUBTRACT').value = SUBTRACT[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_MULTIPLY').value = MULTIPLY[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_IMMEDIATE').value = IMMEDIATE[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_decoded_instruction_ROB_index').value = ROB_index[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_ready_bits_RS1_ready').value = RS1_ready[i]
            getattr(self.dut, f'io_backendPacket_{i}_bits_ready_bits_RS2_ready').value = RS2_ready[i]


    def broadcast(self, RD=[0,0,0,0], RD_valid=[0,0,0,0], valid=[0,0,0,0]):
        self.dut.io_FU_broadcast_0_bits_RD.value = RD[0]
        self.dut.io_FU_broadcast_0_valid.value = valid[0]
        self.dut.io_FU_broadcast_0_bits_RD_valid.value = RD_valid[0]

        self.dut.io_FU_broadcast_1_bits_RD.value = RD[1]
        self.dut.io_FU_broadcast_1_valid.value = valid[1]
        self.dut.io_FU_broadcast_1_bits_RD_valid.value = RD_valid[0]

        self.dut.io_FU_broadcast_2_bits_RD.value = RD[2]
        self.dut.io_FU_broadcast_2_valid.value = valid[2]
        self.dut.io_FU_broadcast_2_bits_RD_valid.value = RD_valid[0]

    def get_ready(self):
        ready = [0,0,0,0]
        ready[0] = self.dut.io_RS_input_0_ready.value
        ready[1] = self.dut.io_RS_input_1_ready.value
        ready[2] = self.dut.io_RS_input_2_ready.value
        ready[3] = self.dut.io_RS_input_3_ready.value

        return ready

    def set_ports_ready(self, ready=[1,1,1,1]):

        self.dut.io_RF_inputs_0_ready.value = ready[0]
        self.dut.io_RF_inputs_1_ready.value = ready[1]
        self.dut.io_RF_inputs_2_ready.value = ready[2]

    def get_ports(self):
        ports = []
        for i in range(3):
            port = {
                'valid':                int(getattr(self.dut, f'io_RF_inputs_{i}_valid').value),
                'RD_valid':             int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_valid').value),
                'RD':                   int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD').value),
                'RS1':                  int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1').value),
                'RS2':                  int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2').value),
                'IMM':                  int(getattr(self.dut, f'io_RF_inputs_{i}_bits_IMM').value),
                'FUNCT3':               int(getattr(self.dut, f'io_RF_inputs_{i}_bits_FUNCT3').value),
                'packet_index':         int(getattr(self.dut, f'io_RF_inputs_{i}_bits_packet_index').value),
                'ROB_index':            int(getattr(self.dut, f'io_RF_inputs_{i}_bits_ROB_index').value),
                'instructionType':      int(getattr(self.dut, f'io_RF_inputs_{i}_bits_instructionType').value),
                'portID':               int(getattr(self.dut, f'io_RF_inputs_{i}_bits_portID').value),
                'RS_type':              int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS_type').value),
                'needs_ALU':            int(getattr(self.dut, f'io_RF_inputs_{i}_bits_needs_ALU').value),
                'needs_branch_unit':    int(getattr(self.dut, f'io_RF_inputs_{i}_bits_needs_branch_unit').value),
                'SUBTRACT':             int(getattr(self.dut, f'io_RF_inputs_{i}_bits_SUBTRACT').value),
                'MULTIPLY':             int(getattr(self.dut, f'io_RF_inputs_{i}_bits_MULTIPLY').value),
                'IMMEDIATE':            int(getattr(self.dut, f'io_RF_inputs_{i}_bits_IMMEDIATE').value)
            }
            ports.append(port)
        return ports

    def get_RS(self):
        rs_entries = []
        for i in range(20):
            entry={
                'RD':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_RD').value),
                'RS1':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_RS1').value),
                'RS2':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_RS2').value),
                'IMM':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_IMM').value),
                'FUNCT3':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_FUNCT3').value),
                'packet_index':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_packet_index').value),
                'ROB_index':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_ROB_index').value),
                'instructionType':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_instructionType').value),
                'portID':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_portID').value),
                'RS_type':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_RS_type').value),
                'needs_ALU':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_needs_ALU').value),
                'needs_branch_unit':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_needs_branch_unit').value),
                'SUBTRACT':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_SUBTRACT').value),
                'MULTIPLY':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_MULTIPLY').value),
                'IMMEDIATE':int(getattr(self.dut, f'reservation_station_{i}_decoded_instruction_IMMEDIATE').value),
                'RS1_ready':int(getattr(self.dut, f'reservation_station_{i}_ready_bits_RS1_ready').value),
                'RS2_ready':int(getattr(self.dut, f'reservation_station_{i}_ready_bits_RS2_ready').value),
                'valid':int(getattr(self.dut, f'reservation_station_{i}_valid').value)
            }
            rs_entries.append(entry)
        return rs_entries

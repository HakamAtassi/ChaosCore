

#io_backendPacket_0_valid
#io_backendPacket_0_bits_decoded_instruction_RD
#io_backendPacket_0_bits_decoded_instruction_RS1
#io_backendPacket_0_bits_decoded_instruction_RS2
#io_backendPacket_0_bits_decoded_instruction_IMM
#io_backendPacket_0_bits_decoded_instruction_FUNCT3
#io_backendPacket_0_bits_decoded_instruction_packet_index
#io_backendPacket_0_bits_decoded_instruction_ROB_index
#io_backendPacket_0_bits_decoded_instruction_instructionType
#io_backendPacket_0_bits_decoded_instruction_portID
#io_backendPacket_0_bits_decoded_instruction_RS_type
#io_backendPacket_0_bits_decoded_instruction_needs_ALU
#io_backendPacket_0_bits_decoded_instruction_needs_branch_unit
#io_backendPacket_0_bits_decoded_instruction_SUBTRACT
#io_backendPacket_0_bits_decoded_instruction_MULTIPLY
#io_backendPacket_0_bits_decoded_instruction_IMMEDIATE
#io_backendPacket_0_bits_ROB_entry
#io_backendPacket_0_bits_ready_bits_RS1_bits
#io_backendPacket_0_bits_ready_bits_RS2_bits

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


    def broadcast(self, RD=[0,0,0,0], data=[0,0,0,0], valid=[0,0,0,0]):
        self.dut.io_FU_broadcast_0_RD_valid.value = valid[0]
        self.dut.io_FU_broadcast_0_RD_bits.value = RD[0]
        self.dut.io_FU_broadcast_0_data.value = data[0]

        self.dut.io_FU_broadcast_1_RD_valid.value = valid[1]
        self.dut.io_FU_broadcast_1_RD_bits.value = RD[1]
        self.dut.io_FU_broadcast_1_data.value = data[1]

        self.dut.io_FU_broadcast_2_RD_valid.value = valid[2]
        self.dut.io_FU_broadcast_2_RD_bits.value = RD[2]
        self.dut.io_FU_broadcast_2_data.value = data[2]

        self.dut.io_FU_broadcast_3_RD_valid.value = valid[3]
        self.dut.io_FU_broadcast_3_RD_bits.value = RD[3]
        self.dut.io_FU_broadcast_3_data.value = data[3]


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
        self.dut.io_RF_inputs_3_ready.value = ready[3]

    def get_ports(self):
        ports = []
        for i in range(4):
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

    def print_outputs(self):
        print("Port Information:")
        print(f"| {'Port':<6} | {'valid':<6} | {'RD_valid':<10} | {'RD_bits':<10} | {'RS1_ready':<10} | {'RS1_valid':<10} | {'RS1_bits':<10} | {'RS2_ready':<10} | {'RS2_is_imm':<10} | {'RS2_valid':<10} | {'RS2_bits':<12} | {'uOp_portID_value':<15}")
        
        ports = self.get_ports()

        for i in range(4):
            valid    = ports[i]['valid']
            RD_valid = ports[0]['RD_valid']
            RS1 = ports[i]['RS1']
            RS2 = ports[i]['RS2']
            portID = ports[i]['portID']
            #RD_valid = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_valid').value)
            #RD_bits = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_bits').value)
            #RS1_ready = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_ready').value)
            #RS1_valid = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_valid').value)
            #RS1_bits = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_bits').value)
            #RS2_ready = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_ready').value)
            #RS2_is_imm = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_is_imm').value)
            #RS2_valid = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_valid').value)
            #RS2_bits = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_bits').value)
            #uOp_portID_value = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_uOp_portID_value').value)

            # Print all port info in 1 line
            print(f"| {valid} | {RD_valid}  |  {RS1}  |  {RS2} |  {portID}  |")
            #print(f"| {i:<6} | {valid:<6} | {RD_valid:<10} | {RD_bits:<10} | {RS1_ready:<10} | {RS1_valid:<10} | {RS1_bits:<10} | {RS2_ready:<10} | {RS2_is_imm:<10} | {RS2_valid:<10} | {RS2_bits:<12} | {uOp_portID_value:<15}")

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

    def print_RS(self):
        header = "| {:<2} | {:<2} | {:<8} | {:<8} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<18} | {:<16} |".format(
            "i", "V", "RD valid", "RD", "RS1 valid", "RS1 ready", "RS1 value", "RS2 valid", "RS2 ready", "RS2 is imm", "RS2 value", "uOp portID value"
        )
        print(header)
        rs_entries = self.get_RS()
        for i, entry in enumerate(rs_entries):
            print("| {:<2} | {:<2} | {:<8} | {:<8} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<18} | {:<16} |".format(
                i, entry['valid'], entry['RD_valid'], entry['RD_bits'], entry['RS1_valid'], entry['RS1_ready'], entry['RS1_bits'],
                entry['RS2_valid'], entry['RS2_ready'], entry['RS2_is_imm'], entry['RS2_bits'], entry['uop_portID_value']
            ))
        print(f"Outputs")
        ready = self.get_ready()
        print(f"Ready {ready}")

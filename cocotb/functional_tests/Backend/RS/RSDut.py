


class RSDut:
    def __init__(self, dut):
        self.dut = dut
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock

    def set_RS_ready(self):
        self.dut.io_RS_input_ready.value = 1

    #def write_RS(self, RD_valid, RD, RS1_ready, RS1_valid, RS1_bits, RS2_ready, RS2_is_imm, RS2_valid, RS2_bits, uOp, valid):
    def write_RS(self, RD_valid=[0,0,0,0], RD=[0,0,0,0], RS1_ready=[0,0,0,0], RS1_valid=[0,0,0,0], RS1_bits=[0,0,0,0], RS2_ready=[0,0,0,0], RS2_is_imm=[0,0,0,0], RS2_valid=[0,0,0,0], RS2_bits=[5,0,0,0], uOp=[0,0,0,0], valid=[0,0,0,0]):

        for i in range(4):
            getattr(self.dut, f'io_RS_input_{i}_valid').value = valid[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RD_valid').value = RD_valid[i]

            getattr(self.dut, f'io_RS_input_{i}_bits_RD_bits').value = RD[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS1_ready').value = RS1_ready[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS1_valid').value = RS1_valid[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS1_bits').value = RS1_bits[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS2_ready').value = RS2_ready[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS2_is_imm').value = RS2_is_imm[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS2_valid').value = RS2_valid[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_RS2_bits').value = RS2_bits[i]
            getattr(self.dut, f'io_RS_input_{i}_bits_uOp_portID_value').value = uOp[i]

    def broadcast(self, RD=[0,0,0,0], data=[0,0,0,0], valid=[0,0,0,0]):
        self.dut.io_FU_broadcast_0_valid.value = valid[0]
        self.dut.io_FU_broadcast_0_bits_RD.value = RD[0]
        self.dut.io_FU_broadcast_0_bits_data.value = data[0]

        self.dut.io_FU_broadcast_1_valid.value = valid[1]
        self.dut.io_FU_broadcast_1_bits_RD.value = RD[1]
        self.dut.io_FU_broadcast_1_bits_data.value = data[1]

        self.dut.io_FU_broadcast_2_valid.value = valid[2]
        self.dut.io_FU_broadcast_2_bits_RD.value = RD[2]
        self.dut.io_FU_broadcast_2_bits_data.value = data[2]

        self.dut.io_FU_broadcast_3_valid.value = valid[3]
        self.dut.io_FU_broadcast_3_bits_RD.value = RD[3]
        self.dut.io_FU_broadcast_3_bits_data.value = data[3]

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
                'valid': int(getattr(self.dut, f'io_RF_inputs_{i}_valid').value),
                'RD_valid': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_valid').value),
                'RD_bits': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_bits').value),
                'RS1_ready': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_ready').value),
                'RS1_valid': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_valid').value),
                'RS1_bits': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_bits').value),
                'RS2_ready': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_ready').value),
                'RS2_is_imm': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_is_imm').value),
                'RS2_valid': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_valid').value),
                'RS2_bits': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_bits').value),
                'uOp_portID_value': int(getattr(self.dut, f'io_RF_inputs_{i}_bits_uOp_portID_value').value)
            }
            ports.append(port)
        return ports

    def print_outputs(self):
        print("Port Information:")
        print(f"| {'Port':<6} | {'valid':<6} | {'RD_valid':<10} | {'RD_bits':<10} | {'RS1_ready':<10} | {'RS1_valid':<10} | {'RS1_bits':<10} | {'RS2_ready':<10} | {'RS2_is_imm':<10} | {'RS2_valid':<10} | {'RS2_bits':<12} | {'uOp_portID_value':<15}")
        
        for i in range(4):
            valid = int(getattr(self.dut, f'io_RF_inputs_{i}_valid').value)
            RD_valid = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_valid').value)
            RD_bits = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RD_bits').value)
            RS1_ready = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_ready').value)
            RS1_valid = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_valid').value)
            RS1_bits = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS1_bits').value)
            RS2_ready = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_ready').value)
            RS2_is_imm = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_is_imm').value)
            RS2_valid = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_valid').value)
            RS2_bits = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_RS2_bits').value)
            uOp_portID_value = int(getattr(self.dut, f'io_RF_inputs_{i}_bits_uOp_portID_value').value)

            # Print all port info in 1 line
            print(f"| {i:<6} | {valid:<6} | {RD_valid:<10} | {RD_bits:<10} | {RS1_ready:<10} | {RS1_valid:<10} | {RS1_bits:<10} | {RS2_ready:<10} | {RS2_is_imm:<10} | {RS2_valid:<10} | {RS2_bits:<12} | {uOp_portID_value:<15}")

    def get_RS(self):
        rs_entries = []
        for i in range(20):
            entry = {
                'valid': int(getattr(self.dut, f'reservation_station_{i}_valid').value),
                'RD_valid': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RD_valid').value),
                'rd_bits': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RD_bits').value),
                'RS1_ready': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS1_ready').value),
                'RS1_valid': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS1_valid').value),
                'RS1_bits': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS1_bits').value),
                'RS2_ready': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_ready').value),
                'RS2_is_imm': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_is_imm').value),
                'RS2_valid': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_valid').value),
                'RS2_bits': int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_bits').value),
                'uop_portID_value': int(getattr(self.dut, f'reservation_station_{i}_RF_data_uOp_portID_value').value),
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
                i, entry['valid'], entry['RD_valid'], entry['rd_bits'], entry['RS1_valid'], entry['RS1_ready'], entry['RS1_bits'],
                entry['RS2_valid'], entry['RS2_ready'], entry['RS2_is_imm'], entry['RS2_bits'], entry['uop_portID_value']
            ))
        print(f"Outputs")
        ready = self.get_ready()
        print(f"Ready {ready}")

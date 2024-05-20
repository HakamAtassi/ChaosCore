


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

    def write_RS(self, RD_valid, RD, RS1_ready, RS1_valid, RS1_bits, RS2_ready, RS2_is_imm, RS2_valid, RS2_bits, uOp, valid):

        self.dut.io_RS_input_valid.value                 = valid

        self.dut.io_RS_input_bits_RD_valid.value         = RD_valid
        self.dut.io_RS_input_bits_RD_bits.value          = RD

        self.dut.io_RS_input_bits_RS1_ready.value        = RS1_ready
        self.dut.io_RS_input_bits_RS1_valid.value        = RS1_valid
        self.dut.io_RS_input_bits_RS1_bits.value         = RS1_bits

        self.dut.io_RS_input_bits_RS2_ready.value        = RS2_ready
        self.dut.io_RS_input_bits_RS2_is_imm.value       = RS2_is_imm
        self.dut.io_RS_input_bits_RS2_valid.value        = RS2_valid
        self.dut.io_RS_input_bits_RS2_bits.value         = RS2_bits

        self.dut.io_RS_input_bits_uOp_portID_value.value = uOp

    def broadcoast(self, RD, data, valid):
        self.dut.io_FU_broadcast_valid.value        =   valid
        self.dut.io_FU_broadcast_bits_RD.value      =   RD
        self.dut.io_FU_broadcast_bits_data.value    =   data


    def print_RS(self):
        header = "| {:<2} | {:<8} | {:<8} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<18} | {:<16} |".format(
                "V", "RD valid", "RD", "RS1 valid", "RS1 ready", "RS1 value", "RS2 valid", "RS2 ready", "RS2 is imm", "RS2 value", "uOp portID value")
        print(header)
        for i in range(20):
            valid               = int(getattr(self.dut, f'reservation_station_{i}_valid'))
            rd_valid            = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RD_valid'))
            rd_bits             = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RD_bits'))
            rs1_ready           = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS1_ready'))
            rs1_valid           = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS1_valid'))
            rs1_bits            = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS1_bits'))
            rs2_ready           = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_ready'))
            rs2_is_imm          = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_is_imm'))
            rs2_valid           = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_valid'))
            rs2_bits            = int(getattr(self.dut, f'reservation_station_{i}_RF_data_RS2_bits'))
            uop_portID_value    = int(getattr(self.dut, f'reservation_station_{i}_RF_data_uOp_portID_value'))

            print("| {:<2} | {:<8} | {:<8} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<10} | {:<18} | {:<16} |".format(
                valid, rd_valid, rd_bits, rs1_valid, rs1_ready, rs1_bits, rs2_valid, rs2_ready, rs2_is_imm, rs2_bits, uop_portID_value))

        print("")

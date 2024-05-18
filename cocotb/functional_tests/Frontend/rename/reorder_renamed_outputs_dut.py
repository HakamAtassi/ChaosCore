from cocotb.triggers import RisingEdge, FallingEdge, Timer


class reorder_renamed_outputs_dut:
    def __init__(self, dut):
        self.dut=dut


    def place_input(self, data, valid_bits):
        self.dut.io_renamed_valid_0.value = valid_bits[0]
        self.dut.io_renamed_valid_1.value = valid_bits[1]
        self.dut.io_renamed_valid_2.value = valid_bits[2]
        self.dut.io_renamed_valid_3.value = valid_bits[3]

        self.dut.io_renamed_values_0 = data[0]
        self.dut.io_renamed_values_1 = data[1]
        self.dut.io_renamed_values_2 = data[2]
        self.dut.io_renamed_values_3 = data[3]

    def get_output(self):
        sorted_data = [0]*4

        sorted_data[0] = int(self.dut.io_renamed_values_sorted_0)
        sorted_data[1] = int(self.dut.io_renamed_values_sorted_1)
        sorted_data[2] = int(self.dut.io_renamed_values_sorted_2)
        sorted_data[3] = int(self.dut.io_renamed_values_sorted_3)

        return sorted_data

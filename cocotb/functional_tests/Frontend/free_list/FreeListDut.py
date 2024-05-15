
class FreeListDut:
    def __init__(self, dut):
        self.dut=dut

    def clock(self):
        return self.dut.clock

    def rename(self, valid_bits):

        self.dut.io_rename_valid_0.value = valid_bits[0]
        self.dut.io_rename_valid_1.value = valid_bits[1]
        self.dut.io_rename_valid_2.value = valid_bits[2]
        self.dut.io_rename_valid_3.value = valid_bits[3] 


    def free(self, data, valid_bits):

        self.dut.io_free_valid_0.value = valid_bits[0]
        self.dut.io_free_valid_1.value = valid_bits[1]
        self.dut.io_free_valid_2.value = valid_bits[2]
        self.dut.io_free_valid_3.value = valid_bits[3]

        self.dut.io_free_values_0.value = data[0]
        self.dut.io_free_values_1.value = data[1]
        self.dut.io_free_values_2.value = data[2]
        self.dut.io_free_values_3.value = data[3]


    def get_renamed_regs(self):
        renamed_regs = [0]*4

        renamed_regs[0] = int(self.dut.io_renamed_values_0.value)
        renamed_regs[1] = int(self.dut.io_renamed_values_1.value)
        renamed_regs[2] = int(self.dut.io_renamed_values_2.value)
        renamed_regs[3] = int(self.dut.io_renamed_values_3.value)

        return renamed_regs



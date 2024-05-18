from cocotb.triggers import RisingEdge, FallingEdge, Timer


class reorder_free_inputs_dut:
    def __init__(self, dut):
        self.dut=dut

    #def clock(self):
        #return self.dut.clock

    #async def reset(self):
        #self.dut.reset.value = 1
        #await RisingEdge(self.clock())
        #self.dut.reset.value = 0

    def place_input(self, data, valid_bits):

        self.dut.io_free_valid_0.value = valid_bits[0]
        self.dut.io_free_valid_1.value = valid_bits[1]
        self.dut.io_free_valid_2.value = valid_bits[2]
        self.dut.io_free_valid_3.value = valid_bits[3]

        self.dut.io_free_values_0.value = data[0]
        self.dut.io_free_values_1.value = data[1]
        self.dut.io_free_values_2.value = data[2]
        self.dut.io_free_values_3.value = data[3]

    def get_output(self):
        sorted_values  = [0]*4
        sorted_valid   = [0]*4

        sorted_values[0] = int(self.dut.io_free_values_sorted_0.value)
        sorted_values[1] = int(self.dut.io_free_values_sorted_1.value)
        sorted_values[2] = int(self.dut.io_free_values_sorted_2.value)
        sorted_values[3] = int(self.dut.io_free_values_sorted_3.value)

        sorted_valid[0] = int(self.dut.io_free_valid_sorted_0.value)
        sorted_valid[1] = int(self.dut.io_free_valid_sorted_1.value)
        sorted_valid[2] = int(self.dut.io_free_valid_sorted_2.value)
        sorted_valid[3] = int(self.dut.io_free_valid_sorted_3.value)

        return sorted_values, sorted_valid


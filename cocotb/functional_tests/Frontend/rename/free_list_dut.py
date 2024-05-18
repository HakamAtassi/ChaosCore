from cocotb.triggers import RisingEdge, FallingEdge, Timer

class free_list_dut:
    def __init__(self, dut):
        self.dut=dut

    def clock(self):
        return self.dut.clock

    async def reset(self):
        self.dut.reset.value = 1
        await RisingEdge(self.clock())
        self.dut.reset.value = 0

    def dequeue_registers(self, valid):

        # valids from request
        self.dut.io_rename_valid_0.value = valid[0]
        self.dut.io_rename_valid_1.value = valid[1]
        self.dut.io_rename_valid_2.value = valid[2]
        self.dut.io_rename_valid_3.value = valid[3]


    def enqueue_registers(self, values, valid):

        # valids from enqueue
        self.dut.io_rename_valid_0.value = valid[0]
        self.dut.io_rename_valid_1.value = valid[1]
        self.dut.io_rename_valid_2.value = valid[2]
        self.dut.io_rename_valid_3.value = valid[3]

        self.dut.io_renamed_values_0.value = value[0]
        self.dut.io_renamed_values_1.value = value[1]
        self.dut.io_renamed_values_2.value = value[2]
        self.dut.io_renamed_values_3.value = value[3]

    def get_outputs(self):

        free_list_values  = [0]*4

        free_list_values[0] = int(self.dut.io_renamed_values_0.value)
        free_list_values[1] = int(self.dut.io_renamed_values_1.value)
        free_list_values[2] = int(self.dut.io_renamed_values_2.value)
        free_list_values[3] = int(self.dut.io_renamed_values_3.value)

        return free_list_values
from cocotb.triggers import RisingEdge, FallingEdge, Timer

class RAT_dut:
    def __init__(self, dut):
        self.dut=dut

    def clock(self):
        return self.dut.clock

    async def reset(self):
        self.dut.reset.value = 1
        await RisingEdge(self.clock())
        self.dut.reset.value = 0


    def write(self, instruction_RD, free_list_RD, free_list_valid):
        self.dut.io_instruction_RD_0.value = instruction_RD[0]
        self.dut.io_instruction_RD_1.value = instruction_RD[1]
        self.dut.io_instruction_RD_2.value = instruction_RD[2]
        self.dut.io_instruction_RD_3.value = instruction_RD[3]

        self.dut.io_free_list_wr_en_0.value = free_list_valid[0]
        self.dut.io_free_list_wr_en_1.value = free_list_valid[1]
        self.dut.io_free_list_wr_en_2.value = free_list_valid[2]
        self.dut.io_free_list_wr_en_3.value = free_list_valid[3]

        self.dut.io_free_list_RD_0.value    = free_list_RD[0]
        self.dut.io_free_list_RD_1.value    = free_list_RD[1]
        self.dut.io_free_list_RD_2.value    = free_list_RD[2]
        self.dut.io_free_list_RD_3.value    = free_list_RD[3]

    def read(self, instruction_RD, instruction_RS1, instruction_RS2):
        self.dut.io_instruction_RD_0.value = instruction_RD[0]
        self.dut.io_instruction_RD_1.value = instruction_RD[1]
        self.dut.io_instruction_RD_2.value = instruction_RD[2]
        self.dut.io_instruction_RD_3.value = instruction_RD[3]

        self.dut.io_instruction_RS1_0.value = instruction_RS1[0]
        self.dut.io_instruction_RS1_1.value = instruction_RS1[1]
        self.dut.io_instruction_RS1_2.value = instruction_RS1[2]
        self.dut.io_instruction_RS1_3.value = instruction_RS1[3]

        self.dut.io_instruction_RS2_0.value = instruction_RS2[0]
        self.dut.io_instruction_RS2_1.value = instruction_RS2[1]
        self.dut.io_instruction_RS2_2.value = instruction_RS2[2]
        self.dut.io_instruction_RS2_3.value = instruction_RS2[3]

    def rename(self, instruction_RD, instruction_RS1, instruction_RS2, free_list_RD, free_list_valid):
        self.read(instruction_RD, instruction_RS1, instruction_RS2)
        self.write(free_list_RD, free_list_valid)

    def create_checkpoint(self, valid):
        self.dut.io_create_checkpoint.value = valid

    def restore_checkpoint(self, value, valid):
        self.dut.io_restore_checkpoint.value = valid
        self.dut.io_restore_checkpoint.value = value

    def free_checkpoint(self, valid):
        self.dut.io_free_checkpoint.value = valid

    def get_outputs(self):
        renamed_RD  = [0]*4
        renamed_RS1 = [0]*4
        renamed_RS2 = [0]*4
        
        renamed_RD[0] = int(self.dut.io_RAT_RD_0.value)
        renamed_RD[1] = int(self.dut.io_RAT_RD_1.value)
        renamed_RD[2] = int(self.dut.io_RAT_RD_2.value)
        renamed_RD[3] = int(self.dut.io_RAT_RD_3.value)

        renamed_RS1[0] = int(self.dut.io_RAT_RS1_0.value)
        renamed_RS1[1] = int(self.dut.io_RAT_RS1_1.value)
        renamed_RS1[2] = int(self.dut.io_RAT_RS1_2.value)
        renamed_RS1[3] = int(self.dut.io_RAT_RS1_3.value)

        renamed_RS2[0] = int(self.dut.io_RAT_RS2_0.value)
        renamed_RS2[1] = int(self.dut.io_RAT_RS2_1.value)
        renamed_RS2[2] = int(self.dut.io_RAT_RS2_2.value)
        renamed_RS2[3] = int(self.dut.io_RAT_RS2_3.value)

        return  renamed_RD, renamed_RS1, renamed_RS2

    
    def get_full(self):
        return int(self.dut.io_checkpoints_full.value)
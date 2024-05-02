

class BTBDut:
    def __init__(self, dut):
        self.dut = dut

    def clock(self):
        return self.dut.clock

    def predict(self, address, valid):
        self.dut.io_predict_PC.value      = address
        self.dut.io_predict_valid.value   = valid

    def commit(self, address, target, type, br_mask, valid):
        self.dut.io_commit_valid.value      =   valid
        self.dut.io_commit_PC.value         =   address
        self.dut.io_commit_target.value     =   target
        self.dut.io_commit_br_type.value    =   type
        self.dut.io_commit_br_mask.value    =   br_mask


    def is_output_valid(self):
        return int(self.dut.io_BTB_valid.value)

    def get_hit(self):
        return int(self.dut.io_BTB_hit.value)

    def get_target(self):
        return int(self.dut.io_BTB_target.value)

    def get_type(self):
        return int(self.dut.io_BTB_type.value)

    def get_br_mask(self):
        return int(self.dut.io_BTB_br_mask.value)

    def get_output(self):
        hit = self.get_hit()
        target = self.get_target()
        br_mask = self.get_br_mask()
        type = self.get_type()
        return (hit, target, type, br_mask)

    def get_mem_line(self, addr):
        line = int(self.dut.BTB_memory.mem_ext.Memory[addr])
        return line

    def get_target_state(self):
        target_state=[]
        target_mask=((1<<36)-1)
        for i in range(4096):
            line = self.get_mem_line(i)
            line=line&target_mask
            #print(hex(line))
            line=line>>(4)
            target_state.append(line)

        return target_state
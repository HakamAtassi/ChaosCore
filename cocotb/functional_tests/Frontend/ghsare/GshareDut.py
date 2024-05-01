


class GshareDut:
    def __init__(self, dut, GHR_width):
        self.dut = dut
        self.GHR_width = GHR_width
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock

    def predict(self, PC, GHR, valid):
        """request prediction"""
        self.dut.io_predict_GHR.value = GHR
        self.dut.io_predict_PC.value = PC
        self.dut.io_predict_valid.value = valid

    def commit(self, PC, GHR, resolved_direction, valid):
        """request update"""
        self.dut.io_commit_GHR.value = GHR
        self.dut.io_commit_PC.value = PC
        self.dut.io_commit_valid.value = valid
        self.dut.io_commit_branch_direction.value = resolved_direction

    def get_output(self):
        """get T_NT"""
        return int(self.dut.io_T_NT.value)

    def is_output_valid(self):
        """check if output is valid"""
        return int(self.dut.io_valid.value)

    def hashed_predict_address(self):
        """check if output is valid"""
        return int(self.dut.hashed_predict_addr.value)

    ##########################
    ### GET INTERNAL STATE ###
    ##########################

    def get_PHT_line(self, addr):
        line = self.dut.PHT.mem_ext.Memory[addr].value
        return line

    def get_cache_state(self):
        PHT_state = []
        for i in range(1<<self.GHR_width):
            PHT_state[i] = self.get_PHT_line(i)
        return PHT_state



class RASDut:
    def __init__(self, dut):
        self.dut = dut
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock
    
    def get_output(self):
        ret_addr = int(self.dut.io_ret_addr.value)
        NEXT = int(self.dut.io_NEXT.value)
        TOS = int(self.dut.io_TOS.value)
        return (ret_addr, NEXT, TOS)

    def is_output_valid(self):
        return self.dut.io_ret_valid.value

    ##########################
    ### GET INTERNAL STATE ###
    ##########################

    def get_TOS_reg(self):
        return int(self.dut.io_TOS.value)
    
    def get_NEXT_reg(self):
        return int(self.dut.io_NEXT.value)

    #############################
    ### INTERFACE WITH MODULE ###
    #############################

    def push(self, addr,valid):
        self.dut.io_wr_valid.value = valid
        self.dut.io_wr_addr.value = addr

    def pop(self, valid):
        self.dut.io_rd_valid.value = valid

    def revert(self, TOS, NEXT, valid):
        self.dut.io_revert_NEXT.value = NEXT
        self.dut.io_revert_TOS.value = TOS
        self.dut.io_revert_valid.value = valid


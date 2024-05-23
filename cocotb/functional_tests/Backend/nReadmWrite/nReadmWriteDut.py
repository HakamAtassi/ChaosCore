


class nReadmWrite:
    def __init__(self, dut):
        self.dut = dut
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock

    def write(self, addr_in = [0,0,0,0], data_in=[0x0,0x0,0x0,0x0], wr_en=[0,0,0,0]):
        for i in range(4):
            getattr(self.dut,f"wdata_{i}").value = addr_in[i]
            getattr(self.dut,f"wen_{i}").value   = wr_en[i]
            getattr(self.dut,f"waddr_{i}").value = addr_in[i]

    def read(self, addr_in = [0,0,0,0,0,0,0,0]):
        for i in range(8):
            getattr(self.dut,f"raddr_{i}").value = addr_in[i]

    def get_output(self):
        output=[0]*8
        for i in range(8):
            output[i] = int(getattr(self.dut,f"rdata_{i}").value)
        return output           





class RAS:
    def __init__(self, dut, entries):
        self.dut = dut
        self.entries = entries
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock


    ##########################
    ### GET INTERNAL STATE ###
    ##########################

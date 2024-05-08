from Channels import *
import random

class FrontendDut:
    def __init__(self, dut, dram_model):
        self.dut=dut
        self.outstanding_dram_request = False
        self.remaining_dram_latency=0
        self.dram_model = dram_model

    def clock(self):
        return self.dut.clock

    def is_waiting_for_dram(self):
        return self.dut.io_dram_data_ready.value == 1

    def generate_dram_response(self, valid):
        self.dut.io_dram_data_valid.value = valid 

        self.dut.io_dram_data_bits.value  = self.dram_model.read(0, 32)

    def set_output_Q_ready(self):
        self.dut.io_fetch_packet_ready.value = 1

    def update(self):
        self.generate_dram_response(0)
        if(self.is_waiting_for_dram() and self.outstanding_dram_request == True and self.remaining_dram_latency==0):
            # TODO: generate dram response
            self.outstanding_dram_request=False
            self.generate_dram_response(1)
            self.outstanding_dram_request = False
        elif(self.is_waiting_for_dram() and self.outstanding_dram_request == True):
            self.remaining_dram_latency-=1
        elif(self.is_waiting_for_dram()):
            self.outstanding_dram_request = True
            self.remaining_dram_latency=random.randint(0,100)
        

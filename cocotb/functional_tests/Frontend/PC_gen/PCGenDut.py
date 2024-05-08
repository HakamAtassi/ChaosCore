from Channels import *

class PCGenDut:
    def __init__(self, dut):
        self.dut=dut
        pass

    def clock(self):
        return self.dut.clock

    def commit(self, commit):
        self.dut.io_commit_valid.value                    =   commit.valid
        self.dut.io_commit_bits_PC.value                  =   commit.address
        self.dut.io_commit_bits_GHR.value                 =   commit.GHR
        self.dut.io_commit_bits_T_NT.value                =   commit.T_NT
        self.dut.io_commit_bits_target.value              =   commit.target
        self.dut.io_commit_bits_br_type.value             =   commit.br_type
        self.dut.io_commit_bits_br_mask.value             =   commit.br_mask
        self.dut.io_commit_bits_misprediction.value       =   commit.misprediction
        self.dut.io_commit_bits_TOS.value                 =   commit.TOS
        self.dut.io_commit_bits_NEXT.value                =   commit.NEXT
        self.dut.io_commit_bits_misprediction_PC.value    =   commit.misprediction_PC

    def prediction(self, prediction):
        self.dut.io_prediction_valid.value          =   prediction.valid
        self.dut.io_prediction_bits_hit.value       =   prediction.BTB_hit
        self.dut.io_prediction_bits_target.value    =   prediction.BTB_target
        self.dut.io_prediction_bits_br_type.value   =   prediction.BTB_br_type
        self.dut.io_prediction_bits_br_mask.value   =   prediction.BTB_br_mask
        self.dut.io_prediction_bits_GHR.value       =   prediction.GHR
        self.dut.io_prediction_bits_T_NT.value      =   prediction.T_NT
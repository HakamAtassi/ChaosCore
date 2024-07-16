class PC_gen_dut:
    def __init__(self, dut):
        self.PC_gen = dut

    ##############
    ## PC ARBIT ##
    ##############

    def PC_gen_commit_valid(self):
        return self.PC_gen.io_commit_valid

    def PC_gen_read_commit(self):
        commit = {}
        commit["valid"] = self.PC_gen.io_commit_valid.value
        commit["fetch_PC"] = self.PC_gen.io_commit_fetch_PC.value
        commit["T_NT"] = self.PC_gen.io_commit_T_NT.value
        commit["ROB_index"] = self.PC_gen.io_commit_ROB_index.value
        commit["br_type"] = self.PC_gen.io_commitbr_type_t.value
        commit["fetch_packet_index"] = self.PC_gen.io_commit_fetch_packet_index.value
        commit["is_misprediction"] = self.PC_gen.io_commit_is_misprediction.value
        commit["expected_PC"] = self.PC_gen.io_commit_expected_PC.value
        commit["commit_GHR"] = self.PC_gen.io_commit_GHR.value
        commit["TOS"] = self.PC_gen.io_commit_TOS.value
        commit["NEXT"] = self.PC_gen.io_commit_NEXT.value
        commit["RAT_index"] = self.PC_gen.io_commit_RAT_index.value
        return commit

    def PC_gen_prediction_valid(self):
        return self.PC_gen.io_prediction_valid

    def PC_gen_read_prediction(self):
        prediction = {}

        # FIXME: signals optimized out
        # prediction["ready"] = self.PC_gen.io_prediction_ready.value
        prediction["valid"] = self.PC_gen.io_prediction_valid.value
        prediction["hit"] = self.PC_gen.io_prediction_bits_hit.value
        prediction["target"] = self.PC_gen.io_prediction_bits_target.value
        prediction["br_type"] = self.PC_gen.io_prediction_bitsbr_type_t.value
        # prediction["br_mask"] = self.PC_gen.io_prediction_bits_br_mask.value
        # prediction["GHR"] = self.PC_gen.io_prediction_bits_GHR.value
        # prediction["T_NT"] = self.PC_gen.io_prediction_bits_T_NT.value
        return prediction

    def PC_gen_read_RAS_read(self):
        RAS_read = {}
        RAS_read["NEXT"] = self.PC_gen.io_RAS_read_NEXT.value
        RAS_read["TOS"] = self.PC_gen.io_RAS_read_TOS.value
        RAS_read["ret_addr"] = self.PC_gen.io_RAS_read_ret_addr.value
        return RAS_read

    def PC_gen_PC_next_valid(self):
        return self.PC_gen.io_PC_next_valid

    def PC_gen_read_PC_next(self):
        PC_next = {}
        PC_next["ready"] = self.PC_gen.io_PC_next_ready.value
        PC_next["valid"] = self.PC_gen.io_PC_next_valid.value
        PC_next["next"] = int(self.PC_gen.io_PC_next_bits_addr.value)
        return PC_next





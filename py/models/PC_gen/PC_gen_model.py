class PC_gen_model:
    def __init__(self):
        self.misprediction_valid = 0
        self.misprediction_PC = 0
        self.is_misprediction = 0

        self.prediction_valid = 0
        self.prediction_PC = 0
        self.prediction_hit = 0
        self.prediction_br_type = 0
        self.prediction_br_mask = 0

        self.revert_valid = 0
        self.revert_PC = 0


        self.PC = 0

    def commit(self, commit):
        self.misprediction_valid = commit["valid"]
        self.misprediction_PC = commit["expected_PC"]
        self.is_misprediction = commit["is_misprediction"]

    def prediction(self, prediction):
        self.prediction_valid = prediction["valid"]
        self.prediction_PC = prediction["target"]
        self.prediction_hit = prediction["hit"]
        self.prediction_br_type = prediction["br_type"]
        #self.prediction_br_mask = prediction["br_mask"]

    def revert(self, revert):
        self.revert_valid = revert["valid"]
        self.revert_PC = revert["PC"]

    def RAS_read(self, RAS_read):
        self.RAS_read_PC = RAS_read["ret_addr"]

    def PC_next(self):
        PC_next = {}

        PC_next["next"] = self.PC

        take_misprediction = self.misprediction_PC and self.misprediction_valid
        take_revert = self.revert_valid
        take_prediction = self.prediction_valid and self.prediction_hit
        take_RAS = self.prediction_br_type == 4  # "RET"
        take_16 = 1

        if take_misprediction:
            self.PC = self.misprediction_PC
        elif take_revert:
            self.PC = self.revert_PC
        elif take_prediction:
            self.PC = self.RAS_PC if take_RAS else self.prediction_PC
        elif take_16:
            self.PC = self.PC + 16

        # PC_next["ready"] = self.PC_gen.io_PC_next_ready.value
        # PC_next["valid"] = self.PC_gen.io_PC_next_valid.value

        return PC_next

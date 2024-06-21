class PC_gen_model:
    def __init__(self):
        self.commit = {}
        self.prediction = {}
        self.revert = {}
        self.RAS_read = {}

        self.PC = 0

        self.PC_next_queue = []


    def inputs(self, commit, prediction, revert, RAS_read, PC_next):
        self.commit = commit
        self.prediction = prediction
        self.revert = revert
        self.RAS_read = RAS_read
        self.PC_next = PC_next

        
        next_PC = self.update()


    def get_is_misprediction(self):
        return self.commit["valid"] and self.commit["is_misprediction"]

    def get_is_prediction(self):
        return self.prediction["valid"] and self.prediction["hit"] and self.prediction["T_NT"]

    def get_is_RAS(self):
        return self.prediction["br_type"] == 4


    def get_next_PC(self):
        PC_next = {}

        PC_next["valid"] = 1
        PC_next["next"] = self.PC

        is_misprediction = self.get_is_misprediction()
        is_revert = self.revert["valid"]
        is_prediction = self.get_is_prediction()
        is_RAS = self.get_is_RAS()
        

        if is_misprediction:
            self.PC = self.commit["expected_PC"]
        elif is_revert:
            self.PC = self.revert["PC"]
        elif is_RAS:
            self.PC = self.RAS["ret_addr"]
        elif is_prediction:
            self.PC = self.prediction["target"]
        else:
            self.PC = self.PC + 16


        return PC_next




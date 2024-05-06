
class commit:
    def __init__(self, commit_data):
        self.address, self.commit_GHR, self.T_NT, self.target, self.br_type, self.br_mask, self.misprediction, self.TOS, self.NEXT, self.valid = commit_data
    def get(self):
        return (self.address, self.commit_GHR, self.T_NT, self.target, self.br_type, self.br_mask, self.misprediction, self.TOS, self.NEXT, self.valid)
    @staticmethod
    def null():
        return commit((0, 0, 0, 0, 0, 0, 0, 0, 0, 0))
    def __eq__(self, other):
        if isinstance(other, commit):
            return self.get() == other.get()
        return False

class predict:
    def __init__(self, predict_data):
        self.address, self.valid = predict_data
    def get(self):
        return (self.address, self.valid)
    @staticmethod
    def null():
        return predict((0, 0))
    def __eq__(self, other):
        if isinstance(other, prediction):
            return self.get() == other.get()
    def print(self):
        print(self.get(), end=" ")

class revert:
    def __init__(self, revert_data):
        self.address, self.revert_GHR, self.valid = revert_data
    def get(self):
        return (self.address, self.revert_GHR, self.valid)
    @staticmethod
    def null():
        return revert((0, 0, 0))
    def __eq__(self, other):
        if isinstance(other, prediction):
            return self.get() == other.get()
    def print(self):
        print(self.get(), end=" ")

class RAS_update:
    def __init__(self, RAS_update_data):
        self.call, self.ret, self.ret_addr = RAS_update_data
    def get(self):
        return (self.call, self.ret, self.ret_addr)
    @staticmethod
    def null():
        return RAS_update((0, 0, 0))
    def __eq__(self, other):
        if isinstance(other, prediction):
            return self.get() == other.get()
    def print(self):
        print(self.get(), end=" ")

class prediction:
    def __init__(self, prediction_data):
        self.hit, self.target, self.br_type, self.br_mask, self.T_NT, self.GHR, self.valid = prediction_data
    def get(self):
        return (self.hit, self.target, self.br_type, self.br_mask, self.T_NT, self.GHR, self.valid)
    @staticmethod
    def null():
        return prediction((0,0,0,0,0,0,0))
    def __eq__(self, other):
        if isinstance(other, prediction):
            return self.get() == other.get()
    def print(self):
        print(self.get(), end=" ")

class BTBResp:
    def __init__(self):
        pass

class FetchPacket:
    def __init__(self, instructions, validBits, PC, fetchWidth=4):
        self.instructions = instructions
        self.PC = PC

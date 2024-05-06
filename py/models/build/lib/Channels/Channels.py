
class Channel:
    def __init__(self, data):
        pass
        #self.data = data

    #def get(self):
        #return self.data

    #@staticmethod
    #def null():
        #return Channel(0)

    #def __eq__(self, other):
        #if isinstance(other, Channel):
            #return self.get() == other.get()
        #return False

    #def print(self):
        #print(self.get(), end=" ")

class Commit(Channel):
    def __init__(self, address, GHR, target, br_type, br_mask, T_NT, misprediction, TOS, NEXT, valid):
        self.address        = address
        self.GHR            = GHR
        self.target         = target
        self.br_type        = br_type
        self.br_mask        = br_mask
        self.T_NT           = T_NT
        self.misprediction  = misprediction
        self.TOS            = TOS
        self.NEXT           = NEXT
        self.valid          = valid

class Predict(Channel):
    def __init__(self, address, valid):
        #self.address, self.valid = data
        self.address = address
        self.valid   = valid

class Revert(Channel):
    def __init__(self,address, GHR, valid):
        self.address = address
        self.GHR     = GHR
        self.valid   = valid

class RAS_update(Channel):
    def __init__(self, call, ret, call_addr):
        self.call     = call
        self.ret      = ret
        self.call_addr = call_addr

class Prediction(Channel):
    def __init__(self, BTB_resp, PHT_resp, GHR, valid):
        self.BTB_hit        = BTB_resp.hit
        self.BTB_target     = BTB_resp.target
        self.BTB_br_type    = BTB_resp.br_type
        self.BTB_br_mask    = BTB_resp.br_mask
        self.valid          = BTB_resp.valid
        self.T_NT           = PHT_resp
        self.GHR            = GHR
        self.valid          = valid

    @staticmethod
    def null():
        # set all members to 0
        return Prediction(BTB_resp=BTB_resp.null(), PHT_resp=0, GHR=0, valid=0)

class BTB_resp(Channel):
    def __init__(self, hit, target, type, mask, valid):
        self.hit = hit
        self.target = target
        self.br_type = type
        self.br_mask = mask
        self.valid = valid

    @staticmethod
    def null():
        # set all members to 0
        return BTB_resp(hit=0, target=0, type=0, mask=0, valid=0)

class Fetch_packet(Channel):
    def __init__(self, instructions, valid_bits, PC, fetch_width=4):
        self.instructions = instructions
        self.valid_bits = valid_bits 
        self.PC = PC
        self.fetch_width = fetch_width

    def get(self):
        return self.instructions, self.valid_bits, self.PC

    @staticmethod
    def null(fetch_width):
        return Fetch_packet([0] * fetch_width, [0] * fetch_width, 0x0, fetch_width)

from Instruction import Instruction

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
    def __init__(self, address, GHR, target, br_type, br_mask, T_NT, misprediction, misprediction_PC, TOS, NEXT, valid):
        self.address        = address
        self.GHR            = GHR
        self.target         = target
        self.br_type        = br_type
        self.br_mask        = br_mask
        self.T_NT           = T_NT
        self.misprediction  = misprediction
        self.misprediction_PC  = misprediction_PC
        self.TOS            = TOS
        self.NEXT           = NEXT
        self.valid          = valid

    @staticmethod
    def null():
     return Commit(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

class Predict(Channel):
    def __init__(self, address, valid):
        #self.address, self.valid = data
        self.address = address
        self.valid   = valid

class Revert(Channel):
    def __init__(self, address, GHR, valid):
        self.address = address
        self.GHR     = GHR
        self.valid   = valid
    
    @staticmethod
    def null():
        # set all members to 0
        return Revert(address=0, GHR=0, valid=0)

class RAS_update(Channel):
    def __init__(self, call, ret, call_addr):
        self.call     = call
        self.ret      = ret
        self.call_addr = call_addr

    @staticmethod
    def null():
        # set all members to 0
        return RAS_update(call=0, ret=0, call_addr=0)

class Prediction(Channel):
    def __init__(self, BTB_resp, PHT_T_NT, GHR, valid):
        self.BTB_hit        = BTB_resp.hit
        self.BTB_target     = BTB_resp.target
        self.BTB_br_type    = BTB_resp.br_type
        self.BTB_br_mask    = BTB_resp.br_mask
        self.T_NT           = PHT_T_NT
        self.GHR            = GHR
        self.valid          = valid

    @staticmethod
    def null():
        # set all members to 0
        return Prediction(BTB_resp=BTB_resp.null(), PHT_T_NT=0, GHR=0, valid=0)

class BTB_resp(Channel):
    def __init__(self, hit, target, type, mask, valid):
        self.hit = hit
        self.target = target
        self.br_type = type
        self.br_mask = mask
        self.valid = valid

    @staticmethod
    def null():
        return BTB_resp(hit=0, target=0, type=0, mask=0, valid=0)

class RAS_read:
    def __init__(self, ret_addr, TOS, NEXT, valid):
        self.ret_addr = ret_addr
        self.TOS      = TOS
        self.NEXT     = NEXT
        self.valid    = valid

    @staticmethod
    def null():
        return RAS_read(ret_addr=0, TOS=0, NEXT=0, valid=0)
    
class fetch_packet:
    def __init__(self, instructions, valid, PC, fetch_width=4):
        self.instructions = instructions
        self.valid = valid
        self.PC = PC
        self.fetch_width = fetch_width

    @staticmethod
    def null(fetch_width):
        return fetch_packet(Instruction.null() * fetch_width, PC=0, valid=0x0, fetch_width=4)

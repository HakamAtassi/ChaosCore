

class PHT:
    def __init__(self, GHR_width=16):
        self.PHT = [0]*(1<<GHR_width)
        self.mask = (1<<GHR_width) - 1
        pass

    def get_hashed_address(self, PC, GHR):
        hashed_address = (PC ^ GHR) & self.mask
        return hashed_address

    def read_state(self, hashed_address):
        return self.PHT[hashed_address]

    def get_state(self):
        return self.PHT

    def predict(self, PC, GHR):
        hashed_address = self.get_hashed_address(PC, GHR)
        state = self.read_state(hashed_address) 
        T_NT = state >> 1
        return T_NT

    def write(self, hashed_address, new_state):
        self.PHT[hashed_address] = new_state

    def commit(self, PC, GHR, resolved_direction):
        hashed_address = self.get_hashed_address(PC, GHR)
        state = self.read_state(hashed_address) 

        if(resolved_direction): state = state+1
        else: state = state-1

        if(state > 3): state = 3
        elif(state < 0) : state = 0

        self.write(hashed_address, state)

class GHR:
    def __init__(self, GHR_width):
        self.GHR = 0
        self.mask = (1<<GHR_width) - 1

    def update(self, bit):
        self.GHR = (self.GHR << 1) | bit
        self.GHR = self.GHR & self.mask

    def write(self, GHR):
        self.GHR = GHR

    def read(self):
        return self.GHR

class Gshare:
    def __init__(self, GHR_width):
        self.PHT = PHT(GHR_width=GHR_width) # PHT has GHR_width bits of addressability
        self.GHR = GHR(GHR_width=GHR_width) # GHR is GHR_width bits wide

    def predict(self, PC):
        hashed_address = PC ^ self.GHR.read()
        T_NT = self.PHT.read_T_NT(address=hashed_address)
        self.GHR.update(T_NT)   # update GHR speculatively 
        return T_NT

    def commit(self, PC, GHR, resolved_direction):
        """Called on correct prediction"""
        hashed_address = GHR ^ PC
        self.PHT.write(hashed_address=hashed_address, direction=resolved_direction)

    def mispredict(self, mispredict_GHR, mispredict_PC, resolved_direction):
        """Called on incorrect prediction"""
        hashed_address = mispredict_GHR ^ mispredict_PC
        self.PHT.write(hashed_address=hashed_address, direction=resolved_direction)
        self.GHR.write(ghr=mispredict_GHR)  # revert GHR to its old value
        
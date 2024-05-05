from Gshare import *
from HashBTB import *
from RAS import *


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


class BP:
    def __init__(self, RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4):
        self.RAS = RAS(entries=RAS_entries)
        self.BTB = HashBTB(entries=BTB_entries, fetch_width=fetch_width)
        self.PHT = PHT(GHR_width=GHR_width)
        self.GHR = GHR(GHR_width=GHR_width)

    #####################
    # BP INPUT CHANNELS #
    #####################

    def commit(self, commit_msg):
        if(commit_msg.valid == 0): return 
        ## commits update the BTB and PHT with branch information
        address, commit_GHR, T_NT, target, br_type, br_mask, misprediction, TOS, NEXT, valid = commit_msg.get()
        if(T_NT):
            self.BTB.commit(address=address, target=target, br_type=br_type, br_mask=br_mask)
        if(br_type == 0):
            self.PHT.commit(PC=address, GHR=commit_GHR, resolved_direction=T_NT)

        if(int(misprediction)==1):
            ## revert RAS and GHR
            self.GHR.write(commit_GHR) # revert GHR
            self.RAS.revert(NEXT, TOS)
    
    def predict(self, predict_msg):
        ## predict requests read the BTB and PHT. RAS output is assumed already available.
        ## They also speculatively update the GHR based on the predicted taken direction (for branches only)
        # Prediction consists of BTB+PHT+Current GHR
        
        if(predict_msg.valid == 0): return
        address, valid = predict_msg.get()

        predict_GHR=self.GHR.read()
        BTB_resp = self.BTB.predict(address=address)
        PHT_resp = self.PHT.predict(PC=address, GHR=predict_GHR)
        if(BTB_resp[0] and BTB_resp[2]==0): # only update GHR when BTB indicates a branch
            self.GHR.update(PHT_resp)
        return prediction((*BTB_resp, PHT_resp, predict_GHR, valid))

    def revert(self, revert_msg):
        if(revert_msg.valid == 0): return
        ## reverts update the GHR only
        # reverts are mini mispredictions. They essentialy redirect the frontend before it has the change to
        # incorrectly update things like the RAS
        address, revert_GHR, valid = revert_msg.get()
        self.GHR.write(revert_GHR)

    def send_all_requests(self, predict, commit, revert, RAS_update):
        is_misprediction   = commit.misprediction
        is_revert          = revert.valid

        #if(commit.valid): print(f"model commit {hex(commit.address)}")

        #print(f"model: {commit.valid} {hex(commit.address)} {hex(commit.misprediction)}")

        if(is_misprediction and commit.valid):
            self.commit(commit)  # on misprediction, handle misprediction first]
            # on mispredictions, ignore reverts even if they are valid
        elif(is_revert):
            # FIXME: is this order correct??
            self.revert(revert)
            self.commit(commit)
        else: # normal operation
            self.commit(commit)
            self.RAS_update(RAS_update)

        prediction = None
        if(predict.valid):
            prediction = self.predict(predict)

        return prediction

    ########################
    # SUBMODULE INTERFACES #
    ########################

    # RAS
    def RAS_read(self):
        # Get access to current RAS values (without updating)
        RAS_output = self.RAS.get_outputs()
        return RAS_output

    def RAS_update(self, RAS_update_msg):
        call, ret, call_addr = RAS_update_msg.get()
        if call:
            self.RAS.push(addr=call_addr)
        elif ret:
            self.RAS.pop()


    def get_PHT_state(self):
        return self.PHT.get_state()


    # GHR
    def get_GHR(self):
        return self.GHR



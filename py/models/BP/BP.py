from Gshare import *
from HashBTB import *
from RAS import *
from Channels import *


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
        if(commit_msg.T_NT):
            self.BTB.commit(commit_msg)
        if(commit_msg.br_type == 0):
            self.PHT.commit(commit_msg)

        if(int(commit_msg.misprediction)==1):
            ## revert RAS and GHR
            self.GHR.write(commit_msg.GHR) # revert GHR
            self.RAS.revert(commit_msg.NEXT, commit_msg.TOS)
    
    def predict(self, predict_msg):
        ## predict requests read the BTB and PHT. RAS output is assumed already available.
        ## They also speculatively update the GHR based on the predicted taken direction (for branches only)
        # Prediction consists of BTB+PHT+Current GHR
        
        if(predict_msg.valid == 0): return
        #address, valid = predict_msg.get()

        predict_GHR=self.GHR.read()
        BTB_resp = self.BTB.predict(address=predict_msg.address)
        PHT_resp = self.PHT.predict(PC=predict_msg.address, GHR=predict_GHR)
        if(BTB_resp.hit and BTB_resp.br_type==0): # only update GHR when BTB indicates a branch
            self.GHR.update(PHT_resp)
        return Prediction(BTB_resp, PHT_resp, predict_GHR, predict_msg.valid)

    def revert(self, revert_msg):
        if(revert_msg.valid == 0): return
        ## reverts update the GHR only
        # reverts are mini mispredictions. They essentialy redirect the frontend before it has the change to
        # incorrectly update things like the RAS
        #address, revert_GHR, valid = revert_msg.get()
        self.GHR.write(revert_msg.GHR)

    def send_all_requests(self, predict, commit, revert, RAS_update):
        is_misprediction   = commit.misprediction
        is_revert          = revert.valid

        if(is_misprediction and commit.valid):
            self.commit(commit)
        elif(is_revert):
            # FIXME: is this order correct??
            self.revert(revert)
            self.commit(commit)
        else: # normal operation
            self.commit(commit)
            self.RAS_update(RAS_update)

        prediction = Prediction.null()
        if(predict.valid):
            prediction = self.predict(predict)

        return prediction

    ########################
    # SUBMODULE INTERFACES #
    ########################

    def RAS_read(self):
        # Get access to current RAS values (without updating)
        return self.RAS.get_outputs()

    def RAS_update(self, RAS_update_msg):
        #call, ret, call_addr = RAS_update_msg.get()
        if  RAS_update_msg.call: self.RAS.push(addr=RAS_update_msg.call_address)
        elif RAS_update_msg.ret: self.RAS.pop()

    def get_PHT_state(self):
        return self.PHT.get_state()

    def get_GHR(self):
        return self.GHR



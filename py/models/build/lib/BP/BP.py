from Gshare import *
from HashBTB import *
from RAS import *

class BP:
    def __init__(self, RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4):
        self.RAS = RAS(entries=RAS_entries)
        self.BTB = HashBTB(entries=BTB_entries, fetch_width=fetch_width)
        self.PHT = PHT(GHR_width=GHR_width)
        self.GHR = GHR(GHR_width=GHR_width)

    #####################
    # BP INPUT CHANNELS #
    #####################

    def commit(self, address, commit_GHR, T_NT, target, br_type, br_mask, NEXT=0, TOS=0,  misprediction=0):
        ## commits update the BTB and PHT with branch information
        self.BTB.commit(address=address, target=target, br_type=br_type, br_mask=br_mask)
        self.PHT.commit(PC=address, GHR=commit_GHR, resolved_direction=T_NT)

        if(misprediction):
            ## revert RAS and GHR
            self.GHR.write(commit_GHR) # revert GHR
            self.RAS.revert(NEXT, TOS)

    
    def predict(self, address):
        ## predict requests read the BTB and PHT. RAS output is assumed already available.
        ## They also speculatively update the GHR based on the predicted taken direction (for branches only)
        # Prediction consists of BTB+PHT+Current GHR
        predict_GHR=self.GHR.read()
        BTB_resp = self.BTB.predict(address=address)
        PHT_resp = self.PHT.predict(PC=address, GHR = predict_GHR)
        self.GHR.update(PHT_resp)
        return (BTB_resp, PHT_resp, self.GHR)

    def revert(self, revert_GHR):
        ## reverts update the GHR only
        # reverts are mini mispredictions. They essentialy redirect the frontend before it has the change to
        # incorrectly update things like the RAS
        self.GHR.write(revert_GHR)

    ########################
    # SUBMODULE INTERFACES #
    ########################

    # RAS
    def RAS_read(self):
        # Get access to current RAS values (without updating)
        RAS_output = self.RAS.get_outputs()
        return RAS_output

    def RAS_update(self, call_addr):
        self.RAS.push(addr=call_addr)

    # GHSARE

    # BTB


    # GHR
    def get_GHR(self):
        return self.GHR



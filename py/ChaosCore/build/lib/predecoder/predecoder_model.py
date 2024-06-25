from model_utils import *
from instruction import *

class predecoder_model:
    def __init__(self):
        self.GHR_queue = []
        self.final_fetch_packet_queue = []
        self.RAS_update_queue = []
        self.predictions_queue = []

    def input(self, flush, prediction, fetch_packet, RAS_read, commit):
        pass


    def update(self):
        pass


    def get_GHR(self):
        pass

    def get_final_fetch_packet_queue(self):
        pass

    def get_RAS_update_queue(self):
        pass

    def get_predictions_queue(self):
        pass


import numpy as np
import Channels 
from Channels import *

class HashBTB:
    def __init__(self, entries, fetch_width=4):
        self.entries        = entries
        self.tag_mem        = [0] * entries
        self.target_mem     = [0] * entries
        self.type_mem       = [0] * entries
        self.br_mask_mem    = [0] * entries
        self.valid_mem      = [0] * entries

        self.address_bits = int(np.log2(entries))
        self.address_mask = (1<<self.address_bits) - 1
        self.fetch_width_bits = int(np.log2(fetch_width))

        self.tag_bits     = (32-2-self.fetch_width_bits-self.address_bits)

    def get_hashed_address(self, address):
        address = address >> 2
        address = address >> self.fetch_width_bits
        address = address & self.address_mask
        return address

    def address_to_tag(self, address):
        shamt = (32-self.tag_bits)
        return (address >> shamt)

    def predict(self, address):
        masked_address = self.get_hashed_address(address)
        current_tag = self.address_to_tag(address)

        tag     = int(self.tag_mem[masked_address])
        target  = int(self.target_mem[masked_address])
        type    = int(self.type_mem[masked_address])
        valid   = int(self.valid_mem[masked_address])
        br_mask = int(self.br_mask_mem[masked_address])


        hit = int(((current_tag == tag) and valid))


        return BTB_resp(hit=hit, target=target, type=type, mask=br_mask, valid=valid)

        
    def commit(self, commit_msg):
        masked_address = self.get_hashed_address(commit_msg.address)
        current_tag = self.address_to_tag(commit_msg.address)

        self.tag_mem[masked_address]        = current_tag
        self.target_mem[masked_address]     = commit_msg.target
        self.type_mem[masked_address]       = commit_msg.br_type
        self.br_mask_mem[masked_address]    = commit_msg.br_mask
        self.valid_mem[masked_address]      = 1

    def get_target_state(self):
        return self.target_mem


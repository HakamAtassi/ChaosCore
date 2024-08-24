
import random
from enum import Enum


class memory_type_t(Enum):
    NONE = 0
    LOAD = 1
    STORE = 2

class access_width_t(Enum):
    NONE = 0
    B = 1  # Byte
    HW = 2 # Half-word
    W = 3  # Word



def generate_load_store(address_pool):

    load_store = {
        "valid"        : 1,
        "memory_type"  : random.choice([memory_type_t.LOAD.value, memory_type_t.STORE.value]),
        "access_width" : random.choice([access_width_t.B.value, access_width_t.HW.value, access_width_t.W.value]),
        "wr_data"      : random.getrandbits(32),
        "address"      : random.randint(0,3) + random.choice(address_pool),
        "MOB_index"    : 0
    }
    return load_store


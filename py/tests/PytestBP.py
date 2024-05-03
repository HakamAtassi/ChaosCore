import pytest
import random
from GenericCache import *
from SimpleDRAM import *
from BP import *
from model_utils import *

@pytest.fixture
def bp():
    bp = BP(RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4)
    return bp

def test_BTB_miss_hit(bp):

    (hit, target, type, br_mask), PHT, GHR = bp.predict(address = 0xdeadbeef)
    
    assert hit == False
    assert type == 0
    assert PHT == 0
    assert GHR.read() == 0

    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001)
    (hit, target, type, br_mask), PHT, GHR = bp.predict(address = 0xdeadbeef)

    assert hit == True, "predict did not hit"
    assert type == 0,   "type did not match expected"
    assert PHT == 0,    "PHT did not update/read correctly"
    assert GHR.read() == 0, "GHR shifted in wrong value"

    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001)

    assert GHR.read() == 0, "GHR updated on commit"
    (hit, target, type, br_mask), PHT, GHR = bp.predict(address = 0xdeadbeef)

    GHR = bp.get_GHR()
    assert GHR.read() == 0x1, "GHR not updated speculatively"

def test_RAS_update_read(bp):

    TOS, NEXT, ret_addr = bp.RAS_read()

    assert TOS      == 0, ""
    assert NEXT     == 0, "" 
    assert ret_addr == 0, ""

    bp.RAS_update(call_addr=0xdeadbeef)
    TOS, NEXT, ret_addr = bp.RAS_read()

    assert TOS      == 0
    assert NEXT     == 1
    assert ret_addr == 0xdeadbeef


def test_midpredict(bp):
    # update speculative structures
    # revert
    # perform assertions

    bp = BP(RAS_entries=128, BTB_entries=4096, GHR_width=16, fetch_width=4)

    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001)
    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001)
    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001)
    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001)
    bp.RAS_update(call_addr=0xdeadbeef)
    bp.RAS_update(call_addr=0xdeadbeef)
    bp.RAS_update(call_addr=0xdeadbeef)



    TOS, NEXT, ret_addr = bp.RAS_read()

    assert TOS      == 2
    assert NEXT     == 3
    assert ret_addr == 0xdeadbeef


    (hit, target, type, br_mask), PHT, GHR = bp.predict(address = 0xdeadbeef)
    (hit, target, type, br_mask), PHT, GHR = bp.predict(address = 0xdeadbeef)

    assert hit == True, "predict did not hit"
    assert target == 0xdeadc0de, "target addr wrong"
    assert GHR.read() == 0x2
    assert type == 0,   "type did not match expected"

    bp.commit(address=0xdeadbeef, commit_GHR=0, T_NT=1, target=0xdeadc0de, br_type=0b00, br_mask=0b0001, TOS=0, NEXT=0, misprediction=1)

    TOS, NEXT, ret_addr = bp.RAS_read()

    assert TOS      == 0
    assert NEXT     == 0
    assert bp.get_GHR().read() == 0x0

    pass

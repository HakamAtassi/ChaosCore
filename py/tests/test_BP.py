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

def test_miss(bp):

    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)
    assert type(resp) == Prediction
    assert resp.valid == 1
    assert resp.BTB_hit == 0
    assert resp.BTB_target == 0x0, f"expected {0x0} got {resp.BTB_target}"

    predict_request = Predict(address = 0xdeadbeef, valid = 0)
    resp = bp.predict(predict_request)
    assert type(resp) == type(None)


def test_hit(bp):

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    bp.commit(commit_request)

    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)
    assert type(resp) == Prediction

    assert resp.valid == 1
    assert resp.BTB_hit == 1
    assert resp.T_NT == 0
    assert resp.BTB_target == 0xdeadbeef
    assert resp.BTB_br_type == 0b11
    assert resp.BTB_br_mask == 0b1111

def test_NT(bp):

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b0,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    bp.commit(commit_request)

    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)
    assert type(resp) == Prediction

    assert resp.valid == 1
    assert resp.BTB_hit == 0

def test_GHR_non_branch(bp):

    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    

    bp.commit(commit_request)



    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)
    assert resp.T_NT == 1
    assert bp.get_GHR().read() == 0, "shouldnt update GHR on non-branch"

def test_GHR_non_branch(bp):

    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b00,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    

    bp.commit(commit_request)

    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)
    assert resp.T_NT == 1
    assert bp.get_GHR().read() == 1, "update GHR on branch"

def test_revert(bp):

    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b00,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    

    bp.commit(commit_request)

    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)
    resp = bp.predict(predict_request)
    resp = bp.predict(predict_request)
    assert resp.T_NT == 1
    assert bp.get_GHR().read() == 7, "update GHR on branch"

    revert_request = Revert(address=0xfacecafe, GHR=0xc0de, valid=1)

    bp.revert(revert_request)
    assert bp.get_GHR().read() == 0xc0de, "revert GHR"



def test_send_all_commit_only(bp):


    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    


    predict_request     = Predict(address = 0xdeadbeef, valid = 0)
    revert_request      = Revert(address=0xfacecafe, GHR=0xc0de, valid=0)
    RAS_update_request  = RAS_update(call=0, ret=0, call_addr = 0xdeadbeef)


    bp.send_all_requests(predict=predict_request, commit=commit_request, revert=revert_request, RAS_update=RAS_update_request)

    predict_request = Predict(address = 0xdeadbeef, valid = 1)
    resp = bp.predict(predict_request)

    assert resp.valid == 1
    assert resp.BTB_hit == 1
    assert resp.T_NT == 1
    assert resp.BTB_target == 0xdeadbeef
    assert resp.BTB_br_type == 0b11
    assert resp.BTB_br_mask == 0b1111

def test_send_all_mispredict_only(bp):


    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xbeef,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=1,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    


    predict_request     = Predict(address = 0xdeadbeef, valid = 0)
    revert_request      = Revert(address=0xfacecafe, GHR=0xc0de, valid=0)
    RAS_update_request  = RAS_update(call=0, ret=0, call_addr = 0xdeadbeef)


    resp = bp.send_all_requests(predict=predict_request, commit=commit_request, revert=revert_request, RAS_update=RAS_update_request)

    #predict_request = Predict(address = 0xdeadbeef, valid = 1)
    #resp = bp.predict(predict_request)

    assert resp.valid == 0
    assert resp.BTB_hit == 0
    assert bp.get_GHR().read() == 0xbeef, "revert GHR"


def test_send_all_mispredict_predict(bp):
    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xbeef,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=1,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    


    predict_request     = Predict(address = 0xdeadbeef, valid = 1)
    revert_request      = Revert(address=0xfacecafe, GHR=0xc0de, valid=0)
    RAS_update_request  = RAS_update(call=0, ret=0, call_addr = 0xdeadbeef)


    resp = bp.send_all_requests(predict=predict_request, commit=commit_request, revert=revert_request, RAS_update=RAS_update_request)


    assert resp.valid == 1
    assert resp.BTB_hit == 1
    assert resp.T_NT == 1
    assert resp.BTB_target == 0xdeadbeef
    assert resp.BTB_br_type == 0b11
    assert resp.BTB_br_mask == 0b1111


def test_send_all_revert_predict(bp):
    bp.PHT.set_all()    # set all PHT bits to 1

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xbeef,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    
    bp.commit(commit_request)

    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xbeef,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=0,
                             TOS=0,
                             NEXT=0,
                             valid=0
                             )

    predict_request     = Predict(address = 0xdeadbeef, valid = 1)
    revert_request      = Revert(address=0xfacecafe, GHR=0xc0de, valid=1)
    RAS_update_request  = RAS_update(call=0, ret=0, call_addr = 0xdeadbeef)

    resp = bp.send_all_requests(predict=predict_request, commit=commit_request, revert=revert_request, RAS_update=RAS_update_request)

    assert resp.valid == 1
    assert resp.BTB_hit == 1
    assert resp.T_NT == 1
    assert resp.BTB_target == 0xdeadbeef
    assert resp.BTB_br_type == 0b11
    assert resp.BTB_br_mask == 0b1111
    assert bp.get_GHR().read() == 0xc0de


def test_send_all_RAS_update_predict(bp):
    assert False


def test_send_all_mispredict_predict_revert_RAS_update(bp):
    bp.PHT.set_all()    # set all PHT bits to 1


    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xbeef,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=1,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )

    predict_request     = Predict(address = 0xdeadbeef, valid = 1)
    revert_request      = Revert(address=0xfacecafe, GHR=0xc0de, valid=1)
    RAS_update_request  = RAS_update(call=1, ret=0, call_addr = 0xdeadbeef)

    resp = bp.send_all_requests(predict=predict_request, commit=commit_request, revert=revert_request, RAS_update=RAS_update_request)

    assert resp.valid == 1
    assert resp.BTB_hit == 1
    assert resp.T_NT == 1
    assert resp.BTB_target == 0xdeadbeef
    assert resp.BTB_br_type == 0b11
    assert resp.BTB_br_mask == 0b1111
    assert bp.get_GHR().read() == 0xbeef


# FIXME: no RAS update tests

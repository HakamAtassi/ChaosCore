import pytest
from HashBTB import *

@pytest.fixture
def hashBTB():
    return HashBTB(entries=4096)


def test_miss(hashBTB):
    prediction=hashBTB.predict(address=0xdeadbeef)
    assert prediction[0] == False

def test_hit(hashBTB):
    prediction=hashBTB.predict(address=0xdeadbeef)
    assert prediction[0] == False

    #def commit(self, address, target, type, br_mask):
    prediction=hashBTB.commit(address=0xdeadbeef, target=0xdeadc0de, type=0b11, br_mask=0b0001)

    prediction=hashBTB.predict(address=0xdeadbeef)
    assert prediction[0] == True
    assert prediction[1] == 0xdeadc0de
    assert prediction[2] == 0b11
    assert prediction[3] == 0b0001

def test_hit_overwrite(hashBTB):
    prediction=hashBTB.predict(address=0xdeadbeef)
    assert prediction[0] == False

    #def commit(self, address, target, type, br_mask):
    prediction=hashBTB.commit(address=0xdeadbeef, target=0xdeadc0de, type=0b11, br_mask=0b0001)

    prediction=hashBTB.predict(address=0xdeadbeef)
    assert prediction[0] == True
    assert prediction[1] == 0xdeadc0de
    assert prediction[2] == 0b11
    assert prediction[3] == 0b0001

    prediction=hashBTB.commit(address=0xfeadbeef, target=0x0eadc0de, type=0b11, br_mask=0b0001)

    prediction=hashBTB.predict(address=0xfeadbeef)
    assert prediction[0] == True
    assert prediction[1] == 0x0eadc0de
    assert prediction[2] == 0b11
    assert prediction[3] == 0b0001


    prediction=hashBTB.predict(address=0xdeadbeef)
    assert prediction[0] == False

def test_get_address_tag(hashBTB):
    addr = 1<<16
    result_addr = hashBTB.address_to_tag(addr)

    assert result_addr == 1, "get_Addr_tag incorrect"
    


def test_get_hashed_address(hashBTB):

    address = 16

    hashed_address = hashBTB.get_hashed_address(address)
    assert hashed_address == 1
    
    prediction=hashBTB.commit(address=0x10, target=0xdeadc0de, type=0b11, br_mask=0b0001)
    prediction=hashBTB.predict(address=0x10)

    assert prediction[0] == True
    assert prediction[1] == 0xdeadc0de
    assert prediction[2] == 0b11
    assert prediction[3] == 0b0001


    assert hashBTB.target_mem[0] == 0x0
    assert hashBTB.target_mem[1] == 0xdeadc0de
    
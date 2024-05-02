import pytest
from RAS import *

@pytest.fixture
def ras():
    return RAS(entries=128)


def test0(ras):
    ras.push(addr=0xdeadbeef)
    ret_addr = ras.pop()
    assert ret_addr == 0xdeadbeef, "ret address mismatch"


def test1(ras):
    ras.push(addr=0x0)
    ras.push(addr=0x1)
    ras.push(addr=0x2)
    ras.push(addr=0x3)
    ret_addr = ras.pop()
    assert ret_addr == 0x3, "ret address mismatch"
    ret_addr = ras.pop()
    assert ret_addr == 0x2, "ret address mismatch"
    ret_addr = ras.pop()
    assert ret_addr == 0x1, "ret address mismatch"
    ret_addr = ras.pop()
    assert ret_addr == 0x0, "ret address mismatch"

def test2(ras):
    ras.push(addr=0x0)
    ras.push(addr=0x1)
    ras.push(addr=0x2)
    ras.push(addr=0x3)

    ret_addr = ras.pop()
    assert ret_addr == 0x3, "ret address mismatch"

    ras.push(addr=0x4)
    ras.push(addr=0x5)

    ret_addr = ras.pop()
    assert ret_addr == 0x5, "ret address mismatch"
    ret_addr = ras.pop()
    assert ret_addr == 0x4, "ret address mismatch"
    ret_addr = ras.pop()
    assert ret_addr == 0x2, "ret address mismatch"

    ret_addr = ras.pop()
    assert ret_addr == 0x1, "ret address mismatch"

    ret_addr = ras.pop()
    assert ret_addr == 0x0, "ret address mismatch"

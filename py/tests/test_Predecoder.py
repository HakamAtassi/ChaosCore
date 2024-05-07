import pytest
from Channels import *
from Predecoder import *
from model_utils import *


@pytest.fixture
def predecoder():
    return Predecoder(start_address=0x8000_0000)

def test_all_add(predecoder):
    i0=Instruction(fuzz('I'), 0x0)
    i1=Instruction(fuzz('I'), 0x0)
    i2=Instruction(fuzz('I'), 0x0)
    i3=Instruction(fuzz('I'), 0x0)


    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    null_prediction  = Prediction.null()
    null_RAS_read  = RAS_read.null()

    predecoder.validate(i_packet, null_RAS_read, null_prediction)

    assert predecoder.expected_address ==  0x8000_0010
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1


def test_all_add_jal(predecoder):
    i0=Instruction(fuzz('I'), 0x0)
    i1=Instruction(fuzz('I'), 0x4)
    i2=Instruction(fuzz('I'), 0x8)
    i3=Instruction(fuzz('J'), 0xC)

    imm = i3.imm

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    null_prediction  = Prediction.null()
    null_RAS_read  = RAS_read.null()

    predecoder.validate(i_packet, null_RAS_read, null_prediction)

    assert predecoder.expected_address ==  0x0000_000C + imm
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1
import pytest
from Channels import *
from Predecoder import *
from model_utils import *

@pytest.fixture
def predecoder():
    return Predecoder(start_address=0x8000_0000)

def test_all_add(predecoder):
    i0=Instruction(fuzz('I'), 0x0, 0)
    i1=Instruction(fuzz('I'), 0x0, 1)
    i2=Instruction(fuzz('I'), 0x0, 2)
    i3=Instruction(fuzz('I'), 0x0, 3)


    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    null_prediction  = Prediction.null()
    null_RAS_read  = RAS_read.null()

    predecoder.validate(i_packet, null_RAS_read, null_prediction)

    assert predecoder.expected_address ==  0x8000_0010
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1

def test_all_add_jal(predecoder):
    i0=Instruction(fuzz('I'), 0, 0x0,)
    i1=Instruction(fuzz('I'), 1, 0x4,)
    i2=Instruction(fuzz('I'), 2, 0x8,)
    i3=Instruction(fuzz('J'), 3, 0xC,)

    imm = i3.imm

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    null_prediction  = Prediction.null()
    null_RAS_read  = RAS_read.null()

    predecoder.validate(i_packet, null_RAS_read, null_prediction)

    assert predecoder.expected_address ==  0x0000_000C + imm
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1

def test_all_add_call(predecoder):

    i0=Instruction(fuzz('I'),        0, 0x0)
    i1=Instruction(fuzz('I'),        1, 0x4)
    i2=Instruction(fuzz('I'),        2, 0x8)
    i3=Instruction(generate_call(),  3, 0xC)

    imm = i3.imm

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    null_prediction  = Prediction.null()
    null_RAS_read  = RAS_read.null()

    predecoder.validate(i_packet, null_RAS_read, null_prediction)

    assert predecoder.expected_address ==  0x0000_000C + imm
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1

def test_all_add_ret(predecoder):

    i0=Instruction(fuzz('I'),      0, 0x0,)
    i1=Instruction(fuzz('I'),      1, 0x4,)
    i2=Instruction(fuzz('I'),      2, 0x8,)
    i3=Instruction(generate_ret(), 3, 0xC,)

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    null_prediction  = Prediction.null()
    null_RAS_read  = RAS_read(0xdeadbeef, 0, 1, 1)

    RAS_update, revert =predecoder.validate(i_packet, null_RAS_read, null_prediction)

    assert predecoder.expected_address ==  0xdeadbeef 
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1

    assert RAS_update.ret == 1

def test_all_add_branch(predecoder):

    i0=Instruction(fuzz('I'), 0, 0x0)
    i1=Instruction(fuzz('I'), 1, 0x4)
    i2=Instruction(fuzz('I'), 2, 0x8)
    i3=Instruction(fuzz('B'), 3, 0xC)

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    prediction  = Prediction(BTB_resp(1,0xdeadc0de,0,0b0001,1),1,0,1)
    null_RAS_read  = RAS_read.null()

    RAS_update, revert = predecoder.validate(i_packet, null_RAS_read, prediction)

    assert hex(predecoder.expected_address) ==  hex(0xdeadc0de)
    assert i_packet.valid == 1
    for i in i_packet.instructions:
        assert i.valid == 1

def test_invalidate(predecoder):

    i0=Instruction(fuzz('I'), 0, 0x0)
    i1=Instruction(fuzz('J'), 1, 0x4)
    i2=Instruction(fuzz('I'), 2, 0x8)
    i3=Instruction(fuzz('B'), 3, 0xC)

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    prediction  = Prediction(BTB_resp(1,0xdeadc0de,0,0b0001,1),1,0,1)
    null_RAS_read  = RAS_read.null()

    RAS_update, revert = predecoder.validate(i_packet, null_RAS_read, prediction)

    assert hex(predecoder.expected_address) ==  hex(i1.imm + 0x4)

    i_packet.instructions[0].valid == 1
    i_packet.instructions[1].valid == 1
    i_packet.instructions[2].valid == 0
    i_packet.instructions[3].valid == 0


def test_branch_invalidate(predecoder):

    i0=Instruction(fuzz('I'), 0, 0x0)
    i1=Instruction(fuzz('B'), 1, 0x4)
    i2=Instruction(fuzz('I'), 2, 0x8)
    i3=Instruction(fuzz('J'), 3, 0xC)

    i_packet=fetch_packet([i0, i1, i2, i3], 1, 0x8000_0000, fetch_width=4)

    prediction  = Prediction(BTB_resp(1,0xdeadc0de,0,0b0100,1),1,0,1)
    null_RAS_read  = RAS_read.null()
    
    RAS_update, revert = predecoder.validate(i_packet, null_RAS_read, prediction)

    assert hex(predecoder.expected_address) ==  hex(0xdeadc0de)

    i_packet.instructions[0].valid == 1
    i_packet.instructions[1].valid == 1
    i_packet.instructions[2].valid == 0
    i_packet.instructions[3].valid == 0

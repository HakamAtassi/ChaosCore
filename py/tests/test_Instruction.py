import pytest
from Instruction import *
from model_utils import *

def test_fuzz():
    assert fuzz(), "cant fuzz for some reason"

def test_construct():
    instr = fuzz()
    test_instr = Instruction(instr, 0x8000_0000)
    assert test_instr.valid == 1, "instr not valid"

def test_call():
    instr = generate_call()
    test_instr = Instruction(instr, 0x8000_0000)
    assert test_instr.valid == 1, "instr not valid"
    assert test_instr.opcode == 0b1101111
    assert test_instr.is_call == 1, "instr should be call"

def test_ret():
    instr = generate_ret()
    test_instr = Instruction(instr, 0x8000_0000)
    assert test_instr.valid == 1, "instr not valid"
    assert test_instr.opcode == 0b1100111, f"{bin(test_instr.opcode)} != {0b1100111}"
    assert test_instr.rs1 == 1
    assert test_instr.rd == 0
    assert test_instr.imm == 0
    assert test_instr.is_ret == 1, "instr should be ret"
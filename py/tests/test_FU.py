import pytest
from FU import *


def test_BEQ():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0b000
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01001011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b11010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BEQ"
    assert FU_outputs["branch_taken"] == 0

def test_BNE():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0b001
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01001011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b11010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BNE"
    assert FU_outputs["branch_taken"] == 1

def test_BLT_signed():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0x4
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01001011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b11010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BLT"
    assert FU_outputs["branch_taken"] == 0

def test_BLT():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0x4
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01001011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b01010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BLT"
    assert FU_outputs["branch_taken"] == 1

def test_BLT_signed_2():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0x4
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01001011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b11010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BLT"
    assert FU_outputs["branch_taken"] == 0

def test_BGE():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0x5
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01001011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b01010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BGE"
    assert FU_outputs["branch_taken"] == 0


def test_BGE_2():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0x5
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01101011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b01010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BGE"
    assert FU_outputs["branch_taken"] == 1

def test_BGE_signed():
    FU_inputs  = generate_null_FU_inputs()

    FU_inputs["valid"]              = 1
    FU_inputs["RS1_ready"]          = 1
    FU_inputs["RS2_ready"]          = 1
    FU_inputs["RD"]                 = 0b000000
    FU_inputs["RD_valid"]           = 0
    FU_inputs["RS1"]                = 0b001001
    FU_inputs["RS1_valid"]          = 1
    FU_inputs["RS2"]                = 0b100111
    FU_inputs["RS2_valid"]          = 1
    FU_inputs["IMM"]                = 0b00000000000000000000
    FU_inputs["FUNCT3"]             = 0x5
    FU_inputs["packet_index"]       = 0b0001
    FU_inputs["ROB_index"]          = 0b111001
    FU_inputs["instructionType"]    = 0b11000
    FU_inputs["portID"]             = 0
    FU_inputs["RS_type"]            = 0
    FU_inputs["needs_ALU"]          = 0
    FU_inputs["needs_branch_unit"]  = 1
    FU_inputs["needs_CSRs"]         = 0
    FU_inputs["SUBTRACT"]           = 0
    FU_inputs["MULTIPLY"]           = 0
    FU_inputs["IMMEDIATE"]          = 0
    FU_inputs["is_load"]            = 0
    FU_inputs["is_store"]           = 0
    FU_inputs["RS1_data"]           = 0b01101011010001100100100010101000
    FU_inputs["RS2_data"]           = 0b11010111111010111011010011100100
    FU_inputs["PC"]                 = 0b00101111001010011011110110100101

    _FU_model = FU_model()
    _FU_model.write_FU_input(FU_inputs=FU_inputs)
    FU_outputs = _FU_model.read_FU_output()

    assert _FU_model.get_operation() == "BGE"
    assert FU_outputs["branch_taken"] == 1









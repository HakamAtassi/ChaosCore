import pytest
import ROB
from ROB.signals import *
import random

def test_1_write():
    ROB_model = ROB.ROB_model()

    random_ROB_packet = generate_null_allocate()


    random_ROB_packet["valid"]                        =  1
    random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF)
    random_ROB_packet["RS1_ready"]                    =  [0]*4
    random_ROB_packet["RS2_ready"]                    =  [0]*4
    random_ROB_packet["RD"]                           =  [0]*4
    random_ROB_packet["RD_valid"]                     =  [0]*4
    random_ROB_packet["RS1"]                          =  [0]*4
    random_ROB_packet["RS1_valid"]                    =  [0]*4
    random_ROB_packet["RS2"]                          =  [0]*4
    random_ROB_packet["RS2_valid"]                    =  [0]*4
    random_ROB_packet["IMM"]                          =  [0]*4
    random_ROB_packet["FUNCT3"]                       =  [0]*4
    random_ROB_packet["packet_index"]                 =  [0]*4
    random_ROB_packet["ROB_index"]                    =  [0]*4
    random_ROB_packet["instructionType"]              =  [0]*4
    random_ROB_packet["portID"]                       =  [0]*4
    random_ROB_packet["RS_type"]                      =  [0]*4
    random_ROB_packet["needs_ALU"]                    =  [0]*4
    random_ROB_packet["needs_branch_unit"]            =  [0]*4
    random_ROB_packet["needs_CSRs"]                   =  [0]*4
    random_ROB_packet["SUBTRACT"]                     =  [0]*4
    random_ROB_packet["MULTIPLY"]                     =  [0]*4
    random_ROB_packet["IMMEDIATE"]                    =  [0]*4
    random_ROB_packet["is_branch"]                    =  [0]*4
    random_ROB_packet["is_load"]                      =  [0]*4
    random_ROB_packet["is_store"]                     =  [0]*4
    random_ROB_packet["valid_bits"]                   = [random.randint(0, 1) for _ in range(4)]


    ROB_model.write_ROB_packet(random_ROB_packet)

    assert ROB_model.shared_mem["fetch_PC"][0] == random_ROB_packet["fetch_PC"]
    assert ROB_model.shared_mem["row_valid"][0] == 1

def test_many_writes():
    ROB_model = ROB.ROB_model()

    random_ROB_packet = generate_null_allocate()


    random_ROB_packet["valid"]                        =  1
    random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF)
    random_ROB_packet["RS1_ready"]                    =  [0]*4
    random_ROB_packet["RS2_ready"]                    =  [0]*4
    random_ROB_packet["RD"]                           =  [0]*4
    random_ROB_packet["RD_valid"]                     =  [0]*4
    random_ROB_packet["RS1"]                          =  [0]*4
    random_ROB_packet["RS1_valid"]                    =  [0]*4
    random_ROB_packet["RS2"]                          =  [0]*4
    random_ROB_packet["RS2_valid"]                    =  [0]*4
    random_ROB_packet["IMM"]                          =  [0]*4
    random_ROB_packet["FUNCT3"]                       =  [0]*4
    random_ROB_packet["packet_index"]                 =  [0]*4
    random_ROB_packet["ROB_index"]                    =  [0]*4
    random_ROB_packet["instructionType"]              =  [0]*4
    random_ROB_packet["portID"]                       =  [0]*4
    random_ROB_packet["RS_type"]                      =  [0]*4
    random_ROB_packet["needs_ALU"]                    =  [0]*4
    random_ROB_packet["needs_branch_unit"]            =  [0]*4
    random_ROB_packet["needs_CSRs"]                   =  [0]*4
    random_ROB_packet["SUBTRACT"]                     =  [0]*4
    random_ROB_packet["MULTIPLY"]                     =  [0]*4
    random_ROB_packet["IMMEDIATE"]                    =  [0]*4
    random_ROB_packet["is_branch"]                    =  [0]*4
    random_ROB_packet["is_load"]                      =  [0]*4
    random_ROB_packet["is_store"]                     =  [0]*4
    random_ROB_packet["valid_bits"]                   = [random.randint(0, 1) for _ in range(4)]


    assert ROB_model.is_full() == 0


    for i in range(64):
        random_ROB_packet["valid"]                        =  1
        random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF)
        random_ROB_packet["RS1_ready"]                    =  [0]*4
        random_ROB_packet["RS2_ready"]                    =  [0]*4
        random_ROB_packet["RD"]                           =  [0]*4
        random_ROB_packet["RD_valid"]                     =  [0]*4
        random_ROB_packet["RS1"]                          =  [0]*4
        random_ROB_packet["RS1_valid"]                    =  [0]*4
        random_ROB_packet["RS2"]                          =  [0]*4
        random_ROB_packet["RS2_valid"]                    =  [0]*4
        random_ROB_packet["IMM"]                          =  [0]*4
        random_ROB_packet["FUNCT3"]                       =  [0]*4
        random_ROB_packet["packet_index"]                 =  [0]*4
        random_ROB_packet["ROB_index"]                    =  [0]*4
        random_ROB_packet["instructionType"]              =  [0]*4
        random_ROB_packet["portID"]                       =  [0]*4
        random_ROB_packet["RS_type"]                      =  [0]*4
        random_ROB_packet["needs_ALU"]                    =  [0]*4
        random_ROB_packet["needs_branch_unit"]            =  [0]*4
        random_ROB_packet["needs_CSRs"]                   =  [0]*4
        random_ROB_packet["SUBTRACT"]                     =  [0]*4
        random_ROB_packet["MULTIPLY"]                     =  [0]*4
        random_ROB_packet["IMMEDIATE"]                    =  [0]*4
        random_ROB_packet["is_branch"]                    =  [0]*4
        random_ROB_packet["is_load"]                      =  [0]*4
        random_ROB_packet["is_store"]                     =  [0]*4
        random_ROB_packet["valid_bits"]                   = [random.randint(0, 1) for _ in range(4)]

        ROB_model.write_ROB_packet(random_ROB_packet)

        print(ROB_model.shared_mem)

        assert ROB_model.shared_mem["fetch_PC"][i] == random_ROB_packet["fetch_PC"]
        assert ROB_model.shared_mem["row_valid"][i] == 1


    assert ROB_model.front_pointer == 0 
    assert ROB_model.back_pointer == 0 
    assert ROB_model.is_full() == 1

def test_writes_over_capacity():
    ROB_model = ROB.ROB_model()

    random_ROB_packet = generate_null_allocate()


    random_ROB_packet["valid"]                        =  1
    random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF)
    random_ROB_packet["RS1_ready"]                    =  [0]*4
    random_ROB_packet["RS2_ready"]                    =  [0]*4
    random_ROB_packet["RD"]                           =  [0]*4
    random_ROB_packet["RD_valid"]                     =  [0]*4
    random_ROB_packet["RS1"]                          =  [0]*4
    random_ROB_packet["RS1_valid"]                    =  [0]*4
    random_ROB_packet["RS2"]                          =  [0]*4
    random_ROB_packet["RS2_valid"]                    =  [0]*4
    random_ROB_packet["IMM"]                          =  [0]*4
    random_ROB_packet["FUNCT3"]                       =  [0]*4
    random_ROB_packet["packet_index"]                 =  [0]*4
    random_ROB_packet["ROB_index"]                    =  [0]*4
    random_ROB_packet["instructionType"]              =  [0]*4
    random_ROB_packet["portID"]                       =  [0]*4
    random_ROB_packet["RS_type"]                      =  [0]*4
    random_ROB_packet["needs_ALU"]                    =  [0]*4
    random_ROB_packet["needs_branch_unit"]            =  [0]*4
    random_ROB_packet["needs_CSRs"]                   =  [0]*4
    random_ROB_packet["SUBTRACT"]                     =  [0]*4
    random_ROB_packet["MULTIPLY"]                     =  [0]*4
    random_ROB_packet["IMMEDIATE"]                    =  [0]*4
    random_ROB_packet["is_branch"]                    =  [0]*4
    random_ROB_packet["is_load"]                      =  [0]*4
    random_ROB_packet["is_store"]                     =  [0]*4
    random_ROB_packet["valid_bits"]                   = [random.randint(0, 1) for _ in range(4)]


    assert ROB_model.is_full() == 0


    for i in range(64):
        random_ROB_packet["valid"]                        =  1
        random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF)
        random_ROB_packet["RS1_ready"]                    =  [0]*4
        random_ROB_packet["RS2_ready"]                    =  [0]*4
        random_ROB_packet["RD"]                           =  [0]*4
        random_ROB_packet["RD_valid"]                     =  [0]*4
        random_ROB_packet["RS1"]                          =  [0]*4
        random_ROB_packet["RS1_valid"]                    =  [0]*4
        random_ROB_packet["RS2"]                          =  [0]*4
        random_ROB_packet["RS2_valid"]                    =  [0]*4
        random_ROB_packet["IMM"]                          =  [0]*4
        random_ROB_packet["FUNCT3"]                       =  [0]*4
        random_ROB_packet["packet_index"]                 =  [0]*4
        random_ROB_packet["ROB_index"]                    =  [0]*4
        random_ROB_packet["instructionType"]              =  [0]*4
        random_ROB_packet["portID"]                       =  [0]*4
        random_ROB_packet["RS_type"]                      =  [0]*4
        random_ROB_packet["needs_ALU"]                    =  [0]*4
        random_ROB_packet["needs_branch_unit"]            =  [0]*4
        random_ROB_packet["needs_CSRs"]                   =  [0]*4
        random_ROB_packet["SUBTRACT"]                     =  [0]*4
        random_ROB_packet["MULTIPLY"]                     =  [0]*4
        random_ROB_packet["IMMEDIATE"]                    =  [0]*4
        random_ROB_packet["is_branch"]                    =  [0]*4
        random_ROB_packet["is_load"]                      =  [0]*4
        random_ROB_packet["is_store"]                     =  [0]*4
        random_ROB_packet["valid_bits"]                   = [random.randint(0, 1) for _ in range(4)]


        ROB_model.write_ROB_packet(random_ROB_packet)

        assert ROB_model.shared_mem["fetch_PC"][i] == random_ROB_packet["fetch_PC"]
        assert ROB_model.shared_mem["row_valid"][i] == 1



    for i in range(64):
        random_ROB_packet["valid"]                        =  1
        random_ROB_packet["fetch_PC"]                     =  0xdeadbeef
        random_ROB_packet["RS1_ready"]                    =  [0]*4
        random_ROB_packet["RS2_ready"]                    =  [0]*4
        random_ROB_packet["RD"]                           =  [0]*4
        random_ROB_packet["RD_valid"]                     =  [0]*4
        random_ROB_packet["RS1"]                          =  [0]*4
        random_ROB_packet["RS1_valid"]                    =  [0]*4
        random_ROB_packet["RS2"]                          =  [0]*4
        random_ROB_packet["RS2_valid"]                    =  [0]*4
        random_ROB_packet["IMM"]                          =  [0]*4
        random_ROB_packet["FUNCT3"]                       =  [0]*4
        random_ROB_packet["packet_index"]                 =  [0]*4
        random_ROB_packet["ROB_index"]                    =  [0]*4
        random_ROB_packet["instructionType"]              =  [0]*4
        random_ROB_packet["portID"]                       =  [0]*4
        random_ROB_packet["RS_type"]                      =  [0]*4
        random_ROB_packet["needs_ALU"]                    =  [0]*4
        random_ROB_packet["needs_branch_unit"]            =  [0]*4
        random_ROB_packet["needs_CSRs"]                   =  [0]*4
        random_ROB_packet["SUBTRACT"]                     =  [0]*4
        random_ROB_packet["MULTIPLY"]                     =  [0]*4
        random_ROB_packet["IMMEDIATE"]                    =  [0]*4
        random_ROB_packet["is_branch"]                    =  [0]*4
        random_ROB_packet["is_load"]                      =  [0]*4
        random_ROB_packet["is_store"]                     =  [0]*4
        random_ROB_packet["valid_bits"]                   = [random.randint(0, 1) for _ in range(4)]

        assert ROB_model.shared_mem["fetch_PC"][i] != random_ROB_packet["fetch_PC"]


        ROB_model.write_ROB_packet(random_ROB_packet)

    assert ROB_model.is_full() == 1




def test_WB_mem():
    ROB_model = ROB.ROB_model()

    random_ROB_packet = generate_null_allocate()


    random_ROB_packet["valid"]                        =  1
    random_ROB_packet["fetch_PC"]                     =  0xdeadbeef
    random_ROB_packet["RS1_ready"]                    =  [0]*4
    random_ROB_packet["RS2_ready"]                    =  [0]*4
    random_ROB_packet["RD"]                           =  [0]*4
    random_ROB_packet["RD_valid"]                     =  [0]*4
    random_ROB_packet["RS1"]                          =  [0]*4
    random_ROB_packet["RS1_valid"]                    =  [0]*4
    random_ROB_packet["RS2"]                          =  [0]*4
    random_ROB_packet["RS2_valid"]                    =  [0]*4
    random_ROB_packet["IMM"]                          =  [0]*4
    random_ROB_packet["FUNCT3"]                       =  [0]*4
    random_ROB_packet["packet_index"]                 =  [0]*4
    random_ROB_packet["ROB_index"]                    =  [0]*4
    random_ROB_packet["instructionType"]              =  [0]*4
    random_ROB_packet["portID"]                       =  [0]*4
    random_ROB_packet["RS_type"]                      =  [0]*4
    random_ROB_packet["needs_ALU"]                    =  [0]*4
    random_ROB_packet["needs_branch_unit"]            =  [0]*4
    random_ROB_packet["needs_CSRs"]                   =  [0]*4
    random_ROB_packet["SUBTRACT"]                     =  [0]*4
    random_ROB_packet["MULTIPLY"]                     =  [0]*4
    random_ROB_packet["IMMEDIATE"]                    =  [0]*4
    random_ROB_packet["is_branch"]                    =  [0]*4
    random_ROB_packet["is_load"]                      =  [0]*4
    random_ROB_packet["is_store"]                     =  [0]*4
    random_ROB_packet["valid_bits"]                   =  [0]*4

    ROB_model.write_ROB_packet(random_ROB_packet)

    assert ROB_model.shared_mem["fetch_PC"][0] == random_ROB_packet["fetch_PC"]
    assert ROB_model.shared_mem["row_valid"][0] == 1

    FU_inputs = {}
    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 0


    ROB_model.write_FU_outputs(0, FU_inputs)

    assert ROB_model.WB_mem[0]["busy"][0] == 1
    assert ROB_model.WB_mem[0]["busy"][1] == 0
    assert ROB_model.WB_mem[0]["busy"][2] == 0
    assert ROB_model.WB_mem[0]["busy"][3] == 0

    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 1

    ROB_model.write_FU_outputs(0, FU_inputs)

    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 2

    ROB_model.write_FU_outputs(0, FU_inputs)


    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 3

    ROB_model.write_FU_outputs(0, FU_inputs)

    assert ROB_model.WB_mem[0]["busy"][0] == 1
    assert ROB_model.WB_mem[1]["busy"][0] == 1
    assert ROB_model.WB_mem[2]["busy"][0] == 1
    assert ROB_model.WB_mem[3]["busy"][0] == 1



def test_WB_mem_after_full():
    ROB_model = ROB.ROB_model()

    random_ROB_packet = generate_null_allocate()

    for _ in range(64):
        random_ROB_packet["valid"]                        =  1
        random_ROB_packet["fetch_PC"]                     =  0xdeadbeef
        random_ROB_packet["RS1_ready"]                    =  [0]*4
        random_ROB_packet["RS2_ready"]                    =  [0]*4
        random_ROB_packet["RD"]                           =  [0]*4
        random_ROB_packet["RD_valid"]                     =  [0]*4
        random_ROB_packet["RS1"]                          =  [0]*4
        random_ROB_packet["RS1_valid"]                    =  [0]*4
        random_ROB_packet["RS2"]                          =  [0]*4
        random_ROB_packet["RS2_valid"]                    =  [0]*4
        random_ROB_packet["IMM"]                          =  [0]*4
        random_ROB_packet["FUNCT3"]                       =  [0]*4
        random_ROB_packet["packet_index"]                 =  [0]*4
        random_ROB_packet["ROB_index"]                    =  [0]*4
        random_ROB_packet["instructionType"]              =  [0]*4
        random_ROB_packet["portID"]                       =  [0]*4
        random_ROB_packet["RS_type"]                      =  [0]*4
        random_ROB_packet["needs_ALU"]                    =  [0]*4
        random_ROB_packet["needs_branch_unit"]            =  [0]*4
        random_ROB_packet["needs_CSRs"]                   =  [0]*4
        random_ROB_packet["SUBTRACT"]                     =  [0]*4
        random_ROB_packet["MULTIPLY"]                     =  [0]*4
        random_ROB_packet["IMMEDIATE"]                    =  [0]*4
        random_ROB_packet["is_branch"]                    =  [0]*4
        random_ROB_packet["is_load"]                      =  [0]*4
        random_ROB_packet["is_store"]                     =  [0]*4
        random_ROB_packet["valid_bits"]                   =  [1,1,1,1]

        ROB_model.write_ROB_packet(random_ROB_packet)

        assert ROB_model.shared_mem["fetch_PC"][0] == random_ROB_packet["fetch_PC"]
        assert ROB_model.shared_mem["row_valid"][0] == 1

    FU_inputs = {}
    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 0


    ROB_model.write_FU_outputs(0, FU_inputs)

    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 1

    ROB_model.write_FU_outputs(0, FU_inputs)

    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 2

    ROB_model.write_FU_outputs(0, FU_inputs)


    FU_inputs["valid"]              = 1
    FU_inputs["RD"]                 = 0
    FU_inputs["RD_data"]            = 0
    FU_inputs["RD_valid"]           = 0
    FU_inputs["instruction_PC"]     = 0
    FU_inputs["branch_taken"]       = 0
    FU_inputs["target_address"]     = 0
    FU_inputs["branch_valid"]       = 0
    FU_inputs["ROB_index"]          = 0
    FU_inputs["fetch_packet_index"] = 3

    ROB_model.write_FU_outputs(0, FU_inputs)

    assert ROB_model.WB_mem[0]["busy"][0] == 1
    assert ROB_model.WB_mem[1]["busy"][0] == 1
    assert ROB_model.WB_mem[2]["busy"][0] == 1
    assert ROB_model.WB_mem[3]["busy"][0] == 1

    ROB_model.read_ROB_output()

    assert ROB_model.is_full() == 0

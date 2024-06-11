from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/FU.v") # Target simulation file (Update me!)

module = "FU"  # Update me!

configs = {
    "simulator": "verilator",
    "verilog_sources": [verilog_file_path],
    "module": f"{module}_cocotb",
    "defines": ["-j12"],
    "toplevel": f"{module}",                                  # top level HDL (Update me!)
    "testcase": None,                                         # This is populated by import_tests.py
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND"],
    # ONLY ENABLE DURING DEBUG
    "waves": 1,                                         # Add waves (1/2)
    "extra_args": ["--trace-fst", "--trace-structs"]    # Add waves (2/2)
    # Waves are in sim_build/dump.fst

}

# DO NOT MODIFY ANYTHING INCLUDING AND AFTER THIS LINE #

def test_reset():
        configs["testcase"] = "test_reset"
        run(**configs)

def test_addi():
        configs["testcase"] = "test_addi"
        run(**configs)

def test_xori():
        configs["testcase"] = "test_xori"
        run(**configs)

def test_andi():
        configs["testcase"] = "test_andi"
        run(**configs)

def test_ori():
        configs["testcase"] = "test_ori"
        run(**configs)

def test_slli():
        configs["testcase"] = "test_slli"
        run(**configs)

def test_srli():
        configs["testcase"] = "test_srli"
        run(**configs)

def test_srai():
        configs["testcase"] = "test_srai"
        run(**configs)

def test_srai_signed():
        configs["testcase"] = "test_srai_signed"
        run(**configs)

def test_slti_t():
        configs["testcase"] = "test_slti_t"
        run(**configs)

def test_slti_f():
        configs["testcase"] = "test_slti_f"
        run(**configs)

def test_slti_t_signed():
        configs["testcase"] = "test_slti_t_signed"
        run(**configs)

def test_slti_f_signed():
        configs["testcase"] = "test_slti_f_signed"
        run(**configs)

def test_add():
        configs["testcase"] = "test_add"
        run(**configs)

def test_sub_pos():
        configs["testcase"] = "test_sub_pos"
        run(**configs)

def test_sub_neg():
        configs["testcase"] = "test_sub_neg"
        run(**configs)

def test_xor():
        configs["testcase"] = "test_xor"
        run(**configs)

def test_and():
        configs["testcase"] = "test_and"
        run(**configs)

def test_or():
        configs["testcase"] = "test_or"
        run(**configs)

def test_sll():
        configs["testcase"] = "test_sll"
        run(**configs)

def test_srl():
        configs["testcase"] = "test_srl"
        run(**configs)

def test_sra():
        configs["testcase"] = "test_sra"
        run(**configs)

def test_sra_signed():
        configs["testcase"] = "test_sra_signed"
        run(**configs)

def test_slt_t():
        configs["testcase"] = "test_slt_t"
        run(**configs)

def test_slt_f():
        configs["testcase"] = "test_slt_f"
        run(**configs)

def test_slt_t_signed():
        configs["testcase"] = "test_slt_t_signed"
        run(**configs)

def test_slt_f_signed():
        configs["testcase"] = "test_slt_f_signed"
        run(**configs)

def test_beq_t():
        configs["testcase"] = "test_beq_t"
        run(**configs)

def test_beq_nt():
        configs["testcase"] = "test_beq_nt"
        run(**configs)

def test_bne_t():
        configs["testcase"] = "test_bne_t"
        run(**configs)

def test_bne_nt():
        configs["testcase"] = "test_bne_nt"
        run(**configs)

def test_blt_t():
        configs["testcase"] = "test_blt_t"
        run(**configs)

def test_blt_nt():
        configs["testcase"] = "test_blt_nt"
        run(**configs)

def test_bge_t():
        configs["testcase"] = "test_bge_t"
        run(**configs)

def test_bge_nt():
        configs["testcase"] = "test_bge_nt"
        run(**configs)


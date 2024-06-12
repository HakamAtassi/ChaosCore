from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/ROB.v") # Target simulation file (Update me!)

module = "ROB"  # Update me!

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

def test_print_ROB():
        configs["testcase"] = "test_print_ROB"
        run(**configs)

def test_write_1():
        configs["testcase"] = "test_write_1"
        run(**configs)

def test_write_4():
        configs["testcase"] = "test_write_4"
        run(**configs)

def test_many_writes():
        configs["testcase"] = "test_many_writes"
        run(**configs)

def test_many_full():
        configs["testcase"] = "test_many_full"
        run(**configs)

def test_FU_all_valid():
        configs["testcase"] = "test_FU_all_valid"
        run(**configs)

def test_FU_not_all_valid():
        configs["testcase"] = "test_FU_not_all_valid"
        run(**configs)

def test_FU_all_valid_diff_rows():
        configs["testcase"] = "test_FU_all_valid_diff_rows"
        run(**configs)

def test_FU_all_valid_single_bank():
        configs["testcase"] = "test_FU_all_valid_single_bank"
        run(**configs)

def test_basic_commit():
        configs["testcase"] = "test_basic_commit"
        run(**configs)

def test_allocate_rob_index():
        configs["testcase"] = "test_allocate_rob_index"
        run(**configs)

def test_commit_rob_index():
        configs["testcase"] = "test_commit_rob_index"
        run(**configs)

def test_WB_port_B():
        configs["testcase"] = "test_WB_port_B"
        run(**configs)


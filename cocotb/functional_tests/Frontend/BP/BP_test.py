from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Frontend/BP/BP.v") # Target simulation file (Update me!)

module = "BP"  # Update me!

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

def test_BTB_write():
        configs["testcase"] = "test_BTB_write"
        run(**configs)

def test_BTB_overwrite():
        configs["testcase"] = "test_BTB_overwrite"
        run(**configs)

def test_BTB_indexing():
        configs["testcase"] = "test_BTB_indexing"
        run(**configs)

def test_BTB_indexing_2():
        configs["testcase"] = "test_BTB_indexing_2"
        run(**configs)

def test_BTB_indexing_4():
        configs["testcase"] = "test_BTB_indexing_4"
        run(**configs)

def test_BTB_non_branch():
        configs["testcase"] = "test_BTB_non_branch"
        run(**configs)

def test_BTB_NT():
        configs["testcase"] = "test_BTB_NT"
        run(**configs)

def test_1_PHT_write():
        configs["testcase"] = "test_1_PHT_write"
        run(**configs)

def test_2_PHT_write():
        configs["testcase"] = "test_2_PHT_write"
        run(**configs)

def test_3_PHT_write():
        configs["testcase"] = "test_3_PHT_write"
        run(**configs)

def test_PHT_up_down():
        configs["testcase"] = "test_PHT_up_down"
        run(**configs)

def test_RAS():
        configs["testcase"] = "test_RAS"
        run(**configs)

def test_RAS_call():
        configs["testcase"] = "test_RAS_call"
        run(**configs)

def test_RAS_call_ret():
        configs["testcase"] = "test_RAS_call_ret"
        run(**configs)


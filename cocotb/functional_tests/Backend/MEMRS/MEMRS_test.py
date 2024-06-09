from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/MEMRS.v") # Target simulation file (Update me!)

module = "MEMRS"  # Update me!

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

def test_print_MEMRS():
        configs["testcase"] = "test_print_MEMRS"
        run(**configs)

def test_write_1():
        configs["testcase"] = "test_write_1"
        run(**configs)

def test_write_many():
        configs["testcase"] = "test_write_many"
        run(**configs)

def test_full():
        configs["testcase"] = "test_full"
        run(**configs)

def test_full_but_1():
        configs["testcase"] = "test_full_but_1"
        run(**configs)

def test_full_but_2():
        configs["testcase"] = "test_full_but_2"
        run(**configs)

def test_full_but_3():
        configs["testcase"] = "test_full_but_3"
        run(**configs)

def test_full_but_4():
        configs["testcase"] = "test_full_but_4"
        run(**configs)

def test_write_1_FU_complete():
        configs["testcase"] = "test_write_1_FU_complete"
        run(**configs)

def test_good_to_go():
        configs["testcase"] = "test_good_to_go"
        run(**configs)

def test_good_to_go_backed_up():
        configs["testcase"] = "test_good_to_go_backed_up"
        run(**configs)


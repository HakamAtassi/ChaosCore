from cocotb_test.simulator import run
import os
import glob

# include everything in hw/verilog
current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_dir = os.path.join(current_file_dir, "../../../hw/verilog")

# Get a list of all .sv files in the hw/verilog directory
sv_files = glob.glob(os.path.join(verilog_dir, "*.sv"))
v_files = glob.glob(os.path.join(verilog_dir, "*.v"))
verilog_files = sv_files + v_files

module = "SOC"  # Update me!

configs = {
    "simulator": "verilator",
    "verilog_sources": verilog_files,
    "module": f"{module}_cocotb",
    "defines": ["-j16"],
    "toplevel": f"{module}",                                  # top level HDL (Update me!)
    "testcase": None,                                         # This is populated by import_tests.py
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND", "-Wno-PINMISSING", "-Wno-SYMRSVDWORD", "-Wno-TIMESCALEMOD"],
    # ONLY ENABLE DURING DEBUG
    "waves": 1,                                         # Add waves (1/2)
    "extra_args": ["--trace-fst", "--trace-structs"]    # Add waves (2/2)
    # Waves are in sim_build/dump.fst
}

# DO NOT MODIFY ANYTHING INCLUDING AND AFTER THIS LINE #

def test_addi():
        configs["testcase"] = "test_addi"
        run(**configs)

def test_xori():
        configs["testcase"] = "test_xori"
        run(**configs)


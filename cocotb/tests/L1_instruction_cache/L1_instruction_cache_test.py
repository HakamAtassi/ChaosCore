from cocotb_test.simulator import run
import os
import glob

current_file_dir = os.path.dirname(os.path.abspath(__file__))
L1_instruction_cache_path = os.path.join(current_file_dir, "../../../hw/verilog/L1_instruction_cache.sv") # Target simulation file (Update me!)

# include everything in hw/verilog
verilog_dir = os.path.join(current_file_dir, "../../../hw/verilog")

# Get a list of all .sv files in the hw/verilog directory
verilog_files = glob.glob(os.path.join(verilog_dir, "*.sv"))

module = "L1_instruction_cache"  # Update me!

configs = {
    "simulator": "verilator",
    "verilog_sources": verilog_files,
    "module": f"{module}_cocotb",
    "defines": ["-j12"],
    "toplevel": f"{module}",                                  # top level HDL (Update me!)
    "testcase": None,                                         # This is populated by import_tests.py
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND", "-Wno-PINMISSING", "-Wno-SYMRSVDWORD"],
    # ONLY ENABLE DURING DEBUG
    "waves": 1,                                         # Add waves (1/2)
    "extra_args": ["--trace-fst", "--trace-structs"]    # Add waves (2/2)
    # Waves are in sim_build/dump.fst

}

# DO NOT MODIFY ANYTHING INCLUDING AND AFTER THIS LINE #

def test_increment():
        configs["testcase"] = "test_increment"
        run(**configs)

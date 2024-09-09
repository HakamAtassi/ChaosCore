from cocotb_test.simulator import run
import os
import glob

# include everything in hw/verilog
current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_dir = os.path.join(current_file_dir, "../../../hw/verilog")

# Get a list of all .sv files in the hw/verilog directory
verilog_filenames = ["ROB.sv", "ROB_shared_mem.sv", "mem_64x70.sv", "ROB_WB_mem.sv", "ROB_entry_mem.sv", "mem_busy_64x1.sv", "fetch_64x53.sv", "mem_64x17.sv", "fetch_64x37.sv", "mem_64x26.sv", "mem_64x28.sv"]

verilog_files = [os.path.join(verilog_dir, filename) for filename in verilog_filenames]

module = "ROB"

configs = {
    "simulator": "verilator",
    "verilog_sources": verilog_files,
    "module": f"{module}_cocotb",
    "defines": ["-j10"],
    "toplevel": f"{module}",                                  # top level HDL (Update me!)
    "testcase": None,                                         # This is populated by import_tests.py
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND", "-Wno-PINMISSING", "-Wno-SYMRSVDWORD"],
    # ONLY ENABLE DURING DEBUG
    "waves": 1,                                         # Add waves (1/2)
    "extra_args": ["--trace-fst", "--trace-structs"]    # Add waves (2/2)
    # Waves are in sim_build/dump.fst
}

# DO NOT MODIFY ANYTHING INCLUDING AND AFTER THIS LINE #

def test_reset():
        configs["testcase"] = "test_reset"
        run(**configs)

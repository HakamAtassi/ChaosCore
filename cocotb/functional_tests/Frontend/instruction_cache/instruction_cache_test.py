from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Frontend/instruction_cache") # Target simulation file (Update me!)

module = "instruction_cache"  # Update me!

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

def test_write_1_all_ready():
        configs["testcase"] = "test_write_1_all_ready"
        run(**configs)

def test_write_2_all_ready():
        configs["testcase"] = "test_write_2_all_ready"
        run(**configs)

def test_write_3_all_ready():
        configs["testcase"] = "test_write_3_all_ready"
        run(**configs)

def test_write_1_cpu_not_ready():
        configs["testcase"] = "test_write_1_cpu_not_ready"
        run(**configs)

def test_write_1_DRAM_not_ready():
        configs["testcase"] = "test_write_1_DRAM_not_ready"
        run(**configs)

def test_reads_fifo_style_all_ready():
        configs["testcase"] = "test_reads_fifo_style_all_ready"
        run(**configs)


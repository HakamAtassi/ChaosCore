from cocotb_test.simulator import run
import os
import subprocess


current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Frontend/instruction_cache.v")

configs = {
    "simulator": "verilator",
    "verilog_sources": [verilog_file_path], # sources
    "module": "RAS_cocotb",        # name of cocotb test module
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND"],
    "defines": ["-j12"],
    "module": None,             # name of cocotb test module
    "toplevel": None,           # top level HDL
    "testcase": None,
    
    # ONLY ENABLE DURING DEBUG
    "waves": 1,    # Add waves (1/2)
    "extra_args": ["--trace-fst", "--trace-structs"]   # Add waves (2/2)
    # Waves are in sim_build/dump.fst
}

# Make first...
result = subprocess.run(['make', 'clean'], cwd=current_file_dir, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

# Print the results
print(result.stdout.decode())


def test_reset():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "reset"       # Name of your cocotb function
    run(**configs)

# Add rest of the tests here...


def test_write_read():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "write_read"       # Name of your cocotb function
    run(**configs)

def test_write_read():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "write_read_DRAM_ready"       # Name of your cocotb function
    run(**configs)


def test_read_DRAM_not_ready():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "write_read_DRAM_not_ready"       # Name of your cocotb function
    run(**configs)


def test_read_all_alignments():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "read_all_alignments"       # Name of your cocotb function
    run(**configs)


def test_write_read_read():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "write_read_read"       # Name of your cocotb function
    run(**configs)


def test_read_miss_kill():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "read_miss_kill"       # Name of your cocotb function
    run(**configs)


def test_read_hit_kill():
    configs["module"] = "instruction_cache_cocotb"    # Cocotb file
    configs["toplevel"] = "instruction_cache"         # Verilog top leve module
    configs["testcase"] = "read_hit_kill"       # Name of your cocotb function
    run(**configs)
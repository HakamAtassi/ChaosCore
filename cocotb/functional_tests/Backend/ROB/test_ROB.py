from cocotb_test.simulator import run
import os
import subprocess


current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/ROB.v")

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
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "reset"       # Name of your cocotb function
    run(**configs)

# Add rest of the tests here...

def test_allocate_all_valid():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "allocate_all_valid"       # Name of your cocotb function
    run(**configs)

def test_allocate_first_invalid():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "allocate_first_invalid"       # Name of your cocotb function
    run(**configs)



def test_allocate_first_not_branch():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "allocate_first_not_branch"       # Name of your cocotb function
    run(**configs)

def test_allocate_multiple():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "allocate_multiple"       # Name of your cocotb function
    run(**configs)

def test_busy():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "busy"       # Name of your cocotb function
    run(**configs)

def test_busy_random():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "busy_random"       # Name of your cocotb function
    run(**configs)

def test_allocate_many():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "allocate_many"       # Name of your cocotb function
    run(**configs)

def test_allocate_many_FU_broadcast():
    configs["module"] = "ROB_cocotb"    # Cocotb file
    configs["toplevel"] = "ROB"         # Verilog top leve module
    configs["testcase"] = "allocate_many_FU_broadcast"       # Name of your cocotb function
    run(**configs)
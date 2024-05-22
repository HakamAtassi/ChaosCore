from cocotb_test.simulator import run

import os
import subprocess

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/RS.v")

configs = {
    "simulator": "verilator",
    "verilog_sources": [verilog_file_path], # sources
    "module": "RS_cocotb",        # name of cocotb test module
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND"],
    "defines": ["-j12"],
    "module": None,        # name of cocotb test module
    "toplevel": None,            # top level HDL
    "testcase": None,
    
    # ONLY ENABLE DURING DEBUG
    "waves": 1,
    "extra_args": ["--trace-fst", "--trace-structs"]
}

# Make first...
result = subprocess.run(['make', 'clean'], cwd=current_file_dir, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

# Print the results
print(result.stdout.decode())
print(result.stderr.decode())


def test_reset():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "simple_reset"
    run(**configs)

def test_allocate_1_RS_not_ready():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "allocate_1_RS_not_ready"
    run(**configs)

def test_allocate_2_RS_not_ready():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "allocate_2_RS_not_ready"
    run(**configs)

def test_single_broadcast_good():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "single_broadcast_good"
    run(**configs)

def test_single_broadcast_bad():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "single_broadcast_bad"
    run(**configs)

##################
# TEST DISPATCH ##
##################

def test_single_dispatch_uOp0():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "dispatch_uOp0"
    run(**configs)

def test_single_dispatch_uOp1():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "dispatch_uOp1"
    run(**configs)

def test_dispatch_uOp0_uOp1():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "dispatch_uOp0_uOp1"
    run(**configs)

def test_dispatch_uOp0_uOp0():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "dispatch_uOp0_uOp0"
    run(**configs)

def test_dispatch_uOp1_uOp1():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "dispatch_uOp1_uOp1"
    run(**configs)

def test_uOp0_uOp1_uOp2_uOp3():
    configs["module"] = "RS_cocotb"
    configs["toplevel"] = "RS"
    configs["testcase"] = "dispatch_uOp0_uOp1_uOp2_uOp3"
    run(**configs)
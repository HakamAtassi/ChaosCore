from cocotb_test.simulator import run

import os
import subprocess

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/chisel/src/main/resources/nReadmWrite.v")

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
    configs["module"] = "nReadmWrite_cocotb"
    configs["toplevel"] = "nReadmWrite"
    configs["testcase"] = "simple_reset"
    run(**configs)


def test_simple_writes():
    configs["module"] = "nReadmWrite_cocotb"
    configs["toplevel"] = "nReadmWrite"
    configs["testcase"] = "simple_writes"
    run(**configs)

def test_simple_writes_4_wide():
    configs["module"] = "nReadmWrite_cocotb"
    configs["toplevel"] = "nReadmWrite"
    configs["testcase"] = "simple_writes_4_wide"
    run(**configs)

def test_simple_writes_4_wide_8_wide():
    configs["module"] = "nReadmWrite_cocotb"
    configs["toplevel"] = "nReadmWrite"
    configs["testcase"] = "simple_writes_4_wide_8_wide"
    run(**configs)

def test_fuzz_writes_4_wide_8_wide():
    configs["module"] = "nReadmWrite_cocotb"
    configs["toplevel"] = "nReadmWrite"
    configs["testcase"] = "fuzz_writes_4_wide_8_wide"
    run(**configs)
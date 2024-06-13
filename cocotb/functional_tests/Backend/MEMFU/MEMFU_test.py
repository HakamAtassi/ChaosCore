from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/MEMFU.v") # Target simulation file (Update me!)

module = "MEMFU"  # Update me!

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

def test_SW():
        configs["testcase"] = "test_SW"
        run(**configs)

def test_SH():
        configs["testcase"] = "test_SH"
        run(**configs)

def test_SB():
        configs["testcase"] = "test_SB"
        run(**configs)

def test_LW():
        configs["testcase"] = "test_LW"
        run(**configs)

def test_LHW():
        configs["testcase"] = "test_LHW"
        run(**configs)

def test_LB():
        configs["testcase"] = "test_LB"
        run(**configs)

def test_LHW_signed():
        configs["testcase"] = "test_LHW_signed"
        run(**configs)

def test_LB_signed():
        configs["testcase"] = "test_LB_signed"
        run(**configs)

def test_LBU_signed():
        configs["testcase"] = "test_LBU_signed"
        run(**configs)

def test_LHWU_signed():
        configs["testcase"] = "test_LHWU_signed"
        run(**configs)

def test_ready_after_waiting_request():
        configs["testcase"] = "test_ready_after_waiting_request"
        run(**configs)

def test_ready_after_accepted_request():
        configs["testcase"] = "test_ready_after_accepted_request"
        run(**configs)


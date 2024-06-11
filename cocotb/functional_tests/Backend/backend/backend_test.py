from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Backend/backend.v") # Target simulation file (Update me!)

module = "backend"  # Update me!

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

def test_print():
        configs["testcase"] = "test_print"
        run(**configs)

def test_addi_RS_allocate():
        configs["testcase"] = "test_addi_RS_allocate"
        run(**configs)

def test_addi_RS_deallocate_port_contention():
        configs["testcase"] = "test_addi_RS_deallocate_port_contention"
        run(**configs)

def test_addi_RS_deallocate_many_free_ports():
        configs["testcase"] = "test_addi_RS_deallocate_many_free_ports"
        run(**configs)

def test_addi_RS_deallocate_many_free_ports_2():
        configs["testcase"] = "test_addi_RS_deallocate_many_free_ports_2"
        run(**configs)

def test_addi_RS_deallocate_many_free_ports_2_init_PRF():
        configs["testcase"] = "test_addi_RS_deallocate_many_free_ports_2_init_PRF"
        run(**configs)

def test_addi_RS_reg_read_RD():
        configs["testcase"] = "test_addi_RS_reg_read_RD"
        run(**configs)


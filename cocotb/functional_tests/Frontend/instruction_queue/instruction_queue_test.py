from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Frontend/instruction_queue.v") # Target simulation file (Update me!)

module = "instruction_queue"

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

def test_write_one():
        configs["testcase"] = "test_write_one"
        run(**configs)

def test_write_all():
        configs["testcase"] = "test_write_all"
        run(**configs)

def test_full():
        configs["testcase"] = "test_full"
        run(**configs)

def test_full():
        configs["testcase"] = "test_full"
        run(**configs)

def test_1_ready():
        configs["testcase"] = "test_1_ready"
        run(**configs)

def test_2_ready():
        configs["testcase"] = "test_2_ready"
        run(**configs)

def test_3_ready():
        configs["testcase"] = "test_3_ready"
        run(**configs)

def test_4_ready():
        configs["testcase"] = "test_4_ready"
        run(**configs)

def test_dequeue_1():
        configs["testcase"] = "test_dequeue_1"
        run(**configs)

def test_dequeue_2():
        configs["testcase"] = "test_dequeue_2"
        run(**configs)

def test_dequeue_3():
        configs["testcase"] = "test_dequeue_3"
        run(**configs)

def test_dequeue_4():
        configs["testcase"] = "test_dequeue_4"
        run(**configs)

def test_dequeue_4_write_1():
        configs["testcase"] = "test_dequeue_4_write_1"
        run(**configs)

def test_dequeue_4_write_2():
        configs["testcase"] = "test_dequeue_4_write_2"
        run(**configs)

def test_dequeue_4_write_3():
        configs["testcase"] = "test_dequeue_4_write_3"
        run(**configs)

def test_dequeue_4_write_4():
        configs["testcase"] = "test_dequeue_4_write_4"
        run(**configs)

def test_no_bubbles():
        configs["testcase"] = "test_no_bubbles"
        run(**configs)

def test_read_write_1():
        configs["testcase"] = "test_read_write_1"
        run(**configs)

def test_read_write_2():
        configs["testcase"] = "test_read_write_2"
        run(**configs)

def test_no_overwrite():
        configs["testcase"] = "test_no_overwrite"
        run(**configs)


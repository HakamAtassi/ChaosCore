from cocotb_test.simulator import run
import os
import glob

# include everything in hw/verilog
current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_dir = os.path.join(current_file_dir, "../../../hw/verilog")

# Get a list of all .sv files in the hw/verilog directory
sv_files = glob.glob(os.path.join(verilog_dir, "*.sv"))
v_files = glob.glob(os.path.join(verilog_dir, "*.v"))
verilog_files = sv_files + v_files

module = "SOC"  # Update me!

configs = {
    "simulator": "verilator",
    "verilog_sources": verilog_files,
    "module": f"{module}_cocotb",
    "defines": ["-j16"],
    "toplevel": f"{module}",                                  # top level HDL (Update me!)
    "testcase": None,                                         # This is populated by import_tests.py
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND", "-Wno-PINMISSING", "-Wno-SYMRSVDWORD", "-Wno-TIMESCALEMOD"],
    # ONLY ENABLE DURING DEBUG
    "waves": 1,                                         # Add waves (1/2)
    "extra_args": ["--trace-fst", "--trace-structs"]    # Add waves (2/2)
    # Waves are in sim_build/dump.fst
}

# DO NOT MODIFY ANYTHING INCLUDING AND AFTER THIS LINE #

def test_add():
        configs["testcase"] = "test_add"
        run(**configs)

def test_addi():
        configs["testcase"] = "test_addi"
        run(**configs)

def test_and():
        configs["testcase"] = "test_and"
        run(**configs)

def test_andi():
        configs["testcase"] = "test_andi"
        run(**configs)

def test_auipc():
        configs["testcase"] = "test_auipc"
        run(**configs)

def test_beq():
        configs["testcase"] = "test_beq"
        run(**configs)

def test_bge():
        configs["testcase"] = "test_bge"
        run(**configs)

def test_bgeu():
        configs["testcase"] = "test_bgeu"
        run(**configs)

def test_blt():
        configs["testcase"] = "test_blt"
        run(**configs)

def test_bltu():
        configs["testcase"] = "test_bltu"
        run(**configs)

def test_bne():
        configs["testcase"] = "test_bne"
        run(**configs)

def test_fence_i():
        configs["testcase"] = "test_fence_i"
        run(**configs)

def test_jal():
        configs["testcase"] = "test_jal"
        run(**configs)

def test_jalr():
        configs["testcase"] = "test_jalr"
        run(**configs)

def test_lb():
        configs["testcase"] = "test_lb"
        run(**configs)

def test_lbu():
        configs["testcase"] = "test_lbu"
        run(**configs)

def test_lh():
        configs["testcase"] = "test_lh"
        run(**configs)

def test_lhu():
        configs["testcase"] = "test_lhu"
        run(**configs)

def test_lui():
        configs["testcase"] = "test_lui"
        run(**configs)

def test_lw():
        configs["testcase"] = "test_lw"
        run(**configs)

def test_ma_data():
        configs["testcase"] = "test_ma_data"
        run(**configs)

def test_or():
        configs["testcase"] = "test_or"
        run(**configs)

def test_ori():
        configs["testcase"] = "test_ori"
        run(**configs)

def test_sb():
        configs["testcase"] = "test_sb"
        run(**configs)

def test_sh():
        configs["testcase"] = "test_sh"
        run(**configs)

def test_simple():
        configs["testcase"] = "test_simple"
        run(**configs)

def test_sll():
        configs["testcase"] = "test_sll"
        run(**configs)

def test_slli():
        configs["testcase"] = "test_slli"
        run(**configs)

def test_slt():
        configs["testcase"] = "test_slt"
        run(**configs)

def test_slti():
        configs["testcase"] = "test_slti"
        run(**configs)

def test_sltiu():
        configs["testcase"] = "test_sltiu"
        run(**configs)

def test_sltu():
        configs["testcase"] = "test_sltu"
        run(**configs)

def test_sra():
        configs["testcase"] = "test_sra"
        run(**configs)

def test_srai():
        configs["testcase"] = "test_srai"
        run(**configs)

def test_srl():
        configs["testcase"] = "test_srl"
        run(**configs)

def test_srli():
        configs["testcase"] = "test_srli"
        run(**configs)

def test_sub():
        configs["testcase"] = "test_sub"
        run(**configs)

def test_sw():
        configs["testcase"] = "test_sw"
        run(**configs)

def test_xor():
        configs["testcase"] = "test_xor"
        run(**configs)

def test_xori():
        configs["testcase"] = "test_xori"
        run(**configs)

def test_reset():
        configs["testcase"] = "test_reset"
        run(**configs)


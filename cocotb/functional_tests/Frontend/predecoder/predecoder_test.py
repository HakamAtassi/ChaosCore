from cocotb_test.simulator import run
import os

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Frontend/BP/predecoder.v") # Target simulation file (Update me!)

module = "predecoder"

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

def test_addi_passthrough():
        configs["testcase"] = "test_addi_passthrough"
        run(**configs)

def test_addi_with_prediction_invalid():
        configs["testcase"] = "test_addi_with_prediction_invalid"
        run(**configs)

def test_ready():
        configs["testcase"] = "test_ready"
        run(**configs)

def test_nonbranch_PC_invalidation():
        configs["testcase"] = "test_nonbranch_PC_invalidation"
        run(**configs)

def test_nonbranch_PC_validation():
        configs["testcase"] = "test_nonbranch_PC_validation"
        run(**configs)

def test_RAS_update():
        configs["testcase"] = "test_RAS_update"
        run(**configs)

def test_JAL_then_correct():
        configs["testcase"] = "test_JAL_then_correct"
        run(**configs)

def test_JAL_then_incorrect():
        configs["testcase"] = "test_JAL_then_incorrect"
        run(**configs)

def test_JAL_output_invalidation():
        configs["testcase"] = "test_JAL_output_invalidation"
        run(**configs)

def test_JALR_output_invalidation():
        configs["testcase"] = "test_JALR_output_invalidation"
        run(**configs)

def test_FTQ_JAL():
        configs["testcase"] = "test_FTQ_JAL"
        run(**configs)

def test_FTQ_JAL_many_branches():
        configs["testcase"] = "test_FTQ_JAL_many_branches"
        run(**configs)

def test_FTQ_JAL_second_instruction():
        configs["testcase"] = "test_FTQ_JAL_second_instruction"
        run(**configs)

def test_FTQ_JAL_first_instruction_invalid():
        configs["testcase"] = "test_FTQ_JAL_first_instruction_invalid"
        run(**configs)

def test_FTQ_BEQ():
        configs["testcase"] = "test_FTQ_BEQ"
        run(**configs)

def test_FTQ_BEQ_second_instruction():
        configs["testcase"] = "test_FTQ_BEQ_second_instruction"
        run(**configs)

def test_FTQ_BEQ_NT():
        configs["testcase"] = "test_FTQ_BEQ_NT"
        run(**configs)

def test_BEQ_GHR():
        configs["testcase"] = "test_BEQ_GHR"
        run(**configs)

def test_BEQ_GHR_many():
        configs["testcase"] = "test_BEQ_GHR_many"
        run(**configs)

def test_FTQ_BEQ_GHR_many_2():
        configs["testcase"] = "test_FTQ_BEQ_GHR_many_2"
        run(**configs)

def test_FTQ_BEQ_GHR_non_branch():
        configs["testcase"] = "test_FTQ_BEQ_GHR_non_branch"
        run(**configs)

def test_FTQ_BEQ_GHR_RET():
        configs["testcase"] = "test_FTQ_BEQ_GHR_RET"
        run(**configs)

def test_call_RAS_update_no_BTB():
        configs["testcase"] = "test_call_RAS_update_no_BTB"
        run(**configs)

def test_call_RAS_update_has_BTB():
        configs["testcase"] = "test_call_RAS_update_has_BTB"
        run(**configs)


from cocotb_test.simulator import run
import os
import subprocess

current_file_dir = os.path.dirname(os.path.abspath(__file__))
verilog_file_path = os.path.join(current_file_dir, "../../../../hw/verilog/Frontend/rename.v")

configs = {
    "simulator": "verilator",
    "verilog_sources": [verilog_file_path], # sources
    "module": "rename_cocotb",        # name of cocotb test module
    "compile_args": ["-Wno-DECLFILENAME", "-Wno-UNUSED", "-Wno-UNDRIVEN", "-Wno-WIDTH", "-Wno-UNOPTFLAT", "-Wno-WIDTHEXPAND"],
    "defines": ["-j12"],
    "module": None,        # name of cocotb test module
    "toplevel": None,            # top level HDL
    "testcase": None
    
    # ONLY ENABLE DURING DEBUG
    #"waves": 0,
    #"extra_args": ["--trace-fst", "--trace-structs"]
}

# Make first...
result = subprocess.run(['make', 'clean'], cwd=current_file_dir, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

# Print the results
print(result.stdout.decode())
print(result.stderr.decode())



########################
## TEST Input Reorder ##
########################

def test_startup():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "rename"
    configs["testcase"] = "test_startup"
    run(**configs)

def test_reorder_free_inputs_no_change():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "reorder_free_inputs"
    configs["testcase"] = "reorder_free_inputs_no_change"
    run(**configs)

def test_reorder_first_element_invalid():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "reorder_free_inputs"
    configs["testcase"] = "reorder_first_element_invalid"
    run(**configs)

def test_reorder_last_element_invalid():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "reorder_free_inputs"
    configs["testcase"] = "reorder_last_element_invalid"
    run(**configs)

def test_reorder_middle_elements_invalid():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "reorder_free_inputs"
    configs["testcase"] = "reorder_middle_elements_invalid"
    run(**configs)

def test_reorder_multiple_invalid():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "reorder_free_inputs"
    configs["testcase"] = "reorder_multiple_invalid"
    run(**configs)

def test_reorder_max_width():
    configs["module"]   = "reorder_free_inputs_cocotb"
    configs["toplevel"] = "reorder_free_inputs"
    configs["testcase"] = "reorder_max_width"
    run(**configs)


#########################
## Test Output Reorder ##
#########################

def test_reorder_renamed_outputs_no_change():
    configs["module"]   = "reorder_renamed_outputs_cocotb"
    configs["toplevel"] = "reorder_renamed_outputs"
    configs["testcase"] = "reorder_renamed_outputs_no_change"
    run(**configs)

def test_reorder_renamed_outputs_last_invalid():
    configs["module"]   = "reorder_renamed_outputs_cocotb"
    configs["toplevel"] = "reorder_renamed_outputs"
    configs["testcase"] = "reorder_renamed_outputs_last_invalid"
    run(**configs)


def test_reorder_renamed_outputs_first_last_invalid():
    configs["module"]   = "reorder_renamed_outputs_cocotb"
    configs["toplevel"] = "reorder_renamed_outputs"
    configs["testcase"] = "reorder_renamed_outputs_first_last_invalid"
    run(**configs)

def test_reorder_renamed_outputs_random_invalid():
    configs["module"]   = "reorder_renamed_outputs_cocotb"
    configs["toplevel"] = "reorder_renamed_outputs"
    configs["testcase"] = "reorder_renamed_outputs_random_invalid"
    run(**configs)

####################
## TEST Free List ##
####################

def test_free_list_check_first_read():
    configs["module"]   = "free_list_cocotb"
    configs["toplevel"] = "free_list"
    configs["testcase"] = "free_list_check_first_read"
    run(**configs)

def test_free_list_check_many_reads():
    configs["module"]   = "free_list_cocotb"
    configs["toplevel"] = "free_list"
    configs["testcase"] = "free_list_check_first_read"
    run(**configs)

def test_free_list_check_many_unordered_reads():
    configs["module"]   = "free_list_cocotb"
    configs["toplevel"] = "free_list"
    configs["testcase"] = "free_list_check_many_unordered_reads"
    run(**configs)

##############
## TEST RAT ##
##############


def test_RAT_startup():
    configs["module"]   = "RAT_cocotb"
    configs["toplevel"] = "RAT"
    configs["testcase"] = "RAT_startup"
    configs["compile_only"] = True
    run(**configs)

def test_RAT_write_read():
    configs["module"]   = "RAT_cocotb"
    configs["toplevel"] = "RAT"
    configs["testcase"] = "RAT_write_read"
    configs["compile_only"] = True
    run(**configs)

def test_RAT_write_read_checkpoint_read():
    configs["module"]   = "RAT_cocotb"
    configs["toplevel"] = "RAT"
    configs["testcase"] = "RAT_write_read_checkpoint_read"
    configs["compile_only"] = True
    run(**configs)

def test_RAT_write_read_many_checkpoints_read():
    configs["module"]   = "RAT_cocotb"
    configs["toplevel"] = "RAT"
    configs["testcase"] = "RAT_write_read_many_checkpoints_read"
    configs["compile_only"] = True
    run(**configs)

def test_RAT_write_read_15_checkpoints_read():
    configs["module"]   = "RAT_cocotb"
    configs["toplevel"] = "RAT"
    configs["testcase"] = "RAT_write_read_15_checkpoints_read"
    configs["compile_only"] = True
    run(**configs)

def test_RAT_write_read_15_checkpoints_read_free():
    configs["module"]   = "RAT_cocotb"
    configs["toplevel"] = "RAT"
    configs["testcase"] = "RAT_write_read_15_checkpoints_read_free"
    configs["compile_only"] = True
    run(**configs)

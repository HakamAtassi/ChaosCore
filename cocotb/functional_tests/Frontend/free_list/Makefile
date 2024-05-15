# Makefile
TEST_DIR=tests

# defaults
SIM ?= verilator

TOPLEVEL_LANG ?= verilog

VERILOG_DIR = ../../../../hw/verilog/Frontend

COMPILE_ARGS += -Wno-DECLFILENAME -Wno-UNUSED -Wno-UNDRIVEN -Wno-WIDTH -Wno-UNOPTFLAT -Wno-WIDTHEXPAND -j 4

EXTRA_ARGS += --trace-fst --trace-structs

WAVES?=1
GUI?=0

VERILOG_SOURCES += $(VERILOG_DIR)/free_list.v
# use VHDL_SOURCES for VHDL files

# TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
TOPLEVEL = reorder_free_inputs

MODULE = free_list_tests

# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim


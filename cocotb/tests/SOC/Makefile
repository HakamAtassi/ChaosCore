# Makefile
TEST_DIR=tests

# defaults
SIM ?= verilator

TOPLEVEL_LANG ?= verilog

VERILOG_DIR = ../../../hw/verilog

COMPILE_ARGS += -Wno-DECLFILENAME -Wno-UNUSED -Wno-UNDRIVEN -Wno-WIDTH -Wno-UNOPTFLAT -Wno-WIDTHEXPAND -j 16 --MAKEFLAGS OPT_FAST=-O0

EXTRA_ARGS += --trace --trace-fst --trace-structs 

WAVES?=1
GUI?=0

#VERILOG_SOURCES += $(VERILOG_DIR)/SOC.sv
VERILOG_SOURCES += $(addprefix $(VERILOG_DIR)/,$(shell cat $(VERILOG_DIR)/filelist.f))
VERILOG_SOURCES += $(addprefix $(VERILOG_DIR)/,$(shell cat $(VERILOG_DIR)/AXI_filelist.f))

# use VHDL_SOURCES for VHDL files

# TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
TOPLEVEL = SOC


#COCOTB_TEST_MODULES = SOC_cocotb
MODULE = SOC_cocotb

# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim

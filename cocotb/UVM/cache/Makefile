###
CWD=$(shell pwd)
export COCOTB_REDUCED_LOG_FMT = 1
    COMPILE_ARGS += --timing
GHDL_ARGS := --ieee=synopsys

COCOTB_HDL_TIMEUNIT = 1ns
COCOTB_HDL_TIMEPRECISION = 1ns

#export COCOTB_LOG_LEVEL=TRACE
export COCOTB_REDUCED_LOG_FMT = 1

# Makefile
TEST_DIR=tests


# defaults
SIM ?= verilator

TOPLEVEL_LANG ?= verilog

VERILOG_DIR = ../../../hw/verilog


#SIM_ARGS=-Wno-DECLFILENAME -Wno-UNUSED -Wno-UNDRIVEN -Wno-WIDTH -Wno-UNOPTFLAT 
#SIM_ARGS=-Wno-fatal


EXTRA_ARGS += --trace-fst --trace-structs

WAVES?=1
GUI?=0

VERILOG_SOURCES += $(VERILOG_DIR)/L1Cache/L1_cache_mem_v2.v
# use VHDL_SOURCES for VHDL files

# TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
TOPLEVEL = L1_cache_mem


MODULE = cacheMemTB

# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim



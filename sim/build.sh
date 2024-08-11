#!/bin/bash

# Define the directory containing the SystemVerilog files
SV_DIR="../hw/verilog/"

# Find all .sv files in the directory and its subdirectories
SV_FILES=$(find "$SV_DIR" -name "*.sv")

# ignore warnings
#rm -rf obj_dir/
WARNINGS="-Wno-PINMISSING -Wno-UNOPTFLAT -Wno-UNUSED -Wno-PINCONNECTEMPTY -Wno-MODDUP -Wno-VARHIDDEN -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-TIMESCALEMOD -Wno-GENUNNAMED -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-SYMRSVDWORD"

# Run Verilator with the specified options, including disabled warnings

#verilator -Wall --cc top_v2.sv --binary --trace --top-module top_v2 -I"$SV_DIR" $WARNINGS --compiler gcc 
#verilator -Wall --cc top_v2.sv --binary --trace --top-module top_v2 -j 15 -I"$SV_DIR" "-Wno-PINMISSING -Wno-UNOPTFLAT -Wno-UNUSED -Wno-PINCONNECTEMPTY -Wno-MODDUP -Wno-VARHIDDEN -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-TIMESCALEMOD -Wno-GENUNNAMED -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-SYMRSVDWORD"

verilator --trace -cc top_v2.sv --exe --build -j 14 -I"$SV_DIR" $WARNINGS --top-module top_v2 main.cpp 

#./obj_dir/VTop_Level 2>&1 | tee "$1"_run.log

#stdbuf -oL ./obj_dir/VTop_Level 2>&1 | tee "${1}_run.log"
./obj_dir/Vtop_v2
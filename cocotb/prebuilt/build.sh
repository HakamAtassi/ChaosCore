#!/bin/bash

# Define the directory containing the SystemVerilog files
SV_DIR="../../hw/verilog/"

# Find all .sv files in the directory and its subdirectories
SV_FILES=$(find "$SV_DIR" -name "*.sv")

# ignore warnings
#rm -rf obj_dir/
WARNINGS="-Wno-PINMISSING -Wno-UNOPTFLAT -Wno-UNUSED -Wno-PINCONNECTEMPTY -Wno-MODDUP -Wno-VARHIDDEN -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-TIMESCALEMOD -Wno-GENUNNAMED -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-SYMRSVDWORD"

verilator -cc top.sv --exe --build -j 14 -I"$SV_DIR" $WARNINGS --top-module top main.cpp 

#./obj_dir/Vtop_v2 $1


# clean up

mkdir prebuilt_executables
mv obj_dir/Vtop prebuilt_executables
rm -rf obj_dir






#verilator top.sv --binary --trace --top top -j 15

#./obj_dir/Vtop


# run simulation using verilator:

#verialtor top_v2.sv --binary --trace --top top -j 15

# all SV files are found in ../hw/verilog/... <= tell verilator about this

#!/bin/bash

# Define the directory containing the SystemVerilog files
SV_DIR="../hw/verilog/"

# Find all .sv files in the directory and its subdirectories
SV_FILES=$(find "$SV_DIR" -name "*.sv")

# ignore warnings
WARNINGS="-Wno-PINMISSING -Wno-UNOPTFLAT -Wno-UNUSED -Wno-PINCONNECTEMPTY -Wno-MODDUP -Wno-VARHIDDEN -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-TIMESCALEMOD -Wno-GENUNNAMED -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-SYMRSVDWORD"

# Run Verilator with the specified options, including disabled warnings
verilator -Wall --cc top_v2.sv --binary --trace --top-module top_v2 -j 15 -I"$SV_DIR" $WARNINGS $SV_FILES
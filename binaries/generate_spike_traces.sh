#!/bin/bash

# Check if an argument is provided
if [ $# -eq 0 ]; then
    echo "Please provide the name of the ELF file (without extension) as an argument."
    exit 1
fi

name="$1"
elffile="elf/$name.elf"

# Check if the ELF file exists
if [ ! -f "$elffile" ]; then
    echo "ELF file $elffile does not exist."
    exit 1
fi

echo "Generating spike trace for $name"

# Run spike with a 10-second timeout
timeout 10s spike -m0x80000000:0x90000000,0x80000:0x90000 --log=spike_traces/$name.log --log-commits --isa=rv32im "$elffile"

# Check if spike was terminated by timeout
if [ $? -eq 124 ]; then
    echo "Spike timed out for $name after 10 seconds"
fi



# Verilog Hex

This folder contains .hex files for use with $readmemh() in verilog. These files are generated via either

hexdump -v -e '1/1 "%02x\n"' binary.bin > hex.hex

or by passing - `-O verilog verilog_hex.hex` during the elf -> binary conversion process. 
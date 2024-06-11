#!/bin/bash


/opt/riscv/bin/riscv32-unknown-elf-gcc -ffreestanding -nostdlib -O3 -fno-plt -fno-pic -march=rv32i -mabi=ilp32  "C/hello_world.c" -o "bins/hello_world.elf"
/opt/riscv/bin/riscv32-unknown-elf-objdump -d -Mnumeric "bins/hello_world.elf" > "bins/hello_world.txt"



#/opt/riscv/bin/riscv32-unknown-elf-as "C/hello_world.c" -o "bins/hello_world.bin"
/opt/riscv/bin/riscv32-unknown-elf-objcopy "bins/hello_world.elf" -O binary "bins/hello_world.bin"
#!/bin/bash


echo "Building File: $1"

rvdir=/opt/riscv/bin

# build C files

${rvdir}/riscv32-unknown-elf-gcc -ffreestanding -nostdlib -O0 -fno-plt -fno-pic -march=rv32i -mabi=ilp32  "C/$1.c" -o "elf/$1.elf"
${rvdir}/riscv32-unknown-elf-objdump -d -Mnumeric "elf/$1.elf" > "txt/$1.txt"


${rvdir}/riscv32-unknown-elf-as "C/$1.c" -o "bin/$1.bin"
${rvdir}/riscv32-unknown-elf-objcopy "elf/$1.elf" -O binary "bin/$1.bin"

# build asm files

${rvdir}/riscv32-unknown-elf-as -o $1.o "asm/$1.asm"
${rvdir}/riscv32-unknown-elf-ld -o "elf/$1.elf" $1.o
rm $1.o
${rvdir}/riscv32-unknown-elf-objcopy -O binary "elf/$1.elf" "bin/$1.bin"
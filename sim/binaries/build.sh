#!/bin/bash

echo "Building all C and ASM files"

rvdir=/opt/riscv/bin
linker_script=linker.ld  # Specify the linker script

# Build C files
for cfile in C/*.c; 
do
    filename=$(basename -- "$cfile")
    name="${filename%.*}"
    echo "Building C File: $name"

    # Compile the C file to ELF using the linker script
    ${rvdir}/riscv32-unknown-elf-gcc -ffreestanding -nostdlib -O0 -fno-plt -fno-pic -march=rv32i -mabi=ilp32 startup.S "C/$name.c" -T $linker_script -o "elf/$name.elf"

    # Disassemble the ELF file to TXT
    ${rvdir}/riscv32-unknown-elf-objdump -d -Mnumeric "elf/$name.elf" > "txt/$name.txt"

    # Assemble the ELF file to binary
    ${rvdir}/riscv32-unknown-elf-objcopy "elf/$name.elf" -O binary "bin/$name.bin"
done

# Build ASM files
for asmfile in asm/*.asm; 
do
    filename=$(basename -- "$asmfile")
    name="${filename%.*}"
    echo "Building ASM File: $name"

    # Assemble the ASM file to ELF
    ${rvdir}/riscv32-unknown-elf-as "asm/$name.asm" -o "$name.o"
    ${rvdir}/riscv32-unknown-elf-ld -T $linker_script -o "elf/$name.elf" "$name.o"
    rm "$name.o"

    # Disassemble the ELF file to TXT
    ${rvdir}/riscv32-unknown-elf-objdump -d -Mnumeric "elf/$name.elf" > "txt/$name.txt"

    # Assemble the ELF file to binary
    ${rvdir}/riscv32-unknown-elf-objcopy -O binary "elf/$name.elf" "bin/$name.bin"
done

echo "Build process completed"
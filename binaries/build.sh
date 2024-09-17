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
    ${rvdir}/riscv32-unknown-elf-gcc -march=rv32im_zicsr -nostartfiles -std=gnu99 startup.S "C/$name.c"  -O1 -ffreestanding -Wl,-Bstatic -o "elf/$name.elf"  -T $linker_script -Wextra -Wshadow -Wundef -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wredundant-decls -Wpedantic -Wcast-qual -g -pedantic  -ffreestanding 


    # Disassemble the ELF file to TXT
    ${rvdir}/riscv32-unknown-elf-objdump -d -Mnumeric "elf/$name.elf" > "txt/$name.txt"

    # Assemble the ELF file to binary
    ${rvdir}/riscv32-unknown-elf-objcopy "elf/$name.elf" -O binary "bin/$name.bin"
done

for cfile in C/*/*.c; 
do


    filename=$(basename -- "$cfile")
    name="${filename%.*}"
    echo "Building C File: $name/$name"

    if [ "$name" == "utils" ]; then
        echo "Skipping utils"
        continue
    fi

    if [ "$name" == "test_utils" ]; then
        echo "Skipping utils"
        continue
    fi

    # Compile the C file to ELF using the linker script
    ${rvdir}/riscv32-unknown-elf-gcc -march=rv32im_zicsr -nostartfiles  -std=gnu99 startup.S "C/$name/$name.c"  -O1 -ffreestanding -Wl,-Bstatic -o "elf/$name.elf"  -T $linker_script -Wextra -Wshadow -Wundef -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wredundant-decls -Wpedantic -Wcast-qual -g -pedantic  -ffreestanding 

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

# generate spike traces for debugging
#spike -m0x80000000:0x90000000,0x80000:0x90000 --log=spike_traces/vec_add.log --log-commits -d --isa=rv32i elf/vec_add.elf
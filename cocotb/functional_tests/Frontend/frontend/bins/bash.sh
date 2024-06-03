#!/bin/bash

rvdir=/opt/riscv/bin

${rvdir}/riscv32-unknown-elf-as -o addi.o addi.s
${rvdir}/riscv32-unknown-elf-ld -o addi.elf addi.o
${rvdir}/riscv32-unknown-elf-objcopy -O binary addi.elf addi.bin


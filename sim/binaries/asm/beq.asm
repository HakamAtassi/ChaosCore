
.section .text
.global _start

__start:
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0

    beq x0, x0, __start


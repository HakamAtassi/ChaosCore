.section .text.start
.global _start

_start:
    la t0, main   # Load the address of 'main' into register t0
    jr t0         # Jump to 'main'

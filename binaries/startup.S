.section .text.start
.global _start

_start:
    li sp, 0x80004000 # Init stack pointer

    la t0, main   # Load the address of 'main' into register t0
    jr t0         # Jump to 'main'

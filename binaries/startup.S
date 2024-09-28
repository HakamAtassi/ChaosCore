
.section .data
ecal_string: .string "handling ECALL\n"
trap_string: .string "handling trap\n"

init_string: .string "INIT-ing regs\n"



.section .text.start
.global _start
.global trap_handler

_start:
    # Init regs
    li x0, 0
    li x1, 0
    li x2, 0
    li x3, 0
    li x4, 0
    li x5, 0
    li x6, 0
    li x7, 0
    li x8, 0
    li x9, 0
    li x10, 0
    li x11, 0
    li x12, 0
    li x13, 0
    li x14, 0
    li x15, 0
    li x16, 0
    li x17, 0
    li x18, 0
    li x19, 0
    li x20, 0
    li x21, 0
    li x22, 0
    li x23, 0
    li x24, 0
    li x25, 0
    li x26, 0
    li x27, 0
    li x28, 0
    li x29, 0
    li x30, 0
    li x31, 0
    
    li sp, 0x80100000    # Set stack pointer


    la a0, init_string          # Load the address of the format string into a0
    call printf                # Call the printf function



    # Set mtvec
    la t0, trap_handler     # Set mtvec value
    li t1, 0                # Set direct mode
    sll t1, t1, 2           # Shift up
    or t0, t0, t1           # or in mode
    csrw mtvec, t0          # write to CSR


    la t0, main
    jr t0      

trap_handler:
    # Save registers (context save)
    addi sp, sp, -64
    sw ra, 0(sp)
    sw t0, 4(sp)
    sw t1, 8(sp)
    sw t2, 12(sp)
    sw a0, 16(sp)
    sw a1, 20(sp)
    sw a2, 24(sp)
    sw a3, 28(sp)
    sw a4, 32(sp)
    sw a5, 36(sp)
    sw a6, 40(sp)
    sw a7, 44(sp)


    la a0, trap_string          # Load the address of the format string into a0
    call printf                # Call the printf function

    csrr t0, mcause # read mcause to get reason for exception
    # TODO: remove top bit (it denotes interrupt)
    li t1, 11       # mcause == 11 means ECALL from M mode

    beq t0, t1, handle_ecall 
    j handle_other_exception 



handle_ecall:
    # increment mepc (machine exception PC)
    csrr t0, mepc 
    addi t0, t0, 4
    csrw mepc, t0 


    la a0, ecal_string          # Load the address of the format string into a0
    call printf                # Call the printf function


    j finish_trap

syscall_print_int:
    j finish_trap    

handle_other_syscall:
    j finish_trap    

handle_other_exception:
    j finish_trap    

finish_trap:
    # load back context to continue execution
    lw ra, 0(sp)  
    lw t0, 4(sp)  
    lw t1, 8(sp)
    lw t2, 12(sp)
    lw a0, 16(sp) 
    lw a1, 20(sp)
    lw a2, 24(sp)
    lw a3, 28(sp)
    lw a4, 32(sp)
    lw a5, 36(sp)
    lw a6, 40(sp)
    lw a7, 44(sp)
    addi sp, sp, 64 

    mret            

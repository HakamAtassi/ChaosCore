SECTIONS
{
    /* Start at a known address, such as 0x80000000 */
    . = 0x80000000;

    /*__global_pointer$ = . + 0x800;*/

    /* Text section (read-execute) */
    .text : {
        *(.text.start)
        *(.text*)
    } 

    /* Read-only data section (read-only) */
    .rodata : {
        *(.rodata*)
    } 

    /* Data section (read-write) */
    .data : {
        _data_start = .;
        *(.data*)
        _data_end = .;
    } 

    /* BSS section (read-write, zero-initialized) */
    .bss : {
        __bss_start = .;
        *(.bss*)
        __bss_end = .;
        _end = .;
    } 

    /* Discard unnecessary sections */
    /DISCARD/ : {
        *(.comment)
        *(.note)
    }
}


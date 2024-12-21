MEMORY
{
    FLASH (RX) : ORIGIN = 0x00000000, LENGTH = 0x00040000
    SRAM (WX)  : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

_stack_size = 0x0800;  /* 2KB stack     ,2kb = 0x0800* , 4kb = 0x1000 , 8kb = 0x2000 (Patricia -no print) , 12kb = 0x3000 (Patricia - with print)*/
_heap_size  = 0x0000;  /* 0 B heap    ,1kb = 0x0400 , 2kb = 0x0800, 512B = 0x0200, 3kb = 0xC00, 256B = 0x0100*/

ENTRY(ResetISR)

REGION_ALIAS("REGION_TEXT", FLASH);
REGION_ALIAS("REGION_BSS", SRAM);
REGION_ALIAS("REGION_DATA", SRAM);
REGION_ALIAS("REGION_STACK", SRAM);
REGION_ALIAS("REGION_HEAP", SRAM);
REGION_ALIAS("REGION_ARM_EXIDX", FLASH);
REGION_ALIAS("REGION_ARM_EXTAB", FLASH);

SECTIONS {

    PROVIDE (_intvecs_base_address = 0x0);

    .intvecs (_intvecs_base_address) : AT (_intvecs_base_address) {
        KEEP (*(.intvecs))
    } > REGION_TEXT

    PROVIDE (_vtable_base_address = 0x20000000);

    .vtable (_vtable_base_address) : AT (_vtable_base_address) {
        KEEP (*(.vtable))
    } > REGION_DATA

    .text : {
        CREATE_OBJECT_SYMBOLS
        *(.text)
        *(.text.*)
        . = ALIGN(0x4);
        KEEP (*(.ctors))
        . = ALIGN(0x4);
        KEEP (*(.dtors))
        . = ALIGN(0x4);
        __init_array_start = .;
        KEEP (*(.init_array*))
        __init_array_end = .;
        *(.init)
        *(.fini*)
    } > REGION_TEXT

    PROVIDE (__etext = .);
    PROVIDE (_etext = .);
    PROVIDE (etext = .);

    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > REGION_TEXT

    .stack (NOLOAD) : ALIGN(4)
    {
        __stack_top = ORIGIN(SRAM);       /* Stack top */
        . = __stack_top + _stack_size;    /* Allocate stack */
        __stack_limit = .;                /* Stack limit */
    } > REGION_STACK

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > REGION_ARM_EXIDX

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > REGION_ARM_EXTAB

    .data : ALIGN (4) {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN (4);
        __data_end__ = .;
    } > REGION_DATA AT> REGION_TEXT

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN (4);
        __bss_end__ = .;
    } > REGION_BSS

    .heap : {
        __heap_start__ = .;
        end = __heap_start__;
        __end = end;
        KEEP(*(.heap))
        . = __end + _heap_size;
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > REGION_HEAP

    PROVIDE (__stack_top = ORIGIN(SRAM) + LENGTH(SRAM)); /* Top of the stack */
}

; Constants for the multiboot

MBALIGN equ 1<<0
MEMINFO equ 1<<1
MBFLAGS equ MBALIGN|MEMINFO
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC+MBFLAGS)

section .multiboot
align 4 ; align 4 bytes = 32 bits boundary
    dd MAGIC
    dd MBFLAGS
    dd CHECKSUM

section .bss
align 16 ; align stack in 16 bytes (needed in x86)
stackBottom:
resb 16384 ; stack size of 16KiB
stackTop:

section .text:
global _start:function (_start.end - _start)
_start:
    mov esp, stackTop
    ; paging and stuff goes here
    ; everything must stay 16-bytes aligned
    extern kernel_main
    call kernel_main

    cli
.hltloop:
    hlt
    jmp .hltloop
.end:
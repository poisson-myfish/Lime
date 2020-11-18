section .data
    ALIGN 4

section .text
global _load_gdt
_load_gdt:
    cli
    lgdt [gdt_desc]
    jmp 0x08:gdt_flush

gdt_flush:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret


section .rodata
gdt:
gdt_null:
    dd 0h
    dd 0h
    
gdt_code:
    dw 0FFFFh
    dw 00000h
    db 00h
    db 10011010b
    db 11001111b
    db 0
gdt_data:
    dw 0FFFFh
    dw 00000h
    db 00h
    db 10010010b
    db 11001111b
    db 0

gdt_desc:
    dw gdt_desc - gdt - 1
    dd gdt

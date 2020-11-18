section .text
global _load_idt
_load_idt:
    mov edx, [esp + 4]
    lidt [edx]
    sti
    ret

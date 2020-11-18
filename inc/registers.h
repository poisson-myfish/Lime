#ifndef LIME_REGISTERS_H
#define LIME_REGISTERS_H
#include <utils.h>

typedef struct
{
    u32 ds;
    u32 edi, esi, ebp, nothing, ebx, edx, ecx, eax;
    u32 interrupt, errorCode;  // For interrupts
    u32 eip, cs, eflags, esp, ss;  // Pushed by CPU
} Registers;

#endif

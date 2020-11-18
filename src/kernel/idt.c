#include <kernel/idt.h>
#include <kernel/lime_tty.h>
#include <kernel/iob.h>
#include <registers.h>

static void set_entry(u16 number, u32 address, u16 selector, u16 flags);
extern void _load_idt(u32 address);

static IdtEntry entries[256];
static u32 ptr[2];

void init_idt()
{
    
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 40);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
    
    set_entry(0, (u32)isr0, 0x08, 0x8e);
    set_entry(1, (u32)isr1, 0x08, 0x8e);
    set_entry(2, (u32)isr2, 0x08, 0x8e);
    set_entry(3, (u32)isr3, 0x08, 0x8e);
    set_entry(4, (u32)isr4, 0x08, 0x8e);
    set_entry(5, (u32)isr5, 0x08, 0x8e);
    set_entry(6, (u32)isr6, 0x08, 0x8e);
    set_entry(7, (u32)isr7, 0x08, 0x8e);
    set_entry(8, (u32)isr8, 0x08, 0x8e);
    set_entry(9, (u32)isr9, 0x08, 0x8e);
    set_entry(10, (u32)isr10, 0x08, 0x8e);
    set_entry(11, (u32)isr11, 0x08, 0x8e);
    set_entry(12, (u32)isr12, 0x08, 0x8e);
    set_entry(13, (u32)isr13, 0x08, 0x8e);
    set_entry(14, (u32)isr14, 0x08, 0x8e);
    set_entry(15, (u32)isr15, 0x08, 0x8e);
    set_entry(16, (u32)isr16, 0x08, 0x8e);
    set_entry(17, (u32)isr17, 0x08, 0x8e);
    set_entry(18, (u32)isr18, 0x08, 0x8e);
    set_entry(19, (u32)isr19, 0x08, 0x8e);
    set_entry(20, (u32)isr20, 0x08, 0x8e);
    set_entry(21, (u32)isr21, 0x08, 0x8e);
    set_entry(22, (u32)isr22, 0x08, 0x8e);
    set_entry(23, (u32)isr23, 0x08, 0x8e);
    set_entry(24, (u32)isr24, 0x08, 0x8e);
    set_entry(25, (u32)isr25, 0x08, 0x8e);
    set_entry(26, (u32)isr26, 0x08, 0x8e);
    set_entry(27, (u32)isr27, 0x08, 0x8e);
    set_entry(28, (u32)isr28, 0x08, 0x8e);
    set_entry(29, (u32)isr29, 0x08, 0x8e);
    set_entry(30, (u32)isr30, 0x08, 0x8e);
    set_entry(31, (u32)isr31, 0x08, 0x8e);
    set_entry(32, (u32)isr32, 0x08, 0x8e);

    u32 idtAddress = (u32)entries;
    ptr[0] = (sizeof(IdtEntry) * 256) + ((idtAddress & 0xffff) << 16);
    ptr[1] = idtAddress >> 16;

    _load_idt((u32)ptr);
}

static void set_entry(u16 number, u32 address, u16 selector, u16 flags)
{
    entries[number].limit_low = address & 0xffff;
    entries[number].selector = selector;
    entries[number].zero = 0;
    entries[number].flags = flags;
    entries[number].limit_high = (address & 0xffff0000) >> 16;
}

void handler(Registers regs)
{
    lime_tty_put_string("[ LIME ] Interrupt: ");
    lime_tty_put_int(regs.interrupt);
    lime_tty_put_string("\n");
}

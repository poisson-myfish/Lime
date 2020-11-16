#include <kernel/lime_tty.h>

extern void _load_gdt();  // From assembly

void lime_main()
{
    lime_tty_init(TtyTextMode);
    lime_tty_put_string("[ LIME ] Welcome to the Lime kernel!\n");
    _load_gdt();
    lime_tty_put_string("[ LIME ] Loaded GDT successfully!");
}

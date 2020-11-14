#include <kernel/lime_tty.h>

void lime_main()
{
    lime_tty_init();
    lime_tty_put_string("Hello, world!");
}

#include <kernel/lime_tty.h>

void lime_main()
{
    lime_tty_init(TtyTextMode);
    lime_tty_put_string("[ LIME ] Initializing...\n");
}

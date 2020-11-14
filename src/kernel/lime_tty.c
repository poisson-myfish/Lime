#include <kernel/lime_tty.h>
#include <kernel/drivers/vga_text_mode.h>
#include <string.h>

static struct
{
    void (*init)();
    void (*putch)(char c);
    void (*putstr)(const char* data);
    void (*clear)();
} ttyDriver;

void lime_tty_init(TtyDriver drv)
{
    switch (drv)
    {
    case TtyTextMode:
        ttyDriver.init = drv_text_mode_init;
        ttyDriver.putch = drv_text_mode_put_char;
        ttyDriver.putstr = drv_text_mode_put_string;
        ttyDriver.clear = drv_text_mode_clear;
        break;
    }

    ttyDriver.init();
}

void lime_tty_put_char(char c)
{
    ttyDriver.putch(c);
}

void lime_tty_put_string(const char* data)
{
    ttyDriver.putstr(data);
}

void lime_tty_clear()
{
    ttyDriver.clear();
}

#ifndef LIME_KERNEL_TTY_H
#define LIME_KERNEL_TTY_H
#include <utils.h>

typedef enum
{
    TtyTextMode
} TtyDriver;

void lime_tty_init(TtyDriver drv);
void lime_tty_put_char(char c);
void lime_tty_put_string(const char* data);
void lime_tty_clear();

#endif

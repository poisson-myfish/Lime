#ifndef LIME_KERNEL_TTY_H
#define LIME_KERNEL_TTY_H
#include <utils.h>

typedef enum
{
    VgaBlack = 0,
    VgaBlue = 1,
    VgaGreen = 2,
    VgaCyan = 3,
    VgaRed = 4,
    VgaMagenta = 5,
    VgaBrown = 6,
    VgaLightGrey = 7,
    VgaDarkGrey = 8,
    VgaLightBlue = 9,
    VgaLightGreen = 10,
    VgaLightCyan = 11,
    VgaLightRed = 12,
    VgaLightMagenta = 13,
    VgaLightBrown = 14,
    VgaWhite = 15
} VgaColor;

void lime_tty_init();
void lime_tty_set_color(u8 color);
void lime_tty_put_at(char c, u8 color, u32 x, u32 y);
void lime_tty_put_char(char c);
void lime_tty_write(const char* data, u32 size);
void lime_tty_put_string(const char* data);
void lime_tty_clear();

#endif

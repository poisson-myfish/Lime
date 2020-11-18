#ifndef LIME_DRIVERS_VGA_TEXT_MODE_H
#define LIME_DRIVERS_VGA_TEXT_MODE_H
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

void drv_text_mode_init();
void drv_text_mode_write(const char* data, u32 size);
void drv_text_mode_set_color(u8 color);
void drv_text_mode_put_char(char c);
void drv_text_mode_put_string(const char* data);
void drv_text_mode_put_int(int number);
void drv_text_mode_clear();
void drv_text_mode_put_at(char c, u8 color, u32 x, u32 y);

#endif

#include <kernel/lime_tty.h>
#include <string.h>

static u8 vga_get_color(VgaColor fg, VgaColor bg);
static u16 vga_entry(char c, u8 color);

static const u32 WIDTH = 80;
static const u32 HEIGHT = 25;

static u32 ttyRow;
static u32 ttyColumn;
static u8 ttyColor;
static u16* ttyBuffer;

void lime_tty_init()
{
    ttyRow = 0;
    ttyColumn = 0;
    ttyColor = vga_get_color(VgaWhite, VgaBlack);
    ttyBuffer = (u16*)0xB8000;

    lime_tty_clear(' ');
}

void lime_tty_set_color(u8 color)
{
    ttyColor = color;
}

void lime_tty_put_at(char c, u8 color, u32 x, u32 y)
{
    u32 index = y * WIDTH + x;
    ttyBuffer[index] = vga_entry(c, color);
}

void lime_tty_put_char(char c)
{
    lime_tty_put_at(c, ttyColor, ttyColumn, ttyRow);
    ttyColumn += 1;
    if (ttyColumn == WIDTH)
    {
        ttyColumn = 0;
        ttyRow += 1;

        if (ttyRow == HEIGHT)
            ttyRow = 0;
    }
}

void lime_tty_write(const char* data, u32 size)
{
    for (u32 i = 0; i < size; i += 1)
        lime_tty_put_char(data[i]);
}

void lime_tty_put_string(const char* data)
{
    lime_tty_write(data, str_len(data));
}


static u8 vga_get_color(VgaColor fg, VgaColor bg)
{
    return fg | bg << 4;
}

static u16 vga_entry(char c, u8 color)
{
    return (u16)c | (u16)color << 8;
}

void lime_tty_clear()
{
    for (u32 y = 0; y < HEIGHT; y += 1)
    {
        for (u32 x = 0; x < WIDTH; x += 1)
        {
            u32 index = y * WIDTH + x;
            ttyBuffer[index] = vga_entry(' ', ttyColor);
        }
    }
}

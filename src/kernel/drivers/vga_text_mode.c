#include <kernel/drivers/vga_text_mode.h>
#include <string.h>

static u8 vga_get_color(VgaColor fg, VgaColor bg);
static u16 vga_entry(char c, u8 color);

static const u32 WIDTH = 80;
static const u32 HEIGHT = 25;

static u32 ttyRow;
static u32 ttyColumn;
static u8 ttyColor;
static u16* ttyBuffer;

void drv_text_mode_init()
{
    ttyRow = 0;
    ttyColumn = 0;
    ttyColor = vga_get_color(VgaWhite, VgaBlack);
    ttyBuffer = (u16*)0xB8000;

    drv_text_mode_clear();
}

void drv_text_mode_set_color(u8 color)
{
    ttyColor = color;
}

void drv_text_mode_put_at(char c, u8 color, u32 x, u32 y)
{
    u32 index = y * WIDTH + x;
    ttyBuffer[index] = vga_entry(c, color);
}

void drv_text_mode_put_char(char c)
{
    if (c == '\n')
    {
        ttyRow += 1;
        ttyColumn = 0;
    }
    else
    {
        drv_text_mode_put_at(c, ttyColor, ttyColumn, ttyRow);
        ttyColumn += 1;

        if (ttyColumn == WIDTH)
        {
            ttyColumn = 0;
            ttyRow += 1;

            if (ttyRow == HEIGHT)
                ttyRow = 0;
        }
    }
}

void drv_text_mode_write(const char* data, u32 size)
{
    for (u32 i = 0; i < size; i += 1)
        drv_text_mode_put_char(data[i]);
}

void drv_text_mode_put_string(const char* data)
{
    drv_text_mode_write(data, str_len(data));
}

void drv_text_mode_put_int(int number)
{
    char str[100];
    drv_text_mode_put_string(int_to_string(number, str, 10));
}

void drv_text_mode_clear()
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

static u8 vga_get_color(VgaColor fg, VgaColor bg)
{
    return fg | bg << 4;
}

static u16 vga_entry(char c, u8 color)
{
    return (u16)c | (u16)color << 8;
}

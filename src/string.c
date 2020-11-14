#include <string.h>

u32 str_len(const char* data)
{
    u32 len = 0;
    while (data[len])
        len += 1;
    return len;
}

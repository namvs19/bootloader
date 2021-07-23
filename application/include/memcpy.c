#include "std_type.h"

void *
memcpy(void *dest, const void *src, uint8_t len)
{
    uint8_t *d = dest;
    const uint8_t *s = src;
    while (len--)
        *d++ = *s++;
    return dest;
}
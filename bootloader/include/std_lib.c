#include "std_lib.h"

uint32_t strlen(const uint8_t *str)
{
    uint32_t len = 0;

    while ((*(str + len) != ENDINGCHAR1) && (*(str + len) != ENDINGCHAR2))
    {
        len++;
    }

    return len;
}

uint8_t hexToChar(const uint8_t ch)
{
    uint8_t result;
    if ((ch >= '0') && (ch <= '9'))
    {
        result = (ch - '0');
    }
    else if ((ch >= 'A') && (ch <= 'F'))
    {
        result = (ch - 'A' + 10u);
    }
    else if ((ch >= 'a') && (ch <= 'f'))
    {
        result = (ch - 'a' + 10u);
    }
    else
    {
        result = 255u;
    }

    return result;
}

uint8_t hexToInt(const uint8_t first, const uint8_t second)
{
    uint32_t number;

    if (first > '9')
    {
        number = (first - 'A' + 10u) << 4u;
    }
    else
    {
        number = (first - '0') << 4u;
    }

    if (second > '9')
    {
        number += (second - 'A' + 10u);
    }
    else
    {
        number |= (second - '0');
    }

    return number;
}

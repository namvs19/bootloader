#include "std_type.h"

#define ENDINGCHAR1 '\r'
#define ENDINGCHAR2 '\0'

uint32_t strlen(const uint8_t *str);

uint8_t hexToInt(const uint8_t first, const uint8_t second);

uint8_t hexToChar(const uint8_t ch);

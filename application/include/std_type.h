#ifndef _STD_TYPE
#define _STD_TYPE

#ifndef _SYSTEM_BUILD
#pragma system_include
#endif

/* Fixed size types. These are all optional. */

typedef char int8_t;
typedef unsigned char uint8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;

#ifndef NULL
#define NULL ((void *)0)
#endif

#endif /* _STD_TYPE */
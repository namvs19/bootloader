#ifndef __SREC_H__
#define __SREC_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "std_type.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SREC_RECORD_LENGTH 80u

typedef enum
{
    HeaderType = '0',
    Data16BitsType = '1',
    Data24BitsType = '2',
    Data32BitsType = '3',
    Reversed = '4',
    RecordCountData16BitsType = '5',
    RecordCountData24BitsType = '6',
    Termination32BitsType = '7',
    Termination24BitsType = '8',
    Termination16BitsType = '9',
} SREC_eRecord_Type;

typedef struct
{
    uint8_t record[SREC_RECORD_LENGTH];
} SREC_Record_Type;

typedef struct
{
    uint32_t u32Address;
    uint8_t *data;
    uint8_t u8DataSize;
    uint8_t u8RecordType;
} SREC_Infomation_Type;

/*******************************************************************************
 * API
 ******************************************************************************/

uint8_t SREC_GetSrecInfo(const uint8_t *record, SREC_Infomation_Type *info);

#endif /* __SREC_H__ */
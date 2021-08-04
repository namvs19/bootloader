#include "srec.h"
#include "std_lib.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SREC_RECORDTYPE_LENGTH 2U
#define SREC_BYTECOUNT_LENGTH 2U

/** Max srec data in byte () */
#define SREC_MAX_DATA_SIZE 32u

typedef enum
{
    S1AddrLen = 4u,
    S2AddrLen = 6u,
    S3AddrLen = 8u,
} SREC_eAddressLen_Type;

typedef enum
{
    TypeRecordPos = 1u,
    ByteCountPos = 2u,
    AddressPos = 4u,
} SREC_ePosition_Type;

typedef struct
{
    uint8_t data[SREC_MAX_DATA_SIZE];
    uint8_t size;
} SREC_DataInfo_Type;

/*******************************************************************************
 * Protypes
 ******************************************************************************/
/** 
 * @brief This function will be check correction - record data and save infomation\
 * 
 * @param record pointer to the record string.
 * 
 * @return 1 if the record is legal and 0 otherwise. 
 **/
static uint8_t srec_VerifyChecksumAndSaveInfo(const uint8_t *record);

/** 
 * @brief This function will be chech record has full byte.
 * 
 * @param record pointer to the record string.
 * 
 * @return 1 if the record is legal and 0 otherwise. 
 **/
static uint8_t srec_VerifyByteCount(const uint8_t *record);

/** 
 * @brief Get address' lenght of the record type .
 * 
 * @param typeChar type of the record.
 * 
 * @return lenght of the address. 
 **/
static inline uint8_t SREC_GetAddressLen(uint8_t typeChar);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static SREC_DataInfo_Type g_Data;
static uint32_t g_u32Address;
/*******************************************************************************
 * API
 ******************************************************************************/

static inline uint8_t SREC_GetAddressLen(uint8_t typeChar)
{
    uint8_t addrLen = 0;
    switch (typeChar)
    {
    case HeaderType:
    case Data16BitsType:
    case RecordCountData16BitsType:
    case Termination16BitsType:
    {
        addrLen = 4u;
        break;
    }
    case Data24BitsType:
    case RecordCountData24BitsType:
    case Termination24BitsType:
    {
        addrLen = 6u;
        break;
    }
    case Data32BitsType:
    case Termination32BitsType:
    {
        addrLen = 6u;
        break;
    }
    }

    return addrLen;
}

static uint8_t srec_VerifyByteCount(const uint8_t *record)
{
    uint8_t u8IsValid = 1u;
    uint8_t u8RecordLen = strlen(record);

    uint8_t u8ByteCount = hexToInt(*(record + ByteCountPos),
                                   *(record + ByteCountPos + 1u))
                          << 1u;

    uint8_t u8ByteFollowByteCount = u8RecordLen -
                                    SREC_RECORDTYPE_LENGTH -
                                    SREC_BYTECOUNT_LENGTH;

    if (u8ByteCount != u8ByteFollowByteCount)
    {
        u8IsValid = 0;
    }

    return u8IsValid;
}

static uint8_t srec_VerifyChecksumAndSaveInfo(const uint8_t *record)
{
    uint8_t u8IsValid = 1u;
    uint8_t u8RecordLen = strlen(record);
    uint8_t u8CurrentIdx = (uint8_t)ByteCountPos;
    uint32_t u32CheckSum = 0;

    uint8_t u8AddressLen = SREC_GetAddressLen(record[TypeRecordPos]);
    uint8_t u8DataPos = AddressPos + u8AddressLen;
    uint8_t u8DataEndPos = u8RecordLen - 2u;

    uint8_t u8ByteBuffer;

    /** Reset state*/
    g_Data.size = 0;
    g_u32Address = 0;

    /** reset size of data for next record*/
    while (u8CurrentIdx < u8RecordLen)
    {
        /** Convert a byte from text */
        u8ByteBuffer = hexToInt(*(record + u8CurrentIdx),
                                *(record + u8CurrentIdx + 1u));
        u32CheckSum += u8ByteBuffer;

        /** Save info of srec */
        if ((u8CurrentIdx >= AddressPos) && (u8CurrentIdx < u8DataEndPos))
        {
            if (u8CurrentIdx < u8DataPos)
            {
                g_u32Address = (g_u32Address << 8u) + u8ByteBuffer;
            }
            else
            {
                g_Data.data[g_Data.size] = u8ByteBuffer;
                g_Data.size += 1u;
            }
        }

        u8CurrentIdx += 2u;
    }

    /** Verify check sum */
    if ((u32CheckSum & 0xFFu) != 0xFFu)
    {
        u8IsValid = 0;
    }

    return u8IsValid;
}

uint8_t SREC_GetSrecInfo(const uint8_t *record,
                         SREC_Infomation_Type *info)
{
    uint8_t isValid = srec_VerifyByteCount(record) &
                      srec_VerifyChecksumAndSaveInfo(record);
    uint8_t LongWordNum = g_Data.size % 4u;

    /** If data size is not a multiple of 4*/
    while (LongWordNum != 0)
    {
        g_Data.data[g_Data.size + LongWordNum] = 0xFFu;
        LongWordNum -= 1u;
    }

    info->u8RecordType = record[TypeRecordPos];
    info->u32Address = g_u32Address;
    info->data = g_Data.data;
    info->u8DataSize = g_Data.size;

    return isValid;
}

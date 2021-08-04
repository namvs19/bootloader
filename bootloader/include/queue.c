#include "queue.h"

SREC_Record_Type queue[MAX_QUEUE_SIZE];
static uint8_t g_u8Back = 0;  /** write */
static uint8_t g_u8Front = 0; /** read */
static volatile uint8_t g_u8Size = 0;

static uint8_t g_u8RecordIndex = 0;
/*******************************************************************************
 * Code
 ******************************************************************************/
__ramfunc void queue_insert(uint8_t ch){
    queue[g_u8Back] =

}

__ramfunc uint8_t
    queue_enqueue(void)
{
    uint8_t u8IsSuccess = 1u;

    /** Check queue is fully */
    if (g_u8Size < MAX_QUEUE_SIZE)
    {
        g_u8Back += 1u;
        g_u8Size += 1u;

        if (g_u8Back == MAX_QUEUE_SIZE)
        {
            g_u8Back = 0;
        }
    }
    else
    {
        u8IsSuccess = 0;
    }

    return u8IsSuccess;
}

__ramfunc uint8_t queue_dequeue(void)
{
    uint8_t u8IsSuccess = 1u;

    if (g_u8Size == 0)
    {
        u8IsSuccess = 0u;
    }
    else
    {
        g_u8Front += 1u;
        g_u8Size -= 1u;
        if (g_u8Front == MAX_QUEUE_SIZE)
        {
            g_u8Front = 0;
        }
    }

    return u8IsSuccess;
}

__ramfunc uint8_t queue_getFront(void)
{
    return (g_u8Size == 0 ? (MAX_QUEUE_SIZE + 1u) : g_u8Front);
}

__ramfunc uint8_t queue_getBack(void)
{
    return g_u8Back;
}

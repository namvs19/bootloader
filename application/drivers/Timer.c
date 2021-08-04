#include "Timer_config.h"
#include "Timer.h"
#include "std_bool.h"
#include <stdlib.h>

#if TIMER_HARDWARE == 1u
#include "PIT.h"
#else
#include "SysTick.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*
#define TIMER_ERROR_CORRECTION_PARA_U32 (44000u)
*/

#define TIME_INTERRUPT_FLAG_MASK (0x01u)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*static inline uint32_t Timer_TimeoutAdjustment(uint32_t Timeout);       */
/*******************************************************************************
 * Variables
 ******************************************************************************/
Timer_SwChannel_Type *Timer_Chnls[TIMER_MAX_CHANNELS_TIMER_U8];
static uint8_t g_ActiveChannels = 0;

#if TIMER_ERROR_CHECK_MODE == 1u
static bool_t g_bDriverStatus = FALSE;
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
/* ----------------------------------------------------------------------------
   -- Initialize
   ---------------------------------------------------------------------------- */
void Timer_InitSWTimer(void)
{
#if TIMER_HARDWARE == 1u
    /* Using PIT timer */
    PIT_Config(PIT,PIT_Chnl_0, PIT_LDVAL_1MS);
    PIT_EnableInterrupt(PIT,PIT_Chnl_0);
    NVIC_EnableIRQ(PIT_IRQn);
    PIT_StartTimer(PIT,PIT_Chnl_0);
#elif TIMER_HARDWARE == 0u
    /* Using Systick timer */
    NVIC_EnableIRQ(SysTick_IRQn);
    SysTick_Config(SYSTICK_LOADVAL_1MS);
#endif

#if TIMER_ERROR_CHECK_MODE == 1u
    g_bDriverStatus = TRUE;
#endif
}

void Timer_InitChannel(uint8_t u8ChannelID,
                       CallBack_Type CallBackFunc,
                       Timer_eSwMode_Type eMode)
{
    Timer_SwChannel_Type *pChannel = (Timer_SwChannel_Type *)malloc(sizeof(Timer_SwChannel_Type));

#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is enable software timer */
    if (g_bDriverStatus == FALSE)
    {
        free(pChannel);
        while (1)
        {
        }
    }

    /* Is correct channel ID */
    if (u8ChannelID > TIMER_MAX_CHANNELS_TIMER_U8)
    {
        free(pChannel);
        while (1)
        {
        }
    }

    /* Is enough memory to dynamically allocate*/
    if (pChannel == NULL)
    {
        while (1)
        {
        }
    }

    /* Is already channel */
    if (Timer_Chnls[u8ChannelID] != 0)
    {
        free(pChannel);
        while (1)
        {
        }
    }

    /* Mode's channel check */
    if ((eMode != ONESHOT) && (eMode != CONTINUOUS))
    {
        free(pChannel);
        while (1)
        {
        }
    }
#endif

    /* Set default state  */
    pChannel->u32TimeOut = 0;
    pChannel->u32NextTimeOut = 0;
    pChannel->u32CurrentTime = 0;
    pChannel->eMode = eMode;
    pChannel->eStatus = STOPPED;
    pChannel->CallBackFunc = CallBackFunc;
    Timer_Chnls[u8ChannelID] = pChannel;

    g_ActiveChannels += 1u;
}

/* ----------------------------------------------------------------------------
   -- Update Parameter
   ---------------------------------------------------------------------------- */
void Timer_UpdateCallback(uint8_t u8ChannelID, CallBack_Type NewCallBackFunc)
{

#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }
#endif

    /* Update new callback function */
    Timer_Chnls[u8ChannelID]->CallBackFunc = NewCallBackFunc;
}

void Timer_UpdateNextTimeOut(uint8_t u8ChannelID, uint32_t u32NextTimeOut)
{
#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }

    /* Timeout verify */
    if (u32NextTimeOut <= 0)
    {
        while (1)
        {
        }
    }

#endif

    /* Update new timeout  */
    Timer_Chnls[u8ChannelID]->u32NextTimeOut = u32NextTimeOut;
}

/* ----------------------------------------------------------------------------
   -- Start/ Stop Timer
   ---------------------------------------------------------------------------- */
void Timer_StartChannel(uint8_t u8ChannelID, uint32_t u32TimeOut)
{
#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }

    /* Timeout verify */
    if (u32TimeOut <= 0)
    {
        while (1)
        {
        }
    }
#endif

    Timer_Chnls[u8ChannelID]->u32TimeOut = u32TimeOut;
    Timer_Chnls[u8ChannelID]->u32CurrentTime = 0;
    Timer_Chnls[u8ChannelID]->eStatus = RUNNING;
}

void Timer_StopChannel(uint8_t u8ChannelID)
{
#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }
#endif

    Timer_Chnls[u8ChannelID]->eStatus = STOPPED;
}

/* ----------------------------------------------------------------------------
   -- Get Information's Channel
   ---------------------------------------------------------------------------- */
uint32_t Timer_GetTimeElapsed(uint8_t u8ChannelID)
{
#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }
#endif

    return Timer_Chnls[u8ChannelID]->u32CurrentTime;
}

uint32_t Timer_GetTimeRemain(uint8_t u8ChannelID)
{

#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }
#endif

    return (Timer_Chnls[u8ChannelID]->u32TimeOut -
            Timer_Chnls[u8ChannelID]->u32CurrentTime);
}

/* ----------------------------------------------------------------------------
   -- Deinitialize
   ---------------------------------------------------------------------------- */
void Timer_DeinitChannel(uint8_t u8ChannelID)
{
#if TIMER_ERROR_CHECK_MODE == 1u
    /* Is exist channel */
    if (Timer_Chnls[u8ChannelID] == 0)
    {
        while (1)
        {
        }
    }
#endif

    free(Timer_Chnls[u8ChannelID]);
    Timer_Chnls[u8ChannelID] = 0;
    g_ActiveChannels -= 1u;

    /* Stop hw timer */
    /* Reset default state */
}

void Timer_Deinit(void)
{
    uint8_t u8Index = 0;

    while ((u8Index < TIMER_MAX_CHANNELS_TIMER_U8) && (g_ActiveChannels > 0))
    {
        if (Timer_Chnls[u8Index] == 0)
        {
            free(Timer_Chnls[u8Index]);
            Timer_Chnls[u8Index] = 0;
            g_ActiveChannels -= 1u;
        }

        u8Index += 1u;
    }

    /* Stop hw timer */
    /* Reset default state */
#if TIMER_HARDWARE == 1u
    PIT_Deinit(PIT);
#elif TIMER_HARDWARE == 0u
    Systick_Deinit();
#endif
}

/* ----------------------------------------------------------------------------
   -- Hardware Timer Interrupt Handler
   ---------------------------------------------------------------------------- */
#if TIMER_HARDWARE == 1u
void PIT_IRQHandler(void)
{
    uint8_t u8Index = 0;
    uint8_t u8ModifiedChannels = g_ActiveChannels;

    if (PIT_GetInterruptFlag(PIT,PIT_Chnl_0) == TIME_INTERRUPT_FLAG_MASK)
    {

        PIT_ClearInterruptFlag(PIT,PIT_Chnl_0);

        while ((u8Index < TIMER_MAX_CHANNELS_TIMER_U8) && (u8ModifiedChannels > 0))
        {
            if ((Timer_Chnls[u8Index] != 0) && (Timer_Chnls[u8Index]->eStatus == RUNNING))
            {
                Timer_Chnls[u8Index]->u32CurrentTime += 1u;
                u8ModifiedChannels -= 1u;

                if (Timer_Chnls[u8Index]->u32CurrentTime == Timer_Chnls[u8Index]->u32TimeOut)
                {
                    /* Interrupt software timer */
                    (*(Timer_Chnls[u8Index]->CallBackFunc))();
                    Timer_Chnls[u8Index]->u32CurrentTime = 0;

                    /* If user  */
                    if (Timer_Chnls[u8Index]->u32NextTimeOut != 0)
                    {
                        Timer_Chnls[u8Index]->u32TimeOut = Timer_Chnls[u8Index]->u32NextTimeOut;
                        Timer_Chnls[u8Index]->u32NextTimeOut = 0;
                    }
                }
            }
            u8Index += 1u;
        }
    }
}
#elif TIMER_HARDWARE == 0u
void SysTick_Handler(void)
{
    uint8_t u8Index = 0;
    uint8_t u8ModifiedChannels = g_ActiveChannels;

    while ((u8Index < TIMER_MAX_CHANNELS_TIMER_U8) && (u8ModifiedChannels > 0))
    {
        if ((Timer_Chnls[u8Index] != 0) && (Timer_Chnls[u8Index]->eStatus == RUNNING))
        {
            Timer_Chnls[u8Index]->u32CurrentTime += 1u;
            u8ModifiedChannels -= 1u;

            if (Timer_Chnls[u8Index]->u32CurrentTime == Timer_Chnls[u8Index]->u32TimeOut)
            {
                (*(Timer_Chnls[u8Index]->CallBackFunc))();
                Timer_Chnls[u8Index]->u32CurrentTime = 0;

                if (Timer_Chnls[u8Index]->u32NextTimeOut != 0)
                {
                    Timer_Chnls[u8Index]->u32TimeOut = Timer_Chnls[u8Index]->u32NextTimeOut;
                    Timer_Chnls[u8Index]->u32NextTimeOut = 0;
                }
            }
        }
        u8Index += 1u;
    }
}

#endif

/*
 *static inline uint32_t Timer_TimeoutAdjustment(uint32_t Timeout)
 *{
 *    return (Timeout - (uint32_t)(Timeout / TIMER_ERROR_CORRECTION_PARA_U32));
 *}
*/
#ifndef __TPM_H__
#define __TPM_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hardware_MKL46Z4.h"
#include "std_type.h"
#include "std_bool.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* TPM Clock Source Select */
typedef enum
{
    eTPMSource_Disable = 0u,     /* Clock disabled */
    eTPMSource_FLL_PLLDIV2 = 1u, /* MCGFLLCLK clock or MCGPLLCLK/2 */
    eTPMSource_External = 2u,    /* OSCERCLK clock */
    eTPMSource_Internal = 3u,    /* MCGIRCLK clock */
} TPM_eClkSource_Type;

typedef enum
{
    eTPM_Disable = 0u,      /* TPM counter is disabled */
    eTPM_Module_Clk = 1u,   /* TPM counter increments on every TPM counter clock */
    eTPM_External_Clk = 2u, /* TPM counter increments on rising edge
                             * of TPM_EXTCLK synchronized to the TPM counter clock */
} TPM_eClkMode_Type;

typedef enum
{
    ePrescale_Divide_1 = 0u,
    ePrescale_Divide_2 = 1u,
    ePrescale_Divide_4 = 2u,
    ePrescale_Divide_8 = 3u,
    ePrescale_Divide_16 = 4u,
    ePrescale_Divide_32 = 5u,
    ePrescale_Divide_64 = 6u,
    ePrescale_Divide_128 = 7u,
} TPM_eClkPrescale_Type;

typedef enum
{
    eChnl_0 = 0u,
    eChnl_1 = 1u,
    eChnl_2 = 2u,
    eChnl_3 = 3u,
    eChnl_4 = 4u,
    eChnl_5 = 5u,
    eChnl_6 = 6u,
    eChnl_7 = 7u,
} TPM_eChannel_Type;

/* State of bit */
typedef enum
{
    eDisable = 0u,
    eEnable = 1u,
} TPM_eStatus_Type;

/* Center-aligned PWM Select */
typedef enum
{
    eUp = 0u,
    eUp_Down = 1u,
} TPM_eCPWMS_Type;

typedef enum
{
    ePause = 0u,    /*TPM counter is paused and does not increment during debug mode*/
    eContinue = 3u, /*TPM counter continues in debug mode. */
} TPM_eDebugMode_Type;

/*Trigger Select - Selects the input trigger*/
typedef enum
{
    eTrigger_ExtPin_input = 0u,
    eTrigger_CMP0_output = 1u,
    eTrigger_PIT_0 = 4u,
    eTrigger_PIT_1 = 5u,
    eTrigger_TPM0_overflow = 8u,
    eTrigger_TPM1_overflow = 9u,
    eTrigger_TPM2_overflow = 10u,
    eTrigger_RTC_alarm = 12u,
    eTrigger_RTC_seconds = 13u,
    eTrigger_LPTMR = 14u,
} TPM_eTriggerSel_Type;

/* Configuration struct for init TPM */
typedef struct
{
    TPM_eStatus_Type enableDMA : 1;
    TPM_eStatus_Type enableOverflowInterrupt : 1;
    TPM_eCPWMS_Type countingMode : 1;
    TPM_eClkPrescale_Type prescale : 3;
    TPM_eTriggerSel_Type triggerSel : 4;
    TPM_eStatus_Type enableReloadOnTrigger : 1;
    TPM_eStatus_Type enableStopOnOverflow : 1;
    TPM_eStatus_Type enableStartOnTrigger : 1;
    TPM_eStatus_Type enableGlobalTimeBase : 1;
    TPM_eDebugMode_Type enableDebugMode : 2;
    TPM_eStatus_Type enableDoze : 1;
} TPM_Config_Type;

/*******************************************************************************
 * API
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- Initialization and deinitialization
   ---------------------------------------------------------------------------- */
static inline void TPM_GetDefaultConfig(TPM_Config_Type *config)
{
    config->enableDMA = eDisable;
    config->enableOverflowInterrupt = eDisable;
    config->countingMode = eUp;
    config->prescale = ePrescale_Divide_1;
    config->triggerSel = eTrigger_ExtPin_input;
    config->enableReloadOnTrigger = eDisable;
    config->enableStopOnOverflow = eDisable;
    config->enableStartOnTrigger = eDisable;
    config->enableGlobalTimeBase = eDisable;
    config->enableDebugMode = ePause;
    config->enableDoze = eDisable;
}

/*!
 * @brief Ungates the TPM clock and configures the peripheral for basic operation.
 *
 * @note This API should be called at the beginning of the application using the TPM driver.
 *
 * @param base   TPM peripheral base address
 */
static inline void TPM_Init(TPM_Type *base, const TPM_Config_Type config)
{
    switch ((uint32_t)base)
    {
    case (uint32_t)TPM0:
    {
        SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
        break;
    }
    case (uint32_t)TPM1:
    {
        SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;
        break;
    }
    case (uint32_t)TPM2:
    {
        SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;
        break;
    }

    default:
    {
        while (1)
        {
        }
    }
    }

    base->SC = TPM_SC_DMA(config.enableDMA) |
               TPM_SC_TOIE(config.enableOverflowInterrupt) |
               TPM_SC_CPWMS(config.countingMode) |
               TPM_SC_PS(config.prescale);

    base->CONF = TPM_CONF_TRGSEL(config.triggerSel) |
                 TPM_CONF_CROT(config.enableReloadOnTrigger) |
                 TPM_CONF_CSOO(config.enableStopOnOverflow) |
                 TPM_CONF_CSOT(config.enableStartOnTrigger) |
                 TPM_CONF_GTBEEN(config.enableGlobalTimeBase) |
                 TPM_CONF_DBGMODE(config.enableDebugMode) |
                 TPM_CONF_DOZEEN(config.enableDoze);
}

/*!
 * @brief Stops the counter and gates the TPM clock
 *
 * @param base TPM peripheral base address
 */
static inline void TPM_Deinit(TPM_Type *base)
{

    base->SC = 0;
    base->CONF = 0;

    switch ((uint32_t)base)
    {
    case (uint32_t)TPM0:
    {
        SIM->SCGC6 &= ~SIM_SCGC6_TPM0_MASK;
        break;
    }
    case (uint32_t)TPM1:
    {
        SIM->SCGC6 &= ~SIM_SCGC6_TPM1_MASK;
        break;
    }
    case (uint32_t)TPM2:
    {
        SIM->SCGC6 &= ~SIM_SCGC6_TPM2_MASK;
        break;
    }

    default:
    {
        while (1)
        {
        }
    }
    }
}

/*!
 * @brief Set TPM clock source.
 *
 * @param ClockSource The value to set TPM clock source.
 */
static inline void TPM_SetClockSource(TPM_eClkSource_Type ClockSource)
{
    SIM->SOPT2 = ((SIM->SOPT2 & ~SIM_SOPT2_TPMSRC_MASK) | SIM_SOPT2_TPMSRC(ClockSource));
}

/* ----------------------------------------------------------------------------
   -- Read and write the timer period
   ---------------------------------------------------------------------------- */
/*!
 * @brief Sets the timer period in units of ticks.
 *
 * @param base TPM peripheral base address
 * @param ticks A timer period in units of ticks, which should be equal or greater than 1.
 */
static inline void TPM_SetTimerPeriod(TPM_Type *base, uint32_t ticks)
{
    base->MOD = ticks - 1u;
}

/*!
 * @brief Reads the current timer counting value.
 *
 * @param base TPM peripheral base address
 *
 * @return The current counter value in ticks
 */
static inline uint32_t TPM_GetCurrentTimerCount(TPM_Type *base)
{
    return (uint32_t)((base->CNT & TPM_CNT_COUNT_MASK) >> TPM_CNT_COUNT_SHIFT);
}

/*!
 * @brief Resets the current timer counting value.
 *
 * @param base TPM peripheral base address
 */
static inline void TPM_ResetCurrentTimerCount(TPM_Type *base)
{
    base->CNT = 0;
}

/* ----------------------------------------------------------------------------
   -- Timer Start and Stop
   ---------------------------------------------------------------------------- */
/*!
 * @brief Starts the TPM counter.
 *
 *
 * @param base        TPM peripheral base address
 * @param clockSource TPM clock source; once clock source is set the counter will start running
 */
static inline void TPM_StartTimer(TPM_Type *base, TPM_eClkMode_Type mode)
{
    base->SC |= TPM_SC_CMOD(mode);
}

/*!
 * @brief Stops the TPM counter.
 *
 * @param base TPM peripheral base address
 */
static inline void TPM_StopTimer(TPM_Type *base)
{
    /* Set clock source to none to disable counter */
    base->SC &= ~(TPM_SC_CMOD_MASK);

    /* Wait till this reads as zero acknowledging the counter is disabled */
    while (base->SC & TPM_SC_CMOD_MASK)
    {
    }
}

/*!
 * @brief Clear overload flag of the TPM counter.
 *
 * @param base TPM peripheral base address
 */
static inline void TPM_ClearOverflowFlag(TPM_Type *base)
{
    base->SC |= TPM_SC_TOF_MASK;
}

#endif /* __TPM_H__ */
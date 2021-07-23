#ifndef _PIT_H_
#define _PIT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hardware_MKL46Z4.h"
#include "std_type.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    PIT_Chnl_0 = 0,
    PIT_Chnl_1 = 1
} ePIT_Chnl_Type;

#define PIT_LDVAL_1S (0xA00000u)

/* Actually, 5242.88*2 pulses will be taken in 1ms */
#define PIT_LDVAL_1MS (0x28F6u)

#define PIT_MCR_DEFAULT (0x06u)
#define PIT_LDVAL_DEFAULT (0x00u)
#define PIT_TCTRL_DEFAULT (0x00u)

/*******************************************************************************
 * API
 ******************************************************************************/
/*! @name MCR - PIT Module Control Register */

/*!
 * @brief Ungates the PIT clock, enables the PIT module.
 *
 */
static inline void PIT_EnableModule(PIT_Type *base)
{
    SIM->SCGC6 |= 1 << 23u;
    base->MCR = PIT_MCR_MDIS(0);
}

static inline void PIT_DisableMoudle(PIT_Type *base)
{
    base->MCR = PIT_MCR_MDIS(1);
}

/*! @name LTMR64H - PIT Upper Lifetime Timer Register */
static inline uint32_t PIT_GetUpperLifeTime(PIT_Type *base)
{

    return base->LTMR64H;
}

/*! @name LTMR64L - PIT Lower Lifetime Timer Register */
static inline uint32_t PIT_GetLowerLifeTime(PIT_Type *base)
{
    return base->LTMR64L;
}

/*! @name LDVAL - Timer Load Value Register */
/*!
 * @brief Sets the timer period in units of count.
 *
 * @param channel Timer channel number.
 * @param ticks   Timer period in units of ticks
 */
static inline void PIT_SetTimerPeriod(PIT_Type *base, ePIT_Chnl_Type channel, uint32_t ticks)
{
    base->CHANNEL[channel].LDVAL = ticks - 1u;
}

/*! @name CVAL - Current Timer Value Register */
/*!
 * @brief Reads the current timer counting value.
 *
 * @param channel Timer channel number
 *
 * @return Current timer counting value in ticks
 */
static inline uint32_t PIT_GetCurrentTimeCount(PIT_Type *base, ePIT_Chnl_Type channel)
{
    return base->CHANNEL[channel].CVAL;
}

/*! @name TCTRL - Timer Control Register */
/*!
 * @brief Enable the PIT Chain mode.
 *
 * @param channel Timer channel number
 */
static inline void PIT_EnableChainMode(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TCTRL |= PIT_TCTRL_CHN(1);
}

/*!
 * @brief Disables the PIT Chain mode.
 *
 * @param channel Timer channel number
 */
static inline void PIT_DisableChainMode(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TCTRL &= ~PIT_TCTRL_CHN_MASK;
}

/*!
 * @brief Enables the selected PIT interrupts.
 *
 * @param channel Timer channel number
 */
static inline void PIT_EnableInterrupt(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TCTRL |= PIT_TCTRL_TIE(1);
}

/*!
 * @brief Disables the selected PIT interrupts.
 *
 * @param channel Timer channel number
 * 
 */
static inline void PIT_DisableInterrupt(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TCTRL &= ~PIT_TCTRL_TIE_MASK;
}

/*!
 * @brief Starts the timer counting.
 *
 * @param channel Timer channel number.
 */
static inline void PIT_StartTimer(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TCTRL |= PIT_TCTRL_TEN(1);
}

/*!
 * @brief Stops the timer counting.
 *
 * @param channel Timer channel number.
 */
static inline void PIT_StopTimer(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TCTRL &= ~PIT_TCTRL_TEN_MASK;
}

/*! @name TFLG - Timer Flag Register */

/*!
 * @brief Gets the PIT status flags.
 *
 * @param channel Timer channel number
 *
 * @return The status flags.
 */
static inline uint32_t PIT_GetInterruptFlag(PIT_Type *base, ePIT_Chnl_Type channel)
{
    return base->CHANNEL[channel].TFLG;
}

/*!
 * @brief  Clears the PIT status flags.
 *
 * @param channel Timer channel number
 */
static inline void PIT_ClearInterruptFlag(PIT_Type *base, ePIT_Chnl_Type channel)
{
    base->CHANNEL[channel].TFLG |= 0x1u;
}

/*!
 * @brief Ungates the PIT clock, enables the PIT module, and configures the peripheral for basic operations.
 *
 * @note This API should be called at the beginning of the application using the PIT driver.
 *
 * @param channel Timer channel number
 * @param ticks   Timer period in units of ticks
 */
static inline void PIT_Config(PIT_Type *base, ePIT_Chnl_Type channel, uint32_t ticks)
{
    PIT_EnableModule(base);
    PIT_SetTimerPeriod(base, channel, ticks);
}

static inline void PIT_Deinit(PIT_Type *base)
{
    base->MCR = PIT_MCR_MDIS(1);
    SIM->SCGC6 &= ~(1 << 23u);
}
#endif /* _PIT_H_ */

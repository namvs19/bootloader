#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "hardware_MKL46Z4.h"

typedef enum
{
    Clock_IRCSlow = 0u,
    Clock_IRCFast = 1u,
} Clock_eInternalRC_Type;

typedef enum
{
    Clock_FastRCDiv1 = 0u,
    Clock_FastRCDiv2 = 1u,
    Clock_FastRCDiv4 = 2u,
    Clock_FastRCDiv8 = 3u,
    Clock_FastRCDiv16 = 4u,
    Clock_FastRCDiv32 = 5u,
    Clock_FastRCDiv64 = 6u,
    Clock_FastRCDiv128 = 7u,

} Clock_eFastIRCDivider_Type;

typedef enum
{
    Clock_OSC_LowPrev = 0u,
    Clock_OSC_HighPrev = 1u,
    Clock_OSC_VeryHighPrev = 2u,
} Clock_eOSC_FrevRange_Type;

typedef enum
{
    Clock_eLowPower = 0u,
    Clocl_eHighGain = 1u,
} Clock_HighGainOSC_Type;

/**
 * @brief Enable IRC clock source and set divider for fast RC
 *
 * @param source select fast or slow RC source.
 * @param divider select divider for fast RC,
 *                at slow RC this param will passed user can pass any value
 *
*/
static inline void Clock_EnableIRC(Clock_eInternalRC_Type source,
                                   Clock_eFastIRCDivider_Type divider)
{
    /** Enable IRC clock */
    MCG->C1 |= MCG_C1_IRCLKEN_MASK;

    /** IRC select source */
    if (source == Clock_IRCSlow)
    {
        MCG->C2 &= ~MCG_C2_IRCS_MASK;
    }
    else
    {
        MCG->C2 |= MCG_C2_IRCS_MASK;
        MCG->SC &= ~MCG_SC_FCRDIV_MASK;
        MCG->SC |= MCG_SC_FCRDIV(divider);
    }

    /** Wait until source is selected successfully */
    while ((MCG->S & MCG_S_IRCST_MASK) != ((uint8_t)source << MCG_S_IRCST_SHIFT))
    {
        ;
    }
}

static inline void Clock_EnableOSC(Clock_eOSC_FrevRange_Type prevRange, Clock_HighGainOSC_Type powerMode)
{
    /* Select frequency range */
    MCG->C2 &= ~MCG_C2_RANGE0_MASK;
    MCG->C2 |= MCG_C2_RANGE0(prevRange);

    /**  */
    MCG->C2 &= ~MCG_C2_HGO_MASK;
    MCG->C2 |= MCG_C2_HGO(powerMode);

    /* Select oscillator is external reference clock source */
    MCG->C2 |= MCG_C2_EREFS0_MASK;

    OSC0->CR |= OSC_CR_ERCLKEN_MASK;

    while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0u)
        ;
}

#endif /* _CLOCK_H_ */
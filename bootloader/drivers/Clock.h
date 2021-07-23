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

void Clock_SwitchFEI(void);
void Clock_SwitchFEE(void);
void Clock_SwitchFBI(void);
void Clock_SwitchFBE(void);

#endif /* _CLOCK_H_ */
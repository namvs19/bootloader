#include "hardware_MKL46Z4.h"

typedef enum
{
    MCG_Clock_FEI = 0u,
    MCG_Clock_FEE,
    MCG_Clock_FBI,
    MCG_Clock_FBE,
} Clock_MCG_FLLMode_Type;

volatile Clock_MCG_FLLMode_Type g_CurrentMode = MCG_Clock_FEI;

void Clock_SwitchFEI(void)
{
    switch (g_CurrentMode)
    {
    case MCG_Clock_FEE:
    {
        /* Configuration FLL using internal reference clock */
        MCG->C1 |= MCG_C1_IREFS_MASK;

        /* Because in FEE mode, core using clock from FLL block,
         * so dont need to configure again
         * MCG->C1 &= ~MCG_C1_CLKS_MASK;
         */

        break;
    }
    case MCG_Clock_FBI:
    {
        break;
    }
    case MCG_Clock_FBE:
    {
        break;
    }
    }

    /* Wait for clock mode is output of FLL */
    while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(0u))
    {
        ;
    }

    /* Select FLL runing in low-range */
    MCG->C4 &= ~MCG_C4_DRST_DRS_MASK;

    /* Select FLL output frequency range
     * with internal reference clock
     * and low-range, FLL_fractor = 640 */
    MCG->C4 &= ~MCG_C4_DMX32_MASK;

    g_CurrentMode = MCG_Clock_FEI;
}

void Clock_SwitchFEE(void)
{
    switch (g_CurrentMode)
    {
    case MCG_Clock_FEI:
    {
        /* Enable OSC block  */
        OSC0->CR |= OSC_CR_ERCLKEN_MASK;
        /* Select very high frequency range */

        MCG->C2 &= ~MCG_C2_RANGE_MASK;

        MCG->C2 |= MCG_C2_RANGE(2);
        /* Configure the crystal oscillator for high gain operation */
        MCG->C2 |= MCG_C2_HGO0_MASK;
        /* Select OSC is external reference clock */
        MCG->C2 |= MCG_C2_EREFS0_MASK;

        /* Choose external reference clock divider for FLL FRDIV = 256 */
        MCG->C1 &= ~MCG_C1_FRDIV_MASK;
        MCG->C1 |= MCG_C1_FRDIV(3u);

        /* Configuration FLL using external reference clock */
        MCG->C1 &= ~MCG_C1_IREFS_MASK;

        /* Because in FEI mode, core using clock from FLL block,
         * so dont need to configure again
         * MCG->C1 &= ~MCG_C1_CLKS_MASK;
         */

        break;
    }
    case MCG_Clock_FBI:
    {
        break;
    }

    case MCG_Clock_FBE:
    {
        break;
    }
    }

    /* Wait for osc stable */
 //   while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0u)
    {
        ;
    }

    /* Wait for external reference is the current source of FLL output */
    while ((MCG->S & MCG_S_IREFST_MASK) == 1u)
    {
        ;
    }

    /* Wait for clock mode is output of FLL */
    while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(0u))
    {
        ;
    }

    /* Select FLL runing in Mid-range */
    MCG->C4 &= ~MCG_C4_DRST_DRS_MASK;
    MCG->C4 |= MCG_C4_DRST_DRS(1u);

    /* Select FLL output frequency range
     * with external reference clock
     * and mid-range, FLL_fractor = 1280 */
    MCG->C4 &= ~MCG_C4_DMX32_MASK;

    g_CurrentMode = MCG_Clock_FEE;
}
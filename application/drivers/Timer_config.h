#ifndef _TIMER_CFG_H_
#define _TIMER_CFG_H_
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* User can modify max channel of timer to save memory. 
 * Channels range depend on your hardware memory storage,
 * But for effectiveness, we recommend max channels in the range [0..90]
 */
#define TIMER_MAX_CHANNELS_TIMER_U8 (10u)

/* User can enable or disable check error mode,
 * But we recommend this option will be enabled in product development time.
 * And disable in release production.
 * 0: Disable, 1: Enable */
#define TIMER_ERROR_CHECK_MODE 0u

/* Choose hardware resources used for software timer */
/* 0: SysTick timer, 1: PIT timer */
#define TIMER_HARDWARE 1u

#endif /* _TIMER_CFG_H_ */

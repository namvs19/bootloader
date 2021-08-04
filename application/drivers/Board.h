#ifndef _BOARD_H_
#define _BOARD_H_

#include "GPIO.h"

/*******************************************************************************
 *  FRDM-KL46Z Board Pheripheral
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- LED
   ---------------------------------------------------------------------------- */
#define BOARD_GREEN_LED_PORT (PORTD)
#define BOARD_GREEN_LED_GPIO (GPIOD)
#define BOARD_GREEN_LED_PIN (5u)

#define BOARD_RED_LED_PORT (PORTE)
#define BOARD_RED_LED_GPIO (GPIOE)
#define BOARD_RED_LED_PIN (29u)

#define BOARD_RED_LED_ON \
    GPIO_WritePin(BOARD_RED_LED_GPIO, BOARD_RED_LED_PIN, GPIO_Low)
#define BOARD_GREEN_LED_ON \
    GPIO_WritePin(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN, GPIO_Low)
#define BOARD_RED_LED_OFF \
    GPIO_WritePin(BOARD_RED_LED_GPIO, BOARD_RED_LED_PIN, GPIO_High)
#define BOARD_GREEN_LED_OFF \
    GPIO_WritePin(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN, GPIO_High)
#define BOARD_RED_LED_TOGGLE \
    GPIO_TogglePin(BOARD_RED_LED_GPIO, BOARD_RED_LED_PIN)
#define BOARD_GREEN_LED_TOGGLE \
    GPIO_TogglePin(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN)
/*!
 * @brief initliaze source and pin configuration for led pin.
 */
static inline void Board_LedInit(void)
{
    /* Enable clock source for PORTD, PORTE */
    SIM->SCGC5 |= (SIM_SCGC5_PORTD_MASK |
                   SIM_SCGC5_PORTE_MASK);

    /* Set the PTE29, PTD5 pin multiplexer to GPIO mode */
    PORT_SetMux(BOARD_RED_LED_PORT, BOARD_RED_LED_PIN, PORT_Mux_gpio);
    PORT_SetMux(BOARD_GREEN_LED_PORT, BOARD_GREEN_LED_PIN, PORT_Mux_gpio);

    /* Set the pin's direction to output */
    GPIO_PinInit(BOARD_RED_LED_GPIO, BOARD_RED_LED_PIN, GPIO_Output);
    GPIO_PinInit(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN, GPIO_Output);

    /* Turn the led off */
    BOARD_RED_LED_OFF;
    BOARD_GREEN_LED_OFF;
}

/* ----------------------------------------------------------------------------
   -- SWITCH
   ---------------------------------------------------------------------------- */
#define BOARD_SW_PORT (PORTC)
#define BOARD_SW1_PIN (3u)
#define BOARD_SW2_PIN (12u)

/*!
 * @brief Enable clock source and initialize pin will be used for switch.
 */
static inline void Board_SwitchInit(void)
{
    /* Enable clock source for PORTC */
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

    /* Set the PTC3, PTC12 pin multiplexer to GPIO mode */
    PORT_SetMux(BOARD_SW_PORT, BOARD_SW1_PIN, PORT_Mux_gpio);
    PORT_SetMux(BOARD_SW_PORT, BOARD_SW2_PIN, PORT_Mux_gpio);

    PORT_SetPull(BOARD_SW_PORT, BOARD_SW1_PIN, PORT_PullUp);
    PORT_SetPull(BOARD_SW_PORT, BOARD_SW2_PIN, PORT_PullUp);

    /* Set the pin's direction to input */
    GPIO_PinInit(GPIOC, BOARD_SW1_PIN, GPIO_Input);
    GPIO_PinInit(GPIOC, BOARD_SW2_PIN, GPIO_Input);
}

static inline void Board_SwitchDeinit(void)
{
    SIM->SCGC5 &= ~SIM_SCGC5_PORTC_MASK;

    PORT_SetMux(BOARD_SW_PORT, BOARD_SW1_PIN, PORT_Mux_disable);
    PORT_SetMux(BOARD_SW_PORT, BOARD_SW2_PIN, PORT_Mux_disable);
}

static inline void Board_LedDeinit(void)
{
    SIM->SCGC5 &= ~SIM_SCGC5_PORTD_MASK;
    SIM->SCGC5 &= ~SIM_SCGC5_PORTE_MASK;

    PORT_SetMux(BOARD_RED_LED_PORT, BOARD_RED_LED_PIN, PORT_Mux_disable);
    PORT_SetMux(BOARD_GREEN_LED_PORT, BOARD_GREEN_LED_PIN, PORT_Mux_disable);

    GPIO_PinInit(BOARD_RED_LED_GPIO, BOARD_RED_LED_PIN, GPIO_Input);
    GPIO_PinInit(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN, GPIO_Input);
}
#endif /* _BOARD_H_ */

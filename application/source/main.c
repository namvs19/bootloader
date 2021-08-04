
/******************************************************************************
 * Includes
 *****************************************************************************/
#include "Timer.h"
#include "Board.h"
/******************************************************************************
 * Definations
 *****************************************************************************/
/******************************************************************************
 * Prototypes
 *****************************************************************************/
/* Callback function controll red led */
void RedLedHandler(void);

/******************************************************************************
 * Variable
 *****************************************************************************/

/******************************************************************************
 * Code
 *****************************************************************************/
int main(void)
{
    /* Initialize led peripheral */
    Board_LedInit();

    /* Initialize software timer */
    Timer_InitSWTimer();

    /* Initialize channels */
    Timer_InitChannel(0, &RedLedHandler, CONTINUOUS);

    /* Start software timer channels */
    Timer_StartChannel(0, 500u);

    while (1)
    {
    }
}

/* Callback function controll red led */
void RedLedHandler(void)
{
    BOARD_RED_LED_TOGGLE;
}

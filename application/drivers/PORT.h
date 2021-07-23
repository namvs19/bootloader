#ifndef _PORT_H_
#define _PORT_H_

#include "hardware_MKL46Z4.h"
#include "std_type.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    PORT_PullDisable = 0,
    PORT_PullDown = 0x02,
    PORT_PullUp = 0x03u,
} PORT_ePull_Type;

typedef enum
{
    PORT_Mux_disable = 0,
    PORT_Mux_gpio = 1u,
    PORT_Mux_al2 = 2u,
    PORT_Mux_al3 = 3u,
    PORT_Mux_al4 = 4u,
    PORT_Mux_al5 = 5u,
    PORT_Mux_al6 = 6u,
    PORT_Mux_al7 = 7u,
} PORT_eMuxControl_Type;

typedef enum
{
    PORT_Interrupt_disable = IRQC_DMA_DISABLE,
    PORT_DMARisingEdge = IRQC_DMA_RISING,
    PORT_DMAFallingEdge = IRQC_DMA_FALLING,
    PORT_DMAEitherEdge = IRQC_DMA_CHANGE,
    PORT_IRQLogicZero = IRQC_LOGIC_ZERO,
    PORT_IRQRisingEdge = IRQC_RISING,
    PORT_IRQFallingEdge = IRQC_FALLING,
    PORT_IRQEitherEdge = IRQC_CHANGE,
    PORT_IRQLogicOne = IRQC_LOGIC_ONE,
} PORT_eInterruptCfg_Type;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Sets mux pin of the port.
 *
 * @param port  PORT peripheral base pointer.
 * @param pin   PORT pin number macro
 * @param mux   PORT mux control.
 */
static inline void PORT_SetMux(PORT_Type *port, uint32_t pin, PORT_eMuxControl_Type mux)
{
    port->PCR[pin] |= (mux << PORT_PCR_MUX_SHIFT);
}

/*!
 * @brief Sets pull up/down pin of the port.
 *
 * @param port  PORT peripheral base pointer.
 * @param pin   PORT pin number macro
 * @param mode  PORT pin pull option.
 */
static inline void PORT_SetPull(PORT_Type *port, uint32_t pin, PORT_ePull_Type mode)
{
    port->PCR[pin] |= (mode << PORT_PCR_PS_SHIFT);
}

/*!
 * @brief Gets interrupt flag of the pin of the port.
 *
 * @param port  PORT peripheral base pointer.
 * @param pin   PORT pin number macro
 *
 * @return 1 if interrupt detected, 0 otherwise.
 */
static inline uint32_t PORT_GetInterruptFlag(PORT_Type *port, uint32_t pin)
{
    return ((port->ISFR >> pin) & 0x01U);
}

/*!
 * @brief Clears interrupt flag of the pin of the port.
 *
 * @param port  PORT peripheral base pointer.
 * @param pin   PORT pin number macro
 */
static inline void PORT_ClearInterruptFlag(PORT_Type *port, uint32_t pin)
{
    port->ISFR |= (1u << pin);
}

/*!
 * @brief Clears interrupt flag of the pin of the port.
 *
 * @param port  PORT peripheral base pointer.
 * @param pin   PORT pin number.
 * @param type  PORT pin type interrupt configuration.
 */
static inline void PORT_ConfigInterrupt(PORT_Type *port, uint32_t pin, PORT_eInterruptCfg_Type type)
{
    port->PCR[pin] |= PORT_PCR_IRQC(type);
}
#endif /* _PORT_H_ */

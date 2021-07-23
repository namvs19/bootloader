#ifndef _GPIO_H_
#define _GPIO_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hardware_MKL46Z4.h"
#include "PORT.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    GPIO_Input = 0u,
    GPIO_Output = 1u,
} GPIO_ePinDirection_Type;

typedef enum
{
    GPIO_Low = 0,
    GPIO_High = 1,
} GPIO_ePinState_Type;
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Writes multi pins of the GPIO port.
 *
 * @param gpio   GPIO peripheral base pointer.
 * @param mask   GPIO pin number macro
 */
static inline void GPIO_SetPort(GPIO_Type *gpio, uint32_t mask)
{
    gpio->PSOR = mask;
}

/*!
 * @brief Writes multi pins of the GPIO port.
 *
 * @param gpio   GPIO peripheral base pointer.
 * @param mask   GPIO pin number macro
 */
static inline void GPIO_ClearPort(GPIO_Type *gpio, uint32_t mask)
{
    gpio->PCOR = mask;
}

/*!
 * @brief Writes multi pins of the GPIO port.
 *
 * @param gpio   GPIO peripheral base pointer.
 * @param mask   GPIO pin number macro
 */
static inline void GPIO_TogglePort(GPIO_Type *gpio, uint32_t mask)
{
    gpio->PTOR = mask;
}

/*!
 * @brief Reads multi pins of the GPIO port.
 *
 * @param gpio   GPIO peripheral base pointer.
 * @param mask   GPIO pin number macro
 */
static inline uint32_t GPIO_ReadPort(GPIO_Type *gpio, uint32_t mask)
{
    return (gpio->PDIR & mask);
}

/*!
 * @brief Sets the output level of the GPIO pin to the logic 1 or 0.
 *
 * @param gpio    GPIO peripheral base pointer.
 * @param pin     GPIO pin number
 * @param value   GPIO pin output logic level.
 */
static inline void GPIO_WritePin(GPIO_Type *gpio, uint32_t pin, GPIO_ePinState_Type state)
{
    if (state == GPIO_Low)
    {
        gpio->PCOR |= (1u << pin);
    }
    else
    {
        gpio->PSOR |= (1u << pin);
    }
}

/*!
 * @brief Toggles the output level of the GPIO pin.
 *
 * @param gpio    GPIO peripheral base pointer.
 * @param pin     GPIO pin number
 */
static inline void GPIO_TogglePin(GPIO_Type *gpio, uint32_t pin)
{
    gpio->PTOR |= (1u << pin);
}

/*!
 * @brief Reads the current input value of the GPIO port.
 *
 * @param gpio GPIO peripheral base pointer.
 * @param pin  GPIO pin number
 * 
 * @return GPIO port input value.
 */
static inline uint32_t GPIO_ReadPin(GPIO_Type *gpio, uint32_t pin)
{
    return (((gpio->PDIR) >> pin) & 0x01U);
}

/*!
 * @brief Initializes a GPIO pin used by the board.
 * @param port   GPIO peripheral base pointer.
 * @param pin    GPIO port pin number
 * @param direct GPIO pin direction.
 */
static inline void GPIO_PinInit(GPIO_Type *gpio, uint32_t pin, GPIO_ePinDirection_Type direct)
{
    if (direct == GPIO_Output)
    {
        gpio->PDDR |= (1u << pin);
        GPIO_WritePin(gpio, pin, GPIO_Low);
    }
    else
    {
        gpio->PDDR &= ~(1u << pin);
    }
}

#endif /* _GPIO_H_ */

#ifndef __UART0_H__
#define __UART0_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "hardware_MKL46Z4.h"
#include "std_bool.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define UART0_PORT PORTA
#define UART0_PIN_TX 1u
#define UART0_PIN_RX 2u

#define UART_ENDINGCHAR ('\r')

typedef enum
{
    UART0_OneStopBit = 0u,
    UART0_TwoStopBit = 1u,
} UART0_eStopBit_Type;

typedef enum
{
    UART0_8bit = 0,
    UART0_9bit = 1u,
    UART0_10bit = 2u,
} UART0_eDataSize_Type;

typedef enum
{
    UART0_ParityDisabled = 0u,
    UART0_ParityEven = 2u,
    UART0_ParityOdd = 3u,
} UART0_eParityMode_Type;

typedef enum
{
    Clock_Disable = 0u,
    Clock_MCGFLLPLL = 1u,
    Clock_OSCERCLK = 2u,
    Clock_MCGIRCLK = 3u,
} UART0_eClockSoure_Type;

typedef enum
{
    eDisable = 0u,
    eEnable = 1u,
} UART0_eState_Type;

typedef struct
{
    UART0_eStopBit_Type stopBit;
    UART0_eDataSize_Type dataSize;
    UART0_eParityMode_Type parity;
    UART0_eState_Type enableTransmitInterrupt;
    UART0_eState_Type enableTXCompleteInterrupt;
    UART0_eState_Type enableReceiveInterrupt;
    UART0_eState_Type enableIDLEInterrupt;
    UART0_eState_Type enableOverunInterrupt;
    UART0_eState_Type enableNoiseErrorInterrupt;
    UART0_eState_Type enableFramingErrorInterrupt;
    UART0_eState_Type enableParityErrorInterrupt;
} UART0_Config_Type;

/*******************************************************************************
 * API
 ******************************************************************************/


void UART0_GetDefaultConfig(UART0_Config_Type *config);

void UART0_SetBaudRate(uint32_t freqSoure, uint32_t baudrate);

/***/
void UART0_PutChar(uint8_t ch);
void UART0_PutCharNonBlocking(uint8_t ch);
void UART0_PutString(uint8_t *message);

void UART0_GetChar(uint8_t *ch);
void UART0_GetCharNonBlocking(uint8_t *ch);
void UART0_GetString(uint8_t *message);

void UART_WriteNumeric(uint32_t number);
void UART_ReadNumeric(uint32_t *number);

void UART0_Init(UART0_Config_Type config);

static inline void UART0_SelectSource(UART0_eClockSoure_Type source)
{
    SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
    SIM->SOPT2 |= SIM_SOPT2_UART0SRC(source);
}

static inline void UART0_EnableTx(void)
{
    UART0->C2 |= UART0_C2_TE_MASK;
}

static inline void UART0_DisableTx(void)
{
    UART0->C2 &= ~UART0_C2_TE_MASK;
}

static inline void UART0_EnableRx(void)
{
    UART0->C2 |= UART0_C2_RE_MASK;
}

static inline void UART0_DisableRx(void)
{
    UART0->C2 &= ~UART0_C2_RE_MASK;
}

static inline uint8_t UART0_EmptyTXData(void)
{
    /**
     * 0 Transmit data buffer full.
     * 1 Transmit data buffer empty.
    */
    return ((UART0->S1 & UART_S1_TDRE_MASK) == UART_S1_TDRE_MASK);
}

static inline uint8_t UART0_EmptyRXData(void)
{
    /**
     * 0 Receive data buffer empty.
     * 1 Receive data buffer full.
    */
    return (!((UART0->S1 & UART0_S1_RDRF_MASK) == UART0_S1_RDRF_MASK));
}

static inline uint8_t UART0_TransmitComplete(void)
{
    /**
     * 0 Transmitter active (sending data, a preamble, or a break).
     * 1 Transmitter idle (transmission activity complete).
    */

    return ((UART0->S1 & UART0_S1_TC_MASK) == UART0_S1_TC_MASK);
}

static inline uint8_t UART0_GetOverrunFlag(void)
{
    return ((UART0->S1 & UART0_S1_OR_MASK) >> UART0_S1_OR_SHIFT);
}

static inline uint8_t UART0_GetNoiseFlag(void)
{
    return ((UART0->S1 & UART0_S1_NF_MASK) >> UART0_S1_NF_SHIFT);
}

static inline uint8_t UART0_GetFramingErrorFlag(void)
{
    return ((UART0->S1 & UART0_S1_FE_MASK) >> UART0_S1_FE_SHIFT);
}

static inline uint8_t UART0_GetParityErrorFlag(void)
{
    return ((UART0->S1 & UART0_S1_PF_MASK) >> UART0_S1_PF_SHIFT);
}

#endif /* __UART0_H__ */

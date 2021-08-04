
/*******************************************************************************
 * Inclunum
 ******************************************************************************/
#include "UART0.h"
#include "queue.h"
#include "std_lib.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define UART_SBR_MIN 1u
#define UART_SBR_MAX 8191u

#define UART_OSR_MIN 4u
#define UART_OSR_MAX 32u

#define UART_INTERGER_DIGITS 21u

typedef struct
{
    uint16_t u16BaudrateDivisor;
    uint8_t u8AcquisitionRate;
} UART0_BaudrateCoeff_Type;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void UART_GetCoeffBaudrate(uint32_t freqSoure,
                                  uint32_t baudrate,
                                  UART0_BaudrateCoeff_Type *coeff);

static uint8_t UART_StrToInt(const uint8_t *str, uint32_t *num);
/*******************************************************************************
 * API
 ******************************************************************************/
void UART0_GetDefaultConfig(UART0_Config_Type *config)
{
    config->stopBit = UART0_OneStopBit;
    config->dataSize = UART0_8bit;
    config->parity = UART0_ParityDisabled;
    config->enableTransmitInterrupt = eDisable;
    config->enableTXCompleteInterrupt = eDisable;
    config->enableReceiveInterrupt = eDisable;
    config->enableIDLEInterrupt = eDisable;
    config->enableOverunInterrupt = eDisable;
    config->enableNoiseErrorInterrupt = eDisable;
    config->enableFramingErrorInterrupt = eDisable;
    config->enableParityErrorInterrupt = eDisable;
}

void UART0_Init(UART0_Config_Type config)
{
    /** Enable clock for PORTA */
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
    /** Enable clock for UART0 module*/
    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;

    /** Select mux UART for pin */
    /** Clear current function */
    PORTA->PCR[UART0_PIN_TX] &= ~PORT_PCR_MUX_MASK;
    PORTA->PCR[UART0_PIN_RX] &= ~PORT_PCR_MUX_MASK;
    /** Select UART function  */
    PORTA->PCR[UART0_PIN_TX] |= PORT_PCR_MUX(2u);
    PORTA->PCR[UART0_PIN_RX] |= PORT_PCR_MUX(2u);

    /** 2. Config Stopbit */
    UART0->BDH &= ~UART0_BDH_SBNS_MASK;
    UART0->BDH |= UART0_BDH_SBNS(config.stopBit);

    /** 2. Config data size */
    switch (config.dataSize)
    {
    case UART0_8bit:
    {
        /** Select 8/9 bits mode */
        UART0->C4 &= ~UART0_C4_M10_MASK;
        /** Select 8bits data */
        UART0->C1 &= ~UART0_C1_M_MASK;
        break;
    }
    case UART0_9bit:
    {
        /** Select 8/9 bits mode */
        UART0->C4 &= ~UART0_C4_M10_MASK;
        /** Select 9bits data */
        UART0->C1 |= UART0_C1_M_MASK;
        break;
    }
    case UART0_10bit:
    {
        /** Select 10 bits mode */
        UART0->C4 |= UART0_C4_M10_MASK;
        break;
    }
    }

    /** 3. Config Parity */
    UART0->C1 &= ~(3u);
    UART0->C1 |= config.parity;

    /** 4. Config interrupt enable */
    /** Clear Current state */
    UART0->C2 &= ~(UART0_C2_TIE_MASK |
                   UART0_C2_TCIE_MASK |
                   UART0_C2_RIE_MASK |
                   UART0_C2_ILIE_MASK);

    UART0->C3 &= ~(UART0_C3_ORIE_MASK |
                   UART0_C3_NEIE_MASK |
                   UART0_C3_FEIE_MASK |
                   UART0_C3_PEIE_MASK);

    UART0->C2 |= UART0_C2_TIE(config.enableTransmitInterrupt);
    UART0->C2 |= UART0_C2_TCIE(config.enableTXCompleteInterrupt);
    UART0->C2 |= UART0_C2_RIE(config.enableReceiveInterrupt);
    UART0->C2 |= UART0_C2_ILIE(config.enableIDLEInterrupt);

    UART0->C3 |= UART0_C3_ORIE(config.enableOverunInterrupt);
    UART0->C3 |= UART0_C3_NEIE(config.enableNoiseErrorInterrupt);
    UART0->C3 |= UART0_C3_FEIE(config.enableFramingErrorInterrupt);
    UART0->C3 |= UART0_C3_PEIE(config.enableParityErrorInterrupt);
}

void UART0_Deinit(void)
{
    UART0_DisableTx();
    UART0_DisableRx();

    /** Clear current function */
    PORTA->PCR[UART0_PIN_TX] &= ~PORT_PCR_MUX_MASK;
    PORTA->PCR[UART0_PIN_RX] &= ~PORT_PCR_MUX_MASK;

    UART0->BDH &= ~UART0_BDH_SBNS_MASK;

    /** Set default stop bit */
    UART0->C4 &= ~UART0_C4_M10_MASK;
    UART0->C1 &= ~UART0_C1_M_MASK;

    /** Set default parity bit */
    UART0->C1 &= ~(3u);

    UART0->C2 &= ~(UART0_C2_TIE_MASK |
                   UART0_C2_TCIE_MASK |
                   UART0_C2_RIE_MASK |
                   UART0_C2_ILIE_MASK);

    UART0->C3 &= ~(UART0_C3_ORIE_MASK |
                   UART0_C3_NEIE_MASK |
                   UART0_C3_FEIE_MASK |
                   UART0_C3_PEIE_MASK);

    /** Enable clock for PORTA */
    SIM->SCGC5 &= ~SIM_SCGC5_PORTA_MASK;
    /** Enable clock for UART0 module*/
    SIM->SCGC4 &= ~SIM_SCGC4_UART0_MASK;
}

static void UART_GetCoeffBaudrate(uint32_t freqSoure,
                                  uint32_t baudrate,
                                  UART0_BaudrateCoeff_Type *coeff)
{
    uint16_t u16CurrBaudrateDivisor;
    uint16_t u16CurrBaudrateDivisor_1;
    uint8_t u8CurrAcquisitionRate;
    uint32_t u32CurrBaudrate;
    uint32_t u32CurrBaudrate_1;

    uint32_t u32Multiplier = freqSoure / baudrate;

    uint32_t u32ErrorMin = baudrate;
    uint32_t u32Error = 0;
    uint32_t u32Error_1 = 0;

    for (u8CurrAcquisitionRate = UART_OSR_MIN + 1u; u8CurrAcquisitionRate <= UART_OSR_MAX; u8CurrAcquisitionRate++)
    {
        u16CurrBaudrateDivisor = (uint16_t)(u32Multiplier / u8CurrAcquisitionRate);
        u16CurrBaudrateDivisor_1 = u16CurrBaudrateDivisor + 1u;

        u32CurrBaudrate = freqSoure / (u8CurrAcquisitionRate * u16CurrBaudrateDivisor);
        u32CurrBaudrate_1 = freqSoure / (u8CurrAcquisitionRate * u16CurrBaudrateDivisor);

        if (u32CurrBaudrate > baudrate)
        {
            u32Error = u32CurrBaudrate - baudrate;
        }
        else
        {
            u32Error = baudrate - u32CurrBaudrate;
        }

        if (u32CurrBaudrate_1 > baudrate)
        {
            u32Error_1 = u32CurrBaudrate_1 - baudrate;
        }
        else
        {
            u32Error_1 = baudrate - u32CurrBaudrate_1;
        }

        if (u32Error_1 < u32Error)
        {
            u32Error = u32Error_1;
            u16CurrBaudrateDivisor = u16CurrBaudrateDivisor_1;
        }

        if ((u32Error <= u32ErrorMin) && (u16CurrBaudrateDivisor < UART_SBR_MAX))
        {
            coeff->u16BaudrateDivisor = u16CurrBaudrateDivisor;
            coeff->u8AcquisitionRate = u8CurrAcquisitionRate;
            u32ErrorMin = u32Error;
        }
    }
}

static uint8_t UART_StrToInt(const uint8_t *str, uint32_t *num)
{
    bool_t IsValid = true;
    uint8_t index = 0;

    /** */
    *num = 0;

    while ((*(str + index) != UART_ENDINGCHAR) && IsValid)
    {
        if (*(str + index) >= '0' && *(str + index) <= '9')
        {
            *num = *num * 10u + (*(str + index) - '0');
        }
        else
        {
            IsValid = false;
            *num = 0;
            UART0_PutString("error number");
        }
        index++;
    }
    return IsValid;
}

void UART0_SetBaudRate(uint32_t freqSoure, uint32_t baudrate)
{
    uint8_t u8UART0_C4 = UART0->C4 & 0xE0u;
    UART0_BaudrateCoeff_Type coeff;
    UART_GetCoeffBaudrate(freqSoure, baudrate, &coeff);

    UART0->BDH &= ~UART0_BDH_SBR_MASK;

    if (coeff.u16BaudrateDivisor > 0xFFu)
    {
        UART0->BDH |= (coeff.u16BaudrateDivisor & 0x1F00u >> 8u);
    }

    UART0->BDL = (uint16_t)(coeff.u16BaudrateDivisor & 0xFFu);
    u8UART0_C4 |= (uint8_t)(coeff.u8AcquisitionRate - 1u);
    UART0->C4 = u8UART0_C4;
}

/***/
void UART0_PutChar(uint8_t ch)
{
    while (!UART0_EmptyTXData())
    {
    }

    UART0->D = ch;
}

void UART0_PutCharNonBlocking(uint8_t ch)
{
    UART0->D = ch;
}

void UART0_PutString(uint8_t *message)
{
    uint8_t index = 0;
    uint8_t len = strlen(message);

    do
    {
        UART0_PutChar(*(message + index));
        index++;
    } while (index < len);
}

/***/
void UART0_GetChar(uint8_t *ch)
{
    while ((UART0->S1 & UART_S1_RDRF_MASK) == 0)
    {
    }

    *ch = UART0->D;
}

void UART0_GetCharNonBlocking(uint8_t *ch)
{
    *ch = UART0->D;
}

void UART0_GetString(uint8_t *message)
{
    uint8_t index = 0;
    uint8_t ch;

    while (UART0->S1 & UART0_S1_IDLE_MASK == 0)
    {
    }

    do
    {
        UART0_GetChar(&ch);
        *(message + index) = ch;
        index++;
    } while (ch != UART_ENDINGCHAR);
}

void UART_WriteNumeric(uint32_t number)
{
    const uint32_t u32DecTable[10u] = {1000000000u, 100000000u, 10000000u, 1000000u,
                                       100000u, 10000u, 1000u, 100u, 10u, 1u};
    uint8_t index = 0;
    uint8_t ch;

    while (number < u32DecTable[index])
    {
        index++;
    }

    while (index < 10u)
    {
        ch = (uint8_t)(number / u32DecTable[index]) + '0';
        UART0_PutChar(ch);

        number = number % u32DecTable[index];
        index++;
    }
}

void UART_ReadNumeric(uint32_t *number)
{
    uint8_t buffer[UART_INTERGER_DIGITS];

    UART0_GetString(buffer);

    UART_StrToInt(buffer, number);
}

/**----------------------------------------------------------------------------
 * Function name: UART0_IRQHandlerInRAM
 * Description: Interrupt handler for UART0 run in RAM
 *----------------------------------------------------------------------------*/
__ramfunc void UART0_IRQHandlerInRAM(void)
{
    static uint8_t s_index = 0;
    uint8_t charBuffer;
    uint8_t queueBack = queue_getBack();

    

    if ((UART0->S1 & UART0_S1_RDRF_MASK) == UART0_S1_RDRF_MASK)
    {
        charBuffer = UART0->D;

        queue[queueBack].record[s_index++] = charBuffer;

        if (charBuffer == '\n')
        {
            if (queue_enqueue())
            {
                /** If queue free */
                s_index = 0;
            }
            else
            {
                /** Disable receive interrupt */
                UART0->C2 &= ~UART0_C2_RE_MASK;
            }
        }
    }
}
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Flash.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    Cmd_Read_1s_Section = 0x01u,
    Cmd_Program_Check = 0x02u,
    Cmd_Read_Resource = 0x03u,
    Cmd_Program_Longword = 0x06u,
    Cmd_Erase_Sector = 0x09u,
    Cmd_Read_1s_AllBlock = 0x40u,
    Cmd_Read_Once = 0x41u,
    Cmd_Program_Once = 0x43u,
    Cmd_Erase_AllBlock = 0x44u,
    Cmd_Verify_Backdoor = 0x45u,
} FLASH_eCommand_Type;

typedef void (*TriggerCommandFunc)(uint8_t volatile *);

#define FLASH_CONFIG_START 0x400u
#define FLASH_CONFIG_END 0x40Fu

#define TRIGGER_COMMAND_FUNC_SIZE 0x12u

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void Flash_TriggerCommand(uint8_t volatile *fstat);
static void Flash_CoppyToRam(uint8_t *funcPointer);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint8_t g_TriggerCommandRam[TRIGGER_COMMAND_FUNC_SIZE];

/*******************************************************************************
 * API
 ******************************************************************************/
void FLASH_EraseSector(uint32_t address)
{
    /** Fill the 0th bit to indicate this is a thumb instruction */
    TriggerCommandFunc Funcp = (TriggerCommandFunc)(g_TriggerCommandRam + 1u);

    while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
        ;

    FTFA->FCCOB0 = (uint8_t)Cmd_Erase_Sector;

    FTFA->FCCOB1 = (address & 0xFF0000u) >> 16u;
    FTFA->FCCOB2 = (address & 0xFF00u) >> 8u;
    FTFA->FCCOB3 = (address & 0xFFu);

    Flash_CoppyToRam((uint8_t *)&Flash_TriggerCommand - 1u);
    (*Funcp)((volatile uint8_t *)(&(FTFA->FSTAT)));
}

void FLASH_WriteLongWord(uint32_t address, uint32_t value)
{
    TriggerCommandFunc Funcp = (TriggerCommandFunc)(g_TriggerCommandRam + 1u);

    while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
        ;

    if ((address < FLASH_CONFIG_START) || (address > FLASH_CONFIG_END))
    {
        FTFA->FCCOB0 = (uint8_t)Cmd_Program_Longword;

        FTFA->FCCOB1 = (address & 0xFF0000u) >> 16u;
        FTFA->FCCOB2 = (address & 0xFF00u) >> 8u;
        FTFA->FCCOB3 = (address & 0xFFu);

        FTFA->FCCOB4 = (value & 0xFF000000u) >> 24u;
        FTFA->FCCOB5 = (value & 0xFF0000u) >> 16u;
        FTFA->FCCOB6 = (value & 0xFF00u) >> 8u;
        FTFA->FCCOB7 = (value & 0xFFu);

        Flash_CoppyToRam((uint8_t *)&Flash_TriggerCommand - 1u);
        (*Funcp)((volatile uint8_t *)(&(FTFA->FSTAT)));
    }
}



void Flash_TriggerCommand(uint8_t volatile *fstat)
{
    *fstat |= FTFA_FSTAT_CCIF_MASK;
    while ((*fstat & FTFA_FSTAT_CCIF_MASK) == 0)
        ;
}

static void Flash_CoppyToRam(uint8_t *funcPointer)
{
    uint8_t index;
    for (index = 0; index < TRIGGER_COMMAND_FUNC_SIZE; index++)
    {
        g_TriggerCommandRam[index] = *(funcPointer + index);
    }
}
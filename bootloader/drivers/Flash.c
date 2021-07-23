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

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
__ramfunc void Flash_ExecuteCommand(FTFA_Type *flash);
__ramfunc void Flash_WaitCommandFinish(FTFA_Type *flash);

/*******************************************************************************
 * API
 ******************************************************************************/
void FLASH_EraseSector(uint32_t address)
{
    Flash_WaitCommandFinish(FTFA);
    FTFA->FCCOB0 = (uint8_t)Cmd_Erase_Sector;

    FTFA->FCCOB1 = (address & 0xFF0000u) >> 16u;
    FTFA->FCCOB2 = (address & 0xFF00u) >> 8u;
    FTFA->FCCOB3 = (address & 0xFFu);

    Flash_ExecuteCommand(FTFA);
    Flash_WaitCommandFinish(FTFA);
}

void FLASH_WriteLongWord(uint32_t address, uint32_t value)
{

    Flash_WaitCommandFinish(FTFA);
    FTFA->FCCOB0 = (uint8_t)Cmd_Program_Longword;

    FTFA->FCCOB1 = (address & 0xFF0000u) >> 16u;
    FTFA->FCCOB2 = (address & 0xFF00u) >> 8u;
    FTFA->FCCOB3 = (address & 0xFFu);

    FTFA->FCCOB4 = (value & 0xFF000000u) >> 24u;
    FTFA->FCCOB5 = (value & 0xFF0000u) >> 16u;
    FTFA->FCCOB6 = (value & 0xFF00u) >> 8u;
    FTFA->FCCOB7 = (value & 0xFFu);

    Flash_ExecuteCommand(FTFA);
    Flash_WaitCommandFinish(FTFA);
}

__ramfunc void Flash_ExecuteCommand(FTFA_Type *flash)
{
    flash->FSTAT |= FTFA_FSTAT_CCIF_MASK;
}
__ramfunc void Flash_WaitCommandFinish(FTFA_Type *flash)
{
    while ((flash->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
        ;
}
/**************************************************************************/ /**
 * Program: Build bootloader program for FRDM-MKL46Z4.
 *          Receive SREC file from PC send through UART.
 * Features:
 *          - Auto verify srec file format
 *          - Auto backup previous firmware before update new firmware.
 *          - Auto restore previous firmware when can not update new firmware.
 *          - When a error happen, can upload firmware to continue update
 *             without reset cpu.
 *          - Auto detect losing connection.
 * Properties: Max application programn size 16KB
 *             Application region start: 0xA000, end 0xDFFF.
 *             Backup region start: 0xE000, end 0x1FFFF.
 ******************************************************************************/

#ifndef __BOOTLOADER_H__
#define __BOOTLOADER_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Board.h"
#include "UART0.h"
#include "Flash.h"
#include "Clock.h"
#include "srec.h"
#include "std_lib.h"
#include "queue.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** The origin vector table of bootloader */
#define VECTORTABLE_DEFAULT_ADDRESS (0x00000000u)

/** 0. PLLFLL
 *  1. OSC
    */
#define UART0_CLOCK_MODE 0u
#define UART0_BAUDRATE_SEL (57600u)

#define APP_REGION_START (0xA000u)
#define APP_REGION_END (0xDFFFu)
#define BACKUP_REGION_START (0xE000u)
#define BACKUP_REGION_END (0x11FFFu)

#define EXIST_APPLICATION (*((uint32_t *)APP_RESETHANDLER_ADDR) != 0xFFFFFFFFu)
#define EXIST_BACKUP (*((uint32_t *)BACKUP_RESETHANDLER_ADDR) != 0xFFFFFFFFu)

/** Section size  */
#define SECTION_SIZE (1024u)
#define APP_RESETHANDLER_OFFSET (0x04u)

/** Reset handler position of primary application and backup memory */
#define APP_RESETHANDLER_ADDR (APP_REGION_START + APP_RESETHANDLER_OFFSET)
#define BACKUP_RESETHANDLER_ADDR (BACKUP_REGION_START + APP_RESETHANDLER_OFFSET)

/** Time out to check lost connection, this value equal to 30s in realtime */
#define TIMEOUT_U32 8500000u
#define TIMEOUT_LIMIT_TOBACKUP_U8 4u

typedef enum
{
    eBootMode = 0u,
    eAppMode = 1u,
} eProgramMode_Type;

typedef enum
{
    eSrec_Error = 0u,
    eUARTOverrun_Error = 1u,
    eTimeout_Error = 2u,
} Error_Type;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/**----------------------------------------------------------------------------
 * Function name: ModeVectorTable
 * Description: Move vector table to the specific destination
 *----------------------------------------------------------------------------*/
void MoveVectorTable(uint32_t destination);

/**----------------------------------------------------------------------------
 * Function name: Copy vector table to specific destination
 * Description: Move vector table to the specific destination
 *----------------------------------------------------------------------------*/
void CopyVectorTable(uint32_t base, uint32_t dest[]);

/**----------------------------------------------------------------------------
 * Function name: ChangeIRQHandler
 * Description: Change default IRQ Handler to new handler
 *----------------------------------------------------------------------------*/
void ChangeIRQHandler(uint32_t *IntvectAddr,
                      IRQn_Type IRQn,
                      void (*newHandler)(void));

/**----------------------------------------------------------------------------
 * Function name: SetupUART
 * Description: Initialize for uart
 *----------------------------------------------------------------------------*/
void SetupUART(void);

/**----------------------------------------------------------------------------
 * Function name: Write one Record to flash memory
 * Description: Initialize for uart
 *----------------------------------------------------------------------------*/
void WriteRecordToFlash(SREC_Infomation_Type info);

/**----------------------------------------------------------------------------
 * Function name: EraseAppMemory
 * Description: Eraser the memory of the application.
 *----------------------------------------------------------------------------*/
void EraseFlashMemory(uint32_t start, uint32_t end, uint16_t sectionSize);

/**----------------------------------------------------------------------------
 * Function name: ResetBootModeState
 * Description: Reset state of boot program for the next update.
 *----------------------------------------------------------------------------*/
void ResetBootModeState(void);

/**----------------------------------------------------------------------------
 * Function name: ErrorReport
 * Description: Report error to serial port.
 *----------------------------------------------------------------------------*/
void ErrorReport(Error_Type errorID);

/**----------------------------------------------------------------------------
 * Function name: JumpToApplication
 * Description: Jump to application program.
 *----------------------------------------------------------------------------*/
void JumpToApplication(uint32_t *AppAddr);

/**----------------------------------------------------------------------------
 * Function name: __JumpASM
 * Description: Jump to application program by asm instruction.
 *----------------------------------------------------------------------------*/
__naked void __JumpASM(uint32_t SP, uint32_t ResetHandler);

/**----------------------------------------------------------------------------
 * Function name: PackingLongword
 * Description: Convert 4 byte to long word form
 *----------------------------------------------------------------------------*/
static inline uint32_t PackingLongwords(uint8_t byte1, uint8_t byte2,
                                        uint8_t byte3, uint8_t byte4);

/**----------------------------------------------------------------------------
 * Function name: GetResetHandler
 * Description: Get reset handler from record data
 *----------------------------------------------------------------------------*/
static inline uint32_t GetResetHandler(uint8_t *data);

/**----------------------------------------------------------------------------
 * Function name: BackupApplication
 * Description: Store application code in backup memory
 *----------------------------------------------------------------------------*/
void BackupApplication(void);

/**----------------------------------------------------------------------------
 * Function name: RestoreBackupApp
 * Description: Restore application program from backup memory
 *----------------------------------------------------------------------------*/
void RestoreBackupApp(void);

void RoutingController(void);

#endif /* __BOOTLOADER_H__ */
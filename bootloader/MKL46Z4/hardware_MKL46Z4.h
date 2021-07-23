/*!
 * @file hardware_MKL46Z.h
 * @version 3.4
 * @date 2014-10-14
 * @brief CMSIS Peripheral Access Layer for MKL46Z4
 *
 * CMSIS Peripheral Access Layer for MKL46Z4
 */

#ifndef _HARDWARE_MKL46Z4_H_
#define _HARDWARE_MKL46Z4_H_

/******************************************************************************
 * Includes
 *****************************************************************************/

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0300U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0004U

#define REGISTER_SIZE (4u)

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48 /**< Number of interrupts in the Vector table */

typedef enum IRQn
{
   /* Auxiliary constants */
   NotAvail_IRQn = -128, /**< Not available device specific interrupt */

   /* Core interrupts */
   NonMaskableInt_IRQn = -14, /**< Non Maskable Interrupt */
   HardFault_IRQn = -13,      /**< Cortex-M0 SV Hard Fault Interrupt */
   SVCall_IRQn = -5,          /**< Cortex-M0 SV Call Interrupt */
   PendSV_IRQn = -2,          /**< Cortex-M0 Pend SV Interrupt */
   SysTick_IRQn = -1,         /**< Cortex-M0 System Tick Interrupt */

   /* Device specific interrupts */
   DMA0_IRQn = 0,         /**< DMA channel 0 transfer complete and error interrupt */
   DMA1_IRQn = 1,         /**< DMA channel 1 transfer complete and error interrupt */
   DMA2_IRQn = 2,         /**< DMA channel 2 transfer complete and error interrupt */
   DMA3_IRQn = 3,         /**< DMA channel 3 transfer complete and error interrupt */
   Reserved20_IRQn = 4,   /**< Reserved interrupt */
   FTFA_IRQn = 5,         /**< FTFA command complete and read collision */
   LVD_LVW_IRQn = 6,      /**< Low-voltage detect, low-voltage warning */
   LLWU_IRQn = 7,         /**< Low Leakage Wakeup */
   I2C0_IRQn = 8,         /**< I2C0 interrupt */
   I2C1_IRQn = 9,         /**< I2C1 interrupt */
   SPI0_IRQn = 10,        /**< SPI0 single interrupt vector for all sources */
   SPI1_IRQn = 11,        /**< SPI1 single interrupt vector for all sources */
   UART0_IRQn = 12,       /**< UART0 status and error */
   UART1_IRQn = 13,       /**< UART1 status and error */
   UART2_IRQn = 14,       /**< UART2 status and error */
   ADC0_IRQn = 15,        /**< ADC0 interrupt */
   CMP0_IRQn = 16,        /**< CMP0 interrupt */
   TPM0_IRQn = 17,        /**< TPM0 single interrupt vector for all sources */
   TPM1_IRQn = 18,        /**< TPM1 single interrupt vector for all sources */
   TPM2_IRQn = 19,        /**< TPM2 single interrupt vector for all sources */
   RTC_IRQn = 20,         /**< RTC alarm interrupt */
   RTC_Seconds_IRQn = 21, /**< RTC seconds interrupt */
   PIT_IRQn = 22,         /**< PIT single interrupt vector for all channels */
   I2S0_IRQn = 23,        /**< I2S0 Single interrupt vector for all sources */
   USB0_IRQn = 24,        /**< USB0 OTG */
   DAC0_IRQn = 25,        /**< DAC0 interrupt */
   TSI0_IRQn = 26,        /**< TSI0 interrupt */
   MCG_IRQn = 27,         /**< MCG interrupt */
   LPTMR0_IRQn = 28,      /**< LPTMR0 interrupt */
   LCD_IRQn = 29,         /**< Segment LCD interrupt */
   PORTA_IRQn = 30,       /**< PORTA pin detect */
   PORTC_PORTD_IRQn = 31  /**< Single interrupt vector for PORTC and PORTD pin detect */
} IRQn_Type;

/*!
 * @}
 */
/* end of group Interrupt_vector_numbers */

/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV 0x0000     /**< Core revision r0p0 */
#define __MPU_PRESENT 0          /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS 2       /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig 0 /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"   /* Core Peripheral Access Layer */
#include "system_MKL46Z4.h" /* Device specific configuration file */

/*!
 * @}
 */
/* end of group Cortex_Core_Configuration */

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */

/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
#pragma push
#pragma anon_unions
#elif defined(__CWCC__)
#pragma push
#pragma cpp_extensions on
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
#pragma language = extended
#else
#error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct
{
   __IO uint32_t PDOR; /**< Port Data Output Register, offset: 0x0 */
   __O uint32_t PSOR;  /**< Port Set Output Register, offset: 0x4 */
   __O uint32_t PCOR;  /**< Port Clear Output Register, offset: 0x8 */
   __O uint32_t PTOR;  /**< Port Toggle Output Register, offset: 0xC */
   __I uint32_t PDIR;  /**< Port Data Input Register, offset: 0x10 */
   __IO uint32_t PDDR; /**< Port Data Direction Register, offset: 0x14 */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIOA ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE (0x400FF040u)
/** Peripheral GPIOB base pointer */
#define GPIOB ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE (0x400FF080u)
/** Peripheral GPIOC base pointer */
#define GPIOC ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE (0x400FF0C0u)
/** Peripheral GPIOD base pointer */
#define GPIOD ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE (0x400FF100u)
/** Peripheral GPIOE base pointer */
#define GPIOE ((GPIO_Type *)GPIOE_BASE)

/** Register address */
#define GPIO_PDOR(port) (((uint32_t)(port)) + 0 * REGISTER_SIZE)
#define GPIO_PSOR(port) (((uint32_t)(port)) + 1u * REGISTER_SIZE)
#define GPIO_PCOR(port) (((uint32_t)(port)) + 2u * REGISTER_SIZE)
#define GPIO_PTOR(port) (((uint32_t)(port)) + 3u * REGISTER_SIZE)
#define GPIO_PDIR(port) (((uint32_t)(port)) + 4u * REGISTER_SIZE)
#define GPIO_PDDR(port) (((uint32_t)(port)) + 5u * REGISTER_SIZE)

/*!
 * @}
 */
/* end of group GPIO_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- FTFA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Peripheral_Access_Layer FTFA Peripheral Access Layer
 * @{
 */

/** FTFA - Register Layout Typedef */
typedef struct
{
   __IO uint8_t FSTAT;  /**< Flash Status Register, offset: 0x0 */
   __IO uint8_t FCNFG;  /**< Flash Configuration Register, offset: 0x1 */
   __I uint8_t FSEC;    /**< Flash Security Register, offset: 0x2 */
   __I uint8_t FOPT;    /**< Flash Option Register, offset: 0x3 */
   __IO uint8_t FCCOB3; /**< Flash Common Command Object Registers, offset: 0x4 */
   __IO uint8_t FCCOB2; /**< Flash Common Command Object Registers, offset: 0x5 */
   __IO uint8_t FCCOB1; /**< Flash Common Command Object Registers, offset: 0x6 */
   __IO uint8_t FCCOB0; /**< Flash Common Command Object Registers, offset: 0x7 */
   __IO uint8_t FCCOB7; /**< Flash Common Command Object Registers, offset: 0x8 */
   __IO uint8_t FCCOB6; /**< Flash Common Command Object Registers, offset: 0x9 */
   __IO uint8_t FCCOB5; /**< Flash Common Command Object Registers, offset: 0xA */
   __IO uint8_t FCCOB4; /**< Flash Common Command Object Registers, offset: 0xB */
   __IO uint8_t FCCOBB; /**< Flash Common Command Object Registers, offset: 0xC */
   __IO uint8_t FCCOBA; /**< Flash Common Command Object Registers, offset: 0xD */
   __IO uint8_t FCCOB9; /**< Flash Common Command Object Registers, offset: 0xE */
   __IO uint8_t FCCOB8; /**< Flash Common Command Object Registers, offset: 0xF */
   __IO uint8_t FPROT3; /**< Program Flash Protection Registers, offset: 0x10 */
   __IO uint8_t FPROT2; /**< Program Flash Protection Registers, offset: 0x11 */
   __IO uint8_t FPROT1; /**< Program Flash Protection Registers, offset: 0x12 */
   __IO uint8_t FPROT0; /**< Program Flash Protection Registers, offset: 0x13 */
} FTFA_Type;

/* ----------------------------------------------------------------------------
   -- FTFA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Masks FTFA Register Masks
 * @{
 */

/*! @name FSTAT - Flash Status Register */
#define FTFA_FSTAT_MGSTAT0_MASK (0x1U)
#define FTFA_FSTAT_MGSTAT0_SHIFT (0U)
#define FTFA_FSTAT_MGSTAT0(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_MGSTAT0_SHIFT)) & FTFA_FSTAT_MGSTAT0_MASK)
#define FTFA_FSTAT_FPVIOL_MASK (0x10U)
#define FTFA_FSTAT_FPVIOL_SHIFT (4U)
#define FTFA_FSTAT_FPVIOL(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_FPVIOL_SHIFT)) & FTFA_FSTAT_FPVIOL_MASK)
#define FTFA_FSTAT_ACCERR_MASK (0x20U)
#define FTFA_FSTAT_ACCERR_SHIFT (5U)
#define FTFA_FSTAT_ACCERR(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_ACCERR_SHIFT)) & FTFA_FSTAT_ACCERR_MASK)
#define FTFA_FSTAT_RDCOLERR_MASK (0x40U)
#define FTFA_FSTAT_RDCOLERR_SHIFT (6U)
#define FTFA_FSTAT_RDCOLERR(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_RDCOLERR_SHIFT)) & FTFA_FSTAT_RDCOLERR_MASK)
#define FTFA_FSTAT_CCIF_MASK (0x80U)
#define FTFA_FSTAT_CCIF_SHIFT (7U)
#define FTFA_FSTAT_CCIF(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_CCIF_SHIFT)) & FTFA_FSTAT_CCIF_MASK)

/*! @name FCNFG - Flash Configuration Register */
#define FTFA_FCNFG_ERSSUSP_MASK (0x10U)
#define FTFA_FCNFG_ERSSUSP_SHIFT (4U)
#define FTFA_FCNFG_ERSSUSP(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_ERSSUSP_SHIFT)) & FTFA_FCNFG_ERSSUSP_MASK)
#define FTFA_FCNFG_ERSAREQ_MASK (0x20U)
#define FTFA_FCNFG_ERSAREQ_SHIFT (5U)
#define FTFA_FCNFG_ERSAREQ(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_ERSAREQ_SHIFT)) & FTFA_FCNFG_ERSAREQ_MASK)
#define FTFA_FCNFG_RDCOLLIE_MASK (0x40U)
#define FTFA_FCNFG_RDCOLLIE_SHIFT (6U)
#define FTFA_FCNFG_RDCOLLIE(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_RDCOLLIE_SHIFT)) & FTFA_FCNFG_RDCOLLIE_MASK)
#define FTFA_FCNFG_CCIE_MASK (0x80U)
#define FTFA_FCNFG_CCIE_SHIFT (7U)
#define FTFA_FCNFG_CCIE(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_CCIE_SHIFT)) & FTFA_FCNFG_CCIE_MASK)

/*! @name FSEC - Flash Security Register */
#define FTFA_FSEC_SEC_MASK (0x3U)
#define FTFA_FSEC_SEC_SHIFT (0U)
#define FTFA_FSEC_SEC(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_SEC_SHIFT)) & FTFA_FSEC_SEC_MASK)
#define FTFA_FSEC_FSLACC_MASK (0xCU)
#define FTFA_FSEC_FSLACC_SHIFT (2U)
#define FTFA_FSEC_FSLACC(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_FSLACC_SHIFT)) & FTFA_FSEC_FSLACC_MASK)
#define FTFA_FSEC_MEEN_MASK (0x30U)
#define FTFA_FSEC_MEEN_SHIFT (4U)
#define FTFA_FSEC_MEEN(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_MEEN_SHIFT)) & FTFA_FSEC_MEEN_MASK)
#define FTFA_FSEC_KEYEN_MASK (0xC0U)
#define FTFA_FSEC_KEYEN_SHIFT (6U)
#define FTFA_FSEC_KEYEN(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_KEYEN_SHIFT)) & FTFA_FSEC_KEYEN_MASK)

/*! @name FOPT - Flash Option Register */
#define FTFA_FOPT_OPT_MASK (0xFFU)
#define FTFA_FOPT_OPT_SHIFT (0U)
#define FTFA_FOPT_OPT(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FOPT_OPT_SHIFT)) & FTFA_FOPT_OPT_MASK)

/*! @name FCCOB3 - Flash Common Command Object Registers */
#define FTFA_FCCOB3_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB3_CCOBn_SHIFT (0U)
#define FTFA_FCCOB3_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB3_CCOBn_SHIFT)) & FTFA_FCCOB3_CCOBn_MASK)

/*! @name FCCOB2 - Flash Common Command Object Registers */
#define FTFA_FCCOB2_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB2_CCOBn_SHIFT (0U)
#define FTFA_FCCOB2_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB2_CCOBn_SHIFT)) & FTFA_FCCOB2_CCOBn_MASK)

/*! @name FCCOB1 - Flash Common Command Object Registers */
#define FTFA_FCCOB1_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB1_CCOBn_SHIFT (0U)
#define FTFA_FCCOB1_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB1_CCOBn_SHIFT)) & FTFA_FCCOB1_CCOBn_MASK)

/*! @name FCCOB0 - Flash Common Command Object Registers */
#define FTFA_FCCOB0_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB0_CCOBn_SHIFT (0U)
#define FTFA_FCCOB0_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB0_CCOBn_SHIFT)) & FTFA_FCCOB0_CCOBn_MASK)

/*! @name FCCOB7 - Flash Common Command Object Registers */
#define FTFA_FCCOB7_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB7_CCOBn_SHIFT (0U)
#define FTFA_FCCOB7_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB7_CCOBn_SHIFT)) & FTFA_FCCOB7_CCOBn_MASK)

/*! @name FCCOB6 - Flash Common Command Object Registers */
#define FTFA_FCCOB6_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB6_CCOBn_SHIFT (0U)
#define FTFA_FCCOB6_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB6_CCOBn_SHIFT)) & FTFA_FCCOB6_CCOBn_MASK)

/*! @name FCCOB5 - Flash Common Command Object Registers */
#define FTFA_FCCOB5_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB5_CCOBn_SHIFT (0U)
#define FTFA_FCCOB5_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB5_CCOBn_SHIFT)) & FTFA_FCCOB5_CCOBn_MASK)

/*! @name FCCOB4 - Flash Common Command Object Registers */
#define FTFA_FCCOB4_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB4_CCOBn_SHIFT (0U)
#define FTFA_FCCOB4_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB4_CCOBn_SHIFT)) & FTFA_FCCOB4_CCOBn_MASK)

/*! @name FCCOBB - Flash Common Command Object Registers */
#define FTFA_FCCOBB_CCOBn_MASK (0xFFU)
#define FTFA_FCCOBB_CCOBn_SHIFT (0U)
#define FTFA_FCCOBB_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOBB_CCOBn_SHIFT)) & FTFA_FCCOBB_CCOBn_MASK)

/*! @name FCCOBA - Flash Common Command Object Registers */
#define FTFA_FCCOBA_CCOBn_MASK (0xFFU)
#define FTFA_FCCOBA_CCOBn_SHIFT (0U)
#define FTFA_FCCOBA_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOBA_CCOBn_SHIFT)) & FTFA_FCCOBA_CCOBn_MASK)

/*! @name FCCOB9 - Flash Common Command Object Registers */
#define FTFA_FCCOB9_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB9_CCOBn_SHIFT (0U)
#define FTFA_FCCOB9_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB9_CCOBn_SHIFT)) & FTFA_FCCOB9_CCOBn_MASK)

/*! @name FCCOB8 - Flash Common Command Object Registers */
#define FTFA_FCCOB8_CCOBn_MASK (0xFFU)
#define FTFA_FCCOB8_CCOBn_SHIFT (0U)
#define FTFA_FCCOB8_CCOBn(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB8_CCOBn_SHIFT)) & FTFA_FCCOB8_CCOBn_MASK)

/*! @name FPROT3 - Program Flash Protection Registers */
#define FTFA_FPROT3_PROT_MASK (0xFFU)
#define FTFA_FPROT3_PROT_SHIFT (0U)
#define FTFA_FPROT3_PROT(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT3_PROT_SHIFT)) & FTFA_FPROT3_PROT_MASK)

/*! @name FPROT2 - Program Flash Protection Registers */
#define FTFA_FPROT2_PROT_MASK (0xFFU)
#define FTFA_FPROT2_PROT_SHIFT (0U)
#define FTFA_FPROT2_PROT(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT2_PROT_SHIFT)) & FTFA_FPROT2_PROT_MASK)

/*! @name FPROT1 - Program Flash Protection Registers */
#define FTFA_FPROT1_PROT_MASK (0xFFU)
#define FTFA_FPROT1_PROT_SHIFT (0U)
#define FTFA_FPROT1_PROT(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT1_PROT_SHIFT)) & FTFA_FPROT1_PROT_MASK)

/*! @name FPROT0 - Program Flash Protection Registers */
#define FTFA_FPROT0_PROT_MASK (0xFFU)
#define FTFA_FPROT0_PROT_SHIFT (0U)
#define FTFA_FPROT0_PROT(x) (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT0_PROT_SHIFT)) & FTFA_FPROT0_PROT_MASK)

/*!
 * @}
 */
/* end of group FTFA_Register_Masks */

/* FTFA - Peripheral instance base addresses */
/** Peripheral FTFA base address */
#define FTFA_BASE (0x40020000u)
/** Peripheral FTFA base pointer */
#define FTFA ((FTFA_Type *)FTFA_BASE)
/** Array initializer of FTFA peripheral base addresses */
#define FTFA_BASE_ADDRS \
   {                    \
      FTFA_BASE         \
   }
/** Array initializer of FTFA peripheral base pointers */
#define FTFA_BASE_PTRS \
   {                   \
      FTFA             \
   }
/** Interrupt vectors for the FTFA peripheral type */
#define FTFA_COMMAND_COMPLETE_IRQS \
   {                               \
      FTFA_IRQn                    \
   }

/*!
 * @}
 */
/* end of group FTFA_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LCD Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LLWU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup MCG_Peripheral_Access_Layer MCG Peripheral Access Layer
 * @{
 */

/** MCG - Register Layout Typedef */
typedef struct
{
   __IO uint8_t C1; /**< MCG Control 1 Register, offset: 0x0 */
   __IO uint8_t C2; /**< MCG Control 2 Register, offset: 0x1 */
   __IO uint8_t C3; /**< MCG Control 3 Register, offset: 0x2 */
   __IO uint8_t C4; /**< MCG Control 4 Register, offset: 0x3 */
   __IO uint8_t C5; /**< MCG Control 5 Register, offset: 0x4 */
   __IO uint8_t C6; /**< MCG Control 6 Register, offset: 0x5 */
   __IO uint8_t S;  /**< MCG Status Register, offset: 0x6 */
   uint8_t RESERVED_0[1];
   __IO uint8_t SC; /**< MCG Status and Control Register, offset: 0x8 */
   uint8_t RESERVED_1[1];
   __IO uint8_t ATCVH; /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
   __IO uint8_t ATCVL; /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
   __IO uint8_t C7;    /**< MCG Control 7 Register, offset: 0xC */
   __IO uint8_t C8;    /**< MCG Control 8 Register, offset: 0xD */
   __I uint8_t C9;     /**< MCG Control 9 Register, offset: 0xE */
   __I uint8_t C10;    /**< MCG Control 10 Register, offset: 0xF */
} MCG_Type;
/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/*! @name C1 - MCG Control 1 Register */
#define MCG_C1_IREFSTEN_MASK (0x1U)
#define MCG_C1_IREFSTEN_SHIFT (0U)
#define MCG_C1_IREFSTEN(x) (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFSTEN_SHIFT)) & MCG_C1_IREFSTEN_MASK)
#define MCG_C1_IRCLKEN_MASK (0x2U)
#define MCG_C1_IRCLKEN_SHIFT (1U)
#define MCG_C1_IRCLKEN(x) (((uint8_t)(((uint8_t)(x)) << MCG_C1_IRCLKEN_SHIFT)) & MCG_C1_IRCLKEN_MASK)
#define MCG_C1_IREFS_MASK (0x4U)
#define MCG_C1_IREFS_SHIFT (2U)
#define MCG_C1_IREFS(x) (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFS_SHIFT)) & MCG_C1_IREFS_MASK)
#define MCG_C1_FRDIV_MASK (0x38U)
#define MCG_C1_FRDIV_SHIFT (3U)
#define MCG_C1_FRDIV(x) (((uint8_t)(((uint8_t)(x)) << MCG_C1_FRDIV_SHIFT)) & MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK (0xC0U)
#define MCG_C1_CLKS_SHIFT (6U)
#define MCG_C1_CLKS(x) (((uint8_t)(((uint8_t)(x)) << MCG_C1_CLKS_SHIFT)) & MCG_C1_CLKS_MASK)

/*! @name C2 - MCG Control 2 Register */
#define MCG_C2_IRCS_MASK (0x1U)
#define MCG_C2_IRCS_SHIFT (0U)
#define MCG_C2_IRCS(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_IRCS_SHIFT)) & MCG_C2_IRCS_MASK)
#define MCG_C2_LP_MASK (0x2U)
#define MCG_C2_LP_SHIFT (1U)
#define MCG_C2_LP(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_LP_SHIFT)) & MCG_C2_LP_MASK)
#define MCG_C2_EREFS0_MASK (0x4U)
#define MCG_C2_EREFS0_SHIFT (2U)
#define MCG_C2_EREFS0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_EREFS0_SHIFT)) & MCG_C2_EREFS0_MASK)
#define MCG_C2_HGO0_MASK (0x8U)
#define MCG_C2_HGO0_SHIFT (3U)
#define MCG_C2_HGO0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_HGO0_SHIFT)) & MCG_C2_HGO0_MASK)
#define MCG_C2_RANGE0_MASK (0x30U)
#define MCG_C2_RANGE0_SHIFT (4U)
#define MCG_C2_RANGE0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_RANGE0_SHIFT)) & MCG_C2_RANGE0_MASK)
#define MCG_C2_FCFTRIM_MASK (0x40U)
#define MCG_C2_FCFTRIM_SHIFT (6U)
#define MCG_C2_FCFTRIM(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_FCFTRIM_SHIFT)) & MCG_C2_FCFTRIM_MASK)
#define MCG_C2_LOCRE0_MASK (0x80U)
#define MCG_C2_LOCRE0_SHIFT (7U)
#define MCG_C2_LOCRE0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C2_LOCRE0_SHIFT)) & MCG_C2_LOCRE0_MASK)

/*! @name C3 - MCG Control 3 Register */
#define MCG_C3_SCTRIM_MASK (0xFFU)
#define MCG_C3_SCTRIM_SHIFT (0U)
#define MCG_C3_SCTRIM(x) (((uint8_t)(((uint8_t)(x)) << MCG_C3_SCTRIM_SHIFT)) & MCG_C3_SCTRIM_MASK)

/*! @name C4 - MCG Control 4 Register */
#define MCG_C4_SCFTRIM_MASK (0x1U)
#define MCG_C4_SCFTRIM_SHIFT (0U)
#define MCG_C4_SCFTRIM(x) (((uint8_t)(((uint8_t)(x)) << MCG_C4_SCFTRIM_SHIFT)) & MCG_C4_SCFTRIM_MASK)
#define MCG_C4_FCTRIM_MASK (0x1EU)
#define MCG_C4_FCTRIM_SHIFT (1U)
#define MCG_C4_FCTRIM(x) (((uint8_t)(((uint8_t)(x)) << MCG_C4_FCTRIM_SHIFT)) & MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK (0x60U)
#define MCG_C4_DRST_DRS_SHIFT (5U)
#define MCG_C4_DRST_DRS(x) (((uint8_t)(((uint8_t)(x)) << MCG_C4_DRST_DRS_SHIFT)) & MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK (0x80U)
#define MCG_C4_DMX32_SHIFT (7U)
#define MCG_C4_DMX32(x) (((uint8_t)(((uint8_t)(x)) << MCG_C4_DMX32_SHIFT)) & MCG_C4_DMX32_MASK)

/*! @name C5 - MCG Control 5 Register */
#define MCG_C5_PRDIV0_MASK (0x1FU)
#define MCG_C5_PRDIV0_SHIFT (0U)
#define MCG_C5_PRDIV0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C5_PRDIV0_SHIFT)) & MCG_C5_PRDIV0_MASK)
#define MCG_C5_PLLSTEN0_MASK (0x20U)
#define MCG_C5_PLLSTEN0_SHIFT (5U)
#define MCG_C5_PLLSTEN0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C5_PLLSTEN0_SHIFT)) & MCG_C5_PLLSTEN0_MASK)
#define MCG_C5_PLLCLKEN0_MASK (0x40U)
#define MCG_C5_PLLCLKEN0_SHIFT (6U)
#define MCG_C5_PLLCLKEN0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C5_PLLCLKEN0_SHIFT)) & MCG_C5_PLLCLKEN0_MASK)

/*! @name C6 - MCG Control 6 Register */
#define MCG_C6_VDIV0_MASK (0x1FU)
#define MCG_C6_VDIV0_SHIFT (0U)
#define MCG_C6_VDIV0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C6_VDIV0_SHIFT)) & MCG_C6_VDIV0_MASK)
#define MCG_C6_CME0_MASK (0x20U)
#define MCG_C6_CME0_SHIFT (5U)
#define MCG_C6_CME0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C6_CME0_SHIFT)) & MCG_C6_CME0_MASK)
#define MCG_C6_PLLS_MASK (0x40U)
#define MCG_C6_PLLS_SHIFT (6U)
#define MCG_C6_PLLS(x) (((uint8_t)(((uint8_t)(x)) << MCG_C6_PLLS_SHIFT)) & MCG_C6_PLLS_MASK)
#define MCG_C6_LOLIE0_MASK (0x80U)
#define MCG_C6_LOLIE0_SHIFT (7U)
#define MCG_C6_LOLIE0(x) (((uint8_t)(((uint8_t)(x)) << MCG_C6_LOLIE0_SHIFT)) & MCG_C6_LOLIE0_MASK)

/*! @name S - MCG Status Register */
#define MCG_S_IRCST_MASK (0x1U)
#define MCG_S_IRCST_SHIFT (0U)
#define MCG_S_IRCST(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_IRCST_SHIFT)) & MCG_S_IRCST_MASK)
#define MCG_S_OSCINIT0_MASK (0x2U)
#define MCG_S_OSCINIT0_SHIFT (1U)
#define MCG_S_OSCINIT0(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_OSCINIT0_SHIFT)) & MCG_S_OSCINIT0_MASK)
#define MCG_S_CLKST_MASK (0xCU)
#define MCG_S_CLKST_SHIFT (2U)
#define MCG_S_CLKST(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_CLKST_SHIFT)) & MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK (0x10U)
#define MCG_S_IREFST_SHIFT (4U)
#define MCG_S_IREFST(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_IREFST_SHIFT)) & MCG_S_IREFST_MASK)
#define MCG_S_PLLST_MASK (0x20U)
#define MCG_S_PLLST_SHIFT (5U)
#define MCG_S_PLLST(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_PLLST_SHIFT)) & MCG_S_PLLST_MASK)
#define MCG_S_LOCK0_MASK (0x40U)
#define MCG_S_LOCK0_SHIFT (6U)
#define MCG_S_LOCK0(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_LOCK0_SHIFT)) & MCG_S_LOCK0_MASK)
#define MCG_S_LOLS0_MASK (0x80U)
#define MCG_S_LOLS0_SHIFT (7U)
#define MCG_S_LOLS0(x) (((uint8_t)(((uint8_t)(x)) << MCG_S_LOLS0_SHIFT)) & MCG_S_LOLS0_MASK)

/*! @name SC - MCG Status and Control Register */
#define MCG_SC_LOCS0_MASK (0x1U)
#define MCG_SC_LOCS0_SHIFT (0U)
#define MCG_SC_LOCS0(x) (((uint8_t)(((uint8_t)(x)) << MCG_SC_LOCS0_SHIFT)) & MCG_SC_LOCS0_MASK)
#define MCG_SC_FCRDIV_MASK (0xEU)
#define MCG_SC_FCRDIV_SHIFT (1U)
#define MCG_SC_FCRDIV(x) (((uint8_t)(((uint8_t)(x)) << MCG_SC_FCRDIV_SHIFT)) & MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK (0x10U)
#define MCG_SC_FLTPRSRV_SHIFT (4U)
#define MCG_SC_FLTPRSRV(x) (((uint8_t)(((uint8_t)(x)) << MCG_SC_FLTPRSRV_SHIFT)) & MCG_SC_FLTPRSRV_MASK)
#define MCG_SC_ATMF_MASK (0x20U)
#define MCG_SC_ATMF_SHIFT (5U)
#define MCG_SC_ATMF(x) (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATMF_SHIFT)) & MCG_SC_ATMF_MASK)
#define MCG_SC_ATMS_MASK (0x40U)
#define MCG_SC_ATMS_SHIFT (6U)
#define MCG_SC_ATMS(x) (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATMS_SHIFT)) & MCG_SC_ATMS_MASK)
#define MCG_SC_ATME_MASK (0x80U)
#define MCG_SC_ATME_SHIFT (7U)
#define MCG_SC_ATME(x) (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATME_SHIFT)) & MCG_SC_ATME_MASK)

/*! @name ATCVH - MCG Auto Trim Compare Value High Register */
#define MCG_ATCVH_ATCVH_MASK (0xFFU)
#define MCG_ATCVH_ATCVH_SHIFT (0U)
#define MCG_ATCVH_ATCVH(x) (((uint8_t)(((uint8_t)(x)) << MCG_ATCVH_ATCVH_SHIFT)) & MCG_ATCVH_ATCVH_MASK)

/*! @name ATCVL - MCG Auto Trim Compare Value Low Register */
#define MCG_ATCVL_ATCVL_MASK (0xFFU)
#define MCG_ATCVL_ATCVL_SHIFT (0U)
#define MCG_ATCVL_ATCVL(x) (((uint8_t)(((uint8_t)(x)) << MCG_ATCVL_ATCVL_SHIFT)) & MCG_ATCVL_ATCVL_MASK)

/*! @name C7 - MCG Control 7 Register */
#define MCG_C7_OSCSEL_MASK (0x1U)
#define MCG_C7_OSCSEL_SHIFT (0U)
#define MCG_C7_OSCSEL(x) (((uint8_t)(((uint8_t)(x)) << MCG_C7_OSCSEL_SHIFT)) & MCG_C7_OSCSEL_MASK)

/*! @name C8 - MCG Control 8 Register */
#define MCG_C8_LOLRE_MASK (0x40U)
#define MCG_C8_LOLRE_SHIFT (6U)
#define MCG_C8_LOLRE(x) (((uint8_t)(((uint8_t)(x)) << MCG_C8_LOLRE_SHIFT)) & MCG_C8_LOLRE_MASK)

/*!
 * @}
 */
/* end of group MCG_Register_Masks */

/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base address */
#define MCG_BASE (0x40064000u)
/** Peripheral MCG base pointer */
#define MCG ((MCG_Type *)MCG_BASE)
/** Array initializer of MCG peripheral base addresses */
#define MCG_BASE_ADDRS \
   {                   \
      MCG_BASE         \
   }
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS \
   {                  \
      MCG             \
   }
/** Interrupt vectors for the MCG peripheral type */
#define MCG_IRQS \
   {             \
      MCG_IRQn   \
   }
/* MCG C2[EREFS] backward compatibility */
#define MCG_C2_EREFS_MASK (MCG_C2_EREFS0_MASK)
#define MCG_C2_EREFS_SHIFT (MCG_C2_EREFS0_SHIFT)
#define MCG_C2_EREFS_WIDTH (MCG_C2_EREFS0_WIDTH)
#define MCG_C2_EREFS(x) (MCG_C2_EREFS0(x))

/* MCG C2[HGO] backward compatibility */
#define MCG_C2_HGO_MASK (MCG_C2_HGO0_MASK)
#define MCG_C2_HGO_SHIFT (MCG_C2_HGO0_SHIFT)
#define MCG_C2_HGO_WIDTH (MCG_C2_HGO0_WIDTH)
#define MCG_C2_HGO(x) (MCG_C2_HGO0(x))

/* MCG C2[RANGE] backward compatibility */
#define MCG_C2_RANGE_MASK (MCG_C2_RANGE0_MASK)
#define MCG_C2_RANGE_SHIFT (MCG_C2_RANGE0_SHIFT)
#define MCG_C2_RANGE_WIDTH (MCG_C2_RANGE0_WIDTH)
#define MCG_C2_RANGE(x) (MCG_C2_RANGE0(x))

/*!
 * @}
 */
/* end of group MCG_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MTB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MTB Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MTBDWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MTBDWT Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Peripheral_Access_Layer OSC Peripheral Access Layer
 * @{
 */

/** OSC - Register Layout Typedef */
typedef struct
{
   __IO uint8_t CR; /**< OSC Control Register, offset: 0x0 */
} OSC_Type;

/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/*! @name CR - OSC Control Register */
#define OSC_CR_SC16P_MASK (0x1U)
#define OSC_CR_SC16P_SHIFT (0U)
#define OSC_CR_SC16P(x) (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC16P_SHIFT)) & OSC_CR_SC16P_MASK)
#define OSC_CR_SC8P_MASK (0x2U)
#define OSC_CR_SC8P_SHIFT (1U)
#define OSC_CR_SC8P(x) (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC8P_SHIFT)) & OSC_CR_SC8P_MASK)
#define OSC_CR_SC4P_MASK (0x4U)
#define OSC_CR_SC4P_SHIFT (2U)
#define OSC_CR_SC4P(x) (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC4P_SHIFT)) & OSC_CR_SC4P_MASK)
#define OSC_CR_SC2P_MASK (0x8U)
#define OSC_CR_SC2P_SHIFT (3U)
#define OSC_CR_SC2P(x) (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC2P_SHIFT)) & OSC_CR_SC2P_MASK)
#define OSC_CR_EREFSTEN_MASK (0x20U)
#define OSC_CR_EREFSTEN_SHIFT (5U)
#define OSC_CR_EREFSTEN(x) (((uint8_t)(((uint8_t)(x)) << OSC_CR_EREFSTEN_SHIFT)) & OSC_CR_EREFSTEN_MASK)
#define OSC_CR_ERCLKEN_MASK (0x80U)
#define OSC_CR_ERCLKEN_SHIFT (7U)
#define OSC_CR_ERCLKEN(x) (((uint8_t)(((uint8_t)(x)) << OSC_CR_ERCLKEN_SHIFT)) & OSC_CR_ERCLKEN_MASK)

/*!
 * @}
 */
/* end of group OSC_Register_Masks */

/* OSC - Peripheral instance base addresses */
/** Peripheral OSC0 base address */
#define OSC0_BASE (0x40065000u)
/** Peripheral OSC0 base pointer */
#define OSC0 ((OSC_Type *)OSC0_BASE)

/*!
 * @}
 */
/* end of group OSC_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct
{
   __IO uint32_t MCR; /**< PIT Module Control Register, offset: 0x0 */
   uint8_t RESERVED_0[220];
   __I uint32_t LTMR64H; /**< PIT Upper Lifetime Timer Register, offset: 0xE0 */
   __I uint32_t LTMR64L; /**< PIT Lower Lifetime Timer Register, offset: 0xE4 */
   uint8_t RESERVED_1[24];
   struct
   {                       /* offset: 0x100, array step: 0x10 */
      __IO uint32_t LDVAL; /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
      __I uint32_t CVAL;   /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
      __IO uint32_t TCTRL; /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
      __IO uint32_t TFLG;  /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
   } CHANNEL[2];
} PIT_Type;

/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/*! @name MCR - PIT Module Control Register */
#define PIT_MCR_FRZ_MASK (0x1u)
#define PIT_MCR_FRZ_SHIFT (0u)
#define PIT_MCR_FRZ(x) (((uint32_t)(((uint32_t)(x)) << PIT_MCR_FRZ_SHIFT)) & PIT_MCR_FRZ_MASK)
#define PIT_MCR_MDIS_MASK (0x2u)
#define PIT_MCR_MDIS_SHIFT (1u)
#define PIT_MCR_MDIS(x) (((uint32_t)(((uint32_t)(x)) << PIT_MCR_MDIS_SHIFT)) & PIT_MCR_MDIS_MASK)

/*! @name LTMR64H - PIT Upper Lifetime Timer Register */
#define PIT_LTMR64H_LTH(x) ((uint32_t)(x))

/*! @name LTMR64L - PIT Lower Lifetime Timer Register */
#define PIT_LTMR64H_LTL(x) ((uint32_t)(x))

/*! @name LDVAL - Timer Load Value Register */
#define PIT_LDVAL_TSV(x) ((uint32_t)(x))

/* The count of PIT_LDVAL */
#define PIT_LDVAL_COUNT (2U)

/*! @name CVAL - Current Timer Value Register */
#define PIT_CVAL_TVL(x) (((uint32_t)(((uint32_t)(x)) << PIT_CVAL_TVL_SHIFT)) & PIT_CVAL_TVL_MASK)

/* The count of PIT_CVAL */
#define PIT_CVAL_COUNT (2U)
/*! @name CVAL - Current Timer Value Register */

/*! @name TCTRL - Timer Control Register */
#define PIT_TCTRL_TEN_MASK (0x1U)
#define PIT_TCTRL_TEN_SHIFT (0U)
#define PIT_TCTRL_TEN(x) (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TEN_SHIFT)) & PIT_TCTRL_TEN_MASK)
#define PIT_TCTRL_TIE_MASK (0x2U)
#define PIT_TCTRL_TIE_SHIFT (1U)
#define PIT_TCTRL_TIE(x) (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TIE_SHIFT)) & PIT_TCTRL_TIE_MASK)
#define PIT_TCTRL_CHN_MASK (0x4U)
#define PIT_TCTRL_CHN_SHIFT (2U)
#define PIT_TCTRL_CHN(x) (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_CHN_SHIFT)) & PIT_TCTRL_CHN_MASK)

/* The count of PIT_TCTRL */
#define PIT_TCTRL_COUNT (2U)

/*! @name TFLG - Timer Flag Register */
#define PIT_TFLG_TIF_MASK (0x1U)
#define PIT_TFLG_TIF_SHIFT (0U)
#define PIT_TFLG_TIF(x) (((uint32_t)(((uint32_t)(x)) << PIT_TFLG_TIF_SHIFT)) & PIT_TFLG_TIF_MASK)

/* The count of PIT_TFLG */
#define PIT_TFLG_COUNT (2U)

/*!
 * @}
 */
/* end of group PIT_Register_Masks */

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base address */
#define PIT_BASE (0x40037000u)
/** Peripheral PIT base pointer */
#define PIT ((PIT_Type *)PIT_BASE)
/** Array initializer of PIT peripheral base addresses */

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct
{
   __IO uint32_t PCR[32]; /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
   __O uint32_t GPCLR;    /**< Global Pin Control Low Register, offset: 0x80 */
   __O uint32_t GPCHR;    /**< Global Pin Control High Register, offset: 0x84 */
   uint8_t RESERVED_0[24];
   __IO uint32_t ISFR; /**< Interrupt Status Flag Register, offset: 0xA0 */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PORT Register Masks */
#define PORT_PCR_PS_MASK (0x1U)
#define PORT_PCR_PS_SHIFT (0U)
#define PORT_PCR_PS(x) (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK (0x2U)
#define PORT_PCR_PE_SHIFT (1U)
#define PORT_PCR_PE(x) (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)
#define PORT_PCR_MUX_MASK (0x700u)
#define PORT_PCR_MUX_SHIFT (8u)
#define PORT_PCR_MUX(x) ((uint32_t)(((uint32_t)(x) << PORT_PCR_MUX_SHIFT) & PORT_PCR_MUX_MASK))

#define PORT_PCR_IRQC_MASK (0xF0000U)
#define PORT_PCR_IRQC_SHIFT (16U)
#define PORT_PCR_IRQC(x) (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)

/* Interrupt configuration  */
#define IRQC_DMA_DISABLE (0)
#define IRQC_DMA_RISING (1U)
#define IRQC_DMA_FALLING (2U)
#define IRQC_DMA_CHANGE (3U)
#define IRQC_LOGIC_ZERO (8U)
#define IRQC_RISING (9U)
#define IRQC_FALLING (10U)
#define IRQC_CHANGE (11U)
#define IRQC_LOGIC_ONE (12U)

/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE ((PORT_Type *)PORTE_BASE)

/* PORT - Register Address */
#define PORT_NUMBER_SIZE (5u)
#define PORT_NUMBER_PIN_PER_PORT (32u)

#define PORT_PCR(port, pin) ((uint32_t)(port) + REGISTER_SIZE * (pin))
#define PORT_GPCLR(port) ((uint32_t)(port) + 0x80u)
#define PORT_GPCHR(port) ((uint32_t)(port) + 0x84u)
#define PORT_ISFR(port) ((uint32_t)(port) + 0xA0u)

/*!
 * @}
 */
/* end of group PORT_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------
   -- ROM Register Masks
   ---------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */
/** SIM - Register Layout Typedef */

typedef struct
{
   __IO uint32_t SOPT1;    /**< System Options Register 1, offset: 0x0 */
   __IO uint32_t SOPT1CFG; /**< SOPT1 Configuration Register, offset: 0x4 */
   uint8_t RESERVED_0[4092];
   __IO uint32_t SOPT2; /**< System Options Register 2, offset: 0x1004 */
   uint8_t RESERVED_1[4];
   __IO uint32_t SOPT4; /**< System Options Register 4, offset: 0x100C */
   __IO uint32_t SOPT5; /**< System Options Register 5, offset: 0x1010 */
   uint8_t RESERVED_2[4];
   __IO uint32_t SOPT7; /**< System Options Register 7, offset: 0x1018 */
   uint8_t RESERVED_3[8];
   __I uint32_t SDID; /**< System Device Identification Register, offset: 0x1024 */
   uint8_t RESERVED_4[12];
   __IO uint32_t SCGC4;   /**< System Clock Gating Control Register 4, offset: 0x1034 */
   __IO uint32_t SCGC5;   /**< System Clock Gating Control Register 5, offset: 0x1038 */
   __IO uint32_t SCGC6;   /**< System Clock Gating Control Register 6, offset: 0x103C */
   __IO uint32_t SCGC7;   /**< System Clock Gating Control Register 7, offset: 0x1040 */
   __IO uint32_t CLKDIV1; /**< System Clock Divider Register 1, offset: 0x1044 */
   uint8_t RESERVED_5[4];
   __IO uint32_t FCFG1; /**< Flash Configuration Register 1, offset: 0x104C */
   __I uint32_t FCFG2;  /**< Flash Configuration Register 2, offset: 0x1050 */
   uint8_t RESERVED_6[4];
   __I uint32_t UIDMH; /**< Unique Identification Register Mid-High, offset: 0x1058 */
   __I uint32_t UIDML; /**< Unique Identification Register Mid Low, offset: 0x105C */
   __I uint32_t UIDL;  /**< Unique Identification Register Low, offset: 0x1060 */
   uint8_t RESERVED_7[156];
   __IO uint32_t COPC;  /**< COP Control Register, offset: 0x1100 */
   __O uint32_t SRVCOP; /**< Service COP, offset: 0x1104 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*! @name SOPT1 - System Options Register 1 */
#define SIM_SOPT1_OSC32KSEL_MASK (0xC0000U)
#define SIM_SOPT1_OSC32KSEL_SHIFT (18U)
#define SIM_SOPT1_OSC32KSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KSEL_SHIFT)) & SIM_SOPT1_OSC32KSEL_MASK)
#define SIM_SOPT1_USBVSTBY_MASK (0x20000000U)
#define SIM_SOPT1_USBVSTBY_SHIFT (29U)
#define SIM_SOPT1_USBVSTBY(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_USBVSTBY_SHIFT)) & SIM_SOPT1_USBVSTBY_MASK)
#define SIM_SOPT1_USBSSTBY_MASK (0x40000000U)
#define SIM_SOPT1_USBSSTBY_SHIFT (30U)
#define SIM_SOPT1_USBSSTBY(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_USBSSTBY_SHIFT)) & SIM_SOPT1_USBSSTBY_MASK)
#define SIM_SOPT1_USBREGEN_MASK (0x80000000U)
#define SIM_SOPT1_USBREGEN_SHIFT (31U)
#define SIM_SOPT1_USBREGEN(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_USBREGEN_SHIFT)) & SIM_SOPT1_USBREGEN_MASK)

/*! @name SOPT1CFG - SOPT1 Configuration Register */
#define SIM_SOPT1CFG_URWE_MASK (0x1000000U)
#define SIM_SOPT1CFG_URWE_SHIFT (24U)
#define SIM_SOPT1CFG_URWE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_URWE_SHIFT)) & SIM_SOPT1CFG_URWE_MASK)
#define SIM_SOPT1CFG_UVSWE_MASK (0x2000000U)
#define SIM_SOPT1CFG_UVSWE_SHIFT (25U)
#define SIM_SOPT1CFG_UVSWE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_UVSWE_SHIFT)) & SIM_SOPT1CFG_UVSWE_MASK)
#define SIM_SOPT1CFG_USSWE_MASK (0x4000000U)
#define SIM_SOPT1CFG_USSWE_SHIFT (26U)
#define SIM_SOPT1CFG_USSWE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1CFG_USSWE_SHIFT)) & SIM_SOPT1CFG_USSWE_MASK)

/*! @name SOPT2 - System Options Register 2 */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK (0x10U)
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT (4U)
#define SIM_SOPT2_RTCCLKOUTSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_RTCCLKOUTSEL_SHIFT)) & SIM_SOPT2_RTCCLKOUTSEL_MASK)
#define SIM_SOPT2_CLKOUTSEL_MASK (0xE0U)
#define SIM_SOPT2_CLKOUTSEL_SHIFT (5U)
#define SIM_SOPT2_CLKOUTSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_CLKOUTSEL_SHIFT)) & SIM_SOPT2_CLKOUTSEL_MASK)
#define SIM_SOPT2_PLLFLLSEL_MASK (0x10000U)
#define SIM_SOPT2_PLLFLLSEL_SHIFT (16U)
#define SIM_SOPT2_PLLFLLSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_PLLFLLSEL_SHIFT)) & SIM_SOPT2_PLLFLLSEL_MASK)
#define SIM_SOPT2_USBSRC_MASK (0x40000U)
#define SIM_SOPT2_USBSRC_SHIFT (18U)
#define SIM_SOPT2_USBSRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_USBSRC_SHIFT)) & SIM_SOPT2_USBSRC_MASK)
#define SIM_SOPT2_TPMSRC_MASK (0x3000000U)
#define SIM_SOPT2_TPMSRC_SHIFT (24U)
#define SIM_SOPT2_TPMSRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_TPMSRC_SHIFT)) & SIM_SOPT2_TPMSRC_MASK)
#define SIM_SOPT2_UART0SRC_MASK (0xC000000U)
#define SIM_SOPT2_UART0SRC_SHIFT (26U)
#define SIM_SOPT2_UART0SRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_UART0SRC_SHIFT)) & SIM_SOPT2_UART0SRC_MASK)

/*! @name SOPT4 - System Options Register 4 */
#define SIM_SOPT4_TPM1CH0SRC_MASK (0xC0000U)
#define SIM_SOPT4_TPM1CH0SRC_SHIFT (18U)
#define SIM_SOPT4_TPM1CH0SRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM1CH0SRC_SHIFT)) & SIM_SOPT4_TPM1CH0SRC_MASK)
#define SIM_SOPT4_TPM2CH0SRC_MASK (0x100000U)
#define SIM_SOPT4_TPM2CH0SRC_SHIFT (20U)
#define SIM_SOPT4_TPM2CH0SRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM2CH0SRC_SHIFT)) & SIM_SOPT4_TPM2CH0SRC_MASK)
#define SIM_SOPT4_TPM0CLKSEL_MASK (0x1000000U)
#define SIM_SOPT4_TPM0CLKSEL_SHIFT (24U)
#define SIM_SOPT4_TPM0CLKSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM0CLKSEL_SHIFT)) & SIM_SOPT4_TPM0CLKSEL_MASK)
#define SIM_SOPT4_TPM1CLKSEL_MASK (0x2000000U)
#define SIM_SOPT4_TPM1CLKSEL_SHIFT (25U)
#define SIM_SOPT4_TPM1CLKSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM1CLKSEL_SHIFT)) & SIM_SOPT4_TPM1CLKSEL_MASK)
#define SIM_SOPT4_TPM2CLKSEL_MASK (0x4000000U)
#define SIM_SOPT4_TPM2CLKSEL_SHIFT (26U)
#define SIM_SOPT4_TPM2CLKSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_TPM2CLKSEL_SHIFT)) & SIM_SOPT4_TPM2CLKSEL_MASK)

/*! @name SOPT5 - System Options Register 5 */
#define SIM_SOPT5_UART0TXSRC_MASK (0x3U)
#define SIM_SOPT5_UART0TXSRC_SHIFT (0U)
#define SIM_SOPT5_UART0TXSRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0TXSRC_SHIFT)) & SIM_SOPT5_UART0TXSRC_MASK)
#define SIM_SOPT5_UART0RXSRC_MASK (0x4U)
#define SIM_SOPT5_UART0RXSRC_SHIFT (2U)
#define SIM_SOPT5_UART0RXSRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0RXSRC_SHIFT)) & SIM_SOPT5_UART0RXSRC_MASK)
#define SIM_SOPT5_UART1TXSRC_MASK (0x30U)
#define SIM_SOPT5_UART1TXSRC_SHIFT (4U)
#define SIM_SOPT5_UART1TXSRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1TXSRC_SHIFT)) & SIM_SOPT5_UART1TXSRC_MASK)
#define SIM_SOPT5_UART1RXSRC_MASK (0x40U)
#define SIM_SOPT5_UART1RXSRC_SHIFT (6U)
#define SIM_SOPT5_UART1RXSRC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1RXSRC_SHIFT)) & SIM_SOPT5_UART1RXSRC_MASK)
#define SIM_SOPT5_UART0ODE_MASK (0x10000U)
#define SIM_SOPT5_UART0ODE_SHIFT (16U)
#define SIM_SOPT5_UART0ODE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0ODE_SHIFT)) & SIM_SOPT5_UART0ODE_MASK)
#define SIM_SOPT5_UART1ODE_MASK (0x20000U)
#define SIM_SOPT5_UART1ODE_SHIFT (17U)
#define SIM_SOPT5_UART1ODE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1ODE_SHIFT)) & SIM_SOPT5_UART1ODE_MASK)
#define SIM_SOPT5_UART2ODE_MASK (0x40000U)
#define SIM_SOPT5_UART2ODE_SHIFT (18U)
#define SIM_SOPT5_UART2ODE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART2ODE_SHIFT)) & SIM_SOPT5_UART2ODE_MASK)

/*! @name SOPT7 - System Options Register 7 */
#define SIM_SOPT7_ADC0TRGSEL_MASK (0xFU)
#define SIM_SOPT7_ADC0TRGSEL_SHIFT (0U)
#define SIM_SOPT7_ADC0TRGSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0TRGSEL_SHIFT)) & SIM_SOPT7_ADC0TRGSEL_MASK)
#define SIM_SOPT7_ADC0PRETRGSEL_MASK (0x10U)
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT (4U)
#define SIM_SOPT7_ADC0PRETRGSEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0PRETRGSEL_SHIFT)) & SIM_SOPT7_ADC0PRETRGSEL_MASK)
#define SIM_SOPT7_ADC0ALTTRGEN_MASK (0x80U)
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT (7U)
#define SIM_SOPT7_ADC0ALTTRGEN(x) (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0ALTTRGEN_SHIFT)) & SIM_SOPT7_ADC0ALTTRGEN_MASK)

/*! @name SDID - System Device Identification Register */
#define SIM_SDID_PINID_MASK (0xFU)
#define SIM_SDID_PINID_SHIFT (0U)
#define SIM_SDID_PINID(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)
#define SIM_SDID_DIEID_MASK (0xF80U)
#define SIM_SDID_DIEID_SHIFT (7U)
#define SIM_SDID_DIEID(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DIEID_SHIFT)) & SIM_SDID_DIEID_MASK)
#define SIM_SDID_REVID_MASK (0xF000U)
#define SIM_SDID_REVID_SHIFT (12U)
#define SIM_SDID_REVID(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)
#define SIM_SDID_SRAMSIZE_MASK (0xF0000U)
#define SIM_SDID_SRAMSIZE_SHIFT (16U)
#define SIM_SDID_SRAMSIZE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SRAMSIZE_SHIFT)) & SIM_SDID_SRAMSIZE_MASK)
#define SIM_SDID_SERIESID_MASK (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT (20U)
#define SIM_SDID_SERIESID(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)
#define SIM_SDID_SUBFAMID_MASK (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT (24U)
#define SIM_SDID_SUBFAMID(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)
#define SIM_SDID_FAMID_MASK (0xF0000000U)
#define SIM_SDID_FAMID_SHIFT (28U)
#define SIM_SDID_FAMID(x) (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMID_SHIFT)) & SIM_SDID_FAMID_MASK)

/*! @name SCGC4 - System Clock Gating Control Register 4 */
#define SIM_SCGC4_I2C0_MASK (0x40U)
#define SIM_SCGC4_I2C0_SHIFT (6U)
#define SIM_SCGC4_I2C0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C0_SHIFT)) & SIM_SCGC4_I2C0_MASK)
#define SIM_SCGC4_I2C1_MASK (0x80U)
#define SIM_SCGC4_I2C1_SHIFT (7U)
#define SIM_SCGC4_I2C1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C1_SHIFT)) & SIM_SCGC4_I2C1_MASK)
#define SIM_SCGC4_UART0_MASK (0x400U)
#define SIM_SCGC4_UART0_SHIFT (10U)
#define SIM_SCGC4_UART0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)
#define SIM_SCGC4_UART1_MASK (0x800U)
#define SIM_SCGC4_UART1_SHIFT (11U)
#define SIM_SCGC4_UART1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART1_SHIFT)) & SIM_SCGC4_UART1_MASK)
#define SIM_SCGC4_UART2_MASK (0x1000U)
#define SIM_SCGC4_UART2_SHIFT (12U)
#define SIM_SCGC4_UART2(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART2_SHIFT)) & SIM_SCGC4_UART2_MASK)
#define SIM_SCGC4_USBOTG_MASK (0x40000U)
#define SIM_SCGC4_USBOTG_SHIFT (18U)
#define SIM_SCGC4_USBOTG(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_USBOTG_SHIFT)) & SIM_SCGC4_USBOTG_MASK)
#define SIM_SCGC4_CMP_MASK (0x80000U)
#define SIM_SCGC4_CMP_SHIFT (19U)
#define SIM_SCGC4_CMP(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP_SHIFT)) & SIM_SCGC4_CMP_MASK)
#define SIM_SCGC4_SPI0_MASK (0x400000U)
#define SIM_SCGC4_SPI0_SHIFT (22U)
#define SIM_SCGC4_SPI0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_SPI0_SHIFT)) & SIM_SCGC4_SPI0_MASK)
#define SIM_SCGC4_SPI1_MASK (0x800000U)
#define SIM_SCGC4_SPI1_SHIFT (23U)
#define SIM_SCGC4_SPI1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_SPI1_SHIFT)) & SIM_SCGC4_SPI1_MASK)

/*! @name SCGC5 - System Clock Gating Control Register 5 */
#define SIM_SCGC5_LPTMR_MASK (0x1U)
#define SIM_SCGC5_LPTMR_SHIFT (0U)
#define SIM_SCGC5_LPTMR(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_LPTMR_SHIFT)) & SIM_SCGC5_LPTMR_MASK)
#define SIM_SCGC5_TSI_MASK (0x20U)
#define SIM_SCGC5_TSI_SHIFT (5U)
#define SIM_SCGC5_TSI(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TSI_SHIFT)) & SIM_SCGC5_TSI_MASK)
#define SIM_SCGC5_PORTA_MASK (0x200U)
#define SIM_SCGC5_PORTA_SHIFT (9U)
#define SIM_SCGC5_PORTA(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)
#define SIM_SCGC5_PORTB_MASK (0x400U)
#define SIM_SCGC5_PORTB_SHIFT (10U)
#define SIM_SCGC5_PORTB(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)
#define SIM_SCGC5_PORTC_MASK (0x800U)
#define SIM_SCGC5_PORTC_SHIFT (11U)
#define SIM_SCGC5_PORTC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)
#define SIM_SCGC5_PORTD_MASK (0x1000U)
#define SIM_SCGC5_PORTD_SHIFT (12U)
#define SIM_SCGC5_PORTD(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)
#define SIM_SCGC5_PORTE_MASK (0x2000U)
#define SIM_SCGC5_PORTE_SHIFT (13U)
#define SIM_SCGC5_PORTE(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)
#define SIM_SCGC5_SLCD_MASK (0x80000U)
#define SIM_SCGC5_SLCD_SHIFT (19U)
#define SIM_SCGC5_SLCD(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_SLCD_SHIFT)) & SIM_SCGC5_SLCD_MASK)

/*! @name SCGC6 - System Clock Gating Control Register 6 */
#define SIM_SCGC6_FTF_MASK (0x1U)
#define SIM_SCGC6_FTF_SHIFT (0U)
#define SIM_SCGC6_FTF(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTF_SHIFT)) & SIM_SCGC6_FTF_MASK)
#define SIM_SCGC6_DMAMUX_MASK (0x2U)
#define SIM_SCGC6_DMAMUX_SHIFT (1U)
#define SIM_SCGC6_DMAMUX(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX_SHIFT)) & SIM_SCGC6_DMAMUX_MASK)
#define SIM_SCGC6_I2S_MASK (0x8000U)
#define SIM_SCGC6_I2S_SHIFT (15U)
#define SIM_SCGC6_I2S(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_I2S_SHIFT)) & SIM_SCGC6_I2S_MASK)
#define SIM_SCGC6_PIT_MASK (0x800000U)
#define SIM_SCGC6_PIT_SHIFT (23U)
#define SIM_SCGC6_PIT(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT_SHIFT)) & SIM_SCGC6_PIT_MASK)
#define SIM_SCGC6_TPM0_MASK (0x1000000U)
#define SIM_SCGC6_TPM0_SHIFT (24U)
#define SIM_SCGC6_TPM0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM0_SHIFT)) & SIM_SCGC6_TPM0_MASK)
#define SIM_SCGC6_TPM1_MASK (0x2000000U)
#define SIM_SCGC6_TPM1_SHIFT (25U)
#define SIM_SCGC6_TPM1(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM1_SHIFT)) & SIM_SCGC6_TPM1_MASK)
#define SIM_SCGC6_TPM2_MASK (0x4000000U)
#define SIM_SCGC6_TPM2_SHIFT (26U)
#define SIM_SCGC6_TPM2(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM2_SHIFT)) & SIM_SCGC6_TPM2_MASK)
#define SIM_SCGC6_ADC0_MASK (0x8000000U)
#define SIM_SCGC6_ADC0_SHIFT (27U)
#define SIM_SCGC6_ADC0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_ADC0_SHIFT)) & SIM_SCGC6_ADC0_MASK)
#define SIM_SCGC6_RTC_MASK (0x20000000U)
#define SIM_SCGC6_RTC_SHIFT (29U)
#define SIM_SCGC6_RTC(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_RTC_SHIFT)) & SIM_SCGC6_RTC_MASK)
#define SIM_SCGC6_DAC0_MASK (0x80000000U)
#define SIM_SCGC6_DAC0_SHIFT (31U)
#define SIM_SCGC6_DAC0(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DAC0_SHIFT)) & SIM_SCGC6_DAC0_MASK)

/*! @name SCGC7 - System Clock Gating Control Register 7 */
#define SIM_SCGC7_DMA_MASK (0x100U)
#define SIM_SCGC7_DMA_SHIFT (8U)
#define SIM_SCGC7_DMA(x) (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_DMA_SHIFT)) & SIM_SCGC7_DMA_MASK)

/*! @name CLKDIV1 - System Clock Divider Register 1 */
#define SIM_CLKDIV1_OUTDIV4_MASK (0x70000U)
#define SIM_CLKDIV1_OUTDIV4_SHIFT (16U)
#define SIM_CLKDIV1_OUTDIV4(x) (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV4_SHIFT)) & SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK (0xF0000000U)
#define SIM_CLKDIV1_OUTDIV1_SHIFT (28U)
#define SIM_CLKDIV1_OUTDIV1(x) (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV1_SHIFT)) & SIM_CLKDIV1_OUTDIV1_MASK)

/*! @name FCFG1 - Flash Configuration Register 1 */
#define SIM_FCFG1_FLASHDIS_MASK (0x1U)
#define SIM_FCFG1_FLASHDIS_SHIFT (0U)
#define SIM_FCFG1_FLASHDIS(x) (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDIS_SHIFT)) & SIM_FCFG1_FLASHDIS_MASK)
#define SIM_FCFG1_FLASHDOZE_MASK (0x2U)
#define SIM_FCFG1_FLASHDOZE_SHIFT (1U)
#define SIM_FCFG1_FLASHDOZE(x) (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)
#define SIM_FCFG1_PFSIZE_MASK (0xF000000U)
#define SIM_FCFG1_PFSIZE_SHIFT (24U)
#define SIM_FCFG1_PFSIZE(x) (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)

/*! @name FCFG2 - Flash Configuration Register 2 */
#define SIM_FCFG2_MAXADDR1_MASK (0x7F0000U)
#define SIM_FCFG2_MAXADDR1_SHIFT (16U)
#define SIM_FCFG2_MAXADDR1(x) (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR1_SHIFT)) & SIM_FCFG2_MAXADDR1_MASK)
#define SIM_FCFG2_MAXADDR0_MASK (0x7F000000U)
#define SIM_FCFG2_MAXADDR0_SHIFT (24U)
#define SIM_FCFG2_MAXADDR0(x) (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR0_SHIFT)) & SIM_FCFG2_MAXADDR0_MASK)

/*! @name UIDMH - Unique Identification Register Mid-High */
#define SIM_UIDMH_UID_MASK (0xFFFFU)
#define SIM_UIDMH_UID_SHIFT (0U)
#define SIM_UIDMH_UID(x) (((uint32_t)(((uint32_t)(x)) << SIM_UIDMH_UID_SHIFT)) & SIM_UIDMH_UID_MASK)

/*! @name UIDML - Unique Identification Register Mid Low */
#define SIM_UIDML_UID_MASK (0xFFFFFFFFU)
#define SIM_UIDML_UID_SHIFT (0U)
#define SIM_UIDML_UID(x) (((uint32_t)(((uint32_t)(x)) << SIM_UIDML_UID_SHIFT)) & SIM_UIDML_UID_MASK)

/*! @name UIDL - Unique Identification Register Low */
#define SIM_UIDL_UID_MASK (0xFFFFFFFFU)
#define SIM_UIDL_UID_SHIFT (0U)
#define SIM_UIDL_UID(x) (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID_SHIFT)) & SIM_UIDL_UID_MASK)

/*! @name COPC - COP Control Register */
#define SIM_COPC_COPW_MASK (0x1U)
#define SIM_COPC_COPW_SHIFT (0U)
#define SIM_COPC_COPW(x) (((uint32_t)(((uint32_t)(x)) << SIM_COPC_COPW_SHIFT)) & SIM_COPC_COPW_MASK)
#define SIM_COPC_COPCLKS_MASK (0x2U)
#define SIM_COPC_COPCLKS_SHIFT (1U)
#define SIM_COPC_COPCLKS(x) (((uint32_t)(((uint32_t)(x)) << SIM_COPC_COPCLKS_SHIFT)) & SIM_COPC_COPCLKS_MASK)
#define SIM_COPC_COPT_MASK (0xCU)
#define SIM_COPC_COPT_SHIFT (2U)
#define SIM_COPC_COPT(x) (((uint32_t)(((uint32_t)(x)) << SIM_COPC_COPT_SHIFT)) & SIM_COPC_COPT_MASK)

/*! @name SRVCOP - Service COP */
#define SIM_SRVCOP_SRVCOP_MASK (0xFFU)
#define SIM_SRVCOP_SRVCOP_SHIFT (0U)
#define SIM_SRVCOP_SRVCOP(x) (((uint32_t)(((uint32_t)(x)) << SIM_SRVCOP_SRVCOP_SHIFT)) & SIM_SRVCOP_SRVCOP_MASK)

/*!
 * @}
 */
/* end of group SIM_Register_Masks */

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE (0x40047000u)
/** Peripheral SIM base pointer */
#define SIM ((SIM_Type *)SIM_BASE)

/*!
 * @}
 */
/* end of group SIM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- TPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Peripheral_Access_Layer TPM Peripheral Access Layer
 * @{
 */

/** TPM - Register Layout Typedef */
typedef struct
{
   __IO uint32_t SC;  /** Status and control, offset 0x00u */
   __IO uint32_t CNT; /** Counter, offset 0x04u */
   __IO uint32_t MOD; /** Modulo, offset 0x08u */
   struct
   {
      __IO uint32_t CnSC; /** Channel (n) status and control */
      __IO uint32_t CnV;  /** Channel (n) value */
   } Channel[6];
   uint8_t RESERVED_0[20];
   __IO uint32_t STATUS; /** Capture and compare status, offset 0x50u */
   uint8_t RESERVED_1[48];
   __IO uint32_t CONF; /** Configuration, offset 0x84u */
} TPM_Type;

/* ----------------------------------------------------------------------------
   -- TPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Register_Masks TPM Register Masks
 * @{
 */

/*! @name SC - Status and Control */
#define TPM_SC_PS_MASK (0x7U)
#define TPM_SC_PS_SHIFT (0U)
#define TPM_SC_PS(x) (((uint32_t)(((uint32_t)(x)) << TPM_SC_PS_SHIFT)) & TPM_SC_PS_MASK)
#define TPM_SC_CMOD_MASK (0x18U)
#define TPM_SC_CMOD_SHIFT (3U)
#define TPM_SC_CMOD(x) (((uint32_t)(((uint32_t)(x)) << TPM_SC_CMOD_SHIFT)) & TPM_SC_CMOD_MASK)
#define TPM_SC_CPWMS_MASK (0x20U)
#define TPM_SC_CPWMS_SHIFT (5U)
#define TPM_SC_CPWMS(x) (((uint32_t)(((uint32_t)(x)) << TPM_SC_CPWMS_SHIFT)) & TPM_SC_CPWMS_MASK)
#define TPM_SC_TOIE_MASK (0x40U)
#define TPM_SC_TOIE_SHIFT (6U)
#define TPM_SC_TOIE(x) (((uint32_t)(((uint32_t)(x)) << TPM_SC_TOIE_SHIFT)) & TPM_SC_TOIE_MASK)
#define TPM_SC_TOF_MASK (0x80U)
#define TPM_SC_TOF_SHIFT (7U)
#define TPM_SC_TOF(x) (((uint32_t)(((uint32_t)(x)) << TPM_SC_TOF_SHIFT)) & TPM_SC_TOF_MASK)
#define TPM_SC_DMA_MASK (0x100U)
#define TPM_SC_DMA_SHIFT (8U)
#define TPM_SC_DMA(x) (((uint32_t)(((uint32_t)(x)) << TPM_SC_DMA_SHIFT)) & TPM_SC_DMA_MASK)

/*! @name CNT - Counter */
#define TPM_CNT_COUNT_MASK (0xFFFFU)
#define TPM_CNT_COUNT_SHIFT (0U)
#define TPM_CNT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << TPM_CNT_COUNT_SHIFT)) & TPM_CNT_COUNT_MASK)

/*! @name MOD - Modulo */
#define TPM_MOD_MOD_MASK (0xFFFFU)
#define TPM_MOD_MOD_SHIFT (0U)
#define TPM_MOD_MOD(x) (((uint32_t)(((uint32_t)(x)) << TPM_MOD_MOD_SHIFT)) & TPM_MOD_MOD_MASK)

/*! @name CnSC - Channel (n) Status and Control */
#define TPM_CnSC_DMA_MASK (0x1U)
#define TPM_CnSC_DMA_SHIFT (0U)
#define TPM_CnSC_DMA(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_DMA_SHIFT)) & TPM_CnSC_DMA_MASK)
#define TPM_CnSC_ELSA_MASK (0x4U)
#define TPM_CnSC_ELSA_SHIFT (2U)
#define TPM_CnSC_ELSA(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_ELSA_SHIFT)) & TPM_CnSC_ELSA_MASK)
#define TPM_CnSC_ELSB_MASK (0x8U)
#define TPM_CnSC_ELSB_SHIFT (3U)
#define TPM_CnSC_ELSB(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_ELSB_SHIFT)) & TPM_CnSC_ELSB_MASK)
#define TPM_CnSC_MSA_MASK (0x10U)
#define TPM_CnSC_MSA_SHIFT (4U)
#define TPM_CnSC_MSA(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_MSA_SHIFT)) & TPM_CnSC_MSA_MASK)
#define TPM_CnSC_MSB_MASK (0x20U)
#define TPM_CnSC_MSB_SHIFT (5U)
#define TPM_CnSC_MSB(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_MSB_SHIFT)) & TPM_CnSC_MSB_MASK)
#define TPM_CnSC_CHIE_MASK (0x40U)
#define TPM_CnSC_CHIE_SHIFT (6U)
#define TPM_CnSC_CHIE(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_CHIE_SHIFT)) & TPM_CnSC_CHIE_MASK)
#define TPM_CnSC_CHF_MASK (0x80U)
#define TPM_CnSC_CHF_SHIFT (7U)
#define TPM_CnSC_CHF(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_CHF_SHIFT)) & TPM_CnSC_CHF_MASK)

/* The count of TPM_CnSC */
#define TPM_CnSC_COUNT (6U)

/*! @name CnV - Channel (n) Value */
#define TPM_CnV_VAL_MASK (0xFFFFU)
#define TPM_CnV_VAL_SHIFT (0U)
#define TPM_CnV_VAL(x) (((uint32_t)(((uint32_t)(x)) << TPM_CnV_VAL_SHIFT)) & TPM_CnV_VAL_MASK)

/* The count of TPM_CnV */
#define TPM_CnV_COUNT (6U)

/*! @name STATUS - Capture and Compare Status */
#define TPM_STATUS_CH0F_MASK (0x1U)
#define TPM_STATUS_CH0F_SHIFT (0U)
#define TPM_STATUS_CH0F(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH0F_SHIFT)) & TPM_STATUS_CH0F_MASK)
#define TPM_STATUS_CH1F_MASK (0x2U)
#define TPM_STATUS_CH1F_SHIFT (1U)
#define TPM_STATUS_CH1F(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH1F_SHIFT)) & TPM_STATUS_CH1F_MASK)
#define TPM_STATUS_CH2F_MASK (0x4U)
#define TPM_STATUS_CH2F_SHIFT (2U)
#define TPM_STATUS_CH2F(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH2F_SHIFT)) & TPM_STATUS_CH2F_MASK)
#define TPM_STATUS_CH3F_MASK (0x8U)
#define TPM_STATUS_CH3F_SHIFT (3U)
#define TPM_STATUS_CH3F(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH3F_SHIFT)) & TPM_STATUS_CH3F_MASK)
#define TPM_STATUS_CH4F_MASK (0x10U)
#define TPM_STATUS_CH4F_SHIFT (4U)
#define TPM_STATUS_CH4F(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH4F_SHIFT)) & TPM_STATUS_CH4F_MASK)
#define TPM_STATUS_CH5F_MASK (0x20U)
#define TPM_STATUS_CH5F_SHIFT (5U)
#define TPM_STATUS_CH5F(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH5F_SHIFT)) & TPM_STATUS_CH5F_MASK)
#define TPM_STATUS_TOF_MASK (0x100U)
#define TPM_STATUS_TOF_SHIFT (8U)
#define TPM_STATUS_TOF(x) (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_TOF_SHIFT)) & TPM_STATUS_TOF_MASK)

/*! @name CONF - Configuration */
#define TPM_CONF_DOZEEN_MASK (0x20U)
#define TPM_CONF_DOZEEN_SHIFT (5U)
#define TPM_CONF_DOZEEN(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_DOZEEN_SHIFT)) & TPM_CONF_DOZEEN_MASK)
#define TPM_CONF_DBGMODE_MASK (0xC0U)
#define TPM_CONF_DBGMODE_SHIFT (6U)
#define TPM_CONF_DBGMODE(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_DBGMODE_SHIFT)) & TPM_CONF_DBGMODE_MASK)
#define TPM_CONF_GTBEEN_MASK (0x200U)
#define TPM_CONF_GTBEEN_SHIFT (9U)
#define TPM_CONF_GTBEEN(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_GTBEEN_SHIFT)) & TPM_CONF_GTBEEN_MASK)
#define TPM_CONF_CSOT_MASK (0x10000U)
#define TPM_CONF_CSOT_SHIFT (16U)
#define TPM_CONF_CSOT(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CSOT_SHIFT)) & TPM_CONF_CSOT_MASK)
#define TPM_CONF_CSOO_MASK (0x20000U)
#define TPM_CONF_CSOO_SHIFT (17U)
#define TPM_CONF_CSOO(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CSOO_SHIFT)) & TPM_CONF_CSOO_MASK)
#define TPM_CONF_CROT_MASK (0x40000U)
#define TPM_CONF_CROT_SHIFT (18U)
#define TPM_CONF_CROT(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CROT_SHIFT)) & TPM_CONF_CROT_MASK)
#define TPM_CONF_TRGSEL_MASK (0xF000000U)
#define TPM_CONF_TRGSEL_SHIFT (24U)
#define TPM_CONF_TRGSEL(x) (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGSEL_SHIFT)) & TPM_CONF_TRGSEL_MASK)

/*!
 * @}
 */
/* end of group TPM_Register_Masks */

/*!
 * @}
 */
/* end of group TPM_Register_Masks */

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE (0x40038000u)
/** Peripheral TPM0 base pointer */
#define TPM0 ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE (0x40039000u)
/** Peripheral TPM1 base pointer */
#define TPM1 ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE (0x4003A000u)
/** Peripheral TPM2 base pointer */
#define TPM2 ((TPM_Type *)TPM2_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                \
   {                                  \
      TPM0_BASE, TPM1_BASE, TPM2_BASE \
   }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS  \
   {                   \
      TPM0, TPM1, TPM2 \
   }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                      \
   {                                  \
      TPM0_IRQn, TPM1_IRQn, TPM2_IRQn \
   }

/*!
 * @}
 */
/* end of group TPM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- TSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct
{
   __IO uint8_t BDH; /**< UART Baud Rate Register: High, offset: 0x0 */
   __IO uint8_t BDL; /**< UART Baud Rate Register: Low, offset: 0x1 */
   __IO uint8_t C1;  /**< UART Control Register 1, offset: 0x2 */
   __IO uint8_t C2;  /**< UART Control Register 2, offset: 0x3 */
   __I uint8_t S1;   /**< UART Status Register 1, offset: 0x4 */
   __IO uint8_t S2;  /**< UART Status Register 2, offset: 0x5 */
   __IO uint8_t C3;  /**< UART Control Register 3, offset: 0x6 */
   __IO uint8_t D;   /**< UART Data Register, offset: 0x7 */
   __IO uint8_t C4;  /**< UART Control Register 4, offset: 0x8 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name BDH - UART Baud Rate Register: High */
#define UART_BDH_SBR_MASK (0x1FU)
#define UART_BDH_SBR_SHIFT (0U)
#define UART_BDH_SBR(x) (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBR_SHIFT)) & UART_BDH_SBR_MASK)
#define UART_BDH_SBNS_MASK (0x20U)
#define UART_BDH_SBNS_SHIFT (5U)
#define UART_BDH_SBNS(x) (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBNS_SHIFT)) & UART_BDH_SBNS_MASK)
#define UART_BDH_RXEDGIE_MASK (0x40U)
#define UART_BDH_RXEDGIE_SHIFT (6U)
#define UART_BDH_RXEDGIE(x) (((uint8_t)(((uint8_t)(x)) << UART_BDH_RXEDGIE_SHIFT)) & UART_BDH_RXEDGIE_MASK)
#define UART_BDH_LBKDIE_MASK (0x80U)
#define UART_BDH_LBKDIE_SHIFT (7U)
#define UART_BDH_LBKDIE(x) (((uint8_t)(((uint8_t)(x)) << UART_BDH_LBKDIE_SHIFT)) & UART_BDH_LBKDIE_MASK)

/*! @name BDL - UART Baud Rate Register: Low */
#define UART_BDL_SBR_MASK (0xFFU)
#define UART_BDL_SBR_SHIFT (0U)
#define UART_BDL_SBR(x) (((uint8_t)(((uint8_t)(x)) << UART_BDL_SBR_SHIFT)) & UART_BDL_SBR_MASK)

/*! @name C1 - UART Control Register 1 */
#define UART_C1_PT_MASK (0x1U)
#define UART_C1_PT_SHIFT (0U)
#define UART_C1_PT(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_PT_SHIFT)) & UART_C1_PT_MASK)
#define UART_C1_PE_MASK (0x2U)
#define UART_C1_PE_SHIFT (1U)
#define UART_C1_PE(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_PE_SHIFT)) & UART_C1_PE_MASK)
#define UART_C1_ILT_MASK (0x4U)
#define UART_C1_ILT_SHIFT (2U)
#define UART_C1_ILT(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_ILT_SHIFT)) & UART_C1_ILT_MASK)
#define UART_C1_WAKE_MASK (0x8U)
#define UART_C1_WAKE_SHIFT (3U)
#define UART_C1_WAKE(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_WAKE_SHIFT)) & UART_C1_WAKE_MASK)
#define UART_C1_M_MASK (0x10U)
#define UART_C1_M_SHIFT (4U)
#define UART_C1_M(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_M_SHIFT)) & UART_C1_M_MASK)
#define UART_C1_RSRC_MASK (0x20U)
#define UART_C1_RSRC_SHIFT (5U)
#define UART_C1_RSRC(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_RSRC_SHIFT)) & UART_C1_RSRC_MASK)
#define UART_C1_UARTSWAI_MASK (0x40U)
#define UART_C1_UARTSWAI_SHIFT (6U)
#define UART_C1_UARTSWAI(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_UARTSWAI_SHIFT)) & UART_C1_UARTSWAI_MASK)
#define UART_C1_LOOPS_MASK (0x80U)
#define UART_C1_LOOPS_SHIFT (7U)
#define UART_C1_LOOPS(x) (((uint8_t)(((uint8_t)(x)) << UART_C1_LOOPS_SHIFT)) & UART_C1_LOOPS_MASK)

/*! @name C2 - UART Control Register 2 */
#define UART_C2_SBK_MASK (0x1U)
#define UART_C2_SBK_SHIFT (0U)
#define UART_C2_SBK(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_SBK_SHIFT)) & UART_C2_SBK_MASK)
#define UART_C2_RWU_MASK (0x2U)
#define UART_C2_RWU_SHIFT (1U)
#define UART_C2_RWU(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_RWU_SHIFT)) & UART_C2_RWU_MASK)
#define UART_C2_RE_MASK (0x4U)
#define UART_C2_RE_SHIFT (2U)
#define UART_C2_RE(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_RE_SHIFT)) & UART_C2_RE_MASK)
#define UART_C2_TE_MASK (0x8U)
#define UART_C2_TE_SHIFT (3U)
#define UART_C2_TE(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_TE_SHIFT)) & UART_C2_TE_MASK)
#define UART_C2_ILIE_MASK (0x10U)
#define UART_C2_ILIE_SHIFT (4U)
#define UART_C2_ILIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_ILIE_SHIFT)) & UART_C2_ILIE_MASK)
#define UART_C2_RIE_MASK (0x20U)
#define UART_C2_RIE_SHIFT (5U)
#define UART_C2_RIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_RIE_SHIFT)) & UART_C2_RIE_MASK)
#define UART_C2_TCIE_MASK (0x40U)
#define UART_C2_TCIE_SHIFT (6U)
#define UART_C2_TCIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_TCIE_SHIFT)) & UART_C2_TCIE_MASK)
#define UART_C2_TIE_MASK (0x80U)
#define UART_C2_TIE_SHIFT (7U)
#define UART_C2_TIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C2_TIE_SHIFT)) & UART_C2_TIE_MASK)

/*! @name S1 - UART Status Register 1 */
#define UART_S1_PF_MASK (0x1U)
#define UART_S1_PF_SHIFT (0U)
#define UART_S1_PF(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_PF_SHIFT)) & UART_S1_PF_MASK)
#define UART_S1_FE_MASK (0x2U)
#define UART_S1_FE_SHIFT (1U)
#define UART_S1_FE(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_FE_SHIFT)) & UART_S1_FE_MASK)
#define UART_S1_NF_MASK (0x4U)
#define UART_S1_NF_SHIFT (2U)
#define UART_S1_NF(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_NF_SHIFT)) & UART_S1_NF_MASK)
#define UART_S1_OR_MASK (0x8U)
#define UART_S1_OR_SHIFT (3U)
#define UART_S1_OR(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_OR_SHIFT)) & UART_S1_OR_MASK)
#define UART_S1_IDLE_MASK (0x10U)
#define UART_S1_IDLE_SHIFT (4U)
#define UART_S1_IDLE(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_IDLE_SHIFT)) & UART_S1_IDLE_MASK)
#define UART_S1_RDRF_MASK (0x20U)
#define UART_S1_RDRF_SHIFT (5U)
#define UART_S1_RDRF(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_RDRF_SHIFT)) & UART_S1_RDRF_MASK)
#define UART_S1_TC_MASK (0x40U)
#define UART_S1_TC_SHIFT (6U)
#define UART_S1_TC(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_TC_SHIFT)) & UART_S1_TC_MASK)
#define UART_S1_TDRE_MASK (0x80U)
#define UART_S1_TDRE_SHIFT (7U)
#define UART_S1_TDRE(x) (((uint8_t)(((uint8_t)(x)) << UART_S1_TDRE_SHIFT)) & UART_S1_TDRE_MASK)

/*! @name S2 - UART Status Register 2 */
#define UART_S2_RAF_MASK (0x1U)
#define UART_S2_RAF_SHIFT (0U)
#define UART_S2_RAF(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_RAF_SHIFT)) & UART_S2_RAF_MASK)
#define UART_S2_LBKDE_MASK (0x2U)
#define UART_S2_LBKDE_SHIFT (1U)
#define UART_S2_LBKDE(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDE_SHIFT)) & UART_S2_LBKDE_MASK)
#define UART_S2_BRK13_MASK (0x4U)
#define UART_S2_BRK13_SHIFT (2U)
#define UART_S2_BRK13(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_BRK13_SHIFT)) & UART_S2_BRK13_MASK)
#define UART_S2_RWUID_MASK (0x8U)
#define UART_S2_RWUID_SHIFT (3U)
#define UART_S2_RWUID(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_RWUID_SHIFT)) & UART_S2_RWUID_MASK)
#define UART_S2_RXINV_MASK (0x10U)
#define UART_S2_RXINV_SHIFT (4U)
#define UART_S2_RXINV(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_RXINV_SHIFT)) & UART_S2_RXINV_MASK)
#define UART_S2_RXEDGIF_MASK (0x40U)
#define UART_S2_RXEDGIF_SHIFT (6U)
#define UART_S2_RXEDGIF(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_RXEDGIF_SHIFT)) & UART_S2_RXEDGIF_MASK)
#define UART_S2_LBKDIF_MASK (0x80U)
#define UART_S2_LBKDIF_SHIFT (7U)
#define UART_S2_LBKDIF(x) (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDIF_SHIFT)) & UART_S2_LBKDIF_MASK)

/*! @name C3 - UART Control Register 3 */
#define UART_C3_PEIE_MASK (0x1U)
#define UART_C3_PEIE_SHIFT (0U)
#define UART_C3_PEIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_PEIE_SHIFT)) & UART_C3_PEIE_MASK)
#define UART_C3_FEIE_MASK (0x2U)
#define UART_C3_FEIE_SHIFT (1U)
#define UART_C3_FEIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_FEIE_SHIFT)) & UART_C3_FEIE_MASK)
#define UART_C3_NEIE_MASK (0x4U)
#define UART_C3_NEIE_SHIFT (2U)
#define UART_C3_NEIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_NEIE_SHIFT)) & UART_C3_NEIE_MASK)
#define UART_C3_ORIE_MASK (0x8U)
#define UART_C3_ORIE_SHIFT (3U)
#define UART_C3_ORIE(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_ORIE_SHIFT)) & UART_C3_ORIE_MASK)
#define UART_C3_TXINV_MASK (0x10U)
#define UART_C3_TXINV_SHIFT (4U)
#define UART_C3_TXINV(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_TXINV_SHIFT)) & UART_C3_TXINV_MASK)
#define UART_C3_TXDIR_MASK (0x20U)
#define UART_C3_TXDIR_SHIFT (5U)
#define UART_C3_TXDIR(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_TXDIR_SHIFT)) & UART_C3_TXDIR_MASK)
#define UART_C3_T8_MASK (0x40U)
#define UART_C3_T8_SHIFT (6U)
#define UART_C3_T8(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_T8_SHIFT)) & UART_C3_T8_MASK)
#define UART_C3_R8_MASK (0x80U)
#define UART_C3_R8_SHIFT (7U)
#define UART_C3_R8(x) (((uint8_t)(((uint8_t)(x)) << UART_C3_R8_SHIFT)) & UART_C3_R8_MASK)

/*! @name D - UART Data Register */
#define UART_D_R0T0_MASK (0x1U)
#define UART_D_R0T0_SHIFT (0U)
#define UART_D_R0T0(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R0T0_SHIFT)) & UART_D_R0T0_MASK)
#define UART_D_R1T1_MASK (0x2U)
#define UART_D_R1T1_SHIFT (1U)
#define UART_D_R1T1(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R1T1_SHIFT)) & UART_D_R1T1_MASK)
#define UART_D_R2T2_MASK (0x4U)
#define UART_D_R2T2_SHIFT (2U)
#define UART_D_R2T2(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R2T2_SHIFT)) & UART_D_R2T2_MASK)
#define UART_D_R3T3_MASK (0x8U)
#define UART_D_R3T3_SHIFT (3U)
#define UART_D_R3T3(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R3T3_SHIFT)) & UART_D_R3T3_MASK)
#define UART_D_R4T4_MASK (0x10U)
#define UART_D_R4T4_SHIFT (4U)
#define UART_D_R4T4(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R4T4_SHIFT)) & UART_D_R4T4_MASK)
#define UART_D_R5T5_MASK (0x20U)
#define UART_D_R5T5_SHIFT (5U)
#define UART_D_R5T5(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R5T5_SHIFT)) & UART_D_R5T5_MASK)
#define UART_D_R6T6_MASK (0x40U)
#define UART_D_R6T6_SHIFT (6U)
#define UART_D_R6T6(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R6T6_SHIFT)) & UART_D_R6T6_MASK)
#define UART_D_R7T7_MASK (0x80U)
#define UART_D_R7T7_SHIFT (7U)
#define UART_D_R7T7(x) (((uint8_t)(((uint8_t)(x)) << UART_D_R7T7_SHIFT)) & UART_D_R7T7_MASK)

/*! @name C4 - UART Control Register 4 */
#define UART_C4_RDMAS_MASK (0x20U)
#define UART_C4_RDMAS_SHIFT (5U)
#define UART_C4_RDMAS(x) (((uint8_t)(((uint8_t)(x)) << UART_C4_RDMAS_SHIFT)) & UART_C4_RDMAS_MASK)
#define UART_C4_TDMAS_MASK (0x80U)
#define UART_C4_TDMAS_SHIFT (7U)
#define UART_C4_TDMAS(x) (((uint8_t)(((uint8_t)(x)) << UART_C4_TDMAS_SHIFT)) & UART_C4_TDMAS_MASK)

/*!
 * @}
 */
/* end of group UART_Register_Masks */

/* UART - Peripheral instance base addresses */
/** Peripheral UART1 base address */
#define UART1_BASE (0x4006B000u)
/** Peripheral UART1 base pointer */
#define UART1 ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE (0x4006C000u)
/** Peripheral UART2 base pointer */
#define UART2 ((UART_Type *)UART2_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS          \
   {                             \
      0u, UART1_BASE, UART2_BASE \
   }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS              \
   {                                \
      (UART_Type *)0u, UART1, UART2 \
   }
/** Interrupt vectors for the UART peripheral type */
#define UART_RX_TX_IRQS                     \
   {                                        \
      NotAvail_IRQn, UART1_IRQn, UART2_IRQn \
   }
#define UART_ERR_IRQS                       \
   {                                        \
      NotAvail_IRQn, UART1_IRQn, UART2_IRQn \
   }

/*!
 * @}
 */
/* end of group UART_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- UART0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART0_Peripheral_Access_Layer UART0 Peripheral Access Layer
 * @{
 */

/** UART0 - Register Layout Typedef */
typedef struct
{
   __IO uint8_t BDH; /**< UART Baud Rate Register High, offset: 0x0 */
   __IO uint8_t BDL; /**< UART Baud Rate Register Low, offset: 0x1 */
   __IO uint8_t C1;  /**< UART Control Register 1, offset: 0x2 */
   __IO uint8_t C2;  /**< UART Control Register 2, offset: 0x3 */
   __IO uint8_t S1;  /**< UART Status Register 1, offset: 0x4 */
   __IO uint8_t S2;  /**< UART Status Register 2, offset: 0x5 */
   __IO uint8_t C3;  /**< UART Control Register 3, offset: 0x6 */
   __IO uint8_t D;   /**< UART Data Register, offset: 0x7 */
   __IO uint8_t MA1; /**< UART Match Address Registers 1, offset: 0x8 */
   __IO uint8_t MA2; /**< UART Match Address Registers 2, offset: 0x9 */
   __IO uint8_t C4;  /**< UART Control Register 4, offset: 0xA */
   __IO uint8_t C5;  /**< UART Control Register 5, offset: 0xB */
} UART0_Type;

/* ----------------------------------------------------------------------------
   -- UART0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART0_Register_Masks UART0 Register Masks
 * @{
 */

/*! @name BDH - UART Baud Rate Register High */
#define UART0_BDH_SBR_MASK (0x1FU)
#define UART0_BDH_SBR_SHIFT (0U)
#define UART0_BDH_SBR(x) (((uint8_t)(((uint8_t)(x)) << UART0_BDH_SBR_SHIFT)) & UART0_BDH_SBR_MASK)
#define UART0_BDH_SBNS_MASK (0x20U)
#define UART0_BDH_SBNS_SHIFT (5U)
#define UART0_BDH_SBNS(x) (((uint8_t)(((uint8_t)(x)) << UART0_BDH_SBNS_SHIFT)) & UART0_BDH_SBNS_MASK)
#define UART0_BDH_RXEDGIE_MASK (0x40U)
#define UART0_BDH_RXEDGIE_SHIFT (6U)
#define UART0_BDH_RXEDGIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_BDH_RXEDGIE_SHIFT)) & UART0_BDH_RXEDGIE_MASK)
#define UART0_BDH_LBKDIE_MASK (0x80U)
#define UART0_BDH_LBKDIE_SHIFT (7U)
#define UART0_BDH_LBKDIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_BDH_LBKDIE_SHIFT)) & UART0_BDH_LBKDIE_MASK)

/*! @name BDL - UART Baud Rate Register Low */
#define UART0_BDL_SBR_MASK (0xFFU)
#define UART0_BDL_SBR_SHIFT (0U)
#define UART0_BDL_SBR(x) (((uint8_t)(((uint8_t)(x)) << UART0_BDL_SBR_SHIFT)) & UART0_BDL_SBR_MASK)

/*! @name C1 - UART Control Register 1 */
#define UART0_C1_PT_MASK (0x1U)
#define UART0_C1_PT_SHIFT (0U)
#define UART0_C1_PT(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_PT_SHIFT)) & UART0_C1_PT_MASK)
#define UART0_C1_PE_MASK (0x2U)
#define UART0_C1_PE_SHIFT (1U)
#define UART0_C1_PE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_PE_SHIFT)) & UART0_C1_PE_MASK)
#define UART0_C1_ILT_MASK (0x4U)
#define UART0_C1_ILT_SHIFT (2U)
#define UART0_C1_ILT(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_ILT_SHIFT)) & UART0_C1_ILT_MASK)
#define UART0_C1_WAKE_MASK (0x8U)
#define UART0_C1_WAKE_SHIFT (3U)
#define UART0_C1_WAKE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_WAKE_SHIFT)) & UART0_C1_WAKE_MASK)
#define UART0_C1_M_MASK (0x10U)
#define UART0_C1_M_SHIFT (4U)
#define UART0_C1_M(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_M_SHIFT)) & UART0_C1_M_MASK)
#define UART0_C1_RSRC_MASK (0x20U)
#define UART0_C1_RSRC_SHIFT (5U)
#define UART0_C1_RSRC(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_RSRC_SHIFT)) & UART0_C1_RSRC_MASK)
#define UART0_C1_DOZEEN_MASK (0x40U)
#define UART0_C1_DOZEEN_SHIFT (6U)
#define UART0_C1_DOZEEN(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_DOZEEN_SHIFT)) & UART0_C1_DOZEEN_MASK)
#define UART0_C1_LOOPS_MASK (0x80U)
#define UART0_C1_LOOPS_SHIFT (7U)
#define UART0_C1_LOOPS(x) (((uint8_t)(((uint8_t)(x)) << UART0_C1_LOOPS_SHIFT)) & UART0_C1_LOOPS_MASK)

/*! @name C2 - UART Control Register 2 */
#define UART0_C2_SBK_MASK (0x1U)
#define UART0_C2_SBK_SHIFT (0U)
#define UART0_C2_SBK(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_SBK_SHIFT)) & UART0_C2_SBK_MASK)
#define UART0_C2_RWU_MASK (0x2U)
#define UART0_C2_RWU_SHIFT (1U)
#define UART0_C2_RWU(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_RWU_SHIFT)) & UART0_C2_RWU_MASK)
#define UART0_C2_RE_MASK (0x4U)
#define UART0_C2_RE_SHIFT (2U)
#define UART0_C2_RE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_RE_SHIFT)) & UART0_C2_RE_MASK)
#define UART0_C2_TE_MASK (0x8U)
#define UART0_C2_TE_SHIFT (3U)
#define UART0_C2_TE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_TE_SHIFT)) & UART0_C2_TE_MASK)
#define UART0_C2_ILIE_MASK (0x10U)
#define UART0_C2_ILIE_SHIFT (4U)
#define UART0_C2_ILIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_ILIE_SHIFT)) & UART0_C2_ILIE_MASK)
#define UART0_C2_RIE_MASK (0x20U)
#define UART0_C2_RIE_SHIFT (5U)
#define UART0_C2_RIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_RIE_SHIFT)) & UART0_C2_RIE_MASK)
#define UART0_C2_TCIE_MASK (0x40U)
#define UART0_C2_TCIE_SHIFT (6U)
#define UART0_C2_TCIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_TCIE_SHIFT)) & UART0_C2_TCIE_MASK)
#define UART0_C2_TIE_MASK (0x80U)
#define UART0_C2_TIE_SHIFT (7U)
#define UART0_C2_TIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C2_TIE_SHIFT)) & UART0_C2_TIE_MASK)

/*! @name S1 - UART Status Register 1 */
#define UART0_S1_PF_MASK (0x1U)
#define UART0_S1_PF_SHIFT (0U)
#define UART0_S1_PF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_PF_SHIFT)) & UART0_S1_PF_MASK)
#define UART0_S1_FE_MASK (0x2U)
#define UART0_S1_FE_SHIFT (1U)
#define UART0_S1_FE(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_FE_SHIFT)) & UART0_S1_FE_MASK)
#define UART0_S1_NF_MASK (0x4U)
#define UART0_S1_NF_SHIFT (2U)
#define UART0_S1_NF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_NF_SHIFT)) & UART0_S1_NF_MASK)
#define UART0_S1_OR_MASK (0x8U)
#define UART0_S1_OR_SHIFT (3U)
#define UART0_S1_OR(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_OR_SHIFT)) & UART0_S1_OR_MASK)
#define UART0_S1_IDLE_MASK (0x10U)
#define UART0_S1_IDLE_SHIFT (4U)
#define UART0_S1_IDLE(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_IDLE_SHIFT)) & UART0_S1_IDLE_MASK)
#define UART0_S1_RDRF_MASK (0x20U)
#define UART0_S1_RDRF_SHIFT (5U)
#define UART0_S1_RDRF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_RDRF_SHIFT)) & UART0_S1_RDRF_MASK)
#define UART0_S1_TC_MASK (0x40U)
#define UART0_S1_TC_SHIFT (6U)
#define UART0_S1_TC(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_TC_SHIFT)) & UART0_S1_TC_MASK)
#define UART0_S1_TDRE_MASK (0x80U)
#define UART0_S1_TDRE_SHIFT (7U)
#define UART0_S1_TDRE(x) (((uint8_t)(((uint8_t)(x)) << UART0_S1_TDRE_SHIFT)) & UART0_S1_TDRE_MASK)

/*! @name S2 - UART Status Register 2 */
#define UART0_S2_RAF_MASK (0x1U)
#define UART0_S2_RAF_SHIFT (0U)
#define UART0_S2_RAF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_RAF_SHIFT)) & UART0_S2_RAF_MASK)
#define UART0_S2_LBKDE_MASK (0x2U)
#define UART0_S2_LBKDE_SHIFT (1U)
#define UART0_S2_LBKDE(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_LBKDE_SHIFT)) & UART0_S2_LBKDE_MASK)
#define UART0_S2_BRK13_MASK (0x4U)
#define UART0_S2_BRK13_SHIFT (2U)
#define UART0_S2_BRK13(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_BRK13_SHIFT)) & UART0_S2_BRK13_MASK)
#define UART0_S2_RWUID_MASK (0x8U)
#define UART0_S2_RWUID_SHIFT (3U)
#define UART0_S2_RWUID(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_RWUID_SHIFT)) & UART0_S2_RWUID_MASK)
#define UART0_S2_RXINV_MASK (0x10U)
#define UART0_S2_RXINV_SHIFT (4U)
#define UART0_S2_RXINV(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_RXINV_SHIFT)) & UART0_S2_RXINV_MASK)
#define UART0_S2_MSBF_MASK (0x20U)
#define UART0_S2_MSBF_SHIFT (5U)
#define UART0_S2_MSBF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_MSBF_SHIFT)) & UART0_S2_MSBF_MASK)
#define UART0_S2_RXEDGIF_MASK (0x40U)
#define UART0_S2_RXEDGIF_SHIFT (6U)
#define UART0_S2_RXEDGIF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_RXEDGIF_SHIFT)) & UART0_S2_RXEDGIF_MASK)
#define UART0_S2_LBKDIF_MASK (0x80U)
#define UART0_S2_LBKDIF_SHIFT (7U)
#define UART0_S2_LBKDIF(x) (((uint8_t)(((uint8_t)(x)) << UART0_S2_LBKDIF_SHIFT)) & UART0_S2_LBKDIF_MASK)

/*! @name C3 - UART Control Register 3 */
#define UART0_C3_PEIE_MASK (0x1U)
#define UART0_C3_PEIE_SHIFT (0U)
#define UART0_C3_PEIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_PEIE_SHIFT)) & UART0_C3_PEIE_MASK)
#define UART0_C3_FEIE_MASK (0x2U)
#define UART0_C3_FEIE_SHIFT (1U)
#define UART0_C3_FEIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_FEIE_SHIFT)) & UART0_C3_FEIE_MASK)
#define UART0_C3_NEIE_MASK (0x4U)
#define UART0_C3_NEIE_SHIFT (2U)
#define UART0_C3_NEIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_NEIE_SHIFT)) & UART0_C3_NEIE_MASK)
#define UART0_C3_ORIE_MASK (0x8U)
#define UART0_C3_ORIE_SHIFT (3U)
#define UART0_C3_ORIE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_ORIE_SHIFT)) & UART0_C3_ORIE_MASK)
#define UART0_C3_TXINV_MASK (0x10U)
#define UART0_C3_TXINV_SHIFT (4U)
#define UART0_C3_TXINV(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_TXINV_SHIFT)) & UART0_C3_TXINV_MASK)
#define UART0_C3_TXDIR_MASK (0x20U)
#define UART0_C3_TXDIR_SHIFT (5U)
#define UART0_C3_TXDIR(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_TXDIR_SHIFT)) & UART0_C3_TXDIR_MASK)
#define UART0_C3_R9T8_MASK (0x40U)
#define UART0_C3_R9T8_SHIFT (6U)
#define UART0_C3_R9T8(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_R9T8_SHIFT)) & UART0_C3_R9T8_MASK)
#define UART0_C3_R8T9_MASK (0x80U)
#define UART0_C3_R8T9_SHIFT (7U)
#define UART0_C3_R8T9(x) (((uint8_t)(((uint8_t)(x)) << UART0_C3_R8T9_SHIFT)) & UART0_C3_R8T9_MASK)

/*! @name D - UART Data Register */
#define UART0_D_R0T0_MASK (0x1U)
#define UART0_D_R0T0_SHIFT (0U)
#define UART0_D_R0T0(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R0T0_SHIFT)) & UART0_D_R0T0_MASK)
#define UART0_D_R1T1_MASK (0x2U)
#define UART0_D_R1T1_SHIFT (1U)
#define UART0_D_R1T1(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R1T1_SHIFT)) & UART0_D_R1T1_MASK)
#define UART0_D_R2T2_MASK (0x4U)
#define UART0_D_R2T2_SHIFT (2U)
#define UART0_D_R2T2(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R2T2_SHIFT)) & UART0_D_R2T2_MASK)
#define UART0_D_R3T3_MASK (0x8U)
#define UART0_D_R3T3_SHIFT (3U)
#define UART0_D_R3T3(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R3T3_SHIFT)) & UART0_D_R3T3_MASK)
#define UART0_D_R4T4_MASK (0x10U)
#define UART0_D_R4T4_SHIFT (4U)
#define UART0_D_R4T4(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R4T4_SHIFT)) & UART0_D_R4T4_MASK)
#define UART0_D_R5T5_MASK (0x20U)
#define UART0_D_R5T5_SHIFT (5U)
#define UART0_D_R5T5(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R5T5_SHIFT)) & UART0_D_R5T5_MASK)
#define UART0_D_R6T6_MASK (0x40U)
#define UART0_D_R6T6_SHIFT (6U)
#define UART0_D_R6T6(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R6T6_SHIFT)) & UART0_D_R6T6_MASK)
#define UART0_D_R7T7_MASK (0x80U)
#define UART0_D_R7T7_SHIFT (7U)
#define UART0_D_R7T7(x) (((uint8_t)(((uint8_t)(x)) << UART0_D_R7T7_SHIFT)) & UART0_D_R7T7_MASK)

/*! @name MA1 - UART Match Address Registers 1 */
#define UART0_MA1_MA_MASK (0xFFU)
#define UART0_MA1_MA_SHIFT (0U)
#define UART0_MA1_MA(x) (((uint8_t)(((uint8_t)(x)) << UART0_MA1_MA_SHIFT)) & UART0_MA1_MA_MASK)

/*! @name MA2 - UART Match Address Registers 2 */
#define UART0_MA2_MA_MASK (0xFFU)
#define UART0_MA2_MA_SHIFT (0U)
#define UART0_MA2_MA(x) (((uint8_t)(((uint8_t)(x)) << UART0_MA2_MA_SHIFT)) & UART0_MA2_MA_MASK)

/*! @name C4 - UART Control Register 4 */
#define UART0_C4_OSR_MASK (0x1FU)
#define UART0_C4_OSR_SHIFT (0U)
#define UART0_C4_OSR(x) (((uint8_t)(((uint8_t)(x)) << UART0_C4_OSR_SHIFT)) & UART0_C4_OSR_MASK)
#define UART0_C4_M10_MASK (0x20U)
#define UART0_C4_M10_SHIFT (5U)
#define UART0_C4_M10(x) (((uint8_t)(((uint8_t)(x)) << UART0_C4_M10_SHIFT)) & UART0_C4_M10_MASK)
#define UART0_C4_MAEN2_MASK (0x40U)
#define UART0_C4_MAEN2_SHIFT (6U)
#define UART0_C4_MAEN2(x) (((uint8_t)(((uint8_t)(x)) << UART0_C4_MAEN2_SHIFT)) & UART0_C4_MAEN2_MASK)
#define UART0_C4_MAEN1_MASK (0x80U)
#define UART0_C4_MAEN1_SHIFT (7U)
#define UART0_C4_MAEN1(x) (((uint8_t)(((uint8_t)(x)) << UART0_C4_MAEN1_SHIFT)) & UART0_C4_MAEN1_MASK)

/*! @name C5 - UART Control Register 5 */
#define UART0_C5_RESYNCDIS_MASK (0x1U)
#define UART0_C5_RESYNCDIS_SHIFT (0U)
#define UART0_C5_RESYNCDIS(x) (((uint8_t)(((uint8_t)(x)) << UART0_C5_RESYNCDIS_SHIFT)) & UART0_C5_RESYNCDIS_MASK)
#define UART0_C5_BOTHEDGE_MASK (0x2U)
#define UART0_C5_BOTHEDGE_SHIFT (1U)
#define UART0_C5_BOTHEDGE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C5_BOTHEDGE_SHIFT)) & UART0_C5_BOTHEDGE_MASK)
#define UART0_C5_RDMAE_MASK (0x20U)
#define UART0_C5_RDMAE_SHIFT (5U)
#define UART0_C5_RDMAE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C5_RDMAE_SHIFT)) & UART0_C5_RDMAE_MASK)
#define UART0_C5_TDMAE_MASK (0x80U)
#define UART0_C5_TDMAE_SHIFT (7U)
#define UART0_C5_TDMAE(x) (((uint8_t)(((uint8_t)(x)) << UART0_C5_TDMAE_SHIFT)) & UART0_C5_TDMAE_MASK)

/*!
 * @}
 */
/* end of group UART0_Register_Masks */

/* UART0 - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0 ((UART0_Type *)UART0_BASE)
/** Array initializer of UART0 peripheral base addresses */
#define UART0_BASE_ADDRS \
   {                     \
      UART0_BASE         \
   }
/** Array initializer of UART0 peripheral base pointers */
#define UART0_BASE_PTRS \
   {                    \
      UART0             \
   }
/** Interrupt vectors for the UART0 peripheral type */
#define UART0_RX_TX_IRQS \
   {                     \
      UART0_IRQn         \
   }
#define UART0_ERR_IRQS \
   {                   \
      UART0_IRQn       \
   }

/*!
 * @}
 */
/* end of group UART0_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

#endif /* _HARDWARE_MKL46Z4_H_ */

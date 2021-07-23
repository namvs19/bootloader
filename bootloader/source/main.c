
#include "Flash.h"
#include "PIT.h"
#include "Board.h"
#include "UART0.h"

uint32_t g_VectorsTableRam[NUMBER_OF_INT_VECTORS] __attribute__((aligned(256)));

__ramfunc void PIT_IRQHandler1(void);

int main(void)
{
   uint8_t index;
   for (index = 0; index < 48u; index++)
   {
      g_VectorsTableRam[index] = *((uint32_t *)(0x04u * index));
   }
   g_VectorsTableRam[38u] = (uint32_t)PIT_IRQHandler1;

   __disable_irq();
   __DMB(); /* Data memory barrier */
   SCB->VTOR = (uint32_t)(g_VectorsTableRam);
   __DSB();
   __enable_irq();

   Board_LedInit();

   PIT_Config(PIT, PIT_Chnl_0, 0xFFFFFFFFu);
   PIT_SetTimerPeriod(PIT, PIT_Chnl_0, PIT_LDVAL_1MS);
   PIT->MCR |= PIT_MCR_FRZ_MASK;
   NVIC_EnableIRQ(PIT_IRQn);
   PIT_EnableInterrupt(PIT, PIT_Chnl_0);
   PIT_StartTimer(PIT, PIT_Chnl_0);

   FLASH_EraseSector(0xA000u);

   while (1)
   {
   }
}

__ramfunc void PIT_IRQHandler1(void)
{
   static uint16_t counter = 0;

   if (counter == 500u)
   {
      GPIOD->PTOR |= (1u << 5);
      counter = 0;
   }
   else
   {
      counter++;
   }
   PIT->CHANNEL[0].TFLG |= 0x1u;
}
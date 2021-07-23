
#include "Board.h"
#include "PIT.h"

int main(void)
{
   // Board_LedInit();

   // __DMB(); /* Data memory barrier */
   // SCB->VTOR = 0x0000A000u;
   // __DSB();

   PIT_Config(PIT, PIT_Chnl_0, 0xFFFFFFFFu);
   PIT_SetTimerPeriod(PIT, PIT_Chnl_0, 0xFFFFFFFFu);
   PIT->MCR |= PIT_MCR_FRZ_MASK;
   PIT_StartTimer(PIT, PIT_Chnl_0);

   SIM->SCGC6 |= SIM_SCGC6_FTF_MASK;

   while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
      ;

   /** Clear */
   FTFA->FCCOB0 = 0x09u;

   FTFA->FCCOB1 = (0xA000u & 0xFF0000u) >> 16u;
   FTFA->FCCOB2 = (0xA000u & 0xFF00u) >> 8u;
   FTFA->FCCOB3 = (0xA000u & 0xFFu);

   FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;

   while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
      ;

   /** Write */
   FTFA->FCCOB0 = 0x06u;

   FTFA->FCCOB1 = (0xA000u & 0xFF0000u) >> 16u;
   FTFA->FCCOB2 = (0xA000u & 0xFF00u) >> 8u;
   FTFA->FCCOB3 = (0xA000u & 0xFFu);

   FTFA->FCCOB4 = 0x01u;
   FTFA->FCCOB5 = 0x02u;
   FTFA->FCCOB6 = 0x03u;
   FTFA->FCCOB7 = 0x04u;

   FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;

   while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
      ;

   /** Clear */
   FTFA->FCCOB0 = 0x09u;

   FTFA->FCCOB1 = (0xA000u & 0xFF0000u) >> 16u;
   FTFA->FCCOB2 = (0xA000u & 0xFF00u) >> 8u;
   FTFA->FCCOB3 = (0xA000u & 0xFFu);

   FTFA->FSTAT |= FTFA_FSTAT_CCIF_MASK;
   while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0)
      ;

   while (1)
   {
   }
}

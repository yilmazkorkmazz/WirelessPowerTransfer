#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/cmp1.h"
#include "mcc_generated_files/tmr1.h"



int takeonebit()
{
   TMR1_StartTimer();
   CM1CON0bits. C1ON = 1;
   APFCONbits.NCO1SEL = 0; 
   PORTCbits.RC1 = 0;
   
   while (PIR1bits.TMR1IF == 0)
   {
       if (CMP1_GetOutputStatus())
       {
           PORTCbits.RC1 = 1;
       }
       
       else
       {
           PORTCbits.RC1 = PORTCbits.RC1;
       } 
       
       TMR1_Reload();
       CM1CON0bits. C1ON = 0;  
   }  
   return PORTCbits.RC1;
}


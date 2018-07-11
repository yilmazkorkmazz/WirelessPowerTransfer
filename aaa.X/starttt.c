#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "mcc_generated_files/tmr1.h"

extern volatile unsigned char           controltimes              @ 0x320;
extern volatile unsigned char           checkdigit              @ 0x330;

void starttt()
{
   controltimes = 6 ;
   checkdigit = 0;
   TMR1_StartTimer();
   ADC_StartConversion();
   
   while ( controltimes > 0)
   {
       while (ADRESH > 32 & ADCON2 == 0)
       {
           checkdigit = 1;
       }
       
       if (ADC_IsConversionDone())
       {
           if(checkdigit == 1)
           {
               controltimes = controltimes - 1;
           }
           else
           {
               controltimes = 6;   
           }
           TMR1_Reload();
           ADC_StartConversion();
           checkdigit = 0;
       }  
   }   
}

#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"


void starttt(void)
{
   0032H = 6 ;
   0033H = 0;
   ADCON2 = 0;
   ADC_StartConversion();
   
   while ( 0032H > 0)
   {
       while(ADRESH.3 == 1 & ADCON2 == 0)
       {
           0033H = 1;
           //
       }
       
       if (ADC_IsConversionDone())
       {
           ADCON2 = 0;
           
           if(0033H == 1)
           {
               0032H = 0032H - 1;
           }
           else
           {
               0032H = 6;   
           }
           
           ADC_StartConversion();
           0033H = 0;
       }  
   }   
}

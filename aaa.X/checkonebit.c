#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"

void checkonebit(void)
{
   ADC_StartConversion();
   0012H = 0;
  
   while (!ADC_IsConversionDone())
   {
       while(ADRESH.3 == 1 & ADCON2 == 0)
       {
           0012H = 1;
           //
       }
   }    
}

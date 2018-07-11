#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"

extern volatile unsigned char           checkdigit2              @ 0x420;
extern volatile unsigned char           devicetype              @ 0x430;
extern volatile unsigned char           digitnumber              @ 0x440;
extern volatile unsigned char           digitloop             @ 0x450;
extern volatile unsigned char           basestwo              @ 0x460;

void checkbit()
{
    ADC_StartConversion();
    checkdigit2 = 0;
   
    while (!ADC_IsConversionDone())
    {
        while(ADRESH > 32 & ADCON2 == 0)
        {
           checkdigit2 = 1;
           
        }
    }
}

uint8_t checktype(void)
{
    devicetype = 0;
    digitnumber = 0;
      
    while (digitnumber < 4)
    {   
      basestwo = 2;
      checkbit();
    
      if (checkdigit2 == 1)
      {
        if (digitnumber == 0)
        {
            devicetype = 1;
        }
        else
        {
            for (digitloop = digitnumber;digitloop > 1; digitloop-- )
            {
                basestwo = basestwo + basestwo;
            }
            devicetype = devicetype + basestwo;
        }    
      }
      else 
      {
        devicetype = devicetype;
      }
      digitnumber = digitnumber + 1;
    }
    return devicetype;
}

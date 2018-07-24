#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "mcc_generated_files/tmr1.h"



bool isDeviceConnected(void)
{
    return 1;
}

int sendbit()
{
    TMR1_StartTimer();
    PORTCbits.RC1 = 0;
    
    while(PIR1bits.TMR1IF == 0)
    {
        if (isDeviceConnected())
        {
           PORTCbits.RC1 = 1;  
        }
        else
        {
            PORTCbits.RC1 = PORTCbits.RC1;
        }
    }
    return PORTCbits.RC1;
}

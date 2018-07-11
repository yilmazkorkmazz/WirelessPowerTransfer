//#include "mcc_generated_files/adc.h"
//#include "mcc_generated_files/mcc.h"
//#include "mcc_generated_files/pin_manager.h"
//#include "mcc_generated_files/tmr0.h"
//#include "mcc_generated_files/tmr1.h"
//
//extern volatile unsigned char           sixdigit              @ 0x390;
//extern volatile unsigned char           bitt              @ 0x380;
//
//bool startFlag = 0;
//
//bool isDeviceConnected(void)
//{
//    return startFlag;
//}
//
//uint8_t sendbits(void)
//{
//    sixdigit = 6;
//    while(PIR1bits.TMR1IF == 0 & sixdigit > 0)
//    {
//        TMR1_StartTimer()
//        if (isDeviceConnected())
//        {
//           bitt = 1;
//           sixdigit = sixdigit - 1;   
//        }
//        else
//        {
//            bitt = 0;
//            sixdigit = 6;
//        }
//    }
//    return bitt;
//}

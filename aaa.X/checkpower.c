#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "checkonebit.h"

//sadece power class? aç?p onebit i?lemi de ayn? class da yap?labilir ?imdilik böyle yapt?m

void checkpower(void)
{
   0021H = 0; //bit
   0022H = 0; //total value
   0023H = 0; //üssü
   
   for(0021H=0 ; 0021H<8; 0021H++)
   {        
    0024H = 2; //2 üssü oldu?u için
    checkonebit(void);
    
    if (0012H == 1)
    {
        if (0021 == 0)
        {
            0022H = 1;
        }
        else if (0021 == 1)
        {
            0022H = 0022H + 2;
        }
        
        else
        {
            for(0023H = 0021H; 0023H > 1; 0023--)
            {
              0024H = 0024H + 0024H;
            }
            
            0022H = 0022H + 0024H;
        }  
    }
    else 
    {
        0022H = 0022H;
    }
   } 
}








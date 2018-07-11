#include <xc.h>
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "mcc_generated_files/tmr1.h"
#include "errorCheck.h"

bool errorFlag = 0;

bool errorOccured(void)
{
    return errorFlag;
}

void setError(void)
{
    errorFlag = 1;
}

void clearErrorFlag(void)
{
    errorFlag = 0;
}

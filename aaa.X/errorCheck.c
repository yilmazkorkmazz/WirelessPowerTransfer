
#include <xc.h>
#include "mcc.h"
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




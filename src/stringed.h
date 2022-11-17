#pragma once
#include "orchestra.h"
class stringed :
    public orchestra
{
private:
    static unsigned int cnt;
    char* manufacturer,*info;
}

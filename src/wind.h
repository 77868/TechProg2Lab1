#pragma once
#include "orchestra.h"
class wind :
    public orchestra
{
private:
    static unsigned int cnt;
    char* defectInfo,*manufacturer;
};


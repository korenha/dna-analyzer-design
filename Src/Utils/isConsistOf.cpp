#include "isConsistOf.h"
#include <string.h>


bool isConsistOf(const char* str, const char* consisted)
{

    size_t i;
    size_t lenStr = strlen(str);

    for (i = 0; i < lenStr; ++i)
    {
        if(!isConsistOf(str[i],consisted))
                return false;
    }
    return true;
}

bool isConsistOf(char str, const char* consisted)
{
    size_t j;
    size_t lenConsisted = strlen(consisted);

    for (j = 0; j < lenConsisted ; ++j)
    {
        if(str == consisted[j])
            return true;
    }

    return false;
}

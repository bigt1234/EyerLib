#include "EyerString.hpp"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

namespace Eyer {
    EyerString::EyerString()
    {

    }

    EyerString::EyerString(const EyerString & str)
    {
        *this = str;
    }

    EyerString::~EyerString()
    {
        ClearStr();
    }

    EyerString::EyerString(char _str[])
    {
        ClearStr();

        int _strLen = strlen(_str) + 1;
        str = (char *)malloc(_strLen);
        memcpy(str, _str, _strLen);
    }

    EyerString & EyerString::operator = (const EyerString & s)
    {
        ClearStr();
        int _strLen = strlen(s.str) + 1;
        str = (char *)malloc(_strLen);
        memcpy(str, s.str, _strLen);

        return *this;
    }

    bool EyerString::operator == (const EyerString & s)
    {
        if(IsEmpty() && s.IsEmpty()){
            return true;
        }

        if(IsEmpty()){
            return false;
        }

        if(s.IsEmpty()){
            return false;
        }

        if (strcmp(str, s.str) == 0) {
            return true;
        }

        return false;
    }

    bool EyerString::IsEmpty() const
    {
        if(str == nullptr){
            return true;
        }
        return false;
    }

    int EyerString::ClearStr()
    {
        if(str != nullptr){
            free(str);
            str = nullptr;
        }

        return 0;
    }
}

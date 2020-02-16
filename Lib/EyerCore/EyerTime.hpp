#ifndef	EYER_CORE_TIME_H
#define	EYER_CORE_TIME_H

#include "EyerString.hpp"

namespace Eyer
{
    class EyerTime
    {
    public:
        static long long GetTime();
        static EyerString TimeFormat();
    };
}

#endif

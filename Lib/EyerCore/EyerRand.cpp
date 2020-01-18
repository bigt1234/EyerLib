#include "EyerMath.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace Eyer {
    int EyerRand::Rand(int x)
    {
        return rand() % x;
    }
}
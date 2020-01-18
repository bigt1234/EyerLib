#ifndef	EYER_LIB_REDNER_LINE_AV_H
#define	EYER_LIB_REDNER_LINE_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerLine
    {
    private:
        EyerVec2 point1;
        EyerVec2 point2;
    public:
        EyerLine();
        ~EyerLine();
    };
}

#endif
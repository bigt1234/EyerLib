#include "EyerGPUDomino.hpp"

namespace Eyer
{
    EyerCommonParams::EyerCommonParams()
    {

    }

    EyerCommonParams::~EyerCommonParams()
    {

    }

    EyerCommonParams::EyerCommonParams(const EyerCommonParams & params)
    {
        *this = params;
    }

    EyerCommonParams::EyerCommonParams & operator = (const EyerCommonParams & params)
    {
        return *this;
    }
}
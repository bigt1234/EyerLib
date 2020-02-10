#ifndef	EYER_LIB_TYPE_AV_H
#define	EYER_LIB_TYPE_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerType;
    class EyerTypePrivate;

    class EyerType
    {
    private:
        EyerString typeFile;
        EyerTypePrivate * impl = nullptr;
    public:
        EyerType(EyerString typeFile);
        ~EyerType();

        int Init();

        int GenChar(char c, int pixel_height, int * width, int * height);
    };
}

#endif
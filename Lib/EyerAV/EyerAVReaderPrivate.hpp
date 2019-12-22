#ifndef	EYER_LIB_AV_READER_PRIVATE_H
#define	EYER_LIB_AV_READER_PRIVATE_H

#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

namespace Eyer
{
    class EyerAVReaderPrivate
    {
    public:
        RedString path;
        AVFormatContext * formatCtx = nullptr;
    };
}


#endif
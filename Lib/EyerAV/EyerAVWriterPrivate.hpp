#ifndef	EYER_LIB_AV_WRITE_PRIVATE_H
#define	EYER_LIB_AV_WRITE_PRIVATE_H

#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

namespace Eyer
{
    class EyerAVWriterPrivate
    {
    public:
        RedString path;
        AVFormatContext * formatCtx = nullptr;
    };
}

#endif
#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

namespace Eyer
{
    EyerAVReader::EyerAVReader(RedString _path)
    {
        path = _path;

        av_register_all();
        avformat_network_init();

        formatCtx = (AVFormatContext *)avformat_alloc_context();
    }

    EyerAVReader::~EyerAVReader()
    {
        
    }

    int EyerAVReader::Open()
    {
        return 0;
    }

    int EyerAVReader::Close()
    {
        return 0;
    }

    int EyerAVReader::Read(EyerAVPacket * packet)
    {
        return 0;
    }
}
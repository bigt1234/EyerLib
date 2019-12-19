#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

namespace Eyer
{
    EyerAVPacket::EyerAVPacket()
    {
        packet = (void *)av_packet_alloc();
        av_init_packet((AVPacket *)packet);
    }

    EyerAVPacket::~EyerAVPacket()
    {
        if (packet != nullptr) {
            av_free_packet((AVPacket *)packet);
            packet = nullptr;
        }
    }
}
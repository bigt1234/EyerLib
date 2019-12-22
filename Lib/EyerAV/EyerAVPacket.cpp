#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

#include "EyerAVPacketPrivate.hpp"

namespace Eyer
{
    EyerAVPacket::EyerAVPacket()
    {
        piml = new EyerAVPacketPrivate();

        piml->packet = av_packet_alloc();
        av_init_packet(piml->packet);
    }

    EyerAVPacket::~EyerAVPacket()
    {
        if (piml->packet != nullptr) {
            av_packet_free(&piml->packet);
            piml->packet = nullptr;
        }

        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVPacket::GetStreamId()
    {
        return piml->packet->stream_index;
    }

    uint64_t EyerAVPacket::GetPTS()
    {
        return piml->packet->pts;
    }

    uint64_t EyerAVPacket::GetDTS()
    {
        return piml->packet->dts;
    }
}
#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

#include "EyerAVFramePrivate.hpp"

namespace Eyer
{
    EyerAVFrame::EyerAVFrame()
    {
        piml = new EyerAVFramePrivate();
        piml->frame = av_frame_alloc();
    }

    EyerAVFrame::~EyerAVFrame()
    {
        if(piml->data != nullptr){
            free(piml->data);
            piml->data = nullptr;
        }
        av_frame_unref(piml->frame);
        av_frame_free(&piml->frame);
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVFrame::SetData(unsigned char * _data, int _dataLen)
    {
        piml->data = (unsigned char *)malloc(_dataLen);

        memcpy(piml->data, _data, _dataLen);

        piml->frame->data[0] = piml->data;

        return 0;
    }

    int EyerAVFrame::SetPTS(uint64_t pts)
    {
        piml->frame->pts = pts;
        return 0;
    }
}

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
        av_frame_free(&piml->frame);
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }
}
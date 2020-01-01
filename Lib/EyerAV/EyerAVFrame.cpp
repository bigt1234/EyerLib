#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

#include "EyerAVEncoderPrivate.hpp"
#include "EyerAVFramePrivate.hpp"

namespace Eyer {
    EyerAVFrame::EyerAVFrame() {
        piml = new EyerAVFramePrivate();
        piml->frame = av_frame_alloc();
    }

    EyerAVFrame::~EyerAVFrame() {
        av_frame_unref(piml->frame);
        av_frame_free(&piml->frame);
        if (piml != nullptr) {
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVFrame::GetInfo()
    {
        if(piml->frame->format == AV_SAMPLE_FMT_FLTP){
            printf("AV_SAMPLE_FMT_FLTP\n");
        }
        else{
            printf("NOT AV_SAMPLE_FMT_FLTP\n");
        }

        printf("Linesize 0:%d\n", piml->frame->linesize[0]);
        printf("Linesize 1:%d\n", piml->frame->linesize[1]);

        return 0;
    }


    // avcodec_fill_audio_frame(piml->frame, 2, AV_SAMPLE_FMT_FLTP, (const uint8_t *) arr, size, 1);
}

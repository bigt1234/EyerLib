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

    int EyerAVFrame::GetLineSize(int channel)
    {
        return piml->frame->linesize[channel];
    }

    int EyerAVFrame::GetWidth()
    {
        return piml->frame->width;
    }

    int EyerAVFrame::GetHeight()
    {
        return piml->frame->height;
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
        printf("Channels:%d\n", piml->frame->channels);
        printf("nb_samples:%d\n", piml->frame->nb_samples);
        printf("nb_samples:%lld\n", piml->frame->channel_layout);

        return 0;
    }


    int EyerAVFrame::SetAudioFLTPData(unsigned char * _channelData0, int _channelDataLen0, unsigned char * _channelData1, int _channelDataLen1)
    {
        int size = 8192;
        unsigned char * channelData0 = (unsigned char *)malloc(_channelDataLen0);
        memcpy(channelData0, _channelData0, _channelDataLen0);

        unsigned char * channelData1 = (unsigned char *)malloc(_channelDataLen1);
        memcpy(channelData1, _channelData1, _channelDataLen1);

        unsigned char * channelData = (unsigned char *)malloc(size);
        /*
        piml->frame->linesize[0] = size;
        piml->frame->format = AV_SAMPLE_FMT_FLTP;

        piml->frame->data[0] = channelData0;
        piml->frame->data[1] = channelData1;

        piml->frame->channels = 2;

        piml->frame->nb_samples = 1024;
         */

        avcodec_fill_audio_frame(piml->frame, 2, AV_SAMPLE_FMT_FLTP, (const uint8_t *) arr, size, 1);

        return 0;
    }
    // avcodec_fill_audio_frame(piml->frame, 2, AV_SAMPLE_FMT_FLTP, (const uint8_t *) arr, size, 1);
}

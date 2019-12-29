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
        av_frame_unref(piml->frame);
        av_frame_free(&piml->frame);
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVFrame::GetLineSize(int dataChannel)
    {
        return piml->frame->linesize[dataChannel];
    }

    int EyerAVFrame::SetPTS(uint64_t pts)
    {
        piml->frame->pts = pts;
        return 0;
    }

    uint64_t EyerAVFrame::GetPTS()
    {
        return piml->frame->pts;
    }

    int EyerAVFrame::SetData(EyerAVEncoder * encoder, unsigned char * data, int dataLen)
    {
        if(encoder->GetBufferSize() != dataLen){
            return -1;
        }

        piml->frame->data[0] = (uint8_t *)data;
        piml->frame->linesize[0] = dataLen;

        piml->frame->nb_samples = encoder->GetFrameSize();
        piml->frame->format = AV_SAMPLE_FMT_FLTP;

        avcodec_fill_audio_frame(piml->frame, encoder->GetChannelNum(), AV_SAMPLE_FMT_FLTP, (const uint8_t *) data, dataLen, 1);

        piml->frame->data[0] = (uint8_t *)data;
        piml->frame->linesize[0] = dataLen;

        return 0;
    }

    int EyerAVFrame::SetZero(EyerAVEncoder * encoder)
    {
        // printf("GetBufferSize:%d\n", encoder->GetBufferSize());
        int size = encoder->GetBufferSize();

        float * data = (float *)malloc(size);
        for(int i=0;i<size / 4 / 2;i++) {
            float a = sinf(i * 0.001f) * 1.0f;
            data[i * 2 + 0] = a;
            data[i * 2 + 1] = a;
        }

        memset(data, 0, size);

        int ret = SetData(encoder, (unsigned char *)data, size);

        return ret;
    }

    int EyerAVFrame::Debug()
    {
        int size = 8192;

        float * arr = (float *)malloc(size);

        for(int i=0;i<size/4;i++){
            arr[i] = sin(i * 0.01) * 128.0f;
        }

        piml->frame->data[0] = (uint8_t *)arr;
        piml->frame->linesize[0] = size;

        piml->frame->nb_samples = 1024;
        piml->frame->format = AV_SAMPLE_FMT_FLTP;

        avcodec_fill_audio_frame(piml->frame, 2, AV_SAMPLE_FMT_FLTP, (const uint8_t *) arr, size, 1);

        // piml->frame->data[0] = (uint8_t *)arr;
        // piml->frame->linesize[0] = size;

        free(arr);

        return 0;
    }
}

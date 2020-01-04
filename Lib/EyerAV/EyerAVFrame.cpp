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

        for(int i=0;i<dataManager.size();i++){
            free(dataManager[i]);
        }
        dataManager.clear();
    }

    int EyerAVFrame::SetPTS(int64_t pts)
    {
        piml->frame->pts = pts;
        return 0;
    }

    int EyerAVFrame::GetLineSize(int channel) {
        return piml->frame->linesize[channel];
    }

    int EyerAVFrame::GetWidth() {
        return piml->frame->width;
    }

    int EyerAVFrame::GetHeight() {
        return piml->frame->height;
    }

    int EyerAVFrame::GetInfo() {
        if (piml->frame->format == AV_SAMPLE_FMT_FLTP) {
            printf("AV_SAMPLE_FMT_FLTP\n");
        } else {
            printf("NOT AV_SAMPLE_FMT_FLTP\n");
        }

        printf("Linesize 0:%d\n", piml->frame->linesize[0]);
        printf("Linesize 1:%d\n", piml->frame->linesize[1]);
        printf("Channels:%d\n", piml->frame->channels);
        printf("nb_samples:%d\n", piml->frame->nb_samples);
        printf("nb_samples:%lld\n", piml->frame->channel_layout);

        return 0;
    }

    int EyerAVFrame::GetAudioData(unsigned char * data)
    {
        memcpy(data, piml->frame->data[0], 8192 / 2);
        memcpy(data + 8192 / 2, piml->frame->data[1], 8192 / 2);
        return 0;
    }

    int EyerAVFrame::SetAudioData(unsigned char * _data, int _dataLen, int nbSamples, int channel, EyerAVFormat _format)
    {
        if(_format == EyerAVFormat::EYER_AV_SAMPLE_FMT_FLTP){
            // float, planar
            unsigned char * data = (unsigned char *)malloc(_dataLen);
            dataManager.push_back(data);

            memcpy(data, _data, _dataLen);

            piml->frame->format = AV_SAMPLE_FMT_FLTP;
            piml->frame->channels = channel;
            piml->frame->nb_samples = nbSamples;
            int ret = avcodec_fill_audio_frame(piml->frame, channel, AV_SAMPLE_FMT_FLTP, (const uint8_t *) data, _dataLen, 0);
            // printf("avcodec_fill_audio_frame ret:%d\n", ret);

            /*
            printf("====================================================\n");
            printf("Linesize 0:%d\n", piml->frame->linesize[0]);
            printf("Linesize 1:%d\n", piml->frame->linesize[1]);
            printf("Channels:%d\n", piml->frame->channels);
            printf("nb_samples:%d\n", piml->frame->nb_samples);
            printf("channel_layout:%lld\n", piml->frame->channel_layout);
            printf("format:%lld\n", piml->frame->format);
            */

            return 0;
        }
        return -1;
    }

    int EyerAVFrame::SetAudioFLTPData(unsigned char * _channelData0, int _channelDataLen0, unsigned char * _channelData1, int _channelDataLen1)
    {
        int size = 8192;
        unsigned char * channelData0 = (unsigned char *)malloc(_channelDataLen0);
        memcpy(channelData0, _channelData0, _channelDataLen0);

        unsigned char * channelData1 = (unsigned char *)malloc(_channelDataLen1);
        memcpy(channelData1, _channelData1, _channelDataLen1);

        unsigned char * channelData = (unsigned char *)malloc(size);
        memcpy(channelData, channelData0, size / 2);
        memcpy(channelData + size / 2, channelData1, size / 2);


        piml->frame->format = AV_SAMPLE_FMT_FLTP;
        piml->frame->channels = 2;
        piml->frame->nb_samples = 1024;

        printf("====================================================\n");
        printf("Linesize 0:%d\n", piml->frame->linesize[0]);
        printf("Linesize 1:%d\n", piml->frame->linesize[1]);
        printf("Channels:%d\n", piml->frame->channels);
        printf("nb_samples:%d\n", piml->frame->nb_samples);
        printf("nb_samples:%lld\n", piml->frame->channel_layout);
        printf("format:%lld\n", piml->frame->format);

        printf("---------------\n");
        avcodec_fill_audio_frame(piml->frame, 2, AV_SAMPLE_FMT_FLTP, (const uint8_t *) channelData, size, 0);

        printf("Linesize 0:%d\n", piml->frame->linesize[0]);
        printf("Linesize 1:%d\n", piml->frame->linesize[1]);
        printf("Channels:%d\n", piml->frame->channels);
        printf("nb_samples:%d\n", piml->frame->nb_samples);
        printf("channel_layout:%lld\n", piml->frame->channel_layout);
        printf("format:%lld\n", piml->frame->format);

        return 0;
    }
    // avcodec_fill_audio_frame(piml->frame, 2, AV_SAMPLE_FMT_FLTP, (const uint8_t *) arr, size, 1);
}

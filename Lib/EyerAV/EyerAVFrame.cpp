#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
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

    EyerAVFrame::EyerAVFrame(const EyerAVFrame & frame)
    {
        piml = new EyerAVFramePrivate();
        piml->frame = av_frame_alloc();
        *this = frame;
    }
    EyerAVFrame & EyerAVFrame::operator = (const EyerAVFrame & frame)
    {
        /*
        av_frame_copy_props(piml->frame, frame.piml->frame);
        av_frame_copy(piml->frame, frame.piml->frame);
        piml->frame->width = frame.piml->frame->width;
        piml->frame->height = frame.piml->frame->height;
        */

        // Copy data
        // YUV 420 Data
        {
            unsigned char * data0 = (unsigned char *)malloc(frame.piml->frame->width *frame.piml->frame->height);
            memcpy(data0, frame.piml->frame->data[0], frame.piml->frame->width *frame.piml->frame->height);
            piml->frame->data[0] = data0;
            dataManager.push_back(data0);
        }
        {
            int dataLen = frame.piml->frame->width / 2 * frame.piml->frame->height / 2;
            unsigned char * data1 = (unsigned char *)malloc(dataLen);
            memcpy(data1, frame.piml->frame->data[1], dataLen);
            piml->frame->data[1] = data1;
            dataManager.push_back(data1);
        }
        {
            int dataLen = frame.piml->frame->width / 2 * frame.piml->frame->height / 2;
            unsigned char * data2 = (unsigned char *)malloc(dataLen);
            memcpy(data2, frame.piml->frame->data[2], dataLen);
            piml->frame->data[2] = data2;
            dataManager.push_back(data2);
        }




        // Copy linesize
        for(int i=0;i<AV_NUM_DATA_POINTERS;i++){
            piml->frame->linesize[i] = frame.piml->frame->linesize[i];
        }

        // Copy extended_data

        // Copy width ,height
        piml->frame->width = frame.piml->frame->width;
        piml->frame->height = frame.piml->frame->height;

        piml->frame->nb_samples = frame.piml->frame->nb_samples;

        piml->frame->format = frame.piml->frame->format;

        piml->frame->key_frame = frame.piml->frame->key_frame;

        piml->frame->pict_type = frame.piml->frame->pict_type;

        piml->frame->sample_aspect_ratio = frame.piml->frame->sample_aspect_ratio;

        piml->frame->pts = frame.piml->frame->pts;

        piml->frame->pkt_dts = frame.piml->frame->pkt_dts;

        piml->frame->coded_picture_number = frame.piml->frame->coded_picture_number;

        piml->frame->display_picture_number = frame.piml->frame->display_picture_number;

        piml->frame->quality = frame.piml->frame->quality;


        return *this;
    }

    int EyerAVFrame::GetYData(unsigned char * yData)
    {
        memcpy(yData, piml->frame->data[0], piml->frame->width * piml->frame->height);
        return 0;
    }

    int EyerAVFrame::GetUData(unsigned char * uData)
    {
        memcpy(uData, piml->frame->data[1], piml->frame->width / 2 * piml->frame->height / 2);
        return 0;
    }

    int EyerAVFrame::GetVData(unsigned char * vData)
    {
        memcpy(vData, piml->frame->data[2], piml->frame->width / 2 * piml->frame->height / 2);
        return 0;
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

    int64_t EyerAVFrame::GetPTS()
    {
        return piml->frame->pts;
    }

    int EyerAVFrame::GetInfo() {
        if (piml->frame->format == AV_SAMPLE_FMT_FLTP) {
            // printf("AV_SAMPLE_FMT_FLTP\n");
        } else {
            // printf("NOT AV_SAMPLE_FMT_FLTP\n");
        }

        for(int i=0;i<AV_NUM_DATA_POINTERS;i++) {
            printf("Linesize %d: %d\n", i, piml->frame->linesize[i]);
        }

        printf("Width:%d\n", piml->frame->width);
        printf("Height:%d\n", piml->frame->height);
        printf("Channels:%d\n", piml->frame->channels);
        printf("nb_samples:%d\n", piml->frame->nb_samples);
        printf("nb_samples:%lld\n", piml->frame->channel_layout);

        return 0;
    }

    int EyerAVFrame::SetVideoData420P(unsigned char * _y, unsigned char * _u, unsigned char * _v, int _width, int _height)
    {
        unsigned char * y = (unsigned char *)malloc(_width * _height);
        memcpy(y, _y, _width * _height);

        unsigned char * u = (unsigned char *)malloc(_width * _height / 4);
        memcpy(u, _u, _width * _height / 4);

        unsigned char * v = (unsigned char *)malloc(_width * _height / 4);
        memcpy(v, _v, _width * _height / 4);

        dataManager.push_back(y);
        dataManager.push_back(u);
        dataManager.push_back(v);

        piml->frame->format = AV_PIX_FMT_YUV420P;
        piml->frame->width = _width;
        piml->frame->height = _height;

        piml->frame->linesize[0] = _width;
        piml->frame->linesize[1] = _width / 2;
        piml->frame->linesize[2] = _width / 2;

        piml->frame->data[0] = y;
        piml->frame->data[1] = u;
        piml->frame->data[2] = v;

        /*
        int ret = av_image_alloc(piml->frame->data, piml->frame->linesize, _width, _height, AV_PIX_FMT_YUV420P, 16);

        EyerLog("=====================================\n");
        EyerLog("linesize[0]:%d\n", piml->frame->linesize[0]);
        EyerLog("linesize[1]:%d\n", piml->frame->linesize[1]);
        EyerLog("linesize[2]:%d\n", piml->frame->linesize[2]);

        memcpy(piml->frame->data[0], _y, _width * _height);
        memcpy(piml->frame->data[1], _u, _width * _height / 4);
        memcpy(piml->frame->data[2], _v, _width * _height / 4);
        */

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
}

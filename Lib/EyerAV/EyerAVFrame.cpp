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

        std::map<int, unsigned char *>::iterator it;
        for(it=piml->dataCache.begin();it!=piml->dataCache.end();++it){
            free(it->second);
            it->second = nullptr;
        }
        piml->dataCache.clear();

        av_frame_unref(piml->frame);
        av_frame_free(&piml->frame);
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVFrame::SetData(unsigned char * _data, int _dataLen, int dataChannel)
    {
        unsigned char * data = (unsigned char *)malloc(_dataLen);
        memcpy(data, _data, _dataLen);

        std::map<int, unsigned char *>::iterator it = piml->dataCache.find(dataChannel);
        if (it != piml->dataCache.end()) {
            // Find it
            if(it->second != nullptr){
                free(it->second);
                it->second = nullptr;
            }

            it->second = data;

            piml->frame->data[dataChannel] = data;
            piml->frame->linesize[dataChannel] = _dataLen;
        }
        else{
            piml->dataCache.insert(std::pair<int, unsigned char *>(dataChannel, data));
            piml->frame->data[dataChannel] = data;
            piml->frame->linesize[dataChannel] = _dataLen;
        };

        return 0;
    }

    int EyerAVFrame::SetZeroData(int dataLen, int dataChannel)
    {
        unsigned char * data = (unsigned char *)malloc(dataLen);
        memset(data, 0, dataLen);

        int ret = SetData(data, dataLen, 0);

        free(data);
        return ret;
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
}

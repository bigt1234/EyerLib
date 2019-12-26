#include "EyerAV.hpp"

#include "EyerAVStreamPrivate.hpp"

namespace Eyer
{
    EyerEyeStream::EyerEyeStream()
    {
        piml = new EyerAVStreamPrivate();
        piml->codecContext = avcodec_alloc_context3(nullptr);
    }
    
    EyerEyeStream::~EyerEyeStream()
    {
        if(piml->codecContext != nullptr){
            avcodec_free_context(&piml->codecContext);
            piml->codecContext = nullptr;
        }
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    EyerEyeStreamType EyerEyeStream::GetStreamType()
    {
        if(piml->codecContext->codec_type == AVMediaType::AVMEDIA_TYPE_VIDEO){
            return EyerEyeStreamType::STREAM_TYPE_VIDEO;
        }
        if(piml->codecContext->codec_type == AVMediaType::AVMEDIA_TYPE_AUDIO){
            return EyerEyeStreamType::STREAM_TYPE_AUDIO;
        }

        return EyerEyeStreamType::STREAM_TYPE_AUDIO;
    }
}

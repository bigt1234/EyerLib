#include "EyerAV.hpp"

#include "EyerAVStreamPrivate.hpp"
#include "EyerAVDecoderPrivate.hpp"
#include "EyerAVPacketPrivate.hpp"
#include "EyerAVFramePrivate.hpp"
#include "EyerAVEncoderPrivate.hpp"

namespace Eyer
{
    EyerAVEncoder::EyerAVEncoder()
    {
        piml = new EyerAVEncoderPrivate();
        // piml->codecContext = avcodec_alloc_context3(nullptr);
    }

    EyerAVEncoder::~EyerAVEncoder()
    {
        if(piml->codecContext != nullptr){
            if(avcodec_is_open(piml->codecContext)){
                avcodec_close(piml->codecContext);
            }
            avcodec_free_context(&piml->codecContext);
            piml->codecContext = nullptr;
        }
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVEncoder::Init(EyerEyeStream * stream)
    {
        AVCodec * codec = nullptr;

        EyerEyeStreamType streamType = stream->GetStreamType();
        if(streamType == EyerEyeStreamType::STREAM_TYPE_UNKNOW){
        }
        if(streamType == EyerEyeStreamType::STREAM_TYPE_AUDIO){
            // 初始化 AAC 编码器
            codec = avcodec_find_encoder(AV_CODEC_ID_AAC);

            if(piml->codecContext != nullptr){
                if(avcodec_is_open(piml->codecContext)){
                    avcodec_close(piml->codecContext);
                }
                avcodec_free_context(&piml->codecContext);
                piml->codecContext = nullptr;
            }

            piml->codecContext = avcodec_alloc_context3(codec);

            avcodec_copy_context(piml->codecContext, stream->piml->codecContext);
        }
        if(streamType == EyerEyeStreamType::STREAM_TYPE_VIDEO){
            // 初始化 H264 编码器
            codec = avcodec_find_encoder(AV_CODEC_ID_H264);

            if(piml->codecContext != nullptr){
                if(avcodec_is_open(piml->codecContext)){
                    avcodec_close(piml->codecContext);
                }
                avcodec_free_context(&piml->codecContext);
                piml->codecContext = nullptr;
            }

            piml->codecContext = avcodec_alloc_context3(codec);

            avcodec_copy_context(piml->codecContext, stream->piml->codecContext);
            /*
            piml->codecContext->time_base.den = 90000;
            piml->codecContext->time_base.num = 1;

            piml->codecContext->pix_fmt = AV_PIX_FMT_YUV420P;
            piml->codecContext->width = stream->piml->codecContext->width;
            piml->codecContext->height = stream->piml->codecContext->height;
            */

            piml->codecContext->me_range = 16;
            piml->codecContext->max_qdiff = 4;
            piml->codecContext->qmin = 10;
            piml->codecContext->qmax = 51;
            piml->codecContext->qcompress = 0.8;
            piml->codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
        }

        if(codec == nullptr){
            return -1;
        }
        if(piml->codecContext == nullptr){
            return -1;
        }

        int ret = avcodec_open2(piml->codecContext, codec, nullptr);
        if(ret){
            RedLog("Open Decoder Fail\n");
            return -1;
        }
        
        return 0;
    }

    int EyerAVEncoder::SendFrame(EyerAVFrame * frame)
    {
        if(piml->codecContext == nullptr){
            return -1;
        }

        AVFrame * f = NULL;
        if(frame != nullptr){
            f = frame->piml->frame;
        }
        int ret = avcodec_send_frame(piml->codecContext, f);
        return ret;
    }

    int EyerAVEncoder::RecvPacket(EyerAVPacket * packet)
    {
        if(piml->codecContext == nullptr){
            return -1;
        }

        int ret = avcodec_receive_packet(piml->codecContext, packet->piml->packet);
        return ret;
    }

    int EyerAVEncoder::Flush()
    {
        avcodec_flush_buffers(piml->codecContext);
        return 0;
    }
}

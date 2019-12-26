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
        piml->codecContext = avcodec_alloc_context3(nullptr);
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
        avcodec_copy_context(piml->codecContext, stream->piml->codecContext);
        AVCodec * codec = avcodec_find_encoder(piml->codecContext->codec_id);

        // piml->codecContext = avcodec_alloc_context3(codec);

        if(piml->codecContext->codec_id == AV_CODEC_ID_H264){
            piml->codecContext->me_range = 16;
            piml->codecContext->max_qdiff = 4;
            piml->codecContext->qmin = 10;
            piml->codecContext->qmax = 51;
            piml->codecContext->qcompress = 0.8;
            piml->codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
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
        int ret = avcodec_send_frame(piml->codecContext, frame->piml->frame);
        return ret;
    }

    int EyerAVEncoder::RecvPacket(EyerAVPacket * packet)
    {
        int ret = avcodec_receive_packet(piml->codecContext, packet->piml->packet);
        return ret;
    }
}
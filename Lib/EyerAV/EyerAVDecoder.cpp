#include "EyerAV.hpp"

#include "EyerAVStreamPrivate.hpp"
#include "EyerAVDecoderPrivate.hpp"
#include "EyerAVPacketPrivate.hpp"
#include "EyerAVFramePrivate.hpp"

namespace Eyer
{
    EyerAVDecoder::EyerAVDecoder()
    {
        piml = new EyerAVDecoderPrivate();
        piml->codecContext = avcodec_alloc_context3(nullptr);
    }

    EyerAVDecoder::~EyerAVDecoder()
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

    int EyerAVDecoder::Init(EyerEyeStream * stream)
    {
        avcodec_copy_context(piml->codecContext, stream->piml->codecContext);

        AVCodec * codec = avcodec_find_decoder(piml->codecContext->codec_id);

        int ret = avcodec_open2(piml->codecContext, codec, nullptr);
        if(ret){
            RedLog("Open Decoder Fail\n");
            return -1;
        }
        return 0;
    }

    int EyerAVDecoder::SendPacket(EyerAVPacket * packet)
    {
        // TODO 判断解码器是否打开
        int ret = avcodec_send_packet(piml->codecContext, packet->piml->packet);
        return ret;
    }

    int EyerAVDecoder::RecvFrame(EyerAVFrame * frame)
    {
        // TODO 判断解码器是否打开
        int ret = avcodec_receive_frame(piml->codecContext, frame->piml->frame);
        return ret;
    }
}
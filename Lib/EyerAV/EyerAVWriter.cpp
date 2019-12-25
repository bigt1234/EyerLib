#include "EyerAV.hpp"

#include "EyerAVStreamPrivate.hpp"
#include "EyerAVDecoderPrivate.hpp"
#include "EyerAVPacketPrivate.hpp"
#include "EyerAVFramePrivate.hpp"
#include "EyerAVEncoderPrivate.hpp"
#include "EyerAVWriterPrivate.hpp"

namespace Eyer
{
    EyerAVWriter::EyerAVWriter(RedString _path)
    {
        piml = new EyerAVWriterPrivate();
        piml->path = _path;
        av_register_all();
        avformat_network_init();

        avformat_alloc_output_context2(&piml->formatCtx, NULL, NULL, piml->path.str);
    }

    EyerAVWriter::~EyerAVWriter()
    {
        if(piml->formatCtx != NULL){
            // Close();
            avformat_free_context(piml->formatCtx);
            piml->formatCtx = NULL;
        }

        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVWriter::Open()
    {
        int ret = avio_open(&piml->formatCtx->pb, piml->path.str, AVIO_FLAG_WRITE);
        if(ret){
            return -1;
        }

        avformat_write_header(piml->formatCtx, nullptr);

        return 0;
    }

    int EyerAVWriter::Close()
    {
        av_write_trailer(piml->formatCtx);
        avio_close(piml->formatCtx->pb);
        return 0;
    }

    int EyerAVWriter::AddStream(EyerEyeStream * stream, EyerAVEncoder * encoder)
    {
        AVStream * avStream = avformat_new_stream(piml->formatCtx, stream->piml->codecContext->codec);

        avcodec_copy_context(avStream->codec, stream->piml->codecContext);

        avStream->codec->codec_tag = 0;

        avcodec_copy_context(avStream->codec, encoder->piml->codecContext);

        avStream->codec->codec_tag = 0;
        encoder->piml->codecContext->codec_tag = 0;
        
        return avStream->id;
    }

    int EyerAVWriter::WritePacket(EyerAVPacket * packet)
    {
        int ret = av_interleaved_write_frame(piml->formatCtx, packet->piml->packet);
        return ret;
    }

    int EyerAVWriter::WriteHand()
    {
        return 0;
    }
}
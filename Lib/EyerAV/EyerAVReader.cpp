#include "EyerAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

#include "EyerAVReaderPrivate.hpp"
#include "EyerAVPacketPrivate.hpp"
#include "EyerAVStreamPrivate.hpp"

namespace Eyer
{
    EyerAVReader::EyerAVReader(RedString _path)
    {
        piml = new EyerAVReaderPrivate();
        piml->path = _path;

        av_register_all();
        avformat_network_init();

        piml->formatCtx = avformat_alloc_context();
    }

    EyerAVReader::~EyerAVReader()
    {
        if(piml->formatCtx != NULL){
            Close();
            avformat_free_context(piml->formatCtx);
            piml->formatCtx = NULL;
        }

        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    int EyerAVReader::Open()
    {
        int ret = avformat_open_input(&piml->formatCtx, piml->path.str, NULL, NULL);
        if(ret){
            return -1;
        }

        avformat_find_stream_info(piml->formatCtx, NULL);

        return 0;
    }

    int EyerAVReader::Close()
    {
        avformat_close_input(&piml->formatCtx);
        return 0;
    }

    int EyerAVReader::Read(EyerAVPacket * packet)
    {
        int ret = av_read_frame(piml->formatCtx, packet->piml->packet);
        return ret;
    }

    int EyerAVReader::GetStreamCount()
    {
        if(piml->formatCtx == nullptr){
            return -1;
        }

        // TODO 判断文件是否打开成功

        return piml->formatCtx->nb_streams;
    }

    int EyerAVReader::GetStream(EyerEyeStream & stream, int index)
    {
        if(piml->formatCtx == nullptr){
            return -1;
        }

        // TODO 判断文件是否打开成功
        if(index < 0){
            return -1;
        }
        if(index >= GetStreamCount()){
            return -1;
        }

        stream.streamIndex = piml->formatCtx->streams[index]->index;
        
        avcodec_copy_context(stream.piml->codecContext, piml->formatCtx->streams[index]->codec);

        return 0;
    }
}
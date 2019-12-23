#ifndef	EYER_LIB_AV_H
#define	EYER_LIB_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerAVPacket;
    class EyerAVReader;
    class EyerAVDecoder;
    class EyerEyeStream;

    class EyerAVPacketPrivate;
    class EyerAVReaderPrivate;
    class EyerAVDecoderPrivate;
    class EyerAVStreamPrivate;
    class EyerAVFramePrivate;

    class EyerAVPacket
    {
    public:
        EyerAVPacketPrivate * piml = nullptr;
    public:
        EyerAVPacket();
        ~EyerAVPacket();

        int GetStreamId();
        uint64_t GetPTS();
        uint64_t GetDTS();
    };

    class EyerAVFrame
    {
    public:
        EyerAVFramePrivate * piml = nullptr;
    public:
        EyerAVFrame();
        ~EyerAVFrame();
    };

    class EyerAVReader
    {
    public:
        EyerAVReaderPrivate * piml = nullptr;
    public:
        EyerAVReader(RedString _path);
        ~EyerAVReader();

        int Open();
        int Close();

        int Read(EyerAVPacket * packet);

        int GetStreamCount();
        int GetStream(EyerEyeStream & stream, int index);
    };

    class EyerEyeStream
    {
    public:
        int streamIndex = -1;
        EyerAVStreamPrivate * piml = nullptr;
    public:
        EyerEyeStream();
        ~EyerEyeStream();
    };

    class EyerAVDecoder
    {
    public:
        EyerAVDecoderPrivate * piml = nullptr;
    public:
        EyerAVDecoder();
        ~EyerAVDecoder();

        int Init(EyerEyeStream * stream);

        int SendPacket(EyerAVPacket * packet);
        int RecvFrame(EyerAVFrame * frame);
    };
}

#endif
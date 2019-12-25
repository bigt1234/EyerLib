#ifndef	EYER_LIB_AV_H
#define	EYER_LIB_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerAVPacket;
    class EyerAVReader;
    class EyerAVDecoder;
    class EyerEyeStream;
    class EyerAVEncoder;

    class EyerAVPacketPrivate;
    class EyerAVReaderPrivate;
    class EyerAVDecoderPrivate;
    class EyerAVStreamPrivate;
    class EyerAVFramePrivate;
    class EyerAVEncoderPrivate;
    class EyerAVWriterPrivate;

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

        int SetPTS(uint64_t pts);
        int SetDTS(uint64_t dts);

        int SetStreamId(int id);
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

    class EyerAVWriter
    {
    public:
        EyerAVWriterPrivate * piml = nullptr;
    public:
        EyerAVWriter(RedString _path);
        ~EyerAVWriter();

        int Open();
        int Close();

        int AddStream(EyerEyeStream * stream, EyerAVEncoder * encoder);

        int WriteHand();
        int WritePacket(EyerAVPacket * packet);
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


    class EyerAVEncoder
    {
    public:
        EyerAVEncoderPrivate * piml = nullptr;
    public:
        EyerAVEncoder();
        ~EyerAVEncoder();

        int Init(EyerEyeStream * stream);

        int SendFrame(EyerAVFrame * frame);
        int RecvPacket(EyerAVPacket * packet);
    };
}

#endif
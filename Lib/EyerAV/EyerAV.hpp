#ifndef	EYER_LIB_AV_H
#define	EYER_LIB_AV_H

#include "EyerCore/EyerCore.hpp"
#include <vector>

namespace Eyer
{
    class EyerAVPacket;
    class EyerAVReader;
    class EyerAVDecoder;
    class EyerAVStream;
    class EyerAVEncoder;

    class EyerAVPacketPrivate;
    class EyerAVReaderPrivate;
    class EyerAVDecoderPrivate;
    class EyerAVStreamPrivate;
    class EyerAVFramePrivate;
    class EyerAVEncoderPrivate;
    class EyerAVWriterPrivate;

    enum EyerAVStreamType{
        STREAM_TYPE_UNKNOW = 0,
        STREAM_TYPE_AUDIO = 1,
        STREAM_TYPE_VIDEO = 2
    };

    enum EyerAVFormat
    {
        EYER_AV_SAMPLE_FMT_FLTP = 1
    };

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

        std::vector<void *> dataManager;
    public:
        EyerAVFrame();
        ~EyerAVFrame();

        int SetAudioData(unsigned char * data, int dataLen, int nbSamples, int channel, EyerAVFormat format);

        int GetLineSize(int channel);

        int SetAudioFLTPData(unsigned char * channelData0, int channelDataLen0, unsigned char * channelData1, int channelDataLen1);

        int GetWidth();
        int GetHeight();

        int GetInfo();
    };

    class EyerAVReader
    {
    public:
        EyerAVReaderPrivate * piml = nullptr;
    public:
        EyerAVReader(EyerString _path);
        ~EyerAVReader();

        int Open();
        int Close();

        int Read(EyerAVPacket * packet);

        int GetStreamCount();
        int GetStream(EyerAVStream & stream, int index);
    };

    class EyerAVWriter
    {
    public:
        EyerAVWriterPrivate * piml = nullptr;
    public:
        EyerAVWriter(EyerString _path);
        ~EyerAVWriter();

        int Open();
        int Close();

        int AddStream(EyerAVEncoder * encoder);

        int GetStreamTimeBaseDen(int streamIndex);
        int GetStreamTimeBaseNum(int streamIndex);

        int WriteHand();
        int WritePacket(EyerAVPacket * packet);
    };

    class EyerAVStream
    {
    public:
        int streamIndex = -1;
        EyerAVStreamPrivate * piml = nullptr;

        double duration = 0;
    public:
        EyerAVStream();
        ~EyerAVStream();

        EyerAVStreamType GetStreamType();

        int SetDuration(double _duration);
        double GetDuration();
    };

    class EyerAVDecoder
    {
    public:
        EyerAVDecoderPrivate * piml = nullptr;
    public:
        EyerAVDecoder();
        ~EyerAVDecoder();

        int Init(EyerAVStream * stream);

        int SendPacket(EyerAVPacket * packet);
        int RecvFrame(EyerAVFrame * frame);
    };

    enum CodecId
    {
        CODEC_ID_UNKNOW = 0,
        CODEC_ID_H264 = 1,
        CODEC_ID_AAC = 2
    };

    class EncoderParam
    {
    public:
        CodecId codecId = CodecId::CODEC_ID_UNKNOW;
        int width = 0;
        int height = 0;
    };

    class EyerAVEncoder
    {
    public:
        EyerAVEncoderPrivate * piml = nullptr;
    public:
        EyerAVEncoder();
        ~EyerAVEncoder();

        int Init(EyerAVStream * stream);
        int Init(EncoderParam * param);

        int Flush();

        int GetBufferSize();
        int GetFrameSize();
        int GetChannelNum();

        int SendFrame(EyerAVFrame * frame);
        int RecvPacket(EyerAVPacket * packet);
    };
}

#endif

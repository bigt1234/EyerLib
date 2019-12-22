#ifndef	EYER_LIB_AV_H
#define	EYER_LIB_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerAVPacket;
    class EyerAVReader;

    class EyerAVPacketPrivate;
    class EyerAVReaderPrivate;

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
    };
}

#endif
#ifndef	EYER_LIB_AV_H
#define	EYER_LIB_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerAVPacket;
    class EyerAVReader;

    class EyerAVPacket
    {
        void * packet = nullptr;
    public:
        EyerAVPacket();
        ~EyerAVPacket();
    };

    class EyerAVReader
    {
    private:
        RedString path;
        void * formatCtx = nullptr;
    public:
        EyerAVReader(RedString _path);
        ~EyerAVReader();

        int Open();
        int Close();

        int Read(EyerAVPacket * packet);
    };
}

#endif
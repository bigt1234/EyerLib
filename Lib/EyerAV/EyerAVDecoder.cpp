#include "EyerAV.hpp"

#include "EyerAVDecoderPrivate.hpp"

namespace Eyer
{
    EyerAVDecoder::EyerAVDecoder()
    {
        pml = new EyerAVDecoderPrivate();
    }

    EyerAVDecoder::~EyerAVDecoder()
    {
        if(pml != nullptr){
            delete pml;
            pml = nullptr;
        }
    }

    int EyerAVDecoder::Init(EyerAVReader * reader)
    {
        return 0;
    }
}
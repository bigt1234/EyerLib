#include "EyerAV.hpp"

#include "EyerAVStreamPrivate.hpp"

namespace Eyer
{
    EyerEyeStream::EyerEyeStream()
    {
        piml = new EyerAVStreamPrivate();
    }
    
    EyerEyeStream::~EyerEyeStream()
    {
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }
}
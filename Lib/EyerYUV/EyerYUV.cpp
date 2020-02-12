#include "EyerYUV.hpp"

#include "libyuv.h"

namespace Eyer
{
    EyerYUV::EyerYUV()
    {

    }

    EyerYUV::~EyerYUV()
    {

    }

    int EyerYUV::RGB2YUV420(int width, int height, unsigned char * rgbData, unsigned char * y, unsigned char * u, unsigned char * v)
    {
        libyuv::RGB24ToI420(
                rgbData,
                width * 3,
                y,
                width,
                u,
                width / 2,
                v,
                width / 2,
                width,
                height
                );
        return 0;
    }
}
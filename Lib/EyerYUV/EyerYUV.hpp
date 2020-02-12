#ifndef	EYER_LIB_YUV_H
#define	EYER_LIB_YUV_H

namespace Eyer
{
    class EyerYUV
    {
    public:
        EyerYUV();
        ~EyerYUV();

        int RGB2YUV420(int width, int height, unsigned char * rgbData, unsigned char * yuvData);
    };
}

#endif
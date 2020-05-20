#ifndef	EYER_LIB_IMG_H
#define	EYER_LIB_IMG_H

#include <stdio.h>
#include "stb_image.h"
namespace Eyer{
    class EyerImg{
    public:
        EyerImg(char * _filename);
        ~EyerImg();
        int LoadImg();

        int WriteJPG(char const *filename, int x, int y, int channel, const void *data, int quality);
        int GetImgH();
        int GetImgW();
        int GetImgChannel();
        int GetImgData(unsigned char * _imgData);

    private:
        char * filename = nullptr;
        unsigned char * imgData = nullptr;
        int imgH = 0;
        int imgW = 0;
        int imgChannel = 0;

    };
}

#endif
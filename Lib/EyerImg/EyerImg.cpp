#include "EyerImg.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

namespace Eyer {
    EyerImg::EyerImg(char * _filename)
    {
        int _strLen = strlen(_filename) + 1;
        filename = (char *)malloc(_strLen);
        memcpy(filename, _filename, _strLen);
    }

    EyerImg::~EyerImg()
    {
        stbi_image_free(imgData);
        if(filename != nullptr){
            free(filename);
            filename = nullptr;
        }
    }

    int EyerImg::LoadImg()
    {
        //如果多次load，会造成内存泄露，需要先判断imgData是否为nullptr，若为nullptr，先free
        if(imgData == nullptr){
            stbi_image_free(imgData);
        }

        imgData = stbi_load(filename, &imgW, &imgH, &imgChannel, 0);
        if(imgData == nullptr){
            return -1;
        }else{
            return 0;
        }
    }

    int EyerImg::GetImgH()
    {
        return imgH;
    }

    int EyerImg::GetImgW()
    {
        return imgW;
    }

    int EyerImg::GetImgChannel()
    {
        return imgChannel;
    }

    int EyerImg::GetImgData(unsigned char * _imgData)
    {
        memcpy(_imgData, imgData, imgH * imgW * imgChannel);
        return 0;
    }

    int EyerImg::WriteJPG(char const *filename, int x, int y, int channel, const void *data, int quality)
    {
        return stbi_write_jpg(filename, x, y, channel, data, 0);
    }
}
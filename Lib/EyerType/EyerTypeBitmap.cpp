#include "EyerType.hpp"

namespace Eyer
{
    EyerTypeBitmap::EyerTypeBitmap()
    {
        
    }

    EyerTypeBitmap::EyerTypeBitmap(int _width, int _height, unsigned char * _data, unsigned int _dataLen)
    {
        width = _width;
        height = _height;
        dataLen = _dataLen;

        data = (unsigned char *)malloc(dataLen);
        memcpy(data, _data, dataLen);
    }

    EyerTypeBitmap::EyerTypeBitmap(const EyerTypeBitmap & _bitmap)
    {
        *this = _bitmap;
    }

    EyerTypeBitmap::~EyerTypeBitmap()
    {
        if(data != nullptr){
            free(data);
            data = nullptr;
        }
    }

    EyerTypeBitmap & EyerTypeBitmap::operator = (const EyerTypeBitmap & _bitmap)
    {
        width = _bitmap.width;
        height = _bitmap.height;
        dataLen = _bitmap.dataLen;

        if(data != nullptr){
            free(data);
            data = nullptr;
        }

        data = (unsigned char *)malloc(dataLen);
        memcpy(data, _bitmap.data, dataLen);

        return *this;
    }
}
#include "EyerType.hpp"

namespace Eyer
{
    EyerTypeBitmap::EyerTypeBitmap()
    {
        
    }

    EyerTypeBitmap::EyerTypeBitmap(int _width, int _height, int _bearingX, int _bearingY, int _advance, unsigned char * _data, unsigned int _dataLen)
    {
        width = _width;
        height = _height;
        dataLen = _dataLen;
        bearingX = _bearingX;
        bearingY = _bearingY;
        advance = _advance;

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

        bearingX = _bitmap.bearingX;
        bearingY = _bitmap.bearingY;

        advance = _bitmap.advance;

        if(data != nullptr){
            free(data);
            data = nullptr;
        }

        data = (unsigned char *)malloc(dataLen);
        memcpy(data, _bitmap.data, dataLen);

        return *this;
    }
}
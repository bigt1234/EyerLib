#include "RedYuv.hpp"

RedYuv::RedYuv(unsigned char * y, int yLen, unsigned char * u, int uLen, unsigned char * v, int vLen)
{
    this->y = (unsigned char *)malloc(yLen);
    this->yLen = yLen;
    memcpy(this->y, y, yLen);

    this->u = (unsigned char *)malloc(uLen);
    this->uLen = uLen;
    memcpy(this->u, u, uLen);

    this->v = (unsigned char *)malloc(vLen);
    this->vLen = vLen;
    memcpy(this->v, v, vLen);
}

RedYuv::RedYuv(unsigned char * yuv, int yuvLen, int w, int h)
{
    this->width = w;
    this->height = h;

    this->y = (unsigned char *)malloc(w * h);
    this->yLen = w * h;
    memcpy(this->y, yuv, this->yLen);

    this->u = (unsigned char *)malloc(w * h / 4);
    this->uLen = w * h / 4;
    memcpy(this->u, yuv + this->yLen, this->uLen);

    this->v = (unsigned char *)malloc(w * h / 4);
    this->vLen = w * h / 4;
    memcpy(this->v, yuv + this->yLen + this->uLen, this->vLen);
}

RedYuv::~RedYuv()
{
    if(y != NULL){
        free(y);
        y = NULL;
    }
    if(u != NULL){
        free(u);
        u = NULL;
    }
    if(v != NULL){
        free(v);
        v = NULL;
    }
}

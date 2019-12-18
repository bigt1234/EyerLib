#ifndef	ZS_LIB_RED_YUV_H
#define	ZS_LIB_RED_YUV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class RedYuv
{
public:
    unsigned char * y = NULL;
    int yLen = 0;
    unsigned char * u = NULL;
    int uLen = 0;
    unsigned char * v = NULL;
    int vLen = 0;

    int width = 0;
    int height = 0;

    long long pts = 0;
public:
    RedYuv(unsigned char * yuv, int yuvLen, int w, int h);
    RedYuv(unsigned char * y, int yLen, unsigned char * u, int uLen, unsigned char * v, int vLen);
    ~RedYuv();
};

#endif

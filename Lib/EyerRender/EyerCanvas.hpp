#ifndef	EYER_LIB_REDNER_CANVAS_AV_H
#define	EYER_LIB_REDNER_CANVAS_AV_H

#include "EyerCore/EyerCore.hpp"
#include "EyerLine.hpp"

namespace Eyer
{
    class EyerCanvas;

    class EyerCanvas
    {
    private:
        int width = 0;
        int height = 0;

        unsigned char * pixelData = nullptr;
    public:
        EyerCanvas(int _width, int _height);
        ~EyerCanvas();

        int DrawLine(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);

        int SetBufferPix(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
        
        int SetClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        int RenderToTGA(EyerString path);
    };
}

#endif
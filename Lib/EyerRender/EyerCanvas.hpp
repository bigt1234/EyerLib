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

        int DrawLine(EyerVec2 p0, EyerVec2 p1, unsigned char r, unsigned char g, unsigned char b);
        int DrawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b);

        int DrawTriangle(EyerVec2 p0, EyerVec2 p1, EyerVec2 p2);



        int DrawLine2(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);

        int SetBufferPix(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
        
        int SetClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        int RenderToTGA(EyerString path);
    };
}

#endif
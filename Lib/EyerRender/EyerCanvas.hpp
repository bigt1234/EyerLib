#ifndef	EYER_LIB_REDNER_CANVAS_AV_H
#define	EYER_LIB_REDNER_CANVAS_AV_H

#include "EyerCore/EyerCore.hpp"
#include "EyerLine.hpp"

#include <vector>

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

        int DrawTriangle2(EyerVec2 p0, EyerVec2 p1, EyerVec2 p2, unsigned char r = 255, unsigned char g = 0, unsigned char b = 0);
        int DrawTriangle(EyerVec2 p0, EyerVec2 p1, EyerVec2 p2, unsigned char r = 255, unsigned char g = 0, unsigned char b = 0);


        int DrawLine2(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);

        int SetBufferPix(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
        
        int SetClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        int RenderToTGA(EyerString path);
    };


    class EyerObjModel
    {
    private:
        EyerString path;

        std::vector<EyerVec3> verts_;
	    std::vector<std::vector<int> > faces_;
    public:
        EyerObjModel(EyerString _path);
        ~EyerObjModel();

        int nverts();
        int nfaces();
        EyerVec3 vert(int i);
        std::vector<int> face(int idx);
    };
}

#endif
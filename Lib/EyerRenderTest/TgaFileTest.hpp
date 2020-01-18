#include <gtest/gtest.h>
#include "EyerRender/EyerRender.hpp"

TEST(TGAFile, createFile){
    Eyer::EyerTGAColor white = Eyer::EyerTGAColor(255, 255, 255, 255);
    Eyer::EyerTGAColor red   = Eyer::EyerTGAColor(255, 0,   0,   255);

    Eyer::EyerTgaImage image(100, 100, Eyer::EyerTgaImage::RGB);
	image.set(52, 41, red);
	image.flip_vertically();
	image.write_tga_file("TGAFile_CreateFileTest.tga");
}

TEST(TGAFile, Canvas){
    int width = 1920;
    int height = 1080;

    Eyer::EyerCanvas canvas(width, height);

    for(int i=0;i<1;i++) {
        int x1 = Eyer::EyerRand::Rand(width);
        int y1 = Eyer::EyerRand::Rand(height);
        int x2 = Eyer::EyerRand::Rand(width);
        int y2 = Eyer::EyerRand::Rand(height);

        unsigned char r = Eyer::EyerRand::Rand(255);
        unsigned char g = Eyer::EyerRand::Rand(255);
        unsigned char b = Eyer::EyerRand::Rand(255);

        canvas.DrawLine(x1, y1, x2, y2, r, g, b);
    }

    for(int i=0;i<1;i++) {
        int x0 = Eyer::EyerRand::Rand(width);
        int y0 = Eyer::EyerRand::Rand(height);
        Eyer::EyerVec2 p0(x0, y0);

        int x1 = Eyer::EyerRand::Rand(width);
        int y1 = Eyer::EyerRand::Rand(height);
        Eyer::EyerVec2 p1(x1, y1);

        int x2 = Eyer::EyerRand::Rand(width);
        int y2 = Eyer::EyerRand::Rand(height);
        Eyer::EyerVec2 p2(x2, y2);

        canvas.DrawTriangle(p0, p1, p2);
    }
    
    canvas.RenderToTGA("TGAFile_CanvasTest.tga");
}
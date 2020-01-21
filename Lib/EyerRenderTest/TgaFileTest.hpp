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

    for(int i=0;i<5;i++) {
        int x1 = Eyer::EyerRand::Rand(width);
        int y1 = Eyer::EyerRand::Rand(height);
        int x2 = Eyer::EyerRand::Rand(width);
        int y2 = Eyer::EyerRand::Rand(height);

        unsigned char r = Eyer::EyerRand::Rand(255);
        unsigned char g = Eyer::EyerRand::Rand(255);
        unsigned char b = Eyer::EyerRand::Rand(255);

        canvas.DrawLine(x1, y1, x2, y2, r, g, b);
    }

    for(int i=0;i<5;i++) {
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


TEST(TGAFile, ReadModel){
    int width = 800;
    int height = 800;

    Eyer::EyerCanvas canvas(width, height);

    Eyer::EyerObjModel model("african_head.obj");
    for (int i=0; i<model.nfaces(); i++) {
        std::vector<int> face = model.face(i);
        for (int j=0; j<3; j++) {
            Eyer::EyerVec3 v0 = model.vert(face[j]);
            Eyer::EyerVec3 v1 = model.vert(face[(j+1)%3]);
            int x0 = (v0.x()+1.)*width/2.;
            int y0 = (v0.y()+1.)*height/2.;
            int x1 = (v1.x()+1.)*width/2.;
            int y1 = (v1.y()+1.)*height/2.;

            canvas.DrawLine(x0, y0, x1, y1, 0, 0, 0);
        }
    }

    canvas.RenderToTGA("TGAFile_ReadObjModel.tga");
}
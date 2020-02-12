#include <stdio.h>
#include <gtest/gtest.h>

#include "EyerGL/EyerGL.hpp"
#include "EyerGL/EyerGLComponent.hpp"
#include "EyerGL/Shader.hpp"
#include "EyerType/EyerType.hpp"

/*
TEST(GLWindows, GLWindows){

    Eyer::EyerGLWindow windows("miaowu", 1280, 720);
    windows.Open();
    windows.SetBGColor(1.0, 1.0, 1.0, 1.0);

    float vertex[] = {
            1.0, 1.0, 0.0,
            1.0, -1.0, 0.0,
            -1.0, -1.0, 0.0,
            -1.0, 1.0, 0.0
    };
    float coor[] = {
            1.0, 1.0, 0.0,
            1.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0
    };
    unsigned int index[] = {
            0, 1, 2,
            0, 2, 3
    };
    Eyer::EyerGLVAO vao;
    vao.AddVBO(vertex, sizeof(vertex), 0);
    vao.AddVBO(coor, sizeof(coor), 1);
    vao.SetEBO(index, sizeof(index));

    Eyer::EyerGLDraw draw(Eyer::GL_SHADER::YUV_VIDEO_VERTEX_SHADER, Eyer::GL_SHADER::YUV_VIDEO_FRAGMENT_SHADER);
    draw.Init();
    draw.SetVAO(&vao);

    Eyer::EyerType type("/home/redknot/Manjari-Bold.otf");
    int ret = type.Init();
    int indexI = type.GenChar('q', 720);

    Eyer::EyerTypeBitmap b;
    ret = type.GetCharBitmap(indexI, &b);
    if(ret){
        EyerLog("GetCharBitmap Error\n");
    }

    Eyer::EyerGLTexture zeroTexture;
    zeroTexture.SetDataRedChannel(b.data, b.width, b.height);

    draw.PutTexture("numberTex", &zeroTexture);

    while (!windows.ShouldClose()){
        windows.Clear();

        draw.Draw();

        windows.Loop();
    }

    windows.Close();
}
 */

TEST(GLWindows, GLWindowsText){
    int width = 1280;
    int height = 720;

    Eyer::EyerGLWindow windows("miaowu", width, height);
    windows.Open();
    windows.SetBGColor(1.0, 1.0, 1.0, 1.0);

    Eyer::EyerGLFrameBuffer frameBuffer;

    Eyer::EyerGLTextDraw textDraw;
    // textDraw.SetText("abcdefghijklmnopqrstuvwxyz");
    textDraw.SetText("Redknot Miaomiao ABC GL gg");
    textDraw.SetColor(0.0, 1.0, 0.0);
    textDraw.SetSize(100);

    textDraw.SetPos(0, 0 + 100);

    frameBuffer.AddComponent(&textDraw);

    while (!windows.ShouldClose()){
        windows.Clear();

        textDraw.SetColor(1.0, 0.0, 0.0);
        textDraw.Viewport(width, height);
        frameBuffer.Draw();

        windows.Loop();
    }

    windows.Close();
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

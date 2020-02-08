#include <stdio.h>
#include <gtest/gtest.h>

#include "EyerGL/EyerGL.hpp"
#include "EyerGL/Shader.hpp"


TEST(GLWindows, GLWindows){

    Eyer::EyerGLWindow windows("miaowu", 800, 640);
    windows.Open();

    Eyer::EyerGLProgram program(Eyer::GL_SHADER::TEST_VERTEX_SHADER, Eyer::GL_SHADER::TEST_FRAGMENT_SHADER);
    program.LinkProgram();

    float vertex[] = {
            
    };
    Eyer::EyerGLVAO vao;
    vao.AddVBO(vertex, sizeof(vertex), 0);

    while (!windows.ShouldClose()){
        windows.Loop();
    }

    windows.Close();
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <stdio.h>
#include <gtest/gtest.h>

#include "EyerGL/EyerGL.hpp"

TEST(GLWindows, GLWindows){
    Eyer::EyerGLWindow windows("miaowu", 800, 640);
    windows.Open();
    while (!windows.ShouldClose()){
        windows.Loop();
    }
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
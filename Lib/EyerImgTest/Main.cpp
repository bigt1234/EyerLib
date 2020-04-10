#include <stdio.h>
#include <gtest/gtest.h>

#define STB_IMAGE_IMPLEMENTATION
#include "EyerImg/stb_image.h"
#include "EyerCore/EyerCore.hpp"

TEST(Eyer, EyerImg){
    int width, height, nrChannels;
    unsigned char * data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <stdio.h>
#include <gtest/gtest.h>
#include "EyerType/EyerType.hpp"

TEST(EyerType, EyerType){
    Eyer::EyerType type("/home/redknot/Manjari-Bold.otf");
    int ret = type.Init();
    ASSERT_EQ(ret, 0) << "Init Ret Error";

    int width = 0;
    int height = 0;
    ret = type.GenChar('1', 1000, &width, &height);
    ASSERT_EQ(ret, 0) << "GenChar Ret Error";

    EyerLog("Width: %d\n", width);
    EyerLog("Height: %d\n", height);
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
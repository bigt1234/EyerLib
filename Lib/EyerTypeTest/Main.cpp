#include <stdio.h>
#include <gtest/gtest.h>
#include "EyerType/EyerType.hpp"

TEST(EyerType, EyerType){
    Eyer::EyerType type("/home/redknot/Manjari-Bold.otf");
    int ret = type.Init();
    ASSERT_EQ(ret, 0) << "Init Ret Error";

    int index = type.GenChar('0', 200);
    ASSERT_GT(index, 0) << "GenChar Error";
    
    EyerLog("GenChar Index: %d\n", index);

    Eyer::EyerTypeBitmap bitmap;
    ret = type.GetCharBitmap(index, &bitmap);
    ASSERT_EQ(ret, 0) << "GetCharBitmap Ret Error";

    EyerLog("Width: %d\n",bitmap.width);
    EyerLog("Height: %d\n", bitmap.height);
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>

#include "EyerCore/Red.hpp"

TEST(RedString_Test,string){
    RedString a;
    RedString b("eyer test str");
    EXPECT_TRUE(a == "");
    EXPECT_FALSE(a == b);

    a = b;
    EXPECT_TRUE(a == b); // 我是你爸爸
}

TEST(RedArgs_Test, args){
    RedArg argA(0, NULL);
    EXPECT_EQ(argA.GetCount(), 0);
}

TEST(RedBtte_Test, byte){
    RedByte byte;
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
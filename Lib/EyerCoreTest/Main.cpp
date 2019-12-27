#include <gtest/gtest.h>

#include "EyerCore/EyerCore.hpp"

TEST(EyerString, string){
    Eyer::EyerString str = "miaowumiaowu";

    Eyer::EyerString strA = str;

    Eyer::EyerString strB;
    strB = str;

    Eyer::EyerString strEmptyA;
    EXPECT_TRUE(strEmptyA.IsEmpty());

    Eyer::EyerString strEmptyB;
    EXPECT_TRUE(strEmptyB.IsEmpty());

    EXPECT_TRUE(strEmptyA == strEmptyB);

    strEmptyA = str;
    EXPECT_FALSE(strEmptyA == strEmptyB);

    strEmptyB = str;
    EXPECT_TRUE(strEmptyA == strEmptyB);
}

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

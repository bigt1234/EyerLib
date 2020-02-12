#include <gtest/gtest.h>

#include "EyerCore/EyerCore.hpp"

#include "MathTest.hpp"

TEST(EyerString, string){
    for(int i=0;i<100;i++){
        Eyer::EyerString str = (Eyer::EyerString)"/Users/lichi/Downloads/size.flv";

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

    for(int i=0;i<100;i++){
        Eyer::EyerString strA = "strA";
        Eyer::EyerString strB = "strB";

        Eyer::EyerString strAB = strA + strB;

        EXPECT_TRUE(strAB == "strAstrB");
    }
}

TEST(RedString_Test,string){
    RedString a;
    RedString b("eyer test str");
    EXPECT_TRUE(a == "");
    EXPECT_FALSE(a == b);

    a = b;
    EXPECT_TRUE(a == b);
}

TEST(RedArgs_Test, args){
    RedArg argA(0, NULL);
    EXPECT_EQ(argA.GetCount(), 0);
}

TEST(RedBtte_Test, byte){
    RedByte byte;
}

TEST(EyerTime, time){
    long long time = Eyer::EyerTime::GetTime();
    EyerLog("Time:%lld\n", time);
    EyerLog("Time:%s\n", Eyer::EyerTime::TimeFormat().str);
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

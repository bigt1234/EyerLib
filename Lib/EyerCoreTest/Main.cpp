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

TEST(EyerLinkedList_Test, insert_delete){
    Eyer::YaoLinkedList<float> list;
    for (int i = 0; i < 10; i++) {
		Eyer::YaoLinkedEle<float> ele(i+0.1);
		if (list.insertEle(&ele, i)) {
			EyerLog("EyerLinkedList insert fail \n");
		}	
	}
    list.circleElement();
    EyerLog("list Length :%d\n", list.length);	
    EXPECT_TRUE(list.length == 10);

    // float * data1 = nullptr;
    // list.find(0, data1);
    // EyerLog("data0:%f\n", *data1);	
    // list.find(1, data1);
    // EyerLog("data1:%f\n", *data1);
    // list.find(5, data1);
    // EyerLog("data5:%f\n", *data1);	
    // list.find(9, data1);
    // EyerLog("data9:%f\n", *data1);		

    /*
	list.deleteEle(0);
    EXPECT_TRUE(list.length == 99);

    list.deleteEle(50);
    EXPECT_TRUE(list.length == 98);
    */
    EyerLog("list Length:%d\n", list.length);	

}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

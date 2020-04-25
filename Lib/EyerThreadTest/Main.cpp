#include <stdio.h>
#include <gtest/gtest.h>

#include "EyerThread/EyerThread.hpp"
#include "EyerCore/EyerCore.hpp"

class TimeThread : public Eyer::EyerThread
{
private:
    Eyer::EyerString tag;

public:
    TimeThread(Eyer::EyerString _tag){
        tag = _tag;
    }

    virtual void Run()
    {
        SetRunning();

        while(!stopFlag){
            printf("this from: %s\n", tag.str);
            Eyer::EyerTime::EyerSleep(1000 * 1000);
        }

        SetStoping();
    }
};

TEST(Eyer, EyerThread){
    TimeThread a("A");
    TimeThread b("B");

    a.Start();
    b.Start();

    Eyer::EyerTime::EyerSleep(1000 * 1000 * 10);

    a.Stop();
    b.Stop();
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>

#include "EyerAV/EyerAV.hpp"

TEST(EyerAVPacket, packet){
    for(int i=0;i<100;i++){
        Eyer::EyerAVPacket packet;

        RedString path("");
        Eyer::EyerAVReader reader(path);
        reader.Open();
        reader.Read(&packet);
        reader.Close();
        
        char * a = (char *)malloc(128);
        
        sleep(1);
    }
    
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

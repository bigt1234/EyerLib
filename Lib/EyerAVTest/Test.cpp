#include <gtest/gtest.h>

#include "EyerAV/EyerAV.hpp"

char * pathStr = (char *)"/home/redknot/Videos/M_1280_720.mp4";

TEST(EyerAVPacket, packet){
    for(int i=0;i<100;i++){
        Eyer::EyerAVPacket packet;
    }   
}

TEST(EyerAVFormat1, format1){
    RedString path("");
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_LT(ret, 0) << "这里应该打开失败";
}

TEST(EyerAVFormat2, format2_open_success){
    RedString path(pathStr);
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_EQ(ret, 0) << "这里应该打开成功";
    reader.Close();
}

TEST(EyerAVFormat3, format3_read_frame){
    RedString path(pathStr);
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_EQ(ret, 0) << "这里应该打开成功";

    while (1)
    {
        Eyer::EyerAVPacket packet;
        int ret = reader.Read(&packet);
        if(ret){
            break;
        }
    }

    reader.Close();
}


TEST(Decoder, decoder){
    RedString path(pathStr);
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_EQ(ret, 0) << "这里应该打开成功";

    int streamCount = reader.GetStreamCount();
    ASSERT_EQ(streamCount, 2) << "如果使用的是提供的测试文件，那么这里应该返回2";

    std::vector<Eyer::EyerAVDecoder *> decoderList;

    for(int i=0;i<streamCount;i++){
        Eyer::EyerEyeStream stream;
        int ret = reader.GetStream(stream, i);
        ASSERT_EQ(ret, 0) << "这里应该返回成功";
        if(ret){
            continue;
        }

        ASSERT_EQ(stream.streamIndex, i) << "此处获取到的";

        Eyer::EyerAVDecoder * decoder = new Eyer::EyerAVDecoder();
        ret = decoder->Init(&stream);

        decoderList.push_back(decoder);

        ASSERT_EQ(ret, 0) << "这里应该返回成功";
    }


    while (1)
    {
        Eyer::EyerAVPacket packet;
        int ret = reader.Read(&packet);
        if(ret){
            break;
        }

        int streamId = packet.GetStreamId();
        // RedLog("Stream Id:%d\n", streamId);

        Eyer::EyerAVDecoder * decoder = decoderList[streamId];

        decoder->SendPacket(&packet);

        while(1){
            Eyer::EyerAVFrame frame;
            int ret = decoder->RecvFrame(&frame);
            if(ret){
                break;
            }

            // Get Frame 

            RedLog("Stream Id: %d\n", streamId);
        }
    }


    for(int i=0;i<decoderList.size();i++){
        Eyer::EyerAVDecoder * decoder = decoderList[i];
        delete decoder;
    }
}


int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

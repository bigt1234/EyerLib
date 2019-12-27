#include <gtest/gtest.h>

#include "EyerAV/EyerAV.hpp"

// char * pathStr = (char *)"/Users/yuqiaomiao/Video/Video/1_0.mp4";
// char * outPathStr = (char *)"/Users/yuqiaomiao/Video/Video/1_0_out.mp4";

char * pathStr = (char *)"/Users/yuqiaomiao/Video/1280_720.mp4";
char * outPathStr = (char *)"/Users/yuqiaomiao/Video/1280_720_out.mp4";
char * outPathSStr = (char *)"/Users/yuqiaomiao/Video/1280_720_S_out.mp4";

// char * pathStr = (char *)"/home/redknot/Videos/M_1280_720.mp4";
// char * outPathStr = (char *)"/home/redknot/Videos/M_1280_720_out.mp4";

TEST(EyerAVPacket, packet){
    for(int i=0;i<100;i++){
        Eyer::EyerAVPacket packet;
    }   
}

TEST(EyerAVFormat1, format1){
    Eyer::EyerString path = "";
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_LT(ret, 0) << "这里应该打开失败";
}

TEST(EyerAVFormat2, format2_open_success){
    Eyer::EyerString path = pathStr;
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_EQ(ret, 0) << "这里应该打开成功";
    reader.Close();
}

TEST(EyerAVFormat3, format3_read_frame){
    Eyer::EyerString path = pathStr;
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



TEST(VideoRecoder, videoRecoder){
    Eyer::EyerString path = pathStr;
    Eyer::EyerAVReader reader(path);
    int ret = reader.Open();
    ASSERT_EQ(ret, 0) << "这里应该打开成功";

    int streamCount = reader.GetStreamCount();
    ASSERT_EQ(streamCount, 2) << "如果使用的是提供的测试文件，那么这里应该返回2";

    Eyer::EyerString outPath = outPathStr;
    Eyer::EyerAVWriter writer(outPath);

    std::vector<Eyer::EyerAVDecoder *> decoderList;
    std::vector<Eyer::EyerAVEncoder *> encoderList;

    for(int i=0;i<streamCount;i++){
        Eyer::EyerAVStream stream;
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

        Eyer::EyerAVEncoder * encoder = new Eyer::EyerAVEncoder();
        ret = encoder->Init(&stream);
        if(ret){
            continue;
        }
        encoderList.push_back(encoder);

        ASSERT_EQ(ret, 0) << "这里应该返回成功";
        writer.AddStream(encoder);
    }

    
    writer.Open();

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

            Eyer::EyerAVEncoder * encoder = encoderList[streamId];
            // Get Frame 
            encoder->SendFrame(&frame);
            while(1){
                Eyer::EyerAVPacket packet;
                ret = encoder->RecvPacket(&packet);
                if(ret){
                    break;
                }

                packet.SetStreamId(streamId);
                writer.WritePacket(&packet);
            }
        }
    }

    // 把编码器里的东西弄干净
    for(int i=0;i<encoderList.size();i++){
        Eyer::EyerAVEncoder * encoder = encoderList[i];
        encoder->SendFrame(nullptr);
        while(1){
            Eyer::EyerAVPacket packet;
            ret = encoder->RecvPacket(&packet);
            if(ret){
                break;
            }

            packet.SetStreamId(i);
            writer.WritePacket(&packet);
        }
    }


    writer.Close();

    for(int i=0;i<decoderList.size();i++){
        Eyer::EyerAVDecoder * decoder = decoderList[i];
        delete decoder;
    }
    decoderList.clear();

    for(int i=0;i<encoderList.size();i++){
        Eyer::EyerAVEncoder * encoder = encoderList[i];
        delete encoder;
    }
    encoderList.clear();
}



TEST(VideoRecoder, split){
    std::vector<Eyer::EyerAVReader *> readerList;
    {
        Eyer::EyerString path = "/Users/yuqiaomiao/Video/1280_720.mp4";
        Eyer::EyerAVReader * reader = new Eyer::EyerAVReader(path);
        readerList.push_back(reader);
    }

    Eyer::EyerString outPath = outPathSStr;
    Eyer::EyerAVWriter writer(outPath);

    // 弄个模版视频
    Eyer::EyerString templPath = "/Users/yuqiaomiao/Video/1280_720.mp4";
    Eyer::EyerAVReader templVideo(templPath);
    std::vector<Eyer::EyerAVEncoder *> encoderList;

    templVideo.Open();
    int streamCount = templVideo.GetStreamCount();

    for(int i=0;i<streamCount;i++){
        Eyer::EyerAVStream stream;
        int ret = templVideo.GetStream(stream, i);

        Eyer::EyerAVEncoder * encoder = new Eyer::EyerAVEncoder();
        encoder->Init(&stream);

        encoderList.push_back(encoder);

        writer.AddStream(encoder);
    }

    templVideo.Close();

    writer.Open();


    for(int j=0;j<readerList.size();j++){
        Eyer::EyerAVReader * reader = readerList[j];
        reader->Open();

        std::vector<Eyer::EyerAVDecoder *> decoderList;

        int streamCount = reader->GetStreamCount();

        for(int i=0;i<streamCount;i++){
            Eyer::EyerAVStream stream;
            int ret = reader->GetStream(stream, i);
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
            int ret = reader->Read(&packet);
            if(ret){
                break;
            }

            int streamId = packet.GetStreamId();

            Eyer::EyerAVDecoder * decoder = decoderList[streamId];

            decoder->SendPacket(&packet);


            while(1){
                Eyer::EyerAVFrame frame;
                int ret = decoder->RecvFrame(&frame);
                if(ret){
                    break;
                }

                Eyer::EyerAVEncoder * encoder = encoderList[streamId];
                // Get Frame
                encoder->SendFrame(&frame);
                while(1){
                    Eyer::EyerAVPacket packet;
                    ret = encoder->RecvPacket(&packet);
                    if(ret){
                        break;
                    }

                    packet.SetStreamId(streamId);

                    writer.WritePacket(&packet);
                }
            }
        }

        for(int i=0;i<decoderList.size();i++){
            Eyer::EyerAVDecoder * decoder = decoderList[i];
            delete decoder;
        }
        decoderList.clear();

        reader->Close();
    }

    // 把编码器里的东西弄干净
    for(int i=0;i<encoderList.size();i++){
        Eyer::EyerAVEncoder * encoder = encoderList[i];
        encoder->SendFrame(nullptr);
        while(1){
            Eyer::EyerAVPacket packet;
            int ret = encoder->RecvPacket(&packet);
            if(ret){
                break;
            }

            packet.SetStreamId(i);

            writer.WritePacket(&packet);
        }
        // encoder->Flush();
    }

    writer.Close();

    for(int i=0;i<readerList.size();i++){
        Eyer::EyerAVReader * reader = readerList[i];
        delete reader;
    }

    for(int i=0;i<encoderList.size();i++){
        Eyer::EyerAVEncoder * encoder = encoderList[i];
        delete encoder;
    }
    encoderList.clear();
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

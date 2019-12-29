#ifndef	EYER_LIB_AV_TEST_ENCODER_H
#define	EYER_LIB_AV_TEST_ENCODER_H

#include <gtest/gtest.h>
#include "EyerAV/EyerAV.hpp"

#include "Path.hpp"

#include <math.h>

TEST(EyerAVCodec, audio_re_encoder){
    Eyer::EyerAVReader audioReader("/home/redknot/Videos/A/1403_20_4431.aac");

    int ret = audioReader.Open();
    if(ret){
        return;
    }

    Eyer::EyerAVStream audioStream;
    ret = audioReader.GetStream(audioStream, 0);
    if(ret){
        return;
    }

    Eyer::EyerAVDecoder audioDecoder;
    audioDecoder.Init(&audioStream);

    Eyer::EyerAVEncoder encoder;
    Eyer::EncoderParam audioParam;
    audioParam.codecId = Eyer::CodecId::CODEC_ID_AAC;
    ret = encoder.Init(&audioParam);
    if(ret){
        printf("Open Encoder Error\n");
        return;
    }

    Eyer::EyerAVWriter writer("/home/redknot/Videos/miaomiao.aac");
    int streamId = writer.AddStream(&encoder);

    writer.Open();

    while(1){
        Eyer::EyerAVPacket readPacket;
        ret = audioReader.Read(&readPacket);
        if(ret){
            break;
        }

        audioDecoder.SendPacket(&readPacket);

        while(1){
            Eyer::EyerAVFrame frame;
            ret = audioDecoder.RecvFrame(&frame);
            if(ret){
                break;
            }

            encoder.SendFrame(&frame);

            Eyer::EyerAVPacket encoderPacket;

            while(1){
                ret = encoder.RecvPacket(&encoderPacket);
                if(ret){
                    break;
                }

                //printf("PTS:%lld\n", encoderPacket.GetPTS());
                //printf("DTS:%lld\n", encoderPacket.GetDTS());
                encoderPacket.SetStreamId(streamId);
                writer.WritePacket(&encoderPacket);
            }
        }
    }

    writer.Close();

    audioReader.Close();
}

/*
TEST(EyerAVCodec, audio_encoder){
    Eyer::EyerAVEncoder encoder;

    Eyer::EncoderParam audioParam;
    audioParam.codecId = Eyer::CodecId::CODEC_ID_AAC;

    int ret = encoder.Init(&audioParam);
    if(ret){
        printf("Open Encoder Error\n");

        return;
    }

    Eyer::EyerAVWriter writer("/home/redknot/Videos/miaomiao.aac");
    int streamId = writer.AddStream(&encoder);

    writer.Open();
    
    for(int i=0;i<1000;i++){
        int bufferSize = encoder.GetBufferSize();
        printf("Buffer Size:%d\n", bufferSize);

        float * buf = (float *)malloc(bufferSize);

        for(int j=0;j<bufferSize / 4;j++){
            buf[j] = sin(j * 0.01f * 1.0f) * 100.0f + 128.0f;
        }

        Eyer::EyerAVFrame frame;
        frame.SetPTS(i * 100);
        frame.SetData((unsigned char *)buf, bufferSize);

        encoder.SendFrame(&frame);
        while(1){
            Eyer::EyerAVPacket packet;
            ret = encoder.RecvPacket(&packet);
            if(ret){
                break;
            }

            printf("Encoder Success DTS:%lld=====PTS:%lld\n", packet.GetDTS(), packet.GetPTS());
            packet.SetStreamId(streamId);

            writer.WritePacket(&packet);
        }

        free(buf);
    }    

    writer.Close();
}
*/

#endif

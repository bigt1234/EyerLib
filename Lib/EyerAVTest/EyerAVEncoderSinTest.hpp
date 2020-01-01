#ifndef	EYER_LIB_AV_TEST_ENCODER_SIN_H
#define	EYER_LIB_AV_TEST_ENCODER_SIN_H

#include <gtest/gtest.h>
#include "EyerAV/EyerAV.hpp"

TEST(EyerAVCodec, audio_encoder_sin){
    Eyer::EyerAVWriter writer("/home/redknot/Videos/A/audio_encoder_sin.aac");

    Eyer::EncoderParam param;
    param.codecId = Eyer::CodecId::CODEC_ID_AAC;
    Eyer::EyerAVEncoder encoder;
    encoder.Init(&param);

    int streamIndex = writer.AddStream(&encoder);

    int timeBaseDen = writer.GetStreamTimeBaseDen(streamIndex);
    int timeBaseNum = writer.GetStreamTimeBaseNum(streamIndex);

    printf("Time Base Den:%d\n", timeBaseDen);
    printf("Time Base Num:%d\n", timeBaseNum);


    int bufferSize = encoder.GetBufferSize();
    printf("bufferSize:%d\n", bufferSize);

    writer.Open();

    for(int i=0;i<1000;i++){
        Eyer::EyerAVFrame frame;

        encoder.SendFrame(&frame);

        while (1){
            Eyer::EyerAVPacket pkt;
            int ret = encoder.RecvPacket(&pkt);
            if(ret){
                break;
            }

            writer.WritePacket(&pkt);
        }
    }


    writer.Close();
}

#endif
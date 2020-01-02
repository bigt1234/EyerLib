//
// Created by lichi on 2020/1/2.
//

#ifndef EYE_LIB_EYERAVDECODERAUDIOTEST_H
#define EYE_LIB_EYERAVDECODERAUDIOTEST_H

#include <gtest/gtest.h>
#include "EyerAV/EyerAV.hpp"

#include "Path.hpp"

TEST(EyerAVDeocder, decoder_audio){
    Eyer::EyerAVReader reader("/Users/lichi/Movies/1403_20_4431.aac");

    reader.Open();

    Eyer::EyerAVStream stream;
    reader.GetStream(stream, 0);

    Eyer::EyerAVDecoder decoder;
    decoder.Init(&stream);

    while(1){
        Eyer::EyerAVPacket pkt;
        int ret = reader.Read(&pkt);
        if(ret){
            break;
        }

        Eyer::EyerAVFrame frame;
        decoder.SendPacket(&pkt);

        while(1){
            ret = decoder.RecvFrame(&frame);
            if(ret){
                break;
            }

            frame.GetInfo();
        }
    }

    reader.Close();
}

#endif //EYE_LIB_EYERAVDECODERAUDIOTEST_H

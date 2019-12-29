//
// Created by redknot on 2019/12/29.
//

#ifndef EYE_LIB_EYER_AV_FRAME_TEST_H
#define EYE_LIB_EYER_AV_FRAME_TEST_H

#include <gtest/gtest.h>
#include "EyerAV/EyerAV.hpp"

TEST(EyerAVFrame, av_frame) {
    for(int i=1024;i<2048;i++){
        Eyer::EyerAVFrame frame;

        unsigned char * data = (unsigned char *)malloc(i);

        frame.SetData(data, i, 0);
        frame.SetData(data, i, 1);
        frame.SetData(data, i, 2);
        frame.SetData(data, i, 3);
        frame.SetData(data, i, 4);
        frame.SetData(data, i, 5);
        frame.SetData(data, i, 6);
        frame.SetData(data, i, 7);

        free(data);
    }
}

#endif //EYE_LIB_EYERAVFRAMETEST_H

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
    }
}

#endif //EYE_LIB_EYERAVFRAMETEST_H

#ifndef	EYER_CORE_TEST_MATH_H
#define	EYER_CORE_TEST_MATH_H

#include <gtest/gtest.h>

#include "EyerCore/EyerCore.hpp"

TEST(EyerMath, Mat_Base){
    for(int i=0;i<100;i++){
        Eyer::EyerMat mat(4, 4);
    }
}

#endif
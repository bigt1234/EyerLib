#include "EyerMath.hpp"

namespace Eyer {
    EyerMat2x1::EyerMat2x1() : EyerMat(2, 1)
    {

    }

    EyerMat2x1::~EyerMat2x1()
    {

    }

    float EyerMat2x1::x()
    {
        return mat[0][0];
    }

    float EyerMat2x1::y()
    {
        return mat[1][0];
    }

    int EyerMat2x1::SetX(float x)
    {
        mat[0][0] = x;
        return 0;
    }

    int EyerMat2x1::SetY(float y)
    {
        mat[1][0] = y;
        return 0;
    }
}
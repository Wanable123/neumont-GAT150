#pragma once
#include "MathUtils.h"

namespace math
{

    int sqr(int v)
    {
        return v * v;
    }
    int half(int v)
    {
        return v / 2;
    }


    inline float DegToRad(float degrees) {
        return degrees * (Pi / 180);


    }

    inline float RadToDeg(float radians) {
        return radians * (180 / Pi);


    }
}
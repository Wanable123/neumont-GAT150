#pragma once 
//thing below is same as pragma

namespace math
{
	const float Pi = 3.14159265359f;
	const float TwoPi = 6.28318530718f;
	const float HalfPi = 1.57079632679f;
	int sqr(int v);
	int half(int v);

	constexpr float DegToRad(float degrees) {
		return degrees * (Pi / 180);


	}

	constexpr float RadToDeg(float radians) {
		return radians * (180 / Pi);


	}
}


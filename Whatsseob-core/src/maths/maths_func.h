#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace whatsseob {
	namespace maths {

		inline float toRadians(float degrees)
		{
			return degrees * (M_PI / 180.f);
		}
	}
}
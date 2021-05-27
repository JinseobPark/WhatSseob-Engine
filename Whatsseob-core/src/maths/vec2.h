#pragma once
#include <iostream>

namespace whatsseob {
	namespace maths {

		struct vec2  //lower for matching OpenGL shading langugage
		{
			float x, y;

			vec2();
			vec2(const float& x, const float& y);
				
			vec2& add(const vec2& v);
			vec2& substract(const vec2& v);
			vec2& multiply(const vec2& v);
			vec2& divide(const vec2& v);

			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);

			//Todo : operator , muliply a * 3
			bool operator==(const vec2& v);
			bool operator!=(const vec2& v);

			vec2& operator+=(const vec2& v);
			vec2& operator-=(const vec2& v);
			vec2& operator*=(const vec2& v);
			vec2& operator/=(const vec2& v);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);

		};


	}
}
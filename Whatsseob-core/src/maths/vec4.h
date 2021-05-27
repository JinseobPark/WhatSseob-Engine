#pragma once
#include <iostream>

namespace whatsseob {
	namespace maths {

		struct vec4  //lower for matching OpenGL shading langugage
		{
			float x, y, z, w; //RGBA

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);
				
			vec4& add(const vec4& v);
			vec4& substract(const vec4& v);
			vec4& multiply(const vec4& v);
			vec4& divide(const vec4& v);

			friend vec4 operator+(vec4 left, const vec4& right);
			friend vec4 operator-(vec4 left, const vec4& right);
			friend vec4 operator*(vec4 left, const vec4& right);
			friend vec4 operator/(vec4 left, const vec4& right);

			//Todo : operator , muliply a * 3
			bool operator==(const vec4& v);
			bool operator!=(const vec4& v);

			vec4& operator+=(const vec4& v);
			vec4& operator-=(const vec4& v);
			vec4& operator*=(const vec4& v);
			vec4& operator/=(const vec4& v);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);

		};


	}
}
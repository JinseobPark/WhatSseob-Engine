#pragma once
#include <iostream>

namespace whatsseob {
	namespace maths {

		struct vec3  //lower for matching OpenGL shading langugage
		{
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);
				
			vec3& add(const vec3& v);
			vec3& substract(const vec3& v);
			vec3& multiply(const vec3& v);
			vec3& divide(const vec3& v);

			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			//Todo : operator , muliply a * 3
			bool operator==(const vec3& v);
			bool operator!=(const vec3& v);

			vec3& operator+=(const vec3& v);
			vec3& operator-=(const vec3& v);
			vec3& operator*=(const vec3& v);
			vec3& operator/=(const vec3& v);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);

		};


	}
}
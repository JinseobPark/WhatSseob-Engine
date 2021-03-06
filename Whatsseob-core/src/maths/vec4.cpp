#include "vec4.h"

namespace whatsseob {
	namespace maths {
		//vec4::vec4()
		//{
		//	x = 0.0f;
		//	y = 0.0f;
		//	z = 0.0f;
		//	w = 0.0f;

		//}
		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		vec4& vec4::add(const vec4& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}
		vec4& vec4::substract(const vec4& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		vec4& vec4::multiply(const vec4& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			w *= v.w;
			return *this;
		}
		vec4& vec4::divide(const vec4& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			w /= v.w;

			//Todo : divide 0
			return *this;
		}
		bool vec4::operator==(const vec4& v)
		{
			return ((x == v.x) && (y == v.y) && (z == v.z) && (w == v.w));
		}
		bool vec4::operator!=(const vec4& v)
		{
			return !(*this == v);
		}
		vec4& vec4::operator+=(const vec4& v)
		{
			return add(v);
		}
		vec4& vec4::operator-=(const vec4& v)
		{
			return substract(v);
		}
		vec4& vec4::operator*=(const vec4& v)
		{
			return multiply(v);
		}
		vec4& vec4::operator/=(const vec4& v)
		{
			return divide(v);
		}
		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);
		}
		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.substract(right);
		}
		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);
		}
		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}
		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << "vec4 : (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}
	}
}
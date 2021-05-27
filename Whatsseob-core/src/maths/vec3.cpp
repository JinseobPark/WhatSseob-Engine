#include "vec3.h"

namespace whatsseob {
	namespace maths {
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		vec3& vec3::add(const vec3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		vec3& vec3::substract(const vec3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		vec3& vec3::multiply(const vec3& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}
		vec3& vec3::divide(const vec3& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;

			//Todo : divide 0
			return *this;
		}
		bool vec3::operator==(const vec3& v)
		{
			return ((x == v.x) && (y == v.y) && (z == v.z));
		}
		bool vec3::operator!=(const vec3& v)
		{
			return !(*this == v);
		}
		vec3& vec3::operator+=(const vec3& v)
		{
			return add(v);
		}
		vec3& vec3::operator-=(const vec3& v)
		{
			return substract(v);
		}
		vec3& vec3::operator*=(const vec3& v)
		{
			return multiply(v);
		}
		vec3& vec3::operator/=(const vec3& v)
		{
			return divide(v);
		}
		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}
		vec3 operator-(vec3 left, const vec3& right)
		{
			return left.substract(right);
		}
		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}
		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}
		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << "vec3 : (" << vector.x << ", " << vector.y << "," << vector.z << ")";
			return stream;
		}
	}
}
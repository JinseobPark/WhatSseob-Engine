#include "vec2.h"

namespace whatsseob {
	namespace maths {
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}
		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}
		vec2& vec2::add(const vec2& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}
		vec2& vec2::substract(const vec2& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		vec2& vec2::multiply(const vec2& v)
		{
			x *= v.x;
			y *= v.y;
			return *this;
		}
		vec2& vec2::divide(const vec2& v)
		{
			x /= v.x;
			y /= v.y;

			//Todo : divide 0
			return *this;
		}
		bool vec2::operator==(const vec2& v)
		{
			return ((x == v.x) && (y == v.y));
		}
		bool vec2::operator!=(const vec2& v)
		{
			return !(*this == v);
		}
		vec2& vec2::operator+=(const vec2& v)
		{
			return add(v);
		}
		vec2& vec2::operator-=(const vec2& v)
		{
			return substract(v);
		}
		vec2& vec2::operator*=(const vec2& v)
		{
			return multiply(v);
		}
		vec2& vec2::operator/=(const vec2& v)
		{
			return divide(v);
		}
		vec2 operator+(vec2 left, const vec2& right)
		{
			return left.add(right);
		}
		vec2 operator-(vec2 left, const vec2& right)
		{
			return left.substract(right);
		}
		vec2 operator*(vec2 left, const vec2& right)
		{
			return left.multiply(right);
		}
		vec2 operator/(vec2 left, const vec2& right)
		{
			return left.divide(right);
		}
		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "Vec2 : (" << vector.x << ", " << vector.y << ")";
			return stream;
		}
	}
}
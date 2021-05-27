#include "mat4.h"

namespace whatsseob {
	namespace maths {

		mat4::mat4()
		{
			/*
			0 0 0 0
			0 0 0 0
			0 0 0 0
			0 0 0 0
			*/
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}

		mat4::mat4(float diagonal)
		{
			/*
			1 0 0 0
			0 1 0 0
			0 0 1 0
			0 0 0 1
			*/
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4& mat4::multiply(const mat4& m)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * m.elements[e + y * 4];
					}
					elements[x + y * 4] = sum;
				}
			}

			return *this;

		}

		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		mat4& mat4::operator*=(const mat4& m)
		{
			return multiply(m);
		}

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);
			/*
			2/r-l		0		0		l+r/l-r
			0		2/t-b		0		t+b/b-t
			0			0		2/n-f	f+n/f-n
			0			0		0			1
			*/


			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = 2.0f / (left + right) / (left - right);
			result.elements[1 + 3 * 4] = 2.0f / (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = 2.0f / (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(1.0f);

			/*
			1/(a*tan(fov/2))	0				0			0
				0			1/fan(fov/2))		0			0
				0				0			n+f/n-f		2*f*n/n-f
				0				0				-1			0
			*/
			float q = 1.0f / (float)tan(toRadians(0.5f * fov));
			float a = q / aspectRatio;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);


			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[2 + 3 * 4] = c;
			result.elements[3 + 2 * 4] = -1.0f;

			return result;


		}
		mat4 mat4::translation(const vec3& translation)
		{
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;


			return result;
		}
		mat4 mat4::rotation(float angle, const vec3& axis)
		{
			mat4 result(1.0f);

			/*
			(1-c)x^2 + c	(1-c)xy - sz	(1-c)xz + sy	0
			(1-c)xy + sz	(1-c)y^2+c		(1-c)yz - sx	0
			(1-c)xz - sy	(1-c)yz+sx		(1-c)z^2+c		0
				0				0				0			1

			*/


			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = x * y * omc - s * z;
			result.elements[1 + 1 * 4] = y * y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * z * omc + c;

			return result;
		}
		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;


			return result;
		}
	}
}
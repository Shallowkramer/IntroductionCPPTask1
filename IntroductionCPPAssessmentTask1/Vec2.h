#pragma once

#include <math.h>

class Vec2
{
public:

	float x = 0.0f;
	float y = 0.0f;

	//defalt constructor
	Vec2() {}

	//overloaded constructor
	Vec2(float x, float y) : x(x), y(y) {}

	//overload plus operator
	Vec2 operator + (const Vec2& rhs)
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}

	//overload plus equal operator
	void operator += (const Vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}

	//overload minus operator
	Vec2 operator - (const Vec2& rhs)
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	//overload minus equal operator
	void operator -= (const Vec2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
	}

	//overload the multiply operator
	Vec2 operator * (float rhs)
	{
		return Vec2(x * rhs, y * rhs);
	}

	//overload the multiply equal operator
	void operator *= (float rhs)
	{
		x *= rhs;
		y *= rhs;
	}

	//overload the divide operator
	Vec2 operator / (float rhs)
	{
		return Vec2(x / rhs, y / rhs);
	}

	//overload the divide equal operator
	void operator /= (float rhs)
	{
		x /= rhs;
		y /= rhs;
	}

	//overload is equal operator
	bool operator == (const Vec2& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}

	//overload not equal operator
	bool operator != (const Vec2& rhs)
	{
		return !(x == rhs.x && y == rhs.y);
	}

	float Length()
	{
		return sqrt(x * x + y * y);
	}

	float Magnitude()
	{
		return Length();
	}

	Vec2 Normalise()
	{
		float len = Length();

		if (len == 0)
		{
			return Vec2(0, 0);
		}
		return Vec2(x / len, y / len);
	}

	float Dot(const Vec2& rhs)
	{
		return x * rhs.x + y * rhs.y;
	}


};

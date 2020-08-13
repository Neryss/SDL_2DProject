#pragma once
#include <iostream>

struct Vector2f
{
	Vector2f()
	:x(0.0f), y(0.0f)
	{}

	Vector2f(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
	bool operator==(const Vector2f &o)
	{
		return(x == o.x && y == o.y);
	}
	bool operator!=(const Vector2f &o)
	{
		return(x != o.x || y != o.y);
	}
	Vector2f operator+(const Vector2f &other) 
	{
		return(Vector2f(x + other.x, y + other.y));
	}
	Vector2f operator-(const Vector2f &other)
	{
		return(Vector2f(x - other.x, y - other.y));
	}
	Vector2f operator*(const Vector2f &other)
	{
		return(Vector2f(x * other.x, y * other.y));
	}

	Vector2f operator+=(const Vector2f &o);
	Vector2f operator-=(const Vector2f &o);
	Vector2f operator*=(const Vector2f &o);
};
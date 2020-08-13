#include "Math.hpp"

Vector2f Vector2f::operator+=(const Vector2f &o)
{
	x += o.x;
	y += o.y;
	return(*this);
}

Vector2f Vector2f::operator-=(const Vector2f &o)
{
	x -= o.x;
	y -= o.y;
	return(*this);
}

Vector2f Vector2f::operator*=(const Vector2f &o)
{
	x *= o.x;
	y *= o.y;
	return(*this);
}
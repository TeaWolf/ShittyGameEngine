// Teawolf

#include "vector_2d.h"

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	m_x += vec.m_x;
	m_y += vec.m_y;

	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	m_x -= vec.m_x;
	m_y -= vec.m_y;

	return *this;
}

Vector2D& Vector2D::operator*=(double scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	return *this;
}

Vector2D& Vector2D::operator/=(double scalar)
{
	m_x /= scalar;
	m_y /= scalar;

	return *this;
}

Vector2D operator+(Vector2D vec0, const Vector2D& vec1)
{
	return vec0 += vec1;
}

Vector2D operator-(Vector2D vec0, const Vector2D& vec1)
{
	return vec0 -= vec1;
}

Vector2D operator*(Vector2D vec, double scalar)
{
	return vec *= scalar;
}

Vector2D operator/(Vector2D vec, double scalar)
{
	return vec /= scalar;
}

double Vector2D::length()
{
	return std::sqrt(m_x * m_x + m_y * m_y);
}

void Vector2D::normalize()
{
	*this /= length();
}

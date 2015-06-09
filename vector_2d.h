// Tewolf

#pragma once

#include <cmath>

class Vector2D
{
public:
	Vector2D() : m_x{0}, m_y{0} {}
	Vector2D(double x, double y) : m_x(x), m_y(y) {}

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(double scalar);
	Vector2D& operator/=(double scalar);
	
	double length();
	void normalize();

	// Accessors
	double get_x() {return m_x;}
	double get_y() {return m_y;}

	void set_x(double x) {m_x = x;}
	void set_y(double y) {m_y = y;}

private:
	double m_x, m_y;
};

// Not declared as friends because they don't need to access private members
Vector2D operator+(Vector2D vec0, const Vector2D& vec1);
Vector2D operator-(Vector2D vec0, const Vector2D& vec1);
Vector2D operator*(Vector2D vec, double scalar);
Vector2D operator/(Vector2D vec, double scalar);

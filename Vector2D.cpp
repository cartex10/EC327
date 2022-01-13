#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D() //Default constructor
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(double in_x, double in_y)	//Constructor
{
	x = in_x;
	y = in_y;
}

Vector2D operator*(Vector2D v1, double d)
{
	return Vector2D(v1.x * d, v1.y * d);
}

Vector2D operator/(Vector2D v1, double d)
{
	return Vector2D(v1.x / d, v1.y / d);
}

ostream& operator<<(ostream& out, Vector2D& v1)
{
	out << "<" << v1.x << ", " << v1.y << ">";
	return out;
}
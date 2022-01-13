#include <iostream>
using namespace std;

#ifndef Vector2D_h
#define Vector2D_h

class Vector2D
{
public:
	double x;
	double y;

	Vector2D();
	Vector2D(double in_x, double in_y);
};

Vector2D operator*(Vector2D, double);

Vector2D operator/(Vector2D, double);

ostream& operator<<(ostream&, Vector2D&);
#endif
#include <cmath>
#include <iostream>
#include <ostream>
#include "Vector2D.h"

using namespace std;

#ifndef Point2D_h
#define Point2D_h

class Point2D
{
public:
	double x;
	double y;
  
	Point2D();
	Point2D(double in_x, double in_y);
};

double GetDistanceBetween(Point2D, Point2D);
Point2D operator+(Point2D, Vector2D);
ostream& operator<<(ostream&, Point2D&);
Vector2D operator-(Point2D, Point2D);

#endif
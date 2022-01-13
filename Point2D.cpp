#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

Point2D::Point2D(double in_x, double in_y)  //Constructor
  {
    x = in_x;
    y = in_y;
  }

Point2D::Point2D()  //Default Constructor
  {
  	x = 0;
  	y = 0;
  }

double GetDistanceBetween(Point2D p1, Point2D p2) //Finds distance between two points
	{
    double temp;
    temp = pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2);
    return sqrt(temp);
	}

Point2D operator+(Point2D p1, Vector2D v1)  //Overloaded + operator
{
	return Point2D(p1.x + v1.x, p1.y + v1.y);
}

ostream& operator<<(ostream& out, Point2D& p1)  //Overloaded << operator
{
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}

Vector2D operator-(Point2D p1, Point2D p2)  //Overloaded - operator
{
	return Vector2D(p1.x - p2.x, p1.y - p2.y);
}
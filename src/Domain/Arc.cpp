#include "Arc.h"
#include <math.h>
#define pi 3.1415

Quadrant Arc::quadrantOf(const Point& point)
{
	if (point.x >= p1.x) {
		if(point.y <= p1.y)
			return Q1;
		else
			return Q4;
	}

	if (point.x <= p1.x && point.y <= p1.y)
		return Q2;

	return Q3;
}

double Arc::calcAngle(double oppleg, double hypotenuse)
{
	return asin(oppleg / hypotenuse) * 180 / pi;
}

double Arc::degreesToRadians(double degrees)
{
	return degrees * pi / 180;
}

std::vector<Point> Arc::getCoordinates()
{
	std::vector<Point> points;
	points.push_back(p2);


	return points;
}

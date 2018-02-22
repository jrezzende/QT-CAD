#include "Arc.h"

int Arc::quadrantOf(const Point& point)
{
	if (point.x >= p1.x) {
		if(point.y <= p1.y) // Q1
			return 1;
		else
			return 4; // Q4
	}

	if (point.x <= p1.x && point.y <= p1.y)
		return 2; // Q2

	return 3; // Q3
}

std::vector<Point> Arc::getCoordinates()
{
	return std::vector<Point>();
}

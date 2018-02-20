#pragma once
#ifndef POINT_H
#define POINT_H

#include <vector>
#include <math.h>
#include "qpoint.h"

class Point
{
public:
	int x;
	int y;

	~Point() {}
	Point() : x(0), y(0) {}
	Point(QPoint point) : x(point.x()), y(point.y()) {}
	Point(int x, int y) : x(x), y(y) {}

	QPoint toQPoint() { return QPoint(x, y); }

	static double distanceBetweenTwoPoints(const Point& p1, const Point& p2) 
	{ return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); }
};

#endif //POINT_H
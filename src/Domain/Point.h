#pragma once
#ifndef POINT_H
#define POINT_H

#include "qpoint.h"

#include <vector>
#include <math.h>
#include <cstdlib>

class Point
{
public:
	double x;
	double y;

	~Point() {}
	Point() : x(0), y(0) {}
	Point(QPoint point) : x(point.x()), y(point.y()) {}
	Point(double x, double y) : x(x), y(y) {}

	QPoint toQPoint() { return QPoint(x, y); }
	static Point toPoint(QPoint pos) { return Point(pos.x(), pos.y()); }

	bool operator==(const Point& point) const { return std::abs(x - point.x) + std::abs(y - point.y) == 0; }

	static double distanceBetweenTwoPoints(const Point& p1, const Point& p2) 
	{ return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); }
};

#endif //POINT_H
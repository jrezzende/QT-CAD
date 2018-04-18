#pragma once
#ifndef INCLUDED_POINT_H
#define INCLUDED_POINT_H

#include <cmath>

class Point
{
public:
	double x;
	double y;

	~Point()= default;
	Point() : x(0), y(0) {}
	Point(const double _x, const double _y) : x(_x), y(_y) {}

	bool operator==(const Point& point) const { return std::abs(x - point.x) + std::abs(y - point.y) < 0.00001; }

	static double distanceBetweenTwoPoints(const Point& p1, const Point& p2) {
	   return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); 
    }
};

#endif //INCLUDED_POINT_H
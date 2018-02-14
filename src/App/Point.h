#pragma once
#ifndef POINT_H
#define POINT_H

#include <vector>
#include "qpoint.h"

class Point
{
public:

	int x;
	int y;

	~Point()= default;
	Point() : x(0), y(0) {}
	Point(QPoint point) : x(point.x()), y(point.y()) {}
	Point(int x, int y) : x(x), y(y) {}
};

#endif //POINT_H
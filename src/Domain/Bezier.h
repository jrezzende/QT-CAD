#pragma once
#ifndef BEZIER_H
#define BEZIER_H

#include "Shape.h"

class Bezier : public Shape
{
	Point p3;

public:
	~Bezier() {}
	Bezier() : Shape() {}
	Bezier(const Point firstPoint, const Point secondPoint) : Shape(firstPoint, secondPoint) {}
	Bezier(const Point firstPoint, const Point secondPoint, const Point thirdPoint)
			   : Shape(firstPoint, secondPoint) { }

	void setThirdPoint(const Point point) { p3= point;}

	std::vector<Point> getCoordinates() override;
};

#endif // !BEZIER_H

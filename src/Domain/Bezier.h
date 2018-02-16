#pragma once
#ifndef BEZIER_H
#define BEZIER_H

#include "Shapes.h"

class Bezier : public Shapes
{
	Point p1, p2, p3;

public:
	~Bezier()= default;
	Bezier()= default;
	Bezier(const Point firstPoint, const Point secondPoint, const Point thirdPoint) : Shapes(firstPoint, secondPoint) {}

	void setThirdPoint(const Point point) { p3= point;}

	std::vector<Point> getCoordinates() override;
};

#endif // !BEZIER_H

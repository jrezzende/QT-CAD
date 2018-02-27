#pragma once
#ifndef ARC_H
#define ARC_H

#include "Shape.h"

enum Quadrant
{
	Q1,
	Q2,
	Q3,
	Q4
};

class Arc : public Shape
{
	Point p3;
	double angle;
	double angleAux;
	double radius;

	Quadrant quadrantOf(const Point& point);
	double calcAngle(double oppleg, double hypotenuse);
	double degreesToRadians(double degrees);

public:
	~Arc() {}
	Arc() : Shape() { radius = Point::distanceBetweenTwoPoints(p1, p2); } // need to adjust constructor

	std::vector<Point> getCoordinates() override;
};
#endif //ARC_H
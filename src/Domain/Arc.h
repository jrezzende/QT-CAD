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

	double initialAngle;
	double finalAngle;
	double incrementAngle;
	double radius;
	int arcDivisions;

	Quadrant quadrantOf(const Point& point);
	double calcAngle(double oppleg, double hypotenuse);
	int calcArcDivisions(double angleArcSize);

	double degreesToRadians(double degrees);
	double radiansToDegrees(double radians);

public:
	~Arc() {}
	Arc() : Shape(), p3(Point(0, 0)) {}
	Arc(const Point& _p1, const Point& _p2, const Point& _p3) : Shape(_p1, _p2), p3(_p3) {}

	void setThirdPoint(const Point& _p3) { p3= _p3; }

	std::vector<Point> getCoordinates() override;
};
#endif //ARC_H
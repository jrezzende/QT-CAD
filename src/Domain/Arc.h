#pragma once
#ifndef ARC_H
#define ARC_H
#define pi 3.1415

#include "Shape.h"

class Arc : public Shape
{
	Point p3;

	double initialAngle;
	double finalAngle;
	double incrementAngle;
	double radius;
	
	int arcDivisions;

	Point& translatePoint(Point& p);
	Point& retranslatePoint(Point& p);

	int calcArcDivisions(double angleArcSize);

public:
	~Arc() {}
	Arc() : Shape(), p3(Point(0, 0)) {}
	Arc(const Point& _p1, const Point& _p2, const Point& _p3) : Shape(_p1, _p2), p3(_p3) { type= UNDEFINED; }

	void setThirdPoint(const Point& _p3) { p3 = _p3; }
	Point getThirdPoint() const { return p3; }

	double degreesToRadians(const double degrees) { return degrees * pi / 180; }
	double radiansToDegrees(const double radians) { return radians * 180 / pi; }

	std::vector<Point> getCoordinates() override;
	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitArc(*this); };
};

#endif //ARC_H
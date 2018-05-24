#pragma once
#ifndef INCLUDED_CADARC_H
#define INCLUDED_CADARC_H
#define PI 3.1415

#include "CADShape.h"

class CADArc : public CADShape
{
	Point p3;

	double initialAngle;
	double finalAngle;
	double incrementAngle;
	double radius;
	int arcDivisions;

	Point translatePoint(Point& p);
	Point retranslatePoint(Point& p);

	int calcArcDivisions(double angleSize);

public:
	~CADArc()= default;
	CADArc() : p3(Point(0, 0)), initialAngle(0.0), finalAngle(0.0), incrementAngle(0.0), radius(0.0), arcDivisions(0) {}

	CADArc(const Point& _p1, const Point& _p2, const Point& _p3) : CADShape(_p1, _p2), p3(_p3), initialAngle(0.0), finalAngle(0.0),
   incrementAngle(0.0), radius(0.0), arcDivisions(0) { type= ARC; }

	void setThirdPoint(const Point _p3) { p3 = _p3; }
	Point thirdPoint() const { return p3; }

	std::vector<Point> coordinates() override;

	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitArc(*this); };
   CADArc* clone() const override { return new CADArc(*this); }

   static double degreesToRadians(const double degrees) { return degrees * PI / 180; }
   static double radiansToDegrees(const double radians) { return radians * 180 / PI; }
};

#endif //  INCLUDED_CADARC_H
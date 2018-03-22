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
	Bezier(const Point firstPoint, const Point secondPoint, const Point thirdPoint) : Shape(firstPoint, secondPoint) { type= UNDEFINED; }

	void setThirdPoint(const Point point) { p3= point;}
	Point getThirdPoint() const { return p3; }

	std::vector<Point> getCoordinates() override;
	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitBezier(*this); };
};

#endif // !BEZIER_H
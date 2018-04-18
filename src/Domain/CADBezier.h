#pragma once
#ifndef INCLUDED_CADBEZIER_H
#define INCLUDED_CADBEZIER_H

#include "CADShape.h"

class CADBezier : public CADShape
{
	Point p3;

public:
	~CADBezier()= default;
	CADBezier()= default;
	CADBezier(const Point firstPoint, const Point secondPoint, const Point thirdPoint) :
   CADShape(firstPoint, secondPoint), p3(thirdPoint) { type= BEZIER; }

	void setThirdPoint(const Point point) { p3= point;}
	Point thirdPoint() const { return p3; }

	std::vector<Point> coordinates() override;

	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitBezier(*this); };
};

#endif //INCLUDED_CADBEZIER_H
#pragma once
#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "Shape.h"

class Line : public Shape
{
public:
	~Line() {}
	Line() : Shape() {}
	Line(const Point firstPoint, const Point lastPoint) : Shape(firstPoint, lastPoint) { type= UNDEFINED; }

	std::vector<Point> getCoordinates() override;
	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitLine(*this); };
};

#endif // !LINE_H
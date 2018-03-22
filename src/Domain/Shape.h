#pragma once
#ifndef SHAPES_H
#define SHAPES_H

#include "Point.h"
#include "ShapeType.h"
#include "ShapeVisitor.h"

#include <vector>

class Shape
{
protected:
	Point p1, p2;
	ShapeType type;

public:
	virtual ~Shape() {}
	Shape() : p1(), p2() {}
	Shape(const Point _p1, const Point _p2) { p1 = _p1; p2 = _p2; type = UNDEFINED; }

	virtual std::vector<Point> getCoordinates()= 0;
	virtual void setShape(const ShapeType _type)= 0;
	virtual void accept(ShapeVisitor& v) = 0;

	void setfirstPoint(const Point _p1) { p1 = _p1; }
	void setSecondPoint(const Point _p2) { p2 = _p2; }

	Point& getFirstPoint() { return p1; }
	Point& getSecondPoint() { return p2; }

	ShapeType shapeType() const { return type; }
};
#endif // !SHAPES_H
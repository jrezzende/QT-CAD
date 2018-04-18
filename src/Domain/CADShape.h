#pragma once
#ifndef INCLUDED_CADSHAPE_H
#define INCLUDED_CADSHAPE_H

#include <vector>

#include "Point.h"
#include "ShapeType.h"
#include "ShapeVisitor.h"

class CADShape
{
protected:
	Point p1, p2;
	ShapeType type;

public:
	virtual ~CADShape()= default;
	CADShape() : type(UNDEFINED) {}
	CADShape(const Point& _p1, const Point& _p2) { p1 = _p1; p2 = _p2; type = UNDEFINED; }

	virtual std::vector<Point> coordinates()= 0;
	virtual void setShape(const ShapeType _type)= 0;
	virtual void accept(ShapeVisitor& v)= 0;

	void setfirstPoint(const Point& _p1) { p1 = _p1; }
	void setSecondPoint(const Point& _p2) { p2 = _p2; }

	Point& firstPoint() { return p1; }
	Point& secondPoint() { return p2; }

	ShapeType shapeType() const { return type; }
};

#endif //  INCLUDED_CADSHAPE_H
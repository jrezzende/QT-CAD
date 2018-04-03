#pragma once
#ifndef INCLUDED_CADLINE_H
#define INCLUDED_CADLINE_H

#include "Point.h"
#include "CADShape.h"

class CADLine : public CADShape
{
public:
	~CADLine()= default;
	CADLine()= default;
	CADLine(const Point firstPoint, const Point lastPoint) : CADShape(firstPoint, lastPoint) { type= LINE; }

	std::vector<Point> getCoordinates() override;

	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitLine(*this); };
};

#endif //  INCLUDED_CADLINE_H
#pragma once
#ifndef INCLUDED_CADLINE_H
#define INCLUDED_CADLINE_H

#include "CADShape.h"

class CADLine final : public CADShape
{
public:
	~CADLine()= default;
	CADLine()= default;

	CADLine(const Point firstPoint, const Point lastPoint) : CADShape(firstPoint, lastPoint) { type= LINE; }

	std::vector<Point> coordinates() override;

	void setShape(const ShapeType _type) override { type= _type; }
	void accept(ShapeVisitor& v) override { v.visitLine(*this); };
   CADLine* clone() const override { return new CADLine(*this); }
};

#endif //  INCLUDED_CADLINE_H
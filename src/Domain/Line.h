#pragma once
#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "Shape.h"

class Line : public Shape
{
public:
	~Line() {}
	Line() : Shape() {  }
	Line(const Point firstPoint, const Point lastPoint) : Shape(firstPoint, lastPoint, type) { type= LINE; }

	std::vector<Point> getCoordinates() override;
};

#endif // !LINE_H

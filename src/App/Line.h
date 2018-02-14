#pragma once
#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "Shapes.h"

class Line : public Shapes
{
	Point p1, p2;
	
public:
	~Line()= default;
	Line()= default;
	Line(const Point firstPoint, const Point lastPoint) : Shapes(firstPoint, lastPoint) {}

	std::vector<Point> getCoordinates() override;
};

#endif // !LINE_H

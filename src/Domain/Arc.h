#pragma once
#ifndef ARC_H
#define ARC_H

#include "Shape.h"

class Arc : public Shape
{
	Point p3;
	int quadrantOf(const Point& point);

public:
	~Arc() {}
	Arc() : Shape() {} // need to adjust constructor

	std::vector<Point> getCoordinates() override;
};

#endif //ARC_H
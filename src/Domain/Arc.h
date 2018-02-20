#pragma once
#ifndef ARC_H
#define ARC_H

#include "Shapes.h"

class Arc : public Shape
{
	Point p3;

	int quadrantOf(const Point& point);

public:
	~Arc() {}
	Arc() : Shape() {}

	std::vector<Point> getCoordinates() override;
};

#endif //ARC_H
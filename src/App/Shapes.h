#pragma once
#ifndef SHAPES_H
#define SHAPES_H

#include "Point.h"
#include <vector>

class Shapes
{
protected:
	Point p1, p2;

public:
	virtual ~Shapes()= default;
	Shapes(const Point p1, const Point p2) { this->p1= p1; this->p2= p2;}

	virtual std::vector<Point> getCoordinates()= 0;

	void setfirstPoint(const Point p1) { this->p1= p1; }
	void setSecondPoint(const Point p2) { this->p2= p2; }

	Point& getFirstPoint() { return p1; } 
	Point& getSecondPoint() { return p2; }
};

#endif // !SHAPES_H

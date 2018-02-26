#pragma once
#ifndef COMMANDSHAPE_H
#define COMMANDSHAPE_H

class Model;
class Point;
class Shape;

class CommandShape
{
protected:
	Model& model;

	bool isDrawing;
	bool secondClick;

public:
	virtual ~CommandShape() {}
	CommandShape(Model& _model) : model(_model), isDrawing(false), secondClick(false) {}

	bool isSecondClick() const { return secondClick; }

	virtual void mousePressEvent(Point& point)= 0;
	virtual void mouseMoveEvent(Point& point) = 0;
	virtual void mouseRelease(Point& point) = 0;
};

#endif // !COMMANDSHAPE_H

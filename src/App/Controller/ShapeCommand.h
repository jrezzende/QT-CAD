#pragma once
#ifndef SHAPECOMMAND_H
#define SHAPECOMMAND_H

#include "Command.h"
#include "Shape.h"
#include "ShapeType.h"

class Model;
class Point;

class ShapeCommand
{
protected:
	Model& model;

	bool isDrawing;
	bool previewDraw;
	bool secondClick;

	ShapeType shape;

public:
	virtual ~ShapeCommand() {}
	ShapeCommand(Model& _model, ShapeType _shape) : model(_model), isDrawing(false), secondClick(false), shape(_shape) {}

	bool hasSecondClick() const { return secondClick; }

	ShapeType getShape() { return shape; }

	virtual void mousePressEvent(Point& point)= 0;
	virtual void mouseMoveEvent(Point& point) = 0;
	virtual void mouseReleaseEvent(Point& point) = 0;
}; 
#endif // !SHAPECOMMAND_H

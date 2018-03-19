#pragma once
#ifndef SHAPECOMMAND_H
#define SHAPECOMMAND_H

#include "Command.h"
#include "Shape.h"

class Model;
class Point;

class ShapeCommand
{
protected:
	Model& model;

	ShapeType type;

	bool isDrawing;
	bool previewDraw;
	bool secondClick;

public:
	virtual ~ShapeCommand() {}
	ShapeCommand(Model& _model, ShapeType _type) : model(_model), 
		type(_type), isDrawing(false), secondClick(false) {}

	bool hasSecondClick() const { return secondClick; }
	ShapeType getType () const { return type; }

	virtual void mousePressEvent(Point& point)= 0;
	virtual void mouseMoveEvent(Point& point) = 0;
	virtual void mouseReleaseEvent(Point& point) = 0;
}; 
#endif // !SHAPECOMMAND_H

#pragma once
#ifndef INCLUDED_SHAPECOMMAND_H
#define INCLUDED_SHAPECOMMAND_H

#include "Command.h"
#include "CADShape.h"
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
	virtual ~ShapeCommand()= default;
	ShapeCommand(Model& _model, ShapeType _shape) :
   model(_model), isDrawing(false), previewDraw(false), secondClick(false), shape(_shape) {}

	bool hasSecondClick() const { return secondClick; }

	ShapeType getShape() const { return shape; }

	virtual void mousePressEvent(const Point& point)= 0;
	virtual void mouseMoveEvent(const Point& point) = 0;
	virtual void mouseReleaseEvent(const Point& point) = 0;
}; 

#endif //  INCLUDED_SHAPECOMMAND_H
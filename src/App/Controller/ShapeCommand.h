#pragma once
#ifndef INCLUDED_SHAPECOMMAND_H
#define INCLUDED_SHAPECOMMAND_H

#include "Command.h"
#include "CADShape.h"
#include "ShapeType.h"

class CADFileManager;
class Point;

class ShapeCommand
{
protected:
   CADFileManager& m;
   ShapeType shape;

	bool isDrawing;
	bool previewDraw;
	bool secondClick;	

public:
	virtual ~ShapeCommand()= default;
	ShapeCommand(CADFileManager& _m, ShapeType _shape) :
   m(_m), shape(_shape), isDrawing(false), previewDraw(false), secondClick(false) {}

	bool hasSecondClick() const { return secondClick; }

	ShapeType type() const { return shape; }

	virtual void mousePressEvent(const Point& point)= 0;
	virtual void mouseMoveEvent(const Point& point) = 0;
	virtual void mouseReleaseEvent(const Point& point) = 0;
}; 

#endif //  INCLUDED_SHAPECOMMAND_H
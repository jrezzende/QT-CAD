#pragma once
#ifndef INCLUDED_COMMANDBEZIER_H
#define INCLUDED_COMMANDBEZIER_H

#include "ShapeCommand.h"
#include "CADBezier.h"
#include "CADLine.h"

#include <iostream>

class CommandBezier : public ShapeCommand
{
	CADBezier* bezier;
	CADLine* previewLine;

public:
	~CommandBezier()= default;
	CommandBezier(CADFileManager& m) :
   ShapeCommand(m, BEZIER) { bezier= new CADBezier(); bezier->setShape(BEZIER); previewLine= new CADLine(); }

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDBEZIER_H
#pragma once
#ifndef INCLUDED_COMMANDARC_H
#define INCLUDED_COMMANDARC_H

#include "ShapeCommand.h"
#include "CADArc.h"
#include "CADLine.h"

class CommandArc : public ShapeCommand
{
	CADArc* arc;
	CADLine* previewLine;

public: 
	~CommandArc()= default;
	CommandArc(Model& m) 
   : ShapeCommand(m, ARC) { arc = new CADArc(); arc->setShape(ARC); previewLine= new CADLine(); }

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDARC_H
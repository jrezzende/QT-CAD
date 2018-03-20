#pragma once
#ifndef COMMANDARC_H
#define COMMANDARC_H

#include "ShapeCommand.h"
#include "Arc.h"
#include "Line.h"

class CommandArc : public ShapeCommand
{
	Arc* arc;
	Line* previewLine;

public: 
	~CommandArc() {}
	CommandArc(Model& m) : ShapeCommand(m, ARC) { arc = new Arc(); arc->setShape(ARC); previewLine= new Line(); }

	void mousePressEvent(Point& point) override;
	void mouseMoveEvent(Point& point) override;
	void mouseReleaseEvent(Point& point) override;
};

#endif // !COMMANDARC_H

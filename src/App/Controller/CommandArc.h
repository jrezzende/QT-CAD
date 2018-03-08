#pragma once
#ifndef COMMANDARC_H
#define COMMANDARC_H

#include "ShapeCommand.h"
#include "Arc.h"
#include "Line.h"

#include <iostream>

class CommandArc : public ShapeCommand
{
	Arc* arc;
	Line* previewLine;
	
	bool previewDraw;
public: 
	~CommandArc() {}
	CommandArc(Model& m) : ShapeCommand(m, ARC), previewDraw(false) {}

	void mousePressEvent(Point& point) override;
	void mouseMoveEvent(Point& point) override;
	void mouseReleaseEvent(Point& point) override;
};

#endif // !COMMANDARC_H

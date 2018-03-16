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

public: 
	~CommandArc() {}
	CommandArc(Model& m) : ShapeCommand(m, ARC) {}

	void mousePressEvent(Point& point) override;
	void mouseMoveEvent(Point& point) override;
	void mouseReleaseEvent(Point& point) override;
};

#endif // !COMMANDARC_H

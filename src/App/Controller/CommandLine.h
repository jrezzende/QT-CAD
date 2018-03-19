#pragma once
#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "ShapeCommand.h"
#include "Line.h"

class CommandLine : public ShapeCommand
{
	Line* line;

public:
	~CommandLine() {}
	CommandLine(Model& m) : ShapeCommand(m, LINE) {}

	void mousePressEvent(Point& point) override;
	void mouseMoveEvent(Point& point) override;
	void mouseReleaseEvent(Point& point) override;
};

#endif // !COMMANDLINE_H

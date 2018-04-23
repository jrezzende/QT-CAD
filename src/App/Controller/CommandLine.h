#pragma once
#ifndef INCLUDED_COMMANDLINE_H
#define INCLUDED_COMMANDLINE_H

#include "ShapeCommand.h"
#include "CADLine.h"

class CommandLine : public ShapeCommand
{
	CADLine* line;

public:
	~CommandLine()= default;
	CommandLine(CADFileManager& m) : ShapeCommand(m, LINE) { line= new CADLine(); }

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDLINE_H
#pragma once
#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "ShapeCommand.h"
#include "Line.h"

#include <iostream>

class CommandLine : public ShapeCommand
{
	Line* line;
	//Line* previewLine;

	//bool previewDrawn;
public:
	~CommandLine() {}
	CommandLine(Model& m) : ShapeCommand(m, LINE) /*previewDrawn(false)*/ { line= new Line(); /*previewLine= new Line();*/ }

	void mousePressEvent(Point& point) override;
	void mouseMoveEvent(Point& point) override;
	void mouseReleaseEvent(Point& point) override;
};

#endif // !COMMANDLINE_H

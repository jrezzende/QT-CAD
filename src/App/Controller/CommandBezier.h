#pragma once
#ifndef COMMANDBEZIER_H
#define COMMANDBEZIER_H

#include "ShapeCommand.h"
#include "Bezier.h"
#include "Line.h"

#include <iostream>

class CommandBezier : public ShapeCommand
{
	Bezier* bezier;
	Line* previewLine;

	bool previewDraw;
public:
	~CommandBezier() {}
	CommandBezier(Model& m) : ShapeCommand(m, BEZIER), previewDraw(false) {}

	void mousePressEvent(Point& point) override;
	void mouseMoveEvent(Point& point) override;
	void mouseReleaseEvent(Point& point) override;
};
#endif // !COMMANDBEZIER_H

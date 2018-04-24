#pragma once
#ifndef INCLUDED_COMMANDBEZIER_H
#define INCLUDED_COMMANDBEZIER_H

#include <memory>

#include "ShapeCommand.h"
#include "CADBezier.h"
#include "CADLine.h"

class CommandBezier : public ShapeCommand
{
	std::shared_ptr<CADBezier> bezier;
	std::shared_ptr<CADLine> previewLine;

public:
	~CommandBezier()= default;
	explicit CommandBezier(CADFileManager& m) :
   ShapeCommand(m, BEZIER) { bezier = std::make_shared<CADBezier>(); bezier->setShape(BEZIER);
	   previewLine= std::make_shared<CADLine>(); }

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDBEZIER_H
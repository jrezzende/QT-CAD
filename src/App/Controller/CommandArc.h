#pragma once
#ifndef INCLUDED_COMMANDARC_H
#define INCLUDED_COMMANDARC_H

#include <memory>

#include "ShapeCommand.h"
#include "CADArc.h"
#include "CADLine.h"

class CommandArc : public ShapeCommand
{
	std::shared_ptr<CADArc> arc;
	std::shared_ptr<CADLine> previewLine;

public: 
	~CommandArc()= default;
	CommandArc(CADFileManager& m): 
   ShapeCommand(m, ARC) { arc= std::make_shared<CADArc>(); arc->setShape(ARC); previewLine = std::make_shared<CADLine>();}

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDARC_H
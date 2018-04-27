#pragma once
#ifndef INCLUDED_COMMANDARC_H
#define INCLUDED_COMMANDARC_H

#include <memory>

#include "ShapeCommand.h"
#include "CADArc.h"
#include "CADLine.h"

class CommandArc : public ShapeCommand
{
	CADArc* arc;
   CADLine* previewLine;

public: 
	~CommandArc()= default;
	explicit CommandArc(CADFileManager& _fileManager, ViewMediator& _viewMediator): 
   ShapeCommand(_fileManager, _viewMediator, ARC) 
   { arc= new CADArc(); arc->setShape(ARC); previewLine = new CADLine(); }

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDARC_H
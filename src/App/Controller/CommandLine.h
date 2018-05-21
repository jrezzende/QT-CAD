#pragma once
#ifndef INCLUDED_COMMANDLINE_H
#define INCLUDED_COMMANDLINE_H

#include <memory>

#include "ShapeCommand.h"
#include "CADLine.h"
#include "ViewMediator.h"
#include "CommandHandler.h"

class CommandLine : public ShapeCommand
{
   Point p1, p2;
	CADLine* line;

   PointMapper* mapper;

public:
	~CommandLine()= default;
   explicit CommandLine(CADFileManager& _fileManager, ViewMediator& _viewMediator) :
      ShapeCommand(_fileManager, _viewMediator, LINE) { 
      line= new CADLine(); mapper= &viewMediator.manager().pointMapper(); 
   }

	void mousePressEvent(const Point& point) override;
	void mouseMoveEvent(const Point& point) override;
	void mouseReleaseEvent(const Point& point) override;
};

#endif //  INCLUDED_COMMANDLINE_H
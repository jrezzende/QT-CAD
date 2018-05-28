#pragma once
#ifndef INCLUDED_COMMANDTRANSLATECANVAS_H
#define INCLUDED_COMMANDTRANSLATECANVAS_H

#include "ShapeCommand.h"
#include "Point.h"

class CommandTranslateCanvas : public ShapeCommand
{
   Point translationPoint, gap;

public:
   ~CommandTranslateCanvas() = default;
   CommandTranslateCanvas(CADFileManager& fileManager, ViewMediator& viewMediator) :
      ShapeCommand(fileManager, viewMediator, UNDEFINED), translationPoint(Point(0, 0)),
      gap(Point(0, 0)) {}

   void mousePressEvent(const Point& point) override;
   void mouseMoveEvent(const Point& point) override;
   void mouseReleaseEvent(const Point& point) override {}
};

#endif // INCLUDED_COMMANDTRANSLATECANVAS_H
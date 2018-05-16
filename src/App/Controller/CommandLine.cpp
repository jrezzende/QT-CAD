#include "CommandLine.h"
#include "CADFileManager.h"

void CommandLine::mousePressEvent(const Point& point)
{
   p1= point;
   p2= point;

   line->setFirstPoint(p1);
   line->setSecondPoint(p2);
}

void CommandLine::mouseMoveEvent(const Point& point)
{
   Point p1_= p1;
   p2= point;

   mapper.recalculatePointToView(p1_);
   mapper.recalculatePointToView(p2);

   line->setFirstPoint(p1_);
   line->setSecondPoint(p2);

   fileManager.currentFile().addShape(*line);
	line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(const Point& point)
{
   p2= point;

   mapper.recalculatePointToView(p1);
   mapper.recalculatePointToView(p2);

   line->setFirstPoint(p1);
   line->setSecondPoint(p2);

   fileManager.currentFile().addShape(*line);
}
#include "CommandLine.h"
#include "CADFileManager.h"

void CommandLine::mousePressEvent(const Point& point)
{
   line->setFirstPoint(point);
   line->setSecondPoint(point);
}

void CommandLine::mouseMoveEvent(const Point& point)
{
   line->setSecondPoint(point);
   fileManager.currentFile().addShape(*line);
}

void CommandLine::mouseReleaseEvent(const Point& point)
{
   fileManager.currentFile().addShape(*line);
}
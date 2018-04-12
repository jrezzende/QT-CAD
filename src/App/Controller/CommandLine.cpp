#include "CommandLine.h"
#include "CADFileManager.h"

void CommandLine::mousePressEvent(const Point& point)
{
	line->setfirstPoint(point);
	line->setSecondPoint(point);
}

void CommandLine::mouseMoveEvent(const Point& point)
{			
	m.getCurrentFile()->addShape(*line);
	line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(const Point& point)
{
	/////////////////////////////////////////////
}
#include "CommandLine.h"
#include "Model.h"

void CommandLine::mousePressEvent(Point& point)
{
	line->setfirstPoint(point);
	line->setSecondPoint(point);
}

void CommandLine::mouseMoveEvent(Point& point)
{			
	model.getCurrentFile()->addShape(line);
	line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(Point& point)
{
	/////////////////////////////////////////////
}
#include "CommandLine.h"
#include "Model.h"

void CommandLine::mousePressEvent(const Point& point)
{
	line->setfirstPoint(point);
	line->setSecondPoint(point);
}

void CommandLine::mouseMoveEvent(const Point& point)
{			
	model.getCurrentFile()->addShape(*line);
	line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(const Point& point)
{
	/////////////////////////////////////////////
}
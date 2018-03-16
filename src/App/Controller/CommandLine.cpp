#include "CommandLine.h"
#include "Model.h"
#include "Canvas.h"

void CommandLine::mousePressEvent(Point& point)
{
	line = new Line(point, point);
}

void CommandLine::mouseMoveEvent(Point& point)
{			
	line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(Point & point)
{
	model.getCurrentFile()->addShape(line);
}
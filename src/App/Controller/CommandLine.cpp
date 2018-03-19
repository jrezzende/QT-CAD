#include "CommandLine.h"
#include "Model.h"

void CommandLine::mousePressEvent(Point& point)
{
	line= new Line(point, point);
}

void CommandLine::mouseMoveEvent(Point& point)
{			
	model.getCurrentFile()->addShape(line);
	line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(Point& point)
{

}
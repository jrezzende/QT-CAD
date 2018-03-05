#include "CommandLine.h"
#include "Model.h"

void CommandLine::mousePressEvent(Point& point)
{
	line= new Line(point, point);

	isDrawing= true;
}

void CommandLine::mouseMoveEvent(Point& point)
{
	if (isDrawing)
		line->setSecondPoint(point);
}

void CommandLine::mouseReleaseEvent(Point & point)
{
	isDrawing= false;
	model.getCurrentFile()->addShape(line);
}
#include "CommandLine.h"
#include "Model.h"

void CommandLine::mousePressEvent(Point& point)
{
	line= new Line(point, point);
	isDrawing = true;

	//previewLine= new Line(point, point);
}

void CommandLine::mouseMoveEvent(Point& point)
{
	if (isDrawing) {
		line->setSecondPoint(point);

		//previewLine->setSecondPoint(point);

		//model.getCurrentFile()->addShape(previewLine);
	}
}

void CommandLine::mouseReleaseEvent(Point & point)
{
	isDrawing= false;
	model.getCurrentFile()->addShape(line);
}
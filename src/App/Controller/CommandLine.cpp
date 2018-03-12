#include "CommandLine.h"
#include "Model.h"

void CommandLine::mousePressEvent(Point& point)
{
	line->setfirstPoint(point);
	//previewLine->setfirstPoint(point);
}

void CommandLine::mouseMoveEvent(Point& point)
{		
	line->setSecondPoint(point);

	/*if (!previewDrawn) {
		model.getCurrentFile()->addShape(previewLine);
		previewDrawn= true;
	}
	else {
		model.getCurrentFile()->eraseLastShape();
		previewDrawn= false;
	}*/
}

void CommandLine::mouseReleaseEvent(Point & point)
{
	model.getCurrentFile()->addShape(line);
}
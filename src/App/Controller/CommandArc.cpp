#include "CommandArc.h"
#include "Model.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(Point & point)
{
	if (!isDrawing) {
		arc= new Arc();
		arc->setfirstPoint(point);
		
		previewLine->setfirstPoint(point);
	}
	else
		secondClick= true;
}

void CommandArc::mouseMoveEvent(Point & point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);

		model.getCurrentFile()->addShape(previewLine);
	}
	else {
		model.getCurrentFile()->eraseShape(previewLine);

		arc->setThirdPoint(point);
		model.getCurrentFile()->addShape(arc);
	}
}

void CommandArc::mouseReleaseEvent(Point & point)
{
	if (!secondClick) {
		arc->setSecondPoint(point);

		isDrawing= true;
	}
	else {
		model.getCurrentFile()->addShape(arc);
		model.getCurrentFile()->getCanvas()->setDrawing(false);

		delete previewLine;
	}
}

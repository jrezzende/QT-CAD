#include "CommandArc.h"
#include "Model.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(const Point& point)
{
	if (!isDrawing) {
		arc->setfirstPoint(point);
		previewLine->setfirstPoint(point);
	}
	else {
		secondClick = true;
		arc->setThirdPoint(point);
		model.getCurrentFile()->eraseShape(*previewLine);
	}
}

void CommandArc::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
		model.getCurrentFile()->addShape(*previewLine);
	}
	else {
		model.getCurrentFile()->addShape(*arc);
		arc->setThirdPoint(point);
	}
}

void CommandArc::mouseReleaseEvent(const Point& point)
{
	if (!secondClick) {
		arc->setSecondPoint(point);
		isDrawing= true;
	}
	else {
		model.getCurrentFile()->addShape(*arc);
		model.getCurrentFile()->getCanvas()->setDrawing(false);

		delete previewLine;
	}
}

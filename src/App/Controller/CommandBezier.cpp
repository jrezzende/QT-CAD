#include "CommandBezier.h"
#include "Model.h"
#include "Canvas.h"

void CommandBezier::mousePressEvent(Point& point)
{
	if (!isDrawing) {
		bezier->setfirstPoint(point);
		previewLine->setfirstPoint(point);
	}
	else {
		secondClick = true;
		bezier->setThirdPoint(point);
		model.getCurrentFile()->eraseShape(previewLine);
	}
}

void CommandBezier::mouseMoveEvent(Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
		model.getCurrentFile()->addShape(previewLine);
	}
	else {
		bezier->setThirdPoint(point);
		model.getCurrentFile()->addShape(bezier);
	}
}

void CommandBezier::mouseReleaseEvent(Point& point)
{
	if (!secondClick) {
		bezier->setSecondPoint(point);
		isDrawing= true;
	}
	else {
		model.getCurrentFile()->addShape(bezier);
		model.getCurrentFile()->getCanvas()->setDrawing(false);
		delete previewLine;
	}
}
